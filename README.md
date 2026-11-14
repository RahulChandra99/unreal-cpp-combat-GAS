<h1 align="center">Gameplay Abilities with GAS (Multiplayer)</h1>
<p align="center">Built using C++, Blueprints and Unreal Engine 5</p>

<p align="center">
  <a href="https://www.youtube.com/watch?v=w7YCiTBzDqA" target="_blank">
    <img src="https://github.com/user-attachments/assets/35b8e5e2-489d-491e-b0e8-0feebf5a9f23" alt="Gameplay demo" width="600"/>
  </a>
</p>
<p align="center">Click the image to watch the demo.</p>

A third person multiplayer project built on Unreal's Gameplay Ability System. The GAS foundation (ability system component, attribute set, granting, base ability class) is in C++. Individual abilities are Blueprint graphs on top of it, with C++ helpers where the maths is easier to write in code.

Made with game FX artist [Kavya Swaminathan](https://www.linkedin.com/in/kavya-swaminathan-/).

| Platform | Engine | Duration | Team Size | Role |
|---|---|---|---|---|
| PC | Unreal Engine 5 / C++ | Present | Duo | AI / Gameplay Programmer |

## GAS setup

The code is in [`Source/CombatRPG/GameplayAbilitySystem`](Source/CombatRPG/GameplayAbilitySystem).

### Ability system component

The component lives on the character and replicates in `Mixed` mode by default.

```cpp
AbilitySystemComponent = CreateDefaultSubobject<UCombatRPGAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
AbilitySystemComponent->SetIsReplicated(true);
AbilitySystemComponent->SetReplicationMode(AscReplicationMode);
```

### Initialising and granting abilities

Actor info is initialised twice: in `PossessedBy` on the server and in `OnRep_PlayerState` on the client. Abilities are only ever granted or removed on the server, and GAS replicates the specs to the owner.

```cpp
void ACombatRPGCharacterBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
		GrantAbilities(StartingAbilities);
	}
}

TArray<FGameplayAbilitySpecHandle> ACombatRPGCharacterBase::GrantAbilities(
	TArray<TSubclassOf<UGameplayAbility>> AbilitiesToGrant)
{
	if (!AbilitySystemComponent || !HasAuthority())
	{
		return TArray<FGameplayAbilitySpecHandle>();
	}

	TArray<FGameplayAbilitySpecHandle> AbilityHandles;
	for (TSubclassOf<UGameplayAbility> Ability : AbilitiesToGrant)
	{
		FGameplayAbilitySpecHandle SpecHandle = AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(
			Ability, 1, -1, this
		));
		AbilityHandles.Add(SpecHandle);
	}

	SendAbilitiesChangedEvent();
	return AbilityHandles;
}
```

`SendAbilitiesChangedEvent` fires an `Event.Abilities.Changed` gameplay event, which the UI listens for so it can update.

### Attributes

`UBasicAttributeSet` holds Health, MaxHealth, Stamina and MaxStamina. Each one replicates with a RepNotify, and values are clamped before they change so an effect can't push health below zero or above the max.

```cpp
void UBasicAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
	} else if (Attribute == GetStaminaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxStamina());
	}
}
```

### Gameplay tags

Every ability inherits from `UCombatRPGGameplayAbility`, which adds a `GameplayAbility.Active` tag while it runs. Other abilities use that tag to block themselves.

```cpp
ActivationOwnedTags.AddTag(FGameplayTag::RequestGameplayTag(FName("GameplayAbility.Active")));
```

## Abilities

### Dash

A four-direction dash. The ability graph is Blueprint. `UDashAbility` in C++ works out which way the dash is going relative to the character and picks the matching montage.

1. Activation event arrives with the input direction
2. Direction is classified as forward, back, left or right
3. Commit checks stamina cost and cooldown
4. Root motion force moves the character
5. The montage for that direction plays
6. A Gameplay Cue plays VFX and audio
7. The ability ends when the montage does

<details>
<summary><b>Direction detection</b></summary>

```cpp
EDashDirection UDashAbility::GetDashDirectionFromWorld(const FVector& WorldDashDirection, float ForwardThreshold) const
{
	const FGameplayAbilityActorInfo* Info = CurrentActorInfo;
	if (!Info || !Info->AvatarActor.IsValid())
	{
		return EDashDirection::Forward;
	}

	FVector Dir = WorldDashDirection;
	Dir.Z = 0.0f;
	Dir = Dir.GetSafeNormal();

	if (Dir.IsNearlyZero())
	{
		return EDashDirection::Forward;
	}

	const AActor* Avatar = Info->AvatarActor.Get();

	const FVector Forward = Avatar->GetActorForwardVector().GetSafeNormal2D();
	const FVector Right = Avatar->GetActorRightVector().GetSafeNormal2D();

	const float F = FVector::DotProduct(Dir, Forward);
	const float R = FVector::DotProduct(Dir, Right);

	if (F >= ForwardThreshold && F >= FMath::Abs(R))
	{
		return EDashDirection::Forward;
	}

	if (F <= -ForwardThreshold && FMath::Abs(F) >= FMath::Abs(R))
	{
		return EDashDirection::Back;
	}

	return (R >= 0.0f) ? EDashDirection::Right : EDashDirection::Left;
}
```

</details>

<img width="3464" height="1266" alt="GA_Dash_EventGraph_00003" src="https://github.com/user-attachments/assets/a8370a5e-dfb7-452e-868e-1ab2de5448b0" />
<img width="2432" height="937" alt="GC_Dash_K2_HandleGameplayCue_00000" src="https://github.com/user-attachments/assets/54f6abc5-40a0-4631-a192-d95988cfb493" />

Stamina cost and cooldown are Gameplay Effects. VFX and sound go through a Gameplay Cue, so they stay out of the gameplay logic.

### Area of attack

A radial melee attack, built in Blueprint.

1. Activation event arrives
2. Commit checks cost and cooldown
3. The attack montage plays
4. A sphere overlap on the server finds everything in range
5. Targets are filtered with Gameplay Tags, so no self hits or friendly fire
6. A damage Gameplay Effect is applied to each valid target
7. A Gameplay Cue plays impact VFX and audio
8. The ability ends when the montage does

<img width="3123" height="1446" alt="GA_AOEAttack_EventGraph_00000" src="https://github.com/user-attachments/assets/1260da13-5889-44ce-a9f2-156b3f942351" />
<img width="3975" height="1526" alt="GA_AOEAttack_EventGraph_00001" src="https://github.com/user-attachments/assets/2d48cbc4-5ca8-44c5-b62a-c3e4e28d30a6" />
<img width="3654" height="2290" alt="GC_AOEMultipleAttack_EventGraph_00000" src="https://github.com/user-attachments/assets/71f696ca-d494-4651-9f46-9b6606e3a4c0" />

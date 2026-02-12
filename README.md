<h1 align="center">Gameplay Mechanics and Abilities using GAS (Multiplayer Integration)</h1>
<p align="center">Built using C++, Blueprints and Unreal Engine 5</p>

---

## Table of Contents

- [Overview](#overview)
- [Gameplay Demo](#gameplay-demo)
- [Project Details](#project-details)
- [Gameplay Ability System](#gameplay-ability-system)
- [Gameplay Abilities](#gameplay-abilities)
  - [Dash Ability](#dash-ability)
  

---

## Overview

This project is a third person multiplayer gameplay framework built around Unreal Engine's *Gameplay Ability System (GAS)*.

The system focuses on scalable ability architecture, replicated gameplay state, and modular C++ design with Blueprint friendly APIs.

### Goals

- Server authoritative multiplayer abilities
- Clean GAS architecture
- Modular gameplay systems
- Replicated attributes and state
- Animation driven movement abilities

---

## Gameplay Demo

Click the image below to watch the demo:

<p align="center">
  <a href="https://www.youtube.com/watch?v=21OzrVktwzA" target="_blank">
    <img src="https://github.com/user-attachments/assets/4eddc091-8649-4187-a79c-8fa5acec11e9" width="600"/>
  </a>
</p>

---

## Project Details

| Platform | Engine | Duration | Team Size | Role |
|---|---|---|---|---|
| PC | Unreal Engine 5 / C++ | Present | Duo | AI / Gameplay Programmer |

---

# Gameplay Ability System

---

## Ability System Component

The Ability System Component is implemented in C++ and attached to the character.

### Responsibilities

- ability lifecycle management
- attribute updates
- gameplay effect processing
- ability replication
- gameplay event communication

<details>
<summary><b>Ability System setup</b></summary>

```cpp
AbilitySystemComponent = CreateDefaultSubobject<UCombatRPGAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
AbilitySystemComponent->SetIsReplicated(true);
AbilitySystemComponent->SetReplicationMode(AscReplicationMode);
```

</details>


## Ability Initialization and Granting

The ability system is initialized on server possession and client PlayerState replication to ensure multiplayer safe setup.

<details>
<summary><b>Ability initialization</b></summary>

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
```

```cpp
void ACombatRPGCharacterBase::OnRep_PlayerState()
{
    Super::OnRep_PlayerState();

    if (AbilitySystemComponent)
    {
        AbilitySystemComponent->InitAbilityActorInfo(this, this);
    }
}
```

</details>


## Custom Attribute Set

A custom AttributeSet stores gameplay attributes such as health and stamina.

### Features

- replicated gameplay stats
- attribute validation
- gameplay effect response
- multiplayer safe values

<details>
<summary><b>Attribute defaults</b></summary>

```cpp
UBasicAttributeSet::UBasicAttributeSet()
{
    Health = 100.f;
    MaxHealth = 100.f;
    Stamina = 100.f;
    MaxStamina = 100.f;
}
```

</details>


## Attribute Replication

Attributes use RepNotify to synchronize gameplay state across clients.

<details>
<summary><b>Attribute replication</b></summary>

```cpp
UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Health)
FGameplayAttributeData Health;
```

</details>

## Attribute Validation and Clamping

Values are validated before and after gameplay effects to prevent invalid states.

<details>
<summary><b>Attribute clamping</b></summary>

```cpp
void UBasicAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
    if (Attribute == GetHealthAttribute())
    {
        NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
    }
}
```

</details>


## Gameplay Tags

Gameplay Tags control ability state and activation rules.

### Usage

- mark active abilities
- block conflicting actions
- drive gameplay state

<details>
<summary><b>Ability active tag</b></summary>

```cpp
ActivationOwnedTags.AddTag(
    FGameplayTag::RequestGameplayTag(FName("GameplayAbility.Active"))
);
```

</details>

## Gameplay Events and UI Updates

Gameplay events notify UI systems when abilities change.

<details>
<summary><b>Ability change event</b></summary>

```cpp
void ACombatRPGCharacterBase::SendAbilitiesChangedEvent()
{
    FGameplayEventData EventData;
    EventData.EventTag = FGameplayTag::RequestGameplayTag(FName("Event.Abilities.Changed"));

    UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
        this,
        EventData.EventTag,
        EventData
    );
}
```

</details>

## Server Authoritative Ability Granting

Abilities are granted only on the server to ensure secure multiplayer behaviour.


## Replication Based State Synchronization

Ability specs and gameplay state replicate automatically through GAS.

## Blueprint Friendly API

Core ability functionality is exposed to Blueprint for fast iteration.

---

# Gameplay Abilities

---

## Dash Ability

The ability calculates dash direction, applies root motion movement, plays a direction specific animation, applies cost and cooldown, and triggers visual feedback.

### Execution Pipeline

1. Ability activation event received  
2. Direction calculated from input  
3. Ability commit validates cost and cooldown  
4. Root motion force applied  
5. Direction based montage plays  
6. Gameplay Cue triggers VFX and audio  
7. Ability ends on montage completion  

### Direction Detection System

Converts world input direction into a direction relative to the character.

<details>
<summary><b><i>View Code</i></b></summary>

```cpp
EDashDirection UDashAbility::GetDashDirectionFromWorld(
    const FVector& WorldDashDirection,
    float ForwardThreshold
) const
{
    FVector Dir = WorldDashDirection;
    Dir.Z = 0.0f;
    Dir = Dir.GetSafeNormal();

    const AActor* Avatar = CurrentActorInfo->AvatarActor.Get();

    const FVector Forward = Avatar->GetActorForwardVector().GetSafeNormal2D();
    const FVector Right = Avatar->GetActorRightVector().GetSafeNormal2D();

    const float F = FVector::DotProduct(Dir, Forward);
    const float R = FVector::DotProduct(Dir, Right);

    if (F >= ForwardThreshold && F >= FMath::Abs(R))
        return EDashDirection::Forward;

    if (F <= -ForwardThreshold && FMath::Abs(F) >= FMath::Abs(R))
        return EDashDirection::Back;

    return (R >= 0.0f) ? EDashDirection::Right : EDashDirection::Left;
}
```

</details>

### Direction Based Animation Selection

Selects a montage based on dash direction.

<details>
<summary><b><i>View Code</i></b></summary>

```cpp
UAnimMontage* UDashAbility::GetDashMontageForDirection(EDashDirection Direction) const
{
    switch (Direction)
    {
        case EDashDirection::Forward: return DashMontageForward;
        case EDashDirection::Back: return DashMontageBack;
        case EDashDirection::Left: return DashMontageLeft;
        case EDashDirection::Right: return DashMontageRight;
        default: return DashMontageForward;
    }
}
```

</details>
<img width="3464" height="1266" alt="GA_Dash_EventGraph_00003" src="https://github.com/user-attachments/assets/a8370a5e-dfb7-452e-868e-1ab2de5448b0" />
<img width="2432" height="937" alt="GC_Dash_K2_HandleGameplayCue_00000" src="https://github.com/user-attachments/assets/54f6abc5-40a0-4631-a192-d95988cfb493" />

- Root Motion Movement : Character movement is driven by root motion force for animation driven movement and smooth gameplay response

- Cost and Cooldown System : Gameplay Effects handle stamina cost and cooldown automatically.

- Gameplay Tag Based State Control : Gameplay Tags prevent conflicting actions and manage ability state.

- Multiplayer Execution : Server authoritative ability execution with client prediction.

- Cosmetic Feedback : Gameplay Cue handles VFX and sound without affecting gameplay logic.




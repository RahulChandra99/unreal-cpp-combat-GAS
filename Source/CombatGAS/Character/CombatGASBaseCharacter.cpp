// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatGASBaseCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameplayAbilitySpec.h"


// Sets default values
ACombatGASBaseCharacter::ACombatGASBaseCharacter()
{

	//tick and refresh bone transforms whether rendered or not
	GetMesh()->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;
	
}

UAbilitySystemComponent* ACombatGASBaseCharacter::GetAbilitySystemComponent() const
{
	return nullptr;
}

void ACombatGASBaseCharacter::GiveStartUpAbilities()
{
	if (!IsValid(GetAbilitySystemComponent())) return;
	
	for (const auto& Ability:StartupAbilities)
	{
		
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(Ability);
		GetAbilitySystemComponent()->GiveAbility(AbilitySpec);
	}
}

void ACombatGASBaseCharacter::InitializeAbilities() const
{
	checkf(IsValid(InitializeAttributeEffect),TEXT("Ini Attribute Effect not set"));
	
	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	//GetAbilitySystemComponent()->MakeOutgoingSpec()
}



// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatGASPlayerState.h"
#include "AbilitySystemComponent.h"
#include "Abilities/AttributeSets/BasicAttributeSet.h"

ACombatGASPlayerState::ACombatGASPlayerState()
{
	SetNetUpdateFrequency(100.f);
	
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	
	BasicAttributeSet = CreateDefaultSubobject<UBasicAttributeSet>("BasicAttributeSet");
}

UAbilitySystemComponent* ACombatGASPlayerState::GetAbilitySystemComponent() const
{
	
	return AbilitySystemComponent;
}

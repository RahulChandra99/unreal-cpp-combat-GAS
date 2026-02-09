// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatRPGGameplayAbility.h"

UCombatRPGGameplayAbility::UCombatRPGGameplayAbility()
{
	ActivationOwnedTags.AddTag(FGameplayTag::RequestGameplayTag(FName("GameplayAbility.Active")));
}

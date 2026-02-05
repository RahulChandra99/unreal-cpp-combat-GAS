// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "CombatGASPlayerState.generated.h"


/**
 * 
 */

class UBasicAttributeSet;
class UAttributeSet;
class UAbilitySystemComponent;

UCLASS()
class COMBATGAS_API ACombatGASPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
private:
	
	UPROPERTY(VisibleAnywhere, Category="Abilities")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	
	UPROPERTY()
	TObjectPtr<UBasicAttributeSet> BasicAttributeSet;
	
public:
	
	ACombatGASPlayerState();
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
	UFUNCTION(BlueprintPure, Category="AbilitySystem")
	UBasicAttributeSet* GetBasicAttributeSet() const { return BasicAttributeSet; }
};

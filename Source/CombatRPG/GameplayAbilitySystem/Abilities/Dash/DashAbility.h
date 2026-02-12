// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CombatRPG/GameplayAbilitySystem/Abilities/CombatRPGGameplayAbility.h"
#include "DashAbility.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EDashDirection : uint8
{
	Forward, Back, Left, Right
};

UCLASS()
class COMBATRPG_API UDashAbility : public UCombatRPGGameplayAbility
{
	GENERATED_BODY()
	
protected:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Dash|Montages")
	TObjectPtr<UAnimMontage> DashMontageForward = nullptr;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Dash|Montages")
	TObjectPtr<UAnimMontage> DashMontageBack = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Dash|Montages")
	TObjectPtr<UAnimMontage> DashMontageLeft = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Dash|Montages")
	TObjectPtr<UAnimMontage> DashMontageRight = nullptr;
	
	UFUNCTION(BlueprintCallable, Category = "Dash")
	EDashDirection GetDashDirectionFromWorld(const FVector& WorldDashDirection, float ForwardThreshold = 0.5f) const;

	UFUNCTION(BlueprintCallable, Category = "Dash")
	UAnimMontage* GetDashMontageForDirection(EDashDirection Direction) const;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "CombatGASBaseCharacter.generated.h"

class UGameplayEffect;
class UGameplayAbility;

UCLASS()
class COMBATGAS_API ACombatGASBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACombatGASBaseCharacter();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
protected:
	
	void GiveStartUpAbilities();
	void InitializeAbilities() const;
	
private:
	
	UPROPERTY(EditDefaultsOnly, Category="Combat|Abilities")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;
	
	UPROPERTY(EditDefaultsOnly, Category = "Combat|Effects")
	TSubclassOf<UGameplayEffect> InitializeAttributeEffect;;
	
};

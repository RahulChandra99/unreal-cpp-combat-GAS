#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "CombatGASBaseCharacter.generated.h"

class UAbilitySystemComponent;
class UBasicAttributeSet;
class UGameplayAbility;
class UGameplayEffect;

UCLASS()
class COMBATGAS_API ACombatGASBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ACombatGASBaseCharacter();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	TObjectPtr<UBasicAttributeSet> BasicAttributeSet;

protected:
	void GiveStartUpAbilities();
	void InitializeAbilities() const;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Combat|Abilities")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "Combat|Effects")
	TSubclassOf<UGameplayEffect> InitializeAttributeEffect;
};

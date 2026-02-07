#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "CombatGASBaseCharacter.generated.h"

struct FGameplayAbilitySpecHandle;
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
	
	UFUNCTION(BlueprintCallable, Category = "AbilitySystem")
	TArray<FGameplayAbilitySpecHandle> GrantAbilities(TArray<TSubclassOf<UGameplayAbility>> AbilitiesToGrant);
	
	UFUNCTION(BlueprintCallable, Category = "AbilitySystem")
	void RemoveAbilities(TArray<FGameplayAbilitySpecHandle> AbilitiesToRemove);
	
	UFUNCTION(BlueprintCallable, Category = "AbilitySystem")
	void SendAbilitiesChangedEvent();
	
protected:
	void GiveStartUpAbilities();
	void InitializeAbilities() const;
	
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AbilitySystem|Abilities")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;

private:
	

	UPROPERTY(EditDefaultsOnly, Category = "AbilitySystem|Effects")
	TSubclassOf<UGameplayEffect> InitializeAttributeEffect;
};

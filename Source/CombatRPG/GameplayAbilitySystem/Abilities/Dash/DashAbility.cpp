// Fill out your copyright notice in the Description page of Project Settings.


#include "DashAbility.h"

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

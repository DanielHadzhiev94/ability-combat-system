#include "UAbilityBase.h"
#include "GameFramework/Actor.h"

UAbilityBase::UAbilityBase()
{
	AbilityName = TEXT("BasicAbility");
}

bool UAbilityBase::TryActivate(AActor* InstigatorActor)
{
	if (AbilityState != EAbilityState::Ready)
	{
		return false;
	}

	if (!InstigatorActor)
	{
		return false;
	}

	if (!CanActivate())
	{
		return false;
	}

	// Ability is activated, so set the Active State.
	AbilityState = EAbilityState::Active;
	ExecuteAbility(InstigatorActor);

	UE_LOG(LogTemp, Log, TEXT("Ability %s is activated by %s"), *AbilityName.ToString(), *InstigatorActor->GetName());

	return true;
}

bool UAbilityBase::CanActivate_Implementation() const
{
	return AbilityState == EAbilityState::Ready;
}

void UAbilityBase::ExecuteAbility_Implementation(AActor* InstigatorActor)
{
}

void UAbilityBase::FinishAbility()
{
	if (AbilityState != EAbilityState::Active)
	{
		UE_LOG(LogTemp, Warning, TEXT("FinishAbility called but ability is not active"));
		return;
	}

	if (Cooldown > 0.f)
	{
		AbilityState = EAbilityState::Cooldown;
		CooldownRemaining = Cooldown;
	}
	else
	{
		AbilityState = EAbilityState::Ready;
	}
}

void UAbilityBase::UpdateCooldown(float DeltaTime)
{
	if (AbilityState != EAbilityState::Cooldown)
	{
		return;
	}

	CooldownRemaining -= DeltaTime;

	if (CooldownRemaining <= 0.f)
	{
		CooldownRemaining = 0.f;
		AbilityState = EAbilityState::Ready;
		UE_LOG(LogTemp, Log, TEXT("Ability %s finished cooldown"), *AbilityName.ToString());
	}
}

EAbilityState UAbilityBase::GetAbilityState() const
{
	return AbilityState;
}

float UAbilityBase::GetCooldownRemaining() const
{
	return CooldownRemaining;
}

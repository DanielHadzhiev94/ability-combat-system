#include "UAbilityBase.h"
#include "GameFramework/Actor.h"

UAbilityBase::UAbilityBase()
{
	AbilityName = TEXT("BasicAbility");
}

void UAbilityBase::Activate_Implementation(AActor* InstigatorActor)
{
	if (!InstigatorActor)
	{
		return;
	}

	// Ability is activated, so set the Active State.
	AbilityState = EAbilityState::Active;

	UE_LOG(LogTemp, Warning,
	       TEXT("Ability %s activated"),
	       *AbilityName.ToString());
}

bool UAbilityBase::CanActivate_Implementation() const
{
	return AbilityState == EAbilityState::Ready;
}

void UAbilityBase::FinishAbility()
{
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

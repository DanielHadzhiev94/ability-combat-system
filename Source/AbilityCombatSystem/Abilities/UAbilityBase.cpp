#include "UAbilityBase.h"
#include "GameFramework/Actor.h"

UAbilityBase::UAbilityBase()
{
	AbilityName = TEXT("BasicAbility");
}

void UAbilityBase::InitializeAbility(AActor* InstigatorActor, UAbilityComponent* AbilityComponent)
{
	if (Initialized)
	{
		UE_LOG(LogTemp, Warning, TEXT("Ability %s is already initialized"), *AbilityName.ToString());
		return;
	}

	OwnerActor = InstigatorActor;
	OwnerAbilityComponent = AbilityComponent;
	Initialized = true;
}

bool UAbilityBase::TryActivate()
{
	if (AbilityState != EAbilityState::Ready)
	{
		return false;
	}

	if (!OwnerActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("Ability %s does not have owner"), *AbilityName.ToString());
		return false;
	}

	// if (!CanActivate())
	// {
	// 	return false;
	// }

	// Ability is activated, so set the Active State.
	AbilityState = EAbilityState::Active;
	ExecuteAbility();

	UE_LOG(LogTemp, Log, TEXT("Ability %s is activated by %s"), *AbilityName.ToString(), *OwnerActor->GetName());

	return true;
}

bool UAbilityBase::CanActivate_Implementation() const
{
	return AbilityState == EAbilityState::Ready;
}

void UAbilityBase::ExecuteAbility_Implementation()
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

AActor* UAbilityBase::GetOwnerActor() const
{
	return OwnerActor;
}

UAbilityComponent* UAbilityBase::GetOwnerAbilityComponent() const
{
	return OwnerAbilityComponent;
}

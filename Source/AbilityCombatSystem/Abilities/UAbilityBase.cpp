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

	UE_LOG(LogTemp, Warning,
	       TEXT("Ability %s activated"),
	       *AbilityName.ToString());
}

bool UAbilityBase::CanActivate_Implementation() const
{
	if (Cooldown > 0)
	{
		return true;
	}

	return false;
}

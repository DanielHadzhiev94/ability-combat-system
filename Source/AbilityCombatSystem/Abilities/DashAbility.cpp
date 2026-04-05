#include "DashAbility.h"
#include "GameFramework/Actor.h"

void UDashAbility::ExecuteAbility_Implementation()
{
	if (!OwnerActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("DashAbility failed: Owner actor is null"));
		FinishAbility();
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("%s is used by %s"), *AbilityName.ToString(), *OwnerActor->GetName());
	FinishAbility();
}

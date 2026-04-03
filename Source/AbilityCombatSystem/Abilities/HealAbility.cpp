// Fill out your copyright notice in the Description page of Project Settings.


#include "HealAbility.h"

void UHealAbility::ExecuteAbility_Implementation()
{
	if (!OwnerActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("HealAbility failed: OwnerActor is null!"));
		FinishAbility();
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("%s used by %s, amount healed %i"), *AbilityName.ToString(), *OwnerActor->GetName(),
	       HealAmount);

	FinishAbility();
}

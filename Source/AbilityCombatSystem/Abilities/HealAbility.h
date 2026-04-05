// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UAbilityBase.h"
#include "UObject/Object.h"
#include "HealAbility.generated.h"

/**
 * 
 */
UCLASS()
class ABILITYCOMBATSYSTEM_API UHealAbility : public UAbilityBase
{
	GENERATED_BODY()

protected:
	virtual void ExecuteAbility_Implementation() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Heal")
	int32 HealAmount = 25;
};

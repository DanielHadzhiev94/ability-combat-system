// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UAbilityBase.h"
#include "UObject/Object.h"
#include "DashAbility.generated.h"

/**
 * 
 */
UCLASS()
class ABILITYCOMBATSYSTEM_API UDashAbility : public UAbilityBase
{
	GENERATED_BODY()

protected:
	virtual void ExecuteAbility_Implementation() override;
};

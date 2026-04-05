// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UAbilityBase.h"
#include "UObject/Object.h"
#include "UFireballAbility.generated.h"

UCLASS()
class ABILITYCOMBATSYSTEM_API UFireballAbility : public UAbilityBase
{
	GENERATED_BODY()
	
public:
	virtual void ExecuteAbility_Implementation() override;
	
	
protected:
	// Projectile class that will be spawned when the ability executes
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Fireball")
	TSubclassOf<AActor> ProjectileClass;

	// Damage dealt by the fireball
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Fireball")
	float Damage = 20.f;

	// Offset from the owner actor where the projectile will spawn
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Fireball")
	FVector SpawnOffset = FVector(100.f, 0.f, 50.f);
};

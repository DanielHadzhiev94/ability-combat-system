// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UHealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeath);
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ABILITYCOMBATSYSTEM_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UHealthComponent();
	
	UPROPERTY(BlueprintAssignable, Category="Health")
	FOnDeath OnDeath;

	void ApplyDamage(float DamageAmount);

	void Heal(float HealAmount);

	UFUNCTION(BlueprintCallable, Category="Health")
	float GetCurrentHealth() const;

	UFUNCTION(BlueprintCallable, Category="Health")
	float GetMaxHealth() const;

	UFUNCTION(BlueprintCallable, Category="Health")
	bool IsDead() const;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Health")
	float MaxHealth = 100.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Health")
	float CurrentHealth = 0.f;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};

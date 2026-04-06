// Fill out your copyright notice in the Description page of Project Settings.


#include "UHealthComponent.h"


// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// Initialize Health
	CurrentHealth = MaxHealth;
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UHealthComponent::ApplyDamage(float DamageAmount)
{
	if (DamageAmount <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("DamageAmount is less or equals to 0"));
		return;
	}
	
	if (IsDead())
	{
		UE_LOG(LogTemp, Log, TEXT("Target has died."));
		return;
	}
	
	CurrentHealth = FMath::Clamp(CurrentHealth - DamageAmount, 0.f, MaxHealth);
	UE_LOG(LogTemp, Log, TEXT("Target was damaged for %f amount. Current Health: %f"), DamageAmount, CurrentHealth);
}

void UHealthComponent::Heal(float HealAmount)
{
	if (HealAmount <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("HealAmount is less or equals to 0"));
		return;
	}

	if (IsDead())
	{
		UE_LOG(LogTemp, Warning, TEXT("Cannot heal. Target is already dead"));
		return;
	}

	CurrentHealth = FMath::Clamp(CurrentHealth + HealAmount, 0.f, MaxHealth);

	UE_LOG(LogTemp, Log, TEXT("Target was healed for %f amount. Current Health: %f"), HealAmount, CurrentHealth);
}

float UHealthComponent::GetCurrentHealth() const
{
	return CurrentHealth;
}

float UHealthComponent::GetMaxHealth() const
{
	return MaxHealth;
}

bool UHealthComponent::IsDead() const
{
	return CurrentHealth <= 0;
}

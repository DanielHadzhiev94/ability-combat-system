// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatSystem/Components/UCharacterHealthComponent.h"

// Sets default values for this component's properties
UCharacterHealthComponent::UCharacterHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCharacterHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// Initialize Health
	CurrentHealth = MaxHealth;
	
}


// Called every frame
void UCharacterHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UCharacterHealthComponent::ApplyDamage(float DamageAmount)
{
	if (DamageAmount <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("DamageAmount is less or equals to 0"));
		return;
	}

	if (IsDead())
	{
		UE_LOG(LogTemp, Warning, TEXT("Target is already dead!"));
		return;
	}

	CurrentHealth = FMath::Clamp(CurrentHealth - DamageAmount, 0.f, MaxHealth);
	if (IsDead())
	{
		OnDeath.Broadcast();
	}
}

void UCharacterHealthComponent::Heal(float HealAmount)
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

float UCharacterHealthComponent::GetCurrentHealth() const
{
	return CurrentHealth;
}

float UCharacterHealthComponent::GetMaxHealth() const
{
	return MaxHealth;
}

bool UCharacterHealthComponent::IsDead() const
{
	return CurrentHealth <= 0;
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatSystem/Components/UAbilityComponent.h"

#include "Abilities/UAbilityBase.h"

UAbilityComponent::UAbilityComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UAbilityComponent::BeginPlay()
{
	Super::BeginPlay();

	for (TSubclassOf<UAbilityBase> AbilityClass : DefaultAbilities)
	{
		GrantAbility(AbilityClass);
	}
}

void UAbilityComponent::TickComponent(float DeltaTime, enum ELevelTick TickType,
                                      FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	for (UAbilityBase* Ability : GrantedAbilities)
	{
		if (!Ability)
		{
			continue;
		}

		Ability->UpdateCooldown(DeltaTime);
	}
}

void UAbilityComponent::GrantAbility(TSubclassOf<UAbilityBase> AbilityClass)
{
	if (!AbilityClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("GrantAbility failed: AbilityClass is null."));
		return;
	}

	UAbilityBase* NewAbility = NewObject<UAbilityBase>(this, AbilityClass);

	if (!NewAbility)
	{
		UE_LOG(LogTemp, Warning, TEXT("GrantAbility failed: Could not create ability instance."));
		return;
	}

	GrantedAbilities.Add(NewAbility);
}

void UAbilityComponent::TryActivateAbilityByIndex(const int32 AbilityIndex)
{
	if (!GrantedAbilities.IsValidIndex(AbilityIndex))
	{
		UE_LOG(LogTemp, Warning, TEXT("TryActivateAbilityByIndex failed: Invalid index %d"), AbilityIndex);
		return;
	}

	UAbilityBase* Ability = GrantedAbilities[AbilityIndex];

	if (!Ability)
	{
		UE_LOG(LogTemp, Warning, TEXT("TryActivateAbilityByIndex failed: Ability at index %d is null"), AbilityIndex);
		return;
	}

	if (!Ability->CanActivate())
	{
		UE_LOG(LogTemp, Warning, TEXT("TryActivateAbilityByIndex failed: Ability cannot activate."));
		return;
	}

	AActor* OwnerActor = GetOwner();

	if (!OwnerActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("TryActivateAbilityByIndex failed: Owner is null."));
		return;
	}

	Ability->Activate(OwnerActor);
	Ability->FinishAbility();
}

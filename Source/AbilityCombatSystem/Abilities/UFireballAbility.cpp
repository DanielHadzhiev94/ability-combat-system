// Fill out your copyright notice in the Description page of Project Settings.


#include "UFireballAbility.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Actor.h"

void UFireballAbility::ExecuteAbility_Implementation()
{
	if (!OwnerActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("FireballAbilty failed: Owner actor is null"));
		FinishAbility();
		return;
	}

	if (!ProjectileClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("FireballAbility failed: Projectile class is null"));
		FinishAbility();
		return;
	}

	UWorld* World = GetWorld();
	if (!World)
	{
		UE_LOG(LogTemp, Warning, TEXT("FireballAbility failed: World is null"));
		FinishAbility();
		return;
	}

	// Take the actor rotation
	const FRotator SpawnRotation = OwnerActor->GetActorRotation();

	// Calculate spawn direction  -> Actor location + rotation direction
	const FVector SpawnLocation = OwnerActor->GetActorLocation() + SpawnRotation.RotateVector(SpawnOffset);

	// Creating the spawn parameters
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.Owner = OwnerActor;
	SpawnParameters.Instigator = Cast<APawn>(OwnerActor);

	// Spawn of the projectile 
	AActor* SpawnProjectiles = World->SpawnActor<AActor>
		(ProjectileClass, SpawnLocation, SpawnRotation, SpawnParameters);
	if (!SpawnProjectiles)
	{
		UE_LOG(LogTemp, Warning, TEXT("FireballAbility failed: Could not spawn projectile."));
		FinishAbility();
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("FireballAbility spawned projectile %s"), *SpawnProjectiles->GetName());
	FinishAbility();
}

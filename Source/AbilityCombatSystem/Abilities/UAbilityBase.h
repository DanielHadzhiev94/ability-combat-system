#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UAbilityBase.generated.h"

class AActor;

UENUM(BlueprintType)
enum class EAbilityState: uint8
{
	Ready,
	Active,
	Cooldown,
};

UCLASS(Blueprintable, BlueprintType)
class ABILITYCOMBATSYSTEM_API UAbilityBase : public UObject
{
	GENERATED_BODY()

public:
	UAbilityBase();

	UFUNCTION(BluePrintNativeEvent)
	void Activate(AActor* InstigatorActor);

	UFUNCTION(BluePrintNativeEvent)
	bool CanActivate() const;

	UFUNCTION()
	void FinishAbility();

	UFUNCTION()
	void UpdateCooldown(float DeltaTime);

	UFUNCTION(BlueprintCallable, Category = "Ability")
	EAbilityState GetAbilityState() const;

	UFUNCTION(BlueprintCallable, Category="Ability")
	float GetCooldownRemaining() const;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ability")
	FName AbilityName;

	UPROPERTY()
	EAbilityState AbilityState = EAbilityState::Ready;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ability")
	float Cooldown = 0.f;

	UPROPERTY()
	float CooldownRemaining = 0.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ability")
	float ManaCost = 0.f;
};

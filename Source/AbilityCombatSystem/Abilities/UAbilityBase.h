#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UAbilityBase.generated.h"

class AActor;
class UAbilityComponent;

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
	
	void InitializeAbility(AActor* InstigatorActor, UAbilityComponent* AbilityComponent);
	
	bool TryActivate();

	UFUNCTION(BlueprintNativeEvent)
	bool CanActivate() const;
	
	UFUNCTION(BlueprintNativeEvent)
	void ExecuteAbility();

	UFUNCTION()
	void FinishAbility();

	UFUNCTION()
	void UpdateCooldown(float DeltaTime);

	UFUNCTION(BlueprintCallable, Category = "Ability")
	EAbilityState GetAbilityState() const;

	UFUNCTION(BlueprintCallable, Category="Ability")
	float GetCooldownRemaining() const;
	
	UFUNCTION(BlueprintCallable, Category="Ability")
	AActor* GetOwnerActor() const;
	
	UFUNCTION(BlueprintCallable, Category="Ability")
	UAbilityComponent* GetOwnerAbilityComponent() const;
	
protected:
	UPROPERTY()
	TObjectPtr<AActor> OwnerActor = nullptr;
	
	UPROPERTY()
	TObjectPtr<UAbilityComponent> OwnerAbilityComponent = nullptr;
	
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
	
private:
	bool Initialized;
};

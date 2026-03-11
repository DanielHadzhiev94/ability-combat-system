#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UAbilityBase.generated.h"

class AActor;

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

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ability")
	FName AbilityName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ability")
	float Cooldown = 0.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ability")
	float ManaCost = 0.f;
};

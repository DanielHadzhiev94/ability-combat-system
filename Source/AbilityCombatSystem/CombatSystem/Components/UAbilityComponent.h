#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UAbilityComponent.generated.h"

class UAbilityBase;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ABILITYCOMBATSYSTEM_API UAbilityComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAbilityComponent();

	void GrantAbility(TSubclassOf<UAbilityBase> AbilityClass);
	void TryActivateAbilityByIndex(int32 AbilityIndex);

protected:
	virtual void BeginPlay() override;
	

protected:
	UPROPERTY()
	TArray<TObjectPtr<UAbilityBase>> GrantedAbilities;
	
	UPROPERTY(EditDefaultsOnly, Category="Abilities")
	TArray<TSubclassOf<UAbilityBase>> DefaultAbilities;
};
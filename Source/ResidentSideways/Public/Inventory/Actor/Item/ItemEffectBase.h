// Copyright SleepyMilitiaGames

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ItemEffectBase.generated.h"

class UItemInfoAsset;
/**
 * 
 */
UCLASS(Blueprintable)
class RESIDENTSIDEWAYS_API UItemEffectBase : public UObject
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UseItem(AActor* Actor, int32 Index);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UItemInfoAsset> ItemInfo;
};

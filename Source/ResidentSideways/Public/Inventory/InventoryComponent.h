// Copyright SleepyMilitiaGames

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnItemAdded, UItemInfoAsset*, Item, int32, Amount);

struct FGameplayTag;
class UItemInfoAsset;

USTRUCT(BlueprintType)
struct FItemSlotInfo
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UItemInfoAsset* Item{nullptr};
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 AmountHeld{0};
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bSlotFilled{false};
}; 

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class RESIDENTSIDEWAYS_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UInventoryComponent();

	
	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnItemAdded OnItemAdded;
	
	UFUNCTION(BlueprintCallable, Category="Inventory")
	bool AddItem(UItemInfoAsset* Item, int32 AmountToAdd);
	
	TArray<FItemSlotInfo> GetInventory() const { return Inventory; };
	
	UFUNCTION(BlueprintCallable, Category="Inventory")
	void SetInventory(const TArray<FItemSlotInfo>& PlayerInventory) { this->Inventory = PlayerInventory; };
	
	FItemSlotInfo GetItemAtIndex(int32 Index) const { return Inventory[Index]; };


	int32 DoesHaveAmmo(const FGameplayTag AmmoTag);
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	UPROPERTY(BlueprintReadOnly, Category="Inventory")
	TArray<FItemSlotInfo> Inventory;

	UPROPERTY(BlueprintReadWrite, Category="Inventory")
	int32 InventorySize{20};

private:
	
	bool TryAddNewItem(UItemInfoAsset* Item, int32 AmountToAdd);
	
	void CheckEmptySlot(int32& Index, bool& bSlotFound);
	
	void SetInventoryArrayElement(int32 Index, UItemInfoAsset* Item, int32 AmoundHeld);

};

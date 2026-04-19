// Copyright SleepyMilitiaGames


#include "Inventory/InventoryComponent.h"
#include "Inventory/ItemInfoAsset.h"
#include "Kismet/KismetMathLibrary.h"


UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
	Inventory.SetNum(InventorySize);
}


bool UInventoryComponent::AddItem(UItemInfoAsset* Item, int32 AmountToAdd)
{
	if (!IsValid(Item) || AmountToAdd <= 0 )return false;
	if (Item->bIsStackable)
	{
		bool bSameItemFound{false};
		int32 ItemIndex{-1};
		for (int32 i = 0; i < Inventory.Num(); i++)
		{
			// Check if the items are the same.
			if (Inventory[i].Item == Item)
			{
				// if so, check if we can stack more.
				if (Inventory[i].AmountHeld < Item->MaxStackSize)
				{
					ItemIndex = i;
					bSameItemFound = true;
					break;
				}
				else bSameItemFound = false;
			}
			else bSameItemFound = false;
		}
		if (bSameItemFound)
		{
			int32 NewStackAmount = Inventory[ItemIndex].AmountHeld + AmountToAdd;
			if (NewStackAmount <= Item->MaxStackSize)
			{
				SetInventoryArrayElement(ItemIndex, Item, NewStackAmount);
				return true;
			}
			else
			{
				SetInventoryArrayElement(ItemIndex, Item, Item->MaxStackSize);
				int32 RemainingAmountToAdd = NewStackAmount - Item->MaxStackSize;
				return TryAddNewItem(Item, RemainingAmountToAdd);
			}
		}
		else
		{
			int32 EmptySlotIndex{-1};
			bool bEmptySlotFound{false};
			CheckEmptySlot(EmptySlotIndex, bEmptySlotFound);
			if (bEmptySlotFound)
			{
				if (AmountToAdd > Item->MaxStackSize)
				{
					SetInventoryArrayElement(EmptySlotIndex, Item, Item->MaxStackSize);
					int32 RemainingAmountToAdd = AmountToAdd - Item->MaxStackSize;
					return TryAddNewItem(Item, RemainingAmountToAdd);
				}
				else
				{
					return TryAddNewItem(Item, AmountToAdd);
				}
			}
			else return false;
		}
	}
	else
	{
		return TryAddNewItem(Item, AmountToAdd);
	}
}


bool UInventoryComponent::TryAddNewItem(UItemInfoAsset* Item, int32 AmountToAdd)
{
	if (!IsValid(Item) || AmountToAdd <= 0) return false;
	int32 Index{-1};
	bool bSlotFound{false};
	CheckEmptySlot(Index, bSlotFound);
	if (bSlotFound)
	{
		// Use MaxMagCapacity for amount held for Firearms only.
		if (Item->ItemType == EItemType::Weapon && Item->WeaponInfo.WeaponType == EWeaponType::Firearm)
		{
			SetInventoryArrayElement(Index, Item, Item->WeaponInfo.MaxMagCapacity);
		}
		else
		{
			SetInventoryArrayElement(Index, Item, AmountToAdd);
		}
		OnItemAdded.Broadcast(Item, AmountToAdd);
		return true;
	}
	else return false;
}

int32 UInventoryComponent::DoesHaveAmmo(const FGameplayTag AmmoTag)
{
	int32 AmountHeld{0};
	for (const FItemSlotInfo& Slot : Inventory)
	{
		if (Slot.bSlotFilled && Slot.Item->ItemTag == AmmoTag)
		{
			AmountHeld += Slot.AmountHeld;
		}
	}
	return AmountHeld;
}

void UInventoryComponent::CheckEmptySlot(int32& Index, bool& bSlotFound)
{
	Index = -1;
	bSlotFound = false;
	for (int32 i = 0; i < Inventory.Num(); i++)
	{
		const FItemSlotInfo& ItemSlot = Inventory[i];
		if (!ItemSlot.bSlotFilled)
		{
			Index = i;
			bSlotFound = true;
			return;
		}
	}
}

void UInventoryComponent::SetInventoryArrayElement(int32 Index, UItemInfoAsset* Item, int32 AmoundHeld)
{
	if (!Inventory.IsValidIndex(Index) || !IsValid(Item) || AmoundHeld <= 0) return;
	FItemSlotInfo NewItem;
	NewItem.Item = Item;
	NewItem.AmountHeld = AmoundHeld;
	NewItem.bSlotFilled = true;
	Inventory[Index] = NewItem;
}





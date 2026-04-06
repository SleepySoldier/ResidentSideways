// Copyright SleepyMilitiaGames

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ItemTypes.h"
#include "Engine/DataAsset.h"
#include "ItemInfoAsset.generated.h"

class UItemEffectBase;
class AWeaponBase;
struct FGameplayTag;

USTRUCT(BlueprintType)
struct FWeaponInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BasePower;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float FireRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxMagCapacity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EWeaponFireMode FireMode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftClassPtr<AWeaponBase> WeaponClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EWeaponType WeaponType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag FirearmAmmoTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName BarrelSocketName{FName("Barrel")};
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UAnimSequenceBase> WeaponAttackAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UAnimMontage> ActorAttackAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UAnimMontage> ActorReloadAnim;
	
};
/**
 * 
 */
UCLASS(BlueprintType)
class RESIDENTSIDEWAYS_API UItemInfoAsset : public UDataAsset
{
	GENERATED_BODY()

	public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base Info")
	FText ItemName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base Info")
	FText Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base Info")
	TSoftObjectPtr<UTexture2D> Icon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base Info")
	FGameplayTag ItemTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base Info")
	TSubclassOf<UItemEffectBase> ItemEffectClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base Info")
	EItemType ItemType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base Info")
	TObjectPtr<UStaticMesh> PickupMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base Info")
	bool bIsStackable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base Info")
	int32 MaxStackSize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	FWeaponInfo WeaponInfo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Medicine")
	float RestoreAmount;
};


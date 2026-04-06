// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"

class UItemInfoAsset;

UCLASS()
class RESIDENTSIDEWAYS_API AWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponBase();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void UseWeapon();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void EndUseWeapon();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ReloadFirearm();

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EditCustom")
	int32 RoundsInMag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EditCustom", meta = (ExposeOnSpawn=true))
	int32 WeaponItemIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EditCustom")
	TObjectPtr<UItemInfoAsset> WeaponInfo;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "EditCustom")
	TObjectPtr<USkeletalMeshComponent> SkeletalMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "EditCustom")
	TObjectPtr<USceneComponent> Root;

protected:
	virtual void BeginPlay() override;
	


private:

	

};

// Copyright SleepyMilitiaGames

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponProjectile.generated.h"

class UProjectileMovementComponent;
class USphereComponent;



UCLASS()
class RESIDENTSIDEWAYS_API AWeaponProjectile : public AActor
{
	GENERATED_BODY()

public:
	AWeaponProjectile();



protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere)
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> ProjectileMesh;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<USphereComponent> OverlapSphere;
	UPROPERTY(EditAnywhere)
	UProjectileMovementComponent* ProjectileMovement;
private:





	

};

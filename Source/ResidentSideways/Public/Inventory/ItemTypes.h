#pragma once

UENUM(BlueprintType)
enum class EItemType : uint8
{
	Consumable,
	Ammo,
	Weapon,
	KeyItem
};

UENUM(BlueprintType)
enum class EWeaponFireMode : uint8
{
	SemiAuto,
	FullAuto,
	BurstFire
};

UENUM(BlueprintType)
enum class EWeaponFireType : uint8
{
	HitScan,
	Spread,
	Projectile
};


UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	Melee,
	Firearm,
};
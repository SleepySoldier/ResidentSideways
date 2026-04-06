#pragma once

UENUM(BlueprintType)
enum class EItemType : uint8
{
	Consumable,
	Ammo,
	Weapon
};

UENUM(BlueprintType)
enum class EWeaponFireMode : uint8
{
	SemiAuto,
	FullAuto,
	BurstFire
};

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	Melee,
	Firearm,
};
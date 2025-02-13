// © 2016 - 2017 Daniel Bortfeld

#pragma once

#include "Etos/Utility/EnumLibrary.h"
#include "UpgradeData.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FUpgradeData : public FTableRowBase
{
	GENERATED_BODY()

public:

	// The name of the building
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName Name = FName(TEXT("New Building"));

	// The icon of the building
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture2D* BuildingIcon;

	// The upgraded mesh of the building
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName MeshPath;

	// The resources required to upgrade this building
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		TArray<FResource> UpgradeCost;

	// Can be e.g. MaxResidents or MaxStorage
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 NewMaximum;

	// If used for upgrading residents, this is their new level
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EResidentLevel ResidentLevel;

	// The time it takes for a building to produce a resource 
	// (or call its respective delay action)
	// 0 means dont call a delay action
	// < 0 means dont change through upgrade
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ProductionTime = -1;
};

// © 2016 - 2017 Daniel Bortfeld

#pragma once

#include "Resource.h"
#include "BuildingData.generated.h"

/**
*
*/
USTRUCT(BlueprintType)
struct FBuildingData
{
	GENERATED_BODY()

public:

	// The name of the building
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName Name = FName(TEXT("New Building"));
	// The icon of the building
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture2D* BuildingIcon;


	// Whether this building is held by the mouse of the player
	// true means it's not bulit and it follows the mouse
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool bIsHeld = false;
	// Whether something blocks the buildings position in buildmode (when it's held and not built)
	// true means you can't build here
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool bPositionIsBlocked = false;
	// Whether this building was built
	// Its built when the resources are spend for building and when 
	// it was placed in the world
	// It calls its delay action when built
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool bIsBuilt = false;
	// The resources required to build this building
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		TArray<FResource> BuildCost;
	// The paths this building could be connected with when it was built right here
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		TArray<class APath*> PossibleConnections;
	// The bulidings that could be in the radius of this building if it was built right here
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		TArray<class ABuilding*> PossibleBuildingsInRadius;


	// The Money this buildings needs per minute
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Upkeep;
	// The first resource needed for production
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FResource NeededResource1;
	// The second resource needed for production
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FResource NeededResource2;
	// The resource this building produces (or already has produced)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FResource ProducedResource;
	// The time it takes for a building to produce a resource 
	// (or call its respective delay action)
	// <= 0 means dont call a delay action
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ProductionTime;
	// The maximum amount of each needed and produced resources this 
	// building can store
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 MaxStoredResources;


	// The buildings inside the radius of this buildings
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		TArray<ABuilding*> BuildingsInRadius;
	// Whether there is already a market barrow on the way to this building
	// to get the resources
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool bBarrowIsOnTheWay;
	// The Path/Road tiles connected to this buildling
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		TArray<APath*> PathConnections;
	// The radius of the building in cm
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Radius;

public:

	FBuildingData(){}

	FBuildingData(const struct FPredefinedBuildingData& predefData);
};

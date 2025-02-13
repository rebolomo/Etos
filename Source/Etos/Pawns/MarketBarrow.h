// � 2016 - 2017 Daniel Bortfeld

#pragma once

#include "GameFramework/Character.h"
#include "Etos/Buildings/Base/Building.h"
#include "Etos/Buildings/Warehouse.h"
#include "Navigation/PathFollowingComponent.h"
#include "AIController.h"
#include "MarketBarrow.generated.h"

UCLASS()
class ETOS_API AMarketBarrow : public ACharacter
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere)
		FVector StartLocation;

	UPROPERTY(VisibleAnywhere)
		FVector TargetLocation;

	UPROPERTY(VisibleAnywhere)
		ABuilding* MyWorkplace;

	UPROPERTY(VisibleAnywhere)
		ABuilding* TargetBuilding;

	// the radius from the target location in which a completed move counts as successfull
	UPROPERTY(EditDefaultsOnly)
		float AcceptanceRadius;
private:

	UPROPERTY()
		AAIController* MyController;

	UPROPERTY(VisibleAnywhere)
		FResource Resource;

	UPROPERTY()
		bool bArrivedAtTarget = false;

	UPROPERTY()
		bool bIsActive;

	UPROPERTY()
		bool bCheckedOut = false;

public:
	// Sets default values for this character's properties
	AMarketBarrow();

	static AMarketBarrow* Construct(UObject* WorldContextObject, TSubclassOf<AMarketBarrow> ClassToSpawn, const FVector& SpawnLocation, const FVector& TargetLocation, ABuilding * MyWorkplace, ABuilding* TargetBuilding, EResource OrderedResource, const FRotator& Rotation = FRotator(), const FActorSpawnParameters& SpawnParameters = FActorSpawnParameters());

	virtual void BeginDestroy() override;

	void ResetBarrow(const FVector & SpawnLocation, const FVector & TargetLocation, ABuilding * MyWorkplace, ABuilding * TargetBuilding, EResource OrderedResource, const FRotator & Rotation = FRotator());

	void StartWork();

	bool IsActive() { return bIsActive; }

	void SetActive(bool isActive);

	FResource GetTransportedResource();

	UFUNCTION(BlueprintImplementableEvent, Category = "Resources", meta = (DisplayName = "OnGetResource"))
		void BPEvent_OnGetResource(const FResource& TransportedResource);

	UFUNCTION(BlueprintImplementableEvent, Category = "Reset", meta = (DisplayName = "OnReset"))
		void BPEvent_OnReset();

private:

	UFUNCTION()
		void OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type MovementResult);

	AAIController* GetAIController();

	void BindToOnMoveCompleted();

	void MoveToTarget();

	void GetResource();

	void MoveBackToWorkplace();

	void AddResourceToWorkplace();

	void HaveLunchBreak();

	void SetCanEverAffectNavigationOnComponents(bool bRelevance);

	void CheckOut_Checked();
};

// © 2016 - 2017 Daniel Bortfeld

#pragma once // unreal somehow does not generate a generated.h file when using #ifndef

class UBoxCollider;

#include "Components/SceneComponent.h"
#include "BoxCollider.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCollisionDelegate, UBoxCollider*, other);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ETOS_API UBoxCollider : public USceneComponent
{
	GENERATED_BODY()

public:

	UPROPERTY()
		FName ActorName;

	UPROPERTY()
		UBoxComponent* Collider;

	UPROPERTY()
		FCollisionDelegate OnTriggerEnter;

	UPROPERTY()
		FCollisionDelegate OnTriggerStay;

	UPROPERTY()
		FCollisionDelegate OnTriggerExit;

private:

	UPROPERTY()
		TArray <UBoxCollider*> collisions;

	UPROPERTY()
		bool bGenerateCollisionEvents = true;

	UPROPERTY()
		TEnumAsByte<EComponentMobility::Type> mobilityType = EComponentMobility::Movable;

public:
	// Sets default values for this component's properties
	UBoxCollider();

	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	bool CheckCollision(UBoxCollider* other);

	bool GetGenerateCollisionEvents();

	void SetGenerateCollisionEvents(bool shouldGenerate);

	void RegisterCollider();

	void UnregisterCollider();

	void SetMobilityType(EComponentMobility::Type newMobilityType);

	EComponentMobility::Type GetMobilityType();

	bool IsInside(UBoxCollider* other);
};

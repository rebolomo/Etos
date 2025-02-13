// © 2016 - 2017 Daniel Bortfeld

#include "Etos.h"
#include "SimpleCollisionManager.h"
#include "BoxCollider.h"

// Sets default values
ASimpleCollisionManager::ASimpleCollisionManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called every frame
void ASimpleCollisionManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CheckCollisions();
}

void ASimpleCollisionManager::RegisterCollider(UBoxCollider * Collider)
{
	if (!Collider->IsValidLowLevel())
		return;

	switch (Collider->GetMobilityType())
	{
	case EComponentMobility::Static:
	case EComponentMobility::Stationary:
		staticColliders.AddUnique(Collider);
		break;
	case EComponentMobility::Movable:
		dynamicColliders.AddUnique(Collider);
		break;
	default:
		UE_LOG(LogTemp, Warning, TEXT("%s: Collider could not be registered"), *Collider->GetName());
		break;
	}
}

void ASimpleCollisionManager::UnregisterCollider(UBoxCollider * Collider)
{
	if (Collider->IsValidLowLevel())
	{
		if (staticColliders.Contains(Collider))
		{
			Collider->SetGenerateCollisionEvents(false);
			for (UBoxCollider* A : staticColliders)
			{
				if (A && A->IsValidLowLevel())
				{
					A->CheckCollision(Collider);
				}
			}
			staticColliders.Remove(Collider);
		}
		else if (dynamicColliders.Contains(Collider))
		{
			Collider->SetGenerateCollisionEvents(false);
			for (UBoxCollider* A : dynamicColliders)
			{
				if (A && A->IsValidLowLevel())
				{
					A->CheckCollision(Collider);
				}
			}
			dynamicColliders.Remove(Collider);
		}
	}
	else
	{
		if (staticColliders.Contains(Collider))
		{
			staticColliders.Remove(Collider);
			staticColliders.Shrink();
		}
		else if (dynamicColliders.Contains(Collider))
		{
			dynamicColliders.Remove(Collider);
			dynamicColliders.Shrink();
		}
	}
}

inline bool ASimpleCollisionManager::IsRegistered(UBoxCollider * Collider)
{
	return staticColliders.Contains(Collider) || dynamicColliders.Contains(Collider);
}

void ASimpleCollisionManager::CheckCollisions()
{
	bool bEverythingIsAwesome = true;

	for (UBoxCollider* A : dynamicColliders)
	{
		if (A && A->IsValidLowLevel())
		{
			for (UBoxCollider* B : dynamicColliders)
			{
				if (A != B)
				{
					if (B && B->IsValidLowLevel())
					{
						A->CheckCollision(B);
					}
					else bEverythingIsAwesome = false;
				}
			}
			for (UBoxCollider* B : staticColliders)
			{
				if (A != B)
				{
					if (B && B->IsValidLowLevel())
					{
						A->CheckCollision(B);
					}
					else bEverythingIsAwesome = false;
				}
			}
		}
		else bEverythingIsAwesome = false;
	}

	if (!bEverythingIsAwesome)
	{// remove invalid entries
		staticColliders.Shrink();
		dynamicColliders.Shrink();
		//for (int32 i = 0; i < registeredColliders.Num(); ++i)
		//{
		//	if (!registeredColliders[i]->IsValidLowLevel())
		//	{
		//		UnregisterCollider(registeredColliders[i]);
		//	}
		//}
	}
}


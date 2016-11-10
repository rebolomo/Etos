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

// Called when the game starts or when spawned
void ASimpleCollisionManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASimpleCollisionManager::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	CheckCollisions();
}

void ASimpleCollisionManager::RegisterCollider(UBoxCollider * Collider)
{
	registeredColliders.AddUnique(Collider);
}

void ASimpleCollisionManager::UnregisterCollider(UBoxCollider * Collider)
{
	registeredColliders.Remove(Collider);
}

void ASimpleCollisionManager::CheckCollisions()
{
	for (UBoxCollider* A : registeredColliders)
	{
		for (UBoxCollider* B : registeredColliders)
		{
			if (A && B && A != B)
			{
				if (A->IsActive() && !A->IsBeingDestroyed())
				{
					if (B->IsActive() && !B->IsBeingDestroyed())
					{
						A->CheckCollision(B);
					}
				}
			}
		}
	}
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "SExplodingBarrel.h"

#include "PhysicsEngine/RadialForceComponent.h"

const float ASExplodingBarrel::EXPLOSION_RADIUS = 900.f;
const float ASExplodingBarrel::EXPLOSION_STRENGTH = 2000.f;
const FName ASExplodingBarrel::COLLISION_PROFILE = "PhysicsActor";

// Sets default values
ASExplodingBarrel::ASExplodingBarrel()
{
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	RootComponent = StaticMeshComponent;
	StaticMeshComponent->SetSimulatePhysics(true);
	StaticMeshComponent->OnComponentHit.AddDynamic(this, &ASExplodingBarrel::HandleOnComponentHit);
	StaticMeshComponent->SetCollisionProfileName(COLLISION_PROFILE);

	RadialForceComponent = CreateDefaultSubobject<URadialForceComponent>("RadialForceComponent");
	RadialForceComponent->Radius = EXPLOSION_RADIUS;
	RadialForceComponent->ImpulseStrength = EXPLOSION_STRENGTH;
	RadialForceComponent->bImpulseVelChange = true;
	
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASExplodingBarrel::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASExplodingBarrel::HandleOnComponentHit(UPrimitiveComponent* PrimitiveComponent, AActor* Actor,
	UPrimitiveComponent* PrimitiveComponent1, FVector Vector, const FHitResult& HitResult)
{
	RadialForceComponent->FireImpulse();
}

// Called every frame
void ASExplodingBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


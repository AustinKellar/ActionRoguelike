// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SExplodingBarrel.generated.h"

class UStaticMeshComponent;
class URadialForceComponent;

UCLASS(Blueprintable)
class ACTIONROGUELIKE_API ASExplodingBarrel : public AActor
{
	GENERATED_BODY()

private:
	static const float EXPLOSION_RADIUS;
	static const float EXPLOSION_STRENGTH;
	static const FName COLLISION_PROFILE;
	
public:
	// Sets default values for this actor's properties
	ASExplodingBarrel();

protected:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(VisibleAnywhere)
	URadialForceComponent* RadialForceComponent;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	
	UFUNCTION()
	void HandleOnComponentHit(UPrimitiveComponent* PrimitiveComponent, AActor* Actor, UPrimitiveComponent* PrimitiveComponent1, FVector Vector, const FHitResult& HitResult);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

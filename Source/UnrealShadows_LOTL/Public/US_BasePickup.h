// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "US_BasePickup.generated.h"

class USphereComponent;
class UStaticMeshComponent;

UCLASS()
class UNREALSHADOWS_LOTL_API AUS_BasePickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUS_BasePickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor*OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool
		bFromSweep, const FHitResult& SweepResult);

	// BlueprintNativeEvent, if 
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category ="Pickup", meta = (DisplayName = "Pickup"))
	void Pickup(class AUS_Character* OwningCharacter);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	FORCEINLINE USphereComponent* GetSphereCollision() const { return SphereCollision;}
	FORCEINLINE UStaticMeshComponent* GetMesh() const { return Mesh; }

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USphereComponent> SphereCollision;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components",	meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> Mesh;
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "US_BasePickup.h"
#include "PlayerClass/US_Character.h"
#include "Components/SphereComponent.h"

// Sets default values
AUS_BasePickup::AUS_BasePickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereCollision = CreateDefaultSubobject<USphereComponent>("Collision");
	RootComponent = SphereCollision;
	SphereCollision->SetGenerateOverlapEvents(true);
	SphereCollision->SetSphereRadius(200.0f);
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(SphereCollision);
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	bReplicates = true;
}

// Called when the game starts or when spawned
void AUS_BasePickup::BeginPlay()
{
	Super::BeginPlay();
	
	SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &AUS_BasePickup::OnBeginOverlap);

}

void AUS_BasePickup::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (const auto Character = Cast<AUS_Character>(OtherActor))
	{
		Pickup(Character);
	}
}

void AUS_BasePickup::Pickup_Implementation(AUS_Character* OwningCharacter)
{
	SetOwner(OwningCharacter);
}

// Called every frame
void AUS_BasePickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


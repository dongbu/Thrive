// Copyright (C) 2013-2017  Revolutionary Games

#include "Thrive.h"
#include "OrganelleContainerComponent.h"


// Sets default values for this component's properties
UOrganelleContainerComponent::UOrganelleContainerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOrganelleContainerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UOrganelleContainerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

TArray<FVector2D> UOrganelleContainerComponent::getOrganellePoints() {
	TArray<USceneComponent*> organelles;

	GetChildrenComponents(false, organelles);
	FString debug = "Organelle container size: " + FString::FromInt(organelles.Num());
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, debug);

	TArray<FVector2D> result;
	for (USceneComponent* organelleScene : organelles) {
		UOrganelleComponent* organelle = (UOrganelleComponent*)organelleScene;
		result.Append(organelle->getPoints());
	}

	return result;
}


#include "Cartero/Actors/SmartObjects/CT_SmartObjectRouter.h"
#include "Components/SplineComponent.h"

ACT_SmartObjectRouter::ACT_SmartObjectRouter() : Super()
{
	SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComponent"));
	SplineComponent->SetupAttachment(RootComponent);

#if WITH_EDITOR
	SplineComponent->bDrawDebug = true;
#endif
}

void ACT_SmartObjectRouter::BeginPlay()
{
	Super::BeginPlay();

	FillSplinePoints();
}

// Rellenar el camino con puntos del mundo.
void ACT_SmartObjectRouter::FillSplinePoints()
{
	for (int32 Index = 0; Index <= SplineComponent->GetNumberOfSplinePoints(); ++Index)
	{
		SplinePoints.Add(SplineComponent->GetLocationAtSplinePoint(Index, ESplineCoordinateSpace::World));
	}
}

const TArray<FVector>& ACT_SmartObjectRouter::GetSplinePoints() const
{
	return SplinePoints;
}

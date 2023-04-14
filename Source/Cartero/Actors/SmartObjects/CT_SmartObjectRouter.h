#pragma once

#include "CoreMinimal.h"
#include "Cartero/Actors/SmartObjects/CT_SmartObjectBase.h"
#include "CT_SmartObjectRouter.generated.h"

class USplineComponent;

UCLASS()
class CARTERO_API ACT_SmartObjectRouter : public ACT_SmartObjectBase
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, Category = "Router")
		USplineComponent* SplineComponent = nullptr;

	ACT_SmartObjectRouter();

	void FillSplinePoints();

	const TArray<FVector>& GetSplinePoints() const;

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY()
		TArray<FVector> SplinePoints;
};

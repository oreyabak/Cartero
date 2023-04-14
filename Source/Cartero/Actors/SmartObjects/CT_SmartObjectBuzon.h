
#pragma once

#include "CoreMinimal.h"
#include "Cartero/Actors/SmartObjects/CT_SmartObjectBase.h"
#include "CT_SmartObjectBuzon.generated.h"

UENUM()
enum class PackColor : uint8
{
	NONE = 0, RED, GREEN, BLUE
};

class USphereComponent;
class UStaticMeshComponent;

UCLASS()
class CARTERO_API ACT_SmartObjectBuzon : public ACT_SmartObjectBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		USphereComponent* SphereComponent = nullptr;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* StaticMeshComponentBase = nullptr;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* StaticMeshComponentPackRed = nullptr;
	
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* StaticMeshComponentPackGreen = nullptr;
	
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* StaticMeshComponentPackBlue = nullptr;

	UPROPERTY(EditAnywhere)
		PackColor TypePackColor;

	ACT_SmartObjectBuzon();

protected:

	virtual void BeginPlay() override;

	UFUNCTION()
		void OnPutPack();

private:

	PackColor HavePack;

	UFUNCTION()
		void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:

	FVector BuzonLocation;

	FORCEINLINE PackColor GetHavePack() const { return HavePack; }

	PackColor GivePack();
	
	void ResetPack();
};

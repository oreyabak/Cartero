#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Cartero/Actors/SmartObjects/CT_SmartObjectBuzon.h"
#include "CT_CarteroCharacter.generated.h"

class UBehaviorTree;
class ACT_SmartObjectBase;

DECLARE_DELEGATE_OneParam(FSmartObjectChanged, ACT_SmartObjectBase*)

UCLASS()
class CARTERO_API ACT_CarteroCharacter : public ACharacter
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditDefaultsOnly)
		UBehaviorTree* BehaviorTree = nullptr;
	
	UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* StaticMeshRedPack = nullptr;

	UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* StaticMeshGreenPack = nullptr;

	UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* StaticMeshBluePack = nullptr;

	UPROPERTY(EditAnywhere, Category = "AI")
		ACT_SmartObjectBase* CurrentSmartObject = nullptr;

	UPROPERTY()
		ACT_SmartObjectBase* MainSmartObject = nullptr;

	FSmartObjectChanged OnSmartObjectChanged;

	ACT_CarteroCharacter();

	void ResetSmartObject();
	void SetCurrentSmartObject(ACT_SmartObjectBase* NewSmartObject);

protected:

	virtual void BeginPlay() override;

public:

	bool HasPack(PackColor pack);

	bool TakePack(PackColor pack);
	
	bool GivePack(PackColor pack);

};

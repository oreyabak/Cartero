#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CT_SmartObjectBase.generated.h"

class UBehaviorTree;
class UArrowComponent;
class UBillboardComponent;

UCLASS()
class CARTERO_API ACT_SmartObjectBase : public AActor
{
	GENERATED_BODY()
	
public:	

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI")
		UBehaviorTree* BehaviorTree = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UBillboardComponent* BillboardComponent = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UArrowComponent* ArrowComponent = nullptr;

	ACT_SmartObjectBase();

};

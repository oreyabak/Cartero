#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CT_CarteroController.generated.h"

class UBehaviorTreeComponent;
class UBlackboardComponent;
class ACT_SmartObjectBase;
class ACT_CarteroCharacter;

UCLASS()
class CARTERO_API ACT_CarteroController : public AAIController
{
	GENERATED_BODY()

public:

	UPROPERTY()
		UBehaviorTreeComponent* BehaviorTreeComponent = nullptr;

	UPROPERTY()
		UBlackboardComponent* BlackboardComponent = nullptr;

	ACT_CarteroController();

protected:

	UPROPERTY()
		ACT_CarteroCharacter* CurrentAgent = nullptr;

	virtual void BeginPlay() override;

	virtual void OnPossess(APawn* InPawn) override;

private:

	void SmartObjectChanged(ACT_SmartObjectBase* NewSmartObject);
};

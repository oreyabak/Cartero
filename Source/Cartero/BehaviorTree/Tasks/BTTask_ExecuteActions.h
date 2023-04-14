#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_ExecuteActions.generated.h"

UCLASS()
class CARTERO_API UBTTask_ExecuteActions : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:

	UBTTask_ExecuteActions();

protected:

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};

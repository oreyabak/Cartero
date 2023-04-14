#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_BuzonRestore.generated.h"

UCLASS()
class CARTERO_API UBTTask_BuzonRestore : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:

	UBTTask_BuzonRestore();

protected:

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};

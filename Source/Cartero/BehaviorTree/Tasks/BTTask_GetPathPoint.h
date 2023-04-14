#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_GetPathPoint.generated.h"

UCLASS()
class CARTERO_API UBTTask_GetPathPoint : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:

	UBTTask_GetPathPoint();

private:

	int32 Index = 0;

protected:

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

};

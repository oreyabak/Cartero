#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_HaveWork.generated.h"

UCLASS()
class CARTERO_API UBTTask_HaveWork : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:

	UBTTask_HaveWork();

protected:

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};

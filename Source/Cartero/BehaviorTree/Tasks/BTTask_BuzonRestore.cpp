
#include "BTTask_BuzonRestore.h"

#include "Cartero/Characters/CT_CarteroCharacter.h"
#include "Cartero/Actors/SmartObjects/CT_SmartObjectBuzon.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_BuzonRestore::UBTTask_BuzonRestore() : Super()
{
	bCreateNodeInstance = true;
}

EBTNodeResult::Type UBTTask_BuzonRestore::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* MyController = OwnerComp.GetAIOwner();
	ACT_CarteroCharacter* MyCartero = MyController ? Cast<ACT_CarteroCharacter>(MyController->GetPawn()) : nullptr;
	if (!MyCartero) return EBTNodeResult::Failed;

	MyCartero->ResetSmartObject();

	return EBTNodeResult::Succeeded;
}
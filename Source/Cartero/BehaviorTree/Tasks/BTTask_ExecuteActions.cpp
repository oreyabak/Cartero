#include "BTTask_ExecuteActions.h"
#include "Cartero/Characters/CT_CarteroCharacter.h"
#include "Cartero/Actors/SmartObjects/CT_SmartObjectBuzon.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_ExecuteActions::UBTTask_ExecuteActions()
{
	bCreateNodeInstance = true;
}

EBTNodeResult::Type UBTTask_ExecuteActions::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
	AAIController* MyController = OwnerComp.GetAIOwner();
	ACT_CarteroCharacter* MyCartero = MyController ? Cast<ACT_CarteroCharacter>(MyController->GetPawn()) : nullptr;
	//if (!MyCartero || !BlackboardComponent) return EBTNodeResult::Failed;
	if (!MyCartero) return EBTNodeResult::Failed;

	ACT_SmartObjectBuzon* SmartObjectBuzon = Cast<ACT_SmartObjectBuzon>(MyCartero->CurrentSmartObject);
	if (!SmartObjectBuzon) return EBTNodeResult::Failed;

	// Dejar el paquete por color.
	MyCartero->GivePack(SmartObjectBuzon->TypePackColor);
	
	// Tomar paquete si hay.
	if (SmartObjectBuzon->GetHavePack() != PackColor::NONE && !MyCartero->HasPack(SmartObjectBuzon->GetHavePack()))
	{
		MyCartero->TakePack(SmartObjectBuzon->GivePack());
	}

	return EBTNodeResult::Succeeded;
}
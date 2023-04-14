
#include "BTTask_HaveWork.h"
#include "Cartero/Characters/CT_CarteroCharacter.h"
#include "Cartero/Actors/SmartObjects/CT_SmartObjectBuzon.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"

UBTTask_HaveWork::UBTTask_HaveWork() : Super()
{
	bCreateNodeInstance = true;
}

EBTNodeResult::Type UBTTask_HaveWork::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
	AAIController* MyController = OwnerComp.GetAIOwner();
	ACT_CarteroCharacter* MyCartero = MyController ? Cast<ACT_CarteroCharacter>(MyController->GetPawn()) : nullptr;
	if (!MyCartero || !BlackboardComponent) return EBTNodeResult::Failed;
	
	ACT_SmartObjectBuzon* SmartObjectBuzon = Cast<ACT_SmartObjectBuzon>(MyCartero->CurrentSmartObject);
	if (!SmartObjectBuzon) return EBTNodeResult::Failed;

	BlackboardComponent->SetValue<UBlackboardKeyType_Vector>("BuzonLocation", SmartObjectBuzon->BuzonLocation);

	// Si el cartero tiene que entregar paquete.
	if (MyCartero->HasPack(SmartObjectBuzon->TypePackColor))
		return EBTNodeResult::Succeeded;
	
	// Si hay paquete a distribuir y el cartero tiene hueco (el cartero solo puede llevar un paquerte de un color).
	if (SmartObjectBuzon->GetHavePack() != PackColor::NONE && !MyCartero->HasPack(SmartObjectBuzon->GetHavePack()))
		return EBTNodeResult::Succeeded;

	return EBTNodeResult::Failed;
}
#include "BTTask_GetPathPoint.h"
#include "Cartero/Characters/CT_CarteroCharacter.h"
#include "Cartero/Actors/SmartObjects/CT_SmartObjectRouter.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"

UBTTask_GetPathPoint::UBTTask_GetPathPoint() : Super()
{
	bCreateNodeInstance = true;
}

EBTNodeResult::Type UBTTask_GetPathPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
	AAIController* MyController = OwnerComp.GetAIOwner();
	ACT_CarteroCharacter* MyCartero = MyController ? Cast<ACT_CarteroCharacter>(MyController->GetPawn()) : nullptr;
	if (!MyCartero || !BlackboardComponent) return EBTNodeResult::Failed;

	ACT_SmartObjectRouter* SmartObjectRouter = Cast<ACT_SmartObjectRouter>(MyCartero->CurrentSmartObject);
	// Referencia al array, para no hacer copia.
	const TArray<FVector>& SplinePoints = SmartObjectRouter ? SmartObjectRouter->GetSplinePoints() : TArray<FVector>();
	if (SplinePoints.IsEmpty()) return EBTNodeResult::Succeeded;

	BlackboardComponent->SetValue<UBlackboardKeyType_Vector>("SplineLocation", SplinePoints[Index]);
	if (Index < SplinePoints.Num() - 1)
	{
		Index++;
	}
	else
	{
		Index = 0;
	}

	return EBTNodeResult::Succeeded;
}
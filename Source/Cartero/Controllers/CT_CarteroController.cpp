#include "Cartero/Controllers/CT_CarteroController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "Cartero/Actors/SmartObjects/CT_SmartObjectRouter.h"
#include "Cartero/Actors/SmartObjects/CT_SmartObjectBase.h"
#include "GamePlayTags/Classes/GamePlayTagContainer.h"
#include "Cartero/Characters/CT_CarteroCharacter.h"


ACT_CarteroController::ACT_CarteroController() : Super()
{
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaivorTreeComponent"));
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
}

void ACT_CarteroController::BeginPlay()
{
	Super::BeginPlay();
	if (!CurrentAgent) return;

	SmartObjectChanged(CurrentAgent->CurrentSmartObject);
}

void ACT_CarteroController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	ACT_CarteroCharacter* Cartero = Cast<ACT_CarteroCharacter>(InPawn);
	UBehaviorTree* BehaviorTree = Cartero ? Cartero->BehaviorTree : nullptr;
	if (BehaviorTree)
	{
		BlackboardComponent->InitializeBlackboard(*BehaviorTree->GetBlackboardAsset());
		BehaviorTreeComponent->StartTree(*BehaviorTree);
	}

	CurrentAgent = Cast<ACT_CarteroCharacter>(GetPawn());
	CurrentAgent->OnSmartObjectChanged.BindUObject(this, &ACT_CarteroController::SmartObjectChanged);
	
}

void ACT_CarteroController::SmartObjectChanged(ACT_SmartObjectBase* NewSmartObject)
{
	if (NewSmartObject)
	{
		FGameplayTag SubTag;
		BehaviorTreeComponent->SetDynamicSubtree(SubTag, NewSmartObject->BehaviorTree);
	}
}
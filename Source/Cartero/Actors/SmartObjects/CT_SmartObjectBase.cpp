#include "Cartero/Actors/SmartObjects/CT_SmartObjectBase.h"
#include "Components/BillboardComponent.h"
#include "Components/ArrowComponent.h"

ACT_SmartObjectBase::ACT_SmartObjectBase() : Super()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	BillboardComponent = CreateDefaultSubobject<UBillboardComponent>(TEXT("BillboardComponent"));
	ArrowComponent = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));

	BillboardComponent->SetupAttachment(RootComponent);
	ArrowComponent->SetupAttachment(RootComponent);
}

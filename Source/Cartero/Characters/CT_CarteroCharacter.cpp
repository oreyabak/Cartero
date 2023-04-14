#include "Cartero/Characters/CT_CarteroCharacter.h"
#include "Cartero/Actors/SmartObjects/CT_SmartObjectBuzon.h"
#include "components/StaticMeshComponent.h"


ACT_CarteroCharacter::ACT_CarteroCharacter()
{
	StaticMeshRedPack = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshRedPack"));
	StaticMeshRedPack->SetupAttachment(RootComponent);
	StaticMeshRedPack->SetVisibility(false);

	StaticMeshGreenPack = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshGreenPack"));
	StaticMeshGreenPack->SetupAttachment(RootComponent);
	StaticMeshGreenPack->SetVisibility(false);

	StaticMeshBluePack = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshBluePack"));
	StaticMeshBluePack->SetupAttachment(RootComponent);
	StaticMeshBluePack->SetVisibility(false);
}

void ACT_CarteroCharacter::ResetSmartObject()
{
	SetCurrentSmartObject(MainSmartObject);
}

void ACT_CarteroCharacter::SetCurrentSmartObject(ACT_SmartObjectBase* NewSmartObject)
{
	CurrentSmartObject = NewSmartObject;
	OnSmartObjectChanged.ExecuteIfBound(CurrentSmartObject);
}

void ACT_CarteroCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (CurrentSmartObject)
	{
		MainSmartObject = CurrentSmartObject;
	}
}

////////////////////////////////////////////////////////// PACKS
bool ACT_CarteroCharacter::HasPack(PackColor pack)
{
	if (pack == PackColor::RED && StaticMeshRedPack->IsVisible()) return true;
	if (pack == PackColor::BLUE && StaticMeshBluePack->IsVisible()) return true;
	return (pack == PackColor::GREEN && StaticMeshGreenPack->IsVisible());
}

bool ACT_CarteroCharacter::TakePack(PackColor pack)
{
	// Solo puede llevar un paquete del mismo color.
	if (pack == PackColor::RED)
	{
		if (StaticMeshRedPack->IsVisible()) return false;
		StaticMeshRedPack->SetVisibility(true);
	}
	else if (pack == PackColor::GREEN)
	{
		if (StaticMeshGreenPack->IsVisible()) return false;
		StaticMeshGreenPack->SetVisibility(true);
	}
	else if (pack == PackColor::BLUE)
	{
		if (StaticMeshBluePack->IsVisible()) return false;
		StaticMeshBluePack->SetVisibility(true);
	}
	else return false;
	
	return true;
}

bool ACT_CarteroCharacter::GivePack(PackColor pack)
{
	// Solo puede dar paquete si lo tiene.
	if (pack == PackColor::RED)
	{
		if (!StaticMeshRedPack->IsVisible()) return false;
		StaticMeshRedPack->SetVisibility(false);
	}
	else if (pack == PackColor::GREEN)
	{
		if (!StaticMeshGreenPack->IsVisible()) return false;
		StaticMeshGreenPack->SetVisibility(false);
	}
	else if (pack == PackColor::BLUE)
	{
		if (!StaticMeshBluePack->IsVisible()) return false;
		StaticMeshBluePack->SetVisibility(false);
	}
	else return false;

	return true;
}
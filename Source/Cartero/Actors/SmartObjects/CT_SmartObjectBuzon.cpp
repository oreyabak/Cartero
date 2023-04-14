
#include "Cartero/Actors/SmartObjects/CT_SmartObjectBuzon.h"
#include "Cartero/Characters/CT_CarteroCharacter.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

ACT_SmartObjectBuzon::ACT_SmartObjectBuzon() : Super()
{
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereComponent->SetupAttachment(RootComponent);

	StaticMeshComponentBase = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base"));
	StaticMeshComponentBase->SetupAttachment(RootComponent);

	StaticMeshComponentPackRed = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PackRed"));
	StaticMeshComponentPackRed->SetupAttachment(StaticMeshComponentBase);

	StaticMeshComponentPackGreen = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PackGreen"));
	StaticMeshComponentPackGreen->SetupAttachment(StaticMeshComponentBase);

	StaticMeshComponentPackBlue = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PackBlue"));
	StaticMeshComponentPackBlue->SetupAttachment(StaticMeshComponentBase);

	ResetPack();
}

void ACT_SmartObjectBuzon::BeginPlay()
{
	SphereComponent->OnComponentBeginOverlap.AddUniqueDynamic(this, &ACT_SmartObjectBuzon::OnComponentBeginOverlap);
	
	FTimerHandle FuzeTimerHandle;
	GetWorld()->GetTimerManager().SetTimer(FuzeTimerHandle, this, &ACT_SmartObjectBuzon::OnPutPack, 10, true);

	BuzonLocation = this->GetActorLocation();
}

void ACT_SmartObjectBuzon::OnPutPack()
{
	if (HavePack != PackColor::NONE) return;

	//        | 0-49   | 50-99
	// Red    | Green  | Blue
	// Green  | Red    | Blue
	// Blue   | Red    | Green
	if (FMath::RandRange(0, 99) < 50)
	{
		if (TypePackColor == PackColor::RED)
		{
			if (StaticMeshComponentPackGreen)
			{
				HavePack = PackColor::GREEN;
				StaticMeshComponentPackGreen->SetVisibility(true);
			}
		}
		else if (StaticMeshComponentPackRed)
		{
			HavePack = PackColor::RED;
			StaticMeshComponentPackRed->SetVisibility(true);
		}
	}
	else
	{
		if (TypePackColor == PackColor::BLUE)
		{
			if (StaticMeshComponentPackGreen)
			{
				HavePack = PackColor::GREEN;
				StaticMeshComponentPackGreen->SetVisibility(true);
			}
		}
		else if (StaticMeshComponentPackBlue)
		{
			HavePack = PackColor::BLUE;
			StaticMeshComponentPackBlue->SetVisibility(true);
		}
	}
}

void ACT_SmartObjectBuzon::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ACT_CarteroCharacter* Cartero = Cast<ACT_CarteroCharacter>(OtherActor);
	if (!Cartero) return;

	Cartero->SetCurrentSmartObject(this);
}

PackColor ACT_SmartObjectBuzon::GivePack()
{
	if (HavePack == PackColor::NONE) return PackColor::NONE;

	PackColor CurrentPackColor = HavePack;
	ResetPack();
	
	return CurrentPackColor;
}

void ACT_SmartObjectBuzon::ResetPack()
{
	HavePack = PackColor::NONE;
	if (StaticMeshComponentPackRed) StaticMeshComponentPackRed->SetVisibility(false);
	if (StaticMeshComponentPackGreen) StaticMeshComponentPackGreen->SetVisibility(false);
	if (StaticMeshComponentPackBlue) StaticMeshComponentPackBlue->SetVisibility(false);
}

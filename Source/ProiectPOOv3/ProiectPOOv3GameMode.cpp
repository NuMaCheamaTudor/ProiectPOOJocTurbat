
#include "ProiectPOOv3GameMode.h"
#include "ProiectPOOv3Character.h"
#include "UObject/ConstructorHelpers.h"

AProiectPOOv3GameMode::AProiectPOOv3GameMode()
{
	// clasa pion setata default la bp
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

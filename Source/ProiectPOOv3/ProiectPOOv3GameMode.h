#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ProiectPOOv3Character.h"
#include "ProiectPOOv3GameMode.generated.h"


UCLASS(minimalapi)
class AProiectPOOv3GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AProiectPOOv3GameMode();


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player References")
	AProiectPOOv3Character* player1;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player References")
	AProiectPOOv3Character* player2;
};




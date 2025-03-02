
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Player2.generated.h"

UCLASS()
class PROIECTPOOV3_API APlayer2 : public APawn
{
	GENERATED_BODY()

public:
	
	APlayer2();

protected:

	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

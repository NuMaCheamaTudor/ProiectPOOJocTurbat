
#include "Player2.h"


APlayer2::APlayer2()
{
 	
	PrimaryActorTick.bCanEverTick = true;

}


void APlayer2::BeginPlay()
{
	Super::BeginPlay();
	
}


void APlayer2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void APlayer2::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


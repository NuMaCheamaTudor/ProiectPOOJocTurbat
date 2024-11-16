

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Hitbox.generated.h"

UCLASS()
class PROIECTPOOV3_API AHitbox : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AHitbox();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};

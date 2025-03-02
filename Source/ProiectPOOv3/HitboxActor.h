// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HitboxActor.generated.h"

UENUM(BlueprintType)
enum class EHitboxEnum : uint8
{
    HbProximity UMETA(DisplayName = "Proximity"),
    HbStrike UMETA(DisplayName = "Strike"),
    HbHurtbox UMETA(DisplayName = "Hurtbox")
};

UCLASS()
class PROIECTPOOV3_API AHitboxActor : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AHitboxActor();

    // The hitbox enum instance
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hitbox")
    EHitboxEnum HitboxType;

    // The location to spawn the hitbox
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hitbox")
    FVector HitboxLocation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hitbox")
    float HitboxDamage;

    // Example function with [[nodiscard]] (assuming you have meaningful return values in the future)
    [[nodiscard]] FVector GetHitboxLocation() const { return HitboxLocation; }

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;
};

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CharacterHitbox.generated.h"

// Enum for hitbox types
UENUM(BlueprintType)
enum class ECharacterHitboxType : uint8
{
    Proximity UMETA(DisplayName = "Proximity"),
    Strike UMETA(DisplayName = "Strike"),
    Hurtbox UMETA(DisplayName = "Hurtbox")
};

// Base class for hitboxes
UCLASS(Abstract)
class PROIECTPOOV3_API ACharacterHitbox : public AActor
{
    GENERATED_BODY()

public:
    // Hitbox type
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hitbox")
    ECharacterHitboxType HitboxType;

    // Damage associated with this hitbox
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hitbox")
    float HitboxDamage;

    // Constructor for the class
    ACharacterHitbox();

    // Virtual function for logic specific to each hitbox type
    virtual void HandleCollision(AActor* OtherActor) const PURE_VIRTUAL(ACharacterHitbox::HandleCollision, );
};

// Class for "Strike" hitboxes
UCLASS()
class PROIECTPOOV3_API AStrikeHitbox : public ACharacterHitbox
{
    GENERATED_BODY()

public:
    virtual void HandleCollision(AActor* OtherActor) const override;
};

// Class for "Proximity" hitboxes
UCLASS()
class PROIECTPOOV3_API AProximityHitbox : public ACharacterHitbox
{
    GENERATED_BODY()

public:
    virtual void HandleCollision(AActor* OtherActor) const override;
};

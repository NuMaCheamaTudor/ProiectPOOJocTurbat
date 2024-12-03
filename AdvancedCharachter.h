#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterHitbox.h"
#include "AdvancedCharacter.generated.h"

// Custom exception to signal that the character is in the air
UCLASS()
class PROIECTPOOV3_API UCharacterInAirException : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Exceptions")
    static FString GetCharacterInAirExceptionMessage();
};

UCLASS()
class PROIECTPOOV3_API AAdvancedCharacter : public ACharacter
{
    GENERATED_BODY()

private:
    // Pointer to the current hitbox
    TSharedPtr<ACharacterHitbox> ActiveHitbox;

    // Character's health state
    float Health;

    // Flag to check if the character is in the air
    bool bIsInAir;

public:
    AAdvancedCharacter();

    // Attack functions
    void StartAttack1();
    void StartAttack2();
    void StartAttack3();
    void StartAttack4();

    // Function to apply damage from the hitbox
    void ApplyDamage(float Damage);

    // Override for collision handling
    void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

    // Static function to get the number of instances
    static int GetInstanceCount();

    // Function to check the air status of the character
    void CheckIfInAir() const;

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;
};

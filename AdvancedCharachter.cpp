#include "AdvancedCharacter.h"
#include "Engine/Engine.h"
#include "CharacterHitbox.h"
#include "Components/CapsuleComponent.h"
#include "CustomExceptions.h"

AAdvancedCharacter::AAdvancedCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    // Initialize health and air status
    Health = 100.0f;
    bIsInAir = false;

    // Set an active hitbox for testing
    ActiveHitbox = MakeShared<AStrikeHitbox>();
}

void AAdvancedCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void AAdvancedCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Check if the character is in the air
    CheckIfInAir();
}

void AAdvancedCharacter::StartAttack1()
{
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, TEXT("Starting Attack 1!"));
    }
}

void AAdvancedCharacter::StartAttack2()
{
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, TEXT("Starting Attack 2!"));
    }
}

void AAdvancedCharacter::StartAttack3()
{
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, TEXT("Starting Attack 3!"));
    }
}

void AAdvancedCharacter::StartAttack4()
{
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, TEXT("Starting Attack 4!"));
    }
}

void AAdvancedCharacter::ApplyDamage(float Damage)
{
    Health -= Damage;
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, FString::Printf(TEXT("Health: %f"), Health));
    }

    if (Health <= 0.0f)
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Character is dead!"));
        }
    }
}

void AAdvancedCharacter::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    if (!OtherActor || OtherActor == this)
    {
        return;
    }

    // If hit by a hitbox
    ACharacterHitbox* Hitbox = Cast<ACharacterHitbox>(OtherActor);
    if (Hitbox)
    {
        Hitbox->HandleCollision(OtherActor);  // Call the specific collision function

        if (Hitbox->HitboxType == ECharacterHitboxType::Strike)
        {
            ApplyDamage(Hitbox->HitboxDamage);
        }
        else if (Hitbox->HitboxType == ECharacterHitboxType::Proximity)
        {
            if (GEngine)
            {
                GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Entered proximity hitbox!"));
            }
        }
    }
    else
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Collision with non-hitbox object detected!"));
        }
    }
}

void AAdvancedCharacter::CheckIfInAir() const
{
    if (bIsInAir)
    {
        throw UCharacterInAirException();
    }
}

int AAdvancedCharacter::GetInstanceCount()
{
    static int instanceCount = 0;
    return ++instanceCount;
}

// Implementing the exception for the character being in the air
FString UCharacterInAirException::GetCharacterInAirExceptionMessage()
{
    return TEXT("The character is in the air!");
}

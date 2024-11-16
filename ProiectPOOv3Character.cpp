

#include "ProiectPOOv3Character.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

AProiectPOOv3Character::AProiectPOOv3Character()
{
	// marime capsula
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// nu te rotesti cu controllerul 
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// camera boom atasat la root
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // rotatia caracterului nu afecteaza camera boomn
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->TargetArmLength = 500.f;
	CameraBoom->SocketOffset = FVector(0.f, 0.f, 75.f);
	CameraBoom->SetRelativeRotation(FRotator(0.f, 180.f, 0.f));

	// creeaza camera si ataseaza boom
	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	SideViewCameraComponent->bUsePawnControlRotation = false; // controller nu roteste camera

	// Config movement
	GetCharacterMovement()->bOrientRotationToMovement = true; //te uiti unde mergi
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f); // la rata asta de roattie
	GetCharacterMovement()->GravityScale = 2.f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;
	viata = 1.00f;

	
}

//////////////////////////////////////////////////////////////////////////
// Input

void AProiectPOOv3Character::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// keybinds
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAxis("MoveRight", this, &AProiectPOOv3Character::MoveRight);
	PlayerInputComponent->BindAction("Atac 1", IE_Pressed, this, &AProiectPOOv3Character::startAtac1);
	PlayerInputComponent->BindAction("Atac2", IE_Pressed, this, &AProiectPOOv3Character::startAtac2);
	PlayerInputComponent->BindAction("Atac3", IE_Pressed, this, &AProiectPOOv3Character::startAtac3);
	PlayerInputComponent->BindAction("Atac4", IE_Pressed, this, &AProiectPOOv3Character::startAtac4);
	PlayerInputComponent->BindTouch(IE_Pressed, this, &AProiectPOOv3Character::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AProiectPOOv3Character::TouchStopped);
}

void AProiectPOOv3Character::MoveRight(float Value)
{
	// adauga mov in idr
	AddMovementInput(FVector(0.f, -1.f, 0.f), Value);
}

void AProiectPOOv3Character::TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	// sare
	Jump();
}

void AProiectPOOv3Character::TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	StopJumping();
}
void AProiectPOOv3Character::startAtac1()
{
	UE_LOG(LogTemp, Warning, TEXT("Da cu pumnu si picioru atac1"));
	IaBataie(0.01f);
}
void AProiectPOOv3Character::startAtac2()
{
	UE_LOG(LogTemp, Warning, TEXT("Da cu pumnu  atac2"));
	IaBataie(0.03f);
}
void AProiectPOOv3Character::startAtac3()
{
	UE_LOG(LogTemp, Warning, TEXT("Da cu  picioru atac3"));
	IaBataie(0.025f);
}
void AProiectPOOv3Character::startAtac4()
{
	UE_LOG(LogTemp, Warning, TEXT("Da cu capu atacu 4"));
	IaBataie(0.05f);
}

void AProiectPOOv3Character::IaBataie(float _damage)
{
	UE_LOG(LogTemp, Warning, TEXT("A luat %f bataie"), _damage);
	viata -= _damage;
	if (viata < 0.00f)
	{
		viata = 0.00f;
	}
}
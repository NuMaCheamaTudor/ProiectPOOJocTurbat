
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ProiectPOOv3Character.generated.h"

UCLASS(config=Game)
class AProiectPOOv3Character : public ACharacter
{
	GENERATED_BODY()

	//din lateral
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* SideViewCameraComponent;

	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;
	void startAtac1();
	void startAtac2();
	void startAtac3();
	void startAtac4();
protected:

	//input side to side
	void MoveRight(float Val);

	// handle la input
	void TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location);

	
	void TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location);

	
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	

	void IaBataie(float _damage);
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Viata")
	float viata;

public:
	AProiectPOOv3Character();
	

	
	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }
	
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	
};

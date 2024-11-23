// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/MpgAnimInstance.h"
#include "Characters/MpgCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UMpgAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	MpgCharacter = Cast<AMpgCharacter>(TryGetPawnOwner());
}

void UMpgAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (MpgCharacter == nullptr)
	{
		MpgCharacter = Cast<AMpgCharacter>(TryGetPawnOwner());
	}

	if (MpgCharacter == nullptr)
	{
		return;
	}

	FVector Velocity = MpgCharacter->GetVelocity();
	Velocity.Z = 0.f;
	Speed = Velocity.Size();

	bIsInAir = MpgCharacter->GetCharacterMovement()->IsFalling();

	bIsAccelerating = MpgCharacter->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f ? true : false;
}

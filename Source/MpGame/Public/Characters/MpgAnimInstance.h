// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MpgAnimInstance.generated.h"

class AMpgCharacter;
/**
 * 
 */
UCLASS()
class MPGAME_API UMpgAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:
	UPROPERTY(BlueprintReadOnly, Category="Character", meta=(AllowPrivateAccess=true))
	AMpgCharacter* MpgCharacter;
	UPROPERTY(BlueprintReadOnly, Category="Movement", meta=(AllowPrivateAccess=true))
	float Speed;
	UPROPERTY(BlueprintReadOnly, Category="Movement", meta=(AllowPrivateAccess=true))
	bool bIsInAir;
	UPROPERTY(BlueprintReadOnly, Category="Movement", meta=(AllowPrivateAccess=true))
	bool bIsAccelerating;
};

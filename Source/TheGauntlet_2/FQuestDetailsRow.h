// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FQuestDetailsRow.generated.h"

USTRUCT(BlueprintType)
struct FQuestDetailsRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FText Description;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UParticleSystem> VictoryVFX;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<USoundBase> VictorySound;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GauntletQuestSubsystem.generated.h"

UCLASS()
class UGauntletQuestSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	UDataTable* QuestDataTable;

	void CompleteQuest();
};

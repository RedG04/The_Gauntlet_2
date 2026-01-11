#pragma once

#include "Engine/GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "CoreMinimal.h"
#include "GaunteletGameInstance.generated.h"

UCLASS()
class THEGAUNTLET_2_API UGauntletGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void StartGame();

	UFUNCTION(BlueprintCallable)
	void ReturnToMainMenu();
};

void UGauntletGameInstance::StartGame()
{
	UGameplayStatics::OpenLevel(this, FName("GamePlayLevel"));
}

void UGauntletGameInstance::ReturnToMainMenu()
{
	UGameplayStatics::OpenLevel(this, FName("MainMenu"));
}

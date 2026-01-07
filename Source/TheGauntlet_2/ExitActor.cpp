#include "ExitActor.h"
#include "TheGauntlet_2Character.h"
#include "GauntletQuestSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

void AExitActor::Interact_Implementation(AActor* Interactor)
{
	ATheGauntlet_2Character* Character = Cast<ATheGauntlet_2Character>(Interactor);
	if (!Character || !Character->HasArtifact())
		return;
	
	SetColor(FLinearColor::Green);
	
	if (UGameInstance* GI = GetGameInstance())
	{
		if (UGauntletQuestSubsystem* QuestSubsystem = GI->GetSubsystem<UGauntletQuestSubsystem>())
		{
			QuestSubsystem->CompleteQuest();
		}
	}
	
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(
		TimerHandle,
		this,
		&AExitActor::ReturnToMainMenu,
		ReturnToMenuDelay,
		false
	);
}

void AExitActor::ReturnToMainMenu()
{
	UGameplayStatics::OpenLevel(this, FName("MainMenu"));
}

// � 2016 - 2017 Daniel Bortfeld

#include "Etos.h"
#include "Etos/UI/InGameUI.h"
#include "EtosHUD.h"

UInGameUI * AEtosHUD::GetInGameUI()
{
	if (inGameUI == nullptr)
	{
		checkf(wInGameUI, TEXT("No default In Game GUI Widget was selected for EtosHUD"));

		inGameUI = CreateWidget<UInGameUI>(GetOwningPlayerController(), wInGameUI);
	}

	return inGameUI;
}

UUserWidget * AEtosHUD::GetWinScreen()
{
	if (winScreen == nullptr)
	{
		checkf(wWinScreen, TEXT("No default Win Screen Widget was selected for EtosHUD"));

		winScreen = CreateWidget<UUserWidget>(GetOwningPlayerController(), wWinScreen);
	}
	return winScreen;
}

UUserWidget * AEtosHUD::GetLoseScreen()
{
	if (loseScreen == nullptr)
	{
		checkf(wLoseScreen, TEXT("No default Lose Screen Widget was selected for EtosHUD"));

		loseScreen = CreateWidget<UUserWidget>(GetOwningPlayerController(), wLoseScreen);
	}
	return loseScreen;
}

void AEtosHUD::BeginDestroy()
{
	wInGameUI = nullptr;
	inGameUI = nullptr;

	Super::BeginDestroy();
}

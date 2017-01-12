// � 2016 - 2017 Daniel Bortfeld

#pragma once

class UInGameUI;
class AResourcePopup;

#include "GameFramework/HUD.h"
#include "EtosHUD.generated.h"

/**
 *
 */
UCLASS()
class ETOS_API AEtosHUD : public AHUD
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
		TSubclassOf<UInGameUI> wInGameUI;

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
		TSubclassOf<UUserWidget> wWinScreen;

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
		TSubclassOf<UUserWidget> wLoseScreen;

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
		TSubclassOf<AResourcePopup> TextPopupBlueprint;

private:

	UPROPERTY()
		UInGameUI* inGameUI;

	UPROPERTY()
		UUserWidget* winScreen;

	UPROPERTY()
		UUserWidget* loseScreen;

public:

	UInGameUI* GetInGameUI();

	UUserWidget* GetWinScreen();

	UUserWidget* GetLoseScreen();

	virtual void BeginDestroy() override;
};

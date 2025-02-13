// © 2016 - 2017 Daniel Bortfeld

#pragma once

class USaveLoadDialogue;

#include "DateTime.h"
#include "Blueprint/UserWidget.h"
#include "SaveLoadDialogueEntry.generated.h"

/**
 *
 */
UCLASS()
class ETOS_API USaveLoadDialogueEntry : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly, Category = "SaveGame")
		FString SaveSlotName;

	UPROPERTY(BlueprintReadOnly, Category = "SaveGame")
		FDateTime SaveTime;

	UPROPERTY(BlueprintReadOnly, Category = "SaveGame")
		USaveLoadDialogue* MySaveLoadDialogue;

public:

	void Reset();

	UFUNCTION(BlueprintImplementableEvent, Category = "SaveGame", meta = (DisplayName = "Reset"))
		void BPEvent_Reset();


};

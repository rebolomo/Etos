// © 2016 - 2017 Daniel Bortfeld

#pragma once

#include "UMG.h"
#include "UMGStyle.h"
#include "Slate/SObjectWidget.h"
#include "IUMGModule.h"
#include "Blueprint/UserWidget.h"

#include "Blueprint/UserWidget.h"
#include "Warning.generated.h"

/**
 *
 */
UCLASS()
class ETOS_API UWarning : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite)
		UButton* YesButton;

	UPROPERTY(BlueprintReadWrite)
		UButton* NoButton;

public:

	UFUNCTION(BlueprintImplementableEvent, Category = Warning, meta = (DisplayName = "BindButtons"))
		void BPEvent_BindButtons();
};

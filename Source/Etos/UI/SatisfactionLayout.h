// © 2016 - 2017 Daniel Bortfeld

#pragma once

#include "Etos/Utility/EnumLibrary.h"
#include "Blueprint/UserWidget.h"
#include "SatisfactionLayout.generated.h"

/**
 *
 */
UCLASS()
class ETOS_API USatisfactionLayout : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(BluePrintReadOnly, Category = "Penis")
		class AResidence* Residence;

	UPROPERTY(BluePrintReadOnly, Category = "Penis")
		EResource MyResource = EResource::None;

	UPROPERTY(BluePrintReadOnly, Category = "Penis")
		EResidentNeed MyNeed = EResidentNeed::None;

public:

	UFUNCTION(BlueprintPure, Category = "Penis")
		float GetSatisfactionPercentage();
};

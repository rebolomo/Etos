// © 2016 - 2017 Daniel Bortfeld

#include "Etos.h"
#include "ResourceCostLayout.h"
#include "Etos/Game/EtosPlayerController.h"

int32 UResourceCostLayout::GetAvailableResources()
{
	if (AEtosPlayerController* PC = dynamic_cast<AEtosPlayerController*, APlayerController>(GetOwningPlayer()))
	{
		return PC->GetResourceAmount(Cost.Type);
	}

	return int32();
}

FSlateColor UResourceCostLayout::GetTextColor()
{
	if (GetAvailableResources() < Cost.Amount)
	{
		return FSlateColor(FLinearColor::Red);
	}
	return FSlateColor(FLinearColor::Green);
}

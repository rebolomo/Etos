// © 2016 - 2017 Daniel Bortfeld 

#include "Etos.h"
#include "Etos/Buildings/Base/Building.h"
#include "Etos/Game/EtosPlayerController.h"
#include "BuildMenuButton.h"

//bool UBuildMenuButton::Initialize()
//{
//	bool result = Super::Initialize();
//
//	if (result)
//	{
//		BPEvent_OnInitialization();
//
//		if (BuildButton)
//		{
//			BuildButton->OnReleased.AddDynamic(this, &UBuildMenuButton::SpawnBuilding);
//		}
//	}
//
//	return result;
//}

//void UBuildMenuButton::SetButtonAndIcon(UButton * button, UImage * icon)
//{
//	this->BuildButton = button;
//	this->BuildingIcon = icon;
//}

void UBuildMenuButton::CallOnHovered_Implementation()
{
	if (OnHovered.IsBound())
	{
		OnHovered.Broadcast(Data);
	}
}

void UBuildMenuButton::CallOnUnhovered_Implementation()
{
	if (OnHovered.IsBound())
	{
		OnUnhovered.Broadcast(Data);
	}
}

FName UBuildMenuButton::GetBuildingName()
{
	return Data.Name;
}

bool UBuildMenuButton::EvaluateEnableCondition()
{
	if (bEnabled)
		return bEnabled;

	switch (Enabled)
	{
	case EEnableBuilding::Always:
		bEnabled = true;
		break;
	case EEnableBuilding::WarehouseBuilt:
		if (GetMyPlayerController())
		{
			bEnabled = myPlayerController->GetWarehouseWasBuilt();
		}
		break;
	case EEnableBuilding::MarketBuilt:
		if (GetMyPlayerController())
		{
			bEnabled = myPlayerController->GetMarketWasBuilt();
		}
		break;
	case EEnableBuilding::OnFirstCitizen:
		if (GetMyPlayerController())
		{
			bEnabled = myPlayerController->GetPopulationAmount(EResidentLevel::Citizen) > 0;
		}
		break;
	default:
		bEnabled = false;
		break;
	}

	return bEnabled;
}

void UBuildMenuButton::SpawnBuilding()
{
	if (GetMyPlayerController())
	{
		myPlayerController->SpawnBuilding(Building, Data);
	}
}

AEtosPlayerController * UBuildMenuButton::GetMyPlayerController()
{
	if (!(myPlayerController && myPlayerController->IsValidLowLevelFast()))
	{
		myPlayerController = Util::GetFirstEtosPlayerController(this);
	}

	return myPlayerController;
}

void UBuildMenuButton::BindBuildButton(UButton* button)
{
	if (button)
	{
		if (!button->OnReleased.IsBound())
		{
			button->OnReleased.AddDynamic(this, &UBuildMenuButton::SpawnBuilding);
		}

		BuildButton = button;
	}
}

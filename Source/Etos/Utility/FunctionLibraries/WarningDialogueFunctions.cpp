// © 2016 - 2017 Daniel Bortfeld

#include "Etos.h"
#include "WarningDialogueFunctions.h"
#include "Etos/UI/Warning.h"

void UWarningDialogueFunctions::BP_ShowWarningDialogue(UObject* WorldContextObject, TSubclassOf<UWarning> WarningWidget, FOnButtonReleased const & OnReleasedYes, FOnButtonReleased const & OnReleasedNo)
{
	if (auto warning = CreateWidget<UWarning>(Util::GetEtosPlayerController(WorldContextObject, 0), WarningWidget))
	{
		warning->BPEvent_BindButtons();
		warning->YesButton->OnReleased.Add(OnReleasedYes);
		warning->NoButton->OnReleased.Add(OnReleasedNo);

		warning->YesButton->OnReleased.AddDynamic(warning, &UWarning::RemoveFromParent);
		warning->NoButton->OnReleased.AddDynamic(warning, &UWarning::RemoveFromParent);

		warning->AddToViewport(10);
	}
}

template<typename PositiveReceiverClass, typename NegativeReceiverClass>
inline void UWarningDialogueFunctions::__Internal_ShowWarningDialogue(UObject* WorldContextObject, TSubclassOf<UWarning> in WarningWidget, PositiveReceiverClass* PositiveCallbackReceiver, typename TFunctionPtrResolver<PositiveReceiverClass>::FunctionPtr in OnReleasedYes, FName in OnReleasedYes_FunctionName, NegativeReceiverClass* NegativeCallbackReceiver, typename TFunctionPtrResolver<NegativeReceiverClass>::FunctionPtr in OnReleasedNo, FName in OnReleasedNo_FunctionName)
{
	if (auto warning = CreateWidget<UWarning>(Util::GetEtosPlayerController(WorldContextObject, 0), WarningWidget))
	{
		warning->BPEvent_BindButtons();

		if (PositiveCallbackReceiver != nullptr && OnReleasedYes != nullptr)
		{
			warning->YesButton->OnReleased.__Internal_AddDynamic(PositiveCallbackReceiver, OnReleasedYes, OnReleasedYes_FunctionName);
		}

		if (NegativeCallbackReceiver != nullptr && OnReleasedNo != nullptr)
		{
			warning->NoButton->OnReleased.__Internal_AddDynamic(NegativeCallbackReceiver, OnReleasedNo, OnReleasedNo_FunctionName);
		}

		warning->YesButton->OnReleased.AddDynamic(warning, &UWarning::RemoveFromParent);
		warning->NoButton->OnReleased.AddDynamic(warning, &UWarning::RemoveFromParent);

		warning->AddToViewport(10);
	}
}

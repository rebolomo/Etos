// © 2016 - 2017 Daniel Bortfeld

#pragma once

#include "Blueprint/UserWidget.h"
#include "BuildMenuButton.generated.h"

/**
 *
 */
UCLASS()
class ETOS_API UBuildMenuButton : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly, Category = "UIElements")
		UButton* BuildButton;

	UPROPERTY(BlueprintReadOnly, Category = "UIElements")
		UImage* BuildingIcon;

	UPROPERTY()
		TSubclassOf<ABuilding> Building;

	UPROPERTY()
		struct FBuildingData Data;

public:

	virtual bool Initialize() override;

	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintImplementableEvent, Category = "Init", meta = (DisplayName = "OnInitialization"))
		void BPEvent_OnInitialization();

	// Create a reference between the elements in the designer and the elements in C++
	UFUNCTION(BlueprintCallable, Category = "UIElements")
		void SetButtonAndIcon(UPARAM(DisplayName = "Bulid Button") UButton* button, UPARAM(DisplayName = "Building Icon")  UImage* icon);

private:

	UFUNCTION()
		void SpawnBuilding();
};

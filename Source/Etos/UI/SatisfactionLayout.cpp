// © 2016 - 2017 Daniel Bortfeld

#include "Etos.h"
#include "SatisfactionLayout.h"
#include "Etos/Buildings/Residence.h"

float USatisfactionLayout::GetSatisfactionPercentage()
{
	if (!(Residence && Residence->IsValidLowLevelFast()))
		return 0;

	if (Enum::IsValid(MyResource))
	{
		return Residence->GetSatisfaction(MyResource);
	}
	else if (Enum::IsValid(MyNeed))
	{
		return Residence->GetSatisfaction(MyNeed);
	}
	return 0;
}

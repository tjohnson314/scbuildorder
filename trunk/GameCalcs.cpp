#include "stdafx.h"
#include "GameCalcs.h"

size_t CGameCalcs::MineralWorkerLimit(size_t baseCount)
{
	return 3 * mymin(baseCount, (size_t)4);
}

size_t CGameCalcs::GasWorkerLimit(size_t baseCount, size_t geyserBuildingCount)
{
	return 3 * baseCount + 4 * (geyserBuildingCount - baseCount);
}

double CGameCalcs::CalculateMineralIncomeRate(size_t baseCount, size_t workerCount)
{
	size_t workers = workerCount;
	size_t mineralPatches = 8 * mymin(baseCount, (size_t)4);
	size_t patches[32] = {0};
	for (size_t i = 0; i < mineralPatches && workers > 0; i++)
	{
		// Assign first drone
		patches[i]++;
		workers--;
	}
	for (size_t i = 0; i < mineralPatches && workers > 0; i++)
	{
		// Assign second drone
		patches[i]++;
		workers--;
	}
	for (size_t i = mineralPatches / 2; i < mineralPatches && workers > 0; i++)
	{
		// Assign third drone
		patches[i]++;
		workers--;
	}
	for (size_t i = 0; i < mineralPatches / 2 && workers > 0; i++)
	{
		// Assign third drone
		patches[i]++;
		workers--;
	}

	// Assume half the patches are close, and half are far, and the close
	// ones have more SCVs. (perfect)
	double mineralIncomeRate = 0.0;
	for (size_t i = 0; i < mineralPatches; i++)
	{
		if (i < mineralPatches / 2) // Close patch
		{
			if (patches[i] == 0)
				break;
			else if (patches[i] == 1)
				mineralIncomeRate += 45.0 / 60.0; // Per TeamLiquid
			else if (patches[i] == 2)
				mineralIncomeRate += 90.0 / 60.0; // Per TeamLiquid
			else
				mineralIncomeRate += 102.0 / 60.0; // Per TeamLiquid
		}
		else
		{
			if (patches[i] == 0)
				break;
			else if (patches[i] == 1)
				mineralIncomeRate += 39.0 / 60.0; // Per TeamLiquid
			else if (patches[i] == 2)
				mineralIncomeRate += 78.0 / 60.0; // Per TeamLiquid
			else
				mineralIncomeRate += 102.0 / 60.0; // Per TeamLiquid
		}
	}

	return mineralIncomeRate;
}

double CGameCalcs::CalculateGasIncomeRate(size_t baseCount, size_t geyserBuildingCount, size_t workerCount)
{
	if (geyserBuildingCount == 0)
		return 0;

	geyserBuildingCount = mymin(geyserBuildingCount, 2 * mymin(baseCount, (size_t)4));
	size_t workers = workerCount;
	size_t geysers[8] = {0};

	for (size_t i = 0; i < geyserBuildingCount && workers > 0; i++)
	{
		// Assign first drone
		geysers[i]++;
		workers--;
	}
	for (size_t i = 0; i < geyserBuildingCount && workers > 0; i++)
	{
		// Assign second drone
		geysers[i]++;
		workers--;
	}
	for (size_t i = baseCount; i < geyserBuildingCount && workers > 0; i++)
	{
		// Assign third drone
		geysers[i]++;
		workers--;
	}
	for (size_t i = 0; i < baseCount && workers > 0; i++)
	{
		// Assign third drone
		geysers[i]++;
		workers--;
	}
	for (size_t i = baseCount; i < geyserBuildingCount && workers > 0; i++)
	{
		// Assign fourth drone
		geysers[i]++;
		workers--;
	}

	double gasIncomeRate = 0.0;

	for (size_t i = 0; i < geyserBuildingCount; i++)
	{
		if (i < baseCount) // Close geyser
		{
			if (geysers[i] == 0)
				break;
			else if (geysers[i] == 1)
				gasIncomeRate += 42.0 / 60.0; // Per TeamLiquid
			else if (geysers[i] == 2)
				gasIncomeRate += 84.0 / 60.0; // Per TeamLiquid
			else
				gasIncomeRate += 114.0 / 60.0; // Per TeamLiquid
		}
		else
		{
			if (geysers[i] == 0)
				break;
			else if (geysers[i] == 1)
				gasIncomeRate += 33.0 / 60.0; // Per TeamLiquid
			else if (geysers[i] == 2)
				gasIncomeRate += 67.0 / 60.0; // Per TeamLiquid
			else if (geysers[i] == 3)
				gasIncomeRate += 101.0 / 60.0; // Per TeamLiquid
			else
				gasIncomeRate += 114.0 / 60.0; // Per TeamLiquid
		}
	}

	return gasIncomeRate;
}

#include "stdafx.h"
#include "GameCalcs.h"

size_t CGameCalcs::MineralWorkerLimit(size_t baseCount)
{
	return 3 * 8 * mymin(baseCount, (size_t)4);
}

size_t CGameCalcs::GasWorkerLimit(size_t baseCount, size_t geyserBuildingCount)
{
	geyserBuildingCount = mymin(geyserBuildingCount, 2 * baseCount);
	return 3 * ((geyserBuildingCount + 1)/2) + 4 * (geyserBuildingCount/2);
}

double CGameCalcs::CalculateMineralIncomeRate(size_t baseCount, size_t workerCount)
{
	static double sumIncome[] = {0.0, 4*45/60.0, (4*45+4*39)/60.0, (8*45+4*39)/60.0, (8*45+8*39)/60.0, (8*45+8*39+4*34)/60.0, (8*45+8*39+4*34+4*12)/60.0}; // Sum of income rates
	static double incomeRate[] = {45/60.0, 39/60.0, 45/60.0, 39/60.0, 34/60.0, 12/60.0, 0}; // Income rates

	size_t patchCount = 4 * baseCount; // Yes, I know it's 8 per base, this is per type of patch (near/far) & how many workers on that patch (1,2,3), in the order that they'd get used
	workerCount = mymin(workerCount, 24*baseCount);
	size_t incomeRateIndex = workerCount/patchCount;
	return baseCount*sumIncome[incomeRateIndex] + (workerCount % patchCount)*incomeRate[incomeRateIndex];
}

double CGameCalcs::CalculateGasIncomeRate(size_t baseCount, size_t geyserBuildingCount, size_t workerCount)
{
	static double closeGeyserSumIncome[] = {0.0, 42/60.0, 84/60.0, 114/60.0}; // Sum of income rates
	static double farGeyserSumIncome[] = {0.0, 33/60.0, 67/60.0, 101/60.0, 114/60.0}; // Sum of income rates

	if (geyserBuildingCount == 0)
		return 0;

	geyserBuildingCount = mymin(geyserBuildingCount, 2 * baseCount);
	size_t closeGeyserCount = (geyserBuildingCount + 1) / 2;
	size_t closeGeyserWorkerCount = mymin(workerCount, 3*closeGeyserCount);
	size_t farGeyserCount = geyserBuildingCount / 2;
	size_t farGeyserWorkerCount = mymin(workerCount-closeGeyserWorkerCount, 4*farGeyserCount);

	return (114/60.0) * (closeGeyserWorkerCount/3) + closeGeyserSumIncome[closeGeyserWorkerCount%3]
		 + (114/60.0) * (farGeyserWorkerCount/4) + farGeyserSumIncome[farGeyserWorkerCount%4];
}

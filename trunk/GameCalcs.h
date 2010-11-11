#pragma once

class CGameCalcs
{
public:
	static size_t MineralWorkerLimit(size_t baseCount);
	static size_t GasWorkerLimit(size_t baseCount, size_t geyserBuildingCount);

	static double CalculateMineralIncomeRate(size_t baseCount, size_t workerCount);
	static double CalculateGasIncomeRate(size_t baseCount, size_t geyserBuildingCount, size_t workerCount);
};

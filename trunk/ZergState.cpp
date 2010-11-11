#include "stdafx.h"
#include "ZergState.h"
#include "ZergEvent.h"
#include "GameCalcs.h"

CZergState::CZergState()
: m_minerals(0), m_gas(0)
, m_hatcheryCount(0), m_extractorCount(0), m_spawningPoolCount(0), m_creepTumourCount(0), m_evolutionChamberCount(0), m_spineCrawlerCount(0), m_sporeCrawlerCount(0), m_roachWarrenCount(0), m_lairCount(0), m_hydraliskDenCount(0), m_banelingNestCount(0), m_spireCount(0), m_infestationPitCount(0), m_nydusNetworkCount(0), m_hiveCount(0), m_ultraliskCavernCount(0), m_greaterSpireCount(0)
, m_hatcheryUnderConstruction(0), m_extractorUnderConstruction(0), m_spawningPoolUnderConstruction(0), m_creepTumourUnderConstruction(0), m_evolutionChamberUnderConstruction(0), m_spineCrawlerUnderConstruction(0), m_sporeCrawlerUnderConstruction(0), m_roachWarrenUnderConstruction(0), m_lairUnderConstruction(0), m_hydraliskDenUnderConstruction(0), m_banelingNestUnderConstruction(0), m_spireUnderConstruction(0), m_infestationPitUnderConstruction(0), m_nydusNetworkUnderConstruction(0), m_hiveUnderConstruction(0), m_ultraliskCavernUnderConstruction(0), m_greaterSpireUnderConstruction(0)
, m_hatcheryInUse(0), m_spawningPoolInUse(0), m_creepTumourOnCooldown(0), m_creepTumourExpandAvailable(0), m_evolutionChamberInUse(0), m_spineCrawlerInUse(0), m_sporeCrawlerInUse(0), m_roachWarrenInUse(0), m_lairInUse(0), m_hydraliskDenInUse(0), m_banelingNestInUse(0), m_spireInUse(0), m_infestationPitInUse(0), m_nydusNetworkInUse(0), m_hiveInUse(0), m_ultraliskCavernInUse(0), m_greaterSpireInUse(0)
, m_larvaCount(0), m_droneCount(0), m_overlordCount(0), m_queenCount(0), m_zerglingCount(0), m_roachCount(0), m_hydraliskCount(0), m_banelingCount(0), m_overseerCount(0), m_infestorCount(0), m_mutaliskCount(0), m_corruptorCount(0), m_ultraliskCount(0), m_broodlordCount(0)
, m_droneUnderConstruction(0), m_overlordUnderConstruction(0), m_queenUnderConstruction(0), m_zerglingUnderConstruction(0), m_roachUnderConstruction(0), m_hydraliskUnderConstruction(0), m_banelingUnderConstruction(0), m_overseerUnderConstruction(0), m_infestorUnderConstruction(0), m_mutaliskUnderConstruction(0), m_corruptorUnderConstruction(0), m_ultraliskUnderConstruction(0), m_broodlordUnderConstruction(0)
, m_dronesOnMinerals(0), m_dronesOnGas(0)
, m_supply(0), m_supplyCap(0), m_supplyCapUnderConstruction(0)
, m_mineralIncomeRate(0), m_gasIncomeRate(0)
, m_timeLastDroneMove(0), m_lastDroneMove(eZergCommandNone)
{
	for(size_t i=0; i < 4; i++)
		m_queenEnergy[i] = 0;
}

CZergState::~CZergState()
{
}

void CZergState::SetInitialState()
{
	memset(this, 0, sizeof(CZergState));
	m_minerals = 50;
	m_hatcheryCount = 1;
	m_droneCount = 6;
	m_dronesOnMinerals = 6;
	m_overlordCount = 1;
	m_larvaCount = 3;

	RecalculateSupply();
	RecalculateSupplyCap();
	RecalculateSupplyCapUnderConstruction();
	RecalculateMineralIncomeRate();
	RecalculateGasIncomeRate();
}

void CZergState::operator=(const CZergState &state)
{
	memmove(this, &state, sizeof(CZergState));
}

bool CZergState::operator>=(const CZergState &state) const
{
	if(m_minerals < state.m_minerals)
		return false;
	if(m_gas < state.m_gas)
		return false;
	for(size_t i=0; i < 4; i++)
	{
		if(m_queenEnergy[i] < state.m_queenEnergy[i])
			return false;
	}

	if(m_hatcheryCount < state.m_hatcheryCount)
		return false;
	if(m_extractorCount < state.m_extractorCount)
		return false;
	if(m_spawningPoolCount < state.m_spawningPoolCount)
		return false;
	if(m_creepTumourCount < state.m_creepTumourCount)
		return false;
	if(m_evolutionChamberCount < state.m_evolutionChamberCount)
		return false;
	if(m_spineCrawlerCount < state.m_spineCrawlerCount)
		return false;
	if(m_sporeCrawlerCount < state.m_sporeCrawlerCount)
		return false;
	if(m_lairCount < state.m_lairCount)
		return false;
	if(m_hydraliskDenCount < state.m_hydraliskDenCount)
		return false;
	if(m_banelingNestCount < state.m_banelingNestCount)
		return false;
	if(m_spireCount < state.m_spireCount)
		return false;
	if(m_infestationPitCount < state.m_infestationPitCount)
		return false;
	if(m_nydusNetworkCount < state.m_nydusNetworkCount)
		return false;
	if(m_hiveCount < state.m_hiveCount)
		return false;
	if(m_ultraliskCavernCount < state.m_ultraliskCavernCount)
		return false;
	if(m_greaterSpireCount < state.m_greaterSpireCount)
		return false;

	if(m_droneCount < state.m_droneCount)
		return false;
	if(m_overlordCount < state.m_overlordCount)
		return false;
	if(m_queenCount < state.m_queenCount)
		return false;
	if(m_zerglingCount < state.m_zerglingCount)
		return false;
	if(m_roachCount < state.m_roachCount)
		return false;
	if(m_banelingCount < state.m_banelingCount)
		return false;
	if(m_overseerCount < state.m_overseerCount)
		return false;
	if(m_infestorCount < state.m_infestorCount)
		return false;
	if(m_mutaliskCount < state.m_mutaliskCount)
		return false;
	if(m_corruptorCount < state.m_corruptorCount)
		return false;
	if(m_ultraliskCount < state.m_ultraliskCount)
		return false;
	if(m_broodlordCount < state.m_broodlordCount)
		return false;

	return true;
}

void CZergState::intersection(const CZergState &s1, const CZergState &s2)
{
	m_minerals = mymin(s1.m_minerals, s2.m_minerals);
	m_gas = mymin(s1.m_gas, s2.m_gas);

	m_hatcheryCount = mymin(s1.m_hatcheryCount, s2.m_hatcheryCount);
	m_extractorCount = mymin(s1.m_extractorCount, s2.m_extractorCount);
	m_spawningPoolCount = mymin(s1.m_spawningPoolCount, s2.m_spawningPoolCount);
	m_creepTumourCount = mymin(s1.m_creepTumourCount, s2.m_creepTumourCount);
	m_evolutionChamberCount = mymin(s1.m_evolutionChamberCount, s2.m_evolutionChamberCount);
	m_spineCrawlerCount = mymin(s1.m_spineCrawlerCount, s2.m_spineCrawlerCount);
	m_sporeCrawlerCount = mymin(s1.m_sporeCrawlerCount, s2.m_sporeCrawlerCount);
	m_roachWarrenCount = mymin(s1.m_roachWarrenCount, s2.m_roachWarrenCount);
	m_lairCount = mymin(s1.m_lairCount, s2.m_lairCount);
	m_hydraliskDenCount = mymin(s1.m_hydraliskDenCount, s2.m_hydraliskDenCount);
	m_banelingNestCount = mymin(s1.m_banelingNestCount, s2.m_banelingNestCount);
	m_spireCount = mymin(s1.m_spireCount, s2.m_spireCount);
	m_infestationPitCount = mymin(s1.m_infestationPitCount, s2.m_infestationPitCount);
	m_nydusNetworkCount = mymin(s1.m_nydusNetworkCount, s2.m_nydusNetworkCount);
	m_hiveCount = mymin(s1.m_hiveCount, s2.m_hiveCount);
	m_ultraliskCavernCount = mymin(s1.m_ultraliskCavernCount, s2.m_ultraliskCavernCount);
	m_greaterSpireCount = mymin(s1.m_greaterSpireCount, s2.m_greaterSpireCount);

	m_droneCount = mymin(s1.m_droneCount, s2.m_droneCount);
	m_overlordCount = mymin(s1.m_overlordCount, s2.m_overlordCount);
	m_queenCount = mymin(s1.m_queenCount, s2.m_queenCount);
	m_zerglingCount = mymin(s1.m_zerglingCount, s2.m_zerglingCount);
	m_roachCount = mymin(s1.m_roachCount, s2.m_roachCount);
	m_banelingCount = mymin(s1.m_banelingCount, s2.m_banelingCount);
	m_overseerCount = mymin(s1.m_overseerCount, s2.m_overseerCount);
	m_infestorCount = mymin(s1.m_infestorCount, s2.m_infestorCount);
	m_mutaliskCount = mymin(s1.m_mutaliskCount, s2.m_mutaliskCount);
	m_corruptorCount = mymin(s1.m_corruptorCount, s2.m_corruptorCount);
	m_ultraliskCount = mymin(s1.m_ultraliskCount, s2.m_ultraliskCount);
	m_broodlordCount = mymin(s1.m_broodlordCount, s2.m_broodlordCount);
}

void CZergState::operator-=(const CZergState &state)
{
	m_minerals -= state.m_minerals;
	m_gas -= state.m_gas;
	for(size_t i=0; i < 4; i++)
		m_queenEnergy[i] -= state.m_queenEnergy[i];

	m_hatcheryCount -= state.m_hatcheryCount;
	m_extractorCount -= state.m_extractorCount;
	m_spawningPoolCount -= state.m_spawningPoolCount;
	m_creepTumourCount -= state.m_creepTumourCount;
	m_evolutionChamberCount -= state.m_evolutionChamberCount;
	m_spineCrawlerCount -= state.m_spineCrawlerCount;
	m_sporeCrawlerCount -= state.m_sporeCrawlerCount;
	m_roachWarrenCount -= state.m_roachWarrenCount;
	m_lairCount -= state.m_lairCount;
	m_hydraliskDenCount -= state.m_hydraliskDenCount;
	m_banelingNestCount -= state.m_banelingNestCount;
	m_spireCount -= state.m_spireCount;
	m_infestationPitCount -= state.m_infestationPitCount;
	m_nydusNetworkCount -= state.m_nydusNetworkCount;
	m_hiveCount -= state.m_hiveCount;
	m_ultraliskCavernCount -= state.m_ultraliskCavernCount;
	m_greaterSpireCount -= state.m_greaterSpireCount;

	m_droneCount -= state.m_droneCount;
	m_overlordCount -= state.m_overlordCount;
	m_queenCount -= state.m_queenCount;
	m_zerglingCount -= state.m_zerglingCount;
	m_roachCount -= state.m_roachCount;
	m_banelingCount -= state.m_banelingCount;
	m_overseerCount -= state.m_overseerCount;
	m_infestorCount -= state.m_infestorCount;
	m_mutaliskCount -= state.m_mutaliskCount;
	m_corruptorCount -= state.m_corruptorCount;
	m_ultraliskCount -= state.m_ultraliskCount;
	m_broodlordCount -= state.m_broodlordCount;
}

double CZergState::value()
{
	double value = 0;

	value += m_minerals * 1;
	value += m_gas * 2;
	for(size_t i=0; i < 4 && i < m_hatcheryCount; i++)
		value += m_queenEnergy[i] * 0.2;

	value += (m_hatcheryCount + m_lairUnderConstruction) * 350;
	value += m_extractorCount * 75;
	value += m_spawningPoolCount * 250;
	value += m_creepTumourCount * 1;
	value += m_evolutionChamberCount * 125;
	value += m_spineCrawlerCount * 150;
	value += m_sporeCrawlerCount * 125;
	value += (m_lairCount + m_hiveUnderConstruction) * 700;
	value += m_hydraliskDenCount * 350;
	value += m_banelingNestCount * 250;
	value += (m_spireCount + m_greaterSpireUnderConstruction) * 650;
	value += m_infestationPitCount * 350;
	value += m_nydusNetworkCount * 600;
	value += m_hiveCount * 1200;
	value += m_ultraliskCavernCount * 600;
	value += m_greaterSpireCount * 1050;

	value += m_larvaCount * 5;
	value += m_droneCount * 50;
	value += m_overlordCount * 100;
	value += m_queenCount * 150;
	value += m_zerglingCount * 25;
	value += m_roachCount * 100;
	value += m_banelingCount * 100;
	value += m_overseerCount * 350;
	value += m_infestorCount * 400;
	value += m_mutaliskCount * 300;
	value += m_corruptorCount * 350;
	value += m_ultraliskCount * 700;
	value += m_broodlordCount * 450;

	return value;
}

bool CZergState::WaitForResources(double &time, double timeLimit, double mineralCost, double gasCost, double queenEnergyCost, CLinkedList<CZergEvent> *&events)
{
	double mineralsRequired = mineralCost - m_minerals;
	double gasRequired = gasCost - m_gas;
	double maxQueenEnergy = 0;
	for(size_t i=0; i < 4 && i < m_queenCount; i++)
		maxQueenEnergy = max(maxQueenEnergy, m_queenEnergy[i]);
	double queenEnergyRequired = queenEnergyCost - maxQueenEnergy;

	while(mineralsRequired > 0 || gasRequired > 0 || queenEnergyRequired > 0)
	{
		double mineralTimeRequired = 0, gasTimeRequired = 0, queenTimeRequired = 0;
		if(mineralsRequired > 0)
		{
			if(m_mineralIncomeRate <= 0)
			{
				if(events)
					mineralTimeRequired = 99999;
				else
					return false; // Never going to get enough minerals
			}
			else
				mineralTimeRequired = mineralsRequired / m_mineralIncomeRate;
		}
		if(gasRequired > 0)
		{
			if(m_gasIncomeRate <= 0)
			{
				if(events)
					gasTimeRequired = 99999;
				else
					return false; // Never going to get enough gas
			}
			else
				gasTimeRequired = gasRequired / m_gasIncomeRate;
		}
		queenTimeRequired = queenEnergyRequired / 0.5625;

		double timeRequired = max(max(mineralTimeRequired, gasTimeRequired), queenTimeRequired);

		if(time + timeRequired > timeLimit && (!events || events->GetData().time() > timeLimit))
			return false;

		if(events && events->GetData().time() < time + timeRequired)
			ProcessEvent(time, events);
		else
			ProgressTime(time, timeRequired);

		mineralsRequired = mineralCost - m_minerals;
		gasRequired = gasCost - m_gas;
		for(size_t i=0; i < 4 && i < m_queenCount; i++)
			maxQueenEnergy = max(maxQueenEnergy, m_queenEnergy[i]);
		queenEnergyRequired = queenEnergyCost - maxQueenEnergy;
	}

	return true;
}

bool CZergState::PrepareToExecuteCommand(double &time, double timeLimit, EZergCommand command, CLinkedList<CZergEvent> *&events)
{
	double mineralCost = MineralCost(command), gasCost = GasCost(command), queenEnergyCost = QueenEnergyCost(command);

	if(!WaitForResources(time, timeLimit, mineralCost, gasCost, queenEnergyCost, events))
		return false;

	if(!HasBuildingStateRequirements(time, command))
	{
		if(!events)
			return false;

		while(!HasBuildingStateRequirements(time, command) && events && events->GetData().time() < timeLimit)
		{
			ProcessEvent(time, events);
		}

		if(!HasBuildingStateRequirements(time, command))
			return false;
	}

	return true;
}

bool CZergState::ExecuteCommand(double &time, double timeLimit, EZergCommand command, CLinkedList<CZergEvent> *&events)
{
	double mineralCost = MineralCost(command), gasCost = GasCost(command), queenEnergyCost = QueenEnergyCost(command);

	if(!WaitForResources(time, timeLimit, mineralCost, gasCost, queenEnergyCost, events))
		return false;

	if(!HasBuildingStateRequirements(time, command))
	{
		if(!events)
			return false;

		while(!HasBuildingStateRequirements(time, command) && events && events->GetData().time() < timeLimit)
		{
			ProcessEvent(time, events);
		}

		if(!HasBuildingStateRequirements(time, command))
			return false;
	}

	m_minerals -= mineralCost;
	m_gas -= gasCost;
	if(queenEnergyCost > 0)
	{
		size_t maxQueenEnergyIndex = 0;
		double maxQueenEnergy = 0;
		for(size_t i=0; i < 4 && i < m_hatcheryCount; i++)
		{
			if(m_queenEnergy[i] > maxQueenEnergy)
			{
				maxQueenEnergyIndex = i;
				maxQueenEnergy = m_queenEnergy[i];
			}
		}
		m_queenEnergy[maxQueenEnergyIndex] -= queenEnergyCost;
	}

	switch(command)
	{
	case eZergCommandBuildHatchery:
		UseDroneForBuilding(15, time, events);
		AddEvent(events, CZergEvent(CZergEvent::eSpawnHatchery, time + 100));
		m_hatcheryUnderConstruction++;
		RecalculateSupplyCapUnderConstruction();
		break;
	case eZergCommandBuildExtractor:
		UseDroneForBuilding(2, time, events);
		AddEvent(events, CZergEvent(CZergEvent::eSpawnExtractor, time + 30));
		m_extractorUnderConstruction++;
		break;
	case eZergCommandBuildSpawningPool:
		UseDroneForBuilding(5, time, events);
		AddEvent(events, CZergEvent(CZergEvent::eSpawnSpawningPool, time + 65));
		m_spawningPoolUnderConstruction++;
		break;
	case eZergCommandExpandCreepTumour:
		AddEvent(events, CZergEvent(CZergEvent::eCreepTumourAvailable, time + 15));
		m_creepTumourOnCooldown++;
		m_creepTumourCount++;
		break;
	case eZergCommandBuildEvolutionChamber:
		UseDroneForBuilding(5, time, events);
		AddEvent(events, CZergEvent(CZergEvent::eSpawnEvolutionChamber, time + 35));
		m_evolutionChamberUnderConstruction++;
		break;
	case eZergCommandBuildSpineCrawler:
		UseDroneForBuilding(5, time, events);
		AddEvent(events, CZergEvent(CZergEvent::eSpawnSpineCrawler, time + 50));
		m_spineCrawlerUnderConstruction++;
		break;
	case eZergCommandBuildSporeCrawler:
		UseDroneForBuilding(5, time, events);
		AddEvent(events, CZergEvent(CZergEvent::eSpawnSporeCrawler, time + 30));
		m_sporeCrawlerUnderConstruction++;
		break;
	case eZergCommandBuildRoachWarren:
		UseDroneForBuilding(5, time, events);
		AddEvent(events, CZergEvent(CZergEvent::eSpawnRoachWarren, time + 55));
		m_roachWarrenUnderConstruction++;
		break;
	case eZergCommandBuildLair:
		AddEvent(events, CZergEvent(CZergEvent::eSpawnLair, time + 80));
		m_lairUnderConstruction++;
		m_hatcheryInUse++;
		break;
	case eZergCommandBuildHydraliskDen:
		UseDroneForBuilding(5, time, events);
		AddEvent(events, CZergEvent(CZergEvent::eSpawnHydraliskDen, time + 40));
		m_hydraliskDenUnderConstruction++;
		break;
	case eZergCommandBuildBanelingNest:
		UseDroneForBuilding(5, time, events);
		AddEvent(events, CZergEvent(CZergEvent::eSpawnBanelingNest, time + 60));
		m_banelingNestUnderConstruction++;
		break;
	case eZergCommandBuildSpire:
		UseDroneForBuilding(5, time, events);
		AddEvent(events, CZergEvent(CZergEvent::eSpawnSpire, time + 100));
		m_spireUnderConstruction++;
		break;
	case eZergCommandBuildInfestationPit:
		UseDroneForBuilding(5, time, events);
		AddEvent(events, CZergEvent(CZergEvent::eSpawnInfestationPit, time + 50));
		m_infestationPitUnderConstruction++;
		break;
	case eZergCommandBuildNydusNetwork:
		UseDroneForBuilding(5, time, events);
		AddEvent(events, CZergEvent(CZergEvent::eSpawnNydusNetwork, time + 50));
		m_nydusNetworkUnderConstruction++;
		break;
	case eZergCommandBuildHive:
		AddEvent(events, CZergEvent(CZergEvent::eSpawnHive, time + 100));
		m_hiveUnderConstruction++;
		m_lairInUse++;
		break;
	case eZergCommandBuildUltraliskCavern:
		UseDroneForBuilding(5, time, events);
		AddEvent(events, CZergEvent(CZergEvent::eSpawnUltraliskCavern, time + 65));
		m_ultraliskCavernUnderConstruction++;
		break;
	case eZergCommandBuildGreaterSpire:
		UseDroneForBuilding(5, time, events);
		AddEvent(events, CZergEvent(CZergEvent::eSpawnGreaterSpire, time + 100));
		m_greaterSpireUnderConstruction++;
		m_spireInUse++;
		break;

	case eZergCommandCancelExtractor:
		m_minerals += (int)((25*3)/4);
		m_droneCount++;
		m_dronesOnMinerals++;
		m_extractorUnderConstruction--;
		RecalculateSupply();

		// Remove the last Spawn Extractor events
		if(events)
		{
			CLinkedList<CZergEvent> *prevEntry = 0, *lastEntry = 0, *curEntry = events;
			if(curEntry->GetData().event() == CZergEvent::eSpawnExtractor)
				lastEntry = curEntry;
			while(curEntry->GetNext() != 0)
			{
				if(curEntry->GetNext()->GetData().event() == CZergEvent::eSpawnExtractor)
				{
					prevEntry = curEntry;
					lastEntry = curEntry->GetNext();
				}

				curEntry = curEntry->GetNext();
			}

			if(lastEntry)
			{
				if(prevEntry)
					prevEntry->SetNext(lastEntry->GetNext());
				else // Must be first entry
					events = lastEntry->GetNext();

				delete lastEntry;
			}
		}
		break;

	case eZergCommandExtractorTrickDrone:
		AddEvent(events, CZergEvent(CZergEvent::eExtractorTrickFinished, time + 2));
		m_droneCount--;
		m_dronesOnMinerals--;
		RecalculateMineralIncomeRate();
	case eZergCommandBuildDrone:
		AddEvent(events, CZergEvent(CZergEvent::eSpawnDrone, time + 17));
		m_droneUnderConstruction++;
		ConsumeLarva(time, events);
		RecalculateSupply();
		break;
	case eZergCommandBuildOverlord:
		AddEvent(events, CZergEvent(CZergEvent::eSpawnOverlord, time + 25));
		m_overlordUnderConstruction++;
		RecalculateSupplyCapUnderConstruction();
		break;
	case eZergCommandBuildQueen:
		AddEvent(events, CZergEvent(CZergEvent::eSpawnQueen, time + 50));
		m_hatcheryInUse++;
		m_queenUnderConstruction++;
		RecalculateSupply();
		break;
	case eZergCommandBuildZergling:
		AddEvent(events, CZergEvent(CZergEvent::eSpawnZergling, time + 24));
		AddEvent(events, CZergEvent(CZergEvent::eSpawnZergling, time + 24));
		m_zerglingUnderConstruction += 2;
		ConsumeLarva(time, events);
		RecalculateSupply();
		break;
	case eZergCommandBuildRoach:
		AddEvent(events, CZergEvent(CZergEvent::eSpawnRoach, time + 27));
		m_roachUnderConstruction++;
		ConsumeLarva(time, events);
		RecalculateSupply();
		break;
	case eZergCommandBuildHydralisk:
		AddEvent(events, CZergEvent(CZergEvent::eSpawnHydralisk, time + 33));
		m_hydraliskUnderConstruction++;
		ConsumeLarva(time, events);
		RecalculateSupply();
		break;
	case eZergCommandBuildBaneling:
		AddEvent(events, CZergEvent(CZergEvent::eSpawnBaneling, time + 30));
		m_zerglingCount--;
		m_banelingUnderConstruction++;
		RecalculateSupply();
		break;
	case eZergCommandBuildOverseer:
		AddEvent(events, CZergEvent(CZergEvent::eSpawnOverseer, time + 16.66));
		m_overlordCount--;
		m_overseerUnderConstruction++;
		break;
	case eZergCommandBuildInfestor:
		AddEvent(events, CZergEvent(CZergEvent::eSpawnRoach, time + 50));
		m_infestorUnderConstruction++;
		ConsumeLarva(time, events);
		RecalculateSupply();
		break;
	case eZergCommandBuildMutalisk:
		AddEvent(events, CZergEvent(CZergEvent::eSpawnMutalisk, time + 33));
		m_mutaliskUnderConstruction++;
		ConsumeLarva(time, events);
		RecalculateSupply();
		break;
	case eZergCommandBuildCorruptor:
		AddEvent(events, CZergEvent(CZergEvent::eSpawnCorruptor, time + 40));
		m_corruptorUnderConstruction++;
		ConsumeLarva(time, events);
		RecalculateSupply();
		break;
	case eZergCommandBuildUltralisk:
		AddEvent(events, CZergEvent(CZergEvent::eSpawnUltralisk, time + 70));
		m_ultraliskUnderConstruction++;
		ConsumeLarva(time, events);
		RecalculateSupply();
		break;
	case eZergCommandBuildBroodlord:
		AddEvent(events, CZergEvent(CZergEvent::eSpawnBroodlord, time + 33.83));
		m_corruptorCount--;
		m_broodlordUnderConstruction++;
		break;

	case eZergCommandMoveDroneToGas:
		m_timeLastDroneMove = time;
		m_lastDroneMove = eZergCommandMoveDroneToGas;
		m_dronesOnMinerals--;
		m_dronesOnGas++;
		RecalculateMineralIncomeRate();
		RecalculateGasIncomeRate();
		break;
	case eZergCommandMoveDroneToMinerals:
		m_timeLastDroneMove = time;
		m_lastDroneMove = eZergCommandMoveDroneToMinerals;
		m_dronesOnGas--;
		m_dronesOnMinerals++;
		RecalculateMineralIncomeRate();
		RecalculateGasIncomeRate();
		break;

	case eZergCommandQueenSpawnLarva:
		AddEvent(events, CZergEvent(CZergEvent::eSpawnQueenLarva, time + 40));
		break;
	}

	return true;
}

void CZergState::ProcessEvent(double &time, CLinkedList<CZergEvent> *&events)
{
	const CZergEvent &event = events->GetData();

	ProgressTime(time, event.time() - time);

	switch(event.event())
	{
	case CZergEvent::eSpawnHatchery:
		m_hatcheryUnderConstruction--;
		m_hatcheryCount++;
		RecalculateMineralIncomeRate();
		RecalculateGasIncomeRate();
		RecalculateSupplyCap();
		break;
	case CZergEvent::eSpawnExtractor:
		m_extractorUnderConstruction--;
		m_extractorCount++;
		RecalculateGasIncomeRate();
		break;
	case CZergEvent::eSpawnSpawningPool:
		m_spawningPoolUnderConstruction--;
		m_spawningPoolCount++;
		break;
	case CZergEvent::eSpawnEvolutionChamber:
		m_evolutionChamberUnderConstruction--;
		m_evolutionChamberCount++;
		break;
	case CZergEvent::eSpawnSpineCrawler:
		m_spineCrawlerUnderConstruction--;
		m_spineCrawlerCount++;
		break;
	case CZergEvent::eSpawnSporeCrawler:
		m_sporeCrawlerUnderConstruction--;
		m_sporeCrawlerCount++;
		break;
	case CZergEvent::eSpawnRoachWarren:
		m_roachWarrenUnderConstruction--;
		m_roachWarrenCount++;
		break;
	case CZergEvent::eSpawnLair:
		m_hatcheryInUse--;
		m_hatcheryCount--;
		m_lairUnderConstruction--;
		m_lairCount++;
		break;
	case CZergEvent::eSpawnHydraliskDen:
		m_hydraliskDenUnderConstruction--;
		m_hydraliskDenCount++;
		break;
	case CZergEvent::eSpawnBanelingNest:
		m_banelingNestUnderConstruction--;
		m_banelingNestCount++;
		break;
	case CZergEvent::eSpawnSpire:
		m_spireUnderConstruction--;
		m_spireCount++;
		break;
	case CZergEvent::eSpawnInfestationPit:
		m_infestationPitUnderConstruction--;
		m_infestationPitCount++;
		break;
	case CZergEvent::eSpawnNydusNetwork:
		m_nydusNetworkUnderConstruction--;
		m_nydusNetworkCount++;
		break;
	case CZergEvent::eSpawnHive:
		m_lairInUse--;
		m_lairCount--;
		m_hiveUnderConstruction--;
		m_hiveCount++;
		break;
	case CZergEvent::eSpawnUltraliskCavern:
		m_ultraliskCavernUnderConstruction--;
		m_ultraliskCavernCount++;
		break;
	case CZergEvent::eSpawnGreaterSpire:
		m_spireInUse--;
		m_spireCount--;
		m_greaterSpireUnderConstruction--;
		m_greaterSpireCount++;
		break;

	case CZergEvent::eCreepTumourAvailable:
		m_creepTumourOnCooldown--;
		m_creepTumourExpandAvailable++;
		break;

	case CZergEvent::eBuildingDroneBackToMinerals:
		m_dronesOnMinerals++;
		RecalculateMineralIncomeRate();
		break;
	case CZergEvent::eBuildingDroneBackToGas:
		m_dronesOnGas++;
		RecalculateGasIncomeRate();
		break;

	case CZergEvent::eSpawnLarva:
		m_larvaCount++;
		if(m_larvaCount < 3)
			AddEvent(events, CZergEvent(CZergEvent::eSpawnLarva, time + 15));
		break;
	case CZergEvent::eSpawnQueenLarva:
		m_larvaCount += 4;
		
		// Remove last subsequent Spawn Larva event
		if(m_larvaCount < 7 && events)
		{
			CLinkedList<CZergEvent> *prevEntry = 0, *lastEntry = 0, *curEntry = events;
			if(curEntry->GetData().event() == CZergEvent::eSpawnLarva)
				lastEntry = curEntry;
			while(curEntry->GetNext() != 0)
			{
				if(curEntry->GetNext()->GetData().event() == CZergEvent::eSpawnLarva)
				{
					prevEntry = curEntry;
					lastEntry = curEntry->GetNext();
				}

				curEntry = curEntry->GetNext();
			}

			if(lastEntry)
			{
				if(prevEntry)
					prevEntry->SetNext(lastEntry->GetNext());
				else // Must be first entry
					events = lastEntry->GetNext();

				delete lastEntry;
			}
		}
		break;
	case CZergEvent::eSpawnDrone:
		m_droneCount++;
		m_dronesOnMinerals++;
		m_droneUnderConstruction--;
		RecalculateMineralIncomeRate();
		break;
	case CZergEvent::eSpawnOverlord:
		m_overlordCount++;
		m_overlordUnderConstruction--;
		RecalculateSupplyCap();
		break;
	case CZergEvent::eSpawnQueen:
		m_hatcheryInUse--;
		if(m_queenCount < 4)
			m_queenEnergy[m_queenCount] = 25;
		m_queenCount++;
		m_queenUnderConstruction--;
		break;
	case CZergEvent::eSpawnZergling:
		m_zerglingCount++;
		m_zerglingUnderConstruction--;
		break;
	case CZergEvent::eSpawnRoach:
		m_roachCount++;
		m_roachUnderConstruction--;
		break;
	case CZergEvent::eSpawnHydralisk:
		m_hydraliskCount++;
		m_hydraliskUnderConstruction--;
		break;
	case CZergEvent::eSpawnBaneling:
		m_banelingCount++;
		m_banelingUnderConstruction--;
		break;
	case CZergEvent::eSpawnOverseer:
		m_overseerCount++;
		m_overseerUnderConstruction--;
		break;
	case CZergEvent::eSpawnInfestor:
		m_infestorCount++;
		m_infestorUnderConstruction--;
		break;
	case CZergEvent::eSpawnMutalisk:
		m_mutaliskCount++;
		m_mutaliskUnderConstruction--;
		break;
	case CZergEvent::eSpawnCorruptor:
		m_corruptorCount++;
		m_corruptorUnderConstruction--;
		break;
	case CZergEvent::eSpawnUltralisk:
		m_ultraliskCount++;
		m_ultraliskUnderConstruction--;
		break;
	case CZergEvent::eSpawnBroodlord:
		m_broodlordCount++;
		m_broodlordUnderConstruction--;
		break;

	case CZergEvent::eExtractorTrickFinished:
		m_minerals += (int)((25*3)/4);
		m_droneCount++;
		m_dronesOnMinerals++;
		RecalculateSupply();
		RecalculateMineralIncomeRate();
		break;
	}

	CLinkedList<CZergEvent> *old = events;
	events = events->GetNext();
	delete old;
}

void CZergState::AddRequirements()
{
	if(m_greaterSpireCount == 0
		&& (m_broodlordCount > 0))
		m_greaterSpireCount++;

	if(m_ultraliskCavernCount == 0
		&& (m_ultraliskCount > 0))
		m_ultraliskCavernCount++;

	if(m_hiveCount == 0
		&& (m_ultraliskCavernCount > 0 || m_greaterSpireCount > 0))
		m_hiveCount++;

	if(m_spireCount == 0
		&& (m_greaterSpireCount > 0
			|| m_mutaliskCount > 0 || m_corruptorCount > 0))
		m_spireCount++;

	if(m_infestationPitCount == 0
		&& (m_hiveCount > 0
			|| m_infestorCount > 0))
		m_infestationPitCount++;

	if(m_banelingNestCount == 0
		&& (m_banelingCount > 0))
		m_banelingNestCount++;

	if(m_hydraliskDenCount == 0
		&& (m_hydraliskCount > 0))
		m_hydraliskDenCount++;

	if(m_lairCount == 0
		&& (m_hydraliskDenCount > 0 || m_infestationPitCount > 0 || m_spireCount > 0 || m_nydusNetworkCount > 0
			|| m_overseerCount > 0))
		m_lairCount++;

	if(m_roachWarrenCount == 0
		&& (m_roachCount > 0))
		m_roachWarrenCount++;

	if(m_queenCount == 0
		&& (m_creepTumourCount > 0))
		m_queenCount++;

	if(m_spawningPoolCount == 0
		&& (m_spineCrawlerCount > 0 || m_sporeCrawlerCount > 0 || m_evolutionChamberCount > 0 || m_roachWarrenCount > 0 || m_lairCount > 0 || m_banelingNestCount > 0
			|| m_zerglingCount > 0 || m_queenCount > 0))
		m_spawningPoolCount++;
}

bool CZergState::HasBuildingRequirements(double time, EZergCommand command) const
{
	switch (command)
	{
	case eZergCommandBuildHatchery:
		return 0 < m_dronesOnMinerals + m_dronesOnGas + m_droneUnderConstruction;
	case eZergCommandBuildExtractor:
		return 0 < m_dronesOnMinerals + m_dronesOnGas + m_droneUnderConstruction;
	case eZergCommandBuildSpawningPool:
		return 0 < m_hatcheryCount + m_hatcheryUnderConstruction + m_lairCount + m_lairUnderConstruction + m_hiveCount + m_hiveUnderConstruction
			&& 0 < m_dronesOnMinerals + m_dronesOnGas + m_droneUnderConstruction;
	case eZergCommandExpandCreepTumour:
		return 0 < m_creepTumourExpandAvailable + m_creepTumourOnCooldown;
	case eZergCommandBuildEvolutionChamber:
		return 0 < m_spawningPoolCount + m_spawningPoolUnderConstruction
			&& 0 < m_dronesOnMinerals + m_dronesOnGas + m_droneUnderConstruction;
	case eZergCommandBuildSpineCrawler:
		return 0 < m_spawningPoolCount + m_spawningPoolUnderConstruction
			&& 0 < m_dronesOnMinerals + m_dronesOnGas + m_droneUnderConstruction;
	case eZergCommandBuildSporeCrawler:
		return 0 < m_spawningPoolCount + m_spawningPoolUnderConstruction
			&& 0 < m_dronesOnMinerals + m_dronesOnGas + m_droneUnderConstruction;
	case eZergCommandBuildRoachWarren:
		return 0 < m_spawningPoolCount + m_spawningPoolUnderConstruction
			&& 0 < m_dronesOnMinerals + m_dronesOnGas + m_droneUnderConstruction;
	case eZergCommandBuildLair:
		return 0 < m_spawningPoolCount + m_spawningPoolUnderConstruction
			&& 0 < m_hatcheryCount + m_hatcheryUnderConstruction;
	case eZergCommandBuildHydraliskDen:
		return 0 < m_lairCount + m_lairUnderConstruction + m_hiveCount + m_hiveUnderConstruction
			&& 0 < m_dronesOnMinerals + m_dronesOnGas + m_droneUnderConstruction;
	case eZergCommandBuildBanelingNest:
		return 0 < m_spawningPoolCount + m_spawningPoolUnderConstruction
			&& 0 < m_dronesOnMinerals + m_dronesOnGas + m_droneUnderConstruction;
	case eZergCommandBuildSpire:
		return 0 < m_lairCount + m_lairUnderConstruction + m_hiveCount + m_hiveUnderConstruction
			&& 0 < m_dronesOnMinerals + m_dronesOnGas + m_droneUnderConstruction;
	case eZergCommandBuildInfestationPit:
		return 0 < m_lairCount + m_lairUnderConstruction + m_hiveCount + m_hiveUnderConstruction
			&& 0 < m_dronesOnMinerals + m_dronesOnGas + m_droneUnderConstruction;
	case eZergCommandBuildNydusNetwork:
		return 0 < m_lairCount + m_lairUnderConstruction + m_hiveCount + m_hiveUnderConstruction
			&& 0 < m_dronesOnMinerals + m_dronesOnGas + m_droneUnderConstruction;
	case eZergCommandBuildHive:
		return 0 < m_infestationPitCount + m_infestationPitUnderConstruction
			&& 0 < m_lairCount + m_lairUnderConstruction;
	case eZergCommandBuildUltraliskCavern:
		return 0 < m_hiveCount + m_hiveUnderConstruction
			&& 0 < m_dronesOnMinerals + m_dronesOnGas + m_droneUnderConstruction;
	case eZergCommandBuildGreaterSpire:
		return 0 < m_hiveCount + m_hiveUnderConstruction
			&& 0 < m_spireCount + m_spireUnderConstruction
			&& 0 < m_dronesOnMinerals + m_dronesOnGas + m_droneUnderConstruction;

	case eZergCommandCancelExtractor:
		return 0 < m_extractorUnderConstruction;
		break;

	case eZergCommandBuildDrone:
		return 0 < m_hatcheryCount + m_hatcheryUnderConstruction + m_lairCount + m_lairUnderConstruction + m_hiveCount + m_hiveUnderConstruction
			&& m_supply + 1 <= m_supplyCapUnderConstruction;
	case eZergCommandBuildOverlord:
		return 1 <= m_larvaCount;
	case eZergCommandBuildQueen:
		return 0 < m_hatcheryCount + m_hatcheryUnderConstruction + m_lairCount + m_lairUnderConstruction + m_hiveCount + m_hiveUnderConstruction
			&& 0 < m_spawningPoolCount + m_spawningPoolUnderConstruction
			&& m_supply + 2 <= m_supplyCapUnderConstruction;
	case eZergCommandBuildZergling:
		return 0 < m_larvaCount + m_hatcheryCount + m_hatcheryUnderConstruction + m_lairCount + m_lairUnderConstruction + m_hiveCount + m_hiveUnderConstruction
			&& 0 < m_spawningPoolCount + m_spawningPoolUnderConstruction
			&& m_supply + 1 <= m_supplyCapUnderConstruction;
	case eZergCommandBuildRoach:
		return 0 < m_larvaCount + m_hatcheryCount + m_hatcheryUnderConstruction + m_lairCount + m_lairUnderConstruction + m_hiveCount + m_hiveUnderConstruction
			&& 0 < m_roachWarrenCount + m_roachWarrenUnderConstruction
			&& m_supply + 2 <= m_supplyCapUnderConstruction;
	case eZergCommandBuildHydralisk:
		return 0 < m_larvaCount + m_hatcheryCount + m_hatcheryUnderConstruction + m_lairCount + m_lairUnderConstruction + m_hiveCount + m_hiveUnderConstruction
			&& 0 < m_hydraliskDenCount + m_hydraliskDenUnderConstruction
			&& m_supply + 2 <= m_supplyCapUnderConstruction;
	case eZergCommandBuildBaneling:
		return 0 < m_larvaCount + m_hatcheryCount + m_hatcheryUnderConstruction + m_lairCount + m_lairUnderConstruction + m_hiveCount + m_hiveUnderConstruction
			&& 0 < m_banelingNestCount + m_banelingNestUnderConstruction
			&& 0 < m_zerglingCount + m_zerglingUnderConstruction;
	case eZergCommandBuildOverseer:
		return 0 < m_lairCount + m_lairUnderConstruction + m_hiveCount + m_hiveUnderConstruction
			&& 0 < m_overlordCount + m_overlordUnderConstruction;
	case eZergCommandBuildInfestor:
		return 0 < m_larvaCount + m_hatcheryCount + m_hatcheryUnderConstruction + m_lairCount + m_lairUnderConstruction + m_hiveCount + m_hiveUnderConstruction
			&& 0 < m_infestationPitCount + m_infestationPitUnderConstruction
			&& m_supply + 2 <= m_supplyCapUnderConstruction;
	case eZergCommandBuildMutalisk:
		return 0 < m_larvaCount + m_hatcheryCount + m_hatcheryUnderConstruction + m_lairCount + m_lairUnderConstruction + m_hiveCount + m_hiveUnderConstruction
			&& 0 < m_spireCount + m_spireUnderConstruction
			&& m_supply + 2 <= m_supplyCapUnderConstruction;
	case eZergCommandBuildCorruptor:
		return 0 < m_larvaCount + m_hatcheryCount + m_hatcheryUnderConstruction + m_lairCount + m_lairUnderConstruction + m_hiveCount + m_hiveUnderConstruction
			&& 0 < m_spireCount + m_spireUnderConstruction
			&& m_supply + 2 <= m_supplyCapUnderConstruction;
	case eZergCommandBuildUltralisk:
		return 0 < m_larvaCount + m_hatcheryCount + m_hatcheryUnderConstruction + m_lairCount + m_lairUnderConstruction + m_hiveCount + m_hiveUnderConstruction
			&& 0 < m_ultraliskCavernCount + m_ultraliskCavernUnderConstruction
			&& m_supply + 2 <= m_supplyCapUnderConstruction;
	case eZergCommandBuildBroodlord:
		return 0 < m_greaterSpireCount + m_greaterSpireUnderConstruction
			&& 0 < m_corruptorCount + m_corruptorUnderConstruction;

	case eZergCommandExtractorTrickDrone:
		return 0 < m_hatcheryCount + m_hatcheryUnderConstruction
			&& m_supply <= m_supplyCapUnderConstruction;

	case eZergCommandMoveDroneToGas:
		return (eZergCommandMoveDroneToMinerals != m_lastDroneMove || time != m_timeLastDroneMove)
			&& 0 < m_hatcheryCount + m_hatcheryUnderConstruction
			&& 0 < m_extractorCount + m_extractorUnderConstruction
			&& 0 < m_dronesOnMinerals + m_droneUnderConstruction
			&& m_dronesOnGas < CGameCalcs::GasWorkerLimit(m_hatcheryCount + m_hatcheryUnderConstruction, m_extractorCount + m_extractorUnderConstruction);
	case eZergCommandMoveDroneToMinerals:
		return (eZergCommandMoveDroneToGas != m_lastDroneMove || time != m_timeLastDroneMove)
			&& 0 < m_hatcheryCount + m_hatcheryUnderConstruction
			&& 0 < m_dronesOnGas
			&& m_dronesOnMinerals < CGameCalcs::MineralWorkerLimit(m_hatcheryCount + m_hatcheryUnderConstruction);

	case eZergCommandQueenSpawnLarva:
		return 0 < m_hatcheryCount + m_hatcheryUnderConstruction + m_lairCount + m_lairUnderConstruction + m_hiveCount + m_hiveUnderConstruction
			&& 0 < m_queenCount + m_queenUnderConstruction;

	default:
		return true;
	}
}

bool CZergState::HasBuildingStateRequirements(double time, EZergCommand command) const
{
	switch (command)
	{
	case eZergCommandBuildHatchery:
		return 0 < m_dronesOnMinerals + m_dronesOnGas;
	case eZergCommandBuildExtractor:
		return 0 < m_dronesOnMinerals + m_dronesOnGas;
	case eZergCommandBuildSpawningPool:
		return 0 < m_hatcheryCount + m_lairCount + m_lairUnderConstruction + m_hiveCount + m_hiveUnderConstruction
			&& 0 < m_dronesOnMinerals + m_dronesOnGas;
	case eZergCommandExpandCreepTumour:
		return 0 < m_creepTumourExpandAvailable;
	case eZergCommandBuildEvolutionChamber:
		return 0 < m_spawningPoolCount
			&& 0 < m_dronesOnMinerals + m_dronesOnGas;
	case eZergCommandBuildSpineCrawler:
		return 0 < m_spawningPoolCount
			&& 0 < m_dronesOnMinerals + m_dronesOnGas;
	case eZergCommandBuildSporeCrawler:
		return 0 < m_spawningPoolCount
			&& 0 < m_dronesOnMinerals + m_dronesOnGas;
	case eZergCommandBuildRoachWarren:
		return 0 < m_spawningPoolCount
			&& 0 < m_dronesOnMinerals + m_dronesOnGas;
	case eZergCommandBuildLair:
		return 0 < m_spawningPoolCount
			&& m_hatcheryInUse < m_hatcheryCount;
	case eZergCommandBuildHydraliskDen:
		return 0 < m_lairCount + m_hiveCount + m_hiveUnderConstruction
			&& 0 < m_dronesOnMinerals + m_dronesOnGas;
	case eZergCommandBuildBanelingNest:
		return 0 < m_spawningPoolCount
			&& 0 < m_dronesOnMinerals + m_dronesOnGas;
	case eZergCommandBuildSpire:
		return 0 < m_lairCount + m_hiveCount + m_hiveUnderConstruction
			&& 0 < m_dronesOnMinerals + m_dronesOnGas;
	case eZergCommandBuildInfestationPit:
		return 0 < m_lairCount + m_hiveCount + m_hiveUnderConstruction
			&& 0 < m_dronesOnMinerals + m_dronesOnGas;
	case eZergCommandBuildNydusNetwork:
		return 0 < m_lairCount + m_hiveCount + m_hiveUnderConstruction
			&& 0 < m_dronesOnMinerals + m_dronesOnGas;
	case eZergCommandBuildHive:
		return 0 < m_infestationPitCount
			&& m_lairInUse < m_lairCount;
	case eZergCommandBuildUltraliskCavern:
		return 0 < m_hiveCount
			&& 0 < m_dronesOnMinerals + m_dronesOnGas;
	case eZergCommandBuildGreaterSpire:
		return 0 < m_hiveCount
			&& m_spireInUse < m_spireCount
			&& 0 < m_dronesOnMinerals + m_dronesOnGas;

	case eZergCommandCancelExtractor:
		return 0 < m_extractorUnderConstruction;

	case eZergCommandBuildDrone:
		return m_supply + 1 <= m_supplyCap
			&& 1 <= m_larvaCount;
	case eZergCommandBuildOverlord:
		return true;
	case eZergCommandBuildQueen:
		return m_hatcheryInUse + m_lairInUse + m_hiveInUse < m_hatcheryCount + m_lairCount + m_lairUnderConstruction + m_hiveCount + m_hiveUnderConstruction
			&& 0 < m_spawningPoolCount
			&& m_supply + 2 <= m_supplyCap;
	case eZergCommandBuildZergling:
		return 0 < m_spawningPoolCount
			&& m_supply + 1 <= m_supplyCap
			&& 1 <= m_larvaCount;
	case eZergCommandBuildRoach:
		return 0 < m_roachWarrenCount
			&& m_supply + 2 <= m_supplyCap
			&& 1 <= m_larvaCount;
	case eZergCommandBuildHydralisk:
		return 0 < m_hydraliskDenCount
			&& m_supply + 2 <= m_supplyCap
			&& 1 <= m_larvaCount;
	case eZergCommandBuildBaneling:
		return 0 < m_banelingNestCount
			&& 1 <= m_zerglingCount;
	case eZergCommandBuildOverseer:
		return 0 < m_lairCount + m_hiveCount + m_hiveUnderConstruction
			&& 1 <= m_overlordCount;
	case eZergCommandBuildInfestor:
		return 0 < m_infestationPitCount
			&& m_supply + 2 <= m_supplyCap
			&& 1 <= m_larvaCount;
	case eZergCommandBuildMutalisk:
		return 0 < m_spireCount
			&& m_supply + 2 <= m_supplyCap
			&& 1 <= m_larvaCount;
	case eZergCommandBuildCorruptor:
		return 0 < m_spireCount
			&& m_supply + 2 <= m_supplyCap
			&& 1 <= m_larvaCount;
	case eZergCommandBuildUltralisk:
		return 0 < m_ultraliskCavernCount
			&& m_supply + 2 <= m_supplyCap
			&& 1 <= m_larvaCount;
	case eZergCommandBuildBroodlord:
		return 0 < m_greaterSpireCount
			&& 1 <= m_corruptorCount;

	case eZergCommandExtractorTrickDrone:
		return 0 < m_hatcheryCount + m_lairCount + m_lairUnderConstruction + m_hiveCount + m_hiveUnderConstruction
			&& m_supply <= m_supplyCap
			&& 1 <= m_larvaCount;

	case eZergCommandMoveDroneToGas:
		return 0 < m_hatcheryCount + m_lairCount + m_lairUnderConstruction + m_hiveCount + m_hiveUnderConstruction
			&& 0 < m_extractorCount
			&& 0 < m_dronesOnMinerals;
	case eZergCommandMoveDroneToMinerals:
		return 0 < m_hatcheryCount + m_lairCount + m_lairUnderConstruction + m_hiveCount + m_hiveUnderConstruction
			&& 0 < m_extractorCount
			&& 0 < m_dronesOnGas;

	case eZergCommandQueenSpawnLarva:
		return 0 < m_hatcheryCount + m_lairCount + m_lairUnderConstruction + m_hiveCount + m_hiveUnderConstruction
			&& 0 < m_queenCount;

	default:
		return true;
	}
}

double CZergState::MineralCost(EZergCommand command)
{
	switch(command)
	{
	case eZergCommandBuildHatchery:
		return 300;
	case eZergCommandBuildExtractor:
		return 25;
	case eZergCommandBuildSpawningPool:
		return 200;
	case eZergCommandBuildEvolutionChamber:
		return 75;
	case eZergCommandBuildSpineCrawler:
		return 100;
	case eZergCommandBuildSporeCrawler:
		return 75;
	case eZergCommandBuildRoachWarren:
		return 150;
	case eZergCommandBuildLair:
		return 150;
	case eZergCommandBuildHydraliskDen:
		return 100;
	case eZergCommandBuildBanelingNest:
		return 100;
	case eZergCommandBuildSpire:
		return 200;
	case eZergCommandBuildInfestationPit:
		return 100;
	case eZergCommandBuildNydusNetwork:
		return 150;
	case eZergCommandBuildHive:
		return 200;
	case eZergCommandBuildUltraliskCavern:
		return 150;
	case eZergCommandBuildGreaterSpire:
		return 100;

	case eZergCommandBuildDrone:
		return 50;
	case eZergCommandBuildOverlord:
		return 100;
	case eZergCommandBuildQueen:
		return 150;
	case eZergCommandBuildZergling:
		return 50;
	case eZergCommandBuildRoach:
		return 75;
	case eZergCommandBuildHydralisk:
		return 100;
	case eZergCommandBuildBaneling:
		return 25;
	case eZergCommandBuildOverseer:
		return 50;
	case eZergCommandBuildInfestor:
		return 100;
	case eZergCommandBuildMutalisk:
		return 100;
	case eZergCommandBuildCorruptor:
		return 150;
	case eZergCommandBuildUltralisk:
		return 300;
	case eZergCommandBuildBroodlord:
		return 150;

	case eZergCommandExtractorTrickDrone:
		return 75;
	}

	return 0;
}

double CZergState::GasCost(EZergCommand command)
{
	switch(command)
	{
	case eZergCommandBuildLair:
		return 100;
	case eZergCommandBuildHydraliskDen:
		return 100;
	case eZergCommandBuildBanelingNest:
		return 50;
	case eZergCommandBuildSpire:
		return 200;
	case eZergCommandBuildInfestationPit:
		return 100;
	case eZergCommandBuildNydusNetwork:
		return 200;
	case eZergCommandBuildHive:
		return 150;
	case eZergCommandBuildUltraliskCavern:
		return 200;
	case eZergCommandBuildGreaterSpire:
		return 150;

	case eZergCommandBuildRoach:
		return 25;
	case eZergCommandBuildHydralisk:
		return 50;
	case eZergCommandBuildBaneling:
		return 25;
	case eZergCommandBuildOverseer:
		return 100;
	case eZergCommandBuildInfestor:
		return 150;
	case eZergCommandBuildMutalisk:
		return 100;
	case eZergCommandBuildCorruptor:
		return 100;
	case eZergCommandBuildUltralisk:
		return 200;
	case eZergCommandBuildBroodlord:
		return 150;
	}

	return 0;
}

double CZergState::QueenEnergyCost(EZergCommand command)
{
	switch(command)
	{
	case eZergCommandQueenSpawnLarva:
		return 25;
	}

	return 0;
}

void CZergState::RecalculateSupply()
{
	m_supply = 
		  1 * (m_droneCount + m_droneUnderConstruction)
		+ 2 * (m_queenCount + m_queenUnderConstruction)
		+ 0.5 * (m_zerglingCount + m_zerglingUnderConstruction)
		+ 2 * (m_roachCount + m_roachUnderConstruction)
		+ 2 * (m_hydraliskCount + m_hydraliskUnderConstruction)
		+ 0.5 * (m_banelingCount + m_banelingUnderConstruction)
		+ 2 * (m_infestorCount + m_infestorUnderConstruction)
		+ 2 * (m_mutaliskCount + m_mutaliskUnderConstruction)
		+ 2 * (m_corruptorCount + m_corruptorUnderConstruction)
		+ 2 * (m_ultraliskCount + m_ultraliskUnderConstruction)
		+ 2 * (m_broodlordCount + m_broodlordUnderConstruction)
		;
}

void CZergState::RecalculateSupplyCap()
{
	m_supplyCap = 2 * (m_hatcheryCount + m_lairCount + m_lairUnderConstruction + m_hiveCount + m_hiveUnderConstruction) + 8 * (m_overlordCount + m_overseerCount + m_overseerUnderConstruction);
}

void CZergState::RecalculateSupplyCapUnderConstruction()
{
	m_supplyCapUnderConstruction = m_supplyCap + 2 * m_hatcheryUnderConstruction + 8 * m_overlordUnderConstruction;
}

void CZergState::RecalculateMineralIncomeRate()
{
	m_mineralIncomeRate = CGameCalcs::CalculateMineralIncomeRate(m_hatcheryCount + m_lairCount + m_lairUnderConstruction + m_hiveCount + m_hiveUnderConstruction, m_dronesOnMinerals);
}

void CZergState::RecalculateGasIncomeRate()
{
	m_gasIncomeRate = CGameCalcs::CalculateGasIncomeRate(m_hatcheryCount + m_lairCount + m_lairUnderConstruction + m_hiveCount + m_hiveUnderConstruction, m_extractorCount, m_dronesOnGas);
}

void CZergState::ProgressTime(double &time, double duration)
{
	m_minerals += m_mineralIncomeRate * duration;
	m_gas += m_gasIncomeRate * duration;
	for(size_t i=0; i < 4 && i < m_queenCount; i++)
		m_queenEnergy[i] = mymin(m_queenEnergy[i] + 0.5625 * duration, 100.0);
	time += duration;
}

void CZergState::ConsumeLarva(double &time, CLinkedList<CZergEvent> *&events)
{
	m_larvaCount--;

	if(m_larvaCount == 2)
		AddEvent(events, CZergEvent(CZergEvent::eSpawnLarva, time + 15));
}

void CZergState::UseDroneForBuilding(double duration, double &time, CLinkedList<CZergEvent> *&events)
{
	m_droneCount--;
	RecalculateSupply();

	// Drone used in building
	if(m_dronesOnMinerals > 0)
	{
		m_dronesOnMinerals--;
		RecalculateMineralIncomeRate();
	}
	else if(m_dronesOnGas > 0)
	{
		m_dronesOnGas--;
		RecalculateGasIncomeRate();
	}

	// Simulate drone being pulled off the line for a period beforehand
	if(m_dronesOnMinerals > 0)
	{
		AddEvent(events, CZergEvent(CZergEvent::eBuildingDroneBackToMinerals, time + duration));
		m_dronesOnMinerals--;
		RecalculateMineralIncomeRate();
	}
	else if(m_dronesOnGas > 0)
	{
		AddEvent(events, CZergEvent(CZergEvent::eBuildingDroneBackToGas, time + duration));
		m_dronesOnGas--;
		RecalculateGasIncomeRate();
	}
}

void CZergState::AddEvent(CLinkedList<CZergEvent> *&events, const CZergEvent &event)
{
	if(!events || event < events->GetData())
		events = new CLinkedList<CZergEvent>(event, events);
	else
		events->InsertOrdered<Less<CZergEvent>>(event);
}

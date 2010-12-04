#include "stdafx.h"
#include "ZergState.h"
#include "ZergEvent.h"
#include "GameCalcs.h"

CZergState::CZergState()
: m_minerals(0), m_gas(0), m_mineralsMined(0), m_gasHarvested(0)
, m_baseCount(0), m_hatcheryCount(0), m_extractorCount(0), m_spawningPoolCount(0), m_creepTumorCount(0), m_evolutionChamberCount(0), m_spineCrawlerCount(0), m_sporeCrawlerCount(0), m_roachWarrenCount(0), m_lairCount(0), m_hydraliskDenCount(0), m_banelingNestCount(0), m_spireCount(0), m_infestationPitCount(0), m_nydusNetworkCount(0), m_hiveCount(0), m_ultraliskCavernCount(0), m_greaterSpireCount(0)
, m_hatcheryUnderConstruction(0), m_extractorUnderConstruction(0), m_spawningPoolUnderConstruction(0), m_creepTumorUnderConstruction(0), m_evolutionChamberUnderConstruction(0), m_spineCrawlerUnderConstruction(0), m_sporeCrawlerUnderConstruction(0), m_roachWarrenUnderConstruction(0), m_lairUnderConstruction(0), m_hydraliskDenUnderConstruction(0), m_banelingNestUnderConstruction(0), m_spireUnderConstruction(0), m_infestationPitUnderConstruction(0), m_nydusNetworkUnderConstruction(0), m_hiveUnderConstruction(0), m_ultraliskCavernUnderConstruction(0), m_greaterSpireUnderConstruction(0)
, m_baseTotalSpawningLarvae(0), m_hatcheryInUse(0), m_spawningPoolInUse(0), m_creepTumorOnCooldown(0), m_creepTumorExpandAvailable(0), m_evolutionChamberInUse(0), m_spineCrawlerInUse(0), m_sporeCrawlerInUse(0), m_roachWarrenInUse(0), m_lairInUse(0), m_hydraliskDenInUse(0), m_banelingNestInUse(0), m_spireInUse(0), m_infestationPitInUse(0), m_nydusNetworkInUse(0), m_hiveInUse(0), m_ultraliskCavernInUse(0), m_greaterSpireInUse(0)
, m_larvaTotalCount(0), m_droneCount(0), m_overlordCount(0), m_queenCount(0), m_zerglingCount(0), m_roachCount(0), m_hydraliskCount(0), m_banelingCount(0), m_overseerCount(0), m_infestorCount(0), m_mutaliskCount(0), m_corruptorCount(0), m_ultraliskCount(0), m_broodlordCount(0)
, m_droneUnderConstruction(0), m_overlordUnderConstruction(0), m_queenUnderConstruction(0), m_zerglingUnderConstruction(0), m_roachUnderConstruction(0), m_hydraliskUnderConstruction(0), m_banelingUnderConstruction(0), m_overseerUnderConstruction(0), m_infestorUnderConstruction(0), m_mutaliskUnderConstruction(0), m_corruptorUnderConstruction(0), m_ultraliskUnderConstruction(0), m_broodlordUnderConstruction(0)
, m_researchAdrenalGlandsCompleted(false), m_researchMetabolicBoostCompleted(false), m_researchMeleeAttacks1Completed(false), m_researchMeleeAttacks2Completed(false), m_researchMeleeAttacks3Completed(false), m_researchGroundCarapace1Completed(false), m_researchGroundCarapace2Completed(false), m_researchGroundCarapace3Completed(false), m_researchMissileAttacks1Completed(false), m_researchMissileAttacks2Completed(false), m_researchMissileAttacks3Completed(false), m_researchGlialReconstitutionCompleted(false), m_researchTunnelingClawsCompleted(false), m_researchCentrifugalHooksCompleted(false), m_researchBurrowCompleted(false), m_researchPneumaticCarapaceCompleted(false), m_researchVentralSacsCompleted(false), m_researchGroovedSpinesCompleted(false), m_researchPathogenGlandsCompleted(false), m_researchNeuralParasiteCompleted(false), m_researchFlyerAttacks1Completed(false), m_researchFlyerAttacks2Completed(false), m_researchFlyerAttacks3Completed(false), m_researchFlyerCarapace1Completed(false), m_researchFlyerCarapace2Completed(false), m_researchFlyerCarapace3Completed(false), m_researchChitinousPlatingCompleted(false)
, m_researchAdrenalGlandsUnderConstruction(false), m_researchMetabolicBoostUnderConstruction(false), m_researchMeleeAttacks1UnderConstruction(false), m_researchMeleeAttacks2UnderConstruction(false), m_researchMeleeAttacks3UnderConstruction(false), m_researchGroundCarapace1UnderConstruction(false), m_researchGroundCarapace2UnderConstruction(false), m_researchGroundCarapace3UnderConstruction(false), m_researchMissileAttacks1UnderConstruction(false), m_researchMissileAttacks2UnderConstruction(false), m_researchMissileAttacks3UnderConstruction(false), m_researchGlialReconstitutionUnderConstruction(false), m_researchTunnelingClawsUnderConstruction(false), m_researchCentrifugalHooksUnderConstruction(false), m_researchBurrowUnderConstruction(false), m_researchPneumaticCarapaceUnderConstruction(false), m_researchVentralSacsUnderConstruction(false), m_researchGroovedSpinesUnderConstruction(false), m_researchPathogenGlandsUnderConstruction(false), m_researchNeuralParasiteUnderConstruction(false), m_researchFlyerAttacks1UnderConstruction(false), m_researchFlyerAttacks2UnderConstruction(false), m_researchFlyerAttacks3UnderConstruction(false), m_researchFlyerCarapace1UnderConstruction(false), m_researchFlyerCarapace2UnderConstruction(false), m_researchFlyerCarapace3UnderConstruction(false), m_researchChitinousPlatingUnderConstruction(false)
, m_queensBusy(0), m_dronesOnMinerals(0), m_dronesOnGas(0)
, m_supply(0), m_supplyCap(0), m_supplyCapUnderConstruction(0)
, m_mineralIncomeRate(0), m_gasIncomeRate(0)
{
	for(size_t i=0; i < 4; i++)
	{
		m_queenEnergy[i] = 0;
		m_larvaCount[i] = 0;
		m_baseSpawningLarvae[i] = false;
	}
}

CZergState::~CZergState()
{
}

void CZergState::SetInitialState()
{
	memset(this, 0, sizeof(CZergState));
	m_minerals = 50;
	m_baseCount = 1;
	m_hatcheryCount = 1;
	m_droneCount = 6;
	m_dronesOnMinerals = 6;
	m_overlordCount = 1;
	m_larvaTotalCount = 3;
	m_larvaCount[0] = 3;

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

bool CZergState::GetResourceWaitTime(const CResourceCost &cost, double &resourceWaitTime) const
{
	double mineralTimeRequired = 0, gasTimeRequired = 0, queenTimeRequired = 0;

	double mineralsRequired = cost.m_minerals - m_minerals;
	if(mineralsRequired > 0)
	{
		if(m_mineralIncomeRate <= 0)
			return false;
		mineralTimeRequired = mineralsRequired / m_mineralIncomeRate;
	}

	double gasRequired = cost.m_gas - m_gas;
	if(gasRequired > 0)
	{
		if(m_gasIncomeRate <= 0)
			return false;
		gasTimeRequired = gasRequired / m_gasIncomeRate;
	}

	double maxNexusEnergy = 0.0;
	const double *queenEnergy = m_queenEnergy, *end = m_queenEnergy + mymin(m_queenCount, (size_t)4);
	while(queenEnergy < end)
		maxNexusEnergy = mymax(maxNexusEnergy, *(queenEnergy++));
	double queenEnergyRequired = cost.m_queenEnergy - maxNexusEnergy;
	if(queenEnergyRequired > 0)
	{
		if(m_queenCount <= 0)
			return false;

		queenTimeRequired = queenEnergyRequired / 0.5625;
	}

	resourceWaitTime = mymax(mymax(mineralTimeRequired, gasTimeRequired), queenTimeRequired);

	return true;
}

void CZergState::ExecuteCommand(double &time, double timeLimit, EZergCommand command, CLinkedList<CZergEvent> *&events)
{
	switch(command)
	{
	case eZergCommandBuildHatchery:
		UseDroneForBuilding(15, time, events);
		AddEvent(events, CZergEvent(CZergEvent::eSpawnHatchery, time + 100));
		m_hatcheryUnderConstruction++;
		m_supplyCapUnderConstruction = mymin((double)200.0, m_supplyCapUnderConstruction + 2.0);
		break;
	case eZergCommandBuildExtractor:
		if(m_extractorCount + m_extractorUnderConstruction < 2 * m_baseCount)
			UseDroneForBuilding(2, time, events);
		else
			UseDroneForBuilding(15, time, events);
		AddEvent(events, CZergEvent(CZergEvent::eSpawnExtractor, time + 30));
		m_extractorUnderConstruction++;
		break;
	case eZergCommandBuildSpawningPool:
		UseDroneForBuilding(5, time, events);
		AddEvent(events, CZergEvent(CZergEvent::eSpawnSpawningPool, time + 65));
		m_spawningPoolUnderConstruction++;
		break;
	case eZergCommandExpandCreepTumor:
		m_creepTumorExpandAvailable--;
		AddEvent(events, CZergEvent(CZergEvent::eCreepTumorAvailable, time + 15));
		m_creepTumorOnCooldown++;
		m_creepTumorCount++;
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
		m_minerals += 19.0;
		m_droneCount++;
		m_dronesOnMinerals++;
		m_extractorUnderConstruction--;
		m_supply += 1.0;
		RecalculateMineralIncomeRate();

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
		m_extractorUnderConstruction++;
		AddEvent(events, CZergEvent(CZergEvent::eExtractorTrickFinished, time + 2));
		m_droneCount--;
		m_dronesOnMinerals--;
		RecalculateMineralIncomeRate();
		AddEvent(events, CZergEvent(CZergEvent::eSpawnDrone, time + 18));
		m_droneUnderConstruction++;
		ConsumeLarva(time, events);
		break;
	case eZergCommandBuildDrone:
		AddEvent(events, CZergEvent(CZergEvent::eSpawnDrone, time + 17));
		m_droneUnderConstruction++;
		ConsumeLarva(time, events);
		m_supply += 1.0;
		break;
	case eZergCommandBuildOverlord:
		AddEvent(events, CZergEvent(CZergEvent::eSpawnOverlord, time + 25));
		m_overlordUnderConstruction++;
		ConsumeLarva(time, events);
		m_supplyCapUnderConstruction = mymin((double)200.0, m_supplyCapUnderConstruction + 8.0);
		break;
	case eZergCommandBuildQueen:
		AddEvent(events, CZergEvent(CZergEvent::eSpawnQueen, time + 50));
		m_hatcheryInUse++;
		m_queenUnderConstruction++;
		m_supply += 2.0;
		break;
	case eZergCommandBuildZergling:
		AddEvent(events, CZergEvent(CZergEvent::eSpawnZergling, time + 24));
		AddEvent(events, CZergEvent(CZergEvent::eSpawnZergling, time + 24));
		m_zerglingUnderConstruction += 2;
		ConsumeLarva(time, events);
		m_supply += 1.0;
		break;
	case eZergCommandBuildRoach:
		AddEvent(events, CZergEvent(CZergEvent::eSpawnRoach, time + 27));
		m_roachUnderConstruction++;
		ConsumeLarva(time, events);
		m_supply += 2.0;
		break;
	case eZergCommandBuildHydralisk:
		AddEvent(events, CZergEvent(CZergEvent::eSpawnHydralisk, time + 33));
		m_hydraliskUnderConstruction++;
		ConsumeLarva(time, events);
		m_supply += 2.0;
		break;
	case eZergCommandBuildBaneling:
		AddEvent(events, CZergEvent(CZergEvent::eSpawnBaneling, time + 30));
		m_zerglingCount--;
		m_banelingUnderConstruction++;
		break;
	case eZergCommandBuildOverseer:
		AddEvent(events, CZergEvent(CZergEvent::eSpawnOverseer, time + 16.66));
		m_overlordCount--;
		m_overseerUnderConstruction++;
		break;
	case eZergCommandBuildInfestor:
		AddEvent(events, CZergEvent(CZergEvent::eSpawnInfestor, time + 50));
		m_infestorUnderConstruction++;
		ConsumeLarva(time, events);
		m_supply += 2.0;
		break;
	case eZergCommandBuildMutalisk:
		AddEvent(events, CZergEvent(CZergEvent::eSpawnMutalisk, time + 33));
		m_mutaliskUnderConstruction++;
		ConsumeLarva(time, events);
		m_supply += 2.0;
		break;
	case eZergCommandBuildCorruptor:
		AddEvent(events, CZergEvent(CZergEvent::eSpawnCorruptor, time + 40));
		m_corruptorUnderConstruction++;
		ConsumeLarva(time, events);
		m_supply += 2.0;
		break;
	case eZergCommandBuildUltralisk:
		AddEvent(events, CZergEvent(CZergEvent::eSpawnUltralisk, time + 70));
		m_ultraliskUnderConstruction++;
		ConsumeLarva(time, events);
		m_supply += 6.0;
		break;
	case eZergCommandBuildBroodlord:
		AddEvent(events, CZergEvent(CZergEvent::eSpawnBroodlord, time + 33.83));
		m_corruptorCount--;
		m_broodlordUnderConstruction++;
		break;

	case eZergCommandQueenSpawnCreepTumor:
		m_queensBusy++;
		AddEvent(events, CZergEvent(CZergEvent::eQueenReady, time + 20));
		m_creepTumorCount++;
		m_creepTumorOnCooldown++;
		AddEvent(events, CZergEvent(CZergEvent::eCreepTumorAvailable, time + 15));
		break;
	case eZergCommandQueenSpawnLarvae:
		{
			size_t index=5;
			for(size_t i=0; i < mymin((size_t)4, m_baseCount); i++)
			{
				if(!m_baseSpawningLarvae[i])
				{
					if(index == 5 || m_larvaCount[index] > m_larvaCount[i])
						index = i;
				}
			}

			if(index < 5)
			{
				m_baseSpawningLarvae[index] = true;
				switch(index)
				{
				case 0:
					AddEvent(events, CZergEvent(CZergEvent::eSpawnQueenLarvae1, time + 40));
					break;
				case 1:
					AddEvent(events, CZergEvent(CZergEvent::eSpawnQueenLarvae2, time + 40));
					break;
				case 2:
					AddEvent(events, CZergEvent(CZergEvent::eSpawnQueenLarvae3, time + 40));
					break;
				case 3:
					AddEvent(events, CZergEvent(CZergEvent::eSpawnQueenLarvae4, time + 40));
					break;
				}
				m_baseTotalSpawningLarvae++;
			}
		}
		break;

	case eZergCommandResearchAdrenalGlands:
		AddEvent(events, CZergEvent(CZergEvent::eResearchAdrenalGlandsComplete, time + 130));
		m_spawningPoolInUse++;
		m_researchAdrenalGlandsUnderConstruction = true;
		break;
	case eZergCommandResearchMetabolicBoost:
		AddEvent(events, CZergEvent(CZergEvent::eResearchMetabolicBoostComplete, time + 110));
		m_spawningPoolInUse++;
		m_researchMetabolicBoostUnderConstruction = true;
		break;
	case eZergCommandResearchMeleeAttacks1:
		AddEvent(events, CZergEvent(CZergEvent::eResearchMeleeAttacks1Complete, time + 160));
		m_evolutionChamberInUse++;
		m_researchMeleeAttacks1UnderConstruction = true;
		break;
	case eZergCommandResearchMeleeAttacks2:
		AddEvent(events, CZergEvent(CZergEvent::eResearchMeleeAttacks2Complete, time + 190));
		m_evolutionChamberInUse++;
		m_researchMeleeAttacks2UnderConstruction = true;
		break;
	case eZergCommandResearchMeleeAttacks3:
		AddEvent(events, CZergEvent(CZergEvent::eResearchMeleeAttacks3Complete, time + 220));
		m_evolutionChamberInUse++;
		m_researchMeleeAttacks3UnderConstruction = true;
		break;
	case eZergCommandResearchGroundCarapace1:
		AddEvent(events, CZergEvent(CZergEvent::eResearchGroundCarapace1Complete, time + 160));
		m_evolutionChamberInUse++;
		m_researchGroundCarapace1UnderConstruction = true;
		break;
	case eZergCommandResearchGroundCarapace2:
		AddEvent(events, CZergEvent(CZergEvent::eResearchGroundCarapace2Complete, time + 190));
		m_evolutionChamberInUse++;
		m_researchGroundCarapace2UnderConstruction = true;
		break;
	case eZergCommandResearchGroundCarapace3:
		AddEvent(events, CZergEvent(CZergEvent::eResearchGroundCarapace3Complete, time + 220));
		m_evolutionChamberInUse++;
		m_researchGroundCarapace3UnderConstruction = true;
		break;
	case eZergCommandResearchMissileAttacks1:
		AddEvent(events, CZergEvent(CZergEvent::eResearchMissileAttacks1Complete, time + 160));
		m_evolutionChamberInUse++;
		m_researchMissileAttacks1UnderConstruction = true;
		break;
	case eZergCommandResearchMissileAttacks2:
		AddEvent(events, CZergEvent(CZergEvent::eResearchMissileAttacks2Complete, time + 190));
		m_evolutionChamberInUse++;
		m_researchMissileAttacks2UnderConstruction = true;
		break;
	case eZergCommandResearchMissileAttacks3:
		AddEvent(events, CZergEvent(CZergEvent::eResearchMissileAttacks3Complete, time + 220));
		m_evolutionChamberInUse++;
		m_researchMissileAttacks3UnderConstruction = true;
		break;
	case eZergCommandResearchGlialReconstitution:
		AddEvent(events, CZergEvent(CZergEvent::eResearchGlialReconstitutionComplete, time + 110));
		m_roachWarrenInUse++;
		m_researchGlialReconstitutionUnderConstruction = true;
		break;
	case eZergCommandResearchTunnelingClaws:
		AddEvent(events, CZergEvent(CZergEvent::eResearchTunnelingClawsComplete, time + 110));
		m_roachWarrenInUse++;
		m_researchTunnelingClawsUnderConstruction = true;
		break;
	case eZergCommandResearchCentrifugalHooks:
		AddEvent(events, CZergEvent(CZergEvent::eResearchCentrifugalHooksComplete, time + 110));
		m_banelingNestInUse++;
		m_researchCentrifugalHooksUnderConstruction = true;
		break;
	case eZergCommandResearchBurrow:
		AddEvent(events, CZergEvent(CZergEvent::eResearchBurrowComplete, time + 100));
		m_lairInUse++;
		m_researchBurrowUnderConstruction = true;
		break;
	case eZergCommandResearchPneumaticCarapace:
		AddEvent(events, CZergEvent(CZergEvent::eResearchPneumaticCarapaceComplete, time + 60));
		m_lairInUse++;
		m_researchPneumaticCarapaceUnderConstruction = true;
		break;
	case eZergCommandResearchVentralSacs:
		AddEvent(events, CZergEvent(CZergEvent::eResearchVentralSacsComplete, time + 130));
		m_lairInUse++;
		m_researchVentralSacsUnderConstruction = true;
		break;
	case eZergCommandResearchGroovedSpines:
		AddEvent(events, CZergEvent(CZergEvent::eResearchGroovedSpinesComplete, time + 80));
		m_hydraliskDenInUse++;
		m_researchGroovedSpinesUnderConstruction = true;
		break;
	case eZergCommandResearchPathogenGlands:
		AddEvent(events, CZergEvent(CZergEvent::eResearchPathogenGlandsComplete, time + 80));
		m_infestationPitInUse++;
		m_researchPathogenGlandsUnderConstruction = true;
		break;
	case eZergCommandResearchNeuralParasite:
		AddEvent(events, CZergEvent(CZergEvent::eResearchNeuralParasiteComplete, time + 110));
		m_infestationPitInUse++;
		m_researchNeuralParasiteUnderConstruction = true;
		break;
	case eZergCommandResearchFlyerAttacks1:
		AddEvent(events, CZergEvent(CZergEvent::eResearchFlyerAttacks1Complete, time + 160));
		m_spireInUse++;
		m_researchFlyerAttacks1UnderConstruction = true;
		break;
	case eZergCommandResearchFlyerAttacks2:
		AddEvent(events, CZergEvent(CZergEvent::eResearchFlyerAttacks2Complete, time + 190));
		m_spireInUse++;
		m_researchFlyerAttacks2UnderConstruction = true;
		break;
	case eZergCommandResearchFlyerAttacks3:
		AddEvent(events, CZergEvent(CZergEvent::eResearchFlyerAttacks3Complete, time + 220));
		m_spireInUse++;
		m_researchFlyerAttacks3UnderConstruction = true;
		break;
	case eZergCommandResearchFlyerCarapace1:
		AddEvent(events, CZergEvent(CZergEvent::eResearchFlyerCarapace1Complete, time + 160));
		m_spireInUse++;
		m_researchFlyerCarapace1UnderConstruction = true;
		break;
	case eZergCommandResearchFlyerCarapace2:
		AddEvent(events, CZergEvent(CZergEvent::eResearchFlyerCarapace2Complete, time + 190));
		m_spireInUse++;
		m_researchFlyerCarapace2UnderConstruction = true;
		break;
	case eZergCommandResearchFlyerCarapace3:
		AddEvent(events, CZergEvent(CZergEvent::eResearchFlyerCarapace3Complete, time + 220));
		m_spireInUse++;
		m_researchFlyerCarapace3UnderConstruction = true;
		break;
	case eZergCommandResearchChitinousPlating:
		AddEvent(events, CZergEvent(CZergEvent::eResearchChitinousPlatingComplete, time + 110));
		m_ultraliskCavernInUse++;
		m_researchChitinousPlatingUnderConstruction = true;
		break;

	case eZergCommandMoveDroneToGas:
		AddEvent(events, CZergEvent(CZergEvent::eDroneStartMiningGas, time + 2));
		m_dronesOnMinerals--;
		RecalculateMineralIncomeRate();
		break;
	case eZergCommandMoveDroneToMinerals:
		AddEvent(events, CZergEvent(CZergEvent::eDroneStartMiningMinerals, time + 2));
		m_dronesOnGas--;
		RecalculateGasIncomeRate();
		break;
	}
}

void CZergState::ProcessEvent(double &time, CLinkedList<CZergEvent> *&events)
{
	CLinkedList<CZergEvent> *entry = events;
	events = entry->GetNext();

	ProgressTime(time, entry->GetData().time() - time);

	switch(entry->GetData().event())
	{
	case CZergEvent::eSpawnHatchery:
		m_hatcheryUnderConstruction--;
		m_hatcheryCount++;
		m_baseCount++;
		m_supplyCap = mymin((double)200.0, m_supplyCap + 2.0);
		RecalculateMineralIncomeRate();
		RecalculateGasIncomeRate();
		if(m_baseCount == 2)
			AddEvent(events, CZergEvent(CZergEvent::eSpawnLarva2, time + 15.0));
		else if(m_baseCount == 3)
			AddEvent(events, CZergEvent(CZergEvent::eSpawnLarva3, time + 15.0));
		else if(m_baseCount == 4)
			AddEvent(events, CZergEvent(CZergEvent::eSpawnLarva4, time + 15.0));
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

	case CZergEvent::eQueenReady:
		m_queensBusy--;
		break;
	case CZergEvent::eCreepTumorAvailable:
		m_creepTumorOnCooldown--;
		m_creepTumorExpandAvailable++;
		break;

	case CZergEvent::eDroneStartMiningMinerals:
		m_dronesOnMinerals++;
		RecalculateMineralIncomeRate();
		break;
	case CZergEvent::eDroneStartMiningGas:
		m_dronesOnGas++;
		RecalculateGasIncomeRate();
		break;

	case CZergEvent::eSpawnLarva1:
		m_larvaTotalCount++;
		m_larvaCount[0]++;
		if(m_larvaCount[0] < 3)
			AddEvent(events, CZergEvent(CZergEvent::eSpawnLarva1, time + 15));
		break;
	case CZergEvent::eSpawnLarva2:
		m_larvaTotalCount++;
		m_larvaCount[1]++;
		if(m_larvaCount[1] < 3)
			AddEvent(events, CZergEvent(CZergEvent::eSpawnLarva2, time + 15));
		break;
	case CZergEvent::eSpawnLarva3:
		m_larvaTotalCount++;
		m_larvaCount[2]++;
		if(m_larvaCount[2] < 3)
			AddEvent(events, CZergEvent(CZergEvent::eSpawnLarva3, time + 15));
		break;
	case CZergEvent::eSpawnLarva4:
		m_larvaTotalCount++;
		m_larvaCount[3]++;
		if(m_larvaCount[3] < 3)
			AddEvent(events, CZergEvent(CZergEvent::eSpawnLarva4, time + 15));
		break;
	case CZergEvent::eSpawnQueenLarvae1:
	case CZergEvent::eSpawnQueenLarvae2:
	case CZergEvent::eSpawnQueenLarvae3:
	case CZergEvent::eSpawnQueenLarvae4:
		{
			size_t *larvaCount;
			CZergEvent::EEvent spawnEvent;
			switch(entry->GetData().event())
			{
			case CZergEvent::eSpawnQueenLarvae1:
				larvaCount = &m_larvaCount[0];
				spawnEvent = CZergEvent::eSpawnLarva1;
				m_baseSpawningLarvae[0] = false;
				break;
			case CZergEvent::eSpawnQueenLarvae2:
				larvaCount = &m_larvaCount[1];
				spawnEvent = CZergEvent::eSpawnLarva2;
				m_baseSpawningLarvae[1] = false;
				break;
			case CZergEvent::eSpawnQueenLarvae3:
				larvaCount = &m_larvaCount[2];
				spawnEvent = CZergEvent::eSpawnLarva3;
				m_baseSpawningLarvae[2] = false;
				break;
			case CZergEvent::eSpawnQueenLarvae4:
				larvaCount = &m_larvaCount[3];
				spawnEvent = CZergEvent::eSpawnLarva4;
				m_baseSpawningLarvae[3] = false;
				break;
			}

			size_t larvaIncrease = mymin((size_t)4, (size_t)19 - *larvaCount);
			*larvaCount += larvaIncrease;
			m_larvaTotalCount += larvaIncrease;
			m_baseTotalSpawningLarvae--;
		
			// Remove last subsequent Spawn Larva event
			if(*larvaCount < 7 && events)
			{
				CLinkedList<CZergEvent> *prevEntry = 0, *lastEntry = 0, *curEntry = events;
				if(curEntry->GetData().event() == spawnEvent)
					lastEntry = curEntry;
				while(curEntry->GetNext() != 0)
				{
					if(curEntry->GetNext()->GetData().event() == spawnEvent)
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
		}
		break;
	case CZergEvent::eSpawnDrone:
		m_droneCount++;
		AddEvent(events, CZergEvent(CZergEvent::eDroneStartMiningMinerals, time + 3));
		m_droneUnderConstruction--;
		break;
	case CZergEvent::eSpawnOverlord:
		m_overlordCount++;
		m_overlordUnderConstruction--;
		m_supplyCap = mymin((double)200.0, m_supplyCap + 8.0);
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
		m_minerals += 19.0;
		m_droneCount++;
		m_dronesOnMinerals++;
		m_supply += 1.0;
		m_extractorUnderConstruction--;
		RecalculateMineralIncomeRate();
		UseDroneForMovement(2, time, events);
		break;

	case CZergEvent::eResearchAdrenalGlandsComplete:
		m_researchAdrenalGlandsCompleted = true;
		m_researchAdrenalGlandsUnderConstruction = false;
		m_spawningPoolInUse--;
		break;
	case CZergEvent::eResearchMetabolicBoostComplete:
		m_researchMetabolicBoostCompleted = true;
		m_researchMetabolicBoostUnderConstruction = false;
		m_spawningPoolInUse--;
		break;
	case CZergEvent::eResearchMeleeAttacks1Complete:
		m_researchMeleeAttacks1Completed = true;
		m_researchMeleeAttacks1UnderConstruction = false;
		m_evolutionChamberInUse--;
		break;
	case CZergEvent::eResearchMeleeAttacks2Complete:
		m_researchMeleeAttacks2Completed = true;
		m_researchMeleeAttacks2UnderConstruction = false;
		m_evolutionChamberInUse--;
		break;
	case CZergEvent::eResearchMeleeAttacks3Complete:
		m_researchMeleeAttacks3Completed = true;
		m_researchMeleeAttacks3UnderConstruction = false;
		m_evolutionChamberInUse--;
		break;
	case CZergEvent::eResearchGroundCarapace1Complete:
		m_researchGroundCarapace1Completed = true;
		m_researchGroundCarapace1UnderConstruction = false;
		m_evolutionChamberInUse--;
		break;
	case CZergEvent::eResearchGroundCarapace2Complete:
		m_researchGroundCarapace2Completed = true;
		m_researchGroundCarapace2UnderConstruction = false;
		m_evolutionChamberInUse--;
		break;
	case CZergEvent::eResearchGroundCarapace3Complete:
		m_researchGroundCarapace3Completed = true;
		m_researchGroundCarapace3UnderConstruction = false;
		m_evolutionChamberInUse--;
		break;
	case CZergEvent::eResearchMissileAttacks1Complete:
		m_researchMissileAttacks1Completed = true;
		m_researchMissileAttacks1UnderConstruction = false;
		m_evolutionChamberInUse--;
		break;
	case CZergEvent::eResearchMissileAttacks2Complete:
		m_researchMissileAttacks2Completed = true;
		m_researchMissileAttacks2UnderConstruction = false;
		m_evolutionChamberInUse--;
		break;
	case CZergEvent::eResearchMissileAttacks3Complete:
		m_researchMissileAttacks3Completed = true;
		m_researchMissileAttacks3UnderConstruction = false;
		m_evolutionChamberInUse--;
		break;
	case CZergEvent::eResearchGlialReconstitutionComplete:
		m_researchGlialReconstitutionCompleted = true;
		m_researchGlialReconstitutionUnderConstruction = false;
		m_roachWarrenInUse--;
		break;
	case CZergEvent::eResearchTunnelingClawsComplete:
		m_researchTunnelingClawsCompleted = true;
		m_researchTunnelingClawsUnderConstruction = false;
		m_roachWarrenInUse--;
		break;
	case CZergEvent::eResearchCentrifugalHooksComplete:
		m_researchCentrifugalHooksCompleted = true;
		m_researchCentrifugalHooksUnderConstruction = false;
		m_banelingNestInUse--;
		break;
	case CZergEvent::eResearchBurrowComplete:
		m_researchBurrowCompleted = true;
		m_researchBurrowUnderConstruction = false;
		m_hiveInUse--;
		break;
	case CZergEvent::eResearchPneumaticCarapaceComplete:
		m_researchPneumaticCarapaceCompleted = true;
		m_researchPneumaticCarapaceUnderConstruction = false;
		m_hiveInUse--;
		break;
	case CZergEvent::eResearchVentralSacsComplete:
		m_researchVentralSacsCompleted = true;
		m_researchVentralSacsUnderConstruction = false;
		m_hiveInUse--;
		break;
	case CZergEvent::eResearchGroovedSpinesComplete:
		m_researchGroovedSpinesCompleted = true;
		m_researchGroovedSpinesUnderConstruction = false;
		m_hydraliskDenInUse--;
		break;
	case CZergEvent::eResearchPathogenGlandsComplete:
		m_researchPathogenGlandsCompleted = true;
		m_researchPathogenGlandsUnderConstruction = false;
		m_infestationPitInUse--;
		break;
	case CZergEvent::eResearchNeuralParasiteComplete:
		m_researchNeuralParasiteCompleted = true;
		m_researchNeuralParasiteUnderConstruction = false;
		m_infestationPitInUse--;
		break;
	case CZergEvent::eResearchFlyerAttacks1Complete:
		m_researchFlyerAttacks1Completed = true;
		m_researchFlyerAttacks1UnderConstruction = false;
		m_spireInUse--;
		break;
	case CZergEvent::eResearchFlyerAttacks2Complete:
		m_researchFlyerAttacks2Completed = true;
		m_researchFlyerAttacks2UnderConstruction = false;
		m_spireInUse--;
		break;
	case CZergEvent::eResearchFlyerAttacks3Complete:
		m_researchFlyerAttacks3Completed = true;
		m_researchFlyerAttacks3UnderConstruction = false;
		m_spireInUse--;
		break;
	case CZergEvent::eResearchFlyerCarapace1Complete:
		m_researchFlyerCarapace1Completed = true;
		m_researchFlyerCarapace1UnderConstruction = false;
		m_spireInUse--;
		break;
	case CZergEvent::eResearchFlyerCarapace2Complete:
		m_researchFlyerCarapace2Completed = true;
		m_researchFlyerCarapace2UnderConstruction = false;
		m_spireInUse--;
		break;
	case CZergEvent::eResearchFlyerCarapace3Complete:
		m_researchFlyerCarapace3Completed = true;
		m_researchFlyerCarapace3UnderConstruction = false;
		m_spireInUse--;
		break;
	case CZergEvent::eResearchChitinousPlatingComplete:
		m_researchChitinousPlatingCompleted = true;
		m_researchChitinousPlatingUnderConstruction = false;
		m_ultraliskCavernInUse--;
		break;

	case CZergEvent::eSendScout:
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
		break;
	case CZergEvent::eKillScout:
		m_droneCount--;
		m_supply--;
		break;
	case CZergEvent::eReturnScout:
		m_dronesOnMinerals++;
		RecalculateMineralIncomeRate();
		break;
	}

	delete entry;
}

bool CZergState::HasBuildingRequirements(double time, EZergCommand command) const
{
	switch (command)
	{
	case eZergCommandBuildHatchery:
		return 2 <= m_dronesOnMinerals + m_dronesOnGas + m_droneUnderConstruction;
	case eZergCommandBuildExtractor:
		return 2 <= m_dronesOnMinerals + m_dronesOnGas + m_droneUnderConstruction;
	case eZergCommandBuildSpawningPool:
		return 0 < m_baseCount
			&& 2 <= m_dronesOnMinerals + m_dronesOnGas + m_droneUnderConstruction;
	case eZergCommandBuildBanelingNest:
		return 0 < m_spawningPoolCount + m_spawningPoolUnderConstruction
			&& 2 <= m_dronesOnMinerals + m_dronesOnGas + m_droneUnderConstruction;
	case eZergCommandExpandCreepTumor:
		return 0 < m_creepTumorExpandAvailable + m_creepTumorOnCooldown;
	case eZergCommandBuildEvolutionChamber:
		return 0 < m_spawningPoolCount + m_spawningPoolUnderConstruction
			&& 2 <= m_dronesOnMinerals + m_dronesOnGas + m_droneUnderConstruction;
	case eZergCommandBuildSpineCrawler:
		return 0 < m_spawningPoolCount + m_spawningPoolUnderConstruction
			&& 2 <= m_dronesOnMinerals + m_dronesOnGas + m_droneUnderConstruction;
	case eZergCommandBuildSporeCrawler:
		return 0 < m_spawningPoolCount + m_spawningPoolUnderConstruction
			&& 2 <= m_dronesOnMinerals + m_dronesOnGas + m_droneUnderConstruction;
	case eZergCommandBuildRoachWarren:
		return 0 < m_spawningPoolCount + m_spawningPoolUnderConstruction
			&& 2 <= m_dronesOnMinerals + m_dronesOnGas + m_droneUnderConstruction;
	case eZergCommandBuildLair:
		return 0 < m_spawningPoolCount + m_spawningPoolUnderConstruction
			&& 0 < m_hatcheryCount + m_hatcheryUnderConstruction;
	case eZergCommandBuildHydraliskDen:
		return 0 < m_lairCount + m_lairUnderConstruction + m_hiveCount
			&& 2 <= m_dronesOnMinerals + m_dronesOnGas + m_droneUnderConstruction;
	case eZergCommandBuildSpire:
		return 0 < m_lairCount + m_lairUnderConstruction + m_hiveCount
			&& 2 <= m_dronesOnMinerals + m_dronesOnGas + m_droneUnderConstruction;
	case eZergCommandBuildInfestationPit:
		return 0 < m_lairCount + m_lairUnderConstruction + m_hiveCount
			&& 2 <= m_dronesOnMinerals + m_dronesOnGas + m_droneUnderConstruction;
	case eZergCommandBuildNydusNetwork:
		return 0 < m_lairCount + m_lairUnderConstruction + m_hiveCount
			&& 2 <= m_dronesOnMinerals + m_dronesOnGas + m_droneUnderConstruction;
	case eZergCommandBuildHive:
		return 0 < m_infestationPitCount + m_infestationPitUnderConstruction
			&& 0 < m_lairCount + m_lairUnderConstruction;
	case eZergCommandBuildUltraliskCavern:
		return 0 < m_hiveCount + m_hiveUnderConstruction
			&& 2 <= m_dronesOnMinerals + m_dronesOnGas + m_droneUnderConstruction;
	case eZergCommandBuildGreaterSpire:
		return 0 < m_hiveCount + m_hiveUnderConstruction
			&& 0 < m_spireCount + m_spireUnderConstruction
			&& 2 <= m_dronesOnMinerals + m_dronesOnGas + m_droneUnderConstruction;

	case eZergCommandCancelExtractor:
		return 0 < m_extractorUnderConstruction;
		break;

	case eZergCommandBuildDrone:
		return 0 < m_larvaCount + m_baseCount
			&& m_supply + 1.0 <= m_supplyCapUnderConstruction;
	case eZergCommandBuildOverlord:
		return 0 < m_larvaCount + m_baseCount;
	case eZergCommandBuildQueen:
		return 0 < m_larvaCount + m_baseCount
			&& 0 < m_spawningPoolCount + m_spawningPoolUnderConstruction
			&& m_supply + 2.0 <= m_supplyCapUnderConstruction;
	case eZergCommandBuildZergling:
		return 0 < m_larvaCount + m_baseCount
			&& 0 < m_spawningPoolCount + m_spawningPoolUnderConstruction
			&& m_supply + 1.0 <= m_supplyCapUnderConstruction;
	case eZergCommandBuildBaneling:
		return 0 < m_banelingNestCount + m_banelingNestUnderConstruction
			&& 0 < m_zerglingCount + m_zerglingUnderConstruction;
	case eZergCommandBuildRoach:
		return 0 < m_larvaCount + m_baseCount
			&& 0 < m_roachWarrenCount + m_roachWarrenUnderConstruction
			&& m_supply + 2.0 <= m_supplyCapUnderConstruction;
	case eZergCommandBuildHydralisk:
		return 0 < m_larvaCount + m_baseCount
			&& 0 < m_hydraliskDenCount + m_hydraliskDenUnderConstruction
			&& m_supply + 2.0 <= m_supplyCapUnderConstruction;
	case eZergCommandBuildOverseer:
		return 0 < m_lairCount + m_lairUnderConstruction + m_hiveCount
			&& 0 < m_overlordCount + m_overlordUnderConstruction;
	case eZergCommandBuildInfestor:
		return 0 < m_larvaCount + m_baseCount
			&& 0 < m_infestationPitCount + m_infestationPitUnderConstruction
			&& m_supply + 2.0 <= m_supplyCapUnderConstruction;
	case eZergCommandBuildMutalisk:
		return 0 < m_larvaCount + m_baseCount
			&& 0 < m_spireCount + m_spireUnderConstruction
			&& m_supply + 2.0 <= m_supplyCapUnderConstruction;
	case eZergCommandBuildCorruptor:
		return 0 < m_larvaCount + m_baseCount
			&& 0 < m_spireCount + m_spireUnderConstruction
			&& m_supply + 2.0 <= m_supplyCapUnderConstruction;
	case eZergCommandBuildUltralisk:
		return 0 < m_larvaCount + m_baseCount
			&& 0 < m_ultraliskCavernCount + m_ultraliskCavernUnderConstruction
			&& m_supply + 6.0 <= m_supplyCapUnderConstruction;
	case eZergCommandBuildBroodlord:
		return 0 < m_greaterSpireCount + m_greaterSpireUnderConstruction
			&& 0 < m_corruptorCount + m_corruptorUnderConstruction;

	case eZergCommandExtractorTrickDrone:
		return 0 < m_larvaCount + m_baseCount
			&& 0 < m_dronesOnMinerals + m_dronesOnGas + m_droneUnderConstruction
			&& m_supply <= m_supplyCapUnderConstruction
			&& m_extractorCount + m_extractorUnderConstruction < 2 * m_baseCount;

	case eZergCommandQueenSpawnCreepTumor:
		return 0 < m_queenCount + m_queenUnderConstruction;
	case eZergCommandQueenSpawnLarvae:
		return 0 < m_baseCount + m_hatcheryUnderConstruction
			&& 0 < m_queenCount + m_queenUnderConstruction;

	case eZergCommandResearchAdrenalGlands:
		return 0 < m_spawningPoolCount + m_spawningPoolUnderConstruction
			&& 0 < m_hiveCount + m_hiveUnderConstruction;
	case eZergCommandResearchMetabolicBoost:
		return 0 < m_spawningPoolCount + m_spawningPoolUnderConstruction;
	case eZergCommandResearchMeleeAttacks1:
		return 0 < m_evolutionChamberCount + m_evolutionChamberUnderConstruction;
	case eZergCommandResearchMeleeAttacks2:
		return 0 < m_evolutionChamberCount + m_evolutionChamberUnderConstruction
			&& 0 < m_hiveCount + m_hiveUnderConstruction
			&& (m_researchMeleeAttacks1Completed || m_researchMeleeAttacks1UnderConstruction);
	case eZergCommandResearchMeleeAttacks3:
		return 0 < m_evolutionChamberCount + m_evolutionChamberUnderConstruction
			&& 0 < m_hiveCount + m_hiveUnderConstruction
			&& (m_researchMeleeAttacks2Completed || m_researchMeleeAttacks2UnderConstruction);
	case eZergCommandResearchGroundCarapace1:
		return 0 < m_evolutionChamberCount + m_evolutionChamberUnderConstruction;
	case eZergCommandResearchGroundCarapace2:
		return 0 < m_evolutionChamberCount + m_evolutionChamberUnderConstruction
			&& 0 < m_hiveCount + m_hiveUnderConstruction
			&& (m_researchGroundCarapace1Completed || m_researchGroundCarapace1UnderConstruction);
	case eZergCommandResearchGroundCarapace3:
		return 0 < m_evolutionChamberCount + m_evolutionChamberUnderConstruction
			&& 0 < m_hiveCount + m_hiveUnderConstruction
			&& (m_researchGroundCarapace2Completed || m_researchGroundCarapace2UnderConstruction);
	case eZergCommandResearchMissileAttacks1:
		return 0 < m_evolutionChamberCount + m_evolutionChamberUnderConstruction;
	case eZergCommandResearchMissileAttacks2:
		return 0 < m_evolutionChamberCount + m_evolutionChamberUnderConstruction
			&& 0 < m_hiveCount + m_hiveUnderConstruction
			&& (m_researchMissileAttacks1Completed || m_researchMissileAttacks1UnderConstruction);
	case eZergCommandResearchMissileAttacks3:
		return 0 < m_evolutionChamberCount + m_evolutionChamberUnderConstruction
			&& 0 < m_hiveCount + m_hiveUnderConstruction
			&& (m_researchMissileAttacks2Completed || m_researchMissileAttacks2UnderConstruction);
	case eZergCommandResearchGlialReconstitution:
		return 0 < m_roachWarrenCount + m_roachWarrenUnderConstruction
			&& 0 < m_lairCount + m_lairUnderConstruction + m_hiveCount;
	case eZergCommandResearchTunnelingClaws:
		return 0 < m_roachWarrenCount + m_roachWarrenUnderConstruction
			&& 0 < m_lairCount + m_lairUnderConstruction + m_hiveCount;
	case eZergCommandResearchCentrifugalHooks:
		return 0 < m_banelingNestCount + m_banelingNestUnderConstruction
			&& 0 < m_lairCount + m_lairUnderConstruction + m_hiveCount;
	case eZergCommandResearchBurrow:
		return 0 < m_lairCount + m_lairUnderConstruction + m_hiveCount;
	case eZergCommandResearchPneumaticCarapace:
		return 0 < m_lairCount + m_lairUnderConstruction + m_hiveCount;
	case eZergCommandResearchVentralSacs:
		return 0 < m_lairCount + m_lairUnderConstruction + m_hiveCount;
	case eZergCommandResearchGroovedSpines:
		return 0 < m_hydraliskDenCount + m_hydraliskDenUnderConstruction;
	case eZergCommandResearchPathogenGlands:
		return 0 < m_infestationPitUnderConstruction;
	case eZergCommandResearchNeuralParasite:
		return 0 < m_infestationPitUnderConstruction;
	case eZergCommandResearchFlyerAttacks1:
		return 0 < m_spireCount + m_spireUnderConstruction + m_greaterSpireCount;
	case eZergCommandResearchFlyerAttacks2:
		return 0 < m_spireCount + m_spireUnderConstruction + m_greaterSpireCount
			&& 0 < m_hiveCount + m_hiveUnderConstruction
			&& (m_researchFlyerAttacks1Completed || m_researchFlyerAttacks1UnderConstruction);
	case eZergCommandResearchFlyerAttacks3:
		return 0 < m_spireCount + m_spireUnderConstruction + m_greaterSpireCount
			&& 0 < m_hiveCount + m_hiveUnderConstruction
			&& (m_researchFlyerAttacks2Completed || m_researchFlyerAttacks2UnderConstruction);
	case eZergCommandResearchFlyerCarapace1:
		return 0 < m_spireCount + m_spireUnderConstruction + m_greaterSpireCount;
	case eZergCommandResearchFlyerCarapace2:
		return 0 < m_spireCount + m_spireUnderConstruction + m_greaterSpireCount
			&& 0 < m_hiveCount + m_hiveUnderConstruction
			&& (m_researchFlyerCarapace1Completed || m_researchFlyerCarapace1UnderConstruction);
	case eZergCommandResearchFlyerCarapace3:
		return 0 < m_spireCount + m_spireUnderConstruction + m_greaterSpireCount
			&& 0 < m_hiveCount + m_hiveUnderConstruction
			&& (m_researchFlyerCarapace2Completed || m_researchFlyerCarapace2UnderConstruction);
	case eZergCommandResearchChitinousPlating:
		return 0 < m_ultraliskCavernCount + m_ultraliskCavernUnderConstruction;

	case eZergCommandMoveDroneToGas:
		return 0 < m_baseCount + m_hatcheryUnderConstruction
			&& 0 < m_extractorCount + m_extractorUnderConstruction
			&& 0 < m_dronesOnMinerals + m_droneUnderConstruction
			&& m_dronesOnGas < CGameCalcs::GasWorkerLimit(m_baseCount + m_hatcheryUnderConstruction, m_extractorCount + m_extractorUnderConstruction);
	case eZergCommandMoveDroneToMinerals:
		return 0 < m_baseCount + m_hatcheryUnderConstruction
			&& 0 < m_dronesOnGas
			&& m_dronesOnMinerals < CGameCalcs::MineralWorkerLimit(m_baseCount + m_hatcheryUnderConstruction);

	default:
		return true;
	}
}

bool CZergState::HasBuildingStateRequirements(double time, EZergCommand command) const
{
	switch (command)
	{
	case eZergCommandBuildHatchery:
		return 2 <= m_dronesOnMinerals + m_dronesOnGas;
	case eZergCommandBuildExtractor:
		return 2 <= m_dronesOnMinerals + m_dronesOnGas;
	case eZergCommandBuildSpawningPool:
		return 0 < m_baseCount
			&& 2 <= m_dronesOnMinerals + m_dronesOnGas;
	case eZergCommandBuildBanelingNest:
		return 0 < m_spawningPoolCount
			&& 2 <= m_dronesOnMinerals + m_dronesOnGas;
	case eZergCommandExpandCreepTumor:
		return 0 < m_creepTumorExpandAvailable;
	case eZergCommandBuildEvolutionChamber:
		return 0 < m_spawningPoolCount
			&& 2 <= m_dronesOnMinerals + m_dronesOnGas;
	case eZergCommandBuildSpineCrawler:
		return 0 < m_spawningPoolCount
			&& 2 <= m_dronesOnMinerals + m_dronesOnGas;
	case eZergCommandBuildSporeCrawler:
		return 0 < m_spawningPoolCount
			&& 2 <= m_dronesOnMinerals + m_dronesOnGas;
	case eZergCommandBuildRoachWarren:
		return 0 < m_spawningPoolCount
			&& 2 <= m_dronesOnMinerals + m_dronesOnGas;
	case eZergCommandBuildLair:
		return 0 < m_spawningPoolCount
			&& m_hatcheryInUse < m_hatcheryCount;
	case eZergCommandBuildHydraliskDen:
		return 0 < m_lairCount + m_hiveCount
			&& 2 <= m_dronesOnMinerals + m_dronesOnGas;
	case eZergCommandBuildSpire:
		return 0 < m_lairCount + m_hiveCount
			&& 2 <= m_dronesOnMinerals + m_dronesOnGas;
	case eZergCommandBuildInfestationPit:
		return 0 < m_lairCount + m_hiveCount
			&& 2 <= m_dronesOnMinerals + m_dronesOnGas;
	case eZergCommandBuildNydusNetwork:
		return 0 < m_lairCount + m_hiveCount
			&& 2 <= m_dronesOnMinerals + m_dronesOnGas;
	case eZergCommandBuildHive:
		return 0 < m_infestationPitCount
			&& m_lairInUse < m_lairCount;
	case eZergCommandBuildUltraliskCavern:
		return 0 < m_hiveCount
			&& 2 <= m_dronesOnMinerals + m_dronesOnGas;
	case eZergCommandBuildGreaterSpire:
		return 0 < m_hiveCount
			&& m_spireInUse < m_spireCount
			&& 2 <= m_dronesOnMinerals + m_dronesOnGas;

	case eZergCommandCancelExtractor:
		return 0 < m_extractorUnderConstruction;

	case eZergCommandBuildDrone:
		return m_supply + 1.0 <= m_supplyCap
			&& 1 <= m_larvaTotalCount;
	case eZergCommandBuildOverlord:
		return 1 <= m_larvaTotalCount;
	case eZergCommandBuildQueen:
		return (m_hatcheryInUse < m_hatcheryCount || m_lairInUse < m_lairCount || m_hiveInUse < m_hiveCount)
			&& 0 < m_spawningPoolCount
			&& m_supply + 2.0 <= m_supplyCap;
	case eZergCommandBuildZergling:
		return 0 < m_spawningPoolCount
			&& m_supply + 1.0 <= m_supplyCap
			&& 1 <= m_larvaTotalCount;
	case eZergCommandBuildBaneling:
		return 0 < m_banelingNestCount
			&& 1 <= m_zerglingCount;
	case eZergCommandBuildRoach:
		return 0 < m_roachWarrenCount
			&& m_supply + 2.0 <= m_supplyCap
			&& 1 <= m_larvaTotalCount;
	case eZergCommandBuildHydralisk:
		return 0 < m_hydraliskDenCount
			&& m_supply + 2.0 <= m_supplyCap
			&& 1 <= m_larvaTotalCount;
	case eZergCommandBuildOverseer:
		return 0 < m_lairCount + m_hiveCount
			&& 1 <= m_overlordCount;
	case eZergCommandBuildInfestor:
		return 0 < m_infestationPitCount
			&& m_supply + 2.0 <= m_supplyCap
			&& 1 <= m_larvaTotalCount;
	case eZergCommandBuildMutalisk:
		return 0 < m_spireCount
			&& m_supply + 2.0 <= m_supplyCap
			&& 1 <= m_larvaTotalCount;
	case eZergCommandBuildCorruptor:
		return 0 < m_spireCount
			&& m_supply + 2.0 <= m_supplyCap
			&& 1 <= m_larvaTotalCount;
	case eZergCommandBuildUltralisk:
		return 0 < m_ultraliskCavernCount
			&& m_supply + 6.0 <= m_supplyCap
			&& 1 <= m_larvaTotalCount;
	case eZergCommandBuildBroodlord:
		return 0 < m_greaterSpireCount
			&& 1 <= m_corruptorCount;

	case eZergCommandExtractorTrickDrone:
		return m_supply <= m_supplyCap
			&& 0 < m_dronesOnMinerals + m_dronesOnGas
			&& 1 <= m_larvaTotalCount;

	case eZergCommandQueenSpawnCreepTumor:
		return m_queensBusy < m_queenCount;
	case eZergCommandQueenSpawnLarvae:
		return m_baseTotalSpawningLarvae < mymin(m_baseCount, (size_t)4)
			&& m_queensBusy < m_queenCount;

	case eZergCommandResearchAdrenalGlands:
		return m_spawningPoolInUse < m_spawningPoolCount
			&& 0 < m_hiveCount;
	case eZergCommandResearchMetabolicBoost:
		return m_spawningPoolInUse < m_spawningPoolCount;
	case eZergCommandResearchMeleeAttacks1:
		return m_evolutionChamberInUse < m_evolutionChamberCount;
	case eZergCommandResearchMeleeAttacks2:
		return m_evolutionChamberInUse < m_evolutionChamberCount
			&& 0 < m_hiveCount
			&& m_researchMeleeAttacks1Completed;
	case eZergCommandResearchMeleeAttacks3:
		return m_evolutionChamberInUse < m_evolutionChamberCount
			&& 0 < m_hiveCount
			&& m_researchMeleeAttacks2Completed;
	case eZergCommandResearchGroundCarapace1:
		return m_evolutionChamberInUse < m_evolutionChamberCount;
	case eZergCommandResearchGroundCarapace2:
		return m_evolutionChamberInUse < m_evolutionChamberCount
			&& 0 < m_hiveCount
			&& m_researchGroundCarapace1Completed;
	case eZergCommandResearchGroundCarapace3:
		return m_evolutionChamberInUse < m_evolutionChamberCount
			&& 0 < m_hiveCount
			&& m_researchGroundCarapace2Completed;
	case eZergCommandResearchMissileAttacks1:
		return m_evolutionChamberInUse < m_evolutionChamberCount;
	case eZergCommandResearchMissileAttacks2:
		return m_evolutionChamberInUse < m_evolutionChamberCount
			&& 0 < m_hiveCount
			&& m_researchMissileAttacks1Completed;
	case eZergCommandResearchMissileAttacks3:
		return m_evolutionChamberInUse < m_evolutionChamberCount
			&& 0 < m_hiveCount
			&& m_researchMissileAttacks2Completed;
	case eZergCommandResearchGlialReconstitution:
		return m_roachWarrenInUse < m_roachWarrenCount
			&& 0 < m_lairCount + m_hiveCount;
	case eZergCommandResearchTunnelingClaws:
		return m_roachWarrenInUse < m_roachWarrenCount
			&& 0 < m_lairCount + m_hiveCount;
	case eZergCommandResearchCentrifugalHooks:
		return m_banelingNestInUse < m_banelingNestCount
			&& 0 < m_lairCount + m_hiveCount;
	case eZergCommandResearchBurrow:
		return (m_lairInUse < m_lairCount || m_hiveInUse < m_hiveCount);
	case eZergCommandResearchPneumaticCarapace:
		return (m_lairInUse < m_lairCount || m_hiveInUse < m_hiveCount);
	case eZergCommandResearchVentralSacs:
		return (m_lairInUse < m_lairCount || m_hiveInUse < m_hiveCount);
	case eZergCommandResearchGroovedSpines:
		return m_hydraliskDenInUse < m_hydraliskDenCount;
	case eZergCommandResearchPathogenGlands:
		return m_infestationPitInUse < m_infestationPitCount;
	case eZergCommandResearchNeuralParasite:
		return m_infestationPitInUse < m_infestationPitCount;
	case eZergCommandResearchFlyerAttacks1:
		return (m_spireInUse < m_spireCount || m_greaterSpireInUse < m_greaterSpireCount);
	case eZergCommandResearchFlyerAttacks2:
		return (m_spireInUse < m_spireCount || m_greaterSpireInUse < m_greaterSpireCount)
			&& 0 < m_hiveCount
			&& m_researchFlyerAttacks1Completed;
	case eZergCommandResearchFlyerAttacks3:
		return (m_spireInUse < m_spireCount || m_greaterSpireInUse < m_greaterSpireCount)
			&& 0 < m_hiveCount
			&& m_researchFlyerAttacks2Completed;
	case eZergCommandResearchFlyerCarapace1:
		return (m_spireInUse < m_spireCount || m_greaterSpireInUse < m_greaterSpireCount);
	case eZergCommandResearchFlyerCarapace2:
		return (m_spireInUse < m_spireCount || m_greaterSpireInUse < m_greaterSpireCount)
			&& 0 < m_hiveCount
			&& m_researchFlyerCarapace1Completed;
	case eZergCommandResearchFlyerCarapace3:
		return (m_spireInUse < m_spireCount || m_greaterSpireInUse < m_greaterSpireCount)
			&& 0 < m_hiveCount
			&& m_researchFlyerCarapace2Completed;
	case eZergCommandResearchChitinousPlating:
		return m_ultraliskCavernInUse < m_ultraliskCavernCount;

	case eZergCommandMoveDroneToGas:
		return 0 < m_baseCount
			&& 0 < m_extractorCount
			&& 0 < m_dronesOnMinerals;
	case eZergCommandMoveDroneToMinerals:
		return 0 < m_baseCount
			&& 0 < m_extractorCount
			&& 0 < m_dronesOnGas;

	default:
		return true;
	}
}

void CZergState::GetCost(CResourceCost &cost, EZergCommand command)
{
	switch(command)
	{
	case eZergCommandBuildHatchery:
		cost.m_minerals = 300;
		break;
	case eZergCommandBuildExtractor:
		cost.m_minerals = 25;
		break;
	case eZergCommandBuildSpawningPool:
		cost.m_minerals = 200;
		break;
	case eZergCommandBuildEvolutionChamber:
		cost.m_minerals = 75;
		break;
	case eZergCommandBuildSpineCrawler:
		cost.m_minerals = 100;
		break;
	case eZergCommandBuildSporeCrawler:
		cost.m_minerals = 75;
		break;
	case eZergCommandBuildRoachWarren:
		cost.m_minerals = 150;
		break;
	case eZergCommandBuildLair:
		cost.m_minerals = 150;
		cost.m_gas = 100;
		break;
	case eZergCommandBuildHydraliskDen:
		cost.m_minerals = 100;
		cost.m_gas = 100;
		break;
	case eZergCommandBuildBanelingNest:
		cost.m_minerals = 100;
		cost.m_gas = 50;
		break;
	case eZergCommandBuildSpire:
		cost.m_minerals = 200;
		cost.m_gas = 200;
		break;
	case eZergCommandBuildInfestationPit:
		cost.m_minerals = 100;
		cost.m_gas = 100;
		break;
	case eZergCommandBuildNydusNetwork:
		cost.m_minerals = 150;
		cost.m_gas = 200;
		break;
	case eZergCommandBuildHive:
		cost.m_minerals = 200;
		cost.m_gas = 150;
		break;
	case eZergCommandBuildUltraliskCavern:
		cost.m_minerals = 150;
		cost.m_gas = 200;
		break;
	case eZergCommandBuildGreaterSpire:
		cost.m_minerals = 100;
		cost.m_gas = 150;
		break;

	case eZergCommandBuildDrone:
		cost.m_minerals = 50;
		break;
	case eZergCommandBuildOverlord:
		cost.m_minerals = 100;
		break;
	case eZergCommandBuildQueen:
		cost.m_minerals = 150;
		break;
	case eZergCommandBuildZergling:
		cost.m_minerals = 50;
		break;
	case eZergCommandBuildRoach:
		cost.m_minerals = 75;
		cost.m_gas = 25;
		break;
	case eZergCommandBuildHydralisk:
		cost.m_minerals = 100;
		cost.m_gas = 50;
		break;
	case eZergCommandBuildBaneling:
		cost.m_minerals = 25;
		cost.m_gas = 25;
		break;
	case eZergCommandBuildOverseer:
		cost.m_minerals = 50;
		cost.m_gas = 100;
		break;
	case eZergCommandBuildInfestor:
		cost.m_minerals = 100;
		cost.m_gas = 150;
		break;
	case eZergCommandBuildMutalisk:
		cost.m_minerals = 100;
		cost.m_gas = 100;
		break;
	case eZergCommandBuildCorruptor:
		cost.m_minerals = 150;
		cost.m_gas = 100;
		break;
	case eZergCommandBuildUltralisk:
		cost.m_minerals = 300;
		cost.m_gas = 200;
		break;
	case eZergCommandBuildBroodlord:
		cost.m_minerals = 150;
		cost.m_gas = 100;
		break;

	case eZergCommandExtractorTrickDrone:
		cost.m_minerals = 75;
		break;

	case eZergCommandQueenSpawnCreepTumor:
		cost.m_queenEnergy = 25;
		break;
	case eZergCommandQueenSpawnLarvae:
		cost.m_queenEnergy = 25;
		break;

	case eZergCommandResearchAdrenalGlands:
		cost.m_minerals = 200;
		cost.m_gas = 200;
		break;
	case eZergCommandResearchMetabolicBoost:
		cost.m_minerals = 100;
		cost.m_gas = 100;
		break;
	case eZergCommandResearchMeleeAttacks1:
		cost.m_minerals = 100;
		cost.m_gas = 100;
		break;
	case eZergCommandResearchMeleeAttacks2:
		cost.m_minerals = 150;
		cost.m_gas = 150;
		break;
	case eZergCommandResearchMeleeAttacks3:
		cost.m_minerals = 200;
		cost.m_gas = 200;
		break;
	case eZergCommandResearchGroundCarapace1:
		cost.m_minerals = 150;
		cost.m_gas = 150;
		break;
	case eZergCommandResearchGroundCarapace2:
		cost.m_minerals = 225;
		cost.m_gas = 225;
		break;
	case eZergCommandResearchGroundCarapace3:
		cost.m_minerals = 300;
		cost.m_gas = 300;
		break;
	case eZergCommandResearchMissileAttacks1:
		cost.m_minerals = 100;
		cost.m_gas = 100;
		break;
	case eZergCommandResearchMissileAttacks2:
		cost.m_minerals = 150;
		cost.m_gas = 150;
		break;
	case eZergCommandResearchMissileAttacks3:
		cost.m_minerals = 200;
		cost.m_gas = 200;
		break;
	case eZergCommandResearchGlialReconstitution:
		cost.m_minerals = 100;
		cost.m_gas = 100;
		break;
	case eZergCommandResearchTunnelingClaws:
		cost.m_minerals = 150;
		cost.m_gas = 150;
		break;
	case eZergCommandResearchCentrifugalHooks:
		cost.m_minerals = 150;
		cost.m_gas = 150;
		break;
	case eZergCommandResearchBurrow:
		cost.m_minerals = 100;
		cost.m_gas = 100;
		break;
	case eZergCommandResearchPneumaticCarapace:
		cost.m_minerals = 100;
		cost.m_gas = 100;
		break;
	case eZergCommandResearchVentralSacs:
		cost.m_minerals = 200;
		cost.m_gas = 200;
		break;
	case eZergCommandResearchGroovedSpines:
		cost.m_minerals = 150;
		cost.m_gas = 150;
		break;
	case eZergCommandResearchPathogenGlands:
		cost.m_minerals = 150;
		cost.m_gas = 150;
		break;
	case eZergCommandResearchNeuralParasite:
		cost.m_minerals = 150;
		cost.m_gas = 150;
		break;
	case eZergCommandResearchFlyerAttacks1:
		cost.m_minerals = 100;
		cost.m_gas = 100;
		break;
	case eZergCommandResearchFlyerAttacks2:
		cost.m_minerals = 175;
		cost.m_gas = 175;
		break;
	case eZergCommandResearchFlyerAttacks3:
		cost.m_minerals = 250;
		cost.m_gas = 250;
		break;
	case eZergCommandResearchFlyerCarapace1:
		cost.m_minerals = 150;
		cost.m_gas = 150;
		break;
	case eZergCommandResearchFlyerCarapace2:
		cost.m_minerals = 225;
		cost.m_gas = 225;
		break;
	case eZergCommandResearchFlyerCarapace3:
		cost.m_minerals = 300;
		cost.m_gas = 300;
		break;
	case eZergCommandResearchChitinousPlating:
		cost.m_minerals = 150;
		cost.m_gas = 150;
		break;
	}
}

void CZergState::RecalculateSupply()
{
	m_supply = 
		  1.0 * (m_droneCount + m_droneUnderConstruction)
		+ 2.0 * (m_queenCount + m_queenUnderConstruction)
		+ 0.5 * (m_zerglingCount + m_zerglingUnderConstruction)
		+ 2.0 * (m_roachCount + m_roachUnderConstruction)
		+ 2.0 * (m_hydraliskCount + m_hydraliskUnderConstruction)
		+ 0.5 * (m_banelingCount + m_banelingUnderConstruction)
		+ 2.0 * (m_infestorCount + m_infestorUnderConstruction)
		+ 2.0 * (m_mutaliskCount + m_mutaliskUnderConstruction)
		+ 2.0 * (m_corruptorCount + m_corruptorUnderConstruction)
		+ 6.0 * (m_ultraliskCount + m_ultraliskUnderConstruction)
		+ 2.0 * (m_broodlordCount + m_broodlordUnderConstruction)
		;
}

void CZergState::RecalculateSupplyCap()
{
	m_supplyCap = 2.0 * (m_hatcheryCount + m_lairCount + m_hiveCount) + 8.0 * (m_overlordCount + m_overseerCount);
}

void CZergState::RecalculateSupplyCapUnderConstruction()
{
	m_supplyCapUnderConstruction = m_supplyCap + 2.0 * m_hatcheryUnderConstruction + 8.0 * m_overlordUnderConstruction;
}

void CZergState::RecalculateMineralIncomeRate()
{
	m_mineralIncomeRate = CGameCalcs::CalculateMineralIncomeRate(m_hatcheryCount + m_lairCount + m_hiveCount, m_dronesOnMinerals);
}

void CZergState::RecalculateGasIncomeRate()
{
	m_gasIncomeRate = CGameCalcs::CalculateGasIncomeRate(m_hatcheryCount + m_lairCount + m_hiveCount, m_extractorCount, m_dronesOnGas);
}

void CZergState::ProgressTime(double &time, double duration)
{
	m_minerals += m_mineralIncomeRate * duration;
	m_gas += m_gasIncomeRate * duration;
	m_mineralsMined += m_mineralIncomeRate * duration;
	m_gasHarvested += m_gasIncomeRate * duration;
	double *queenEnergy = m_queenEnergy, *end = m_queenEnergy + mymin(m_queenCount, (size_t)4);
	while(queenEnergy < end)
	{
		(*queenEnergy) = mymin((*queenEnergy) + 0.5625 * duration, 200.0);
		queenEnergy++;
	}
	time += duration;
}

void CZergState::ConsumeLarva(double &time, CLinkedList<CZergEvent> *&events)
{
	m_larvaTotalCount--;

	// TODO: Not necessarily optimal to use first available larva
	if(m_larvaCount[0] > 0)
	{
		m_larvaCount[0]--;
		if(m_larvaCount[0] == 2)
			AddEvent(events, CZergEvent(CZergEvent::eSpawnLarva1, time + 15));
	}
	else if(m_larvaCount[1] > 0)
	{
		m_larvaCount[1]--;
		if(m_larvaCount[1] == 2)
			AddEvent(events, CZergEvent(CZergEvent::eSpawnLarva2, time + 15));
	}
	else if(m_larvaCount[2] > 0)
	{
		m_larvaCount[2]--;
		if(m_larvaCount[2] == 2)
			AddEvent(events, CZergEvent(CZergEvent::eSpawnLarva3, time + 15));
	}
	else if(m_larvaCount[3] > 0)
	{
		m_larvaCount[3]--;
		if(m_larvaCount[3] == 2)
			AddEvent(events, CZergEvent(CZergEvent::eSpawnLarva4, time + 15));
	}
}

void CZergState::UseDroneForMovement(double duration, double &time, CLinkedList<CZergEvent> *&events)
{
	// Simulate drone being pulled off the line for a period beforehand
	if(m_dronesOnMinerals > 0)
	{
		AddEvent(events, CZergEvent(CZergEvent::eDroneStartMiningMinerals, time + duration));
		m_dronesOnMinerals--;
		RecalculateMineralIncomeRate();
	}
	else if(m_dronesOnGas > 0)
	{
		AddEvent(events, CZergEvent(CZergEvent::eDroneStartMiningGas, time + duration));
		m_dronesOnGas--;
		RecalculateGasIncomeRate();
	}
}

void CZergState::UseDroneForBuilding(double duration, double &time, CLinkedList<CZergEvent> *&events)
{
	m_droneCount--;
	m_supply -= 1.0;

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

	UseDroneForMovement(duration, time, events);
}

void CZergState::AddEvent(CLinkedList<CZergEvent> *&events, const CZergEvent &event)
{
	if(!events || event < events->GetData())
		events = new CLinkedList<CZergEvent>(event, events);
	else
		events->InsertOrdered<Less<CZergEvent>>(event);
}

bool CZergState::HasResources(const CResourceCost &cost) const
{
	if(m_minerals < cost.m_minerals)
		return false;
	if(m_gas < cost.m_gas)
		return false;
	if(cost.m_queenEnergy > 0)
	{
		double maxNexusEnergy = 0;
		const double *queenEnergy = m_queenEnergy, *end = m_queenEnergy + mymin(m_queenCount, (size_t)4);
		while(queenEnergy < end && maxNexusEnergy <= cost.m_queenEnergy)
			maxNexusEnergy = mymax(maxNexusEnergy, *(queenEnergy++));
		if(maxNexusEnergy < cost.m_queenEnergy)
			return false;
	}

	return true;
}

void CZergState::SpendResources(const CResourceCost &cost)
{
	m_minerals -= cost.m_minerals;
	m_gas -= cost.m_gas;
	if(cost.m_queenEnergy > 0)
	{
		double *queenEnergy = m_queenEnergy, *end = m_queenEnergy + mymin(m_queenCount, (size_t)4), *best = m_queenEnergy;
		while(queenEnergy < end)
		{
			if(*queenEnergy > *best)
				best = queenEnergy;
			queenEnergy++;
		}

		*best -= cost.m_queenEnergy;
	}
}

void CZergState::PrintDetails(CString &output) const
{
	PrintSummary(output);

	output.AppendFormat(L"\r\nIncome:   %4.0fM %4.0fG", 60.0 * m_mineralIncomeRate, 60.0 * m_gasIncomeRate);

	output.Append(L"\r\nBuildings: ");

	if(0 < m_hatcheryCount)				output.AppendFormat(L" %u Hatchery", m_hatcheryCount);
	if(0 < m_extractorCount)			output.AppendFormat(L" %u Extractor", m_extractorCount);
	if(0 < m_spawningPoolCount)			output.AppendFormat(L" %u Spawning Pool", m_spawningPoolCount);
	if(0 < m_creepTumorCount)			output.AppendFormat(L" %u Creep Tumor", m_creepTumorCount);
	if(0 < m_evolutionChamberCount)		output.AppendFormat(L" %u Evolution Chamber", m_evolutionChamberCount);
	if(0 < m_spineCrawlerCount)			output.AppendFormat(L" %u Spine Crawler", m_spineCrawlerCount);
	if(0 < m_sporeCrawlerCount)			output.AppendFormat(L" %u Spore Crawler", m_sporeCrawlerCount);
	if(0 < m_roachWarrenCount)			output.AppendFormat(L" %u Roach Warren", m_roachWarrenCount);
	if(0 < m_lairCount)					output.AppendFormat(L" %u Lair", m_lairCount);
	if(0 < m_hydraliskDenCount)			output.AppendFormat(L" %u Hydralisk Den", m_hydraliskDenCount);
	if(0 < m_banelingNestCount)			output.AppendFormat(L" %u Baneling Nest", m_banelingNestCount);
	if(0 < m_spireCount)				output.AppendFormat(L" %u Spire", m_spireCount);
	if(0 < m_infestationPitCount)		output.AppendFormat(L" %u Infestation Pit", m_infestationPitCount);
	if(0 < m_nydusNetworkCount)			output.AppendFormat(L" %u Nydus Network", m_nydusNetworkCount);
	if(0 < m_hiveCount)					output.AppendFormat(L" %u Hive", m_hiveCount);
	if(0 < m_ultraliskCavernCount)		output.AppendFormat(L" %u Ultralisk Cavern", m_ultraliskCavernCount);
	if(0 < m_greaterSpireCount)			output.AppendFormat(L" %u Greater Spire", m_greaterSpireCount);

	output.Append(L"\r\nUnits:     ");

//	if(0 < m_larvaCount)			output.AppendFormat(L" %u Larva", m_larvaCount);
	if(0 < m_droneCount)			output.AppendFormat(L" %u Drone", m_droneCount);
	if(0 < m_overlordCount)			output.AppendFormat(L" %u Overlord", m_overlordCount);
	if(0 < m_queenCount)			output.AppendFormat(L" %u Queen", m_queenCount);
	if(0 < m_zerglingCount)			output.AppendFormat(L" %u Zergling", m_zerglingCount);
	if(0 < m_roachCount)			output.AppendFormat(L" %u Roach", m_roachCount);
	if(0 < m_hydraliskCount)		output.AppendFormat(L" %u Hydralisk", m_hydraliskCount);
	if(0 < m_banelingCount)			output.AppendFormat(L" %u Baneling", m_banelingCount);
	if(0 < m_overseerCount)			output.AppendFormat(L" %u Overseer", m_overseerCount);
	if(0 < m_infestorCount)			output.AppendFormat(L" %u Infestor", m_infestorCount);
	if(0 < m_mutaliskCount)			output.AppendFormat(L" %u Mutalisk", m_mutaliskCount);
	if(0 < m_corruptorCount)		output.AppendFormat(L" %u Corruptor", m_corruptorCount);
	if(0 < m_ultraliskCount)		output.AppendFormat(L" %u Ultralisk", m_ultraliskCount);
	if(0 < m_broodlordCount)		output.AppendFormat(L" %u Broodlord", m_broodlordCount);

	output.Append(L"\r\nUpgrades:  ");

	if(m_researchAdrenalGlandsCompleted)			output.Append(L" Adrenal Glands");
	if(m_researchMetabolicBoostCompleted)			output.Append(L" Metabolic Boost");
	if(m_researchMeleeAttacks1Completed)			output.Append(L" Melee Attacks 1");
	if(m_researchMeleeAttacks2Completed)			output.Append(L" Melee Attacks 2");
	if(m_researchMeleeAttacks3Completed)			output.Append(L" Melee Attacks 3");
	if(m_researchGroundCarapace1Completed)			output.Append(L" Ground Carapace 1");
	if(m_researchGroundCarapace2Completed)			output.Append(L" Ground Carapace 2");
	if(m_researchGroundCarapace3Completed)			output.Append(L" Ground Carapace 3");
	if(m_researchMissileAttacks1Completed)			output.Append(L" Missile Attacks 1");
	if(m_researchMissileAttacks2Completed)			output.Append(L" Missile Attacks 2");
	if(m_researchMissileAttacks3Completed)			output.Append(L" Missile Attacks 3");
	if(m_researchGlialReconstitutionCompleted)		output.Append(L" Glial Reconstitution");
	if(m_researchTunnelingClawsCompleted)			output.Append(L" Tunneling Claws");
	if(m_researchCentrifugalHooksCompleted)			output.Append(L" Centrifugal Hooks");
	if(m_researchBurrowCompleted)					output.Append(L" Burrow");
	if(m_researchPneumaticCarapaceCompleted)		output.Append(L" Pneumatic Carapace");
	if(m_researchVentralSacsCompleted)				output.Append(L" Ventral Sacs");
	if(m_researchGroovedSpinesCompleted)			output.Append(L" Grooved Spines");
	if(m_researchPathogenGlandsCompleted)			output.Append(L" Pathogen Glands");
	if(m_researchNeuralParasiteCompleted)			output.Append(L" Neural Parasite");
	if(m_researchFlyerAttacks1Completed)			output.Append(L" Flyer Attacks 1");
	if(m_researchFlyerAttacks2Completed)			output.Append(L" Flyer Attacks 2");
	if(m_researchFlyerAttacks3Completed)			output.Append(L" Flyer Attacks 3");
	if(m_researchFlyerCarapace1Completed)			output.Append(L" Flyer Carapace 1");
	if(m_researchFlyerCarapace2Completed)			output.Append(L" Flyer Carapace 2");
	if(m_researchFlyerCarapace3Completed)			output.Append(L" Flyer Carapace 3");
	if(m_researchChitinousPlatingCompleted)			output.Append(L" Chitinous Plating");

	output.Append(L"\r\n");
}

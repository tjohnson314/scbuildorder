#include "stdafx.h"
#include "TerranState.h"
#include "TerranEvent.h"
#include "GameCalcs.h"

CTerranState::CTerranState()
: m_minerals(0), m_gas(0)
, m_baseCount(0), m_commandCenterCount(0), m_refineryCount(0), m_barracksCount(0), m_orbitalCommandCount(0), m_engineeringBayCount(0), m_bunkerCount(0), m_missileTurretCount(0), m_sensorTowerCount(0), m_planetaryFortressCount(0), m_ghostAcademyCount(0), m_factoryCount(0), m_armoryCount(0), m_starportCount(0), m_fusionCoreCount(0)
, m_techLabCount(0), m_reactorCount(0), m_barracksTechLabCount(0), m_barracksReactorCount(0), m_factoryTechLabCount(0), m_factoryReactorCount(0), m_starportTechLabCount(0), m_starportReactorCount(0)
, m_commandCenterUnderConstruction(0), m_refineryUnderConstruction(0), m_barracksUnderConstruction(0), m_orbitalCommandUnderConstruction(0), m_engineeringBayUnderConstruction(0), m_bunkerUnderConstruction(0), m_missileTurretUnderConstruction(0), m_sensorTowerUnderConstruction(0), m_planetaryFortressUnderConstruction(0), m_ghostAcademyUnderConstruction(0), m_factoryUnderConstruction(0), m_armoryUnderConstruction(0), m_starportUnderConstruction(0), m_fusionCoreUnderConstruction(0)
, m_commandCenterInUse(0), m_barracksInUse(0), m_orbitalCommandInUse(0), m_engineeringBayInUse(0), m_bunkerInUse(0), m_missileTurretInUse(0), m_sensorTowerInUse(0), m_planetaryFortressInUse(0), m_ghostAcademyInUse(0), m_factoryInUse(0), m_armoryInUse(0), m_starportInUse(0), m_fusionCoreInUse(0)
, m_techLabAvailable(0), m_reactorAvailable(0), m_barracksTechLabInUse(0), m_barracksReactorInUse(0), m_factoryTechLabInUse(0), m_factoryReactorInUse(0), m_starportTechLabInUse(0), m_starportReactorInUse(0)
, m_barracksTechLabUnderConstruction(0), m_barracksReactorUnderConstruction(0), m_factoryTechLabUnderConstruction(0), m_factoryReactorUnderConstruction(0), m_starportTechLabUnderConstruction(0), m_starportReactorUnderConstruction(0)
, m_ghostAcademyNukeCount(0), m_ghostAcademyNukeUnderConstruction(0)
, m_scvCount(0), m_muleCount(0), m_marineCount(0), m_marauderCount(0), m_reaperCount(0), m_ghostCount(0), m_hellionCount(0), m_siegeTankCount(0), m_thorCount(0), m_vikingCount(0), m_medivacCount(0), m_ravenCount(0), m_bansheeCount(0), m_battleCruiserCount(0)
, m_scvUnderConstruction(0), m_muleUnderConstruction(0), m_marineUnderConstruction(0), m_marauderUnderConstruction(0), m_reaperUnderConstruction(0), m_ghostUnderConstruction(0), m_hellionUnderConstruction(0), m_siegeTankUnderConstruction(0), m_thorUnderConstruction(0), m_vikingUnderConstruction(0), m_medivacUnderConstruction(0), m_ravenUnderConstruction(0), m_bansheeUnderConstruction(0), m_battleCruiserUnderConstruction(0)
, m_researchStimpackCompleted(false), m_researchCombatShieldCompleted(false), m_researchNitroPacksCompleted(false), m_researchConcussiveShellsCompleted(false), m_researchInfantryWeapons1Completed(false), m_researchInfantryWeapons2Completed(false), m_researchInfantryWeapons3Completed(false), m_researchInfantryArmor1Completed(false), m_researchInfantryArmor2Completed(false), m_researchInfantryArmor3Completed(false), m_researchBuildingArmorCompleted(false), m_researchHiSecAutoTrackingCompleted(false), m_researchNeoSteelFrameCompleted(false), m_researchMoebiusReactorCompleted(false), m_researchPersonalCloakingCompleted(false), m_researchInfernalPreIgniterCompleted(false), m_researchSiegeTechCompleted(false), m_researchDurableMaterialsCompleted(false), m_research250mmStrikeCannonsCompleted(false), m_researchVehicleWeapons1Completed(false), m_researchVehicleWeapons2Completed(false), m_researchVehicleWeapons3Completed(false), m_researchVehiclePlating1Completed(false), m_researchVehiclePlating2Completed(false), m_researchVehiclePlating3Completed(false), m_researchShipWeapons1Completed(false), m_researchShipWeapons2Completed(false), m_researchShipWeapons3Completed(false), m_researchShipPlating1Completed(false), m_researchShipPlating2Completed(false), m_researchShipPlating3Completed(false), m_researchCorvidReactorCompleted(false), m_researchCaduceusReactorCompleted(false), m_researchSeekerMissileCompleted(false), m_researchCloakingFieldCompleted(false), m_researchBehemothReactorCompleted(false), m_researchWeaponRefitCompleted(false)
, m_researchStimpackUnderConstruction(false), m_researchCombatShieldUnderConstruction(false), m_researchNitroPacksUnderConstruction(false), m_researchConcussiveShellsUnderConstruction(false), m_researchInfantryWeapons1UnderConstruction(false), m_researchInfantryWeapons2UnderConstruction(false), m_researchInfantryWeapons3UnderConstruction(false), m_researchInfantryArmor1UnderConstruction(false), m_researchInfantryArmor2UnderConstruction(false), m_researchInfantryArmor3UnderConstruction(false), m_researchBuildingArmorUnderConstruction(false), m_researchHiSecAutoTrackingUnderConstruction(false), m_researchNeoSteelFrameUnderConstruction(false), m_researchMoebiusReactorUnderConstruction(false), m_researchPersonalCloakingUnderConstruction(false), m_researchInfernalPreIgniterUnderConstruction(false), m_researchSiegeTechUnderConstruction(false), m_researchDurableMaterialsUnderConstruction(false), m_research250mmStrikeCannonsUnderConstruction(false), m_researchVehicleWeapons1UnderConstruction(false), m_researchVehicleWeapons2UnderConstruction(false), m_researchVehicleWeapons3UnderConstruction(false), m_researchVehiclePlating1UnderConstruction(false), m_researchVehiclePlating2UnderConstruction(false), m_researchVehiclePlating3UnderConstruction(false), m_researchShipWeapons1UnderConstruction(false), m_researchShipWeapons2UnderConstruction(false), m_researchShipWeapons3UnderConstruction(false), m_researchShipPlating1UnderConstruction(false), m_researchShipPlating2UnderConstruction(false), m_researchShipPlating3UnderConstruction(false), m_researchCorvidReactorUnderConstruction(false), m_researchCaduceusReactorUnderConstruction(false), m_researchSeekerMissileUnderConstruction(false), m_researchCloakingFieldUnderConstruction(false), m_researchBehemothReactorUnderConstruction(false), m_researchWeaponRefitUnderConstruction(false)
, m_scvsOnMinerals(0), m_scvsOnGas(0), m_scannerSweepCount(0)
, m_supply(0), m_supplyCap(0), m_supplyCapUnderConstruction(0)
, m_mineralIncomeRate(0), m_gasIncomeRate(0)
{
	for(size_t i=0; i < 4; i++)
		m_orbitalCommandEnergy[i] = 0;
}

CTerranState::~CTerranState()
{
}

void CTerranState::SetInitialState()
{
	memset(this, 0, sizeof(CTerranState));
	m_minerals = 50;
	m_baseCount = 1;
	m_commandCenterCount = 1;
	m_scvCount = 6;
	m_scvsOnMinerals = 6;

	RecalculateSupply();
	RecalculateSupplyCap();
	RecalculateSupplyCapUnderConstruction();
	RecalculateMineralIncomeRate();
	RecalculateGasIncomeRate();
}

void CTerranState::operator=(const CTerranState &state)
{
	memmove(this, &state, sizeof(CTerranState));
}

bool CTerranState::GetResourceWaitTime(const CResourceCost &cost, double &resourceWaitTime) const
{
	double mineralTimeRequired = 0, gasTimeRequired = 0, orbitalCommandTimeRequired = 0;

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
	const double *orbitalCommandEnergy = m_orbitalCommandEnergy, *end = m_orbitalCommandEnergy + mymin(m_orbitalCommandCount, (size_t)4);
	while(orbitalCommandEnergy < end)
		maxNexusEnergy = mymax(maxNexusEnergy, *(orbitalCommandEnergy++));
	double orbitalCommandEnergyRequired = cost.m_orbitalCommandEnergy - maxNexusEnergy;
	if(orbitalCommandEnergyRequired > 0)
	{
		if(m_orbitalCommandCount <= 0)
			return false;

		orbitalCommandTimeRequired = orbitalCommandEnergyRequired / 0.5625;
	}

	resourceWaitTime = mymax(mymax(mineralTimeRequired, gasTimeRequired), orbitalCommandTimeRequired);

	return true;
}

void CTerranState::ExecuteCommand(double &time, double timeLimit, ETerranCommand command, CLinkedList<CTerranEvent> *&events)
{
	switch(command)
	{
	case eTerranCommandBuildCommandCenter:
		UseSCVForBuilding(15, time, events);
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnCommandCenter, time + 100));
		m_commandCenterUnderConstruction++;
		m_supplyCapUnderConstruction += 11;
		break;
	case eTerranCommandBuildRefinery:
		if(m_refineryCount + m_refineryUnderConstruction < 2 * m_baseCount)
			UseSCVForBuilding(2, time, events);
		else
			UseSCVForBuilding(15, time, events);
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnRefinery, time + 30));
		m_refineryUnderConstruction++;
		break;
	case eTerranCommandBuildSupplyDepot:
		UseSCVForBuilding(5, time, events);
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnSupplyDepot, time + 30));
		m_supplyDepotUnderConstruction++;
		m_supplyCapUnderConstruction += 8;
		break;
	case eTerranCommandBuildBarracksNaked:
		UseSCVForBuilding(5, time, events);
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnBarracksNaked, time + 60));
		m_barracksUnderConstruction++;
		break;
	case eTerranCommandBuildBarracksOnTechLab:
		UseSCVForBuilding(5, time, events);
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnBarracksOnTechLab, time + 60));
		m_barracksUnderConstruction++;
		m_barracksTechLabUnderConstruction++;
		m_techLabAvailable--;
		break;
	case eTerranCommandBuildBarracksOnReactor:
		UseSCVForBuilding(5, time, events);
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnBarracksOnReactor, time + 60));
		m_barracksUnderConstruction++;
		m_barracksReactorUnderConstruction++;
		m_reactorAvailable--;
		break;
	case eTerranCommandBuildOrbitalCommand:
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnOrbitalCommand, time + 35));
		m_orbitalCommandUnderConstruction++;
		m_commandCenterInUse++;
		break;
	case eTerranCommandBuildEngineeringBay:
		UseSCVForBuilding(5, time, events);
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnEngineeringBay, time + 35));
		m_engineeringBayUnderConstruction++;
		break;
	case eTerranCommandBuildBunker:
		UseSCVForBuilding(5, time, events);
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnBunker, time + 35));
		m_bunkerUnderConstruction++;
		break;
	case eTerranCommandBuildMissileTurret:
		UseSCVForBuilding(5, time, events);
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnMissileTurret, time + 25));
		m_missileTurretUnderConstruction++;
		break;
	case eTerranCommandBuildSensorTower:
		UseSCVForBuilding(5, time, events);
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnSensorTower, time + 25));
		m_sensorTowerUnderConstruction++;
		break;
	case eTerranCommandBuildPlanetaryFortress:
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnPlanetaryFortress, time + 50));
		m_planetaryFortressUnderConstruction++;
		m_orbitalCommandInUse++;
		break;
	case eTerranCommandBuildGhostAcademy:
		UseSCVForBuilding(5, time, events);
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnGhostAcademy, time + 40));
		m_ghostAcademyUnderConstruction++;
		break;
	case eTerranCommandBuildFactoryNaked:
		UseSCVForBuilding(5, time, events);
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnFactoryNaked, time + 60));
		m_factoryUnderConstruction++;
		break;
	case eTerranCommandBuildFactoryOnTechLab:
		UseSCVForBuilding(5, time, events);
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnFactoryOnTechLab, time + 60));
		m_factoryUnderConstruction++;
		m_factoryTechLabUnderConstruction++;
		m_techLabAvailable--;
		break;
	case eTerranCommandBuildFactoryOnReactor:
		UseSCVForBuilding(5, time, events);
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnFactoryOnReactor, time + 60));
		m_factoryUnderConstruction++;
		m_factoryReactorUnderConstruction++;
		m_reactorAvailable--;
		break;
	case eTerranCommandBuildArmory:
		UseSCVForBuilding(5, time, events);
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnArmory, time + 65));
		m_armoryUnderConstruction++;
		break;
	case eTerranCommandBuildStarportNaked:
		UseSCVForBuilding(5, time, events);
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnStarportNaked, time + 50));
		m_starportUnderConstruction++;
		break;
	case eTerranCommandBuildStarportOnTechLab:
		UseSCVForBuilding(5, time, events);
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnStarportOnTechLab, time + 50));
		m_starportUnderConstruction++;
		m_starportTechLabUnderConstruction++;
		m_techLabAvailable--;
		break;
	case eTerranCommandBuildStarportOnReactor:
		UseSCVForBuilding(5, time, events);
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnStarportOnReactor, time + 50));
		m_starportUnderConstruction++;
		m_starportReactorUnderConstruction++;
		m_reactorAvailable--;
		break;
	case eTerranCommandBuildFusionCore:
		UseSCVForBuilding(5, time, events);
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnFusionCore, time + 65));
		m_fusionCoreUnderConstruction++;
		break;

	case eTerranCommandBuildBarracksReactor:
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnBarracksReactor, time + 50));
		m_barracksReactorUnderConstruction++;
		m_barracksInUse++;
		break;
	case eTerranCommandBuildBarracksTechLab:
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnBarracksTechLab, time + 25));
		m_barracksTechLabUnderConstruction++;
		m_barracksInUse++;
		break;
	case eTerranCommandBuildFactoryReactor:
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnFactoryReactor, time + 50));
		m_factoryReactorUnderConstruction++;
		m_factoryInUse++;
		break;
	case eTerranCommandBuildFactoryTechLab:
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnFactoryTechLab, time + 25));
		m_factoryTechLabUnderConstruction++;
		m_factoryInUse++;
		break;
	case eTerranCommandBuildStarportReactor:
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnStarportReactor, time + 50));
		m_starportReactorUnderConstruction++;
		m_starportInUse++;
		break;
	case eTerranCommandBuildStarportTechLab:
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnStarportTechLab, time + 25));
		m_starportTechLabUnderConstruction++;
		m_starportInUse++;
		break;

	case eTerranCommandBuildSCV:
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnSCV, time + 17));
		m_scvUnderConstruction++;
		m_supply++;
		m_commandCenterInUse++;
		break;
	case eTerranCommandBuildMarine:
		if(m_barracksReactorInUse < 2 * m_barracksReactorCount)
		{
			AddEvent(events, CTerranEvent(CTerranEvent::eSpawnMarineReactor, time + 25));
			m_barracksReactorInUse++;
		}
		else if(m_barracksInUse < m_barracksCount - m_barracksReactorCount - m_barracksTechLabCount)
		{
			AddEvent(events, CTerranEvent(CTerranEvent::eSpawnMarineNaked, time + 25));
			m_barracksInUse++;
		}
		else
		{
			AddEvent(events, CTerranEvent(CTerranEvent::eSpawnMarineTechLab, time + 25));
			m_barracksTechLabInUse++;
		}
		m_marineUnderConstruction++;
		m_supply++;
		break;
	case eTerranCommandBuildMarineNaked:
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnMarineNaked, time + 25));
		m_marineUnderConstruction++;
		m_supply++;
		m_barracksInUse++;
		break;
	case eTerranCommandBuildMarineReactor:
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnMarineReactor, time + 25));
		m_marineUnderConstruction++;
		m_supply++;
		m_barracksReactorInUse++;
		break;
	case eTerranCommandBuildMarineTechLab:
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnMarineTechLab, time + 25));
		m_marineUnderConstruction++;
		m_supply++;
		m_barracksTechLabInUse++;
		break;
	case eTerranCommandBuildMarauder:
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnMarauder, time + 30));
		m_marauderUnderConstruction++;
		m_supply += 2;
		m_barracksTechLabInUse++;
		break;
	case eTerranCommandBuildReaper:
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnReaper, time + 45));
		m_reaperUnderConstruction++;
		m_supply++;
		m_barracksTechLabInUse++;
		break;
	case eTerranCommandBuildGhost:
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnGhost, time + 40));
		m_ghostUnderConstruction++;
		m_supply += 2;
		m_barracksTechLabInUse++;
		break;
	case eTerranCommandBuildHellion:
		if(m_factoryReactorInUse < 2 * m_factoryReactorCount)
		{
			AddEvent(events, CTerranEvent(CTerranEvent::eSpawnHellionReactor, time + 30));
			m_factoryReactorInUse++;
		}
		else if(m_factoryInUse < m_factoryCount - m_factoryReactorCount - m_factoryTechLabCount)
		{
			AddEvent(events, CTerranEvent(CTerranEvent::eSpawnHellionNaked, time + 30));
			m_factoryInUse++;
		}
		else
		{
			AddEvent(events, CTerranEvent(CTerranEvent::eSpawnHellionTechLab, time + 30));
			m_factoryTechLabInUse++;
		}
		m_hellionUnderConstruction++;
		m_supply += 2;
		break;
	case eTerranCommandBuildHellionNaked:
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnHellionNaked, time + 30));
		m_hellionUnderConstruction++;
		m_supply += 2;
		m_factoryInUse++;
		break;
	case eTerranCommandBuildHellionReactor:
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnHellionReactor, time + 30));
		m_hellionUnderConstruction++;
		m_supply += 2;
		m_factoryReactorInUse++;
		break;
	case eTerranCommandBuildHellionTechLab:
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnHellionTechLab, time + 30));
		m_hellionUnderConstruction++;
		m_supply += 2;
		m_factoryTechLabInUse++;
		break;
	case eTerranCommandBuildSiegeTank:
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnSiegeTank, time + 45));
		m_siegeTankUnderConstruction++;
		m_supply += 3;
		m_factoryTechLabInUse++;
		break;
	case eTerranCommandBuildThor:
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnThor, time + 60));
		m_thorUnderConstruction++;
		m_supply += 6;
		m_factoryTechLabInUse++;
		break;
	case eTerranCommandBuildViking:
		if(m_starportReactorInUse < 2 * m_starportReactorCount)
		{
			AddEvent(events, CTerranEvent(CTerranEvent::eSpawnVikingReactor, time + 42));
			m_starportReactorInUse++;
		}
		else if(m_starportInUse < m_starportCount - m_starportReactorCount - m_starportTechLabCount)
		{
			AddEvent(events, CTerranEvent(CTerranEvent::eSpawnVikingNaked, time + 42));
			m_starportInUse++;
		}
		else
		{
			AddEvent(events, CTerranEvent(CTerranEvent::eSpawnVikingTechLab, time + 42));
			m_starportTechLabInUse++;
		}
		m_vikingUnderConstruction++;
		m_supply += 2;
		break;
	case eTerranCommandBuildVikingNaked:
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnVikingNaked, time + 42));
		m_vikingUnderConstruction++;
		m_supply += 2;
		m_starportInUse++;
		break;
	case eTerranCommandBuildVikingReactor:
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnVikingReactor, time + 42));
		m_vikingUnderConstruction++;
		m_supply += 2;
		m_starportReactorInUse++;
		break;
	case eTerranCommandBuildVikingTechLab:
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnVikingTechLab, time + 42));
		m_vikingUnderConstruction++;
		m_supply += 2;
		m_starportTechLabInUse++;
		break;
	case eTerranCommandBuildMedivac:
		if(m_starportReactorInUse < 2 * m_starportReactorCount)
		{
			AddEvent(events, CTerranEvent(CTerranEvent::eSpawnMedivacReactor, time + 42));
			m_starportReactorInUse++;
		}
		else if(m_starportInUse < m_starportCount - m_starportReactorCount - m_starportTechLabCount)
		{
			AddEvent(events, CTerranEvent(CTerranEvent::eSpawnMedivacNaked, time + 42));
			m_starportInUse++;
		}
		else
		{
			AddEvent(events, CTerranEvent(CTerranEvent::eSpawnMedivacTechLab, time + 42));
			m_starportTechLabInUse++;
		}
		m_medivacUnderConstruction++;
		m_supply += 2;
		break;
	case eTerranCommandBuildMedivacNaked:
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnMedivacNaked, time + 42));
		m_medivacUnderConstruction++;
		m_supply += 2;
		m_starportInUse++;
		break;
	case eTerranCommandBuildMedivacReactor:
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnMedivacReactor, time + 42));
		m_medivacUnderConstruction++;
		m_supply += 2;
		m_starportReactorInUse++;
		break;
	case eTerranCommandBuildMedivacTechLab:
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnMedivacTechLab, time + 42));
		m_medivacUnderConstruction++;
		m_supply += 2;
		m_starportTechLabInUse++;
		break;
	case eTerranCommandBuildRaven:
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnRaven, time + 60));
		m_ravenUnderConstruction++;
		m_supply += 2;
		m_starportTechLabInUse++;
		break;
	case eTerranCommandBuildBanshee:
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnBanshee, time + 60));
		m_bansheeUnderConstruction++;
		m_supply += 3;
		m_starportTechLabInUse++;
		break;
	case eTerranCommandBuildBattleCruiser:
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnBattleCruiser, time + 90));
		m_battleCruiserUnderConstruction++;
		m_supply += 6;
		m_starportTechLabInUse++;
		break;

	case eTerranCommandCalldownMULE:
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnMULE, time + 3));
		m_muleUnderConstruction++;
		break;
	case eTerranCommandCalldownExtraSupplies:
		AddEvent(events, CTerranEvent(CTerranEvent::eSpawnSupplyDepotExtraSupplies, time + 3));
		m_supplyDepotExtraSuppliesUnderConstruction++;
		break;
	case eTerranCommandScannerSweep:
		m_scannerSweepCount++;
		break;

	case eTerranCommandResearchStimpack:
		AddEvent(events, CTerranEvent(CTerranEvent::eResearchStimpackComplete, time + 140));
		m_researchStimpackUnderConstruction = true;
		m_barracksTechLabResearchInUse++;
		break;
	case eTerranCommandResearchCombatShield:
		AddEvent(events, CTerranEvent(CTerranEvent::eResearchCombatShieldComplete, time + 110));
		m_researchCombatShieldUnderConstruction = true;
		m_barracksTechLabResearchInUse++;
		break;
	case eTerranCommandResearchNitroPacks:
		AddEvent(events, CTerranEvent(CTerranEvent::eResearchNitroPacksComplete, time + 100));
		m_researchNitroPacksUnderConstruction = true;
		m_barracksTechLabResearchInUse++;
		break;
	case eTerranCommandResearchConcussiveShells:
		AddEvent(events, CTerranEvent(CTerranEvent::eResearchConcussiveShellsComplete, time + 60));
		m_researchConcussiveShellsUnderConstruction = true;
		m_barracksTechLabResearchInUse++;
		break;
	case eTerranCommandResearchInfantryWeapons1:
		AddEvent(events, CTerranEvent(CTerranEvent::eResearchInfantryWeapons1Complete, time + 160));
		m_researchInfantryWeapons1UnderConstruction = true;
		m_engineeringBayInUse++;
		break;
	case eTerranCommandResearchInfantryWeapons2:
		AddEvent(events, CTerranEvent(CTerranEvent::eResearchInfantryWeapons2Complete, time + 190));
		m_researchInfantryWeapons2UnderConstruction = true;
		m_engineeringBayInUse++;
		break;
	case eTerranCommandResearchInfantryWeapons3:
		AddEvent(events, CTerranEvent(CTerranEvent::eResearchInfantryWeapons3Complete, time + 220));
		m_researchInfantryWeapons3UnderConstruction = true;
		m_engineeringBayInUse++;
		break;
	case eTerranCommandResearchInfantryArmor1:
		AddEvent(events, CTerranEvent(CTerranEvent::eResearchInfantryArmor1Complete, time + 160));
		m_researchInfantryArmor1UnderConstruction = true;
		m_engineeringBayInUse++;
		break;
	case eTerranCommandResearchInfantryArmor2:
		AddEvent(events, CTerranEvent(CTerranEvent::eResearchInfantryArmor2Complete, time + 190));
		m_researchInfantryArmor2UnderConstruction = true;
		m_engineeringBayInUse++;
		break;
	case eTerranCommandResearchInfantryArmor3:
		AddEvent(events, CTerranEvent(CTerranEvent::eResearchInfantryArmor3Complete, time + 220));
		m_researchInfantryArmor3UnderConstruction = true;
		m_engineeringBayInUse++;
		break;
	case eTerranCommandResearchBuildingArmor:
		AddEvent(events, CTerranEvent(CTerranEvent::eResearchBuildingArmorComplete, time + 140));
		m_researchBuildingArmorUnderConstruction = true;
		m_engineeringBayInUse++;
		break;
	case eTerranCommandResearchHiSecAutoTracking:
		AddEvent(events, CTerranEvent(CTerranEvent::eResearchHiSecAutoTrackingComplete, time + 80));
		m_researchHiSecAutoTrackingUnderConstruction = true;
		m_engineeringBayInUse++;
		break;
	case eTerranCommandResearchNeoSteelFrame:
		AddEvent(events, CTerranEvent(CTerranEvent::eResearchNeoSteelFrameComplete, time + 110));
		m_researchNeoSteelFrameUnderConstruction = true;
		m_engineeringBayInUse++;
		break;
	case eTerranCommandResearchMoebiusReactor:
		AddEvent(events, CTerranEvent(CTerranEvent::eResearchMoebiusReactorComplete, time + 80));
		m_researchMoebiusReactorUnderConstruction = true;
		m_ghostAcademyInUse++;
		break;
	case eTerranCommandResearchPersonalCloaking:
		AddEvent(events, CTerranEvent(CTerranEvent::eResearchPersonalCloakingComplete, time + 120));
		m_researchPersonalCloakingUnderConstruction = true;
		m_ghostAcademyInUse++;
		break;
	case eTerranCommandArmNuke:
		AddEvent(events, CTerranEvent(CTerranEvent::eArmNukeComplete, time + 60));
		m_ghostAcademyNukeUnderConstruction++;
		m_ghostAcademyInUse++;
		break;
	case eTerranCommandResearchInfernalPreIgniter:
		AddEvent(events, CTerranEvent(CTerranEvent::eResearchInfernalPreIgniterComplete, time + 110));
		m_researchInfernalPreIgniterUnderConstruction = true;
		m_factoryTechLabResearchInUse++;
		break;
	case eTerranCommandResearchSiegeTech:
		AddEvent(events, CTerranEvent(CTerranEvent::eResearchSiegeTechComplete, time + 80));
		m_researchSiegeTechUnderConstruction = true;
		m_factoryTechLabResearchInUse++;
		break;
	case eTerranCommandResearchDurableMaterials:
		AddEvent(events, CTerranEvent(CTerranEvent::eResearchDurableMaterialsComplete, time + 110));
		m_researchDurableMaterialsUnderConstruction = true;
		m_factoryTechLabResearchInUse++;
		break;
	case eTerranCommandResearch250mmStrikeCannons:
		AddEvent(events, CTerranEvent(CTerranEvent::eResearch250mmStrikeCannonsComplete, time + 110));
		m_research250mmStrikeCannonsUnderConstruction = true;
		m_factoryTechLabResearchInUse++;
		break;
	case eTerranCommandResearchVehicleWeapons1:
		AddEvent(events, CTerranEvent(CTerranEvent::eResearchVehicleWeapons1Complete, time + 160));
		m_researchVehicleWeapons1UnderConstruction = true;
		m_armoryInUse++;
		break;
	case eTerranCommandResearchVehicleWeapons2:
		AddEvent(events, CTerranEvent(CTerranEvent::eResearchVehicleWeapons2Complete, time + 190));
		m_researchVehicleWeapons2UnderConstruction = true;
		m_armoryInUse++;
		break;
	case eTerranCommandResearchVehicleWeapons3:
		AddEvent(events, CTerranEvent(CTerranEvent::eResearchVehicleWeapons3Complete, time + 220));
		m_researchVehicleWeapons3UnderConstruction = true;
		m_armoryInUse++;
		break;
	case eTerranCommandResearchVehiclePlating1:
		AddEvent(events, CTerranEvent(CTerranEvent::eResearchVehiclePlating1Complete, time + 160));
		m_researchVehiclePlating1UnderConstruction = true;
		m_armoryInUse++;
		break;
	case eTerranCommandResearchVehiclePlating2:
		AddEvent(events, CTerranEvent(CTerranEvent::eResearchVehiclePlating2Complete, time + 190));
		m_researchVehiclePlating2UnderConstruction = true;
		m_armoryInUse++;
		break;
	case eTerranCommandResearchVehiclePlating3:
		AddEvent(events, CTerranEvent(CTerranEvent::eResearchVehiclePlating3Complete, time + 220));
		m_researchVehiclePlating3UnderConstruction = true;
		m_armoryInUse++;
		break;
	case eTerranCommandResearchShipWeapons1:
		AddEvent(events, CTerranEvent(CTerranEvent::eResearchShipWeapons1Complete, time + 160));
		m_researchShipWeapons1UnderConstruction = true;
		m_armoryInUse++;
		break;
	case eTerranCommandResearchShipWeapons2:
		AddEvent(events, CTerranEvent(CTerranEvent::eResearchShipWeapons2Complete, time + 190));
		m_researchShipWeapons2UnderConstruction = true;
		m_armoryInUse++;
		break;
	case eTerranCommandResearchShipWeapons3:
		AddEvent(events, CTerranEvent(CTerranEvent::eResearchShipWeapons3Complete, time + 220));
		m_researchShipWeapons3UnderConstruction = true;
		m_armoryInUse++;
		break;
	case eTerranCommandResearchShipPlating1:
		AddEvent(events, CTerranEvent(CTerranEvent::eResearchShipPlating1Complete, time + 160));
		m_researchShipPlating1UnderConstruction = true;
		m_armoryInUse++;
		break;
	case eTerranCommandResearchShipPlating2:
		AddEvent(events, CTerranEvent(CTerranEvent::eResearchShipPlating2Complete, time + 190));
		m_researchShipPlating2UnderConstruction = true;
		m_armoryInUse++;
		break;
	case eTerranCommandResearchShipPlating3:
		AddEvent(events, CTerranEvent(CTerranEvent::eResearchShipPlating3Complete, time + 220));
		m_researchShipPlating3UnderConstruction = true;
		m_armoryInUse++;
		break;
	case eTerranCommandResearchCorvidReactor:
		AddEvent(events, CTerranEvent(CTerranEvent::eResearchCorvidReactorComplete, time + 110));
		m_researchCorvidReactorUnderConstruction = true;
		m_starportTechLabResearchInUse++;
		break;
	case eTerranCommandResearchCaduceusReactor:
		AddEvent(events, CTerranEvent(CTerranEvent::eResearchCaduceusReactorComplete, time + 80));
		m_researchCaduceusReactorUnderConstruction = true;
		m_starportTechLabResearchInUse++;
		break;
	case eTerranCommandResearchSeekerMissile:
		AddEvent(events, CTerranEvent(CTerranEvent::eResearchSeekerMissileComplete, time + 110));
		m_researchSeekerMissileUnderConstruction = true;
		m_starportTechLabResearchInUse++;
		break;
	case eTerranCommandResearchCloakingField:
		AddEvent(events, CTerranEvent(CTerranEvent::eResearchCloakingFieldComplete, time + 110));
		m_researchCloakingFieldUnderConstruction = true;
		m_starportTechLabResearchInUse++;
		break;
	case eTerranCommandResearchBehemothReactor:
		AddEvent(events, CTerranEvent(CTerranEvent::eResearchBehemothReactorComplete, time + 80));
		m_researchBehemothReactorUnderConstruction = true;
		m_fusionCoreInUse++;
		break;
	case eTerranCommandResearchWeaponRefit:
		AddEvent(events, CTerranEvent(CTerranEvent::eResearchWeaponRefitComplete, time + 60));
		m_researchWeaponRefitUnderConstruction = true;
		m_fusionCoreInUse++;
		break;

	case eTerranCommandMoveSCVToGas:
		AddEvent(events, CTerranEvent(CTerranEvent::eSCVStartMiningGas, time + 2));
		m_scvsOnMinerals--;
		RecalculateMineralIncomeRate();
		break;
	case eTerranCommandMoveSCVToMinerals:
		AddEvent(events, CTerranEvent(CTerranEvent::eSCVStartMiningMinerals, time + 2));
		m_scvsOnGas--;
		RecalculateGasIncomeRate();
		break;
	}
}

void CTerranState::ProcessEvent(double &time, CLinkedList<CTerranEvent> *&events)
{
	CLinkedList<CTerranEvent> *entry = events;
	events = entry->GetNext();

	ProgressTime(time, entry->GetData().time() - time);

	switch(entry->GetData().event())
	{
	case CTerranEvent::eSpawnCommandCenter:
		m_commandCenterUnderConstruction--;
		m_commandCenterCount++;
		m_baseCount++;
		m_supplyCap += 11;
		RecalculateMineralIncomeRate();
		RecalculateGasIncomeRate();
		AddEvent(events, CTerranEvent(CTerranEvent::eSCVStartMiningMinerals, time + 2));
		break;
	case CTerranEvent::eSpawnRefinery:
		m_refineryUnderConstruction--;
		m_refineryCount++;
		RecalculateGasIncomeRate();
		AddEvent(events, CTerranEvent(CTerranEvent::eSCVStartMiningMinerals, time + 2));
		break;
	case CTerranEvent::eSpawnSupplyDepot:
		m_supplyDepotUnderConstruction--;
		m_supplyDepotCount++;
		m_supplyCap += 8;
		AddEvent(events, CTerranEvent(CTerranEvent::eSCVStartMiningMinerals, time + 5));
		break;
	case CTerranEvent::eSpawnSupplyDepotExtraSupplies:
		m_supplyDepotExtraSuppliesUnderConstruction--;
		m_supplyDepotExtraSuppliesCount++;
		m_supplyCap += 8;
		break;
	case CTerranEvent::eSpawnBarracksNaked:
		m_barracksUnderConstruction--;
		m_barracksCount++;
		AddEvent(events, CTerranEvent(CTerranEvent::eSCVStartMiningMinerals, time + 5));
		break;
	case CTerranEvent::eSpawnBarracksOnTechLab:
		m_barracksUnderConstruction--;
		m_barracksCount++;
		m_barracksTechLabUnderConstruction--;
		m_barracksTechLabCount++;
		AddEvent(events, CTerranEvent(CTerranEvent::eSCVStartMiningMinerals, time + 5));
		break;
	case CTerranEvent::eSpawnBarracksOnReactor:
		m_barracksUnderConstruction--;
		m_barracksCount++;
		m_barracksReactorUnderConstruction--;
		m_barracksReactorCount++;
		AddEvent(events, CTerranEvent(CTerranEvent::eSCVStartMiningMinerals, time + 5));
		break;
	case CTerranEvent::eSpawnOrbitalCommand:
		if(m_orbitalCommandCount < 4)
			m_orbitalCommandEnergy[m_orbitalCommandCount] = 50.0;
		m_commandCenterInUse--;
		m_orbitalCommandUnderConstruction--;
		m_orbitalCommandCount++;
		break;
	case CTerranEvent::eSpawnEngineeringBay:
		m_engineeringBayUnderConstruction--;
		m_engineeringBayCount++;
		AddEvent(events, CTerranEvent(CTerranEvent::eSCVStartMiningMinerals, time + 5));
		break;
	case CTerranEvent::eSpawnBunker:
		m_bunkerUnderConstruction--;
		m_bunkerCount++;
		AddEvent(events, CTerranEvent(CTerranEvent::eSCVStartMiningMinerals, time + 5));
		break;
	case CTerranEvent::eSpawnMissileTurret:
		m_missileTurretUnderConstruction--;
		m_missileTurretCount++;
		AddEvent(events, CTerranEvent(CTerranEvent::eSCVStartMiningMinerals, time + 5));
		break;
	case CTerranEvent::eSpawnSensorTower:
		m_sensorTowerUnderConstruction--;
		m_sensorTowerCount++;
		AddEvent(events, CTerranEvent(CTerranEvent::eSCVStartMiningMinerals, time + 5));
		break;
	case CTerranEvent::eSpawnPlanetaryFortress:
		m_commandCenterInUse--;
		m_planetaryFortressUnderConstruction--;
		m_planetaryFortressCount++;
		break;
	case CTerranEvent::eSpawnGhostAcademy:
		m_ghostAcademyUnderConstruction--;
		m_ghostAcademyCount++;
		AddEvent(events, CTerranEvent(CTerranEvent::eSCVStartMiningMinerals, time + 5));
		break;
	case CTerranEvent::eSpawnFactoryNaked:
		m_factoryUnderConstruction--;
		m_factoryCount++;
		AddEvent(events, CTerranEvent(CTerranEvent::eSCVStartMiningMinerals, time + 5));
		break;
	case CTerranEvent::eSpawnFactoryOnTechLab:
		m_factoryUnderConstruction--;
		m_factoryCount++;
		m_factoryTechLabUnderConstruction--;
		m_factoryTechLabCount++;
		AddEvent(events, CTerranEvent(CTerranEvent::eSCVStartMiningMinerals, time + 5));
		break;
	case CTerranEvent::eSpawnFactoryOnReactor:
		m_factoryUnderConstruction--;
		m_factoryCount++;
		m_factoryReactorUnderConstruction--;
		m_factoryReactorCount++;
		AddEvent(events, CTerranEvent(CTerranEvent::eSCVStartMiningMinerals, time + 5));
		break;
	case CTerranEvent::eSpawnArmory:
		m_armoryUnderConstruction--;
		m_armoryCount++;
		AddEvent(events, CTerranEvent(CTerranEvent::eSCVStartMiningMinerals, time + 5));
		break;
	case CTerranEvent::eSpawnStarportNaked:
		m_starportUnderConstruction--;
		m_starportCount++;
		AddEvent(events, CTerranEvent(CTerranEvent::eSCVStartMiningMinerals, time + 5));
		break;
	case CTerranEvent::eSpawnStarportOnTechLab:
		m_starportUnderConstruction--;
		m_starportCount++;
		m_starportTechLabUnderConstruction--;
		m_starportTechLabCount++;
		AddEvent(events, CTerranEvent(CTerranEvent::eSCVStartMiningMinerals, time + 5));
		break;
	case CTerranEvent::eSpawnStarportOnReactor:
		m_starportUnderConstruction--;
		m_starportCount++;
		m_starportReactorUnderConstruction--;
		m_starportReactorCount++;
		AddEvent(events, CTerranEvent(CTerranEvent::eSCVStartMiningMinerals, time + 5));
		break;
	case CTerranEvent::eSpawnFusionCore:
		m_fusionCoreUnderConstruction--;
		m_fusionCoreCount++;
		AddEvent(events, CTerranEvent(CTerranEvent::eSCVStartMiningMinerals, time + 5));
		break;

	case CTerranEvent::eSpawnBarracksTechLab:
		m_barracksInUse--;
		m_barracksTechLabCount++;
		m_barracksTechLabUnderConstruction--;
		m_techLabCount++;
		break;
	case CTerranEvent::eSpawnBarracksReactor:
		m_barracksInUse--;
		m_barracksReactorCount++;
		m_barracksReactorUnderConstruction--;
		m_reactorCount++;
		break;
	case CTerranEvent::eSpawnFactoryTechLab:
		m_factoryInUse--;
		m_factoryTechLabCount++;
		m_factoryTechLabUnderConstruction--;
		m_techLabCount++;
		break;
	case CTerranEvent::eSpawnFactoryReactor:
		m_factoryInUse--;
		m_factoryReactorCount++;
		m_factoryReactorUnderConstruction--;
		m_reactorCount++;
		break;
	case CTerranEvent::eSpawnStarportTechLab:
		m_starportInUse--;
		m_starportTechLabCount++;
		m_starportTechLabUnderConstruction--;
		m_techLabCount++;
		break;
	case CTerranEvent::eSpawnStarportReactor:
		m_starportInUse--;
		m_starportReactorCount++;
		m_starportReactorUnderConstruction--;
		m_reactorCount++;
		break;

	case CTerranEvent::eSCVStartMiningMinerals:
		m_scvsOnMinerals++;
		RecalculateMineralIncomeRate();
		break;
	case CTerranEvent::eSCVStartMiningGas:
		m_scvsOnGas++;
		RecalculateGasIncomeRate();
		break;

	case CTerranEvent::eSpawnSCV:
		m_commandCenterInUse--;
		m_scvCount++;
		AddEvent(events, CTerranEvent(CTerranEvent::eSCVStartMiningMinerals, time + 2));
		m_scvUnderConstruction--;
		break;
	case CTerranEvent::eSpawnMULE:
		m_muleCount++;
		m_muleUnderConstruction--;
		RecalculateMineralIncomeRate();
		AddEvent(events, CTerranEvent(CTerranEvent::eKillMULE, time + 90));
		break;
	case CTerranEvent::eSpawnMarineNaked:
		m_barracksInUse--;
		m_marineCount++;
		m_marineUnderConstruction--;
		break;
	case CTerranEvent::eSpawnMarineReactor:
		m_barracksReactorInUse--;
		m_marineCount++;
		m_marineUnderConstruction--;
		break;
	case CTerranEvent::eSpawnMarineTechLab:
		m_barracksTechLabInUse--;
		m_marineCount++;
		m_marineUnderConstruction--;
		break;
	case CTerranEvent::eSpawnMarauder:
		m_barracksTechLabInUse--;
		m_marauderCount++;
		m_marauderUnderConstruction--;
		break;
	case CTerranEvent::eSpawnReaper:
		m_barracksTechLabInUse--;
		m_reaperCount++;
		m_reaperUnderConstruction--;
		break;
	case CTerranEvent::eSpawnGhost:
		m_barracksTechLabInUse--;
		m_ghostCount++;
		m_ghostUnderConstruction--;
		break;
	case CTerranEvent::eSpawnHellionNaked:
		m_factoryInUse--;
		m_hellionCount++;
		m_hellionUnderConstruction--;
		break;
	case CTerranEvent::eSpawnHellionReactor:
		m_factoryReactorInUse--;
		m_hellionCount++;
		m_hellionUnderConstruction--;
		break;
	case CTerranEvent::eSpawnHellionTechLab:
		m_factoryTechLabInUse--;
		m_hellionCount++;
		m_hellionUnderConstruction--;
		break;
	case CTerranEvent::eSpawnSiegeTank:
		m_factoryTechLabInUse--;
		m_siegeTankCount++;
		m_siegeTankUnderConstruction--;
		break;
	case CTerranEvent::eSpawnThor:
		m_factoryTechLabInUse--;
		m_thorCount++;
		m_thorUnderConstruction--;
		break;
	case CTerranEvent::eSpawnVikingNaked:
		m_starportInUse--;
		m_vikingCount++;
		m_vikingUnderConstruction--;
		break;
	case CTerranEvent::eSpawnVikingReactor:
		m_starportReactorInUse--;
		m_vikingCount++;
		m_vikingUnderConstruction--;
		break;
	case CTerranEvent::eSpawnVikingTechLab:
		m_starportTechLabInUse--;
		m_vikingCount++;
		m_vikingUnderConstruction--;
		break;
	case CTerranEvent::eSpawnMedivacNaked:
		m_starportInUse--;
		m_medivacCount++;
		m_medivacUnderConstruction--;
		break;
	case CTerranEvent::eSpawnMedivacReactor:
		m_starportReactorInUse--;
		m_medivacCount++;
		m_medivacUnderConstruction--;
		break;
	case CTerranEvent::eSpawnMedivacTechLab:
		m_starportTechLabInUse--;
		m_medivacCount++;
		m_medivacUnderConstruction--;
		break;
	case CTerranEvent::eSpawnRaven:
		m_starportTechLabInUse--;
		m_ravenCount++;
		m_ravenUnderConstruction--;
		break;
	case CTerranEvent::eSpawnBanshee:
		m_starportTechLabInUse--;
		m_bansheeCount++;
		m_bansheeUnderConstruction--;
		break;
	case CTerranEvent::eSpawnBattleCruiser:
		m_starportTechLabInUse--;
		m_battleCruiserCount++;
		m_battleCruiserUnderConstruction--;
		break;

	case CTerranEvent::eKillMULE:
		m_muleCount--;
		RecalculateMineralIncomeRate();
		break;

	case CTerranEvent::eResearchStimpackComplete:
		m_barracksTechLabResearchInUse--;
		m_researchStimpackCompleted = true;
		m_researchStimpackUnderConstruction = false;
		break;
	case CTerranEvent::eResearchCombatShieldComplete:
		m_barracksTechLabResearchInUse--;
		m_researchCombatShieldCompleted = true;
		m_researchCombatShieldUnderConstruction = false;
		break;
	case CTerranEvent::eResearchNitroPacksComplete:
		m_barracksTechLabResearchInUse--;
		m_researchNitroPacksCompleted = true;
		m_researchNitroPacksUnderConstruction = false;
		break;
	case CTerranEvent::eResearchConcussiveShellsComplete:
		m_barracksTechLabResearchInUse--;
		m_researchConcussiveShellsCompleted = true;
		m_researchConcussiveShellsUnderConstruction = false;
		break;
	case CTerranEvent::eResearchInfantryWeapons1Complete:
		m_engineeringBayInUse--;
		m_researchInfantryWeapons1Completed = true;
		m_researchInfantryWeapons1UnderConstruction = false;
		break;
	case CTerranEvent::eResearchInfantryWeapons2Complete:
		m_engineeringBayInUse--;
		m_researchInfantryWeapons2Completed = true;
		m_researchInfantryWeapons2UnderConstruction = false;
		break;
	case CTerranEvent::eResearchInfantryWeapons3Complete:
		m_engineeringBayInUse--;
		m_researchInfantryWeapons3Completed = true;
		m_researchInfantryWeapons3UnderConstruction = false;
		break;
	case CTerranEvent::eResearchInfantryArmor1Complete:
		m_engineeringBayInUse--;
		m_researchInfantryArmor1Completed = true;
		m_researchInfantryArmor1UnderConstruction = false;
		break;
	case CTerranEvent::eResearchInfantryArmor2Complete:
		m_engineeringBayInUse--;
		m_researchInfantryArmor2Completed = true;
		m_researchInfantryArmor2UnderConstruction = false;
		break;
	case CTerranEvent::eResearchInfantryArmor3Complete:
		m_engineeringBayInUse--;
		m_researchInfantryArmor3Completed = true;
		m_researchInfantryArmor3UnderConstruction = false;
		break;
	case CTerranEvent::eResearchBuildingArmorComplete:
		m_engineeringBayInUse--;
		m_researchBuildingArmorCompleted = true;
		m_researchBuildingArmorUnderConstruction = false;
		break;
	case CTerranEvent::eResearchHiSecAutoTrackingComplete:
		m_engineeringBayInUse--;
		m_researchHiSecAutoTrackingCompleted = true;
		m_researchHiSecAutoTrackingUnderConstruction = false;
		break;
	case CTerranEvent::eResearchNeoSteelFrameComplete:
		m_engineeringBayInUse--;
		m_researchNeoSteelFrameCompleted = true;
		m_researchNeoSteelFrameUnderConstruction = false;
		break;
	case CTerranEvent::eResearchMoebiusReactorComplete:
		m_ghostAcademyInUse--;
		m_researchMoebiusReactorCompleted = true;
		m_researchMoebiusReactorUnderConstruction = false;
		break;
	case CTerranEvent::eResearchPersonalCloakingComplete:
		m_ghostAcademyInUse--;
		m_researchPersonalCloakingCompleted = true;
		m_researchPersonalCloakingUnderConstruction = false;
		break;
	case CTerranEvent::eArmNukeComplete:
		m_ghostAcademyInUse--;
		m_ghostAcademyNukeCount++;
		m_ghostAcademyNukeUnderConstruction--;
		break;
	case CTerranEvent::eResearchInfernalPreIgniterComplete:
		m_factoryTechLabResearchInUse--;
		m_researchInfernalPreIgniterCompleted = true;
		m_researchInfernalPreIgniterUnderConstruction = false;
		break;
	case CTerranEvent::eResearchSiegeTechComplete:
		m_factoryTechLabResearchInUse--;
		m_researchSiegeTechCompleted = true;
		m_researchSiegeTechUnderConstruction = false;
		break;
	case CTerranEvent::eResearchDurableMaterialsComplete:
		m_factoryTechLabResearchInUse--;
		m_researchDurableMaterialsCompleted = true;
		m_researchDurableMaterialsUnderConstruction = false;
		break;
	case CTerranEvent::eResearch250mmStrikeCannonsComplete:
		m_factoryTechLabResearchInUse--;
		m_research250mmStrikeCannonsCompleted = true;
		m_research250mmStrikeCannonsUnderConstruction = false;
		break;
	case CTerranEvent::eResearchVehicleWeapons1Complete:
		m_armoryInUse--;
		m_researchVehicleWeapons1Completed = true;
		m_researchVehicleWeapons1UnderConstruction = false;
		break;
	case CTerranEvent::eResearchVehicleWeapons2Complete:
		m_armoryInUse--;
		m_researchVehicleWeapons2Completed = true;
		m_researchVehicleWeapons2UnderConstruction = false;
		break;
	case CTerranEvent::eResearchVehicleWeapons3Complete:
		m_armoryInUse--;
		m_researchVehicleWeapons3Completed = true;
		m_researchVehicleWeapons3UnderConstruction = false;
		break;
	case CTerranEvent::eResearchVehiclePlating1Complete:
		m_armoryInUse--;
		m_researchVehiclePlating1Completed = true;
		m_researchVehiclePlating1UnderConstruction = false;
		break;
	case CTerranEvent::eResearchVehiclePlating2Complete:
		m_armoryInUse--;
		m_researchVehiclePlating2Completed = true;
		m_researchVehiclePlating2UnderConstruction = false;
		break;
	case CTerranEvent::eResearchVehiclePlating3Complete:
		m_armoryInUse--;
		m_researchVehiclePlating3Completed = true;
		m_researchVehiclePlating3UnderConstruction = false;
		break;
	case CTerranEvent::eResearchShipWeapons1Complete:
		m_armoryInUse--;
		m_researchShipWeapons1Completed = true;
		m_researchShipWeapons1UnderConstruction = false;
		break;
	case CTerranEvent::eResearchShipWeapons2Complete:
		m_armoryInUse--;
		m_researchShipWeapons2Completed = true;
		m_researchShipWeapons2UnderConstruction = false;
		break;
	case CTerranEvent::eResearchShipWeapons3Complete:
		m_armoryInUse--;
		m_researchShipWeapons3Completed = true;
		m_researchShipWeapons3UnderConstruction = false;
		break;
	case CTerranEvent::eResearchShipPlating1Complete:
		m_armoryInUse--;
		m_researchShipPlating1Completed = true;
		m_researchShipPlating1UnderConstruction = false;
		break;
	case CTerranEvent::eResearchShipPlating2Complete:
		m_armoryInUse--;
		m_researchShipPlating2Completed = true;
		m_researchShipPlating2UnderConstruction = false;
		break;
	case CTerranEvent::eResearchShipPlating3Complete:
		m_armoryInUse--;
		m_researchShipPlating3Completed = true;
		m_researchShipPlating3UnderConstruction = false;
		break;
	case CTerranEvent::eResearchCorvidReactorComplete:
		m_starportTechLabResearchInUse--;
		m_researchCorvidReactorCompleted = true;
		m_researchCorvidReactorUnderConstruction = false;
		break;
	case CTerranEvent::eResearchCaduceusReactorComplete:
		m_starportTechLabResearchInUse--;
		m_researchCaduceusReactorCompleted = true;
		m_researchCaduceusReactorUnderConstruction = false;
		break;
	case CTerranEvent::eResearchSeekerMissileComplete:
		m_starportTechLabResearchInUse--;
		m_researchSeekerMissileCompleted = true;
		m_researchSeekerMissileUnderConstruction = false;
		break;
	case CTerranEvent::eResearchCloakingFieldComplete:
		m_starportTechLabResearchInUse--;
		m_researchCloakingFieldCompleted = true;
		m_researchCloakingFieldUnderConstruction = false;
		break;
	case CTerranEvent::eResearchBehemothReactorComplete:
		m_fusionCoreInUse--;
		m_researchBehemothReactorCompleted = true;
		m_researchBehemothReactorUnderConstruction = false;
		break;
	case CTerranEvent::eResearchWeaponRefitComplete:
		m_fusionCoreInUse--;
		m_researchWeaponRefitCompleted = true;
		m_researchWeaponRefitUnderConstruction = false;
		break;
	}

	delete entry;
}

bool CTerranState::HasBuildingRequirements(double time, ETerranCommand command) const
{
	switch (command)
	{
	case eTerranCommandBuildCommandCenter:
		return 2 <= m_scvsOnMinerals + m_scvsOnGas + m_scvUnderConstruction;
	case eTerranCommandBuildRefinery:
		return 2 <= m_scvsOnMinerals + m_scvsOnGas + m_scvUnderConstruction;
	case eTerranCommandBuildSupplyDepot:
		return 2 <= m_scvsOnMinerals + m_scvsOnGas + m_scvUnderConstruction;
	case eTerranCommandBuildBarracksNaked:
		return 0 < m_supplyDepotCount + m_supplyDepotUnderConstruction
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas + m_scvUnderConstruction;
	case eTerranCommandBuildBarracksOnTechLab:
		return 0 < m_supplyDepotCount + m_supplyDepotUnderConstruction
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas + m_scvUnderConstruction
			&& 0 < m_techLabAvailable;
	case eTerranCommandBuildBarracksOnReactor:
		return 0 < m_supplyDepotCount + m_supplyDepotUnderConstruction
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas + m_scvUnderConstruction
			&& 0 < m_reactorAvailable;
	case eTerranCommandBuildOrbitalCommand:
		return 0 < m_barracksCount + m_barracksUnderConstruction
			&& m_orbitalCommandCount + m_orbitalCommandUnderConstruction + m_planetaryFortressCount + m_planetaryFortressUnderConstruction < m_commandCenterCount + m_commandCenterUnderConstruction;
	case eTerranCommandBuildEngineeringBay:
		return 0 < m_barracksCount + m_barracksUnderConstruction
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas + m_scvUnderConstruction;
	case eTerranCommandBuildBunker:
		return 0 < m_barracksCount + m_barracksUnderConstruction
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas + m_scvUnderConstruction;
	case eTerranCommandBuildMissileTurret:
		return 0 < m_engineeringBayCount + m_engineeringBayUnderConstruction
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas + m_scvUnderConstruction;
	case eTerranCommandBuildSensorTower:
		return 0 < m_engineeringBayCount + m_engineeringBayUnderConstruction
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas + m_scvUnderConstruction;
	case eTerranCommandBuildPlanetaryFortress:
		return 0 < m_barracksCount + m_barracksUnderConstruction
			&& m_orbitalCommandCount + m_orbitalCommandUnderConstruction + m_planetaryFortressCount + m_planetaryFortressUnderConstruction < m_commandCenterCount + m_commandCenterUnderConstruction;
	case eTerranCommandBuildGhostAcademy:
		return 0 < m_barracksCount + m_barracksUnderConstruction
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas + m_scvUnderConstruction;
	case eTerranCommandBuildFactoryNaked:
		return 0 < m_barracksCount + m_barracksUnderConstruction
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas + m_scvUnderConstruction;
	case eTerranCommandBuildFactoryOnTechLab:
		return 0 < m_barracksCount + m_barracksUnderConstruction
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas + m_scvUnderConstruction
			&& 0 < m_techLabAvailable;
	case eTerranCommandBuildFactoryOnReactor:
		return 0 < m_barracksCount + m_barracksUnderConstruction
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas + m_scvUnderConstruction
			&& 0 < m_reactorAvailable;
	case eTerranCommandBuildArmory:
		return 0 < m_factoryCount + m_factoryUnderConstruction
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas + m_scvUnderConstruction;
	case eTerranCommandBuildStarportNaked:
		return 0 < m_factoryCount + m_factoryUnderConstruction
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas + m_scvUnderConstruction;
	case eTerranCommandBuildStarportOnTechLab:
		return 0 < m_factoryCount + m_factoryUnderConstruction
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas + m_scvUnderConstruction
			&& 0 < m_techLabAvailable;
	case eTerranCommandBuildStarportOnReactor:
		return 0 < m_factoryCount + m_factoryUnderConstruction
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas + m_scvUnderConstruction
			&& 0 < m_reactorAvailable;
	case eTerranCommandBuildFusionCore:
		return 0 < m_starportCount + m_starportUnderConstruction
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas + m_scvUnderConstruction;

	case eTerranCommandBuildBarracksTechLab:
		return 0 < m_barracksCount + m_barracksUnderConstruction - m_barracksTechLabCount - m_barracksTechLabUnderConstruction - m_barracksReactorCount - m_barracksReactorUnderConstruction
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas + m_scvUnderConstruction;
	case eTerranCommandBuildBarracksReactor:
		return 0 < m_barracksCount + m_barracksUnderConstruction - m_barracksTechLabCount - m_barracksTechLabUnderConstruction - m_barracksReactorCount - m_barracksReactorUnderConstruction
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas + m_scvUnderConstruction;
	case eTerranCommandBuildFactoryTechLab:
		return 0 < m_factoryCount + m_factoryUnderConstruction - m_factoryTechLabCount - m_factoryTechLabUnderConstruction - m_factoryReactorCount - m_factoryReactorUnderConstruction
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas + m_scvUnderConstruction;
	case eTerranCommandBuildFactoryReactor:
		return 0 < m_factoryCount + m_factoryUnderConstruction - m_factoryTechLabCount - m_factoryTechLabUnderConstruction - m_factoryReactorCount - m_factoryReactorUnderConstruction
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas + m_scvUnderConstruction;
	case eTerranCommandBuildStarportTechLab:
		return 0 < m_starportCount + m_starportUnderConstruction - m_starportTechLabCount - m_starportTechLabUnderConstruction - m_starportReactorCount - m_starportReactorUnderConstruction
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas + m_scvUnderConstruction;
	case eTerranCommandBuildStarportReactor:
		return 0 < m_starportCount + m_starportUnderConstruction - m_starportTechLabCount - m_starportTechLabUnderConstruction - m_starportReactorCount - m_starportReactorUnderConstruction
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas + m_scvUnderConstruction;

	case eTerranCommandBuildSCV:
		return 0 < m_commandCenterCount + m_commandCenterUnderConstruction
			&& m_supply + 1 <= m_supplyCapUnderConstruction;
	case eTerranCommandBuildMarine:
		return 0 < m_barracksCount + m_barracksUnderConstruction
			&& m_supply + 1 <= m_supplyCapUnderConstruction;
	case eTerranCommandBuildMarineNaked:
		return 0 < m_barracksCount + m_barracksUnderConstruction - m_barracksReactorCount - m_barracksReactorUnderConstruction - m_barracksTechLabCount - m_barracksTechLabUnderConstruction
			&& m_supply + 1 <= m_supplyCapUnderConstruction;
	case eTerranCommandBuildMarineReactor:
		return 0 < m_barracksReactorCount + m_barracksReactorUnderConstruction
			&& m_supply + 1 <= m_supplyCapUnderConstruction;
	case eTerranCommandBuildMarineTechLab:
		return 0 < m_barracksTechLabCount + m_barracksTechLabUnderConstruction
			&& m_supply + 1 <= m_supplyCapUnderConstruction;
	case eTerranCommandBuildMarauder:
		return 0 < m_barracksTechLabCount + m_barracksTechLabUnderConstruction
			&& m_supply + 2 <= m_supplyCapUnderConstruction;
	case eTerranCommandBuildReaper:
		return 0 < m_barracksTechLabCount + m_barracksTechLabUnderConstruction
			&& m_supply + 1 <= m_supplyCapUnderConstruction;
	case eTerranCommandBuildGhost:
		return 0 < m_barracksTechLabCount + m_barracksTechLabUnderConstruction
			&& m_supply + 2 <= m_supplyCapUnderConstruction;
	case eTerranCommandBuildHellion:
		return 0 < m_factoryCount + m_factoryUnderConstruction
			&& m_supply + 2 <= m_supplyCapUnderConstruction;
	case eTerranCommandBuildHellionNaked:
		return 0 < m_factoryCount + m_factoryUnderConstruction - m_factoryReactorCount - m_factoryReactorUnderConstruction - m_factoryTechLabCount - m_factoryTechLabUnderConstruction
			&& m_supply + 2 <= m_supplyCapUnderConstruction;
	case eTerranCommandBuildHellionReactor:
		return 0 < m_factoryReactorCount + m_factoryReactorUnderConstruction
			&& m_supply + 2 <= m_supplyCapUnderConstruction;
	case eTerranCommandBuildHellionTechLab:
		return 0 < m_factoryTechLabCount + m_factoryTechLabUnderConstruction
			&& m_supply + 2 <= m_supplyCapUnderConstruction;
	case eTerranCommandBuildSiegeTank:
		return 0 < m_factoryTechLabCount + m_factoryTechLabUnderConstruction
			&& m_supply + 3 <= m_supplyCapUnderConstruction;
	case eTerranCommandBuildThor:
		return 0 < m_factoryTechLabCount + m_factoryTechLabUnderConstruction
			&& 0 < m_armoryCount + m_armoryUnderConstruction
			&& m_supply + 6 <= m_supplyCapUnderConstruction;
	case eTerranCommandBuildViking:
		return 0 < m_starportCount + m_starportUnderConstruction
			&& m_supply + 2 <= m_supplyCapUnderConstruction;
	case eTerranCommandBuildVikingNaked:
		return 0 < m_starportCount + m_starportUnderConstruction - m_starportReactorCount - m_starportReactorUnderConstruction - m_starportTechLabCount - m_starportTechLabUnderConstruction
			&& m_supply + 2 <= m_supplyCapUnderConstruction;
	case eTerranCommandBuildVikingReactor:
		return 0 < m_starportReactorCount + m_starportReactorUnderConstruction
			&& m_supply + 2 <= m_supplyCapUnderConstruction;
	case eTerranCommandBuildVikingTechLab:
		return 0 < m_starportTechLabCount + m_starportTechLabUnderConstruction
			&& m_supply + 2 <= m_supplyCapUnderConstruction;
	case eTerranCommandBuildMedivac:
		return 0 < m_starportCount + m_starportUnderConstruction
			&& m_supply + 2 <= m_supplyCapUnderConstruction;
	case eTerranCommandBuildMedivacNaked:
		return 0 < m_starportCount + m_starportUnderConstruction - m_starportReactorCount - m_starportReactorUnderConstruction - m_starportTechLabCount - m_starportTechLabUnderConstruction
			&& m_supply + 2 <= m_supplyCapUnderConstruction;
	case eTerranCommandBuildMedivacReactor:
		return 0 < m_starportReactorCount + m_starportReactorUnderConstruction
			&& m_supply + 2 <= m_supplyCapUnderConstruction;
	case eTerranCommandBuildMedivacTechLab:
		return 0 < m_starportTechLabCount + m_starportTechLabUnderConstruction
			&& m_supply + 2 <= m_supplyCapUnderConstruction;
	case eTerranCommandBuildRaven:
		return 0 < m_starportTechLabCount + m_starportTechLabUnderConstruction
			&& m_supply + 2 <= m_supplyCapUnderConstruction;
	case eTerranCommandBuildBanshee:
		return 0 < m_starportTechLabCount + m_starportTechLabUnderConstruction
			&& m_supply + 3 <= m_supplyCapUnderConstruction;
	case eTerranCommandBuildBattleCruiser:
		return 0 < m_starportTechLabCount + m_starportTechLabUnderConstruction
			&& m_supply + 6 <= m_supplyCapUnderConstruction;

	case eTerranCommandCalldownMULE:
		return 0 < m_orbitalCommandCount + m_orbitalCommandUnderConstruction;
	case eTerranCommandCalldownExtraSupplies:
		return 0 < m_orbitalCommandCount + m_orbitalCommandUnderConstruction
			&& m_supplyDepotExtraSuppliesCount + m_supplyDepotExtraSuppliesUnderConstruction < m_supplyDepotCount + m_supplyDepotUnderConstruction;
	case eTerranCommandScannerSweep:
		return 0 < m_orbitalCommandCount + m_orbitalCommandUnderConstruction;

	case eTerranCommandResearchStimpack:
		return 0 < m_barracksTechLabCount + m_barracksTechLabUnderConstruction
			&& !m_researchStimpackCompleted && !m_researchStimpackUnderConstruction;
	case eTerranCommandResearchCombatShield:
		return 0 < m_barracksTechLabCount + m_barracksTechLabUnderConstruction
			&& !m_researchCombatShieldCompleted && !m_researchCombatShieldUnderConstruction;
	case eTerranCommandResearchNitroPacks:
		return 0 < m_barracksTechLabCount + m_barracksTechLabUnderConstruction
			&& !m_researchNitroPacksCompleted && !m_researchNitroPacksUnderConstruction;
	case eTerranCommandResearchConcussiveShells:
		return 0 < m_barracksTechLabCount + m_barracksTechLabUnderConstruction
			&& !m_researchConcussiveShellsCompleted && !m_researchConcussiveShellsUnderConstruction;
	case eTerranCommandResearchInfantryWeapons1:
		return 0 < m_engineeringBayCount + m_engineeringBayUnderConstruction
			&& !m_researchInfantryWeapons1Completed && !m_researchInfantryWeapons1UnderConstruction;
	case eTerranCommandResearchInfantryWeapons2:
		return 0 < m_engineeringBayCount + m_engineeringBayUnderConstruction
			&& 0 < m_armoryCount + m_armoryUnderConstruction
			&& !m_researchInfantryWeapons2Completed && !m_researchInfantryWeapons2UnderConstruction
			&& (m_researchInfantryWeapons1Completed || m_researchInfantryWeapons1UnderConstruction);
	case eTerranCommandResearchInfantryWeapons3:
		return 0 < m_engineeringBayCount + m_engineeringBayUnderConstruction
			&& 0 < m_armoryCount + m_armoryUnderConstruction
			&& !m_researchInfantryWeapons3Completed && !m_researchInfantryWeapons3UnderConstruction
			&& (m_researchInfantryWeapons2Completed || m_researchInfantryWeapons2UnderConstruction);
	case eTerranCommandResearchInfantryArmor1:
		return 0 < m_engineeringBayCount + m_engineeringBayUnderConstruction
			&& !m_researchInfantryArmor1Completed && !m_researchInfantryArmor1UnderConstruction;
	case eTerranCommandResearchInfantryArmor2:
		return 0 < m_engineeringBayCount + m_engineeringBayUnderConstruction
			&& 0 < m_armoryCount + m_armoryUnderConstruction
			&& !m_researchInfantryArmor2Completed && !m_researchInfantryArmor2UnderConstruction
			&& (m_researchInfantryArmor1Completed || m_researchInfantryArmor1UnderConstruction);
	case eTerranCommandResearchInfantryArmor3:
		return 0 < m_engineeringBayCount + m_engineeringBayUnderConstruction
			&& 0 < m_armoryCount + m_armoryUnderConstruction
			&& !m_researchInfantryArmor3Completed && !m_researchInfantryArmor3UnderConstruction
			&& (m_researchInfantryArmor2Completed || m_researchInfantryArmor2UnderConstruction);
	case eTerranCommandResearchBuildingArmor:
		return 0 < m_engineeringBayCount + m_engineeringBayUnderConstruction
			&& !m_researchBuildingArmorCompleted && !m_researchBuildingArmorUnderConstruction;
	case eTerranCommandResearchHiSecAutoTracking:
		return 0 < m_engineeringBayCount + m_engineeringBayUnderConstruction
			&& !m_researchHiSecAutoTrackingCompleted && !m_researchHiSecAutoTrackingUnderConstruction;
	case eTerranCommandResearchNeoSteelFrame:
		return 0 < m_engineeringBayCount + m_engineeringBayUnderConstruction
			&& !m_researchNeoSteelFrameCompleted && !m_researchNeoSteelFrameUnderConstruction;
	case eTerranCommandResearchMoebiusReactor:
		return 0 < m_ghostAcademyCount + m_ghostAcademyUnderConstruction
			&& !m_researchMoebiusReactorCompleted && !m_researchMoebiusReactorUnderConstruction;
	case eTerranCommandResearchPersonalCloaking:
		return 0 < m_ghostAcademyCount + m_ghostAcademyUnderConstruction
			&& !m_researchPersonalCloakingCompleted && !m_researchPersonalCloakingUnderConstruction;
	case eTerranCommandArmNuke:
		return m_ghostAcademyNukeCount + m_ghostAcademyNukeUnderConstruction < m_ghostAcademyCount + m_ghostAcademyUnderConstruction;
	case eTerranCommandResearchInfernalPreIgniter:
		return 0 < m_factoryTechLabCount + m_factoryTechLabUnderConstruction
			&& !m_researchInfernalPreIgniterCompleted && !m_researchInfernalPreIgniterUnderConstruction;
	case eTerranCommandResearchSiegeTech:
		return 0 < m_factoryTechLabCount + m_factoryTechLabUnderConstruction
			&& !m_researchSiegeTechCompleted && !m_researchSiegeTechUnderConstruction;
	case eTerranCommandResearchDurableMaterials:
		return 0 < m_factoryTechLabCount + m_factoryTechLabUnderConstruction
			&& !m_researchDurableMaterialsCompleted && !m_researchDurableMaterialsUnderConstruction;
	case eTerranCommandResearch250mmStrikeCannons:
		return 0 < m_factoryTechLabCount + m_factoryTechLabUnderConstruction
			&& !m_research250mmStrikeCannonsCompleted && !m_research250mmStrikeCannonsUnderConstruction;
	case eTerranCommandResearchVehicleWeapons1:
		return 0 < m_armoryCount + m_armoryUnderConstruction
			&& !m_researchVehicleWeapons1Completed && !m_researchVehicleWeapons1UnderConstruction;
	case eTerranCommandResearchVehicleWeapons2:
		return 0 < m_armoryCount + m_armoryUnderConstruction
			&& !m_researchVehicleWeapons2Completed && !m_researchVehicleWeapons2UnderConstruction
			&& (m_researchVehicleWeapons1Completed || m_researchVehicleWeapons1UnderConstruction);
	case eTerranCommandResearchVehicleWeapons3:
		return 0 < m_armoryCount + m_armoryUnderConstruction
			&& !m_researchVehicleWeapons3Completed && !m_researchVehicleWeapons3UnderConstruction
			&& (m_researchVehicleWeapons2Completed || m_researchVehicleWeapons2UnderConstruction);
	case eTerranCommandResearchVehiclePlating1:
		return 0 < m_armoryCount + m_armoryUnderConstruction
			&& !m_researchVehiclePlating1Completed && !m_researchVehiclePlating1UnderConstruction;
	case eTerranCommandResearchVehiclePlating2:
		return 0 < m_armoryCount + m_armoryUnderConstruction
			&& !m_researchVehiclePlating2Completed && !m_researchVehiclePlating2UnderConstruction
			&& (m_researchVehiclePlating1Completed || m_researchVehiclePlating1UnderConstruction);
	case eTerranCommandResearchVehiclePlating3:
		return 0 < m_armoryCount + m_armoryUnderConstruction
			&& !m_researchVehiclePlating3Completed && !m_researchVehiclePlating3UnderConstruction
			&& (m_researchVehiclePlating2Completed || m_researchVehiclePlating2UnderConstruction);
	case eTerranCommandResearchShipWeapons1:
		return 0 < m_armoryCount + m_armoryUnderConstruction
			&& !m_researchShipWeapons1Completed && !m_researchShipWeapons1UnderConstruction;
	case eTerranCommandResearchShipWeapons2:
		return 0 < m_armoryCount + m_armoryUnderConstruction
			&& !m_researchShipWeapons2Completed && !m_researchShipWeapons2UnderConstruction
			&& (m_researchShipWeapons1Completed || m_researchShipWeapons1UnderConstruction);
	case eTerranCommandResearchShipWeapons3:
		return 0 < m_armoryCount + m_armoryUnderConstruction
			&& !m_researchShipWeapons3Completed && !m_researchShipWeapons3UnderConstruction
			&& (m_researchShipWeapons2Completed || m_researchShipWeapons2UnderConstruction);
	case eTerranCommandResearchShipPlating1:
		return 0 < m_armoryCount + m_armoryUnderConstruction
			&& !m_researchShipPlating1Completed && !m_researchShipPlating1UnderConstruction;
	case eTerranCommandResearchShipPlating2:
		return 0 < m_armoryCount + m_armoryUnderConstruction
			&& !m_researchShipPlating2Completed && !m_researchShipPlating2UnderConstruction
			&& (m_researchShipPlating1Completed || m_researchShipPlating1UnderConstruction);
	case eTerranCommandResearchShipPlating3:
		return 0 < m_armoryCount + m_armoryUnderConstruction
			&& !m_researchShipPlating3Completed && !m_researchShipPlating3UnderConstruction
			&& (m_researchShipPlating2Completed || m_researchShipPlating2UnderConstruction);
	case eTerranCommandResearchCorvidReactor:
		return 0 < m_starportTechLabCount + m_starportTechLabUnderConstruction
			&& !m_researchCorvidReactorCompleted && !m_researchCorvidReactorUnderConstruction;
	case eTerranCommandResearchCaduceusReactor:
		return 0 < m_starportTechLabCount + m_starportTechLabUnderConstruction
			&& !m_researchCaduceusReactorCompleted && !m_researchCaduceusReactorUnderConstruction;
	case eTerranCommandResearchSeekerMissile:
		return 0 < m_starportTechLabCount + m_starportTechLabUnderConstruction
			&& !m_researchSeekerMissileCompleted && !m_researchSeekerMissileUnderConstruction;
	case eTerranCommandResearchCloakingField:
		return 0 < m_starportTechLabCount + m_starportTechLabUnderConstruction
			&& !m_researchCloakingFieldCompleted && !m_researchCloakingFieldUnderConstruction;
	case eTerranCommandResearchBehemothReactor:
		return 0 < m_fusionCoreCount + m_fusionCoreUnderConstruction
			&& !m_researchBehemothReactorCompleted && !m_researchBehemothReactorUnderConstruction;
	case eTerranCommandResearchWeaponRefit:
		return 0 < m_fusionCoreCount + m_fusionCoreUnderConstruction
			&& !m_researchWeaponRefitCompleted && !m_researchWeaponRefitUnderConstruction;

	case eTerranCommandMoveSCVToGas:
		return 0 < m_baseCount + m_commandCenterUnderConstruction
			&& 0 < m_refineryCount + m_refineryUnderConstruction
			&& 0 < m_scvsOnMinerals + m_scvUnderConstruction
			&& m_scvsOnGas < CGameCalcs::GasWorkerLimit(m_baseCount + m_commandCenterUnderConstruction, m_refineryCount + m_refineryUnderConstruction);
	case eTerranCommandMoveSCVToMinerals:
		return 0 < m_baseCount + m_commandCenterUnderConstruction
			&& 0 < m_scvsOnGas
			&& m_scvsOnMinerals < CGameCalcs::MineralWorkerLimit(m_baseCount + m_commandCenterUnderConstruction);

	default:
		return true;
	}
}

bool CTerranState::HasBuildingStateRequirements(double time, ETerranCommand command) const
{
	switch (command)
	{
	case eTerranCommandBuildCommandCenter:
		return 2 <= m_scvsOnMinerals + m_scvsOnGas;
	case eTerranCommandBuildRefinery:
		return 2 <= m_scvsOnMinerals + m_scvsOnGas;
	case eTerranCommandBuildSupplyDepot:
		return 2 <= m_scvsOnMinerals + m_scvsOnGas;
	case eTerranCommandBuildBarracksNaked:
		return 0 < m_supplyDepotCount
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas;
	case eTerranCommandBuildBarracksOnTechLab:
		return 0 < m_supplyDepotCount
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas
			&& 0 < m_techLabAvailable;
	case eTerranCommandBuildBarracksOnReactor:
		return 0 < m_supplyDepotCount
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas
			&& 0 < m_reactorAvailable;
	case eTerranCommandBuildOrbitalCommand:
		return 0 < m_barracksCount
			&& m_orbitalCommandCount + m_orbitalCommandUnderConstruction + m_planetaryFortressCount + m_planetaryFortressUnderConstruction < m_commandCenterCount
			&& m_commandCenterInUse < m_commandCenterCount - m_orbitalCommandCount - m_planetaryFortressCount;
	case eTerranCommandBuildEngineeringBay:
		return 0 < m_barracksCount
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas;
	case eTerranCommandBuildBunker:
		return 0 < m_barracksCount
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas;
	case eTerranCommandBuildMissileTurret:
		return 0 < m_engineeringBayCount
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas;
	case eTerranCommandBuildSensorTower:
		return 0 < m_engineeringBayCount
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas;
	case eTerranCommandBuildPlanetaryFortress:
		return 0 < m_barracksCount
			&& m_orbitalCommandCount + m_orbitalCommandUnderConstruction + m_planetaryFortressCount + m_planetaryFortressUnderConstruction < m_commandCenterCount;
	case eTerranCommandBuildGhostAcademy:
		return 0 < m_barracksCount
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas;
	case eTerranCommandBuildFactoryNaked:
		return 0 < m_barracksCount
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas;
	case eTerranCommandBuildFactoryOnTechLab:
		return 0 < m_barracksCount
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas
			&& 0 < m_techLabAvailable;
	case eTerranCommandBuildFactoryOnReactor:
		return 0 < m_barracksCount
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas
			&& 0 < m_reactorAvailable;
	case eTerranCommandBuildArmory:
		return 0 < m_factoryCount
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas;
	case eTerranCommandBuildStarportNaked:
		return 0 < m_factoryCount
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas;
	case eTerranCommandBuildStarportOnTechLab:
		return 0 < m_factoryCount
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas
			&& 0 < m_techLabAvailable;
	case eTerranCommandBuildStarportOnReactor:
		return 0 < m_factoryCount
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas
			&& 0 < m_reactorAvailable;
	case eTerranCommandBuildFusionCore:
		return 0 < m_starportCount
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas;

	case eTerranCommandBuildBarracksTechLab:
		return m_barracksInUse < m_barracksCount - m_barracksTechLabCount - m_barracksReactorCount
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas;
	case eTerranCommandBuildBarracksReactor:
		return m_barracksInUse < m_barracksCount - m_barracksTechLabCount - m_barracksReactorCount
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas;
	case eTerranCommandBuildFactoryTechLab:
		return m_factoryInUse < m_factoryCount - m_factoryTechLabCount - m_factoryReactorCount
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas;
	case eTerranCommandBuildFactoryReactor:
		return m_factoryInUse < m_factoryCount - m_factoryTechLabCount - m_factoryReactorCount
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas;
	case eTerranCommandBuildStarportTechLab:
		return m_starportInUse < m_starportCount - m_starportTechLabCount - m_starportReactorCount
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas;
	case eTerranCommandBuildStarportReactor:
		return m_starportInUse < m_starportCount - m_starportTechLabCount - m_starportReactorCount
			&& 2 <= m_scvsOnMinerals + m_scvsOnGas;

	case eTerranCommandBuildSCV:
		return m_commandCenterInUse < m_commandCenterCount
			&& m_supply + 1 <= m_supplyCap;
	case eTerranCommandBuildMarine:
		return (m_barracksInUse < m_barracksCount - m_barracksReactorCount - m_barracksTechLabCount
				|| m_barracksReactorInUse < 2 * m_barracksReactorCount
				|| m_barracksTechLabInUse < m_barracksTechLabCount)
			&& m_supply + 1 <= m_supplyCap;
	case eTerranCommandBuildMarineNaked:
		return m_barracksInUse < m_barracksCount - m_barracksReactorCount - m_barracksTechLabCount
			&& m_supply + 1 <= m_supplyCap;
	case eTerranCommandBuildMarineReactor:
		return m_barracksReactorInUse < 2 * m_barracksReactorCount
			&& m_supply + 1 <= m_supplyCap;
	case eTerranCommandBuildMarineTechLab:
		return m_barracksTechLabInUse < m_barracksTechLabCount
			&& m_supply + 1 <= m_supplyCap;
	case eTerranCommandBuildMarauder:
		return m_barracksTechLabInUse < m_barracksTechLabCount
			&& m_supply + 2 <= m_supplyCap;
	case eTerranCommandBuildReaper:
		return m_barracksTechLabInUse < m_barracksTechLabCount
			&& m_supply + 1 <= m_supplyCap;
	case eTerranCommandBuildGhost:
		return m_barracksTechLabInUse < m_barracksTechLabCount
			&& m_supply + 2 <= m_supplyCap;
	case eTerranCommandBuildHellion:
		return (m_factoryInUse < m_factoryCount - m_factoryReactorCount - m_factoryTechLabCount
				|| m_factoryReactorInUse < 2 * m_factoryReactorCount
				|| m_factoryTechLabInUse < m_factoryTechLabCount)
			&& m_supply + 2 <= m_supplyCap;
	case eTerranCommandBuildHellionNaked:
		return m_factoryInUse < m_factoryCount - m_factoryReactorCount - m_factoryTechLabCount
			&& m_supply + 2 <= m_supplyCap;
	case eTerranCommandBuildHellionReactor:
		return m_factoryReactorInUse < 2 * m_factoryReactorCount
			&& m_supply + 2 <= m_supplyCap;
	case eTerranCommandBuildHellionTechLab:
		return m_factoryTechLabInUse < m_factoryTechLabCount
			&& m_supply + 2 <= m_supplyCap;
	case eTerranCommandBuildSiegeTank:
		return m_factoryTechLabInUse < m_factoryTechLabCount
			&& m_supply + 3 <= m_supplyCap;
	case eTerranCommandBuildThor:
		return m_factoryTechLabInUse < m_factoryTechLabCount
			&& 0 < m_armoryCount
			&& m_supply + 6 <= m_supplyCap;
	case eTerranCommandBuildViking:
		return (m_starportInUse < m_starportCount - m_starportReactorCount - m_starportTechLabCount
				|| m_starportReactorInUse < 2 * m_starportReactorCount
				|| m_starportTechLabInUse < m_starportTechLabCount)
			&& m_supply + 2 <= m_supplyCap;
	case eTerranCommandBuildVikingNaked:
		return m_starportInUse < m_starportCount - m_starportReactorCount - m_starportTechLabCount
			&& m_supply + 2 <= m_supplyCap;
	case eTerranCommandBuildVikingReactor:
		return m_starportReactorInUse < 2 * m_starportReactorCount
			&& m_supply + 2 <= m_supplyCap;
	case eTerranCommandBuildVikingTechLab:
		return m_starportTechLabInUse < m_starportTechLabCount
			&& m_supply + 2 <= m_supplyCap;
	case eTerranCommandBuildMedivac:
		return (m_starportInUse < m_starportCount - m_starportReactorCount - m_starportTechLabCount
				|| m_starportReactorInUse < 2 * m_starportReactorCount
				|| m_starportTechLabInUse < m_starportTechLabCount)
			&& m_supply + 2 <= m_supplyCap;
	case eTerranCommandBuildMedivacNaked:
		return m_starportInUse < m_starportCount - m_starportReactorCount - m_starportTechLabCount
			&& m_supply + 2 <= m_supplyCap;
	case eTerranCommandBuildMedivacReactor:
		return m_starportReactorInUse < 2 * m_starportReactorCount
			&& m_supply + 2 <= m_supplyCap;
	case eTerranCommandBuildMedivacTechLab:
		return m_starportTechLabInUse < m_starportTechLabCount
			&& m_supply + 2 <= m_supplyCap;
	case eTerranCommandBuildRaven:
		return m_starportTechLabInUse < m_starportTechLabCount
			&& m_supply + 2 <= m_supplyCap;
	case eTerranCommandBuildBanshee:
		return m_starportTechLabInUse < m_starportTechLabCount
			&& m_supply + 3 <= m_supplyCap;
	case eTerranCommandBuildBattleCruiser:
		return m_starportTechLabInUse < m_starportTechLabCount
			&& m_supply + 6 <= m_supplyCap;

	case eTerranCommandCalldownMULE:
		return 0 < m_orbitalCommandCount;
	case eTerranCommandCalldownExtraSupplies:
		return 0 < m_orbitalCommandCount
			&& m_supplyDepotExtraSuppliesCount + m_supplyDepotExtraSuppliesUnderConstruction < m_supplyDepotCount;
	case eTerranCommandScannerSweep:
		return 0 < m_orbitalCommandCount;

	case eTerranCommandResearchStimpack:
		return m_barracksTechLabResearchInUse < m_barracksTechLabCount;
	case eTerranCommandResearchCombatShield:
		return m_barracksTechLabResearchInUse < m_barracksTechLabCount;
	case eTerranCommandResearchNitroPacks:
		return m_barracksTechLabResearchInUse < m_barracksTechLabCount;
	case eTerranCommandResearchConcussiveShells:
		return m_barracksTechLabResearchInUse < m_barracksTechLabCount;
	case eTerranCommandResearchInfantryWeapons1:
		return m_engineeringBayInUse < m_engineeringBayCount;
	case eTerranCommandResearchInfantryWeapons2:
		return m_engineeringBayInUse < m_engineeringBayCount
			&& 0 < m_armoryCount
			&& m_researchInfantryWeapons1Completed;
	case eTerranCommandResearchInfantryWeapons3:
		return m_engineeringBayInUse < m_engineeringBayCount
			&& 0 < m_armoryCount
			&& m_researchInfantryWeapons2Completed;
	case eTerranCommandResearchInfantryArmor1:
		return m_engineeringBayInUse < m_engineeringBayCount;
	case eTerranCommandResearchInfantryArmor2:
		return m_engineeringBayInUse < m_engineeringBayCount
			&& 0 < m_armoryCount
			&& m_researchInfantryArmor1Completed;
	case eTerranCommandResearchInfantryArmor3:
		return m_engineeringBayInUse < m_engineeringBayCount
			&& 0 < m_armoryCount
			&& m_researchInfantryArmor2Completed;
	case eTerranCommandResearchBuildingArmor:
		return m_engineeringBayInUse < m_engineeringBayCount;
	case eTerranCommandResearchHiSecAutoTracking:
		return m_engineeringBayInUse < m_engineeringBayCount;
	case eTerranCommandResearchNeoSteelFrame:
		return m_engineeringBayInUse < m_engineeringBayCount;
	case eTerranCommandResearchMoebiusReactor:
		return m_ghostAcademyInUse < m_ghostAcademyCount;
	case eTerranCommandResearchPersonalCloaking:
		return m_ghostAcademyInUse < m_ghostAcademyCount;
	case eTerranCommandArmNuke:
		return m_ghostAcademyNukeCount + m_ghostAcademyInUse < m_ghostAcademyCount;
	case eTerranCommandResearchInfernalPreIgniter:
		return m_factoryTechLabResearchInUse < m_factoryTechLabCount;
	case eTerranCommandResearchSiegeTech:
		return m_factoryTechLabResearchInUse < m_factoryTechLabCount;
	case eTerranCommandResearchDurableMaterials:
		return m_factoryTechLabResearchInUse < m_factoryTechLabCount;
	case eTerranCommandResearch250mmStrikeCannons:
		return m_factoryTechLabResearchInUse < m_factoryTechLabCount;
	case eTerranCommandResearchVehicleWeapons1:
		return m_armoryInUse < m_armoryCount;
	case eTerranCommandResearchVehicleWeapons2:
		return m_armoryInUse < m_armoryCount
			&& m_researchVehicleWeapons1Completed;
	case eTerranCommandResearchVehicleWeapons3:
		return m_armoryInUse < m_armoryCount
			&& m_researchVehicleWeapons2Completed;
	case eTerranCommandResearchVehiclePlating1:
		return m_armoryInUse < m_armoryCount;
	case eTerranCommandResearchVehiclePlating2:
		return m_armoryInUse < m_armoryCount
			&& m_researchVehiclePlating1Completed;
	case eTerranCommandResearchVehiclePlating3:
		return m_armoryInUse < m_armoryCount
			&& m_researchVehiclePlating2Completed;
	case eTerranCommandResearchShipWeapons1:
		return m_armoryInUse < m_armoryCount;
	case eTerranCommandResearchShipWeapons2:
		return m_armoryInUse < m_armoryCount
			&& m_researchShipWeapons1Completed;
	case eTerranCommandResearchShipWeapons3:
		return m_armoryInUse < m_armoryCount
			&& m_researchShipWeapons2Completed;
	case eTerranCommandResearchShipPlating1:
		return m_armoryInUse < m_armoryCount;
	case eTerranCommandResearchShipPlating2:
		return m_armoryInUse < m_armoryCount
			&& m_researchShipPlating1Completed;
	case eTerranCommandResearchShipPlating3:
		return m_armoryInUse < m_armoryCount
			&& m_researchShipPlating2Completed;
	case eTerranCommandResearchCorvidReactor:
		return m_starportTechLabResearchInUse < m_starportTechLabCount;
	case eTerranCommandResearchCaduceusReactor:
		return m_starportTechLabResearchInUse < m_starportTechLabCount;
	case eTerranCommandResearchSeekerMissile:
		return m_starportTechLabResearchInUse < m_starportTechLabCount;
	case eTerranCommandResearchCloakingField:
		return m_starportTechLabResearchInUse < m_starportTechLabCount;
	case eTerranCommandResearchBehemothReactor:
		return m_fusionCoreInUse < m_fusionCoreCount;
	case eTerranCommandResearchWeaponRefit:
		return m_fusionCoreInUse < m_fusionCoreCount;

	case eTerranCommandMoveSCVToGas:
		return 0 < m_baseCount
			&& 0 < m_refineryCount
			&& 0 < m_scvsOnMinerals;
	case eTerranCommandMoveSCVToMinerals:
		return 0 < m_baseCount
			&& 0 < m_refineryCount
			&& 0 < m_scvsOnGas;

	default:
		return true;
	}
}

void CTerranState::GetCost(CResourceCost &cost, ETerranCommand command)
{
	switch(command)
	{
	case eTerranCommandBuildCommandCenter:
		cost.m_minerals = 400;
		break;
	case eTerranCommandBuildRefinery:
		cost.m_minerals = 75;
		break;
	case eTerranCommandBuildSupplyDepot:
		cost.m_minerals = 100;
		break;
	case eTerranCommandBuildBarracksNaked:
	case eTerranCommandBuildBarracksOnTechLab:
	case eTerranCommandBuildBarracksOnReactor:
		cost.m_minerals = 150;
		break;
	case eTerranCommandBuildOrbitalCommand:
		cost.m_minerals = 150;
		break;
	case eTerranCommandBuildEngineeringBay:
		cost.m_minerals = 125;
		break;
	case eTerranCommandBuildBunker:
		cost.m_minerals = 100;
		break;
	case eTerranCommandBuildMissileTurret:
		cost.m_minerals = 100;
		break;
	case eTerranCommandBuildSensorTower:
		cost.m_minerals = 125;
		cost.m_gas = 100;
		break;
	case eTerranCommandBuildPlanetaryFortress:
		cost.m_minerals = 150;
		cost.m_gas = 150;
		break;
	case eTerranCommandBuildGhostAcademy:
		cost.m_minerals = 150;
		cost.m_gas = 50;
		break;
	case eTerranCommandBuildFactoryNaked:
	case eTerranCommandBuildFactoryOnTechLab:
	case eTerranCommandBuildFactoryOnReactor:
		cost.m_minerals = 150;
		cost.m_gas = 100;
		break;
	case eTerranCommandBuildArmory:
		cost.m_minerals = 150;
		cost.m_gas = 100;
		break;
	case eTerranCommandBuildStarportNaked:
	case eTerranCommandBuildStarportOnTechLab:
	case eTerranCommandBuildStarportOnReactor:
		cost.m_minerals = 150;
		cost.m_gas = 100;
		break;
	case eTerranCommandBuildFusionCore:
		cost.m_minerals = 150;
		cost.m_gas = 150;
		break;

	case eTerranCommandBuildBarracksTechLab:
	case eTerranCommandBuildFactoryTechLab:
	case eTerranCommandBuildStarportTechLab:
		cost.m_minerals = 50;
		cost.m_gas = 25;
		break;
	case eTerranCommandBuildBarracksReactor:
	case eTerranCommandBuildFactoryReactor:
	case eTerranCommandBuildStarportReactor:
		cost.m_minerals = 50;
		cost.m_gas = 50;
		break;

	case eTerranCommandBuildSCV:
		cost.m_minerals = 50;
		break;
	case eTerranCommandBuildMarine:
	case eTerranCommandBuildMarineNaked:
	case eTerranCommandBuildMarineReactor:
	case eTerranCommandBuildMarineTechLab:
		cost.m_minerals = 50;
		break;
	case eTerranCommandBuildMarauder:
		cost.m_minerals = 100;
		cost.m_gas = 25;
		break;
	case eTerranCommandBuildReaper:
		cost.m_minerals = 50;
		cost.m_gas = 50;
		break;
	case eTerranCommandBuildGhost:
		cost.m_minerals = 150;
		cost.m_gas = 150;
		break;
	case eTerranCommandBuildHellion:
	case eTerranCommandBuildHellionNaked:
	case eTerranCommandBuildHellionReactor:
	case eTerranCommandBuildHellionTechLab:
		cost.m_minerals = 100;
		break;
	case eTerranCommandBuildSiegeTank:
		cost.m_minerals = 150;
		cost.m_gas = 125;
		break;
	case eTerranCommandBuildThor:
		cost.m_minerals = 300;
		cost.m_gas = 200;
		break;
	case eTerranCommandBuildViking:
	case eTerranCommandBuildVikingNaked:
	case eTerranCommandBuildVikingReactor:
	case eTerranCommandBuildVikingTechLab:
		cost.m_minerals = 150;
		cost.m_gas = 75;
		break;
	case eTerranCommandBuildMedivac:
	case eTerranCommandBuildMedivacNaked:
	case eTerranCommandBuildMedivacReactor:
	case eTerranCommandBuildMedivacTechLab:
		cost.m_minerals = 100;
		cost.m_gas = 100;
		break;
	case eTerranCommandBuildRaven:
		cost.m_minerals = 100;
		cost.m_gas = 200;
		break;
	case eTerranCommandBuildBanshee:
		cost.m_minerals = 150;
		cost.m_gas = 100;
		break;
	case eTerranCommandBuildBattleCruiser:
		cost.m_minerals = 400;
		cost.m_gas = 300;
		break;

	case eTerranCommandCalldownMULE:
		cost.m_orbitalCommandEnergy = 50;
		break;
	case eTerranCommandCalldownExtraSupplies:
		cost.m_orbitalCommandEnergy = 50;
		break;
	case eTerranCommandScannerSweep:
		cost.m_orbitalCommandEnergy = 50;
		break;

	case eTerranCommandResearchStimpack:
		cost.m_minerals = 100;
		cost.m_gas = 100;
		break;
	case eTerranCommandResearchCombatShield:
		cost.m_minerals = 100;
		cost.m_gas = 100;
		break;
	case eTerranCommandResearchNitroPacks:
		cost.m_minerals = 50;
		cost.m_gas = 50;
		break;
	case eTerranCommandResearchConcussiveShells:
		cost.m_minerals = 50;
		cost.m_gas = 50;
		break;
	case eTerranCommandResearchInfantryWeapons1:
		cost.m_minerals = 100;
		cost.m_gas = 100;
		break;
	case eTerranCommandResearchInfantryWeapons2:
		cost.m_minerals = 175;
		cost.m_gas = 175;
		break;
	case eTerranCommandResearchInfantryWeapons3:
		cost.m_minerals = 250;
		cost.m_gas = 250;
		break;
	case eTerranCommandResearchInfantryArmor1:
		cost.m_minerals = 100;
		cost.m_gas = 100;
		break;
	case eTerranCommandResearchInfantryArmor2:
		cost.m_minerals = 175;
		cost.m_gas = 175;
		break;
	case eTerranCommandResearchInfantryArmor3:
		cost.m_minerals = 250;
		cost.m_gas = 250;
		break;
	case eTerranCommandResearchBuildingArmor:
		cost.m_minerals = 150;
		cost.m_gas = 150;
		break;
	case eTerranCommandResearchHiSecAutoTracking:
		cost.m_minerals = 100;
		cost.m_gas = 100;
		break;
	case eTerranCommandResearchNeoSteelFrame:
		cost.m_minerals = 100;
		cost.m_gas = 100;
		break;
	case eTerranCommandResearchMoebiusReactor:
		cost.m_minerals = 100;
		cost.m_gas = 100;
		break;
	case eTerranCommandResearchPersonalCloaking:
		cost.m_minerals = 150;
		cost.m_gas = 150;
		break;
	case eTerranCommandArmNuke:
		cost.m_minerals = 100;
		cost.m_gas = 100;
		break;
	case eTerranCommandResearchInfernalPreIgniter:
		cost.m_minerals = 150;
		cost.m_gas = 150;
		break;
	case eTerranCommandResearchSiegeTech:
		cost.m_minerals = 100;
		cost.m_gas = 100;
		break;
	case eTerranCommandResearchDurableMaterials:
		cost.m_minerals = 150;
		cost.m_gas = 150;
		break;
	case eTerranCommandResearch250mmStrikeCannons:
		cost.m_minerals = 150;
		cost.m_gas = 150;
		break;
	case eTerranCommandResearchVehicleWeapons1:
		cost.m_minerals = 100;
		cost.m_gas = 100;
		break;
	case eTerranCommandResearchVehicleWeapons2:
		cost.m_minerals = 175;
		cost.m_gas = 175;
		break;
	case eTerranCommandResearchVehicleWeapons3:
		cost.m_minerals = 250;
		cost.m_gas = 250;
		break;
	case eTerranCommandResearchVehiclePlating1:
		cost.m_minerals = 100;
		cost.m_gas = 100;
		break;
	case eTerranCommandResearchVehiclePlating2:
		cost.m_minerals = 175;
		cost.m_gas = 175;
		break;
	case eTerranCommandResearchVehiclePlating3:
		cost.m_minerals = 250;
		cost.m_gas = 250;
		break;
	case eTerranCommandResearchShipWeapons1:
		cost.m_minerals = 100;
		cost.m_gas = 100;
		break;
	case eTerranCommandResearchShipWeapons2:
		cost.m_minerals = 175;
		cost.m_gas = 175;
		break;
	case eTerranCommandResearchShipWeapons3:
		cost.m_minerals = 250;
		cost.m_gas = 250;
		break;
	case eTerranCommandResearchShipPlating1:
		cost.m_minerals = 150;
		cost.m_gas = 150;
		break;
	case eTerranCommandResearchShipPlating2:
		cost.m_minerals = 225;
		cost.m_gas = 225;
		break;
	case eTerranCommandResearchShipPlating3:
		cost.m_minerals = 300;
		cost.m_gas = 300;
		break;
	case eTerranCommandResearchCorvidReactor:
		cost.m_minerals = 150;
		cost.m_gas = 150;
		break;
	case eTerranCommandResearchCaduceusReactor:
		cost.m_minerals = 100;
		cost.m_gas = 100;
		break;
	case eTerranCommandResearchSeekerMissile:
		cost.m_minerals = 150;
		cost.m_gas = 150;
		break;
	case eTerranCommandResearchCloakingField:
		cost.m_minerals = 200;
		cost.m_gas = 200;
		break;
	case eTerranCommandResearchBehemothReactor:
		cost.m_minerals = 150;
		cost.m_gas = 150;
		break;
	case eTerranCommandResearchWeaponRefit:
		cost.m_minerals = 150;
		cost.m_gas = 150;
		break;
	}
}

void CTerranState::RecalculateSupply()
{
	m_supply = 
		  1 * (m_scvCount + m_scvUnderConstruction)
		+ 1 * (m_marineCount + m_marineUnderConstruction)
		+ 2 * (m_marauderCount + m_marauderUnderConstruction)
		+ 1 * (m_reaperCount + m_reaperUnderConstruction)
		+ 2 * (m_ghostCount + m_ghostUnderConstruction)
		+ 2 * (m_hellionCount + m_hellionUnderConstruction)
		+ 3 * (m_siegeTankCount + m_siegeTankUnderConstruction)
		+ 6 * (m_thorCount + m_thorUnderConstruction)
		+ 2 * (m_vikingCount + m_vikingUnderConstruction)
		+ 2 * (m_medivacCount + m_medivacUnderConstruction)
		+ 2 * (m_ravenCount + m_ravenUnderConstruction)
		+ 3 * (m_bansheeCount + m_bansheeUnderConstruction)
		+ 6 * (m_battleCruiserCount + m_battleCruiserUnderConstruction)
		;
}

void CTerranState::RecalculateSupplyCap()
{
	m_supplyCap = 11 * m_commandCenterCount + 8 * m_supplyDepotCount + 8 * m_supplyDepotExtraSuppliesCount;
}

void CTerranState::RecalculateSupplyCapUnderConstruction()
{
	m_supplyCapUnderConstruction = m_supplyCap + 11 * m_commandCenterUnderConstruction + 8 * m_supplyDepotUnderConstruction + 8 * m_supplyDepotExtraSuppliesUnderConstruction;
}

void CTerranState::RecalculateMineralIncomeRate()
{
	m_mineralIncomeRate = CGameCalcs::CalculateMineralIncomeRate(m_commandCenterCount, m_scvsOnMinerals) + 3 * m_muleCount; // MULEs presumed to mine 270 minerals over 90 seconds
}

void CTerranState::RecalculateGasIncomeRate()
{
	m_gasIncomeRate = CGameCalcs::CalculateGasIncomeRate(m_commandCenterCount, m_refineryCount, m_scvsOnGas);
}

void CTerranState::ProgressTime(double &time, double duration)
{
	m_minerals += m_mineralIncomeRate * duration;
	m_gas += m_gasIncomeRate * duration;
	double *orbitalCommandEnergy = m_orbitalCommandEnergy, *end = m_orbitalCommandEnergy + mymin(m_orbitalCommandCount, (size_t)4);
	while(orbitalCommandEnergy < end)
	{
		(*orbitalCommandEnergy) = mymin((*orbitalCommandEnergy) + 0.5625 * duration, 200.0);
		orbitalCommandEnergy++;
	}
	time += duration;
}

void CTerranState::UseSCVForMovement(double duration, double &time, CLinkedList<CTerranEvent> *&events)
{
	// Simulate SCV being pulled off the line for a period beforehand
	if(m_scvsOnMinerals > 0)
	{
		AddEvent(events, CTerranEvent(CTerranEvent::eSCVStartMiningMinerals, time + duration));
		m_scvsOnMinerals--;
		RecalculateMineralIncomeRate();
	}
	else if(m_scvsOnGas > 0)
	{
		AddEvent(events, CTerranEvent(CTerranEvent::eSCVStartMiningGas, time + duration));
		m_scvsOnGas--;
		RecalculateGasIncomeRate();
	}
}

void CTerranState::UseSCVForBuilding(double duration, double &time, CLinkedList<CTerranEvent> *&events)
{
	if(m_scvsOnMinerals > 0)
	{
		m_scvsOnMinerals--;
		RecalculateMineralIncomeRate();
	}
	else if(m_scvsOnGas > 0)
	{
		m_scvsOnGas--;
		RecalculateGasIncomeRate();
	}

	UseSCVForMovement(duration, time, events);
}

void CTerranState::AddEvent(CLinkedList<CTerranEvent> *&events, const CTerranEvent &event)
{
	if(!events || event < events->GetData())
		events = new CLinkedList<CTerranEvent>(event, events);
	else
		events->InsertOrdered<Less<CTerranEvent>>(event);
}

bool CTerranState::HasResources(const CResourceCost &cost) const
{
	if(m_minerals < cost.m_minerals)
		return false;
	if(m_gas < cost.m_gas)
		return false;
	if(cost.m_orbitalCommandEnergy > 0)
	{
		double maxNexusEnergy = 0;
		const double *orbitalCommandEnergy = m_orbitalCommandEnergy, *end = m_orbitalCommandEnergy + mymin(m_orbitalCommandCount, (size_t)4);
		while(orbitalCommandEnergy < end && maxNexusEnergy <= cost.m_orbitalCommandEnergy)
			maxNexusEnergy = mymax(maxNexusEnergy, *(orbitalCommandEnergy++));
		if(maxNexusEnergy < cost.m_orbitalCommandEnergy)
			return false;
	}

	return true;
}

void CTerranState::SpendResources(const CResourceCost &cost)
{
	m_minerals -= cost.m_minerals;
	m_gas -= cost.m_gas;
	if(cost.m_orbitalCommandEnergy > 0)
	{
		double *orbitalCommandEnergy = m_orbitalCommandEnergy, *end = m_orbitalCommandEnergy + mymin(m_orbitalCommandCount, (size_t)4), *best = m_orbitalCommandEnergy;
		while(orbitalCommandEnergy < end)
		{
			if(*orbitalCommandEnergy > *best)
				best = orbitalCommandEnergy;
			orbitalCommandEnergy++;
		}

		*best -= cost.m_orbitalCommandEnergy;
	}
}

void CTerranState::PrintDetails(CString &output) const
{
	PrintSummary(output);

	output.AppendFormat(L"\r\nIncome:   %4.0fM %4.0fG", 60.0 * m_mineralIncomeRate, 60.0 * m_gasIncomeRate);

	output.Append(L"\r\nBuildings: ");

	if(0 < m_commandCenterCount - m_orbitalCommandCount - m_planetaryFortressCount)
											output.AppendFormat(L" %u Command Center", m_commandCenterCount - m_orbitalCommandCount - m_planetaryFortressCount);
	if(0 < m_refineryCount)					output.AppendFormat(L" %u Refinery", m_refineryCount);
	if(0 < m_barracksCount)					output.AppendFormat(L" %u Barracks", m_barracksCount);
	if(0 < m_orbitalCommandCount)			output.AppendFormat(L" %u Orbital Command", m_orbitalCommandCount);
	if(0 < m_engineeringBayCount)			output.AppendFormat(L" %u Engineering Bay", m_engineeringBayCount);
	if(0 < m_bunkerCount)					output.AppendFormat(L" %u Bunker", m_bunkerCount);
	if(0 < m_missileTurretCount)			output.AppendFormat(L" %u Missile Turret", m_missileTurretCount);
	if(0 < m_sensorTowerCount)				output.AppendFormat(L" %u Sensor Tower", m_sensorTowerCount);
	if(0 < m_planetaryFortressCount)		output.AppendFormat(L" %u Planetary Fortress", m_planetaryFortressCount);
	if(0 < m_ghostAcademyCount)				output.AppendFormat(L" %u Ghost Academy", m_ghostAcademyCount);
	if(0 < m_factoryCount)					output.AppendFormat(L" %u Factory", m_factoryCount);
	if(0 < m_armoryCount)					output.AppendFormat(L" %u Armory", m_armoryCount);
	if(0 < m_starportCount)					output.AppendFormat(L" %u Starport", m_starportCount);
	if(0 < m_fusionCoreCount)				output.AppendFormat(L" %u Fusion Core", m_fusionCoreCount);

	if(0 < m_reactorCount)					output.AppendFormat(L" %u Reactor", m_reactorCount);
	if(0 < m_techLabCount)					output.AppendFormat(L" %u Tech Lab", m_techLabCount);

	output.Append(L"\r\nUnits:     ");

	if(0 < m_scvCount)				output.AppendFormat(L" %u SCV", m_scvCount);
	if(0 < m_marineCount)			output.AppendFormat(L" %u Marine", m_marineCount);
	if(0 < m_marauderCount)			output.AppendFormat(L" %u Marauder", m_marauderCount);
	if(0 < m_reaperCount)			output.AppendFormat(L" %u Reaper", m_reaperCount);
	if(0 < m_ghostCount)			output.AppendFormat(L" %u Ghost", m_ghostCount);
	if(0 < m_hellionCount)			output.AppendFormat(L" %u Hellion", m_hellionCount);
	if(0 < m_siegeTankCount)		output.AppendFormat(L" %u Siege Tank", m_siegeTankCount);
	if(0 < m_thorCount)				output.AppendFormat(L" %u Thor", m_thorCount);
	if(0 < m_vikingCount)			output.AppendFormat(L" %u Viking", m_vikingCount);
	if(0 < m_medivacCount)			output.AppendFormat(L" %u Medivac", m_medivacCount);
	if(0 < m_ravenCount)			output.AppendFormat(L" %u Raven", m_ravenCount);
	if(0 < m_bansheeCount)			output.AppendFormat(L" %u Banshee", m_bansheeCount);
	if(0 < m_battleCruiserCount)	output.AppendFormat(L" %u Battle Cruiser", m_battleCruiserCount);

	output.Append(L"\r\nResearch:  ");

	if(m_researchStimpackCompleted)				output.AppendFormat(L" Stimpack");
	if(m_researchCombatShieldCompleted)			output.AppendFormat(L" Combat Shield");
	if(m_researchNitroPacksCompleted)			output.AppendFormat(L" Nitro Packs");
	if(m_researchConcussiveShellsCompleted)		output.AppendFormat(L" Concussive Shells");
	if(m_researchInfantryWeapons1Completed)		output.AppendFormat(L" Infantry Weapons 1");
	if(m_researchInfantryWeapons2Completed)		output.AppendFormat(L" Infantry Weapons 2");
	if(m_researchInfantryWeapons3Completed)		output.AppendFormat(L" Infantry Weapons 3");
	if(m_researchInfantryArmor1Completed)		output.AppendFormat(L" Infantry Armor 1");
	if(m_researchInfantryArmor2Completed)		output.AppendFormat(L" Infantry Armor 2");
	if(m_researchInfantryArmor3Completed)		output.AppendFormat(L" Infantry Armor 3");
	if(m_researchBuildingArmorCompleted)		output.AppendFormat(L" Building Armor");
	if(m_researchHiSecAutoTrackingCompleted)	output.AppendFormat(L" Hi-sec Auto Tracking");
	if(m_researchNeoSteelFrameCompleted)		output.AppendFormat(L" Neo-steel Frame");
	if(m_researchMoebiusReactorCompleted)		output.AppendFormat(L" Moebius Reactor");
	if(m_researchPersonalCloakingCompleted)		output.AppendFormat(L" Personal Cloaking");
	if(m_researchInfernalPreIgniterCompleted)	output.AppendFormat(L" Infernal Pre-igniter");
	if(m_researchSiegeTechCompleted)			output.AppendFormat(L" Siege Tech");
	if(m_researchDurableMaterialsCompleted)		output.AppendFormat(L" Durable Materials");
	if(m_research250mmStrikeCannonsCompleted)	output.AppendFormat(L" 250mm Strike Cannons");
	if(m_researchVehicleWeapons1Completed)		output.AppendFormat(L" Vehicle Weapons 1");
	if(m_researchVehicleWeapons2Completed)		output.AppendFormat(L" Vehicle Weapons 2");
	if(m_researchVehicleWeapons3Completed)		output.AppendFormat(L" Vehicle Weapons 3");
	if(m_researchVehiclePlating1Completed)		output.AppendFormat(L" Vehicle Plating 1");
	if(m_researchVehiclePlating2Completed)		output.AppendFormat(L" Vehicle Plating 2");
	if(m_researchVehiclePlating3Completed)		output.AppendFormat(L" Vehicle Plating 3");
	if(m_researchShipWeapons1Completed)			output.AppendFormat(L" Ship Weapons 1");
	if(m_researchShipWeapons2Completed)			output.AppendFormat(L" Ship Weapons 2");
	if(m_researchShipWeapons3Completed)			output.AppendFormat(L" Ship Weapons 3");
	if(m_researchShipPlating1Completed)			output.AppendFormat(L" Ship Plating 1");
	if(m_researchShipPlating2Completed)			output.AppendFormat(L" Ship Plating 2");
	if(m_researchShipPlating3Completed)			output.AppendFormat(L" Ship Plating 3");
	if(m_researchCorvidReactorCompleted)		output.AppendFormat(L" Corvid Reactor");
	if(m_researchCaduceusReactorCompleted)		output.AppendFormat(L" Caduceus Reactor");
	if(m_researchSeekerMissileCompleted)		output.AppendFormat(L" Seeker Missile");
	if(m_researchCloakingFieldCompleted)		output.AppendFormat(L" Cloaking Field");
	if(m_researchBehemothReactorCompleted)		output.AppendFormat(L" Behemoth Reactor");
	if(m_researchWeaponRefitCompleted)			output.AppendFormat(L" Weapon Refit");

	output.Append(L"\r\n");
}

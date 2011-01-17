#include "stdafx.h"
#include "TerranTarget.h"

CTerranTarget::CTerranTarget()
: m_minerals(0), m_gas(0), m_orbitalCommandEnergy(0)
, m_commandCenterCount(0), m_refineryCount(0), m_supplyDepotCount(0), m_barracksCount(0), m_orbitalCommandCount(0), m_engineeringBayCount(0), m_bunkerCount(0), m_missileTurretCount(0), m_sensorTowerCount(0), m_planetaryFortressCount(0), m_ghostAcademyCount(0), m_factoryCount(0), m_armoryCount(0), m_starportCount(0), m_fusionCoreCount(0)
, m_techLabCount(0), m_reactorCount(0), m_ghostAcademyNukeCount(0)
, m_constantSCVProduction(false), m_scvCount(0), m_marineCount(0), m_marauderCount(0), m_reaperCount(0), m_ghostCount(0), m_hellionCount(0), m_siegeTankCount(0), m_thorCount(0), m_vikingCount(0), m_medivacCount(0), m_ravenCount(0), m_bansheeCount(0), m_battleCruiserCount(0), m_scannerSweepCount(0)
, m_researchStimpackCompleted(false), m_researchCombatShieldCompleted(false), m_researchNitroPacksCompleted(false), m_researchConcussiveShellsCompleted(false), m_researchInfantryWeapons1Completed(false), m_researchInfantryWeapons2Completed(false), m_researchInfantryWeapons3Completed(false), m_researchInfantryArmor1Completed(false), m_researchInfantryArmor2Completed(false), m_researchInfantryArmor3Completed(false), m_researchBuildingArmorCompleted(false), m_researchHiSecAutoTrackingCompleted(false), m_researchNeoSteelFrameCompleted(false), m_researchMoebiusReactorCompleted(false), m_researchPersonalCloakingCompleted(false), m_researchInfernalPreIgniterCompleted(false), m_researchSiegeTechCompleted(false), m_research250mmStrikeCannonsCompleted(false), m_researchVehicleWeapons1Completed(false), m_researchVehicleWeapons2Completed(false), m_researchVehicleWeapons3Completed(false), m_researchVehiclePlating1Completed(false), m_researchVehiclePlating2Completed(false), m_researchVehiclePlating3Completed(false), m_researchShipWeapons1Completed(false), m_researchShipWeapons2Completed(false), m_researchShipWeapons3Completed(false), m_researchShipPlating1Completed(false), m_researchShipPlating2Completed(false), m_researchShipPlating3Completed(false), m_researchDurableMaterialsCompleted(false), m_researchCorvidReactorCompleted(false), m_researchCaduceusReactorCompleted(false), m_researchSeekerMissileCompleted(false), m_researchCloakingFieldCompleted(false), m_researchBehemothReactorCompleted(false), m_researchWeaponRefitCompleted(false)
{
}

double CTerranTarget::targetValue(const CTerranState &state, double time, bool bSatisfied) const
{
	double value = 0;
/*	
	if(!bSatisfied && time > 0)
	{
		value += state.m_mineralIncomeRate;
		value += state.m_gasIncomeRate * 2.0;
	}
*/
	value += mymin(m_minerals, state.m_minerals) * 1.0;
	value += mymin(m_gas, state.m_gas) * 2.0;
	double orbitalCommandEnergy = 0;
	for(size_t i=0; i < 4 && i < m_orbitalCommandCount; i++)
		orbitalCommandEnergy += state.m_orbitalCommandEnergy[i];
	value += mymin(m_orbitalCommandEnergy, orbitalCommandEnergy) * 0.2;

	value += mymin(m_commandCenterCount, (state.m_commandCenterCount + state.m_orbitalCommandUnderConstruction + state.m_planetaryFortressUnderConstruction)) * 400;
	value += mymin(m_refineryCount, state.m_refineryCount) * 75;
	value += mymin(m_supplyDepotCount, state.m_supplyDepotCount) * 100;
	value += mymin(m_barracksCount, state.m_barracksCount) * 150;
	value += mymin(m_orbitalCommandCount, state.m_orbitalCommandCount) * 700;
	value += mymin(m_engineeringBayCount, state.m_engineeringBayCount) * 125;
	value += mymin(m_bunkerCount, state.m_bunkerCount) * 100;
	value += mymin(m_missileTurretCount, state.m_missileTurretCount) * 100;
	value += mymin(m_sensorTowerCount, state.m_sensorTowerCount) * 325;
	value += mymin(m_planetaryFortressCount, state.m_planetaryFortressCount) * 1200;
	value += mymin(m_ghostAcademyCount, state.m_ghostAcademyCount) * 250;
	value += mymin(m_factoryCount, state.m_factoryCount) * 350;
	value += mymin(m_armoryCount, state.m_armoryCount) * 350;
	value += mymin(m_starportCount, state.m_starportCount) * 350;
	value += mymin(m_fusionCoreCount, state.m_fusionCoreCount) * 450;

	value += mymin(m_techLabCount, state.m_techLabCount) * 100;
	value += mymin(m_reactorCount, state.m_reactorCount) * 150;
	value += mymin(m_ghostAcademyNukeCount, state.m_ghostAcademyNukeCount) * 300;

	value += mymin(m_scvCount, state.m_scvCount) * 50;
	value += mymin(m_marineCount, state.m_marineCount) * 50;
	value += mymin(m_marauderCount, state.m_marauderCount) * 150;
	value += mymin(m_reaperCount, state.m_reaperCount) * 150;
	value += mymin(m_ghostCount, state.m_ghostCount) * 450;
	value += mymin(m_hellionCount, state.m_hellionCount) * 100;
	value += mymin(m_siegeTankCount, state.m_siegeTankCount) * 400;
	value += mymin(m_thorCount, state.m_thorCount) * 700;
	value += mymin(m_vikingCount, state.m_vikingCount) * 300;
	value += mymin(m_medivacCount, state.m_medivacCount) * 300;
	value += mymin(m_ravenCount, state.m_ravenCount) * 500;
	value += mymin(m_bansheeCount, state.m_bansheeCount) * 350;
	value += mymin(m_battleCruiserCount, state.m_battleCruiserCount) * 1000;

	if(m_researchStimpackCompleted && state.m_researchStimpackCompleted)
		value += 300;
	if(m_researchCombatShieldCompleted && state.m_researchCombatShieldCompleted)
		value += 300;
	if(m_researchNitroPacksCompleted && state.m_researchNitroPacksCompleted)
		value += 150;
	if(m_researchConcussiveShellsCompleted && state.m_researchConcussiveShellsCompleted)
		value += 150;
	if(m_researchInfantryWeapons1Completed && state.m_researchInfantryWeapons1Completed)
		value += 300;
	if(m_researchInfantryWeapons2Completed && state.m_researchInfantryWeapons2Completed)
		value += 525;
	if(m_researchInfantryWeapons3Completed && state.m_researchInfantryWeapons3Completed)
		value += 750;
	if(m_researchInfantryArmor1Completed && state.m_researchInfantryArmor1Completed)
		value += 300;
	if(m_researchInfantryArmor2Completed && state.m_researchInfantryArmor2Completed)
		value += 525;
	if(m_researchInfantryArmor3Completed && state.m_researchInfantryArmor3Completed)
		value += 750;
	if(m_researchBuildingArmorCompleted && state.m_researchBuildingArmorCompleted)
		value += 450;
	if(m_researchHiSecAutoTrackingCompleted && state.m_researchHiSecAutoTrackingCompleted)
		value += 300;
	if(m_researchNeoSteelFrameCompleted && state.m_researchNeoSteelFrameCompleted)
		value += 300;
	if(m_researchMoebiusReactorCompleted && state.m_researchMoebiusReactorCompleted)
		value += 300;
	if(m_researchPersonalCloakingCompleted && state.m_researchPersonalCloakingCompleted)
		value += 450;
	if(m_researchInfernalPreIgniterCompleted && state.m_researchInfernalPreIgniterCompleted)
		value += 450;
	if(m_researchSiegeTechCompleted && state.m_researchSiegeTechCompleted)
		value += 300;
	if(m_research250mmStrikeCannonsCompleted && state.m_research250mmStrikeCannonsCompleted)
		value += 450;
	if(m_researchVehicleWeapons1Completed && state.m_researchVehicleWeapons1Completed)
		value += 300;
	if(m_researchVehicleWeapons2Completed && state.m_researchVehicleWeapons2Completed)
		value += 525;
	if(m_researchVehicleWeapons3Completed && state.m_researchVehicleWeapons3Completed)
		value += 750;
	if(m_researchVehiclePlating1Completed && state.m_researchVehiclePlating1Completed)
		value += 300;
	if(m_researchVehiclePlating2Completed && state.m_researchVehiclePlating2Completed)
		value += 525;
	if(m_researchVehiclePlating3Completed && state.m_researchVehiclePlating3Completed)
		value += 750;
	if(m_researchShipWeapons1Completed && state.m_researchShipWeapons1Completed)
		value += 300;
	if(m_researchShipWeapons2Completed && state.m_researchShipWeapons2Completed)
		value += 525;
	if(m_researchShipWeapons3Completed && state.m_researchShipWeapons3Completed)
		value += 750;
	if(m_researchShipPlating1Completed && state.m_researchShipPlating1Completed)
		value += 450;
	if(m_researchShipPlating2Completed && state.m_researchShipPlating2Completed)
		value += 675;
	if(m_researchShipPlating3Completed && state.m_researchShipPlating3Completed)
		value += 900;
	if(m_researchDurableMaterialsCompleted && state.m_researchDurableMaterialsCompleted)
		value += 450;
	if(m_researchCorvidReactorCompleted && state.m_researchCorvidReactorCompleted)
		value += 450;
	if(m_researchCaduceusReactorCompleted && state.m_researchCaduceusReactorCompleted)
		value += 300;
	if(m_researchSeekerMissileCompleted && state.m_researchSeekerMissileCompleted)
		value += 450;
	if(m_researchCloakingFieldCompleted && state.m_researchCloakingFieldCompleted)
		value += 600;
	if(m_researchBehemothReactorCompleted && state.m_researchBehemothReactorCompleted)
		value += 450;
	if(m_researchWeaponRefitCompleted && state.m_researchWeaponRefitCompleted)
		value += 450;

	if(m_constantSCVProduction)
		value -= state.m_commandCentreIdleTime;

	return value;
}

double CTerranTarget::targetTimePenalty(const CTerranState &state, double time) const
{
	double value = 0.0;

/*
	if(m_constantSCVProduction)
	{
		size_t expectedSCVs = (size_t)(time / 11.0);
		if(expectedSCVs > state.m_probeCount && state.m_probeCount > m_probeCount)
			value += (expectedSCVs - state.m_probeCount) * 3.0;
	}
*/

	return value;
}

double CTerranTarget::extraValue(const CTerranState &state) const
{
	double value = 0;

	if(state.m_minerals > m_minerals)
		value += (state.m_minerals - m_minerals) * 1.1;
	if(state.m_gas > m_gas)
		value += (state.m_gas - m_gas) * 2.2;
	double orbitalCommandEnergy = 0;
	for(size_t i=0; i < 4 && i < m_orbitalCommandCount; i++)
		orbitalCommandEnergy += state.m_orbitalCommandEnergy[i];
	if(orbitalCommandEnergy > m_orbitalCommandEnergy)
		value += (orbitalCommandEnergy - m_orbitalCommandEnergy) * 0.2;

	if(state.m_commandCenterCount > m_commandCenterCount)
		value += (state.m_commandCenterCount - m_commandCenterCount) * 400;
	if(state.m_refineryCount > m_refineryCount)
		value += (state.m_refineryCount - m_refineryCount) * 75;
	if(state.m_supplyDepotCount > m_supplyDepotCount)
		value += (state.m_supplyDepotCount - m_supplyDepotCount) * 100;
	if(state.m_barracksCount > m_barracksCount)
		value += (state.m_barracksCount - m_barracksCount) * 150;
	if(state.m_orbitalCommandCount > m_orbitalCommandCount)
		value += (state.m_orbitalCommandCount - m_orbitalCommandCount) * 700;
	if(state.m_engineeringBayCount > m_engineeringBayCount)
		value += (state.m_engineeringBayCount - m_engineeringBayCount) * 125;
	if(state.m_bunkerCount > m_bunkerCount)
		value += (state.m_bunkerCount - m_bunkerCount) * 100;
	if(state.m_missileTurretCount > m_missileTurretCount)
		value += (state.m_missileTurretCount - m_missileTurretCount) * 100;
	if(state.m_sensorTowerCount > m_sensorTowerCount)
		value += (state.m_sensorTowerCount - m_sensorTowerCount) * 325;
	if(state.m_planetaryFortressCount > m_planetaryFortressCount)
		value += (state.m_planetaryFortressCount - m_planetaryFortressCount) * 1200;
	if(state.m_ghostAcademyCount > m_ghostAcademyCount)
		value += (state.m_ghostAcademyCount - m_ghostAcademyCount) * 250;
	if(state.m_factoryCount > m_factoryCount)
		value += (state.m_factoryCount - m_factoryCount) * 350;
	if(state.m_armoryCount > m_armoryCount)
		value += (state.m_armoryCount - m_armoryCount) * 350;
	if(state.m_starportCount > m_starportCount)
		value += (state.m_starportCount - m_starportCount) * 350;
	if(state.m_fusionCoreCount > m_fusionCoreCount)
		value += (state.m_fusionCoreCount - m_fusionCoreCount) * 450;

	if(state.m_techLabCount > m_techLabCount)
		value += (state.m_techLabCount - m_techLabCount) * 100;
	if(state.m_reactorCount > m_reactorCount)
		value += (state.m_reactorCount - m_reactorCount) * 150;
	if(state.m_ghostAcademyNukeCount > m_ghostAcademyNukeCount)
		value += (state.m_ghostAcademyNukeCount - m_ghostAcademyNukeCount) * 300;

	if(state.m_scvCount > m_scvCount)
		value += (state.m_scvCount - m_scvCount) * 50;
	if(state.m_marineCount > m_marineCount)
		value += (state.m_marineCount - m_marineCount) * 50;
	if(state.m_marauderCount > m_marauderCount)
		value += (state.m_marauderCount - m_marauderCount) * 150;
	if(state.m_reaperCount > m_reaperCount)
		value += (state.m_reaperCount - m_reaperCount) * 150;
	if(state.m_ghostCount > m_ghostCount)
		value += (state.m_ghostCount - m_ghostCount) * 450;
	if(state.m_hellionCount > m_hellionCount)
		value += (state.m_hellionCount - m_hellionCount) * 100;
	if(state.m_siegeTankCount > m_siegeTankCount)
		value += (state.m_siegeTankCount - m_siegeTankCount) * 400;
	if(state.m_thorCount > m_thorCount)
		value += (state.m_thorCount - m_thorCount) * 700;
	if(state.m_vikingCount > m_vikingCount)
		value += (state.m_vikingCount - m_vikingCount) * 300;
	if(state.m_medivacCount > m_medivacCount)
		value += (state.m_medivacCount - m_medivacCount) * 300;
	if(state.m_ravenCount > m_ravenCount)
		value += (state.m_ravenCount - m_ravenCount) * 500;
	if(state.m_bansheeCount > m_bansheeCount)
		value += (state.m_bansheeCount - m_bansheeCount) * 350;
	if(state.m_battleCruiserCount > m_battleCruiserCount)
		value += (state.m_battleCruiserCount - m_battleCruiserCount) * 1000;

	if(state.m_researchStimpackCompleted && !m_researchStimpackCompleted)
		value += 300;
	if(state.m_researchCombatShieldCompleted && !m_researchCombatShieldCompleted)
		value += 300;
	if(state.m_researchNitroPacksCompleted && !m_researchNitroPacksCompleted)
		value += 150;
	if(state.m_researchConcussiveShellsCompleted && !m_researchConcussiveShellsCompleted)
		value += 150;
	if(state.m_researchInfantryWeapons1Completed && !m_researchInfantryWeapons1Completed)
		value += 300;
	if(state.m_researchInfantryWeapons2Completed && !m_researchInfantryWeapons2Completed)
		value += 525;
	if(state.m_researchInfantryWeapons3Completed && !m_researchInfantryWeapons3Completed)
		value += 750;
	if(state.m_researchInfantryArmor1Completed && !m_researchInfantryArmor1Completed)
		value += 300;
	if(state.m_researchInfantryArmor2Completed && !m_researchInfantryArmor2Completed)
		value += 525;
	if(state.m_researchInfantryArmor3Completed && !m_researchInfantryArmor3Completed)
		value += 750;
	if(state.m_researchBuildingArmorCompleted && !m_researchBuildingArmorCompleted)
		value += 450;
	if(state.m_researchHiSecAutoTrackingCompleted && !m_researchHiSecAutoTrackingCompleted)
		value += 300;
	if(state.m_researchNeoSteelFrameCompleted && !m_researchNeoSteelFrameCompleted)
		value += 300;
	if(state.m_researchMoebiusReactorCompleted && !m_researchMoebiusReactorCompleted)
		value += 300;
	if(state.m_researchPersonalCloakingCompleted && !m_researchPersonalCloakingCompleted)
		value += 450;
	if(state.m_researchInfernalPreIgniterCompleted && !m_researchInfernalPreIgniterCompleted)
		value += 450;
	if(state.m_researchSiegeTechCompleted && !m_researchSiegeTechCompleted)
		value += 300;
	if(state.m_research250mmStrikeCannonsCompleted && !m_research250mmStrikeCannonsCompleted)
		value += 450;
	if(state.m_researchVehicleWeapons1Completed && !m_researchVehicleWeapons1Completed)
		value += 300;
	if(state.m_researchVehicleWeapons2Completed && !m_researchVehicleWeapons2Completed)
		value += 525;
	if(state.m_researchVehicleWeapons3Completed && !m_researchVehicleWeapons3Completed)
		value += 750;
	if(state.m_researchVehiclePlating1Completed && !m_researchVehiclePlating1Completed)
		value += 300;
	if(state.m_researchVehiclePlating2Completed && !m_researchVehiclePlating2Completed)
		value += 525;
	if(state.m_researchVehiclePlating3Completed && !m_researchVehiclePlating3Completed)
		value += 750;
	if(state.m_researchShipWeapons1Completed && !m_researchShipWeapons1Completed)
		value += 300;
	if(state.m_researchShipWeapons2Completed && !m_researchShipWeapons2Completed)
		value += 525;
	if(state.m_researchShipWeapons3Completed && !m_researchShipWeapons3Completed)
		value += 750;
	if(state.m_researchShipPlating1Completed && !m_researchShipPlating1Completed)
		value += 450;
	if(state.m_researchShipPlating2Completed && !m_researchShipPlating2Completed)
		value += 675;
	if(state.m_researchShipPlating3Completed && !m_researchShipPlating3Completed)
		value += 900;
	if(state.m_researchDurableMaterialsCompleted && !m_researchDurableMaterialsCompleted)
		value += 450;
	if(state.m_researchCorvidReactorCompleted && !m_researchCorvidReactorCompleted)
		value += 450;
	if(state.m_researchCaduceusReactorCompleted && !m_researchCaduceusReactorCompleted)
		value += 300;
	if(state.m_researchSeekerMissileCompleted && !m_researchSeekerMissileCompleted)
		value += 450;
	if(state.m_researchCloakingFieldCompleted && !m_researchCloakingFieldCompleted)
		value += 600;
	if(state.m_researchBehemothReactorCompleted && !m_researchBehemothReactorCompleted)
		value += 450;
	if(state.m_researchWeaponRefitCompleted && !m_researchWeaponRefitCompleted)
		value += 450;

	return value;
}

bool CTerranTarget::hasTarget() const
{
	if(0 < m_minerals) return true;
	if(0 < m_gas) return true;
	if(0 < m_orbitalCommandEnergy) return true;

	if(0 < m_commandCenterCount) return true;
	if(0 < m_refineryCount) return true;
	if(0 < m_supplyDepotCount) return true;
	if(0 < m_barracksCount) return true;
	if(0 < m_orbitalCommandCount) return true;
	if(0 < m_engineeringBayCount) return true;
	if(0 < m_bunkerCount) return true;
	if(0 < m_missileTurretCount) return true;
	if(0 < m_sensorTowerCount) return true;
	if(0 < m_planetaryFortressCount) return true;
	if(0 < m_ghostAcademyCount) return true;
	if(0 < m_factoryCount) return true;
	if(0 < m_armoryCount) return true;
	if(0 < m_starportCount) return true;
	if(0 < m_fusionCoreCount) return true;

	if(0 < m_techLabCount) return true;
	if(0 < m_reactorCount) return true;
	if(0 < m_ghostAcademyNukeCount) return true;

	if(0 < m_scvCount) return true;
	if(0 < m_marineCount) return true;
	if(0 < m_marauderCount) return true;
	if(0 < m_reaperCount) return true;
	if(0 < m_ghostCount) return true;
	if(0 < m_hellionCount) return true;
	if(0 < m_siegeTankCount) return true;
	if(0 < m_thorCount) return true;
	if(0 < m_vikingCount) return true;
	if(0 < m_medivacCount) return true;
	if(0 < m_ravenCount) return true;
	if(0 < m_bansheeCount) return true;
	if(0 < m_battleCruiserCount) return true;

	if(m_researchStimpackCompleted) return true;
	if(m_researchCombatShieldCompleted) return true;
	if(m_researchNitroPacksCompleted) return true;
	if(m_researchConcussiveShellsCompleted) return true;
	if(m_researchInfantryWeapons1Completed) return true;
	if(m_researchInfantryWeapons2Completed) return true;
	if(m_researchInfantryWeapons3Completed) return true;
	if(m_researchInfantryArmor1Completed) return true;
	if(m_researchInfantryArmor2Completed) return true;
	if(m_researchInfantryArmor3Completed) return true;
	if(m_researchBuildingArmorCompleted) return true;
	if(m_researchHiSecAutoTrackingCompleted) return true;
	if(m_researchNeoSteelFrameCompleted) return true;
	if(m_researchMoebiusReactorCompleted) return true;
	if(m_researchPersonalCloakingCompleted) return true;
	if(m_researchInfernalPreIgniterCompleted) return true;
	if(m_researchSiegeTechCompleted) return true;
	if(m_research250mmStrikeCannonsCompleted) return true;
	if(m_researchVehicleWeapons1Completed) return true;
	if(m_researchVehicleWeapons2Completed) return true;
	if(m_researchVehicleWeapons3Completed) return true;
	if(m_researchVehiclePlating1Completed) return true;
	if(m_researchVehiclePlating2Completed) return true;
	if(m_researchVehiclePlating3Completed) return true;
	if(m_researchShipWeapons1Completed) return true;
	if(m_researchShipWeapons2Completed) return true;
	if(m_researchShipWeapons3Completed) return true;
	if(m_researchShipPlating1Completed) return true;
	if(m_researchShipPlating2Completed) return true;
	if(m_researchShipPlating3Completed) return true;
	if(m_researchDurableMaterialsCompleted) return true;
	if(m_researchCorvidReactorCompleted) return true;
	if(m_researchCaduceusReactorCompleted) return true;
	if(m_researchSeekerMissileCompleted) return true;
	if(m_researchCloakingFieldCompleted) return true;
	if(m_researchBehemothReactorCompleted) return true;
	if(m_researchWeaponRefitCompleted) return true;

	return false;
}

bool CTerranTarget::satisfiesTarget(const CTerranState &state) const
{
	if(state.m_minerals < m_minerals)
		return false;
	if(state.m_gas < m_gas)
		return false;

	double orbitalCommandEnergy = 0;
	const double *orbitalCommandEnergyPtr = state.m_orbitalCommandEnergy;
	for(size_t i=0; i < 4; i++, orbitalCommandEnergyPtr++)
		orbitalCommandEnergy += *orbitalCommandEnergyPtr;
	if(orbitalCommandEnergy < m_orbitalCommandEnergy)
		return false;

	if(state.m_commandCenterCount < m_commandCenterCount)
		return false;
	if(state.m_refineryCount < m_refineryCount)
		return false;
	if(state.m_supplyDepotCount < m_supplyDepotCount)
		return false;
	if(state.m_barracksCount < m_barracksCount)
		return false;
	if(state.m_orbitalCommandCount < m_orbitalCommandCount)
		return false;
	if(state.m_engineeringBayCount < m_engineeringBayCount)
		return false;
	if(state.m_bunkerCount < m_bunkerCount)
		return false;
	if(state.m_missileTurretCount < m_missileTurretCount)
		return false;
	if(state.m_sensorTowerCount < m_sensorTowerCount)
		return false;
	if(state.m_planetaryFortressCount < m_planetaryFortressCount)
		return false;
	if(state.m_ghostAcademyCount < m_ghostAcademyCount)
		return false;
	if(state.m_factoryCount < m_factoryCount)
		return false;
	if(state.m_armoryCount < m_armoryCount)
		return false;
	if(state.m_starportCount < m_starportCount)
		return false;
	if(state.m_fusionCoreCount < m_fusionCoreCount)
		return false;

	if(state.m_techLabCount < m_techLabCount)
		return false;
	if(state.m_reactorCount < m_reactorCount)
		return false;
	if(state.m_ghostAcademyNukeCount < m_ghostAcademyNukeCount)
		return false;

	if(state.m_scvCount < m_scvCount)
		return false;
	if(state.m_marineCount < m_marineCount)
		return false;
	if(state.m_marauderCount < m_marauderCount)
		return false;
	if(state.m_reaperCount < m_reaperCount)
		return false;
	if(state.m_ghostCount < m_ghostCount)
		return false;
	if(state.m_hellionCount < m_hellionCount)
		return false;
	if(state.m_siegeTankCount < m_siegeTankCount)
		return false;
	if(state.m_thorCount < m_thorCount)
		return false;
	if(state.m_vikingCount < m_vikingCount)
		return false;
	if(state.m_medivacCount < m_medivacCount)
		return false;
	if(state.m_ravenCount < m_ravenCount)
		return false;
	if(state.m_bansheeCount < m_bansheeCount)
		return false;
	if(state.m_battleCruiserCount < m_battleCruiserCount)
		return false;

	if(m_researchStimpackCompleted && !state.m_researchStimpackCompleted)
		return false;
	if(m_researchCombatShieldCompleted && !state.m_researchCombatShieldCompleted)
		return false;
	if(m_researchNitroPacksCompleted && !state.m_researchNitroPacksCompleted)
		return false;
	if(m_researchConcussiveShellsCompleted && !state.m_researchConcussiveShellsCompleted)
		return false;
	if(m_researchInfantryWeapons1Completed && !state.m_researchInfantryWeapons1Completed)
		return false;
	if(m_researchInfantryWeapons2Completed && !state.m_researchInfantryWeapons2Completed)
		return false;
	if(m_researchInfantryWeapons3Completed && !state.m_researchInfantryWeapons3Completed)
		return false;
	if(m_researchInfantryArmor1Completed && !state.m_researchInfantryArmor1Completed)
		return false;
	if(m_researchInfantryArmor2Completed && !state.m_researchInfantryArmor2Completed)
		return false;
	if(m_researchInfantryArmor3Completed && !state.m_researchInfantryArmor3Completed)
		return false;
	if(m_researchBuildingArmorCompleted && !state.m_researchBuildingArmorCompleted)
		return false;
	if(m_researchHiSecAutoTrackingCompleted && !state.m_researchHiSecAutoTrackingCompleted)
		return false;
	if(m_researchNeoSteelFrameCompleted && !state.m_researchNeoSteelFrameCompleted)
		return false;
	if(m_researchMoebiusReactorCompleted && !state.m_researchMoebiusReactorCompleted)
		return false;
	if(m_researchPersonalCloakingCompleted && !state.m_researchPersonalCloakingCompleted)
		return false;
	if(m_researchInfernalPreIgniterCompleted && !state.m_researchInfernalPreIgniterCompleted)
		return false;
	if(m_researchSiegeTechCompleted && !state.m_researchSiegeTechCompleted)
		return false;
	if(m_research250mmStrikeCannonsCompleted && !state.m_research250mmStrikeCannonsCompleted)
		return false;
	if(m_researchVehicleWeapons1Completed && !state.m_researchVehicleWeapons1Completed)
		return false;
	if(m_researchVehicleWeapons2Completed && !state.m_researchVehicleWeapons2Completed)
		return false;
	if(m_researchVehicleWeapons3Completed && !state.m_researchVehicleWeapons3Completed)
		return false;
	if(m_researchVehiclePlating1Completed && !state.m_researchVehiclePlating1Completed)
		return false;
	if(m_researchVehiclePlating2Completed && !state.m_researchVehiclePlating2Completed)
		return false;
	if(m_researchVehiclePlating3Completed && !state.m_researchVehiclePlating3Completed)
		return false;
	if(m_researchShipWeapons1Completed && !state.m_researchShipWeapons1Completed)
		return false;
	if(m_researchShipWeapons2Completed && !state.m_researchShipWeapons2Completed)
		return false;
	if(m_researchShipWeapons3Completed && !state.m_researchShipWeapons3Completed)
		return false;
	if(m_researchShipPlating1Completed && !state.m_researchShipPlating1Completed)
		return false;
	if(m_researchShipPlating2Completed && !state.m_researchShipPlating2Completed)
		return false;
	if(m_researchShipPlating3Completed && !state.m_researchShipPlating3Completed)
		return false;
	if(m_researchDurableMaterialsCompleted && !state.m_researchDurableMaterialsCompleted)
		return false;
	if(m_researchCorvidReactorCompleted && !state.m_researchCorvidReactorCompleted)
		return false;
	if(m_researchCaduceusReactorCompleted && !state.m_researchCaduceusReactorCompleted)
		return false;
	if(m_researchSeekerMissileCompleted && !state.m_researchSeekerMissileCompleted)
		return false;
	if(m_researchCloakingFieldCompleted && !state.m_researchCloakingFieldCompleted)
		return false;
	if(m_researchBehemothReactorCompleted && !state.m_researchBehemothReactorCompleted)
		return false;
	if(m_researchWeaponRefitCompleted && !state.m_researchWeaponRefitCompleted)
		return false;

	return true;
}

void CTerranTarget::AddRequirements()
{
	if(m_techLabCount == 0
		&& (m_marauderCount > 0 || m_reaperCount > 0 || m_ghostCount > 0 || m_siegeTankCount > 0 || m_thorCount > 0 || m_ravenCount > 0 || m_bansheeCount > 0 || m_battleCruiserCount > 0
			|| m_researchStimpackCompleted || m_researchCombatShieldCompleted || m_researchNitroPacksCompleted || m_researchConcussiveShellsCompleted || m_researchInfernalPreIgniterCompleted || m_researchSiegeTechCompleted || m_research250mmStrikeCannonsCompleted || m_researchDurableMaterialsCompleted || m_researchCorvidReactorCompleted || m_researchCaduceusReactorCompleted || m_researchSeekerMissileCompleted || m_researchCloakingFieldCompleted))
		m_techLabCount++;

	if(m_fusionCoreCount == 0
		&& (m_battleCruiserCount > 0
			|| m_researchBehemothReactorCompleted || m_researchWeaponRefitCompleted))
		m_fusionCoreCount++;

	if(m_starportCount == 0
		&& (m_fusionCoreCount > 0
			|| m_vikingCount > 0 || m_medivacCount > 0 || m_ravenCount > 0 || m_bansheeCount > 0
			|| m_researchDurableMaterialsCompleted || m_researchCorvidReactorCompleted || m_researchCaduceusReactorCompleted || m_researchSeekerMissileCompleted || m_researchCloakingFieldCompleted))
		m_starportCount++;

	if(!m_researchVehicleWeapons2Completed
		&& m_researchVehicleWeapons3Completed)
		m_researchVehicleWeapons2Completed = true;

	if(!m_researchVehiclePlating2Completed
		&& m_researchVehiclePlating3Completed)
		m_researchVehiclePlating2Completed = true;

	if(!m_researchShipWeapons2Completed
		&& m_researchShipWeapons3Completed)
		m_researchShipWeapons2Completed = true;

	if(!m_researchShipPlating2Completed
		&& m_researchShipPlating3Completed)
		m_researchShipPlating2Completed = true;

	if(!m_researchVehicleWeapons1Completed
		&& m_researchVehicleWeapons2Completed)
		m_researchVehicleWeapons1Completed = true;

	if(!m_researchVehiclePlating1Completed
		&& m_researchVehiclePlating2Completed)
		m_researchVehiclePlating1Completed = true;

	if(!m_researchShipWeapons1Completed
		&& m_researchShipWeapons2Completed)
		m_researchShipWeapons1Completed = true;

	if(!m_researchShipPlating1Completed
		&& m_researchShipPlating2Completed)
		m_researchShipPlating1Completed = true;

	if(!m_researchInfantryWeapons2Completed
		&& m_researchInfantryWeapons3Completed)
		m_researchInfantryWeapons2Completed = true;

	if(!m_researchInfantryArmor2Completed
		&& m_researchInfantryArmor3Completed)
		m_researchInfantryArmor2Completed = true;

	if(m_armoryCount == 0
		&& (m_thorCount > 0
			 || m_researchInfantryWeapons2Completed || m_researchInfantryArmor2Completed || m_researchVehicleWeapons1Completed || m_researchVehiclePlating1Completed || m_researchShipWeapons1Completed || m_researchShipPlating1Completed))
		m_armoryCount++;

	if(m_factoryCount == 0
		&& (m_armoryCount > 0 || m_starportCount > 0
			|| m_hellionCount > 0 || m_siegeTankCount > 0 || m_thorCount > 0 || m_ghostAcademyNukeCount > 0
			|| m_researchNitroPacksCompleted || m_researchInfernalPreIgniterCompleted || m_researchSiegeTechCompleted || m_research250mmStrikeCannonsCompleted))
		m_factoryCount++;

	if(m_ghostAcademyCount < m_ghostAcademyNukeCount)
		m_ghostAcademyCount = m_ghostAcademyNukeCount;

	if(m_ghostAcademyCount == 0
		&& (m_ghostCount > 0
			|| m_researchMoebiusReactorCompleted || m_researchPersonalCloakingCompleted))
		m_ghostAcademyCount++;

	if(!m_researchInfantryWeapons1Completed
		&& m_researchInfantryWeapons2Completed)
		m_researchInfantryWeapons1Completed = true;

	if(!m_researchInfantryArmor1Completed
		&& m_researchInfantryArmor2Completed)
		m_researchInfantryArmor1Completed = true;

	if(m_engineeringBayCount == 0
		&& (m_planetaryFortressCount > 0 || m_missileTurretCount > 0 || m_sensorTowerCount > 0
			|| m_researchInfantryWeapons1Completed || m_researchInfantryArmor1Completed || m_researchBuildingArmorCompleted || m_researchHiSecAutoTrackingCompleted || m_researchNeoSteelFrameCompleted))
		m_engineeringBayCount++;

	if(m_barracksCount == 0
		&& (m_techLabCount > 0 || m_reactorCount > 0 || m_orbitalCommandCount > 0 || m_ghostAcademyCount > 0 || m_factoryCount > 0
			|| m_marineCount > 0 || m_marauderCount > 0 || m_reaperCount > 0))
		m_barracksCount++;

	if(m_supplyDepotCount == 0
		&& (m_barracksCount > 0))
		m_supplyDepotCount++;

	if(m_refineryCount == 0
		&& (m_ghostAcademyCount > 0 || m_planetaryFortressCount > 0 || m_techLabCount > 0 || m_reactorCount > 0 || m_factoryCount > 0
			|| m_researchInfantryWeapons1Completed || m_researchInfantryArmor1Completed || m_researchBuildingArmorCompleted || m_researchHiSecAutoTrackingCompleted || m_researchNeoSteelFrameCompleted))
		m_refineryCount++;
}

void CTerranTarget::operator+=(const CTerranTarget &target)
{
	m_minerals = mymax(m_minerals, target.m_minerals);
	m_gas = mymax(m_gas, target.m_gas);
	m_orbitalCommandEnergy = mymax(m_orbitalCommandEnergy, target.m_orbitalCommandEnergy);

	m_commandCenterCount = mymax(m_commandCenterCount, target.m_commandCenterCount);
	m_refineryCount = mymax(m_refineryCount, target.m_refineryCount);
	m_supplyDepotCount = mymax(m_supplyDepotCount, target.m_supplyDepotCount);
	m_barracksCount = mymax(m_barracksCount, target.m_barracksCount);
	m_orbitalCommandCount = mymax(m_orbitalCommandCount, target.m_orbitalCommandCount);
	m_engineeringBayCount = mymax(m_engineeringBayCount, target.m_engineeringBayCount);
	m_bunkerCount = mymax(m_bunkerCount, target.m_bunkerCount);
	m_missileTurretCount = mymax(m_missileTurretCount, target.m_missileTurretCount);
	m_sensorTowerCount = mymax(m_sensorTowerCount, target.m_sensorTowerCount);
	m_planetaryFortressCount = mymax(m_planetaryFortressCount, target.m_planetaryFortressCount);
	m_ghostAcademyCount = mymax(m_ghostAcademyCount, target.m_ghostAcademyCount);
	m_factoryCount = mymax(m_factoryCount, target.m_factoryCount);
	m_armoryCount = mymax(m_armoryCount, target.m_armoryCount);
	m_starportCount = mymax(m_starportCount, target.m_starportCount);
	m_fusionCoreCount = mymax(m_fusionCoreCount, target.m_fusionCoreCount);

	m_techLabCount = mymax(m_techLabCount, target.m_techLabCount);
	m_reactorCount = mymax(m_reactorCount, target.m_reactorCount);
	m_ghostAcademyNukeCount = mymax(m_ghostAcademyNukeCount, target.m_ghostAcademyNukeCount);

	m_scvCount = mymax(m_scvCount, target.m_scvCount);
	m_marineCount = mymax(m_marineCount, target.m_marineCount);
	m_marauderCount = mymax(m_marauderCount, target.m_marauderCount);
	m_reaperCount = mymax(m_reaperCount, target.m_reaperCount);
	m_ghostCount = mymax(m_ghostCount, target.m_ghostCount);
	m_hellionCount = mymax(m_hellionCount, target.m_hellionCount);
	m_siegeTankCount = mymax(m_siegeTankCount, target.m_siegeTankCount);
	m_thorCount = mymax(m_thorCount, target.m_thorCount);
	m_vikingCount = mymax(m_vikingCount, target.m_vikingCount);
	m_medivacCount = mymax(m_medivacCount, target.m_medivacCount);
	m_ravenCount = mymax(m_ravenCount, target.m_ravenCount);
	m_bansheeCount = mymax(m_bansheeCount, target.m_bansheeCount);
	m_battleCruiserCount = mymax(m_battleCruiserCount, target.m_battleCruiserCount);
	m_bansheeCount = mymax(m_bansheeCount, target.m_bansheeCount);

	m_researchStimpackCompleted |= target.m_researchStimpackCompleted;
	m_researchCombatShieldCompleted |= target.m_researchCombatShieldCompleted;
	m_researchNitroPacksCompleted |= target.m_researchNitroPacksCompleted;
	m_researchConcussiveShellsCompleted |= target.m_researchConcussiveShellsCompleted;
	m_researchInfantryWeapons1Completed |= target.m_researchInfantryWeapons1Completed;
	m_researchInfantryWeapons2Completed |= target.m_researchInfantryWeapons2Completed;
	m_researchInfantryWeapons3Completed |= target.m_researchInfantryWeapons3Completed;
	m_researchInfantryArmor1Completed |= target.m_researchInfantryArmor1Completed;
	m_researchInfantryArmor2Completed |= target.m_researchInfantryArmor2Completed;
	m_researchInfantryArmor3Completed |= target.m_researchInfantryArmor3Completed;
	m_researchBuildingArmorCompleted |= target.m_researchBuildingArmorCompleted;
	m_researchHiSecAutoTrackingCompleted |= target.m_researchHiSecAutoTrackingCompleted;
	m_researchNeoSteelFrameCompleted |= target.m_researchNeoSteelFrameCompleted;
	m_researchMoebiusReactorCompleted |= target.m_researchMoebiusReactorCompleted;
	m_researchPersonalCloakingCompleted |= target.m_researchPersonalCloakingCompleted;
	m_researchInfernalPreIgniterCompleted |= target.m_researchInfernalPreIgniterCompleted;
	m_researchSiegeTechCompleted |= target.m_researchSiegeTechCompleted;
	m_research250mmStrikeCannonsCompleted |= target.m_research250mmStrikeCannonsCompleted;
	m_researchVehicleWeapons1Completed |= target.m_researchVehicleWeapons1Completed;
	m_researchVehicleWeapons2Completed |= target.m_researchVehicleWeapons2Completed;
	m_researchVehicleWeapons3Completed |= target.m_researchVehicleWeapons3Completed;
	m_researchVehiclePlating1Completed |= target.m_researchVehiclePlating1Completed;
	m_researchVehiclePlating2Completed |= target.m_researchVehiclePlating2Completed;
	m_researchVehiclePlating3Completed |= target.m_researchVehiclePlating3Completed;
	m_researchShipWeapons1Completed |= target.m_researchShipWeapons1Completed;
	m_researchShipWeapons2Completed |= target.m_researchShipWeapons2Completed;
	m_researchShipWeapons3Completed |= target.m_researchShipWeapons3Completed;
	m_researchShipPlating1Completed |= target.m_researchShipPlating1Completed;
	m_researchShipPlating2Completed |= target.m_researchShipPlating2Completed;
	m_researchShipPlating3Completed |= target.m_researchShipPlating3Completed;
	m_researchDurableMaterialsCompleted |= target.m_researchDurableMaterialsCompleted;
	m_researchCorvidReactorCompleted |= target.m_researchCorvidReactorCompleted;
	m_researchCaduceusReactorCompleted |= target.m_researchCaduceusReactorCompleted;
	m_researchSeekerMissileCompleted |= target.m_researchSeekerMissileCompleted;
	m_researchCloakingFieldCompleted |= target.m_researchCloakingFieldCompleted;
	m_researchBehemothReactorCompleted |= target.m_researchBehemothReactorCompleted;
	m_researchWeaponRefitCompleted |= target.m_researchWeaponRefitCompleted;
}

void CTerranTarget::BuildAlphabet(CVector<ETerranCommand> &alphabet) const
{
	alphabet.push_back(eTerranCommandBuildCommandCenter);

	if(m_refineryCount > 0)
	{
		alphabet.push_back(eTerranCommandBuildRefinery);
		alphabet.push_back(eTerranCommandMoveSCVToGas);
		alphabet.push_back(eTerranCommandMoveSCVToMinerals);
	}

	alphabet.push_back(eTerranCommandBuildSupplyDepot);

	alphabet.push_back(eTerranCommandBuildBarracksNaked);
	alphabet.push_back(eTerranCommandBuildOrbitalCommand); // Always try this to test possible use of MULEs & extra supply
	if(m_engineeringBayCount > 0)
		alphabet.push_back(eTerranCommandBuildEngineeringBay);
	if(m_bunkerCount > 0)
		alphabet.push_back(eTerranCommandBuildBunker);
	if(m_missileTurretCount > 0)
		alphabet.push_back(eTerranCommandBuildMissileTurret);
	if(m_sensorTowerCount > 0)
		alphabet.push_back(eTerranCommandBuildSensorTower);
	if(m_planetaryFortressCount > 0)
		alphabet.push_back(eTerranCommandBuildPlanetaryFortress);
	if(m_ghostAcademyCount > 0)
		alphabet.push_back(eTerranCommandBuildGhostAcademy);
	if(m_factoryCount > 0)
		alphabet.push_back(eTerranCommandBuildFactoryNaked);
	if(m_armoryCount > 0)
		alphabet.push_back(eTerranCommandBuildArmory);
	if(m_starportCount > 0)
		alphabet.push_back(eTerranCommandBuildStarportNaked);
	if(m_fusionCoreCount > 0)
		alphabet.push_back(eTerranCommandBuildFusionCore);


	if(m_techLabCount > 0 || m_reactorCount > 0)
	{
		alphabet.push_back(eTerranCommandLiftBarracksNaked);
		alphabet.push_back(eTerranCommandLandBarracksNaked);

		if(m_factoryCount > 0)
		{
			alphabet.push_back(eTerranCommandLiftFactoryNaked);
			alphabet.push_back(eTerranCommandLandFactoryNaked);
		}

		if(m_starportCount > 0)
		{
			alphabet.push_back(eTerranCommandLiftStarportNaked);
			alphabet.push_back(eTerranCommandLandStarportNaked);
		}
	}

	if(m_techLabCount > 0)
	{
		alphabet.push_back(eTerranCommandBuildBarracksTechLab);
		alphabet.push_back(eTerranCommandBuildBarracksOnTechLab); // TODO: Should test if anything actually needs a barracks tech lab
		alphabet.push_back(eTerranCommandLiftBarracksTechLab);
		alphabet.push_back(eTerranCommandLandBarracksTechLab);

		if(m_factoryCount > 0)
		{
			alphabet.push_back(eTerranCommandBuildFactoryTechLab);
			alphabet.push_back(eTerranCommandBuildFactoryOnTechLab); // TODO: Should test if anything actually needs a factory tech lab
			alphabet.push_back(eTerranCommandLiftFactoryTechLab);
			alphabet.push_back(eTerranCommandLandFactoryTechLab);
		}
		if(m_starportCount > 0)
		{
			alphabet.push_back(eTerranCommandBuildStarportTechLab);
			alphabet.push_back(eTerranCommandBuildStarportOnTechLab); // TODO: Should test if anything actually needs a starport tech lab
			alphabet.push_back(eTerranCommandLiftStarportTechLab);
			alphabet.push_back(eTerranCommandLandStarportTechLab);
		}
	}

	if(m_reactorCount > 0 || m_marineCount >= 2 || m_hellionCount >= 2 || m_vikingCount + m_medivacCount >= 2)
	{
		alphabet.push_back(eTerranCommandBuildBarracksReactor);
		if(m_marineCount >= 2)
			alphabet.push_back(eTerranCommandBuildBarracksOnReactor);
		alphabet.push_back(eTerranCommandLiftBarracksReactor);
		alphabet.push_back(eTerranCommandLandBarracksReactor);

		if(m_factoryCount > 0)
		{
			alphabet.push_back(eTerranCommandBuildFactoryReactor);
			if(m_hellionCount >= 2)
				alphabet.push_back(eTerranCommandBuildFactoryOnReactor);
			alphabet.push_back(eTerranCommandLiftFactoryReactor);
			alphabet.push_back(eTerranCommandLandFactoryReactor);
		}
		if(m_starportCount > 0)
		{
			alphabet.push_back(eTerranCommandBuildStarportReactor);
			if(m_vikingCount + m_medivacCount >= 2)
				alphabet.push_back(eTerranCommandBuildStarportOnReactor);
			alphabet.push_back(eTerranCommandLiftStarportReactor);
			alphabet.push_back(eTerranCommandLandStarportReactor);
		}
	}

	if(m_ghostAcademyNukeCount > 0)
		alphabet.push_back(eTerranCommandArmNuke);

	alphabet.push_back(eTerranCommandBuildSCV);
	if(m_marineCount > 0)
	{
		alphabet.push_back(eTerranCommandBuildMarine);

/*		alphabet.push_back(eTerranCommandBuildMarineNaked);
		alphabet.push_back(eTerranCommandBuildMarineReactor);
		if(m_techLabCount > 0)
			alphabet.push_back(eTerranCommandBuildMarineTechLab);
*/
	}
	if(m_marauderCount > 0)
		alphabet.push_back(eTerranCommandBuildMarauder);
	if(m_reaperCount > 0)
		alphabet.push_back(eTerranCommandBuildReaper);
	if(m_ghostCount > 0)
		alphabet.push_back(eTerranCommandBuildGhost);
	if(m_hellionCount > 0)
	{
		alphabet.push_back(eTerranCommandBuildHellion);

/*		alphabet.push_back(eTerranCommandBuildHellionNaked);
		alphabet.push_back(eTerranCommandBuildHellionReactor);
		if(m_techLabCount > 0)
			alphabet.push_back(eTerranCommandBuildHellionTechLab);
*/
	}
	if(m_siegeTankCount > 0)
		alphabet.push_back(eTerranCommandBuildSiegeTank);
	if(m_thorCount > 0)
		alphabet.push_back(eTerranCommandBuildThor);
	if(m_vikingCount > 0)
	{
		alphabet.push_back(eTerranCommandBuildViking);

/*		alphabet.push_back(eTerranCommandBuildVikingNaked);
		alphabet.push_back(eTerranCommandBuildVikingReactor);
		if(m_techLabCount > 0)
			alphabet.push_back(eTerranCommandBuildVikingTechLab);
*/
	}
	if(m_medivacCount > 0)
	{
		alphabet.push_back(eTerranCommandBuildMedivac);

/*		alphabet.push_back(eTerranCommandBuildMedivacNaked);
		alphabet.push_back(eTerranCommandBuildMedivacReactor);
		if(m_techLabCount > 0)
			alphabet.push_back(eTerranCommandBuildMedivacTechLab);
*/
	}
	if(m_ravenCount > 0)
		alphabet.push_back(eTerranCommandBuildRaven);
	if(m_bansheeCount > 0)
		alphabet.push_back(eTerranCommandBuildBanshee);
	if(m_battleCruiserCount > 0)
		alphabet.push_back(eTerranCommandBuildBattleCruiser);

	alphabet.push_back(eTerranCommandCalldownMULE);
	alphabet.push_back(eTerranCommandCalldownExtraSupplies);
	if(m_scannerSweepCount > 0)
		alphabet.push_back(eTerranCommandScannerSweep);


	if(m_researchStimpackCompleted)
		alphabet.push_back(eTerranCommandResearchStimpack);
	if(m_researchCombatShieldCompleted)
		alphabet.push_back(eTerranCommandResearchCombatShield);
	if(m_researchNitroPacksCompleted)
		alphabet.push_back(eTerranCommandResearchNitroPacks);
	if(m_researchConcussiveShellsCompleted)
		alphabet.push_back(eTerranCommandResearchConcussiveShells);
	if(m_researchInfantryWeapons1Completed)
		alphabet.push_back(eTerranCommandResearchInfantryWeapons1);
	if(m_researchInfantryWeapons2Completed)
		alphabet.push_back(eTerranCommandResearchInfantryWeapons2);
	if(m_researchInfantryWeapons3Completed)
		alphabet.push_back(eTerranCommandResearchInfantryWeapons3);
	if(m_researchInfantryArmor1Completed)
		alphabet.push_back(eTerranCommandResearchInfantryArmor1);
	if(m_researchInfantryArmor2Completed)
		alphabet.push_back(eTerranCommandResearchInfantryArmor2);
	if(m_researchInfantryArmor3Completed)
		alphabet.push_back(eTerranCommandResearchInfantryArmor3);
	if(m_researchBuildingArmorCompleted)
		alphabet.push_back(eTerranCommandResearchBuildingArmor);
	if(m_researchHiSecAutoTrackingCompleted)
		alphabet.push_back(eTerranCommandResearchHiSecAutoTracking);
	if(m_researchNeoSteelFrameCompleted)
		alphabet.push_back(eTerranCommandResearchNeoSteelFrame);
	if(m_researchMoebiusReactorCompleted)
		alphabet.push_back(eTerranCommandResearchMoebiusReactor);
	if(m_researchPersonalCloakingCompleted)
		alphabet.push_back(eTerranCommandResearchPersonalCloaking);
	if(m_researchInfernalPreIgniterCompleted)
		alphabet.push_back(eTerranCommandResearchInfernalPreIgniter);
	if(m_researchSiegeTechCompleted)
		alphabet.push_back(eTerranCommandResearchSiegeTech);
	if(m_research250mmStrikeCannonsCompleted)
		alphabet.push_back(eTerranCommandResearch250mmStrikeCannons);
	if(m_researchVehicleWeapons1Completed)
		alphabet.push_back(eTerranCommandResearchVehicleWeapons1);
	if(m_researchVehicleWeapons2Completed)
		alphabet.push_back(eTerranCommandResearchVehicleWeapons2);
	if(m_researchVehicleWeapons3Completed)
		alphabet.push_back(eTerranCommandResearchVehicleWeapons3);
	if(m_researchVehiclePlating1Completed)
		alphabet.push_back(eTerranCommandResearchVehiclePlating1);
	if(m_researchVehiclePlating2Completed)
		alphabet.push_back(eTerranCommandResearchVehiclePlating2);
	if(m_researchVehiclePlating3Completed)
		alphabet.push_back(eTerranCommandResearchVehiclePlating3);
	if(m_researchShipWeapons1Completed)
		alphabet.push_back(eTerranCommandResearchShipWeapons1);
	if(m_researchShipWeapons2Completed)
		alphabet.push_back(eTerranCommandResearchShipWeapons2);
	if(m_researchShipWeapons3Completed)
		alphabet.push_back(eTerranCommandResearchShipWeapons3);
	if(m_researchShipPlating1Completed)
		alphabet.push_back(eTerranCommandResearchShipPlating1);
	if(m_researchShipPlating2Completed)
		alphabet.push_back(eTerranCommandResearchShipPlating2);
	if(m_researchShipPlating3Completed)
		alphabet.push_back(eTerranCommandResearchShipPlating3);
	if(m_researchDurableMaterialsCompleted)
		alphabet.push_back(eTerranCommandResearchDurableMaterials);
	if(m_researchCorvidReactorCompleted)
		alphabet.push_back(eTerranCommandResearchCorvidReactor);
	if(m_researchCaduceusReactorCompleted)
		alphabet.push_back(eTerranCommandResearchCaduceusReactor);
	if(m_researchSeekerMissileCompleted)
		alphabet.push_back(eTerranCommandResearchSeekerMissile);
	if(m_researchCloakingFieldCompleted)
		alphabet.push_back(eTerranCommandResearchCloakingField);
	if(m_researchBehemothReactorCompleted)
		alphabet.push_back(eTerranCommandResearchBehemothReactor);
	if(m_researchWeaponRefitCompleted)
		alphabet.push_back(eTerranCommandResearchWeaponRefit);
}

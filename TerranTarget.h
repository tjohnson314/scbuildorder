#pragma once

#pragma once

#include "TerranCommand.h"
#include "TerranState.h"
#include "Engine.h"

class CTerranTarget
{
public:
	CTerranTarget();
	~CTerranTarget() {}

	double targetValue(const CTerranState &state, double time, bool bSatisfied) const;
	double targetTimePenalty(const CTerranState &state, double time) const;
	double extraValue(const CTerranState &state) const;

	bool hasTarget() const;
	bool satisfiesTarget(const CTerranState &state) const;
	
	void AddRequirements();

	void operator+=(const CTerranTarget &target);

	void BuildAlphabet(CVector<ETerranCommand> &alphabet) const;

	// Resources
	double m_minerals;
	double m_gas;
	double m_orbitalCommandEnergy;

	// Buildings
	size_t m_commandCenterCount;
	size_t m_refineryCount;
	size_t m_supplyDepotCount;
	size_t m_barracksCount;
	size_t m_orbitalCommandCount;
	size_t m_engineeringBayCount;
	size_t m_bunkerCount;
	size_t m_missileTurretCount;
	size_t m_sensorTowerCount;
	size_t m_planetaryFortressCount;
	size_t m_ghostAcademyCount;
	size_t m_factoryCount;
	size_t m_armoryCount;
	size_t m_starportCount;
	size_t m_fusionCoreCount;

	size_t m_techLabCount;
	size_t m_reactorCount;

	// Units
	bool m_constantSCVProduction;

	size_t m_scvCount;
	size_t m_marineCount;
	size_t m_marauderCount;
	size_t m_reaperCount;
	size_t m_ghostCount;
	size_t m_hellionCount;
	size_t m_siegeTankCount;
	size_t m_thorCount;
	size_t m_vikingCount;
	size_t m_medivacCount;
	size_t m_ravenCount;
	size_t m_bansheeCount;
	size_t m_battleCruiserCount;

	size_t m_scannerSweepCount;

	// Research
	bool m_researchStimpackCompleted;
	bool m_researchCombatShieldCompleted;
	bool m_researchNitroPacksCompleted;
	bool m_researchConcussiveShellsCompleted;
	bool m_researchInfantryWeapons1Completed;
	bool m_researchInfantryWeapons2Completed;
	bool m_researchInfantryWeapons3Completed;
	bool m_researchInfantryArmor1Completed;
	bool m_researchInfantryArmor2Completed;
	bool m_researchInfantryArmor3Completed;
	bool m_researchBuildingArmorCompleted;
	bool m_researchHiSecAutoTrackingCompleted;
	bool m_researchNeoSteelFrameCompleted;
	bool m_researchMoebiusReactorCompleted;
	bool m_researchPersonalCloakingCompleted;
	bool m_researchInfernalPreIgniterCompleted;
	bool m_researchSiegeTechCompleted;
	bool m_researchDurableMaterialsCompleted;
	bool m_research250mmStrikeCannonsCompleted;
	bool m_researchVehicleWeapons1Completed;
	bool m_researchVehicleWeapons2Completed;
	bool m_researchVehicleWeapons3Completed;
	bool m_researchVehiclePlating1Completed;
	bool m_researchVehiclePlating2Completed;
	bool m_researchVehiclePlating3Completed;
	bool m_researchShipWeapons1Completed;
	bool m_researchShipWeapons2Completed;
	bool m_researchShipWeapons3Completed;
	bool m_researchShipPlating1Completed;
	bool m_researchShipPlating2Completed;
	bool m_researchShipPlating3Completed;
	bool m_researchCorvidReactorCompleted;
	bool m_researchCaduceusReactorCompleted;
	bool m_researchSeekerMissileCompleted;
	bool m_researchCloakingFieldCompleted;
	bool m_researchBehemothReactorCompleted;
	bool m_researchWeaponRefitCompleted;
	
};

typedef CSimulatorEngine<CTerranTarget, CTerranState, ETerranCommand, CTerranEvent> CTerranEngine;

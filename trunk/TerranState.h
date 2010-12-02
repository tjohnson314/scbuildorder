#pragma once

#include <stdio.h>
#include "TerranCommand.h"
#include "TerranEvent.h"
#include "LinkedList.h"
#include "Engine.h"

struct CTerranState
{
public:
	class CResourceCost
	{
	public:
		CResourceCost() : m_minerals(0), m_gas(0), m_orbitalCommandEnergy(0) {}

		double m_minerals;
		double m_gas;
		double m_orbitalCommandEnergy;
	};

	CTerranState();
	~CTerranState();

	void SetInitialState();

	bool HasBuildingStateRequirements(double time, ETerranCommand command) const;
	bool HasBuildingRequirements(double time, ETerranCommand command) const;

	bool HasResources(const CResourceCost &cost) const;

	static void GetCost(CResourceCost &cost, ETerranCommand command);
	void SpendResources(const CResourceCost &cost);

	void operator=(const CTerranState &state);

	bool GetResourceWaitTime(const CResourceCost &cost, double &resourceWaitTime) const;
	void ExecuteCommand(double &time, double timeLimit, ETerranCommand command, CLinkedList<CTerranEvent> *&events);

	void RecalculateSupply();
	void RecalculateSupplyCap();
	void RecalculateSupplyCapUnderConstruction();
	void RecalculateMineralIncomeRate();
	void RecalculateGasIncomeRate();

	void ProgressTime(double &time, double duration);
	void ProcessEvent(double &time, CLinkedList<CTerranEvent> *&events);

	void UseSCVForMovement(double duration, double &time, CLinkedList<CTerranEvent> *&events);
	void UseSCVForBuilding(double duration, double &time, CLinkedList<CTerranEvent> *&events);
	void AddEvent(CLinkedList<CTerranEvent> *&events, const CTerranEvent &event);
	void AddEvent(CLinkedList<CTerranEvent> *&events, CLinkedList<CTerranEvent> *event);

	void PrintSummary(CString &output) const { output.AppendFormat(L"%4.0fM %4.0fG %3.0fE %3d/%3dS", m_minerals, m_gas, m_orbitalCommandEnergy[0], (size_t)m_supply, (size_t)m_supplyCap); }
	void PrintDetails(CString &output) const;

	// Resources
	double m_minerals;
	double m_gas;
	double m_orbitalCommandEnergy[4]; // Only going to store energy for 4 nexi

	// Buildings
	size_t m_baseCount;
	size_t m_commandCenterCount;
	size_t m_refineryCount;
	size_t m_supplyDepotCount;
	size_t m_supplyDepotExtraSuppliesCount;
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

	size_t m_barracksTechLabCount;
	size_t m_barracksReactorCount;
	size_t m_factoryTechLabCount;
	size_t m_factoryReactorCount;
	size_t m_starportTechLabCount;
	size_t m_starportReactorCount;

	// Building States
	size_t m_commandCenterUnderConstruction;
	size_t m_refineryUnderConstruction;
	size_t m_supplyDepotUnderConstruction;
	size_t m_supplyDepotExtraSuppliesUnderConstruction;
	size_t m_barracksUnderConstruction;
	size_t m_orbitalCommandUnderConstruction;
	size_t m_engineeringBayUnderConstruction;
	size_t m_bunkerUnderConstruction;
	size_t m_missileTurretUnderConstruction;
	size_t m_sensorTowerUnderConstruction;
	size_t m_planetaryFortressUnderConstruction;
	size_t m_ghostAcademyUnderConstruction;
	size_t m_factoryUnderConstruction;
	size_t m_armoryUnderConstruction;
	size_t m_starportUnderConstruction;
	size_t m_fusionCoreUnderConstruction;

	size_t m_barracksTechLabUnderConstruction;
	size_t m_barracksReactorUnderConstruction;
	size_t m_factoryTechLabUnderConstruction;
	size_t m_factoryReactorUnderConstruction;
	size_t m_starportTechLabUnderConstruction;
	size_t m_starportReactorUnderConstruction;

	size_t m_commandCenterInUse;
	size_t m_barracksInUse;
	size_t m_orbitalCommandInUse;
	size_t m_engineeringBayInUse;
	size_t m_bunkerInUse;
	size_t m_missileTurretInUse;
	size_t m_sensorTowerInUse;
	size_t m_planetaryFortressInUse;
	size_t m_ghostAcademyInUse;
	size_t m_factoryInUse;
	size_t m_armoryInUse;
	size_t m_starportInUse;
	size_t m_fusionCoreInUse;

	size_t m_techLabAvailable;
	size_t m_reactorAvailable;

	size_t m_barracksTechLabInUse;
	size_t m_barracksReactorInUse;
	size_t m_factoryTechLabInUse;
	size_t m_factoryReactorInUse;
	size_t m_starportTechLabInUse;
	size_t m_starportReactorInUse;

	size_t m_barracksTechLabResearchInUse;
	size_t m_factoryTechLabResearchInUse;
	size_t m_starportTechLabResearchInUse;

	size_t m_ghostAcademyNukeCount;
	size_t m_ghostAcademyNukeUnderConstruction;

	// Units
	size_t m_scvCount;
	size_t m_muleCount;
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

	size_t m_scvUnderConstruction;
	size_t m_muleUnderConstruction;
	size_t m_marineUnderConstruction;
	size_t m_marauderUnderConstruction;
	size_t m_reaperUnderConstruction;
	size_t m_ghostUnderConstruction;
	size_t m_hellionUnderConstruction;
	size_t m_siegeTankUnderConstruction;
	size_t m_thorUnderConstruction;
	size_t m_vikingUnderConstruction;
	size_t m_medivacUnderConstruction;
	size_t m_ravenUnderConstruction;
	size_t m_bansheeUnderConstruction;
	size_t m_battleCruiserUnderConstruction;

	// Unit States
	size_t m_scvsOnMinerals;
	size_t m_scvsOnGas;
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

	bool m_researchStimpackUnderConstruction;
	bool m_researchCombatShieldUnderConstruction;
	bool m_researchNitroPacksUnderConstruction;
	bool m_researchConcussiveShellsUnderConstruction;
	bool m_researchInfantryWeapons1UnderConstruction;
	bool m_researchInfantryWeapons2UnderConstruction;
	bool m_researchInfantryWeapons3UnderConstruction;
	bool m_researchInfantryArmor1UnderConstruction;
	bool m_researchInfantryArmor2UnderConstruction;
	bool m_researchInfantryArmor3UnderConstruction;
	bool m_researchBuildingArmorUnderConstruction;
	bool m_researchHiSecAutoTrackingUnderConstruction;
	bool m_researchNeoSteelFrameUnderConstruction;
	bool m_researchMoebiusReactorUnderConstruction;
	bool m_researchPersonalCloakingUnderConstruction;
	bool m_researchInfernalPreIgniterUnderConstruction;
	bool m_researchSiegeTechUnderConstruction;
	bool m_researchDurableMaterialsUnderConstruction;
	bool m_research250mmStrikeCannonsUnderConstruction;
	bool m_researchVehicleWeapons1UnderConstruction;
	bool m_researchVehicleWeapons2UnderConstruction;
	bool m_researchVehicleWeapons3UnderConstruction;
	bool m_researchVehiclePlating1UnderConstruction;
	bool m_researchVehiclePlating2UnderConstruction;
	bool m_researchVehiclePlating3UnderConstruction;
	bool m_researchShipWeapons1UnderConstruction;
	bool m_researchShipWeapons2UnderConstruction;
	bool m_researchShipWeapons3UnderConstruction;
	bool m_researchShipPlating1UnderConstruction;
	bool m_researchShipPlating2UnderConstruction;
	bool m_researchShipPlating3UnderConstruction;
	bool m_researchCorvidReactorUnderConstruction;
	bool m_researchCaduceusReactorUnderConstruction;
	bool m_researchSeekerMissileUnderConstruction;
	bool m_researchCloakingFieldUnderConstruction;
	bool m_researchBehemothReactorUnderConstruction;
	bool m_researchWeaponRefitUnderConstruction;

	// Supply
	size_t m_supply;
	size_t m_supplyCap;
	size_t m_supplyCapUnderConstruction;

	// Income Rates
	double m_mineralIncomeRate;
	double m_gasIncomeRate;
};

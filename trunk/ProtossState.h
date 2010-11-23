#pragma once

#include <iostream>
#include "ProtossCommand.h"
#include "ProtossEvent.h"
#include "FastSortedQueue.h"
#include "Engine.h"

struct CProtossState
{
public:
	class CResourceCost
	{
	public:
		CResourceCost() : m_minerals(0), m_gas(0), m_nexusEnergy(0) {}

		double m_minerals;
		double m_gas;
		double m_nexusEnergy;
	};

	CProtossState();
	~CProtossState();

	void SetInitialState();

	bool HasBuildingStateRequirements(double time, EProtossCommand command) const;
	bool HasBuildingRequirements(double time, EProtossCommand command) const;

	bool HasResources(const CResourceCost &cost) const;

	static void GetCost(CResourceCost &cost, EProtossCommand command);
	void SpendResources(const CResourceCost &cost);

	void operator=(const CProtossState &state);

	bool GetResourceWaitTime(const CResourceCost &cost, double &resourceWaitTime) const;
	void ExecuteCommand(double &time, double timeLimit, EProtossCommand command, CLinkedList<CProtossEvent> *&events);

	void RecalculateSupply();
	void RecalculateSupplyCap();
	void RecalculateSupplyCapUnderConstruction();
	void RecalculateMineralIncomeRate();
	void RecalculateGasIncomeRate();

	void ProgressTime(double &time, double duration);
	void ProcessEvent(double &time, CLinkedList<CProtossEvent> *&events);

	void UseProbeForBuilding(double duration, double &time, CLinkedList<CProtossEvent> *&events);
	void AddEvent(CLinkedList<CProtossEvent> *&events, const CProtossEvent &event);
	void AddEvent(CLinkedList<CProtossEvent> *&events, CLinkedList<CProtossEvent> *event);

	void PrintSummary(CString &output) const { output.AppendFormat(L"%4.0fM %4.0fG %3.0fE %3d/%3dS", m_minerals, m_gas, m_nexusEnergy[0], m_supply, m_supplyCap); }
	void PrintDetails(CString &output) const;

	// Resources
	double m_minerals;
	double m_gas;
	double m_nexusEnergy[4]; // Only going to store energy for 4 nexi

	// Buildings
	size_t m_nexusCount;
	size_t m_assimilatorCount;
	size_t m_pylonCount;
	size_t m_gatewayCount;
	size_t m_warpGateCount;
	size_t m_forgeCount;
	size_t m_photonCannonCount;
	size_t m_cyberneticsCoreCount;
	size_t m_twilightCouncilCount;
	size_t m_templarArchivesCount;
	size_t m_darkShrineCount;
	size_t m_roboticsFacilityCount;
	size_t m_roboticsBayCount;
	size_t m_stargateCount;
	size_t m_fleetBeaconCount;

	// Building States
	size_t m_nexusUnderConstruction;
	size_t m_assimilatorUnderConstruction;
	size_t m_pylonUnderConstruction;
	size_t m_gatewayUnderConstruction;
	size_t m_warpGateUnderConstruction;
	size_t m_forgeUnderConstruction;
	size_t m_photonCannonUnderConstruction;
	size_t m_cyberneticsCoreUnderConstruction;
	size_t m_twilightCouncilUnderConstruction;
	size_t m_templarArchivesUnderConstruction;
	size_t m_darkShrineUnderConstruction;
	size_t m_roboticsFacilityUnderConstruction;
	size_t m_roboticsBayUnderConstruction;
	size_t m_stargateUnderConstruction;
	size_t m_fleetBeaconUnderConstruction;

	size_t m_nexusInUse;
	size_t m_gatewayInUse;
	size_t m_warpGateOnCooldown;
	size_t m_forgeInUse;
	size_t m_cyberneticsCoreInUse;
	size_t m_twilightCouncilInUse;
	size_t m_templarArchivesInUse;
	size_t m_darkShrineInUse;
	size_t m_roboticsFacilityInUse;
	size_t m_roboticsBayInUse;
	size_t m_stargateInUse;
	size_t m_fleetBeaconInUse;

	size_t m_nexusChronoCount;
	size_t m_gatewayChronoCount;
	size_t m_warpGateChronoCount;
	size_t m_forgeChronoCount;
	size_t m_cyberneticsCoreChronoCount;
	size_t m_twilightCouncilChronoCount;
	size_t m_templarArchivesChronoCount;
	size_t m_darkShrineChronoCount;
	size_t m_roboticsFacilityChronoCount;
	size_t m_roboticsBayChronoCount;
	size_t m_stargateChronoCount;
	size_t m_fleetBeaconChronoCount;

	size_t m_nexusChronoAvailable;
	size_t m_gatewayChronoAvailable;
	size_t m_warpGateChronoAvailable;
	size_t m_forgeChronoAvailable;
	size_t m_cyberneticsCoreChronoAvailable;
	size_t m_twilightCouncilChronoAvailable;
	size_t m_templarArchivesChronoAvailable;
	size_t m_darkShrineChronoAvailable;
	size_t m_roboticsFacilityChronoAvailable;
	size_t m_roboticsBayChronoAvailable;
	size_t m_stargateChronoAvailable;
	size_t m_fleetBeaconChronoAvailable;

	// Units
	size_t m_probeCount;
	size_t m_zealotCount;
	size_t m_stalkerCount;
	size_t m_sentryCount;
	size_t m_highTemplarCount;
	size_t m_darkTemplarCount;
	size_t m_archonCount;
	size_t m_warpPrismCount;
	size_t m_observerCount;
	size_t m_immortalCount;
	size_t m_colossusCount;
	size_t m_phoenixCount;
	size_t m_voidRayCount;
	size_t m_carrierCount;
	size_t m_mothershipCount;

	size_t m_probeUnderConstruction;
	size_t m_zealotUnderConstruction;
	size_t m_stalkerUnderConstruction;
	size_t m_sentryUnderConstruction;
	size_t m_highTemplarUnderConstruction;
	size_t m_darkTemplarUnderConstruction;
	size_t m_archonUnderConstruction;
	size_t m_warpPrismUnderConstruction;
	size_t m_observerUnderConstruction;
	size_t m_immortalUnderConstruction;
	size_t m_colossusUnderConstruction;
	size_t m_phoenixUnderConstruction;
	size_t m_voidRayUnderConstruction;
	size_t m_carrierUnderConstruction;
	size_t m_mothershipUnderConstruction;

	// Unit States
	size_t m_probesOnMinerals;
	size_t m_probesOnGas;

	// Research
	bool m_researchGroundWeapons1Completed;
	bool m_researchGroundWeapons2Completed;
	bool m_researchGroundWeapons3Completed;
	bool m_researchGroundArmor1Completed;
	bool m_researchGroundArmor2Completed;
	bool m_researchGroundArmor3Completed;
	bool m_researchShields1Completed;
	bool m_researchShields2Completed;
	bool m_researchShields3Completed;
	bool m_researchAirWeapons1Completed;
	bool m_researchAirWeapons2Completed;
	bool m_researchAirWeapons3Completed;
	bool m_researchAirArmor1Completed;
	bool m_researchAirArmor2Completed;
	bool m_researchAirArmor3Completed;
	bool m_researchWarpGateTransformationCompleted;
	bool m_researchHallucinationCompleted;
	bool m_researchChargeCompleted;
	bool m_researchBlinkCompleted;
	bool m_researchPsionicStormCompleted;
	bool m_researchKhaydarinAmuletCompleted;
	bool m_researchGraviticDriveCompleted;
	bool m_researchGraviticBoostersCompleted;
	bool m_researchExtendedThermalLanceCompleted;
	bool m_researchFluxVanesCompleted;
	bool m_researchGravitonCatapultCompleted;

	bool m_researchGroundWeapons1UnderConstruction;
	bool m_researchGroundWeapons2UnderConstruction;
	bool m_researchGroundWeapons3UnderConstruction;
	bool m_researchGroundArmor1UnderConstruction;
	bool m_researchGroundArmor2UnderConstruction;
	bool m_researchGroundArmor3UnderConstruction;
	bool m_researchShields1UnderConstruction;
	bool m_researchShields2UnderConstruction;
	bool m_researchShields3UnderConstruction;
	bool m_researchAirWeapons1UnderConstruction;
	bool m_researchAirWeapons2UnderConstruction;
	bool m_researchAirWeapons3UnderConstruction;
	bool m_researchAirArmor1UnderConstruction;
	bool m_researchAirArmor2UnderConstruction;
	bool m_researchAirArmor3UnderConstruction;
	bool m_researchWarpGateTransformationUnderConstruction;
	bool m_researchHallucinationUnderConstruction;
	bool m_researchChargeUnderConstruction;
	bool m_researchBlinkUnderConstruction;
	bool m_researchPsionicStormUnderConstruction;
	bool m_researchKhaydarinAmuletUnderConstruction;
	bool m_researchGraviticDriveUnderConstruction;
	bool m_researchGraviticBoostersUnderConstruction;
	bool m_researchExtendedThermalLanceUnderConstruction;
	bool m_researchFluxVanesUnderConstruction;
	bool m_researchGravitonCatapultUnderConstruction;

	// Supply
	size_t m_supply;
	size_t m_supplyCap;
	size_t m_supplyCapUnderConstruction;

	// Income Rates
	double m_mineralIncomeRate;
	double m_gasIncomeRate;

	double m_timeLastProbeMove;
	EProtossCommand m_lastProbeMove;
};


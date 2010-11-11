#pragma once

#include <iostream>
#include "ProtossCommand.h"
#include "ProtossEvent.h"
#include "LinkedList.h"
#include "Engine.h"

struct CProtossState
{
public:
	CProtossState();
	~CProtossState();

	void SetInitialState();

	void AddRequirements();
	bool HasBuildingStateRequirements(double time, EProtossCommand command) const;
	bool HasBuildingRequirements(double time, EProtossCommand command) const;

	static double MineralCost(EProtossCommand command);
	static double GasCost(EProtossCommand command);
	static double NexusEnergyCost(EProtossCommand command);

	void operator=(const CProtossState &state);
	bool operator>=(const CProtossState &state) const;

	void intersection(const CProtossState &s1, const CProtossState &s2);
	void operator-=(const CProtossState &state);

	bool WaitForResources(double &time, double timeLimit, double mineralCost, double gasCost, double nexusEnergyCost, CLinkedList<CProtossEvent> *&events);
	bool PrepareToExecuteCommand(double &time, double timeLimit, EProtossCommand command, CLinkedList<CProtossEvent> *&events);
	bool ExecuteCommand(double &time, double timeLimit, EProtossCommand command, CLinkedList<CProtossEvent> *&events);

	double value();

	void RecalculateSupply();
	void RecalculateSupplyCap();
	void RecalculateSupplyCapUnderConstruction();
	void RecalculateMineralIncomeRate();
	void RecalculateGasIncomeRate();

	void ProgressTime(double &time, double duration);
	void ProcessEvent(double &time, CLinkedList<CProtossEvent> *&events);

	void UseProbeForBuilding(double duration, double &time, CLinkedList<CProtossEvent> *&events);
	void AddEvent(CLinkedList<CProtossEvent> *&events, const CProtossEvent &event);

	void PrintSummary(CString &output) const { output.AppendFormat(L"%4.0fM %4.0fG %3.0fE %3d/%3dS", m_minerals, m_gas, m_nexusEnergy[0], m_supply, m_supplyCap); }

	// Resources
	double m_minerals;
	double m_gas;
	double m_nexusEnergy[4]; // Only going to store energy for 4 nexi

	// Buildings
	size_t m_nexusCount;
	size_t m_assimilatorCount;
	size_t m_pylonCount;
	size_t m_gatewayCount;
	size_t m_warpgateCount;
	size_t m_forgeCount;
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
	size_t m_warpgateUnderConstruction;
	size_t m_forgeUnderConstruction;
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
	size_t m_warpgateOnCooldown;
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
	size_t m_warpgateChronoCount;
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
	size_t m_warpgateChronoAvailable;
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
	bool m_researchWarpgateCompleted;

	bool m_researchWarpgateUnderConstruction;

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

typedef CSimulatorEngine<CProtossState, EProtossCommand, CProtossEvent> CProtossEngine;


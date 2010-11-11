#pragma once

#include <stdio.h>
#include "ZergCommand.h"
#include "ZergEvent.h"
#include "LinkedList.h"
#include "Engine.h"

struct CZergState
{
public:
	CZergState();
	~CZergState();

	void SetInitialState();

	void AddRequirements();
	bool HasBuildingStateRequirements(double time, EZergCommand command) const;
	bool HasBuildingRequirements(double time, EZergCommand command) const;

	static double MineralCost(EZergCommand command);
	static double GasCost(EZergCommand command);
	static double QueenEnergyCost(EZergCommand command);

	void operator=(const CZergState &state);
	bool operator>=(const CZergState &state) const;

	void intersection(const CZergState &s1, const CZergState &s2);
	void operator-=(const CZergState &state);

	bool WaitForResources(double &time, double timeLimit, double mineralCost, double gasCost, double nexusEnergyCost, CLinkedList<CZergEvent> *&events);
	bool PrepareToExecuteCommand(double &time, double timeLimit, EZergCommand command, CLinkedList<CZergEvent> *&events);
	bool ExecuteCommand(double &time, double timeLimit, EZergCommand command, CLinkedList<CZergEvent> *&events);

	double value();

	void RecalculateSupply();
	void RecalculateSupplyCap();
	void RecalculateSupplyCapUnderConstruction();
	void RecalculateMineralIncomeRate();
	void RecalculateGasIncomeRate();

	void ProgressTime(double &time, double duration);
	void ProcessEvent(double &time, CLinkedList<CZergEvent> *&events);

	void ConsumeLarva(double &time, CLinkedList<CZergEvent> *&events);
	void UseDroneForBuilding(double duration, double &time, CLinkedList<CZergEvent> *&events);
	void AddEvent(CLinkedList<CZergEvent> *&events, const CZergEvent &event);

	void PrintSummary(CString &output) const { output.AppendFormat(L"%4.0fM %4.0fG %2dL %3.0fE %3.0f/%3.0fS", m_minerals, m_gas, m_larvaCount, m_queenEnergy[0], m_supply, m_supplyCap); }

	// Resources
	double m_minerals;
	double m_gas;
	double m_queenEnergy[4]; // Only going to store energy for 4 nexi

	// Buildings
	size_t m_hatcheryCount;
	size_t m_extractorCount;
	size_t m_spawningPoolCount;
	size_t m_creepTumourCount;
	size_t m_evolutionChamberCount;
	size_t m_spineCrawlerCount;
	size_t m_sporeCrawlerCount;
	size_t m_roachWarrenCount;
	size_t m_lairCount;
	size_t m_hydraliskDenCount;
	size_t m_banelingNestCount;
	size_t m_spireCount;
	size_t m_infestationPitCount;
	size_t m_nydusNetworkCount;
	size_t m_hiveCount;
	size_t m_ultraliskCavernCount;
	size_t m_greaterSpireCount;

	// Building States
	size_t m_hatcheryUnderConstruction;
	size_t m_extractorUnderConstruction;
	size_t m_spawningPoolUnderConstruction;
	size_t m_creepTumourUnderConstruction;
	size_t m_evolutionChamberUnderConstruction;
	size_t m_spineCrawlerUnderConstruction;
	size_t m_sporeCrawlerUnderConstruction;
	size_t m_roachWarrenUnderConstruction;
	size_t m_lairUnderConstruction;
	size_t m_hydraliskDenUnderConstruction;
	size_t m_banelingNestUnderConstruction;
	size_t m_spireUnderConstruction;
	size_t m_infestationPitUnderConstruction;
	size_t m_nydusNetworkUnderConstruction;
	size_t m_hiveUnderConstruction;
	size_t m_ultraliskCavernUnderConstruction;
	size_t m_greaterSpireUnderConstruction;

	size_t m_hatcheryInUse;
	size_t m_spawningPoolInUse;
	size_t m_creepTumourOnCooldown;
	size_t m_creepTumourExpandAvailable;
	size_t m_evolutionChamberInUse;
	size_t m_spineCrawlerInUse;
	size_t m_sporeCrawlerInUse;
	size_t m_roachWarrenInUse;
	size_t m_lairInUse;
	size_t m_hydraliskDenInUse;
	size_t m_banelingNestInUse;
	size_t m_spireInUse;
	size_t m_infestationPitInUse;
	size_t m_nydusNetworkInUse;
	size_t m_hiveInUse;
	size_t m_ultraliskCavernInUse;
	size_t m_greaterSpireInUse;

	// Units
	size_t m_larvaCount;
	size_t m_droneCount;
	size_t m_overlordCount;
	size_t m_queenCount;
	size_t m_zerglingCount;
	size_t m_roachCount;
	size_t m_hydraliskCount;
	size_t m_banelingCount;
	size_t m_overseerCount;
	size_t m_infestorCount;
	size_t m_mutaliskCount;
	size_t m_corruptorCount;
	size_t m_ultraliskCount;
	size_t m_broodlordCount;

	size_t m_droneUnderConstruction;
	size_t m_overlordUnderConstruction;
	size_t m_queenUnderConstruction;
	size_t m_zerglingUnderConstruction;
	size_t m_roachUnderConstruction;
	size_t m_hydraliskUnderConstruction;
	size_t m_banelingUnderConstruction;
	size_t m_overseerUnderConstruction;
	size_t m_infestorUnderConstruction;
	size_t m_mutaliskUnderConstruction;
	size_t m_corruptorUnderConstruction;
	size_t m_ultraliskUnderConstruction;
	size_t m_broodlordUnderConstruction;

	// Unit States
	size_t m_dronesOnMinerals;
	size_t m_dronesOnGas;

	// Research

	// Supply
	double m_supply;
	double m_supplyCap;
	double m_supplyCapUnderConstruction;

	// Income Rates
	double m_mineralIncomeRate;
	double m_gasIncomeRate;

	double m_timeLastDroneMove;
	EZergCommand m_lastDroneMove;
};

typedef CSimulatorEngine<CZergState, EZergCommand, CZergEvent> CZergEngine;

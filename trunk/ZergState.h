#pragma once

#include <stdio.h>
#include "ZergCommand.h"
#include "ZergEvent.h"
#include "LinkedList.h"
#include "Engine.h"

struct CZergState
{
public:
	class CResourceCost
	{
	public:
		CResourceCost() : m_minerals(0), m_gas(0), m_queenEnergy(0) {}

		double m_minerals;
		double m_gas;
		double m_queenEnergy;
	};

	CZergState();
	~CZergState();

	void SetInitialState();

	bool HasBuildingStateRequirements(double time, EZergCommand command) const;
	bool HasBuildingRequirements(double time, EZergCommand command) const;

	bool HasResources(const CResourceCost &cost) const;

	static void GetCost(CResourceCost &cost, EZergCommand command);
	void SpendResources(const CResourceCost &cost);

	void operator=(const CZergState &state);

	bool GetResourceWaitTime(const CResourceCost &cost, double &resourceWaitTime) const;
	void ExecuteCommand(double &time, double timeLimit, EZergCommand command, CLinkedList<CZergEvent> *&events);

	void RecalculateSupply();
	void RecalculateSupplyCap();
	void RecalculateSupplyCapUnderConstruction();
	void RecalculateMineralIncomeRate();
	void RecalculateGasIncomeRate();

	void ProgressTime(double &time, double duration);
	void ProcessEvent(double &time, CLinkedList<CZergEvent> *&events);

	void ConsumeLarva(double &time, CLinkedList<CZergEvent> *&events);
	void UseDroneForMovement(double duration, double &time, CLinkedList<CZergEvent> *&events);
	void UseDroneForBuilding(double duration, double &time, CLinkedList<CZergEvent> *&events);
	void AddEvent(CLinkedList<CZergEvent> *&events, const CZergEvent &event);
	void AddEvent(CLinkedList<CZergEvent> *&events, CLinkedList<CZergEvent> *event);

	void PrintSummary(CString &output) const { output.AppendFormat(L"%4.0fM %4.0fG %2dL %2dL %2dL %3.0fE %3d/%3dS", m_minerals, m_gas, m_larvaCount[0], m_larvaCount[1], m_larvaCount[2], m_queenEnergy[0], (size_t)m_supply, (size_t)m_supplyCap); }
	void PrintDetails(CString &output) const;

	// Resources
	double m_minerals;
	double m_gas;
	double m_queenEnergy[4]; // Only going to store energy for 4 nexi

	double m_mineralsMined;
	double m_gasHarvested;

	// Buildings
	size_t m_baseCount;
	size_t m_hatcheryCount;
	size_t m_extractorCount;
	size_t m_spawningPoolCount;
	size_t m_banelingNestCount;
	size_t m_creepTumorCount;
	size_t m_evolutionChamberCount;
	size_t m_spineCrawlerCount;
	size_t m_sporeCrawlerCount;
	size_t m_roachWarrenCount;
	size_t m_lairCount;
	size_t m_hydraliskDenCount;
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
	size_t m_creepTumorUnderConstruction;
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

	size_t m_baseTotalSpawningLarvae;
	bool m_baseSpawningLarvae[4];
	size_t m_hatcheryInUse;
	size_t m_spawningPoolInUse;
	size_t m_creepTumorOnCooldown;
	size_t m_creepTumorExpandAvailable;
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
	size_t m_larvaTotalCount;
	size_t m_larvaCount[4];	// Store larva for up to 4 bases
	size_t m_droneCount;
	size_t m_overlordCount;
	size_t m_queenCount;
	size_t m_zerglingCount;
	size_t m_banelingCount;
	size_t m_roachCount;
	size_t m_hydraliskCount;
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
	size_t m_banelingUnderConstruction;
	size_t m_roachUnderConstruction;
	size_t m_hydraliskUnderConstruction;
	size_t m_overseerUnderConstruction;
	size_t m_infestorUnderConstruction;
	size_t m_mutaliskUnderConstruction;
	size_t m_corruptorUnderConstruction;
	size_t m_ultraliskUnderConstruction;
	size_t m_broodlordUnderConstruction;

	// Unit States
	size_t m_queensBusy; // Due to building creep tumors
	size_t m_dronesOnMinerals;
	size_t m_dronesOnGas;

	// Research
	bool m_researchAdrenalGlandsCompleted;
	bool m_researchMetabolicBoostCompleted;
	bool m_researchMeleeAttacks1Completed;
	bool m_researchMeleeAttacks2Completed;
	bool m_researchMeleeAttacks3Completed;
	bool m_researchGroundCarapace1Completed;
	bool m_researchGroundCarapace2Completed;
	bool m_researchGroundCarapace3Completed;
	bool m_researchMissileAttacks1Completed;
	bool m_researchMissileAttacks2Completed;
	bool m_researchMissileAttacks3Completed;
	bool m_researchGlialReconstitutionCompleted;
	bool m_researchTunnelingClawsCompleted;
	bool m_researchCentrifugalHooksCompleted;
	bool m_researchBurrowCompleted;
	bool m_researchPneumaticCarapaceCompleted;
	bool m_researchVentralSacsCompleted;
	bool m_researchGroovedSpinesCompleted;
	bool m_researchPathogenGlandsCompleted;
	bool m_researchNeuralParasiteCompleted;
	bool m_researchFlyerAttacks1Completed;
	bool m_researchFlyerAttacks2Completed;
	bool m_researchFlyerAttacks3Completed;
	bool m_researchFlyerCarapace1Completed;
	bool m_researchFlyerCarapace2Completed;
	bool m_researchFlyerCarapace3Completed;
	bool m_researchChitinousPlatingCompleted;

	bool m_researchAdrenalGlandsUnderConstruction;
	bool m_researchMetabolicBoostUnderConstruction;
	bool m_researchMeleeAttacks1UnderConstruction;
	bool m_researchMeleeAttacks2UnderConstruction;
	bool m_researchMeleeAttacks3UnderConstruction;
	bool m_researchGroundCarapace1UnderConstruction;
	bool m_researchGroundCarapace2UnderConstruction;
	bool m_researchGroundCarapace3UnderConstruction;
	bool m_researchMissileAttacks1UnderConstruction;
	bool m_researchMissileAttacks2UnderConstruction;
	bool m_researchMissileAttacks3UnderConstruction;
	bool m_researchGlialReconstitutionUnderConstruction;
	bool m_researchTunnelingClawsUnderConstruction;
	bool m_researchCentrifugalHooksUnderConstruction;
	bool m_researchBurrowUnderConstruction;
	bool m_researchPneumaticCarapaceUnderConstruction;
	bool m_researchVentralSacsUnderConstruction;
	bool m_researchGroovedSpinesUnderConstruction;
	bool m_researchPathogenGlandsUnderConstruction;
	bool m_researchNeuralParasiteUnderConstruction;
	bool m_researchFlyerAttacks1UnderConstruction;
	bool m_researchFlyerAttacks2UnderConstruction;
	bool m_researchFlyerAttacks3UnderConstruction;
	bool m_researchFlyerCarapace1UnderConstruction;
	bool m_researchFlyerCarapace2UnderConstruction;
	bool m_researchFlyerCarapace3UnderConstruction;
	bool m_researchChitinousPlatingUnderConstruction;

	// Supply
	double m_supply;
	double m_supplyCap;
	double m_supplyCapUnderConstruction;

	// Income Rates
	double m_mineralIncomeRate;
	double m_gasIncomeRate;
};

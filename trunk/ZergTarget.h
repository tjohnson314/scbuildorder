#pragma once

#pragma once

#include "ZergCommand.h"
#include "ZergState.h"
#include "Engine.h"

class CZergTarget
{
public:
	CZergTarget();
	~CZergTarget() {}

	double targetValue(const CZergState &state, double time, bool bSatisfied) const;
	double targetTimePenalty(const CZergState &state, double time) const;
	double extraValue(const CZergState &state) const;

	bool hasTarget() const;
	bool satisfiesTarget(const CZergState &state) const;
	
	void AddRequirements();

	void operator+=(const CZergTarget &target);

	void BuildAlphabet(CVector<EZergCommand> &alphabet) const;

	// Resources
	double m_minerals;
	double m_gas;
	double m_queenEnergy;

	// Buildings
	size_t m_hatcheryCount;
	size_t m_extractorCount;
	size_t m_spawningPoolCount;
	size_t m_creepTumorCount;
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

};

typedef CSimulatorEngine<CZergTarget, CZergState, EZergCommand, CZergEvent> CZergEngine;

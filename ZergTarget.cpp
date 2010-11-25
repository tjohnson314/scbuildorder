#include "stdafx.h"
#include "ZergTarget.h"

CZergTarget::CZergTarget()
: m_minerals(0), m_gas(0), m_queenEnergy(0)
, m_hatcheryCount(0), m_extractorCount(0), m_spawningPoolCount(0), m_creepTumorCount(0), m_evolutionChamberCount(0), m_spineCrawlerCount(0), m_sporeCrawlerCount(0), m_roachWarrenCount(0), m_lairCount(0), m_hydraliskDenCount(0), m_banelingNestCount(0), m_spireCount(0), m_infestationPitCount(0), m_nydusNetworkCount(0), m_hiveCount(0), m_ultraliskCavernCount(0), m_greaterSpireCount(0)
, m_larvaCount(0), m_droneCount(0), m_overlordCount(0), m_queenCount(0), m_zerglingCount(0), m_roachCount(0), m_hydraliskCount(0), m_banelingCount(0), m_overseerCount(0), m_infestorCount(0), m_mutaliskCount(0), m_corruptorCount(0), m_ultraliskCount(0), m_broodlordCount(0)
, m_researchAdrenalGlandsCompleted(false), m_researchMetabolicBoostCompleted(false), m_researchMeleeAttacks1Completed(false), m_researchMeleeAttacks2Completed(false), m_researchMeleeAttacks3Completed(false), m_researchGroundCarapace1Completed(false), m_researchGroundCarapace2Completed(false), m_researchGroundCarapace3Completed(false), m_researchMissileAttacks1Completed(false), m_researchMissileAttacks2Completed(false), m_researchMissileAttacks3Completed(false), m_researchGlialReconstitutionCompleted(false), m_researchTunnelingClawsCompleted(false), m_researchCentrifugalHooksCompleted(false), m_researchBurrowCompleted(false), m_researchPneumaticCarapaceCompleted(false), m_researchVentralSacsCompleted(false), m_researchGroovedSpinesCompleted(false), m_researchPathogenGlandsCompleted(false), m_researchNeuralParasiteCompleted(false), m_researchFlyerAttacks1Completed(false), m_researchFlyerAttacks2Completed(false), m_researchFlyerAttacks3Completed(false), m_researchFlyerCarapace1Completed(false), m_researchFlyerCarapace2Completed(false), m_researchFlyerCarapace3Completed(false), m_researchChitinousPlatingCompleted(false)
{
}

double CZergTarget::targetValue(const CZergState &state, double time) const
{
	double value = 0;

	value += mymin(m_minerals, state.m_minerals) * 1.0;
	value += mymin(m_gas, state.m_gas) * 2.0;
	double queenEnergy = 0;
	for(size_t i=0; i < 4 && i < m_queenCount; i++)
		queenEnergy += state.m_queenEnergy[i];
	value += mymin(m_queenEnergy, queenEnergy) * 0.2;

	value += mymin(m_hatcheryCount, (state.m_hatcheryCount + state.m_lairUnderConstruction)) * 350;
	value += mymin(m_extractorCount, state.m_extractorCount) * 75;
	value += mymin(m_spawningPoolCount, state.m_spawningPoolCount) * 250;
	value += mymin(m_creepTumorCount, state.m_creepTumorCount) * 10;
	value += mymin(m_evolutionChamberCount, state.m_evolutionChamberCount) * 125;
	value += mymin(m_spineCrawlerCount, state.m_spineCrawlerCount) * 150;
	value += mymin(m_sporeCrawlerCount, state.m_sporeCrawlerCount) * 125;
	value += mymin(m_lairCount, (state.m_lairCount + state.m_hiveUnderConstruction)) * 700;
	value += mymin(m_hydraliskDenCount, state.m_hydraliskDenCount) * 350;
	value += mymin(m_banelingNestCount, state.m_banelingNestCount) * 250;
	value += mymin(m_spireCount, (state.m_spireCount + state.m_greaterSpireUnderConstruction)) * 650;
	value += mymin(m_infestationPitCount, state.m_infestationPitCount) * 350;
	value += mymin(m_nydusNetworkCount, state.m_nydusNetworkCount) * 600;
	value += mymin(m_hiveCount, state.m_hiveCount) * 1200;
	value += mymin(m_ultraliskCavernCount, state.m_ultraliskCavernCount) * 600;
	value += mymin(m_greaterSpireCount, state.m_greaterSpireCount) * 1050;

	value += mymin(m_larvaCount, state.m_larvaTotalCount) * 5;
	value += mymin(m_droneCount, state.m_droneCount) * 50;
	value += mymin(m_overlordCount, state.m_overlordCount) * 100;
	value += mymin(m_queenCount, state.m_queenCount) * 150;
	value += mymin(m_zerglingCount, state.m_zerglingCount) * 25;
	value += mymin(m_banelingCount, state.m_banelingCount) * 100;
	value += mymin(m_roachCount, state.m_roachCount) * 100;
	value += mymin(m_hydraliskCount, state.m_hydraliskCount) * 200;
	value += mymin(m_overseerCount, state.m_overseerCount) * 350;
	value += mymin(m_infestorCount, state.m_infestorCount) * 400;
	value += mymin(m_mutaliskCount, state.m_mutaliskCount) * 300;
	value += mymin(m_corruptorCount, state.m_corruptorCount) * 350;
	value += mymin(m_ultraliskCount, state.m_ultraliskCount) * 700;
	value += mymin(m_broodlordCount, state.m_broodlordCount) * 450;

	if(m_researchAdrenalGlandsCompleted && state.m_researchAdrenalGlandsCompleted)
		value += 600;
	if(m_researchMetabolicBoostCompleted && state.m_researchMetabolicBoostCompleted)
		value += 300;
	if(m_researchMeleeAttacks1Completed && state.m_researchMeleeAttacks1Completed)
		value += 300;
	if(m_researchMeleeAttacks2Completed && state.m_researchMeleeAttacks2Completed)
		value += 450;
	if(m_researchMeleeAttacks3Completed && state.m_researchMeleeAttacks3Completed)
		value += 600;
	if(m_researchGroundCarapace1Completed && state.m_researchGroundCarapace1Completed)
		value += 450;
	if(m_researchGroundCarapace2Completed && state.m_researchGroundCarapace2Completed)
		value += 675;
	if(m_researchGroundCarapace3Completed && state.m_researchGroundCarapace3Completed)
		value += 900;
	if(m_researchMissileAttacks1Completed && state.m_researchMissileAttacks1Completed)
		value += 300;
	if(m_researchMissileAttacks2Completed && state.m_researchMissileAttacks2Completed)
		value += 450;
	if(m_researchMissileAttacks3Completed && state.m_researchMissileAttacks3Completed)
		value += 600;
	if(m_researchGlialReconstitutionCompleted && state.m_researchGlialReconstitutionCompleted)
		value += 300;
	if(m_researchTunnelingClawsCompleted && state.m_researchTunnelingClawsCompleted)
		value += 450;
	if(m_researchCentrifugalHooksCompleted && state.m_researchCentrifugalHooksCompleted)
		value += 450;
	if(m_researchBurrowCompleted && state.m_researchBurrowCompleted)
		value += 300;
	if(m_researchPneumaticCarapaceCompleted && state.m_researchPneumaticCarapaceCompleted)
		value += 300;
	if(m_researchVentralSacsCompleted && state.m_researchVentralSacsCompleted)
		value += 600;
	if(m_researchGroovedSpinesCompleted && state.m_researchGroovedSpinesCompleted)
		value += 450;
	if(m_researchPathogenGlandsCompleted && state.m_researchPathogenGlandsCompleted)
		value += 450;
	if(m_researchNeuralParasiteCompleted && state.m_researchNeuralParasiteCompleted)
		value += 300;
	if(m_researchFlyerAttacks1Completed && state.m_researchFlyerAttacks1Completed)
		value += 300;
	if(m_researchFlyerAttacks2Completed && state.m_researchFlyerAttacks2Completed)
		value += 525;
	if(m_researchFlyerAttacks3Completed && state.m_researchFlyerAttacks3Completed)
		value += 750;
	if(m_researchFlyerCarapace1Completed && state.m_researchFlyerCarapace1Completed)
		value += 450;
	if(m_researchFlyerCarapace2Completed && state.m_researchFlyerCarapace2Completed)
		value += 675;
	if(m_researchFlyerCarapace3Completed && state.m_researchFlyerCarapace3Completed)
		value += 900;
	if(m_researchChitinousPlatingCompleted && state.m_researchChitinousPlatingCompleted)
		value += 450;

	return value;
}

double CZergTarget::targetTimePenalty(const CZergState &state, double time) const
{
	double value = 0.0;

/*
	if(m_constantDroneProduction)
	{
		size_t expectedDrones = (size_t)(time / 11.0);
		if(expectedDrones > state.m_probeCount && state.m_probeCount > m_probeCount)
			value += (expectedDrones - state.m_probeCount) * 3.0;
	}
*/

	return value;
}

double CZergTarget::extraValue(const CZergState &state) const
{
	double value = 0;

	if(state.m_minerals > m_minerals)
		value += (state.m_minerals - m_minerals) * 1.1;
	if(state.m_gas > m_gas)
		value += (state.m_gas - m_gas) * 2.2;
	double queenEnergy = 0;
	for(size_t i=0; i < 4 && i < m_queenCount; i++)
		queenEnergy += state.m_queenEnergy[i];
	if(queenEnergy > m_queenEnergy)
		value += (queenEnergy - m_queenEnergy) * 0.2;

	if(state.m_hatcheryCount > m_hatcheryCount)
		value += (state.m_hatcheryCount - m_hatcheryCount) * 350;
	if(state.m_extractorCount > m_extractorCount)
		value += (state.m_extractorCount - m_extractorCount) * 75;
	if(state.m_spawningPoolCount > m_spawningPoolCount)
		value += (state.m_spawningPoolCount - m_spawningPoolCount) * 250;
	if(state.m_creepTumorCount > m_creepTumorCount)
		value += (state.m_creepTumorCount - m_creepTumorCount) * 10;
	if(state.m_evolutionChamberCount > m_evolutionChamberCount)
		value += (state.m_evolutionChamberCount - m_evolutionChamberCount) * 125;
	if(state.m_spineCrawlerCount > m_spineCrawlerCount)
		value += (state.m_spineCrawlerCount - m_spineCrawlerCount) * 150;
	if(state.m_sporeCrawlerCount > m_sporeCrawlerCount)
		value += (state.m_sporeCrawlerCount - m_sporeCrawlerCount) * 125;
	if(state.m_lairCount > m_lairCount)
		value += (state.m_lairCount - m_lairCount) * 700;
	if(state.m_hydraliskDenCount > m_hydraliskDenCount)
		value += (state.m_hydraliskDenCount - m_hydraliskDenCount) * 350;
	if(state.m_banelingNestCount > m_banelingNestCount)
		value += (state.m_banelingNestCount - m_banelingNestCount) * 250;
	if(state.m_spireCount > m_spireCount)
		value += (state.m_spireCount + m_spireCount) * 650;
	if(state.m_infestationPitCount > m_infestationPitCount)
		value += (state.m_infestationPitCount - m_infestationPitCount) * 350;
	if(state.m_nydusNetworkCount > m_nydusNetworkCount)
		value += (state.m_nydusNetworkCount - m_nydusNetworkCount) * 600;
	if(state.m_hiveCount > m_hiveCount)
		value += (state.m_hiveCount - m_hiveCount) * 1200;
	if(state.m_ultraliskCavernCount > m_ultraliskCavernCount)
		value += (state.m_ultraliskCavernCount - m_ultraliskCavernCount) * 600;
	if(state.m_greaterSpireCount > m_greaterSpireCount)
		value += (state.m_greaterSpireCount - m_greaterSpireCount) * 1050;

	if(state.m_larvaTotalCount > m_larvaCount)
		value += (state.m_larvaTotalCount - m_larvaCount) * 10;
	if(state.m_droneCount > m_droneCount)
		value += (state.m_droneCount - m_droneCount) * 50;
	if(state.m_overlordCount > m_overlordCount)
		value += (state.m_overlordCount - m_overlordCount) * 100;
	if(state.m_queenCount > m_queenCount)
		value += (state.m_queenCount - m_queenCount) * 150;
	if(state.m_zerglingCount > m_zerglingCount)
	{
		if(m_banelingCount > 0 && m_zerglingCount == 0 && state.m_banelingCount == 0)
			value += 5000 * state.m_zerglingCount; // Hack to make Zerglings valuable when requesting Banelings
		else
			value += (state.m_zerglingCount - m_zerglingCount) * 25;
	}
	if(state.m_banelingCount > m_banelingCount)
		value += (state.m_banelingCount - m_banelingCount) * 100;
	if(state.m_roachCount > m_roachCount)
		value += (state.m_roachCount - m_roachCount) * 100;
	if(state.m_hydraliskCount > m_hydraliskCount)
		value += (state.m_hydraliskCount - m_hydraliskCount) * 200;
	if(state.m_overseerCount > m_overseerCount)
		value += (state.m_overseerCount - m_overseerCount) * 350;
	if(state.m_infestorCount > m_infestorCount)
		value += (state.m_infestorCount - m_infestorCount) * 400;
	if(state.m_mutaliskCount > m_mutaliskCount)
		value += (state.m_mutaliskCount - m_mutaliskCount) * 300;
	if(state.m_corruptorCount > m_corruptorCount)
	{
		if(m_broodlordCount > 0 && m_corruptorCount == 0 && state.m_broodlordCount == 0)
			value += 5000 * state.m_corruptorCount; // Hack to make Corruptors valuable when requesting Broodlords
		else
			value += (state.m_corruptorCount - m_corruptorCount) * 350;
	}
	if(state.m_ultraliskCount > m_ultraliskCount)
		value += (state.m_ultraliskCount - m_ultraliskCount) * 700;
	if(state.m_broodlordCount > m_broodlordCount)
		value += (state.m_broodlordCount - m_broodlordCount) * 450;

	if(!m_researchAdrenalGlandsCompleted && state.m_researchAdrenalGlandsCompleted)
		value += 600;
	if(!m_researchMetabolicBoostCompleted && state.m_researchMetabolicBoostCompleted)
		value += 300;
	if(!m_researchMeleeAttacks1Completed && state.m_researchMeleeAttacks1Completed)
		value += 300;
	if(!m_researchMeleeAttacks2Completed && state.m_researchMeleeAttacks2Completed)
		value += 450;
	if(!m_researchMeleeAttacks3Completed && state.m_researchMeleeAttacks3Completed)
		value += 600;
	if(!m_researchGroundCarapace1Completed && state.m_researchGroundCarapace1Completed)
		value += 450;
	if(!m_researchGroundCarapace2Completed && state.m_researchGroundCarapace2Completed)
		value += 675;
	if(!m_researchGroundCarapace3Completed && state.m_researchGroundCarapace3Completed)
		value += 900;
	if(!m_researchMissileAttacks1Completed && state.m_researchMissileAttacks1Completed)
		value += 300;
	if(!m_researchMissileAttacks2Completed && state.m_researchMissileAttacks2Completed)
		value += 450;
	if(!m_researchMissileAttacks3Completed && state.m_researchMissileAttacks3Completed)
		value += 600;
	if(!m_researchGlialReconstitutionCompleted && state.m_researchGlialReconstitutionCompleted)
		value += 300;
	if(!m_researchTunnelingClawsCompleted && state.m_researchTunnelingClawsCompleted)
		value += 450;
	if(!m_researchCentrifugalHooksCompleted && state.m_researchCentrifugalHooksCompleted)
		value += 450;
	if(!m_researchBurrowCompleted && state.m_researchBurrowCompleted)
		value += 300;
	if(!m_researchPneumaticCarapaceCompleted && state.m_researchPneumaticCarapaceCompleted)
		value += 300;
	if(!m_researchVentralSacsCompleted && state.m_researchVentralSacsCompleted)
		value += 600;
	if(!m_researchGroovedSpinesCompleted && state.m_researchGroovedSpinesCompleted)
		value += 450;
	if(!m_researchPathogenGlandsCompleted && state.m_researchPathogenGlandsCompleted)
		value += 450;
	if(!m_researchNeuralParasiteCompleted && state.m_researchNeuralParasiteCompleted)
		value += 300;
	if(!m_researchFlyerAttacks1Completed && state.m_researchFlyerAttacks1Completed)
		value += 300;
	if(!m_researchFlyerAttacks2Completed && state.m_researchFlyerAttacks2Completed)
		value += 525;
	if(!m_researchFlyerAttacks3Completed && state.m_researchFlyerAttacks3Completed)
		value += 750;
	if(!m_researchFlyerCarapace1Completed && state.m_researchFlyerCarapace1Completed)
		value += 450;
	if(!m_researchFlyerCarapace2Completed && state.m_researchFlyerCarapace2Completed)
		value += 675;
	if(!m_researchFlyerCarapace3Completed && state.m_researchFlyerCarapace3Completed)
		value += 900;
	if(!m_researchChitinousPlatingCompleted && state.m_researchChitinousPlatingCompleted)
		value += 450;

	return value;
}

bool CZergTarget::hasTarget() const
{
	if(0 < m_minerals) return true;
	if(0 < m_gas) return true;
	if(0 < m_queenEnergy) return true;

	if(0 < m_hatcheryCount) return true;
	if(0 < m_extractorCount) return true;
	if(0 < m_spawningPoolCount) return true;
	if(0 < m_creepTumorCount) return true;
	if(0 < m_evolutionChamberCount) return true;
	if(0 < m_spineCrawlerCount) return true;
	if(0 < m_sporeCrawlerCount) return true;
	if(0 < m_roachWarrenCount) return true;
	if(0 < m_lairCount) return true;
	if(0 < m_hydraliskDenCount) return true;
	if(0 < m_banelingNestCount) return true;
	if(0 < m_spireCount) return true;
	if(0 < m_infestationPitCount) return true;
	if(0 < m_nydusNetworkCount) return true;
	if(0 < m_hiveCount) return true;
	if(0 < m_ultraliskCavernCount) return true;
	if(0 < m_greaterSpireCount) return true;

	if(0 < m_larvaCount) return true;
	if(0 < m_droneCount) return true;
	if(0 < m_overlordCount) return true;
	if(0 < m_queenCount) return true;
	if(0 < m_zerglingCount) return true;
	if(0 < m_banelingCount) return true;
	if(0 < m_roachCount) return true;
	if(0 < m_hydraliskCount) return true;
	if(0 < m_overseerCount) return true;
	if(0 < m_infestorCount) return true;
	if(0 < m_mutaliskCount) return true;
	if(0 < m_corruptorCount) return true;
	if(0 < m_ultraliskCount) return true;
	if(0 < m_broodlordCount) return true;

	if(m_researchAdrenalGlandsCompleted)
		return true;
	if(m_researchMetabolicBoostCompleted)
		return true;
	if(m_researchMeleeAttacks1Completed)
		return true;
	if(m_researchMeleeAttacks2Completed)
		return true;
	if(m_researchMeleeAttacks3Completed)
		return true;
	if(m_researchGroundCarapace1Completed)
		return true;
	if(m_researchGroundCarapace2Completed)
		return true;
	if(m_researchGroundCarapace3Completed)
		return true;
	if(m_researchMissileAttacks1Completed)
		return true;
	if(m_researchMissileAttacks2Completed)
		return true;
	if(m_researchMissileAttacks3Completed)
		return true;
	if(m_researchGlialReconstitutionCompleted)
		return true;
	if(m_researchTunnelingClawsCompleted)
		return true;
	if(m_researchCentrifugalHooksCompleted)
		return true;
	if(m_researchBurrowCompleted)
		return true;
	if(m_researchPneumaticCarapaceCompleted)
		return true;
	if(m_researchVentralSacsCompleted)
		return true;
	if(m_researchGroovedSpinesCompleted)
		return true;
	if(m_researchPathogenGlandsCompleted)
		return true;
	if(m_researchNeuralParasiteCompleted)
		return true;
	if(m_researchFlyerAttacks1Completed)
		return true;
	if(m_researchFlyerAttacks2Completed)
		return true;
	if(m_researchFlyerAttacks3Completed)
		return true;
	if(m_researchFlyerCarapace1Completed)
		return true;
	if(m_researchFlyerCarapace2Completed)
		return true;
	if(m_researchFlyerCarapace3Completed)
		return true;
	if(m_researchChitinousPlatingCompleted)
		return true;

	return false;
}

bool CZergTarget::satisfiesTarget(const CZergState &state) const
{
	if(state.m_minerals < m_minerals)
		return false;
	if(state.m_gas < m_gas)
		return false;

	double queenEnergy = 0;
	const double *queenEnergyPtr = state.m_queenEnergy;
	for(size_t i=0; i < 4; i++, queenEnergyPtr++)
		queenEnergy += *queenEnergyPtr;
	if(queenEnergy < m_queenEnergy)
		return false;

	if(state.m_hatcheryCount < m_hatcheryCount)
		return false;
	if(state.m_extractorCount < m_extractorCount)
		return false;
	if(state.m_spawningPoolCount < m_spawningPoolCount)
		return false;
	if(state.m_banelingNestCount < m_banelingNestCount)
		return false;
	if(state.m_creepTumorCount < m_creepTumorCount)
		return false;
	if(state.m_evolutionChamberCount < m_evolutionChamberCount)
		return false;
	if(state.m_spineCrawlerCount < m_spineCrawlerCount)
		return false;
	if(state.m_sporeCrawlerCount < m_sporeCrawlerCount)
		return false;
	if(state.m_roachWarrenCount < m_roachWarrenCount)
		return false;
	if(state.m_lairCount < m_lairCount)
		return false;
	if(state.m_hydraliskDenCount < m_hydraliskDenCount)
		return false;
	if(state.m_spireCount < m_spireCount)
		return false;
	if(state.m_infestationPitCount < m_infestationPitCount)
		return false;
	if(state.m_nydusNetworkCount < m_nydusNetworkCount)
		return false;
	if(state.m_hiveCount < m_hiveCount)
		return false;
	if(state.m_ultraliskCavernCount < m_ultraliskCavernCount)
		return false;
	if(state.m_greaterSpireCount < m_greaterSpireCount)
		return false;

	if(state.m_droneCount < m_droneCount)
		return false;
	if(state.m_overlordCount < m_overlordCount)
		return false;
	if(state.m_queenCount < m_queenCount)
		return false;
	if(state.m_zerglingCount < m_zerglingCount)
		return false;
	if(state.m_banelingCount < m_banelingCount)
		return false;
	if(state.m_roachCount < m_roachCount)
		return false;
	if(state.m_hydraliskCount < m_hydraliskCount)
		return false;
	if(state.m_overseerCount < m_overseerCount)
		return false;
	if(state.m_infestorCount < m_infestorCount)
		return false;
	if(state.m_mutaliskCount < m_mutaliskCount)
		return false;
	if(state.m_corruptorCount < m_corruptorCount)
		return false;
	if(state.m_ultraliskCount < m_ultraliskCount)
		return false;
	if(state.m_broodlordCount < m_broodlordCount)
		return false;

	if(m_researchAdrenalGlandsCompleted && !state.m_researchAdrenalGlandsCompleted)
		return false;
	if(m_researchMetabolicBoostCompleted && !state.m_researchMetabolicBoostCompleted)
		return false;
	if(m_researchMeleeAttacks1Completed && !state.m_researchMeleeAttacks1Completed)
		return false;
	if(m_researchMeleeAttacks2Completed && !state.m_researchMeleeAttacks2Completed)
		return false;
	if(m_researchMeleeAttacks3Completed && !state.m_researchMeleeAttacks3Completed)
		return false;
	if(m_researchGroundCarapace1Completed && !state.m_researchGroundCarapace1Completed)
		return false;
	if(m_researchGroundCarapace2Completed && !state.m_researchGroundCarapace2Completed)
		return false;
	if(m_researchGroundCarapace3Completed && !state.m_researchGroundCarapace3Completed)
		return false;
	if(m_researchMissileAttacks1Completed && !state.m_researchMissileAttacks1Completed)
		return false;
	if(m_researchMissileAttacks2Completed && !state.m_researchMissileAttacks2Completed)
		return false;
	if(m_researchMissileAttacks3Completed && !state.m_researchMissileAttacks3Completed)
		return false;
	if(m_researchGlialReconstitutionCompleted && !state.m_researchGlialReconstitutionCompleted)
		return false;
	if(m_researchTunnelingClawsCompleted && !state.m_researchTunnelingClawsCompleted)
		return false;
	if(m_researchCentrifugalHooksCompleted && !state.m_researchCentrifugalHooksCompleted)
		return false;
	if(m_researchBurrowCompleted && !state.m_researchBurrowCompleted)
		return false;
	if(m_researchPneumaticCarapaceCompleted && !state.m_researchPneumaticCarapaceCompleted)
		return false;
	if(m_researchVentralSacsCompleted && !state.m_researchVentralSacsCompleted)
		return false;
	if(m_researchGroovedSpinesCompleted && !state.m_researchGroovedSpinesCompleted)
		return false;
	if(m_researchPathogenGlandsCompleted && !state.m_researchPathogenGlandsCompleted)
		return false;
	if(m_researchNeuralParasiteCompleted && !state.m_researchNeuralParasiteCompleted)
		return false;
	if(m_researchFlyerAttacks1Completed && !state.m_researchFlyerAttacks1Completed)
		return false;
	if(m_researchFlyerAttacks2Completed && !state.m_researchFlyerAttacks2Completed)
		return false;
	if(m_researchFlyerAttacks3Completed && !state.m_researchFlyerAttacks3Completed)
		return false;
	if(m_researchFlyerCarapace1Completed && !state.m_researchFlyerCarapace1Completed)
		return false;
	if(m_researchFlyerCarapace2Completed && !state.m_researchFlyerCarapace2Completed)
		return false;
	if(m_researchFlyerCarapace3Completed && !state.m_researchFlyerCarapace3Completed)
		return false;
	if(m_researchChitinousPlatingCompleted && !state.m_researchChitinousPlatingCompleted)
		return false;

	return true;
}

void CZergTarget::AddRequirements()
{
	if(m_greaterSpireCount == 0
		&& (m_broodlordCount > 0))
		m_greaterSpireCount++;

	if(m_ultraliskCavernCount == 0
		&& (m_ultraliskCount > 0
			|| m_researchChitinousPlatingCompleted))
		m_ultraliskCavernCount++;

	if(!m_researchFlyerAttacks2Completed
		&& m_researchFlyerAttacks3Completed)
		m_researchFlyerAttacks2Completed = true;

	if(!m_researchFlyerCarapace2Completed
		&& m_researchFlyerCarapace3Completed)
		m_researchFlyerCarapace2Completed = true;

	if(!m_researchMeleeAttacks2Completed
		&& m_researchMeleeAttacks3Completed)
		m_researchMeleeAttacks2Completed = true;

	if(!m_researchGroundCarapace2Completed
		&& m_researchGroundCarapace3Completed)
		m_researchGroundCarapace2Completed = true;

	if(!m_researchMissileAttacks2Completed
		&& m_researchMissileAttacks3Completed)
		m_researchMissileAttacks2Completed = true;

	if(m_hiveCount == 0
		&& (m_ultraliskCavernCount > 0 || m_greaterSpireCount > 0
			|| m_researchMeleeAttacks2Completed || m_researchGroundCarapace2Completed || m_researchMissileAttacks2Completed || m_researchFlyerAttacks2Completed || m_researchFlyerCarapace2Completed))
		m_hiveCount++;

	if(!m_researchFlyerAttacks1Completed
		&& m_researchFlyerAttacks2Completed)
		m_researchFlyerAttacks1Completed = true;

	if(!m_researchFlyerCarapace1Completed
		&& m_researchFlyerCarapace2Completed)
		m_researchFlyerCarapace1Completed = true;

	if(m_spireCount == 0
		&& (m_greaterSpireCount > 0
			|| m_mutaliskCount > 0 || m_corruptorCount > 0
			|| m_researchFlyerAttacks1Completed || m_researchFlyerCarapace1Completed))
		m_spireCount++;

	if(m_infestationPitCount == 0
		&& (m_hiveCount > 0
			|| m_infestorCount > 0
			|| m_researchPathogenGlandsCompleted || m_researchNeuralParasiteCompleted))
		m_infestationPitCount++;

	if(m_hydraliskDenCount == 0
		&& (m_hydraliskCount > 0
			|| m_researchGroovedSpinesCompleted))
		m_hydraliskDenCount++;

	if(m_lairCount == 0
		&& (m_hydraliskDenCount > 0 || m_infestationPitCount > 0 || m_spireCount > 0 || m_nydusNetworkCount > 0
			|| m_overseerCount > 0
			|| m_researchBurrowCompleted || m_researchGlialReconstitutionCompleted || m_researchPneumaticCarapaceCompleted || m_researchVentralSacsCompleted))
		m_lairCount++;

	if(m_roachWarrenCount == 0
		&& (m_roachCount > 0
			|| m_researchGlialReconstitutionCompleted || m_researchTunnelingClawsCompleted))
		m_roachWarrenCount++;

	if(m_queenCount == 0
		&& (m_creepTumorCount > 0))
		m_queenCount++;

	if(!m_researchMeleeAttacks1Completed
		&& m_researchMeleeAttacks2Completed)
		m_researchMeleeAttacks1Completed = true;

	if(!m_researchGroundCarapace1Completed
		&& m_researchGroundCarapace2Completed)
		m_researchGroundCarapace1Completed = true;

	if(!m_researchMissileAttacks1Completed
		&& m_researchMissileAttacks2Completed)
		m_researchMissileAttacks1Completed = true;

	if(m_evolutionChamberCount == 0
		&& (m_researchMeleeAttacks1Completed || m_researchGroundCarapace1Completed || m_researchMissileAttacks1Completed))
		m_evolutionChamberCount++;

	if(m_banelingNestCount == 0
		&& (m_banelingCount > 0
			|| m_researchCentrifugalHooksCompleted))
		m_banelingNestCount++;

	if(m_spawningPoolCount == 0
		&& (m_spineCrawlerCount > 0 || m_sporeCrawlerCount > 0 || m_evolutionChamberCount > 0 || m_roachWarrenCount > 0 || m_lairCount > 0 || m_banelingNestCount > 0
			|| m_zerglingCount > 0 || m_queenCount > 0
			|| m_researchMetabolicBoostCompleted))
		m_spawningPoolCount++;

	if(m_extractorCount == 0
		&& (m_lairCount > 0 || m_banelingNestCount > 0
			|| m_roachCount > 0
			|| m_researchMetabolicBoostCompleted || m_researchMeleeAttacks1Completed || m_researchGroundCarapace1Completed || m_researchMissileAttacks1Completed || m_researchGlialReconstitutionCompleted || m_researchTunnelingClawsCompleted))
		m_extractorCount++;
}

void CZergTarget::operator+=(const CZergTarget &target)
{
	m_minerals = mymax(m_minerals, target.m_minerals);
	m_gas = mymax(m_gas, target.m_gas);
	m_queenEnergy = mymax(m_queenEnergy, target.m_queenEnergy);

	m_hatcheryCount = mymax(m_hatcheryCount, target.m_hatcheryCount);
	m_extractorCount = mymax(m_extractorCount, target.m_extractorCount);
	m_spawningPoolCount = mymax(m_spawningPoolCount, target.m_spawningPoolCount);
	m_creepTumorCount = mymax(m_creepTumorCount, target.m_creepTumorCount);
	m_evolutionChamberCount = mymax(m_evolutionChamberCount, target.m_evolutionChamberCount);
	m_spineCrawlerCount = mymax(m_spineCrawlerCount, target.m_spineCrawlerCount);
	m_sporeCrawlerCount = mymax(m_sporeCrawlerCount, target.m_sporeCrawlerCount);
	m_roachWarrenCount = mymax(m_roachWarrenCount, target.m_roachWarrenCount);
	m_lairCount = mymax(m_lairCount, target.m_lairCount);
	m_hydraliskDenCount = mymax(m_hydraliskDenCount, target.m_hydraliskDenCount);
	m_banelingNestCount = mymax(m_banelingNestCount, target.m_banelingNestCount);
	m_spireCount = mymax(m_spireCount, target.m_spireCount);
	m_infestationPitCount = mymax(m_infestationPitCount, target.m_infestationPitCount);
	m_nydusNetworkCount = mymax(m_nydusNetworkCount, target.m_nydusNetworkCount);
	m_hiveCount = mymax(m_hiveCount, target.m_hiveCount);
	m_ultraliskCavernCount = mymax(m_ultraliskCavernCount, target.m_ultraliskCavernCount);
	m_greaterSpireCount = mymax(m_greaterSpireCount, target.m_greaterSpireCount);

	m_droneCount = mymax(m_droneCount, target.m_droneCount);
	m_overlordCount = mymax(m_overlordCount, target.m_overlordCount);
	m_queenCount = mymax(m_queenCount, target.m_queenCount);
	m_zerglingCount = mymax(m_zerglingCount, target.m_zerglingCount);
	m_banelingCount = mymax(m_banelingCount, target.m_banelingCount);
	m_roachCount = mymax(m_roachCount, target.m_roachCount);
	m_hydraliskCount = mymax(m_hydraliskCount, target.m_hydraliskCount);
	m_overseerCount = mymax(m_overseerCount, target.m_overseerCount);
	m_infestorCount = mymax(m_infestorCount, target.m_infestorCount);
	m_mutaliskCount = mymax(m_mutaliskCount, target.m_mutaliskCount);
	m_corruptorCount = mymax(m_corruptorCount, target.m_corruptorCount);
	m_ultraliskCount = mymax(m_ultraliskCount, target.m_ultraliskCount);
	m_broodlordCount = mymax(m_broodlordCount, target.m_broodlordCount);

	m_researchAdrenalGlandsCompleted |= target.m_researchAdrenalGlandsCompleted;
	m_researchMetabolicBoostCompleted |= target.m_researchMetabolicBoostCompleted;
	m_researchMeleeAttacks1Completed |= target.m_researchMeleeAttacks1Completed;
	m_researchMeleeAttacks2Completed |= target.m_researchMeleeAttacks2Completed;
	m_researchMeleeAttacks3Completed |= target.m_researchMeleeAttacks3Completed;
	m_researchGroundCarapace1Completed |= target.m_researchGroundCarapace1Completed;
	m_researchGroundCarapace2Completed |= target.m_researchGroundCarapace2Completed;
	m_researchGroundCarapace3Completed |= target.m_researchGroundCarapace3Completed;
	m_researchMissileAttacks1Completed |= target.m_researchMissileAttacks1Completed;
	m_researchMissileAttacks2Completed |= target.m_researchMissileAttacks2Completed;
	m_researchMissileAttacks3Completed |= target.m_researchMissileAttacks3Completed;
	m_researchGlialReconstitutionCompleted |= target.m_researchGlialReconstitutionCompleted;
	m_researchTunnelingClawsCompleted |= target.m_researchTunnelingClawsCompleted;
	m_researchCentrifugalHooksCompleted |= target.m_researchCentrifugalHooksCompleted;
	m_researchBurrowCompleted |= target.m_researchBurrowCompleted;
	m_researchPneumaticCarapaceCompleted |= target.m_researchPneumaticCarapaceCompleted;
	m_researchVentralSacsCompleted |= target.m_researchVentralSacsCompleted;
	m_researchGroovedSpinesCompleted |= target.m_researchGroovedSpinesCompleted;
	m_researchPathogenGlandsCompleted |= target.m_researchPathogenGlandsCompleted;
	m_researchNeuralParasiteCompleted |= target.m_researchNeuralParasiteCompleted;
	m_researchFlyerAttacks1Completed |= target.m_researchFlyerAttacks1Completed;
	m_researchFlyerAttacks2Completed |= target.m_researchFlyerAttacks2Completed;
	m_researchFlyerAttacks3Completed |= target.m_researchFlyerAttacks3Completed;
	m_researchFlyerCarapace1Completed |= target.m_researchFlyerCarapace1Completed;
	m_researchFlyerCarapace2Completed |= target.m_researchFlyerCarapace2Completed;
	m_researchFlyerCarapace3Completed |= target.m_researchFlyerCarapace3Completed;
	m_researchChitinousPlatingCompleted |= target.m_researchChitinousPlatingCompleted;
}

void CZergTarget::BuildAlphabet(CVector<EZergCommand> &alphabet) const
{
	alphabet.push_back(eZergCommandBuildHatchery);
	alphabet.push_back(eZergCommandBuildExtractor);
	//alphabet.push_back(eZergCommandCancelExtractor);

	if(m_extractorCount > 0)
	{
		alphabet.push_back(eZergCommandMoveDroneToGas);
		alphabet.push_back(eZergCommandMoveDroneToMinerals);
	}

	alphabet.push_back(eZergCommandBuildSpawningPool); // Might be better to have queen even if you don't need pool
	if(m_creepTumorCount > 0)
	{
		alphabet.push_back(eZergCommandQueenSpawnCreepTumor);
		alphabet.push_back(eZergCommandExpandCreepTumor);
	}
	if(m_evolutionChamberCount > 0)
		alphabet.push_back(eZergCommandBuildEvolutionChamber);
	if(m_spineCrawlerCount > 0)
		alphabet.push_back(eZergCommandBuildSpineCrawler);
	if(m_sporeCrawlerCount > 0)
		alphabet.push_back(eZergCommandBuildSporeCrawler);
	if(m_roachWarrenCount > 0)
		alphabet.push_back(eZergCommandBuildRoachWarren);
	if(m_lairCount > 0)
		alphabet.push_back(eZergCommandBuildLair);
	if(m_hydraliskDenCount > 0)
		alphabet.push_back(eZergCommandBuildHydraliskDen);
	if(m_banelingNestCount > 0)
		alphabet.push_back(eZergCommandBuildBanelingNest);
	if(m_spireCount > 0)
		alphabet.push_back(eZergCommandBuildSpire);
	if(m_infestationPitCount > 0)
		alphabet.push_back(eZergCommandBuildInfestationPit);
	if(m_nydusNetworkCount > 0)
		alphabet.push_back(eZergCommandBuildNydusNetwork);
	if(m_hiveCount > 0)
		alphabet.push_back(eZergCommandBuildHive);
	if(m_ultraliskCavernCount > 0)
		alphabet.push_back(eZergCommandBuildUltraliskCavern);
	if(m_greaterSpireCount > 0)
		alphabet.push_back(eZergCommandBuildGreaterSpire);

	alphabet.push_back(eZergCommandBuildDrone);
	alphabet.push_back(eZergCommandBuildOverlord);
	alphabet.push_back(eZergCommandBuildQueen);
	if(m_zerglingCount > 0 || m_banelingCount > 0)
		alphabet.push_back(eZergCommandBuildZergling);
	if(m_banelingCount > 0)
		alphabet.push_back(eZergCommandBuildBaneling);
	if(m_roachCount > 0)
		alphabet.push_back(eZergCommandBuildRoach);
	if(m_hydraliskCount > 0)
		alphabet.push_back(eZergCommandBuildHydralisk);
	if(m_overseerCount > 0)
		alphabet.push_back(eZergCommandBuildOverseer);
	if(m_infestorCount > 0)
		alphabet.push_back(eZergCommandBuildInfestor);
	if(m_mutaliskCount > 0)
		alphabet.push_back(eZergCommandBuildMutalisk);
	if(m_corruptorCount > 0 || m_broodlordCount > 0)
		alphabet.push_back(eZergCommandBuildCorruptor);
	if(m_ultraliskCount > 0)
		alphabet.push_back(eZergCommandBuildUltralisk);
	if(m_broodlordCount > 0)
		alphabet.push_back(eZergCommandBuildBroodlord);

	alphabet.push_back(eZergCommandExtractorTrickDrone);

	alphabet.push_back(eZergCommandQueenSpawnLarvae);

	if(m_researchAdrenalGlandsCompleted)
		alphabet.push_back(eZergCommandResearchAdrenalGlands);
	if(m_researchMetabolicBoostCompleted)
		alphabet.push_back(eZergCommandResearchMetabolicBoost);
	if(m_researchMeleeAttacks1Completed)
		alphabet.push_back(eZergCommandResearchMeleeAttacks1);
	if(m_researchMeleeAttacks2Completed)
		alphabet.push_back(eZergCommandResearchMeleeAttacks2);
	if(m_researchMeleeAttacks3Completed)
		alphabet.push_back(eZergCommandResearchMeleeAttacks3);
	if(m_researchGroundCarapace1Completed)
		alphabet.push_back(eZergCommandResearchGroundCarapace1);
	if(m_researchGroundCarapace2Completed)
		alphabet.push_back(eZergCommandResearchGroundCarapace2);
	if(m_researchGroundCarapace3Completed)
		alphabet.push_back(eZergCommandResearchGroundCarapace3);
	if(m_researchMissileAttacks1Completed)
		alphabet.push_back(eZergCommandResearchMissileAttacks1);
	if(m_researchMissileAttacks2Completed)
		alphabet.push_back(eZergCommandResearchMissileAttacks2);
	if(m_researchMissileAttacks3Completed)
		alphabet.push_back(eZergCommandResearchMissileAttacks3);
	if(m_researchGlialReconstitutionCompleted)
		alphabet.push_back(eZergCommandResearchGlialReconstitution);
	if(m_researchTunnelingClawsCompleted)
		alphabet.push_back(eZergCommandResearchTunnelingClaws);
	if(m_researchCentrifugalHooksCompleted)
		alphabet.push_back(eZergCommandResearchCentrifugalHooks);
	if(m_researchBurrowCompleted)
		alphabet.push_back(eZergCommandResearchBurrow);
	if(m_researchPneumaticCarapaceCompleted)
		alphabet.push_back(eZergCommandResearchPneumaticCarapace);
	if(m_researchVentralSacsCompleted)
		alphabet.push_back(eZergCommandResearchVentralSacs);
	if(m_researchGroovedSpinesCompleted)
		alphabet.push_back(eZergCommandResearchGroovedSpines);
	if(m_researchPathogenGlandsCompleted)
		alphabet.push_back(eZergCommandResearchPathogenGlands);
	if(m_researchNeuralParasiteCompleted)
		alphabet.push_back(eZergCommandResearchNeuralParasite);
	if(m_researchFlyerAttacks1Completed)
		alphabet.push_back(eZergCommandResearchFlyerAttacks1);
	if(m_researchFlyerAttacks2Completed)
		alphabet.push_back(eZergCommandResearchFlyerAttacks2);
	if(m_researchFlyerAttacks3Completed)
		alphabet.push_back(eZergCommandResearchFlyerAttacks3);
	if(m_researchFlyerCarapace1Completed)
		alphabet.push_back(eZergCommandResearchFlyerCarapace1);
	if(m_researchFlyerCarapace2Completed)
		alphabet.push_back(eZergCommandResearchFlyerCarapace2);
	if(m_researchFlyerCarapace3Completed)
		alphabet.push_back(eZergCommandResearchFlyerCarapace3);
	if(m_researchChitinousPlatingCompleted)
		alphabet.push_back(eZergCommandResearchChitinousPlating);
}

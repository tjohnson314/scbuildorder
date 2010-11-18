#include "stdafx.h"
#include "ProtossTarget.h"

CProtossTarget::CProtossTarget()
: m_minerals(0), m_gas(0), m_nexusEnergy(0)
, m_nexusCount(0), m_pylonCount(0), m_assimilatorCount(0), m_gatewayCount(0), m_warpGateCount(0), m_forgeCount(0), m_photonCannonCount(0), m_cyberneticsCoreCount(0), m_twilightCouncilCount(0), m_templarArchivesCount(0), m_darkShrineCount(0), m_roboticsFacilityCount(0), m_roboticsBayCount(0), m_stargateCount(0), m_fleetBeaconCount(0)
, m_constantProbeProduction(false), m_probeCount(0), m_zealotCount(0), m_stalkerCount(0), m_sentryCount(0), m_highTemplarCount(0), m_darkTemplarCount(0), m_archonCount(0), m_warpPrismCount(0), m_observerCount(0), m_immortalCount(0), m_colossusCount(0), m_phoenixCount(0), m_voidRayCount(0), m_carrierCount(0), m_mothershipCount(0)
, m_researchGroundWeapons1Completed(false), m_researchGroundWeapons2Completed(false), m_researchGroundWeapons3Completed(false), m_researchGroundArmor1Completed(false), m_researchGroundArmor2Completed(false), m_researchGroundArmor3Completed(false), m_researchShields1Completed(false), m_researchShields2Completed(false), m_researchShields3Completed(false), m_researchAirWeapons1Completed(false), m_researchAirWeapons2Completed(false), m_researchAirWeapons3Completed(false), m_researchAirArmor1Completed(false), m_researchAirArmor2Completed(false), m_researchAirArmor3Completed(false), m_researchWarpGateTransformationCompleted(false), m_researchHallucinationCompleted(false), m_researchChargeCompleted(false), m_researchBlinkCompleted(false), m_researchPsionicStormCompleted(false), m_researchKhaydarinAmuletCompleted(false), m_researchGraviticDriveCompleted(false), m_researchGraviticBoostersCompleted(false), m_researchExtendedThermalLanceCompleted(false), m_researchFluxVanesCompleted(false), m_researchGravitonCatapultCompleted(false)
{
}

double CProtossTarget::targetValue(const CProtossState &state, double time) const
{
	double value = 0;

	value += mymin(m_minerals, state.m_minerals) * 1;
	value += mymin(m_gas, state.m_gas) * 2;
	double nexusEnergy = 0;
	for(size_t i=0; i < 4 && i < m_nexusCount; i++)
		nexusEnergy += state.m_nexusEnergy[i];
	value += mymin(m_nexusEnergy, nexusEnergy) * 0.2;

	value += mymin(m_nexusCount, state.m_nexusCount) * 400;
	value += mymin(m_assimilatorCount, state.m_assimilatorCount) * 75;
	value += mymin(m_pylonCount, state.m_pylonCount) * 100;
	value += mymin(m_gatewayCount, state.m_gatewayCount) * 150;
	value += mymin(m_warpGateCount, state.m_warpGateCount) * 10; // WarpGate value already calculated in gateway count
	value += mymin(m_forgeCount, state.m_forgeCount) * 150;
	value += mymin(m_photonCannonCount, state.m_photonCannonCount) * 150;
	value += mymin(m_cyberneticsCoreCount, state.m_cyberneticsCoreCount) * 150;
	value += mymin(m_twilightCouncilCount, state.m_twilightCouncilCount) * 350;
	value += mymin(m_templarArchivesCount, state.m_templarArchivesCount) * 550;
	value += mymin(m_darkShrineCount, state.m_darkShrineCount) * 650;
	value += mymin(m_roboticsFacilityCount, state.m_roboticsFacilityCount) * 400;
	value += mymin(m_roboticsBayCount, state.m_roboticsBayCount) * 600;
	value += mymin(m_stargateCount, state.m_stargateCount) * 450;
	value += mymin(m_fleetBeaconCount, state.m_fleetBeaconCount) * 700;

	value += mymin(m_probeCount, state.m_probeCount) * 50;
	value += mymin(m_zealotCount, state.m_zealotCount) * 100;
	value += mymin(m_stalkerCount, state.m_stalkerCount) * 225;
	value += mymin(m_sentryCount, state.m_sentryCount) * 250;
	value += mymin(m_highTemplarCount, state.m_highTemplarCount) * 350;
	value += mymin(m_darkTemplarCount, state.m_darkTemplarCount) * 375;
	value += mymin(m_archonCount, state.m_archonCount) * 800;
	value += mymin(m_warpPrismCount, state.m_warpPrismCount) * 200;
	value += mymin(m_observerCount, state.m_observerCount) * 250;
	value += mymin(m_immortalCount, state.m_immortalCount) * 450;
	value += mymin(m_colossusCount, state.m_colossusCount) * 700;
	value += mymin(m_phoenixCount, state.m_phoenixCount) * 350;
	value += mymin(m_voidRayCount, state.m_voidRayCount) * 550;
	value += mymin(m_carrierCount, state.m_carrierCount) * 850;
	value += mymin(m_mothershipCount, state.m_mothershipCount) * 1200;

	if(m_researchGroundWeapons1Completed && state.m_researchGroundWeapons1Completed)
		value += 300;
	if(m_researchGroundWeapons2Completed && state.m_researchGroundWeapons2Completed)
		value += 525;
	if(m_researchGroundWeapons3Completed && state.m_researchGroundWeapons3Completed)
		value += 750;
	if(m_researchGroundArmor1Completed && state.m_researchGroundArmor1Completed)
		value += 300;
	if(m_researchGroundArmor2Completed && state.m_researchGroundArmor2Completed)
		value += 525;
	if(m_researchGroundArmor3Completed && state.m_researchGroundArmor3Completed)
		value += 750;
	if(m_researchShields1Completed && state.m_researchShields1Completed)
		value += 600;
	if(m_researchShields2Completed && state.m_researchShields2Completed)
		value += 900;
	if(m_researchShields3Completed && state.m_researchShields3Completed)
		value += 1200;
	if(m_researchAirWeapons1Completed && state.m_researchAirWeapons1Completed)
		value += 300;
	if(m_researchAirWeapons2Completed && state.m_researchAirWeapons2Completed)
		value += 525;
	if(m_researchAirWeapons3Completed && state.m_researchAirWeapons3Completed)
		value += 750;
	if(m_researchAirArmor1Completed && state.m_researchAirArmor1Completed)
		value += 450;
	if(m_researchAirArmor2Completed && state.m_researchAirArmor2Completed)
		value += 670;
	if(m_researchAirArmor3Completed && state.m_researchAirArmor3Completed)
		value += 900;
	if(m_researchWarpGateTransformationCompleted && state.m_researchWarpGateTransformationCompleted)
		value += 150;
	if(m_researchHallucinationCompleted && state.m_researchHallucinationCompleted)
		value += 300;
	if(m_researchChargeCompleted && state.m_researchChargeCompleted)
		value += 600;
	if(m_researchBlinkCompleted && state.m_researchBlinkCompleted)
		value += 450;
	if(m_researchPsionicStormCompleted && state.m_researchPsionicStormCompleted)
		value += 600;
	if(m_researchKhaydarinAmuletCompleted && state.m_researchKhaydarinAmuletCompleted)
		value += 450;
	if(m_researchGraviticDriveCompleted && state.m_researchGraviticDriveCompleted)
		value += 300;
	if(m_researchGraviticBoostersCompleted && state.m_researchGraviticBoostersCompleted)
		value += 300;
	if(m_researchExtendedThermalLanceCompleted && state.m_researchExtendedThermalLanceCompleted)
		value += 600;
	if(m_researchFluxVanesCompleted && state.m_researchFluxVanesCompleted)
		value += 450;
	if(m_researchGravitonCatapultCompleted && state.m_researchGravitonCatapultCompleted)
		value += 450;

	return value;
}

double CProtossTarget::targetTimePenalty(const CProtossState &state, double time) const
{
	double value = 0.0;

	if(m_constantProbeProduction)
	{
		size_t expectedProbes = (size_t)(time / 11.0);
		if(expectedProbes > state.m_probeCount && state.m_probeCount > m_probeCount)
			value += (expectedProbes - state.m_probeCount) * 3.0;
	}

	return value;
}

double CProtossTarget::extraValue(const CProtossState &state) const
{
	double value = 0;

	if(state.m_minerals > m_minerals)
		value += (state.m_minerals - m_minerals) * 1;
	if(state.m_gas > m_gas)
		value += (state.m_gas - m_gas) * 2;
	double nexusEnergy = 0;
	for(size_t i=0; i < 4 && i < m_nexusCount; i++)
		nexusEnergy += state.m_nexusEnergy[i];
	if(nexusEnergy > m_nexusEnergy)
		value += (nexusEnergy - m_nexusEnergy) * 0.2;

	if(state.m_nexusCount > m_nexusCount)
		value += (state.m_nexusCount - m_nexusCount) * 400;
	if(state.m_assimilatorCount > m_assimilatorCount)
		value += (state.m_assimilatorCount - m_assimilatorCount) * 75;
	if(state.m_pylonCount > m_pylonCount)
		value += (state.m_pylonCount - m_pylonCount) * 100;
	if(state.m_gatewayCount > m_gatewayCount)
		value += (state.m_gatewayCount - m_gatewayCount) * 150;
	if(state.m_warpGateCount > m_warpGateCount)
		value += (state.m_warpGateCount - m_warpGateCount) * 10; // WarpGate value already calculated in gateway count
	if(state.m_forgeCount > m_forgeCount)
		value += (state.m_forgeCount - m_forgeCount) * 150;
	if(state.m_photonCannonCount > m_photonCannonCount)
		value += (state.m_photonCannonCount - m_photonCannonCount) * 150;
	if(state.m_cyberneticsCoreCount > m_cyberneticsCoreCount)
		value += (state.m_cyberneticsCoreCount - m_cyberneticsCoreCount) * 150;
	if(state.m_twilightCouncilCount > m_twilightCouncilCount)
		value += (state.m_twilightCouncilCount - m_twilightCouncilCount) * 350;
	if(state.m_templarArchivesCount > m_templarArchivesCount)
	{
		if(m_archonCount > 0 && m_templarArchivesCount == 0)
			value += 10000; // Hack to make Templar Archives valuable when requesting Archons
		else
			value += (state.m_templarArchivesCount - m_templarArchivesCount) * 550;
	}
	if(state.m_darkShrineCount > m_darkShrineCount)
	{
		if(m_archonCount > 0 && m_darkShrineCount == 0)
			value += 10000; // Hack to make Dark Shrine valuable when requesting Archons
		else
			value += (state.m_darkShrineCount - m_darkShrineCount) * 650;
	}
	if(state.m_roboticsFacilityCount > m_roboticsFacilityCount)
		value += (state.m_roboticsFacilityCount - m_roboticsFacilityCount) * 400;
	if(state.m_roboticsBayCount > m_roboticsBayCount)
		value += (state.m_roboticsBayCount - m_roboticsBayCount) * 600;
	if(state.m_stargateCount > m_stargateCount)
		value += (state.m_stargateCount - m_stargateCount) * 450;
	if(state.m_fleetBeaconCount > m_fleetBeaconCount)
		value += (state.m_fleetBeaconCount - m_fleetBeaconCount) * 700;

	if(state.m_probeCount > m_probeCount)
		value += (state.m_probeCount - m_probeCount) * 50;
	if(state.m_zealotCount > m_zealotCount)
		value += (state.m_zealotCount - m_zealotCount) * 100;
	if(state.m_stalkerCount > m_stalkerCount)
		value += (state.m_stalkerCount - m_stalkerCount) * 225;
	if(state.m_sentryCount > m_sentryCount)
		value += (state.m_sentryCount - m_sentryCount) * 250;
	if(state.m_highTemplarCount > m_highTemplarCount)
	{
		if(m_archonCount > 0 && m_highTemplarCount == 0)
			value += 5000 * state.m_highTemplarCount; // Hack to make High Templar valuable when requesting Archons
		else
			value += (state.m_highTemplarCount - m_highTemplarCount) * 350;
	}
	if(state.m_darkTemplarCount > m_darkTemplarCount)
	{
		if(m_archonCount > 0 && m_darkTemplarCount == 0)
			value += 5000 * state.m_darkTemplarCount; // Hack to make Dark Templar valuable when requesting Archons
		else
			value += (state.m_darkTemplarCount - m_darkTemplarCount) * 375;
	}
	if(state.m_archonCount > m_archonCount)
		value += (state.m_archonCount - m_archonCount) * 800;
	if(state.m_warpPrismCount > m_warpPrismCount)
		value += (state.m_warpPrismCount - m_warpPrismCount) * 200;
	if(state.m_observerCount > m_observerCount)
		value += (state.m_observerCount - m_observerCount) * 250;
	if(state.m_immortalCount > m_immortalCount)
		value += (state.m_immortalCount - m_immortalCount) * 450;
	if(state.m_colossusCount > m_colossusCount)
		value += (state.m_colossusCount - m_colossusCount) * 700;
	if(state.m_phoenixCount > m_phoenixCount)
		value += (state.m_phoenixCount - m_phoenixCount) * 350;
	if(state.m_voidRayCount > m_voidRayCount)
		value += (state.m_voidRayCount - m_voidRayCount) * 550;
	if(state.m_carrierCount > m_carrierCount)
		value += (state.m_carrierCount - m_carrierCount) * 850;
	if(state.m_mothershipCount > m_mothershipCount)
		value += (state.m_mothershipCount - m_mothershipCount) * 1200;

	if(m_researchGroundWeapons1Completed && state.m_researchGroundWeapons1Completed)
		value += 300;
	if(m_researchGroundWeapons2Completed && state.m_researchGroundWeapons2Completed)
		value += 525;
	if(m_researchGroundWeapons3Completed && state.m_researchGroundWeapons3Completed)
		value += 750;
	if(m_researchGroundArmor1Completed && state.m_researchGroundArmor1Completed)
		value += 300;
	if(m_researchGroundArmor2Completed && state.m_researchGroundArmor2Completed)
		value += 525;
	if(m_researchGroundArmor3Completed && state.m_researchGroundArmor3Completed)
		value += 750;
	if(m_researchShields1Completed && state.m_researchShields1Completed)
		value += 600;
	if(m_researchShields2Completed && state.m_researchShields2Completed)
		value += 900;
	if(m_researchShields3Completed && state.m_researchShields3Completed)
		value += 1200;
	if(m_researchAirWeapons1Completed && state.m_researchAirWeapons1Completed)
		value += 300;
	if(m_researchAirWeapons2Completed && state.m_researchAirWeapons2Completed)
		value += 525;
	if(m_researchAirWeapons3Completed && state.m_researchAirWeapons3Completed)
		value += 750;
	if(m_researchAirArmor1Completed && state.m_researchAirArmor1Completed)
		value += 450;
	if(m_researchAirArmor2Completed && state.m_researchAirArmor2Completed)
		value += 670;
	if(m_researchAirArmor3Completed && state.m_researchAirArmor3Completed)
		value += 900;
	if(m_researchWarpGateTransformationCompleted && state.m_researchWarpGateTransformationCompleted)
		value += 150;
	if(m_researchHallucinationCompleted && state.m_researchHallucinationCompleted)
		value += 300;
	if(m_researchChargeCompleted && state.m_researchChargeCompleted)
		value += 600;
	if(m_researchBlinkCompleted && state.m_researchBlinkCompleted)
		value += 450;
	if(m_researchPsionicStormCompleted && state.m_researchPsionicStormCompleted)
		value += 600;
	if(m_researchKhaydarinAmuletCompleted && state.m_researchKhaydarinAmuletCompleted)
		value += 450;
	if(m_researchGraviticDriveCompleted && state.m_researchGraviticDriveCompleted)
		value += 300;
	if(m_researchGraviticBoostersCompleted && state.m_researchGraviticBoostersCompleted)
		value += 300;
	if(m_researchExtendedThermalLanceCompleted && state.m_researchExtendedThermalLanceCompleted)
		value += 600;
	if(m_researchFluxVanesCompleted && state.m_researchFluxVanesCompleted)
		value += 450;
	if(m_researchGravitonCatapultCompleted && state.m_researchGravitonCatapultCompleted)
		value += 450;

	return value;
}

bool CProtossTarget::hasTarget() const
{
	if(0 < m_minerals)
		return true;
	if(0 < m_gas)
		return true;
	if(0 < m_nexusEnergy)
		return true;

	if(0 < m_nexusCount)
		return true;
	if(0 < m_pylonCount)
		return true;
	if(0 < m_assimilatorCount)
		return true;
	if(0 < m_gatewayCount)
		return true;
	if(0 < m_warpGateCount)
		return true;
	if(0 < m_forgeCount)
		return true;
	if(0 < m_photonCannonCount)
		return true;
	if(0 < m_cyberneticsCoreCount)
		return true;
	if(0 < m_twilightCouncilCount)
		return true;
	if(0 < m_templarArchivesCount)
		return true;
	if(0 < m_darkShrineCount)
		return true;
	if(0 < m_roboticsFacilityCount)
		return true;
	if(0 < m_roboticsBayCount)
		return true;
	if(0 < m_stargateCount)
		return true;
	if(0 < m_fleetBeaconCount)
		return true;

	if(0 < m_probeCount)
		return true;
	if(0 < m_zealotCount)
		return true;
	if(0 < m_stalkerCount)
		return true;
	if(0 < m_sentryCount)
		return true;
	if(0 < m_highTemplarCount)
		return true;
	if(0 < m_darkTemplarCount)
		return true;
	if(0 < m_archonCount)
		return true;
	if(0 < m_warpPrismCount)
		return true;
	if(0 < m_observerCount)
		return true;
	if(0 < m_immortalCount)
		return true;
	if(0 < m_colossusCount)
		return true;
	if(0 < m_phoenixCount)
		return true;
	if(0 < m_voidRayCount)
		return true;
	if(0 < m_carrierCount)
		return true;
	if(0 < m_mothershipCount)
		return true;

	if(m_researchGroundWeapons1Completed)
		return true;
	if(m_researchGroundWeapons2Completed)
		return true;
	if(m_researchGroundWeapons3Completed)
		return true;
	if(m_researchGroundArmor1Completed)
		return true;
	if(m_researchGroundArmor2Completed)
		return true;
	if(m_researchGroundArmor3Completed)
		return true;
	if(m_researchShields1Completed)
		return true;
	if(m_researchShields2Completed)
		return true;
	if(m_researchShields3Completed)
		return true;
	if(m_researchAirWeapons1Completed)
		return true;
	if(m_researchAirWeapons2Completed)
		return true;
	if(m_researchAirWeapons3Completed)
		return true;
	if(m_researchAirArmor1Completed)
		return true;
	if(m_researchAirArmor2Completed)
		return true;
	if(m_researchAirArmor3Completed)
		return true;
	if(m_researchWarpGateTransformationCompleted)
		return true;
	if(m_researchHallucinationCompleted)
		return true;
	if(m_researchChargeCompleted)
		return true;
	if(m_researchBlinkCompleted)
		return true;
	if(m_researchPsionicStormCompleted)
		return true;
	if(m_researchKhaydarinAmuletCompleted)
		return true;
	if(m_researchGraviticDriveCompleted)
		return true;
	if(m_researchGraviticBoostersCompleted)
		return true;
	if(m_researchExtendedThermalLanceCompleted)
		return true;
	if(m_researchFluxVanesCompleted)
		return true;
	if(m_researchGravitonCatapultCompleted)
		return true;

	return false;
}

bool CProtossTarget::satisfiesTarget(const CProtossState &state) const
{
	if(state.m_minerals < m_minerals)
		return false;
	if(state.m_gas < m_gas)
		return false;

	double nexusEnergy = 0;
	const double *nexusEnergyPtr = state.m_nexusEnergy;
	for(size_t i=0; i < 4; i++, nexusEnergyPtr++)
		nexusEnergy += *nexusEnergyPtr;
	if(nexusEnergy < m_nexusEnergy)
		return false;

	if(state.m_nexusCount < m_nexusCount)
		return false;
	if(state.m_pylonCount < m_pylonCount)
		return false;
	if(state.m_assimilatorCount < m_assimilatorCount)
		return false;
	if(state.m_gatewayCount < m_gatewayCount)
		return false;
	if(state.m_warpGateCount < m_warpGateCount)
		return false;
	if(state.m_forgeCount < m_forgeCount)
		return false;
	if(state.m_photonCannonCount < m_photonCannonCount)
		return false;
	if(state.m_cyberneticsCoreCount < m_cyberneticsCoreCount)
		return false;
	if(state.m_twilightCouncilCount < m_twilightCouncilCount)
		return false;
	if(state.m_templarArchivesCount < m_templarArchivesCount)
		return false;
	if(state.m_darkShrineCount < m_darkShrineCount)
		return false;
	if(state.m_roboticsFacilityCount < m_roboticsFacilityCount)
		return false;
	if(state.m_roboticsBayCount < m_roboticsBayCount)
		return false;
	if(state.m_stargateCount < m_stargateCount)
		return false;
	if(state.m_fleetBeaconCount < m_fleetBeaconCount)
		return false;

	if(state.m_probeCount < m_probeCount)
		return false;
	if(state.m_zealotCount < m_zealotCount)
		return false;
	if(state.m_stalkerCount < m_stalkerCount)
		return false;
	if(state.m_sentryCount < m_sentryCount)
		return false;
	if(state.m_highTemplarCount < m_highTemplarCount)
		return false;
	if(state.m_darkTemplarCount < m_darkTemplarCount)
		return false;
	if(state.m_archonCount < m_archonCount)
		return false;
	if(state.m_warpPrismCount < m_warpPrismCount)
		return false;
	if(state.m_observerCount < m_observerCount)
		return false;
	if(state.m_immortalCount < m_immortalCount)
		return false;
	if(state.m_colossusCount < m_colossusCount)
		return false;
	if(state.m_phoenixCount < m_phoenixCount)
		return false;
	if(state.m_voidRayCount < m_voidRayCount)
		return false;
	if(state.m_carrierCount < m_carrierCount)
		return false;
	if(state.m_mothershipCount < m_mothershipCount)
		return false;

	if(!state.m_researchGroundWeapons1Completed && m_researchGroundWeapons1Completed)
		return false;
	if(!state.m_researchGroundWeapons2Completed && m_researchGroundWeapons2Completed)
		return false;
	if(!state.m_researchGroundWeapons3Completed && m_researchGroundWeapons3Completed)
		return false;
	if(!state.m_researchGroundArmor1Completed && m_researchGroundArmor1Completed)
		return false;
	if(!state.m_researchGroundArmor2Completed && m_researchGroundArmor2Completed)
		return false;
	if(!state.m_researchGroundArmor3Completed && m_researchGroundArmor3Completed)
		return false;
	if(!state.m_researchShields1Completed && m_researchShields1Completed)
		return false;
	if(!state.m_researchShields2Completed && m_researchShields2Completed)
		return false;
	if(!state.m_researchShields3Completed && m_researchShields3Completed)
		return false;
	if(!state.m_researchAirWeapons1Completed && m_researchAirWeapons1Completed)
		return false;
	if(!state.m_researchAirWeapons2Completed && m_researchAirWeapons2Completed)
		return false;
	if(!state.m_researchAirWeapons3Completed && m_researchAirWeapons3Completed)
		return false;
	if(!state.m_researchAirArmor1Completed && m_researchAirArmor1Completed)
		return false;
	if(!state.m_researchAirArmor2Completed && m_researchAirArmor2Completed)
		return false;
	if(!state.m_researchAirArmor3Completed && m_researchAirArmor3Completed)
		return false;
	if(!state.m_researchWarpGateTransformationCompleted && m_researchWarpGateTransformationCompleted)
		return false;
	if(!state.m_researchHallucinationCompleted && m_researchHallucinationCompleted)
		return false;
	if(!state.m_researchChargeCompleted && m_researchChargeCompleted)
		return false;
	if(!state.m_researchBlinkCompleted && m_researchBlinkCompleted)
		return false;
	if(!state.m_researchPsionicStormCompleted && m_researchPsionicStormCompleted)
		return false;
	if(!state.m_researchKhaydarinAmuletCompleted && m_researchKhaydarinAmuletCompleted)
		return false;
	if(!state.m_researchGraviticDriveCompleted && m_researchGraviticDriveCompleted)
		return false;
	if(!state.m_researchGraviticBoostersCompleted && m_researchGraviticBoostersCompleted)
		return false;
	if(!state.m_researchExtendedThermalLanceCompleted && m_researchExtendedThermalLanceCompleted)
		return false;
	if(!state.m_researchFluxVanesCompleted && m_researchFluxVanesCompleted)
		return false;
	if(!state.m_researchGravitonCatapultCompleted && m_researchGravitonCatapultCompleted)
		return false;

	return true;
}

void CProtossTarget::AddRequirements()
{
	if(!m_researchAirWeapons2Completed
		&& m_researchAirWeapons3Completed)
		m_researchAirWeapons2Completed = true;

	if(!m_researchAirArmor2Completed
		&& m_researchAirArmor3Completed)
		m_researchAirArmor2Completed = true;

	if(m_fleetBeaconCount == 0
		&& (m_carrierCount > 0 || m_mothershipCount > 0
		|| m_researchGravitonCatapultCompleted || m_researchFluxVanesCompleted || m_researchAirWeapons2Completed || m_researchAirArmor2Completed))
		m_fleetBeaconCount++;

	if(m_stargateCount == 0
		&& (m_fleetBeaconCount > 0
		|| m_phoenixCount > 0 || m_voidRayCount > 0))
		m_stargateCount++;

	if(m_roboticsBayCount == 0
		&& (m_colossusCount > 0
			|| m_researchGraviticDriveCompleted || m_researchGraviticBoostersCompleted || m_researchExtendedThermalLanceCompleted))
		m_roboticsBayCount++;

	if(m_roboticsFacilityCount == 0
		&& (m_roboticsBayCount > 0
		|| m_warpPrismCount > 0 || m_observerCount > 0 || m_immortalCount > 0))
		m_roboticsFacilityCount++;

	if(m_darkShrineCount == 0
		&& m_darkTemplarCount > 0)
		m_darkShrineCount++;

	if(m_templarArchivesCount == 0
		&& (m_highTemplarCount > 0
			|| m_researchPsionicStormCompleted || m_researchKhaydarinAmuletCompleted))
		m_templarArchivesCount++;

	if(!m_researchGroundWeapons2Completed
		&& m_researchGroundWeapons3Completed)
		m_researchGroundWeapons2Completed = true;

	if(!m_researchGroundArmor2Completed
		&& m_researchGroundArmor3Completed)
		m_researchGroundArmor2Completed = true;

	if(!m_researchShields2Completed
		&& m_researchShields3Completed)
		m_researchShields2Completed = true;

	if(m_twilightCouncilCount == 0
		&& (m_templarArchivesCount > 0 || m_darkShrineCount > 0
			|| m_archonCount > 0 // Don't know if it's from HTs or DTs, but either way requires TC
			|| m_researchChargeCompleted || m_researchBlinkCompleted || m_researchGroundWeapons2Completed || m_researchGroundArmor2Completed || m_researchShields2Completed))
		m_twilightCouncilCount++;

	if(!m_researchAirWeapons1Completed
		&& m_researchAirWeapons2Completed)
		m_researchAirWeapons1Completed = true;

	if(!m_researchAirArmor1Completed
		&& m_researchAirArmor2Completed)
		m_researchAirArmor1Completed = true;

	if(!m_researchWarpGateTransformationCompleted
		&& (m_warpGateCount > 0))
		m_researchWarpGateTransformationCompleted = true;

	if(m_cyberneticsCoreCount == 0
		&& (m_roboticsFacilityCount > 0 || m_stargateCount > 0 || m_twilightCouncilCount > 0
			|| m_stalkerCount > 0 || m_sentryCount > 0
			|| m_researchAirWeapons1Completed || m_researchAirArmor1Completed || m_researchWarpGateTransformationCompleted || m_researchHallucinationCompleted))
		m_cyberneticsCoreCount++;

	if(!m_researchGroundWeapons1Completed
		&& m_researchGroundWeapons2Completed)
		m_researchGroundWeapons1Completed = true;

	if(!m_researchGroundArmor1Completed
		&& m_researchGroundArmor2Completed)
		m_researchGroundArmor1Completed = true;

	if(!m_researchShields1Completed
		&& m_researchShields2Completed)
		m_researchShields1Completed = true;

	if(m_forgeCount == 0
		&& (m_photonCannonCount > 0
			|| m_researchGroundWeapons1Completed || m_researchGroundArmor1Completed || m_researchShields1Completed))
		m_forgeCount++;

	if(m_gatewayCount < m_warpGateCount)
		m_gatewayCount = m_warpGateCount;

	if(m_gatewayCount == 0
		&& (m_cyberneticsCoreCount > 0 || m_zealotCount > 0))
		m_gatewayCount++;

	if(m_assimilatorCount == 0
		&& (m_twilightCouncilCount > 0 || m_roboticsFacilityCount > 0 || m_stargateCount > 0
			|| m_stalkerCount > 0 || m_sentryCount > 0
			|| m_researchGroundWeapons1Completed || m_researchGroundArmor1Completed || m_researchShields1Completed || m_researchWarpGateTransformationCompleted || m_researchHallucinationCompleted))
		m_assimilatorCount++;

	if(m_pylonCount == 0
		&& (m_gatewayCount > 0 || m_forgeCount > 0))
		m_pylonCount++;
}

void CProtossTarget::operator+=(const CProtossTarget &target)
{
	m_minerals = mymax(m_minerals, target.m_minerals);
	m_gas = mymax(m_gas, target.m_gas);
	m_nexusEnergy = mymax(m_nexusEnergy,  target.m_nexusEnergy) * 0.2;

	m_nexusCount = mymax(m_nexusCount, target.m_nexusCount);
	m_assimilatorCount = mymax(m_assimilatorCount, target.m_assimilatorCount);
	m_pylonCount = mymax(m_pylonCount, target.m_pylonCount);
	m_gatewayCount = mymax(m_gatewayCount, target.m_gatewayCount);
	m_warpGateCount = mymax(m_warpGateCount, target.m_warpGateCount); // WarpGate value already calculated in gateway count
	m_forgeCount = mymax(m_forgeCount, target.m_forgeCount);
	m_photonCannonCount = mymax(m_photonCannonCount, target.m_photonCannonCount);
	m_cyberneticsCoreCount = mymax(m_cyberneticsCoreCount, target.m_cyberneticsCoreCount);
	m_twilightCouncilCount = mymax(m_twilightCouncilCount, target.m_twilightCouncilCount);
	m_templarArchivesCount = mymax(m_templarArchivesCount, target.m_templarArchivesCount);
	m_darkShrineCount = mymax(m_darkShrineCount, target.m_darkShrineCount);
	m_roboticsFacilityCount = mymax(m_roboticsFacilityCount, target.m_roboticsFacilityCount);
	m_roboticsBayCount = mymax(m_roboticsBayCount, target.m_roboticsBayCount);
	m_stargateCount = mymax(m_stargateCount, target.m_stargateCount);
	m_fleetBeaconCount = mymax(m_fleetBeaconCount, target.m_fleetBeaconCount);

	m_probeCount = mymax(m_probeCount, target.m_probeCount);
	m_zealotCount = mymax(m_zealotCount, target.m_zealotCount);
	m_stalkerCount = mymax(m_stalkerCount, target.m_stalkerCount);
	m_sentryCount = mymax(m_sentryCount, target.m_sentryCount);
	m_highTemplarCount = mymax(m_highTemplarCount, target.m_highTemplarCount);
	m_darkTemplarCount = mymax(m_darkTemplarCount, target.m_darkTemplarCount);
	m_archonCount = mymax(m_archonCount, target.m_archonCount);
	m_warpPrismCount = mymax(m_warpPrismCount, target.m_warpPrismCount);
	m_observerCount = mymax(m_observerCount, target.m_observerCount);
	m_immortalCount = mymax(m_immortalCount, target.m_immortalCount);
	m_colossusCount = mymax(m_colossusCount, target.m_colossusCount);
	m_phoenixCount = mymax(m_phoenixCount, target.m_phoenixCount);
	m_voidRayCount = mymax(m_voidRayCount, target.m_voidRayCount);
	m_carrierCount = mymax(m_carrierCount, target.m_carrierCount);
	m_mothershipCount = mymax(m_mothershipCount, target.m_mothershipCount);

	m_researchGroundWeapons1Completed |= target.m_researchGroundWeapons1Completed;
	m_researchGroundWeapons2Completed |= target.m_researchGroundWeapons2Completed;
	m_researchGroundWeapons3Completed |= target.m_researchGroundWeapons3Completed;
	m_researchGroundArmor1Completed |= target.m_researchGroundArmor1Completed;
	m_researchGroundArmor2Completed |= target.m_researchGroundArmor2Completed;
	m_researchGroundArmor3Completed |= target.m_researchGroundArmor3Completed;
	m_researchShields1Completed |= target.m_researchShields1Completed;
	m_researchShields2Completed |= target.m_researchShields2Completed;
	m_researchShields3Completed |= target.m_researchShields3Completed;
	m_researchAirWeapons1Completed |= target.m_researchAirWeapons1Completed;
	m_researchAirWeapons2Completed |= target.m_researchAirWeapons2Completed;
	m_researchAirWeapons3Completed |= target.m_researchAirWeapons3Completed;
	m_researchAirArmor1Completed |= target.m_researchAirArmor1Completed;
	m_researchAirArmor2Completed |= target.m_researchAirArmor2Completed;
	m_researchAirArmor3Completed |= target.m_researchAirArmor3Completed;
	m_researchWarpGateTransformationCompleted |= target.m_researchWarpGateTransformationCompleted;
	m_researchHallucinationCompleted |= target.m_researchHallucinationCompleted;
	m_researchChargeCompleted |= target.m_researchChargeCompleted;
	m_researchBlinkCompleted |= target.m_researchBlinkCompleted;
	m_researchPsionicStormCompleted |= target.m_researchPsionicStormCompleted;
	m_researchKhaydarinAmuletCompleted |= target.m_researchKhaydarinAmuletCompleted;
	m_researchGraviticDriveCompleted |= target.m_researchGraviticDriveCompleted;
	m_researchGraviticBoostersCompleted |= target.m_researchGraviticBoostersCompleted;
	m_researchExtendedThermalLanceCompleted |= target.m_researchExtendedThermalLanceCompleted;
	m_researchFluxVanesCompleted |= target.m_researchFluxVanesCompleted;
	m_researchGravitonCatapultCompleted |= target.m_researchGravitonCatapultCompleted;
}

void CProtossTarget::BuildAlphabet(CVector<EProtossCommand> &alphabet) const
{
/*
	alphabet.push_back(eProtossCommandBuildNexus);
	alphabet.push_back(eProtossCommandBuildPylon);
	alphabet.push_back(eProtossCommandBuildAssimilator);
	alphabet.push_back(eProtossCommandBuildGateway);
	alphabet.push_back(eProtossCommandConvertGatewayToWarpGate);
	alphabet.push_back(eProtossCommandBuildForge);
	alphabet.push_back(eProtossCommandBuildPhotonCannon);
	alphabet.push_back(eProtossCommandBuildCyberneticsCore);
	alphabet.push_back(eProtossCommandBuildTwilightCouncil);
	alphabet.push_back(eProtossCommandBuildTemplarArchives);
	alphabet.push_back(eProtossCommandBuildDarkShrine);
	alphabet.push_back(eProtossCommandBuildRoboticsFacility);
	alphabet.push_back(eProtossCommandBuildRoboticsBay);
	alphabet.push_back(eProtossCommandBuildStargate);
	alphabet.push_back(eProtossCommandBuildFleetBeacon);

	alphabet.push_back(eProtossCommandChronoNexus);
	alphabet.push_back(eProtossCommandChronoGateway);
	alphabet.push_back(eProtossCommandChronoWarpGate);
	alphabet.push_back(eProtossCommandChronoForge);
	alphabet.push_back(eProtossCommandChronoCyberneticsCore);
	alphabet.push_back(eProtossCommandChronoTwilightCouncil);
	alphabet.push_back(eProtossCommandChronoTemplarArchives);
	//alphabet.push_back(eProtossCommandChronoDarkShrine);
	alphabet.push_back(eProtossCommandChronoRoboticsFacility);
	alphabet.push_back(eProtossCommandChronoRoboticsBay);
	alphabet.push_back(eProtossCommandChronoStargate);
	alphabet.push_back(eProtossCommandChronoFleetBeacon);

	alphabet.push_back(eProtossCommandBuildProbe);
	alphabet.push_back(eProtossCommandBuildZealot);
	alphabet.push_back(eProtossCommandBuildStalker);
	alphabet.push_back(eProtossCommandBuildSentry);
	alphabet.push_back(eProtossCommandBuildHighTemplar);
	alphabet.push_back(eProtossCommandBuildDarkTemplar);
	alphabet.push_back(eProtossCommandBuildArchon2HT);
	alphabet.push_back(eProtossCommandBuildArchon1HT1DT);
	alphabet.push_back(eProtossCommandBuildArchon2DT);
	alphabet.push_back(eProtossCommandBuildWarpPrism);
	alphabet.push_back(eProtossCommandBuildObserver);
	alphabet.push_back(eProtossCommandBuildImmortal);
	alphabet.push_back(eProtossCommandBuildColossus);
	alphabet.push_back(eProtossCommandBuildPhoenix);
	alphabet.push_back(eProtossCommandBuildVoidRay);
	alphabet.push_back(eProtossCommandBuildCarrier);
	alphabet.push_back(eProtossCommandBuildMothership);

	alphabet.push_back(eProtossCommandResearchGroundWeapons1);
	alphabet.push_back(eProtossCommandResearchGroundWeapons2);
	alphabet.push_back(eProtossCommandResearchGroundWeapons3);
	alphabet.push_back(eProtossCommandResearchGroundArmor1);
	alphabet.push_back(eProtossCommandResearchGroundArmor2);
	alphabet.push_back(eProtossCommandResearchGroundArmor3);
	alphabet.push_back(eProtossCommandResearchShields1);
	alphabet.push_back(eProtossCommandResearchShields2);
	alphabet.push_back(eProtossCommandResearchShields3);
	alphabet.push_back(eProtossCommandResearchAirWeapons1);
	alphabet.push_back(eProtossCommandResearchAirWeapons2);
	alphabet.push_back(eProtossCommandResearchAirWeapons3);
	alphabet.push_back(eProtossCommandResearchAirArmor1);
	alphabet.push_back(eProtossCommandResearchAirArmor2);
	alphabet.push_back(eProtossCommandResearchAirArmor3);
	alphabet.push_back(eProtossCommandResearchWarpGateTransformation);
	alphabet.push_back(eProtossCommandResearchHallucination);
	alphabet.push_back(eProtossCommandResearchCharge);
	alphabet.push_back(eProtossCommandResearchBlink);
	alphabet.push_back(eProtossCommandResearchPsionicStorm);
	alphabet.push_back(eProtossCommandResearchKhaydarinAmulet);
	alphabet.push_back(eProtossCommandResearchGraviticDrive);
	alphabet.push_back(eProtossCommandResearchGraviticBoosters);
	alphabet.push_back(eProtossCommandResearchExtendedThermalLance);
	alphabet.push_back(eProtossCommandResearchFluxVanes);
	alphabet.push_back(eProtossCommandResearchGravitonCatapult);

	alphabet.push_back(eProtossCommandMoveProbeToGas);
	alphabet.push_back(eProtossCommandMoveProbeToMinerals);

/*/
	alphabet.push_back(eProtossCommandBuildNexus);
	alphabet.push_back(eProtossCommandChronoNexus);
	alphabet.push_back(eProtossCommandBuildPylon);

	if(m_assimilatorCount > 0)
	{
		alphabet.push_back(eProtossCommandBuildAssimilator);
		alphabet.push_back(eProtossCommandMoveProbeToGas);
		alphabet.push_back(eProtossCommandMoveProbeToMinerals);
	}
	if(m_gatewayCount > 0 || m_warpGateCount > 0)
	{
		alphabet.push_back(eProtossCommandBuildGateway);
		alphabet.push_back(eProtossCommandChronoGateway);
		alphabet.push_back(eProtossCommandConvertGatewayToWarpGate);
		alphabet.push_back(eProtossCommandChronoWarpGate);
	}
	if(m_forgeCount > 0)
	{
		alphabet.push_back(eProtossCommandBuildForge);
		alphabet.push_back(eProtossCommandChronoForge);
	}
	if(m_photonCannonCount > 0)
		alphabet.push_back(eProtossCommandBuildPhotonCannon);
	if(m_cyberneticsCoreCount > 0)
	{
		alphabet.push_back(eProtossCommandBuildCyberneticsCore);
		alphabet.push_back(eProtossCommandChronoCyberneticsCore);
	}
	if(m_twilightCouncilCount > 0)
	{
		alphabet.push_back(eProtossCommandBuildTwilightCouncil);
		alphabet.push_back(eProtossCommandChronoTwilightCouncil);
	}
	if(m_templarArchivesCount > 0 || m_archonCount > 0)
	{
		alphabet.push_back(eProtossCommandBuildTemplarArchives);
		alphabet.push_back(eProtossCommandChronoTemplarArchives);
	}
	if(m_darkShrineCount > 0 || m_archonCount > 0)
		alphabet.push_back(eProtossCommandBuildDarkShrine);
	if(m_roboticsFacilityCount > 0)
	{
		alphabet.push_back(eProtossCommandBuildRoboticsFacility);
		alphabet.push_back(eProtossCommandChronoRoboticsFacility);
	}
	if(m_roboticsBayCount > 0)
	{
		alphabet.push_back(eProtossCommandBuildRoboticsBay);
		alphabet.push_back(eProtossCommandChronoRoboticsBay);
	}
	if(m_stargateCount > 0)
	{
		alphabet.push_back(eProtossCommandBuildStargate);
		alphabet.push_back(eProtossCommandChronoStargate);
	}
	if(m_fleetBeaconCount > 0)
	{
		alphabet.push_back(eProtossCommandBuildFleetBeacon);
		alphabet.push_back(eProtossCommandChronoFleetBeacon);
	}

	alphabet.push_back(eProtossCommandBuildProbe);
	if(m_zealotCount > 0)
		alphabet.push_back(eProtossCommandBuildZealot);
	if(m_stalkerCount > 0)
		alphabet.push_back(eProtossCommandBuildStalker);
	if(m_sentryCount > 0)
		alphabet.push_back(eProtossCommandBuildSentry);
	if(m_highTemplarCount > 0 || m_archonCount > 0)
		alphabet.push_back(eProtossCommandBuildHighTemplar);
	if(m_darkTemplarCount > 0 || m_archonCount > 0)
		alphabet.push_back(eProtossCommandBuildDarkTemplar);
	if(m_archonCount > 0)
	{
		alphabet.push_back(eProtossCommandBuildArchon2HT);
		alphabet.push_back(eProtossCommandBuildArchon1HT1DT);
		alphabet.push_back(eProtossCommandBuildArchon2DT);
	}
	if(m_warpPrismCount > 0)
		alphabet.push_back(eProtossCommandBuildWarpPrism);
	if(m_observerCount > 0)
		alphabet.push_back(eProtossCommandBuildObserver);
	if(m_immortalCount > 0)
		alphabet.push_back(eProtossCommandBuildImmortal);
	if(m_colossusCount > 0)
		alphabet.push_back(eProtossCommandBuildColossus);
	if(m_phoenixCount > 0)
		alphabet.push_back(eProtossCommandBuildPhoenix);
	if(m_voidRayCount > 0)
		alphabet.push_back(eProtossCommandBuildVoidRay);
	if(m_carrierCount > 0)
		alphabet.push_back(eProtossCommandBuildCarrier);
	if(m_mothershipCount > 0)
		alphabet.push_back(eProtossCommandBuildMothership);

	if(m_researchGroundWeapons1Completed)
		alphabet.push_back(eProtossCommandResearchGroundWeapons1);
	if(m_researchGroundWeapons2Completed)
		alphabet.push_back(eProtossCommandResearchGroundWeapons2);
	if(m_researchGroundWeapons3Completed)
		alphabet.push_back(eProtossCommandResearchGroundWeapons3);
	if(m_researchGroundArmor1Completed)
		alphabet.push_back(eProtossCommandResearchGroundArmor1);
	if(m_researchGroundArmor2Completed)
		alphabet.push_back(eProtossCommandResearchGroundArmor2);
	if(m_researchGroundArmor3Completed)
		alphabet.push_back(eProtossCommandResearchGroundArmor3);
	if(m_researchShields1Completed)
		alphabet.push_back(eProtossCommandResearchShields1);
	if(m_researchShields2Completed)
		alphabet.push_back(eProtossCommandResearchShields2);
	if(m_researchShields3Completed)
		alphabet.push_back(eProtossCommandResearchShields3);
	if(m_researchAirWeapons1Completed)
		alphabet.push_back(eProtossCommandResearchAirWeapons1);
	if(m_researchAirWeapons2Completed)
		alphabet.push_back(eProtossCommandResearchAirWeapons2);
	if(m_researchAirWeapons3Completed)
		alphabet.push_back(eProtossCommandResearchAirWeapons3);
	if(m_researchAirArmor1Completed)
		alphabet.push_back(eProtossCommandResearchAirArmor1);
	if(m_researchAirArmor2Completed)
		alphabet.push_back(eProtossCommandResearchAirArmor2);
	if(m_researchAirArmor3Completed)
		alphabet.push_back(eProtossCommandResearchAirArmor3);
	if(m_researchWarpGateTransformationCompleted)
		alphabet.push_back(eProtossCommandResearchWarpGateTransformation);
	if(m_researchHallucinationCompleted)
		alphabet.push_back(eProtossCommandResearchHallucination);
	if(m_researchChargeCompleted)
		alphabet.push_back(eProtossCommandResearchCharge);
	if(m_researchBlinkCompleted)
		alphabet.push_back(eProtossCommandResearchBlink);
	if(m_researchPsionicStormCompleted)
		alphabet.push_back(eProtossCommandResearchPsionicStorm);
	if(m_researchKhaydarinAmuletCompleted)
		alphabet.push_back(eProtossCommandResearchKhaydarinAmulet);
	if(m_researchGraviticDriveCompleted)
		alphabet.push_back(eProtossCommandResearchGraviticDrive);
	if(m_researchGraviticBoostersCompleted)
		alphabet.push_back(eProtossCommandResearchGraviticBoosters);
	if(m_researchExtendedThermalLanceCompleted)
		alphabet.push_back(eProtossCommandResearchExtendedThermalLance);
	if(m_researchFluxVanesCompleted)
		alphabet.push_back(eProtossCommandResearchFluxVanes);
	if(m_researchGravitonCatapultCompleted)
		alphabet.push_back(eProtossCommandResearchGravitonCatapult);
//*/
}

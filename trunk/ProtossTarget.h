#pragma once

#include "ProtossCommand.h"
#include "ProtossState.h"
#include "Engine.h"

class CProtossTarget
{
public:
	CProtossTarget();
	~CProtossTarget() {}

	double targetValue(const CProtossState &state, double time, bool bSatisfied) const;
	double targetTimePenalty(const CProtossState &state, double time) const;
	double extraValue(const CProtossState &state) const;

	bool hasTarget() const;
	bool satisfiesTarget(const CProtossState &state) const;
	
	void AddRequirements();

	void operator+=(const CProtossTarget &target);

	void BuildAlphabet(CVector<EProtossCommand> &alphabet) const;

	// Resources
	double m_minerals;
	double m_gas;
	double m_nexusEnergy;

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

	// Units
	bool m_constantProbeProduction;

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

};

typedef CSimulatorEngine<CProtossTarget, CProtossState, EProtossCommand, CProtossEvent> CProtossEngine;

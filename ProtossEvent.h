#pragma once

class CProtossEvent
{
public:
	enum EEvent
	{
		// Buildings
		eSpawnNexus
		, eSpawnAssimilator
		, eSpawnPylon
		, eSpawnGateway
		, eSpawnWarpGate
		, eSpawnChronoWarpGate
		, eSpawnForge
		, eSpawnPhotonCannon
		, eSpawnCyberneticsCore
		, eSpawnTwilightCouncil
		, eSpawnTemplarArchives
		, eSpawnDarkShrine
		, eSpawnRoboticsFacility
		, eSpawnRoboticsBay
		, eSpawnStargate
		, eSpawnFleetBeacon

		, eWarpGateOffCooldown
		, eChronoWarpGateOffCooldown

		, eChronoNexusEnd
		, eChronoGatewayEnd
		, eChronoWarpGateEnd
		, eChronoForgeEnd
		, eChronoCyberneticsCoreEnd
		, eChronoTwilightCouncilEnd
		, eChronoTemplarArchivesEnd
		, eChronoDarkShrineEnd
		, eChronoRoboticsFacilityEnd
		, eChronoRoboticsBayEnd
		, eChronoStargateEnd
		, eChronoFleetBeaconEnd

		, eProbeStartMiningMinerals
		, eProbeStartMiningGas

		// Units
		, eSpawnProbe
		, eSpawnZealot
		, eSpawnStalker
		, eSpawnSentry
		, eSpawnHighTemplar
		, eSpawnDarkTemplar
		, eSpawnArchon
		, eSpawnWarpPrism
		, eSpawnObserver
		, eSpawnImmortal
		, eSpawnColossus
		, eSpawnPhoenix
		, eSpawnVoidRay
		, eSpawnCarrier
		, eSpawnMothership

		, eSpawnChronoProbe
		, eSpawnChronoZealot
		, eSpawnChronoStalker
		, eSpawnChronoSentry
		, eSpawnChronoHighTemplar
		, eSpawnChronoDarkTemplar
		, eSpawnChronoWarpPrism
		, eSpawnChronoObserver
		, eSpawnChronoImmortal
		, eSpawnChronoColossus
		, eSpawnChronoPhoenix
		, eSpawnChronoVoidRay
		, eSpawnChronoCarrier
		, eSpawnChronoMothership

		, eSpawnWarpGateZealot
		, eSpawnWarpGateStalker
		, eSpawnWarpGateSentry
		, eSpawnWarpGateHighTemplar
		, eSpawnWarpGateDarkTemplar

		// Research
		, eResearchGroundWeapons1Complete
		, eResearchGroundWeapons2Complete
		, eResearchGroundWeapons3Complete
		, eResearchGroundArmor1Complete
		, eResearchGroundArmor2Complete
		, eResearchGroundArmor3Complete
		, eResearchShields1Complete
		, eResearchShields2Complete
		, eResearchShields3Complete
		, eResearchAirWeapons1Complete
		, eResearchAirWeapons2Complete
		, eResearchAirWeapons3Complete
		, eResearchAirArmor1Complete
		, eResearchAirArmor2Complete
		, eResearchAirArmor3Complete
		, eResearchWarpGateTransformationComplete
		, eResearchHallucinationComplete
		, eResearchChargeComplete
		, eResearchBlinkComplete
		, eResearchPsionicStormComplete
		, eResearchKhaydarinAmuletComplete
		, eResearchGraviticDriveComplete
		, eResearchGraviticBoostersComplete
		, eResearchExtendedThermalLanceComplete
		, eResearchFluxVanesComplete
		, eResearchGravitonCatapultComplete

		, eResearchChronoGroundWeapons1Complete
		, eResearchChronoGroundWeapons2Complete
		, eResearchChronoGroundWeapons3Complete
		, eResearchChronoGroundArmor1Complete
		, eResearchChronoGroundArmor2Complete
		, eResearchChronoGroundArmor3Complete
		, eResearchChronoShields1Complete
		, eResearchChronoShields2Complete
		, eResearchChronoShields3Complete
		, eResearchChronoAirWeapons1Complete
		, eResearchChronoAirWeapons2Complete
		, eResearchChronoAirWeapons3Complete
		, eResearchChronoAirArmor1Complete
		, eResearchChronoAirArmor2Complete
		, eResearchChronoAirArmor3Complete
		, eResearchChronoWarpGateTransformationComplete
		, eResearchChronoHallucinationComplete
		, eResearchChronoChargeComplete
		, eResearchChronoBlinkComplete
		, eResearchChronoPsionicStormComplete
		, eResearchChronoKhaydarinAmuletComplete
		, eResearchChronoGraviticDriveComplete
		, eResearchChronoGraviticBoostersComplete
		, eResearchChronoExtendedThermalLanceComplete
		, eResearchChronoFluxVanesComplete
		, eResearchChronoGravitonCatapultComplete
	};

	CProtossEvent(EEvent event, double time) : m_event(event), m_time(time) {}

	void event(EEvent event) { m_event = event; }
	EEvent event() const { return m_event; }
	void time(double time) { m_time = time; }
	double time() const { return m_time; }

	bool operator <(const CProtossEvent &event) const { return m_time < event.time(); }

protected:
	EEvent m_event;
	double m_time;
};

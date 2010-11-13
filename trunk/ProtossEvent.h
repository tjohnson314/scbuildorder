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
		, eSpawnWarpgate
		, eSpawnChronoWarpgate
		, eSpawnForge
		, eSpawnCyberneticsCore
		, eSpawnTwilightCouncil
		, eSpawnTemplarArchives
		, eSpawnDarkShrine
		, eSpawnRoboticsFacility
		, eSpawnRoboticsBay
		, eSpawnStargate
		, eSpawnFleetBeacon

		, eWarpgateOffCooldown
		, eChronoWarpgateOffCooldown

		, eChronoNexusEnd
		, eChronoGatewayEnd
		, eChronoWarpgateEnd
		, eChronoForgeEnd
		, eChronoCyberneticsCoreEnd
		, eChronoTwilightCouncilEnd
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

		, eSpawnWarpgateZealot
		, eSpawnWarpgateStalker
		, eSpawnWarpgateSentry
		, eSpawnWarpgateHighTemplar
		, eSpawnWarpgateDarkTemplar

		// Research
		, eCompleteWarpgateResearch

		, eCompleteChronoWarpgateResearch
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

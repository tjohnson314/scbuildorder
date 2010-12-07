#include "stdafx.h"
#include "ProtossEvent.h"

const WCHAR *tostring(EOutputFormat format, CProtossEvent::EEvent event)
{
	switch(event)
	{
		// Buildings
	case CProtossEvent::eSpawnNexus:
		return L"Nexus Completed";
	case CProtossEvent::eSpawnAssimilator:
		return L"Assimilator Completed";
	case CProtossEvent::eSpawnPylon:
		return L"Pylon Completed";
	case CProtossEvent::eSpawnGateway:
		return L"Gateway Completed";
	case CProtossEvent::eSpawnWarpGate:
	case CProtossEvent::eSpawnChronoWarpGate:
		return L"Warp Gate Completed";
	case CProtossEvent::eSpawnForge:
		return L"Forge Completed";
	case CProtossEvent::eSpawnPhotonCannon:
		return L"Photon Cannon Completed";
	case CProtossEvent::eSpawnCyberneticsCore:
		return L"Cybernetics Core Completed";
	case CProtossEvent::eSpawnTwilightCouncil:
		return L"Twilight Council Completed";
	case CProtossEvent::eSpawnTemplarArchives:
		return L"Templar Archives Completed";
	case CProtossEvent::eSpawnDarkShrine:
		return L"Dark Shrine Completed";
	case CProtossEvent::eSpawnRoboticsFacility:
		return L"Robitics Facility Completed";
	case CProtossEvent::eSpawnRoboticsBay:
		return L"Robitics Bay Completed";
	case CProtossEvent::eSpawnStargate:
		return L"Stargate Completed";
	case CProtossEvent::eSpawnFleetBeacon:
		return L"Fleet Beacon Completed";

	case CProtossEvent::eWarpGateOffCooldown:
	case CProtossEvent::eChronoWarpGateOffCooldown:
		return L"Warp Gate Off Cooldown";

	case CProtossEvent::eChronoNexusEnd:
		return L"Nexus Chrono Ended";
	case CProtossEvent::eChronoGatewayEnd:
		return L"Gateway Chrono Ended";
	case CProtossEvent::eChronoWarpGateEnd:
		return L"Warp Gate Chrono Ended";
	case CProtossEvent::eChronoForgeEnd:
		return L"Forge Chrono Ended";
	case CProtossEvent::eChronoCyberneticsCoreEnd:
		return L"Cybernetics Core Chrono Ended";
	case CProtossEvent::eChronoTwilightCouncilEnd:
		return L"Twilight Council Chrono Ended";
	case CProtossEvent::eChronoTemplarArchivesEnd:
		return L"Templar Archives Chrono Ended";
	case CProtossEvent::eChronoRoboticsFacilityEnd:
		return L"Robotics Facility Chrono Ended";
	case CProtossEvent::eChronoRoboticsBayEnd:
		return L"Robitics Bay Chrono Ended";
	case CProtossEvent::eChronoStargateEnd:
		return L"Stargate Chrono Ended";
	case CProtossEvent::eChronoFleetBeaconEnd:
		return L"Fleet Beacon Chrono Ended";
		// Units
	case CProtossEvent::eSpawnProbe:
	case CProtossEvent::eSpawnChronoProbe:
		return L"Probe Spawned";
	case CProtossEvent::eSpawnZealot:
	case CProtossEvent::eSpawnChronoZealot:
	case CProtossEvent::eSpawnWarpGateZealot:
		return L"Zealot Spawned";
	case CProtossEvent::eSpawnStalker:
	case CProtossEvent::eSpawnChronoStalker:
	case CProtossEvent::eSpawnWarpGateStalker:
		return L"Stalker Spawned";
	case CProtossEvent::eSpawnSentry:
	case CProtossEvent::eSpawnChronoSentry:
	case CProtossEvent::eSpawnWarpGateSentry:
		return L"Sentry Spawned";
	case CProtossEvent::eSpawnHighTemplar:
	case CProtossEvent::eSpawnChronoHighTemplar:
	case CProtossEvent::eSpawnWarpGateHighTemplar:
		return L"High Templar Spawned";
	case CProtossEvent::eSpawnDarkTemplar:
	case CProtossEvent::eSpawnChronoDarkTemplar:
	case CProtossEvent::eSpawnWarpGateDarkTemplar:
		return L"Dark Templar Spawned";
	case CProtossEvent::eSpawnArchon:
		return L"Archon Spawned";
	case CProtossEvent::eSpawnWarpPrism:
	case CProtossEvent::eSpawnChronoWarpPrism:
		return L"Warp Prism Spawned";
	case CProtossEvent::eSpawnObserver:
	case CProtossEvent::eSpawnChronoObserver:
		return L"Observer Spawned";
	case CProtossEvent::eSpawnImmortal:
	case CProtossEvent::eSpawnChronoImmortal:
		return L"Immortal Spawned";
	case CProtossEvent::eSpawnColossus:
	case CProtossEvent::eSpawnChronoColossus:
		return L"Colossus Spawned";
	case CProtossEvent::eSpawnPhoenix:
	case CProtossEvent::eSpawnChronoPhoenix:
		return L"Phoenix Spawned";
	case CProtossEvent::eSpawnVoidRay:
	case CProtossEvent::eSpawnChronoVoidRay:
		return L"Void Ray Spawned";
	case CProtossEvent::eSpawnCarrier:
	case CProtossEvent::eSpawnChronoCarrier:
		return L"Carrier Spawned";
	case CProtossEvent::eSpawnMothership:
	case CProtossEvent::eSpawnChronoMothership:
		return L"Mothership Spawned";

		// Research
	case CProtossEvent::eResearchGroundWeapons1Complete:
	case CProtossEvent::eResearchChronoGroundWeapons1Complete:
		return L"Ground Weapons 1 Completed";
	case CProtossEvent::eResearchGroundWeapons2Complete:
	case CProtossEvent::eResearchChronoGroundWeapons2Complete:
		return L"Ground Weapons 2 Completed";
	case CProtossEvent::eResearchGroundWeapons3Complete:
	case CProtossEvent::eResearchChronoGroundWeapons3Complete:
		return L"Ground Weapons 3 Completed";
	case CProtossEvent::eResearchGroundArmor1Complete:
	case CProtossEvent::eResearchChronoGroundArmor1Complete:
		return L"Ground Armor 1 Completed";
	case CProtossEvent::eResearchGroundArmor2Complete:
	case CProtossEvent::eResearchChronoGroundArmor2Complete:
		return L"Ground Armor 2 Completed";
	case CProtossEvent::eResearchGroundArmor3Complete:
	case CProtossEvent::eResearchChronoGroundArmor3Complete:
		return L"Ground Armor 3 Completed";
	case CProtossEvent::eResearchShields1Complete:
	case CProtossEvent::eResearchChronoShields1Complete:
		return L"Shields 1 Completed";
	case CProtossEvent::eResearchShields2Complete:
	case CProtossEvent::eResearchChronoShields2Complete:
		return L"Shields 2 Completed";
	case CProtossEvent::eResearchShields3Complete:
	case CProtossEvent::eResearchChronoShields3Complete:
		return L"Shields 3 Completed";
	case CProtossEvent::eResearchAirWeapons1Complete:
	case CProtossEvent::eResearchChronoAirWeapons1Complete:
		return L"Air Weapons 1 Completed";
	case CProtossEvent::eResearchAirWeapons2Complete:
	case CProtossEvent::eResearchChronoAirWeapons2Complete:
		return L"Air Weapons 2 Completed";
	case CProtossEvent::eResearchAirWeapons3Complete:
	case CProtossEvent::eResearchChronoAirWeapons3Complete:
		return L"Air Weapons 3 Completed";
	case CProtossEvent::eResearchAirArmor1Complete:
	case CProtossEvent::eResearchChronoAirArmor1Complete:
		return L"Air Armor 1 Completed";
	case CProtossEvent::eResearchAirArmor2Complete:
	case CProtossEvent::eResearchChronoAirArmor2Complete:
		return L"Air Armor 2 Completed";
	case CProtossEvent::eResearchAirArmor3Complete:
	case CProtossEvent::eResearchChronoAirArmor3Complete:
		return L"Air Armor 3 Completed";
	case CProtossEvent::eResearchWarpGateTransformationComplete:
	case CProtossEvent::eResearchChronoWarpGateTransformationComplete:
		return L"Warp Gate Transformation Completed";
	case CProtossEvent::eResearchHallucinationComplete:
	case CProtossEvent::eResearchChronoHallucinationComplete:
		return L"Hallucination Completed";
	case CProtossEvent::eResearchChargeComplete:
	case CProtossEvent::eResearchChronoChargeComplete:
		return L"Charge Completed";
	case CProtossEvent::eResearchBlinkComplete:
	case CProtossEvent::eResearchChronoBlinkComplete:
		return L"Blink Completed";
	case CProtossEvent::eResearchPsionicStormComplete:
	case CProtossEvent::eResearchChronoPsionicStormComplete:
		return L"Psionic Storm Completed";
	case CProtossEvent::eResearchKhaydarinAmuletComplete:
	case CProtossEvent::eResearchChronoKhaydarinAmuletComplete:
		return L"Khaydarin Amulet Completed";
	case CProtossEvent::eResearchGraviticDriveComplete:
	case CProtossEvent::eResearchChronoGraviticDriveComplete:
		return L"Gravitic Drive Completed";
	case CProtossEvent::eResearchGraviticBoostersComplete:
	case CProtossEvent::eResearchChronoGraviticBoostersComplete:
		return L"Gravitic Boosters COmpleted";
	case CProtossEvent::eResearchExtendedThermalLanceComplete:
	case CProtossEvent::eResearchChronoExtendedThermalLanceComplete:
		return L"Extended Thermal Lance Completed";
	case CProtossEvent::eResearchFluxVanesComplete:
	case CProtossEvent::eResearchChronoFluxVanesComplete:
		return L"Flux Vanes Completed";
	case CProtossEvent::eResearchGravitonCatapultComplete:
	case CProtossEvent::eResearchChronoGravitonCatapultComplete:
		return L"Graviton Catapult Completed";

		// Misc
	case CProtossEvent::eProbeStartMiningMinerals:
	case CProtossEvent::eProbeStartMiningGas:
		return L""; // Shouldn't be displayed

	case CProtossEvent::eSendScout:
		return L"Scout Sent";
	case CProtossEvent::eKillScout:
		return L"Scout Died";
	case CProtossEvent::eReturnScout:
		return L"Scout Returned";
	}

	return L"";
}

bool DisplayEvent(EOutputFormat format, CProtossEvent::EEvent event)
{
	switch(format)
	{
	case eOutputFormatFull:
		switch(event)
		{
		case CProtossEvent::eProbeStartMiningMinerals:
		case CProtossEvent::eProbeStartMiningGas:
			return false;

		}
		return true;
	}

	return false;
}

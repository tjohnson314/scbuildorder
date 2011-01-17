#include "stdafx.h"
#include "ProtossCommand.h"

const WCHAR *tostring(EOutputFormat format, EProtossCommand command)
{
	switch(format)
	{
	case eOutputFormatSimple:
	case eOutputFormatHaploid:
	case eOutputFormatSC2Gears:
		switch(command)
		{
		case eProtossCommandBuildNexus:
			return L"Nexus";
		case eProtossCommandBuildPylon:
			return L"Pylon";
		case eProtossCommandBuildAssimilator:
			return L"Assimilator";
		case eProtossCommandBuildGateway:
			return L"Gateway";
		case eProtossCommandConvertGatewayToWarpGate:
			return L"Convert Gateway To Warp Gate";
		case eProtossCommandBuildForge:
			return L"Forge";
		case eProtossCommandBuildPhotonCannon:
			return L"Photon Cannon";
		case eProtossCommandBuildCyberneticsCore:
			return L"Cybernetics Core";
		case eProtossCommandBuildTwilightCouncil:
			return L"Twilight Council";
		case eProtossCommandBuildTemplarArchives:
			return L"Templar Archives";
		case eProtossCommandBuildDarkShrine:
			return L"Dark Shrine";
		case eProtossCommandBuildRoboticsFacility:
			return L"Robotics Facility";
		case eProtossCommandBuildRoboticsBay:
			return L"Robotics Bay";
		case eProtossCommandBuildStargate:
			return L"Stargate";
		case eProtossCommandBuildFleetBeacon:
			return L"Fleet Beacon";

		case eProtossCommandBuildProbe:
			return L"Probe";
		case eProtossCommandBuildZealot:
			return L"Zealot";
		case eProtossCommandBuildStalker:
			return L"Stalker";
		case eProtossCommandBuildSentry:
			return L"Sentry";
		case eProtossCommandBuildHighTemplar:
			return L"High Templar";
		case eProtossCommandBuildDarkTemplar:
			return L"Dark Templar";
		case eProtossCommandBuildArchon2HT:
		case eProtossCommandBuildArchon1HT1DT:
		case eProtossCommandBuildArchon2DT:
			return L"Archon";
			return L"Archon";
			return L"Archon";
		case eProtossCommandBuildWarpPrism:
			return L"Warp Prism";
		case eProtossCommandBuildObserver:
			return L"Observer";
		case eProtossCommandBuildImmortal:
			return L"Immortal";
		case eProtossCommandBuildColossus:
			return L"Colossus";
		case eProtossCommandBuildPhoenix:
			return L"Phoenix";
		case eProtossCommandBuildVoidRay:
			return L"Void Ray";
		case eProtossCommandBuildCarrier:
			return L"Carrier";
		case eProtossCommandBuildMothership:
			return L"Mothership";

		case eProtossCommandChronoNexus:
			return L"Chrono Nexus";
		case eProtossCommandChronoGateway:
			return L"Chrono Gateway";
		case eProtossCommandChronoWarpGate:
			return L"Chrono Warp Gate";
		case eProtossCommandChronoForge:
			return L"Chrono Forge";
		case eProtossCommandChronoCyberneticsCore:
			return L"Chrono Cybernetics Core";
		case eProtossCommandChronoTwilightCouncil:
			return L"Chrono Twilight Council";
		case eProtossCommandChronoTemplarArchives:
			return L"Chrono Templar Archives";
		case eProtossCommandChronoRoboticsFacility:
			return L"Chrono Robotics Facility";
		case eProtossCommandChronoRoboticsBay:
			return L"Chrono Robotics Bay";
		case eProtossCommandChronoStargate:
			return L"Chrono Stargate";
		case eProtossCommandChronoFleetBeacon:
			return L"Chrono Fleet Beacon";

		case eProtossCommandResearchGroundWeapons1:
			return L"Ground Weapons 1";
		case eProtossCommandResearchGroundWeapons2:
			return L"Ground Weapons 2";
		case eProtossCommandResearchGroundWeapons3:
			return L"Ground Weapons 3";
		case eProtossCommandResearchGroundArmor1:
			return L"Ground Armor 1";
		case eProtossCommandResearchGroundArmor2:
			return L"Ground Armor 2";
		case eProtossCommandResearchGroundArmor3:
			return L"Ground Armor 3";
		case eProtossCommandResearchShields1:
			return L"Shields 1";
		case eProtossCommandResearchShields2:
			return L"Shields 2";
		case eProtossCommandResearchShields3:
			return L"Shields 3";
		case eProtossCommandResearchAirWeapons1:
			return L"Air Weapons 1";
		case eProtossCommandResearchAirWeapons2:
			return L"Air Weapons 2";
		case eProtossCommandResearchAirWeapons3:
			return L"Air Weapons 3";
		case eProtossCommandResearchAirArmor1:
			return L"Air Armor 1";
		case eProtossCommandResearchAirArmor2:
			return L"Air Armor 2";
		case eProtossCommandResearchAirArmor3:
			return L"Air Armor 3";
		case eProtossCommandResearchWarpGateTransformation:
			return L"Warp Gate Transformation";
		case eProtossCommandResearchHallucination:
			return L"Hallucination";
		case eProtossCommandResearchCharge:
			return L"Charge";
		case eProtossCommandResearchBlink:
			return L"Blink";
		case eProtossCommandResearchPsionicStorm:
			return L"Psionic Storm";
		case eProtossCommandResearchKhaydarinAmulet:
			return L"Khaydarin Amulet";
		case eProtossCommandResearchGraviticDrive:
			return L"Gravitic Drive";
		case eProtossCommandResearchGraviticBoosters:
			return L"Gravitic Boosters";
		case eProtossCommandResearchExtendedThermalLance:
			return L"Extended Thermal Lance";
		case eProtossCommandResearchFluxVanes:
			return L"Flux Vanes";
		case eProtossCommandResearchGravitonCatapult:
			return L"Graviton Catapult";

		case eProtossCommandMoveProbeToGas:
			return L"Move Probe To Gas";
		case eProtossCommandMoveProbeToMinerals:
			return L"Move Probe To Minerals";
		}
		break;

	case eOutputFormatDetailed:
	case eOutputFormatFull:
		switch(command)
		{
		case eProtossCommandBuildNexus:
			return L"Build Nexus";
		case eProtossCommandBuildPylon:
			return L"Build Pylon";
		case eProtossCommandBuildAssimilator:
			return L"Build Assimilator";
		case eProtossCommandBuildGateway:
			return L"Build Gateway";
		case eProtossCommandConvertGatewayToWarpGate:
			return L"Convert Gateway To Warp Gate";
		case eProtossCommandBuildForge:
			return L"Build Forge";
		case eProtossCommandBuildPhotonCannon:
			return L"Build Photon Cannon";
		case eProtossCommandBuildCyberneticsCore:
			return L"Build Cybernetics Core";
		case eProtossCommandBuildTwilightCouncil:
			return L"Build Twilight Council";
		case eProtossCommandBuildTemplarArchives:
			return L"Build Templar Archives";
		case eProtossCommandBuildDarkShrine:
			return L"Build Dark Shrine";
		case eProtossCommandBuildRoboticsFacility:
			return L"Build Robotics Facility";
		case eProtossCommandBuildRoboticsBay:
			return L"Build Robotics Bay";
		case eProtossCommandBuildStargate:
			return L"Build Stargate";
		case eProtossCommandBuildFleetBeacon:
			return L"Build Fleet Beacon";

		case eProtossCommandBuildProbe:
			return L"Build Probe";
		case eProtossCommandBuildZealot:
			return L"Build Zealot";
		case eProtossCommandBuildStalker:
			return L"Build Stalker";
		case eProtossCommandBuildSentry:
			return L"Build Sentry";
		case eProtossCommandBuildHighTemplar:
			return L"Build High Templar";
		case eProtossCommandBuildDarkTemplar:
			return L"Build Dark Templar";
		case eProtossCommandBuildArchon2HT:
			return L"Build Archon (2 HTs)";
		case eProtossCommandBuildArchon1HT1DT:
			return L"Build Archon (1HT 1DT)";
		case eProtossCommandBuildArchon2DT:
			return L"Build Archon (2 DTs)";
		case eProtossCommandBuildWarpPrism:
			return L"Build Warp Prism";
		case eProtossCommandBuildObserver:
			return L"Build Observer";
		case eProtossCommandBuildImmortal:
			return L"Build Immortal";
		case eProtossCommandBuildColossus:
			return L"Build Colossus";
		case eProtossCommandBuildPhoenix:
			return L"Build Phoenix";
		case eProtossCommandBuildVoidRay:
			return L"Build Void Ray";
		case eProtossCommandBuildCarrier:
			return L"Build Carrier";
		case eProtossCommandBuildMothership:
			return L"Build Mothership";

		case eProtossCommandChronoNexus:
			return L"Chrono Nexus";
		case eProtossCommandChronoGateway:
			return L"Chrono Gateway";
		case eProtossCommandChronoWarpGate:
			return L"Chrono Warp Gate";
		case eProtossCommandChronoForge:
			return L"Chrono Forge";
		case eProtossCommandChronoCyberneticsCore:
			return L"Chrono Cybernetics Core";
		case eProtossCommandChronoTwilightCouncil:
			return L"Chrono Twilight Council";
		case eProtossCommandChronoTemplarArchives:
			return L"Chrono Templar Archives";
		case eProtossCommandChronoRoboticsFacility:
			return L"Chrono Robotics Facility";
		case eProtossCommandChronoRoboticsBay:
			return L"Chrono Robotics Bay";
		case eProtossCommandChronoStargate:
			return L"Chrono Stargate";
		case eProtossCommandChronoFleetBeacon:
			return L"Chrono Fleet Beacon";

		case eProtossCommandResearchGroundWeapons1:
			return L"Research Ground Weapons 1";
		case eProtossCommandResearchGroundWeapons2:
			return L"Research Ground Weapons 2";
		case eProtossCommandResearchGroundWeapons3:
			return L"Research Ground Weapons 3";
		case eProtossCommandResearchGroundArmor1:
			return L"Research Ground Armor 1";
		case eProtossCommandResearchGroundArmor2:
			return L"Research Ground Armor 2";
		case eProtossCommandResearchGroundArmor3:
			return L"Research Ground Armor 3";
		case eProtossCommandResearchShields1:
			return L"Research Shields 1";
		case eProtossCommandResearchShields2:
			return L"Research Shields 2";
		case eProtossCommandResearchShields3:
			return L"Research Shields 3";
		case eProtossCommandResearchAirWeapons1:
			return L"Research Air Weapons 1";
		case eProtossCommandResearchAirWeapons2:
			return L"Research Air Weapons 2";
		case eProtossCommandResearchAirWeapons3:
			return L"Research Air Weapons 3";
		case eProtossCommandResearchAirArmor1:
			return L"Research Air Armor 1";
		case eProtossCommandResearchAirArmor2:
			return L"Research Air Armor 2";
		case eProtossCommandResearchAirArmor3:
			return L"Research Air Armor 3";
		case eProtossCommandResearchWarpGateTransformation:
			return L"Research Warp Gate Transformation";
		case eProtossCommandResearchHallucination:
			return L"Research Hallucination";
		case eProtossCommandResearchCharge:
			return L"Research Charge";
		case eProtossCommandResearchBlink:
			return L"Research Blink";
		case eProtossCommandResearchPsionicStorm:
			return L"Research Psionic Storm";
		case eProtossCommandResearchKhaydarinAmulet:
			return L"Research Khaydarin Amulet";
		case eProtossCommandResearchGraviticDrive:
			return L"Research Gravitic Drive";
		case eProtossCommandResearchGraviticBoosters:
			return L"Research Gravitic Boosters";
		case eProtossCommandResearchExtendedThermalLance:
			return L"Research Extended Thermal Lance";
		case eProtossCommandResearchFluxVanes:
			return L"Research Flux Vanes";
		case eProtossCommandResearchGravitonCatapult:
			return L"Research Graviton Catapult";

		case eProtossCommandMoveProbeToGas:
			return L"Move Probe To Gas";
		case eProtossCommandMoveProbeToMinerals:
			return L"Move Probe To Minerals";
		}
		break;

	case eOutputFormatYABOT:
		// YABOT format codes provided by Turtle36 - thanks!!
		switch(command)
		{
		case eProtossCommandBuildNexus:
			return L"0 25 0";
		case eProtossCommandBuildPylon:
			return L"0 27 0";
		case eProtossCommandBuildAssimilator:
			return L"0 19 0";
		case eProtossCommandBuildGateway:
			return L"0 24 0";
		case eProtossCommandConvertGatewayToWarpGate:
			return L"2 2 0";
		case eProtossCommandBuildForge:
			return L"0 23 0";
		case eProtossCommandBuildPhotonCannon:
			return L"0 26 0";
		case eProtossCommandBuildCyberneticsCore:
			return L"0 20 0";
		case eProtossCommandBuildTwilightCouncil:
			return L"0 32 0";
		case eProtossCommandBuildTemplarArchives:
			return L"0 31 0";
		case eProtossCommandBuildDarkShrine:
			return L"0 21 0";
		case eProtossCommandBuildRoboticsFacility:
			return L"0 29 0";
		case eProtossCommandBuildRoboticsBay:
			return L"0 28 0";
		case eProtossCommandBuildStargate:
			return L"0 30 0";
		case eProtossCommandBuildFleetBeacon:
			return L"0 22 0";

		case eProtossCommandBuildProbe:
			return L"1 22 0";
		case eProtossCommandBuildZealot:
			return L"1 26 0";
		case eProtossCommandBuildStalker:
			return L"1 24 0";
		case eProtossCommandBuildSentry:
			return L"1 23 0";
		case eProtossCommandBuildHighTemplar:
			return L"1 17 0";
		case eProtossCommandBuildDarkTemplar:
			return L"1 16 0";
		case eProtossCommandBuildArchon2HT:
		case eProtossCommandBuildArchon1HT1DT:
		case eProtossCommandBuildArchon2DT:
			return L"1 13 0";
		case eProtossCommandBuildWarpPrism:
			return L"1 39 0";
		case eProtossCommandBuildObserver:
			return L"1 20 0";
		case eProtossCommandBuildImmortal:
			return L"1 18 0";
		case eProtossCommandBuildColossus:
			return L"1 15 0";
		case eProtossCommandBuildPhoenix:
			return L"1 21 0";
		case eProtossCommandBuildVoidRay:
			return L"1 25 0";
		case eProtossCommandBuildCarrier:
			return L"1 14 0";
		case eProtossCommandBuildMothership:
			return L"1 19 0";

		case eProtossCommandChronoNexus:
		case eProtossCommandChronoGateway:
		case eProtossCommandChronoWarpGate:
		case eProtossCommandChronoForge:
		case eProtossCommandChronoCyberneticsCore:
		case eProtossCommandChronoTwilightCouncil:
		case eProtossCommandChronoTemplarArchives:
		case eProtossCommandChronoRoboticsFacility:
		case eProtossCommandChronoRoboticsBay:
		case eProtossCommandChronoStargate:
		case eProtossCommandChronoFleetBeacon:
			return L"";

		case eProtossCommandResearchGroundWeapons1:
			return L"3 19 0";
		case eProtossCommandResearchGroundWeapons2:
			return L"3 19 0";
		case eProtossCommandResearchGroundWeapons3:
			return L"3 19 0";
		case eProtossCommandResearchGroundArmor1:
			return L"3 18 0";
		case eProtossCommandResearchGroundArmor2:
			return L"3 18 0";
		case eProtossCommandResearchGroundArmor3:
			return L"3 18 0";
		case eProtossCommandResearchShields1:
			return L"3 22 0";
		case eProtossCommandResearchShields2:
			return L"3 22 0";
		case eProtossCommandResearchShields3:
			return L"3 22 0";
		case eProtossCommandResearchAirWeapons1:
			return L"3 21 0";
		case eProtossCommandResearchAirWeapons2:
			return L"3 21 0";
		case eProtossCommandResearchAirWeapons3:
			return L"3 21 0";
		case eProtossCommandResearchAirArmor1:
			return L"3 20 0";
		case eProtossCommandResearchAirArmor2:
			return L"3 20 0";
		case eProtossCommandResearchAirArmor3:
			return L"3 20 0";
		case eProtossCommandResearchWarpGateTransformation:
			return L"3 26 0";
		case eProtossCommandResearchHallucination:
			return L"3 23 0";
		case eProtossCommandResearchCharge:
			return L"3 27 0";
		case eProtossCommandResearchBlink:
			return L"3 25 0";
		case eProtossCommandResearchPsionicStorm:
			return L"3 24 0";
		case eProtossCommandResearchKhaydarinAmulet:
			return L"3 48 0";
		case eProtossCommandResearchGraviticDrive:
			return L"";
		case eProtossCommandResearchGraviticBoosters:
			return L"";
		case eProtossCommandResearchExtendedThermalLance:
			return L"3 47 0";
		case eProtossCommandResearchFluxVanes:
			return L"";
		case eProtossCommandResearchGravitonCatapult:
			return L"";

		case eProtossCommandMoveProbeToGas:
		case eProtossCommandMoveProbeToMinerals:
			return L"";
		}
		break;

	}
	
	return L"";
}

bool DisplayCommand(EOutputFormat format, EProtossCommand command)
{
	switch(format)
	{
	case eOutputFormatSimple:
		return eProtossCommandBuildProbe != command;
	case eOutputFormatDetailed:
		return true;
	case eOutputFormatFull:
		return true;
	case eOutputFormatHaploid:
		return eProtossCommandBuildProbe != command;
	case eOutputFormatYABOT:
		switch(command)
		{
		case eProtossCommandBuildProbe:
		case eProtossCommandMoveProbeToGas:
		case eProtossCommandMoveProbeToMinerals:

		case eProtossCommandChronoNexus:
		case eProtossCommandChronoGateway:
		case eProtossCommandChronoWarpGate:
		case eProtossCommandChronoForge:
		case eProtossCommandChronoCyberneticsCore:
		case eProtossCommandChronoTwilightCouncil:
		case eProtossCommandChronoTemplarArchives:
		case eProtossCommandChronoRoboticsFacility:
		case eProtossCommandChronoRoboticsBay:
		case eProtossCommandChronoStargate:
		case eProtossCommandChronoFleetBeacon:

		case eProtossCommandResearchGraviticDrive:
		case eProtossCommandResearchGraviticBoosters:
		case eProtossCommandResearchFluxVanes:
		case eProtossCommandResearchGravitonCatapult:
			return false;
		}

		return true;
	case eOutputFormatSC2Gears:
		return eProtossCommandBuildProbe != command;
	}

	return false;
}

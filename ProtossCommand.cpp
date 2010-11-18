#include "stdafx.h"
#include "ProtossCommand.h"

const WCHAR *tostring(EProtossCommand command)
{
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
	
	return L"";
}

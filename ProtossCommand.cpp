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
	case eProtossCommandConvertGatewayToWarpgate:
		return L"Convert Gateway To Warpgate";
	case eProtossCommandBuildForge:
		return L"Build Forge";
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
	case eProtossCommandChronoWarpgate:
		return L"Chrono Warpgate";
	case eProtossCommandChronoForge:
		return L"Chrono Forge";
	case eProtossCommandChronoCyberneticsCore:
		return L"Chrono Cybernetics Core";
	case eProtossCommandChronoTwilightCouncil:
		return L"Chrono Twilight Council";
	case eProtossCommandChronoTemplarArchives:
		return L"Chrono Twilight Archives";
	case eProtossCommandChronoRoboticsFacility:
		return L"Chrono Robotics Facility";
	case eProtossCommandChronoRoboticsBay:
		return L"Chrono Robotics Bay";
	case eProtossCommandChronoStargate:
		return L"Chrono Stargate";
	case eProtossCommandChronoFleetBeacon:
		return L"Chrono Fleet Beacon";

	case eProtossCommandResearchWarpgate:
		return L"Research Warpgate";

	case eProtossCommandMoveProbeToGas:
		return L"Move Probe To Gas";
	case eProtossCommandMoveProbeToMinerals:
		return L"Move Probe To Minerals";
	}
	
	return L"";
}

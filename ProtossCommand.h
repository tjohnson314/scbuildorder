#pragma once

#include <vector>
#include <iostream>
#include "Vector.h"

enum EProtossCommand
{
	eProtossCommandNone = 0
	, eProtossCommandBuildNexus
	, eProtossCommandBuildPylon
	, eProtossCommandBuildAssimilator
	, eProtossCommandBuildGateway
	, eProtossCommandConvertGatewayToWarpgate
	, eProtossCommandBuildForge
	, eProtossCommandBuildCyberneticsCore
	, eProtossCommandBuildTwilightCouncil
	, eProtossCommandBuildTemplarArchives
	, eProtossCommandBuildDarkShrine
	, eProtossCommandBuildRoboticsFacility
	, eProtossCommandBuildRoboticsBay
	, eProtossCommandBuildStargate
	, eProtossCommandBuildFleetBeacon

	, eProtossCommandChronoNexus
	, eProtossCommandChronoGateway
	, eProtossCommandChronoWarpgate
	, eProtossCommandChronoForge
	, eProtossCommandChronoCyberneticsCore
	, eProtossCommandChronoTwilightCouncil
	, eProtossCommandChronoTemplarArchives
	, eProtossCommandChronoDarkShrine
	, eProtossCommandChronoRoboticsFacility
	, eProtossCommandChronoRoboticsBay
	, eProtossCommandChronoStargate
	, eProtossCommandChronoFleetBeacon

	, eProtossCommandBuildProbe
	, eProtossCommandBuildZealot
	, eProtossCommandBuildStalker
	, eProtossCommandBuildSentry
	, eProtossCommandBuildHighTemplar
	, eProtossCommandBuildDarkTemplar
	, eProtossCommandBuildWarpPrism
	, eProtossCommandBuildObserver
	, eProtossCommandBuildImmortal
	, eProtossCommandBuildColossus
	, eProtossCommandBuildPhoenix
	, eProtossCommandBuildVoidRay
	, eProtossCommandBuildCarrier
	, eProtossCommandBuildMothership

	, eProtossCommandResearchWarpgate

	, eProtossCommandMoveProbeToGas
	, eProtossCommandMoveProbeToMinerals
};

const WCHAR *tostring(EProtossCommand command);

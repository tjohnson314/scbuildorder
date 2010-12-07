#pragma once

#include <vector>
#include <iostream>
#include "Vector.h"
#include "OutputFormat.h"

enum EProtossCommand
{
	eProtossCommandNone = 0

	, eProtossCommandBuildNexus
	, eProtossCommandBuildPylon
	, eProtossCommandBuildAssimilator
	, eProtossCommandBuildGateway
	, eProtossCommandConvertGatewayToWarpGate
	, eProtossCommandBuildForge
	, eProtossCommandBuildPhotonCannon
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
	, eProtossCommandChronoWarpGate
	, eProtossCommandChronoForge
	, eProtossCommandChronoCyberneticsCore
	, eProtossCommandChronoTwilightCouncil
	, eProtossCommandChronoTemplarArchives
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
	, eProtossCommandBuildArchon2HT
	, eProtossCommandBuildArchon1HT1DT
	, eProtossCommandBuildArchon2DT
	, eProtossCommandBuildWarpPrism
	, eProtossCommandBuildObserver
	, eProtossCommandBuildImmortal
	, eProtossCommandBuildColossus
	, eProtossCommandBuildPhoenix
	, eProtossCommandBuildVoidRay
	, eProtossCommandBuildCarrier
	, eProtossCommandBuildMothership

	, eProtossCommandResearchGroundWeapons1
	, eProtossCommandResearchGroundWeapons2
	, eProtossCommandResearchGroundWeapons3
	, eProtossCommandResearchGroundArmor1
	, eProtossCommandResearchGroundArmor2
	, eProtossCommandResearchGroundArmor3
	, eProtossCommandResearchShields1
	, eProtossCommandResearchShields2
	, eProtossCommandResearchShields3
	, eProtossCommandResearchAirWeapons1
	, eProtossCommandResearchAirWeapons2
	, eProtossCommandResearchAirWeapons3
	, eProtossCommandResearchAirArmor1
	, eProtossCommandResearchAirArmor2
	, eProtossCommandResearchAirArmor3
	, eProtossCommandResearchWarpGateTransformation
	, eProtossCommandResearchHallucination
	, eProtossCommandResearchCharge
	, eProtossCommandResearchBlink
	, eProtossCommandResearchPsionicStorm
	, eProtossCommandResearchKhaydarinAmulet
	, eProtossCommandResearchGraviticDrive
	, eProtossCommandResearchGraviticBoosters
	, eProtossCommandResearchExtendedThermalLance
	, eProtossCommandResearchFluxVanes
	, eProtossCommandResearchGravitonCatapult

	, eProtossCommandMoveProbeToGas
	, eProtossCommandMoveProbeToMinerals
};

const WCHAR *tostring(EOutputFormat format, EProtossCommand command);

inline bool DisplayCommand(EOutputFormat format, EProtossCommand command)
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
		return eProtossCommandBuildProbe != command;
	case eOutputFormatSC2Gears:
		return eProtossCommandBuildProbe != command;
	}

	return false;
}

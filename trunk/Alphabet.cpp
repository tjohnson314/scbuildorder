#include "stdafx.h"
#include "Alphabet.h"

void GetAlphabet(CVector<EProtossCommand> &vecAlphabet)
{
	vecAlphabet.push_back(eProtossCommandBuildNexus);
	vecAlphabet.push_back(eProtossCommandBuildPylon);
	vecAlphabet.push_back(eProtossCommandBuildAssimilator);
	vecAlphabet.push_back(eProtossCommandBuildGateway);
	vecAlphabet.push_back(eProtossCommandConvertGatewayToWarpgate);
	vecAlphabet.push_back(eProtossCommandBuildForge);
	vecAlphabet.push_back(eProtossCommandBuildCyberneticsCore);
	vecAlphabet.push_back(eProtossCommandBuildTwilightCouncil);
	vecAlphabet.push_back(eProtossCommandBuildTemplarArchives);
	vecAlphabet.push_back(eProtossCommandBuildDarkShrine);
	vecAlphabet.push_back(eProtossCommandBuildRoboticsFacility);
	vecAlphabet.push_back(eProtossCommandBuildRoboticsBay);
	vecAlphabet.push_back(eProtossCommandBuildStargate);
	vecAlphabet.push_back(eProtossCommandBuildFleetBeacon);

	vecAlphabet.push_back(eProtossCommandChronoNexus);
	vecAlphabet.push_back(eProtossCommandChronoGateway);
	vecAlphabet.push_back(eProtossCommandChronoWarpgate);
	vecAlphabet.push_back(eProtossCommandChronoForge);
	vecAlphabet.push_back(eProtossCommandChronoCyberneticsCore);
	vecAlphabet.push_back(eProtossCommandChronoTwilightCouncil);
	vecAlphabet.push_back(eProtossCommandChronoTemplarArchives);
	//vecAlphabet.push_back(eProtossCommandChronoDarkShrine);
	vecAlphabet.push_back(eProtossCommandChronoRoboticsFacility);
	vecAlphabet.push_back(eProtossCommandChronoRoboticsBay);
	vecAlphabet.push_back(eProtossCommandChronoStargate);
	vecAlphabet.push_back(eProtossCommandChronoFleetBeacon);

	vecAlphabet.push_back(eProtossCommandBuildProbe);
	vecAlphabet.push_back(eProtossCommandBuildZealot);
	vecAlphabet.push_back(eProtossCommandBuildStalker);
	vecAlphabet.push_back(eProtossCommandBuildSentry);
	vecAlphabet.push_back(eProtossCommandBuildHighTemplar);
	vecAlphabet.push_back(eProtossCommandBuildDarkTemplar);
	vecAlphabet.push_back(eProtossCommandBuildWarpPrism);
	vecAlphabet.push_back(eProtossCommandBuildObserver);
	vecAlphabet.push_back(eProtossCommandBuildImmortal);
	vecAlphabet.push_back(eProtossCommandBuildColossus);
	vecAlphabet.push_back(eProtossCommandBuildPhoenix);
	vecAlphabet.push_back(eProtossCommandBuildVoidRay);
	vecAlphabet.push_back(eProtossCommandBuildCarrier);
	vecAlphabet.push_back(eProtossCommandBuildMothership);

	vecAlphabet.push_back(eProtossCommandResearchWarpgate);

	vecAlphabet.push_back(eProtossCommandMoveProbeToGas);
	vecAlphabet.push_back(eProtossCommandMoveProbeToMinerals);
}

void GetAlphabet(CVector<EZergCommand> &vecAlphabet)
{
	vecAlphabet.push_back(eZergCommandBuildHatchery);
	vecAlphabet.push_back(eZergCommandBuildExtractor);
	vecAlphabet.push_back(eZergCommandBuildSpawningPool);
	vecAlphabet.push_back(eZergCommandExpandCreepTumour);
	vecAlphabet.push_back(eZergCommandBuildEvolutionChamber);
	vecAlphabet.push_back(eZergCommandBuildSpineCrawler);
	vecAlphabet.push_back(eZergCommandBuildSporeCrawler);
	vecAlphabet.push_back(eZergCommandBuildRoachWarren);
	vecAlphabet.push_back(eZergCommandBuildLair);
	vecAlphabet.push_back(eZergCommandBuildHydraliskDen);
	vecAlphabet.push_back(eZergCommandBuildBanelingNest);
	vecAlphabet.push_back(eZergCommandBuildSpire);
	vecAlphabet.push_back(eZergCommandBuildInfestationPit);
	vecAlphabet.push_back(eZergCommandBuildNydusNetwork);
	vecAlphabet.push_back(eZergCommandBuildHive);
	vecAlphabet.push_back(eZergCommandBuildUltraliskCavern);
	vecAlphabet.push_back(eZergCommandBuildGreaterSpire);

	vecAlphabet.push_back(eZergCommandCancelExtractor);

	vecAlphabet.push_back(eZergCommandBuildDrone);
	vecAlphabet.push_back(eZergCommandBuildOverlord);
	vecAlphabet.push_back(eZergCommandBuildQueen);
	vecAlphabet.push_back(eZergCommandBuildZergling);
	vecAlphabet.push_back(eZergCommandBuildRoach);
	vecAlphabet.push_back(eZergCommandBuildHydralisk);
	vecAlphabet.push_back(eZergCommandBuildBaneling);
	vecAlphabet.push_back(eZergCommandBuildOverseer);
	vecAlphabet.push_back(eZergCommandBuildInfestor);
	vecAlphabet.push_back(eZergCommandBuildMutalisk);
	vecAlphabet.push_back(eZergCommandBuildCorruptor);
	vecAlphabet.push_back(eZergCommandBuildUltralisk);
	vecAlphabet.push_back(eZergCommandBuildBroodlord);

	vecAlphabet.push_back(eZergCommandExtractorTrickDrone);

	vecAlphabet.push_back(eZergCommandMoveDroneToGas);
	vecAlphabet.push_back(eZergCommandMoveDroneToMinerals);

	vecAlphabet.push_back(eZergCommandQueenSpawnLarva);
}


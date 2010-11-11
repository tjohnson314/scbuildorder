#include "stdafx.h"
#include "ZergCommand.h"

const WCHAR *tostring(EZergCommand command)
{
	switch(command)
	{
	case eZergCommandBuildHatchery:
		return L"Build Hatchery";
	case eZergCommandBuildExtractor:
		return L"Build Extractor";
	case eZergCommandBuildSpawningPool:
		return L"Build Spawning Pool";
	case eZergCommandExpandCreepTumour:
		return L"Expand Creep Tumour";
	case eZergCommandBuildEvolutionChamber:
		return L"Build Evolution Chamber";
	case eZergCommandBuildSpineCrawler:
		return L"Build Spine Crawler";
	case eZergCommandBuildSporeCrawler:
		return L"Build Spore Crawler";
	case eZergCommandBuildRoachWarren:
		return L"Build Roach Warren";
	case eZergCommandBuildLair:
		return L"Build Lair";
	case eZergCommandBuildHydraliskDen:
		return L"Build Hydralisk Den";
	case eZergCommandBuildBanelingNest:
		return L"Build Baneling Nest";
	case eZergCommandBuildSpire:
		return L"Build Spire";
	case eZergCommandBuildInfestationPit:
		return L"Build Infestation Pit";
	case eZergCommandBuildNydusNetwork:
		return L"Build Nydus Network";
	case eZergCommandBuildHive:
		return L"Build Hive";
	case eZergCommandBuildUltraliskCavern:
		return L"Build Ultralisk Cavern";
	case eZergCommandBuildGreaterSpire:
		return L"Build Greater Spire";

	case eZergCommandCancelExtractor:
		return L"Cancel Extractor";

	case eZergCommandBuildDrone:
		return L"Build Drone";
	case eZergCommandBuildOverlord:
		return L"Build Overlord";
	case eZergCommandBuildQueen:
		return L"Build Queen";
	case eZergCommandBuildZergling:
		return L"Build Zergling";
	case eZergCommandBuildRoach:
		return L"Build Roach";
	case eZergCommandBuildBaneling:
		return L"Build Baneling";
	case eZergCommandBuildHydralisk:
		return L"Build Hydralisk";
	case eZergCommandBuildOverseer:
		return L"Build Overseer";
	case eZergCommandBuildInfestor:
		return L"Build Infestor";
	case eZergCommandBuildMutalisk:
		return L"Build Mutalisk";
	case eZergCommandBuildCorruptor:
		return L"Build Corruptor";
	case eZergCommandBuildUltralisk:
		return L"Build Ultralisk";
	case eZergCommandBuildBroodlord:
		return L"Build Broodlord";

	case eZergCommandExtractorTrickDrone:
		return L"Extractor Trick Drone";

	case eZergCommandQueenSpawnLarva:
		return L"Queen Spawn Larva";

	case eZergCommandMoveDroneToGas:
		return L"Move Drone To Gas";
	case eZergCommandMoveDroneToMinerals:
		return L"Move Drone To Minerals";
	}
	
	return L"";
}

#include "stdafx.h"
#include "ZergCommand.h"

const WCHAR *tostring(EOutputFormat format, EZergCommand command)
{
	switch(format)
	{
	case eOutputFormatSimple:
	case eOutputFormatHaploid:
	case eOutputFormatSC2Gears:
		switch(command)
		{
		case eZergCommandBuildHatchery:
			return L"Hatchery";
		case eZergCommandBuildExtractor:
			return L"Extractor";
		case eZergCommandBuildSpawningPool:
			return L"Spawning Pool";
		case eZergCommandExpandCreepTumor:
			return L"Expand Creep Tumor";
		case eZergCommandBuildEvolutionChamber:
			return L"Evolution Chamber";
		case eZergCommandBuildSpineCrawler:
			return L"Spine Crawler";
		case eZergCommandBuildSporeCrawler:
			return L"Spore Crawler";
		case eZergCommandBuildRoachWarren:
			return L"Roach Warren";
		case eZergCommandBuildLair:
			return L"Lair";
		case eZergCommandBuildHydraliskDen:
			return L"Hydralisk Den";
		case eZergCommandBuildBanelingNest:
			return L"Baneling Nest";
		case eZergCommandBuildSpire:
			return L"Spire";
		case eZergCommandBuildInfestationPit:
			return L"Infestation Pit";
		case eZergCommandBuildNydusNetwork:
			return L"Nydus Network";
		case eZergCommandBuildHive:
			return L"Hive";
		case eZergCommandBuildUltraliskCavern:
			return L"Ultralisk Cavern";
		case eZergCommandBuildGreaterSpire:
			return L"Greater Spire";

		case eZergCommandCancelExtractor:
			return L"Cancel Extractor";

		case eZergCommandBuildDrone:
			return L"Drone";
		case eZergCommandBuildOverlord:
			return L"Overlord";
		case eZergCommandBuildQueen:
			return L"Queen";
		case eZergCommandBuildZergling:
			return L"Zergling";
		case eZergCommandBuildRoach:
			return L"Roach";
		case eZergCommandBuildBaneling:
			return L"Baneling";
		case eZergCommandBuildHydralisk:
			return L"Hydralisk";
		case eZergCommandBuildOverseer:
			return L"Overseer";
		case eZergCommandBuildInfestor:
			return L"Infestor";
		case eZergCommandBuildMutalisk:
			return L"Mutalisk";
		case eZergCommandBuildCorruptor:
			return L"Corruptor";
		case eZergCommandBuildUltralisk:
			return L"Ultralisk";
		case eZergCommandBuildBroodlord:
			return L"Broodlord";

		case eZergCommandExtractorTrickDrone:
			return L"Extractor Trick";

		case eZergCommandQueenSpawnCreepTumor:
			return L"Creep Tumor";
		case eZergCommandQueenSpawnLarvae:
			return L"Spawn Larvae";

		case eZergCommandResearchAdrenalGlands:
			return L"Adrenal Glands";
		case eZergCommandResearchMetabolicBoost:
			return L"Metabolic Boost";
		case eZergCommandResearchMeleeAttacks1:
			return L"Melee Attacks 1";
		case eZergCommandResearchMeleeAttacks2:
			return L"Melee Attacks 2";
		case eZergCommandResearchMeleeAttacks3:
			return L"Melee Attacks 3";
		case eZergCommandResearchGroundCarapace1:
			return L"Ground Carapace 1";
		case eZergCommandResearchGroundCarapace2:
			return L"Ground Carapace 2";
		case eZergCommandResearchGroundCarapace3:
			return L"Ground Carapace 3";
		case eZergCommandResearchMissileAttacks1:
			return L"Missile Attacks 1";
		case eZergCommandResearchMissileAttacks2:
			return L"Missile Attacks 2";
		case eZergCommandResearchMissileAttacks3:
			return L"Missile Attacks 3";
		case eZergCommandResearchGlialReconstitution:
			return L"Glial Reconstitution";
		case eZergCommandResearchTunnelingClaws:
			return L"Tunneling Claws";
		case eZergCommandResearchCentrifugalHooks:
			return L"Centrifugal Hooks";
		case eZergCommandResearchBurrowAtHatchery:
		case eZergCommandResearchBurrowAtLair:
		case eZergCommandResearchBurrowAtHive:
			return L"Burrow";
		case eZergCommandResearchPneumaticCarapaceAtHatchery:
		case eZergCommandResearchPneumaticCarapaceAtLair:
		case eZergCommandResearchPneumaticCarapaceAtHive:
			return L"Pneumatic Carapace";
		case eZergCommandResearchVentralSacsAtHatchery:
		case eZergCommandResearchVentralSacsAtLair:
		case eZergCommandResearchVentralSacsAtHive:
			return L"Ventral Sacs";
		case eZergCommandResearchGroovedSpines:
			return L"Grooved Spines";
		case eZergCommandResearchPathogenGlands:
			return L"Pathogen Glands";
		case eZergCommandResearchNeuralParasite:
			return L"Neural Parasite";
		case eZergCommandResearchFlyerAttacks1:
			return L"Flyer Attacks 1";
		case eZergCommandResearchFlyerAttacks2:
			return L"Flyer Attacks 2";
		case eZergCommandResearchFlyerAttacks3:
			return L"Flyer Attacks 3";
		case eZergCommandResearchFlyerCarapace1:
			return L"Flyer Carapace 1";
		case eZergCommandResearchFlyerCarapace2:
			return L"Flyer Carapace 2";
		case eZergCommandResearchFlyerCarapace3:
			return L"Flyer Carapace 3";
		case eZergCommandResearchChitinousPlating:
			return L"Chitinous Plating";

		case eZergCommandMoveDroneToGas:
			return L"Move Drone To Gas";
		case eZergCommandMoveDroneToMinerals:
			return L"Move Drone To Minerals";
		}

		break;

	case eOutputFormatDetailed:
	case eOutputFormatFull:
		switch(command)
		{
		case eZergCommandBuildHatchery:
			return L"Build Hatchery";
		case eZergCommandBuildExtractor:
			return L"Build Extractor";
		case eZergCommandBuildSpawningPool:
			return L"Build Spawning Pool";
		case eZergCommandExpandCreepTumor:
			return L"Expand Creep Tumor";
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

		case eZergCommandQueenSpawnCreepTumor:
			return L"Queen Spawn Creep Tumor";
		case eZergCommandQueenSpawnLarvae:
			return L"Queen Spawn Larvae";

		case eZergCommandResearchAdrenalGlands:
			return L"Research Adrenal Glands";
		case eZergCommandResearchMetabolicBoost:
			return L"Research Metabolic Boost";
		case eZergCommandResearchMeleeAttacks1:
			return L"Research Melee Attacks 1";
		case eZergCommandResearchMeleeAttacks2:
			return L"Research Melee Attacks 2";
		case eZergCommandResearchMeleeAttacks3:
			return L"Research Melee Attacks 3";
		case eZergCommandResearchGroundCarapace1:
			return L"Research Ground Carapace 1";
		case eZergCommandResearchGroundCarapace2:
			return L"Research Ground Carapace 2";
		case eZergCommandResearchGroundCarapace3:
			return L"Research Ground Carapace 3";
		case eZergCommandResearchMissileAttacks1:
			return L"Research Missile Attacks 1";
		case eZergCommandResearchMissileAttacks2:
			return L"Research Missile Attacks 2";
		case eZergCommandResearchMissileAttacks3:
			return L"Research Missile Attacks 3";
		case eZergCommandResearchGlialReconstitution:
			return L"Research Glial Reconstitution";
		case eZergCommandResearchTunnelingClaws:
			return L"Research Tunneling Claws";
		case eZergCommandResearchCentrifugalHooks:
			return L"Research Centrifugal Hooks";
		case eZergCommandResearchBurrowAtHatchery:
			return L"Research Burrow (at Hatchery)";
		case eZergCommandResearchBurrowAtLair:
			return L"Research Burrow (at Lair)";
		case eZergCommandResearchBurrowAtHive:
			return L"Research Burrow (at Hive)";
		case eZergCommandResearchPneumaticCarapaceAtHatchery:
			return L"Research Pneumatic Carapace (at Hatchery)";
		case eZergCommandResearchPneumaticCarapaceAtLair:
			return L"Research Pneumatic Carapace (at Lair)";
		case eZergCommandResearchPneumaticCarapaceAtHive:
			return L"Research Pneumatic Carapace (at Hive)";
		case eZergCommandResearchVentralSacsAtHatchery:
			return L"Research Ventral Sacs (at Hatchery)";
		case eZergCommandResearchVentralSacsAtLair:
			return L"Research Ventral Sacs (at Lair)";
		case eZergCommandResearchVentralSacsAtHive:
			return L"Research Ventral Sacs (at Hive)";
		case eZergCommandResearchGroovedSpines:
			return L"Research Grooved Spines";
		case eZergCommandResearchPathogenGlands:
			return L"Research Pathogen Glands";
		case eZergCommandResearchNeuralParasite:
			return L"Research Neural Parasite";
		case eZergCommandResearchFlyerAttacks1:
			return L"Research Flyer Attacks 1";
		case eZergCommandResearchFlyerAttacks2:
			return L"Research Flyer Attacks 2";
		case eZergCommandResearchFlyerAttacks3:
			return L"Research Flyer Attacks 3";
		case eZergCommandResearchFlyerCarapace1:
			return L"Research Flyer Carapace 1";
		case eZergCommandResearchFlyerCarapace2:
			return L"Research Flyer Carapace 2";
		case eZergCommandResearchFlyerCarapace3:
			return L"Research Flyer Carapace 3";
		case eZergCommandResearchChitinousPlating:
			return L"Research Chitinous Plating";

		case eZergCommandMoveDroneToGas:
			return L"Move Drone To Gas";
		case eZergCommandMoveDroneToMinerals:
			return L"Move Drone To Minerals";
		}
		break;

	case eOutputFormatYABOT:
		switch(command)
		{
		case eZergCommandBuildHatchery:
			return L"0 36 0";
		case eZergCommandBuildExtractor:
			return L"0 35 0";
		case eZergCommandBuildSpawningPool:
			return L"0 41 0";
		case eZergCommandExpandCreepTumor:
			return L"0 46 0";
		case eZergCommandBuildEvolutionChamber:
			return L"0 34 0";
		case eZergCommandBuildSpineCrawler:
			return L"0 42 0";
		case eZergCommandBuildSporeCrawler:
			return L"0 44 0";
		case eZergCommandBuildRoachWarren:
			return L"0 40 0";
		case eZergCommandBuildLair:
			return L"2 3 0";
		case eZergCommandBuildHydraliskDen:
			return L"0 37 0";
		case eZergCommandBuildBanelingNest:
			return L"0 33 0";
		case eZergCommandBuildSpire:
			return L"0 43 0";
		case eZergCommandBuildInfestationPit:
			return L"0 38 0";
		case eZergCommandBuildNydusNetwork:
			return L"0 39 0";
		case eZergCommandBuildHive:
			return L"2 4 0";
		case eZergCommandBuildUltraliskCavern:
			return L"0 45 0";
		case eZergCommandBuildGreaterSpire:
			return L"2 5 0";

		case eZergCommandCancelExtractor:
			return L"0 35 1";

		case eZergCommandBuildDrone:
			return L"1 28 0";
		case eZergCommandBuildOverlord:
			return L"1 31 0";
		case eZergCommandBuildQueen:
			return L"1 32 0";
		case eZergCommandBuildZergling:
			return L"1 35 0";
		case eZergCommandBuildRoach:
			return L"1 33 0";
		case eZergCommandBuildBaneling:
			return L"2 7 0";
		case eZergCommandBuildHydralisk:
			return L"1 29 0";
		case eZergCommandBuildOverseer:
			return L"2 8 0";
		case eZergCommandBuildInfestor:
			return L"1 38 0";
		case eZergCommandBuildMutalisk:
			return L"1 30 0";
		case eZergCommandBuildCorruptor:
			return L"1 27 0";
		case eZergCommandBuildUltralisk:
			return L"1 34 0";
		case eZergCommandBuildBroodlord:
			return L"2 6 0";

		case eZergCommandExtractorTrickDrone:
			return L"0 35 1";

		case eZergCommandQueenSpawnCreepTumor:
			return L"1 46 0";
		case eZergCommandQueenSpawnLarvae:
			return L"";

		case eZergCommandResearchAdrenalGlands:
			return L"3 41 0";
		case eZergCommandResearchMetabolicBoost:
			return L"3 42 0";
		case eZergCommandResearchMeleeAttacks1:
			return L"3 29 0";
		case eZergCommandResearchMeleeAttacks2:
			return L"3 29 0";
		case eZergCommandResearchMeleeAttacks3:
			return L"3 29 0";
		case eZergCommandResearchGroundCarapace1:
			return L"3 28 0";
		case eZergCommandResearchGroundCarapace2:
			return L"3 28 0";
		case eZergCommandResearchGroundCarapace3:
			return L"3 28 0";
		case eZergCommandResearchMissileAttacks1:
			return L"3 32 0";
		case eZergCommandResearchMissileAttacks2:
			return L"3 32 0";
		case eZergCommandResearchMissileAttacks3:
			return L"3 32 0";
		case eZergCommandResearchGlialReconstitution:
			return L"3 36 0";
		case eZergCommandResearchTunnelingClaws:
			return L"3 38 0";
		case eZergCommandResearchCentrifugalHooks:
			return L"3 45 0";
		case eZergCommandResearchBurrowAtHatchery:
		case eZergCommandResearchBurrowAtLair:
		case eZergCommandResearchBurrowAtHive:
			return L"3 44 0";
		case eZergCommandResearchPneumaticCarapaceAtHatchery:
		case eZergCommandResearchPneumaticCarapaceAtLair:
		case eZergCommandResearchPneumaticCarapaceAtHive:
			return L"3 34 0";
		case eZergCommandResearchVentralSacsAtHatchery:
		case eZergCommandResearchVentralSacsAtLair:
		case eZergCommandResearchVentralSacsAtHive:
			return L"3 35 0";
		case eZergCommandResearchGroovedSpines:
			return L"3 33 0";
		case eZergCommandResearchPathogenGlands:
			return L"3 50 0";
		case eZergCommandResearchNeuralParasite:
			return L"3 49 0";
		case eZergCommandResearchFlyerAttacks1:
			return L"3 31 0";
		case eZergCommandResearchFlyerAttacks2:
			return L"3 31 0";
		case eZergCommandResearchFlyerAttacks3:
			return L"3 31 0";
		case eZergCommandResearchFlyerCarapace1:
			return L"3 30 0";
		case eZergCommandResearchFlyerCarapace2:
			return L"3 30 0";
		case eZergCommandResearchFlyerCarapace3:
			return L"3 30 0";
		case eZergCommandResearchChitinousPlating:
			return L"3 40 0";

		case eZergCommandMoveDroneToGas:
			return L"";
		case eZergCommandMoveDroneToMinerals:
			return L"";
		}
		break;
	}
	
	return L"";
}

bool DisplayCommand(EOutputFormat format, EZergCommand command)
{
	switch(format)
	{
	case eOutputFormatSimple:
		return eZergCommandBuildDrone != command;
	case eOutputFormatDetailed:
		return true;
	case eOutputFormatFull:
		return true;
	case eOutputFormatHaploid:
		return eZergCommandBuildDrone != command;
	case eOutputFormatYABOT:
		switch(command)
		{
		case eZergCommandQueenSpawnLarvae:
		case eZergCommandBuildDrone:
		case eZergCommandMoveDroneToGas:
		case eZergCommandMoveDroneToMinerals:
			return false;
		}
		return true;
	case eOutputFormatSC2Gears:
		return eZergCommandBuildDrone != command;
	}

	return false;
}

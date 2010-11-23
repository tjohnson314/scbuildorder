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
	case eZergCommandResearchBurrow:
		return L"Research Burrow";
	case eZergCommandResearchPneumaticCarapace:
		return L"Research Pneumatic Carapace";
	case eZergCommandResearchVentralSacs:
		return L"Research Ventral Sacs";
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
	
	return L"";
}

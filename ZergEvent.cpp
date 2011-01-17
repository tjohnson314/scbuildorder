#include "stdafx.h"
#include "ZergEvent.h"

const WCHAR *tostring(EOutputFormat format, CZergEvent::EEvent event)
{
	switch(event)
	{
	case CZergEvent::eSpawnHatchery:
		return L"Hatchery Completed";
	case CZergEvent::eSpawnExtractor:
		return L"Extractor Completed";
	case CZergEvent::eSpawnSpawningPool:
		return L"Spawning Pool Completed";
	case CZergEvent::eSpawnCreepTumor:
		return L"Creep Tumor Completed";
	case CZergEvent::eSpawnEvolutionChamber:
		return L"Evolution Chamber Completed";
	case CZergEvent::eSpawnSpineCrawler:
		return L"Spine Crawler Completed";
	case CZergEvent::eSpawnSporeCrawler:
		return L"Spore Crawler Completed";
	case CZergEvent::eSpawnRoachWarren:
		return L"Roach Warren Completed";
	case CZergEvent::eSpawnLair:
		return L"Lair Completed";
	case CZergEvent::eSpawnHydraliskDen:
		return L"Hydralisk Den Completed";
	case CZergEvent::eSpawnBanelingNest:
		return L"Baneling Nest Completed";
	case CZergEvent::eSpawnSpire:
		return L"Spire Completed";
	case CZergEvent::eSpawnInfestationPit:
		return L"Infestation Pit Completed";
	case CZergEvent::eSpawnNydusNetwork:
		return L"Nydus Network Completed";
	case CZergEvent::eSpawnHive:
		return L"Hive Completed";
	case CZergEvent::eSpawnUltraliskCavern:
		return L"Ultralisk Cavern Completed";
	case CZergEvent::eSpawnGreaterSpire:
		return L"Greater Spire Completed";
	case CZergEvent::eExtractorTrickFinished:
		return L"Extractor Trick Finished";
	case CZergEvent::eCreepTumorAvailable:
		return L"Creep Tumor Available";

		// Units
	case CZergEvent::eSpawnLarva1:
	case CZergEvent::eSpawnLarva2:
	case CZergEvent::eSpawnLarva3:
	case CZergEvent::eSpawnLarva4:
		return L"Larva Spawned";
	case CZergEvent::eSpawnQueenLarvae1:
	case CZergEvent::eSpawnQueenLarvae2:
	case CZergEvent::eSpawnQueenLarvae3:
	case CZergEvent::eSpawnQueenLarvae4:
		return L"Spawn Larvae Completed";
	case CZergEvent::eSpawnDrone:
		return L"Drone Completed";
	case CZergEvent::eSpawnOverlord:
		return L"Overlord Completed";
	case CZergEvent::eSpawnQueen:
		return L"Queen Completed";
	case CZergEvent::eSpawnZergling:
		return L"Zergling Completed";
	case CZergEvent::eSpawnRoach:
		return L"Roach Completed";
	case CZergEvent::eSpawnHydralisk:
		return L"Hydralisk Completed";
	case CZergEvent::eSpawnBaneling:
		return L"Baneling Completed";
	case CZergEvent::eSpawnOverseer:
		return L"Overseer Completed";
	case CZergEvent::eSpawnInfestor:
		return L"Infestor Completed";
	case CZergEvent::eSpawnMutalisk:
		return L"Mutalisk Completed";
	case CZergEvent::eSpawnCorruptor:
		return L"Corruptor Completed";
	case CZergEvent::eSpawnUltralisk:
		return L"Ultralisk Completed";
	case CZergEvent::eSpawnBroodlord:
		return L"Broodlord Completed";

		// Research:
	case CZergEvent::eResearchAdrenalGlandsComplete:
		return L"Adrenal Glands Completed";
	case CZergEvent::eResearchMetabolicBoostComplete:
		return L"Metabolic Boost Completed";
	case CZergEvent::eResearchMeleeAttacks1Complete:
		return L"Melee Attacks 1 Completed";
	case CZergEvent::eResearchMeleeAttacks2Complete:
		return L"Melee Attacks 2 Completed";
	case CZergEvent::eResearchMeleeAttacks3Complete:
		return L"Melee Attacks 3 Completed";
	case CZergEvent::eResearchGroundCarapace1Complete:
		return L"Ground Carapace 1 Completed";
	case CZergEvent::eResearchGroundCarapace2Complete:
		return L"Ground Carapace 2 Completed";
	case CZergEvent::eResearchGroundCarapace3Complete:
		return L"Ground Carapace 3 Completed";
	case CZergEvent::eResearchMissileAttacks1Complete:
		return L"Missile Attacks 1 Completed";
	case CZergEvent::eResearchMissileAttacks2Complete:
		return L"Missile Attacks 2 Completed";
	case CZergEvent::eResearchMissileAttacks3Complete:
		return L"Missile Attacks 3 Completed";
	case CZergEvent::eResearchGlialReconstitutionComplete:
		return L"Glial Reconstitution Completed";
	case CZergEvent::eResearchTunnelingClawsComplete:
		return L"Tunneling Claws Completed";
	case CZergEvent::eResearchCentrifugalHooksComplete:
		return L"Centrifugal Hooks Completed";
	case CZergEvent::eResearchBurrowCompleteAtHatchery:
	case CZergEvent::eResearchBurrowCompleteAtLair:
	case CZergEvent::eResearchBurrowCompleteAtHive:
		return L"Burrow Completed";
	case CZergEvent::eResearchPneumaticCarapaceCompleteAtHatchery:
	case CZergEvent::eResearchPneumaticCarapaceCompleteAtLair:
	case CZergEvent::eResearchPneumaticCarapaceCompleteAtHive:
		return L"Pneumatic Carapace Completed";
	case CZergEvent::eResearchVentralSacsCompleteAtHatchery:
	case CZergEvent::eResearchVentralSacsCompleteAtLair:
	case CZergEvent::eResearchVentralSacsCompleteAtHive:
		return L"Ventral Sacs Completed";
	case CZergEvent::eResearchGroovedSpinesComplete:
		return L"Grooved Spines Completed";
	case CZergEvent::eResearchPathogenGlandsComplete:
		return L"Pathogen Glands Completed";
	case CZergEvent::eResearchNeuralParasiteComplete:
		return L"Neural Parasite Completed";
	case CZergEvent::eResearchFlyerAttacks1Complete:
		return L"Flyer Attacks 1 Completed";
	case CZergEvent::eResearchFlyerAttacks2Complete:
		return L"Flyer Attacks 2 Completed";
	case CZergEvent::eResearchFlyerAttacks3Complete:
		return L"Flyer Attacks 3 Completed";
	case CZergEvent::eResearchFlyerCarapace1Complete:
		return L"Flyer Carapace 1 Completed";
	case CZergEvent::eResearchFlyerCarapace2Complete:
		return L"Flyer Carapace 2 Completed";
	case CZergEvent::eResearchFlyerCarapace3Complete:
		return L"Flyer Carapace 3 Completed";
	case CZergEvent::eResearchChitinousPlatingComplete:
		return L"Chitinous Plating Compelted";

		// Misc
	case CZergEvent::eQueenReady:
	case CZergEvent::eDroneStartMiningMinerals:
	case CZergEvent::eDroneStartMiningGas:
		return L""; // Shouldn't be displayed

	case CZergEvent::eSendScout:
		return L"Scout Sent";
	case CZergEvent::eKillScout:
		return L"Scout Died";
	case CZergEvent::eReturnScout:
		return L"Scout Returned";
	}

	return L"";
}

bool DisplayEvent(EOutputFormat format, CZergEvent::EEvent event)
{
	switch(format)
	{
	case eOutputFormatFull:
		switch(event)
		{
		case CZergEvent::eQueenReady:
		case CZergEvent::eDroneStartMiningMinerals:
		case CZergEvent::eDroneStartMiningGas:
			return false;
		}
		return true;
	}

	return false;
}

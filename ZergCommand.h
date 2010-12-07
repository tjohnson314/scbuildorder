#pragma once

#include <vector>
#include <iostream>
#include "Vector.h"
#include "OutputFormat.h"

enum EZergCommand
{
	eZergCommandNone = 0

	, eZergCommandBuildHatchery
	, eZergCommandBuildExtractor
	, eZergCommandBuildSpawningPool
	, eZergCommandExpandCreepTumor
	, eZergCommandBuildEvolutionChamber
	, eZergCommandBuildSpineCrawler
	, eZergCommandBuildSporeCrawler
	, eZergCommandBuildRoachWarren
	, eZergCommandBuildLair
	, eZergCommandBuildHydraliskDen
	, eZergCommandBuildBanelingNest
	, eZergCommandBuildSpire
	, eZergCommandBuildInfestationPit
	, eZergCommandBuildNydusNetwork
	, eZergCommandBuildHive
	, eZergCommandBuildUltraliskCavern
	, eZergCommandBuildGreaterSpire

	, eZergCommandCancelExtractor

	, eZergCommandBuildDrone
	, eZergCommandBuildOverlord
	, eZergCommandBuildQueen
	, eZergCommandBuildZergling
	, eZergCommandBuildRoach
	, eZergCommandBuildHydralisk
	, eZergCommandBuildBaneling
	, eZergCommandBuildOverseer
	, eZergCommandBuildInfestor
	, eZergCommandBuildMutalisk
	, eZergCommandBuildCorruptor
	, eZergCommandBuildUltralisk
	, eZergCommandBuildBroodlord

	, eZergCommandExtractorTrickDrone
	, eZergCommandExtractorTrickQueen
	, eZergCommandExtractorTrickZergling
	, eZergCommandExtractorTrickRoach

	, eZergCommandQueenSpawnLarvae
	, eZergCommandQueenSpawnCreepTumor

	, eZergCommandResearchAdrenalGlands
	, eZergCommandResearchMetabolicBoost
	, eZergCommandResearchMeleeAttacks1
	, eZergCommandResearchMeleeAttacks2
	, eZergCommandResearchMeleeAttacks3
	, eZergCommandResearchGroundCarapace1
	, eZergCommandResearchGroundCarapace2
	, eZergCommandResearchGroundCarapace3
	, eZergCommandResearchMissileAttacks1
	, eZergCommandResearchMissileAttacks2
	, eZergCommandResearchMissileAttacks3
	, eZergCommandResearchGlialReconstitution
	, eZergCommandResearchTunnelingClaws
	, eZergCommandResearchCentrifugalHooks
	, eZergCommandResearchBurrow
	, eZergCommandResearchPneumaticCarapace
	, eZergCommandResearchVentralSacs
	, eZergCommandResearchGroovedSpines
	, eZergCommandResearchPathogenGlands
	, eZergCommandResearchNeuralParasite
	, eZergCommandResearchFlyerAttacks1
	, eZergCommandResearchFlyerAttacks2
	, eZergCommandResearchFlyerAttacks3
	, eZergCommandResearchFlyerCarapace1
	, eZergCommandResearchFlyerCarapace2
	, eZergCommandResearchFlyerCarapace3
	, eZergCommandResearchChitinousPlating

	, eZergCommandMoveDroneToGas
	, eZergCommandMoveDroneToMinerals
};

const WCHAR *tostring(EOutputFormat format, EZergCommand command);

inline bool DisplayCommand(EOutputFormat format, EZergCommand command)
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
		return eZergCommandBuildDrone != command;
	case eOutputFormatSC2Gears:
		return eZergCommandBuildDrone != command;
	}

	return false;
}

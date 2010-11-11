#pragma once

#include <vector>
#include <iostream>
#include "Vector.h"

enum EZergCommand
{
	eZergCommandNone = 0
	, eZergCommandBuildHatchery
	, eZergCommandBuildExtractor
	, eZergCommandBuildSpawningPool
	, eZergCommandExpandCreepTumour
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

	, eZergCommandQueenSpawnLarva

	, eZergCommandMoveDroneToGas
	, eZergCommandMoveDroneToMinerals
};

const WCHAR *tostring(EZergCommand command);

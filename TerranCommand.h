#pragma once

#include <vector>
#include <iostream>
#include "Vector.h"
#include "OutputFormat.h"

enum ETerranCommand
{
	eTerranCommandNone = 0

	, eTerranCommandBuildCommandCenter
	, eTerranCommandBuildRefinery
	, eTerranCommandBuildSupplyDepot
	, eTerranCommandBuildBarracksNaked
	, eTerranCommandBuildBarracksOnTechLab
	, eTerranCommandBuildBarracksOnReactor
	, eTerranCommandBuildOrbitalCommand
	, eTerranCommandBuildEngineeringBay
	, eTerranCommandBuildBunker
	, eTerranCommandBuildMissileTurret
	, eTerranCommandBuildSensorTower
	, eTerranCommandBuildPlanetaryFortress
	, eTerranCommandBuildGhostAcademy
	, eTerranCommandBuildFactoryNaked
	, eTerranCommandBuildFactoryOnTechLab
	, eTerranCommandBuildFactoryOnReactor
	, eTerranCommandBuildArmory
	, eTerranCommandBuildStarportNaked
	, eTerranCommandBuildStarportOnTechLab
	, eTerranCommandBuildStarportOnReactor
	, eTerranCommandBuildFusionCore

	, eTerranCommandBuildBarracksTechLab
	, eTerranCommandBuildBarracksReactor
	, eTerranCommandBuildFactoryTechLab
	, eTerranCommandBuildFactoryReactor
	, eTerranCommandBuildStarportTechLab
	, eTerranCommandBuildStarportReactor

	, eTerranCommandLiftBarracksNaked
	, eTerranCommandLiftBarracksTechLab
	, eTerranCommandLiftBarracksReactor
	, eTerranCommandLiftFactoryNaked
	, eTerranCommandLiftFactoryTechLab
	, eTerranCommandLiftFactoryReactor
	, eTerranCommandLiftStarportNaked
	, eTerranCommandLiftStarportTechLab
	, eTerranCommandLiftStarportReactor

	, eTerranCommandLandBarracksNaked
	, eTerranCommandLandBarracksTechLab
	, eTerranCommandLandBarracksReactor
	, eTerranCommandLandFactoryNaked
	, eTerranCommandLandFactoryTechLab
	, eTerranCommandLandFactoryReactor
	, eTerranCommandLandStarportNaked
	, eTerranCommandLandStarportTechLab
	, eTerranCommandLandStarportReactor

	, eTerranCommandBuildSCV
	, eTerranCommandBuildMarine
	, eTerranCommandBuildMarineNaked
	, eTerranCommandBuildMarineReactor
	, eTerranCommandBuildMarineTechLab
	, eTerranCommandBuildMarauder
	, eTerranCommandBuildReaper
	, eTerranCommandBuildGhost
	, eTerranCommandBuildHellion
	, eTerranCommandBuildHellionNaked
	, eTerranCommandBuildHellionReactor
	, eTerranCommandBuildHellionTechLab
	, eTerranCommandBuildSiegeTank
	, eTerranCommandBuildThor
	, eTerranCommandBuildViking
	, eTerranCommandBuildVikingNaked
	, eTerranCommandBuildVikingReactor
	, eTerranCommandBuildVikingTechLab
	, eTerranCommandBuildMedivac
	, eTerranCommandBuildMedivacNaked
	, eTerranCommandBuildMedivacReactor
	, eTerranCommandBuildMedivacTechLab
	, eTerranCommandBuildRaven
	, eTerranCommandBuildBanshee
	, eTerranCommandBuildBattleCruiser

	, eTerranCommandCalldownMULE
	, eTerranCommandCalldownExtraSupplies
	, eTerranCommandScannerSweep

	, eTerranCommandResearchStimpack
	, eTerranCommandResearchCombatShield
	, eTerranCommandResearchNitroPacks
	, eTerranCommandResearchConcussiveShells
	, eTerranCommandResearchInfantryWeapons1
	, eTerranCommandResearchInfantryWeapons2
	, eTerranCommandResearchInfantryWeapons3
	, eTerranCommandResearchInfantryArmor1
	, eTerranCommandResearchInfantryArmor2
	, eTerranCommandResearchInfantryArmor3
	, eTerranCommandResearchBuildingArmor
	, eTerranCommandResearchHiSecAutoTracking
	, eTerranCommandResearchNeoSteelFrame
	, eTerranCommandResearchMoebiusReactor
	, eTerranCommandResearchPersonalCloaking
	, eTerranCommandArmNuke
	, eTerranCommandResearchInfernalPreIgniter
	, eTerranCommandResearchSiegeTech
	, eTerranCommandResearch250mmStrikeCannons
	, eTerranCommandResearchVehicleWeapons1
	, eTerranCommandResearchVehicleWeapons2
	, eTerranCommandResearchVehicleWeapons3
	, eTerranCommandResearchVehiclePlating1
	, eTerranCommandResearchVehiclePlating2
	, eTerranCommandResearchVehiclePlating3
	, eTerranCommandResearchShipWeapons1
	, eTerranCommandResearchShipWeapons2
	, eTerranCommandResearchShipWeapons3
	, eTerranCommandResearchShipPlating1
	, eTerranCommandResearchShipPlating2
	, eTerranCommandResearchShipPlating3
	, eTerranCommandResearchDurableMaterials
	, eTerranCommandResearchCorvidReactor
	, eTerranCommandResearchCaduceusReactor
	, eTerranCommandResearchSeekerMissile
	, eTerranCommandResearchCloakingField
	, eTerranCommandResearchBehemothReactor
	, eTerranCommandResearchWeaponRefit


	, eTerranCommandMoveSCVToGas
	, eTerranCommandMoveSCVToMinerals
};

const WCHAR *tostring(EOutputFormat format, ETerranCommand command);

bool DisplayCommand(EOutputFormat format, ETerranCommand command);

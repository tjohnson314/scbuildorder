#include "stdafx.h"
#include "TerranCommand.h"

const WCHAR *tostring(ETerranCommand command)
{
	switch(command)
	{
	case eTerranCommandBuildCommandCenter:
		return L"Build Command Center";
	case eTerranCommandBuildRefinery:
		return L"Build Refinery";
	case eTerranCommandBuildSupplyDepot:
		return L"Build Supply Depot";
	case eTerranCommandBuildBarracksNaked:
		return L"Build Barracks (Naked)";
	case eTerranCommandBuildBarracksOnTechLab:
		return L"Build Barracks (on Tech Lab)";
	case eTerranCommandBuildBarracksOnReactor:
		return L"Build Barracks (on Reactor)";
	case eTerranCommandBuildOrbitalCommand:
		return L"Build Orbital Command";
	case eTerranCommandBuildEngineeringBay:
		return L"Build Engineering Bay";
	case eTerranCommandBuildBunker:
		return L"Build Bunker";
	case eTerranCommandBuildMissileTurret:
		return L"Build Missile Turret";
	case eTerranCommandBuildSensorTower:
		return L"Build Sensor Tower";
	case eTerranCommandBuildPlanetaryFortress:
		return L"Build Planetary Fortress";
	case eTerranCommandBuildGhostAcademy:
		return L"Build Ghost Academy";
	case eTerranCommandBuildFactoryNaked:
		return L"Build Factory (Naked)";
	case eTerranCommandBuildFactoryOnTechLab:
		return L"Build Factory (on Tech Lab)";
	case eTerranCommandBuildFactoryOnReactor:
		return L"Build Factory (on Reactor)";
	case eTerranCommandBuildArmory:
		return L"Build Armory";
	case eTerranCommandBuildStarportNaked:
		return L"Build Starport (Naked)";
	case eTerranCommandBuildStarportOnTechLab:
		return L"Build Starport (on Tech Lab)";
	case eTerranCommandBuildStarportOnReactor:
		return L"Build Starport (on Reactor)";
	case eTerranCommandBuildFusionCore:
		return L"Build Fusion Core";

	case eTerranCommandBuildBarracksTechLab:
		return L"Build Barracks Tech Lab";
	case eTerranCommandBuildBarracksReactor:
		return L"Build Barracks Reactor";
	case eTerranCommandBuildFactoryTechLab:
		return L"Build Factory Tech Lab";
	case eTerranCommandBuildFactoryReactor:
		return L"Build Factory Reactor";
	case eTerranCommandBuildStarportTechLab:
		return L"Build Starport Tech Lab";
	case eTerranCommandBuildStarportReactor:
		return L"Build Starport Reactor";

	case eTerranCommandLiftBarracksTechLab:
		return L"Lift Barracks (Tech Lab)";
	case eTerranCommandLiftBarracksReactor:
		return L"Lift Barracks (Reactor)";
	case eTerranCommandLiftBarracksNaked:
		return L"Lift Barracks (Naked)";
	case eTerranCommandLiftFactoryTechLab:
		return L"Lift Factory (Tech Lab)";
	case eTerranCommandLiftFactoryReactor:
		return L"Lift Factory (Reactor)";
	case eTerranCommandLiftFactoryNaked:
		return L"Lift Factory (Naked)";
	case eTerranCommandLiftStarportTechLab:
		return L"Lift Starport (Tech Lab)";
	case eTerranCommandLiftStarportReactor:
		return L"Lift Starport (Reactor)";
	case eTerranCommandLiftStarportNaked:
		return L"Lift Starport (Naked)";

	case eTerranCommandLandBarracksTechLab:
		return L"Land Barracks (Tech Lab)";
	case eTerranCommandLandBarracksReactor:
		return L"Land Barracks (Reactor)";
	case eTerranCommandLandBarracksNaked:
		return L"Land Barracks (Naked)";
	case eTerranCommandLandFactoryTechLab:
		return L"Land Factory (Tech Lab)";
	case eTerranCommandLandFactoryReactor:
		return L"Land Factory (Reactor)";
	case eTerranCommandLandFactoryNaked:
		return L"Land Factory (Naked)";
	case eTerranCommandLandStarportTechLab:
		return L"Land Starport (Tech Lab)";
	case eTerranCommandLandStarportReactor:
		return L"Land Starport (Reactor)";
	case eTerranCommandLandStarportNaked:
		return L"Land Starport (Naked)";

	case eTerranCommandBuildSCV:
		return L"Build SCV";
	case eTerranCommandBuildMarine:
		return L"Build Marine";
	case eTerranCommandBuildMarineNaked:
		return L"Build Marine (@ Naked Barracks)";
	case eTerranCommandBuildMarineReactor:
		return L"Build Marine (@ Reactor Barracks)";
	case eTerranCommandBuildMarineTechLab:
		return L"Build Marine (@ Tech Lab Barracks)";
	case eTerranCommandBuildMarauder:
		return L"Build Marauder";
	case eTerranCommandBuildReaper:
		return L"Build Reaper";
	case eTerranCommandBuildGhost:
		return L"Build Ghost";
	case eTerranCommandBuildHellion:
		return L"Build Hellion";
	case eTerranCommandBuildHellionNaked:
		return L"Build Hellion (@ Naked Factory)";
	case eTerranCommandBuildHellionReactor:
		return L"Build Hellion (@ Reactor Factory)";
	case eTerranCommandBuildHellionTechLab:
		return L"Build Hellion (@ Tech Lab Factory)";
	case eTerranCommandBuildSiegeTank:
		return L"Build Siege Tank";
	case eTerranCommandBuildThor:
		return L"Build Thor";
	case eTerranCommandBuildViking:
		return L"Build Viking";
	case eTerranCommandBuildVikingNaked:
		return L"Build Viking (@ Naked Starport)";
	case eTerranCommandBuildVikingReactor:
		return L"Build Viking (@ Reactor Starport)";
	case eTerranCommandBuildVikingTechLab:
		return L"Build Viking (@ Tech Lab Starport)";
	case eTerranCommandBuildMedivac:
		return L"Build Medivac";
	case eTerranCommandBuildMedivacNaked:
		return L"Build Medivac (@ Naked Starport)";
	case eTerranCommandBuildMedivacReactor:
		return L"Build Medivac (@ Reactor Starport)";
	case eTerranCommandBuildMedivacTechLab:
		return L"Build Medivac (@ Tech Lab Starport)";
	case eTerranCommandBuildRaven:
		return L"Build Raven";
	case eTerranCommandBuildBanshee:
		return L"Build Banshee";
	case eTerranCommandBuildBattleCruiser:
		return L"Build Battle Cruiser";

	case eTerranCommandCalldownMULE:
		return L"Calldown MULE";
	case eTerranCommandCalldownExtraSupplies:
		return L"Calldown Extra Supplies";
	case eTerranCommandScannerSweep:
		return L"Scanner Sweep";

	case eTerranCommandResearchStimpack:
		return L"Research Stimpack";
	case eTerranCommandResearchCombatShield:
		return L"Research Combat Shield";
	case eTerranCommandResearchNitroPacks:
		return L"Research Nitro Packs";
	case eTerranCommandResearchConcussiveShells:
		return L"Research Concussive Shells";
	case eTerranCommandResearchInfantryWeapons1:
		return L"Research Infantry Weapons 1";
	case eTerranCommandResearchInfantryWeapons2:
		return L"Research Infantry Weapons 2";
	case eTerranCommandResearchInfantryWeapons3:
		return L"Research Infantry Weapons 3";
	case eTerranCommandResearchInfantryArmor1:
		return L"Research Infantry Armor 1";
	case eTerranCommandResearchInfantryArmor2:
		return L"Research Infantry Armor 2";
	case eTerranCommandResearchInfantryArmor3:
		return L"Research Infantry Armor 3";
	case eTerranCommandResearchBuildingArmor:
		return L"Research Building Armor";
	case eTerranCommandResearchHiSecAutoTracking:
		return L"Research Hi-Sec Auto Tracking";
	case eTerranCommandResearchNeoSteelFrame:
		return L"Research Neo-steel Frame";
	case eTerranCommandResearchMoebiusReactor:
		return L"Research Moebius Reactor";
	case eTerranCommandResearchPersonalCloaking:
		return L"Research Personal Cloaking";
	case eTerranCommandArmNuke:
		return L"Arm Nuke";
	case eTerranCommandResearchInfernalPreIgniter:
		return L"Research Infernal Pre-igniter";
	case eTerranCommandResearchSiegeTech:
		return L"Research Siege Tech";
	case eTerranCommandResearchDurableMaterials:
		return L"Research Durable Materials";
	case eTerranCommandResearch250mmStrikeCannons:
		return L"Research 250mm Strike Cannons";
	case eTerranCommandResearchVehicleWeapons1:
		return L"Research Vehicle Weapons 1";
	case eTerranCommandResearchVehicleWeapons2:
		return L"Research Vehicle Weapons 2";
	case eTerranCommandResearchVehicleWeapons3:
		return L"Research Vehicle Weapons 3";
	case eTerranCommandResearchVehiclePlating1:
		return L"Research Vehicle Plating 1";
	case eTerranCommandResearchVehiclePlating2:
		return L"Research Vehicle Plating 2";
	case eTerranCommandResearchVehiclePlating3:
		return L"Research Vehicle Plating 3";
	case eTerranCommandResearchShipWeapons1:
		return L"Research Ship Weapons 1";
	case eTerranCommandResearchShipWeapons2:
		return L"Research Ship Weapons 2";
	case eTerranCommandResearchShipWeapons3:
		return L"Research Ship Weapons 3";
	case eTerranCommandResearchShipPlating1:
		return L"Research Ship Plating 1";
	case eTerranCommandResearchShipPlating2:
		return L"Research Ship Plating 2";
	case eTerranCommandResearchShipPlating3:
		return L"Research Ship Plating 3";
	case eTerranCommandResearchCorvidReactor:
		return L"Research Corvid Reactor";
	case eTerranCommandResearchCaduceusReactor:
		return L"Research Caduceus Reactor";
	case eTerranCommandResearchSeekerMissile:
		return L"Research Seeker Missile";
	case eTerranCommandResearchCloakingField:
		return L"Research Cloaking Field";
	case eTerranCommandResearchBehemothReactor:
		return L"Research Behemoth Reactor";
	case eTerranCommandResearchWeaponRefit:
		return L"Research Weapon Refit";

	case eTerranCommandMoveSCVToGas:
		return L"Move SCV To Gas";
	case eTerranCommandMoveSCVToMinerals:
		return L"Move SCV To Minerals";
	}
	
	return L"";
}

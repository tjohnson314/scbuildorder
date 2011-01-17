#include "stdafx.h"
#include "TerranEvent.h"

const WCHAR *tostring(EOutputFormat format, CTerranEvent::EEvent event)
{
	switch(event)
	{
	// Buildings
	case CTerranEvent::eSpawnCommandCenter:
		return L"Command Center Completed";
	case CTerranEvent::eSpawnRefinery:
		return L"Refinery Completed";
	case CTerranEvent::eSpawnSupplyDepot:
		return L"Supply Depot Completed";
	case CTerranEvent::eSpawnSupplyDepotExtraSupplies:
		return L"Supply Depot Extra Supplied Landed";
	case CTerranEvent::eSpawnBarracksNaked:
		return L"Barracks Completed (Naked)";
	case CTerranEvent::eSpawnBarracksOnTechLab:
		return L"Barracks Completed (On Tech Lab)";
	case CTerranEvent::eSpawnBarracksOnReactor:
		return L"Barracks Completed (On Reactor)";
	case CTerranEvent::eSpawnOrbitalCommand:
		return L"Orbital Command Completed";
	case CTerranEvent::eSpawnEngineeringBay:
		return L"Engineering Bay Completed";
	case CTerranEvent::eSpawnBunker:
		return L"Bunker Completed";
	case CTerranEvent::eSpawnMissileTurret:
		return L"Missile Turret Completed";
	case CTerranEvent::eSpawnSensorTower:
		return L"Sensor Completed";
	case CTerranEvent::eSpawnPlanetaryFortress:
		return L"Planetary Fortress Completed";
	case CTerranEvent::eSpawnGhostAcademy:
		return L"Ghost Academy Completed";
	case CTerranEvent::eSpawnFactoryNaked:
		return L"Factory Completed (Naked)";
	case CTerranEvent::eSpawnFactoryOnTechLab:
		return L"Factory Completed (On Tech Lab)";
	case CTerranEvent::eSpawnFactoryOnReactor:
		return L"Factory Completed (On Reactor)";
	case CTerranEvent::eSpawnArmory:
		return L"Armory Completed";
	case CTerranEvent::eSpawnStarportNaked:
		return L"Starport Completed (Naked)";
	case CTerranEvent::eSpawnStarportOnTechLab:
		return L"Starport Completed (On Tech Lab)";
	case CTerranEvent::eSpawnStarportOnReactor:
		return L"Starport Completed (On Reactor)";
	case CTerranEvent::eSpawnFusionCore:
		return L"Fusion Core Completed";

	case CTerranEvent::eSpawnBarracksTechLab:
		return L"Barracks Tech Lab Completed";
	case CTerranEvent::eSpawnBarracksReactor:
		return L"Barracks Reactor Completed";
	case CTerranEvent::eSpawnFactoryTechLab:
		return L"Factory Tech Lab Completed";
	case CTerranEvent::eSpawnFactoryReactor:
		return L"Factory Reactor Completed";
	case CTerranEvent::eSpawnStarportTechLab:
		return L"Starport Tech Lab Completed";
	case CTerranEvent::eSpawnStarportReactor:
		return L"Starport Reactor Completed";

	// Building States
	case CTerranEvent::eBarracksReadyToLand:
		return L"Barracks Ready To Land";
	case CTerranEvent::eFactoryReadyToLand:
		return L"Factory Ready To Land";
	case CTerranEvent::eStarportReadyToLand:
		return L"Starport Ready To Land";

	case CTerranEvent::eTechLabAvailable:
		return L"Tech Lab Available";
	case CTerranEvent::eReactorAvailable:
		return L"Reactor Available";

	case CTerranEvent::eBarracksLandedNaked:
		return L"Barracks Landed (Naked)";
	case CTerranEvent::eBarracksLandedOnTechLab:
		return L"Barracks Landed (On Tech Lab)";
	case CTerranEvent::eBarracksLandedOnReactor:
		return L"Barracks Landed (On Reactor)";
	case CTerranEvent::eFactoryLandedNaked:
		return L"Factory Landed (Naked)";
	case CTerranEvent::eFactoryLandedOnTechLab:
		return L"Factory Landed (On Tech Lab)";
	case CTerranEvent::eFactoryLandedOnReactor:
		return L"Factory Landed (On Reactor)";
	case CTerranEvent::eStarportLandedNaked:
		return L"Starport Landed (Naked)";
	case CTerranEvent::eStarportLandedOnTechLab:
		return L"Starport Landed (On Tech Lab)";
	case CTerranEvent::eStarportLandedOnReactor:
		return L"Starport Landed (On Reactor)";

	// Units
	case CTerranEvent::eSpawnSCV:
		return L"SCV Spawned";
	case CTerranEvent::eSpawnMULE:
		return L"MULE Spawned";
	case CTerranEvent::eSpawnMarineNaked:
	case CTerranEvent::eSpawnMarineTechLab:
	case CTerranEvent::eSpawnMarineReactor:
		return L"Marine Spawned";
	case CTerranEvent::eSpawnMarauder:
		return L"Marauder Spawned";
	case CTerranEvent::eSpawnReaper:
		return L"Reaper Spawned";
	case CTerranEvent::eSpawnGhost:
		return L"Ghost Spawned";
	case CTerranEvent::eSpawnHellionNaked:
	case CTerranEvent::eSpawnHellionTechLab:
	case CTerranEvent::eSpawnHellionReactor:
		return L"Hellion Spawned";
	case CTerranEvent::eSpawnSiegeTank:
		return L"Siege Tank Spawned";
	case CTerranEvent::eSpawnThor:
		return L"Thor Spawned";
	case CTerranEvent::eSpawnVikingNaked:
	case CTerranEvent::eSpawnVikingTechLab:
	case CTerranEvent::eSpawnVikingReactor:
		return L"Viking Spawned";
	case CTerranEvent::eSpawnMedivacNaked:
	case CTerranEvent::eSpawnMedivacTechLab:
	case CTerranEvent::eSpawnMedivacReactor:
		return L"Medivac Spawned";
	case CTerranEvent::eSpawnRaven:
		return L"Raven Spawned";
	case CTerranEvent::eSpawnBanshee:
		return L"Banshee Spawned";
	case CTerranEvent::eSpawnBattleCruiser:
		return L"Battle Cruiser Spawned";

	case CTerranEvent::eKillMULE:
		return L"MULE Died";

	// Research
	case CTerranEvent::eResearchStimpackComplete:
		return L"Stimpack Completed";
	case CTerranEvent::eResearchCombatShieldComplete:
		return L"Combat Shield Completed";
	case CTerranEvent::eResearchNitroPacksComplete:
		return L"Nitro Packs Completed";
	case CTerranEvent::eResearchConcussiveShellsComplete:
		return L"Concussive Shells Completed";
	case CTerranEvent::eResearchInfantryWeapons1Complete:
		return L"Infantry Weapons 1 Completed";
	case CTerranEvent::eResearchInfantryWeapons2Complete:
		return L"Infantry Weapons 2 Completed";
	case CTerranEvent::eResearchInfantryWeapons3Complete:
		return L"Infantry Weapons 3 Completed";
	case CTerranEvent::eResearchInfantryArmor1Complete:
		return L"Infantry Armor 1 Completed";
	case CTerranEvent::eResearchInfantryArmor2Complete:
		return L"Infantry Armor 2 Completed";
	case CTerranEvent::eResearchInfantryArmor3Complete:
		return L"Infantry Armor 3 Completed";
	case CTerranEvent::eResearchBuildingArmorComplete:
		return L"Building Armor Completed";
	case CTerranEvent::eResearchHiSecAutoTrackingComplete:
		return L"Hi-Sec Auto Tracking Completed";
	case CTerranEvent::eResearchNeoSteelFrameComplete:
		return L"Neo-steel Frame Completed";
	case CTerranEvent::eResearchMoebiusReactorComplete:
		return L"Moebius Reactor Completed";
	case CTerranEvent::eResearchPersonalCloakingComplete:
		return L"Personal Cloaking Completed";
	case CTerranEvent::eArmNukeComplete:
		return L"Arm Nuke Completed";
	case CTerranEvent::eResearchInfernalPreIgniterComplete:
		return L"Infernal Pre-Igniter Completed";
	case CTerranEvent::eResearchSiegeTechComplete:
		return L"Siege Tech Completed";
	case CTerranEvent::eResearch250mmStrikeCannonsComplete:
		return L"250mm Strike Cannons Completed";
	case CTerranEvent::eResearchVehicleWeapons1Complete:
		return L"Vehicle Weapons 1 Completed";
	case CTerranEvent::eResearchVehicleWeapons2Complete:
		return L"Vehicle Weapons 2 Completed";
	case CTerranEvent::eResearchVehicleWeapons3Complete:
		return L"Vehicle Weapons 3 Completed";
	case CTerranEvent::eResearchVehiclePlating1Complete:
		return L"Vehicle Plating 1 Completed";
	case CTerranEvent::eResearchVehiclePlating2Complete:
		return L"Vehicle Plating 2 Completed";
	case CTerranEvent::eResearchVehiclePlating3Complete:
		return L"Vehicle Plating 3 Completed";
	case CTerranEvent::eResearchShipWeapons1Complete:
		return L"Ship Weapons 1 Completed";
	case CTerranEvent::eResearchShipWeapons2Complete:
		return L"Ship Weapons 2 Completed";
	case CTerranEvent::eResearchShipWeapons3Complete:
		return L"Ship Weapons 3 Completed";
	case CTerranEvent::eResearchShipPlating1Complete:
		return L"Ship Plating 1 Completed";
	case CTerranEvent::eResearchShipPlating2Complete:
		return L"Ship Plating 2 Completed";
	case CTerranEvent::eResearchShipPlating3Complete:
		return L"Ship Plating 3 Completed";
	case CTerranEvent::eResearchDurableMaterialsComplete:
		return L"Durable Materials Completed";
	case CTerranEvent::eResearchCorvidReactorComplete:
		return L"Corvid Reactor Completed";
	case CTerranEvent::eResearchCaduceusReactorComplete:
		return L"Caduceus Reactor Completed";
	case CTerranEvent::eResearchSeekerMissileComplete:
		return L"Seeker Missile Completed";
	case CTerranEvent::eResearchCloakingFieldComplete:
		return L"Cloaking Field Completed";
	case CTerranEvent::eResearchBehemothReactorComplete:
		return L"Behemoth Reactor Completed";
	case CTerranEvent::eResearchWeaponRefitComplete:
		return L"Weapon Refit Completed";

	// Misc
	case CTerranEvent::eSCVStartMiningMinerals:
	case CTerranEvent::eSCVStartMiningGas:
		return L""; // Shouldn't be displayed

	case CTerranEvent::eSendScout:
		return L"Scout Sent";
	case CTerranEvent::eKillScout:
		return L"Scout Died";
	case CTerranEvent::eReturnScout:
		return L"Scout Returned";
	}

	return L"";
}

bool DisplayEvent(EOutputFormat format, CTerranEvent::EEvent event)
{
	switch(format)
	{
	case eOutputFormatFull:
		switch(event)
		{
		case CTerranEvent::eSCVStartMiningMinerals:
		case CTerranEvent::eSCVStartMiningGas:
			return false;

		}
		return true;
	}

	return false;
}

#pragma once

class CTerranEvent
{
public:
	enum EEvent
	{
		eNone

		// Buildings
		, eSpawnCommandCenter
		, eSpawnRefinery
		, eSpawnSupplyDepot
		, eSpawnSupplyDepotExtraSupplies
		, eSpawnBarracksNaked
		, eSpawnBarracksOnTechLab
		, eSpawnBarracksOnReactor
		, eSpawnOrbitalCommand
		, eSpawnEngineeringBay
		, eSpawnBunker
		, eSpawnMissileTurret
		, eSpawnSensorTower
		, eSpawnPlanetaryFortress
		, eSpawnGhostAcademy
		, eSpawnFactoryNaked
		, eSpawnFactoryOnTechLab
		, eSpawnFactoryOnReactor
		, eSpawnArmory
		, eSpawnStarportNaked
		, eSpawnStarportOnTechLab
		, eSpawnStarportOnReactor
		, eSpawnFusionCore

		, eSpawnBarracksTechLab
		, eSpawnBarracksReactor
		, eSpawnFactoryTechLab
		, eSpawnFactoryReactor
		, eSpawnStarportTechLab
		, eSpawnStarportReactor

		// Units
		, eSpawnSCV
		, eSpawnMULE
		, eSpawnMarineNaked
		, eSpawnMarineTechLab
		, eSpawnMarineReactor
		, eSpawnMarauder
		, eSpawnReaper
		, eSpawnGhost
		, eSpawnHellionNaked
		, eSpawnHellionTechLab
		, eSpawnHellionReactor
		, eSpawnSiegeTank
		, eSpawnThor
		, eSpawnVikingNaked
		, eSpawnVikingTechLab
		, eSpawnVikingReactor
		, eSpawnMedivacNaked
		, eSpawnMedivacTechLab
		, eSpawnMedivacReactor
		, eSpawnRaven
		, eSpawnBanshee
		, eSpawnBattleCruiser

		, eKillMULE

		// Research
		, eResearchStimpackComplete
		, eResearchCombatShieldComplete
		, eResearchNitroPacksComplete
		, eResearchConcussiveShellsComplete
		, eResearchInfantryWeapons1Complete
		, eResearchInfantryWeapons2Complete
		, eResearchInfantryWeapons3Complete
		, eResearchInfantryArmor1Complete
		, eResearchInfantryArmor2Complete
		, eResearchInfantryArmor3Complete
		, eResearchBuildingArmorComplete
		, eResearchHiSecAutoTrackingComplete
		, eResearchNeoSteelFrameComplete
		, eResearchMoebiusReactorComplete
		, eResearchPersonalCloakingComplete
		, eArmNukeComplete
		, eResearchInfernalPreIgniterComplete
		, eResearchSiegeTechComplete
		, eResearchDurableMaterialsComplete
		, eResearch250mmStrikeCannonsComplete
		, eResearchVehicleWeapons1Complete
		, eResearchVehicleWeapons2Complete
		, eResearchVehicleWeapons3Complete
		, eResearchVehiclePlating1Complete
		, eResearchVehiclePlating2Complete
		, eResearchVehiclePlating3Complete
		, eResearchShipWeapons1Complete
		, eResearchShipWeapons2Complete
		, eResearchShipWeapons3Complete
		, eResearchShipPlating1Complete
		, eResearchShipPlating2Complete
		, eResearchShipPlating3Complete
		, eResearchCorvidReactorComplete
		, eResearchCaduceusReactorComplete
		, eResearchSeekerMissileComplete
		, eResearchCloakingFieldComplete
		, eResearchBehemothReactorComplete
		, eResearchWeaponRefitComplete

		// Misc
		, eSCVStartMiningMinerals
		, eSCVStartMiningGas

		, eSendScout
		, eKillScout
		, eReturnScout
	};

	CTerranEvent() : m_event(eNone), m_time(0) {}
	CTerranEvent(EEvent event, double time) : m_event(event), m_time(time) {}

	void event(EEvent event) { m_event = event; }
	EEvent event() const { return m_event; }
	void time(double time) { m_time = time; }
	double time() const { return m_time; }

	bool operator <(const CTerranEvent &event) const { return m_time < event.time(); }

protected:
	EEvent m_event;
	double m_time;
};

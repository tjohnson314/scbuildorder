#pragma once

class CZergEvent
{
public:
	enum EEvent
	{
		// Buildings
		eSpawnHatchery
		, eSpawnExtractor
		, eSpawnSpawningPool
		, eSpawnCreepTumor
		, eSpawnEvolutionChamber
		, eSpawnSpineCrawler
		, eSpawnSporeCrawler
		, eSpawnRoachWarren
		, eSpawnLair
		, eSpawnHydraliskDen
		, eSpawnBanelingNest
		, eSpawnSpire
		, eSpawnInfestationPit
		, eSpawnNydusNetwork
		, eSpawnHive
		, eSpawnUltraliskCavern
		, eSpawnGreaterSpire

		, eExtractorTrickFinished
		, eCreepTumorAvailable

		// Units
		, eSpawnLarva1
		, eSpawnLarva2
		, eSpawnLarva3
		, eSpawnLarva4
		, eSpawnQueenLarvae1
		, eSpawnQueenLarvae2
		, eSpawnQueenLarvae3
		, eSpawnQueenLarvae4
		, eSpawnDrone
		, eSpawnOverlord
		, eSpawnQueen
		, eSpawnZergling
		, eSpawnRoach
		, eSpawnHydralisk
		, eSpawnBaneling
		, eSpawnOverseer
		, eSpawnInfestor
		, eSpawnMutalisk
		, eSpawnCorruptor
		, eSpawnUltralisk
		, eSpawnBroodlord

		// Research
		, eResearchAdrenalGlandsComplete
		, eResearchMetabolicBoostComplete
		, eResearchMeleeAttacks1Complete
		, eResearchMeleeAttacks2Complete
		, eResearchMeleeAttacks3Complete
		, eResearchGroundCarapace1Complete
		, eResearchGroundCarapace2Complete
		, eResearchGroundCarapace3Complete
		, eResearchMissileAttacks1Complete
		, eResearchMissileAttacks2Complete
		, eResearchMissileAttacks3Complete
		, eResearchGlialReconstitutionComplete
		, eResearchTunnelingClawsComplete
		, eResearchCentrifugalHooksComplete
		, eResearchBurrowComplete
		, eResearchPneumaticCarapaceComplete
		, eResearchVentralSacsComplete
		, eResearchGroovedSpinesComplete
		, eResearchPathogenGlandsComplete
		, eResearchNeuralParasiteComplete
		, eResearchFlyerAttacks1Complete
		, eResearchFlyerAttacks2Complete
		, eResearchFlyerAttacks3Complete
		, eResearchFlyerCarapace1Complete
		, eResearchFlyerCarapace2Complete
		, eResearchFlyerCarapace3Complete
		, eResearchChitinousPlatingComplete

		, eQueenReady
		, eDroneStartMiningMinerals
		, eDroneStartMiningGas
	};

	CZergEvent(EEvent event, double time) : m_event(event), m_time(time) {}

	void event(EEvent event) { m_event = event; }
	EEvent event() const { return m_event; }
	void time(double time) { m_time = time; }
	double time() const { return m_time; }

	bool operator <(const CZergEvent &event) const { return m_time < event.time(); }

protected:
	EEvent m_event;
	double m_time;
};

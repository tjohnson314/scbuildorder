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
		, eSpawnCreepTumour
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

		, eCreepTumourAvailable

		// Units
		, eSpawnLarva
		, eSpawnQueenLarva
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

		, eExtractorTrickFinished

		, eBuildingDroneBackToMinerals
		, eBuildingDroneBackToGas

		// Abilities

		// Research
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

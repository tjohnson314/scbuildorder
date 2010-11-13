#include "stdafx.h"
#include "ProtossState.h"
#include "ProtossEvent.h"
#include "GameCalcs.h"

#define CHRONOBOOST_GAIN	(2.0/3.0)
#define CHRONOBOOST_LOSS	(1.5)

CProtossState::CProtossState()
: m_minerals(0), m_gas(0)
, m_nexusCount(0), m_pylonCount(0), m_assimilatorCount(0), m_gatewayCount(0), m_warpgateCount(0), m_forgeCount(0), m_cyberneticsCoreCount(0), m_twilightCouncilCount(0), m_templarArchivesCount(0), m_darkShrineCount(0), m_roboticsFacilityCount(0), m_roboticsBayCount(0), m_stargateCount(0), m_fleetBeaconCount(0)
, m_nexusUnderConstruction(0), m_assimilatorUnderConstruction(0), m_pylonUnderConstruction(0), m_gatewayUnderConstruction(0), m_warpgateUnderConstruction(0), m_forgeUnderConstruction(0), m_cyberneticsCoreUnderConstruction(0), m_twilightCouncilUnderConstruction(0), m_templarArchivesUnderConstruction(0), m_darkShrineUnderConstruction(0), m_roboticsFacilityUnderConstruction(0), m_roboticsBayUnderConstruction(0), m_stargateUnderConstruction(0), m_fleetBeaconUnderConstruction(0)
, m_nexusInUse(0), m_gatewayInUse(0), m_warpgateOnCooldown(0), m_forgeInUse(0), m_cyberneticsCoreInUse(0), m_twilightCouncilInUse(0), m_templarArchivesInUse(0), m_darkShrineInUse(0), m_roboticsFacilityInUse(0), m_roboticsBayInUse(0), m_stargateInUse(0), m_fleetBeaconInUse(0)
, m_nexusChronoCount(0), m_gatewayChronoCount(0), m_warpgateChronoCount(0), m_forgeChronoCount(0), m_cyberneticsCoreChronoCount(0), m_twilightCouncilChronoCount(0), m_templarArchivesChronoCount(0), m_darkShrineChronoCount(0), m_roboticsFacilityChronoCount(0), m_roboticsBayChronoCount(0), m_stargateChronoCount(0), m_fleetBeaconChronoCount(0)
, m_nexusChronoAvailable(0), m_gatewayChronoAvailable(0), m_warpgateChronoAvailable(0), m_cyberneticsCoreChronoAvailable(0), m_twilightCouncilChronoAvailable(0), m_templarArchivesChronoAvailable(0), m_darkShrineChronoAvailable(0), m_roboticsFacilityChronoAvailable(0), m_roboticsBayChronoAvailable(0), m_stargateChronoAvailable(0), m_fleetBeaconChronoAvailable(0)
, m_probeCount(0), m_zealotCount(0), m_stalkerCount(0), m_sentryCount(0), m_highTemplarCount(0), m_darkTemplarCount(0), m_warpPrismCount(0), m_observerCount(0), m_immortalCount(0), m_colossusCount(0), m_phoenixCount(0), m_voidRayCount(0), m_carrierCount(0), m_mothershipCount(0)
, m_probeUnderConstruction(0), m_zealotUnderConstruction(0), m_stalkerUnderConstruction(0), m_sentryUnderConstruction(0), m_highTemplarUnderConstruction(0), m_darkTemplarUnderConstruction(0), m_warpPrismUnderConstruction(0), m_observerUnderConstruction(0), m_immortalUnderConstruction(0), m_colossusUnderConstruction(0), m_phoenixUnderConstruction(0), m_voidRayUnderConstruction(0), m_carrierUnderConstruction(0), m_mothershipUnderConstruction(0)
, m_researchWarpgateCompleted(false), m_researchWarpgateUnderConstruction(false)
, m_probesOnMinerals(0), m_probesOnGas(0)
, m_supply(0), m_supplyCap(0), m_supplyCapUnderConstruction(0)
, m_mineralIncomeRate(0), m_gasIncomeRate(0)
, m_timeLastProbeMove(0), m_lastProbeMove(eProtossCommandNone)
{
	for(size_t i=0; i < 4; i++)
		m_nexusEnergy[i] = 0;
}

CProtossState::~CProtossState()
{
}

void CProtossState::SetInitialState()
{
	memset(this, 0, sizeof(CProtossState));
	m_minerals = 50;
	m_nexusCount = 1;
	m_probeCount = 6;
	m_probesOnMinerals = 6;

	RecalculateSupply();
	RecalculateSupplyCap();
	RecalculateSupplyCapUnderConstruction();
	RecalculateMineralIncomeRate();
	RecalculateGasIncomeRate();
}

void CProtossState::operator=(const CProtossState &state)
{
	memmove(this, &state, sizeof(CProtossState));
}

bool CProtossState::operator>=(const CProtossState &state) const
{
	if(m_minerals < state.m_minerals)
		return false;
	if(m_gas < state.m_gas)
		return false;
	for(size_t i=0; i < 4; i++)
	{
		if(m_nexusEnergy[i] < state.m_nexusEnergy[i])
			return false;
	}

	if(m_nexusCount < state.m_nexusCount)
		return false;
	if(m_pylonCount < state.m_pylonCount)
		return false;
	if(m_assimilatorCount < state.m_assimilatorCount)
		return false;
	if(m_gatewayCount < state.m_gatewayCount)
		return false;
	if(m_warpgateCount < state.m_warpgateCount)
		return false;
	if(m_forgeCount < state.m_forgeCount)
		return false;
	if(m_cyberneticsCoreCount < state.m_cyberneticsCoreCount)
		return false;
	if(m_twilightCouncilCount < state.m_twilightCouncilCount)
		return false;
	if(m_templarArchivesCount < state.m_templarArchivesCount)
		return false;
	if(m_darkShrineCount < state.m_darkShrineCount)
		return false;
	if(m_roboticsFacilityCount < state.m_roboticsFacilityCount)
		return false;
	if(m_roboticsBayCount < state.m_roboticsBayCount)
		return false;
	if(m_stargateCount < state.m_stargateCount)
		return false;
	if(m_fleetBeaconCount < state.m_fleetBeaconCount)
		return false;

	if(m_probeCount < state.m_probeCount)
		return false;
	if(m_zealotCount < state.m_zealotCount)
		return false;
	if(m_stalkerCount < state.m_stalkerCount)
		return false;
	if(m_sentryCount < state.m_sentryCount)
		return false;
	if(m_highTemplarCount < state.m_highTemplarCount)
		return false;
	if(m_darkTemplarCount < state.m_darkTemplarCount)
		return false;
	if(m_warpPrismCount < state.m_warpPrismCount)
		return false;
	if(m_observerCount < state.m_observerCount)
		return false;
	if(m_immortalCount < state.m_immortalCount)
		return false;
	if(m_colossusCount < state.m_colossusCount)
		return false;
	if(m_phoenixCount < state.m_phoenixCount)
		return false;
	if(m_voidRayCount < state.m_voidRayCount)
		return false;
	if(m_carrierCount < state.m_carrierCount)
		return false;
	if(m_mothershipCount < state.m_mothershipCount)
		return false;

	if(!m_researchWarpgateCompleted && state.m_researchWarpgateCompleted)
		return false;

	return true;
}

void CProtossState::intersection(const CProtossState &s1, const CProtossState &s2)
{
	m_minerals = mymin(s1.m_minerals, s2.m_minerals);
	m_gas = mymin(s1.m_gas, s2.m_gas);

	m_nexusCount = mymin(s1.m_nexusCount, s2.m_nexusCount);
	m_pylonCount = mymin(s1.m_pylonCount, s2.m_pylonCount);
	m_assimilatorCount = mymin(s1.m_assimilatorCount, s2.m_assimilatorCount);
	m_gatewayCount = mymin(s1.m_gatewayCount, s2.m_gatewayCount);
	m_warpgateCount = mymin(s1.m_warpgateCount, s2.m_warpgateCount);
	m_forgeCount = mymin(s1.m_forgeCount, s2.m_forgeCount);
	m_cyberneticsCoreCount = mymin(s1.m_cyberneticsCoreCount, s2.m_cyberneticsCoreCount);
	m_twilightCouncilCount = mymin(s1.m_twilightCouncilCount, s2.m_twilightCouncilCount);
	m_templarArchivesCount = mymin(s1.m_templarArchivesCount, s2.m_templarArchivesCount);
	m_darkShrineCount = mymin(s1.m_darkShrineCount, s2.m_darkShrineCount);
	m_roboticsFacilityCount = mymin(s1.m_roboticsFacilityCount, s2.m_roboticsFacilityCount);
	m_roboticsBayCount = mymin(s1.m_roboticsBayCount, s2.m_roboticsBayCount);
	m_stargateCount = mymin(s1.m_stargateCount, s2.m_stargateCount);
	m_fleetBeaconCount = mymin(s1.m_fleetBeaconCount, s2.m_fleetBeaconCount);

	m_probeCount = mymin(s1.m_probeCount, s2.m_probeCount);
	m_zealotCount = mymin(s1.m_zealotCount, s2.m_zealotCount);
	m_stalkerCount = mymin(s1.m_stalkerCount, s2.m_stalkerCount);
	m_sentryCount = mymin(s1.m_sentryCount, s2.m_sentryCount);
	m_highTemplarCount = mymin(s1.m_highTemplarCount, s2.m_highTemplarCount);
	m_darkTemplarCount = mymin(s1.m_darkTemplarCount, s2.m_darkTemplarCount);
	m_warpPrismCount = mymin(s1.m_warpPrismCount, s2.m_warpPrismCount);
	m_observerCount = mymin(s1.m_observerCount, s2.m_observerCount);
	m_immortalCount = mymin(s1.m_immortalCount, s2.m_immortalCount);
	m_colossusCount = mymin(s1.m_colossusCount, s2.m_colossusCount);
	m_phoenixCount = mymin(s1.m_phoenixCount, s2.m_phoenixCount);
	m_voidRayCount = mymin(s1.m_voidRayCount, s2.m_voidRayCount);
	m_carrierCount = mymin(s1.m_carrierCount, s2.m_carrierCount);
	m_mothershipCount = mymin(s1.m_mothershipCount, s2.m_mothershipCount);

	m_researchWarpgateCompleted = s1.m_researchWarpgateCompleted && s2.m_researchWarpgateCompleted;
}

void CProtossState::operator-=(const CProtossState &state)
{
	m_minerals -= state.m_minerals;
	m_gas -= state.m_gas;
	for(size_t i=0; i < 4; i++)
		m_nexusEnergy[i] -= state.m_nexusEnergy[i];

	m_nexusCount -= state.m_nexusCount;
	m_pylonCount -= state.m_pylonCount;
	m_assimilatorCount -= state.m_assimilatorCount;
	m_gatewayCount -= state.m_gatewayCount;
	m_warpgateCount -= state.m_warpgateCount;
	m_forgeCount -= state.m_forgeCount;
	m_cyberneticsCoreCount -= state.m_cyberneticsCoreCount;
	m_twilightCouncilCount -= state.m_twilightCouncilCount;
	m_templarArchivesCount -= state.m_templarArchivesCount;
	m_darkShrineCount -= state.m_darkShrineCount;
	m_roboticsFacilityCount -= state.m_roboticsFacilityCount;
	m_roboticsBayCount -= state.m_roboticsBayCount;
	m_stargateCount -= state.m_stargateCount;
	m_fleetBeaconCount -= state.m_fleetBeaconCount;

	m_probeCount -= state.m_probeCount;
	m_zealotCount -= state.m_zealotCount;
	m_stalkerCount -= state.m_stalkerCount;
	m_sentryCount -= state.m_sentryCount;
	m_highTemplarCount -= state.m_highTemplarCount;
	m_darkTemplarCount -= state.m_darkTemplarCount;
	m_warpPrismCount -= state.m_warpPrismCount;
	m_observerCount -= state.m_observerCount;
	m_immortalCount -= state.m_immortalCount;
	m_colossusCount -= state.m_colossusCount;
	m_phoenixCount -= state.m_phoenixCount;
	m_voidRayCount -= state.m_voidRayCount;
	m_carrierCount -= state.m_carrierCount;
	m_mothershipCount -= state.m_mothershipCount;
}

double CProtossState::value() const
{
	double value = 0;

	value += m_minerals * 1;
	value += m_gas * 2;
	for(size_t i=0; i < 4 && i < m_nexusCount; i++)
		value += m_nexusEnergy[i] * 0.2;

	value += m_nexusCount * 400;
	value += m_assimilatorCount * 75;
	value += m_pylonCount * 100;
	value += (m_gatewayCount - m_warpgateCount) * 150;
	value += m_warpgateCount * 150;
	value += m_forgeCount * 150;
	value += m_cyberneticsCoreCount * 150;
	value += m_twilightCouncilCount * 350;
	value += m_templarArchivesCount * 550;
	value += m_darkShrineCount * 650;
	value += m_roboticsFacilityCount * 400;
	value += m_roboticsBayCount * 600;
	value += m_stargateCount * 450;
	value += m_fleetBeaconCount * 700;

	value += m_probeCount * 50;
	value += m_zealotCount * 100;
	value += m_stalkerCount * 225;
	value += m_sentryCount * 250;
	value += m_highTemplarCount * 350;
	value += m_darkTemplarCount * 350;
	value += m_warpPrismCount * 200;
	value += m_observerCount * 250;
	value += m_immortalCount * 450;
	value += m_colossusCount * 700;
	value += m_phoenixCount * 350;
	value += m_voidRayCount * 550;
	value += m_carrierCount * 850;
	value += m_mothershipCount * 1200;

	if(m_researchWarpgateCompleted)
		value += 150;

	return value;
}

bool CProtossState::GetResourceWaitTime(const CResourceCost &cost, double &resourceWaitTime) const
{
	double mineralsRequired = cost.m_minerals - m_minerals;
	double gasRequired = cost.m_gas - m_gas;
	double maxNexusEnergy = 0;
	for(size_t i=0; i < 4 && i < m_nexusCount; i++)
		maxNexusEnergy = max(maxNexusEnergy, m_nexusEnergy[i]);
	double nexusEnergyRequired = cost.m_nexusEnergy - maxNexusEnergy;

	double mineralTimeRequired = 0, gasTimeRequired = 0, nexusTimeRequired = 0;
	if(mineralsRequired > 0)
	{
		if(m_mineralIncomeRate <= 0)
			return false;
		mineralTimeRequired = mineralsRequired / m_mineralIncomeRate;
	}
	if(gasRequired > 0)
	{
		if(m_gasIncomeRate <= 0)
			return false;
		gasTimeRequired = gasRequired / m_gasIncomeRate;
	}
	if(nexusEnergyRequired > 0)
	{
		if(m_nexusCount <= 0)
			return false;

		nexusTimeRequired = nexusEnergyRequired / 0.5625;
	}

	resourceWaitTime = max(max(mineralTimeRequired, gasTimeRequired), nexusTimeRequired);

	return true;
}

bool CProtossState::HasResources(const CResourceCost &cost) const
{
	if(m_minerals < cost.m_minerals)
		return false;
	if(m_gas < cost.m_gas)
		return false;
	if(cost.m_nexusEnergy > 0)
	{
		double maxNexusEnergy = 0;
		for(size_t i=0; i < 4 && i < m_nexusCount; i++)
		{
			if(m_nexusEnergy[i] > maxNexusEnergy)
			{
				maxNexusEnergy = m_nexusEnergy[i];
				if(maxNexusEnergy > cost.m_nexusEnergy)
					break;
			}
		}
		if(maxNexusEnergy < cost.m_nexusEnergy)
			return false;
	}

	return true;
}

void CProtossState::SpendResources(const CResourceCost &cost)
{
	m_minerals -= cost.m_minerals;
	m_gas -= cost.m_gas;
	if(cost.m_nexusEnergy > 0)
	{
		size_t maxNexusEnergyIndex = 0;
		double maxNexusEnergy = 0;
		for(size_t i=0; i < 4 && i < m_nexusCount; i++)
		{
			if(m_nexusEnergy[i] > maxNexusEnergy)
			{
				maxNexusEnergyIndex = i;
				maxNexusEnergy = m_nexusEnergy[i];
			}
		}
		m_nexusEnergy[maxNexusEnergyIndex] -= cost.m_nexusEnergy;
	}
}

void CProtossState::ExecuteCommand(double &time, double timeLimit, EProtossCommand command, CLinkedList<CProtossEvent> *&events)
{
	switch(command)
	{
	case eProtossCommandBuildNexus:
		UseProbeForBuilding(30, time, events);
		AddEvent(events, CProtossEvent(CProtossEvent::eSpawnNexus, time + 100));
		m_nexusUnderConstruction++;
		RecalculateSupplyCapUnderConstruction();
		break;
	case eProtossCommandBuildPylon:
		UseProbeForBuilding(10, time, events);
		AddEvent(events, CProtossEvent(CProtossEvent::eSpawnPylon, time + 25));
		m_pylonUnderConstruction++;
		RecalculateSupplyCapUnderConstruction();
		break;
	case eProtossCommandBuildAssimilator:
		UseProbeForBuilding(4, time, events);
		AddEvent(events, CProtossEvent(CProtossEvent::eSpawnAssimilator, time + 30));
		m_assimilatorUnderConstruction++;
		break;
	case eProtossCommandBuildGateway:
		UseProbeForBuilding(10, time, events);
		AddEvent(events, CProtossEvent(CProtossEvent::eSpawnGateway, time + 65));
		m_gatewayUnderConstruction++;
		break;
	case eProtossCommandConvertGatewayToWarpgate:
		if(m_gatewayChronoAvailable > 0)
		{
			m_gatewayChronoAvailable--;
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnChronoWarpgate, time + 10 * CHRONOBOOST_GAIN));
		}
		else
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnWarpgate, time + 10));
		m_gatewayInUse++;
		m_warpgateUnderConstruction++;
		break;
	case eProtossCommandBuildForge:
		UseProbeForBuilding(10, time, events);
		AddEvent(events, CProtossEvent(CProtossEvent::eSpawnForge, time + 45));
		m_forgeUnderConstruction++;
		break;
	case eProtossCommandBuildCyberneticsCore:
		UseProbeForBuilding(10, time, events);
		AddEvent(events, CProtossEvent(CProtossEvent::eSpawnCyberneticsCore, time + 50));
		m_cyberneticsCoreUnderConstruction++;
		break;
	case eProtossCommandBuildTwilightCouncil:
		UseProbeForBuilding(10, time, events);
		AddEvent(events, CProtossEvent(CProtossEvent::eSpawnTwilightCouncil, time + 50));
		m_twilightCouncilUnderConstruction++;
		break;
	case eProtossCommandBuildTemplarArchives:
		UseProbeForBuilding(10, time, events);
		AddEvent(events, CProtossEvent(CProtossEvent::eSpawnTemplarArchives, time + 50));
		m_templarArchivesUnderConstruction++;
		break;
	case eProtossCommandBuildDarkShrine:
		UseProbeForBuilding(10, time, events);
		AddEvent(events, CProtossEvent(CProtossEvent::eSpawnDarkShrine, time + 100));
		m_darkShrineUnderConstruction++;
		break;
	case eProtossCommandBuildRoboticsFacility:
		UseProbeForBuilding(10, time, events);
		AddEvent(events, CProtossEvent(CProtossEvent::eSpawnRoboticsFacility, time + 65));
		m_roboticsFacilityUnderConstruction++;
		break;
	case eProtossCommandBuildRoboticsBay:
		UseProbeForBuilding(10, time, events);
		AddEvent(events, CProtossEvent(CProtossEvent::eSpawnRoboticsBay, time + 65));
		m_roboticsBayUnderConstruction++;
		break;
	case eProtossCommandBuildStargate:
		UseProbeForBuilding(10, time, events);
		AddEvent(events, CProtossEvent(CProtossEvent::eSpawnStargate, time + 60));
		m_stargateUnderConstruction++;
		break;
	case eProtossCommandBuildFleetBeacon:
		UseProbeForBuilding(10, time, events);
		AddEvent(events, CProtossEvent(CProtossEvent::eSpawnFleetBeacon, time + 60));
		m_fleetBeaconUnderConstruction++;
		break;

	case eProtossCommandBuildProbe:
		if(m_nexusChronoAvailable > 0)
		{
			m_nexusChronoAvailable--;
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnChronoProbe, time + 17 * CHRONOBOOST_GAIN));
		}
		else
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnProbe, time + 17));
		m_nexusInUse++;
		m_probeUnderConstruction++;
		RecalculateSupply();
		break;
	case eProtossCommandBuildZealot:
		if(m_warpgateChronoAvailable > 0)
		{
			m_warpgateChronoAvailable--;
			m_warpgateOnCooldown++;
			AddEvent(events, CProtossEvent(CProtossEvent::eChronoWarpgateOffCooldown, time + 28 * CHRONOBOOST_GAIN));
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnWarpgateZealot, time + 5));
		}
		else if(m_warpgateOnCooldown < m_warpgateCount)
		{
			m_warpgateOnCooldown++;
			AddEvent(events, CProtossEvent(CProtossEvent::eWarpgateOffCooldown, time + 28));
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnWarpgateZealot, time + 5));
		}
		else if(m_gatewayChronoAvailable > 0)
		{
			m_gatewayChronoAvailable--;
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnChronoZealot, time + 38 * CHRONOBOOST_GAIN));
		}
		else
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnZealot, time + 38));
		m_gatewayInUse++;
		m_zealotUnderConstruction++;
		RecalculateSupply();
		break;
	case eProtossCommandBuildStalker:
		if(m_warpgateChronoAvailable > 0)
		{
			m_warpgateChronoAvailable--;
			m_warpgateOnCooldown++;
			AddEvent(events, CProtossEvent(CProtossEvent::eChronoWarpgateOffCooldown, time + 32 * CHRONOBOOST_GAIN));
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnWarpgateStalker, time + 5));
		}
		else if(m_warpgateOnCooldown < m_warpgateCount)
		{
			m_warpgateOnCooldown++;
			AddEvent(events, CProtossEvent(CProtossEvent::eWarpgateOffCooldown, time + 32));
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnWarpgateStalker, time + 5));
		}
		else if(m_gatewayChronoAvailable > 0)
		{
			m_gatewayChronoAvailable--;
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnChronoStalker, time + 42 * CHRONOBOOST_GAIN));
		}
		else
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnStalker, time + 42));
		m_gatewayInUse++;
		m_stalkerUnderConstruction++;
		RecalculateSupply();
		break;
	case eProtossCommandBuildSentry:
		if(m_warpgateChronoAvailable > 0)
		{
			m_warpgateChronoAvailable--;
			m_warpgateOnCooldown++;
			AddEvent(events, CProtossEvent(CProtossEvent::eChronoWarpgateOffCooldown, time + 32 * CHRONOBOOST_GAIN));
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnWarpgateSentry, time + 5));
		}
		else if(m_warpgateOnCooldown < m_warpgateCount)
		{
			m_warpgateOnCooldown++;
			AddEvent(events, CProtossEvent(CProtossEvent::eWarpgateOffCooldown, time + 32));
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnWarpgateSentry, time + 5));
		}
		else if(m_gatewayChronoAvailable > 0)
		{
			m_gatewayChronoAvailable--;
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnChronoSentry, time + 42 * CHRONOBOOST_GAIN));
		}
		else
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnSentry, time + 42));
		m_gatewayInUse++;
		m_sentryUnderConstruction++;
		RecalculateSupply();
		break;
	case eProtossCommandBuildHighTemplar:
		if(m_warpgateChronoAvailable > 0)
		{
			m_warpgateChronoAvailable--;
			m_warpgateOnCooldown++;
			AddEvent(events, CProtossEvent(CProtossEvent::eChronoWarpgateOffCooldown, time + 45 * CHRONOBOOST_GAIN));
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnWarpgateHighTemplar, time + 5));
		}
		else if(m_warpgateOnCooldown < m_warpgateCount)
		{
			m_warpgateOnCooldown++;
			AddEvent(events, CProtossEvent(CProtossEvent::eWarpgateOffCooldown, time + 45));
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnWarpgateHighTemplar, time + 5));
		}
		else if(m_gatewayChronoAvailable > 0)
		{
			m_gatewayChronoAvailable--;
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnChronoHighTemplar, time + 55 * CHRONOBOOST_GAIN));
		}
		else
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnHighTemplar, time + 55));
		m_gatewayInUse++;
		m_highTemplarUnderConstruction++;
		RecalculateSupply();
		break;
	case eProtossCommandBuildDarkTemplar:
		if(m_warpgateChronoAvailable > 0)
		{
			m_warpgateChronoAvailable--;
			m_warpgateOnCooldown++;
			AddEvent(events, CProtossEvent(CProtossEvent::eChronoWarpgateOffCooldown, time + 45 * CHRONOBOOST_GAIN));
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnWarpgateDarkTemplar, time + 5));
		}
		else if(m_warpgateOnCooldown < m_warpgateCount)
		{
			m_warpgateOnCooldown++;
			AddEvent(events, CProtossEvent(CProtossEvent::eWarpgateOffCooldown, time + 45));
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnWarpgateDarkTemplar, time + 5));
		}
		else if(m_gatewayChronoAvailable > 0)
		{
			m_gatewayChronoAvailable--;
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnChronoDarkTemplar, time + 55 * CHRONOBOOST_GAIN));
		}
		else
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnDarkTemplar, time + 55));
		m_gatewayInUse++;
		m_darkTemplarUnderConstruction++;
		RecalculateSupply();
		break;
	case eProtossCommandBuildWarpPrism:
		if(m_roboticsFacilityChronoAvailable > 0)
		{
			m_roboticsFacilityChronoAvailable--;
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnChronoWarpPrism, time + 50 * CHRONOBOOST_GAIN));
		}
		else
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnWarpPrism, time + 50));
		m_roboticsFacilityInUse++;
		m_warpPrismUnderConstruction++;
		RecalculateSupply();
		break;
	case eProtossCommandBuildObserver:
		if(m_roboticsFacilityChronoAvailable > 0)
		{
			m_roboticsFacilityChronoAvailable--;
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnChronoObserver, time + 40 * CHRONOBOOST_GAIN));
		}
		else
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnObserver, time + 40));
		m_roboticsFacilityInUse++;
		m_observerUnderConstruction++;
		RecalculateSupply();
		break;
	case eProtossCommandBuildImmortal:
		if(m_roboticsFacilityChronoAvailable > 0)
		{
			m_roboticsFacilityChronoAvailable--;
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnChronoImmortal, time + 55 * CHRONOBOOST_GAIN));
		}
		else
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnImmortal, time + 55));
		m_roboticsFacilityInUse++;
		m_immortalUnderConstruction++;
		RecalculateSupply();
		break;
	case eProtossCommandBuildColossus:
		if(m_roboticsFacilityChronoAvailable > 0)
		{
			m_roboticsFacilityChronoAvailable--;
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnChronoColossus, time + 75 * CHRONOBOOST_GAIN));
		}
		else
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnColossus, time + 75));
		m_roboticsFacilityInUse++;
		m_colossusUnderConstruction++;
		RecalculateSupply();
		break;
	case eProtossCommandBuildPhoenix:
		if(m_stargateChronoAvailable > 0)
		{
			m_stargateChronoAvailable--;
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnChronoPhoenix, time + 45 * CHRONOBOOST_GAIN));
		}
		else
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnPhoenix, time + 45));
		m_stargateInUse++;
		m_phoenixUnderConstruction++;
		RecalculateSupply();
		break;
	case eProtossCommandBuildVoidRay:
		if(m_stargateChronoAvailable > 0)
		{
			m_stargateChronoAvailable--;
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnChronoVoidRay, time + 60 * CHRONOBOOST_GAIN));
		}
		else
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnVoidRay, time + 60));
		m_stargateInUse++;
		m_voidRayUnderConstruction++;
		RecalculateSupply();
		break;
	case eProtossCommandBuildCarrier:
		if(m_stargateChronoAvailable > 0)
		{
			m_stargateChronoAvailable--;
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnChronoCarrier, time + 75 * CHRONOBOOST_GAIN));
		}
		else
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnCarrier, time + 75));
		m_stargateInUse++;
		m_carrierUnderConstruction++;
		RecalculateSupply();
		break;
	case eProtossCommandBuildMothership:
		if(m_nexusChronoAvailable > 0)
		{
			m_nexusChronoAvailable--;
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnChronoMothership, time + 75 * CHRONOBOOST_GAIN));
		}
		else
			AddEvent(events, CProtossEvent(CProtossEvent::eSpawnMothership, time + 75));
		m_nexusInUse++;
		m_mothershipUnderConstruction++;
		RecalculateSupply();
		break;

	case eProtossCommandChronoNexus:
		AddEvent(events, CProtossEvent(CProtossEvent::eChronoNexusEnd, time + 20));
		m_nexusChronoCount++;

		// Find last Build Probe event and make 20% faster
		if(events && m_nexusInUse > m_nexusChronoCount - 1)
		{
			CLinkedList<CProtossEvent> *prevEntry = 0, *lastEntry = 0, *curEntry = events;
			if(curEntry->GetData().event() == CProtossEvent::eSpawnProbe
				|| curEntry->GetData().event() == CProtossEvent::eSpawnMothership)
				lastEntry = curEntry;
			while(curEntry->GetNext() != 0)
			{
				if(curEntry->GetNext()->GetData().event() == CProtossEvent::eSpawnProbe
					|| curEntry->GetNext()->GetData().event() == CProtossEvent::eSpawnMothership)
				{
					prevEntry = curEntry;
					lastEntry = curEntry->GetNext();
				}

				curEntry = curEntry->GetNext();
			}

			if(lastEntry)
			{
				if(prevEntry)
					prevEntry->SetNext(lastEntry->GetNext());
				else // Must be first entry
					events = lastEntry->GetNext();

				switch(lastEntry->GetData().event())
				{
				case CProtossEvent::eSpawnProbe:
					lastEntry->GetData().event(CProtossEvent::eSpawnChronoProbe);
					break;
				case CProtossEvent::eSpawnMothership:
					lastEntry->GetData().event(CProtossEvent::eSpawnChronoMothership);
					break;
				}
				lastEntry->GetData().time(time + (lastEntry->GetData().time() - time) * CHRONOBOOST_GAIN);
				AddEvent(events, lastEntry->GetData());
				delete lastEntry;
			}
			else
				m_nexusChronoAvailable++;
		}
		break;
	case eProtossCommandChronoGateway:
		AddEvent(events, CProtossEvent(CProtossEvent::eChronoGatewayEnd, time + 20));
		m_gatewayChronoCount++;

		// Find last build gateway unit event and make 20% faster
		if(events)
		{
			CLinkedList<CProtossEvent> *prevEntry = 0, *lastEntry = 0, *curEntry = events;
			if(curEntry->GetData().event() == CProtossEvent::eSpawnZealot
				|| curEntry->GetData().event() == CProtossEvent::eSpawnStalker
				|| curEntry->GetData().event() == CProtossEvent::eSpawnSentry
				|| curEntry->GetData().event() == CProtossEvent::eSpawnHighTemplar
				|| curEntry->GetData().event() == CProtossEvent::eSpawnDarkTemplar
				|| curEntry->GetData().event() == CProtossEvent::eSpawnWarpgate)
				lastEntry = curEntry;
			while(curEntry->GetNext() != 0)
			{
				if(curEntry->GetNext()->GetData().event() == CProtossEvent::eSpawnZealot
					|| curEntry->GetNext()->GetData().event() == CProtossEvent::eSpawnStalker
					|| curEntry->GetNext()->GetData().event() == CProtossEvent::eSpawnSentry
					|| curEntry->GetNext()->GetData().event() == CProtossEvent::eSpawnHighTemplar
					|| curEntry->GetNext()->GetData().event() == CProtossEvent::eSpawnDarkTemplar
					|| curEntry->GetNext()->GetData().event() == CProtossEvent::eSpawnWarpgate)
				{
					prevEntry = curEntry;
					lastEntry = curEntry->GetNext();
				}

				curEntry = curEntry->GetNext();
			}

			if(lastEntry)
			{
				if(prevEntry)
					prevEntry->SetNext(lastEntry->GetNext());
				else // Must be first entry
					events = lastEntry->GetNext();

				switch(lastEntry->GetData().event())
				{
				case CProtossEvent::eSpawnZealot:
					lastEntry->GetData().event(CProtossEvent::eSpawnChronoZealot);
					break;
				case CProtossEvent::eSpawnStalker:
					lastEntry->GetData().event(CProtossEvent::eSpawnChronoStalker);
					break;
				case CProtossEvent::eSpawnSentry:
					lastEntry->GetData().event(CProtossEvent::eSpawnChronoSentry);
					break;
				case CProtossEvent::eSpawnHighTemplar:
					lastEntry->GetData().event(CProtossEvent::eSpawnChronoHighTemplar);
					break;
				case CProtossEvent::eSpawnDarkTemplar:
					lastEntry->GetData().event(CProtossEvent::eSpawnChronoDarkTemplar);
					break;
				case CProtossEvent::eSpawnWarpgate:
					lastEntry->GetData().event(CProtossEvent::eSpawnChronoWarpgate);
					break;
				}
				lastEntry->GetData().time(time + (lastEntry->GetData().time() - time) * CHRONOBOOST_GAIN);
				AddEvent(events, lastEntry->GetData());
				delete lastEntry;
			}
			else
				m_gatewayChronoAvailable++;
		}
		break;
	case eProtossCommandChronoWarpgate:
		AddEvent(events, CProtossEvent(CProtossEvent::eChronoWarpgateEnd, time + 20));
		m_warpgateChronoCount++;

		// Find last warpgate cooldown event and make 20% faster
		if(events)
		{
			CLinkedList<CProtossEvent> *prevEntry = 0, *lastEntry = 0, *curEntry = events;
			if(curEntry->GetData().event() == CProtossEvent::eWarpgateOffCooldown)
				lastEntry = curEntry;
			while(curEntry->GetNext() != 0)
			{
				if(curEntry->GetNext()->GetData().event() == CProtossEvent::eWarpgateOffCooldown)
				{
					prevEntry = curEntry;
					lastEntry = curEntry->GetNext();
				}

				curEntry = curEntry->GetNext();
			}

			if(lastEntry)
			{
				if(prevEntry)
					prevEntry->SetNext(lastEntry->GetNext());
				else // Must be first entry
					events = lastEntry->GetNext();

				lastEntry->GetData().event(CProtossEvent::eChronoWarpgateOffCooldown);
				lastEntry->GetData().time(time + (lastEntry->GetData().time() - time) * CHRONOBOOST_GAIN);
				AddEvent(events, lastEntry->GetData());
				delete lastEntry;
			}
			else
				m_warpgateChronoAvailable++;
		}
		break;
	case eProtossCommandChronoCyberneticsCore:
		AddEvent(events, CProtossEvent(CProtossEvent::eChronoCyberneticsCoreEnd, time + 20));
		m_cyberneticsCoreChronoCount++;

		// Find last cybernetics core event and make 20% faster
		if(events)
		{
			CLinkedList<CProtossEvent> *prevEntry = 0, *lastEntry = 0, *curEntry = events;
			if(curEntry->GetData().event() == CProtossEvent::eCompleteWarpgateResearch)
				lastEntry = curEntry;
			while(curEntry->GetNext() != 0)
			{
				if(curEntry->GetNext()->GetData().event() == CProtossEvent::eCompleteWarpgateResearch)
				{
					prevEntry = curEntry;
					lastEntry = curEntry->GetNext();
				}

				curEntry = curEntry->GetNext();
			}

			if(lastEntry)
			{
				if(prevEntry)
					prevEntry->SetNext(lastEntry->GetNext());
				else // Must be first entry
					events = lastEntry->GetNext();

				lastEntry->GetData().event(CProtossEvent::eCompleteChronoWarpgateResearch);
				lastEntry->GetData().time(time + (lastEntry->GetData().time() - time) * CHRONOBOOST_GAIN);
				AddEvent(events, lastEntry->GetData());
				delete lastEntry;
			}
			else
				m_cyberneticsCoreChronoAvailable++;
		}
		break;
	case eProtossCommandChronoRoboticsFacility:
		AddEvent(events, CProtossEvent(CProtossEvent::eChronoRoboticsFacilityEnd, time + 20));
		m_roboticsFacilityChronoCount++;

		// Find last cybernetics core event and make 20% faster
		if(events)
		{
			CLinkedList<CProtossEvent> *prevEntry = 0, *lastEntry = 0, *curEntry = events;
			if(curEntry->GetData().event() == CProtossEvent::eSpawnWarpPrism
				|| curEntry->GetData().event() == CProtossEvent::eSpawnObserver
				|| curEntry->GetData().event() == CProtossEvent::eSpawnImmortal
				|| curEntry->GetData().event() == CProtossEvent::eSpawnColossus)
				lastEntry = curEntry;
			while(curEntry->GetNext() != 0)
			{
				if(curEntry->GetNext()->GetData().event() == CProtossEvent::eSpawnWarpPrism
					|| curEntry->GetNext()->GetData().event() == CProtossEvent::eSpawnObserver
					|| curEntry->GetNext()->GetData().event() == CProtossEvent::eSpawnImmortal
					|| curEntry->GetNext()->GetData().event() == CProtossEvent::eSpawnColossus)
				{
					prevEntry = curEntry;
					lastEntry = curEntry->GetNext();
				}

				curEntry = curEntry->GetNext();
			}

			if(lastEntry)
			{
				if(prevEntry)
					prevEntry->SetNext(lastEntry->GetNext());
				else // Must be first entry
					events = lastEntry->GetNext();

				switch(lastEntry->GetData().event())
				{
				case CProtossEvent::eSpawnWarpPrism:
					lastEntry->GetData().event(CProtossEvent::eSpawnChronoWarpPrism);
					break;
				case CProtossEvent::eSpawnObserver:
					lastEntry->GetData().event(CProtossEvent::eSpawnChronoObserver);
					break;
				case CProtossEvent::eSpawnImmortal:
					lastEntry->GetData().event(CProtossEvent::eSpawnChronoImmortal);
					break;
				case CProtossEvent::eSpawnColossus:
					lastEntry->GetData().event(CProtossEvent::eSpawnChronoColossus);
					break;
				}
				lastEntry->GetData().time(time + (lastEntry->GetData().time() - time) * CHRONOBOOST_GAIN);
				AddEvent(events, lastEntry->GetData());
				delete lastEntry;
			}
			else
				m_roboticsFacilityChronoAvailable++;
		}
		break;
	case eProtossCommandChronoStargate:
		AddEvent(events, CProtossEvent(CProtossEvent::eChronoStargateEnd, time + 20));
		m_stargateChronoCount++;

		// Find last cybernetics core event and make 20% faster
		if(events)
		{
			CLinkedList<CProtossEvent> *prevEntry = 0, *lastEntry = 0, *curEntry = events;
			if(curEntry->GetData().event() == CProtossEvent::eSpawnPhoenix
				|| curEntry->GetData().event() == CProtossEvent::eSpawnVoidRay
				|| curEntry->GetData().event() == CProtossEvent::eSpawnCarrier)
				lastEntry = curEntry;
			while(curEntry->GetNext() != 0)
			{
				if(curEntry->GetNext()->GetData().event() == CProtossEvent::eSpawnPhoenix
					|| curEntry->GetNext()->GetData().event() == CProtossEvent::eSpawnVoidRay
					|| curEntry->GetNext()->GetData().event() == CProtossEvent::eSpawnCarrier)
				{
					prevEntry = curEntry;
					lastEntry = curEntry->GetNext();
				}

				curEntry = curEntry->GetNext();
			}

			if(lastEntry)
			{
				if(prevEntry)
					prevEntry->SetNext(lastEntry->GetNext());
				else // Must be first entry
					events = lastEntry->GetNext();

				switch(lastEntry->GetData().event())
				{
				case CProtossEvent::eSpawnPhoenix:
					lastEntry->GetData().event(CProtossEvent::eSpawnChronoPhoenix);
					break;
				case CProtossEvent::eSpawnVoidRay:
					lastEntry->GetData().event(CProtossEvent::eSpawnChronoVoidRay);
					break;
				case CProtossEvent::eSpawnCarrier:
					lastEntry->GetData().event(CProtossEvent::eSpawnChronoCarrier);
					break;
				}
				lastEntry->GetData().time(time + (lastEntry->GetData().time() - time) * CHRONOBOOST_GAIN);
				AddEvent(events, lastEntry->GetData());
				delete lastEntry;
			}
			else
				m_stargateChronoAvailable++;
		}
		break;

	case eProtossCommandResearchWarpgate:
		if(m_cyberneticsCoreChronoAvailable > 0)
		{
			m_cyberneticsCoreChronoAvailable--;
			AddEvent(events, CProtossEvent(CProtossEvent::eCompleteChronoWarpgateResearch, time + 140 * CHRONOBOOST_GAIN));
		}
		else
			AddEvent(events, CProtossEvent(CProtossEvent::eCompleteWarpgateResearch, time + 140));
		m_cyberneticsCoreInUse++;
		m_researchWarpgateUnderConstruction = true;
		break;

	case eProtossCommandMoveProbeToGas:
		m_timeLastProbeMove = time;
		m_lastProbeMove = eProtossCommandMoveProbeToGas;
		m_probesOnMinerals--;
		m_probesOnGas++;
		RecalculateMineralIncomeRate();
		RecalculateGasIncomeRate();
		break;
	case eProtossCommandMoveProbeToMinerals:
		m_timeLastProbeMove = time;
		m_lastProbeMove = eProtossCommandMoveProbeToMinerals;
		m_probesOnGas--;
		m_probesOnMinerals++;
		RecalculateMineralIncomeRate();
		RecalculateGasIncomeRate();
		break;
	}
}

void CProtossState::ProcessEvent(double &time, CLinkedList<CProtossEvent> *&events)
{
	const CProtossEvent &event = events->GetData();

	ProgressTime(time, event.time() - time);

	switch(event.event())
	{
	case CProtossEvent::eSpawnNexus:
		m_nexusUnderConstruction--;
		m_nexusCount++;
		RecalculateMineralIncomeRate();
		RecalculateSupplyCap();
		break;
	case CProtossEvent::eSpawnAssimilator:
		m_assimilatorUnderConstruction--;
		m_assimilatorCount++;
		RecalculateGasIncomeRate();
		break;
	case CProtossEvent::eSpawnPylon:
		m_pylonUnderConstruction--;
		m_pylonCount++;
		RecalculateSupplyCap();
		break;
	case CProtossEvent::eSpawnGateway:
		m_gatewayUnderConstruction--;
		m_gatewayCount++;
		break;
	case CProtossEvent::eSpawnChronoWarpgate:
		m_warpgateChronoAvailable++;
		// Find the first ChronoGatewayEnd and convert to ChronoWarpgateEnd
		{
			CLinkedList<CProtossEvent> *curEntry = events;
			while(curEntry->GetNext() != 0)
			{
				CLinkedList<CProtossEvent> *chronoGatewayEnd = curEntry->GetNext();
				if(chronoGatewayEnd->GetData().event() == CProtossEvent::eChronoGatewayEnd)
				{
					chronoGatewayEnd->GetData().event(CProtossEvent::eChronoWarpgateEnd);
					break;
				}

				curEntry = chronoGatewayEnd;
			}
		}
	case CProtossEvent::eSpawnWarpgate:
		m_warpgateUnderConstruction--;
		m_warpgateCount++;
		m_gatewayInUse--;
		break;
	case CProtossEvent::eSpawnForge:
		m_forgeUnderConstruction--;
		m_forgeCount++;
		break;
	case CProtossEvent::eSpawnCyberneticsCore:
		m_cyberneticsCoreUnderConstruction--;
		m_cyberneticsCoreCount++;
		break;
	case CProtossEvent::eSpawnTwilightCouncil:
		m_twilightCouncilUnderConstruction--;
		m_twilightCouncilCount++;
		break;
	case CProtossEvent::eSpawnTemplarArchives:
		m_templarArchivesUnderConstruction--;
		m_templarArchivesCount++;
		break;
	case CProtossEvent::eSpawnDarkShrine:
		m_darkShrineUnderConstruction--;
		m_darkShrineCount++;
		break;
	case CProtossEvent::eSpawnRoboticsFacility:
		m_roboticsFacilityUnderConstruction--;
		m_roboticsFacilityCount++;
		break;
	case CProtossEvent::eSpawnRoboticsBay:
		m_roboticsBayUnderConstruction--;
		m_roboticsBayCount++;
		break;
	case CProtossEvent::eSpawnStargate:
		m_stargateUnderConstruction--;
		m_stargateCount++;
		break;
	case CProtossEvent::eSpawnFleetBeacon:
		m_fleetBeaconUnderConstruction--;
		m_fleetBeaconCount++;
		break;

	case CProtossEvent::eChronoWarpgateOffCooldown:
		m_warpgateChronoAvailable++;
	case CProtossEvent::eWarpgateOffCooldown:
		m_warpgateOnCooldown--;
		break;

	case CProtossEvent::eProbeStartMiningMinerals:
		m_probesOnMinerals++;
		RecalculateMineralIncomeRate();
		break;
	case CProtossEvent::eProbeStartMiningGas:
		m_probesOnGas++;
		RecalculateGasIncomeRate();
		break;

	case CProtossEvent::eSpawnChronoProbe:
		m_nexusChronoAvailable++;
	case CProtossEvent::eSpawnProbe:
		m_probeCount++;
		AddEvent(events, CProtossEvent(CProtossEvent::eProbeStartMiningMinerals, time + 2));
		m_nexusInUse--;
		m_probeUnderConstruction--;
		break;
	case CProtossEvent::eSpawnChronoZealot:
		m_gatewayChronoAvailable++;
	case CProtossEvent::eSpawnZealot:
		m_gatewayInUse--;
	case CProtossEvent::eSpawnWarpgateZealot:
		m_zealotCount++;
		m_zealotUnderConstruction--;
		break;
	case CProtossEvent::eSpawnChronoStalker:
		m_gatewayChronoAvailable++;
	case CProtossEvent::eSpawnStalker:
		m_gatewayInUse--;
	case CProtossEvent::eSpawnWarpgateStalker:
		m_stalkerCount++;
		m_stalkerUnderConstruction--;
		break;
	case CProtossEvent::eSpawnChronoSentry:
		m_gatewayChronoAvailable++;
	case CProtossEvent::eSpawnSentry:
		m_gatewayInUse--;
	case CProtossEvent::eSpawnWarpgateSentry:
		m_sentryCount++;
		m_sentryUnderConstruction--;
		break;
	case CProtossEvent::eSpawnChronoHighTemplar:
		m_gatewayChronoAvailable++;
	case CProtossEvent::eSpawnHighTemplar:
		m_gatewayInUse--;
	case CProtossEvent::eSpawnWarpgateHighTemplar:
		m_highTemplarCount++;
		m_highTemplarUnderConstruction--;
		break;
	case CProtossEvent::eSpawnChronoDarkTemplar:
		m_gatewayChronoAvailable++;
	case CProtossEvent::eSpawnDarkTemplar:
		m_gatewayInUse--;
	case CProtossEvent::eSpawnWarpgateDarkTemplar:
		m_darkTemplarCount++;
		m_darkTemplarUnderConstruction--;
		break;
	case CProtossEvent::eSpawnChronoWarpPrism:
		m_roboticsFacilityChronoAvailable++;
	case CProtossEvent::eSpawnWarpPrism:
		m_warpPrismCount++;
		m_roboticsFacilityInUse--;
		m_warpPrismUnderConstruction--;
		break;
	case CProtossEvent::eSpawnChronoObserver:
		m_roboticsFacilityChronoAvailable++;
	case CProtossEvent::eSpawnObserver:
		m_observerCount++;
		m_roboticsFacilityInUse--;
		m_observerUnderConstruction--;
		break;
	case CProtossEvent::eSpawnChronoImmortal:
		m_roboticsFacilityChronoAvailable++;
	case CProtossEvent::eSpawnImmortal:
		m_immortalCount++;
		m_roboticsFacilityInUse--;
		m_immortalUnderConstruction--;
		break;
	case CProtossEvent::eSpawnChronoColossus:
		m_roboticsFacilityChronoAvailable++;
	case CProtossEvent::eSpawnColossus:
		m_colossusCount++;
		m_roboticsFacilityInUse--;
		m_colossusUnderConstruction--;
		break;
	case CProtossEvent::eSpawnChronoPhoenix:
		m_stargateChronoAvailable++;
	case CProtossEvent::eSpawnPhoenix:
		m_phoenixCount++;
		m_stargateInUse--;
		m_phoenixUnderConstruction--;
		break;
	case CProtossEvent::eSpawnChronoVoidRay:
		m_stargateChronoAvailable++;
	case CProtossEvent::eSpawnVoidRay:
		m_voidRayCount++;
		m_stargateInUse--;
		m_voidRayUnderConstruction--;
		break;
	case CProtossEvent::eSpawnChronoCarrier:
		m_stargateChronoAvailable++;
	case CProtossEvent::eSpawnCarrier:
		m_carrierCount++;
		m_stargateInUse--;
		m_carrierUnderConstruction--;
		break;
	case CProtossEvent::eSpawnChronoMothership:
		m_nexusChronoAvailable++;
	case CProtossEvent::eSpawnMothership:
		m_mothershipCount++;
		m_nexusInUse--;
		m_mothershipUnderConstruction--;
		break;


	case CProtossEvent::eChronoNexusEnd:
		m_nexusChronoCount--;
		if(m_nexusChronoAvailable > 0)
			m_nexusChronoAvailable--;
		else
		{
			// Increase first Probe build time by 25%
			CLinkedList<CProtossEvent> *curEntry = events;
			while(curEntry->GetNext() != 0)
			{
				CLinkedList<CProtossEvent> *buildProbe = curEntry->GetNext();
				if(buildProbe->GetData().event() == CProtossEvent::eSpawnChronoProbe
					|| buildProbe->GetData().event() == CProtossEvent::eSpawnChronoMothership)
				{
					curEntry->SetNext(buildProbe->GetNext());
					switch(buildProbe->GetData().event())
					{
					case CProtossEvent::eSpawnChronoProbe:
						buildProbe->GetData().event(CProtossEvent::eSpawnProbe);
						break;
					case CProtossEvent::eSpawnChronoMothership:
						buildProbe->GetData().event(CProtossEvent::eSpawnMothership);
						break;
					}
					buildProbe->GetData().time(time + (buildProbe->GetData().time() - time) * CHRONOBOOST_LOSS);
					AddEvent(events, buildProbe->GetData());
					delete buildProbe;
					break;
				}
					
				curEntry = buildProbe;
			}
		}
		break;
	case CProtossEvent::eChronoGatewayEnd:
		m_gatewayChronoCount--;
		if(m_gatewayChronoAvailable > 0)
			m_gatewayChronoAvailable--;
		else
		{
			// Increase first gateway unit build time by 25%
			CLinkedList<CProtossEvent> *curEntry = events;
			while(curEntry->GetNext() != 0)
			{
				CLinkedList<CProtossEvent> *buildUnit = curEntry->GetNext();
				if(buildUnit->GetData().event() == CProtossEvent::eSpawnChronoZealot
					|| buildUnit->GetData().event() == CProtossEvent::eSpawnChronoStalker
					|| buildUnit->GetData().event() == CProtossEvent::eSpawnChronoSentry
					|| buildUnit->GetData().event() == CProtossEvent::eSpawnChronoHighTemplar
					|| buildUnit->GetData().event() == CProtossEvent::eSpawnChronoDarkTemplar
					|| buildUnit->GetData().event() == CProtossEvent::eSpawnChronoWarpgate)
				{
					curEntry->SetNext(buildUnit->GetNext());
					switch(buildUnit->GetData().event())
					{
					case CProtossEvent::eSpawnChronoZealot:
						buildUnit->GetData().event(CProtossEvent::eSpawnZealot);
						break;
					case CProtossEvent::eSpawnChronoStalker:
						buildUnit->GetData().event(CProtossEvent::eSpawnStalker);
						break;
					case CProtossEvent::eSpawnChronoSentry:
						buildUnit->GetData().event(CProtossEvent::eSpawnSentry);
						break;
					case CProtossEvent::eSpawnChronoHighTemplar:
						buildUnit->GetData().event(CProtossEvent::eSpawnHighTemplar);
						break;
					case CProtossEvent::eSpawnChronoDarkTemplar:
						buildUnit->GetData().event(CProtossEvent::eSpawnDarkTemplar);
						break;
					case CProtossEvent::eSpawnChronoWarpgate:
						buildUnit->GetData().event(CProtossEvent::eSpawnWarpgate);
						break;
					}
					buildUnit->GetData().time(time + (buildUnit->GetData().time() - time) * CHRONOBOOST_LOSS);
					AddEvent(events, buildUnit->GetData());
					delete buildUnit;
					break;
				}
					
				curEntry = buildUnit;
			}
		}
		break;
	case CProtossEvent::eChronoWarpgateEnd:
		m_warpgateChronoCount--;
		if(m_warpgateChronoAvailable > 0)
			m_warpgateChronoAvailable--;
		else
		{
			// Increase first warpgate cooldown time by 25%
			CLinkedList<CProtossEvent> *curEntry = events;
			while(curEntry->GetNext() != 0)
			{
				CLinkedList<CProtossEvent> *warpgateCooldown = curEntry->GetNext();
				if(warpgateCooldown->GetData().event() == CProtossEvent::eChronoWarpgateOffCooldown)
				{
					curEntry->SetNext(warpgateCooldown->GetNext());
					warpgateCooldown->GetData().event(CProtossEvent::eWarpgateOffCooldown);
					warpgateCooldown->GetData().time(time + (warpgateCooldown->GetData().time() - time) * CHRONOBOOST_LOSS);
					AddEvent(events, warpgateCooldown->GetData());
					delete warpgateCooldown;
					break;
				}

				curEntry = warpgateCooldown;
			}
		}
		break;
	case CProtossEvent::eChronoCyberneticsCoreEnd:
		m_cyberneticsCoreChronoCount--;
		if(m_cyberneticsCoreChronoAvailable > 0)
			m_cyberneticsCoreChronoAvailable--;
		else
		{
			// Increase first warpgate cooldown time by 25%
			CLinkedList<CProtossEvent> *curEntry = events;
			while(curEntry->GetNext() != 0)
			{
				CLinkedList<CProtossEvent> *cyberneticsCoreCooldown = curEntry->GetNext();
				if(cyberneticsCoreCooldown->GetData().event() == CProtossEvent::eCompleteChronoWarpgateResearch)
				{
					curEntry->SetNext(cyberneticsCoreCooldown->GetNext());
					cyberneticsCoreCooldown->GetData().event(CProtossEvent::eCompleteWarpgateResearch);
					cyberneticsCoreCooldown->GetData().time(time + (cyberneticsCoreCooldown->GetData().time() - time) * CHRONOBOOST_LOSS);
					AddEvent(events, cyberneticsCoreCooldown->GetData());
					delete cyberneticsCoreCooldown;
					break;
				}

				curEntry = cyberneticsCoreCooldown;
			}
		}
		break;
	case CProtossEvent::eChronoRoboticsFacilityEnd:
		m_roboticsFacilityChronoCount--;
		if(m_roboticsFacilityChronoAvailable > 0)
			m_roboticsFacilityChronoAvailable--;
		else
		{
			// Increase first gateway unit build time by 25%
			CLinkedList<CProtossEvent> *curEntry = events;
			while(curEntry->GetNext() != 0)
			{
				CLinkedList<CProtossEvent> *buildUnit = curEntry->GetNext();
				if(buildUnit->GetData().event() == CProtossEvent::eSpawnChronoWarpPrism
					|| buildUnit->GetData().event() == CProtossEvent::eSpawnChronoObserver
					|| buildUnit->GetData().event() == CProtossEvent::eSpawnChronoImmortal
					|| buildUnit->GetData().event() == CProtossEvent::eSpawnChronoColossus)
				{
					curEntry->SetNext(buildUnit->GetNext());
					switch(buildUnit->GetData().event())
					{
					case CProtossEvent::eSpawnChronoWarpPrism:
						buildUnit->GetData().event(CProtossEvent::eSpawnWarpPrism);
						break;
					case CProtossEvent::eSpawnChronoObserver:
						buildUnit->GetData().event(CProtossEvent::eSpawnObserver);
						break;
					case CProtossEvent::eSpawnChronoImmortal:
						buildUnit->GetData().event(CProtossEvent::eSpawnImmortal);
						break;
					case CProtossEvent::eSpawnChronoColossus:
						buildUnit->GetData().event(CProtossEvent::eSpawnColossus);
						break;
					}
					buildUnit->GetData().time(time + (buildUnit->GetData().time() - time) * CHRONOBOOST_LOSS);
					AddEvent(events, buildUnit->GetData());
					delete buildUnit;
					break;
				}
					
				curEntry = buildUnit;
			}
		}
		break;
	case CProtossEvent::eChronoStargateEnd:
		m_stargateChronoCount--;
		if(m_stargateChronoAvailable > 0)
			m_stargateChronoAvailable--;
		else
		{
			// Increase first gateway unit build time by 25%
			CLinkedList<CProtossEvent> *curEntry = events;
			while(curEntry->GetNext() != 0)
			{
				CLinkedList<CProtossEvent> *buildUnit = curEntry->GetNext();
				if(buildUnit->GetData().event() == CProtossEvent::eSpawnChronoPhoenix
					|| buildUnit->GetData().event() == CProtossEvent::eSpawnChronoVoidRay
					|| buildUnit->GetData().event() == CProtossEvent::eSpawnChronoCarrier)
				{
					curEntry->SetNext(buildUnit->GetNext());
					switch(buildUnit->GetData().event())
					{
					case CProtossEvent::eSpawnChronoPhoenix:
						buildUnit->GetData().event(CProtossEvent::eSpawnPhoenix);
						break;
					case CProtossEvent::eSpawnChronoVoidRay:
						buildUnit->GetData().event(CProtossEvent::eSpawnVoidRay);
						break;
					case CProtossEvent::eSpawnChronoCarrier:
						buildUnit->GetData().event(CProtossEvent::eSpawnCarrier);
						break;
					}
					buildUnit->GetData().time(time + (buildUnit->GetData().time() - time) * CHRONOBOOST_LOSS);
					AddEvent(events, buildUnit->GetData());
					delete buildUnit;
					break;
				}
					
				curEntry = buildUnit;
			}
		}
		break;

	case CProtossEvent::eCompleteChronoWarpgateResearch:
		m_cyberneticsCoreChronoAvailable++;
	case CProtossEvent::eCompleteWarpgateResearch:
		m_researchWarpgateCompleted = true;
		m_researchWarpgateUnderConstruction = false;
		break;
	}

	CLinkedList<CProtossEvent> *old = events;
	events = events->GetNext();
	delete old;
}

void CProtossState::AddRequirements()
{
	if(m_fleetBeaconCount == 0
		&& (m_carrierCount > 0 || m_mothershipCount > 0))
		m_fleetBeaconCount++;

	if(m_stargateCount == 0
		&& (m_fleetBeaconCount > 0
		|| m_phoenixCount > 0 || m_voidRayCount > 0))
		m_stargateCount++;

	if(m_roboticsBayCount == 0
		&& m_colossusCount > 0)
		m_roboticsBayCount++;

	if(m_roboticsFacilityCount == 0
		&& (m_roboticsBayCount > 0
		|| m_warpPrismCount > 0 || m_observerCount > 0 || m_immortalCount > 0))
		m_roboticsFacilityCount++;

	if(m_darkShrineCount == 0
		&& m_darkTemplarCount > 0)
		m_darkShrineCount++;

	if(m_templarArchivesCount == 0
		&& m_highTemplarCount > 0)
		m_templarArchivesCount++;

	if(m_twilightCouncilCount == 0
		&& (m_templarArchivesCount > 0 || m_darkShrineCount > 0))
		m_twilightCouncilCount++;

	if(!m_researchWarpgateCompleted
		&& (m_warpgateCount > 0))
		m_researchWarpgateCompleted = true;

	if(m_cyberneticsCoreCount == 0
		&& (m_roboticsFacilityCount > 0 || m_stargateCount > 0 || m_twilightCouncilCount > 0
			|| m_stalkerCount > 0 || m_sentryCount > 0
			|| m_researchWarpgateCompleted))
		m_cyberneticsCoreCount++;

	if(m_gatewayCount == 0
		&& (m_cyberneticsCoreCount > 0 || m_zealotCount > 0))
		m_gatewayCount++;

	if(m_assimilatorCount == 0
		&& (m_twilightCouncilCount > 0 || m_roboticsFacilityCount > 0 || m_stargateCount > 0
			|| m_stalkerCount > 0 || m_sentryCount > 0
			|| m_researchWarpgateCompleted))
		m_assimilatorCount++;

	if(m_pylonCount == 0
		&& (m_gatewayCount > 0))
		m_pylonCount++;
}

bool CProtossState::HasBuildingRequirements(double time, EProtossCommand command) const
{
	switch (command)
	{
	case eProtossCommandBuildNexus:
		return 0 < m_probesOnMinerals + m_probesOnGas + m_probeUnderConstruction;
	case eProtossCommandBuildPylon:
		return 0 < m_probesOnMinerals + m_probesOnGas + m_probeUnderConstruction;
	case eProtossCommandBuildAssimilator:
		return 0 < m_probesOnMinerals + m_probesOnGas + m_probeUnderConstruction;
	case eProtossCommandBuildGateway:
		return 0 < m_nexusCount + m_nexusUnderConstruction
			&& 0 < m_pylonCount + m_pylonUnderConstruction
			&& 0 < m_probesOnMinerals + m_probesOnGas + m_probeUnderConstruction;
	case eProtossCommandConvertGatewayToWarpgate:
		return 0 < m_gatewayCount - m_warpgateCount - m_warpgateUnderConstruction + m_gatewayUnderConstruction
			&& (m_researchWarpgateCompleted || m_researchWarpgateUnderConstruction)
			&& 0 < m_pylonCount + m_pylonUnderConstruction;
	case eProtossCommandBuildForge:
		return 0 < m_nexusCount + m_nexusUnderConstruction
			&& 0 < m_pylonCount + m_pylonUnderConstruction
			&& 0 < m_probesOnMinerals + m_probesOnGas + m_probeUnderConstruction;
	case eProtossCommandBuildCyberneticsCore:
		return 0 < m_gatewayCount + m_gatewayUnderConstruction
			&& 0 < m_pylonCount + m_pylonUnderConstruction
			&& 0 < m_probesOnMinerals + m_probesOnGas + m_probeUnderConstruction;
	case eProtossCommandBuildTwilightCouncil:
		return 0 < m_cyberneticsCoreCount + m_cyberneticsCoreUnderConstruction
			&& 0 < m_pylonCount + m_pylonUnderConstruction
			&& 0 < m_probesOnMinerals + m_probesOnGas + m_probeUnderConstruction;
	case eProtossCommandBuildTemplarArchives:
		return 0 < m_twilightCouncilCount + m_twilightCouncilUnderConstruction
			&& 0 < m_pylonCount + m_pylonUnderConstruction
			&& 0 < m_probesOnMinerals + m_probesOnGas + m_probeUnderConstruction;
	case eProtossCommandBuildDarkShrine:
		return 0 < m_twilightCouncilCount + m_twilightCouncilUnderConstruction
			&& 0 < m_pylonCount + m_pylonUnderConstruction
			&& 0 < m_probesOnMinerals + m_probesOnGas + m_probeUnderConstruction;
	case eProtossCommandBuildRoboticsFacility:
		return 0 < m_cyberneticsCoreCount + m_cyberneticsCoreUnderConstruction
			&& 0 < m_pylonCount + m_pylonUnderConstruction
			&& 0 < m_probesOnMinerals + m_probesOnGas + m_probeUnderConstruction;
	case eProtossCommandBuildRoboticsBay:
		return 0 < m_roboticsFacilityCount + m_roboticsFacilityUnderConstruction
			&& 0 < m_pylonCount + m_pylonUnderConstruction
			&& 0 < m_probesOnMinerals + m_probesOnGas + m_probeUnderConstruction;
	case eProtossCommandBuildStargate:
		return 0 < m_cyberneticsCoreCount + m_cyberneticsCoreUnderConstruction
			&& 0 < m_pylonCount + m_pylonUnderConstruction
			&& 0 < m_probesOnMinerals + m_probesOnGas + m_probeUnderConstruction;
	case eProtossCommandBuildFleetBeacon:
		return 0 < m_stargateCount + m_stargateUnderConstruction
			&& 0 < m_pylonCount + m_pylonUnderConstruction
			&& 0 < m_probesOnMinerals + m_probesOnGas + m_probeUnderConstruction;

	case eProtossCommandBuildProbe:
		return 0 < m_nexusCount + m_nexusUnderConstruction
			&& m_supply + 1 <= m_supplyCapUnderConstruction;
	case eProtossCommandBuildZealot:
		return 0 < m_gatewayCount + m_gatewayUnderConstruction
			&& 0 < m_pylonCount + m_pylonUnderConstruction
			&& m_supply + 2 <= m_supplyCapUnderConstruction;
	case eProtossCommandBuildStalker:
		return 0 < m_gatewayCount + m_gatewayUnderConstruction
			&& 0 < m_cyberneticsCoreCount + m_cyberneticsCoreUnderConstruction
			&& 0 < m_pylonCount + m_pylonUnderConstruction
			&& m_supply + 2 <= m_supplyCapUnderConstruction;
	case eProtossCommandBuildSentry:
		return 0 < m_gatewayCount + m_gatewayUnderConstruction
			&& 0 < m_cyberneticsCoreCount + m_cyberneticsCoreUnderConstruction
			&& 0 < m_pylonCount + m_pylonUnderConstruction
			&& m_supply + 2 <= m_supplyCapUnderConstruction;
	case eProtossCommandBuildHighTemplar:
		return 0 < m_gatewayCount + m_gatewayUnderConstruction
			&& 0 < m_templarArchivesCount + m_templarArchivesUnderConstruction
			&& 0 < m_pylonCount + m_pylonUnderConstruction
			&& m_supply + 2 <= m_supplyCapUnderConstruction;
	case eProtossCommandBuildDarkTemplar:
		return 0 < m_gatewayCount + m_gatewayUnderConstruction
			&& 0 < m_darkShrineCount + m_darkShrineUnderConstruction
			&& 0 < m_pylonCount + m_pylonUnderConstruction
			&& m_supply + 2 <= m_supplyCapUnderConstruction;
	case eProtossCommandBuildWarpPrism:
		return 0 < m_roboticsFacilityCount + m_roboticsFacilityUnderConstruction
			&& 0 < m_pylonCount + m_pylonUnderConstruction
			&& m_supply + 2 <= m_supplyCapUnderConstruction;
	case eProtossCommandBuildObserver:
		return 0 < m_roboticsFacilityCount + m_roboticsFacilityUnderConstruction
			&& 0 < m_pylonCount + m_pylonUnderConstruction
			&& m_supply + 2 <= m_supplyCapUnderConstruction;
	case eProtossCommandBuildImmortal:
		return 0 < m_roboticsFacilityCount + m_roboticsFacilityUnderConstruction
			&& 0 < m_pylonCount + m_pylonUnderConstruction
			&& m_supply + 4 <= m_supplyCapUnderConstruction;
	case eProtossCommandBuildColossus:
		return 0 < m_roboticsFacilityCount + m_roboticsFacilityUnderConstruction
			&& 0 < m_roboticsBayCount + m_roboticsBayUnderConstruction
			&& 0 < m_pylonCount + m_pylonUnderConstruction
			&& m_supply + 6 <= m_supplyCapUnderConstruction;
	case eProtossCommandBuildPhoenix:
		return 0 < m_stargateCount + m_stargateUnderConstruction
			&& 0 < m_pylonCount + m_pylonUnderConstruction
			&& m_supply + 2 <= m_supplyCapUnderConstruction;
	case eProtossCommandBuildVoidRay:
		return 0 < m_stargateCount + m_stargateUnderConstruction
			&& 0 < m_pylonCount + m_pylonUnderConstruction
			&& m_supply + 3 <= m_supplyCapUnderConstruction;
	case eProtossCommandBuildCarrier:
		return 0 < m_stargateCount + m_stargateUnderConstruction
			&& 0 < m_fleetBeaconCount + m_fleetBeaconUnderConstruction
			&& 0 < m_pylonCount + m_pylonUnderConstruction
			&& m_supply + 6 <= m_supplyCapUnderConstruction;
	case eProtossCommandBuildMothership:
		return 0 < m_nexusCount + m_nexusUnderConstruction
			&& 0 < m_fleetBeaconCount + m_fleetBeaconUnderConstruction
			&& 0 == m_mothershipCount + m_mothershipUnderConstruction // Only allowed one
			&& m_supply + 8 <= m_supplyCapUnderConstruction;

	case eProtossCommandChronoNexus:
		return 0 < m_nexusCount + m_nexusUnderConstruction;
	case eProtossCommandChronoGateway:
		return 0 < m_nexusCount + m_nexusUnderConstruction
			&& 0 < m_gatewayCount + m_gatewayUnderConstruction - m_warpgateCount;
	case eProtossCommandChronoWarpgate:
		return 0 < m_nexusCount + m_nexusUnderConstruction
			&& 0 < m_warpgateCount + m_warpgateUnderConstruction;
	case eProtossCommandChronoForge:
		return 0 < m_nexusCount + m_nexusUnderConstruction
			&& 0 < m_forgeCount + m_forgeUnderConstruction;
	case eProtossCommandChronoCyberneticsCore:
		return 0 < m_nexusCount + m_nexusUnderConstruction
			&& 0 < m_cyberneticsCoreCount + m_cyberneticsCoreUnderConstruction;
	case eProtossCommandChronoTwilightCouncil:
		return 0 < m_nexusCount
			&& 0 < m_twilightCouncilCount + m_twilightCouncilUnderConstruction;
	case eProtossCommandChronoTemplarArchives:
		return 0 < m_nexusCount
			&& 0 < m_templarArchivesCount + m_templarArchivesUnderConstruction;
	case eProtossCommandChronoDarkShrine:
		return 0 < m_nexusCount
			&& 0 < m_darkShrineCount + m_darkShrineUnderConstruction;
	case eProtossCommandChronoRoboticsFacility:
		return 0 < m_nexusCount
			&& 0 < m_roboticsFacilityCount + m_roboticsFacilityUnderConstruction;
	case eProtossCommandChronoRoboticsBay:
		return 0 < m_nexusCount
			&& 0 < m_roboticsFacilityCount + m_roboticsBayUnderConstruction;
	case eProtossCommandChronoStargate:
		return 0 < m_nexusCount
			&& 0 < m_stargateCount + m_stargateUnderConstruction;
	case eProtossCommandChronoFleetBeacon:
		return 0 < m_nexusCount
			&& 0 < m_fleetBeaconCount + m_fleetBeaconUnderConstruction;

	case eProtossCommandMoveProbeToGas:
		return (eProtossCommandMoveProbeToMinerals != m_lastProbeMove || time != m_timeLastProbeMove)
			&& 0 < m_nexusCount + m_nexusUnderConstruction
			&& 0 < m_assimilatorCount + m_assimilatorUnderConstruction
			&& 0 < m_probesOnMinerals + m_probeUnderConstruction
			&& m_probesOnGas < CGameCalcs::GasWorkerLimit(m_nexusCount + m_nexusUnderConstruction, m_assimilatorCount + m_assimilatorUnderConstruction);
	case eProtossCommandMoveProbeToMinerals:
		return (eProtossCommandMoveProbeToGas != m_lastProbeMove || time != m_timeLastProbeMove)
			&& 0 < m_nexusCount + m_nexusUnderConstruction
			&& 0 < m_assimilatorCount + m_assimilatorUnderConstruction
			&& 0 < m_probesOnGas
			&& m_probesOnMinerals < CGameCalcs::MineralWorkerLimit(m_nexusCount + m_nexusUnderConstruction);

	case eProtossCommandResearchWarpgate:
		return 0 < m_cyberneticsCoreCount + m_cyberneticsCoreUnderConstruction
			&& !m_researchWarpgateCompleted && !m_researchWarpgateUnderConstruction;

	default:
		return true;
	}
}

bool CProtossState::HasBuildingStateRequirements(double time, EProtossCommand command) const
{
	switch (command)
	{
	case eProtossCommandBuildNexus:
		return 0 < m_probesOnMinerals + m_probesOnGas;
	case eProtossCommandBuildPylon:
		return 0 < m_probesOnMinerals + m_probesOnGas;
	case eProtossCommandBuildAssimilator:
		return 0 < m_probesOnMinerals + m_probesOnGas;
	case eProtossCommandBuildGateway:
		return 0 < m_nexusCount
			&& 0 < m_pylonCount
			&& 0 < m_probesOnMinerals + m_probesOnGas;
	case eProtossCommandConvertGatewayToWarpgate:
		return m_gatewayInUse < m_gatewayCount - m_warpgateCount - m_warpgateUnderConstruction
			&& m_researchWarpgateCompleted
			&& 0 < m_pylonCount;
	case eProtossCommandBuildForge:
		return 0 < m_nexusCount
			&& 0 < m_pylonCount
			&& 0 < m_probesOnMinerals + m_probesOnGas;
	case eProtossCommandBuildCyberneticsCore:
		return 0 < m_gatewayCount
			&& 0 < m_pylonCount
			&& 0 < m_probesOnMinerals + m_probesOnGas;
	case eProtossCommandBuildTwilightCouncil:
		return 0 < m_cyberneticsCoreCount
			&& 0 < m_pylonCount
			&& 0 < m_probesOnMinerals + m_probesOnGas;
	case eProtossCommandBuildTemplarArchives:
		return 0 < m_twilightCouncilCount
			&& 0 < m_pylonCount
			&& 0 < m_probesOnMinerals + m_probesOnGas;
	case eProtossCommandBuildDarkShrine:
		return 0 < m_twilightCouncilCount
			&& 0 < m_pylonCount
			&& 0 < m_probesOnMinerals + m_probesOnGas;
	case eProtossCommandBuildRoboticsFacility:
		return 0 < m_cyberneticsCoreCount
			&& 0 < m_pylonCount
			&& 0 < m_probesOnMinerals + m_probesOnGas;
	case eProtossCommandBuildRoboticsBay:
		return 0 < m_roboticsFacilityCount
			&& 0 < m_pylonCount
			&& 0 < m_probesOnMinerals + m_probesOnGas;
	case eProtossCommandBuildStargate:
		return 0 < m_cyberneticsCoreCount
			&& 0 < m_pylonCount
			&& 0 < m_probesOnMinerals + m_probesOnGas;
	case eProtossCommandBuildFleetBeacon:
		return 0 < m_stargateCount
			&& 0 < m_pylonCount
			&& 0 < m_probesOnMinerals + m_probesOnGas;

	case eProtossCommandBuildProbe:
		return m_nexusInUse < m_nexusCount
			&& m_supply + 1 <= m_supplyCap;
	case eProtossCommandBuildZealot:
		return (m_gatewayInUse < m_gatewayCount - m_warpgateCount - m_warpgateUnderConstruction || m_warpgateOnCooldown < m_warpgateCount)
			&& 0 < m_pylonCount
			&& m_supply + 2 <= m_supplyCap;
	case eProtossCommandBuildStalker:
		return (m_gatewayInUse < m_gatewayCount - m_warpgateCount - m_warpgateUnderConstruction || m_warpgateOnCooldown < m_warpgateCount)
			&& 0 < m_cyberneticsCoreCount
			&& 0 < m_pylonCount
			&& m_supply + 2 <= m_supplyCap;
	case eProtossCommandBuildSentry:
		return (m_gatewayInUse < m_gatewayCount - m_warpgateCount - m_warpgateUnderConstruction || m_warpgateOnCooldown < m_warpgateCount)
			&& 0 < m_cyberneticsCoreCount
			&& 0 < m_pylonCount
			&& m_supply + 2 <= m_supplyCap;
	case eProtossCommandBuildHighTemplar:
		return (m_gatewayInUse < m_gatewayCount - m_warpgateCount - m_warpgateUnderConstruction || m_warpgateOnCooldown < m_warpgateCount)
			&& 0 < m_templarArchivesCount
			&& 0 < m_pylonCount
			&& m_supply + 2 <= m_supplyCap;
	case eProtossCommandBuildDarkTemplar:
		return (m_gatewayInUse < m_gatewayCount - m_warpgateCount - m_warpgateUnderConstruction || m_warpgateOnCooldown < m_warpgateCount)
			&& 0 < m_darkShrineCount
			&& 0 < m_pylonCount
			&& m_supply + 2 <= m_supplyCap;
	case eProtossCommandBuildWarpPrism:
		return m_roboticsFacilityInUse < m_roboticsFacilityCount
			&& 0 < m_pylonCount
			&& m_supply + 2 <= m_supplyCap;
	case eProtossCommandBuildObserver:
		return m_roboticsFacilityInUse < m_roboticsFacilityCount
			&& 0 < m_pylonCount
			&& m_supply + 2 <= m_supplyCap;
	case eProtossCommandBuildImmortal:
		return m_roboticsFacilityInUse < m_roboticsFacilityCount
			&& 0 < m_pylonCount
			&& m_supply + 4 <= m_supplyCap;
	case eProtossCommandBuildColossus:
		return m_roboticsFacilityInUse < m_roboticsFacilityCount
			&& 0 < m_roboticsBayCount
			&& 0 < m_pylonCount
			&& m_supply + 6 <= m_supplyCap;
	case eProtossCommandBuildPhoenix:
		return m_stargateInUse < m_stargateCount
			&& 0 < m_pylonCount
			&& m_supply + 2 <= m_supplyCap;
	case eProtossCommandBuildVoidRay:
		return m_stargateInUse < m_stargateCount
			&& 0 < m_pylonCount
			&& m_supply + 3 <= m_supplyCap;
	case eProtossCommandBuildCarrier:
		return m_stargateInUse < m_stargateCount
			&& 0 < m_fleetBeaconCount
			&& 0 < m_pylonCount
			&& m_supply + 6 <= m_supplyCap;
	case eProtossCommandBuildMothership:
		return m_nexusInUse < m_nexusCount
			&& 0 < m_fleetBeaconCount
			&& m_supply + 8 <= m_supplyCap;

	case eProtossCommandChronoNexus:
		return 0 < m_nexusCount
			&& m_nexusChronoCount < m_nexusCount;
	case eProtossCommandChronoGateway:
		return 0 < m_nexusCount
			&& m_gatewayChronoCount < m_gatewayCount - m_warpgateCount;
	case eProtossCommandChronoWarpgate:
		return 0 < m_nexusCount
			&& m_warpgateChronoCount < m_warpgateCount;
	case eProtossCommandChronoForge:
		return 0 < m_nexusCount + m_nexusUnderConstruction
			&& m_forgeChronoCount < m_forgeCount;
	case eProtossCommandChronoCyberneticsCore:
		return 0 < m_nexusCount
			&& m_cyberneticsCoreChronoCount < m_cyberneticsCoreCount;
	case eProtossCommandChronoTwilightCouncil:
		return 0 < m_nexusCount
			&& m_twilightCouncilChronoCount < m_twilightCouncilCount;
	case eProtossCommandChronoTemplarArchives:
		return 0 < m_nexusCount
			&& m_templarArchivesChronoCount < m_templarArchivesCount;
	case eProtossCommandChronoDarkShrine:
		return 0 < m_nexusCount
			&& m_darkShrineChronoCount < m_darkShrineCount;
	case eProtossCommandChronoRoboticsFacility:
		return 0 < m_nexusCount
			&& m_roboticsFacilityChronoCount < m_roboticsFacilityCount;
	case eProtossCommandChronoRoboticsBay:
		return 0 < m_nexusCount
			&& m_roboticsBayChronoCount < m_roboticsFacilityCount;
	case eProtossCommandChronoStargate:
		return 0 < m_nexusCount
			&& m_stargateChronoCount < m_stargateCount;
	case eProtossCommandChronoFleetBeacon:
		return 0 < m_nexusCount
			&& m_fleetBeaconChronoCount < m_fleetBeaconCount;

	case eProtossCommandMoveProbeToGas:
		return 0 < m_nexusCount
			&& 0 < m_assimilatorCount
			&& 0 < m_probesOnMinerals;
	case eProtossCommandMoveProbeToMinerals:
		return 0 < m_nexusCount
			&& 0 < m_assimilatorCount
			&& 0 < m_probesOnGas;

	case eProtossCommandResearchWarpgate:
		return 0 < m_cyberneticsCoreCount;

	default:
		return true;
	}
}

void CProtossState::GetCost(CResourceCost &cost, EProtossCommand command)
{
	switch(command)
	{
	case eProtossCommandBuildNexus:
		cost.m_minerals = 400;
		break;
	case eProtossCommandBuildPylon:
		cost.m_minerals = 100;
		break;
	case eProtossCommandBuildAssimilator:
		cost.m_minerals = 75;
		break;
	case eProtossCommandBuildGateway:
		cost.m_minerals = 150;
		break;
	case eProtossCommandBuildForge:
		cost.m_minerals = 200;
		break;
	case eProtossCommandBuildCyberneticsCore:
		cost.m_minerals = 150;
		break;
	case eProtossCommandBuildTwilightCouncil:
		cost.m_minerals = 150;
		cost.m_gas = 100;
		break;
	case eProtossCommandBuildTemplarArchives:
		cost.m_minerals = 150;
		cost.m_gas = 200;
		break;
	case eProtossCommandBuildDarkShrine:
		cost.m_minerals = 150;
		cost.m_gas = 250;
		break;
	case eProtossCommandBuildRoboticsFacility:
		cost.m_minerals = 200;
		cost.m_gas = 100;
		break;
	case eProtossCommandBuildRoboticsBay:
		cost.m_minerals = 200;
		cost.m_gas = 200;
		break;
	case eProtossCommandBuildStargate:
		cost.m_minerals = 150;
		cost.m_gas = 150;
		break;
	case eProtossCommandBuildFleetBeacon:
		cost.m_minerals = 300;
		cost.m_gas = 200;
		break;

	case eProtossCommandBuildProbe:
		cost.m_minerals = 50;
		break;
	case eProtossCommandBuildZealot:
		cost.m_minerals = 100;
		break;
	case eProtossCommandBuildStalker:
		cost.m_minerals = 125;
		cost.m_gas = 50;
		break;
	case eProtossCommandBuildSentry:
		cost.m_minerals = 50;
		cost.m_gas = 100;
		break;
	case eProtossCommandBuildHighTemplar:
		cost.m_minerals = 50;
		cost.m_gas = 150;
		break;
	case eProtossCommandBuildDarkTemplar:
		cost.m_minerals = 50;
		cost.m_gas = 150;
		break;
	case eProtossCommandBuildWarpPrism:
		cost.m_minerals = 200;
		break;
	case eProtossCommandBuildObserver:
		cost.m_minerals = 50;
		cost.m_gas = 100;
		break;
	case eProtossCommandBuildImmortal:
		cost.m_minerals = 250;
		cost.m_gas = 100;
		break;
	case eProtossCommandBuildColossus:
		cost.m_minerals = 300;
		cost.m_gas = 200;
		break;
	case eProtossCommandBuildPhoenix:
		cost.m_minerals = 150;
		cost.m_gas = 100;
		break;
	case eProtossCommandBuildVoidRay:
		cost.m_minerals = 250;
		cost.m_gas = 150;
		break;
	case eProtossCommandBuildCarrier:
		cost.m_minerals = 350;
		cost.m_gas = 250;
		break;
	case eProtossCommandBuildMothership:
		cost.m_minerals = 400;
		cost.m_gas = 400;
		break;

	case eProtossCommandResearchWarpgate:
		cost.m_minerals = 50;
		cost.m_gas = 50;
		break;

	case eProtossCommandChronoNexus:
	case eProtossCommandChronoGateway:
	case eProtossCommandChronoWarpgate:
	case eProtossCommandChronoForge:
	case eProtossCommandChronoCyberneticsCore:
	case eProtossCommandChronoTwilightCouncil:
	case eProtossCommandChronoTemplarArchives:
	case eProtossCommandChronoDarkShrine:
	case eProtossCommandChronoRoboticsFacility:
	case eProtossCommandChronoRoboticsBay:
	case eProtossCommandChronoStargate:
	case eProtossCommandChronoFleetBeacon:
		cost.m_nexusEnergy = 25;
		break;
	}
}

void CProtossState::RecalculateSupply()
{
	m_supply = 
		  1 * (m_probeCount + m_probeUnderConstruction)
		+ 2 * (m_zealotCount + m_zealotUnderConstruction)
		+ 2 * (m_stalkerCount + m_stalkerUnderConstruction)
		+ 2 * (m_sentryCount + m_sentryUnderConstruction)
		+ 2 * (m_highTemplarCount + m_highTemplarUnderConstruction)
		+ 2 * (m_darkTemplarCount + m_darkTemplarUnderConstruction)
		+ 2 * (m_warpPrismCount + m_warpPrismUnderConstruction)
		+ 2 * (m_observerCount + m_observerUnderConstruction)
		+ 4 * (m_immortalCount + m_immortalUnderConstruction)
		+ 6 * (m_colossusCount + m_colossusUnderConstruction)
		+ 2 * (m_phoenixCount + m_phoenixUnderConstruction)
		+ 3 * (m_voidRayCount + m_voidRayUnderConstruction)
		+ 6 * (m_carrierCount + m_carrierUnderConstruction)
		+ 8 * (m_mothershipCount + m_mothershipUnderConstruction)
		;
}

void CProtossState::RecalculateSupplyCap()
{
	m_supplyCap = 10 * m_nexusCount + 8 * m_pylonCount;
}

void CProtossState::RecalculateSupplyCapUnderConstruction()
{
	m_supplyCapUnderConstruction = m_supplyCap + 10 * m_nexusUnderConstruction + 8 * m_pylonUnderConstruction;
}

void CProtossState::RecalculateMineralIncomeRate()
{
	m_mineralIncomeRate = CGameCalcs::CalculateMineralIncomeRate(m_nexusCount, m_probesOnMinerals);
}

void CProtossState::RecalculateGasIncomeRate()
{
	m_gasIncomeRate = CGameCalcs::CalculateGasIncomeRate(m_nexusCount, m_assimilatorCount, m_probesOnGas);
}

void CProtossState::ProgressTime(double &time, double duration)
{
	m_minerals += m_mineralIncomeRate * duration;
	m_gas += m_gasIncomeRate * duration;
	for(size_t i=0; i < 4 && i < m_nexusCount; i++)
		m_nexusEnergy[i] = mymin(m_nexusEnergy[i] + 0.5625 * duration, 100.0);
	time += duration;
}

void CProtossState::UseProbeForBuilding(double duration, double &time, CLinkedList<CProtossEvent> *&events)
{
	if(m_probesOnMinerals > 0)
	{
		AddEvent(events, CProtossEvent(CProtossEvent::eProbeStartMiningMinerals, time + duration));
		m_probesOnMinerals--;
		RecalculateMineralIncomeRate();
	}
	else if(m_probesOnGas > 0)
	{
		AddEvent(events, CProtossEvent(CProtossEvent::eProbeStartMiningGas, time + duration));
		m_probesOnGas--;
		RecalculateGasIncomeRate();
	}
}

void CProtossState::AddEvent(CLinkedList<CProtossEvent> *&events, const CProtossEvent &event)
{
	if(!events || event < events->GetData())
		events = new CLinkedList<CProtossEvent>(event, events);
	else
		events->InsertOrdered<Less<CProtossEvent>>(event);
}

void CProtossState::PrintDetails(CString &output) const
{
	PrintSummary(output);

	output.Append(L"\r\nBuildings: ");

	if(0 < m_nexusCount)			output.AppendFormat(L" %u Nexus", m_nexusCount);
	if(0 < m_assimilatorCount)		output.AppendFormat(L" %u Assimilator", m_assimilatorCount);
	if(0 < m_pylonCount)			output.AppendFormat(L" %u Pylon", m_pylonCount);
	if(0 < m_gatewayCount)			output.AppendFormat(L" %u Gateway", m_gatewayCount - m_warpgateCount);
	if(0 < m_warpgateCount)			output.AppendFormat(L" %u Warpgate", m_warpgateCount);
	if(0 < m_cyberneticsCoreCount)	output.AppendFormat(L" %u Cybernetics Core", m_cyberneticsCoreCount);
	if(0 < m_twilightCouncilCount)	output.AppendFormat(L" %u Twilight Council", m_twilightCouncilCount);
	if(0 < m_templarArchivesCount)	output.AppendFormat(L" %u Templar Archives", m_templarArchivesCount);
	if(0 < m_darkShrineCount)		output.AppendFormat(L" %u Dark Shrine", m_darkShrineCount);
	if(0 < m_roboticsFacilityCount)	output.AppendFormat(L" %u Robotics Facility", m_roboticsFacilityCount);
	if(0 < m_roboticsBayCount)		output.AppendFormat(L" %u Robotics Bay", m_roboticsBayCount);
	if(0 < m_stargateCount)			output.AppendFormat(L" %u Stargate", m_stargateCount);
	if(0 < m_fleetBeaconCount)		output.AppendFormat(L" %u Fleet Beacon", m_fleetBeaconCount);

	output.Append(L"\r\nUnits:     ");

	if(0 < m_probeCount)			output.AppendFormat(L" %u Probe", m_probeCount);
	if(0 < m_zealotCount)			output.AppendFormat(L" %u Zealot", m_zealotCount);
	if(0 < m_stalkerCount)			output.AppendFormat(L" %u Stalker", m_stalkerCount);
	if(0 < m_sentryCount)			output.AppendFormat(L" %u Sentry", m_sentryCount);
	if(0 < m_highTemplarCount)		output.AppendFormat(L" %u High Templar", m_highTemplarCount);
	if(0 < m_darkTemplarCount)		output.AppendFormat(L" %u Dark Templar", m_darkTemplarCount);
	if(0 < m_warpPrismCount)		output.AppendFormat(L" %u Warp Prism", m_warpPrismCount);
	if(0 < m_observerCount)			output.AppendFormat(L" %u Observer", m_observerCount);
	if(0 < m_immortalCount)			output.AppendFormat(L" %u Immortal", m_immortalCount);
	if(0 < m_colossusCount)			output.AppendFormat(L" %u Colossus", m_colossusCount);
	if(0 < m_phoenixCount)			output.AppendFormat(L" %u Phoenix", m_phoenixCount);
	if(0 < m_voidRayCount)			output.AppendFormat(L" %u Void Ray", m_voidRayCount);
	if(0 < m_carrierCount)			output.AppendFormat(L" %u Carrier", m_carrierCount);
	if(0 < m_mothershipCount)		output.AppendFormat(L" %u Mothership", m_mothershipCount);

	output.Append(L"\r\nUpgrades:  ");

	if(m_researchWarpgateCompleted)	output.Append(L" Warpgate");

	output.Append(L"\r\n");
}


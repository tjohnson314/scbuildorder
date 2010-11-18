#pragma once

#include "Village.h"
#include "GAConfiguration.h"
#include "GAPopulation.h"
#include "Vector.h"
#include "ThreadPool.h"
#include "FitnessCalc.h"
#include "FitnessValue.h"

template<typename TTarget, typename TState, typename TCommand, typename TEvent>
class CSimulatorEngine
{
public:
	CSimulatorEngine(double timeLimit);
	~CSimulatorEngine();

	void AddWaypoint(const TTarget &target, double targetTime) { m_targetFitness.AddWaypoint(target, targetTime); }
	void InitConfiguration(double mutationRate);
	void AddVillage(size_t populationLimit, size_t initialPopulation) { if(!m_config) return; m_villages.push_back(new CVillage<TTarget, TState, TCommand, TEvent>(*m_config, m_stagnationLimit, populationLimit, initialPopulation)); }
	void AddSeed(const CVector<TCommand> &seed) { if(!m_config) return; m_seeds.push_back(new CVector<TCommand>(seed)); }
	void AddCustomEvent(const TEvent &customEvent) { if(!m_config) return; m_targetFitness.AddCustomEvent(customEvent); }

	void Start();
	void Stop();

	static void Execute(void *input) { ((CSimulatorEngine<TTarget, TState, TCommand, TEvent> *)input)->Execute(); }
	void Execute();

	size_t VillagePopulationCount(size_t village) const { return m_villages[village]->populationCount(); }
	size_t VillageEvolution(size_t village) const { return m_villages[village]->evolution(); }
	size_t VillageStagnationCount(size_t village) const { return m_villages[village]->stagnationCount(); }
	unsigned long long VillageGameCount(size_t village) const { return m_villages[village]->gameCount(); }
	CFitnessValue VillageBestFitness(size_t village) const { return m_villages[village]->bestFitness(); }

	size_t CityPopulationCount() const { if(!m_city) return 0; return m_city->populationCount(); }
	size_t CityEvolution() const { return m_evolution; }
	size_t CityStagnationCount() const { if(!m_city) return 0; return m_city->StagnationCount(); }
	unsigned long long CityGameCount() const { if(!m_city) return 0; return m_city->gameCount(); }
	CFitnessValue CityBestFitness() const { CLock lock(m_semaphore); return m_bestFitness; }

	size_t StagnationLimit() const { return m_stagnationLimit; }

	void GetBestGame(CVector<TCommand> &game) const { CLock lock(m_semaphore); if(!m_bestGame) return; game = *m_bestGame; }

	void PrintBestGame(CString &output) const;

protected:
	CVector<TCommand> m_vecAlphabet;
	CFitnessCalc<TTarget, TState, TCommand, TEvent> m_targetFitness;
	CGAConfiguration<TCommand, CFitnessCalc<TTarget, TState, TCommand, TEvent>, CFitnessValue> *m_config;

	CVector<CVector<TCommand> *> m_seeds;

	size_t m_stagnationLimit;
	CVector<CVillage<TTarget, TState, TCommand, TEvent> *> m_villages;
	CGAPopulation<TCommand, CFitnessCalc<TTarget, TState, TCommand, TEvent>, CFitnessValue> *m_city;

	CVector<TCommand> *m_bestGame;
	CFitnessValue m_bestFitness;
	HANDLE m_semaphore;

	HANDLE m_threadHandle;
	DWORD m_threadId;

	bool m_bRunning;
	bool m_bContinueRunning;

	size_t m_evolution;

};

template<typename TTarget, typename TState, typename TCommand, typename TEvent>
CSimulatorEngine<TTarget, TState, TCommand, TEvent>::CSimulatorEngine(double timeLimit)
: m_targetFitness(timeLimit), m_config(0), m_city(0), m_bestGame(0), m_bestFitness(), m_threadHandle(0), m_threadId(0), m_stagnationLimit(1000), m_bRunning(false), m_bContinueRunning(true), m_evolution(0)
{
	m_semaphore = CreateSemaphore(0, 1, 1, 0);
}

template<typename TTarget, typename TState, typename TCommand, typename TEvent>
CSimulatorEngine<TTarget, TState, TCommand, TEvent>::~CSimulatorEngine()
{
	while(m_seeds.size() > 0)
		delete m_seeds.pop();

	for(size_t i=0; i < m_villages.size(); i++)
		delete m_villages[i];

	delete m_config;
	delete m_bestGame;

	CloseHandle(m_semaphore);
	CloseHandle(m_threadHandle);
}

template<typename TTarget, typename TState, typename TCommand, typename TEvent>
void CSimulatorEngine<TTarget, TState, TCommand, TEvent>::InitConfiguration(double mutationRate)
{
	if(m_bRunning)
		return;

	m_targetFitness.BuildAlphabet(m_vecAlphabet);

	while(m_seeds.size() > 0)
		delete m_seeds.pop();

	delete m_config;
	m_config = new CGAConfiguration<TCommand, CFitnessCalc<TTarget, TState, TCommand, TEvent>, CFitnessValue>(m_vecAlphabet, mutationRate, m_targetFitness);

	m_config->AddOperator(new CGAConfiguration<TCommand, CFitnessCalc<TTarget, TState, TCommand, TEvent>, CFitnessValue>::CGAOperatorInsert(*m_config));
	m_config->AddOperator(new CGAConfiguration<TCommand, CFitnessCalc<TTarget, TState, TCommand, TEvent>, CFitnessValue>::CGAOperatorDuplicate(*m_config));
	m_config->AddOperator(new CGAConfiguration<TCommand, CFitnessCalc<TTarget, TState, TCommand, TEvent>, CFitnessValue>::CGAOperatorDelete(*m_config));
	m_config->AddOperator(new CGAConfiguration<TCommand, CFitnessCalc<TTarget, TState, TCommand, TEvent>, CFitnessValue>::CGAOperatorImmediateSwap(*m_config));
	m_config->AddOperator(new CGAConfiguration<TCommand, CFitnessCalc<TTarget, TState, TCommand, TEvent>, CFitnessValue>::CGAOperatorRandomSwap(*m_config));
	m_config->AddOperator(new CGAConfiguration<TCommand, CFitnessCalc<TTarget, TState, TCommand, TEvent>, CFitnessValue>::CGAOperatorMove(*m_config));
	m_config->AddOperator(new CGAConfiguration<TCommand, CFitnessCalc<TTarget, TState, TCommand, TEvent>, CFitnessValue>::CGAOperatorMutate(*m_config));

	m_targetFitness.ClearCustomEvents();
}

template<typename TTarget, typename TState, typename TCommand, typename TEvent>
void CSimulatorEngine<TTarget, TState, TCommand, TEvent>::Start()
{
	if(m_bRunning)
		return;

	m_threadHandle = CThreadPool::Get()->StartThread(CSimulatorEngine<TTarget, TState, TCommand, TEvent>::Execute, this);
}

template<typename TTarget, typename TState, typename TCommand, typename TEvent>
void CSimulatorEngine<TTarget, TState, TCommand, TEvent>::Stop()
{
	if(m_bRunning)
	{
		m_bContinueRunning = false;

		WaitForSingleObject(m_threadHandle, INFINITE);
	}
}

template<typename TTarget, typename TState, typename TCommand, typename TEvent>
void CSimulatorEngine<TTarget, TState, TCommand, TEvent>::Execute()
{
	m_bRunning = true;

	for(size_t i=0; i < m_villages.size(); i++)
		m_villages[i]->Start();

	m_city = new CGAPopulation<TCommand, CFitnessCalc<TTarget, TState, TCommand, TEvent>, CFitnessValue>(*m_config, 1000);
	m_city->Initialise(200, 4, 8);

	for(size_t i=0; i < m_seeds.size(); i++)
		m_city->AddChromosome(*m_seeds[i]);

	m_city->Sort();

	for(m_evolution=0; m_bContinueRunning; m_evolution++)
	{
		m_stagnationLimit = 1000 + m_evolution;

		if(m_evolution%100 == 0 && 0 != m_evolution)
		{
			for(size_t i=0; i < m_villages.size(); i++)
			{
				CVector<TCommand> best;
				m_villages[i]->bestValue(best);
				m_city->AddChromosome(best);

				m_city->Sort();

				if(m_city->IsSatisfied())
					break;
			}
		}

		if(m_evolution % 20 == 0) // Every 20 city evolutions update the best game
		{
			CLock lock(m_semaphore);
			delete m_bestGame;
			m_bestGame = new CVector<TCommand>(m_city->GetBestChromosome());
			m_bestFitness = m_city->GetBestFitness();
		}

		m_city->Evolve();
	}

	for(size_t i=0; i < m_villages.size(); i++)
		m_villages[i]->Stop();

	for(size_t i=0; i < m_villages.size(); i++)
		m_villages[i]->WaitForCompletion();

	delete m_city;
	m_city = 0;

	CLock lock(m_semaphore);
	delete m_bestGame;
	m_bestGame = 0;

	m_bRunning = false;
};

template<typename TTarget, typename TState, typename TCommand, typename TEvent>
void CSimulatorEngine<TTarget, TState, TCommand, TEvent>::PrintBestGame(CString &output) const
{
	CVector<TCommand> game;
	GetBestGame(game);
	
	m_targetFitness.PrintGame(output, game);
}

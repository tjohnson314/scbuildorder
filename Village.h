#pragma once

#include "Lock.h"
#include "GAPopulation.h"
#include "FitnessCalc.h"
#include "FitnessValue.h"

template<typename TTarget, typename TState, typename TCommand, typename TEvent>
class CVillage
{
public:
	CVillage(const CGAConfiguration<TCommand, CFitnessCalc<TTarget, TState, TCommand, TEvent>, CFitnessValue> &config, const size_t &stagnationLimit, size_t populationLimit, size_t initialPopulation);
	~CVillage() { CloseHandle(m_semaphore); CloseHandle(m_threadHandle); }

	size_t populationCount() const { if(!m_population) return 0; return m_population->populationCount(); }
	size_t evolution() const { return m_evolution; }
	size_t stagnationCount() const { if(!m_population) return 0; return m_population->StagnationCount(); }
	unsigned long long gameCount() const { if(!m_population) return 0; return m_population->gameCount(); }
	
	CFitnessValue bestFitness() const { CLock lock(m_semaphore); return m_bestFitness; }
	void bestValue(CVector<TCommand> &value) const { CLock lock(m_semaphore); if(!m_bestValue) return; value = *m_bestValue; }

	void Start();
	void Stop() { m_bContinueRunning = false; }
	void WaitForCompletion() { if(!m_bRunning) return; WaitForSingleObject(m_threadHandle, INFINITE); }

	size_t getStagnationLimit() const { return m_stagnationLimit; }

	static void Execute(void *input) { ((CVillage<TTarget, TState, TCommand, TEvent> *)input)->Execute(); }
	void Execute();
	void Run(); // Only call from static member above

protected:
	void Initialise() { m_evolution = 0; m_population->Initialise(m_initialPopulation, 4, 8); }

	const CGAConfiguration<TCommand, CFitnessCalc<TTarget, TState, TCommand, TEvent>, CFitnessValue> &m_config;
	CGAPopulation<TCommand, CFitnessCalc<TTarget, TState, TCommand, TEvent>, CFitnessValue> *m_population;
	const size_t &m_stagnationLimit;

	size_t m_populationLimit;
	size_t m_initialPopulation;

	HANDLE m_threadHandle;
	DWORD m_threadId;

	HANDLE m_semaphore;

	bool m_bRunning;
	bool m_bContinueRunning;

	size_t m_evolution;

	CVector<TCommand> *m_bestValue;
	CFitnessValue m_bestFitness;
};

template<typename TTarget, typename TState, typename TCommand, typename TEvent>
CVillage<TTarget, TState, TCommand, TEvent>::CVillage(const CGAConfiguration<TCommand, CFitnessCalc<TTarget, TState, TCommand, TEvent>, CFitnessValue> &config, const size_t &stagnationLimit, size_t populationLimit, size_t initialPopulation)
: m_config(config), m_populationLimit(populationLimit), m_population(0), m_stagnationLimit(stagnationLimit), m_initialPopulation(initialPopulation), m_threadHandle(0), m_threadId(0), m_bRunning(false), m_bContinueRunning(true), m_evolution(0), m_bestValue(0), m_bestFitness()
{
	m_semaphore = CreateSemaphore(0, 1, 1, 0);
}

template<typename TTarget, typename TState, typename TCommand, typename TEvent>
void CVillage<TTarget, TState, TCommand, TEvent>::Start()
{
	if(m_bRunning)
		return;

	m_threadHandle = CThreadPool::Get()->StartThread(CVillage<TTarget, TState, TCommand, TEvent>::Execute, this);
}

template<typename TTarget, typename TState, typename TCommand, typename TEvent>
void CVillage<TTarget, TState, TCommand, TEvent>::Execute()
{
	m_bRunning = true;

	m_population = new CGAPopulation<TCommand, CFitnessCalc<TTarget, TState, TCommand, TEvent>, CFitnessValue>(m_config, m_populationLimit);

	Initialise();

	for(m_evolution = 0; m_bContinueRunning; m_evolution++)
	{
		if(m_evolution % 100 == 0)
		{
			CLock lock(m_semaphore);
			delete m_bestValue;
			m_bestValue = new CVector<TCommand>(m_population->GetBestChromosome());
			m_bestFitness = m_population->GetBestFitness();
		}

		if(m_population->StagnationCount() > m_stagnationLimit)
		{
			m_population->Clear();
			Initialise();
		}

		m_population->Evolve();
	}

	CLock lock(m_semaphore);
	delete m_bestValue;
	m_bestValue = 0;

	delete m_population;

	m_bRunning = false;
}

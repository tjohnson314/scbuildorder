#pragma once

#include "Lock.h"
#include "GAPopulation.h"
#include "FitnessCalc.h"

template<typename TState, typename TCommand, typename TEvent>
class CVillage
{
public:
	CVillage(const CGAConfiguration<TCommand, CFitnessCalc<TState, TCommand, TEvent>, CFitnessValue> &config, const size_t &stagnationLimit, size_t populationLimit, size_t initialPopulation);
	~CVillage() { CloseHandle(m_semaphore); CloseHandle(m_threadHandle); }

	unsigned long long gameCount() const { if(!m_population) return 0; return m_population->gameCount(); }
	//CGAPopulation<TCommand, CFitnessCalc<TState, TCommand, TEvent>> *population() const { return m_population; }
	
	void bestValue(CVector<TCommand> &value) const { CLock lock(m_semaphore); if(!m_bestValue) return; value = *m_bestValue; }

	void Start();
	void Stop() { m_bContinueRunning = false; }
	void WaitForCompletion() { if(!m_bRunning) return; WaitForSingleObject(m_threadHandle, INFINITE); }

	size_t getStagnationLimit() const { return m_stagnationLimit; }

	static DWORD WINAPI Execute(LPVOID input) { ((CVillage<TState, TCommand, TEvent> *)input)->Execute(); return 0; }
	void Execute();
	void Run(); // Only call from static member above

protected:
	void Initialise() { m_population->Initialise(m_initialPopulation, 4, 8); }

	const CGAConfiguration<TCommand, CFitnessCalc<TState, TCommand, TEvent>, CFitnessValue> &m_config;
	CGAPopulation<TCommand, CFitnessCalc<TState, TCommand, TEvent>, CFitnessValue> *m_population;
	const size_t &m_stagnationLimit;

	size_t m_populationLimit;
	size_t m_initialPopulation;

	HANDLE m_threadHandle;
	DWORD m_threadId;

	HANDLE m_semaphore;

	bool m_bRunning;
	bool m_bContinueRunning;

	CVector<TCommand> *m_bestValue;
};

template<typename TState, typename TCommand, typename TEvent>
CVillage<TState, TCommand, TEvent>::CVillage(const CGAConfiguration<TCommand, CFitnessCalc<TState, TCommand, TEvent>, CFitnessValue> &config, const size_t &stagnationLimit, size_t populationLimit, size_t initialPopulation)
: m_config(config), m_populationLimit(populationLimit), m_population(0), m_stagnationLimit(stagnationLimit), m_initialPopulation(initialPopulation), m_threadHandle(0), m_threadId(0), m_bRunning(false), m_bContinueRunning(true), m_bestValue(0)
{
	m_semaphore = CreateSemaphore(0, 1, 1, 0);
}

template<typename TState, typename TCommand, typename TEvent>
void CVillage<TState, TCommand, TEvent>::Start()
{
	if(m_bRunning)
		return;

	m_threadHandle = CreateThread( 
			NULL,				// default security attributes
			0,					// use default stack size  
			CVillage<TState, TCommand, TEvent>::Execute,			// thread function name
			this,				// argument to thread function 
			0,					// use default creation flags 
			&m_threadId);		// returns the thread identifier 

	SetThreadPriority(m_threadHandle, THREAD_PRIORITY_BELOW_NORMAL);
}

template<typename TState, typename TCommand, typename TEvent>
void CVillage<TState, TCommand, TEvent>::Execute()
{
	m_bRunning = true;

	m_population = new CGAPopulation<TCommand, CFitnessCalc<TState, TCommand, TEvent>, CFitnessValue>(m_config, m_populationLimit);

	Initialise();

	size_t count = 0;
	while(m_bContinueRunning)
	{
		if(count % 100 == 0)
		{
			CLock lock(m_semaphore);
			delete m_bestValue;
			m_bestValue = new CVector<TCommand>(m_population->GetBestChromosome());
		}

		if(m_population->StagnationCount() > m_stagnationLimit)
		{
			m_population->Clear();
			Initialise();
		}

		m_population->Evolve();

		count++;
	}

	CLock lock(m_semaphore);
	delete m_bestValue;
	m_bestValue = 0;

	delete m_population;

	m_bRunning = false;
}

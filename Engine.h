#pragma once

#include "Alphabet.h"
#include "Village.h"
#include "GAConfiguration.h"
#include "GAPopulation.h"
#include "Vector.h"
#include "ThreadPool.h"

template<typename TState, typename TCommand, typename TEvent>
class CSimulatorEngine
{
public:
	CSimulatorEngine(double timeLimit);
	~CSimulatorEngine();

	void AddWaypoint(const TState &targetState, double targetTime) { m_targetFitness.AddWaypoint(targetState, targetTime); }
	void InitConfiguration(double mutationRate);
	void AddVillage(size_t populationLimit, size_t initialPopulation) { if(!m_config) return; m_villages.push_back(new CVillage<TState, TCommand, TEvent>(*m_config, m_stagnationLimit, populationLimit, initialPopulation)); }

	void Start();
	void Stop();

	static void Execute(void *input) { ((CSimulatorEngine<TState, TCommand, TEvent> *)input)->Execute(); }
	//static DWORD WINAPI Execute(LPVOID input) { ((CSimulatorEngine<TState, TCommand, TEvent> *)input)->Execute(); return 0; }
	void Execute();

	size_t Evolution() const { return m_evolution; }
	unsigned long long GameCount() const { return m_gameCount; }
	void GetBestGame(CVector<TCommand> &game) const { CLock lock(m_semaphore); if(!m_bestGame) return; game = *m_bestGame; }

	void PrintBestGame(CString &output) const;

protected:
	CVector<TCommand> m_vecAlphabet;
	CFitnessCalc<TState, TCommand, TEvent> m_targetFitness;
	CGAConfiguration<TCommand, CFitnessCalc<TState, TCommand, TEvent>, CFitnessValue> *m_config;

	size_t m_stagnationLimit;
	CVector<CVillage<TState, TCommand, TEvent> *> m_villages;
	CGAPopulation<TCommand, CFitnessCalc<TState, TCommand, TEvent>, CFitnessValue> *m_city;

	CVector<TCommand> *m_bestGame;
	HANDLE m_semaphore;

	HANDLE m_threadHandle;
	DWORD m_threadId;

	bool m_bRunning;
	bool m_bContinueRunning;

	size_t m_evolution;
	unsigned long long m_gameCount;

};

template<typename TState, typename TCommand, typename TEvent>
CSimulatorEngine<TState, TCommand, TEvent>::CSimulatorEngine(double timeLimit)
: m_targetFitness(timeLimit), m_config(0), m_city(0), m_bestGame(0), m_threadHandle(0), m_threadId(0), m_stagnationLimit(1000), m_bRunning(false), m_bContinueRunning(true), m_evolution(0), m_gameCount(0)
{
	m_semaphore = CreateSemaphore(0, 1, 1, 0);
	GetAlphabet(m_vecAlphabet);
}

template<typename TState, typename TCommand, typename TEvent>
CSimulatorEngine<TState, TCommand, TEvent>::~CSimulatorEngine()
{
	for(size_t i=0; i < m_villages.size(); i++)
		delete m_villages[i];

	delete m_config;

	CloseHandle(m_semaphore);
	CloseHandle(m_threadHandle);
}

template<typename TState, typename TCommand, typename TEvent>
void CSimulatorEngine<TState, TCommand, TEvent>::InitConfiguration(double mutationRate)
{
	if(m_bRunning)
		return;

	delete m_config;

	m_config = new CGAConfiguration<TCommand, CFitnessCalc<TState, TCommand, TEvent>, CFitnessValue>(m_vecAlphabet, mutationRate, m_targetFitness);

	m_config->AddOperator(new CGAConfiguration<TCommand, CFitnessCalc<TState, TCommand, TEvent>, CFitnessValue>::CGAOperatorInsert(*m_config));
	m_config->AddOperator(new CGAConfiguration<TCommand, CFitnessCalc<TState, TCommand, TEvent>, CFitnessValue>::CGAOperatorDuplicate(*m_config));
	m_config->AddOperator(new CGAConfiguration<TCommand, CFitnessCalc<TState, TCommand, TEvent>, CFitnessValue>::CGAOperatorDelete(*m_config));
	m_config->AddOperator(new CGAConfiguration<TCommand, CFitnessCalc<TState, TCommand, TEvent>, CFitnessValue>::CGAOperatorImmediateSwap(*m_config));
	m_config->AddOperator(new CGAConfiguration<TCommand, CFitnessCalc<TState, TCommand, TEvent>, CFitnessValue>::CGAOperatorRandomSwap(*m_config));
	m_config->AddOperator(new CGAConfiguration<TCommand, CFitnessCalc<TState, TCommand, TEvent>, CFitnessValue>::CGAOperatorMove(*m_config));
	m_config->AddOperator(new CGAConfiguration<TCommand, CFitnessCalc<TState, TCommand, TEvent>, CFitnessValue>::CGAOperatorMutate(*m_config));
}

template<typename TState, typename TCommand, typename TEvent>
void CSimulatorEngine<TState, TCommand, TEvent>::Start()
{
	if(m_bRunning)
		return;

	m_threadHandle = CThreadPool::Get()->StartThread(CSimulatorEngine<TState, TCommand, TEvent>::Execute, this);

	/*
	m_threadHandle = CreateThread( 
			NULL,				// default security attributes
			0,					// use default stack size  
			CSimulatorEngine<TState, TCommand, TEvent>::Execute,			// thread function name
			this,				// argument to thread function 
			0,					// use default creation flags 
			&m_threadId);		// returns the thread identifier 

	SetThreadPriority(m_threadHandle, THREAD_PRIORITY_BELOW_NORMAL);
	*/
}

template<typename TState, typename TCommand, typename TEvent>
void CSimulatorEngine<TState, TCommand, TEvent>::Stop()
{
	if(m_bRunning)
	{
		m_bContinueRunning = false;

		WaitForSingleObject(m_threadHandle, INFINITE);
	}
}

template<typename TState, typename TCommand, typename TEvent>
void CSimulatorEngine<TState, TCommand, TEvent>::Execute()
{
	m_bRunning = true;

	for(size_t i=0; i < m_villages.size(); i++)
		m_villages[i]->Start();

	m_city = new CGAPopulation<TCommand, CFitnessCalc<TState, TCommand, TEvent>, CFitnessValue>(*m_config, 1000);
	m_city->Initialise(200, 4, 8);

	for(m_evolution=0; m_bContinueRunning; m_evolution++)
	{
		m_stagnationLimit = 1000 + m_evolution / 1000;

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

		unsigned long long gameCount = m_city->gameCount();
		for(size_t i=0; i < m_villages.size(); i++)
			gameCount += m_villages[i]->gameCount();
		m_gameCount = gameCount; // Update game count in a single atomic operation

		if(m_evolution % 20 == 0) // Every 20 city evolutions update the best game
		{
			CLock lock(m_semaphore);
			delete m_bestGame;
			m_bestGame = new CVector<TCommand>(m_city->GetBestChromosome());
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

template<typename TState, typename TCommand, typename TEvent>
void CSimulatorEngine<TState, TCommand, TEvent>::PrintBestGame(CString &output) const
{
	CVector<TCommand> game;
	GetBestGame(game);
	
	m_targetFitness.PrintGame(output, game);
}

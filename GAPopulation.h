#pragma once
#include "stdafx.h"
#include "Vector.h"

#include "GAConfiguration.h"
#include "GAChromosome.h"

template<typename TGene, typename TFitnessCalc, typename TFitness>
class CGAPopulation
{
public:
	CGAPopulation(const CGAConfiguration<TGene, TFitnessCalc, TFitness> &config, size_t maxPopulation);
	~CGAPopulation();

	void Initialise(size_t initialPopulation, size_t minSize, size_t maxSize);

	bool AddChromosome(const CVector<TGene> &value);

	const CGAConfiguration<TGene, TFitnessCalc, TFitness> &config() const { return m_config; }

	size_t populationCount() const { return m_populationCount; }
	unsigned long long gameCount() const { return m_gameCount; }

	const TFitness GetBestFitness() const { return m_population[0]->GetFitness(); }
	const CVector<TGene> GetBestChromosome() const { return m_population[0]->GetValue(); }
	bool IsSatisfied() const { return m_config.SatisfiesTarget(GetBestChromosome()); }

	void Sort() { Sort(m_population); }
	bool Evolve();
	void Clear() { ClearPopulation(m_population); memset(m_population, 0, m_maxPopulation * sizeof(CGAChromosome<TGene, TFitness> *)); m_populationCount = 0; m_stagnationCount = 0; }

	void Print(size_t maxCount = 0);

	size_t StagnationCount() const { return m_stagnationCount; }
	size_t PopulationCount() const { return m_populationCount; }
	size_t MaxPopulation() const { return m_maxPopulation; }

protected:
	void Sort(CGAChromosome<TGene, TFitness> **population);
	void ClearPopulation(CGAChromosome<TGene, TFitness> **population);

	CMemoryPool m_populationMemPool;

	const CGAConfiguration<TGene, TFitnessCalc, TFitness> &m_config;

	size_t m_maxPopulation;
	size_t m_populationCount;
	size_t m_stagnationCount;
	unsigned long long m_gameCount;

	CGAChromosome<TGene, TFitness> **m_population;
};

template<typename TGene, typename TFitnessCalc, typename TFitness>
CGAPopulation<TGene, TFitnessCalc, TFitness>::CGAPopulation(const CGAConfiguration<TGene, TFitnessCalc, TFitness> &config, size_t maxPopulation)
: m_config(config), m_maxPopulation(maxPopulation < 20 ? 20 : maxPopulation), m_populationMemPool(maxPopulation * sizeof(CGAChromosome<TGene, TFitness> *)), m_stagnationCount(0), m_gameCount(0)
{
	m_populationCount = 0;
	m_population = (CGAChromosome<TGene, TFitness> **)m_populationMemPool.Alloc();
	memset(m_population, 0, m_maxPopulation * sizeof(CGAChromosome<TGene, TFitness> *));
}

template<typename TGene, typename TFitnessCalc, typename TFitness>
CGAPopulation<TGene, TFitnessCalc, TFitness>::~CGAPopulation()
{
	ClearPopulation(m_population);
	m_populationMemPool.Free(m_population);
}

template<typename TGene, typename TFitnessCalc, typename TFitness>
void CGAPopulation<TGene, TFitnessCalc, TFitness>::Initialise(size_t initialPopulation, size_t minSize, size_t maxSize)
{
	minSize = mymin(minSize, maxSize);
	for(size_t j=0; j < initialPopulation; j++)
	{
		CVector<TGene> junk;
		size_t size = (((maxSize - minSize) * rand_sse()) / RAND_MAX) + minSize;
		for(size_t k=0; k < size; k++)
			junk.push_back(m_config.GetRandomGene());

		AddChromosome(junk);
	}

	Sort(m_population);
}

template<typename TGene, typename TFitnessCalc, typename TFitness>
void CGAPopulation<TGene, TFitnessCalc, TFitness>::ClearPopulation(CGAChromosome<TGene, TFitness> **population)
{
	for(size_t i=0; i < m_maxPopulation; i++)
		if(population[i])
			delete population[i];
}

template<typename TGene, typename TFitnessCalc, typename TFitness>
bool CGAPopulation<TGene, TFitnessCalc, TFitness>::AddChromosome(const CVector<TGene> &value)
{
	CGAChromosome<TGene, TFitness> **ptrEmpty = m_population;
	if(m_populationCount >= m_maxPopulation)
	{
		ptrEmpty = &m_population[m_populationCount - 1];
		delete *ptrEmpty;
	}
	else
	{
		while(*ptrEmpty != 0)
			ptrEmpty++;
		m_populationCount++;
	}

	*ptrEmpty = new CGAChromosome<TGene, TFitness>(value);
	m_config.ValidateAndCalculateFitness(*ptrEmpty);

	return true;
}

template<typename TGene, typename TFitnessCalc, typename TFitness>
bool CGAPopulation<TGene, TFitnessCalc, TFitness>::Evolve()
{
	TFitness currentBestFitness = m_population[0]->GetFitness();

	CGAChromosome<TGene, TFitness> **newPopulation = (CGAChromosome<TGene, TFitness> **)m_populationMemPool.Alloc();
	memset(newPopulation, 0, m_maxPopulation * sizeof(CGAChromosome<TGene, TFitness> *));

	size_t newPopulationCount = m_maxPopulation / 8; // Save room for elitism performed later

	double totalFitness = 0;
	for(size_t i=0; i < m_maxPopulation; i++)
	{
		if(m_population[i] != 0)
			totalFitness += (double)m_population[i]->GetFitness();
	}

	while(newPopulationCount < m_maxPopulation && newPopulationCount < m_populationCount * 2)
	{
		// Breeding
		CGAChromosome<TGene, TFitness> *parentA, *parentB, **population;

		double chosenFitness = (totalFitness * rand_sse()) / RAND_MAX;
		double curFitness = 0;
		population = m_population;
		for(size_t i=0; i < m_maxPopulation; i++, population++)
		{
			if(*population != 0)
			{
				curFitness += (*population)->GetFitness();
	
				if(curFitness >= chosenFitness)
				{
					parentA = *population;
					break;
				}
			}
		}

		chosenFitness = (totalFitness * rand_sse()) / RAND_MAX;
		curFitness = 0;
		population = m_population;
		for(size_t i=0; i < m_maxPopulation; i++, population++)
		{
			if(*population != 0)
			{
				curFitness += (*population)->GetFitness();
	
				if(curFitness >= chosenFitness)
				{
					parentB = *population;
					break;
				}
			}
		}

		double crossover = (double)rand_sse() / (double)RAND_MAX;
		newPopulation[newPopulationCount++] = parentA->Breed(parentB, crossover);
		if(newPopulationCount < m_maxPopulation)
			newPopulation[newPopulationCount++] = parentB->Breed(parentA, crossover);
	}

	// Mutation
	for(size_t i = m_maxPopulation/8; i < newPopulationCount; i++)
	{
		for(size_t j=0; j < m_config.GetOperatorCount(); j++)
		{
			m_config.GetOperator(j)->Execute(newPopulation[i]);
		}
	}

	// Set Fitness
	for(size_t i=m_maxPopulation/8; i < newPopulationCount; i++)
	{
		m_gameCount++;
		m_config.ValidateAndCalculateFitness(newPopulation[i]);
	}

	// Elitism
	size_t tempIndex = 0;
	for(size_t i=0; i < m_maxPopulation && tempIndex < m_maxPopulation/8; i++)
	{
		if(m_population[i])
		{
			newPopulation[tempIndex++] = m_population[i];
			m_population[i] = 0;
		}
	}

	// Sort
	Sort(newPopulation);

	// Remove duplicates
	size_t curIndex = 0;
	for(size_t i=0; i < newPopulationCount; i++)
	{
		while(!newPopulation[i] && i < newPopulationCount)
			i++;

		if(i >= newPopulationCount)
			break;

		while(i < newPopulationCount - 1 && newPopulation[i+1] && newPopulation[i]->GetValue() == newPopulation[i+1]->GetValue())
		{
			delete newPopulation[i];
			newPopulation[i] = 0;
			i++;
		}

		if(curIndex != i)
		{
			newPopulation[curIndex++] = newPopulation[i];
			newPopulation[i] = 0;
		}
		else
			curIndex++;
	}

	m_populationCount = curIndex;

	ClearPopulation(m_population);
	m_populationMemPool.Free(m_population);
	m_population = newPopulation;

	if(currentBestFitness < m_population[0]->GetFitness())
		m_stagnationCount = 0;
	else
		m_stagnationCount++;
	
	return true;
}

template<typename TGene, typename TFitnessCalc, typename TFitness>
void CGAPopulation<TGene, TFitnessCalc, TFitness>::Sort(CGAChromosome<TGene, TFitness> **population)
{
	qsort(population, m_maxPopulation, sizeof(CGAChromosome<TGene, TFitness> *), CompareChromosome<TGene, TFitness>);
}

template<typename TGene, typename TFitnessCalc, typename TFitness>
void CGAPopulation<TGene, TFitnessCalc, TFitness>::Print(size_t maxCount /* = 0 */)
{
	cout << "Population count: " << m_populationCount << endl;
	for(size_t i=0; i < m_maxPopulation && i < maxCount; i++)
		if(m_population[i])
		{
			cout << "Chromosome " << i << ": ";
			m_population[i]->Print();
		}

	cout << "";
}

#pragma once
#include "stdafx.h"
#include "MemoryPool.h"
#include "FastString.h"
#include "Vector.h"

template<typename TGene>
class CGAChromosome : public CMemPoolNode<CGAChromosome<TGene>>
{
public:
	CGAChromosome(const CVector<TGene> &init) : m_value(init) {}
	CGAChromosome(const CGAChromosome<TGene> &chromosome) : m_value(chromosome.GetValue()) { SetFitness(chromosome.GetFitness()); }

	void SetFitness(double fitness) { m_fitness = fitness; }
	double GetFitness() const { return m_fitness; }

	void SetValue(const CVector<TGene> &value) { m_value = value; }
	const CVector<TGene> &GetValue() const { return m_value; }

	CGAChromosome<TGene> *Clone() const { return new CGAChromosome<TGene>(*this); }

	CGAChromosome<TGene> *Breed(const CGAChromosome<TGene> *spouse, double crossover) const;

protected:
	CVector<TGene> m_value;
	double m_fitness;
};

template<typename TGene>
CGAChromosome<TGene> *CGAChromosome<TGene>::Breed(const CGAChromosome<TGene> *spouse, double crossover) const
{
	CVector<TGene> value;
	value.append(m_value.data(), (size_t)(crossover * m_value.size()));
	size_t crossoverPoint = (size_t)(crossover * spouse->GetValue().size());
	value.append(spouse->GetValue().data() + crossoverPoint, spouse->GetValue().size() - crossoverPoint);

	CGAChromosome<TGene> *child = new CGAChromosome<TGene>(value);
	return child;
}

template<typename TGene>
int CompareChromosome(const void *p1, const void *p2)
{
	const CGAChromosome<TGene> *chromosome1 = *(const CGAChromosome<TGene> **)(p1);
	const CGAChromosome<TGene> *chromosome2 = *(const CGAChromosome<TGene> **)(p2);
	if(!chromosome1)
		return 1;
	else if(!chromosome2)
		return -1;
	else if(chromosome2->GetFitness() < chromosome1->GetFitness())
		return -1;
	else if(chromosome1->GetFitness() < chromosome2->GetFitness())
		return 1;
	else
	{
		if(chromosome1->GetValue().size() < chromosome2->GetValue().size())
			return -1;
		else if(chromosome2->GetValue().size() < chromosome1->GetValue().size())
			return 1;
		else
		{
			if(chromosome1->GetValue() < chromosome2->GetValue())
				return -1;
			else if(chromosome2->GetValue() < chromosome1->GetValue())
				return 1;
			else
				return 0;
		}
	}
}

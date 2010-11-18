#pragma once
#include "stdafx.h"
#include "MemoryPool.h"
#include "FastString.h"
#include "Vector.h"

template<typename TGene, typename TFitness>
class CGAChromosome : public CMemPoolNode<CGAChromosome<TGene, TFitness>>
{
public:
	CGAChromosome(const CVector<TGene> &init) : m_value(init) {}
	CGAChromosome(const CGAChromosome<TGene, TFitness> &chromosome) : m_value(chromosome.GetValue()) { SetFitness(chromosome.GetFitness()); }

	void SetFitness(TFitness fitness) { m_fitness = fitness; }
	TFitness GetFitness() const { return m_fitness; }

	void SetValue(const CVector<TGene> &value) { m_value = value; }
	CVector<TGene> &GetValue() { return m_value; }
	const CVector<TGene> &GetValue() const { return m_value; }

	CGAChromosome<TGene, TFitness> *Clone() const { return new CGAChromosome<TGene, TFitness>(*this); }

	CGAChromosome<TGene, TFitness> *Breed(const CGAChromosome<TGene, TFitness> *spouse, double crossover) const;

protected:
	CVector<TGene> m_value;
	TFitness m_fitness;
};

template<typename TGene, typename TFitness>
CGAChromosome<TGene, TFitness> *CGAChromosome<TGene, TFitness>::Breed(const CGAChromosome<TGene, TFitness> *spouse, double crossover) const
{
	CVector<TGene> value;
	value.append(m_value.data(), (size_t)(crossover * m_value.size()));
	size_t crossoverPoint = (size_t)(crossover * spouse->GetValue().size());
	value.append(spouse->GetValue().data() + crossoverPoint, spouse->GetValue().size() - crossoverPoint);

	return new CGAChromosome<TGene, TFitness>(value);
}

template<typename TGene, typename TFitness>
int CompareChromosome(const void *p1, const void *p2)
{
	const CGAChromosome<TGene, TFitness> *chromosome1 = *(const CGAChromosome<TGene, TFitness> **)(p1);
	const CGAChromosome<TGene, TFitness> *chromosome2 = *(const CGAChromosome<TGene, TFitness> **)(p2);
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

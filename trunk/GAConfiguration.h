#pragma once
#include "stdafx.h"
#include "GAChromosome.h"
#include "GAOperator.h"

template<typename TGene, typename TFitnessCalc, typename TFitness>
class CGAConfiguration
{
public:
	class CGAOperator
	{
	public:
		CGAOperator(const CGAConfiguration<TGene, TFitnessCalc, TFitness> &config) : m_config(config) {}
		virtual bool Execute(CGAChromosome<TGene, TFitness> *chromosome) const = 0;
	protected:
		const CGAConfiguration &m_config;
	};

	class CGAOperatorInsert : public CGAOperator
	{
	public:
		CGAOperatorInsert(const CGAConfiguration<TGene, TFitnessCalc, TFitness> &config) : CGAOperator(config) {}
		virtual bool Execute(CGAChromosome<TGene, TFitness> *chromosome) const;
	};

	class CGAOperatorDuplicate : public CGAOperator
	{
	public:
		CGAOperatorDuplicate(const CGAConfiguration<TGene, TFitnessCalc, TFitness> &config) : CGAOperator(config) {}
		virtual bool Execute(CGAChromosome<TGene, TFitness> *chromosome) const;
	};

	class CGAOperatorDelete : public CGAOperator
	{
	public:
		CGAOperatorDelete(const CGAConfiguration<TGene, TFitnessCalc, TFitness> &config) : CGAOperator(config) {}
		virtual bool Execute(CGAChromosome<TGene, TFitness> *chromosome) const;
	};

	class CGAOperatorImmediateSwap : public CGAOperator
	{
	public:
		CGAOperatorImmediateSwap(const CGAConfiguration<TGene, TFitnessCalc, TFitness> &config) : CGAOperator(config) {}
		virtual bool Execute(CGAChromosome<TGene, TFitness> *chromosome) const;
	};

	class CGAOperatorRandomSwap : public CGAOperator
	{
	public:
		CGAOperatorRandomSwap(const CGAConfiguration<TGene, TFitnessCalc, TFitness> &config) : CGAOperator(config) {}
		virtual bool Execute(CGAChromosome<TGene, TFitness> *chromosome) const;
	};

	class CGAOperatorMove : public CGAOperator
	{
	public:
		CGAOperatorMove(const CGAConfiguration<TGene, TFitnessCalc, TFitness> &config) : CGAOperator(config) {}
		virtual bool Execute(CGAChromosome<TGene, TFitness> *chromosome) const;
	};

	class CGAOperatorMutate : public CGAOperator
	{
	public:
		CGAOperatorMutate(const CGAConfiguration<TGene, TFitnessCalc, TFitness> &config) : CGAOperator(config) {}
		virtual bool Execute(CGAChromosome<TGene, TFitness> *chromosome) const;
	};

	CGAConfiguration(const CVector<TGene> &alphabet, double mutationRate, const TFitnessCalc &fitness);

	void AddOperator(CGAOperator *op) { m_operators.push_back(op); }

	size_t GetMutationCount() const { int r = rand_sse(); if(r < m_mutationCountOneCutOff) return 1; else if(r < m_mutationCountTwoCutOff) return 2; else if(r < m_mutationCountThreeCutOff) return 3; return 0; }
	const CVector<TGene> &GetAlphabet() const { return m_alphabet; }
	TGene GetRandomGene() const { return m_alphabet[(rand_sse() * m_alphabet.size()) / (RAND_MAX + 1)]; }
	size_t GetOperatorCount() const { return m_operators.size(); }
	const CGAOperator *GetOperator(size_t index) const { return m_operators[index]; }

	bool ValidateAndCalculateFitness(CGAChromosome<TGene, TFitness> *chromosome) const;
	bool SatisfiesTarget(const CVector<TGene> &value) const { return m_fitness.SatisfiesTarget(value); }

protected:
	const TFitnessCalc &m_fitness;
	CVector<TGene> m_alphabet;
	short m_mutationCountOneCutOff;
	short m_mutationCountTwoCutOff;
	short m_mutationCountThreeCutOff;
	double m_mutationRate;

	CVector<CGAOperator *> m_operators;

	mutable CMemoryPoolManager m_memoryManager;
};

template<typename TGene, typename TFitnessCalc, typename TFitness>
CGAConfiguration<TGene, TFitnessCalc, TFitness>::CGAConfiguration(const CVector<TGene> &alphabet, double mutationRate, const TFitnessCalc &fitness)
: m_alphabet(alphabet), m_fitness(fitness), m_mutationRate(mutationRate)
{
	m_mutationCountOneCutOff = (short)(RAND_MAX * mutationRate);
	m_mutationCountTwoCutOff = (short)(m_mutationCountOneCutOff + RAND_MAX * 0.1 * mutationRate);
	m_mutationCountThreeCutOff = (short)(m_mutationCountTwoCutOff + RAND_MAX * 0.01 * mutationRate);
}

template<typename TGene, typename TFitnessCalc, typename TFitness>
bool CGAConfiguration<TGene, TFitnessCalc, TFitness>::ValidateAndCalculateFitness(CGAChromosome<TGene, TFitness> *chromosome) const
{
	TFitness fitness;
	if(!m_fitness.ValidateAndCalculateFitness(chromosome->GetValue(), fitness))
		return false;

	chromosome->SetFitness(fitness);
	return true;
}


template<typename TGene, typename TFitnessCalc, typename TFitness>
bool CGAConfiguration<TGene, TFitnessCalc, TFitness>::CGAOperatorInsert::Execute(CGAChromosome<TGene, TFitness> *chromosome) const
{
	size_t mutationCount = m_config.GetMutationCount();
	if(mutationCount > 0)
	{
		CVector<TGene> value(chromosome->GetValue());
		for(; mutationCount > 0; mutationCount--)
		{
			size_t i = (rand_sse() * (value.size() + 1)) / (RAND_MAX + 1);
			value.insert(i, m_config.GetRandomGene());
		}
		chromosome->SetValue(value);
	}

	return true;
}

template<typename TGene, typename TFitnessCalc, typename TFitness>
bool CGAConfiguration<TGene, TFitnessCalc, TFitness>::CGAOperatorDuplicate::Execute(CGAChromosome<TGene, TFitness> *chromosome) const
{
	if(0 >= chromosome->GetValue().size())
		return true;

	size_t mutationCount = m_config.GetMutationCount();
	if(mutationCount > 0)
	{
		CVector<TGene> value(chromosome->GetValue());
		for(; mutationCount > 0; mutationCount--)
		{
			size_t i = (rand_sse() * value.size()) / (RAND_MAX + 1);
			value.insert(i, value[i]);
		}
		chromosome->SetValue(value);
	}

	return true;
}

template<typename TGene, typename TFitnessCalc, typename TFitness>
bool CGAConfiguration<TGene, TFitnessCalc, TFitness>::CGAOperatorDelete::Execute(CGAChromosome<TGene, TFitness> *chromosome) const
{
	if(1 >= chromosome->GetValue().size())
		return true;

	size_t mutationCount = mymin(m_config.GetMutationCount(), chromosome->GetValue().size() - 1);
	if(mutationCount > 0)
	{
		CVector<TGene> value(chromosome->GetValue());
		for(; mutationCount > 0; mutationCount--)
		{
			size_t i = (rand_sse() * value.size()) / (RAND_MAX + 1);
			value.erase(i);
		}
		chromosome->SetValue(value);
	}

	return true;
}

template<typename TGene, typename TFitnessCalc, typename TFitness>
bool CGAConfiguration<TGene, TFitnessCalc, TFitness>::CGAOperatorImmediateSwap::Execute(CGAChromosome<TGene, TFitness> *chromosome) const
{
	if(1 >= chromosome->GetValue().size())
		return true;

	size_t mutationCount = m_config.GetMutationCount();
	if(mutationCount > 0)
	{
		CVector<TGene> value(chromosome->GetValue());
		for(; mutationCount > 0; mutationCount--)
		{
			size_t i = (rand_sse() * (value.size() - 1)) / (RAND_MAX + 1);
			size_t j = i+1;

			TGene gene = value[i];
			value[i] = value[j];
			value[j] = gene;
		}
		chromosome->SetValue(value);
	}

	return true;
}

template<typename TGene, typename TFitnessCalc, typename TFitness>
bool CGAConfiguration<TGene, TFitnessCalc, TFitness>::CGAOperatorRandomSwap::Execute(CGAChromosome<TGene, TFitness> *chromosome) const
{
	if(1 >= chromosome->GetValue().size())
		return true;

	size_t mutationCount = m_config.GetMutationCount();
	if(mutationCount > 0)
	{
		CVector<TGene> value(chromosome->GetValue());
		for(; mutationCount > 0; mutationCount--)
		{
			size_t i = (rand_sse() * value.size()) / (RAND_MAX + 1);
			size_t j = (rand_sse() * value.size()) / (RAND_MAX + 1);

			TGene gene = value[i];
			value[i] = value[j];
			value[j] = gene;
		}
		chromosome->SetValue(value);
	}

	return true;
}

template<typename TGene, typename TFitnessCalc, typename TFitness>
bool CGAConfiguration<TGene, TFitnessCalc, TFitness>::CGAOperatorMove::Execute(CGAChromosome<TGene, TFitness> *chromosome) const
{
	if(1 >= chromosome->GetValue().size())
		return true;

	size_t mutationCount = m_config.GetMutationCount();
	if(mutationCount > 0)
	{
		CVector<TGene> value(chromosome->GetValue());
		for(; mutationCount > 0; mutationCount--)
		{
			size_t i = (rand_sse() * value.size()) / (RAND_MAX + 1);
			size_t j = (rand_sse() * (value.size() - 1)) / (RAND_MAX + 1);

			TGene gene = value[i];
			value.erase(i);
			value.insert(j, gene);
		}
		chromosome->SetValue(value);
	}

	return true;
}

template<typename TGene, typename TFitnessCalc, typename TFitness>
bool CGAConfiguration<TGene, TFitnessCalc, TFitness>::CGAOperatorMutate::Execute(CGAChromosome<TGene, TFitness> *chromosome) const
{
	if(0 >= chromosome->GetValue().size())
		return true;

	size_t mutationCount = m_config.GetMutationCount();
	if(mutationCount > 0)
	{
		CVector<TGene> value(chromosome->GetValue());
		for(; mutationCount > 0; mutationCount--)
		{
			size_t i = (rand_sse() * value.size()) / (RAND_MAX + 1);

			value[i] = m_config.GetRandomGene();
		}
		chromosome->SetValue(value);
	}

	return true;
}

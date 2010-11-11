#pragma once
#include "stdafx.h"
#include "GAChromosome.h"
#include "GAOperator.h"

template<typename TGene, typename TFitness>
class CGAConfiguration
{
public:
	class CGAOperator
	{
	public:
		CGAOperator(const CGAConfiguration<TGene, TFitness> &config) : m_config(config) {}
		virtual bool Execute(CGAChromosome<TGene> *chromosome) const = 0;
	protected:
		const CGAConfiguration &m_config;
	};

	class CGAOperatorInsert : public CGAOperator
	{
	public:
		CGAOperatorInsert(const CGAConfiguration<TGene, TFitness> &config) : CGAOperator(config) {}
		virtual bool Execute(CGAChromosome<TGene> *chromosome) const;
	};

	class CGAOperatorDuplicate : public CGAOperator
	{
	public:
		CGAOperatorDuplicate(const CGAConfiguration<TGene, TFitness> &config) : CGAOperator(config) {}
		virtual bool Execute(CGAChromosome<TGene> *chromosome) const;
	};

	class CGAOperatorDelete : public CGAOperator
	{
	public:
		CGAOperatorDelete(const CGAConfiguration<TGene, TFitness> &config) : CGAOperator(config) {}
		virtual bool Execute(CGAChromosome<TGene> *chromosome) const;
	};

	class CGAOperatorImmediateSwap : public CGAOperator
	{
	public:
		CGAOperatorImmediateSwap(const CGAConfiguration<TGene, TFitness> &config) : CGAOperator(config) {}
		virtual bool Execute(CGAChromosome<TGene> *chromosome) const;
	};

	class CGAOperatorRandomSwap : public CGAOperator
	{
	public:
		CGAOperatorRandomSwap(const CGAConfiguration<TGene, TFitness> &config) : CGAOperator(config) {}
		virtual bool Execute(CGAChromosome<TGene> *chromosome) const;
	};

	class CGAOperatorMove : public CGAOperator
	{
	public:
		CGAOperatorMove(const CGAConfiguration<TGene, TFitness> &config) : CGAOperator(config) {}
		virtual bool Execute(CGAChromosome<TGene> *chromosome) const;
	};

	class CGAOperatorMutate : public CGAOperator
	{
	public:
		CGAOperatorMutate(const CGAConfiguration<TGene, TFitness> &config) : CGAOperator(config) {}
		virtual bool Execute(CGAChromosome<TGene> *chromosome) const;
	};

	CGAConfiguration(const CVector<TGene> &alphabet, double mutationRate, const TFitness &fitness);

	void AddOperator(CGAOperator *op) { m_operators.push_back(op); }

	bool GetMutation() const { return rand_sse() < m_mutationCutOff; }
	const CVector<TGene> &GetAlphabet() const { return m_alphabet; }
	TGene GetRandomGene() const { return m_alphabet[(rand_sse() * m_alphabet.size()) / (RAND_MAX + 1)]; }
	size_t GetOperatorCount() const { return m_operators.size(); }
	const CGAOperator *GetOperator(size_t index) const { return m_operators[index]; }

	double CalculateFitness(const CVector<TGene> &value) const { return m_fitness.CalculateFitness(value); }
	bool SatisfiesTarget(const CVector<TGene> &value) const { return m_fitness.SatisfiesTarget(value); }

protected:
	TFitness m_fitness;
	CVector<TGene> m_alphabet;
	short m_mutationCutOff;

	CVector<CGAOperator *> m_operators;

	mutable CMemoryPoolManager m_memoryManager;
};

template<typename TGene, typename TFitness>
CGAConfiguration<TGene, TFitness>::CGAConfiguration(const CVector<TGene> &alphabet, double mutationRate, const TFitness &fitness)
: m_alphabet(alphabet), m_fitness(fitness)
{
	m_mutationCutOff = (short)(RAND_MAX * mutationRate);
}

template<typename TGene, typename TFitness>
bool CGAConfiguration<TGene, TFitness>::CGAOperatorInsert::Execute(CGAChromosome<TGene> *chromosome) const
{
	CVector<TGene> value(chromosome->GetValue());
	bool hasMutated = false;
	for(size_t i=0; i < value.size() + 1; i++)
	{
		if(m_config.GetMutation())
		{
			value.insert(i, m_config.GetRandomGene());
			hasMutated = true;
		}
	}

	if(hasMutated)
		chromosome->SetValue(value);

	return true;
}

template<typename TGene, typename TFitness>
bool CGAConfiguration<TGene, TFitness>::CGAOperatorDuplicate::Execute(CGAChromosome<TGene> *chromosome) const
{
	CVector<TGene> value(chromosome->GetValue());
	bool hasMutated = false;
	for(size_t i=0; i < value.size(); i++)
	{
		if(m_config.GetMutation())
		{
			value.insert(i, value[i]);
			hasMutated = true;
		}
	}

	if(hasMutated)
		chromosome->SetValue(value);

	return true;
}

template<typename TGene, typename TFitness>
bool CGAConfiguration<TGene, TFitness>::CGAOperatorDelete::Execute(CGAChromosome<TGene> *chromosome) const
{
	CVector<TGene> value(chromosome->GetValue());
	bool hasMutated = false;
	for(size_t i=0; i < value.size() && value.size() > 1; i++)
	{
		if(m_config.GetMutation())
		{
			value.erase(i);
			hasMutated = true;
		}
	}

	if(hasMutated)
		chromosome->SetValue(value);

	return true;
}

template<typename TGene, typename TFitness>
bool CGAConfiguration<TGene, TFitness>::CGAOperatorImmediateSwap::Execute(CGAChromosome<TGene> *chromosome) const
{
	CVector<TGene> value(chromosome->GetValue());
	bool hasMutated = false;
	for(size_t i=0; i < value.size() - 1; i++)
	{
		if(m_config.GetMutation())
		{
			size_t j = i+1;

			if(value[i] != value[j])
			{
				TGene gene = value[i];
				value[i] = value[j];
				value[j] = gene;
				hasMutated = true;
			}
		}
	}

	if(hasMutated)
		chromosome->SetValue(value);

	return true;
}

template<typename TGene, typename TFitness>
bool CGAConfiguration<TGene, TFitness>::CGAOperatorRandomSwap::Execute(CGAChromosome<TGene> *chromosome) const
{
	CVector<TGene> value(chromosome->GetValue());
	bool hasMutated = false;
	for(size_t i=0; i < value.size(); i++)
	{
		if(m_config.GetMutation())
		{
			size_t j = rand_sse() % value.size();

			if(i != j && value[i] != value[j])
			{
				TGene gene = value[i];
				value[i] = value[j];
				value[j] = gene;
				hasMutated = true;
			}
		}
	}

	if(hasMutated)
		chromosome->SetValue(value);

	return true;
}

template<typename TGene, typename TFitness>
bool CGAConfiguration<TGene, TFitness>::CGAOperatorMove::Execute(CGAChromosome<TGene> *chromosome) const
{
	CVector<TGene> value(chromosome->GetValue());
	bool hasMutated = false;
	for(size_t i=0; i < value.size(); i++)
	{
		if(m_config.GetMutation())
		{
			size_t j = rand_sse() % value.size();

			if(i != j)
			{
				TGene gene = value[i];
				value.erase(i);
				value.insert(j, gene);
				hasMutated = true;
			}
		}
	}

	if(hasMutated)
		chromosome->SetValue(value);

	return true;
}

template<typename TGene, typename TFitness>
bool CGAConfiguration<TGene, TFitness>::CGAOperatorMutate::Execute(CGAChromosome<TGene> *chromosome) const
{
	CVector<TGene> value(chromosome->GetValue());
	bool hasMutated = false;
	for(size_t i=0; i < value.size(); i++)
	{
		if(m_config.GetMutation())
		{
			value[i] = m_config.GetRandomGene();
			hasMutated = true;
		}
	}

	if(hasMutated)
		chromosome->SetValue(value);

	return true;
}

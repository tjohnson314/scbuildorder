#pragma once

#include <iostream>
#include <stdio.h>
#include "Vector.h"

template <typename TState, typename TCommand, typename TEvent>
class CFitness
{
public:
	CFitness(const TState &target, double timeLimit);

	double CalculateFitness(const CVector<TCommand> &value) const;
	bool SatisfiesTarget(const CVector<TCommand> &value) const { return false; }

	void PrintGame(CString &output, const CVector<TCommand> &value) const;

protected:
	TState m_target;
	double m_timeLimit;
};

template <typename TState, typename TCommand, typename TEvent>
CFitness<TState, TCommand, TEvent>::CFitness(const TState &target, double timeLimit)
: m_target(target), m_timeLimit(timeLimit)
{
	m_target.AddRequirements();
}

template <typename TState, typename TCommand, typename TEvent>
double CFitness<TState, TCommand, TEvent>::CalculateFitness(const CVector<TCommand> &value) const
{
	double time = 0;

	TState state;
	state.SetInitialState();

	CLinkedList<TEvent> *events = 0;

	bool bSatisfied = false;

	const TCommand *data = value.data();
	for(size_t i=0; i < value.size(); i++, data++)
	{
		if(!state.HasBuildingRequirements(time, *data))
			break; // No junk DNA :P

		if(!state.ExecuteCommand(time, m_timeLimit, *data, events))
			break;

		if(state >= m_target)
		{
			bSatisfied = true;
			break;
		}
	}

	while(events && !bSatisfied && events->GetData().time() < m_timeLimit)
	{
		state.ProcessEvent(time, events);

		if(state >= m_target)
			bSatisfied = true;
	}

	double fitness = 0;

	TState intersection;
	intersection.intersection(state, m_target);

	TState extra(state);
	extra -= intersection;

	fitness = intersection.value() + 0.01 * extra.value();

	if(!bSatisfied)
		fitness /= m_timeLimit;
	else if(0 < time)
		fitness /= time;

	while(events)
	{
		CLinkedList<TEvent> *event = events;
		events = events->GetNext();
		delete event;
	}

	return fitness;
}

template <typename TState, typename TCommand, typename TEvent>
void CFitness<TState, TCommand, TEvent>::PrintGame(CString &output, const CVector<TCommand> &value) const
{
	double time = 0;

	TState state;
	state.SetInitialState();

	CLinkedList<TEvent> *events = 0;

	bool bSatisfied = false;

	output = "";

	const TCommand *data = value.data();
	for(size_t i=0; i < value.size(); i++, data++)
	{
		if(!state.HasBuildingRequirements(time, *data))
			break; // No junk DNA :P

		if(!state.PrepareToExecuteCommand(time, m_timeLimit, *data, events))
			break;

		output.AppendFormat(L"%7.2f: ", time);
		state.PrintSummary(output);
		output.AppendFormat(L" - %s\r\n", tostring(*data));

		if(!state.ExecuteCommand(time, m_timeLimit, *data, events))
			break;

		if(state >= m_target)
		{
			bSatisfied = true;
			break;
		}
	}

	while(events && !bSatisfied && events->GetData().time() < m_timeLimit)
	{
		state.ProcessEvent(time, events);

		if(state >= m_target)
			bSatisfied = true;
	}

	output.AppendFormat(L"%7.2f: ", time);
	state.PrintSummary(output);
	output.AppendFormat(L" - %s.\r\n", bSatisfied ? L"Satisfied" : L"Failed");

	while(events)
	{
		CLinkedList<TEvent> *event = events;
		events = events->GetNext();
		delete event;
	}
}

#pragma once

#include <iostream>
#include <stdio.h>
#include "Vector.h"
#include "FitnessValue.h"

template <typename TTarget, typename TState, typename TCommand, typename TEvent>
class CFitnessCalc
{
public:
	class CWaypoint
	{
	public:
		CWaypoint(const TTarget &target, double targetTime) : m_target(target), m_targetTime(targetTime) { m_target.AddRequirements(); }
	
		TTarget m_target;
		double m_targetTime;
	};

	CFitnessCalc(double timeLimit) : m_timeLimit(timeLimit) {}
	~CFitnessCalc();

	void BuildAlphabet(CVector<TCommand> &alphabet);
	void AddWaypoint(const TTarget &target, double targetTime);

	void ClearCustomEvents() { m_customEvents.erase(0, m_customEvents.size()); }
	void AddCustomEvent(const TEvent &event) { m_customEvents.push_back(event); }

	bool ValidateAndCalculateFitness(CVector<TCommand> &value, CFitnessValue &fitness) const;
	bool SatisfiesTarget(const CVector<TCommand> &value) const { return false; }

	void PrintGame(CString &output, const CVector<TCommand> &value) const;

protected:
	double m_timeLimit;
	CVector<const CWaypoint *> m_waypoints;
	CVector<TEvent> m_customEvents;
};

template <typename TTarget, typename TState, typename TCommand, typename TEvent>
CFitnessCalc<TTarget, TState, TCommand, TEvent>::~CFitnessCalc()
{
	const CWaypoint * const *waypoint = m_waypoints.data();
	for(size_t i=0; i < m_waypoints.size(); i++, waypoint++)
		delete *waypoint;
}

template <typename TTarget, typename TState, typename TCommand, typename TEvent>
void CFitnessCalc<TTarget, TState, TCommand, TEvent>::AddWaypoint(const TTarget &target, double targetTime)
{
	m_waypoints.push_back(new CWaypoint(target, targetTime));
	if(targetTime > m_timeLimit)
		m_timeLimit = targetTime;
}

template <typename TTarget, typename TState, typename TCommand, typename TEvent>
void CFitnessCalc<TTarget, TState, TCommand, TEvent>::BuildAlphabet(CVector<TCommand> &alphabet)
{
	TTarget target;
	for(size_t i=0; i < m_waypoints.size(); i++)
	{
		target += m_waypoints[i]->m_target;
	}

	target.BuildAlphabet(alphabet);
}

template <typename TTarget, typename TState, typename TCommand, typename TEvent>
bool CFitnessCalc<TTarget, TState, TCommand, TEvent>::ValidateAndCalculateFitness(CVector<TCommand> &value, CFitnessValue &fitness) const
{
	double time = 2; // Assume it takes 2 secs to start building/mining anything

	TState state;
	CLinkedList<TEvent> *events = 0;
	state.SetInitialState();

	const TEvent *customEvent = m_customEvents.data();
	for(size_t i=0; i < m_customEvents.size(); i++, customEvent++)
		state.AddEvent(events, *customEvent);

	size_t cmdIndex = 0;
	const TCommand *command = value.data();
	const CWaypoint * const *waypoint = m_waypoints.data();
	bool bSatisfied = true, bRanOutOfTime = false;
	size_t i=0;
	while(true)
	{
		bSatisfied = false;

		for(; cmdIndex < value.size(); cmdIndex++, command++)
		{
			if(!state.HasBuildingRequirements(time, *command))
				break; // No junk DNA :P

			TState::CResourceCost cost;
			state.GetCost(cost, *command);

			bool bHaveCost = state.HasResources(cost);
			bool bHaveStateRequirements = state.HasBuildingStateRequirements(time, *command);

			while(!bHaveCost || !bHaveStateRequirements)
			{
				double resourceWaitTime;
				bool bWillGetResources = true;

				bool bWaitForEvent = !bHaveStateRequirements;

				if(!bWaitForEvent)
				{
					bWillGetResources = state.GetResourceWaitTime(cost, resourceWaitTime);
					bWaitForEvent = !bWillGetResources || (events && events->GetData().time() < time + resourceWaitTime);
				}

				if(bWaitForEvent)
				{
					if(!events)
						break; // Will never get resources / building state requirements
					else
					{
						// Process the event
						if(!bRanOutOfTime && events->GetData().time() > (*waypoint)->m_targetTime)
						{
							bRanOutOfTime = true;

							fitness.m_targetValue += (*waypoint)->m_target.targetValue(state, 0);
							fitness.m_targetValueTime = (*waypoint)->m_targetTime;
						}

						if(events->GetData().time() > m_timeLimit)
							break;

						state.ProcessEvent(time, events);

						if((*waypoint)->m_target.satisfiesTarget(state))
						{
							bSatisfied = true;
							break;
						}

						bHaveStateRequirements = state.HasBuildingStateRequirements(time, *command);
						if(bHaveStateRequirements)
							bHaveCost = state.HasResources(cost);
					}
				}
				else if(!bHaveStateRequirements)
					break; // Will never get the state requirements
				else if(!bWillGetResources)
					break; // Will never get resources
				else
				{
					if(!bRanOutOfTime && time + resourceWaitTime > (*waypoint)->m_targetTime)
					{
						bRanOutOfTime = true;

						fitness.m_targetValue += (*waypoint)->m_target.targetValue(state, 0);
						fitness.m_targetValueTime = (*waypoint)->m_targetTime;
					}

					if(time + resourceWaitTime > m_timeLimit)
						break;
					else
					{
						state.ProgressTime(time, resourceWaitTime);
						bHaveCost = true;
					}
				}
			}

			if(bSatisfied || !bHaveCost || !bHaveStateRequirements)
				break;

			state.SpendResources(cost);
			state.ExecuteCommand(time, (*waypoint)->m_targetTime, *command, events);

			if((*waypoint)->m_target.satisfiesTarget(state))
			{
				bSatisfied = true;
				break;
			}
		}

		if(!bSatisfied)
		{
			while(events)
			{
				if(!bRanOutOfTime && events->GetData().time() > (*waypoint)->m_targetTime)
				{
					bRanOutOfTime = true;

					fitness.m_targetValue += (*waypoint)->m_target.targetValue(state, 0);
					fitness.m_targetValueTime = (*waypoint)->m_targetTime;
				}

				if(events->GetData().time() > m_timeLimit)
					break;

				state.ProcessEvent(time, events);

				if((*waypoint)->m_target.satisfiesTarget(state))
				{
					bSatisfied = true;
					break;
				}
			}
		}

		if(!bRanOutOfTime)
		{
			fitness.m_targetValue += (*waypoint)->m_target.targetValue(state, bSatisfied ? time : 0);
			if(bSatisfied)
				fitness.m_targetValueTime = time + (*waypoint)->m_target.targetTimePenalty(state, time);
			else
				fitness.m_targetValueTime = (*waypoint)->m_targetTime;
		}
		else
		{
			fitness.m_extraValue = (*waypoint)->m_target.targetValue(state, 0);
			fitness.m_extraValueTime = time;
		}

		i++;
		if(!(i < m_waypoints.size() && bSatisfied && !bRanOutOfTime))
			break;

		waypoint++;
	}

	if(!bRanOutOfTime)
		fitness.m_extraValue = (*waypoint)->m_target.extraValue(state);

	value.truncate(cmdIndex + 1); // No point keeping the build order longer than it needs to be

	while(events)
	{
		CLinkedList<TEvent> *event = events;
		events = events->GetNext();
		delete event;
	}

	return true;
}

template <typename TTarget, typename TState, typename TCommand, typename TEvent>
void CFitnessCalc<TTarget, TState, TCommand, TEvent>::PrintGame(CString &output, const CVector<TCommand> &value) const
{
	double time = 2.0; // Assume it takes 2 secs to start building/mining anything
	TState state;
	CLinkedList<TEvent> *events = 0;
	state.SetInitialState();
	output = "";

	const TEvent *customEvent = m_customEvents.data();
	for(size_t i=0; i < m_customEvents.size(); i++, customEvent++)
		state.AddEvent(events, *customEvent);

	size_t cmdIndex = 0;
	const TCommand *command = value.data();
	const CWaypoint * const *waypoint = m_waypoints.data();
	bool bContinue = true, bSatisfied = false;
	bool bRanOutOfTime = false;
	for(size_t i=0; i < m_waypoints.size() && bContinue; i++, waypoint++)
	{
		bSatisfied = false;

		for(; cmdIndex < value.size(); cmdIndex++, command++)
		{
			if(!state.HasBuildingRequirements(time, *command))
				break; // No junk DNA :P

			TState::CResourceCost cost;
			state.GetCost(cost, *command);

			bool bHaveCost = state.HasResources(cost);
			bool bHaveStateRequirements = state.HasBuildingStateRequirements(time, *command);

			while(!bHaveCost || !bHaveStateRequirements)
			{
				double resourceWaitTime;
				bool bWillGetResources = true;

				bool bWaitForEvent = !bHaveStateRequirements;

				if(!bWaitForEvent)
				{
					bWillGetResources = state.GetResourceWaitTime(cost, resourceWaitTime);
					bWaitForEvent = !bWillGetResources || (events && events->GetData().time() < time + resourceWaitTime);
				}

				if(bWaitForEvent)
				{
					if(!events)
						break; // Will never get resources / building state requirements
					else
					{
						// Process the event
						if(!bRanOutOfTime && events->GetData().time() > (*waypoint)->m_targetTime)
						{
							bRanOutOfTime = true;

							output.AppendFormat(L"\r\nWaypoint %d %s:\r\n", i + 1, bSatisfied ? L"satisfied" : L"failed");
							output.AppendFormat(L"%2d:%05.2f: ", (int)(time/60) - 60*(int)(time/3600), time - 60*(int)(time/60));
							state.PrintDetails(output);
							output.Append(L"\r\n");
						}

						if(events->GetData().time() > m_timeLimit)
							break;

						state.ProcessEvent(time, events);

						if((*waypoint)->m_target.satisfiesTarget(state))
						{
							bSatisfied = true;
							break;
						}

						if(!bHaveStateRequirements)
							bHaveStateRequirements = state.HasBuildingStateRequirements(time, *command);
						if(bHaveStateRequirements && !bHaveCost)
							bHaveCost = state.HasResources(cost);
					}
				}
				else if(!bHaveStateRequirements)
					break; // Will never get the state requirements
				else if(!bWillGetResources)
					break; // Will never get resources
				else
				{
					if(!bRanOutOfTime && time + resourceWaitTime > (*waypoint)->m_targetTime)
					{
						bRanOutOfTime = true;

						output.AppendFormat(L"\r\nWaypoint %d %s:\r\n", i + 1, bSatisfied ? L"satisfied" : L"failed");
						output.AppendFormat(L"%2d:%05.2f: ", (int)(time/60) - 60*(int)(time/3600), time - 60*(int)(time/60));
						state.PrintDetails(output);
						output.Append(L"\r\n");
					}

					if(time + resourceWaitTime > m_timeLimit)
						break;
					else
					{
						state.ProgressTime(time, resourceWaitTime);
						bHaveCost = true;
					}
				}
			}

			if(bSatisfied || !bHaveCost || !bHaveStateRequirements)
				break;

			output.AppendFormat(L"%2d:%05.2f: ", (int)(time/60) - 60*(int)(time/3600), time - 60*(int)(time/60));
			state.PrintSummary(output);
			output.AppendFormat(L" - %s\r\n", tostring(*command));

			state.SpendResources(cost);
			state.ExecuteCommand(time, (*waypoint)->m_targetTime, *command, events);

			if((*waypoint)->m_target.satisfiesTarget(state))
			{
				bSatisfied = true;
				break;
			}
		}

		if(!bSatisfied)
		{
			while(events)
			{
				if(!bRanOutOfTime && events->GetData().time() > (*waypoint)->m_targetTime)
				{
					bRanOutOfTime = true;

					output.AppendFormat(L"\r\nWaypoint %d %s:\r\n", i + 1, bSatisfied ? L"satisfied" : L"failed");
					output.AppendFormat(L"%2d:%05.2f: ", (int)(time/60) - 60*(int)(time/3600), time - 60*(int)(time/60));
					state.PrintDetails(output);
					output.Append(L"\r\n");
				}

				if(events->GetData().time() > m_timeLimit)
					break;

				state.ProcessEvent(time, events);

				if((*waypoint)->m_target.satisfiesTarget(state))
				{
					bSatisfied = true;
					break;
				}
			}
		}

		output.AppendFormat(L"\r\nWaypoint %d %s:\r\n", i + 1, bSatisfied ? L"satisfied" : L"failed");
		output.AppendFormat(L"%2d:%05.2f: ", (int)(time/60) - 60*(int)(time/3600), time - 60*(int)(time/60));
		state.PrintDetails(output);
		output.Append(L"\r\n");
	}

	while(events)
	{
		CLinkedList<TEvent> *event = events;
		events = events->GetNext();
		delete event;
	}
}

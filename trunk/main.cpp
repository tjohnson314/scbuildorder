#include "stdafx.h"

#include <time.h>

#include "GAConfiguration.h"
#include "GAChromosome.h"
#include "GAOperator.h"
#include "GAPopulation.h"

#include "ProtossCommand.h"
#include "ProtossEvent.h"
#include "ProtossState.h"

#include "ZergCommand.h"
#include "ZergEvent.h"
#include "ZergState.h"

#include "Fitness.h"

void PrintUsage()
{
	cout << "Usage:" << endl << "\tSCBuildOrder [ZP] [(count) (target)]*" << endl;
}

/*

int main(int argc, char *argv[])
{
	stopEvolving = false;
	stagnationLimit = 1000;

	srand_sse(unsigned(time(0)));
	for(int i=0; i < 5; i++)
		rand_sse(); // Discard first 5

	if(argc < 4 || argc %2 != 0)
	{
		PrintUsage();
		return 0;
	}

	if(argv[1][0] == 'Z')
	{
		CZergState targetState;

		for(int i=2; i < argc; i++)
		{
			size_t count = atoi(argv[i++]);

			if(0 >= count || count > 500)
			{
				PrintUsage();
				return 0;
			}

			switch(argv[i][0])
			{
			case 'D':
				targetState.m_droneCount = count;
				break;
			case 'L':
				targetState.m_overlordCount = count;
				break;
			case 'Q':
				targetState.m_queenCount = count;
				break;
			case 'Z':
				targetState.m_zerglingCount = count;
				break;
			case 'R':
				targetState.m_roachCount = count;
				break;
			case 'H':
				targetState.m_hydraliskCount = count;
				break;
			case 'B':
				targetState.m_banelingCount = count;
				break;
			case 'S':
				targetState.m_overseerCount = count;
				break;
			case 'I':
				targetState.m_infestorCount = count;
				break;
			case 'M':
				targetState.m_mutaliskCount = count;
				break;
			case 'C':
				targetState.m_corruptorCount = count;
				break;
			case 'U':
				targetState.m_ultraliskCount = count;
				break;
			case 'O':
				targetState.m_broodlordCount = count;
				break;
			}
		}

		Execute<CZergState, EZergCommand, CZergEvent>(targetState);
	}
	else if(argv[1][0] == 'P')
	{
		CProtossState targetState;

		for(int i=2; i < argc; i++)
		{
			size_t count = atoi(argv[i++]);

			if(0 >= count || count > 500)
			{
				PrintUsage();
				return 0;
			}

			switch(argv[i][0])
			{
			case 'P':
				targetState.m_probeCount = count;
				break;
			case 'Z':
				targetState.m_zealotCount = count;
				break;
			case 'S':
				targetState.m_stalkerCount = count;
				break;
			case 'E':
				targetState.m_sentryCount = count;
				break;
			case 'T':
				targetState.m_highTemplarCount = count;
				break;
			case 'D':
				targetState.m_darkTemplarCount = count;
				break;
			case 'W':
				targetState.m_warpPrismCount = count;
				break;
			case 'O':
				targetState.m_observerCount = count;
				break;
			case 'I':
				targetState.m_immortalCount = count;
				break;
			case 'C':
				targetState.m_colossusCount = count;
				break;
			case 'H':
				targetState.m_phoenixCount = count;
				break;
			case 'V':
				targetState.m_voidRayCount = count;
				break;
			case 'A':
				targetState.m_carrierCount = count;
				break;
			case 'M':
				targetState.m_mothershipCount = count;
				break;
			}
		}

		Execute<CProtossState, EProtossCommand, CProtossEvent>(targetState);
	}

	return 0;
}

*/

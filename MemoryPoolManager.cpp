#include "stdafx.h"
#include "MemoryPoolManager.h"

CMemoryPoolManager::CMemoryPoolManager()
{
}

CMemoryPoolManager::~CMemoryPoolManager()
{
	for(CMemoryPoolMap::iterator iter = m_mapPools.begin(); iter != m_mapPools.end(); ++iter)
	{
		delete iter->second;
	}
}

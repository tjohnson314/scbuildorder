#pragma once

#include <map>
#include "MemoryPool.h"

using namespace std;

class CMemoryPoolManager
{
public:
	CMemoryPoolManager();
	~CMemoryPoolManager();

	void AddMemoryPool(size_t size, size_t nInitialCapacity = MEMORYPOOL_INITIALCAPACITY)
	{
		if(m_mapPools.find(size) == m_mapPools.end())
			m_mapPools[size] = new CMemoryPool(size, nInitialCapacity);
	}

	CMemoryPool *GetMemoryPool(size_t size) { return m_mapPools[size]; }

	CMemoryPool *GetMemoryPoolAddAsNeeded(size_t size, size_t nInitialCapacity = MEMORYPOOL_INITIALCAPACITY)
	{
		CMemoryPoolMap::iterator iter = m_mapPools.find(size);
		if(iter == m_mapPools.end())
		{
			CMemoryPool *pool = new CMemoryPool(size, nInitialCapacity);
			m_mapPools[size] = pool;
			return pool;
		}
		else
			return iter->second;
	}

protected:
	typedef map<size_t, CMemoryPool *> CMemoryPoolMap;
	CMemoryPoolMap m_mapPools;

};

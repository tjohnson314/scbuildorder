#pragma once

class CMemoryPool;

#include <vector>
#include <map>

using namespace std;

#define MEMORYPOOL_INITIALCAPACITY 1000

template <typename T, size_t nInitialCapacity = MEMORYPOOL_INITIALCAPACITY, size_t nGrowFactor = 2, size_t nGrowAdditional = 0.0>
class CMemPoolNode
{
public:
	void *operator new(size_t)
	{
		if(!m_pool)
			m_pool = new CMemoryPool(sizeof(T), nInitialCapacity, (float)nGrowFactor, (float)nGrowAdditional);
		return m_pool->Alloc();
	}

	void operator delete(void *p)
	{
		m_pool->Free(p);
	}

	void *operator new[](size_t size)
	{
		return m_pool->AllocArray(size);
	}

	void operator delete[](void *p)
	{
		m_pool->FreeArray(p);
	}

	static const CMemoryPool &GetMemoryPool() { return *m_pool; }

private:
	__declspec(thread) static CMemoryPool *m_pool;
};

template <typename T, size_t nInitialCapacity, size_t nGrowFactor, size_t nGrowAdditional> CMemoryPool *CMemPoolNode<T, nInitialCapacity, nGrowFactor, nGrowAdditional>::m_pool = 0;

class CMemoryPool
{
public:
	CMemoryPool(float fGrowFactor = 2.0, float fGrowAdditional = 0.0);
	CMemoryPool(size_t nSize, size_t nInitialCapacity = MEMORYPOOL_INITIALCAPACITY, float fGrowFactor = 2.0, float fGrowAdditional = 0.0);
	~CMemoryPool();

	void Initialise(size_t nSize, size_t nInitialCapacity = MEMORYPOOL_INITIALCAPACITY);

	inline void *Alloc();
	inline void Free(void *p);

	void *AllocArray(size_t size);
	void FreeArray(void *p);

	size_t GetSize() const { return m_nSize; }
	size_t GetStackCapacity() const { return m_nStackCapacity; }
	size_t GetAllocated() const { return m_nAllocatedCount; }
	size_t GetCurrentlyUsed() const { return m_nAllocatedCount - (m_pEndFree - m_parrFree); }

	static size_t GetUsedMemory() { return m_nUsedMemory; }

protected:
	class CArrayBlock
	{
	public:
		struct Less
		{
			bool operator()(const CArrayBlock* p1, const CArrayBlock* p2) const
			{
				return p1->size < p2->size;
			}
		};
		size_t size;
		bool bUsed;
	};

	void AddBlock(size_t nCapacity);
	void ExtendStack(size_t nCapacity);

	inline void AppendToFreeStack(void *p);

	size_t m_nSize;
	size_t m_nAllocatedCount;
	size_t m_nStackCapacity;
	size_t m_nLastBlockSize;
	size_t m_nLastStackIncrease;
	float m_fGrowFactor;
	float m_fGrowAdditional;

	void **m_parrFree;
	void **m_pEndFree;
	void **m_pEndStack;

	vector<char *> m_vecBlocks;
	typedef map<CArrayBlock *, CArrayBlock *, CArrayBlock::Less> ArrayBlockMap;
	ArrayBlockMap m_mapArrayBlocks;

	static size_t m_nUsedMemory;
};

void *CMemoryPool::Alloc()
{
	if(m_parrFree > m_pEndFree)
		AddBlock((size_t)(((float)m_nLastBlockSize) * m_fGrowFactor + m_fGrowAdditional));

	return (*(m_pEndFree--));
}

void CMemoryPool::Free(void *p)
{
	AppendToFreeStack(p);
}

void CMemoryPool::AppendToFreeStack(void *p)
{
	if(m_pEndFree == m_pEndStack)
		ExtendStack((size_t)(((float)m_nLastStackIncrease) * m_fGrowFactor + m_fGrowAdditional));

	(*(++m_pEndFree)) = p;
}


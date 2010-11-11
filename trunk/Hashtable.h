#pragma once

template <typename Key, typename KeyRef, typename Val, typename ValRef, typename Compare = Equal<KeyRef>>
class CHashtable;

#include "MemoryPool.h"
#include "LinkedList.h"

template <typename T>
unsigned long HashKey(T key)
{
	return (unsigned long)key;
}

template <typename T>
struct Equal
{
public:
	bool operator()(T a, T b) const
	{
		return a == b;
	}
};

size_t GetNextPrimeSize(size_t nDesiredSize);

template <typename Key, typename KeyRef, typename Val, typename ValRef>
class CHashtableNode : public CMemPoolNode<CHashtableNode<Key, KeyRef, Val, ValRef>, 100000, 1.0>
{
protected:
	CHashtableNode *m_pNextNode;

public:
	Key m_key;
	Val m_val;

	CHashtableNode(KeyRef key, ValRef val, CHashtableNode *pNextNode = NULL) : m_key(key), m_val(val), m_pNextNode(pNextNode) {}
	~CHashtableNode() {}

	CHashtableNode *GetNext() { return m_pNextNode; }
	const CHashtableNode *GetNext() const { return m_pNextNode; }
	void SetNext(CHashtableNode *pNode) { m_pNextNode = pNode; }

	void operator=(const CHashtableNode<Key, KeyRef, Val, ValRef> &node) { m_key = node.m_key; m_val = node.m_val; }

	operator KeyRef() { return m_key; }
};

template <typename Key, typename KeyRef, typename Val, typename ValRef, typename Compare>
class CHashtable : public CMemPoolNode<CHashtable<Key, KeyRef, Val, ValRef, Compare>, 10>
{
private:
	typedef CHashtableNode<Key, KeyRef, Val, ValRef> Node;

	Compare m_comp;
	float m_fGrowThreshold;
	float m_fGrowFactor;
	size_t m_nSize;
	size_t m_nCount;
	Node **m_arrHashtable;

	Node *FindKey(size_t nIndex, KeyRef key) const
	{
		Node *pNode = m_arrHashtable[nIndex];
		for(; pNode != NULL && !m_comp(*pNode, key); pNode = pNode->GetNext());
		return pNode;
	}

public:
	CHashtable(size_t nInitialSize = 1009, const Compare &comp = Compare(), float fGrowThreshold = CHRONOBOOST_GAIN, float fGrowFactor = 2.0);
	~CHashtable();

	void SetAt(KeyRef key, ValRef val);
	bool ContainsKey(KeyRef key) const;
	bool Lookup(KeyRef key, Val &val) const;
	const Node *GetIndex(size_t nIndex) const
	{
		if(nIndex >= m_nSize)
			return NULL;
		else
			return m_arrHashtable[nIndex];
	}

	void Grow();
	void Reallocate(size_t nSize);
	size_t Size() const { return m_nSize; }

	void GetStatistics(size_t &nSize, size_t &nCount, size_t &nUsed, size_t &nMaxCollision) const;
	size_t CalculateMemoryUsage() const { return m_nSize * sizeof(Node *); }
};

template <typename Key, typename KeyRef, typename Val, typename ValRef, typename Compare>
CHashtable<Key, KeyRef, Val, ValRef, Compare>::CHashtable(size_t nInitialSize /* = 1009 */, const Compare &comp /* = Compare() */, float fGrowThreshold /* = 0.5 */, float fGrowFactor /* = 2.0 */)
: m_nSize(0)
, m_nCount(0)
, m_comp(comp)
, m_fGrowThreshold(fGrowThreshold)
, m_fGrowFactor(fGrowFactor)
, m_arrHashtable(NULL)
{
	Reallocate(nInitialSize);
}

template <typename Key, typename KeyRef, typename Val, typename ValRef, typename Compare>
CHashtable<Key, KeyRef, Val, ValRef, Compare>::~CHashtable()
{
	for(size_t i=0; i < m_nSize; i++)
	{
		while(m_arrHashtable[i] != NULL)
		{
			Node *pNode = m_arrHashtable[i];
			m_arrHashtable[i] = pNode->GetNext();
			delete pNode;
		}
	}

	delete[] m_arrHashtable;
}

template <typename Key, typename KeyRef, typename Val, typename ValRef, typename Compare>
void CHashtable<Key, KeyRef, Val, ValRef, Compare>::Reallocate(size_t nSize)
{
	Node **arrHashtable = new Node *[nSize];
	for(size_t i=0; i < nSize; i++)
		arrHashtable[i] = NULL;

	for(size_t i=0; i < m_nSize; i++)
	{
		while(m_arrHashtable[i] != NULL)
		{
			Node *pNode = m_arrHashtable[i];
			m_arrHashtable[i] = pNode->GetNext();
			size_t nIndex = HashKey<Key>(pNode->m_key) % nSize;
			pNode->SetNext(arrHashtable[nIndex]);
			arrHashtable[nIndex] = pNode;
		}
	}

	delete[] m_arrHashtable;
	m_arrHashtable = arrHashtable;;
	m_nSize = nSize;
}

template <typename Key, typename KeyRef, typename Val, typename ValRef, typename Compare>
void CHashtable<Key, KeyRef, Val, ValRef, Compare>::Grow()
{
	Reallocate(GetNextPrimeSize((size_t)(m_fGrowFactor * m_nSize)));
}


template <typename Key, typename KeyRef, typename Val, typename ValRef, typename Compare>
void CHashtable<Key, KeyRef, Val, ValRef, Compare>::SetAt(KeyRef key, ValRef val)
{
	size_t nIndex = HashKey<KeyRef>(key) % m_nSize;
	Node *pNode = FindKey(nIndex, key);
	if(pNode)
		pNode->m_val = val;
	else
	{
		if((float)m_nCount / (float)m_nSize > m_fGrowThreshold)
			Grow();
		m_nCount++;
		m_arrHashtable[nIndex] = new Node(key, val, m_arrHashtable[nIndex]);
	}
}

template <typename Key, typename KeyRef, typename Val, typename ValRef, typename Compare>
bool CHashtable<Key, KeyRef, Val, ValRef, Compare>::ContainsKey(KeyRef key) const
{
	size_t nIndex = HashKey<KeyRef>(key) % m_nSize;
	return (NULL != FindKey(nIndex, key));
}

template <typename Key, typename KeyRef, typename Val, typename ValRef, typename Compare>
bool CHashtable<Key, KeyRef, Val, ValRef, Compare>::Lookup(KeyRef key, Val &val) const
{
	size_t nIndex = HashKey<KeyRef>(key) % m_nSize;
	Node *pNode = FindKey(nIndex, key);
	if(!pNode)
		return false;
	else
	{
		val = pNode->m_val;
		return true;
	}
}

template <typename Key, typename KeyRef, typename Val, typename ValRef, typename Compare>
void CHashtable<Key, KeyRef, Val, ValRef, Compare>::GetStatistics(size_t &nSize, size_t &nCount, size_t &nUsed, size_t &nMaxCollision) const
{
	nCount = m_nCount;
	nSize = m_nSize;
	
	nUsed = 0;
	nMaxCollision = 0;
	for(size_t i=0; i < m_nSize; i++)
	{
		if(m_arrHashtable[i])
		{
			size_t nMax = 0;
			Node *pNode = m_arrHashtable[i];
			while(pNode->GetNext())
			{
				nMax++;
				pNode = pNode->GetNext();
			}

			if(nMax > nMaxCollision)
				nMaxCollision = nMax;

			nUsed++;
		}
	}
}

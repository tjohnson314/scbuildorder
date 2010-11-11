#pragma once

#include "MemoryPool.h"
#include "MemoryPoolManager.h"

template<typename T>
class CVector : public CMemPoolNode<CVector<T>>
{
public:
	CVector() : m_size(0), m_capacity(0), m_data(0) {}
	CVector(const CVector<T> &vec);
	~CVector();

	size_t size() const { return m_size; }
	size_t capacity() const { return m_capacity; }

	void append(const CVector &vector) { append(vector.data(), vector.length()); }
	void append(const T *vals, size_t count);
	void push_back(const T &val);
	void insert(size_t index, const T &val);
	void erase(size_t index, size_t count = 1);
	void capacity(size_t capacity);
	void push(const T &val) { push_back(val); }
	T &pop() { return m_data[--m_size]; }

	const T &operator[](size_t index) const { return m_data[index]; }
	T &operator[](size_t index) { return m_data[index]; }
	const T *data() const { return m_data; }

	bool operator==(const CVector<T> &vector) const;
	bool operator <(const CVector<T> &vector) const;

	void operator =(const CVector<T> &vector);

protected:
	size_t m_size;
	size_t m_capacity;
	T *m_data;
	__declspec(thread) static CMemoryPoolManager *m_memoryPoolManager;
};

template<typename T>
CMemoryPoolManager *CVector<T>::m_memoryPoolManager = 0;

template<typename T>
CVector<T>::CVector(const CVector<T> &vector)
: m_size(0), m_capacity(0), m_data(0)
{
	capacity(vector.size());
	T *data = m_data;
	const T *vecData = vector.data();
	for(size_t index = 0; index < vector.size(); index++)
		*(data++) = *(vecData++);
	m_size = vector.size();
}

template<typename T>
CVector<T>::~CVector()
{
	if(m_data)
		m_memoryPoolManager->GetMemoryPool(m_capacity * sizeof(T))->Free(m_data);
}

template<typename T>
void CVector<T>::append(const T *vals, size_t count)
{
	capacity(m_size + count);
	T *data = &m_data[m_size];
	for(size_t index = 0; index < count; index++)
		*(data++) = *(vals++);
	m_size += count;
}

template<typename T>
void CVector<T>::push_back(const T &val)
{
	capacity(m_size + 1);
	m_data[m_size++] = val;
}

template<typename T>
void CVector<T>::insert(size_t index, const T &val)
{
	capacity(m_size + 1);
	memmove(&m_data[index + 1], &m_data[index], (m_size - index) * sizeof(T));
	m_data[index] = val;
	m_size++;
}

template<typename T>
void CVector<T>::erase(size_t index, size_t count /* = 1 */)
{
	memmove(&m_data[index], &m_data[index + count], (m_size - count - index) * sizeof(T));
	m_size -= count;
}

template<typename T>
void CVector<T>::capacity(size_t capacity)
{
	if(m_capacity > capacity)
		return;

	size_t newCapacity = m_capacity > 0 ? m_capacity : 16;
	while(newCapacity < capacity + 1)
		newCapacity <<= 1;

	if(!m_memoryPoolManager)
		m_memoryPoolManager = new CMemoryPoolManager();

	T *newData = (T *)m_memoryPoolManager->GetMemoryPoolAddAsNeeded(newCapacity * sizeof(T))->Alloc();
	if(m_data)
	{
		memcpy(newData, m_data, m_capacity * sizeof(T));
		m_memoryPoolManager->GetMemoryPool(m_capacity * sizeof(T))->Free(m_data);
	}

	// Initialise values
	T *init = &newData[m_capacity];
	for(size_t index = m_capacity; index < newCapacity; index++)
		new (init++) T();

	m_data = newData;
	m_capacity = newCapacity;
}

template<typename T>
bool CVector<T>::operator==(const CVector<T> &vector) const
{
	if(m_size != vector.size())
		return false;

	const T *data = m_data;
	const T *vecData = vector.data();
	for(size_t index=0; index < m_size; index++, data++, vecData++)
	{
		if(*data != *vecData)
			return false;
	}

	return true;
}

template<typename T>
bool CVector<T>::operator<(const CVector<T> &vector) const
{
	const T *data = m_data;
	const T *vecData = vector.data();
	for(size_t index=0; index < m_size && index < vector.size(); index++, data++, vecData++)
	{
		if(*data < *vecData)
			return true;
		else if(*vecData < *data)
			return false;
	}

	return m_size < vector.size();
}

template<typename T>
void CVector<T>::operator=(const CVector<T> &vector)
{
	capacity(vector.size());
	T *data = m_data;
	const T *vecData = vector.data();
	for(size_t index = 0; index < vector.size(); index++)
		*(data++) = *(vecData++);
	m_size = vector.size();
}

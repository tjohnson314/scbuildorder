#pragma once

class CFitnessValue
{
public:
	inline CFitnessValue();
	inline CFitnessValue(const CFitnessValue &value);

	inline void operator =(const CFitnessValue &value);
	inline bool operator <(const CFitnessValue &value) const;
	inline bool operator==(const CFitnessValue &value) const;
	operator double() const { return (m_targetValue + 0.01 * m_extraValue) / (m_targetValueTime > 0 ? m_targetValueTime : 1); }

	double m_targetValue;
	double m_targetValueTime;
	double m_extraValue;
	double m_extraValueTime;
};

CFitnessValue::CFitnessValue()
	: m_targetValue(0), m_targetValueTime(0), m_extraValue(0), m_extraValueTime(0)
{
}

CFitnessValue::CFitnessValue(const CFitnessValue &value)
{
	m_targetValue = value.m_targetValue;
	m_targetValueTime = value.m_targetValueTime;
	m_extraValue = value.m_extraValue;
	m_extraValueTime = value.m_extraValueTime;
}

void CFitnessValue::operator =(const CFitnessValue &value)
{
	m_targetValue = value.m_targetValue;
	m_targetValueTime = value.m_targetValueTime;
	m_extraValue = value.m_extraValue;
	m_extraValueTime = value.m_extraValueTime;
}

bool CFitnessValue::operator <(const CFitnessValue &value) const
{
	if(m_targetValue < value.m_targetValue)
		return true;
	else if(m_targetValue != value.m_targetValue)
		return false;

	if(m_targetValueTime > value.m_targetValueTime)
		return true;
	else if(m_targetValueTime != value.m_targetValueTime)
		return false;

	if(m_extraValue < value.m_extraValue)
		return true;
	else if(m_extraValue != value.m_extraValue)
		return false;

	return m_extraValueTime > value.m_extraValueTime;
}

bool CFitnessValue::operator==(const CFitnessValue &value) const
{
	return m_targetValue == value.m_targetValue
		&& m_targetValueTime == value.m_targetValueTime
		&& m_extraValue == value.m_extraValue
		&& m_extraValueTime == value.m_extraValueTime;
}

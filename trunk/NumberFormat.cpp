#include "stdafx.h"
#include "NumberFormat.h"

CNumberFormat::CNumberFormat()
{
	m_format.NumDigits = 0;
	m_format.LeadingZero = 0;
	m_format.lpDecimalSep = NULL;
	m_format.lpThousandSep = NULL;
	m_format.NegativeOrder = 0;
	m_format.Grouping = 0;
}

CNumberFormat::~CNumberFormat()
{
	delete m_format.lpDecimalSep;
	delete m_format.lpThousandSep;
}

bool CNumberFormat::LoadDefault(LCID locale /* = LOCALE_USER_DEFAULT */)
{
    CString strBuffer;
    bool result = true;
	int bufferSize;

	bufferSize = GetLocaleInfo(locale, LOCALE_IDIGITS, NULL, 0);
    if(0 != bufferSize)
	{
		if(GetLocaleInfo(locale, LOCALE_IDIGITS, strBuffer.GetBuffer(bufferSize), bufferSize))
		    m_format.NumDigits = wcstoul(strBuffer, NULL, 0);
		else
			result = false;
		strBuffer.ReleaseBuffer();
	}

	bufferSize = GetLocaleInfo(locale, LOCALE_ILZERO, NULL, 0);
	if(0 != bufferSize)
	{
		if(GetLocaleInfo(locale, LOCALE_ILZERO, strBuffer.GetBuffer(bufferSize), bufferSize))
		    m_format.LeadingZero = wcstoul(strBuffer, NULL, 0);
		else
			result = false;
		strBuffer.ReleaseBuffer();
	}

	bufferSize = GetLocaleInfo(locale, LOCALE_SDECIMAL, NULL, 0);
	if(0 != bufferSize)
	{
		delete m_format.lpDecimalSep;
	    m_format.lpDecimalSep = new WCHAR[bufferSize];
	    if(!GetLocaleInfo(locale, LOCALE_SDECIMAL, m_format.lpDecimalSep, bufferSize))
		{
			result = false;
			delete m_format.lpDecimalSep;
			m_format.lpDecimalSep = 0;
		}
	}

	bufferSize = GetLocaleInfo(locale, LOCALE_STHOUSAND, NULL, 0);
	if(0 != bufferSize)
	{
		delete m_format.lpThousandSep;
	    m_format.lpThousandSep = new WCHAR[bufferSize];
	    if(!GetLocaleInfo(locale, LOCALE_STHOUSAND, m_format.lpThousandSep, bufferSize))
		{
			result = false;
			delete m_format.lpThousandSep;
			m_format.lpDecimalSep = 0;
		}
	}

	bufferSize = GetLocaleInfo(locale, LOCALE_INEGNUMBER, NULL, 0);
	if(0 != bufferSize)
	{
		if(GetLocaleInfo(locale, LOCALE_INEGNUMBER, strBuffer.GetBuffer(bufferSize), bufferSize))
		    m_format.NegativeOrder = wcstoul(strBuffer, NULL, 0);
		else
			result = false;
		strBuffer.ReleaseBuffer();
	}

	bufferSize = GetLocaleInfo(locale, LOCALE_SGROUPING, NULL, 0);
	if(0 != bufferSize)
	{
		if(GetLocaleInfo(locale, LOCALE_SGROUPING, strBuffer.GetBuffer(bufferSize), bufferSize))
		{
			m_format.Grouping = 0;
		    for(const WCHAR *c = strBuffer; *c; c++)
			{
		        if(*c >= L'1' && *c <= L'9')
		            m_format.Grouping = m_format.Grouping * 10 + (*c - L'0');
			    if(*c != L'0' && !c[1])
					m_format.Grouping *= 10;
		    }
		}
		else
			result = false;
		strBuffer.ReleaseBuffer();
	}

    return result;
}

int CNumberFormat::FormatNumberByLocale(LPCTSTR pszNumber, CString &strFormatted, LCID locale /* = LOCALE_USER_DEFAULT */)
{
   int nSize = ::GetNumberFormat(locale, 0, pszNumber, &m_format, NULL, 0);
   nSize = ::GetNumberFormat(locale, 0, pszNumber, &m_format, strFormatted.GetBuffer(nSize), nSize);
   strFormatted.ReleaseBuffer();
   return nSize;
}

int CNumberFormat::FormatNumberByLocale(double dNumber, CString &strFormatted, LCID locale /* = LOCALE_USER_DEFAULT */)
{
   CString strNumber;
   strNumber.Format(_T("%.2f"), dNumber);
   return FormatNumberByLocale(strNumber, strFormatted, locale);
}

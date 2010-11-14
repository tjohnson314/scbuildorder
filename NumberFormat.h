#pragma once

class CNumberFormat
{
public:
	CNumberFormat();
	~CNumberFormat();

	bool LoadDefault(LCID locale = LOCALE_USER_DEFAULT);
	int FormatNumberByLocale(LPCTSTR pszNumber, CString &strFormatted, LCID locale = LOCALE_USER_DEFAULT);
	int FormatNumberByLocale(double dNumber, CString &strFormatted, LCID locale = LOCALE_USER_DEFAULT);

	void SetNumDigits(UINT numDigits) { m_format.NumDigits = numDigits; }

protected:
	NUMBERFMTW m_format;
};

#pragma once

class CNumberFormat
{
public:
	CNumberFormat();
	~CNumberFormat();

	bool LoadDefault(LPCWSTR lpLocaleName = LOCALE_NAME_USER_DEFAULT);
	int FormatNumberByLocale(LPCTSTR pszNumber, CString &strFormatted, LPCWSTR lpLocaleName = LOCALE_NAME_USER_DEFAULT);
	int FormatNumberByLocale(double dNumber, CString &strFormatted, LPCWSTR lpLocaleName = LOCALE_NAME_USER_DEFAULT);

	void SetNumDigits(UINT numDigits) { m_format.NumDigits = numDigits; }

protected:
	NUMBERFMTW m_format;
};

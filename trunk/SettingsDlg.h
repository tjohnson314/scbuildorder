#pragma once


// CSettingsDlg dialog

class CSettingsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSettingsDlg)

public:
	CSettingsDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSettingsDlg();

// Dialog Data
	enum { IDD = IDD_DLG_SETTINGS };

	double GetTimeLimit() const { return m_timeLimit; }
	double GetMutationRate() const { return m_mutationRate; }

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

	double m_timeLimit;
	double m_mutationRate;
};

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

	BOOL GetScoutingWorker() const { return m_scoutingWorker; }
	double GetScoutingWorkerTime() const { return m_scoutingWorkerTime; }
	BOOL GetScoutingWorkerDies() const { return m_scoutingWorkerDies; }
	BOOL GetScoutingWorkerReturns() const { return m_scoutingWorkerReturns; }
	double GetScoutingWorkerEndTime() const { return m_scoutingWorkerEndTime; }

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	void EnableScoutingWorkerControls();

	DECLARE_MESSAGE_MAP()

	double m_timeLimit;
	double m_mutationRate;

	BOOL m_scoutingWorker;
	double m_scoutingWorkerTime;
	BOOL m_scoutingWorkerDies;
	BOOL m_scoutingWorkerReturns;
	double m_scoutingWorkerEndTime;

public:
	afx_msg void OnBnClickedCheckScoutingworker();
	afx_msg void OnBnClickedCheckScoutingworkerdies();
	afx_msg void OnBnClickedCheckScoutingworkerreturns();
	afx_msg void OnEnKillFocusScoutingworkerend();
	afx_msg void OnEnKillFocusScoutingworkertime();
};

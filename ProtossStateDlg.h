#pragma once

#include "ProtossState.h"

// CProtossStateDlg dialog

class CProtossStateDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CProtossStateDlg)

public:
	CProtossStateDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CProtossStateDlg();

// Dialog Data
	enum { IDD = IDD_DLG_PROTOSSSTATE };

	const CProtossState &GetState() { UpdateData(TRUE); return m_protossState; }
	void SetWaypointTargetTime(double time) { m_waypointTargetTime = time; }
	double GetWaypointTargetTime() { UpdateData(TRUE); return m_waypointTargetTime; }

protected:
	void DDX_Check(CDataExchange* pDX, int nIDC, bool &bValue);
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

	CProtossState m_protossState;
	double m_waypointTargetTime;
};

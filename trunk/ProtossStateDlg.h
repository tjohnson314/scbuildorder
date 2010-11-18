#pragma once

#include "ProtossTarget.h"

// CProtossStateDlg dialog

class CProtossStateDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CProtossStateDlg)

public:
	CProtossStateDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CProtossStateDlg();

// Dialog Data
	enum { IDD = IDD_DLG_PROTOSSSTATE };

	const CProtossTarget &GetTarget() { UpdateData(TRUE); return m_protossTarget; }
	void SetWaypointTargetTime(double time) { m_waypointTargetTime = time; }
	double GetWaypointTargetTime() { UpdateData(TRUE); return m_waypointTargetTime; }

protected:
	void DDX_Check(CDataExchange* pDX, int nIDC, bool &bValue);
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

	CProtossTarget m_protossTarget;
	double m_waypointTargetTime;
};

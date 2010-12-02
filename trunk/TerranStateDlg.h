#pragma once

#include "TerranTarget.h"

// CTerranStateDlg dialog

class CTerranStateDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTerranStateDlg)

public:
	CTerranStateDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTerranStateDlg();

// Dialog Data
	enum { IDD = IDD_DLG_TERRANSTATE };

	const CTerranTarget &GetTarget() { UpdateData(TRUE); return m_terranTarget; }
	void SetWaypointTargetTime(double time) { m_waypointTargetTime = time; }
	double GetWaypointTargetTime() { UpdateData(TRUE); return m_waypointTargetTime; }

protected:
	void DDX_Check(CDataExchange* pDX, int nIDC, bool &bValue);
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

	CTerranTarget m_terranTarget;
	double m_waypointTargetTime;
};

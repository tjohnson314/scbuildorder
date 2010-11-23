#pragma once

#include "ZergTarget.h"

// CZergStateDlg dialog

class CZergStateDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CZergStateDlg)

public:
	CZergStateDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CZergStateDlg();

// Dialog Data
	enum { IDD = IDD_DLG_ZERGSTATE };

	const CZergTarget &GetTarget() { UpdateData(TRUE); return m_zergTarget; }
	void SetWaypointTargetTime(double time) { m_waypointTargetTime = time; }
	double GetWaypointTargetTime() { UpdateData(TRUE); return m_waypointTargetTime; }

protected:
	void DDX_Check(CDataExchange* pDX, int nIDC, bool &bValue);
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

	CZergTarget m_zergTarget;
	double m_waypointTargetTime;
};

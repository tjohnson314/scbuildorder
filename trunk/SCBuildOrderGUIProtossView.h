// SCBuildOrderGUIView.h : interface of the CSCBuildOrderGUIProtossView class
//

#pragma once

#include <vector>

#include "SCBuildOrderGUIView.h"
#include "SCBuildOrderGUIDoc.h"
#include "ProtossTarget.h"
#include "ProtossStateDlg.h"
#include "SettingsDlg.h"

#include "NumberFormat.h"

class CSCBuildOrderGUIProtossView : public CSCBuildOrderGUIView
{
protected: // create from serialization only
	CSCBuildOrderGUIProtossView();
	DECLARE_DYNCREATE(CSCBuildOrderGUIProtossView)

// Attributes
public:
	CSCBuildOrderGUIDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
public:
	virtual ~CSCBuildOrderGUIProtossView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

protected:
	CProtossEngine *m_protossEngine;

	virtual bool StartEngine();
	virtual void StopEngine();

	CVector<EProtossCommand> m_bestBuildOrder;
	CVector<CProtossStateDlg *> m_waypointDlgs;

	virtual void AddTargetDlg();
	virtual void SetTargetDlgPositions(const CRect &rect);

	virtual const CEngine *GetEngine() const { return m_protossEngine; }
	virtual bool UpdateBestBuildOrder();
	virtual void PrintBestGame(EOutputFormat format, CString &text) const;
	virtual CDialog *GetTargetDlg(int index) { return m_waypointDlgs[index]; }
};

#ifndef _DEBUG  // debug version in SCBuildOrderGUIViewView.cpp
inline CSCBuildOrderGUIDoc* CSCBuildOrderGUIProtossView::GetDocument() const
   { return reinterpret_cast<CSCBuildOrderGUIDoc*>(m_pDocument); }
#endif


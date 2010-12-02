// SCBuildOrderGUIView.h : interface of the CSCBuildOrderGUITerranView class
//

#pragma once

#include <vector>

#include "SCBuildOrderGUIView.h"
#include "SCBuildOrderGUIDoc.h"
#include "TerranTarget.h"
#include "TerranStateDlg.h"
#include "SettingsDlg.h"

#include "NumberFormat.h"

class CSCBuildOrderGUITerranView : public CSCBuildOrderGUIView
{
protected: // create from serialization only
	CSCBuildOrderGUITerranView();
	DECLARE_DYNCREATE(CSCBuildOrderGUITerranView)

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
	virtual ~CSCBuildOrderGUITerranView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

protected:
	CTerranEngine *m_terranEngine;

	virtual void StartEngine();
	virtual void StopEngine();

	CVector<ETerranCommand> m_bestBuildOrder;
	CVector<CTerranStateDlg *> m_waypointDlgs;

	virtual void AddTargetDlg();
	virtual void SetTargetDlgPositions(const CRect &rect);

	virtual const CEngine *GetEngine() const { return m_terranEngine; }
	virtual bool UpdateBestBuildOrder();
	virtual CDialog *GetTargetDlg(int index) { return m_waypointDlgs[index]; }
};

#ifndef _DEBUG  // debug version in SCBuildOrderGUIViewView.cpp
inline CSCBuildOrderGUIDoc* CSCBuildOrderGUITerranView::GetDocument() const
   { return reinterpret_cast<CSCBuildOrderGUIDoc*>(m_pDocument); }
#endif


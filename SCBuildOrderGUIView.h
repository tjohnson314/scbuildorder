// SCBuildOrderGUIView.h : interface of the CSCBuildOrderGUIView class
//

#pragma once

#include "SCBuildOrderGUIDoc.h"
#include "ProtossState.h"
#include "ZergState.h"

class CSCBuildOrderGUIView : public CFormView
{
protected: // create from serialization only
	CSCBuildOrderGUIView();
	DECLARE_DYNCREATE(CSCBuildOrderGUIView)

// Attributes
public:
	enum { IDD = IDD_PROTOSS_FORMVIEW };
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
	virtual ~CSCBuildOrderGUIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnTimer(UINT TimerVal);
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonStart();

protected:
	CProtossState m_protossState;

	CProtossEngine *m_protossEngine;
	CZergEngine *m_zergEngine;

	bool m_bStarted;
	UINT m_updateTimer;
	DWORD m_startTickCount;
	double m_timeLimit;
};

#ifndef _DEBUG  // debug version in SCBuildOrderGUIViewView.cpp
inline CSCBuildOrderGUIDoc* CSCBuildOrderGUIView::GetDocument() const
   { return reinterpret_cast<CSCBuildOrderGUIDoc*>(m_pDocument); }
#endif


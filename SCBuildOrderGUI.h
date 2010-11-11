
// SCBuildOrderGUI.h : main header file for the SCBuildOrderGUI application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CSCBuildOrderGUIApp:
// See SCBuildOrderGUI.cpp for the implementation of this class
//

class CSCBuildOrderGUIApp : public CWinAppEx
{
public:
	CSCBuildOrderGUIApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSCBuildOrderGUIApp theApp;

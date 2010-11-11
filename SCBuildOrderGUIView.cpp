
// SCBuildOrderGUIView.cpp : implementation of the CSCBuildOrderGUIView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "SCBuildOrderGUI.h"
#endif

#include "SCBuildOrderGUIDoc.h"
#include "SCBuildOrderGUIView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define IDT_TIMER_0		0

// CSCBuildOrderGUIView

IMPLEMENT_DYNCREATE(CSCBuildOrderGUIView, CFormView)

BEGIN_MESSAGE_MAP(CSCBuildOrderGUIView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_STARTSTOP, &CSCBuildOrderGUIView::OnBnClickedButtonStart)
END_MESSAGE_MAP()



// CSCBuildOrderGUIView construction/destruction

CSCBuildOrderGUIView::CSCBuildOrderGUIView()
	: CFormView(CSCBuildOrderGUIView::IDD)
	, m_updateTimer(0), m_bStarted(false), m_startTickCount(0), m_timeLimit(1200)
{
	// TODO: add construction code here

}

CSCBuildOrderGUIView::~CSCBuildOrderGUIView()
{
}

void CSCBuildOrderGUIView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TIMELIMIT, m_timeLimit);
	DDX_Text(pDX, IDC_EDIT_PROBECOUNT, m_protossState.m_probeCount);
	DDX_Text(pDX, IDC_EDIT_ZEALOTCOUNT, m_protossState.m_zealotCount);
	DDX_Text(pDX, IDC_EDIT_STALKERCOUNT, m_protossState.m_stalkerCount);
	DDX_Text(pDX, IDC_EDIT_SENTRYCOUNT, m_protossState.m_sentryCount);
	DDX_Text(pDX, IDC_EDIT_HIGHTEMPLARCOUNT, m_protossState.m_highTemplarCount);
	DDX_Text(pDX, IDC_EDIT_DARKTEMPLARCOUNT, m_protossState.m_darkTemplarCount);
	DDX_Text(pDX, IDC_EDIT_WARPPRISMCOUNT, m_protossState.m_warpPrismCount);
	DDX_Text(pDX, IDC_EDIT_OBSERVERCOUNT, m_protossState.m_observerCount);
	DDX_Text(pDX, IDC_EDIT_IMMORTALCOUNT, m_protossState.m_immortalCount);
	DDX_Text(pDX, IDC_EDIT_COLOSSUSCOUNT, m_protossState.m_colossusCount);
	DDX_Text(pDX, IDC_EDIT_PHOENIXCOUNT, m_protossState.m_phoenixCount);
	DDX_Text(pDX, IDC_EDIT_VOIDRAYCOUNT, m_protossState.m_voidRayCount);
	DDX_Text(pDX, IDC_EDIT_CARRIERCOUNT, m_protossState.m_carrierCount);
	DDX_Text(pDX, IDC_EDIT_MOTHERSHIPCOUNT, m_protossState.m_mothershipCount);
}

BOOL CSCBuildOrderGUIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

// CSCBuildOrderGUIView drawing

void CSCBuildOrderGUIView::OnDraw(CDC* /*pDC*/)
{
	CSCBuildOrderGUIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}

void CSCBuildOrderGUIView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	//UpdateData(FALSE);
}

void CSCBuildOrderGUIView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSCBuildOrderGUIView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSCBuildOrderGUIView diagnostics

#ifdef _DEBUG
void CSCBuildOrderGUIView::AssertValid() const
{
	CFormView::AssertValid();
}

void CSCBuildOrderGUIView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CSCBuildOrderGUIDoc* CSCBuildOrderGUIView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSCBuildOrderGUIDoc)));
	return (CSCBuildOrderGUIDoc*)m_pDocument;
}
#endif //_DEBUG


// CSCBuildOrderGUIView message handlers



void CSCBuildOrderGUIView::OnBnClickedButtonStart()
{
	if(!m_bStarted)
	{
		m_bStarted = true;
		GetDlgItem(IDC_BUTTON_STARTSTOP)->SetWindowTextW(L"Stop");

		UpdateData(TRUE);

		m_protossEngine = new CProtossEngine();
		m_protossEngine->SetTarget(m_protossState, m_timeLimit);
		m_protossEngine->AddVillage(200, 100);
		m_protossEngine->AddVillage(200, 100);
		m_protossEngine->AddVillage(200, 100);
		m_protossEngine->AddVillage(200, 100);
		m_protossEngine->AddVillage(200, 100);

		m_protossEngine->Start();
		m_startTickCount = GetTickCount();
		m_updateTimer = SetTimer(IDT_TIMER_0, 1000, 0);
	}
	else
	{
		KillTimer(m_updateTimer);

		m_protossEngine->Stop();
		delete m_protossEngine;
		m_protossEngine = 0;

		m_bStarted = false;
		GetDlgItem(IDC_BUTTON_STARTSTOP)->SetWindowTextW(L"Start");
	}
}

void CSCBuildOrderGUIView::OnTimer(UINT TimerVal)
{
	if(m_protossEngine)
	{
		CString strText;
		strText.Format(L"%u", m_protossEngine->Evolution());
		GetDlgItem(IDC_EDIT_EVOLUTION)->SetWindowTextW(strText);
		strText.Format(L"%llu", m_protossEngine->GameCount());
		GetDlgItem(IDC_EDIT_GAMECOUNT)->SetWindowTextW(strText);
		DWORD timeDiff = GetTickCount() - m_startTickCount;
		if(0 != timeDiff)
		{
			strText.Format(L"%llu", (1000 * m_protossEngine->GameCount()) / timeDiff);
			GetDlgItem(IDC_EDIT_GAMERATE)->SetWindowTextW(strText);
		}

		m_protossEngine->PrintBestGame(strText);
		GetDlgItem(IDC_EDIT_OUTPUT)->SetWindowTextW(strText);
	}
}


// SCBuildOrderGUIView.cpp : implementation of the CSCBuildOrderGUIView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "SCBuildOrderGUI.h"
#endif

#include "SCBuildOrderGUIDoc.h"
#include "SCBuildOrderGUIZergView.h"

#include "SettingsDlg.h"
#include "ZergStateDlg.h"

#include "NumberFormat.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSCBuildOrderGUIView

IMPLEMENT_DYNCREATE(CSCBuildOrderGUIZergView, CSCBuildOrderGUIView)

BEGIN_MESSAGE_MAP(CSCBuildOrderGUIZergView, CSCBuildOrderGUIView)
END_MESSAGE_MAP()



// CSCBuildOrderGUIView construction/destruction

CSCBuildOrderGUIZergView::CSCBuildOrderGUIZergView()
	: CSCBuildOrderGUIView(), m_zergEngine(NULL)
{
}

CSCBuildOrderGUIZergView::~CSCBuildOrderGUIZergView()
{
	StopEngine();
	delete m_zergEngine;

	while(m_waypointDlgs.size() > 0)
		delete m_waypointDlgs.pop();
}

void CSCBuildOrderGUIZergView::DoDataExchange(CDataExchange* pDX)
{
	CSCBuildOrderGUIView::DoDataExchange(pDX);
}

BOOL CSCBuildOrderGUIZergView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CSCBuildOrderGUIView::PreCreateWindow(cs);
}

// CSCBuildOrderGUIZergView drawing

void CSCBuildOrderGUIZergView::OnDraw(CDC* /*pDC*/)
{
	CSCBuildOrderGUIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}

void CSCBuildOrderGUIZergView::AddTargetDlg()
{
	CZergStateDlg *pDlg = new CZergStateDlg();
	pDlg->SetWaypointTargetTime((m_waypointDlgs.size() + 1) * 300);
	pDlg->Create(IDD_DLG_ZERGSTATE, this);
	m_waypointDlgs.push_back(pDlg);
}

void CSCBuildOrderGUIZergView::OnInitialUpdate()
{
	CSCBuildOrderGUIView::OnInitialUpdate();
}

// CSCBuildOrderGUIView diagnostics

#ifdef _DEBUG
void CSCBuildOrderGUIZergView::AssertValid() const
{
	CSCBuildOrderGUIView::AssertValid();
}

void CSCBuildOrderGUIZergView::Dump(CDumpContext& dc) const
{
	CSCBuildOrderGUIView::Dump(dc);
}

CSCBuildOrderGUIDoc* CSCBuildOrderGUIZergView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSCBuildOrderGUIDoc)));
	return (CSCBuildOrderGUIDoc*)m_pDocument;
}
#endif //_DEBUG

// CSCBuildOrderGUIZergView message handlers
bool CSCBuildOrderGUIZergView::StartEngine()
{
	m_settingsDlg->UpdateData(TRUE);

	delete m_zergEngine;
	m_zergEngine = new CZergEngine(m_settingsDlg->GetTimeLimit());
	bool waypointAdded = false;
	for(size_t i=0; i < m_waypointDlgs.size(); i++)
	{
		if(m_waypointDlgs[i]->GetTarget().hasTarget())
		{
			waypointAdded = true;
			m_zergEngine->AddWaypoint(m_waypointDlgs[i]->GetTarget(), m_waypointDlgs[i]->GetWaypointTargetTime());
		}
	}
	if(!waypointAdded)
	{
		delete m_zergEngine;
		m_zergEngine = 0;
		MessageBox(L"No waypoints to be added.  Please enter target details.");
		return false;
	}

	InitEngine(m_zergEngine);

	m_zergEngine->AddSeed(m_bestBuildOrder);
	m_bestBuildOrder = CVector<EZergCommand>();

	if(m_settingsDlg->GetScoutingWorker())
	{
		m_zergEngine->AddCustomEvent(CZergEvent(CZergEvent::eSendScout, m_settingsDlg->GetScoutingWorkerTime()));
		if(m_settingsDlg->GetScoutingWorkerDies())
			m_zergEngine->AddCustomEvent(CZergEvent(CZergEvent::eKillScout, m_settingsDlg->GetScoutingWorkerEndTime()));
		else if(m_settingsDlg->GetScoutingWorkerReturns())
			m_zergEngine->AddCustomEvent(CZergEvent(CZergEvent::eReturnScout, m_settingsDlg->GetScoutingWorkerEndTime()));
	}

	m_zergEngine->Start();

	return CSCBuildOrderGUIView::StartEngine();
}

void CSCBuildOrderGUIZergView::StopEngine()
{
	CSCBuildOrderGUIView::StopEngine();

	if(m_zergEngine)
		m_zergEngine->Stop();
}

bool CSCBuildOrderGUIZergView::UpdateBestBuildOrder()
{
	CVector<EZergCommand> buildOrder;
	m_zergEngine->GetBestGame(buildOrder);
	if(buildOrder != m_bestBuildOrder)
	{
		m_bestBuildOrder = buildOrder;
		return true;
	}

	return false;
}

void CSCBuildOrderGUIZergView::PrintBestGame(EOutputFormat format, CString &text) const
{
	if(!m_zergEngine)
		return;

	m_zergEngine->PrintGame(format, m_bestBuildOrder, text);
}

void CSCBuildOrderGUIZergView::SetTargetDlgPositions(const CRect &rect)
{
	for(int nCount=0; nCount < 5; nCount++)
		m_waypointDlgs[nCount]->SetWindowPos(&wndTop, rect.left, rect.top, rect.Width(), rect.Height(), SWP_HIDEWINDOW);
}

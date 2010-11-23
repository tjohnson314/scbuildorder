
// SCBuildOrderGUIView.cpp : implementation of the CSCBuildOrderGUIView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "SCBuildOrderGUI.h"
#endif

#include "SCBuildOrderGUIDoc.h"
#include "SCBuildOrderGUIProtossView.h"

#include "SettingsDlg.h"
#include "ProtossStateDlg.h"

#include "NumberFormat.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSCBuildOrderGUIView

IMPLEMENT_DYNCREATE(CSCBuildOrderGUIProtossView, CSCBuildOrderGUIView)

BEGIN_MESSAGE_MAP(CSCBuildOrderGUIProtossView, CSCBuildOrderGUIView)
END_MESSAGE_MAP()



// CSCBuildOrderGUIView construction/destruction

CSCBuildOrderGUIProtossView::CSCBuildOrderGUIProtossView()
	: CSCBuildOrderGUIView(), m_protossEngine(NULL)
{
}

CSCBuildOrderGUIProtossView::~CSCBuildOrderGUIProtossView()
{
	StopEngine();

	while(m_waypointDlgs.size() > 0)
		delete m_waypointDlgs.pop();
}

void CSCBuildOrderGUIProtossView::DoDataExchange(CDataExchange* pDX)
{
	CSCBuildOrderGUIView::DoDataExchange(pDX);
}

BOOL CSCBuildOrderGUIProtossView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CSCBuildOrderGUIView::PreCreateWindow(cs);
}

// CSCBuildOrderGUIProtossView drawing

void CSCBuildOrderGUIProtossView::OnDraw(CDC* /*pDC*/)
{
	CSCBuildOrderGUIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}

void CSCBuildOrderGUIProtossView::AddTargetDlg()
{
	CProtossStateDlg *pDlg = new CProtossStateDlg();
	pDlg->SetWaypointTargetTime((m_waypointDlgs.size() + 1) * 300);
	pDlg->Create(IDD_DLG_PROTOSSSTATE, this);
	m_waypointDlgs.push_back(pDlg);
}

void CSCBuildOrderGUIProtossView::OnInitialUpdate()
{
	CSCBuildOrderGUIView::OnInitialUpdate();
}

// CSCBuildOrderGUIView diagnostics

#ifdef _DEBUG
void CSCBuildOrderGUIProtossView::AssertValid() const
{
	CSCBuildOrderGUIView::AssertValid();
}

void CSCBuildOrderGUIProtossView::Dump(CDumpContext& dc) const
{
	CSCBuildOrderGUIView::Dump(dc);
}

CSCBuildOrderGUIDoc* CSCBuildOrderGUIProtossView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSCBuildOrderGUIDoc)));
	return (CSCBuildOrderGUIDoc*)m_pDocument;
}
#endif //_DEBUG

// CSCBuildOrderGUIProtossView message handlers
void CSCBuildOrderGUIProtossView::StartEngine()
{
	CSCBuildOrderGUIView::StartEngine();

	m_protossEngine = new CProtossEngine(m_settingsDlg->GetTimeLimit());
	bool waypointAdded = false;
	for(size_t i=0; i < m_waypointDlgs.size(); i++)
	{
		if(m_waypointDlgs[i]->GetTarget().hasTarget())
		{
			waypointAdded = true;
			m_protossEngine->AddWaypoint(m_waypointDlgs[i]->GetTarget(), m_waypointDlgs[i]->GetWaypointTargetTime());
		}
	}
	if(!waypointAdded)
	{
		delete m_protossEngine;
		m_protossEngine = 0;
		MessageBox(L"No waypoints to be added.  Please enter target details.");
		return;
	}

	InitEngine(m_protossEngine);

	m_protossEngine->AddSeed(m_bestBuildOrder);
	m_bestBuildOrder = CVector<EProtossCommand>();

	if(m_settingsDlg->GetScoutingWorker())
	{
		m_protossEngine->AddCustomEvent(CProtossEvent(CProtossEvent::eSendScout, m_settingsDlg->GetScoutingWorkerTime()));
		if(m_settingsDlg->GetScoutingWorkerDies())
			m_protossEngine->AddCustomEvent(CProtossEvent(CProtossEvent::eKillScout, m_settingsDlg->GetScoutingWorkerEndTime()));
		else if(m_settingsDlg->GetScoutingWorkerReturns())
			m_protossEngine->AddCustomEvent(CProtossEvent(CProtossEvent::eReturnScout, m_settingsDlg->GetScoutingWorkerEndTime()));
	}

	m_protossEngine->Start();
}

void CSCBuildOrderGUIProtossView::StopEngine()
{
	CSCBuildOrderGUIView::StopEngine();

	if(m_protossEngine)
	{
		m_protossEngine->Stop();
		delete m_protossEngine;
		m_protossEngine = 0;
	}
}

bool CSCBuildOrderGUIProtossView::UpdateBestBuildOrder()
{
	CVector<EProtossCommand> buildOrder;
	m_protossEngine->GetBestGame(buildOrder);
	if(buildOrder != m_bestBuildOrder)
	{
		m_bestBuildOrder = buildOrder;
		return true;
	}

	return false;
}

void CSCBuildOrderGUIProtossView::SetTargetDlgPositions(const CRect &rect)
{
	for(int nCount=0; nCount < 5; nCount++)
		m_waypointDlgs[nCount]->SetWindowPos(&wndTop, rect.left, rect.top, rect.Width(), rect.Height(), SWP_HIDEWINDOW);
}

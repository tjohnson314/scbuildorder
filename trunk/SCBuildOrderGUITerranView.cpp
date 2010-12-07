
// SCBuildOrderGUIView.cpp : implementation of the CSCBuildOrderGUIView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "SCBuildOrderGUI.h"
#endif

#include "SCBuildOrderGUIDoc.h"
#include "SCBuildOrderGUITerranView.h"

#include "SettingsDlg.h"
#include "TerranStateDlg.h"

#include "NumberFormat.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSCBuildOrderGUIView

IMPLEMENT_DYNCREATE(CSCBuildOrderGUITerranView, CSCBuildOrderGUIView)

BEGIN_MESSAGE_MAP(CSCBuildOrderGUITerranView, CSCBuildOrderGUIView)
END_MESSAGE_MAP()



// CSCBuildOrderGUIView construction/destruction

CSCBuildOrderGUITerranView::CSCBuildOrderGUITerranView()
	: CSCBuildOrderGUIView(), m_terranEngine(NULL)
{
}

CSCBuildOrderGUITerranView::~CSCBuildOrderGUITerranView()
{
	StopEngine();
	delete m_terranEngine;

	while(m_waypointDlgs.size() > 0)
		delete m_waypointDlgs.pop();
}

void CSCBuildOrderGUITerranView::DoDataExchange(CDataExchange* pDX)
{
	CSCBuildOrderGUIView::DoDataExchange(pDX);
}

BOOL CSCBuildOrderGUITerranView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CSCBuildOrderGUIView::PreCreateWindow(cs);
}

// CSCBuildOrderGUITerranView drawing

void CSCBuildOrderGUITerranView::OnDraw(CDC* /*pDC*/)
{
	CSCBuildOrderGUIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}

void CSCBuildOrderGUITerranView::AddTargetDlg()
{
	CTerranStateDlg *pDlg = new CTerranStateDlg();
	pDlg->SetWaypointTargetTime((m_waypointDlgs.size() + 1) * 300);
	pDlg->Create(IDD_DLG_TERRANSTATE, this);
	m_waypointDlgs.push_back(pDlg);
}

void CSCBuildOrderGUITerranView::OnInitialUpdate()
{
	CSCBuildOrderGUIView::OnInitialUpdate();
}

// CSCBuildOrderGUIView diagnostics

#ifdef _DEBUG
void CSCBuildOrderGUITerranView::AssertValid() const
{
	CSCBuildOrderGUIView::AssertValid();
}

void CSCBuildOrderGUITerranView::Dump(CDumpContext& dc) const
{
	CSCBuildOrderGUIView::Dump(dc);
}

CSCBuildOrderGUIDoc* CSCBuildOrderGUITerranView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSCBuildOrderGUIDoc)));
	return (CSCBuildOrderGUIDoc*)m_pDocument;
}
#endif //_DEBUG

// CSCBuildOrderGUITerranView message handlers
bool CSCBuildOrderGUITerranView::StartEngine()
{
	m_settingsDlg->UpdateData(TRUE);

	delete m_terranEngine;
	m_terranEngine = new CTerranEngine(m_settingsDlg->GetTimeLimit());
	bool waypointAdded = false;
	for(size_t i=0; i < m_waypointDlgs.size(); i++)
	{
		if(m_waypointDlgs[i]->GetTarget().hasTarget())
		{
			waypointAdded = true;
			m_terranEngine->AddWaypoint(m_waypointDlgs[i]->GetTarget(), m_waypointDlgs[i]->GetWaypointTargetTime());
		}
	}
	if(!waypointAdded)
	{
		delete m_terranEngine;
		m_terranEngine = 0;
		MessageBox(L"No waypoints to be added.  Please enter target details.");
		return false;
	}

	InitEngine(m_terranEngine);

	m_terranEngine->AddSeed(m_bestBuildOrder);
	m_bestBuildOrder = CVector<ETerranCommand>();

	if(m_settingsDlg->GetScoutingWorker())
	{
		m_terranEngine->AddCustomEvent(CTerranEvent(CTerranEvent::eSendScout, m_settingsDlg->GetScoutingWorkerTime()));
		if(m_settingsDlg->GetScoutingWorkerDies())
			m_terranEngine->AddCustomEvent(CTerranEvent(CTerranEvent::eKillScout, m_settingsDlg->GetScoutingWorkerEndTime()));
		else if(m_settingsDlg->GetScoutingWorkerReturns())
			m_terranEngine->AddCustomEvent(CTerranEvent(CTerranEvent::eReturnScout, m_settingsDlg->GetScoutingWorkerEndTime()));
	}

	m_terranEngine->Start();

	return CSCBuildOrderGUIView::StartEngine();
}

void CSCBuildOrderGUITerranView::StopEngine()
{
	CSCBuildOrderGUIView::StopEngine();

	if(m_terranEngine)
	{
		m_terranEngine->Stop();
		delete m_terranEngine;
		m_terranEngine = 0;
	}
}

bool CSCBuildOrderGUITerranView::UpdateBestBuildOrder()
{
	CVector<ETerranCommand> buildOrder;
	m_terranEngine->GetBestGame(buildOrder);
	if(buildOrder != m_bestBuildOrder)
	{
		m_bestBuildOrder = buildOrder;
		return true;
	}

	return false;
}

void CSCBuildOrderGUITerranView::PrintBestGame(EOutputFormat format, CString &text) const
{
	if(!m_terranEngine)
		return;

	m_terranEngine->PrintGame(format, m_bestBuildOrder, text);
}

void CSCBuildOrderGUITerranView::SetTargetDlgPositions(const CRect &rect)
{
	for(int nCount=0; nCount < 5; nCount++)
		m_waypointDlgs[nCount]->SetWindowPos(&wndTop, rect.left, rect.top, rect.Width(), rect.Height(), SWP_HIDEWINDOW);
}

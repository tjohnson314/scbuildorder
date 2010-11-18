
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

#include "SettingsDlg.h"
#include "ProtossStateDlg.h"

#include "NumberFormat.h"

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
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_PAGES, &CSCBuildOrderGUIView::OnTcnSelchangeTabPages)
	ON_WM_SIZE()
END_MESSAGE_MAP()



// CSCBuildOrderGUIView construction/destruction

CSCBuildOrderGUIView::CSCBuildOrderGUIView()
	: CFormView(CSCBuildOrderGUIView::IDD)
	, m_updateTimer(0), m_bStarted(false), m_startTickCount(0), m_timeLimit(1200)
{
	// TODO: add construction code here
	m_numberFormatInt.LoadDefault();
	m_numberFormatInt.SetNumDigits(0);

	m_numberFormatFloat.LoadDefault();
}

CSCBuildOrderGUIView::~CSCBuildOrderGUIView()
{
	if(m_bStarted)
	{
		m_updateTimer = 0;
		StopEngine();
	}

	while(m_waypointDlgs.size() > 0)
		delete m_waypointDlgs.pop();

	delete m_settingsDlg;
}

void CSCBuildOrderGUIView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
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

	// Tab control
	for(size_t i=0; i < 5; i++)
	{
		if(i == 4)
			((CTabCtrl *)GetDlgItem(IDC_TAB_PAGES))->InsertItem(i, L"Target");
		else
		{
			CString tabName;
			tabName.Format(L"Waypoint %d", i + 1);
			((CTabCtrl *)GetDlgItem(IDC_TAB_PAGES))->InsertItem(i, tabName);
		}

		CProtossStateDlg *pDlg = new CProtossStateDlg();
		pDlg->SetWaypointTargetTime((i+1) * 300);
		pDlg->Create(IDD_DLG_PROTOSSSTATE, this);
		m_waypointDlgs.push_back(pDlg);
	}

	((CTabCtrl *)GetDlgItem(IDC_TAB_PAGES))->InsertItem(5, L"Settings");
	((CTabCtrl *)GetDlgItem(IDC_TAB_PAGES))->SetCurSel(4);
	m_settingsDlg = new CSettingsDlg();
	m_settingsDlg->Create(IDD_DLG_SETTINGS, this);

	ActivateTabDialogs();

	// Villages list
	CListCtrl *villageList = (CListCtrl *)GetDlgItem(IDC_LIST_VILLAGEINFO);

	LVCOLUMN lvColumn;

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_CENTER;
	lvColumn.cx = 60;
	lvColumn.pszText = L"Name";
	villageList->InsertColumn(0, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_CENTER;
	lvColumn.cx = 80;
	lvColumn.pszText = L"Population";
	villageList->InsertColumn(1, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_CENTER;
	lvColumn.cx = 80;
	lvColumn.pszText = L"Evolution";
	villageList->InsertColumn(2, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_CENTER;
	lvColumn.cx = 80;
	lvColumn.pszText = L"Stagnation";
	villageList->InsertColumn(3, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_CENTER;
	lvColumn.cx = 80;
	lvColumn.pszText = L"Game Count";
	villageList->InsertColumn(4, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_CENTER;
	lvColumn.cx = 80;
	lvColumn.pszText = L"Game Rate";
	villageList->InsertColumn(5, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_CENTER;
	lvColumn.cx = 80;
	lvColumn.pszText = L"Best Fitness";
	villageList->InsertColumn(6, &lvColumn);

	// Output
	m_font.CreatePointFont(90, _T("Courier"));
	GetDlgItem(IDC_EDIT_OUTPUT)->SetFont(&m_font);
}

void CSCBuildOrderGUIView::ResizeControls()
{
	if(!IsWindowVisible())
		return;

	CRect rectDlgClient, rectDlgWnd, rectWnd;
	GetClientRect(rectDlgClient);
	GetWindowRect(rectDlgWnd);

	// Anchor Villages List to right
	CWnd *pWnd = GetDlgItem(IDC_LIST_VILLAGEINFO);
	pWnd->GetWindowRect(rectWnd);
	if(rectDlgWnd.right > rectWnd.left)
		pWnd->SetWindowPos(NULL, 0, 0, rectDlgClient.right - rectDlgClient.left - (rectWnd.left - rectDlgWnd.left) - 6, rectWnd.bottom - rectWnd.top, SWP_NOMOVE|SWP_NOZORDER);

	// Anchor Output to bottom and right
	pWnd = GetDlgItem(IDC_EDIT_OUTPUT);
	pWnd->GetWindowRect(rectWnd);
	if(rectDlgWnd.right > rectWnd.left && rectDlgWnd.bottom > rectWnd.top)
		pWnd->SetWindowPos(NULL, 0, 0, rectDlgClient.right - rectDlgClient.left - (rectWnd.left - rectDlgWnd.left) - 6, rectDlgClient.bottom - rectDlgClient.top - (rectWnd.top - rectDlgWnd.top) - 6, SWP_NOMOVE|SWP_NOZORDER);

	// Anchor tab control to bottom
	pWnd = GetDlgItem(IDC_TAB_PAGES);
	pWnd->GetWindowRect(rectWnd);
	if(rectDlgWnd.bottom > rectWnd.top)
		pWnd->SetWindowPos(NULL, 0, 0, rectWnd.right - rectWnd.left, rectDlgClient.bottom - rectDlgClient.top - (rectWnd.top - rectDlgWnd.top) - 6, SWP_NOMOVE|SWP_NOZORDER);

	ActivateTabDialogs();

	GetParentFrame()->RecalcLayout();
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
void CSCBuildOrderGUIView::StopEngine()
{
	if(m_updateTimer)
		KillTimer(m_updateTimer);

	m_protossEngine->Stop();
	delete m_protossEngine;
	m_protossEngine = 0;

	m_bStarted = false;
}

void CSCBuildOrderGUIView::OnBnClickedButtonStart()
{
	if(!m_bStarted)
	{
		UpdateData(TRUE);

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
		m_protossEngine->InitConfiguration(m_settingsDlg->GetMutationRate());
		m_protossEngine->AddVillage(200, 100);
		m_protossEngine->AddVillage(200, 100);
		m_protossEngine->AddVillage(200, 100);
		m_protossEngine->AddVillage(200, 100);
		m_protossEngine->AddVillage(200, 100);

		m_protossEngine->AddSeed(m_bestBuildOrder);

		if(m_settingsDlg->GetScoutingWorker())
		{
			m_protossEngine->AddCustomEvent(CProtossEvent(CProtossEvent::eSendScout, m_settingsDlg->GetScoutingWorkerTime()));
			if(m_settingsDlg->GetScoutingWorkerDies())
				m_protossEngine->AddCustomEvent(CProtossEvent(CProtossEvent::eKillScout, m_settingsDlg->GetScoutingWorkerEndTime()));
			else if(m_settingsDlg->GetScoutingWorkerReturns())
				m_protossEngine->AddCustomEvent(CProtossEvent(CProtossEvent::eReturnScout, m_settingsDlg->GetScoutingWorkerEndTime()));
		}

		CListCtrl *villageList = (CListCtrl *)GetDlgItem(IDC_LIST_VILLAGEINFO);
		villageList->DeleteAllItems();

		LVITEM lvItem;
		CString villageName;
		int nItem;
		lvItem.mask = LVIF_TEXT;
		lvItem.iSubItem = 0;

		villageName = L"Overall";

		lvItem.iItem = 0;
		lvItem.pszText = villageName.GetBuffer();
		nItem = villageList->InsertItem(&lvItem);
		villageName.ReleaseBuffer();

		villageList->SetItemText(nItem, 1, L"0");
		villageList->SetItemText(nItem, 2, L"0");
		villageList->SetItemText(nItem, 3, L"0");
		villageList->SetItemText(nItem, 4, L"0");
		villageList->SetItemText(nItem, 5, L"0");
		villageList->SetItemText(nItem, 5, L"0");

		villageName = L"City";

		lvItem.iItem = 1;
		lvItem.pszText = villageName.GetBuffer();
		nItem = villageList->InsertItem(&lvItem);
		villageName.ReleaseBuffer();

		villageList->SetItemText(nItem, 1, L"0");
		villageList->SetItemText(nItem, 2, L"0");
		villageList->SetItemText(nItem, 3, L"0");
		villageList->SetItemText(nItem, 4, L"0");
		villageList->SetItemText(nItem, 5, L"0");
		villageList->SetItemText(nItem, 5, L"0");

		for(size_t i=0; i < 5; i++)
		{
			villageName.Format(L"Village %d", i+1);

			lvItem.iItem = i+2;
			lvItem.pszText = villageName.GetBuffer();
			nItem = villageList->InsertItem(&lvItem);
			villageName.ReleaseBuffer();

			villageList->SetItemText(nItem, 1, L"0");
			villageList->SetItemText(nItem, 2, L"0");
			villageList->SetItemText(nItem, 3, L"0");
			villageList->SetItemText(nItem, 4, L"0");
			villageList->SetItemText(nItem, 5, L"0");
			villageList->SetItemText(nItem, 5, L"0");
		}

		m_bStarted = true;
		GetDlgItem(IDC_BUTTON_STARTSTOP)->SetWindowTextW(L"Stop");

		m_protossEngine->Start();
		m_startTickCount = GetTickCount();
		m_updateTimer = SetTimer(IDT_TIMER_0, 1000, 0);
	}
	else
	{
		StopEngine();
		GetDlgItem(IDC_BUTTON_STARTSTOP)->SetWindowTextW(L"Start");
	}
}

void CSCBuildOrderGUIView::UpdateListBoxEntry(int nItem, size_t population, size_t evolution, size_t stagnationCount, unsigned long long gameCount, double bestFitness, DWORD timeDiff)
{
	CListCtrl *villageList = (CListCtrl *)GetDlgItem(IDC_LIST_VILLAGEINFO);

	LVITEM lvItem;
	lvItem.mask = LVIF_TEXT;
	lvItem.iSubItem = 0;

	CString strText, strText2;

	strText.Format(L"%u", population);
	m_numberFormatInt.FormatNumberByLocale(strText, strText2);
	villageList->SetItemText(nItem, 1, strText2);

	strText.Format(L"%u", evolution);
	m_numberFormatInt.FormatNumberByLocale(strText, strText2);
	villageList->SetItemText(nItem, 2, strText2);

	strText.Format(L"%u", stagnationCount);
	m_numberFormatInt.FormatNumberByLocale(strText, strText2);
	villageList->SetItemText(nItem, 3, strText2);

	strText.Format(L"%llu", gameCount);
	m_numberFormatInt.FormatNumberByLocale(strText, strText2);
	villageList->SetItemText(nItem, 4, strText2);

	if(0 != timeDiff)
	{
		strText.Format(L"%llu", (1000 * gameCount) / timeDiff);
		m_numberFormatInt.FormatNumberByLocale(strText, strText2);
		villageList->SetItemText(nItem, 5, strText2);
	}
	else
		villageList->SetItemText(nItem, 5, 0);

	strText.Format(L"%08.3lf", bestFitness);
	m_numberFormatFloat.FormatNumberByLocale(strText, strText2);
	villageList->SetItemText(nItem, 6, strText2);
}

void CSCBuildOrderGUIView::OnTimer(UINT TimerVal)
{
	if(m_protossEngine)
	{
		DWORD timeDiff = GetTickCount() - m_startTickCount;

		size_t totalPopulation = m_protossEngine->CityPopulationCount();
		size_t totalEvolution = m_protossEngine->CityEvolution();
		size_t totalStagnationCount = m_protossEngine->CityStagnationCount();
		unsigned long long totalGameCount = m_protossEngine->CityGameCount();
		double overallBestFitness = m_protossEngine->CityBestFitness();

		UpdateListBoxEntry(1, totalPopulation, totalEvolution, totalStagnationCount, totalGameCount, 1000.0 * overallBestFitness, timeDiff);
		for(size_t i=0; i < 5; i++)
		{
			size_t villagePopulation = m_protossEngine->VillagePopulationCount(i);
			size_t villageEvolution = m_protossEngine->VillageEvolution(i);
			size_t villageStagnationCount = m_protossEngine->VillageStagnationCount(i);
			unsigned long long villageGameCount = m_protossEngine->VillageGameCount(i);
			double villageBestFitness = m_protossEngine->VillageBestFitness(i);

			UpdateListBoxEntry(i+2, villagePopulation, villageEvolution, villageStagnationCount, villageGameCount, 1000.0 * villageBestFitness, timeDiff);

			totalPopulation += villagePopulation;
			totalGameCount += villageGameCount;
			if(villageBestFitness > overallBestFitness)
				overallBestFitness = villageBestFitness;
		}
		totalStagnationCount = m_protossEngine->StagnationLimit();
		UpdateListBoxEntry(0, totalPopulation, totalEvolution, totalStagnationCount, totalGameCount, 1000.0 * overallBestFitness, timeDiff);

		CVector<EProtossCommand> buildOrder;
		m_protossEngine->GetBestGame(buildOrder);

		if(buildOrder != m_bestBuildOrder)
		{
			CString strText;
			m_bestBuildOrder = buildOrder;
			m_protossEngine->PrintBestGame(strText);
			GetDlgItem(IDC_EDIT_OUTPUT)->SetWindowTextW(strText);
		}
	}
}

void CSCBuildOrderGUIView::ActivateTabDialogs()
{
	CTabCtrl *tabCtrl = (CTabCtrl *)GetDlgItem(IDC_TAB_PAGES);

	int nSel = tabCtrl->GetCurSel();
	CDialog *pCurSelDlg;
	if(nSel < 5)
		pCurSelDlg = m_waypointDlgs[nSel];
	else
		pCurSelDlg = m_settingsDlg;

	if(pCurSelDlg->m_hWnd)
		pCurSelDlg->ShowWindow(SW_HIDE);

	CRect rectClient;
	CRect rectWnd;

	tabCtrl->GetClientRect(rectClient);
	tabCtrl->AdjustRect(FALSE, rectClient);
	tabCtrl->GetWindowRect(rectWnd);
	tabCtrl->GetParent()->ScreenToClient(rectWnd);
	rectClient.OffsetRect(rectWnd.left, rectWnd.top);
	for(int nCount=0; nCount < 5; nCount++)
	{
		m_waypointDlgs[nCount]->SetWindowPos(&wndTop, rectClient.left, rectClient.top, rectClient.Width(), rectClient.Height(), SWP_HIDEWINDOW);
	}
	m_settingsDlg->SetWindowPos(&wndTop, rectClient.left, rectClient.top, rectClient.Width(), rectClient.Height(), SWP_HIDEWINDOW);

	if(nSel < 5)
		pCurSelDlg = m_waypointDlgs[nSel];
	else
		pCurSelDlg = m_settingsDlg;

	pCurSelDlg->SetWindowPos(&wndTop, rectClient.left, rectClient.top, rectClient.Width(), rectClient.Height(), SWP_SHOWWINDOW);
	pCurSelDlg->ShowWindow(SW_SHOW);
}

void CSCBuildOrderGUIView::OnTcnSelchangeTabPages(NMHDR *pNMHDR, LRESULT *pResult)
{
	CTabCtrl *tabCtrl = (CTabCtrl *)GetDlgItem(IDC_TAB_PAGES);
	ActivateTabDialogs();

	*pResult = 0;
}


void CSCBuildOrderGUIView::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	ResizeControls();
}
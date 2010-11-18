// SettingsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SCBuildOrderGUI.h"
#include "SettingsDlg.h"
#include "afxdialogex.h"


// CSettingsDlg dialog

IMPLEMENT_DYNAMIC(CSettingsDlg, CDialogEx)

CSettingsDlg::CSettingsDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSettingsDlg::IDD, pParent)
	, m_timeLimit(1200), m_mutationRate(0.3)
	, m_scoutingWorker(FALSE), m_scoutingWorkerTime(0.0)
	, m_scoutingWorkerDies(FALSE), m_scoutingWorkerReturns(FALSE), m_scoutingWorkerEndTime(0.0)
{
}

CSettingsDlg::~CSettingsDlg()
{
}

void CSettingsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TIMELIMIT, m_timeLimit);
	DDX_Text(pDX, IDC_EDIT_MUTATIONRATE, m_mutationRate);

	DDX_Check(pDX, IDC_CHECK_SCOUTINGWORKER, m_scoutingWorker);
	DDX_Text(pDX, IDC_EDIT_SCOUTINGWORKERTIME, m_scoutingWorkerTime);
	DDX_Check(pDX, IDC_CHECK_SCOUTINGWORKERDIES, m_scoutingWorkerDies);
	DDX_Check(pDX, IDC_CHECK_SCOUTINGWORKERRETURNS, m_scoutingWorkerReturns);
	DDX_Text(pDX, IDC_EDIT_SCOUTINGWORKEREND, m_scoutingWorkerEndTime);
}

BOOL CSettingsDlg::OnInitDialog()
{
	BOOL bRet = CDialogEx::OnInitDialog();

	CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_LIST_VILLAGES);

	pList->SetExtendedStyle(pList->GetExtendedStyle() | LVS_EX_FULLROWSELECT);

	LVCOLUMN lvColumn;

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_CENTER;
	lvColumn.cx = 60;
	lvColumn.pszText = L"Village #";
	pList->InsertColumn(0, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_CENTER;
	lvColumn.cx = 100;
	lvColumn.pszText = L"Max Population";
	pList->InsertColumn(1, &lvColumn);
	
	LVITEM lvItem;
	CString villageName;
	int nItem;

	for(size_t i=0; i < 5; i++)
	{
		villageName.Format(L"Village %d", i+1);

		lvItem.mask = LVIF_TEXT;
		lvItem.iItem = i;
		lvItem.iSubItem = 0;
		lvItem.pszText = villageName.GetBuffer();
		nItem = pList->InsertItem(&lvItem);

		pList->SetItemText(nItem, 1, L"200");

		villageName.ReleaseBuffer();
	}

	EnableScoutingWorkerControls();

	return bRet;
}


BEGIN_MESSAGE_MAP(CSettingsDlg, CDialogEx)
	ON_BN_CLICKED(IDC_CHECK_SCOUTINGWORKER, &CSettingsDlg::OnBnClickedCheckScoutingworker)
	ON_BN_CLICKED(IDC_CHECK_SCOUTINGWORKERDIES, &CSettingsDlg::OnBnClickedCheckScoutingworkerdies)
	ON_BN_CLICKED(IDC_CHECK_SCOUTINGWORKERRETURNS, &CSettingsDlg::OnBnClickedCheckScoutingworkerreturns)
	ON_EN_KILLFOCUS(IDC_EDIT_SCOUTINGWORKEREND, &CSettingsDlg::OnEnKillFocusScoutingworkerend)
	ON_EN_KILLFOCUS(IDC_EDIT_SCOUTINGWORKERTIME, &CSettingsDlg::OnEnKillFocusScoutingworkertime)
END_MESSAGE_MAP()

// CSettingsDlg message handlers

void CSettingsDlg::EnableScoutingWorkerControls()
{
	UpdateData(TRUE);

	GetDlgItem(IDC_EDIT_SCOUTINGWORKERTIME)->EnableWindow(m_scoutingWorker ? BST_CHECKED : BST_UNCHECKED);
	GetDlgItem(IDC_CHECK_SCOUTINGWORKERDIES)->EnableWindow(m_scoutingWorker ? BST_CHECKED : BST_UNCHECKED);
	GetDlgItem(IDC_CHECK_SCOUTINGWORKERRETURNS)->EnableWindow(m_scoutingWorker ? BST_CHECKED : BST_UNCHECKED);
	GetDlgItem(IDC_EDIT_SCOUTINGWORKEREND)->EnableWindow(m_scoutingWorker && (m_scoutingWorkerDies || m_scoutingWorkerReturns) ? BST_CHECKED : BST_UNCHECKED);
}

void CSettingsDlg::OnBnClickedCheckScoutingworker()
{
	EnableScoutingWorkerControls();
}

void CSettingsDlg::OnBnClickedCheckScoutingworkerdies()
{
	UpdateData(TRUE);
	m_scoutingWorkerReturns = FALSE;
	UpdateData(FALSE);

	EnableScoutingWorkerControls();
}

void CSettingsDlg::OnBnClickedCheckScoutingworkerreturns()
{
	UpdateData(TRUE);
	m_scoutingWorkerDies = FALSE;
	UpdateData(FALSE);

	EnableScoutingWorkerControls();
}

void CSettingsDlg::OnEnKillFocusScoutingworkerend()
{
	UpdateData(TRUE);
	if(m_scoutingWorkerTime > m_scoutingWorkerEndTime)
	{
		m_scoutingWorkerEndTime = m_scoutingWorkerTime;
		UpdateData(FALSE);
	}
}

void CSettingsDlg::OnEnKillFocusScoutingworkertime()
{
	UpdateData(TRUE);
	if(m_scoutingWorkerTime > m_scoutingWorkerEndTime)
	{
		m_scoutingWorkerEndTime = m_scoutingWorkerTime;
		UpdateData(FALSE);
	}
}

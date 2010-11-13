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
	, m_timeLimit(1200), m_mutationRate(0.02)
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

	return bRet;
}


BEGIN_MESSAGE_MAP(CSettingsDlg, CDialogEx)
END_MESSAGE_MAP()

// CSettingsDlg message handlers

// ProtossStateDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SCBuildOrderGUI.h"
#include "ProtossStateDlg.h"
#include "afxdialogex.h"


// CProtossStateDlg dialog

IMPLEMENT_DYNAMIC(CProtossStateDlg, CDialogEx)

CProtossStateDlg::CProtossStateDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CProtossStateDlg::IDD, pParent)
	, m_waypointTargetTime(1200)
{
}

CProtossStateDlg::~CProtossStateDlg()
{
}

void CProtossStateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TIMELIMIT, m_waypointTargetTime);
	DDX_Text(pDX, IDC_EDIT_NEXUSCOUNT, m_protossState.m_nexusCount);
	DDX_Text(pDX, IDC_EDIT_PYLONCOUNT, m_protossState.m_pylonCount);
	DDX_Text(pDX, IDC_EDIT_ASSIMILATORCOUNT, m_protossState.m_assimilatorCount);
	DDX_Text(pDX, IDC_EDIT_GATEWAYCOUNT, m_protossState.m_gatewayCount);
	DDX_Text(pDX, IDC_EDIT_WARPGATECOUNT, m_protossState.m_warpgateCount);
	DDX_Text(pDX, IDC_EDIT_FORGECOUNT, m_protossState.m_forgeCount);
	DDX_Text(pDX, IDC_EDIT_PHOTONCANNONCOUNT, m_protossState.m_photonCannonCount);
	DDX_Text(pDX, IDC_EDIT_CYBERNETICSCORECOUNT, m_protossState.m_cyberneticsCoreCount);
	DDX_Text(pDX, IDC_EDIT_TWILIGHTCOUNCILCOUNT, m_protossState.m_twilightCouncilCount);
	DDX_Text(pDX, IDC_EDIT_TEMPLARARCHIVESCOUNT, m_protossState.m_templarArchivesCount);
	DDX_Text(pDX, IDC_EDIT_DARKSHRINECOUNT, m_protossState.m_darkShrineCount);
	DDX_Text(pDX, IDC_EDIT_ROBOTICSFACILITYCOUNT, m_protossState.m_roboticsFacilityCount);
	DDX_Text(pDX, IDC_EDIT_ROBOTICSBAYCOUNT, m_protossState.m_roboticsBayCount);
	DDX_Text(pDX, IDC_EDIT_STARGATECOUNT, m_protossState.m_stargateCount);
	DDX_Text(pDX, IDC_EDIT_FLEETBEACONCOUNT, m_protossState.m_fleetBeaconCount);
	BOOL bWarpgateResearch = m_protossState.m_researchWarpgateCompleted;
	DDX_Check(pDX, IDC_CHECK_WARPGATERESEARCH, bWarpgateResearch);
	m_protossState.m_researchWarpgateCompleted = bWarpgateResearch ? true : false;
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


BEGIN_MESSAGE_MAP(CProtossStateDlg, CDialogEx)
END_MESSAGE_MAP()


// CProtossStateDlg message handlers

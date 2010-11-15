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

void CProtossStateDlg::DDX_Check(CDataExchange* pDX, int nIDC, bool &bValue)
{
	BOOL bBigBool = bValue ? TRUE : FALSE;
	::DDX_Check(pDX, nIDC, bBigBool);
	bValue = bBigBool ? true : false;
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
	DDX_Check(pDX, IDC_CHECK_GROUNDWEAPONSPLUS1, m_protossState.m_researchGroundWeapons1Completed);
	DDX_Check(pDX, IDC_CHECK_GROUNDWEAPONSPLUS2, m_protossState.m_researchGroundWeapons2Completed);
	DDX_Check(pDX, IDC_CHECK_GROUNDWEAPONSPLUS3, m_protossState.m_researchGroundWeapons3Completed);
	DDX_Check(pDX, IDC_CHECK_GROUNDARMORPLUS1, m_protossState.m_researchGroundArmor1Completed);
	DDX_Check(pDX, IDC_CHECK_GROUNDARMORPLUS2, m_protossState.m_researchGroundArmor2Completed);
	DDX_Check(pDX, IDC_CHECK_GROUNDARMORPLUS3, m_protossState.m_researchGroundArmor3Completed);
	DDX_Check(pDX, IDC_CHECK_SHIELDSPLUS1, m_protossState.m_researchShields1Completed);
	DDX_Check(pDX, IDC_CHECK_SHIELDSPLUS2, m_protossState.m_researchShields2Completed);
	DDX_Check(pDX, IDC_CHECK_SHIELDSPLUS3, m_protossState.m_researchShields3Completed);
	DDX_Text(pDX, IDC_EDIT_PHOTONCANNONCOUNT, m_protossState.m_photonCannonCount);
	DDX_Text(pDX, IDC_EDIT_CYBERNETICSCORECOUNT, m_protossState.m_cyberneticsCoreCount);
	DDX_Check(pDX, IDC_CHECK_AIRWEAPONSPLUS1, m_protossState.m_researchAirWeapons1Completed);
	DDX_Check(pDX, IDC_CHECK_AIRWEAPONSPLUS2, m_protossState.m_researchAirWeapons2Completed);
	DDX_Check(pDX, IDC_CHECK_AIRWEAPONSPLUS3, m_protossState.m_researchAirWeapons3Completed);
	DDX_Check(pDX, IDC_CHECK_AIRARMORPLUS1, m_protossState.m_researchAirArmor1Completed);
	DDX_Check(pDX, IDC_CHECK_AIRARMORPLUS2, m_protossState.m_researchAirArmor2Completed);
	DDX_Check(pDX, IDC_CHECK_AIRARMORPLUS3, m_protossState.m_researchAirArmor3Completed);
	DDX_Check(pDX, IDC_CHECK_WARPGATETRANSFORM, m_protossState.m_researchWarpGateTransformationCompleted);
	DDX_Check(pDX, IDC_CHECK_HALLUCINATION, m_protossState.m_researchHallucinationCompleted);
	DDX_Text(pDX, IDC_EDIT_TWILIGHTCOUNCILCOUNT, m_protossState.m_twilightCouncilCount);
	DDX_Check(pDX, IDC_CHECK_CHARGE, m_protossState.m_researchChargeCompleted);
	DDX_Check(pDX, IDC_CHECK_BLINK, m_protossState.m_researchBlinkCompleted);
	DDX_Text(pDX, IDC_EDIT_TEMPLARARCHIVESCOUNT, m_protossState.m_templarArchivesCount);
	DDX_Check(pDX, IDC_CHECK_PSIONICSTORM, m_protossState.m_researchPsionicStormCompleted);
	DDX_Check(pDX, IDC_CHECK_KHAYDARINAMULET, m_protossState.m_researchKhaydarinAmuletCompleted);
	DDX_Text(pDX, IDC_EDIT_DARKSHRINECOUNT, m_protossState.m_darkShrineCount);
	DDX_Text(pDX, IDC_EDIT_ROBOTICSFACILITYCOUNT, m_protossState.m_roboticsFacilityCount);
	DDX_Text(pDX, IDC_EDIT_ROBOTICSBAYCOUNT, m_protossState.m_roboticsBayCount);
	DDX_Check(pDX, IDC_CHECK_GRAVITICDRIVE, m_protossState.m_researchGraviticDriveCompleted);
	DDX_Check(pDX, IDC_CHECK_GRAVITICBOOSTERS, m_protossState.m_researchGraviticBoostersCompleted);
	DDX_Check(pDX, IDC_CHECK_THERMALLANCE, m_protossState.m_researchExtendedThermalLanceCompleted);
	DDX_Text(pDX, IDC_EDIT_STARGATECOUNT, m_protossState.m_stargateCount);
	DDX_Text(pDX, IDC_EDIT_FLEETBEACONCOUNT, m_protossState.m_fleetBeaconCount);
	DDX_Check(pDX, IDC_CHECK_FLUXVANES, m_protossState.m_researchFluxVanesCompleted);
	DDX_Check(pDX, IDC_CHECK_GRAVITONCATAPULT, m_protossState.m_researchGravitonCatapultCompleted);
	DDX_Text(pDX, IDC_EDIT_PROBECOUNT, m_protossState.m_probeCount);
	DDX_Text(pDX, IDC_EDIT_ZEALOTCOUNT, m_protossState.m_zealotCount);
	DDX_Text(pDX, IDC_EDIT_STALKERCOUNT, m_protossState.m_stalkerCount);
	DDX_Text(pDX, IDC_EDIT_SENTRYCOUNT, m_protossState.m_sentryCount);
	DDX_Text(pDX, IDC_EDIT_HIGHTEMPLARCOUNT, m_protossState.m_highTemplarCount);
	DDX_Text(pDX, IDC_EDIT_DARKTEMPLARCOUNT, m_protossState.m_darkTemplarCount);
	DDX_Text(pDX, IDC_EDIT_ARCHONCOUNT, m_protossState.m_archonCount);
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

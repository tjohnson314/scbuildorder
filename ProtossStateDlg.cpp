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
	DDX_Text(pDX, IDC_EDIT_NEXUSCOUNT, m_protossTarget.m_nexusCount);
	DDX_Text(pDX, IDC_EDIT_PYLONCOUNT, m_protossTarget.m_pylonCount);
	DDX_Text(pDX, IDC_EDIT_ASSIMILATORCOUNT, m_protossTarget.m_assimilatorCount);
	DDX_Text(pDX, IDC_EDIT_GATEWAYCOUNT, m_protossTarget.m_gatewayCount);
	DDX_Text(pDX, IDC_EDIT_WARPGATECOUNT, m_protossTarget.m_warpGateCount);
	DDX_Text(pDX, IDC_EDIT_FORGECOUNT, m_protossTarget.m_forgeCount);
	DDX_Check(pDX, IDC_CHECK_GROUNDWEAPONSPLUS1, m_protossTarget.m_researchGroundWeapons1Completed);
	DDX_Check(pDX, IDC_CHECK_GROUNDWEAPONSPLUS2, m_protossTarget.m_researchGroundWeapons2Completed);
	DDX_Check(pDX, IDC_CHECK_GROUNDWEAPONSPLUS3, m_protossTarget.m_researchGroundWeapons3Completed);
	DDX_Check(pDX, IDC_CHECK_GROUNDARMORPLUS1, m_protossTarget.m_researchGroundArmor1Completed);
	DDX_Check(pDX, IDC_CHECK_GROUNDARMORPLUS2, m_protossTarget.m_researchGroundArmor2Completed);
	DDX_Check(pDX, IDC_CHECK_GROUNDARMORPLUS3, m_protossTarget.m_researchGroundArmor3Completed);
	DDX_Check(pDX, IDC_CHECK_SHIELDSPLUS1, m_protossTarget.m_researchShields1Completed);
	DDX_Check(pDX, IDC_CHECK_SHIELDSPLUS2, m_protossTarget.m_researchShields2Completed);
	DDX_Check(pDX, IDC_CHECK_SHIELDSPLUS3, m_protossTarget.m_researchShields3Completed);
	DDX_Text(pDX, IDC_EDIT_PHOTONCANNONCOUNT, m_protossTarget.m_photonCannonCount);
	DDX_Text(pDX, IDC_EDIT_CYBERNETICSCORECOUNT, m_protossTarget.m_cyberneticsCoreCount);
	DDX_Check(pDX, IDC_CHECK_AIRWEAPONSPLUS1, m_protossTarget.m_researchAirWeapons1Completed);
	DDX_Check(pDX, IDC_CHECK_AIRWEAPONSPLUS2, m_protossTarget.m_researchAirWeapons2Completed);
	DDX_Check(pDX, IDC_CHECK_AIRWEAPONSPLUS3, m_protossTarget.m_researchAirWeapons3Completed);
	DDX_Check(pDX, IDC_CHECK_AIRARMORPLUS1, m_protossTarget.m_researchAirArmor1Completed);
	DDX_Check(pDX, IDC_CHECK_AIRARMORPLUS2, m_protossTarget.m_researchAirArmor2Completed);
	DDX_Check(pDX, IDC_CHECK_AIRARMORPLUS3, m_protossTarget.m_researchAirArmor3Completed);
	DDX_Check(pDX, IDC_CHECK_WARPGATETRANSFORM, m_protossTarget.m_researchWarpGateTransformationCompleted);
	DDX_Check(pDX, IDC_CHECK_HALLUCINATION, m_protossTarget.m_researchHallucinationCompleted);
	DDX_Text(pDX, IDC_EDIT_TWILIGHTCOUNCILCOUNT, m_protossTarget.m_twilightCouncilCount);
	DDX_Check(pDX, IDC_CHECK_CHARGE, m_protossTarget.m_researchChargeCompleted);
	DDX_Check(pDX, IDC_CHECK_BLINK, m_protossTarget.m_researchBlinkCompleted);
	DDX_Text(pDX, IDC_EDIT_TEMPLARARCHIVESCOUNT, m_protossTarget.m_templarArchivesCount);
	DDX_Check(pDX, IDC_CHECK_PSIONICSTORM, m_protossTarget.m_researchPsionicStormCompleted);
	DDX_Text(pDX, IDC_EDIT_DARKSHRINECOUNT, m_protossTarget.m_darkShrineCount);
	DDX_Text(pDX, IDC_EDIT_ROBOTICSFACILITYCOUNT, m_protossTarget.m_roboticsFacilityCount);
	DDX_Text(pDX, IDC_EDIT_ROBOTICSBAYCOUNT, m_protossTarget.m_roboticsBayCount);
	DDX_Check(pDX, IDC_CHECK_GRAVITICDRIVE, m_protossTarget.m_researchGraviticDriveCompleted);
	DDX_Check(pDX, IDC_CHECK_GRAVITICBOOSTERS, m_protossTarget.m_researchGraviticBoostersCompleted);
	DDX_Check(pDX, IDC_CHECK_THERMALLANCE, m_protossTarget.m_researchExtendedThermalLanceCompleted);
	DDX_Text(pDX, IDC_EDIT_STARGATECOUNT, m_protossTarget.m_stargateCount);
	DDX_Text(pDX, IDC_EDIT_FLEETBEACONCOUNT, m_protossTarget.m_fleetBeaconCount);
//	DDX_Check(pDX, IDC_CHECK_FLUXVANES, m_protossTarget.m_researchFluxVanesCompleted);
	DDX_Check(pDX, IDC_CHECK_GRAVITONCATAPULT, m_protossTarget.m_researchGravitonCatapultCompleted);
	DDX_Text(pDX, IDC_EDIT_PROBECOUNT, m_protossTarget.m_probeCount);
	DDX_Check(pDX, IDC_CHECK_CONSTANTPROBEPRODUCTION, m_protossTarget.m_constantProbeProduction);
	DDX_Text(pDX, IDC_EDIT_ZEALOTCOUNT, m_protossTarget.m_zealotCount);
	DDX_Text(pDX, IDC_EDIT_STALKERCOUNT, m_protossTarget.m_stalkerCount);
	DDX_Text(pDX, IDC_EDIT_SENTRYCOUNT, m_protossTarget.m_sentryCount);
	DDX_Text(pDX, IDC_EDIT_HIGHTEMPLARCOUNT, m_protossTarget.m_highTemplarCount);
	DDX_Text(pDX, IDC_EDIT_DARKTEMPLARCOUNT, m_protossTarget.m_darkTemplarCount);
	DDX_Text(pDX, IDC_EDIT_ARCHONCOUNT, m_protossTarget.m_archonCount);
	DDX_Text(pDX, IDC_EDIT_WARPPRISMCOUNT, m_protossTarget.m_warpPrismCount);
	DDX_Text(pDX, IDC_EDIT_OBSERVERCOUNT, m_protossTarget.m_observerCount);
	DDX_Text(pDX, IDC_EDIT_IMMORTALCOUNT, m_protossTarget.m_immortalCount);
	DDX_Text(pDX, IDC_EDIT_COLOSSUSCOUNT, m_protossTarget.m_colossusCount);
	DDX_Text(pDX, IDC_EDIT_PHOENIXCOUNT, m_protossTarget.m_phoenixCount);
	DDX_Text(pDX, IDC_EDIT_VOIDRAYCOUNT, m_protossTarget.m_voidRayCount);
	DDX_Text(pDX, IDC_EDIT_CARRIERCOUNT, m_protossTarget.m_carrierCount);
	DDX_Text(pDX, IDC_EDIT_MOTHERSHIPCOUNT, m_protossTarget.m_mothershipCount);
}


BEGIN_MESSAGE_MAP(CProtossStateDlg, CDialogEx)
END_MESSAGE_MAP()


// CProtossStateDlg message handlers

// ZergStateDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SCBuildOrderGUI.h"
#include "ZergStateDlg.h"
#include "afxdialogex.h"


// CZergStateDlg dialog

IMPLEMENT_DYNAMIC(CZergStateDlg, CDialogEx)

CZergStateDlg::CZergStateDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CZergStateDlg::IDD, pParent)
	, m_waypointTargetTime(1200)
{
}

CZergStateDlg::~CZergStateDlg()
{
}

void CZergStateDlg::DDX_Check(CDataExchange* pDX, int nIDC, bool &bValue)
{
	BOOL bBigBool = bValue ? TRUE : FALSE;
	::DDX_Check(pDX, nIDC, bBigBool);
	bValue = bBigBool ? true : false;
}

void CZergStateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT_TIMELIMIT, m_waypointTargetTime);

	DDX_Text(pDX, IDC_EDIT_HATCHERYCOUNT, m_zergTarget.m_hatcheryCount);
	DDX_Text(pDX, IDC_EDIT_EXTRACTORCOUNT, m_zergTarget.m_extractorCount);
	DDX_Text(pDX, IDC_EDIT_SPAWNINGPOOLCOUNT, m_zergTarget.m_spawningPoolCount);
	DDX_Text(pDX, IDC_EDIT_CREEPTUMORCOUNT, m_zergTarget.m_creepTumorCount);
	DDX_Text(pDX, IDC_EDIT_EVOLUTIONCHAMBERCOUNT, m_zergTarget.m_evolutionChamberCount);
	DDX_Text(pDX, IDC_EDIT_SPINECRAWLERCOUNT, m_zergTarget.m_spineCrawlerCount);
	DDX_Text(pDX, IDC_EDIT_SPORECRAWLERCOUNT, m_zergTarget.m_sporeCrawlerCount);
	DDX_Text(pDX, IDC_EDIT_ROACHWARRENCOUNT, m_zergTarget.m_roachWarrenCount);
	DDX_Text(pDX, IDC_EDIT_LAIRCOUNT, m_zergTarget.m_lairCount);
	DDX_Text(pDX, IDC_EDIT_HYDRALISKDENCOUNT, m_zergTarget.m_hydraliskDenCount);
	DDX_Text(pDX, IDC_EDIT_BANELINGNESTCOUNT, m_zergTarget.m_banelingNestCount);
	DDX_Text(pDX, IDC_EDIT_SPIRECOUNT, m_zergTarget.m_spireCount);
	DDX_Text(pDX, IDC_EDIT_INFESTATIONPITCOUNT, m_zergTarget.m_infestationPitCount);
	DDX_Text(pDX, IDC_EDIT_NYDUSNETWORKCOUNT, m_zergTarget.m_nydusNetworkCount);
	DDX_Text(pDX, IDC_EDIT_HIVECOUNT, m_zergTarget.m_hiveCount);
	DDX_Text(pDX, IDC_EDIT_ULTRALISKCAVERNCOUNT, m_zergTarget.m_ultraliskCavernCount);
	DDX_Text(pDX, IDC_EDIT_GREATERSPIRECOUNT, m_zergTarget.m_greaterSpireCount);

	DDX_Check(pDX, IDC_CHECK_ADRENALGLANDS, m_zergTarget.m_researchAdrenalGlandsCompleted);
	DDX_Check(pDX, IDC_CHECK_METABOLICBOOST, m_zergTarget.m_researchMetabolicBoostCompleted);
	DDX_Check(pDX, IDC_CHECK_MELEEATTACKSPLUS1, m_zergTarget.m_researchMeleeAttacks1Completed);
	DDX_Check(pDX, IDC_CHECK_MELEEATTACKSPLUS2, m_zergTarget.m_researchMeleeAttacks2Completed);
	DDX_Check(pDX, IDC_CHECK_MELEEATTACKSPLUS3, m_zergTarget.m_researchMeleeAttacks3Completed);
	DDX_Check(pDX, IDC_CHECK_GROUNDCARAPACEPLUS1, m_zergTarget.m_researchGroundCarapace1Completed);
	DDX_Check(pDX, IDC_CHECK_GROUNDCARAPACEPLUS2, m_zergTarget.m_researchGroundCarapace2Completed);
	DDX_Check(pDX, IDC_CHECK_GROUNDCARAPACEPLUS3, m_zergTarget.m_researchGroundCarapace3Completed);
	DDX_Check(pDX, IDC_CHECK_MISSILEATTACKSPLUS1, m_zergTarget.m_researchMissileAttacks1Completed);
	DDX_Check(pDX, IDC_CHECK_MISSILEATTACKSPLUS2, m_zergTarget.m_researchMissileAttacks2Completed);
	DDX_Check(pDX, IDC_CHECK_MISSILEATTACKSPLUS3, m_zergTarget.m_researchMissileAttacks3Completed);
	DDX_Check(pDX, IDC_CHECK_GLIALRECONSTITUTION, m_zergTarget.m_researchGlialReconstitutionCompleted);
	DDX_Check(pDX, IDC_CHECK_TUNNELINGCLAWS, m_zergTarget.m_researchTunnelingClawsCompleted);
	DDX_Check(pDX, IDC_CHECK_CENTRIFUGALHOOKS, m_zergTarget.m_researchCentrifugalHooksCompleted);
	DDX_Check(pDX, IDC_CHECK_BURROW, m_zergTarget.m_researchBurrowCompleted);
	DDX_Check(pDX, IDC_CHECK_PNEUMATICCARAPACE, m_zergTarget.m_researchPneumaticCarapaceCompleted);
	DDX_Check(pDX, IDC_CHECK_VENTRALSACS, m_zergTarget.m_researchVentralSacsCompleted);
	DDX_Check(pDX, IDC_CHECK_GROOVEDSPINES, m_zergTarget.m_researchGroovedSpinesCompleted);
	DDX_Check(pDX, IDC_CHECK_PATHOGENGLANDS, m_zergTarget.m_researchPathogenGlandsCompleted);
	DDX_Check(pDX, IDC_CHECK_NEURALPARASITE, m_zergTarget.m_researchNeuralParasiteCompleted);
	DDX_Check(pDX, IDC_CHECK_FLYERATTACKSPLUS1, m_zergTarget.m_researchFlyerAttacks1Completed);
	DDX_Check(pDX, IDC_CHECK_FLYERATTACKSPLUS2, m_zergTarget.m_researchFlyerAttacks2Completed);
	DDX_Check(pDX, IDC_CHECK_FLYERATTACKSPLUS3, m_zergTarget.m_researchFlyerAttacks3Completed);
	DDX_Check(pDX, IDC_CHECK_FLYERCARAPACEPLUS1, m_zergTarget.m_researchFlyerCarapace1Completed);
	DDX_Check(pDX, IDC_CHECK_FLYERCARAPACEPLUS2, m_zergTarget.m_researchFlyerCarapace2Completed);
	DDX_Check(pDX, IDC_CHECK_FLYERCARAPACEPLUS3, m_zergTarget.m_researchFlyerCarapace3Completed);
	DDX_Check(pDX, IDC_CHECK_CHITINOUSPLATING, m_zergTarget.m_researchChitinousPlatingCompleted);

	DDX_Text(pDX, IDC_EDIT_DRONECOUNT, m_zergTarget.m_droneCount);
	//DDX_Check(pDX, IDC_CHECK_CONSTANTPROBEPRODUCTION, m_zergTarget.m_constantProbeProduction);
	DDX_Text(pDX, IDC_EDIT_OVERLORDCOUNT, m_zergTarget.m_overlordCount);
	DDX_Text(pDX, IDC_EDIT_QUEENCOUNT, m_zergTarget.m_queenCount);
	DDX_Text(pDX, IDC_EDIT_ZERGLINGCOUNT, m_zergTarget.m_zerglingCount);
	DDX_Text(pDX, IDC_EDIT_BANELINGCOUNT, m_zergTarget.m_banelingCount);
	DDX_Text(pDX, IDC_EDIT_ROACHCOUNT, m_zergTarget.m_roachCount);
	DDX_Text(pDX, IDC_EDIT_HYDRALISKCOUNT, m_zergTarget.m_hydraliskCount);
	DDX_Text(pDX, IDC_EDIT_OVERSEERCOUNT, m_zergTarget.m_overseerCount);
	DDX_Text(pDX, IDC_EDIT_INFESTORCOUNT, m_zergTarget.m_infestorCount);
	DDX_Text(pDX, IDC_EDIT_MUTALISKCOUNT, m_zergTarget.m_mutaliskCount);
	DDX_Text(pDX, IDC_EDIT_CORRUPTORCOUNT, m_zergTarget.m_corruptorCount);
	DDX_Text(pDX, IDC_EDIT_ULTRALISKCOUNT, m_zergTarget.m_ultraliskCount);
	DDX_Text(pDX, IDC_EDIT_BROODLORDCOUNT, m_zergTarget.m_broodlordCount);
}


BEGIN_MESSAGE_MAP(CZergStateDlg, CDialogEx)
END_MESSAGE_MAP()


// CZergStateDlg message handlers

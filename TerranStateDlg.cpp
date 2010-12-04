// TerranStateDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SCBuildOrderGUI.h"
#include "TerranStateDlg.h"
#include "afxdialogex.h"


// CTerranStateDlg dialog

IMPLEMENT_DYNAMIC(CTerranStateDlg, CDialogEx)

CTerranStateDlg::CTerranStateDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTerranStateDlg::IDD, pParent)
	, m_waypointTargetTime(1200)
{
}

CTerranStateDlg::~CTerranStateDlg()
{
}

void CTerranStateDlg::DDX_Check(CDataExchange* pDX, int nIDC, bool &bValue)
{
	BOOL bBigBool = bValue ? TRUE : FALSE;
	::DDX_Check(pDX, nIDC, bBigBool);
	bValue = bBigBool ? true : false;
}

void CTerranStateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TIMELIMIT, m_waypointTargetTime);
	DDX_Text(pDX, IDC_EDIT_COMMANDCENTERCOUNT, m_terranTarget.m_commandCenterCount);
	DDX_Text(pDX, IDC_EDIT_SUPPLYDEPOTCOUNT, m_terranTarget.m_supplyDepotCount);
	DDX_Text(pDX, IDC_EDIT_REFINERYCOUNT, m_terranTarget.m_refineryCount);
	DDX_Text(pDX, IDC_EDIT_BARRACKSCOUNT, m_terranTarget.m_barracksCount);
	DDX_Text(pDX, IDC_EDIT_ORBITALCOMMANDCOUNT, m_terranTarget.m_orbitalCommandCount);
	DDX_Text(pDX, IDC_EDIT_ENGINEERINGBAYCOUNT, m_terranTarget.m_engineeringBayCount);
	DDX_Text(pDX, IDC_EDIT_BUNKERCOUNT, m_terranTarget.m_bunkerCount);
	DDX_Text(pDX, IDC_EDIT_MISSILETURRETCOUNT, m_terranTarget.m_missileTurretCount);
	DDX_Text(pDX, IDC_EDIT_SENSORTOWERCOUNT, m_terranTarget.m_sensorTowerCount);
	DDX_Text(pDX, IDC_EDIT_PLANETARYFORTRESSCOUNT, m_terranTarget.m_planetaryFortressCount);
	DDX_Text(pDX, IDC_EDIT_GHOSTACADEMYCOUNT, m_terranTarget.m_ghostAcademyCount);
	DDX_Text(pDX, IDC_EDIT_FACTORYCOUNT, m_terranTarget.m_factoryCount);
	DDX_Text(pDX, IDC_EDIT_ARMORYCOUNT, m_terranTarget.m_armoryCount);
	DDX_Text(pDX, IDC_EDIT_STARPORTCOUNT, m_terranTarget.m_starportCount);
	DDX_Text(pDX, IDC_EDIT_FUSIONCORECOUNT, m_terranTarget.m_fusionCoreCount);

	DDX_Text(pDX, IDC_EDIT_TECHLABCOUNT, m_terranTarget.m_techLabCount);
	DDX_Text(pDX, IDC_EDIT_REACTORCOUNT, m_terranTarget.m_reactorCount);

	DDX_Text(pDX, IDC_EDIT_SCVCOUNT, m_terranTarget.m_scvCount);
	DDX_Check(pDX, IDC_CHECK_CONSTANTSCVPRODUCTION, m_terranTarget.m_constantSCVProduction);
	DDX_Text(pDX, IDC_EDIT_MARINECOUNT, m_terranTarget.m_marineCount);
	DDX_Text(pDX, IDC_EDIT_MARAUDERCOUNT, m_terranTarget.m_marauderCount);
	DDX_Text(pDX, IDC_EDIT_REAPERCOUNT, m_terranTarget.m_reaperCount);
	DDX_Text(pDX, IDC_EDIT_GHOSTCOUNT, m_terranTarget.m_ghostCount);
	DDX_Text(pDX, IDC_EDIT_HELLIONCOUNT, m_terranTarget.m_hellionCount);
	DDX_Text(pDX, IDC_EDIT_SIEGETANKCOUNT, m_terranTarget.m_siegeTankCount);
	DDX_Text(pDX, IDC_EDIT_THORCOUNT, m_terranTarget.m_thorCount);
	DDX_Text(pDX, IDC_EDIT_VIKINGCOUNT, m_terranTarget.m_vikingCount);
	DDX_Text(pDX, IDC_EDIT_MEDIVACCOUNT, m_terranTarget.m_medivacCount);
	DDX_Text(pDX, IDC_EDIT_RAVENCOUNT, m_terranTarget.m_ravenCount);
	DDX_Text(pDX, IDC_EDIT_BANSHEECOUNT, m_terranTarget.m_bansheeCount);
	DDX_Text(pDX, IDC_EDIT_BATTLECRUISERCOUNT, m_terranTarget.m_battleCruiserCount);

	DDX_Check(pDX, IDC_CHECK_STIMPACK, m_terranTarget.m_researchStimpackCompleted);
	DDX_Check(pDX, IDC_CHECK_COMBATSHIELD, m_terranTarget.m_researchCombatShieldCompleted);
	DDX_Check(pDX, IDC_CHECK_NITROPACKS, m_terranTarget.m_researchNitroPacksCompleted);
	DDX_Check(pDX, IDC_CHECK_CONCUSSIVESHELLS, m_terranTarget.m_researchConcussiveShellsCompleted);
	DDX_Check(pDX, IDC_CHECK_INFANTRYWEAPONSPLUS1, m_terranTarget.m_researchInfantryWeapons1Completed);
	DDX_Check(pDX, IDC_CHECK_INFANTRYWEAPONSPLUS2, m_terranTarget.m_researchInfantryWeapons2Completed);
	DDX_Check(pDX, IDC_CHECK_INFANTRYWEAPONSPLUS3, m_terranTarget.m_researchInfantryWeapons3Completed);
	DDX_Check(pDX, IDC_CHECK_INFANTRYARMORPLUS1, m_terranTarget.m_researchInfantryArmor1Completed);
	DDX_Check(pDX, IDC_CHECK_INFANTRYARMORPLUS2, m_terranTarget.m_researchInfantryArmor2Completed);
	DDX_Check(pDX, IDC_CHECK_INFANTRYARMORPLUS3, m_terranTarget.m_researchInfantryArmor3Completed);
	DDX_Check(pDX, IDC_CHECK_BUILDINGARMOR, m_terranTarget.m_researchBuildingArmorCompleted);
	DDX_Check(pDX, IDC_CHECK_HISECAUTOTRACKING, m_terranTarget.m_researchHiSecAutoTrackingCompleted);
	DDX_Check(pDX, IDC_CHECK_NEOSTEELFRAME, m_terranTarget.m_researchNeoSteelFrameCompleted);
	DDX_Check(pDX, IDC_CHECK_MOEBIUSREACTOR, m_terranTarget.m_researchMoebiusReactorCompleted);
	DDX_Check(pDX, IDC_CHECK_PERSONALCLOAKING, m_terranTarget.m_researchPersonalCloakingCompleted);
	DDX_Check(pDX, IDC_CHECK_INFERNALPREIGNITER, m_terranTarget.m_researchInfernalPreIgniterCompleted);
	DDX_Check(pDX, IDC_CHECK_SIEGETECH, m_terranTarget.m_researchSiegeTechCompleted);
	DDX_Check(pDX, IDC_CHECK_DURABLEMATERIALS, m_terranTarget.m_researchDurableMaterialsCompleted);
	DDX_Check(pDX, IDC_CHECK_250MMSTRIKECANNONS, m_terranTarget.m_research250mmStrikeCannonsCompleted);
	DDX_Check(pDX, IDC_CHECK_VEHICLEWEAPONSPLUS1, m_terranTarget.m_researchVehicleWeapons1Completed);
	DDX_Check(pDX, IDC_CHECK_VEHICLEWEAPONSPLUS2, m_terranTarget.m_researchVehicleWeapons2Completed);
	DDX_Check(pDX, IDC_CHECK_VEHICLEWEAPONSPLUS3, m_terranTarget.m_researchVehicleWeapons3Completed);
	DDX_Check(pDX, IDC_CHECK_VEHICLEPLATINGPLUS1, m_terranTarget.m_researchVehiclePlating1Completed);
	DDX_Check(pDX, IDC_CHECK_VEHICLEPLATINGPLUS2, m_terranTarget.m_researchVehiclePlating2Completed);
	DDX_Check(pDX, IDC_CHECK_VEHICLEPLATINGPLUS3, m_terranTarget.m_researchVehiclePlating3Completed);
	DDX_Check(pDX, IDC_CHECK_SHIPWEAPONSPLUS1, m_terranTarget.m_researchShipWeapons1Completed);
	DDX_Check(pDX, IDC_CHECK_SHIPWEAPONSPLUS2, m_terranTarget.m_researchShipWeapons2Completed);
	DDX_Check(pDX, IDC_CHECK_SHIPWEAPONSPLUS3, m_terranTarget.m_researchShipWeapons3Completed);
	DDX_Check(pDX, IDC_CHECK_SHIPPLATINGPLUS1, m_terranTarget.m_researchShipPlating1Completed);
	DDX_Check(pDX, IDC_CHECK_SHIPPLATINGPLUS2, m_terranTarget.m_researchShipPlating2Completed);
	DDX_Check(pDX, IDC_CHECK_SHIPPLATINGPLUS3, m_terranTarget.m_researchShipPlating3Completed);
	DDX_Check(pDX, IDC_CHECK_CORVIDREACTOR, m_terranTarget.m_researchCorvidReactorCompleted);
	DDX_Check(pDX, IDC_CHECK_CADUCEUSREACTOR, m_terranTarget.m_researchCaduceusReactorCompleted);
	DDX_Check(pDX, IDC_CHECK_SEEKERMISSILE, m_terranTarget.m_researchSeekerMissileCompleted);
	DDX_Check(pDX, IDC_CHECK_CLOAKINGFIELD, m_terranTarget.m_researchCloakingFieldCompleted);
	DDX_Check(pDX, IDC_CHECK_BEHEMOTHREACTOR, m_terranTarget.m_researchBehemothReactorCompleted);
	DDX_Check(pDX, IDC_CHECK_WEAPONREFIT, m_terranTarget.m_researchWeaponRefitCompleted);

}


BEGIN_MESSAGE_MAP(CTerranStateDlg, CDialogEx)
END_MESSAGE_MAP()


// CTerranStateDlg message handlers

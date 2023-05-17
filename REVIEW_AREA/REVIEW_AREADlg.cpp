
// REVIEW_AREADlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "REVIEW_AREA.h"
#include "REVIEW_AREADlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

HWND hCommWnd;
HANDLE hStage;

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CREVIEWAREADlg 대화 상자



CREVIEWAREADlg::CREVIEWAREADlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_REVIEW_AREA_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CREVIEWAREADlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC_LOGO, m_pic_logo);
	DDX_Control(pDX, IDC_PIC_START, m_pic_start);
	DDX_Control(pDX, IDC_PIC_STOP, m_pic_stop);
	DDX_Control(pDX, IDC_EDIT_UPPER_LIGHT, m_edit_upper_light);
	DDX_Control(pDX, IDC_EDIT_SIDE_LIGHT, m_edit_side_light);
	DDX_Control(pDX, IDC_TAB_WINDOWS, m_tab_windows);
	DDX_Control(pDX, IDC_SLD_UPPER, m_sld_upper);
	DDX_Control(pDX, IDC_SLD_SIDE, m_sld_side);
	DDX_Control(pDX, IDC_BTN_UPPER_CAM, m_btn_upper_cam);
	DDX_Control(pDX, IDC_BTN_SIDE_CAM, m_btn_side_cam);
	DDX_Control(pDX, IDC_BTN_ALL_CAM, m_btn_all_cam);
	DDX_Control(pDX, IDC_BTN_MAIN_STAGE_X, m_btn_main_stage_x);
	DDX_Control(pDX, IDC_BTN_MAIN_STAGE_Y, m_btn_main_stage_y);
	DDX_Control(pDX, IDC_BTN_SUB_STAGE_X, m_btn_sub_stage_x);
	DDX_Control(pDX, IDC_BTN_ALL_STAGE, m_btn_all_stage);
	DDX_Control(pDX, IDC_BTN_UPPER_LIGHT, m_btn_upper_light);
	DDX_Control(pDX, IDC_BTN_SIDE_LIGHT, m_btn_side_light);
	DDX_Control(pDX, IDC_BTN_UPPER_AF, m_btn_upper_af);
	DDX_Control(pDX, IDC_BTN_SIDE_AF, m_btn_side_af);
	DDX_Control(pDX, IDC_PIC_LOGIN, m_pic_login);
	DDX_Control(pDX, IDC_CMB_AF_STEP, m_cmb_af_step);
	DDX_Control(pDX, IDC_SPIN_AF, m_spin_af);
	DDX_Control(pDX, IDC_CHK_UPPER_AF, m_chk_upper_af);
	DDX_Control(pDX, IDC_CHK_SIDE_AF, m_chk_side_af);
	DDX_Control(pDX, IDC_PIC_UPPER_AF, m_pic_upper_af);
	DDX_Control(pDX, IDC_PIC_SIDE_AF, m_pic_side_af);
}

BEGIN_MESSAGE_MAP(CREVIEWAREADlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BTN_UPPER_CAM, &CREVIEWAREADlg::OnBnClickedBtnUpperCam)
	ON_BN_CLICKED(IDC_BTN_SIDE_CAM, &CREVIEWAREADlg::OnBnClickedBtnSideCam)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_WINDOWS, &CREVIEWAREADlg::OnSelchangeTabWindows)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLD_UPPER, &CREVIEWAREADlg::OnReleasedcaptureSldUpper)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLD_SIDE, &CREVIEWAREADlg::OnReleasedcaptureSldSide)
	ON_EN_CHANGE(IDC_EDIT_UPPER_LIGHT, &CREVIEWAREADlg::OnChangeEditUpperLight)
	ON_EN_CHANGE(IDC_EDIT_SIDE_LIGHT, &CREVIEWAREADlg::OnChangeEditSideLight)
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_BTN_ALL_CAM, &CREVIEWAREADlg::OnBnClickedBtnAllCam)
	ON_BN_CLICKED(IDC_BTN_MAIN_STAGE_X, &CREVIEWAREADlg::OnBnClickedBtnMainStageX)
	ON_BN_CLICKED(IDC_BTN_MAIN_STAGE_Y, &CREVIEWAREADlg::OnBnClickedBtnMainStageY)
	ON_BN_CLICKED(IDC_BTN_SUB_STAGE_X, &CREVIEWAREADlg::OnBnClickedBtnSubStageX)
	ON_BN_CLICKED(IDC_BTN_ALL_STAGE, &CREVIEWAREADlg::OnBnClickedBtnAllStage)
	ON_WM_CTLCOLOR()
	ON_WM_DESTROY()
	ON_WM_VSCROLL()
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_BTN_UPPER_LIGHT, &CREVIEWAREADlg::OnBnClickedBtnUpperLight)
	ON_BN_CLICKED(IDC_BTN_SIDE_LIGHT, &CREVIEWAREADlg::OnBnClickedBtnSideLight)
	ON_BN_CLICKED(IDC_BTN_UPPER_AF, &CREVIEWAREADlg::OnBnClickedBtnUpperAf)
	ON_BN_CLICKED(IDC_BTN_SIDE_AF, &CREVIEWAREADlg::OnBnClickedBtnSideAf)
	ON_COMMAND(ID_SAVE_CAM_UPPER, &CREVIEWAREADlg::OnSaveCamUpper)
	ON_COMMAND(ID_SAVE_CAM_SIDE, &CREVIEWAREADlg::OnSaveCamSide)
	ON_COMMAND(ID_SAVE_CAM_ALL, &CREVIEWAREADlg::OnSaveCamAll)
	ON_COMMAND(ID_FILE_LOAD, &CREVIEWAREADlg::OnFileLoad)
	ON_COMMAND(ID_FILE_EXIT, &CREVIEWAREADlg::OnFileExit)
	ON_COMMAND(ID_GRAPHIC_ACTIVE, &CREVIEWAREADlg::OnGraphicActive)
	ON_COMMAND(ID_GRAPHIC_LINE, &CREVIEWAREADlg::OnGraphicLine)
	ON_COMMAND(ID_GRAPHIC_RECTANGLE, &CREVIEWAREADlg::OnGraphicRectangle)
	ON_COMMAND(ID_GRAPHIC_CIRCLE, &CREVIEWAREADlg::OnGraphicCircle)
	ON_COMMAND(ID_GRAPHIC_EDGE, &CREVIEWAREADlg::OnGraphicEdge)
	ON_COMMAND(ID_GRAPHIC_EDGE_2, &CREVIEWAREADlg::OnGraphicEdge_2)
	ON_COMMAND(ID_COMPORT_CONNECT, &CREVIEWAREADlg::OnComportConnect)
	ON_COMMAND(ID_SYSTEM_LOGIN, &CREVIEWAREADlg::OnSystemLogin)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_AF, &CREVIEWAREADlg::OnDeltaposSpinAf)
	ON_BN_CLICKED(IDC_CHK_UPPER_AF, &CREVIEWAREADlg::OnBnClickedChkUpperAf)
	ON_BN_CLICKED(IDC_CHK_SIDE_AF, &CREVIEWAREADlg::OnBnClickedChkSideAf)
	ON_BN_CLICKED(IDC_BTN_AF, &CREVIEWAREADlg::OnBnClickedBtnAf)
	ON_BN_CLICKED(IDC_BTN_STOP, &CREVIEWAREADlg::OnBnClickedBtnStop)
	ON_BN_CLICKED(IDC_BTN_MOVE_STOP, &CREVIEWAREADlg::OnBnClickedBtnMoveStop)
END_MESSAGE_MAP()


// CREVIEWAREADlg 메시지 처리기

BOOL CREVIEWAREADlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	bg_brush.CreateSolidBrush(RGB(255, 255, 255));

	int iScreenWidth = GetSystemMetrics(SM_CXSCREEN);
	int iScreenHeight = GetSystemMetrics(SM_CYSCREEN);

	int cam_width = 2048;
	int cam_height = 2048;

	int cam_mag = 4;

	cam_width = cam_width / cam_mag;
	cam_width = cam_width / cam_mag;

	SetWindowPos(&wndTop, -10, 0, 1870, 1090, SWP_HIDEWINDOW);

	GetDlgItem(IDC_PIC_LOGO)->MoveWindow(1650, 10, 200, 40);
	GetDlgItem(IDC_STATIC_DAY)->MoveWindow(1530, 70, 170, 30);
	GetDlgItem(IDC_STATIC_TIME)->MoveWindow(1720, 70, 120, 30);
	GetDlgItem(IDC_STATIC_RECIPE_NAME)->MoveWindow(1600, 120, 100, 30);
	GetDlgItem(IDC_STATIC_RECIPE)->MoveWindow(1720, 120, 120, 30);

	GetDlgItem(IDC_BTN_UPPER_CAM)->MoveWindow(1600, 170, 30, 30);
	GetDlgItem(IDC_BTN_SIDE_CAM)->MoveWindow(1630, 170, 30, 30);
	GetDlgItem(IDC_BTN_ALL_CAM)->MoveWindow(1660, 170, 30, 30);

	GetDlgItem(IDC_BTN_UPPER_LIGHT)->MoveWindow(1705, 170, 30, 30);
	GetDlgItem(IDC_BTN_SIDE_LIGHT)->MoveWindow(1735, 170, 30, 30);
	GetDlgItem(IDC_BTN_UPPER_AF)->MoveWindow(1780, 170, 30, 30);
	GetDlgItem(IDC_BTN_SIDE_AF)->MoveWindow(1810, 170, 30, 30);

	GetDlgItem(IDC_BTN_MAIN_STAGE_X)->MoveWindow(1720, 210, 30, 30);
	GetDlgItem(IDC_BTN_MAIN_STAGE_Y)->MoveWindow(1750, 210, 30, 30);
	GetDlgItem(IDC_BTN_SUB_STAGE_X)->MoveWindow(1780, 210, 30, 30);
	GetDlgItem(IDC_BTN_ALL_STAGE)->MoveWindow(1810, 210, 30, 30);

	GetDlgItem(IDC_STATIC_LOGIN)->MoveWindow(1720, 260, 90, 30);
	GetDlgItem(IDC_STATIC_START)->MoveWindow(1720, 300, 90, 30);
	GetDlgItem(IDC_STATIC_STOP)->MoveWindow(1720, 340, 90, 30);
	GetDlgItem(IDC_PIC_LOGIN)->MoveWindow(1820, 268, 20, 20);
	GetDlgItem(IDC_PIC_START)->MoveWindow(1820, 308, 20, 20);
	GetDlgItem(IDC_PIC_STOP)->MoveWindow(1820, 348, 20, 20);

	GetDlgItem(IDC_GRP_LIGHT)->MoveWindow(1670, 400, 170, 160);
	GetDlgItem(IDC_GRP_UPPER_LIGHT)->MoveWindow(1680, 420, 70, 130);
	GetDlgItem(IDC_SLD_UPPER)->MoveWindow(1705, 440, 20, 80);
	GetDlgItem(IDC_EDIT_UPPER_LIGHT)->MoveWindow(1695, 520, 40, 20);
	GetDlgItem(IDC_GRP_SIDE_LIGHT)->MoveWindow(1760, 420, 70, 130);
	GetDlgItem(IDC_SLD_SIDE)->MoveWindow(1785, 440, 20, 80);
	GetDlgItem(IDC_EDIT_SIDE_LIGHT)->MoveWindow(1775, 520, 40, 20);
	
	GetDlgItem(IDC_GRP_AF)->MoveWindow(1440, 300, 220, 260);
	GetDlgItem(IDC_CHK_UPPER_AF)->MoveWindow(1470, 330, 80, 20);
	GetDlgItem(IDC_CHK_SIDE_AF)->MoveWindow(1470, 360, 80, 20);
	GetDlgItem(IDC_CMB_AF_STEP)->MoveWindow(1570, 330, 60, 20);
	GetDlgItem(IDC_SPIN_AF)->MoveWindow(1470, 390, 60, 30);
	GetDlgItem(IDC_BTN_MOVE_STOP)->MoveWindow(1570, 390, 60, 30);
	GetDlgItem(IDC_BTN_ORIGIN)->MoveWindow(1570, 430, 60, 30);
	GetDlgItem(IDC_BTN_AF)->MoveWindow(1470, 470, 60, 30);
	GetDlgItem(IDC_BTN_STOP)->MoveWindow(1570, 470, 60, 30);
	GetDlgItem(IDC_STATIC_UPPER_AF)->MoveWindow(1470, 520, 40, 20);
	GetDlgItem(IDC_PIC_UPPER_AF)->MoveWindow(1520, 520, 30, 30);
	GetDlgItem(IDC_STATIC_SIDE_AF)->MoveWindow(1570, 520, 40, 20);
	GetDlgItem(IDC_PIC_SIDE_AF)->MoveWindow(1620, 520, 30, 30);
	
	
	
	GetDlgItem(IDC_CHK_UPPER_AF)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHK_SIDE_AF)->EnableWindow(FALSE);

	GetDlgItem(IDC_TAB_WINDOWS)->MoveWindow(0, 0, iScreenWidth - 470, 1040);

	HFONT valueFont;
	valueFont = CreateFont(25, 10, 0, 0, FW_BOLD, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_MODERN, _T("맑은 고딕"));

	GetDlgItem(IDC_STATIC_DAY)->SendMessage(WM_SETFONT, (WPARAM)valueFont, (LPARAM)TRUE);
	GetDlgItem(IDC_STATIC_TIME)->SendMessage(WM_SETFONT, (WPARAM)valueFont, (LPARAM)TRUE);
	GetDlgItem(IDC_STATIC_RECIPE_NAME)->SendMessage(WM_SETFONT, (WPARAM)valueFont, (LPARAM)TRUE);
	GetDlgItem(IDC_STATIC_RECIPE)->SendMessage(WM_SETFONT, (WPARAM)valueFont, (LPARAM)TRUE);
	GetDlgItem(IDC_STATIC_LOGIN)->SendMessage(WM_SETFONT, (WPARAM)valueFont, (LPARAM)TRUE);
	GetDlgItem(IDC_STATIC_START)->SendMessage(WM_SETFONT, (WPARAM)valueFont, (LPARAM)TRUE);
	GetDlgItem(IDC_STATIC_STOP)->SendMessage(WM_SETFONT, (WPARAM)valueFont, (LPARAM)TRUE);

	m_cam_off.LoadBitmapW(IDB_BITMAP_CAM_OFF);
	m_cam_on.LoadBitmapW(IDB_BITMAP_CAM_ON);

	m_af_off.LoadBitmapW(IDB_BITMAP_AF_OFF);
	m_af_on.LoadBitmapW(IDB_BITMAP_AF_ON);

	m_light_off.LoadBitmapW(IDB_BITMAP_LIGHT_OFF);
	m_light_on.LoadBitmapW(IDB_BITMAP_LIGHT_ON);

	m_stage_off.LoadBitmapW(IDB_BITMAP_STAGE_OFF);
	m_stage_on.LoadBitmapW(IDB_BITMAP_STAGE_ON);

	m_btn_upper_cam.SetBitmap(m_cam_off);
	m_btn_side_cam.SetBitmap(m_cam_off);
	m_btn_all_cam.SetBitmap(m_cam_off);

	m_btn_upper_light.SetBitmap(m_light_off);
	m_btn_side_light.SetBitmap(m_light_off);

	m_btn_upper_af.SetBitmap(m_af_off);
	m_btn_side_af.SetBitmap(m_af_off);

	m_btn_main_stage_x.SetBitmap(m_stage_off);
	m_btn_main_stage_y.SetBitmap(m_stage_off);
	m_btn_sub_stage_x.SetBitmap(m_stage_off);
	m_btn_all_stage.SetBitmap(m_stage_off);

	

	m_logo.LoadBitmapW(IDB_BITMAP_LOGO);
	m_green_led.LoadBitmapW(IDB_BITMAP_GREEN_LED);
	m_red_led.LoadBitmapW(IDB_BITMAP_RED_LED);

	m_pic_logo.SetBitmap(m_logo);
	m_pic_login.SetBitmap(m_red_led);
	m_pic_start.SetBitmap(m_red_led);
	m_pic_stop.SetBitmap(m_green_led);


	m_pic_upper_af.SetBitmap(m_red_led);
	m_pic_side_af.SetBitmap(m_red_led);
	// TAB WINDOWS
	m_tab_windows.InsertItem(0, _T("AUTO"));
	m_tab_windows.InsertItem(1, _T("MANUAL"));
	m_tab_windows.InsertItem(2, _T("ALARM"));

	m_tab_windows.SetCurSel(0);

	// Tab control
	dlg_auto = new DIALOG_AUTO;
	dlg_auto->Create(IDD_DIALOG_AUTO, this);
	dlg_auto->MoveWindow(0, 0, iScreenWidth - 500, 1050);
	dlg_auto->ShowWindow(SW_SHOW);
	dlg_auto->hStage_auto = hStage;

	dlg_manual = new DIALOG_MANUAL;
	dlg_manual->Create(IDD_DIALOG_MANUAL, this);
	dlg_manual->MoveWindow(0, 0, iScreenWidth - 500, 1025);
	dlg_manual->ShowWindow(SW_HIDE);
	dlg_manual->hStage_manual = hStage;

	dlg_history = new DIALOG_HISTORY;
	dlg_history->Create(IDD_DIALOG_HISTORY, this);
	dlg_history->MoveWindow(0, 0, iScreenWidth - 500, 1025);
	dlg_history->ShowWindow(SW_HIDE);

	dlg_alarm = new DIALOG_ALARM;
	dlg_alarm->Create(IDD_DIALOG_ALARM, this);
	dlg_alarm->MoveWindow(0, 0, iScreenWidth - 500, 1025);
	dlg_alarm->ShowWindow(SW_HIDE);

	dlg_setting = new DIALOG_SETTING;
	dlg_setting->Create(IDD_DIALOG_SETTING, this);
	dlg_setting->MoveWindow(1440, 570, 400, 400);
	dlg_setting->ShowWindow(SW_SHOW);

	GetDlgItem(IDCANCEL)->MoveWindow(1800, 980, 40, 40);


	dlg_auto->m_edit_tacktime_process.SetWindowTextW(_T("0"));
	dlg_auto->m_edit_tacktime_align.SetWindowTextW(_T("0"));
	dlg_auto->m_edit_tacktime_inspection.SetWindowTextW(_T("0"));
	dlg_auto->m_edit_tacktime_judge.SetWindowTextW(_T("0"));
	dlg_auto->m_edit_tacktime_unloading.SetWindowTextW(_T("0"));
	dlg_auto->m_edit_tacktime_total.SetWindowTextW(_T("0"));

	// Stage

	//hStage = acsc_OpenCommEthernet("10.0.0.100", 701);
	hStage = acsc_OpenCommSimulator();
	// Stage_X : ACSC_AXIS_4
	// Stage_Y : ACSC_AXIS_0
	// Sub_X : ACSC_AXIS_10

	acsc_GetMotorState(hStage, ACSC_AXIS_4, &stage_main_x_Status, NULL);
	acsc_GetMotorState(hStage, ACSC_AXIS_0, &stage_main_y_Status, NULL);
	acsc_GetMotorState(hStage, ACSC_AXIS_10, &stage_sub_x_Status, NULL);

	if (stage_main_x_Status != 4194321)	//4194321
	{
		dlg_auto->check_alarm = 1;
		dlg_auto->displayAlarm(12);
	}

	if (stage_main_y_Status != 4194321)
	{
		dlg_auto->check_alarm = 1;
		dlg_auto->displayAlarm(13);
	}

	if (stage_sub_x_Status != 4194321)
	{
		dlg_auto->check_alarm = 1;
		dlg_auto->displayAlarm(14);
	}

	// thread
	Status = NULL;
	Status = AfxBeginThread(Status_Thread, this);

	// light
	m_sld_upper.SetRange(0, 255);
	m_sld_side.SetRange(0, 255);

	m_sld_upper.SetRangeMin(0);
	m_sld_side.SetRangeMin(0);

	m_sld_upper.SetRangeMax(255);
	m_sld_side.SetRangeMax(255);

	m_sld_upper.SetTicFreq(1);
	m_sld_side.SetTicFreq(10);

	m_sld_upper.SetLineSize(1);
	m_sld_side.SetLineSize(1);

	m_sld_upper.SetPageSize(10);
	m_sld_side.SetPageSize(10);

	upper_light_comport.OpenPort(byIndexComPort(6), byIndexBaud(1), byIndexData(3), byIndexParity(0), byIndexStop(0));
	side_light_comport.OpenPort(byIndexComPort(7), byIndexBaud(1), byIndexData(3), byIndexParity(0), byIndexStop(0));

	BYTE sendUpperLight[12] = { 'S','E','T',' ','C','U','R',' ','1', '8', '0','\r' };

	upper_light_comport.WriteComm(sendUpperLight, sizeof(sendUpperLight));

	BYTE SendSideLight[13] = { 'S','E','T',' ','C','U','R',' ','1', '1', '8', '0','\r' };
	side_light_comport.WriteComm(SendSideLight, sizeof(SendSideLight));

	m_edit_upper_light.SetWindowTextW(_T("80"));
	m_edit_side_light.SetWindowTextW(_T("180"));

	m_sld_upper.EnableWindow(TRUE);
	m_sld_side.EnableWindow(TRUE);

	m_edit_upper_light.EnableWindow(TRUE);
	m_edit_side_light.EnableWindow(TRUE);


	//upper_af_comport.OpenPort(byIndexComPort(8), byIndexBaud(1), byIndexData(3), byIndexParity(0), byIndexStop(0));
	//side_af_comport.OpenPort(byIndexComPort(9), byIndexBaud(1), byIndexData(3), byIndexParity(0), byIndexStop(0));

	// 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.

	GetDlgItem(IDC_STATIC_START)->SetWindowTextW(_T("START"));
	GetDlgItem(IDC_STATIC_STOP)->SetWindowTextW(_T("STOP"));


	TCHAR path[_MAX_PATH];
	GetModuleFileName(NULL, path, sizeof path);

	strPath = path;
	int i = strPath.ReverseFind('6');//실행 파일 이름을 지우기 위해서 왼쪽에 있는 '/'를 찾는다.
	//int i = strPath.Find(_T("REVIEW_AREA"));//실행 파일 이름을 지우기 위해서 왼쪽에 있는 '/'를 찾는다.

	strPath = strPath.Left(i - 1);//뒤에 있는 현재 실행 파일 이름을 지운다.
	//strPath = strPath.Left(i);//뒤에 있는 현재 실행 파일 이름을 지운다.

	strPath = strPath + _T("REVIEW_AREA\\");

	dlg_auto->file_path = strPath;

	display_check_graphic = 0;
	display_check_upper = 0;
	display_check_side = 0;

	CMenu* hMenu = GetMenu();

	hMenu->CheckMenuItem(ID_LINE_CROSS, MF_UNCHECKED);

	hMenu->CheckMenuItem(ID_UPPER_LEFT_UP, MF_UNCHECKED);
	hMenu->CheckMenuItem(ID_UPPER_LEFT_DOWN, MF_UNCHECKED);
	hMenu->CheckMenuItem(ID_UPPER_RIGHT_UP, MF_UNCHECKED);
	hMenu->CheckMenuItem(ID_UPPER_RIGHT_DOWN, MF_UNCHECKED);

	hMenu->CheckMenuItem(ID_SIDE_LEFT_UP, MF_UNCHECKED);
	hMenu->CheckMenuItem(ID_SIDE_LEFT_DOWN, MF_UNCHECKED);
	hMenu->CheckMenuItem(ID_SIDE_RIGHT_UP, MF_UNCHECKED);
	hMenu->CheckMenuItem(ID_SIDE_RIGHT_DOWN, MF_UNCHECKED);

	check_login = 0;

	upper_ecode = 0;
	side_ecode = 0;

	upper_ecode = ATF_OpenConnection("COM9", 9600);
	side_ecode = ATF_OpenConnection("\\\\.\\COM10", 9600);

	if (upper_ecode == 0)
	{
		m_btn_upper_af.SetBitmap(m_af_on);
		GetDlgItem(IDC_CHK_UPPER_AF)->EnableWindow(TRUE);
	
		m_cmb_af_step.SetCurSel(3);

		m_chk_upper_af.SetCheck(1);
		m_chk_side_af.SetCheck(0);
	}

	if (side_ecode == 0)
	{
		m_btn_side_af.SetBitmap(m_af_on);
		GetDlgItem(IDC_CHK_SIDE_AF)->EnableWindow(TRUE);

		m_cmb_af_step.SetCurSel(3);

		m_chk_upper_af.SetCheck(0);
		m_chk_side_af.SetCheck(1);
	}
	
	selected_af = 2;

	SetTimer(1, 1000, NULL);

	return TRUE;
}

void CREVIEWAREADlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CREVIEWAREADlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
	//CPaintDC dc(this);

	/*CDC memDC;
	//그래프나 도형을 그릴 Bitmap을 생성합니다. (도화지 정도로 보시면 될 거 같습니다.)
	CBitmap bmp, *pOldbmp;
	//메모리 DC를 위의 CPaintDC인 dc에 호환되게 만들어 줍니다.
	memDC.CreateCompatibleDC(&dc);
	//주어진 dc에 호환하는 비트맵을 생성합니다.
	bmp.CreateCompatibleBitmap(&dc, 30, 30);
	//이제 memDC에 생성된 비트맵을 연결 시켜줍니다.
	pOldbmp = memDC.SelectObject(&bmp);

	memDC.SelectObject(pOldbmp);
	bmp.DeleteObject();
	memDC.DeleteDC();
	*/


}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CREVIEWAREADlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



BOOL CREVIEWAREADlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_RETURN) // ENTER키 눌릴 시
			return TRUE;
		else if (pMsg->wParam == VK_ESCAPE) // ESC키 눌릴 시
			return TRUE;
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}


void CREVIEWAREADlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	if (nIDEvent == 1)
	{
		Clock_time = CTime::GetCurrentTime();

		CString month;

		if (Clock_time.GetMonth() == 0)
			month = _T("Jan");

		else if (Clock_time.GetMonth() == 1)
			month = _T("Feb");

		else if (Clock_time.GetMonth() == 2)
			month = _T("Mar");

		else if (Clock_time.GetMonth() == 3)
			month = _T("Apl");

		else if (Clock_time.GetMonth() == 4)
			month = _T("May");

		else if (Clock_time.GetMonth() == 5)
			month = _T("Jun");

		else if (Clock_time.GetMonth() == 6)
			month = _T("Jul");

		else if (Clock_time.GetMonth() == 7)
			month = _T("Aug");

		else if (Clock_time.GetMonth() == 8)
			month = _T("Sep");

		else if (Clock_time.GetMonth() == 9)
			month = _T("Oct");

		else if (Clock_time.GetMonth() == 10)
			month = _T("Nov");

		else if (Clock_time.GetMonth() == 11)
			month = _T("Dec");

		str_year.Format(_T("%04d / "), Clock_time.GetYear());
		str_day.Format(_T(" / %02d"), Clock_time.GetDay());

		str_day = str_year + month + str_day;

		str_clock.Format(_T("%02d : %02d : %02d"), Clock_time.GetHour(), Clock_time.GetMinute(), Clock_time.GetSecond());

		GetDlgItem(IDC_STATIC_DAY)->SetWindowTextW(str_day);
		GetDlgItem(IDC_STATIC_TIME)->SetWindowTextW(str_clock);
	}

	CDialogEx::OnTimer(nIDEvent);
}


CString CREVIEWAREADlg::byIndexComPort(int xPort)
{
	CString PortName = _T("");
	switch (xPort)
	{
	case 0:		PortName = "COM1"; 			break;

	case 1:		PortName = "COM2";			break;

	case 2:		PortName = "COM3"; 			break;

	case 3:		PortName = "COM4";			break;

	case 4:		PortName = "COM5";			break;

	case 5:		PortName = "COM6";			break;

	case 6:		PortName = "COM7";			break;

	case 7:		PortName = "COM8";			break;

	case 8:		PortName = "COM9";		 	break;

	case 9:		PortName = "COM10";			break;
	}

	return PortName;
}


DWORD CREVIEWAREADlg::byIndexBaud(int xBaud)
{
	DWORD dwBaud = 0;
	switch (xBaud)
	{
	case 0:		dwBaud = CBR_4800;		break;

	case 1:		dwBaud = CBR_9600;		break;

	case 2:		dwBaud = CBR_14400;		break;

	case 3:		dwBaud = CBR_19200;		break;

	case 4:		dwBaud = CBR_38400;		break;

	case 5:		dwBaud = CBR_56000;		break;

	case 6:		dwBaud = CBR_57600;		break;

	case 7:		dwBaud = CBR_115200;	break;
	}

	return dwBaud;
}


BYTE CREVIEWAREADlg::byIndexData(int xData)
{
	BYTE byData = 0;
	switch (xData)
	{
	case 0:	byData = 5;			break;

	case 1:	byData = 6;			break;

	case 2:	byData = 7;			break;

	case 3:	byData = 8;			break;
	}

	return byData;
}


BYTE CREVIEWAREADlg::byIndexParity(int xParity)
{
	BYTE byParity = 0;
	switch (xParity)
	{
	case 0:	byParity = NOPARITY;	break;

	case 1:	byParity = ODDPARITY;	break;

	case 2:	byParity = EVENPARITY;	break;
	}

	return byParity;
}


BYTE CREVIEWAREADlg::byIndexStop(int xStop)
{
	BYTE byStop = 0;
	if (xStop == 0)
	{
		byStop = ONESTOPBIT;
	}
	else
	{
		byStop = TWOSTOPBITS;
	}
	return byStop;
}


void CREVIEWAREADlg::OnBnClickedBtnUpperCam()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	dlg_auto->CamUpperStatus();
}


void CREVIEWAREADlg::OnBnClickedBtnSideCam()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	dlg_auto->CamSideStatus();
}


void CREVIEWAREADlg::OnBnClickedBtnAllCam()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	dlg_auto->CamStatus();
}


void CREVIEWAREADlg::OnBnClickedBtnMainStageX()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (stage_main_x_Status == 4194320)			// motor disable
		acsc_Enable(hStage, ACSC_AXIS_4, NULL);

	else if (stage_main_x_Status == 4194321)
		acsc_Disable(hStage, ACSC_AXIS_4, NULL);
}


void CREVIEWAREADlg::OnBnClickedBtnMainStageY()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (stage_main_y_Status == 4194320)			// motor disable
		acsc_Enable(hStage, ACSC_AXIS_0, NULL);

	else if (stage_main_y_Status == 4194321)
		acsc_Disable(hStage, ACSC_AXIS_0, NULL);
}


void CREVIEWAREADlg::OnBnClickedBtnSubStageX()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (stage_sub_x_Status == 4194320)			// motor disable
		acsc_Enable(hStage, ACSC_AXIS_10, NULL);

	else if (stage_sub_x_Status == 4194321)
		acsc_Disable(hStage, ACSC_AXIS_10, NULL);
}


void CREVIEWAREADlg::OnBnClickedBtnAllStage()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	if (stage_main_x_Status == 4194321 && stage_main_y_Status == 4194321 && stage_sub_x_Status == 4194321)
	{
		m_btn_all_stage.SetBitmap(m_stage_off);

		acsc_Disable(hStage, ACSC_AXIS_4, NULL);
		acsc_Disable(hStage, ACSC_AXIS_0, NULL);
		acsc_Disable(hStage, ACSC_AXIS_10, NULL);
	}

	else if (stage_main_x_Status == 4194320 && stage_main_y_Status == 4194320 && stage_sub_x_Status == 4194320)
	{
		m_btn_all_stage.SetBitmap(m_stage_on);

		acsc_Enable(hStage, ACSC_AXIS_4, NULL);
		acsc_Enable(hStage, ACSC_AXIS_0, NULL);
		acsc_Enable(hStage, ACSC_AXIS_10, NULL);
	}

	else
	{
		m_btn_all_stage.SetBitmap(m_stage_on);

		if (stage_main_x_Status == 4194320)			// motor disable
			acsc_Enable(hStage, ACSC_AXIS_4, NULL);

		if (stage_main_y_Status == 4194320)			// motor disable
			acsc_Enable(hStage, ACSC_AXIS_0, NULL);

		if (stage_sub_x_Status == 4194320)			// motor disable
			acsc_Enable(hStage, ACSC_AXIS_10, NULL);
	}
}


void CREVIEWAREADlg::OnSelchangeTabWindows(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	int Tab = m_tab_windows.GetCurSel();

	if (Tab == 0)
	{
		MdispZoom(dlg_auto->area_cam.m_MilDisplay_Upper, dlg_auto->area_cam.ZoomFactor, dlg_auto->area_cam.ZoomFactor);
		MdispZoom(dlg_auto->area_cam.m_MilDisplay_Side, dlg_auto->area_cam.ZoomFactor, dlg_auto->area_cam.ZoomFactor);

		MdispSelectWindow(dlg_auto->area_cam.m_MilDisplay_Upper, dlg_auto->area_cam.m_MilImage_Upper, dlg_auto->m_pic_upper.GetSafeHwnd());
		MdispSelectWindow(dlg_auto->area_cam.m_MilDisplay_Side, dlg_auto->area_cam.m_MilImage_Side, dlg_auto->m_pic_side.GetSafeHwnd());

		dlg_auto->ShowWindow(SW_SHOW);
		dlg_manual->ShowWindow(SW_HIDE);
		dlg_history->ShowWindow(SW_HIDE);
		dlg_alarm->ShowWindow(SW_HIDE);
	}

	else if (Tab == 1)
	{
		double zoomfactor = (double)(dlg_manual->dlg_manual_upper->width_value) / 2048;

		MdispZoom(dlg_auto->area_cam.m_MilDisplay_Upper, zoomfactor, zoomfactor);
		MdispZoom(dlg_auto->area_cam.m_MilDisplay_Side, zoomfactor, zoomfactor);

		MdispSelectWindow(dlg_auto->area_cam.m_MilDisplay_Upper, dlg_auto->area_cam.m_MilImage_Upper, dlg_manual->dlg_manual_upper->m_pic_manual_upper.GetSafeHwnd());
		MdispSelectWindow(dlg_auto->area_cam.m_MilDisplay_Side, dlg_auto->area_cam.m_MilImage_Side, dlg_manual->dlg_manual_side->m_pic_manual_side.GetSafeHwnd());

		dlg_auto->ShowWindow(SW_HIDE);
		dlg_manual->ShowWindow(SW_SHOW);
		dlg_history->ShowWindow(SW_HIDE);
		dlg_alarm->ShowWindow(SW_HIDE);
	}

	else if (Tab == 2)
	{
		dlg_auto->ShowWindow(SW_HIDE);
		dlg_manual->ShowWindow(SW_HIDE);
		//dlg_history->ShowWindow(SW_SHOW);
		//dlg_alarm->ShowWindow(SW_HIDE);
		dlg_alarm->ShowWindow(SW_SHOW);
	}

	/*else if (Tab == 3)
	{
		dlg_auto->ShowWindow(SW_HIDE);
		dlg_manual->ShowWindow(SW_HIDE);
		dlg_history->ShowWindow(SW_HIDE);
		dlg_alarm->ShowWindow(SW_SHOW);
	}*/
	*pResult = 0;
}


void CREVIEWAREADlg::OnReleasedcaptureSldUpper(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


void CREVIEWAREADlg::OnReleasedcaptureSldSide(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


void CREVIEWAREADlg::OnChangeEditUpperLight()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strPos;
	m_edit_upper_light.GetWindowTextW(strPos);

	int nPos = _ttoi(strPos);
	m_sld_upper.SetPos(nPos);

	if (nPos < 10)
	{
		char num_place;

		num_place = strPos[0];

		BYTE SendLight[12] = { 'S','E','T',' ','C','U','R',' ','1', ' ', num_place,'\r' };
		upper_light_comport.WriteComm(SendLight, sizeof(SendLight));
	}


	else if (nPos > 9 && nPos < 100)
	{
		char ten_place, num_place;
		ten_place = strPos[0];
		num_place = strPos[1];

		BYTE SendLight[13] = { 'S','E','T',' ','C','U','R',' ','1', ' ', ten_place, num_place,'\r' };
		upper_light_comport.WriteComm(SendLight, sizeof(SendLight));
	}

	else if (nPos >= 100 && nPos < 256)
	{
		char hun_place, ten_place, num_place;
		hun_place = strPos[0];
		ten_place = strPos[1];
		num_place = strPos[2];

		BYTE SendLight[14] = { 'S','E','T',' ','C','U','R',' ','1', ' ', hun_place, ten_place, num_place,'\r' };
		upper_light_comport.WriteComm(SendLight, sizeof(SendLight));
	}

	else if (nPos >= 256)
	{
		char hun_place, ten_place, num_place;
		hun_place = strPos[0];
		ten_place = strPos[1];
		num_place = strPos[2];

		BYTE SendLight[14] = { 'S','E','T',' ','C','U','R',' ','1', ' ', hun_place, ten_place, num_place,'\r' };
		upper_light_comport.WriteComm(SendLight, sizeof(SendLight));

		m_edit_upper_light.SetWindowTextW(_T("255"));
	}
}


void CREVIEWAREADlg::OnChangeEditSideLight()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strPos;
	m_edit_side_light.GetWindowTextW(strPos);

	int nPos = _ttoi(strPos);
	m_sld_side.SetPos(nPos);

	if (nPos < 10)
	{
		char num_place;

		num_place = strPos[0];

		BYTE SendLight[12] = { 'S','E','T',' ','C','U','R',' ','1', ' ', num_place,'\r' };
		side_light_comport.WriteComm(SendLight, sizeof(SendLight));
	}


	else if (nPos > 9 && nPos < 100)
	{
		char ten_place, num_place;
		ten_place = strPos[0];
		num_place = strPos[1];

		BYTE SendLight[13] = { 'S','E','T',' ','C','U','R',' ','1', ' ', ten_place, num_place,'\r' };
		side_light_comport.WriteComm(SendLight, sizeof(SendLight));
	}

	else if (nPos >= 100 && nPos < 256)
	{
		char hun_place, ten_place, num_place;
		hun_place = strPos[0];
		ten_place = strPos[1];
		num_place = strPos[2];

		BYTE SendLight[14] = { 'S','E','T',' ','C','U','R',' ','1', ' ', hun_place, ten_place, num_place,'\r' };
		side_light_comport.WriteComm(SendLight, sizeof(SendLight));
	}

	else if (nPos >= 256)
	{
		char hun_place, ten_place, num_place;
		hun_place = strPos[0];
		ten_place = strPos[1];
		num_place = strPos[2];

		BYTE SendLight[14] = { 'S','E','T',' ','C','U','R',' ','1', ' ', hun_place, ten_place, num_place,'\r' };
		side_light_comport.WriteComm(SendLight, sizeof(SendLight));

		m_edit_side_light.SetWindowTextW(_T("255"));
	}
}


BOOL CREVIEWAREADlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	/*CRect rect;

	GetClientRect(rect);

	pDC->FillSolidRect(rect, RGB(0, 0, 0));

	return TRUE;*/
	//return FALSE;
	return CDialogEx::OnEraseBkgnd(pDC);
}


UINT CREVIEWAREADlg::Status_Thread(LPVOID pParam)
{
	CREVIEWAREADlg *dlg_Status = (CREVIEWAREADlg*)pParam;

	while (1)
	{
		if (!acsc_GetMotorState(hStage, ACSC_AXIS_4, &dlg_Status->stage_main_x_Status, NULL))
		{
			dlg_Status->dlg_auto->stage_main_x_status = dlg_Status->stage_main_x_Status;
		}

		else
		{
			dlg_Status->dlg_auto->stage_main_x_status = dlg_Status->stage_main_x_Status;
			// Stage_X_Status
			if (dlg_Status->stage_main_x_Status == 4194320)			// motor disable
			{
				dlg_Status->m_btn_main_stage_x.SetBitmap(dlg_Status->m_stage_off);
			}

			else if (dlg_Status->stage_main_x_Status == 4194321)		// motor enable
			{
				dlg_Status->m_btn_main_stage_x.SetBitmap(dlg_Status->m_stage_on);
			}
		}


		if (!acsc_GetMotorState(hStage, ACSC_AXIS_0, &dlg_Status->stage_main_y_Status, NULL))
		{
			dlg_Status->dlg_auto->stage_main_y_status = dlg_Status->stage_main_y_Status;
		}

		else
		{
			dlg_Status->dlg_auto->stage_main_y_status = dlg_Status->stage_main_y_Status;
			if (dlg_Status->stage_main_y_Status == 4194320)			// motor disable
			{
				dlg_Status->m_btn_main_stage_y.SetBitmap(dlg_Status->m_stage_off);
			}

			else if (dlg_Status->stage_main_y_Status == 4194321)		// motor enable
			{
				dlg_Status->m_btn_main_stage_y.SetBitmap(dlg_Status->m_stage_on);
			}
		}

		if (!acsc_GetMotorState(hStage, ACSC_AXIS_10, &dlg_Status->stage_sub_x_Status, NULL))
		{
			dlg_Status->dlg_auto->stage_sub_x_status = dlg_Status->stage_sub_x_Status;
		}

		else
		{
			dlg_Status->dlg_auto->stage_sub_x_status = dlg_Status->stage_sub_x_Status;

			if (dlg_Status->stage_sub_x_Status == 4194320)			// motor disable
			{
				dlg_Status->m_btn_sub_stage_x.SetBitmap(dlg_Status->m_stage_off);
			}

			else if (dlg_Status->stage_sub_x_Status == 4194321)		// motor enable
			{
				dlg_Status->m_btn_sub_stage_x.SetBitmap(dlg_Status->m_stage_on);
			}
		}


		if (dlg_Status->stage_main_x_Status == 4194320 && dlg_Status->stage_main_y_Status == 4194320 && dlg_Status->stage_sub_x_Status == 4194320)			// motor disable
		{
			dlg_Status->m_btn_all_stage.SetBitmap(dlg_Status->m_stage_off);
		}

		else if (dlg_Status->stage_main_x_Status == 4194321 && dlg_Status->stage_main_y_Status == 4194321 && dlg_Status->stage_sub_x_Status == 4194321)
		{
			dlg_Status->m_btn_all_stage.SetBitmap(dlg_Status->m_stage_on);
		}

		else
		{
			dlg_Status->m_btn_all_stage.SetBitmap(dlg_Status->m_stage_on);
		}

		acsc_GetRPosition(hStage, ACSC_AXIS_4, &dlg_Status->stage_main_x_pos, NULL);
		acsc_GetRPosition(hStage, ACSC_AXIS_0, &dlg_Status->stage_main_y_pos, NULL);
		acsc_GetRPosition(hStage, ACSC_AXIS_10, &dlg_Status->stage_sub_x_pos, NULL);

		CString stage_position;

		stage_position.Format(_T("%.4f"), dlg_Status->stage_main_x_pos);
		dlg_Status->dlg_auto->m_edit_stage_main_x_pos.SetWindowTextW(stage_position);
		dlg_Status->dlg_manual->m_edit_stage_main_x_reference.SetWindowTextW(stage_position);

		stage_position.Format(_T("%.4f"), dlg_Status->stage_main_y_pos);
		dlg_Status->dlg_auto->m_edit_stage_main_y_pos.SetWindowTextW(stage_position);
		dlg_Status->dlg_manual->m_edit_stage_main_y_reference.SetWindowTextW(stage_position);

		stage_position.Format(_T("%.4f"), dlg_Status->stage_sub_x_pos);
		dlg_Status->dlg_auto->m_edit_stage_sub_x_pos.SetWindowTextW(stage_position);
		dlg_Status->dlg_manual->m_edit_stage_sub_x_reference.SetWindowTextW(stage_position);

		// LED
		if (dlg_Status->dlg_auto->upper_camera_status == 1)
			dlg_Status->m_btn_upper_cam.SetBitmap(dlg_Status->m_cam_on);

		else if (dlg_Status->dlg_auto->upper_camera_status == 0)
			dlg_Status->m_btn_upper_cam.SetBitmap(dlg_Status->m_cam_off);

		if (dlg_Status->dlg_auto->side_camera_status == 1)
			dlg_Status->m_btn_side_cam.SetBitmap(dlg_Status->m_cam_on);


		else if (dlg_Status->dlg_auto->side_camera_status == 0)
			dlg_Status->m_btn_side_cam.SetBitmap(dlg_Status->m_cam_off);

		// 둘다 ON인 경우
		if (dlg_Status->dlg_auto->upper_camera_status == 1 && dlg_Status->dlg_auto->side_camera_status == 1)
		{
			dlg_Status->m_btn_all_cam.SetBitmap(dlg_Status->m_cam_on);
		}

		// 둘다 OFF인 경우
		else if (dlg_Status->dlg_auto->upper_camera_status == 0 && dlg_Status->dlg_auto->side_camera_status == 0)
		{
			dlg_Status->m_btn_all_cam.SetBitmap(dlg_Status->m_cam_off);
		}

		// 둘 중 하나라도 on 인 경우
		else
		{
			dlg_Status->m_btn_all_cam.SetBitmap(dlg_Status->m_cam_on);
		}


		if (dlg_Status->dlg_auto->bStart == TRUE)
		{
			dlg_Status->m_pic_start.SetBitmap(dlg_Status->m_green_led);
			dlg_Status->m_pic_stop.SetBitmap(dlg_Status->m_red_led);
		}

		if (dlg_Status->dlg_auto->bStop == TRUE)
		{
			dlg_Status->m_pic_start.SetBitmap(dlg_Status->m_red_led);
			dlg_Status->m_pic_stop.SetBitmap(dlg_Status->m_green_led);
		}


		if (dlg_Status->upper_light_comport.m_bConnected)
			dlg_Status->m_btn_upper_light.SetBitmap(dlg_Status->m_light_on);

		else if (!dlg_Status->upper_light_comport.m_bConnected)
			dlg_Status->m_btn_upper_light.SetBitmap(dlg_Status->m_light_off);

		if (dlg_Status->side_light_comport.m_bConnected)
			dlg_Status->m_btn_side_light.SetBitmap(dlg_Status->m_light_on);

		else if (!dlg_Status->side_light_comport.m_bConnected)
			dlg_Status->m_btn_side_light.SetBitmap(dlg_Status->m_light_off);
	}

	return 0;
}


HBRUSH CREVIEWAREADlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.

	if (pWnd->GetDlgCtrlID() == IDC_STATIC_DAY)
	{
		pDC->SetTextColor(RGB(0, 0, 0));
		//pDC->SetBkColor(RGB(255, 255, 255));
		//return bg_brush;
	}

	if (pWnd->GetDlgCtrlID() == IDC_STATIC_TIME)
	{
		pDC->SetTextColor(RGB(0, 0, 0));
		//pDC->SetBkColor(RGB(255, 255, 255));
		//return bg_brush;
	}

	if (pWnd->GetDlgCtrlID() == IDC_STATIC_RECIPE_NAME)
	{
		pDC->SetTextColor(RGB(0, 0, 0));
		//pDC->SetBkColor(RGB(255, 255, 255));
		//return bg_brush;
	}

	if (pWnd->GetDlgCtrlID() == IDC_STATIC_RECIPE)
	{
		pDC->SetTextColor(RGB(0, 0, 0));
		//pDC->SetBkColor(RGB(255, 255, 255));
		//return bg_brush;
	}

	if (pWnd->GetDlgCtrlID() == IDC_SLD_UPPER)
	{
		//return bg_brush;
	}

	if (pWnd->GetDlgCtrlID() == IDC_SLD_SIDE)
	{
		//return bg_brush;
	}

	return hbr;
}


void CREVIEWAREADlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	DWORD nExitCode = NULL;

	GetExitCodeThread(Status->m_hThread, &nExitCode);
	TerminateThread(Status->m_hThread, nExitCode);

	Status = NULL;
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CREVIEWAREADlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	if (pScrollBar)
	{
		if (pScrollBar == (CScrollBar*)&m_sld_upper)
		{
			int nPos = m_sld_upper.GetPos();
			CString strPos;

			strPos.Format(_T("%d"), nPos);

			m_edit_upper_light.SetWindowTextW(strPos);
		}

		if (pScrollBar == (CScrollBar*)&m_sld_side)
		{
			int nPos = m_sld_side.GetPos();
			CString strPos;

			strPos.Format(_T("%d"), nPos);

			m_edit_side_light.SetWindowTextW(strPos);
		}
	}
	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}


int CREVIEWAREADlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	return 0;
}


void CREVIEWAREADlg::OnBnClickedBtnUpperLight()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (upper_light_comport.m_bConnected == FALSE)
	{
		upper_light_comport.OpenPort(byIndexComPort(6), byIndexBaud(1), byIndexData(3), byIndexParity(0), byIndexStop(0));
		BYTE SendLight[12] = { 'S','E','T',' ','C','U','R',' ','1', '8','0', '\r' };
		upper_light_comport.WriteComm(SendLight, sizeof(SendLight));

		//check_light_comport = 1;

		m_edit_upper_light.SetWindowTextW(_T("80"));
		m_sld_upper.EnableWindow(TRUE);
		m_edit_upper_light.EnableWindow(TRUE);
	}

	else if (upper_light_comport.m_bConnected == TRUE)
	{
		BYTE SendLight[12] = { 'S','E','T',' ','C','U','R',' ','1', ' ', '0', '\r' };
		upper_light_comport.WriteComm(SendLight, sizeof(SendLight));

		upper_light_comport.ClosePort();

		//check_light_comport = 0;
		m_sld_upper.EnableWindow(FALSE);
		m_edit_upper_light.EnableWindow(FALSE);
	}
}


void CREVIEWAREADlg::OnBnClickedBtnSideLight()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (side_light_comport.m_bConnected == FALSE)
	{
		side_light_comport.OpenPort(byIndexComPort(7), byIndexBaud(1), byIndexData(3), byIndexParity(0), byIndexStop(0));
		BYTE SendLight[13] = { 'S','E','T',' ','C','U','R',' ','1', '1', '8','0', '\r' };
		side_light_comport.WriteComm(SendLight, sizeof(SendLight));

		m_edit_side_light.SetWindowTextW(_T("180"));
		m_sld_side.EnableWindow(TRUE);
		m_edit_side_light.EnableWindow(TRUE);
	}

	else if (side_light_comport.m_bConnected == TRUE)
	{
		BYTE SendLight[12] = { 'S','E','T',' ','C','U','R',' ','1', ' ', '0', '\r' };
		side_light_comport.WriteComm(SendLight, sizeof(SendLight));

		side_light_comport.ClosePort();

		//check_light_comport = 0;
		m_sld_side.EnableWindow(FALSE);
		m_edit_side_light.EnableWindow(FALSE);
	}
}


void CREVIEWAREADlg::OnBnClickedBtnUpperAf()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	/*if (upper_af_comport.m_bConnected == FALSE)
	{
		upper_af_comport.OpenPort(byIndexComPort(8), byIndexBaud(1), byIndexData(3), byIndexParity(0), byIndexStop(0));
		
	}

	else if (upper_af_comport.m_bConnected == TRUE)
	{
		upper_af_comport.ClosePort();
		
	}*/
}


void CREVIEWAREADlg::OnBnClickedBtnSideAf()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	/*if (side_af_comport.m_bConnected == FALSE)
	{
		side_af_comport.OpenPort(byIndexComPort(9), byIndexBaud(1), byIndexData(3), byIndexParity(0), byIndexStop(0));
		
	}

	else if (side_af_comport.m_bConnected == TRUE)
	{
		side_af_comport.ClosePort();
		
	}*/
}




void CREVIEWAREADlg::OnSaveCamUpper()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CTime capture_time = CTime::GetCurrentTime();
	CString str_capture_time;

	str_capture_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), capture_time.GetYear(), capture_time.GetMonth(),
		capture_time.GetDay(), capture_time.GetHour(), capture_time.GetMinute(), capture_time.GetSecond());

	// 활성화 상태
	if (dlg_auto->upper_camera_status == 1)
	{
		MdigHalt(dlg_auto->area_cam.m_MilDigitizer_Upper);

		CString saveTitle;
		saveTitle = strPath + _T("DATA\\3. CAPTURE\\1. UPPER\\") + str_capture_time + _T(".bmp");

		// Align Before Image Grab
		MdigGrab(dlg_auto->area_cam.m_MilDigitizer_Upper, dlg_auto->area_cam.m_MilImage_Upper);
		// Align Before Image Save
		MbufExport(saveTitle, M_BMP, dlg_auto->area_cam.m_MilImage_Upper);
		MdigGrabContinuous(dlg_auto->area_cam.m_MilDigitizer_Upper, dlg_auto->area_cam.m_MilImage_Upper);
	}

	else if (dlg_auto->upper_camera_status == 0)
	{
		CString saveTitle;
		saveTitle = strPath + _T("DATA\\3. CAPTURE\\1. UPPER\\") + str_capture_time + _T(".bmp");

		MdigGrab(dlg_auto->area_cam.m_MilDigitizer_Upper, dlg_auto->area_cam.m_MilImage_Upper);
		MbufExport(saveTitle, M_BMP, dlg_auto->area_cam.m_MilImage_Upper);
	}
}



void CREVIEWAREADlg::OnSaveCamSide()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CTime capture_time = CTime::GetCurrentTime();
	CString str_capture_time;

	str_capture_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), capture_time.GetYear(), capture_time.GetMonth(),
		capture_time.GetDay(), capture_time.GetHour(), capture_time.GetMinute(), capture_time.GetSecond());

	// 활성화 상태
	if (dlg_auto->side_camera_status == 1)
	{
		MdigHalt(dlg_auto->area_cam.m_MilDigitizer_Side);

		CString saveTitle;
		saveTitle = strPath + _T("DATA\\3. CAPTURE\\2. SIDE\\") + str_capture_time + _T(".bmp");

		// Align Before Image Grab
		MdigGrab(dlg_auto->area_cam.m_MilDigitizer_Side, dlg_auto->area_cam.m_MilImage_Side);
		// Align Before Image Save
		MbufExport(saveTitle, M_BMP, dlg_auto->area_cam.m_MilImage_Side);
		MdigGrabContinuous(dlg_auto->area_cam.m_MilDigitizer_Side, dlg_auto->area_cam.m_MilImage_Side);
	}

	else if (dlg_auto->side_camera_status == 0)
	{
		CString saveTitle;
		saveTitle = strPath + _T("DATA\\3. CAPTURE\\2. SIDE\\") + str_capture_time + _T(".bmp");

		MdigGrab(dlg_auto->area_cam.m_MilDigitizer_Side, dlg_auto->area_cam.m_MilImage_Side);
		MbufExport(saveTitle, M_BMP, dlg_auto->area_cam.m_MilImage_Side);
	}
}


void CREVIEWAREADlg::OnSaveCamAll()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	OnSaveCamUpper();
	OnSaveCamSide();
}


void CREVIEWAREADlg::OnFileLoad()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CREVIEWAREADlg::OnFileExit()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	::PostQuitMessage(WM_QUIT);
}


void CREVIEWAREADlg::OnGraphicActive()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMenu* hMenu = GetMenu();

	dlg_manual->OnBnClickedBtnGraphic();
}


void CREVIEWAREADlg::graphic_active()
{
	CMenu* hMenu = GetMenu();

	if (dlg_manual->check_graphic_mode == 1)
		hMenu->CheckMenuItem(ID_GRAPHIC_ACTIVE, MF_CHECKED);

	else if (dlg_manual->check_graphic_mode == 0)
		hMenu->CheckMenuItem(ID_GRAPHIC_ACTIVE, MF_UNCHECKED);
}


void CREVIEWAREADlg::OnGraphicLine()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CREVIEWAREADlg::OnGraphicRectangle()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CREVIEWAREADlg::OnGraphicCircle()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CREVIEWAREADlg::OnGraphicEdge()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CREVIEWAREADlg::OnGraphicEdge_2()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CREVIEWAREADlg::OnComportConnect()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	DIALOG_COMPORT		dlg_comport;

	if (dlg_comport.DoModal() == IDOK)
	{

	}

}


void CREVIEWAREADlg::OnSystemLogin()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	DIALOG_SYSTEM*	dlg_system;
	dlg_system = new DIALOG_SYSTEM;

	if (dlg_system->DoModal() == IDOK)
	{
		if (check_login == 0)
		{
			if (str_id == "admin")
			{
				if (str_pw == "wiacorp")
				{
					m_pic_login.SetBitmap(m_green_led);
					check_login = 1;
					dlg_setting->m_tab_setting.InsertItem(5, _T("HIDDEN"));
					Invalidate(FALSE);
				}
			}
		}

		else if (check_login == 1)
		{
			m_pic_login.SetBitmap(m_red_led);
			check_login = 0;
			dlg_setting->m_tab_setting.DeleteItem(5);

			Invalidate(FALSE);
		}

	}
}


void CREVIEWAREADlg::OnDeltaposSpinAf(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	
	double move_step;

	int step_pos = m_cmb_af_step.GetCurSel();

	if (step_pos == 0)
		move_step = 0.25 * 4;

	else if (step_pos == 1)
		move_step = 0.5 * 4;

	else if (step_pos == 2)
		move_step = 1 * 4;

	else if (step_pos == 3)
		move_step = 5 * 4;

	else if (step_pos == 4)
		move_step = 20 * 4;

	else if (step_pos == 5)
		move_step = 100 * 4;

	else if (step_pos == 6)
		move_step = 100000 * 4;

	if (m_chk_upper_af.GetCheck() == 1)
	{
		ATF_OpenConnection("COM9", 9600);

		if (pNMUpDown->iDelta < 0)
			ATF_MoveZ(move_step);

		else if (pNMUpDown->iDelta > 0)
		{
			move_step = -move_step;
			ATF_MoveZ(move_step);
		}
	}

	else if (m_chk_side_af.GetCheck() == 1)
	{
		ATF_OpenConnection("\\\\.\\COM10", 9600);

		if (pNMUpDown->iDelta < 0)
			ATF_MoveZ(move_step);

		else if (pNMUpDown->iDelta > 0)
		{
			move_step = -move_step;
			ATF_MoveZ(move_step);
		}
	}
	


	/*double move_step;
	if (selected_af == 2)
	{
		ATF_CloseConnection();
		selected_af = 1;
	}


	int iVal = pNMUpDown->iPos + pNMUpDown->iDelta;
	// up

	if (pNMUpDown->iDelta < 0)
	{
		ATF_OpenConnection("COM9", 9600);
		ATF_MoveZ(move_step);
	}
	// down

	else if (pNMUpDown->iDelta > 0)
	{
		move_step = -move_step;
		ATF_OpenConnection("COM9", 9600);
		ATF_MoveZ(move_step);
	}*/

	//	ATF_CloseConnection();
	*pResult = 0;
}


void CREVIEWAREADlg::OnBnClickedChkUpperAf()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_chk_upper_af.GetCheck() == 0)
	{
		m_chk_upper_af.SetCheck(0);
		m_chk_side_af.SetCheck(1);
	}

	else if (m_chk_upper_af.GetCheck() == 1)
	{
		m_chk_upper_af.SetCheck(1);
		m_chk_side_af.SetCheck(0);
	}
	ATF_CloseConnection();
}


void CREVIEWAREADlg::OnBnClickedChkSideAf()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_chk_side_af.GetCheck() == 0)
	{
		m_chk_side_af.SetCheck(0);
		m_chk_upper_af.SetCheck(1);
	}

	else if (m_chk_side_af.GetCheck() == 1)
	{
		m_chk_side_af.SetCheck(1);
		m_chk_upper_af.SetCheck(0);
	}
	ATF_CloseConnection();
}


void CREVIEWAREADlg::OnBnClickedBtnAf()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	if (m_chk_upper_af.GetCheck() == 1)
	{
		ATF_OpenConnection("COM9", 9600);
		ATF_AFTrack();
		m_pic_upper_af.SetBitmap(m_green_led);
	}

	else if (m_chk_side_af.GetCheck() == 1)
	{
		ATF_OpenConnection("\\\\.\\COM10", 9600);
		ATF_AFTrack();
		m_pic_side_af.SetBitmap(m_green_led);
	}
}


void CREVIEWAREADlg::OnBnClickedBtnStop()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_chk_upper_af.GetCheck() == 1)
	{
		ATF_AfStop();
		ATF_CloseConnection();

		ATF_OpenConnection("\\\\.\\COM10", 9600);
		ATF_AfStop();
	}

	else if (m_chk_side_af.GetCheck() == 1)
	{
		ATF_AfStop();
		
		ATF_CloseConnection();

		ATF_OpenConnection("COM9", 9600);
		ATF_AfStop();	
	}

	m_pic_upper_af.SetBitmap(m_red_led);
	m_pic_side_af.SetBitmap(m_red_led);
}


void CREVIEWAREADlg::OnBnClickedBtnMoveStop()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ATF_StopZMotor();
}


void CREVIEWAREADlg::align_af_pos()
{
	ATF_OpenConnection("COM9", 9600);

	ATF_MoveZ(400);
}


void CREVIEWAREADlg::process_af_pos()
{
	ATF_OpenConnection("COM9", 9600);

	ATF_MoveZ(-400);
}


void CREVIEWAREADlg::inspection_upper_af(int Case)
{
	ATF_CloseConnection();
	// af start
	if (Case == 0)
	{
		ATF_OpenConnection("COM9", 9600);
		ATF_AFTrack();
	}

	// af stop
	else if (Case == 1)
	{
		ATF_OpenConnection("COM9", 9600);
		ATF_AfStop();
	}
}


void CREVIEWAREADlg::inspection_side_af(int Case)
{
	ATF_CloseConnection();
	// af start
	if (Case == 0)
	{
		ATF_OpenConnection("\\\\.\\COM10", 9600);
		ATF_AFTrack();
	}

	// af stop
	else if (Case == 1)
	{
		ATF_OpenConnection("\\\\.\\COM10", 9600);
		ATF_AfStop();
	}
}


void CREVIEWAREADlg::ProcessAFStart()
{ 
	ATF_CloseConnection();
	ATF_OpenConnection("COM9", 9600);
	ATF_AFTrack();
	
	ATF_CloseConnection();
	ATF_OpenConnection("\\\\.\\COM10", 9600);
	ATF_AFTrack();

	m_pic_side_af.SetBitmap(m_green_led);
	m_pic_upper_af.SetBitmap(m_green_led);
}


void CREVIEWAREADlg::ProcessAFStop()
{
	ATF_CloseConnection();
	ATF_OpenConnection("COM9", 9600);
	ATF_AfStop();

	ATF_CloseConnection();
	ATF_OpenConnection("\\\\.\\COM10", 9600);
	ATF_AfStop();

	m_pic_side_af.SetBitmap(m_red_led);
	m_pic_upper_af.SetBitmap(m_red_led);
}
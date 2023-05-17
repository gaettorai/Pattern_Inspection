// DIALOG_AUTO.cpp: 구현 파일
//

#include "stdafx.h"
#include "REVIEW_AREA.h"
#include "DIALOG_AUTO.h"
#include "afxdialogex.h"

#include "REVIEW_AREADlg.h"
// DIALOG_AUTO 대화 상자

IMPLEMENT_DYNAMIC(DIALOG_AUTO, CDialogEx)

DIALOG_AUTO::DIALOG_AUTO(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_AUTO, pParent)
{

}

DIALOG_AUTO::~DIALOG_AUTO()
{
}

void DIALOG_AUTO::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC_PROCESS_READY, m_pic_process_ready);
	DDX_Control(pDX, IDC_PIC_PROCESS_PROCESS, m_pic_process_process);
	DDX_Control(pDX, IDC_PIC_UPPER, m_pic_upper);
	DDX_Control(pDX, IDC_PIC_SIDE, m_pic_side);
	DDX_Control(pDX, IDC_PIC_PROCESS_PREALIGN, m_pic_process_prealign);
	DDX_Control(pDX, IDC_PIC_PROCESS_TABALIGN, m_pic_process_tabalign);
	DDX_Control(pDX, IDC_PIC_PROCESS_INSPECTION, m_pic_process_inspection);
	DDX_Control(pDX, IDC_PIC_PROCESS_JUDGE, m_pic_process_judge);
	DDX_Control(pDX, IDC_PIC_PROCESS_UNLOADING, m_pic_process_unloading);
	DDX_Control(pDX, IDC_EDIT_STAGE_MAIN_X_POS, m_edit_stage_main_x_pos);
	DDX_Control(pDX, IDC_EDIT_STAGE_MAIN_X_READY_POS, m_edit_stage_main_x_ready_pos);
	DDX_Control(pDX, IDC_EDIT_STAGE_MAIN_X_PROCESS_POS, m_edit_stage_main_x_process_pos);
	DDX_Control(pDX, IDC_EDIT_STAGE_MAIN_X_LIMIT_MIN, m_edit_stage_main_x_limit_min);
	DDX_Control(pDX, IDC_EDIT_STAGE_MAIN_X_LIMIT_MAX, m_edit_stage_main_x_limit_max);
	DDX_Control(pDX, IDC_EDIT_STAGE_MAIN_X_MANUAL_SPEED, m_edit_stage_main_x_manual_speed);
	DDX_Control(pDX, IDC_EDIT_STAGE_MAIN_X_PROCESS_SPEED, m_edit_stage_main_x_process_speed);
	DDX_Control(pDX, IDC_EDIT_STAGE_MAIN_Y_POS, m_edit_stage_main_y_pos);
	DDX_Control(pDX, IDC_EDIT_STAGE_MAIN_Y_READY_POS, m_edit_stage_main_y_ready_pos);
	DDX_Control(pDX, IDC_EDIT_STAGE_MAIN_Y_PROCESS_POS, m_edit_stage_main_y_process_pos);
	DDX_Control(pDX, IDC_EDIT_STAGE_MAIN_Y_LIMIT_MIN, m_edit_stage_main_y_limit_min);
	DDX_Control(pDX, IDC_EDIT_STAGE_MAIN_Y_LIMIT_MAX, m_edit_stage_main_y_limit_max);
	DDX_Control(pDX, IDC_EDIT_STAGE_MAIN_Y_MANUAL_SPEED, m_edit_stage_main_y_manual_speed);
	DDX_Control(pDX, IDC_EDIT_STAGE_MAIN_Y_PROCESS_SPEED, m_edit_stage_main_y_process_speed);
	DDX_Control(pDX, IDC_EDIT_STAGE_SUB_X_POS, m_edit_stage_sub_x_pos);
	DDX_Control(pDX, IDC_EDIT_STAGE_SUB_X_READY_POS, m_edit_stage_sub_x_ready_pos);
	DDX_Control(pDX, IDC_EDIT_STAGE_SUB_X_PROCESS_POS, m_edit_stage_sub_x_process_pos);
	DDX_Control(pDX, IDC_EDIT_STAGE_SUB_X_LIMIT_MIN, m_edit_stage_sub_x_limit_min);
	DDX_Control(pDX, IDC_EDIT_STAGE_SUB_X_LIMIT_MAX, m_edit_stage_sub_x_limit_max);
	DDX_Control(pDX, IDC_EDIT_STAGE_SUB_X_ALIGN_OFFSET, m_edit_stage_sub_x_align_offset);
	DDX_Control(pDX, IDC_EDIT_STAGE_SUB_X_MANUAL_SPEED, m_edit_stage_sub_x_manual_speed);
	DDX_Control(pDX, IDC_EDIT_STAGE_SUB_X_PROCESS_SPEED, m_edit_stage_sub_x_process_speed);
	DDX_Control(pDX, IDC_EDIT_TACKTIME_PROCESS, m_edit_tacktime_process);
	DDX_Control(pDX, IDC_EDIT_TACKTIME_ALIGN, m_edit_tacktime_align);
	DDX_Control(pDX, IDC_EDIT_TACKTIME_INSPECTION, m_edit_tacktime_inspection);
	DDX_Control(pDX, IDC_EDIT_TACKTIME_JUDGE, m_edit_tacktime_judge);
	DDX_Control(pDX, IDC_EDIT_TACKTIME_UNLOADING, m_edit_tacktime_unloading);
	DDX_Control(pDX, IDC_EDIT_TACKTIME_TOTAL, m_edit_tacktime_total);
	DDX_Control(pDX, IDC_LIST_RESULT, m_list_result);
	DDX_Control(pDX, IDC_LIST_MA_X, m_list_ma_x);
	DDX_Control(pDX, IDC_LIST_OS, m_list_os);
	DDX_Control(pDX, IDC_LIST_OTHER, m_list_other);
	DDX_Control(pDX, IDC_LIST_MA_Y, m_list_ma_y);
	DDX_Control(pDX, IDC_LIST_LOG, m_list_log);
	DDX_Control(pDX, IDC_EDIT_PROCESS, m_edit_process);
	DDX_Control(pDX, IDC_EDIT_GLASS_ID, m_edit_glass_id);
}


BEGIN_MESSAGE_MAP(DIALOG_AUTO, CDialogEx)
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_BTN_START, &DIALOG_AUTO::OnBnClickedBtnStart)
	ON_BN_CLICKED(IDC_BTN_STOP, &DIALOG_AUTO::OnBnClickedBtnStop)
	ON_BN_CLICKED(IDC_BTN_RESET, &DIALOG_AUTO::OnBnClickedBtnReset)
	ON_BN_CLICKED(IDC_BTN_LOG_RESET, &DIALOG_AUTO::OnBnClickedBtnLogReset)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BTN_EMO, &DIALOG_AUTO::OnBnClickedBtnEmo)
	ON_BN_CLICKED(IDC_BTN_MANUAL_INSPECT, &DIALOG_AUTO::OnBnClickedBtnManualInspect)
END_MESSAGE_MAP()


// DIALOG_AUTO 메시지 처리기


BOOL DIALOG_AUTO::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	int cam_width = 2048;
	int cam_height = 2048;

	cam_width = 2048 / 4;
	cam_height = 2048 / 4;

	GetDlgItem(IDC_PIC_UPPER)->MoveWindow(4, 0, cam_width, cam_height);
	GetDlgItem(IDC_PIC_SIDE)->MoveWindow(4, cam_height, cam_width, cam_height);

	/*GetDlgItem(IDC_BTN_START)->MoveWindow(540, 550, 100, 100);
	GetDlgItem(IDC_BTN_STOP)->MoveWindow(650, 550, 100, 100);
	GetDlgItem(IDC_BTN_EMO)->MoveWindow(540, 660, 100, 100);
	GetDlgItem(IDC_BTN_RESET)->MoveWindow(650, 660, 100, 100);
	*/
	GetDlgItem(IDC_BTN_MANUAL_INSPECT)->MoveWindow(540, 0, 100, 100);
	GetDlgItem(IDC_BTN_START)->MoveWindow(540, 330, 100, 100);
	GetDlgItem(IDC_BTN_STOP)->MoveWindow(540, 440, 100, 100);
	GetDlgItem(IDC_BTN_EMO)->MoveWindow(540, 550, 100, 100);
	GetDlgItem(IDC_BTN_RESET)->MoveWindow(540, 660, 100, 100);

	GetDlgItem(IDC_STATIC_GLASS_ID)->MoveWindow(540, 250, 100, 20);
	GetDlgItem(IDC_EDIT_GLASS_ID)->MoveWindow(540, 280, 100, 20);

	GetDlgItem(IDC_BTN_EMO)->EnableWindow(FALSE);

	GetDlgItem(IDC_STATIC_LIST_RESULT)->MoveWindow(780, 10, 200, 30);
	GetDlgItem(IDC_STATIC_LIST_MA_X)->MoveWindow(990, 10, 200, 30);
	GetDlgItem(IDC_STATIC_LIST_MA_Y)->MoveWindow(1200, 10, 200, 30);
	GetDlgItem(IDC_STATIC_LIST_OS)->MoveWindow(990, 200, 410, 20);
	GetDlgItem(IDC_STATIC_LIST_OTHER)->MoveWindow(990, 370, 410, 20);

	GetDlgItem(IDC_LIST_RESULT)->MoveWindow(780, 40, 200, 500);
	GetDlgItem(IDC_LIST_MA_X)->MoveWindow(990, 40, 200, 150);
	GetDlgItem(IDC_LIST_MA_Y)->MoveWindow(1200, 40, 200, 150);
	GetDlgItem(IDC_LIST_OS)->MoveWindow(990, 220, 410, 150);
	GetDlgItem(IDC_LIST_OTHER)->MoveWindow(990, 390, 410, 150);

	int edit_y_start = cam_height + 300;

	int static_width = 110;
	int static_height = 25;

	int edit_width = 65;

	process_af_check = 0;

	GetDlgItem(IDC_STATIC_STAGE_MAIN_X_POS)->MoveWindow(520, edit_y_start, static_width, 25);
	GetDlgItem(IDC_STATIC_STAGE_MAIN_X_READY_POS)->MoveWindow(520, edit_y_start + 25, static_width, 25);
	GetDlgItem(IDC_STATIC_STAGE_MAIN_X_PROCESS_POS)->MoveWindow(520, edit_y_start + 50, static_width, 25);
	GetDlgItem(IDC_STATIC_STAGE_MAIN_X_LIMIT_MIN)->MoveWindow(520, edit_y_start + 75, static_width, 25);
	GetDlgItem(IDC_STATIC_STAGE_MAIN_X_LIMIT_MAX)->MoveWindow(520, edit_y_start + 100, static_width, 25);
	GetDlgItem(IDC_STATIC_STAGE_MAIN_X_MANUAL_SPEED)->MoveWindow(520, edit_y_start + 125, static_width, 25);
	GetDlgItem(IDC_STATIC_STAGE_MAIN_X_PROCESS_SPEED)->MoveWindow(520, edit_y_start + 150, static_width, 25);

	GetDlgItem(IDC_EDIT_STAGE_MAIN_X_POS)->MoveWindow(630, edit_y_start, edit_width, 25);
	GetDlgItem(IDC_EDIT_STAGE_MAIN_X_READY_POS)->MoveWindow(630, edit_y_start + 25, edit_width, 25);
	GetDlgItem(IDC_EDIT_STAGE_MAIN_X_PROCESS_POS)->MoveWindow(630, edit_y_start + 50, edit_width, 25);
	GetDlgItem(IDC_EDIT_STAGE_MAIN_X_LIMIT_MIN)->MoveWindow(630, edit_y_start + 75, edit_width, 25);
	GetDlgItem(IDC_EDIT_STAGE_MAIN_X_LIMIT_MAX)->MoveWindow(630, edit_y_start + 100, edit_width, 25);
	GetDlgItem(IDC_EDIT_STAGE_MAIN_X_MANUAL_SPEED)->MoveWindow(630, edit_y_start + 125, edit_width, 25);
	GetDlgItem(IDC_EDIT_STAGE_MAIN_X_PROCESS_SPEED)->MoveWindow(630, edit_y_start + 150, edit_width, 25);

	GetDlgItem(IDC_STATIC_STAGE_MAIN_Y_POS)->MoveWindow(700, edit_y_start, static_width, 25);
	GetDlgItem(IDC_STATIC_STAGE_MAIN_Y_READY_POS)->MoveWindow(700, edit_y_start + 25, static_width, 25);
	GetDlgItem(IDC_STATIC_STAGE_MAIN_Y_PROCESS_POS)->MoveWindow(700, edit_y_start + 50, static_width, 25);
	GetDlgItem(IDC_STATIC_STAGE_MAIN_Y_LIMIT_MIN)->MoveWindow(700, edit_y_start + 75, static_width, 25);
	GetDlgItem(IDC_STATIC_STAGE_MAIN_Y_LIMIT_MAX)->MoveWindow(700, edit_y_start + 100, static_width, 25);
	GetDlgItem(IDC_STATIC_STAGE_MAIN_Y_MANUAL_SPEED)->MoveWindow(700, edit_y_start + 125, static_width, 25);
	GetDlgItem(IDC_STATIC_STAGE_MAIN_Y_PROCESS_SPEED)->MoveWindow(700, edit_y_start + 150, static_width, 25);

	GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_POS)->MoveWindow(810, edit_y_start, edit_width, 25);
	GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_READY_POS)->MoveWindow(810, edit_y_start + 25, edit_width, 25);
	GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_PROCESS_POS)->MoveWindow(810, edit_y_start + 50, edit_width, 25);
	GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_LIMIT_MIN)->MoveWindow(810, edit_y_start + 75, edit_width, 25);
	GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_LIMIT_MAX)->MoveWindow(810, edit_y_start + 100, edit_width, 25);
	GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_MANUAL_SPEED)->MoveWindow(810, edit_y_start + 125, edit_width, 25);
	GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_PROCESS_SPEED)->MoveWindow(810, edit_y_start + 150, edit_width, 25);

	GetDlgItem(IDC_STATIC_STAGE_SUB_X_POS)->MoveWindow(880, edit_y_start, static_width, 25);
	GetDlgItem(IDC_STATIC_STAGE_SUB_X_READY_POS)->MoveWindow(880, edit_y_start + 25, static_width, 25);
	GetDlgItem(IDC_STATIC_STAGE_SUB_X_PROCESS_POS)->MoveWindow(880, edit_y_start + 50, static_width, 25);
	GetDlgItem(IDC_STATIC_STAGE_SUB_X_ALIGN_OFFSET)->MoveWindow(880, edit_y_start + 75, static_width, 25);
	GetDlgItem(IDC_STATIC_STAGE_SUB_X_LIMIT_MIN)->MoveWindow(880, edit_y_start + 100, static_width, 25);
	GetDlgItem(IDC_STATIC_STAGE_SUB_X_LIMIT_MAX)->MoveWindow(880, edit_y_start + 125, static_width, 25);
	GetDlgItem(IDC_STATIC_STAGE_SUB_X_MANUAL_SPEED)->MoveWindow(880, edit_y_start + 150, static_width, 25);
	GetDlgItem(IDC_STATIC_STAGE_SUB_X_PROCESS_SPEED)->MoveWindow(880, edit_y_start + 175, static_width, 25);

	GetDlgItem(IDC_EDIT_STAGE_SUB_X_POS)->MoveWindow(990, edit_y_start, edit_width, 25);
	GetDlgItem(IDC_EDIT_STAGE_SUB_X_READY_POS)->MoveWindow(990, edit_y_start + 25, edit_width, 25);
	GetDlgItem(IDC_EDIT_STAGE_SUB_X_PROCESS_POS)->MoveWindow(990, edit_y_start + 50, edit_width, 25);
	GetDlgItem(IDC_EDIT_STAGE_SUB_X_ALIGN_OFFSET)->MoveWindow(990, edit_y_start + 75, edit_width, 25);
	GetDlgItem(IDC_EDIT_STAGE_SUB_X_LIMIT_MIN)->MoveWindow(990, edit_y_start + 100, edit_width, 25);
	GetDlgItem(IDC_EDIT_STAGE_SUB_X_LIMIT_MAX)->MoveWindow(990, edit_y_start + 125, edit_width, 25);
	GetDlgItem(IDC_EDIT_STAGE_SUB_X_MANUAL_SPEED)->MoveWindow(990, edit_y_start + 150, edit_width, 25);
	GetDlgItem(IDC_EDIT_STAGE_SUB_X_PROCESS_SPEED)->MoveWindow(990, edit_y_start + 175, edit_width, 25);

	GetDlgItem(IDC_STATIC_PROCESS_READY)->MoveWindow(1080, edit_y_start, 100, 25);
	GetDlgItem(IDC_STATIC_PROCESS_PROCESS)->MoveWindow(1080, edit_y_start + 25, 100, 25);
	GetDlgItem(IDC_STATIC_PROCESS_PREALIGN)->MoveWindow(1080, edit_y_start + 50, 100, 25);
	GetDlgItem(IDC_STATIC_PROCESS_TABALIGN)->MoveWindow(1080, edit_y_start + 75, 100, 25);
	GetDlgItem(IDC_STATIC_PROCESS_INSPECTION)->MoveWindow(1080, edit_y_start + 100, 100, 25);
	GetDlgItem(IDC_STATIC_PROCESS_UNLOADING)->MoveWindow(1080, edit_y_start + 125, 100, 25);
	GetDlgItem(IDC_STATIC_PROCESS_JUDGE)->MoveWindow(1080, edit_y_start + 150, 100, 25);

	GetDlgItem(IDC_PIC_PROCESS_READY)->MoveWindow(1190, edit_y_start, 25, 25);
	GetDlgItem(IDC_PIC_PROCESS_PROCESS)->MoveWindow(1190, edit_y_start + 25, 25, 25);
	GetDlgItem(IDC_PIC_PROCESS_PREALIGN)->MoveWindow(1190, edit_y_start + 50, 25, 25);
	GetDlgItem(IDC_PIC_PROCESS_TABALIGN)->MoveWindow(1190, edit_y_start + 75, 25, 25);
	GetDlgItem(IDC_PIC_PROCESS_INSPECTION)->MoveWindow(1190, edit_y_start + 100, 25, 25);
	GetDlgItem(IDC_PIC_PROCESS_UNLOADING)->MoveWindow(1190, edit_y_start + 125, 25, 25);
	GetDlgItem(IDC_PIC_PROCESS_JUDGE)->MoveWindow(1190, edit_y_start + 150, 25, 25);

	GetDlgItem(IDC_STATIC_TACKTIME_PROCESS)->MoveWindow(1230, edit_y_start, 100, 25);
	GetDlgItem(IDC_STATIC_TACKTIME_ALIGN)->MoveWindow(1230, edit_y_start + 25, 100, 25);
	GetDlgItem(IDC_STATIC_TACKTIME_INSPECTION)->MoveWindow(1230, edit_y_start + 50, 100, 25);
	GetDlgItem(IDC_STATIC_TACKTIME_UNLOADING)->MoveWindow(1230, edit_y_start + 75, 100, 25);
	GetDlgItem(IDC_STATIC_TACKTIME_JUDGE)->MoveWindow(1230, edit_y_start + 100, 100, 25);
	GetDlgItem(IDC_STATIC_TACKTIME_TOTAL)->MoveWindow(1230, edit_y_start + 150, 100, 25);

	GetDlgItem(IDC_EDIT_TACKTIME_PROCESS)->MoveWindow(1340, edit_y_start, edit_width, 25);
	GetDlgItem(IDC_EDIT_TACKTIME_ALIGN)->MoveWindow(1340, edit_y_start + 25, edit_width, 25);
	GetDlgItem(IDC_EDIT_TACKTIME_INSPECTION)->MoveWindow(1340, edit_y_start + 50, edit_width, 25);
	GetDlgItem(IDC_EDIT_TACKTIME_UNLOADING)->MoveWindow(1340, edit_y_start + 75, edit_width, 25);
	GetDlgItem(IDC_EDIT_TACKTIME_JUDGE)->MoveWindow(1340, edit_y_start + 100, edit_width, 25);
	GetDlgItem(IDC_EDIT_TACKTIME_TOTAL)->MoveWindow(1340, edit_y_start + 150, edit_width, 25);

	GetDlgItem(IDC_EDIT_PROCESS)->MoveWindow(780, 550, 620, 40);
	GetDlgItem(IDC_LIST_LOG)->MoveWindow(780, 600, 620, 160);
	GetDlgItem(IDC_BTN_LOG_RESET)->MoveWindow(1330, 770, 70, 30);

	check_manual = false;

	hdc_upper = GetDlgItem(IDC_PIC_UPPER)->GetDC()->m_hDC;
	hdc_side = GetDlgItem(IDC_PIC_SIDE)->GetDC()->m_hDC;

	SetStretchBltMode(hdc_upper, COLORONCOLOR);
	SetStretchBltMode(hdc_side, COLORONCOLOR);

	m_edit_glass_id.SetWindowTextW(_T("NO_NAME"));

	m_green_led.LoadBitmapW(IDB_BITMAP_GREEN_LED);
	m_red_led.LoadBitmapW(IDB_BITMAP_RED_LED);
	m_yellow_led.LoadBitmapW(IDB_BITMAP_YELLOW_LED);

	m_pic_process_ready.SetBitmap(m_red_led);
	m_pic_process_process.SetBitmap(m_red_led);
	m_pic_process_prealign.SetBitmap(m_red_led);
	m_pic_process_tabalign.SetBitmap(m_red_led);
	m_pic_process_inspection.SetBitmap(m_red_led);
	m_pic_process_judge.SetBitmap(m_red_led);
	m_pic_process_unloading.SetBitmap(m_red_led);

	CFont font;
	LOGFONT	LogFont;

	GetDlgItem(IDC_EDIT_PROCESS)->GetFont()->GetLogFont(&LogFont);

	LogFont.lfWidth = 8;
	LogFont.lfHeight = 30;

	font.CreateFontIndirectW(&LogFont);

	GetDlgItem(IDC_EDIT_PROCESS)->SetFont(&font);

	m_edit_process.SetWindowTextW(_T("INSPECTION STAND-BY"));


	HFONT hNewFont;

	hNewFont = CreateFont(15, 10, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_MODERN, _T("IMPACT"));
	m_list_result.SendMessage(WM_SETFONT, (WPARAM)hNewFont, (LPARAM)TRUE);
	m_list_ma_x.SendMessage(WM_SETFONT, (WPARAM)hNewFont, (LPARAM)TRUE);
	m_list_ma_y.SendMessage(WM_SETFONT, (WPARAM)hNewFont, (LPARAM)TRUE);
	m_list_os.SendMessage(WM_SETFONT, (WPARAM)hNewFont, (LPARAM)TRUE);
	m_list_other.SendMessage(WM_SETFONT, (WPARAM)hNewFont, (LPARAM)TRUE);
	m_list_log.SendMessage(WM_SETFONT, (WPARAM)hNewFont, (LPARAM)TRUE);

	m_list_result.InsertColumn(1, TEXT("TAB."), LVCFMT_CENTER, 50);
	m_list_result.InsertColumn(2, TEXT("POINT"), LVCFMT_CENTER, 50);
	m_list_result.InsertColumn(3, TEXT("RESULT"), LVCFMT_CENTER, 100);

	m_list_ma_x.InsertColumn(1, TEXT("T"), LVCFMT_CENTER, 30);
	m_list_ma_x.InsertColumn(2, TEXT("P"), LVCFMT_CENTER, 30);
	m_list_ma_x.InsertColumn(3, TEXT("N"), LVCFMT_CENTER, 30);
	m_list_ma_x.InsertColumn(4, TEXT("MA_X"), LVCFMT_CENTER, 110);

	m_list_ma_y.InsertColumn(1, TEXT("T"), LVCFMT_CENTER, 30);
	m_list_ma_y.InsertColumn(2, TEXT("P"), LVCFMT_CENTER, 30);
	m_list_ma_y.InsertColumn(3, TEXT("N"), LVCFMT_CENTER, 30);
	m_list_ma_y.InsertColumn(4, TEXT("MA_Y"), LVCFMT_CENTER, 110);

	m_list_os.InsertColumn(1, TEXT("T"), LVCFMT_CENTER, 50);
	m_list_os.InsertColumn(2, TEXT("P"), LVCFMT_CENTER, 50);
	m_list_os.InsertColumn(3, TEXT("N"), LVCFMT_CENTER, 50);
	m_list_os.InsertColumn(4, TEXT("OPEN"), LVCFMT_CENTER, 130);
	m_list_os.InsertColumn(5, TEXT("SHORT"), LVCFMT_CENTER, 130);

	m_list_other.InsertColumn(1, TEXT("T"), LVCFMT_CENTER, 50);
	m_list_other.InsertColumn(2, TEXT("P"), LVCFMT_CENTER, 50);
	m_list_other.InsertColumn(3, TEXT("N"), LVCFMT_CENTER, 50);
	m_list_other.InsertColumn(4, TEXT("WIDTH"), LVCFMT_CENTER, 130);
	m_list_other.InsertColumn(5, TEXT("HEIGHT"), LVCFMT_CENTER, 130);

	m_list_log.InsertColumn(1, TEXT("Time"), LVCFMT_CENTER, 100);
	m_list_log.InsertColumn(2, TEXT("Level"), LVCFMT_CENTER, 80);
	m_list_log.InsertColumn(3, TEXT("Where"), LVCFMT_CENTER, 140);
	m_list_log.InsertColumn(4, TEXT("Message"), LVCFMT_CENTER, 300);

	log_count = 0;
	// Camera connect

	area_cam.ZoomFactor = 0.25;

	MappAlloc(M_DEFAULT, &area_cam.m_MilApplication);

	MsysAlloc(area_cam.m_MilApplication, M_SYSTEM_SOLIOS, M_DEV1, M_DEFAULT, &area_cam.m_MilSystem_Upper);
	MsysAlloc(area_cam.m_MilApplication, M_SYSTEM_SOLIOS, M_DEV0, M_DEFAULT, &area_cam.m_MilSystem_Side);

	MdigAlloc(area_cam.m_MilSystem_Upper, M_DEFAULT, MIL_TEXT("M_DEFAULT"), M_DEFAULT, &area_cam.m_MilDigitizer_Upper);
	MdigAlloc(area_cam.m_MilSystem_Side, M_DEFAULT, MIL_TEXT("M_DEFAULT"), M_DEFAULT, &area_cam.m_MilDigitizer_Side);

	MdispAlloc(area_cam.m_MilSystem_Upper, M_DEFAULT, MIL_TEXT("M_DEFAULT"), M_DEFAULT, &area_cam.m_MilDisplay_Upper);
	MdispAlloc(area_cam.m_MilSystem_Side, M_DEFAULT, MIL_TEXT("M_DEFAULT"), M_DEFAULT, &area_cam.m_MilDisplay_Side);

	// upper & side 동일
	MdigInquire(area_cam.m_MilDigitizer_Upper, M_SIZE_X, &area_cam.m_digitizerSizeX);
	MdigInquire(area_cam.m_MilDigitizer_Upper, M_SIZE_Y, &area_cam.m_digitizerSizeY);
	MdigInquire(area_cam.m_MilDigitizer_Upper, M_SIZE_BAND, &area_cam.m_digitizerNoBands);

	MbufAllocColor(area_cam.m_MilSystem_Upper, area_cam.m_digitizerNoBands, area_cam.m_digitizerSizeX, area_cam.m_digitizerSizeY, 8 + M_UNSIGNED,
		M_IMAGE + M_DISP + M_GRAB + M_PROC, &area_cam.m_MilImage_Upper);

	MbufAllocColor(area_cam.m_MilSystem_Side, area_cam.m_digitizerNoBands, area_cam.m_digitizerSizeX, area_cam.m_digitizerSizeY, 8 + M_UNSIGNED,
		M_IMAGE + M_DISP + M_GRAB + M_PROC, &area_cam.m_MilImage_Side);

	MdispZoom(area_cam.m_MilDisplay_Upper, area_cam.ZoomFactor, area_cam.ZoomFactor);
	MdispSelectWindow(area_cam.m_MilDisplay_Upper, area_cam.m_MilImage_Upper, m_pic_upper.GetSafeHwnd());

	MdispZoom(area_cam.m_MilDisplay_Side, area_cam.ZoomFactor, area_cam.ZoomFactor);
	MdispSelectWindow(area_cam.m_MilDisplay_Side, area_cam.m_MilImage_Side, m_pic_side.GetSafeHwnd());

	MdigGrabContinuous(area_cam.m_MilDigitizer_Upper, area_cam.m_MilImage_Upper);
	MdigGrabContinuous(area_cam.m_MilDigitizer_Side, area_cam.m_MilImage_Side);

	upper_camera_status = 1;
	side_camera_status = 1;

	check_alarm = 0;

	// pass tab init
	for (int i = 0; i < 30; i++)
	{
		pass_tab[i] = 0;
	}

	process_pass_tab_1 = false;
	process_pass_tab_2 = false;
	process_pass_tab_3 = false;
	process_pass_tab_4 = false;
	process_pass_tab_5 = false;
	process_pass_tab_6 = false;
	process_pass_tab_7 = false;
	process_pass_tab_8 = false;
	process_pass_tab_9 = false;
	process_pass_tab_10 = false;
	process_pass_tab_11 = false;
	process_pass_tab_12 = false;
	process_pass_tab_13 = false;
	process_pass_tab_14 = false;
	process_pass_tab_15 = false;
	process_pass_tab_16 = false;
	process_pass_tab_17 = false;
	process_pass_tab_18 = false;
	process_pass_tab_19 = false;
	process_pass_tab_20 = false;
	process_pass_tab_21 = false;
	process_pass_tab_22 = false;
	process_pass_tab_23 = false;
	process_pass_tab_24 = false;
	process_pass_tab_25 = false;
	process_pass_tab_26 = false;
	process_pass_tab_27 = false;
	process_pass_tab_28 = false;
	process_pass_tab_29 = false;
	process_pass_tab_30 = false;

	check_ng_ma_x = true;
	check_ng_ma_y = true;
	check_ng_open = true;
	check_ng_short = true;
	check_ng_width = true;
	check_ng_height = true;
	check_ng_upper_mark_1 = true;
	check_ng_upper_mark_2 = true;
	check_ng_side_mark_1 = true;
	check_ng_side_mark_2 = true;

	SetTimer(1, 1, NULL);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


BOOL DIALOG_AUTO::PreTranslateMessage(MSG* pMsg)
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


BOOL DIALOG_AUTO::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	/*CRect rect;

	GetClientRect(rect);

	pDC->FillSolidRect(rect, RGB(255, 255, 255));

	return TRUE;
	*/
	return CDialogEx::OnEraseBkgnd(pDC);
}


void DIALOG_AUTO::OnBnClickedBtnStart()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	DIALOG_CLAMP clampDlg;

	clampRet = clampDlg.DoModal();

	// OK PROCESS
	if (clampRet == 1)
	{
		// Stage Enable 여부 확인
		if (stage_main_x_status != 4194321 || stage_main_y_status != 4194321 || stage_sub_x_status != 4194321)
		{
			AfxMessageBox(_T("Check Stage_Status"));

			log_time = CTime::GetCurrentTime();
			str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), log_time.GetYear(), log_time.GetMonth(), log_time.GetDay(), log_time.GetHour(), log_time.GetMinute(), log_time.GetSecond());
			display_log(str_log_time, _T("ERROR"), _T("ALARM"), _T("Check_Stage_Status"), log_count);

			if (stage_main_x_status != 4194321)	//4194321
			{
				check_alarm = 1;
				displayAlarm(12);
			}

			if (stage_main_y_status != 4194321)
			{
				check_alarm = 1;
				displayAlarm(13);
			}

			if (stage_sub_x_status != 4194321)
			{
				check_alarm = 1;
				displayAlarm(14);
			}
		}

		// Stage Enable 상태에서 
		else if (check_alarm == 0)
		{
			Start_Time = GetTickCount();
			inspection_start_time = CTime::GetCurrentTime();
			str_inspection_start_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), inspection_start_time.GetYear(), inspection_start_time.GetMonth(),
				inspection_start_time.GetDay(), inspection_start_time.GetHour(), inspection_start_time.GetMinute(), inspection_start_time.GetSecond());

			log_time = CTime::GetCurrentTime();
			str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), log_time.GetYear(), log_time.GetMonth(), log_time.GetDay(), log_time.GetHour(), log_time.GetMinute(), log_time.GetSecond());

			display_log(str_log_time, _T("INSPECTION"), _T("PROCESS"), _T("INSPECTION_START"), log_count);
			m_edit_process.SetWindowTextW(_T("INSPECTION_START"));

			m_edit_process.SetWindowTextW(_T("INSPECTION START"));

			CString str_glass_id;

			m_edit_glass_id.GetWindowTextW(str_glass_id);


			folder_path = file_path + _T("DATA\\2. INSPECTION\\");
			folder_path = folder_path + str_glass_id + _T("_[") + str_inspection_start_time + _T("]");

			origin_path = folder_path + _T("\\ORIGIN");
			result_path = folder_path + _T("\\RESULT");

			::CreateDirectory(folder_path, NULL);
			::CreateDirectory(origin_path, NULL);
			::CreateDirectory(result_path, NULL);

			acsc_SetVelocity(hStage_auto, ACSC_AXIS_4, stage_main_x_process_speed, NULL);
			acsc_SetVelocity(hStage_auto, ACSC_AXIS_0, stage_main_y_process_speed, NULL);
			acsc_SetVelocity(hStage_auto, ACSC_AXIS_10, stage_sub_x_process_speed, NULL);

			// 검사 가능한 Tab 의 수
			possible_tab = (int)(stage_sub_x_limit_max - stage_sub_x_process_pos + tab_interval) / (tab_dist + tab_interval);

			if (tab_count <= possible_tab)
				possible_tab = tab_count;

			// 검사가 종료되는 Sub_x position
			finish_position = stage_sub_x_process_pos + (tab_dist * tab_count) + (tab_interval * (tab_count - 1));

			// Half & Half 검사를 진행할 경우 사용
			// 검사가 가능한 Tab이 종료되는 Sub_x position
			first_finish_position = stage_sub_x_process_pos + (tab_dist * possible_tab) + (tab_interval * (possible_tab - 1));

			// prealign position 이 벗어나는 경우
			if (stage_sub_x_process_pos + stage_sub_x_align_offset >= stage_sub_x_limit_max)
			{
				AfxMessageBox(_T("Check PreAlign Offset"));

				log_time = CTime::GetCurrentTime();
				str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), log_time.GetYear(), log_time.GetMonth(), log_time.GetDay(), log_time.GetHour(), log_time.GetMinute(), log_time.GetSecond());
				display_log(str_log_time, _T("ERROR"), _T("PreAlign"), _T("Check_PreAlign_Offset"), log_count);
				check_alarm = 1;

				displayAlarm(2);
			}

			else
			{
				ParameterInit();

				if (finish_position < stage_sub_x_limit_max)
				{
					log_time = CTime::GetCurrentTime();
					str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), log_time.GetYear(), log_time.GetMonth(), log_time.GetDay(), log_time.GetHour(), log_time.GetMinute(), log_time.GetSecond());
					display_log(str_log_time, _T("INSPECTION"), _T("PROCESS"), _T("INSPECTION START(at Once)"), log_count);

					Inspect = AfxBeginThread(Inspect_Thread, this);
				}

				// Limit 이상인 경우
				else if (finish_position >= stage_sub_x_limit_max)
				{
					over_pos = finish_position - first_finish_position;

					// 이동 해야 하는 값이 Stage_x 이동 가능 부분보다 큰 경우
					if (stage_main_x_limit_max - stage_main_x_process_pos > over_pos)
					{
						log_time = CTime::GetCurrentTime();
						str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), log_time.GetYear(), log_time.GetMonth(), log_time.GetDay(), log_time.GetHour(), log_time.GetMinute(), log_time.GetSecond());
						display_log(str_log_time, _T("INSPECTION"), _T("PROCESS"), _T("INSPECTION START(Half & Half)"), log_count);

						Inspect = AfxBeginThread(Inspect_Thread, this);
					}

					else if (stage_main_x_limit_max - stage_main_x_process_pos < over_pos)
					{
						AfxMessageBox(_T("Sub Stage_x limit [Check Parameter]"));

						log_time = CTime::GetCurrentTime();
						str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), log_time.GetYear(), log_time.GetMonth(), log_time.GetDay(), log_time.GetHour(), log_time.GetMinute(), log_time.GetSecond());
						display_log(str_log_time, _T("ERROR"), _T("SUB_X"), _T("Check_Sub_Stage_X Parameter"), log_count);
						check_alarm = 1;

						displayAlarm(11);
					}
				}
			}
		}

		else if (check_alarm == 1)
		{
			AfxMessageBox(_T("Check Alarm Reset"));

			log_time = CTime::GetCurrentTime();
			str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), log_time.GetYear(), log_time.GetMonth(), log_time.GetDay(), log_time.GetHour(), log_time.GetMinute(), log_time.GetSecond());
			display_log(str_log_time, _T("ERROR"), _T("ALARM"), _T("Check_Alarm_Reset"), log_count);
		}
	}

	// Unloading
	else if (clampRet == 2)
	{

	}
}


void DIALOG_AUTO::OnBnClickedBtnStop()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	check_process_stop = 2;
}


void DIALOG_AUTO::OnBnClickedBtnReset()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	log_time = CTime::GetCurrentTime();
	str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), log_time.GetYear(), log_time.GetMonth(), log_time.GetDay(), log_time.GetHour(), log_time.GetMinute(), log_time.GetSecond());
	display_log(str_log_time, _T("INSPECTION"), _T("ALARM"), _T("ALARM_RESET"), log_count);

	check_alarm = 0;
}


void DIALOG_AUTO::OnBnClickedBtnLogReset()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	m_list_log.DeleteAllItems();
	log_count = 0;
}


void DIALOG_AUTO::ParameterInit()
{
	bStart = false;	// auto 동작 start
	bStop = true;	// auto 동작 stop
	bReady = false;	// safety pos move 
	bReadyComplete = false;	// safety pos move complete
	bProcess = false;
	bProcessComplete = false;
	bPreAlign = false;	// Ready Pos move
	bPreAlignComplete = false;	// ready pos move complete
	bTabAlign = false;	// Align 실행
	bTabAlignComplete = false;	// Align complete
	bInspect = false;	// Inspect 진행 중
	bInspectComplete = false;	// Inspect 동작 완료
	bJudge = false;	// 판정 
	bJudgeComplete = false;	// 판정 완료
	bUnloading = false;	// 배출
	bUnloadingComplete = false;	// 배출 완료

	process_pass_prealign = true;
	process_pass_tabalign = true;


	check_process_stop = 0;

	check_alram_unloading = 0;

	tab_start = 0;
	align_correction = 0;

	ng_result_list_count = 0;
	ng_ma_x_list_count = 0;
	ng_ma_y_list_count = 0;
	ng_os_list_count = 0;
	ng_other_list_count = 0;

	m_list_result.DeleteAllItems();
	m_list_ma_x.DeleteAllItems();
	m_list_ma_y.DeleteAllItems();
	m_list_os.DeleteAllItems();
	m_list_other.DeleteAllItems();

	m_edit_tacktime_process.SetWindowTextW(_T("0"));
	m_edit_tacktime_align.SetWindowTextW(_T("0"));
	m_edit_tacktime_inspection.SetWindowTextW(_T("0"));
	m_edit_tacktime_judge.SetWindowTextW(_T("0"));
	m_edit_tacktime_unloading.SetWindowTextW(_T("0"));
	m_edit_tacktime_total.SetWindowTextW(_T("0"));

	for (int i = 0; i < 30; i++)
	{
		result_value.upper_num[i] = 0;
		result_value.side_num[i] = 0;

		for (int j = 0; j < 100; j++)
		{
			result_value.upper_x[i][j] = 0;
			result_value.upper_width[i][j] = 0;
			result_value.upper_y[i][j] = 0;
			result_value.upper_height[i][j] = 0;
			result_value.upper_ma_x_center[i][j] = 0;

			result_value.side_x[i][j] = 0;
			result_value.side_width[i][j] = 0;
			result_value.side_y[i][j] = 0;
			result_value.side_height[i][j] = 0;
			result_value.side_ma_x_center[i][j] = 0;
			result_value.side_ma_y_center[i][j] = 0;

			result_value.ma_x[i][j] = 0;
			result_value.ma_y[i][j] = 0;

			result_value.result_ma_x[i][j] = 0;
			result_value.result_ma_y[i][j] = 0;
			result_value.result_open[i][j] = 0;
			result_value.result_short[i][j] = 0;
			result_value.result_width[i][j] = 0;
			result_value.result_height[i][j] = 0;
		}
	}

	for (int i = 0; i < 300; i++)
	{
		result_value.total_result[i] = 0;
	}

	GetDlgItem(IDC_BTN_START)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_EMO)->EnableWindow(TRUE);
}



UINT DIALOG_AUTO::Inspect_Thread(LPVOID pParam)
{
	DIALOG_AUTO *dlg_Inspect = (DIALOG_AUTO*)pParam;

	eAutoSeq m_AutoSeq = eAutoSeq::MoveReadyPos;
	eAutoResult m_AutoResult = eAutoResult::NotYet;

	DIALOG_POPUP popupDlg;

	dlg_Inspect->bStart = true;
	dlg_Inspect->bStop = false;

	while (dlg_Inspect->bStart)
	{
		while (!dlg_Inspect->bStop)
		{
			switch (m_AutoSeq)
			{
			case MoveReadyPos:
				dlg_Inspect->m_edit_process.SetWindowTextW(_T("MOVE READY_POS"));

				dlg_Inspect->log_time = CTime::GetCurrentTime();
				dlg_Inspect->str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), dlg_Inspect->log_time.GetYear(), dlg_Inspect->log_time.GetMonth(),
					dlg_Inspect->log_time.GetDay(), dlg_Inspect->log_time.GetHour(), dlg_Inspect->log_time.GetMinute(), dlg_Inspect->log_time.GetSecond());

				dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PROCESS"), _T("Move_Ready_Pos"), dlg_Inspect->log_count);

				dlg_Inspect->bReady = true;
				dlg_Inspect->Invalidate(false);

				// Stage Y 위치 확인
				acsc_GetRPosition(dlg_Inspect->hStage_auto, ACSC_AXIS_0, &dlg_Inspect->stage_main_y_pos, NULL);

				// Gantry 간섭 영역 확인
				// Stage Y 이동 후 Stage X 이동
				if (dlg_Inspect->stage_main_y_pos > dlg_Inspect->gantry_limit_min && dlg_Inspect->stage_main_y_pos < dlg_Inspect->gantry_limit_max)
				{
					acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_0, dlg_Inspect->stage_main_y_ready_pos, NULL);
					do
					{
						acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_0, &dlg_Inspect->stage_main_y_status, NULL);
						Sleep(10);
					} while (dlg_Inspect->stage_main_y_status & ACSC_AST_MOVE);

					if (dlg_Inspect->check_process_stop == 1)
					{
						dlg_Inspect->process_stop = 1;
						return 0;
					}

					dlg_Inspect->log_time = CTime::GetCurrentTime();
					dlg_Inspect->str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), dlg_Inspect->log_time.GetYear(), dlg_Inspect->log_time.GetMonth(),
						dlg_Inspect->log_time.GetDay(), dlg_Inspect->log_time.GetHour(), dlg_Inspect->log_time.GetMinute(), dlg_Inspect->log_time.GetSecond());

					dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("STAGE_Y"), _T("Ready_Position Complete"), dlg_Inspect->log_count);

					acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_4, dlg_Inspect->stage_main_x_ready_pos, NULL);
					do
					{
						acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_4, &dlg_Inspect->stage_main_x_status, NULL);
						Sleep(10);
					} while (dlg_Inspect->stage_main_x_status & ACSC_AST_MOVE);

					if (dlg_Inspect->check_process_stop == 1)
					{
						dlg_Inspect->process_stop = 1;
						return 0;
					}

					dlg_Inspect->log_time = CTime::GetCurrentTime();
					dlg_Inspect->str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), dlg_Inspect->log_time.GetYear(), dlg_Inspect->log_time.GetMonth(),
						dlg_Inspect->log_time.GetDay(), dlg_Inspect->log_time.GetHour(), dlg_Inspect->log_time.GetMinute(), dlg_Inspect->log_time.GetSecond());

					dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("STAGE_X"), _T("Ready_Position Complete"), dlg_Inspect->log_count);
				}

				// Stage x 이동 후 Stage y 이동
				else
				{
					acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_4, dlg_Inspect->stage_main_x_ready_pos, NULL);
					do
					{
						acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_4, &dlg_Inspect->stage_main_x_status, NULL);
						Sleep(10);
					} while (dlg_Inspect->stage_main_x_status & ACSC_AST_MOVE);

					if (dlg_Inspect->check_process_stop == 1)
					{
						dlg_Inspect->process_stop = 1;
						return 0;
					}

					dlg_Inspect->log_time = CTime::GetCurrentTime();
					dlg_Inspect->str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), dlg_Inspect->log_time.GetYear(), dlg_Inspect->log_time.GetMonth(),
						dlg_Inspect->log_time.GetDay(), dlg_Inspect->log_time.GetHour(), dlg_Inspect->log_time.GetMinute(), dlg_Inspect->log_time.GetSecond());

					dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("STAGE_X"), _T("Ready_Position Complete"), dlg_Inspect->log_count);

					acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_0, dlg_Inspect->stage_main_y_ready_pos, NULL);
					do
					{
						acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_0, &dlg_Inspect->stage_main_y_status, NULL);
						Sleep(10);
					} while (dlg_Inspect->stage_main_y_status & ACSC_AST_MOVE);

					if (dlg_Inspect->check_process_stop == 1)
					{
						dlg_Inspect->process_stop = 1;
						return 0;
					}

					dlg_Inspect->log_time = CTime::GetCurrentTime();
					dlg_Inspect->str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), dlg_Inspect->log_time.GetYear(), dlg_Inspect->log_time.GetMonth(),
						dlg_Inspect->log_time.GetDay(), dlg_Inspect->log_time.GetHour(), dlg_Inspect->log_time.GetMinute(), dlg_Inspect->log_time.GetSecond());

					dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("STAGE_Y"), _T("Ready_Position Complete"), dlg_Inspect->log_count);
				}

				acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_10, dlg_Inspect->stage_sub_x_ready_pos, NULL);
				do
				{
					acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_10, &dlg_Inspect->stage_sub_x_status, NULL);
					Sleep(10);
				} while (dlg_Inspect->stage_sub_x_status & ACSC_AST_MOVE);

				dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("SUB_X"), _T("Ready_Position Complete"), dlg_Inspect->log_count);

				m_AutoSeq = eAutoSeq::ReadyPosComplete;

				break;

			case ReadyPosComplete:

				if (dlg_Inspect->check_process_stop == 1)
				{
					dlg_Inspect->process_stop = 1;
					return 0;
				}

				dlg_Inspect->m_edit_process.SetWindowTextW(_T("MOVE READY_POS COMPLETE"));

				dlg_Inspect->bReadyComplete = true;
				dlg_Inspect->Invalidate(false);

				m_AutoSeq = eAutoSeq::MoveProcessPos;
				break;

			case MoveProcessPos:

				if (dlg_Inspect->check_process_stop == 1)
				{
					dlg_Inspect->process_stop = 1;
					return 0;
				}

				dlg_Inspect->m_edit_process.SetWindowTextW(_T("MOVE PROCESS_POS"));

				dlg_Inspect->log_time = CTime::GetCurrentTime();
				dlg_Inspect->str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), dlg_Inspect->log_time.GetYear(), dlg_Inspect->log_time.GetMonth(),
					dlg_Inspect->log_time.GetDay(), dlg_Inspect->log_time.GetHour(), dlg_Inspect->log_time.GetMinute(), dlg_Inspect->log_time.GetSecond());

				dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PROCESS"), _T("Move_Process_Pos"), dlg_Inspect->log_count);

				if (m_AutoResult == NotYet)
				{
					dlg_Inspect->bProcess = true;
					dlg_Inspect->Invalidate(false);
				}

				acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_0, dlg_Inspect->stage_main_y_process_pos, NULL);
				do
				{
					acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_0, &dlg_Inspect->stage_main_y_status, NULL);
					Sleep(10);
				} while (dlg_Inspect->stage_main_y_status & ACSC_AST_MOVE);

				if (dlg_Inspect->check_process_stop == 1)
				{
					dlg_Inspect->process_stop = 1;
					return 0;
				}

				dlg_Inspect->log_time = CTime::GetCurrentTime();
				dlg_Inspect->str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), dlg_Inspect->log_time.GetYear(), dlg_Inspect->log_time.GetMonth(),
					dlg_Inspect->log_time.GetDay(), dlg_Inspect->log_time.GetHour(), dlg_Inspect->log_time.GetMinute(), dlg_Inspect->log_time.GetSecond());

				dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("STAGE_Y"), _T("Process_Position Complete"), dlg_Inspect->log_count);

				acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_4, dlg_Inspect->stage_main_x_process_pos, NULL);
				do
				{
					acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_4, &dlg_Inspect->stage_main_x_status, NULL);
					Sleep(10);
				} while (dlg_Inspect->stage_main_x_status & ACSC_AST_MOVE);

				if (dlg_Inspect->check_process_stop == 1)
				{
					dlg_Inspect->process_stop = 1;
					return 0;
				}

				dlg_Inspect->log_time = CTime::GetCurrentTime();
				dlg_Inspect->str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), dlg_Inspect->log_time.GetYear(), dlg_Inspect->log_time.GetMonth(),
					dlg_Inspect->log_time.GetDay(), dlg_Inspect->log_time.GetHour(), dlg_Inspect->log_time.GetMinute(), dlg_Inspect->log_time.GetSecond());

				dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("STAGE_X"), _T("Process_Position Complete"), dlg_Inspect->log_count);

				acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_10, dlg_Inspect->stage_sub_x_process_pos, NULL);
				do
				{
					acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_10, &dlg_Inspect->stage_sub_x_status, NULL);
					Sleep(10);
				} while (dlg_Inspect->stage_sub_x_status & ACSC_AST_MOVE);

				if (dlg_Inspect->check_process_stop == 1)
				{
					dlg_Inspect->process_stop = 1;
					return 0;
				}

				dlg_Inspect->log_time = CTime::GetCurrentTime();
				dlg_Inspect->str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), dlg_Inspect->log_time.GetYear(), dlg_Inspect->log_time.GetMonth(),
					dlg_Inspect->log_time.GetDay(), dlg_Inspect->log_time.GetHour(), dlg_Inspect->log_time.GetMinute(), dlg_Inspect->log_time.GetSecond());

				dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("SUB_X"), _T("Process_Position Complete"), dlg_Inspect->log_count);

				m_AutoSeq = eAutoSeq::ProcessPosComplete;

				break;

			case ProcessPosComplete:

				if (dlg_Inspect->check_process_stop == 1)
				{
					dlg_Inspect->process_stop = 1;
					return 0;
				}

				dlg_Inspect->m_edit_process.SetWindowTextW(_T("MOVE PROCESS_POS COMPLETE"));

				dlg_Inspect->bProcessComplete = true;
				dlg_Inspect->bPreAlign = true;

				dlg_Inspect->Invalidate(false);

				dlg_Inspect->Align_Time = GetTickCount();

				// 첫 검사인 경우 Pre Align 도 진행
				if (m_AutoResult == NotYet)
				{
					if (dlg_Inspect->process_pass_prealign == true)
					{
						dlg_Inspect->m_edit_process.SetWindowTextW(_T("PRE ALIGN PASS"));

						dlg_Inspect->log_time = CTime::GetCurrentTime();
						dlg_Inspect->str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), dlg_Inspect->log_time.GetYear(), dlg_Inspect->log_time.GetMonth(),
							dlg_Inspect->log_time.GetDay(), dlg_Inspect->log_time.GetHour(), dlg_Inspect->log_time.GetMinute(), dlg_Inspect->log_time.GetSecond());

						dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PRE_ALIGN"), _T("Pre_Align_Pass_Mode"), dlg_Inspect->log_count);

						m_AutoSeq = eAutoSeq::PreAlignComplete;
					}
					else if (dlg_Inspect->process_pass_prealign == false)
						m_AutoSeq = eAutoSeq::PreAlign;
				}


				// 두 번째 검사인 경우 PreAlign은 진행하지 않고 Tab Align 으로 바로
				else if (m_AutoResult == FirstFinish)
					m_AutoSeq = eAutoSeq::MoveTabAlignPos;

				break;

			case PreAlign:
				if (dlg_Inspect->check_process_stop == 1)
				{
					dlg_Inspect->process_stop = 1;
					return 0;
				}

				dlg_Inspect->m_edit_process.SetWindowTextW(_T("PRE_ALIGN [LEFT]"));

				// Align 진행
				dlg_Inspect->ImageAlign(1);

				// Matching percent 확인
				if (dlg_Inspect->maxVal_align * 100 > dlg_Inspect->prealign_matching)
				{
					dlg_Inspect->align_x_start = dlg_Inspect->maxLoc_align.x * 2;
					dlg_Inspect->align_width = dlg_Inspect->align_x_start + dlg_Inspect->resize_upper_mark.cols * 2;
					dlg_Inspect->align_y_start = dlg_Inspect->maxLoc_align.y * 2;
					dlg_Inspect->align_height = dlg_Inspect->align_y_start + dlg_Inspect->resize_upper_mark.rows * 2;

					rectangle(dlg_Inspect->load_align_image, Point(dlg_Inspect->align_x_start, dlg_Inspect->align_y_start),
						Point(dlg_Inspect->align_width, dlg_Inspect->align_height), Scalar(0, 255, 0), 8, 8, 0);

					CString saveTitle = _T("Data\\1. ALIGN\\4. OK\\1. PREALIGN\\");
					saveTitle = saveTitle + dlg_Inspect->str_inspection_start_time + _T(".bmp");

					dlg_Inspect->log_time = CTime::GetCurrentTime();
					dlg_Inspect->str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), dlg_Inspect->log_time.GetYear(), dlg_Inspect->log_time.GetMonth(),
						dlg_Inspect->log_time.GetDay(), dlg_Inspect->log_time.GetHour(), dlg_Inspect->log_time.GetMinute(), dlg_Inspect->log_time.GetSecond());

					CString pa_str;

					pa_str.Format(_T("[P]Align Mark Matching(Left) : %.2f [OK]"), dlg_Inspect->maxVal_align * 100);

					dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PRE_ALIGN"), pa_str, dlg_Inspect->log_count);

					CT2CA pszConvertedAnsiString(saveTitle);
					std::string writeTitle(pszConvertedAnsiString);

					imwrite(writeTitle, dlg_Inspect->load_align_image);

					StretchDIBits(dlg_Inspect->hdc_upper, 0, 0, 512, 512, 0, 0, dlg_Inspect->load_align_image.cols, dlg_Inspect->load_align_image.rows,
						dlg_Inspect->load_align_image.data, dlg_Inspect->loadInfo, DIB_RGB_COLORS, SRCCOPY);
				}

				// 검출 실패
				// Manual 검사 진행
				else if (dlg_Inspect->maxVal_align * 100 < dlg_Inspect->prealign_matching)
				{
					// 취소 클릭 시 기존 값 대로 align 진행
					dlg_Inspect->align_x_start = dlg_Inspect->maxLoc_align.x * 2;
					dlg_Inspect->align_width = dlg_Inspect->align_x_start + dlg_Inspect->resize_upper_mark.cols * 2;
					dlg_Inspect->align_y_start = dlg_Inspect->maxLoc_align.y * 2;
					dlg_Inspect->align_height = dlg_Inspect->align_y_start + dlg_Inspect->resize_upper_mark.rows * 2;

					rectangle(dlg_Inspect->load_align_image, Point(dlg_Inspect->align_x_start, dlg_Inspect->align_y_start),
						Point(dlg_Inspect->align_width, dlg_Inspect->align_height), Scalar(0, 0, 255), 8, 8, 0);

					CString saveTitle = _T("Data\\1. ALIGN\\3. NG\\1. PREALIGN\\");
					saveTitle = saveTitle + dlg_Inspect->str_inspection_start_time + _T(".bmp");

					dlg_Inspect->log_time = CTime::GetCurrentTime();
					dlg_Inspect->str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), dlg_Inspect->log_time.GetYear(), dlg_Inspect->log_time.GetMonth(),
						dlg_Inspect->log_time.GetDay(), dlg_Inspect->log_time.GetHour(), dlg_Inspect->log_time.GetMinute(), dlg_Inspect->log_time.GetSecond());

					CString pa_str;

					pa_str.Format(_T("[P]Align Mark Matching(Left) : %.2f [NG]"), dlg_Inspect->maxVal_align * 100);

					dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PRE_ALIGN"), pa_str, dlg_Inspect->log_count);

					CT2CA pszConvertedAnsiString(saveTitle);
					std::string writeTitle(pszConvertedAnsiString);

					imwrite(writeTitle, dlg_Inspect->load_align_image);

					// 영역 재 설정 후 확인 클릭하면 새로운 값으로 align 진행
					DIALOG_MANUAL_ALIGN dlg;

					dlg.alignCase = 1;	// prealign
					dlg.file_name = writeTitle;

					dlg_Inspect->iRet = dlg.DoModal();

					if (dlg_Inspect->iRet == 1)
					{
						dlg_Inspect->align_x_start = dlg.x1;
						dlg_Inspect->align_width = dlg.x2;
						dlg_Inspect->align_y_start = dlg.y1;
						dlg_Inspect->align_height = dlg.y2;

						dlg_Inspect->log_time = CTime::GetCurrentTime();
						dlg_Inspect->str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), dlg_Inspect->log_time.GetYear(), dlg_Inspect->log_time.GetMonth(),
							dlg_Inspect->log_time.GetDay(), dlg_Inspect->log_time.GetHour(), dlg_Inspect->log_time.GetMinute(), dlg_Inspect->log_time.GetSecond());

						dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PRE_ALIGN"), _T("Manual Alignment(Left)"), dlg_Inspect->log_count);
					}

					if (dlg_Inspect->iRet == 2)
					{
						dlg_Inspect->errorRet = popupDlg.DoModal();

						// OK PROCESS
						if (dlg_Inspect->errorRet == 1)
						{
							m_AutoSeq = eAutoSeq::PreAlignComplete;
						}

						// Unloading
						else if (dlg_Inspect->errorRet == 2)
						{
							m_AutoSeq = eAutoSeq::Unloading;
							dlg_Inspect->check_alram_unloading = 1;
						}
						break;
					}
				}

				MdigGrabContinuous(dlg_Inspect->area_cam.m_MilDigitizer_Upper, dlg_Inspect->area_cam.m_MilImage_Upper);
				MdigGrabContinuous(dlg_Inspect->area_cam.m_MilDigitizer_Side, dlg_Inspect->area_cam.m_MilImage_Side);

				// align 오차 계산 (left)
				dlg_Inspect->prealign_pos_left = (dlg_Inspect->align_y_start + dlg_Inspect->resize_upper_mark.rows);

				dlg_Inspect->m_edit_process.SetWindowTextW(_T("MOVE PRE_ALIGN POS[RIGHT]"));

				if (dlg_Inspect->check_process_stop == 1)
				{
					dlg_Inspect->process_stop = 1;
					return 0;
				}

				// 다음 glass mark 위치로 이동 (align offset 적용)
				acsc_ToPoint(dlg_Inspect->hStage_auto, ACSC_AMF_RELATIVE, ACSC_AXIS_10, dlg_Inspect->stage_sub_x_align_offset, NULL);
				do
				{
					acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_10, &dlg_Inspect->stage_sub_x_status, NULL);
					Sleep(10);
				} while (dlg_Inspect->stage_sub_x_status & ACSC_AST_MOVE);

				if (dlg_Inspect->check_process_stop == 1)
				{
					dlg_Inspect->process_stop = 1;
					return 0;
				}

				dlg_Inspect->log_time = CTime::GetCurrentTime();
				dlg_Inspect->str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), dlg_Inspect->log_time.GetYear(), dlg_Inspect->log_time.GetMonth(),
					dlg_Inspect->log_time.GetDay(), dlg_Inspect->log_time.GetHour(), dlg_Inspect->log_time.GetMinute(), dlg_Inspect->log_time.GetSecond());

				dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PRE_ALIGN"), _T("Pre_Align Pos(Right) Move"), dlg_Inspect->log_count);

				// Align 진행
				dlg_Inspect->m_edit_process.SetWindowTextW(_T("PRE_ALIGN [RIGHT]"));

				dlg_Inspect->ImageAlign(1);

				// 검출이 성공한 경우

				if (dlg_Inspect->maxVal_align * 100 > dlg_Inspect->prealign_matching)
				{
					dlg_Inspect->align_x_start = dlg_Inspect->maxLoc_align.x * 2;
					dlg_Inspect->align_width = dlg_Inspect->align_x_start + dlg_Inspect->resize_upper_mark.cols * 2;
					dlg_Inspect->align_y_start = dlg_Inspect->maxLoc_align.y * 2;
					dlg_Inspect->align_height = dlg_Inspect->align_y_start + dlg_Inspect->resize_upper_mark.rows * 2;

					rectangle(dlg_Inspect->load_align_image, Point(dlg_Inspect->align_x_start, dlg_Inspect->align_y_start),
						Point(dlg_Inspect->align_width, dlg_Inspect->align_height), Scalar(0, 255, 0), 8, 8, 0);

					CString saveTitle = _T("Data\\1. ALIGN\\4. OK\\1. PREALIGN\\");
					saveTitle = saveTitle + dlg_Inspect->str_inspection_start_time + _T(".bmp");

					dlg_Inspect->log_time = CTime::GetCurrentTime();
					dlg_Inspect->str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), dlg_Inspect->log_time.GetYear(), dlg_Inspect->log_time.GetMonth(),
						dlg_Inspect->log_time.GetDay(), dlg_Inspect->log_time.GetHour(), dlg_Inspect->log_time.GetMinute(), dlg_Inspect->log_time.GetSecond());

					CString pa_str;
					pa_str.Format(_T("[P]Align Mark Matching(Right) : %.2f [OK]"), dlg_Inspect->maxVal_align * 100);
					dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PRE_ALIGN"), pa_str, dlg_Inspect->log_count);

					CT2CA pszConvertedAnsiString(saveTitle);
					std::string writeTitle(pszConvertedAnsiString);

					imwrite(writeTitle, dlg_Inspect->load_align_image);

					StretchDIBits(dlg_Inspect->hdc_upper, 0, 0, 512, 512, 0, 0, dlg_Inspect->load_align_image.cols, dlg_Inspect->load_align_image.rows,
						dlg_Inspect->load_align_image.data, dlg_Inspect->loadInfo, DIB_RGB_COLORS, SRCCOPY);
				}

				// 검출 실패
				// Manual 검사 진행
				else if (dlg_Inspect->maxVal_align * 100 < dlg_Inspect->prealign_matching)
				{

					// 취소 클릭 시 기존 값 대로 align 진행
					dlg_Inspect->align_x_start = dlg_Inspect->maxLoc_align.x * 2;
					dlg_Inspect->align_width = dlg_Inspect->align_x_start + dlg_Inspect->resize_upper_mark.cols * 2;
					dlg_Inspect->align_y_start = dlg_Inspect->maxLoc_align.y * 2;
					dlg_Inspect->align_height = dlg_Inspect->align_y_start + dlg_Inspect->resize_upper_mark.rows * 2;

					rectangle(dlg_Inspect->load_align_image, Point(dlg_Inspect->align_x_start, dlg_Inspect->align_y_start),
						Point(dlg_Inspect->align_width, dlg_Inspect->align_height), Scalar(0, 0, 255), 8, 8, 0);

					CString saveTitle = _T("Data\\1. ALIGN\\3. NG\\1. PREALIGN\\");
					saveTitle = saveTitle + dlg_Inspect->str_inspection_start_time + _T(".bmp");

					dlg_Inspect->log_time = CTime::GetCurrentTime();
					dlg_Inspect->str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), dlg_Inspect->log_time.GetYear(), dlg_Inspect->log_time.GetMonth(),
						dlg_Inspect->log_time.GetDay(), dlg_Inspect->log_time.GetHour(), dlg_Inspect->log_time.GetMinute(), dlg_Inspect->log_time.GetSecond());

					CString pa_str;
					pa_str.Format(_T("[P]Align Mark Matching(Right) : %.2f [NG]"), dlg_Inspect->maxVal_align * 100);
					dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PRE_ALIGN"), pa_str, dlg_Inspect->log_count);

					CT2CA pszConvertedAnsiString(saveTitle);
					std::string writeTitle(pszConvertedAnsiString);

					imwrite(writeTitle, dlg_Inspect->load_align_image);

					// 영역 재 설정 후 확인 클릭하면 새로운 값으로 align 진행
					DIALOG_MANUAL_ALIGN dlg;

					dlg.alignCase = 1;	// prealign
					dlg.file_name = writeTitle;

					dlg_Inspect->iRet = dlg.DoModal();

					if (dlg_Inspect->iRet == 1)
					{
						dlg_Inspect->align_x_start = dlg.x1;
						dlg_Inspect->align_width = dlg.x2;
						dlg_Inspect->align_y_start = dlg.y1;
						dlg_Inspect->align_height = dlg.y2;

						dlg_Inspect->log_time = CTime::GetCurrentTime();
						dlg_Inspect->str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), dlg_Inspect->log_time.GetYear(), dlg_Inspect->log_time.GetMonth(),
							dlg_Inspect->log_time.GetDay(), dlg_Inspect->log_time.GetHour(), dlg_Inspect->log_time.GetMinute(), dlg_Inspect->log_time.GetSecond());

						dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PRE_ALIGN"), _T("Manual Alignment(Right)"), dlg_Inspect->log_count);
					}

					if (dlg_Inspect->iRet == 2)
					{
						dlg_Inspect->errorRet = popupDlg.DoModal();

						// OK PROCESS
						if (dlg_Inspect->errorRet == 1)
							m_AutoSeq = eAutoSeq::PreAlignComplete;

						// Unloading
						else if (dlg_Inspect->errorRet == 2)
						{
							m_AutoSeq = eAutoSeq::Unloading;
							dlg_Inspect->check_alram_unloading = 1;
						}

						break;
					}
				}

				MdigGrabContinuous(dlg_Inspect->area_cam.m_MilDigitizer_Upper, dlg_Inspect->area_cam.m_MilImage_Upper);
				MdigGrabContinuous(dlg_Inspect->area_cam.m_MilDigitizer_Side, dlg_Inspect->area_cam.m_MilImage_Side);

				dlg_Inspect->prealign_pos_right = (dlg_Inspect->align_y_start + dlg_Inspect->resize_upper_mark.rows);

				// Pre Align 오차 정도가 허용치 이내인 경우
				if (abs(dlg_Inspect->prealign_pos_left - dlg_Inspect->prealign_pos_right) < (dlg_Inspect->prealign_range / 0.55))
				{
					m_AutoSeq = eAutoSeq::PreAlignComplete;
				}

				// 아닌 경우
				else
				{
					dlg_Inspect->errorRet = popupDlg.DoModal();

					// OK PROCESS
					if (dlg_Inspect->errorRet == 1)
						m_AutoSeq = eAutoSeq::PreAlignComplete;

					// Unloading
					else if (dlg_Inspect->errorRet == 2)
					{
						m_AutoSeq = eAutoSeq::Unloading;
						dlg_Inspect->check_alram_unloading = 1;
					}

					break;
				}

				break;

			case PreAlignComplete:

				dlg_Inspect->m_edit_process.SetWindowTextW(_T("PRE_ALIGN COMPLETE"));

				dlg_Inspect->log_time = CTime::GetCurrentTime();
				dlg_Inspect->str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), dlg_Inspect->log_time.GetYear(), dlg_Inspect->log_time.GetMonth(),
					dlg_Inspect->log_time.GetDay(), dlg_Inspect->log_time.GetHour(), dlg_Inspect->log_time.GetMinute(), dlg_Inspect->log_time.GetSecond());

				dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PRE_ALIGN"), _T("Pre_Align Complete"), dlg_Inspect->log_count);

				dlg_Inspect->bPreAlignComplete = true;
				dlg_Inspect->Invalidate(false);

				m_AutoSeq = eAutoSeq::MoveTabAlignPos;
				break;

			case MoveTabAlignPos:

				dlg_Inspect->m_edit_process.SetWindowTextW(_T("MOVE TAB_ALIGN POS"));

				dlg_Inspect->bTabAlign = true;
				dlg_Inspect->Invalidate(false);

				acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_10, dlg_Inspect->stage_sub_x_process_pos, NULL);
				do
				{
					acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_10, &dlg_Inspect->stage_sub_x_status, NULL);
					Sleep(10);
				} while (dlg_Inspect->stage_sub_x_status & ACSC_AST_MOVE);

				dlg_Inspect->m_edit_process.SetWindowTextW(_T("MOVE TAB_ALIGN POS COMPLETE"));

				dlg_Inspect->log_time = CTime::GetCurrentTime();
				dlg_Inspect->str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), dlg_Inspect->log_time.GetYear(), dlg_Inspect->log_time.GetMonth(),
					dlg_Inspect->log_time.GetDay(), dlg_Inspect->log_time.GetHour(), dlg_Inspect->log_time.GetMinute(), dlg_Inspect->log_time.GetSecond());

				dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("TAB_ALIGN"), _T("Move Tab Align Pos"), dlg_Inspect->log_count);

				m_AutoSeq = eAutoSeq::TabAlignPosComplete;

				break;

			case TabAlignPosComplete:

				if (dlg_Inspect->process_pass_tabalign == true)
				{
					dlg_Inspect->m_edit_process.SetWindowTextW(_T("TAB_ALIGN PASS"));
					m_AutoSeq = eAutoSeq::TabAlignComplete;
				}

				else if (dlg_Inspect->process_pass_tabalign == false)
					m_AutoSeq = eAutoSeq::TabAlign;

				break;

			case TabAlign:

				dlg_Inspect->m_edit_process.SetWindowTextW(_T("TAB_ALIGN"));

				// mark align
				dlg_Inspect->ImageAlign(2);

				// 검출이 성공한 경우
				if (dlg_Inspect->maxVal_align * 100 > dlg_Inspect->tabalign_matching)
				{
					dlg_Inspect->align_x_start = dlg_Inspect->maxLoc_align.x * 2;
					dlg_Inspect->align_width = dlg_Inspect->align_x_start + dlg_Inspect->resize_upper_mark.cols * 2;
					dlg_Inspect->align_y_start = dlg_Inspect->maxLoc_align.y * 2;
					dlg_Inspect->align_height = dlg_Inspect->align_y_start + dlg_Inspect->resize_upper_mark.rows * 2;

					rectangle(dlg_Inspect->load_align_image, Point(dlg_Inspect->align_x_start, dlg_Inspect->align_y_start),
						Point(dlg_Inspect->align_width, dlg_Inspect->align_height), Scalar(0, 255, 0), 8, 8, 0);

					CString saveTitle = _T("Data\\1. ALIGN\\4. OK\\2. TABALIGN\\");
					saveTitle = saveTitle + dlg_Inspect->str_inspection_start_time + _T(".bmp");

					dlg_Inspect->log_time = CTime::GetCurrentTime();
					dlg_Inspect->str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), dlg_Inspect->log_time.GetYear(), dlg_Inspect->log_time.GetMonth(),
						dlg_Inspect->log_time.GetDay(), dlg_Inspect->log_time.GetHour(), dlg_Inspect->log_time.GetMinute(), dlg_Inspect->log_time.GetSecond());

					CString ta_str;
					ta_str.Format(_T("[T]Align Mark Matching : %.2f [OK]"), dlg_Inspect->maxVal_align * 100);
					dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("Tab_ALIGN"), ta_str, dlg_Inspect->log_count);

					CT2CA pszConvertedAnsiString(saveTitle);
					std::string writeTitle(pszConvertedAnsiString);

					imwrite(writeTitle, dlg_Inspect->load_align_image);

					StretchDIBits(dlg_Inspect->hdc_upper, 0, 0, 512, 512, 0, 0, dlg_Inspect->load_align_image.cols, dlg_Inspect->load_align_image.rows,
						dlg_Inspect->load_align_image.data, dlg_Inspect->loadInfo, DIB_RGB_COLORS, SRCCOPY);
				}

				// 검출 실패
				// Manual 검사 진행
				else if (dlg_Inspect->maxVal_align * 100 < dlg_Inspect->tabalign_matching)
				{

					// 취소 클릭 시 기존 값 대로 align 진행
					dlg_Inspect->align_x_start = dlg_Inspect->maxLoc_align.x * 2;
					dlg_Inspect->align_width = dlg_Inspect->align_x_start + dlg_Inspect->resize_upper_mark.cols * 2;
					dlg_Inspect->align_y_start = dlg_Inspect->maxLoc_align.y * 2;
					dlg_Inspect->align_height = dlg_Inspect->align_y_start + dlg_Inspect->resize_upper_mark.rows * 2;

					rectangle(dlg_Inspect->load_align_image, Point(dlg_Inspect->align_x_start, dlg_Inspect->align_y_start),
						Point(dlg_Inspect->align_width, dlg_Inspect->align_height), Scalar(0, 0, 255), 8, 8, 0);

					CString saveTitle = _T("Data\\1. ALIGN\\3. NG\\2. TABALIGN\\");
					saveTitle = saveTitle + dlg_Inspect->str_inspection_start_time + _T(".bmp");

					dlg_Inspect->log_time = CTime::GetCurrentTime();
					dlg_Inspect->str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), dlg_Inspect->log_time.GetYear(), dlg_Inspect->log_time.GetMonth(),
						dlg_Inspect->log_time.GetDay(), dlg_Inspect->log_time.GetHour(), dlg_Inspect->log_time.GetMinute(), dlg_Inspect->log_time.GetSecond());

					CString ta_str;
					ta_str.Format(_T("[T]Align Mark Matching : %.2f [NG]"), dlg_Inspect->maxVal_align * 100);
					dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("Tab_ALIGN"), ta_str, dlg_Inspect->log_count);

					CT2CA pszConvertedAnsiString(saveTitle);
					std::string writeTitle(pszConvertedAnsiString);

					imwrite(writeTitle, dlg_Inspect->load_align_image);

					// 영역 재 설정 후 확인 클릭하면 새로운 값으로 align 진행
					DIALOG_MANUAL_ALIGN dlg;
					dlg.alignCase = 1;	// prealign
					dlg.file_name = writeTitle;

					dlg_Inspect->iRet = dlg.DoModal();

					if (dlg_Inspect->iRet == 1)
					{
						dlg_Inspect->align_x_start = dlg.x1;
						dlg_Inspect->align_width = dlg.x2;
						dlg_Inspect->align_y_start = dlg.y1;
						dlg_Inspect->align_height = dlg.y2;

						dlg_Inspect->log_time = CTime::GetCurrentTime();
						dlg_Inspect->str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), dlg_Inspect->log_time.GetYear(), dlg_Inspect->log_time.GetMonth(),
							dlg_Inspect->log_time.GetDay(), dlg_Inspect->log_time.GetHour(), dlg_Inspect->log_time.GetMinute(), dlg_Inspect->log_time.GetSecond());

						dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("TAB_ALIGN"), _T("Manual Alignment"), dlg_Inspect->log_count);
					}

					if (dlg_Inspect->iRet == 2)
					{
						dlg_Inspect->errorRet = popupDlg.DoModal();

						// OK PROCESS
						if (dlg_Inspect->errorRet == 1)
							m_AutoSeq = eAutoSeq::TabAlignComplete;

						// Unloading
						else if (dlg_Inspect->errorRet == 2)
						{
							m_AutoSeq = eAutoSeq::Unloading;
							dlg_Inspect->check_alram_unloading = 1;
						}

						break;
					}
				}

				MdigGrabContinuous(dlg_Inspect->area_cam.m_MilDigitizer_Upper, dlg_Inspect->area_cam.m_MilImage_Upper);
				MdigGrabContinuous(dlg_Inspect->area_cam.m_MilDigitizer_Side, dlg_Inspect->area_cam.m_MilImage_Side);

				// align 오차 계산
				dlg_Inspect->align_correction = (1024 - (dlg_Inspect->align_x_start + dlg_Inspect->resize_upper_mark.cols)) * 0.00055;

				// 계산한 오차 값으로 검사 시작 위치 설정
				acsc_ToPoint(dlg_Inspect->hStage_auto, ACSC_AMF_RELATIVE, ACSC_AXIS_10, dlg_Inspect->align_correction, NULL);
				do
				{
					acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_10, &dlg_Inspect->stage_sub_x_status, NULL);
					Sleep(100);
				} while (dlg_Inspect->stage_sub_x_status & ACSC_AST_MOVE);

				m_AutoSeq = eAutoSeq::TabAlignComplete;

				break;

			case TabAlignComplete:

				dlg_Inspect->m_edit_process.SetWindowTextW(_T("TAB_ALIGN COMPLETE"));

				dlg_Inspect->log_time = CTime::GetCurrentTime();
				dlg_Inspect->str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), dlg_Inspect->log_time.GetYear(), dlg_Inspect->log_time.GetMonth(),
					dlg_Inspect->log_time.GetDay(), dlg_Inspect->log_time.GetHour(), dlg_Inspect->log_time.GetMinute(), dlg_Inspect->log_time.GetSecond());

				dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("TAB_ALIGN"), _T("Tab_Align Complete"), dlg_Inspect->log_count);

				dlg_Inspect->bTabAlignComplete = true;
				dlg_Inspect->Invalidate(false);

				dlg_Inspect->tab_start_point = dlg_Inspect->stage_sub_x_process_pos - dlg_Inspect->align_correction;

				m_AutoSeq = eAutoSeq::MoveInspectionPos;

				break;

			case MoveInspectionPos:

				dlg_Inspect->m_edit_process.SetWindowTextW(_T("MOVE INSPECTION_POS"));

				dlg_Inspect->bInspect = true;
				dlg_Inspect->Invalidate(false);

				m_AutoSeq = eAutoSeq::Inspection;

				break;

			case Inspection:

				dlg_Inspect->process_af_check = 1;

				Sleep(2000);

				dlg_Inspect->m_edit_process.SetWindowTextW(_T("MOVE INSPECTION_POS COMPLETE"));

				dlg_Inspect->log_time = CTime::GetCurrentTime();
				dlg_Inspect->str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), dlg_Inspect->log_time.GetYear(), dlg_Inspect->log_time.GetMonth(),
					dlg_Inspect->log_time.GetDay(), dlg_Inspect->log_time.GetHour(), dlg_Inspect->log_time.GetMinute(), dlg_Inspect->log_time.GetSecond());

				dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("INSPECTION"), _T("Inspection Start"), dlg_Inspect->log_count);


				if (m_AutoResult == NotYet)
				{
					dlg_Inspect->Inspect_Time = GetTickCount();

					// Tab Point 간격 설정
					if (dlg_Inspect->tab_point == 1)
						dlg_Inspect->tab_step = dlg_Inspect->tab_dist;

					else if (dlg_Inspect->tab_point > 1)
						dlg_Inspect->tab_step = dlg_Inspect->tab_dist / (dlg_Inspect->tab_point - 1);
				}

				for (int tab = dlg_Inspect->tab_start; tab < dlg_Inspect->possible_tab; tab++)
				{
					dlg_Inspect->log_time = CTime::GetCurrentTime();
					dlg_Inspect->str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), dlg_Inspect->log_time.GetYear(), dlg_Inspect->log_time.GetMonth(),
						dlg_Inspect->log_time.GetDay(), dlg_Inspect->log_time.GetHour(), dlg_Inspect->log_time.GetMinute(), dlg_Inspect->log_time.GetSecond());

					if (tab == 0 && dlg_Inspect->process_pass_tab_1 == true)
					{
						dlg_Inspect->m_edit_process.SetWindowTextW(_T("INSPECTION [TAB_1_PASS]"));

						dlg_Inspect->tab_start_point = dlg_Inspect->tab_start_point + dlg_Inspect->tab_dist + dlg_Inspect->tab_interval;
						dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PROCESS_TAB"), _T("TAB_1_PASS"), dlg_Inspect->log_count);

						acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_10, dlg_Inspect->tab_start_point, NULL);
						do
						{
							acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_10, &dlg_Inspect->stage_sub_x_status, NULL);
							Sleep(10);
						} while (dlg_Inspect->stage_sub_x_status & ACSC_AST_MOVE);
					}

					else if (tab == 1 && dlg_Inspect->process_pass_tab_2 == true)
					{
						dlg_Inspect->m_edit_process.SetWindowTextW(_T("INSPECTION [TAB_2_PASS]"));

						dlg_Inspect->tab_start_point = dlg_Inspect->tab_start_point + dlg_Inspect->tab_dist + dlg_Inspect->tab_interval;
						dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PROCESS_TAB"), _T("TAB_2_PASS"), dlg_Inspect->log_count);

						acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_10, dlg_Inspect->tab_start_point, NULL);
						do
						{
							acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_10, &dlg_Inspect->stage_sub_x_status, NULL);
							Sleep(10);
						} while (dlg_Inspect->stage_sub_x_status & ACSC_AST_MOVE);
					}

					else if (tab == 2 && dlg_Inspect->process_pass_tab_3 == true)
					{
						dlg_Inspect->m_edit_process.SetWindowTextW(_T("INSPECTION [TAB_3_PASS]"));

						dlg_Inspect->tab_start_point = dlg_Inspect->tab_start_point + dlg_Inspect->tab_dist + dlg_Inspect->tab_interval;
						dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PROCESS_TAB"), _T("TAB_3_PASS"), dlg_Inspect->log_count);

						acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_10, dlg_Inspect->tab_start_point, NULL);
						do
						{
							acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_10, &dlg_Inspect->stage_sub_x_status, NULL);
							Sleep(10);
						} while (dlg_Inspect->stage_sub_x_status & ACSC_AST_MOVE);
					}

					else if (tab == 3 && dlg_Inspect->process_pass_tab_4 == true)
					{
						dlg_Inspect->m_edit_process.SetWindowTextW(_T("INSPECTION [TAB_4_PASS]"));

						dlg_Inspect->tab_start_point = dlg_Inspect->tab_start_point + dlg_Inspect->tab_dist + dlg_Inspect->tab_interval;
						dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PROCESS_TAB"), _T("TAB_4_PASS"), dlg_Inspect->log_count);

						acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_10, dlg_Inspect->tab_start_point, NULL);
						do
						{
							acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_10, &dlg_Inspect->stage_sub_x_status, NULL);
							Sleep(10);
						} while (dlg_Inspect->stage_sub_x_status & ACSC_AST_MOVE);
					}

					else if (tab == 4 && dlg_Inspect->process_pass_tab_5 == true)
					{
						dlg_Inspect->m_edit_process.SetWindowTextW(_T("INSPECTION [TAB_5_PASS]"));

						dlg_Inspect->tab_start_point = dlg_Inspect->tab_start_point + dlg_Inspect->tab_dist + dlg_Inspect->tab_interval;
						dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PROCESS_TAB"), _T("TAB_5_PASS"), dlg_Inspect->log_count);

						acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_10, dlg_Inspect->tab_start_point, NULL);
						do
						{
							acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_10, &dlg_Inspect->stage_sub_x_status, NULL);
							Sleep(10);
						} while (dlg_Inspect->stage_sub_x_status & ACSC_AST_MOVE);
					}

					else if (tab == 5 && dlg_Inspect->process_pass_tab_6 == true)
					{
						dlg_Inspect->m_edit_process.SetWindowTextW(_T("INSPECTION [TAB_6_PASS]"));

						dlg_Inspect->tab_start_point = dlg_Inspect->tab_start_point + dlg_Inspect->tab_dist + dlg_Inspect->tab_interval;
						dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PROCESS_TAB"), _T("TAB_6_PASS"), dlg_Inspect->log_count);

						acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_10, dlg_Inspect->tab_start_point, NULL);
						do
						{
							acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_10, &dlg_Inspect->stage_sub_x_status, NULL);
							Sleep(10);
						} while (dlg_Inspect->stage_sub_x_status & ACSC_AST_MOVE);
					}

					else if (tab == 6 && dlg_Inspect->process_pass_tab_7 == true)
					{
						dlg_Inspect->m_edit_process.SetWindowTextW(_T("INSPECTION [TAB_7_PASS]"));

						dlg_Inspect->tab_start_point = dlg_Inspect->tab_start_point + dlg_Inspect->tab_dist + dlg_Inspect->tab_interval;
						dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PROCESS_TAB"), _T("TAB_7_PASS"), dlg_Inspect->log_count);

						acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_10, dlg_Inspect->tab_start_point, NULL);
						do
						{
							acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_10, &dlg_Inspect->stage_sub_x_status, NULL);
							Sleep(10);
						} while (dlg_Inspect->stage_sub_x_status & ACSC_AST_MOVE);
					}

					else if (tab == 7 && dlg_Inspect->process_pass_tab_8 == true)
					{
						dlg_Inspect->m_edit_process.SetWindowTextW(_T("INSPECTION [TAB_8_PASS]"));

						dlg_Inspect->tab_start_point = dlg_Inspect->tab_start_point + dlg_Inspect->tab_dist + dlg_Inspect->tab_interval;
						dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PROCESS_TAB"), _T("TAB_8_PASS"), dlg_Inspect->log_count);

						acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_10, dlg_Inspect->tab_start_point, NULL);
						do
						{
							acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_10, &dlg_Inspect->stage_sub_x_status, NULL);
							Sleep(10);
						} while (dlg_Inspect->stage_sub_x_status & ACSC_AST_MOVE);
					}

					else if (tab == 8 && dlg_Inspect->process_pass_tab_9 == true)
					{
						dlg_Inspect->m_edit_process.SetWindowTextW(_T("INSPECTION [TAB_9_PASS]"));

						dlg_Inspect->tab_start_point = dlg_Inspect->tab_start_point + dlg_Inspect->tab_dist + dlg_Inspect->tab_interval;
						dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PROCESS_TAB"), _T("TAB_9_PASS"), dlg_Inspect->log_count);

						acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_10, dlg_Inspect->tab_start_point, NULL);
						do
						{
							acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_10, &dlg_Inspect->stage_sub_x_status, NULL);
							Sleep(10);
						} while (dlg_Inspect->stage_sub_x_status & ACSC_AST_MOVE);
					}

					else if (tab == 9 && dlg_Inspect->process_pass_tab_10 == true)
					{
						dlg_Inspect->m_edit_process.SetWindowTextW(_T("INSPECTION [TAB_10_PASS]"));

						dlg_Inspect->tab_start_point = dlg_Inspect->tab_start_point + dlg_Inspect->tab_dist + dlg_Inspect->tab_interval;
						dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PROCESS_TAB"), _T("TAB_10_PASS"), dlg_Inspect->log_count);

						acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_10, dlg_Inspect->tab_start_point, NULL);
						do
						{
							acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_10, &dlg_Inspect->stage_sub_x_status, NULL);
							Sleep(10);
						} while (dlg_Inspect->stage_sub_x_status & ACSC_AST_MOVE);
					}

					else if (tab == 10 && dlg_Inspect->process_pass_tab_11 == true)
					{
						dlg_Inspect->m_edit_process.SetWindowTextW(_T("INSPECTION [TAB_11_PASS]"));

						dlg_Inspect->tab_start_point = dlg_Inspect->tab_start_point + dlg_Inspect->tab_dist + dlg_Inspect->tab_interval;
						dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PROCESS_TAB"), _T("TAB_11_PASS"), dlg_Inspect->log_count);

						acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_10, dlg_Inspect->tab_start_point, NULL);
						do
						{
							acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_10, &dlg_Inspect->stage_sub_x_status, NULL);
							Sleep(10);
						} while (dlg_Inspect->stage_sub_x_status & ACSC_AST_MOVE);
					}

					else if (tab == 11 && dlg_Inspect->process_pass_tab_12 == true)
					{
						dlg_Inspect->m_edit_process.SetWindowTextW(_T("INSPECTION [TAB_12_PASS]"));

						dlg_Inspect->tab_start_point = dlg_Inspect->tab_start_point + dlg_Inspect->tab_dist + dlg_Inspect->tab_interval;
						dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PROCESS_TAB"), _T("TAB_12_PASS"), dlg_Inspect->log_count);

						acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_10, dlg_Inspect->tab_start_point, NULL);
						do
						{
							acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_10, &dlg_Inspect->stage_sub_x_status, NULL);
							Sleep(10);
						} while (dlg_Inspect->stage_sub_x_status & ACSC_AST_MOVE);
					}

					else if (tab == 12 && dlg_Inspect->process_pass_tab_13 == true)
					{
						dlg_Inspect->m_edit_process.SetWindowTextW(_T("INSPECTION [TAB_13_PASS]"));

						dlg_Inspect->tab_start_point = dlg_Inspect->tab_start_point + dlg_Inspect->tab_dist + dlg_Inspect->tab_interval;
						dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PROCESS_TAB"), _T("TAB_13_PASS"), dlg_Inspect->log_count);

						acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_10, dlg_Inspect->tab_start_point, NULL);
						do
						{
							acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_10, &dlg_Inspect->stage_sub_x_status, NULL);
							Sleep(10);
						} while (dlg_Inspect->stage_sub_x_status & ACSC_AST_MOVE);
					}

					else if (tab == 13 && dlg_Inspect->process_pass_tab_14 == true)
					{
						dlg_Inspect->m_edit_process.SetWindowTextW(_T("INSPECTION [TAB_14_PASS]"));

						dlg_Inspect->tab_start_point = dlg_Inspect->tab_start_point + dlg_Inspect->tab_dist + dlg_Inspect->tab_interval;
						dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PROCESS_TAB"), _T("TAB_14_PASS"), dlg_Inspect->log_count);

						acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_10, dlg_Inspect->tab_start_point, NULL);
						do
						{
							acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_10, &dlg_Inspect->stage_sub_x_status, NULL);
							Sleep(10);
						} while (dlg_Inspect->stage_sub_x_status & ACSC_AST_MOVE);
					}

					else if (tab == 14 && dlg_Inspect->process_pass_tab_15 == true)
					{
						dlg_Inspect->m_edit_process.SetWindowTextW(_T("INSPECTION [TAB_15_PASS]"));

						dlg_Inspect->tab_start_point = dlg_Inspect->tab_start_point + dlg_Inspect->tab_dist + dlg_Inspect->tab_interval;
						dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PROCESS_TAB"), _T("TAB_15_PASS"), dlg_Inspect->log_count);

						acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_10, dlg_Inspect->tab_start_point, NULL);
						do
						{
							acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_10, &dlg_Inspect->stage_sub_x_status, NULL);
							Sleep(10);
						} while (dlg_Inspect->stage_sub_x_status & ACSC_AST_MOVE);
					}

					else if (tab == 15 && dlg_Inspect->process_pass_tab_16 == true)
					{
						dlg_Inspect->m_edit_process.SetWindowTextW(_T("INSPECTION [TAB_16_PASS]"));

						dlg_Inspect->tab_start_point = dlg_Inspect->tab_start_point + dlg_Inspect->tab_dist + dlg_Inspect->tab_interval;
						dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PROCESS_TAB"), _T("TAB_16_PASS"), dlg_Inspect->log_count);

						acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_10, dlg_Inspect->tab_start_point, NULL);
						do
						{
							acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_10, &dlg_Inspect->stage_sub_x_status, NULL);
							Sleep(10);
						} while (dlg_Inspect->stage_sub_x_status & ACSC_AST_MOVE);
					}

					else if (tab == 16 && dlg_Inspect->process_pass_tab_17 == true)
					{
						dlg_Inspect->m_edit_process.SetWindowTextW(_T("INSPECTION [TAB_17_PASS]"));

						dlg_Inspect->tab_start_point = dlg_Inspect->tab_start_point + dlg_Inspect->tab_dist + dlg_Inspect->tab_interval;
						dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PROCESS_TAB"), _T("TAB_17_PASS"), dlg_Inspect->log_count);

						acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_10, dlg_Inspect->tab_start_point, NULL);
						do
						{
							acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_10, &dlg_Inspect->stage_sub_x_status, NULL);
							Sleep(10);
						} while (dlg_Inspect->stage_sub_x_status & ACSC_AST_MOVE);
					}

					else if (tab == 17 && dlg_Inspect->process_pass_tab_18 == true)
					{
						dlg_Inspect->m_edit_process.SetWindowTextW(_T("INSPECTION [TAB_18_PASS]"));

						dlg_Inspect->tab_start_point = dlg_Inspect->tab_start_point + dlg_Inspect->tab_dist + dlg_Inspect->tab_interval;
						dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PROCESS_TAB"), _T("TAB_18_PASS"), dlg_Inspect->log_count);

						acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_10, dlg_Inspect->tab_start_point, NULL);
						do
						{
							acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_10, &dlg_Inspect->stage_sub_x_status, NULL);
							Sleep(10);
						} while (dlg_Inspect->stage_sub_x_status & ACSC_AST_MOVE);
					}

					else if (tab == 18 && dlg_Inspect->process_pass_tab_19 == true)
					{
						dlg_Inspect->m_edit_process.SetWindowTextW(_T("INSPECTION [TAB_19_PASS]"));

						dlg_Inspect->tab_start_point = dlg_Inspect->tab_start_point + dlg_Inspect->tab_dist + dlg_Inspect->tab_interval;
						dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PROCESS_TAB"), _T("TAB_19_PASS"), dlg_Inspect->log_count);

						acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_10, dlg_Inspect->tab_start_point, NULL);
						do
						{
							acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_10, &dlg_Inspect->stage_sub_x_status, NULL);
							Sleep(10);
						} while (dlg_Inspect->stage_sub_x_status & ACSC_AST_MOVE);
					}

					else if (tab == 19 && dlg_Inspect->process_pass_tab_20 == true)
					{
						dlg_Inspect->m_edit_process.SetWindowTextW(_T("INSPECTION [TAB_20_PASS]"));

						dlg_Inspect->tab_start_point = dlg_Inspect->tab_start_point + dlg_Inspect->tab_dist + dlg_Inspect->tab_interval;
						dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PROCESS_TAB"), _T("TAB_20_PASS"), dlg_Inspect->log_count);

						acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_10, dlg_Inspect->tab_start_point, NULL);
						do
						{
							acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_10, &dlg_Inspect->stage_sub_x_status, NULL);
							Sleep(10);
						} while (dlg_Inspect->stage_sub_x_status & ACSC_AST_MOVE);
					}

					else if (tab == 20 && dlg_Inspect->process_pass_tab_21 == true)
					{
						dlg_Inspect->m_edit_process.SetWindowTextW(_T("INSPECTION [TAB_21_PASS]"));

						dlg_Inspect->tab_start_point = dlg_Inspect->tab_start_point + dlg_Inspect->tab_dist + dlg_Inspect->tab_interval;
						dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PROCESS_TAB"), _T("TAB_21_PASS"), dlg_Inspect->log_count);

						acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_10, dlg_Inspect->tab_start_point, NULL);
						do
						{
							acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_10, &dlg_Inspect->stage_sub_x_status, NULL);
							Sleep(10);
						} while (dlg_Inspect->stage_sub_x_status & ACSC_AST_MOVE);
					}

					else if (tab == 21 && dlg_Inspect->process_pass_tab_22 == true)
					{
						dlg_Inspect->m_edit_process.SetWindowTextW(_T("INSPECTION [TAB_22_PASS]"));

						dlg_Inspect->tab_start_point = dlg_Inspect->tab_start_point + dlg_Inspect->tab_dist + dlg_Inspect->tab_interval;
						dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PROCESS_TAB"), _T("TAB_22_PASS"), dlg_Inspect->log_count);

						acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_10, dlg_Inspect->tab_start_point, NULL);
						do
						{
							acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_10, &dlg_Inspect->stage_sub_x_status, NULL);
							Sleep(10);
						} while (dlg_Inspect->stage_sub_x_status & ACSC_AST_MOVE);
					}

					else if (tab == 22 && dlg_Inspect->process_pass_tab_23 == true)
					{
						dlg_Inspect->m_edit_process.SetWindowTextW(_T("INSPECTION [TAB_23_PASS]"));

						dlg_Inspect->tab_start_point = dlg_Inspect->tab_start_point + dlg_Inspect->tab_dist + dlg_Inspect->tab_interval;
						dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PROCESS_TAB"), _T("TAB_23_PASS"), dlg_Inspect->log_count);

						acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_10, dlg_Inspect->tab_start_point, NULL);
						do
						{
							acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_10, &dlg_Inspect->stage_sub_x_status, NULL);
							Sleep(10);
						} while (dlg_Inspect->stage_sub_x_status & ACSC_AST_MOVE);
					}

					else if (tab == 23 && dlg_Inspect->process_pass_tab_24 == true)
					{
						dlg_Inspect->m_edit_process.SetWindowTextW(_T("INSPECTION [TAB_24_PASS]"));

						dlg_Inspect->tab_start_point = dlg_Inspect->tab_start_point + dlg_Inspect->tab_dist + dlg_Inspect->tab_interval;
						dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PROCESS_TAB"), _T("TAB_24_PASS"), dlg_Inspect->log_count);

						acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_10, dlg_Inspect->tab_start_point, NULL);
						do
						{
							acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_10, &dlg_Inspect->stage_sub_x_status, NULL);
							Sleep(10);
						} while (dlg_Inspect->stage_sub_x_status & ACSC_AST_MOVE);
					}

					else if (tab == 24 && dlg_Inspect->process_pass_tab_25 == true)
					{
						dlg_Inspect->m_edit_process.SetWindowTextW(_T("INSPECTION [TAB_25_PASS]"));

						dlg_Inspect->tab_start_point = dlg_Inspect->tab_start_point + dlg_Inspect->tab_dist + dlg_Inspect->tab_interval;
						dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PROCESS_TAB"), _T("TAB_25_PASS"), dlg_Inspect->log_count);

						acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_10, dlg_Inspect->tab_start_point, NULL);
						do
						{
							acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_10, &dlg_Inspect->stage_sub_x_status, NULL);
							Sleep(10);
						} while (dlg_Inspect->stage_sub_x_status & ACSC_AST_MOVE);
					}

					else if (tab == 25 && dlg_Inspect->process_pass_tab_26 == true)
					{
						dlg_Inspect->m_edit_process.SetWindowTextW(_T("INSPECTION [TAB_26_PASS]"));

						dlg_Inspect->tab_start_point = dlg_Inspect->tab_start_point + dlg_Inspect->tab_dist + dlg_Inspect->tab_interval;
						dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PROCESS_TAB"), _T("TAB_26_PASS"), dlg_Inspect->log_count);

						acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_10, dlg_Inspect->tab_start_point, NULL);
						do
						{
							acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_10, &dlg_Inspect->stage_sub_x_status, NULL);
							Sleep(10);
						} while (dlg_Inspect->stage_sub_x_status & ACSC_AST_MOVE);
					}

					else if (tab == 26 && dlg_Inspect->process_pass_tab_27 == true)
					{
						dlg_Inspect->m_edit_process.SetWindowTextW(_T("INSPECTION [TAB_27_PASS]"));

						dlg_Inspect->tab_start_point = dlg_Inspect->tab_start_point + dlg_Inspect->tab_dist + dlg_Inspect->tab_interval;
						dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PROCESS_TAB"), _T("TAB_27_PASS"), dlg_Inspect->log_count);

						acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_10, dlg_Inspect->tab_start_point, NULL);
						do
						{
							acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_10, &dlg_Inspect->stage_sub_x_status, NULL);
							Sleep(10);
						} while (dlg_Inspect->stage_sub_x_status & ACSC_AST_MOVE);
					}

					else if (tab == 27 && dlg_Inspect->process_pass_tab_28 == true)
					{
						dlg_Inspect->m_edit_process.SetWindowTextW(_T("INSPECTION [TAB_28_PASS]"));

						dlg_Inspect->tab_start_point = dlg_Inspect->tab_start_point + dlg_Inspect->tab_dist + dlg_Inspect->tab_interval;
						dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PROCESS_TAB"), _T("TAB_28_PASS"), dlg_Inspect->log_count);

						acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_10, dlg_Inspect->tab_start_point, NULL);
						do
						{
							acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_10, &dlg_Inspect->stage_sub_x_status, NULL);
							Sleep(10);
						} while (dlg_Inspect->stage_sub_x_status & ACSC_AST_MOVE);
					}

					else if (tab == 28 && dlg_Inspect->process_pass_tab_29 == true)
					{
						dlg_Inspect->m_edit_process.SetWindowTextW(_T("INSPECTION [TAB_29_PASS]"));

						dlg_Inspect->tab_start_point = dlg_Inspect->tab_start_point + dlg_Inspect->tab_dist + dlg_Inspect->tab_interval;
						dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PROCESS_TAB"), _T("TAB_29_PASS"), dlg_Inspect->log_count);

						acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_10, dlg_Inspect->tab_start_point, NULL);
						do
						{
							acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_10, &dlg_Inspect->stage_sub_x_status, NULL);
							Sleep(10);
						} while (dlg_Inspect->stage_sub_x_status & ACSC_AST_MOVE);
					}

					else if (tab == 29 && dlg_Inspect->process_pass_tab_30 == true)
					{
						dlg_Inspect->m_edit_process.SetWindowTextW(_T("INSPECTION [TAB_30_PASS]"));

						dlg_Inspect->tab_start_point = dlg_Inspect->tab_start_point + dlg_Inspect->tab_dist + dlg_Inspect->tab_interval;
						dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PROCESS_TAB"), _T("TAB_30_PASS"), dlg_Inspect->log_count);

						acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_10, dlg_Inspect->tab_start_point, NULL);
						do
						{
							acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_10, &dlg_Inspect->stage_sub_x_status, NULL);
							Sleep(10);
						} while (dlg_Inspect->stage_sub_x_status & ACSC_AST_MOVE);
					}

					else
					{
						for (int i = 0; i < dlg_Inspect->tab_point; i++)
						{
							if (i == 0)	// Tab Start Position
							{
								dlg_Inspect->tab_start_point = dlg_Inspect->tab_start_point + dlg_Inspect->upper_align_offset;

								acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_10, dlg_Inspect->tab_start_point, NULL);
								do
								{
									acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_10, &dlg_Inspect->stage_sub_x_status, NULL);
									Sleep(10);
								} while (dlg_Inspect->stage_sub_x_status & ACSC_AST_MOVE);

								dlg_Inspect->tab_center_point = dlg_Inspect->tab_start_point - dlg_Inspect->upper_align_offset;
								dlg_Inspect->tab_end_point = dlg_Inspect->tab_start_point - dlg_Inspect->upper_align_offset + dlg_Inspect->tab_step;

								CString str_tab;
								str_tab.Format(_T("INSPECTION : Tab[%d], Point[%d]"), tab + 1, i + 1);
								dlg_Inspect->m_edit_process.SetWindowTextW(str_tab);

								dlg_Inspect->Image_Inspect(tab, i);
								Sleep(500);
							}

							else if (i < dlg_Inspect->tab_point - 1)	// Tab Center Position
							{
								dlg_Inspect->tab_center_point = dlg_Inspect->tab_center_point + dlg_Inspect->tab_step;

								acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_10, dlg_Inspect->tab_center_point, NULL);
								do
								{
									acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_10, &dlg_Inspect->stage_sub_x_status, NULL);
									Sleep(10);
								} while (dlg_Inspect->stage_sub_x_status & ACSC_AST_MOVE);

								CString str_tab;
								str_tab.Format(_T("INSPECTION : Tab[%d], Point[%d]"), tab + 1, i + 1);
								dlg_Inspect->m_edit_process.SetWindowTextW(str_tab);

								dlg_Inspect->Image_Inspect(tab, i);
								Sleep(200);
							}

							else if (i == dlg_Inspect->tab_point - 1)	// Tab End Position
							{
								dlg_Inspect->tab_end_point = dlg_Inspect->tab_center_point + dlg_Inspect->tab_step - dlg_Inspect->upper_align_offset;
								acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_10, dlg_Inspect->tab_end_point, NULL);
								do
								{
									acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_10, &dlg_Inspect->stage_sub_x_status, NULL);
									Sleep(10);
								} while (dlg_Inspect->stage_sub_x_status & ACSC_AST_MOVE);

								dlg_Inspect->tab_end_point = dlg_Inspect->tab_end_point + dlg_Inspect->upper_align_offset;

								CString str_tab;
								str_tab.Format(_T("INSPECTION : Tab[%d], Point[%d]"), tab + 1, i + 1);
								dlg_Inspect->m_edit_process.SetWindowTextW(str_tab);

								dlg_Inspect->Image_Inspect(tab, i);
								Sleep(200);
							}
						}
						dlg_Inspect->tab_start_point = dlg_Inspect->tab_end_point + dlg_Inspect->tab_interval;

						dlg_Inspect->ExcelResult(tab);
						Sleep(500);
					}
				}

				dlg_Inspect->Invalidate(false);

				if (dlg_Inspect->tab_count == dlg_Inspect->possible_tab)
				{
					dlg_Inspect->process_af_check = 2;
					Sleep(2000);

					m_AutoResult = InspectionFinish;
					Sleep(500);

					m_AutoSeq = eAutoSeq::InspectionComplete;
				}


				else if (dlg_Inspect->tab_count > dlg_Inspect->possible_tab)
				{
					dlg_Inspect->process_af_check = 2;
					Sleep(2000);


					dlg_Inspect->m_edit_process.SetWindowTextW(_T("MOVE PROCESS_POS [FOR HALF&HALF]"));

					dlg_Inspect->tab_start = dlg_Inspect->possible_tab;
					dlg_Inspect->possible_tab = dlg_Inspect->tab_count;
					dlg_Inspect->stage_main_x_process_pos = dlg_Inspect->stage_main_x_process_pos + dlg_Inspect->over_pos;
					dlg_Inspect->stage_sub_x_process_pos = dlg_Inspect->first_finish_position - dlg_Inspect->over_pos + dlg_Inspect->tab_interval;
					m_AutoResult = FirstFinish;
					Sleep(200);

					m_AutoSeq = eAutoSeq::MoveProcessPos;
				}

				break;

			case InspectionComplete:

				dlg_Inspect->m_edit_process.SetWindowTextW(_T("INSPECTION COMPLETE"));

				dlg_Inspect->bInspectComplete = true;
				dlg_Inspect->Invalidate(false);

				m_AutoSeq = eAutoSeq::Unloading;
				break;

			case Unloading:

				dlg_Inspect->m_edit_process.SetWindowTextW(_T("MOVE UNLOADING_POS"));

				dlg_Inspect->Unloading_Time = GetTickCount();


				if (dlg_Inspect->check_alram_unloading == 1)
				{
					dlg_Inspect->bPreAlign = true;
					dlg_Inspect->bPreAlignComplete = true;
					dlg_Inspect->bTabAlign = true;
					dlg_Inspect->bTabAlignComplete = true;
					dlg_Inspect->bInspect = true;
					dlg_Inspect->bInspectComplete = true;
					dlg_Inspect->bUnloading = true;
					dlg_Inspect->bJudge = true;
					dlg_Inspect->bJudgeComplete = true;


					dlg_Inspect->Invalidate(false);
				}

				else if (dlg_Inspect->check_alram_unloading == 0)
					dlg_Inspect->bUnloading = true;


				dlg_Inspect->log_time = CTime::GetCurrentTime();
				dlg_Inspect->str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), dlg_Inspect->log_time.GetYear(), dlg_Inspect->log_time.GetMonth(),
					dlg_Inspect->log_time.GetDay(), dlg_Inspect->log_time.GetHour(), dlg_Inspect->log_time.GetMinute(), dlg_Inspect->log_time.GetSecond());

				dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PROCESS"), _T("Move_Unloading_Pos"), dlg_Inspect->log_count);


				// Stage Y 위치 확인
				acsc_GetRPosition(dlg_Inspect->hStage_auto, ACSC_AXIS_0, &dlg_Inspect->stage_main_y_pos, NULL);

				if (dlg_Inspect->stage_main_y_pos > dlg_Inspect->gantry_limit_min && dlg_Inspect->stage_main_y_pos < dlg_Inspect->gantry_limit_max)
				{
					acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_0, dlg_Inspect->stage_main_y_ready_pos, NULL);
					do
					{
						acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_0, &dlg_Inspect->stage_main_y_status, NULL);
						Sleep(10);
					} while (dlg_Inspect->stage_main_y_status & ACSC_AST_MOVE);

					dlg_Inspect->log_time = CTime::GetCurrentTime();
					dlg_Inspect->str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), dlg_Inspect->log_time.GetYear(), dlg_Inspect->log_time.GetMonth(),
						dlg_Inspect->log_time.GetDay(), dlg_Inspect->log_time.GetHour(), dlg_Inspect->log_time.GetMinute(), dlg_Inspect->log_time.GetSecond());

					dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("STAGE_Y"), _T("Unloading Position Complete"), dlg_Inspect->log_count);

					acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_4, dlg_Inspect->stage_main_x_ready_pos, NULL);
					do
					{
						acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_4, &dlg_Inspect->stage_main_x_status, NULL);
						Sleep(10);
					} while (dlg_Inspect->stage_main_x_status & ACSC_AST_MOVE);

					dlg_Inspect->log_time = CTime::GetCurrentTime();
					dlg_Inspect->str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), dlg_Inspect->log_time.GetYear(), dlg_Inspect->log_time.GetMonth(),
						dlg_Inspect->log_time.GetDay(), dlg_Inspect->log_time.GetHour(), dlg_Inspect->log_time.GetMinute(), dlg_Inspect->log_time.GetSecond());

					dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("STAGE_X"), _T("Unloading Position Complete"), dlg_Inspect->log_count);
				}

				else
				{
					acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_4, dlg_Inspect->stage_main_x_ready_pos, NULL);
					do
					{
						acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_4, &dlg_Inspect->stage_main_x_status, NULL);
						Sleep(10);
					} while (dlg_Inspect->stage_main_x_status & ACSC_AST_MOVE);

					dlg_Inspect->log_time = CTime::GetCurrentTime();
					dlg_Inspect->str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), dlg_Inspect->log_time.GetYear(), dlg_Inspect->log_time.GetMonth(),
						dlg_Inspect->log_time.GetDay(), dlg_Inspect->log_time.GetHour(), dlg_Inspect->log_time.GetMinute(), dlg_Inspect->log_time.GetSecond());

					dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("STAGE_X"), _T("Unloading Position Complete"), dlg_Inspect->log_count);

					acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_0, dlg_Inspect->stage_main_y_ready_pos, NULL);
					do
					{
						acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_0, &dlg_Inspect->stage_main_y_status, NULL);
						Sleep(10);
					} while (dlg_Inspect->stage_main_y_status & ACSC_AST_MOVE);

					dlg_Inspect->log_time = CTime::GetCurrentTime();
					dlg_Inspect->str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), dlg_Inspect->log_time.GetYear(), dlg_Inspect->log_time.GetMonth(),
						dlg_Inspect->log_time.GetDay(), dlg_Inspect->log_time.GetHour(), dlg_Inspect->log_time.GetMinute(), dlg_Inspect->log_time.GetSecond());

					dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("STAGE_Y"), _T("Unloading Position Complete"), dlg_Inspect->log_count);
				}


				acsc_ToPoint(dlg_Inspect->hStage_auto, 0, ACSC_AXIS_10, dlg_Inspect->stage_sub_x_ready_pos, NULL);
				do
				{
					acsc_GetMotorState(dlg_Inspect->hStage_auto, ACSC_AXIS_10, &dlg_Inspect->stage_sub_x_status, NULL);
					Sleep(10);
				} while (dlg_Inspect->stage_sub_x_status & ACSC_AST_MOVE);

				dlg_Inspect->log_time = CTime::GetCurrentTime();
				dlg_Inspect->str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), dlg_Inspect->log_time.GetYear(), dlg_Inspect->log_time.GetMonth(),
					dlg_Inspect->log_time.GetDay(), dlg_Inspect->log_time.GetHour(), dlg_Inspect->log_time.GetMinute(), dlg_Inspect->log_time.GetSecond());

				dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("SUB_X"), _T("Unloading Position Complete"), dlg_Inspect->log_count);
				m_AutoSeq = eAutoSeq::UnloadingComplete;
				break;


			case UnloadingComplete:

				dlg_Inspect->m_edit_process.SetWindowTextW(_T("MOVE UNLOADING_POS COMPLETE"));
				dlg_Inspect->bUnloadingComplete = true;
				dlg_Inspect->Invalidate(false);

				//Sleep(500);

				if (dlg_Inspect->check_alram_unloading == 1)
				{
					dlg_Inspect->bStart = false;
					dlg_Inspect->bStop = true;
					dlg_Inspect->bReady = false;
					dlg_Inspect->bReadyComplete = false;
					dlg_Inspect->bProcess = false;
					dlg_Inspect->bProcessComplete = false;
					dlg_Inspect->bPreAlign = false;
					dlg_Inspect->bPreAlignComplete = false;
					dlg_Inspect->bTabAlign = false;
					dlg_Inspect->bTabAlignComplete = false;
					dlg_Inspect->bInspect = false;
					dlg_Inspect->bInspectComplete = false;
					dlg_Inspect->bJudge = false;
					dlg_Inspect->bJudgeComplete = false;
					dlg_Inspect->bUnloading = false;
					dlg_Inspect->bUnloadingComplete = false;

					dlg_Inspect->Invalidate(false);

					dlg_Inspect->log_time = CTime::GetCurrentTime();
					dlg_Inspect->str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), dlg_Inspect->log_time.GetYear(), dlg_Inspect->log_time.GetMonth(),
						dlg_Inspect->log_time.GetDay(), dlg_Inspect->log_time.GetHour(), dlg_Inspect->log_time.GetMinute(), dlg_Inspect->log_time.GetSecond());

					dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PROCESS"), _T("Move Unloading Pos"), dlg_Inspect->log_count);

					dlg_Inspect->m_edit_process.SetWindowTextW(_T("MOVE UNLOADING POS"));

					Sleep(500);

					dlg_Inspect->GetDlgItem(IDC_BTN_EMO)->EnableWindow(FALSE);

					dlg_Inspect->GetDlgItem(IDC_BTN_START)->EnableWindow(TRUE);

					dlg_Inspect->m_edit_process.SetWindowTextW(_T("INSPECTION STAND-BY"));

					break;
				}

				else if (dlg_Inspect->check_alram_unloading == 0)
				{
					dlg_Inspect->Judge_Time = GetTickCount();

					m_AutoSeq = eAutoSeq::Judge;

					break;
				}

			case Judge:

				dlg_Inspect->m_edit_process.SetWindowTextW(_T("INSPECTION JUDGE"));

				dlg_Inspect->log_time = CTime::GetCurrentTime();
				dlg_Inspect->str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), dlg_Inspect->log_time.GetYear(), dlg_Inspect->log_time.GetMonth(),
					dlg_Inspect->log_time.GetDay(), dlg_Inspect->log_time.GetHour(), dlg_Inspect->log_time.GetMinute(), dlg_Inspect->log_time.GetSecond());

				dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PROCESS"), _T("Judge"), dlg_Inspect->log_count);

				dlg_Inspect->bJudge = true;
				dlg_Inspect->Invalidate(false);

				dlg_Inspect->PopupResult();

				m_AutoSeq = eAutoSeq::JudgeComplete;
				break;

			case JudgeComplete:

				dlg_Inspect->m_edit_process.SetWindowTextW(_T("INSPECTION JUDGE COMPLETE"));

				dlg_Inspect->log_time = CTime::GetCurrentTime();
				dlg_Inspect->str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), dlg_Inspect->log_time.GetYear(), dlg_Inspect->log_time.GetMonth(),
					dlg_Inspect->log_time.GetDay(), dlg_Inspect->log_time.GetHour(), dlg_Inspect->log_time.GetMinute(), dlg_Inspect->log_time.GetSecond());

				dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PROCESS"), _T("Judge_Complete"), dlg_Inspect->log_count);

				dlg_Inspect->bJudgeComplete = true;
				dlg_Inspect->Invalidate(false);

				Sleep(2000);

				dlg_Inspect->bStart = false;
				dlg_Inspect->bStop = true;
				dlg_Inspect->bReady = false;
				dlg_Inspect->bReadyComplete = false;
				dlg_Inspect->bProcess = false;
				dlg_Inspect->bProcessComplete = false;
				dlg_Inspect->bPreAlign = false;
				dlg_Inspect->bPreAlignComplete = false;
				dlg_Inspect->bTabAlign = false;
				dlg_Inspect->bTabAlignComplete = false;
				dlg_Inspect->bInspect = false;
				dlg_Inspect->bInspectComplete = false;
				dlg_Inspect->bJudge = false;
				dlg_Inspect->bJudgeComplete = false;
				dlg_Inspect->bUnloading = false;
				dlg_Inspect->bUnloadingComplete = false;

				dlg_Inspect->Invalidate(false);

				dlg_Inspect->log_time = CTime::GetCurrentTime();
				dlg_Inspect->str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), dlg_Inspect->log_time.GetYear(), dlg_Inspect->log_time.GetMonth(),
					dlg_Inspect->log_time.GetDay(), dlg_Inspect->log_time.GetHour(), dlg_Inspect->log_time.GetMinute(), dlg_Inspect->log_time.GetSecond());

				dlg_Inspect->display_log(dlg_Inspect->str_log_time, _T("INSPECTION"), _T("PROCESS"), _T("Inspection Finish"), dlg_Inspect->log_count);

				dlg_Inspect->m_edit_process.SetWindowTextW(_T("INSPECTION FINISH"));

				Sleep(500);

				dlg_Inspect->GetDlgItem(IDC_BTN_EMO)->EnableWindow(FALSE);
				dlg_Inspect->GetDlgItem(IDC_BTN_START)->EnableWindow(TRUE);

				dlg_Inspect->m_edit_process.SetWindowTextW(_T("INSPECTION STAND-BY"));

				break;
			}
		}
	}
	return 0;
}


void DIALOG_AUTO::ImageAlign(int alignCase)
{
	CREVIEWAREADlg *pDlg = (CREVIEWAREADlg*)AfxGetMainWnd();

	pDlg->align_af_pos();

	Sleep(1000);

	// Image Pause
	MdigHalt(area_cam.m_MilDigitizer_Upper);
	MdigHalt(area_cam.m_MilDigitizer_Side);

	// Align Before Image Save File Name
	// 이름 수정 필요.
	CString saveTitle;
	saveTitle = file_path + _T("Data\\1. ALIGN\\2. BEFORE\\") + str_inspection_start_time + _T(".bmp");

	// Align Before Image Grab
	MdigGrab(area_cam.m_MilDigitizer_Upper, area_cam.m_MilImage_Upper);
	// Align Before Image Save
	MbufExport(saveTitle, M_BMP, area_cam.m_MilImage_Upper);

	CT2CA pszConvertedAnsiString(saveTitle);
	std::string loadTitle(pszConvertedAnsiString);

	// real time
	load_align_image = imread(loadTitle);

	//simulator
	//load_align_image = imread("test_1.bmp");

	// prealign (mark load)
	if (alignCase == 1)
		load_align_mark = imread("Data\\1. ALIGN\\1. REG\\upper_prealign.bmp");

	// tabalign
	else if (alignCase == 2)
		load_align_mark = imread("Data\\1. ALIGN\\1. REG\\upper_tabalign.bmp");

	// Load Align Before Image

	loadInfo = (BITMAPINFO*)loadBuf;
	loadInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	loadInfo->bmiHeader.biWidth = load_align_image.cols;
	loadInfo->bmiHeader.biHeight = -(load_align_image.rows);
	loadInfo->bmiHeader.biBitCount = 24;
	loadInfo->bmiHeader.biPlanes = 1;
	loadInfo->bmiHeader.biCompression = BI_RGB;
	loadInfo->bmiHeader.biSizeImage = 0;
	loadInfo->bmiHeader.biXPelsPerMeter = 0;
	loadInfo->bmiHeader.biYPelsPerMeter = 0;
	loadInfo->bmiHeader.biClrUsed = 0;
	loadInfo->bmiHeader.biClrImportant = 0;

	resize(load_align_image, resize_upper_image, Size(load_align_image.cols / 2, load_align_image.rows / 2));
	resize(load_align_mark, resize_upper_mark, Size(load_align_mark.cols / 2, load_align_mark.rows / 2));

	matchTemplate(resize_upper_image, resize_upper_mark, detect_align_mark, TM_CCOEFF_NORMED);
	minMaxLoc(detect_align_mark, NULL, &maxVal_align, NULL, &maxLoc_align);

	pDlg->process_af_pos();
}


void DIALOG_AUTO::Image_Inspect(int TabNum, int TabPoint)
{
	// pause
	MdigHalt(area_cam.m_MilDigitizer_Upper);
	MdigHalt(area_cam.m_MilDigitizer_Side);

	CString saveTitle_upper;
	CString saveTitle_side;

	CString saveManual_upper;
	CString saveManual_side;

	CString image_upper;
	CString image_side;

	image_upper.Format(_T("\\upper(%d_%d).bmp"), TabNum + 1, TabPoint + 1);
	image_side.Format(_T("\\side(%d_%d).bmp"), TabNum + 1, TabPoint + 1);

	saveTitle_upper = origin_path + image_upper;
	saveTitle_side = origin_path + image_side;

	folder_path = folder_path + str_inspection_start_time;
	MdigGrab(area_cam.m_MilDigitizer_Upper, area_cam.m_MilImage_Upper);
	MdigGrab(area_cam.m_MilDigitizer_Side, area_cam.m_MilImage_Side);

	// save image
	MdigGrabContinuous(area_cam.m_MilDigitizer_Upper, area_cam.m_MilImage_Upper);
	MdigGrabContinuous(area_cam.m_MilDigitizer_Side, area_cam.m_MilImage_Side);

	Mat Inspect_upper_load;
	Mat Inspect_side_load;

	Mat Inspect_upper_clone;
	Mat Inspect_side_clone;

	Mat Inspect_upper_morphology;
	Mat Inspect_side_morphology;

	Mat Inspect_upper_binary;
	Mat Inspect_side_binary;
	Mat Inspect_edge_binary;

	Mat Inspect_upper_canny;
	Mat Inspect_side_canny;

	MbufExport(saveTitle_upper, M_BMP, area_cam.m_MilImage_Upper);
	MbufExport(saveTitle_side, M_BMP, area_cam.m_MilImage_Side);

	CT2CA upperConvertTitle(saveTitle_upper);
	std::string upperTitle(upperConvertTitle);

	CT2CA sideConvertTitle(saveTitle_side);
	std::string sideTitle(sideConvertTitle);

	// Real Time
	Inspect_upper_load = imread(upperTitle);
	Inspect_side_load = imread(sideTitle);

	// simulator
	//Inspect_upper_load = imread("upper.bmp");
	//Inspect_side_load = imread("side.bmp");

	loadInfo = (BITMAPINFO*)loadBuf;
	loadInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	loadInfo->bmiHeader.biWidth = Inspect_upper_load.cols;
	loadInfo->bmiHeader.biHeight = -(Inspect_upper_load.rows);
	loadInfo->bmiHeader.biBitCount = 24;
	loadInfo->bmiHeader.biPlanes = 1;
	loadInfo->bmiHeader.biCompression = BI_RGB;
	loadInfo->bmiHeader.biSizeImage = 0;
	loadInfo->bmiHeader.biXPelsPerMeter = 0;
	loadInfo->bmiHeader.biYPelsPerMeter = 0;
	loadInfo->bmiHeader.biClrUsed = 0;
	loadInfo->bmiHeader.biClrImportant = 0;


	// image 전처리 순서
	// rgb2gray->morphology->binary->canny->contour
	// Image Copy

	Inspect_upper_clone = Inspect_upper_load.clone();
	Inspect_side_clone = Inspect_side_load.clone();

	// rgb2gray
	cvtColor(Inspect_upper_load, Inspect_upper_load, COLOR_BGR2GRAY);
	cvtColor(Inspect_side_load, Inspect_side_load, COLOR_BGR2GRAY);

	int upper_edge_sum[2500] = { 0 };

	for (int i = upper_roi_min; i < upper_roi_max; i++)
	{
		for (int j = 0; j < 2048; j++)
		{
			int intensity = Inspect_upper_load.at<uchar>(i, j);
			upper_edge_sum[i] += intensity;
		}
	}
	int upper_edge = 0;

	for (int i = upper_roi_min; i < upper_roi_max; i++)
	{
		// 해상도에서 절반 이상의 Pixel 이 검출
		// 검출 안되면 
		//if (upper_edge_sum[i] > (2048 / 3 * 255))
		if (upper_edge_sum[i] > 200000)
		{
			upper_edge = i;
			break;
		}
	}
	int upper_edge_2;
	upper_edge_2 = upper_edge + 95;

	// upper copper 측 line 그리기
	// copper 이어진 부분 없애기 위해
	for (int i = 0; i < 2048; i++)
	{
		for (int j = 0; j < upper_roi_max - upper_edge_2; j++)
		{
			Inspect_upper_load.at<uchar>(upper_edge_2 + j, i) = 0;
		}
	}
	// morphology
	Mat element_open(morphology_open, morphology_open, CV_8U, cv::Scalar(1));
	Mat element_close(morphology_close, morphology_close, CV_8U, cv::Scalar(1));

	morphologyEx(Inspect_upper_load, Inspect_upper_morphology, cv::MORPH_CLOSE, element_open);
	morphologyEx(Inspect_upper_morphology, Inspect_upper_morphology, cv::MORPH_OPEN, element_close);

	morphologyEx(Inspect_side_load, Inspect_side_morphology, cv::MORPH_CLOSE, element_open);
	morphologyEx(Inspect_side_morphology, Inspect_side_morphology, cv::MORPH_OPEN, element_close);

	// binary
	threshold(Inspect_upper_morphology, Inspect_upper_binary, binary_upper, 255, THRESH_BINARY);
	threshold(Inspect_side_morphology, Inspect_side_binary, binary_side, 255, THRESH_BINARY);
	threshold(Inspect_side_morphology, Inspect_edge_binary, binary_edge, 255, THRESH_BINARY);

	//imwrite("binary_upper.bmp", Inspect_upper_binary);
	// start, end position 
	int upper_pixel_sum[2500] = { 0 };

	int side_pixel_sum[2500] = { 0 };

	int edge_position = 0;

	int edge_pixel_sum[2500] = { 0 };

	double upper_dist_1 = 0;
	double upper_dist_2 = 0;
	double side_dist_1 = 0;


	// 상부 roi 이내의 Pixel 값 정렬
	for (int i = 0; i < 2048; i++)
	{
		for (int j = upper_roi_min; j < upper_edge_2; j++)
		{
			int intensity = Inspect_upper_binary.at<uchar>(j, i);
			upper_pixel_sum[i] += intensity;
		}
	}

	// 측면부 roi 이내의 Pixel 값 정렬
	for (int i = 0; i < 2048; i++)
	{
		for (int j = side_roi_min; j < side_roi_max; j++)
		{
			int intensity = Inspect_side_binary.at<uchar>(j, i);
			side_pixel_sum[i] += intensity;
		}
	}

	// 측면부(Edge) roi 이내의 Pixel 값 정렬
	for (int i = edge_roi_min; i < edge_roi_max; i++)
	{
		for (int j = 0; j < 2048; j++)
		{
			int intensity = Inspect_edge_binary.at<uchar>(i, j);
			edge_pixel_sum[i] += intensity;
		}
	}

	// Edge 경계면 검출
	for (int i = edge_roi_min; i < edge_roi_max; i++)
	{
		// 해상도에서 절반 이상의 Pixel 이 검출
		// 검출 안되면 
		if (edge_pixel_sum[i] > (2048 / 2 * 255))
		{
			edge_position = i;
			break;
		}
	}


	// 시작과 끝 지점은 Align Mark 검출하고 나서 기준 잡기
	// 검출된 Mark에 중심에서 offset 값 만큼 이동하여 시작점 확인
	// 이 곳에서 mark_1, mark_2 검출이 필요. 

	/*if (TabPoint == 0 || TabPoint == tab_point - 1)	// Tab 첫 번째 point or Tab 끝 부분
	{
		if (TabPoint == 0)
		{
			upper_start_position = 0;
			side_start_position = 0;

			for (int i = 2048 - 2; i > 0; i--)
			{
				if (upper_pixel_sum[i] != 0 && upper_pixel_sum[i + 1] == 0)
				{
					upper_end_position = i;
					break;
				}
			}

			for (int i = 2048 - 2; i > 0; i--)
			{
				if (side_pixel_sum[i] != 0 && side_pixel_sum[i + 1] == 0)
				{
					side_end_position = i;
					break;
				}
			}
		}

		else if (TabPoint == tab_point - 1)
		{
			upper_end_position = 2048;
			side_end_position = 2048;

			for (int i = 0; i < 2048; i++)
			{
				if (upper_pixel_sum[i] == 0 && upper_pixel_sum[i + 1])
				{
					upper_start_position = i;
					break;
				}
			}

			for (int i = 0; i < 2048; i++)
			{
				if (side_pixel_sum[i] == 0 && side_pixel_sum[i + 1])
				{
					side_start_position = i;
					break;
				}
			}
		}*/

		// 상부 mark 검출 관련 내용
		// start 지점 확인용 align mark
		// upper

		/*load_align_mark = imread("Data\\1. ALIGN\\1. REG\\upper_tabalign.bmp");
		cvtColor(load_align_mark, load_align_mark, COLOR_BGR2GRAY);

		resize(Inspect_upper_load, resize_upper_image, Size(Inspect_upper_load.cols / 2, Inspect_upper_load.rows / 2));
		resize(load_align_mark, resize_upper_mark, Size(load_align_mark.cols / 2, load_align_mark.rows / 2));

		matchTemplate(resize_upper_image, resize_upper_mark, detect_align_mark, TM_CCOEFF_NORMED);
		minMaxLoc(detect_align_mark, NULL, &maxVal_align, NULL, &maxLoc_align);

		tabalign_x_start = maxLoc_align.x * 2;
		tabalign_width = tabalign_x_start + resize_upper_mark.cols * 2;
		tabalign_y_start = maxLoc_align.y * 2;
		tabalign_height = tabalign_y_start + resize_upper_mark.rows * 2;
		*/

		/*resize(Inspect_side_load, resize_side_image, Size(Inspect_side_load.cols / 2, Inspect_side_load.rows / 2));


		// 둘다 참인경우
		// 두 개의 mark 간 거리를 비교
		if (check_ng_side_mark_1 == true && check_ng_side_mark_2 == true)
		{
			load_side_mark_1 = imread("Data\\1. ALIGN\\1. REG\\side_mark_1.bmp");
			load_side_mark_2 = imread("Data\\1. ALIGN\\1. REG\\side_mark_2.bmp");

			cvtColor(load_side_mark_1, load_side_mark_1, COLOR_BGR2GRAY);
			cvtColor(load_side_mark_2, load_side_mark_2, COLOR_BGR2GRAY);

			resize(load_side_mark_1, resize_side_mark_1, Size(load_side_mark_1.cols / 2, load_side_mark_1.rows / 2));
			resize(load_side_mark_2, resize_side_mark_2, Size(load_side_mark_2.cols / 2, load_side_mark_2.rows / 2));

			matchTemplate(resize_side_image, resize_side_mark_1, detect_side_mark_1, TM_CCOEFF_NORMED);
			matchTemplate(resize_side_image, resize_side_mark_2, detect_side_mark_2, TM_CCOEFF_NORMED);
		}

		// mark_1 과 pat 까지
		else if (check_ng_side_mark_1 == true)
		{
			load_side_mark_1 = imread("Data\\1. ALIGN\\1. REG\\side_mark_1.bmp");
			cvtColor(load_side_mark_1, load_side_mark_1, COLOR_BGR2GRAY);

			resize(load_side_mark_1, resize_side_mark_1, Size(load_side_mark_1.cols / 2, load_side_mark_1.rows / 2));

			matchTemplate(resize_side_image, resize_side_mark_1, detect_side_mark_1, TM_CCOEFF_NORMED);
		}

		// mark_2와 pat 까지
		else if (check_ng_side_mark_2 == true)
		{
			load_side_mark_2 = imread("Data\\1. ALIGN\\1. REG\\side_mark_2.bmp");
			cvtColor(load_side_mark_2, load_side_mark_2, COLOR_BGR2GRAY);

			resize(load_side_mark_2, resize_side_mark_2, Size(load_side_mark_2.cols / 2, load_side_mark_2.rows / 2));

			matchTemplate(resize_side_image, resize_side_mark_2, detect_side_mark_2, TM_CCOEFF_NORMED);
		}
		*/
		// mark 검출에 성공하면 mark 기준으로 설정
		// 검출된 mark 에서 align offset 값 만큼 이동한 위치가 start or end position
		// mark 검출에 실패한 경우에는 start : 0, end : 2048
		/*if (maxVal_align * 100 > tabalign_matching)
		{
			// Tab의 시작
			if (TabPoint == 0)
			{
				upper_start_position = tabalign_width + resize_upper_mark.cols + upper_align_offset;
				side_start_position = tabalign_width + resize_upper_mark.cols + side_align_offset;
			}

			// Tab의 끝
			else if (TabPoint == tab_point - 1)
			{
				upper_end_position = tabalign_x_start + resize_upper_mark.cols - upper_align_offset;
				side_end_position = tabalign_x_start + resize_upper_mark.cols - side_align_offset;
			}
		}*/
		//}

	upper_start_position = 0;
	upper_end_position = 2048;

	side_start_position = 0;
	side_end_position = 2048;

	// upper
	for (int i = 0; i < 2048; i++)
	{
		if (upper_pixel_sum[i] == 0 && upper_pixel_sum[i + 1])
		{
			upper_start_position = i;
			break;
		}
	}

	for (int i = 2048 - 2; i > 0; i--)
	{
		if (upper_pixel_sum[i] != 0 && upper_pixel_sum[i + 1] == 0)
		{
			upper_end_position = i;
			break;
		}
	}


	for (int i = 0; i < 2048; i++)
	{
		if (side_pixel_sum[i] == 0 && side_pixel_sum[i + 1])
		{
			side_start_position = i;
			break;
		}
	}

	for (int i = 2048 - 2; i > 0; i--)
	{
		if (side_pixel_sum[i] != 0 && side_pixel_sum[i + 1] == 0)
		{
			side_end_position = i;
			break;
		}
	}
	// tab 중심의 경우 (mark 가 없기 때문에 binary 값으로 시작 끝 확인)
//	else
//	{
//		
	//}

	// canny
	Canny(Inspect_upper_binary, Inspect_upper_canny, 100, 100 * 3, 3);
	Canny(Inspect_side_binary, Inspect_side_canny, 100, 100 * 3, 3);

	// contour
	vector<vector<Point> > upper_contours;
	vector<vector<Point> > side_contours;
	vector<Vec4i>	hierarchy;

	findContours(Inspect_upper_canny, upper_contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point());
	findContours(Inspect_side_canny, side_contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point());

	vector<vector<Point>> contours_poly_u(upper_contours.size());
	vector<Rect> boundRect_u(upper_contours.size());

	vector<vector<Point>> contours_poly_s(side_contours.size());
	vector<Rect> boundRect_s(side_contours.size());

	for (int i = 0; i < upper_contours.size(); i++)
	{
		approxPolyDP(Mat(upper_contours[i]), contours_poly_u[i], 1, true);
		boundRect_u[i] = boundingRect(Mat(contours_poly_u[i]));
	}

	for (int i = 0; i < side_contours.size(); i++)
	{
		approxPolyDP(Mat(side_contours[i]), contours_poly_s[i], 1, true);
		boundRect_s[i] = boundingRect(Mat(contours_poly_s[i]));
	}

	vector<Rect> boundRect_u_detect(upper_contours.size());
	vector<Rect> boundRect_s_detect(side_contours.size());

	// 검출된 상부 contour의 수
	int upper_contours_count = 0;

	for (int i = 0; i < upper_contours.size(); i++)
	{
		// Detect 된 Contour 가 roi 영역(Y) 내에 있고, 
		// 일정 Size 이상이며, 
		// 시작과 끝(X) 사이에 위치한 경우에 
		if (boundRect_u[i].y >= upper_roi_min && boundRect_u[i].y < upper_roi_max &&
			boundRect_u[i].area() >= upper_contour && boundRect_u[i].area() < 50000 &&
			boundRect_u[i].x >= upper_start_position && boundRect_u[i].x <= upper_end_position
			&& boundRect_u[i].width < 100)
		{
			// 상부 copper 는 모두 다 green
			// Scalar (blue, green, red)

			drawContours(Inspect_upper_clone, upper_contours, i, Scalar(0, 255, 0), 2, 8, hierarchy, 0, Point());
			boundRect_u_detect[upper_contours_count] = boundRect_u[i];
			upper_contours_count++;
		}
	}

	// side contours
	// width & height check

	int side_contours_count = 0;

	for (int i = 0; i < side_contours.size(); i++)
	{
		// Detect 된 Contour 가 roi 영역(Y) 내에 있고, 
		// 일정 Size 이상이며, 
		// 시작과 끝(X) 사이에 위치한 경우에 
		if (boundRect_s[i].y >= side_roi_min && boundRect_s[i].y < side_roi_max &&
			boundRect_s[i].area() >= side_contour &&
			boundRect_s[i].x >= side_start_position && boundRect_s[i].x <= side_end_position)
		{
			if (check_ng_both == true)
			{
				if (boundRect_s[i].width > (width - width_range) / 0.55 &&
					boundRect_s[i].width < (width + width_range) / 0.55)
				{
					if (boundRect_s[i].height > (height - height_range) / 0.55 &&
						boundRect_s[i].height < (height + height_range) / 0.55)
					{
						// OK의 경우 Green
						drawContours(Inspect_side_clone, side_contours, i, Scalar(0, 255, 0), 2, 8, hierarchy, 0, Point());
						boundRect_s_detect[side_contours_count] = boundRect_s[i];
						side_contours_count++;
					}

					else
					{
						drawContours(Inspect_side_clone, side_contours, i, Scalar(height_b, height_g, height_r), 2, 8, hierarchy, 0, Point());
						boundRect_s_detect[side_contours_count] = boundRect_s[i];
						side_contours_count++;
					}
				}

				else
				{
					// 둘다 ng 인 경우
					if (boundRect_s[i].height< (height - height_range) / 0.55 ||
						boundRect_s[i].height >(height + height_range) / 0.55)
					{
						drawContours(Inspect_side_clone, side_contours, i, Scalar(both_b, both_g, both_r), 2, 8, hierarchy, 0, Point());
						boundRect_s_detect[side_contours_count] = boundRect_s[i];
						side_contours_count++;
					}

					// width 만 ng
					else
					{
						drawContours(Inspect_side_clone, side_contours, i, Scalar(width_b, width_g, width_r), 2, 8, hierarchy, 0, Point());
						boundRect_s_detect[side_contours_count] = boundRect_s[i];
						side_contours_count++;
					}
				}
			}

			else if (check_ng_width == true)
			{
				if (boundRect_s[i].width > (width - width_range) / 0.55 &&
					boundRect_s[i].width < (width + width_range) / 0.55)
				{
					// OK의 경우 Green
					drawContours(Inspect_side_clone, side_contours, i, Scalar(0, 255, 0), 2, 8, hierarchy, 0, Point());
					boundRect_s_detect[side_contours_count] = boundRect_s[i];
					side_contours_count++;
				}

				else
				{
					drawContours(Inspect_side_clone, side_contours, i, Scalar(width_b, width_g, width_r), 2, 8, hierarchy, 0, Point());
					boundRect_s_detect[side_contours_count] = boundRect_s[i];
					side_contours_count++;
				}
			}

			else if (check_ng_height == true)
			{
				if (boundRect_s[i].height > (height - height_range) / 0.55 &&
					boundRect_s[i].height < (height + height_range) / 0.55)
				{
					// OK의 경우 Green
					drawContours(Inspect_side_clone, side_contours, i, Scalar(0, 255, 0), 2, 8, hierarchy, 0, Point());
					boundRect_s_detect[side_contours_count] = boundRect_s[i];
					side_contours_count++;
				}

				else
				{
					drawContours(Inspect_side_clone, side_contours, i, Scalar(height_b, height_g, height_r), 2, 8, hierarchy, 0, Point());
					boundRect_s_detect[side_contours_count] = boundRect_s[i];
					side_contours_count++;
				}
			}

		}
	}

	/*
	// 상부 Edge 면 색상은 Green 으로 고정
	line(Inspect_side_clone, Point(0, edge_position), Point(2048, edge_position), Scalar(0, 255, 0, 3));
	*/

	// 검출된 contour 정렬 (좌측 부터 순서대로)
	vector<Rect> sort_upper_detect(upper_contours_count);
	vector<Rect> sort_side_detect(side_contours_count);

	int detect_u_pos[500] = { 0 };
	int detect_s_pos[500] = { 0 };

	for (int i = 0; i < upper_contours_count; i++)
		detect_u_pos[i] = boundRect_u_detect[i].x;

	for (int i = 0; i < side_contours_count; i++)
		detect_s_pos[i] = boundRect_s_detect[i].x;

	sort(detect_u_pos, detect_u_pos + upper_contours_count);
	sort(detect_s_pos, detect_s_pos + side_contours_count);

	for (int i = 0; i < upper_contours_count; i++)
	{
		for (int j = 0; j < upper_contours_count; j++)
		{
			if (boundRect_u_detect[j].x == detect_u_pos[i])
				sort_upper_detect[i] = boundRect_u_detect[j];
		}
	}

	for (int i = 0; i < side_contours_count; i++)
	{
		for (int j = 0; j < side_contours_count; j++)
		{
			if (boundRect_s_detect[j].x == detect_s_pos[i])
				sort_side_detect[i] = boundRect_s_detect[j];
		}
	}

	// Upper Value 정렬
	int upper_result_count = 0;
	CString number;

	for (int i = 0; i < upper_contours_count; i++)
	{
		result_value.upper_x[TabPoint][upper_result_count] = sort_upper_detect[i].x;
		result_value.upper_width[TabPoint][upper_result_count] = sort_upper_detect[i].width * 0.55;
		result_value.upper_y[TabPoint][upper_result_count] = sort_upper_detect[i].y;
		result_value.upper_height[TabPoint][upper_result_count] = sort_upper_detect[i].height * 0.55;
		result_value.upper_ma_x_center[TabPoint][upper_result_count] = sort_upper_detect[i].x + sort_upper_detect[i].width / 2;	// pixel 값

		number.Format(_T("%d"), upper_result_count + 1);

		CT2CA pszConvertedAnsiString(number);
		std::string str_number(pszConvertedAnsiString);

		putText(Inspect_upper_clone, str_number, Point(result_value.upper_x[TabPoint][upper_result_count], result_value.upper_y[TabPoint][upper_result_count] - 20),
			80, 1.5, Scalar(0, 0, 255), 6, 8, false);

		upper_result_count++;
	}
	result_value.upper_num[TabPoint] = upper_result_count;

	// Side Value 정렬
	int side_result_count = 0;

	for (int i = 0; i < side_contours_count; i++)
	{
		result_value.side_x[TabPoint][side_result_count] = sort_side_detect[i].x;
		result_value.side_width[TabPoint][side_result_count] = sort_side_detect[i].width * 0.55;
		result_value.side_y[TabPoint][side_result_count] = sort_side_detect[i].y;
		result_value.side_height[TabPoint][side_result_count] = sort_side_detect[i].height * 0.55;
		result_value.side_ma_x_center[TabPoint][side_result_count] = sort_side_detect[i].x + sort_side_detect[i].width / 2;	// pixel 값
		result_value.side_ma_y_center[TabPoint][side_result_count] = sort_side_detect[i].y + sort_side_detect[i].height / 2;	// pixel 값

		number.Format(_T("%d"), side_result_count + 1);

		CT2CA pszConvertedAnsiString(number);
		std::string str_number(pszConvertedAnsiString);

		putText(Inspect_side_clone, str_number, Point(result_value.side_x[TabPoint][side_result_count], result_value.side_y[TabPoint][side_result_count] - 20),
			80, 1.5, Scalar(0, 0, 255), 6, 8, false);

		side_result_count++;
	}
	result_value.side_num[TabPoint] = side_result_count;

	int check_ma_x = 0;	// ng 발생 시 '1'
	int check_ma_y = 0;	// ng 발생 시 '1'
	int check_open = 0;	// ng 발생 시 '1'
	int check_short = 0;	// ng 발생 시 '1'
	int check_width = 0;	// ng 발생 시 '1'
	int check_height = 0;	// ng 발생 시 '1'

	// 상부 기준 가장 가까운 Pattern 과의 1대1 비교

	if (check_ng_ma_x == TRUE)
	{
		for (int i = 0; i < upper_contours_count; i++)
		{
			int minValue = 2048;
			int minPos = i;

			for (int j = 0; j < side_contours_count; j++)
			{
				double dist;
				dist = (result_value.upper_ma_x_center[TabPoint][i] - result_value.side_ma_x_center[TabPoint][j]);

				if (abs(dist) < minValue)
				{
					minValue = dist;
					minPos = j;
				}
			}

			result_value.ma_x[TabPoint][i] = (-(result_value.upper_ma_x_center[TabPoint][i] - result_value.side_ma_x_center[TabPoint][minPos]) * 0.55) + offset;

			// miss align 오차가 판정 범위 이내인 경우 (OK)
			if (abs(result_value.ma_x[TabPoint][i]) <= ma_x_range)
			{
				// upper image line draw
				line(Inspect_upper_clone, Point(result_value.upper_ma_x_center[TabPoint][i], 0),
					Point(result_value.upper_ma_x_center[TabPoint][i], 2048), Scalar(0, 255, 0), 3);

				// side image line draw
				// offset 값이 반영되어야 함 (1)
				line(Inspect_side_clone, Point(result_value.side_ma_x_center[TabPoint][minPos], 0),
					Point(result_value.side_ma_x_center[TabPoint][minPos], 2048), Scalar(0, 255, 0), 3);

				number.Format(_T("%d"), i + 1);

				CT2CA pszConvertedAnsiString(number);
				std::string str_number(pszConvertedAnsiString);

				putText(Inspect_upper_clone, str_number, Point(result_value.upper_ma_x_center[TabPoint][i], 50),
					80, 1.5, Scalar(0, 255, 0), 6, 8, false);

				result_value.result_ma_x[TabPoint][i] = 0;	// ok

				check_ma_x = 0;

				continue;
			}

			// miss align 오차가 판정 범위를 벗어난 경우 (NG) 
			else if (abs(result_value.ma_x[TabPoint][i]) > ma_x_range)
			{
				line(Inspect_upper_clone, Point(result_value.upper_ma_x_center[TabPoint][i], 0),
					Point(result_value.upper_ma_x_center[TabPoint][i], 2048), Scalar(ma_x_b, ma_x_g, ma_x_r), 3);

				// side image line draw
				// offset 값이 반영되어야 함 (1)
				line(Inspect_side_clone, Point(result_value.side_ma_x_center[TabPoint][minPos], 0),
					Point(result_value.side_ma_x_center[TabPoint][minPos], 2048), Scalar(ma_x_b, ma_x_g, ma_x_r), 3);

				number.Format(_T("%d"), i + 1);

				CT2CA pszConvertedAnsiString(number);
				std::string str_number(pszConvertedAnsiString);

				putText(Inspect_upper_clone, str_number, Point(result_value.upper_ma_x_center[TabPoint][i], 50),
					80, 1.5, Scalar(0, 0, 255), 6, 8, false);

				result_value.result_ma_x[TabPoint][i] = 1;	// ng

				check_ma_x = 1;

				continue;
			}
		}
	}


	/*if (check_ng_ma_y == TRUE)
	{
		for (int i = 0; i < side_contours_count; i++)
		{
			double dist;

			result_value.ma_y[TabPoint][i] = (result_value.side_ma_y_center[TabPoint][i] - edge_position) * 0.55;

			// 지정된 Center 값에서 일정 영역 이상으로 벗어난 경우
			if (result_value.ma_y[TabPoint][i] <= ma_y_value - ma_y_range || result_value.ma_y[TabPoint][i] >= ma_y_value + ma_y_range)
			{
				line(Inspect_side_clone, Point(result_value.side_x[TabPoint][i], result_value.side_ma_y_center[TabPoint][i]),
					Point(result_value.side_x[TabPoint][i] + result_value.side_width[TabPoint][i] / 0.55, result_value.side_ma_y_center[TabPoint][i]), Scalar(ma_y_b, ma_y_g, ma_y_r), 3);

				result_value.result_ma_y[TabPoint][i] = 1;

				check_ma_y = 1;

				continue;
			}

			else if (result_value.ma_y[TabPoint][i] > ma_y_value - ma_y_range && result_value.ma_y[TabPoint][i] < ma_y_value + ma_y_range)
			{
				line(Inspect_side_clone, Point(result_value.side_x[TabPoint][i], result_value.side_ma_y_center[TabPoint][i]),
					Point(result_value.side_x[TabPoint][i] + result_value.side_width[TabPoint][i] / 0.55, result_value.side_ma_y_center[TabPoint][i]), Scalar(0, 255, 0), 3);

				result_value.result_ma_y[TabPoint][i] = 0;

				continue;
			}
		}
	}*/


	if (check_ng_open == TRUE)
	{
		for (int i = 0; i < side_contours_count - 1; i++)
		{
			if (result_value.side_x[TabPoint][i + 1] > result_value.side_x[TabPoint][i] &&
				result_value.side_x[TabPoint][i + 1] < result_value.side_x[TabPoint][i] + (result_value.side_width[TabPoint][i] / 0.55))
			{
				rectangle(Inspect_side_clone, Point(result_value.side_x[TabPoint][i], result_value.side_y[TabPoint][i]),
					Point(result_value.side_x[TabPoint][i] + result_value.side_width[TabPoint][i] / 0.55,
						result_value.side_y[TabPoint][i] + result_value.side_height[TabPoint][i] / 0.55), Scalar(open_b, open_g, open_r), 8, 8, 0);

				rectangle(Inspect_side_clone, Point(result_value.side_x[TabPoint][i + 1], result_value.side_y[TabPoint][i + 1]),
					Point(result_value.side_x[TabPoint][i + 1] + result_value.side_width[TabPoint][i + 1] / 0.55,
						result_value.side_y[TabPoint][i + 1] + result_value.side_height[TabPoint][i + 1] / 0.55), Scalar(open_b, open_g, open_r), 8, 8, 0);

				result_value.result_open[TabPoint][i] = 1;
				result_value.result_open[TabPoint][i + 1] = 1;

				i = i + 1;

				check_open = 1;
			}

			else
				result_value.result_open[TabPoint][i] = 0;
		}
	}

	if (check_ng_short == TRUE)
	{
		for (int i = 0; i < side_contours_count; i++)
		{
			if (result_value.side_width[TabPoint][i] > (width + space))
			{
				rectangle(Inspect_side_clone, Point(result_value.side_x[TabPoint][i], result_value.side_y[TabPoint][i]),
					Point(result_value.side_x[TabPoint][i] + result_value.side_width[TabPoint][i] / 0.55,
						result_value.side_y[TabPoint][i] + result_value.side_height[TabPoint][i] / 0.55), Scalar(short_b, short_g, short_r), 8, 8, 0);

				result_value.result_short[TabPoint][i] = 1;

				check_short = 1;
			}

			else
				result_value.result_short[TabPoint][i] = 0;
		}
	}

	if (check_ng_width == TRUE)
	{
		for (int i = 0; i < side_contours_count; i++)
		{
			if (result_value.side_width[TabPoint][i] < width - width_range ||
				result_value.side_width[TabPoint][i] > width + width_range)
			{
				result_value.result_width[TabPoint][i] = 1;

				check_width = 1;
			}

			else
				result_value.result_width[TabPoint][i] = 0;
		}
	}

	if (check_ng_height == TRUE)
	{
		for (int i = 0; i < side_contours_count; i++)
		{
			if (result_value.side_height[TabPoint][i] < height - height_range ||
				result_value.side_height[TabPoint][i] > height + height_range)
			{
				result_value.result_height[TabPoint][i] = 1;

				check_height = 1;
			}

			else
				result_value.result_height[TabPoint][i] = 0;
		}
	}

	// 이미지 저장
	CString NumofTab;
	NumofTab.Format(_T("%d"), TabNum + 1);

	CString NumofPoint;
	NumofPoint.Format(_T("%d"), TabPoint + 1);

	CString save_upper;
	CString save_side;
	CString save_merge;

	saveTabPath = result_path + _T("\\") + NumofTab;

	if (TabPoint == 0)
		::CreateDirectory(saveTabPath, NULL);

	save_upper = saveTabPath + _T("\\") + NumofTab + _T("_") + NumofPoint + _T("_UPPER.bmp");
	CT2CA pszConvertedAnsiString_upper(save_upper);
	std::string upper_name(pszConvertedAnsiString_upper);
	imwrite(upper_name, Inspect_upper_clone);

	save_side = saveTabPath + _T("\\") + NumofTab + _T("_") + NumofPoint + _T("_SIDE.bmp");
	CT2CA pszConvertedAnsiString_side(save_side);
	std::string side_name(pszConvertedAnsiString_side);
	imwrite(side_name, Inspect_side_clone);

	vconcat(Inspect_upper_clone, Inspect_side_clone, Merge_result);

	mergeInfo = (BITMAPINFO *)mergeBuf;
	mergeInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	mergeInfo->bmiHeader.biWidth = Merge_result.cols;
	mergeInfo->bmiHeader.biHeight = -(Merge_result.rows);
	mergeInfo->bmiHeader.biBitCount = 24;
	mergeInfo->bmiHeader.biPlanes = 1;
	mergeInfo->bmiHeader.biCompression = BI_RGB;
	mergeInfo->bmiHeader.biSizeImage = 0;
	mergeInfo->bmiHeader.biXPelsPerMeter = 0;
	mergeInfo->bmiHeader.biYPelsPerMeter = 0;
	mergeInfo->bmiHeader.biClrUsed = 0;
	mergeInfo->bmiHeader.biClrImportant = 0;

	save_merge = saveTabPath + _T("\\") + NumofTab + _T("_") + NumofPoint + _T("_MERGE.bmp");
	CT2CA pszConvertedAnsiString_merge(save_merge);
	std::string merge_name(pszConvertedAnsiString_merge);

	imwrite(merge_name, Merge_result);

	//CString save_origin;
	if (check_ma_x == 1 || check_ma_y == 1 || check_open == 1 || check_short == 1 || check_width == 1 || check_height == 1)
		result_value.total_result[TabPoint + (TabNum * (int)tab_point)] = 1;

	else
		result_value.total_result[TabPoint + (TabNum * (int)tab_point)] = 0;

	if (result_value.total_result[TabPoint + (TabNum * (int)tab_point)] == 1)
	{
		m_list_result.InsertItem(ng_result_list_count, NumofTab);
		m_list_result.SetItemText(ng_result_list_count, 1, NumofPoint);
		m_list_result.SetItemText(ng_result_list_count, 2, _T("NG"));

		ng_result_list_count++;
	}

	else if (result_value.total_result[TabPoint + (TabNum * (int)tab_point)] == 0)
	{
		m_list_result.InsertItem(ng_result_list_count, NumofTab);
		m_list_result.SetItemText(ng_result_list_count, 1, NumofPoint);
		m_list_result.SetItemText(ng_result_list_count, 2, _T("OK"));

		ng_result_list_count++;
	}


	CString Num_ma;

	for (int i = 0; i < upper_result_count; i++)
	{
		if (result_value.result_ma_x[TabPoint][i] == 1)
		{
			CString ma_x_result;

			Num_ma.Format(_T("%d"), i + 1);
			ma_x_result.Format(_T("%.3f"), result_value.ma_x[TabPoint][i]);

			m_list_ma_x.InsertItem(ng_ma_x_list_count, NumofTab);
			m_list_ma_x.SetItemText(ng_ma_x_list_count, 1, NumofPoint);
			m_list_ma_x.SetItemText(ng_ma_x_list_count, 2, Num_ma);
			m_list_ma_x.SetItemText(ng_ma_x_list_count, 3, ma_x_result);
			ng_ma_x_list_count++;
		}
	}

	for (int i = 0; i < side_result_count; i++)
	{
		if (result_value.result_ma_y[TabPoint][i] == 1)
		{
			CString ma_y_result;

			Num_ma.Format(_T("%d"), i + 1);
			ma_y_result.Format(_T("%.3f"), result_value.ma_y[TabPoint][i]);

			m_list_ma_y.InsertItem(ng_ma_y_list_count, NumofTab);
			m_list_ma_y.SetItemText(ng_ma_y_list_count, 1, NumofPoint);
			m_list_ma_y.SetItemText(ng_ma_y_list_count, 2, Num_ma);
			m_list_ma_y.SetItemText(ng_ma_y_list_count, 3, ma_y_result);
			ng_ma_y_list_count++;
		}
	}

	for (int i = 0; i < side_result_count; i++)
	{
		CString Num_os;

		if (result_value.result_open[TabPoint][i] == 1)
		{
			Num_os.Format(_T("%d"), i + 1);
			m_list_os.InsertItem(ng_os_list_count, NumofTab);
			m_list_os.SetItemText(ng_os_list_count, 1, NumofPoint);
			m_list_os.SetItemText(ng_os_list_count, 2, Num_os);
			m_list_os.SetItemText(ng_os_list_count, 3, _T("OPEN NG"));
			m_list_os.SetItemText(ng_os_list_count, 4, _T("-"));

			ng_os_list_count++;
		}

		if (result_value.result_short[TabPoint][i] == 1)
		{
			Num_os.Format(_T("%d"), i + 1);
			m_list_os.InsertItem(ng_os_list_count, NumofTab);
			m_list_os.SetItemText(ng_os_list_count, 1, NumofPoint);
			m_list_os.SetItemText(ng_os_list_count, 2, Num_os);
			m_list_os.SetItemText(ng_os_list_count, 3, _T("-"));
			m_list_os.SetItemText(ng_os_list_count, 4, _T("SHORT NG"));

			ng_os_list_count++;
		}
	}

	for (int i = 0; i < side_result_count; i++)
	{
		CString Num_other;

		if (result_value.result_width[TabPoint][i] == 1 && result_value.result_height[TabPoint][i] == 1)
		{
			CString width_result;
			CString height_result;

			Num_other.Format(_T("%d"), i + 1);
			width_result.Format(_T("%.4f"), result_value.side_width[TabPoint][i]);
			height_result.Format(_T("%.4f"), result_value.side_height[TabPoint][i]);

			m_list_other.InsertItem(ng_other_list_count, NumofTab);
			m_list_other.SetItemText(ng_other_list_count, 1, NumofPoint);
			m_list_other.SetItemText(ng_other_list_count, 2, Num_other);
			m_list_other.SetItemText(ng_other_list_count, 3, width_result);
			m_list_other.SetItemText(ng_other_list_count, 4, height_result);

			ng_other_list_count++;
		}
		else if (result_value.result_width[TabPoint][i] == 1)
		{
			CString width_result;

			Num_other.Format(_T("%d"), i + 1);
			width_result.Format(_T("%.4f"), result_value.side_width[TabPoint][i]);

			m_list_other.InsertItem(ng_other_list_count, NumofTab);
			m_list_other.SetItemText(ng_other_list_count, 1, NumofPoint);
			m_list_other.SetItemText(ng_other_list_count, 2, Num_other);
			m_list_other.SetItemText(ng_other_list_count, 3, width_result);
			m_list_other.SetItemText(ng_other_list_count, 4, _T("-"));

			ng_other_list_count++;
		}

		else if (result_value.result_height[TabPoint][i] == 1)
		{
			CString height_result;

			Num_other.Format(_T("%d"), i + 1);
			height_result.Format(_T("%.4f"), result_value.side_height[TabPoint][i]);

			m_list_other.InsertItem(ng_other_list_count, NumofTab);
			m_list_other.SetItemText(ng_other_list_count, 1, NumofPoint);
			m_list_other.SetItemText(ng_other_list_count, 2, Num_other);
			m_list_other.SetItemText(ng_other_list_count, 3, _T("-"));
			m_list_other.SetItemText(ng_other_list_count, 4, height_result);

			ng_other_list_count++;
		}
	}


	CString str_tab;
	str_tab.Format(_T("Tab : %d, Point : %d - INSPECTION COMPLETE."), TabNum + 1, TabPoint + 1);

	log_time = CTime::GetCurrentTime();
	str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), log_time.GetYear(), log_time.GetMonth(), log_time.GetDay(), log_time.GetHour(), log_time.GetMinute(), log_time.GetSecond());

	display_log(str_log_time, _T("INSPECTION"), _T("INSPECTION"), str_tab, log_count);

}


void DIALOG_AUTO::Image_manual_Inspect()
{
	if (upper_camera_status == 1 && side_camera_status == 1)
	{
		MdigHalt(area_cam.m_MilDigitizer_Upper);
		MdigHalt(area_cam.m_MilDigitizer_Side);
	}

	else if (upper_camera_status == 1)
		MdigHalt(area_cam.m_MilDigitizer_Upper);

	else if (side_camera_status == 1)
		MdigHalt(area_cam.m_MilDigitizer_Side);

	upper_camera_status = 0;
	side_camera_status = 0;

	CString saveManual_upper;
	CString saveManual_side;

	saveManual_upper = origin_path + _T("\\upper.bmp");
	saveManual_side = origin_path + _T("\\side.bmp");

	folder_path = folder_path + str_inspection_start_time;

	MdigGrab(area_cam.m_MilDigitizer_Upper, area_cam.m_MilImage_Upper);
	MdigGrab(area_cam.m_MilDigitizer_Side, area_cam.m_MilImage_Side);

	Mat Inspect_upper_load;
	Mat Inspect_side_load;

	Mat Inspect_upper_clone;
	Mat Inspect_side_clone;

	Mat Inspect_upper_morphology;
	Mat Inspect_side_morphology;

	Mat Inspect_upper_binary;
	Mat Inspect_side_binary;
	Mat Inspect_edge_binary;

	Mat Inspect_upper_canny;
	Mat Inspect_side_canny;

	MbufExport(saveManual_upper, M_BMP, area_cam.m_MilImage_Upper);
	MbufExport(saveManual_side, M_BMP, area_cam.m_MilImage_Side);

	CT2CA upperConvertTitle(saveManual_upper);
	std::string upperTitle(upperConvertTitle);

	CT2CA sideConvertTitle(saveManual_side);
	std::string sideTitle(sideConvertTitle);

	// Real Time
	Inspect_upper_load = imread(upperTitle);
	Inspect_side_load = imread(sideTitle);

	loadInfo = (BITMAPINFO*)loadBuf;
	loadInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	loadInfo->bmiHeader.biWidth = Inspect_upper_load.cols;
	loadInfo->bmiHeader.biHeight = -(Inspect_upper_load.rows);
	loadInfo->bmiHeader.biBitCount = 24;
	loadInfo->bmiHeader.biPlanes = 1;
	loadInfo->bmiHeader.biCompression = BI_RGB;
	loadInfo->bmiHeader.biSizeImage = 0;
	loadInfo->bmiHeader.biXPelsPerMeter = 0;
	loadInfo->bmiHeader.biYPelsPerMeter = 0;
	loadInfo->bmiHeader.biClrUsed = 0;
	loadInfo->bmiHeader.biClrImportant = 0;


	// image 전처리 순서
	// rgb2gray->morphology->binary->canny->contour
	// Image Copy

	Inspect_upper_clone = Inspect_upper_load.clone();
	Inspect_side_clone = Inspect_side_load.clone();

	// rgb2gray
	cvtColor(Inspect_upper_load, Inspect_upper_load, COLOR_BGR2GRAY);
	cvtColor(Inspect_side_load, Inspect_side_load, COLOR_BGR2GRAY);

	int upper_edge_sum[2500] = { 0 };

	for (int i = upper_roi_min; i < upper_roi_max; i++)
	{
		for (int j = 0; j < 2048; j++)
		{
			int intensity = Inspect_upper_load.at<uchar>(i, j);
			upper_edge_sum[i] += intensity;
		}
	}
	int upper_edge = 0;

	for (int i = upper_roi_min; i < upper_roi_max; i++)
	{
		// 해상도에서 절반 이상의 Pixel 이 검출
		// 검출 안되면 
		//if (upper_edge_sum[i] > (2048 / 3 * 255))
		if (upper_edge_sum[i] > 200000)
		{
			upper_edge = i;
			break;
		}
	}
	int upper_edge_2;
	upper_edge_2 = upper_edge + 95;

	// upper copper 측 line 그리기
	// copper 이어진 부분 없애기 위해
	for (int i = 0; i < 2048; i++)
	{
		for (int j = 0; j < upper_roi_max - upper_edge_2; j++)
		{
			Inspect_upper_load.at<uchar>(upper_edge_2 + j, i) = 0;
		}
	}
	// morphology
	Mat element_open(morphology_open, morphology_open, CV_8U, cv::Scalar(1));
	Mat element_close(morphology_close, morphology_close, CV_8U, cv::Scalar(1));

	morphologyEx(Inspect_upper_load, Inspect_upper_morphology, cv::MORPH_CLOSE, element_open);
	morphologyEx(Inspect_upper_morphology, Inspect_upper_morphology, cv::MORPH_OPEN, element_close);

	morphologyEx(Inspect_side_load, Inspect_side_morphology, cv::MORPH_CLOSE, element_open);
	morphologyEx(Inspect_side_morphology, Inspect_side_morphology, cv::MORPH_OPEN, element_close);

	// binary
	threshold(Inspect_upper_morphology, Inspect_upper_binary, binary_upper, 255, THRESH_BINARY);
	threshold(Inspect_side_morphology, Inspect_side_binary, binary_side, 255, THRESH_BINARY);
	threshold(Inspect_side_morphology, Inspect_edge_binary, binary_edge, 255, THRESH_BINARY);

	// start, end position 
	int upper_pixel_sum[2500] = { 0 };

	int side_pixel_sum[2500] = { 0 };

	int edge_position = 0;

	int edge_pixel_sum[2500] = { 0 };

	double upper_dist_1 = 0;
	double upper_dist_2 = 0;
	double side_dist_1 = 0;


	// 상부 roi 이내의 Pixel 값 정렬
	for (int i = 0; i < 2048; i++)
	{
		for (int j = upper_roi_min; j < upper_edge_2; j++)
		{
			int intensity = Inspect_upper_binary.at<uchar>(j, i);
			upper_pixel_sum[i] += intensity;
		}
	}

	// 측면부 roi 이내의 Pixel 값 정렬
	for (int i = 0; i < 2048; i++)
	{
		for (int j = side_roi_min; j < side_roi_max; j++)
		{
			int intensity = Inspect_side_binary.at<uchar>(j, i);
			side_pixel_sum[i] += intensity;
		}
	}

	// 측면부(Edge) roi 이내의 Pixel 값 정렬
	for (int i = edge_roi_min; i < edge_roi_max; i++)
	{
		for (int j = 0; j < 2048; j++)
		{
			int intensity = Inspect_edge_binary.at<uchar>(i, j);
			edge_pixel_sum[i] += intensity;
		}
	}

	// Edge 경계면 검출
	for (int i = edge_roi_min; i < edge_roi_max; i++)
	{
		// 해상도에서 절반 이상의 Pixel 이 검출
		// 검출 안되면 
		if (edge_pixel_sum[i] > (2048 / 2 * 255))
		{
			edge_position = i;
			break;
		}
	}

	upper_start_position = 0;
	upper_end_position = 2048;

	side_start_position = 0;
	side_end_position = 2048;

	// upper
	for (int i = 0; i < 2048; i++)
	{
		if (upper_pixel_sum[i] == 0 && upper_pixel_sum[i + 1])
		{
			upper_start_position = i;
			break;
		}
	}

	for (int i = 2048 - 2; i > 0; i--)
	{
		if (upper_pixel_sum[i] != 0 && upper_pixel_sum[i + 1] == 0)
		{
			upper_end_position = i;
			break;
		}
	}


	for (int i = 0; i < 2048; i++)
	{
		if (side_pixel_sum[i] == 0 && side_pixel_sum[i + 1])
		{
			side_start_position = i;
			break;
		}
	}

	for (int i = 2048 - 2; i > 0; i--)
	{
		if (side_pixel_sum[i] != 0 && side_pixel_sum[i + 1] == 0)
		{
			side_end_position = i;
			break;
		}
	}

	// canny
	Canny(Inspect_upper_binary, Inspect_upper_canny, 100, 100 * 3, 3);
	Canny(Inspect_side_binary, Inspect_side_canny, 100, 100 * 3, 3);

	// contour
	vector<vector<Point> > upper_contours;
	vector<vector<Point> > side_contours;
	vector<Vec4i>	hierarchy;

	findContours(Inspect_upper_canny, upper_contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point());
	findContours(Inspect_side_canny, side_contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point());

	vector<vector<Point>> contours_poly_u(upper_contours.size());
	vector<Rect> boundRect_u(upper_contours.size());

	vector<vector<Point>> contours_poly_s(side_contours.size());
	vector<Rect> boundRect_s(side_contours.size());

	for (int i = 0; i < upper_contours.size(); i++)
	{
		approxPolyDP(Mat(upper_contours[i]), contours_poly_u[i], 1, true);
		boundRect_u[i] = boundingRect(Mat(contours_poly_u[i]));
	}

	for (int i = 0; i < side_contours.size(); i++)
	{
		approxPolyDP(Mat(side_contours[i]), contours_poly_s[i], 1, true);
		boundRect_s[i] = boundingRect(Mat(contours_poly_s[i]));
	}

	vector<Rect> boundRect_u_detect(upper_contours.size());
	vector<Rect> boundRect_s_detect(side_contours.size());

	// 검출된 상부 contour의 수
	int upper_contours_count = 0;

	for (int i = 0; i < upper_contours.size(); i++)
	{
		// Detect 된 Contour 가 roi 영역(Y) 내에 있고, 
		// 일정 Size 이상이며, 
		// 시작과 끝(X) 사이에 위치한 경우에 
		if (boundRect_u[i].y >= upper_roi_min && boundRect_u[i].y < upper_roi_max &&
			boundRect_u[i].area() >= upper_contour && boundRect_u[i].area() < 50000 &&
			boundRect_u[i].x >= upper_start_position && boundRect_u[i].x <= upper_end_position
			&& boundRect_u[i].width < 100)
		{
			// 상부 copper 는 모두 다 green
			// Scalar (blue, green, red)

			drawContours(Inspect_upper_clone, upper_contours, i, Scalar(0, 255, 0), 2, 8, hierarchy, 0, Point());
			boundRect_u_detect[upper_contours_count] = boundRect_u[i];
			upper_contours_count++;
		}
	}

	// side contours
	// width & height check

	int side_contours_count = 0;

	for (int i = 0; i < side_contours.size(); i++)
	{
		// Detect 된 Contour 가 roi 영역(Y) 내에 있고, 
		// 일정 Size 이상이며, 
		// 시작과 끝(X) 사이에 위치한 경우에 
		if (boundRect_s[i].y >= side_roi_min && boundRect_s[i].y < side_roi_max &&
			boundRect_s[i].area() >= side_contour &&
			boundRect_s[i].x >= side_start_position && boundRect_s[i].x <= side_end_position)
		{
			if (check_ng_both == true)
			{
				if (boundRect_s[i].width > (width - width_range) / 0.55 &&
					boundRect_s[i].width < (width + width_range) / 0.55)
				{
					if (boundRect_s[i].height > (height - height_range) / 0.55 &&
						boundRect_s[i].height < (height + height_range) / 0.55)
					{
						// OK의 경우 Green
						drawContours(Inspect_side_clone, side_contours, i, Scalar(0, 255, 0), 2, 8, hierarchy, 0, Point());
						boundRect_s_detect[side_contours_count] = boundRect_s[i];
						side_contours_count++;
					}

					else
					{
						drawContours(Inspect_side_clone, side_contours, i, Scalar(height_b, height_g, height_r), 2, 8, hierarchy, 0, Point());
						boundRect_s_detect[side_contours_count] = boundRect_s[i];
						side_contours_count++;
					}
				}

				else
				{
					// 둘다 ng 인 경우
					if (boundRect_s[i].height< (height - height_range) / 0.55 ||
						boundRect_s[i].height >(height + height_range) / 0.55)
					{
						drawContours(Inspect_side_clone, side_contours, i, Scalar(both_b, both_g, both_r), 2, 8, hierarchy, 0, Point());
						boundRect_s_detect[side_contours_count] = boundRect_s[i];
						side_contours_count++;
					}

					// width 만 ng
					else
					{
						drawContours(Inspect_side_clone, side_contours, i, Scalar(width_b, width_g, width_r), 2, 8, hierarchy, 0, Point());
						boundRect_s_detect[side_contours_count] = boundRect_s[i];
						side_contours_count++;
					}
				}
			}

			else if (check_ng_width == true)
			{
				if (boundRect_s[i].width > (width - width_range) / 0.55 &&
					boundRect_s[i].width < (width + width_range) / 0.55)
				{
					// OK의 경우 Green
					drawContours(Inspect_side_clone, side_contours, i, Scalar(0, 255, 0), 2, 8, hierarchy, 0, Point());
					boundRect_s_detect[side_contours_count] = boundRect_s[i];
					side_contours_count++;
				}

				else
				{
					drawContours(Inspect_side_clone, side_contours, i, Scalar(width_b, width_g, width_r), 2, 8, hierarchy, 0, Point());
					boundRect_s_detect[side_contours_count] = boundRect_s[i];
					side_contours_count++;
				}
			}

			else if (check_ng_height == true)
			{
				if (boundRect_s[i].height > (height - height_range) / 0.55 &&
					boundRect_s[i].height < (height + height_range) / 0.55)
				{
					// OK의 경우 Green
					drawContours(Inspect_side_clone, side_contours, i, Scalar(0, 255, 0), 2, 8, hierarchy, 0, Point());
					boundRect_s_detect[side_contours_count] = boundRect_s[i];
					side_contours_count++;
				}

				else
				{
					drawContours(Inspect_side_clone, side_contours, i, Scalar(height_b, height_g, height_r), 2, 8, hierarchy, 0, Point());
					boundRect_s_detect[side_contours_count] = boundRect_s[i];
					side_contours_count++;
				}
			}

		}
	}

	// 검출된 contour 정렬 (좌측 부터 순서대로)
	vector<Rect> sort_upper_detect(upper_contours_count);
	vector<Rect> sort_side_detect(side_contours_count);

	int detect_u_pos[500] = { 0 };
	int detect_s_pos[500] = { 0 };

	for (int i = 0; i < upper_contours_count; i++)
		detect_u_pos[i] = boundRect_u_detect[i].x;

	for (int i = 0; i < side_contours_count; i++)
		detect_s_pos[i] = boundRect_s_detect[i].x;

	sort(detect_u_pos, detect_u_pos + upper_contours_count);
	sort(detect_s_pos, detect_s_pos + side_contours_count);

	for (int i = 0; i < upper_contours_count; i++)
	{
		for (int j = 0; j < upper_contours_count; j++)
		{
			if (boundRect_u_detect[j].x == detect_u_pos[i])
				sort_upper_detect[i] = boundRect_u_detect[j];
		}
	}

	for (int i = 0; i < side_contours_count; i++)
	{
		for (int j = 0; j < side_contours_count; j++)
		{
			if (boundRect_s_detect[j].x == detect_s_pos[i])
				sort_side_detect[i] = boundRect_s_detect[j];
		}
	}

	// Upper Value 정렬
	int upper_result_count = 0;
	CString number;

	for (int i = 0; i < upper_contours_count; i++)
	{
		manual_result_value.upper_x[upper_result_count] = sort_upper_detect[i].x;
		manual_result_value.upper_width[upper_result_count] = sort_upper_detect[i].width * 0.55;
		manual_result_value.upper_y[upper_result_count] = sort_upper_detect[i].y;
		manual_result_value.upper_height[upper_result_count] = sort_upper_detect[i].height * 0.55;
		manual_result_value.upper_ma_x_center[upper_result_count] = sort_upper_detect[i].x + sort_upper_detect[i].width / 2;	// pixel 값

		number.Format(_T("%d"), upper_result_count + 1);

		CT2CA pszConvertedAnsiString(number);
		std::string str_number(pszConvertedAnsiString);

		putText(Inspect_upper_clone, str_number, Point(manual_result_value.upper_x[upper_result_count], manual_result_value.upper_y[upper_result_count] - 20),
			80, 1.5, Scalar(0, 0, 255), 6, 8, false);

		upper_result_count++;
	}

	manual_result_value.upper_num = upper_result_count;

	// Side Value 정렬
	int side_result_count = 0;

	for (int i = 0; i < side_contours_count; i++)
	{
		manual_result_value.side_x[side_result_count] = sort_side_detect[i].x;
		manual_result_value.side_width[side_result_count] = sort_side_detect[i].width * 0.55;
		manual_result_value.side_y[side_result_count] = sort_side_detect[i].y;
		manual_result_value.side_height[side_result_count] = sort_side_detect[i].height * 0.55;
		manual_result_value.side_ma_x_center[side_result_count] = sort_side_detect[i].x + sort_side_detect[i].width / 2;	// pixel 값
		manual_result_value.side_ma_y_center[side_result_count] = sort_side_detect[i].y + sort_side_detect[i].height / 2;	// pixel 값

		number.Format(_T("%d"), side_result_count + 1);

		CT2CA pszConvertedAnsiString(number);
		std::string str_number(pszConvertedAnsiString);

		putText(Inspect_side_clone, str_number, Point(manual_result_value.side_x[side_result_count], manual_result_value.side_y[side_result_count] - 20),
			80, 1.5, Scalar(0, 0, 255), 6, 8, false);

		side_result_count++;
	}

	manual_result_value.side_num = side_result_count;

	int check_ma_x = 0;	// ng 발생 시 '1'
	int check_ma_y = 0;	// ng 발생 시 '1'
	int check_open = 0;	// ng 발생 시 '1'
	int check_short = 0;	// ng 발생 시 '1'
	int check_width = 0;	// ng 발생 시 '1'
	int check_height = 0;	// ng 발생 시 '1'

	// 상부 기준 가장 가까운 Pattern 과의 1대1 비교

	if (check_ng_ma_x == TRUE)
	{
		for (int i = 0; i < upper_contours_count; i++)
		{
			int minValue = 2048;
			int minPos = i;

			for (int j = 0; j < side_contours_count; j++)
			{
				double dist;
				dist = (manual_result_value.upper_ma_x_center[i] - manual_result_value.side_ma_x_center[j]);

				if (abs(dist) < minValue)
				{
					minValue = dist;
					minPos = j;
				}
			}

			manual_result_value.ma_x[i] = (-(manual_result_value.upper_ma_x_center[i] - manual_result_value.side_ma_x_center[minPos]) * 0.55) + offset;

			// miss align 오차가 판정 범위 이내인 경우 (OK)
			if (abs(manual_result_value.ma_x[i]) <= ma_x_range)
			{
				// upper image line draw
				line(Inspect_upper_clone, Point(manual_result_value.upper_ma_x_center[i], 0),
					Point(manual_result_value.upper_ma_x_center[i], 2048), Scalar(0, 255, 0), 3);

				// side image line draw
				// offset 값이 반영되어야 함 (1)
				line(Inspect_side_clone, Point(manual_result_value.side_ma_x_center[minPos], 0),
					Point(manual_result_value.side_ma_x_center[minPos], 2048), Scalar(0, 255, 0), 3);

				number.Format(_T("%d"), i + 1);

				CT2CA pszConvertedAnsiString(number);
				std::string str_number(pszConvertedAnsiString);

				putText(Inspect_upper_clone, str_number, Point(manual_result_value.upper_ma_x_center[i], 50),
					80, 1.5, Scalar(0, 255, 0), 6, 8, false);

				manual_result_value.result_ma_x[i] = 0;	// ok

				check_ma_x = 0;

				continue;
			}

			// miss align 오차가 판정 범위를 벗어난 경우 (NG) 
			else if (abs(manual_result_value.ma_x[i]) > ma_x_range)
			{
				line(Inspect_upper_clone, Point(manual_result_value.upper_ma_x_center[i], 0),
					Point(manual_result_value.upper_ma_x_center[i], 2048), Scalar(ma_x_b, ma_x_g, ma_x_r), 3);

				// side image line draw
				// offset 값이 반영되어야 함 (1)
				line(Inspect_side_clone, Point(manual_result_value.side_ma_x_center[minPos], 0),
					Point(manual_result_value.side_ma_x_center[minPos], 2048), Scalar(ma_x_b, ma_x_g, ma_x_r), 3);

				number.Format(_T("%d"), i + 1);

				CT2CA pszConvertedAnsiString(number);
				std::string str_number(pszConvertedAnsiString);

				putText(Inspect_upper_clone, str_number, Point(manual_result_value.upper_ma_x_center[i], 50),
					80, 1.5, Scalar(0, 0, 255), 6, 8, false);

				manual_result_value.result_ma_x[i] = 1;	// ng

				check_ma_x = 1;

				continue;
			}
		}
	}

	if (check_ng_open == TRUE)
	{
		for (int i = 0; i < side_contours_count - 1; i++)
		{
			if (manual_result_value.side_x[i + 1] > manual_result_value.side_x[i] &&
				manual_result_value.side_x[i + 1] < manual_result_value.side_x[i] + (manual_result_value.side_width[i] / 0.55))
			{
				rectangle(Inspect_side_clone, Point(manual_result_value.side_x[i], manual_result_value.side_y[i]),
					Point(manual_result_value.side_x[i] + manual_result_value.side_width[i] / 0.55,
						manual_result_value.side_y[i] + manual_result_value.side_height[i] / 0.55), Scalar(open_b, open_g, open_r), 8, 8, 0);

				rectangle(Inspect_side_clone, Point(manual_result_value.side_x[i + 1], manual_result_value.side_y[i + 1]),
					Point(manual_result_value.side_x[i + 1] + manual_result_value.side_width[i + 1] / 0.55,
						manual_result_value.side_y[i + 1] + manual_result_value.side_height[i + 1] / 0.55), Scalar(open_b, open_g, open_r), 8, 8, 0);

				manual_result_value.result_open[i] = 1;
				manual_result_value.result_open[i + 1] = 1;

				i = i + 1;

				check_open = 1;
			}

			else
				manual_result_value.result_open[i] = 0;
		}
	}

	if (check_ng_short == TRUE)
	{
		for (int i = 0; i < side_contours_count; i++)
		{
			if (manual_result_value.side_width[i] > (width + space))
			{
				rectangle(Inspect_side_clone, Point(manual_result_value.side_x[i], manual_result_value.side_y[i]),
					Point(manual_result_value.side_x[i] + manual_result_value.side_width[i] / 0.55,
						manual_result_value.side_y[i] + manual_result_value.side_height[i] / 0.55), Scalar(short_b, short_g, short_r), 8, 8, 0);

				manual_result_value.result_short[i] = 1;

				check_short = 1;
			}

			else
				manual_result_value.result_short[i] = 0;
		}
	}

	if (check_ng_width == TRUE)
	{
		for (int i = 0; i < side_contours_count; i++)
		{
			if (manual_result_value.side_width[i] < width - width_range ||
				manual_result_value.side_width[i] > width + width_range)
			{
				manual_result_value.result_width[i] = 1;

				check_width = 1;
			}

			else
				manual_result_value.result_width[i] = 0;
		}
	}

	if (check_ng_height == TRUE)
	{
		for (int i = 0; i < side_contours_count; i++)
		{
			if (manual_result_value.side_height[i] < height - height_range ||
				manual_result_value.side_height[i] > height + height_range)
			{
				manual_result_value.result_height[i] = 1;

				check_height = 1;
			}

			else
				manual_result_value.result_height[i] = 0;
		}
	}


	for (int i = 0; i < 2048; i++)
	{
		for (int j = 0; j < upper_roi_max - upper_edge_2; j++)
		{
			Inspect_upper_clone.at<uchar>(upper_edge_2 + j, i) = 255;
		}
	}

	saveManual_upper = result_path + _T("\\upper.bmp");
	saveManual_side = result_path + _T("\\side.bmp");

	CT2CA pszConvertedAnsiString_upper(saveManual_upper);
	std::string writeTitle_upper(pszConvertedAnsiString_upper);

	CT2CA pszConvertedAnsiString_side(saveManual_side);
	std::string writeTitle_side(pszConvertedAnsiString_side);

	imwrite(writeTitle_upper, Inspect_upper_clone);
	imwrite(writeTitle_side, Inspect_side_clone);

	Inspect_upper_clone = imread(writeTitle_upper);

	StretchDIBits(hdc_upper, 0, 0, 512, 512, 0, 0, Inspect_upper_clone.cols, Inspect_upper_clone.rows,
		Inspect_upper_clone.data, loadInfo, DIB_RGB_COLORS, SRCCOPY);

	StretchDIBits(hdc_side, 0, 0, 512, 512, 0, 0, Inspect_side_clone.cols, Inspect_side_clone.rows,
		Inspect_side_clone.data, loadInfo, DIB_RGB_COLORS, SRCCOPY);
}


void DIALOG_AUTO::ExcelResult(int TabNum)
{
	CXLEzAutomation XL(FALSE);

	XL.SetCellValue(2, 2, _T("TAB"));
	XL.SetCellValue(3, 2, _T("POINT"));
	XL.SetCellValue(4, 2, _T("JUDGE"));

	XL.SetCellValue(2, (tab_point + 2) + 2, _T("UPPER"));
	XL.SetCellValue(2, (tab_point + 2) + 3, _T("TAB"));
	XL.SetCellValue(3, (tab_point + 2) + 3, _T("POINT"));
	XL.SetCellValue(4, (tab_point + 2) + 3, _T("NUM"));
	XL.SetCellValue(5, (tab_point + 2) + 3, _T("X"));
	XL.SetCellValue(6, (tab_point + 2) + 3, _T("WIDTH"));
	XL.SetCellValue(7, (tab_point + 2) + 3, _T("Y"));
	XL.SetCellValue(8, (tab_point + 2) + 3, _T("HEIGHT"));
	XL.SetCellValue(9, (tab_point + 2) + 3, _T("MA_X_VALUE"));
	XL.SetCellValue(10, (tab_point + 2) + 3, _T("JUDGE"));

	CString excel_tab_num;
	CString excel_tab_point;

	int excel_upper_start_pos = 0;
	excel_upper_start_pos = (tab_point + 2) + 4;

	int result_count = 0;

	for (int j = 0; j < tab_point; j++)
	{
		excel_tab_num.Format(_T("%d"), TabNum + 1);
		excel_tab_point.Format(_T("%d"), j + 1);

		XL.SetCellValue(2, j + 3, excel_tab_num);
		XL.SetCellValue(3, j + 3, excel_tab_point);

		// upper
		for (int k = 0; k < result_value.upper_num[j]; k++)
		{
			CString upper_pat_num;
			CString upper_x;
			CString upper_width;
			CString upper_y;
			CString upper_height;
			CString excel_ma_x_value;
			CString excel_judge;

			upper_pat_num.Format(_T("%d"), k + 1);
			upper_x.Format(_T("%.2f"), result_value.upper_x[j][k]);
			upper_width.Format(_T("%.2f"), result_value.upper_width[j][k]);
			upper_y.Format(_T("%.2f"), result_value.upper_y[j][k]);
			upper_height.Format(_T("%.2f"), result_value.upper_height[j][k]);
			excel_ma_x_value.Format(_T("%.2f"), result_value.ma_x[j][k]);

			if (result_value.result_ma_x[j][k] == 0)
				excel_judge = _T("OK");

			else if (result_value.result_ma_x[j][k] == 1)
				excel_judge = _T("NG");

			else if (result_value.result_ma_x[j][k] == 2)
				excel_judge = _T("No Match");

			XL.SetCellValue(2, excel_upper_start_pos + k, excel_tab_num);	// tab
			XL.SetCellValue(3, excel_upper_start_pos + k, excel_tab_point);	// point
			XL.SetCellValue(4, excel_upper_start_pos + k, upper_pat_num);	// num
			XL.SetCellValue(5, excel_upper_start_pos + k, upper_x);	// x
			XL.SetCellValue(6, excel_upper_start_pos + k, upper_width);	// width
			XL.SetCellValue(7, excel_upper_start_pos + k, upper_y);	// y
			XL.SetCellValue(8, excel_upper_start_pos + k, upper_height);	// height
			XL.SetCellValue(9, excel_upper_start_pos + k, excel_ma_x_value);	// ma_value
			XL.SetCellValue(10, excel_upper_start_pos + k, excel_judge);	// judge
		}
		excel_upper_start_pos = excel_upper_start_pos + result_value.upper_num[j];
	}

	XL.SetCellValue(2, excel_upper_start_pos + 1, _T("SIDE"));
	XL.SetCellValue(2, excel_upper_start_pos + 2, _T("TAB"));
	XL.SetCellValue(3, excel_upper_start_pos + 2, _T("POINT"));
	XL.SetCellValue(4, excel_upper_start_pos + 2, _T("NUM"));
	XL.SetCellValue(5, excel_upper_start_pos + 2, _T("X"));
	XL.SetCellValue(6, excel_upper_start_pos + 2, _T("WIDTH"));
	XL.SetCellValue(7, excel_upper_start_pos + 2, _T("Y"));
	XL.SetCellValue(8, excel_upper_start_pos + 2, _T("HEIGHT"));
	XL.SetCellValue(9, excel_upper_start_pos + 2, _T("MA_Y_VALUE"));
	XL.SetCellValue(10, excel_upper_start_pos + 2, _T("OPEN"));
	XL.SetCellValue(11, excel_upper_start_pos + 2, _T("SHORT"));
	XL.SetCellValue(12, excel_upper_start_pos + 2, _T("JUDGE"));



	int excel_side_start_pos = 0;
	excel_side_start_pos = excel_upper_start_pos + 3;

	for (int j = 0; j < tab_point; j++)
	{
		excel_tab_num.Format(_T("%d"), TabNum + 1);
		excel_tab_point.Format(_T("%d"), j + 1);

		for (int k = 0; k < result_value.side_num[j]; k++)
		{
			CString side_pat_num;
			CString side_x;
			CString side_width;
			CString side_y;
			CString side_height;
			CString excel_open;
			CString excel_short;
			CString excel_ma_y_value;
			CString excel_judge;

			side_pat_num.Format(_T("%d"), k + 1);


			side_x.Format(_T("%.2f"), result_value.side_x[j][k]);
			side_width.Format(_T("%.2f"), result_value.side_width[j][k]);
			side_y.Format(_T("%.2f"), result_value.side_y[j][k]);
			side_height.Format(_T("%.2f"), result_value.side_height[j][k]);
			//excel_ma_y_value.Format(_T("%.2f"), result_value.ma_y[j][k]);

			if (result_value.result_ma_x[j][k] == 0)
				excel_judge = _T("OK");

			else if (result_value.result_ma_x[j][k] == 1)
				excel_judge = _T("NG");

			else if (result_value.result_ma_x[j][k] == 2)
				excel_judge = _T("No Match");

			XL.SetCellValue(2, excel_side_start_pos + k, excel_tab_num); // tab
			XL.SetCellValue(3, excel_side_start_pos + k, excel_tab_point); // point
			XL.SetCellValue(4, excel_side_start_pos + k, side_pat_num); // num
			XL.SetCellValue(5, excel_side_start_pos + k, side_x);	// x
			XL.SetCellValue(6, excel_side_start_pos + k, side_width);	// width
			XL.SetCellValue(7, excel_side_start_pos + k, side_y);	// y
			XL.SetCellValue(8, excel_side_start_pos + k, side_height);	// height
			//XL.SetCellValue(9, excel_side_start_pos + k, excel_ma_y_value);	// ma_value


			// OPEN
			if (result_value.result_open[j][k] == 0)
				XL.SetCellValue(9, excel_side_start_pos + k, _T("OK"));

			else if (result_value.result_open[j][k] == 1)
				XL.SetCellValue(9, excel_side_start_pos + k, _T("OPEN"));

			// SHORT
			if (result_value.result_short[j][k] == 0)
				XL.SetCellValue(10, excel_side_start_pos + k, _T("OK"));

			else if (result_value.result_short[j][k] == 1)
				XL.SetCellValue(10, excel_side_start_pos + k, _T("SHORT"));

			// width & height 결과 부분
			if (result_value.result_width[j][k] == 0 && result_value.result_height[j][k] == 0)
				excel_judge = _T("OK");

			else if (result_value.result_width[j][k] == 1 && result_value.result_height[j][k] == 0)
				excel_judge = _T("WIDTH_NG");

			else if (result_value.result_width[j][k] == 0 && result_value.result_height[j][k] == 1)
				excel_judge = _T("HEIGHT_NG");

			else if (result_value.result_width[j][k] == 1 && result_value.result_height[j][k] == 1)
				excel_judge = _T("BOTH_NG");

			XL.SetCellValue(11, excel_side_start_pos + k, excel_judge);	// height
		}
		excel_side_start_pos = excel_side_start_pos + result_value.side_num[j];
	}

	CString excel_save_name;
	excel_save_name = saveTabPath + _T("\\Result.xlsx");
	
	XL.SaveFileAs(excel_save_name);

	XL.ReleaseExcel();
}


void DIALOG_AUTO::PopupResult()
{
	DIALOG_RESULT resultdlg;

	if (check_manual == true)
	{
		for (int i = 0; i < manual_result_value.upper_num; i++)
		{
			CString str_num;
			str_num.Format(_T("%d"), i + 1);
			resultdlg.m_list_upper.InsertItem(0, str_num, 0);

			CString str_upper_x;
			CString str_upper_width;
			CString str_upper_y;
			CString str_upper_height;
			CString str_upper_ma_x;
			CString str_upper_ma_result;

			str_upper_x.Format(_T("%.2f"), manual_result_value.upper_x[i]);
			str_upper_width.Format(_T("%.2f"), manual_result_value.upper_width[i]);
			str_upper_y.Format(_T("%.2f"), manual_result_value.upper_y[i]);
			str_upper_height.Format(_T("%.2f"), manual_result_value.upper_height[i]);
			str_upper_ma_x.Format(_T("%.2f"), manual_result_value.ma_x[i]);

			resultdlg.m_list_upper.SetItemText(0, 1, str_upper_x);
			resultdlg.m_list_upper.SetItemText(0, 2, str_upper_width);
			resultdlg.m_list_upper.SetItemText(0, 3, str_upper_y);
			resultdlg.m_list_upper.SetItemText(0, 4, str_upper_height);
			resultdlg.m_list_upper.SetItemText(0, 5, str_upper_ma_x);
		}

		for (int i = 0; i < manual_result_value.side_num; i++)
		{

			CString str_num;
			str_num.Format(_T("%d"), i + 1);
			resultdlg.m_list_upper.InsertItem(0, str_num, 0);

			CString str_side_x;
			CString str_side_width;
			CString str_side_y;
			CString str_side_height;
			CString str_side_open;
			CString str_side_short;
			CString str_side_judge;

			str_side_x.Format(_T("%.2f"), manual_result_value.side_x[i]);
			str_side_width.Format(_T("%.2f"), manual_result_value.side_width[i]);
			str_side_y.Format(_T("%.2f"), manual_result_value.side_y[i]);
			str_side_height.Format(_T("%.2f"), manual_result_value.side_height[i]);
			str_side_open.Format(_T("%.2f"), manual_result_value.result_open[i]);
			str_side_short.Format(_T("%2.f"), manual_result_value.result_short[i]);

			resultdlg.m_list_side.SetItemText(0, 1, str_side_x);
			resultdlg.m_list_side.SetItemText(0, 2, str_side_width);
			resultdlg.m_list_side.SetItemText(0, 3, str_side_y);
			resultdlg.m_list_side.SetItemText(0, 4, str_side_height);
			resultdlg.m_list_side.SetItemText(0, 5, str_side_open);
			resultdlg.m_list_side.SetItemText(0, 6, str_side_short);

		}

		resultdlg.check_manual = true;

		if (resultdlg.DoModal() == IDOK)
		{

		}
	}

	else if (check_manual == false)
	{
		resultdlg.start_tab = 0;
		resultdlg.load_path = result_path;

		resultdlg.result_tab = tab_count;
		resultdlg.result_point = tab_point;

		resultdlg.camera_offset = offset / 0.55;

		resultdlg.process_pass_tab_1 = process_pass_tab_1;
		resultdlg.process_pass_tab_2 = process_pass_tab_2;
		resultdlg.process_pass_tab_3 = process_pass_tab_3;
		resultdlg.process_pass_tab_4 = process_pass_tab_4;
		resultdlg.process_pass_tab_5 = process_pass_tab_5;
		resultdlg.process_pass_tab_6 = process_pass_tab_6;
		resultdlg.process_pass_tab_7 = process_pass_tab_7;
		resultdlg.process_pass_tab_8 = process_pass_tab_8;
		resultdlg.process_pass_tab_9 = process_pass_tab_9;
		resultdlg.process_pass_tab_10 = process_pass_tab_10;
		resultdlg.process_pass_tab_11 = process_pass_tab_11;
		resultdlg.process_pass_tab_12 = process_pass_tab_12;
		resultdlg.process_pass_tab_13 = process_pass_tab_13;
		resultdlg.process_pass_tab_14 = process_pass_tab_14;
		resultdlg.process_pass_tab_15 = process_pass_tab_15;
		resultdlg.process_pass_tab_16 = process_pass_tab_16;
		resultdlg.process_pass_tab_17 = process_pass_tab_17;
		resultdlg.process_pass_tab_18 = process_pass_tab_18;
		resultdlg.process_pass_tab_19 = process_pass_tab_19;
		resultdlg.process_pass_tab_20 = process_pass_tab_20;
		resultdlg.process_pass_tab_21 = process_pass_tab_21;
		resultdlg.process_pass_tab_22 = process_pass_tab_22;
		resultdlg.process_pass_tab_23 = process_pass_tab_23;
		resultdlg.process_pass_tab_24 = process_pass_tab_24;
		resultdlg.process_pass_tab_25 = process_pass_tab_25;
		resultdlg.process_pass_tab_26 = process_pass_tab_26;
		resultdlg.process_pass_tab_27 = process_pass_tab_27;
		resultdlg.process_pass_tab_28 = process_pass_tab_28;
		resultdlg.process_pass_tab_29 = process_pass_tab_29;
		resultdlg.process_pass_tab_30 = process_pass_tab_30;

		for (int i = 0; i < 300; i++)
		{
			resultdlg.result[i] = result_value.total_result[i];
		}

		resultdlg.ma_r = ma_x_r;
		resultdlg.ma_g = ma_x_g;
		resultdlg.ma_b = ma_x_b;

		resultdlg.open_r = open_r;
		resultdlg.open_g = open_g;
		resultdlg.open_b = open_b;

		resultdlg.short_r = short_r;
		resultdlg.short_g = short_g;
		resultdlg.short_b = short_b;

		resultdlg.width_r = width_r;
		resultdlg.width_g = width_g;
		resultdlg.width_b = width_b;

		resultdlg.height_r = height_r;
		resultdlg.height_g = height_g;
		resultdlg.height_b = height_b;

		resultdlg.both_r = both_r;
		resultdlg.both_g = both_g;
		resultdlg.both_b = both_b;

		if (resultdlg.DoModal() == IDOK)
		{
			bJudge = 1;
		}
	}
}


void DIALOG_AUTO::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CREVIEWAREADlg *pTime = (CREVIEWAREADlg*)AfxGetMainWnd();

	if (pTime->dlg_manual->overlay_display == 0)
	{
		MdispControl(area_cam.m_MilDisplay_Upper, M_OVERLAY_SHOW, M_DISABLE);
		MdispControl(area_cam.m_MilDisplay_Side, M_OVERLAY_SHOW, M_DISABLE);

		pTime->dlg_manual->overlay_display = 2;
	}

	else if (pTime->dlg_manual->overlay_display == 1)
	{
		// overlay
		MdispControl(area_cam.m_MilDisplay_Upper, M_OVERLAY, M_ENABLE);
		MdispControl(area_cam.m_MilDisplay_Side, M_OVERLAY, M_ENABLE);

		/* Inquire the overlay buffer associated with the display. */
		MdispInquire(area_cam.m_MilDisplay_Upper, M_OVERLAY_ID, &area_cam.m_Overlay_Upper_Center);
		MdispInquire(area_cam.m_MilDisplay_Side, M_OVERLAY_ID, &area_cam.m_Overlay_Side_Center);

		/* Clear the overlay to transparent. */
		MdispControl(area_cam.m_MilDisplay_Upper, M_OVERLAY_CLEAR, M_DEFAULT);
		MdispControl(area_cam.m_MilDisplay_Side, M_OVERLAY_CLEAR, M_DEFAULT);

		/* Disable the overlay display update to accelerate annotations. */
		MdispControl(area_cam.m_MilDisplay_Upper, M_OVERLAY_SHOW, M_DISABLE);
		MdispControl(area_cam.m_MilDisplay_Side, M_OVERLAY_SHOW, M_DISABLE);

		MIL_INT ImageWidth, ImageHeight;
		ImageWidth = MbufInquire(area_cam.m_Overlay_Upper_Center, M_SIZE_X, M_NULL);
		ImageHeight = MbufInquire(area_cam.m_Overlay_Upper_Center, M_SIZE_Y, M_NULL);

		/* Draw MIL overlay annotations. */
		/*********************************/

		/* Set the graphic text background to transparent. */
		MgraControl(M_DEFAULT, M_BACKGROUND_MODE, M_TRANSPARENT);

		/* Print a white string in the overlay image buffer. */
		MgraColor(M_DEFAULT, M_COLOR_RED);

		MgraLine(M_DEFAULT, area_cam.m_Overlay_Upper_Center, ImageWidth / 2 - 2, 0, ImageWidth / 2 - 2, ImageHeight);
		MgraLine(M_DEFAULT, area_cam.m_Overlay_Upper_Center, ImageWidth / 2 - 1, 0, ImageWidth / 2 - 1, ImageHeight);
		MgraLine(M_DEFAULT, area_cam.m_Overlay_Upper_Center, ImageWidth / 2, 0, ImageWidth / 2, ImageHeight);
		MgraLine(M_DEFAULT, area_cam.m_Overlay_Upper_Center, ImageWidth / 2 + 1, 0, ImageWidth / 2 + 1, ImageHeight);
		MgraLine(M_DEFAULT, area_cam.m_Overlay_Upper_Center, ImageWidth / 2 + 2, 0, ImageWidth / 2 + 2, ImageHeight);

		MgraLine(M_DEFAULT, area_cam.m_Overlay_Upper_Center, 0, ImageHeight / 2 - 2, ImageWidth, ImageHeight / 2 - 2);
		MgraLine(M_DEFAULT, area_cam.m_Overlay_Upper_Center, 0, ImageHeight / 2 - 1, ImageWidth, ImageHeight / 2 - 1);
		MgraLine(M_DEFAULT, area_cam.m_Overlay_Upper_Center, 0, ImageHeight / 2, ImageWidth, ImageHeight / 2);
		MgraLine(M_DEFAULT, area_cam.m_Overlay_Upper_Center, 0, ImageHeight / 2 + 1, ImageWidth, ImageHeight / 2 + 1);
		MgraLine(M_DEFAULT, area_cam.m_Overlay_Upper_Center, 0, ImageHeight / 2 + 2, ImageWidth, ImageHeight / 2 + 2);

		MgraLine(M_DEFAULT, area_cam.m_Overlay_Side_Center, ImageWidth / 2 - 2, 0, ImageWidth / 2 - 2, ImageHeight);
		MgraLine(M_DEFAULT, area_cam.m_Overlay_Side_Center, ImageWidth / 2 - 1, 0, ImageWidth / 2 - 1, ImageHeight);
		MgraLine(M_DEFAULT, area_cam.m_Overlay_Side_Center, ImageWidth / 2, 0, ImageWidth / 2, ImageHeight);
		MgraLine(M_DEFAULT, area_cam.m_Overlay_Side_Center, ImageWidth / 2 + 1, 0, ImageWidth / 2 + 1, ImageHeight);
		MgraLine(M_DEFAULT, area_cam.m_Overlay_Side_Center, ImageWidth / 2 + 2, 0, ImageWidth / 2 + 2, ImageHeight);

		MgraLine(M_DEFAULT, area_cam.m_Overlay_Side_Center, 0, ImageHeight / 2 - 2, ImageWidth, ImageHeight / 2 - 2);
		MgraLine(M_DEFAULT, area_cam.m_Overlay_Side_Center, 0, ImageHeight / 2 - 1, ImageWidth, ImageHeight / 2 - 1);
		MgraLine(M_DEFAULT, area_cam.m_Overlay_Side_Center, 0, ImageHeight / 2, ImageWidth, ImageHeight / 2);
		MgraLine(M_DEFAULT, area_cam.m_Overlay_Side_Center, 0, ImageHeight / 2 + 1, ImageWidth, ImageHeight / 2 + 1);
		MgraLine(M_DEFAULT, area_cam.m_Overlay_Side_Center, 0, ImageHeight / 2 + 2, ImageWidth, ImageHeight / 2 + 2);

		MdispControl(area_cam.m_MilDisplay_Upper, M_OVERLAY_SHOW, M_ENABLE);
		MdispControl(area_cam.m_MilDisplay_Side, M_OVERLAY_SHOW, M_ENABLE);

		pTime->dlg_manual->overlay_display = 2;
	}

	if (bStart == TRUE)
	{
		Now_Time = GetTickCount();

		CString str_TotalTime;
		CString str_AlignTime;
		CString str_InspectTime;
		CString str_UnloadingTime;
		CString str_JudgeTime;

		str_TotalTime.Format(_T("%.3f"), (Now_Time - Start_Time) / (double)1000);
		str_AlignTime.Format(_T("%.3f"), (Now_Time - Align_Time) / (double)1000);
		str_InspectTime.Format(_T("%.3f"), (Now_Time - Inspect_Time) / (double)1000);
		str_UnloadingTime.Format(_T("%.3f"), (Now_Time - Unloading_Time) / (double)1000);
		str_JudgeTime.Format(_T("%.3f"), (Now_Time - Judge_Time) / (double)1000);

		CString str_process;
		CString str_align;
		CString str_inspect;
		CString str_unloading;
		CString str_judge;

		double val_process;
		double val_align;
		double val_inspect;
		double val_unloading;
		double val_judge;

		m_edit_tacktime_process.GetWindowTextW(str_process);
		m_edit_tacktime_align.GetWindowTextW(str_align);
		m_edit_tacktime_inspection.GetWindowTextW(str_inspect);
		m_edit_tacktime_unloading.GetWindowTextW(str_unloading);
		m_edit_tacktime_judge.GetWindowTextW(str_judge);

		val_process = _wtof(str_process);
		val_align = _wtof(str_align);
		val_inspect = _wtof(str_inspect);
		val_unloading = _wtof(str_unloading);
		val_judge = _wtof(str_judge);

		double total;
		total = val_process + val_align + val_inspect + val_unloading + val_judge;

		CString str_total;
		str_total.Format(_T("%.4f"), total);

		m_edit_tacktime_total.SetWindowTextW(str_total);

		// Process_pos Tacktime
		if (bProcessComplete == FALSE)
			m_edit_tacktime_process.SetWindowTextW(str_TotalTime);

		// Align Tacktime
		if (bProcessComplete == TRUE && bTabAlignComplete == FALSE)
			m_edit_tacktime_align.SetWindowTextW(str_AlignTime);

		// Inspection Tacktime
		if (bTabAlignComplete == TRUE && bInspectComplete == FALSE)
			m_edit_tacktime_inspection.SetWindowTextW(str_InspectTime);

		// Unloading TackTime
		if (bInspectComplete == TRUE && bUnloadingComplete == FALSE)
			m_edit_tacktime_unloading.SetWindowTextW(str_UnloadingTime);

		// Judge TackTime
		if (bUnloadingComplete == TRUE && bJudgeComplete == FALSE)
			m_edit_tacktime_judge.SetWindowTextW(str_JudgeTime);
	}

	if (bReady == false)
		m_pic_process_ready.SetBitmap(m_red_led);

	else if (bReady == true && bReadyComplete == false)
		m_pic_process_ready.SetBitmap(m_yellow_led);

	else if (bReadyComplete == true)
		m_pic_process_ready.SetBitmap(m_green_led);


	if (bProcess == false)
		m_pic_process_process.SetBitmap(m_red_led);

	else if (bProcess == true && bProcessComplete == false)
		m_pic_process_process.SetBitmap(m_yellow_led);

	else if (bProcessComplete == true)
		m_pic_process_process.SetBitmap(m_green_led);


	if (bPreAlign == false)
		m_pic_process_prealign.SetBitmap(m_red_led);

	else if (bPreAlign == true && bPreAlignComplete == false)
		m_pic_process_prealign.SetBitmap(m_yellow_led);

	else if (bPreAlignComplete == true)
		m_pic_process_prealign.SetBitmap(m_green_led);


	if (bTabAlign == false)
		m_pic_process_tabalign.SetBitmap(m_red_led);

	else if (bTabAlign == true && bTabAlignComplete == false)
		m_pic_process_tabalign.SetBitmap(m_yellow_led);

	else if (bTabAlignComplete == true)
		m_pic_process_tabalign.SetBitmap(m_green_led);


	if (bInspect == false)
		m_pic_process_inspection.SetBitmap(m_red_led);

	else if (bInspect == true && bInspectComplete == false)
		m_pic_process_inspection.SetBitmap(m_yellow_led);

	else if (bInspectComplete == true)
		m_pic_process_inspection.SetBitmap(m_green_led);

	if (bUnloading == false)
		m_pic_process_unloading.SetBitmap(m_red_led);

	else if (bUnloading == true && bUnloadingComplete == false)
		m_pic_process_unloading.SetBitmap(m_yellow_led);

	else if (bUnloadingComplete == true)
		m_pic_process_unloading.SetBitmap(m_green_led);

	if (bJudge == false)
		m_pic_process_judge.SetBitmap(m_red_led);

	else if (bJudge == true && bJudgeComplete == false)
		m_pic_process_judge.SetBitmap(m_yellow_led);

	else if (bJudgeComplete == true)
		m_pic_process_judge.SetBitmap(m_green_led);


	if (process_stop == 1)
		process_clicked_stop();

	if (check_process_stop == 2)
	{
		log_time = CTime::GetCurrentTime();
		str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), log_time.GetYear(), log_time.GetMonth(), log_time.GetDay(), log_time.GetHour(), log_time.GetMinute(), log_time.GetSecond());

		display_log(str_log_time, _T("INSPECTION"), _T("STOP"), _T("Clicked Stop Button"), log_count);
		m_edit_process.SetWindowTextW(_T("Clicked Stop Button"));
		check_process_stop = 1;
	}

	if (process_af_check == 1)
	{
		pTime->ProcessAFStart();
		process_af_check = 0;
	}

	else if (process_af_check == 2)
	{
		pTime->ProcessAFStop();
		process_af_check = 0;
	}

	CDialogEx::OnTimer(nIDEvent);
}


void DIALOG_AUTO::CamUpperStatus()
{
	CREVIEWAREADlg *pStatus = (CREVIEWAREADlg*)AfxGetMainWnd();

	if (upper_camera_status == 1)
	{
		MdigHalt(area_cam.m_MilDigitizer_Upper);

		// 멈추면서 이미지 저장 필요
		CString str_upper_image;
		str_upper_image = _T("Data\\4. MEASURE\\1. ORIGIN\\UPPER.bmp");

		MdigGrab(area_cam.m_MilDigitizer_Upper, area_cam.m_MilImage_Upper);

		MbufExport(str_upper_image, M_BMP, area_cam.m_MilImage_Upper);

		upper_camera_status = 0;

		pStatus->dlg_manual->GetDlgItem(IDC_CMB_UPPER_MARK)->EnableWindow(TRUE);
		pStatus->dlg_manual->m_cmb_upper_mark.SetCurSel(0);
		pStatus->dlg_manual->GetDlgItem(IDC_BTN_UPPER_MARK_REG)->EnableWindow(TRUE);
		//pStatus->dlg_manual->GetDlgItem(IDC_BTN_UPPER_MARK_SAVE)->EnableWindow(TRUE);

		if (side_camera_status == 0)
		{
			/*
			pStatus->dlg_manual->GetDlgItem(IDC_BTN_GRAPHIC)->EnableWindow(TRUE);
			pStatus->dlg_manual->GetDlgItem(IDC_BTN_LINE)->EnableWindow(TRUE);
			pStatus->dlg_manual->GetDlgItem(IDC_BTN_RECTANGLE)->EnableWindow(TRUE);
			pStatus->dlg_manual->GetDlgItem(IDC_BTN_CIRCLE)->EnableWindow(TRUE);
			pStatus->dlg_manual->GetDlgItem(IDC_BTN_EDGE_1)->EnableWindow(TRUE);
			pStatus->dlg_manual->GetDlgItem(IDC_BTN_EDGE_2)->EnableWindow(TRUE);
			*/
			pStatus->dlg_manual->GetDlgItem(IDC_CMB_CAMERA)->EnableWindow(TRUE);
			pStatus->dlg_manual->GetDlgItem(IDC_EDIT_MORP_OPEN)->EnableWindow(TRUE);
			pStatus->dlg_manual->GetDlgItem(IDC_EDIT_MORP_CLOSE)->EnableWindow(TRUE);
			pStatus->dlg_manual->GetDlgItem(IDC_EDIT_BINARY)->EnableWindow(TRUE);
			pStatus->dlg_manual->GetDlgItem(IDC_EDIT_CONTOUR)->EnableWindow(TRUE);
			pStatus->dlg_manual->GetDlgItem(IDC_EDIT_TEST_ROI_MIN)->EnableWindow(TRUE);
			pStatus->dlg_manual->GetDlgItem(IDC_EDIT_TEST_ROI_MAX)->EnableWindow(TRUE);
			pStatus->dlg_manual->GetDlgItem(IDC_BTN_MORP)->EnableWindow(TRUE);


			pStatus->dlg_manual->OnCbnSelchangeCmbCamera();

		}
	}

	else if (upper_camera_status == 0)
	{
		MdigGrabContinuous(area_cam.m_MilDigitizer_Upper, area_cam.m_MilImage_Upper);

		/*
		pStatus->dlg_manual->GetDlgItem(IDC_BTN_GRAPHIC)->EnableWindow(FALSE);
		pStatus->dlg_manual->GetDlgItem(IDC_BTN_LINE)->EnableWindow(FALSE);
		pStatus->dlg_manual->GetDlgItem(IDC_BTN_RECTANGLE)->EnableWindow(FALSE);
		pStatus->dlg_manual->GetDlgItem(IDC_BTN_CIRCLE)->EnableWindow(FALSE);
		pStatus->dlg_manual->GetDlgItem(IDC_BTN_EDGE_1)->EnableWindow(FALSE);
		pStatus->dlg_manual->GetDlgItem(IDC_BTN_EDGE_2)->EnableWindow(FALSE);
		*/
		pStatus->dlg_manual->GetDlgItem(IDC_CMB_UPPER_MARK)->EnableWindow(FALSE);
		pStatus->dlg_manual->GetDlgItem(IDC_BTN_UPPER_MARK_REG)->EnableWindow(FALSE);
		pStatus->dlg_manual->GetDlgItem(IDC_BTN_UPPER_MARK_SAVE)->EnableWindow(FALSE);

		pStatus->dlg_manual->GetDlgItem(IDC_CMB_CAMERA)->EnableWindow(FALSE);
		pStatus->dlg_manual->GetDlgItem(IDC_EDIT_MORP_OPEN)->EnableWindow(FALSE);
		pStatus->dlg_manual->GetDlgItem(IDC_EDIT_MORP_CLOSE)->EnableWindow(FALSE);
		pStatus->dlg_manual->GetDlgItem(IDC_EDIT_BINARY)->EnableWindow(FALSE);
		pStatus->dlg_manual->GetDlgItem(IDC_EDIT_CONTOUR)->EnableWindow(FALSE);
		pStatus->dlg_manual->GetDlgItem(IDC_EDIT_TEST_ROI_MIN)->EnableWindow(FALSE);
		pStatus->dlg_manual->GetDlgItem(IDC_EDIT_TEST_ROI_MAX)->EnableWindow(FALSE);
		pStatus->dlg_manual->GetDlgItem(IDC_BTN_MORP)->EnableWindow(FALSE);
		pStatus->dlg_manual->GetDlgItem(IDC_BTN_BINARY)->EnableWindow(FALSE);
		pStatus->dlg_manual->GetDlgItem(IDC_BTN_CONTOUR)->EnableWindow(FALSE);
		pStatus->dlg_manual->GetDlgItem(IDC_BTN_FOCUS_RESET)->EnableWindow(FALSE);


		pStatus->dlg_manual->measure_mode = 0;
		pStatus->dlg_manual->measure_count = 1;

		upper_camera_status = 1;
	}
}


void DIALOG_AUTO::CamSideStatus()
{
	CREVIEWAREADlg *pStatus = (CREVIEWAREADlg*)AfxGetMainWnd();

	if (side_camera_status == 1)
	{
		MdigHalt(area_cam.m_MilDigitizer_Side);

		// 멈추면서 이미지 저장 필요
		CString str_side_image;
		str_side_image = _T("Data\\4. MEASURE\\1. ORIGIN\\SIDE.bmp");
		MdigGrab(area_cam.m_MilDigitizer_Side, area_cam.m_MilImage_Side);

		MbufExport(str_side_image, M_BMP, area_cam.m_MilImage_Side);
		side_camera_status = 0;

		pStatus->dlg_manual->GetDlgItem(IDC_CMB_SIDE_MARK)->EnableWindow(TRUE);
		pStatus->dlg_manual->m_cmb_side_mark.SetCurSel(0);
		pStatus->dlg_manual->GetDlgItem(IDC_BTN_SIDE_MARK_REG)->EnableWindow(TRUE);
		//pStatus->dlg_manual->GetDlgItem(IDC_BTN_SIDE_MARK_SAVE)->EnableWindow(TRUE);

		if (upper_camera_status == 0)
		{
			/*
			pStatus->dlg_manual->GetDlgItem(IDC_BTN_GRAPHIC)->EnableWindow(TRUE);
			pStatus->dlg_manual->GetDlgItem(IDC_BTN_LINE)->EnableWindow(TRUE);
			pStatus->dlg_manual->GetDlgItem(IDC_BTN_RECTANGLE)->EnableWindow(TRUE);
			pStatus->dlg_manual->GetDlgItem(IDC_BTN_CIRCLE)->EnableWindow(TRUE);
			pStatus->dlg_manual->GetDlgItem(IDC_BTN_EDGE_1)->EnableWindow(TRUE);
			pStatus->dlg_manual->GetDlgItem(IDC_BTN_EDGE_2)->EnableWindow(TRUE);
			*/
			pStatus->dlg_manual->GetDlgItem(IDC_CMB_CAMERA)->EnableWindow(TRUE);
			pStatus->dlg_manual->GetDlgItem(IDC_EDIT_MORP_OPEN)->EnableWindow(TRUE);
			pStatus->dlg_manual->GetDlgItem(IDC_EDIT_MORP_CLOSE)->EnableWindow(TRUE);
			pStatus->dlg_manual->GetDlgItem(IDC_EDIT_BINARY)->EnableWindow(TRUE);
			pStatus->dlg_manual->GetDlgItem(IDC_EDIT_CONTOUR)->EnableWindow(TRUE);
			pStatus->dlg_manual->GetDlgItem(IDC_EDIT_TEST_ROI_MIN)->EnableWindow(TRUE);
			pStatus->dlg_manual->GetDlgItem(IDC_EDIT_TEST_ROI_MAX)->EnableWindow(TRUE);
			pStatus->dlg_manual->GetDlgItem(IDC_BTN_MORP)->EnableWindow(TRUE);


			pStatus->dlg_manual->OnCbnSelchangeCmbCamera();

		}
	}

	else if (side_camera_status == 0)
	{
		MdigGrabContinuous(area_cam.m_MilDigitizer_Side, area_cam.m_MilImage_Side);

		/*
		pStatus->dlg_manual->GetDlgItem(IDC_BTN_GRAPHIC)->EnableWindow(FALSE);
		pStatus->dlg_manual->GetDlgItem(IDC_BTN_LINE)->EnableWindow(FALSE);
		pStatus->dlg_manual->GetDlgItem(IDC_BTN_RECTANGLE)->EnableWindow(FALSE);
		pStatus->dlg_manual->GetDlgItem(IDC_BTN_CIRCLE)->EnableWindow(FALSE);
		pStatus->dlg_manual->GetDlgItem(IDC_BTN_EDGE_1)->EnableWindow(FALSE);
		pStatus->dlg_manual->GetDlgItem(IDC_BTN_EDGE_2)->EnableWindow(FALSE);
		*/
		pStatus->dlg_manual->GetDlgItem(IDC_CMB_SIDE_MARK)->EnableWindow(FALSE);
		pStatus->dlg_manual->GetDlgItem(IDC_BTN_SIDE_MARK_REG)->EnableWindow(FALSE);
		pStatus->dlg_manual->GetDlgItem(IDC_BTN_SIDE_MARK_SAVE)->EnableWindow(FALSE);

		pStatus->dlg_manual->GetDlgItem(IDC_CMB_CAMERA)->EnableWindow(FALSE);
		pStatus->dlg_manual->GetDlgItem(IDC_EDIT_MORP_OPEN)->EnableWindow(FALSE);
		pStatus->dlg_manual->GetDlgItem(IDC_EDIT_MORP_CLOSE)->EnableWindow(FALSE);
		pStatus->dlg_manual->GetDlgItem(IDC_EDIT_BINARY)->EnableWindow(FALSE);
		pStatus->dlg_manual->GetDlgItem(IDC_EDIT_CONTOUR)->EnableWindow(FALSE);
		pStatus->dlg_manual->GetDlgItem(IDC_BTN_MORP)->EnableWindow(FALSE);
		pStatus->dlg_manual->GetDlgItem(IDC_BTN_BINARY)->EnableWindow(FALSE);
		pStatus->dlg_manual->GetDlgItem(IDC_BTN_CONTOUR)->EnableWindow(FALSE);
		pStatus->dlg_manual->GetDlgItem(IDC_EDIT_TEST_ROI_MIN)->EnableWindow(FALSE);
		pStatus->dlg_manual->GetDlgItem(IDC_EDIT_TEST_ROI_MAX)->EnableWindow(FALSE);
		pStatus->dlg_manual->GetDlgItem(IDC_BTN_FOCUS_RESET)->EnableWindow(FALSE);


		pStatus->dlg_manual->measure_mode = 0;
		pStatus->dlg_manual->measure_count = 1;

		side_camera_status = 1;
	}
}


void DIALOG_AUTO::CamStatus()
{
	CREVIEWAREADlg *pStatus = (CREVIEWAREADlg*)AfxGetMainWnd();

	if ((upper_camera_status == 1 && side_camera_status == 1) || (upper_camera_status == 0 && side_camera_status == 0))
	{
		CamUpperStatus();
		CamSideStatus();
	}

	// 둘중 하나만 on 인 경우
	else if (upper_camera_status == 1 || side_camera_status == 1)
	{
		if (upper_camera_status == 1)
		{
			MdigGrabContinuous(area_cam.m_MilDigitizer_Side, area_cam.m_MilImage_Side);

			/*pStatus->dlg_manual->GetDlgItem(IDC_BTN_LINE)->EnableWindow(FALSE);
			pStatus->dlg_manual->GetDlgItem(IDC_BTN_RECTANGLE)->EnableWindow(FALSE);
			pStatus->dlg_manual->GetDlgItem(IDC_BTN_CIRCLE)->EnableWindow(FALSE);
			pStatus->dlg_manual->GetDlgItem(IDC_BTN_EDGE_1)->EnableWindow(FALSE);
			pStatus->dlg_manual->GetDlgItem(IDC_BTN_EDGE_2)->EnableWindow(FALSE);
			*/
			pStatus->dlg_manual->GetDlgItem(IDC_CMB_SIDE_MARK)->EnableWindow(FALSE);
			pStatus->dlg_manual->GetDlgItem(IDC_BTN_SIDE_MARK_REG)->EnableWindow(FALSE);
			pStatus->dlg_manual->GetDlgItem(IDC_BTN_SIDE_MARK_SAVE)->EnableWindow(FALSE);

			pStatus->dlg_manual->GetDlgItem(IDC_CMB_CAMERA)->EnableWindow(FALSE);
			pStatus->dlg_manual->GetDlgItem(IDC_EDIT_MORP_OPEN)->EnableWindow(FALSE);
			pStatus->dlg_manual->GetDlgItem(IDC_EDIT_MORP_CLOSE)->EnableWindow(FALSE);
			pStatus->dlg_manual->GetDlgItem(IDC_EDIT_BINARY)->EnableWindow(FALSE);
			pStatus->dlg_manual->GetDlgItem(IDC_EDIT_CONTOUR)->EnableWindow(FALSE);
			pStatus->dlg_manual->GetDlgItem(IDC_BTN_MORP)->EnableWindow(FALSE);
			pStatus->dlg_manual->GetDlgItem(IDC_EDIT_TEST_ROI_MIN)->EnableWindow(FALSE);
			pStatus->dlg_manual->GetDlgItem(IDC_EDIT_TEST_ROI_MAX)->EnableWindow(FALSE);


			pStatus->dlg_manual->OnCbnSelchangeCmbCamera();

			side_camera_status = 1;
		}

		else if (side_camera_status == 1)
		{
			MdigGrabContinuous(area_cam.m_MilDigitizer_Upper, area_cam.m_MilImage_Upper);

			/*pStatus->dlg_manual->GetDlgItem(IDC_BTN_LINE)->EnableWindow(FALSE);
			pStatus->dlg_manual->GetDlgItem(IDC_BTN_RECTANGLE)->EnableWindow(FALSE);
			pStatus->dlg_manual->GetDlgItem(IDC_BTN_CIRCLE)->EnableWindow(FALSE);
			pStatus->dlg_manual->GetDlgItem(IDC_BTN_EDGE_1)->EnableWindow(FALSE);
			pStatus->dlg_manual->GetDlgItem(IDC_BTN_EDGE_2)->EnableWindow(FALSE);
			*/
			pStatus->dlg_manual->GetDlgItem(IDC_CMB_UPPER_MARK)->EnableWindow(FALSE);
			pStatus->dlg_manual->GetDlgItem(IDC_BTN_UPPER_MARK_REG)->EnableWindow(FALSE);
			pStatus->dlg_manual->GetDlgItem(IDC_BTN_UPPER_MARK_SAVE)->EnableWindow(FALSE);
			pStatus->dlg_manual->GetDlgItem(IDC_CMB_CAMERA)->EnableWindow(FALSE);

			pStatus->dlg_manual->GetDlgItem(IDC_EDIT_MORP_OPEN)->EnableWindow(FALSE);
			pStatus->dlg_manual->GetDlgItem(IDC_EDIT_MORP_CLOSE)->EnableWindow(FALSE);
			pStatus->dlg_manual->GetDlgItem(IDC_EDIT_BINARY)->EnableWindow(FALSE);
			pStatus->dlg_manual->GetDlgItem(IDC_EDIT_CONTOUR)->EnableWindow(FALSE);
			pStatus->dlg_manual->GetDlgItem(IDC_EDIT_TEST_ROI_MIN)->EnableWindow(FALSE);
			pStatus->dlg_manual->GetDlgItem(IDC_EDIT_TEST_ROI_MAX)->EnableWindow(FALSE);

			pStatus->dlg_manual->GetDlgItem(IDC_BTN_MORP)->EnableWindow(FALSE);
			pStatus->dlg_manual->GetDlgItem(IDC_BTN_BINARY)->EnableWindow(FALSE);
			pStatus->dlg_manual->GetDlgItem(IDC_BTN_CONTOUR)->EnableWindow(FALSE);
			pStatus->dlg_manual->GetDlgItem(IDC_BTN_FOCUS_RESET)->EnableWindow(FALSE);


			pStatus->dlg_manual->measure_mode = 0;
			pStatus->dlg_manual->measure_count = 1;

			upper_camera_status = 1;
		}
	}

}

void DIALOG_AUTO::OnBnClickedBtnEmo()
{
	CREVIEWAREADlg *pDlg = (CREVIEWAREADlg*)AfxGetMainWnd();

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	acsc_Kill(hStage_auto, ACSC_AXIS_4, NULL);	// Stage_x kill
	acsc_Kill(hStage_auto, ACSC_AXIS_0, NULL);	// Stage_y_ kill
	acsc_Kill(hStage_auto, ACSC_AXIS_10, NULL);	// Sub_x_kill

		// Stage Thread OFF
	DWORD nExitCode = NULL;

	GetExitCodeThread(Inspect->m_hThread, &nExitCode);
	TerminateThread(Inspect->m_hThread, nExitCode);

	Inspect = NULL;

	bStart = false;
	bStop = true;
	bReady = false;
	bReadyComplete = false;
	bProcess = false;
	bProcessComplete = false;
	bPreAlign = false;
	bPreAlignComplete = false;
	bTabAlign = false;
	bTabAlignComplete = false;
	bInspect = false;
	bInspectComplete = false;
	bJudge = false;
	bJudgeComplete = false;
	bUnloading = false;
	bUnloadingComplete = false;

	Invalidate(false);

	log_time = CTime::GetCurrentTime();
	str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), log_time.GetYear(), log_time.GetMonth(), log_time.GetDay(), log_time.GetHour(), log_time.GetMinute(), log_time.GetSecond());

	display_log(str_log_time, _T("INSPECTION"), _T("STOP"), _T("Clicked EMO Button"), log_count);
	m_edit_process.SetWindowTextW(_T("Clicked EMO Button"));

	GetDlgItem(IDC_BTN_EMO)->EnableWindow(FALSE);

	check_alarm = 1;

	displayAlarm(1);
}


void DIALOG_AUTO::display_log(CString time, CString level, CString point, CString message, int log_count)
{
	m_list_log.InsertItem(log_count, str_log_time);
	m_list_log.SetItemText(log_count, 1, level);
	m_list_log.SetItemText(log_count, 2, point);
	m_list_log.SetItemText(log_count, 3, message);

	log_count++;
}


void DIALOG_AUTO::process_clicked_stop()
{
	DWORD nExitCode = NULL;

	GetExitCodeThread(Inspect->m_hThread, &nExitCode);
	TerminateThread(Inspect->m_hThread, nExitCode);

	Inspect = NULL;
	bStart = false;
	bStop = true;

	process_stop = 0;

	bStart = false;
	bStop = true;
	bReady = false;
	bReadyComplete = false;
	bProcess = false;
	bProcessComplete = false;
	bPreAlign = false;
	bPreAlignComplete = false;
	bTabAlign = false;
	bTabAlignComplete = false;
	bInspect = false;
	bInspectComplete = false;
	bJudge = false;
	bJudgeComplete = false;
	bUnloading = false;
	bUnloadingComplete = false;

	Invalidate(false);
}


void DIALOG_AUTO::displayAlarm(int nCase)
{
	CREVIEWAREADlg *pDlg = (CREVIEWAREADlg*)AfxGetMainWnd();

	pDlg->dlg_alarm->DisplayAlarm(nCase);
}


void DIALOG_AUTO::DrawLine(CPoint startPos, CPoint endPos, int Cam, CString strText)
{
	MgraFontScale(M_DEFAULT, 3, 3);

	// upper
	if (Cam == 1)
	{
		MgraLine(M_DEFAULT, area_cam.m_Overlay_Upper_Center, startPos.x * 4 - 2, startPos.y * 4 - 2, endPos.x * 4 - 2, endPos.y * 4 - 2);
		MgraLine(M_DEFAULT, area_cam.m_Overlay_Upper_Center, startPos.x * 4 - 1, startPos.y * 4 - 1, endPos.x * 4 - 1, endPos.y * 4 - 1);
		MgraLine(M_DEFAULT, area_cam.m_Overlay_Upper_Center, startPos.x * 4, startPos.y * 4, endPos.x * 4, endPos.y * 4);
		MgraLine(M_DEFAULT, area_cam.m_Overlay_Upper_Center, startPos.x * 4 + 1, startPos.y * 4 + 1, endPos.x * 4 + 1, endPos.y * 4 + 1);
		MgraLine(M_DEFAULT, area_cam.m_Overlay_Upper_Center, startPos.x * 4 + 2, startPos.y * 4 + 2, endPos.x * 4 + 2, endPos.y * 4 + 2);

		if (startPos.x > 400)
			startPos.x = 400;

		MgraText(M_DEFAULT, area_cam.m_Overlay_Upper_Center, startPos.x * 4, startPos.y * 4, strText);
	}

	// side
	else if (Cam == 2)
	{
		MgraLine(M_DEFAULT, area_cam.m_Overlay_Side_Center, startPos.x * 4 - 2, startPos.y * 4 - 2, endPos.x * 4 - 2, endPos.y * 4 - 2);
		MgraLine(M_DEFAULT, area_cam.m_Overlay_Side_Center, startPos.x * 4 - 1, startPos.y * 4 - 1, endPos.x * 4 - 1, endPos.y * 4 - 1);
		MgraLine(M_DEFAULT, area_cam.m_Overlay_Side_Center, startPos.x * 4, startPos.y * 4, endPos.x * 4, endPos.y * 4);
		MgraLine(M_DEFAULT, area_cam.m_Overlay_Side_Center, startPos.x * 4 + 1, startPos.y * 4 + 1, endPos.x * 4 + 1, endPos.y * 4 + 1);
		MgraLine(M_DEFAULT, area_cam.m_Overlay_Side_Center, startPos.x * 4 + 2, startPos.y * 4 + 2, endPos.x * 4 + 2, endPos.y * 4 + 2);

		if (startPos.x > 400)
			startPos.x = 400;

		MgraText(M_DEFAULT, area_cam.m_Overlay_Side_Center, startPos.x * 4, startPos.y * 4, strText);
	}

}


void DIALOG_AUTO::DrawRectangle(CPoint startPos, CPoint endPos, int Cam, CString strText_Ver, CString strText_Hor)
{
	double width;
	double height;

	width = (endPos.x - startPos.x) * 4;
	height = (endPos.y - startPos.y) * 4;

	MgraFontScale(M_DEFAULT, 3, 3);

	if (width < 0)
	{
		int x;
		x = endPos.x;
		endPos.x = startPos.x;
		startPos.x = x;
		width = -width;
	}

	if (height < 0)
	{
		int y;
		y = endPos.y;
		endPos.y = startPos.y;
		startPos.y = y;
		height = -height;
	}

	// 두껍게 그리기 위해
	if (Cam == 1)
	{
		MgraRectAngle(M_DEFAULT, area_cam.m_Overlay_Upper_Center, startPos.x * 4 - 2, startPos.y * 4 - 2, width, height, 0, M_DEFAULT);
		MgraRectAngle(M_DEFAULT, area_cam.m_Overlay_Upper_Center, startPos.x * 4 - 1, startPos.y * 4 - 1, width, height, 0, M_DEFAULT);
		MgraRectAngle(M_DEFAULT, area_cam.m_Overlay_Upper_Center, startPos.x * 4, startPos.y * 4, width, height, 0, M_DEFAULT);
		MgraRectAngle(M_DEFAULT, area_cam.m_Overlay_Upper_Center, startPos.x * 4 + 1, startPos.y * 4 + 1, width, height, 0, M_DEFAULT);
		MgraRectAngle(M_DEFAULT, area_cam.m_Overlay_Upper_Center, startPos.x * 4 + 2, startPos.y * 4 + 2, width, height, 0, M_DEFAULT);

		if (startPos.x > 400)
			startPos.x = 400;

		MgraText(M_DEFAULT, area_cam.m_Overlay_Upper_Center, startPos.x * 4, startPos.y * 4 - 40, strText_Ver);
		MgraText(M_DEFAULT, area_cam.m_Overlay_Upper_Center, startPos.x * 4, startPos.y * 4, strText_Hor);
	}

	else if (Cam == 2)
	{
		MgraRectAngle(M_DEFAULT, area_cam.m_Overlay_Side_Center, startPos.x * 4 - 2, startPos.y * 4 - 2, width, height, 0, M_DEFAULT);
		MgraRectAngle(M_DEFAULT, area_cam.m_Overlay_Side_Center, startPos.x * 4 - 1, startPos.y * 4 - 1, width, height, 0, M_DEFAULT);
		MgraRectAngle(M_DEFAULT, area_cam.m_Overlay_Side_Center, startPos.x * 4, startPos.y * 4, width, height, 0, M_DEFAULT);
		MgraRectAngle(M_DEFAULT, area_cam.m_Overlay_Side_Center, startPos.x * 4 + 1, startPos.y * 4 + 1, width, height, 0, M_DEFAULT);
		MgraRectAngle(M_DEFAULT, area_cam.m_Overlay_Side_Center, startPos.x * 4 + 2, startPos.y * 4 + 2, width, height, 0, M_DEFAULT);

		if (startPos.x > 400)
			startPos.x = 400;

		MgraText(M_DEFAULT, area_cam.m_Overlay_Side_Center, startPos.x * 4, startPos.y * 4 - 40, strText_Ver);
		MgraText(M_DEFAULT, area_cam.m_Overlay_Side_Center, startPos.x * 4, startPos.y * 4, strText_Hor);
	}

}


void DIALOG_AUTO::DrawCircle(CPoint startPos, CPoint endPos, int radius, int Cam, CString strText)
{
	MgraFontScale(M_DEFAULT, 3, 3);

	if (Cam == 1)
	{
		MgraLine(M_DEFAULT, area_cam.m_Overlay_Upper_Center, startPos.x * 4 - 2, startPos.y * 4 - 2, endPos.x * 4 - 2, endPos.y * 4 - 2);
		MgraLine(M_DEFAULT, area_cam.m_Overlay_Upper_Center, startPos.x * 4 - 1, startPos.y * 4 - 1, endPos.x * 4 - 1, endPos.y * 4 - 1);
		MgraLine(M_DEFAULT, area_cam.m_Overlay_Upper_Center, startPos.x * 4, startPos.y * 4, endPos.x * 4, endPos.y * 4);
		MgraLine(M_DEFAULT, area_cam.m_Overlay_Upper_Center, startPos.x * 4 + 1, startPos.y * 4 + 1, endPos.x * 4 + 1, endPos.y * 4 + 1);
		MgraLine(M_DEFAULT, area_cam.m_Overlay_Upper_Center, startPos.x * 4 + 2, startPos.y * 4 + 2, endPos.x * 4 + 2, endPos.y * 4 + 2);

		MgraArc(M_DEFAULT, area_cam.m_Overlay_Upper_Center, startPos.x * 4, startPos.y * 4, radius * 4 - 1, radius * 4 - 1, 0, 360);
		MgraArc(M_DEFAULT, area_cam.m_Overlay_Upper_Center, startPos.x * 4, startPos.y * 4, radius * 4, radius * 4, 0, 360);
		MgraArc(M_DEFAULT, area_cam.m_Overlay_Upper_Center, startPos.x * 4, startPos.y * 4, radius * 4 + 1, radius * 4 + 1, 0, 360);

		if (startPos.x > 400)
			startPos.x = 400;

		MgraText(M_DEFAULT, area_cam.m_Overlay_Upper_Center, startPos.x * 4, startPos.y * 4, strText);
	}

	else if (Cam == 2)
	{
		MgraLine(M_DEFAULT, area_cam.m_Overlay_Side_Center, startPos.x * 4 - 2, startPos.y * 4 - 2, endPos.x * 4 - 2, endPos.y * 4 - 2);
		MgraLine(M_DEFAULT, area_cam.m_Overlay_Side_Center, startPos.x * 4 - 1, startPos.y * 4 - 1, endPos.x * 4 - 1, endPos.y * 4 - 1);
		MgraLine(M_DEFAULT, area_cam.m_Overlay_Side_Center, startPos.x * 4, startPos.y * 4, endPos.x * 4, endPos.y * 4);
		MgraLine(M_DEFAULT, area_cam.m_Overlay_Side_Center, startPos.x * 4 + 1, startPos.y * 4 + 1, endPos.x * 4 + 1, endPos.y * 4 + 1);
		MgraLine(M_DEFAULT, area_cam.m_Overlay_Side_Center, startPos.x * 4 + 2, startPos.y * 4 + 2, endPos.x * 4 + 2, endPos.y * 4 + 2);

		MgraArc(M_DEFAULT, area_cam.m_Overlay_Side_Center, startPos.x * 4, startPos.y * 4, radius * 4 - 1, radius * 4 - 1, 0, 360);
		MgraArc(M_DEFAULT, area_cam.m_Overlay_Side_Center, startPos.x * 4, startPos.y * 4, radius * 4, radius * 4, 0, 360);
		MgraArc(M_DEFAULT, area_cam.m_Overlay_Side_Center, startPos.x * 4, startPos.y * 4, radius * 4 + 1, radius * 4 + 1, 0, 360);

		if (startPos.x > 400)
			startPos.x = 400;

		MgraText(M_DEFAULT, area_cam.m_Overlay_Side_Center, startPos.x * 4, startPos.y * 4, strText);
	}


}

void DIALOG_AUTO::OnBnClickedBtnManualInspect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CREVIEWAREADlg *pDlg = (CREVIEWAREADlg*)AfxGetMainWnd();

	Start_Time = GetTickCount();
	inspection_start_time = CTime::GetCurrentTime();
	str_inspection_start_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), inspection_start_time.GetYear(), inspection_start_time.GetMonth(),
		inspection_start_time.GetDay(), inspection_start_time.GetHour(), inspection_start_time.GetMinute(), inspection_start_time.GetSecond());

	log_time = CTime::GetCurrentTime();
	str_log_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), log_time.GetYear(), log_time.GetMonth(), log_time.GetDay(), log_time.GetHour(), log_time.GetMinute(), log_time.GetSecond());

	CString str_glass_id;

	m_edit_glass_id.GetWindowTextW(str_glass_id);

	folder_path = file_path + _T("DATA\\5. MANUAL\\");
	folder_path = folder_path + str_glass_id + _T("_[") + str_inspection_start_time + _T("]");

	origin_path = folder_path + _T("\\ORIGIN");
	result_path = folder_path + _T("\\RESULT");

	::CreateDirectory(folder_path, NULL);
	::CreateDirectory(origin_path, NULL);
	::CreateDirectory(result_path, NULL);

	check_manual = true;

	Image_manual_Inspect();

	PopupResult();
}

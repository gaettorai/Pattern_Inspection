// DIALOG_SETTING_STAGE.cpp: 구현 파일
//

#include "stdafx.h"
#include "REVIEW_AREA.h"
#include "DIALOG_SETTING_STAGE.h"
#include "afxdialogex.h"


// DIALOG_SETTING_STAGE 대화 상자

IMPLEMENT_DYNAMIC(DIALOG_SETTING_STAGE, CDialogEx)

DIALOG_SETTING_STAGE::DIALOG_SETTING_STAGE(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SETTING_STAGE, pParent)
{

}

DIALOG_SETTING_STAGE::~DIALOG_SETTING_STAGE()
{
}

void DIALOG_SETTING_STAGE::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_EDIT_STAGE_MAIN_X_READY_POS, m_edit_stage_main_x_ready_pos);
	DDX_Control(pDX, IDC_EDIT_STAGE_MAIN_X_PROCESS_POS, m_edit_stage_main_x_process_pos);
	DDX_Control(pDX, IDC_EDIT_STAGE_MAIN_X_LIMIT_MIN, m_edit_stage_main_x_limit_min);
	DDX_Control(pDX, IDC_EDIT_STAGE_MAIN_X_LIMIT_MAX, m_edit_stage_main_x_limit_max);
	DDX_Control(pDX, IDC_EDIT_STAGE_MAIN_X_MANUAL_SPEED, m_edit_stage_main_x_manual_speed);
	DDX_Control(pDX, IDC_EDIT_STAGE_MAIN_X_PROCESS_SPEED, m_edit_stage_main_x_process_speed);
	DDX_Control(pDX, IDC_EDIT_STAGE_MAIN_Y_READY_POS, m_edit_stage_main_y_ready_pos);
	DDX_Control(pDX, IDC_EDIT_STAGE_MAIN_Y_PROCESS_POS, m_edit_stage_main_y_process_pos);
	DDX_Control(pDX, IDC_EDIT_STAGE_MAIN_Y_LIMIT_MIN, m_edit_stage_main_y_limit_min);
	DDX_Control(pDX, IDC_EDIT_STAGE_MAIN_Y_LIMIT_MAX, m_edit_stage_main_y_limit_max);
	DDX_Control(pDX, IDC_EDIT_STAGE_MAIN_Y_MANUAL_SPEED, m_edit_stage_main_y_manual_speed);
	DDX_Control(pDX, IDC_EDIT_STAGE_MAIN_Y_PROCESS_SPEED, m_edit_stage_main_y_process_speed);
	DDX_Control(pDX, IDC_EDIT_STAGE_SUB_X_READY_POS, m_edit_stage_sub_x_ready_pos);
	DDX_Control(pDX, IDC_EDIT_STAGE_SUB_X_PROCESS_POS, m_edit_stage_sub_x_process_pos);
	DDX_Control(pDX, IDC_EDIT_STAGE_SUB_X_LIMIT_MIN, m_edit_stage_sub_x_limit_min);
	DDX_Control(pDX, IDC_EDIT_STAGE_SUB_X_LIMIT_MAX, m_edit_stage_sub_x_limit_max);
	DDX_Control(pDX, IDC_EDIT_STAGE_SUB_X_ALIGN_OFFSET, m_edit_stage_sub_x_align_offset);
	DDX_Control(pDX, IDC_EDIT_STAGE_SUB_X_MANUAL_SPEED, m_edit_stage_sub_x_manual_speed);
	DDX_Control(pDX, IDC_EDIT_STAGE_SUB_X_PROCESS_SPEED, m_edit_stage_sub_x_process_speed);
}


BEGIN_MESSAGE_MAP(DIALOG_SETTING_STAGE, CDialogEx)
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// DIALOG_SETTING_STAGE 메시지 처리기


HBRUSH DIALOG_SETTING_STAGE::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}


BOOL DIALOG_SETTING_STAGE::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	return CDialogEx::OnEraseBkgnd(pDC);
}


BOOL DIALOG_SETTING_STAGE::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	int static_widht = 100;
	int static_height = 30;
	
	int edit_height = 30;
	
	int y_gap = 30;

	int y_start = 50;

	GetDlgItem(IDC_STATIC_READY_POS)->MoveWindow(10, y_start, 100, edit_height);
	GetDlgItem(IDC_STATIC_PROCESS_POS)->MoveWindow(10, y_start + y_gap * 1, 100, edit_height);
	GetDlgItem(IDC_STATIC_LIMIT_MIN)->MoveWindow(10, y_start + y_gap * 2, 100, edit_height);
	GetDlgItem(IDC_STATIC_LIMIT_MAX)->MoveWindow(10, y_start + y_gap * 3, 100, edit_height);
	GetDlgItem(IDC_STATIC_ALIGN_OFFSET)->MoveWindow(10, y_start + y_gap * 4, 100, edit_height);
	GetDlgItem(IDC_STATIC_MANUAL_SPEED)->MoveWindow(10, y_start + y_gap * 5, 100, edit_height);
	GetDlgItem(IDC_STATIC_PROCESS_SPEED)->MoveWindow(10, y_start + y_gap * 6, 100, edit_height);

	GetDlgItem(IDC_STATIC_STAGE_MAIN_X)->MoveWindow(110, 20, 80, 30);
	GetDlgItem(IDC_EDIT_STAGE_MAIN_X_READY_POS)->MoveWindow(110, y_start, 80, edit_height);
	GetDlgItem(IDC_EDIT_STAGE_MAIN_X_PROCESS_POS)->MoveWindow(110, y_start + y_gap * 1, 80, edit_height);
	GetDlgItem(IDC_EDIT_STAGE_MAIN_X_LIMIT_MIN)->MoveWindow(110, y_start + y_gap * 2, 80, edit_height);
	GetDlgItem(IDC_EDIT_STAGE_MAIN_X_LIMIT_MAX)->MoveWindow(110, y_start + y_gap * 3, 80, edit_height);
	GetDlgItem(IDC_EDIT_STAGE_MAIN_X_MANUAL_SPEED)->MoveWindow(110, y_start + y_gap * 5, 80, edit_height);
	GetDlgItem(IDC_EDIT_STAGE_MAIN_X_PROCESS_SPEED)->MoveWindow(110, y_start + y_gap * 6, 80, edit_height);

	GetDlgItem(IDC_STATIC_STAGE_MAIN_Y)->MoveWindow(190, 20, 80, 30);
	GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_READY_POS)->MoveWindow(190, y_start, 80, edit_height);
	GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_PROCESS_POS)->MoveWindow(190, y_start + y_gap * 1, 80, edit_height);
	GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_LIMIT_MIN)->MoveWindow(190, y_start + y_gap * 2, 80, edit_height);
	GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_LIMIT_MAX)->MoveWindow(190, y_start + y_gap * 3, 80, edit_height);
	GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_MANUAL_SPEED)->MoveWindow(190, y_start + y_gap * 5, 80, edit_height);
	GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_PROCESS_SPEED)->MoveWindow(190, y_start + y_gap * 6, 80, edit_height);

	GetDlgItem(IDC_STATIC_STAGE_SUB_X)->MoveWindow(270, 20, 80, 30);
	GetDlgItem(IDC_EDIT_STAGE_SUB_X_READY_POS)->MoveWindow(270, y_start, 80, edit_height);
	GetDlgItem(IDC_EDIT_STAGE_SUB_X_PROCESS_POS)->MoveWindow(270, y_start + y_gap * 1, 80, edit_height);
	GetDlgItem(IDC_EDIT_STAGE_SUB_X_LIMIT_MIN)->MoveWindow(270, y_start + y_gap * 2, 80, edit_height);
	GetDlgItem(IDC_EDIT_STAGE_SUB_X_LIMIT_MAX)->MoveWindow(270, y_start + y_gap * 3, 80, edit_height);
	GetDlgItem(IDC_EDIT_STAGE_SUB_X_ALIGN_OFFSET)->MoveWindow(270, y_start + y_gap * 4, 80, edit_height);
	GetDlgItem(IDC_EDIT_STAGE_SUB_X_MANUAL_SPEED)->MoveWindow(270, y_start + y_gap * 5, 80, edit_height);
	GetDlgItem(IDC_EDIT_STAGE_SUB_X_PROCESS_SPEED)->MoveWindow(270, y_start + y_gap * 6, 80, edit_height);

	
	// 값 불러오기 
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


BOOL DIALOG_SETTING_STAGE::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	return CDialogEx::PreTranslateMessage(pMsg);
}

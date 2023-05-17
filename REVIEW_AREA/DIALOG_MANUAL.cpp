// DIALOG_MANUAL.cpp: 구현 파일
//

#include "stdafx.h"
#include "REVIEW_AREA.h"
#include "DIALOG_MANUAL.h"
#include "afxdialogex.h"

#include "REVIEW_AREADlg.h"

// DIALOG_MANUAL 대화 상자

IMPLEMENT_DYNAMIC(DIALOG_MANUAL, CDialogEx)

DIALOG_MANUAL::DIALOG_MANUAL(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_MANUAL, pParent)
{

}

DIALOG_MANUAL::~DIALOG_MANUAL()
{
}

void DIALOG_MANUAL::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC_UPPER, m_pic_upper);
	DDX_Control(pDX, IDC_PIC_SIDE, m_pic_side);
	DDX_Control(pDX, IDC_CMB_CAMERA, m_cmb_camera);
	DDX_Control(pDX, IDC_PIC_UPPER_MARK, m_pic_mark_upper);
	DDX_Control(pDX, IDC_EDIT_STAGE_MAIN_X_COMMAND, m_edit_stage_main_x_command);
	DDX_Control(pDX, IDC_EDIT_STAGE_MAIN_X_REFERENCE, m_edit_stage_main_x_reference);
	DDX_Control(pDX, IDC_EDIT_STAGE_MAIN_X_POSITION, m_edit_stage_main_x_position);
	DDX_Control(pDX, IDC_EDIT_STAGE_MAIN_Y_COMMAND, m_edit_stage_main_y_command);
	DDX_Control(pDX, IDC_EDIT_STAGE_MAIN_Y_REFERENCE, m_edit_stage_main_y_reference);
	DDX_Control(pDX, IDC_EDIT_STAGE_MAIN_Y_POSITION, m_edit_stage_main_y_position);
	DDX_Control(pDX, IDC_EDIT_STAGE_SUB_X_COMMAND, m_edit_stage_sub_x_command);
	DDX_Control(pDX, IDC_EDIT_STAGE_SUB_X_REFERENCE, m_edit_stage_sub_x_reference);
	DDX_Control(pDX, IDC_EDIT_STAGE_SUB_X_POSITION, m_edit_stage_sub_x_position);
	DDX_Control(pDX, IDC_CMB_UPPER_MARK, m_cmb_upper_mark);
	DDX_Control(pDX, IDC_CHK_ABS_1, m_chk_abs_1);
	DDX_Control(pDX, IDC_CHK_REL_1, m_chk_rel_1);
	DDX_Control(pDX, IDC_CHK_ABS_2, m_chk_abs_2);
	DDX_Control(pDX, IDC_CHK_REL_2, m_chk_rel_2);
	DDX_Control(pDX, IDC_CHK_ABS_3, m_chk_abs_3);
	DDX_Control(pDX, IDC_CHK_REL_3, m_chk_rel_3);
	DDX_Control(pDX, IDC_LIST_MEASURE, m_list_measure);;
	DDX_Control(pDX, IDC_CMB_SIDE_MARK, m_cmb_side_mark);
	DDX_Control(pDX, IDC_PIC_SIDE_MARK, m_pic_side_mark);
	DDX_Control(pDX, IDC_EDIT_MORP_OPEN, m_edit_morp_open);
	DDX_Control(pDX, IDC_EDIT_MORP_CLOSE, m_edit_morp_close);
	DDX_Control(pDX, IDC_EDIT_BINARY, m_edit_binary);
	DDX_Control(pDX, IDC_EDIT_CONTOUR, m_edit_contour);
	DDX_Control(pDX, IDC_BTN_GRAPHIC, m_btn_graphic);
	DDX_Control(pDX, IDC_BTN_LINE, m_btn_line);
	DDX_Control(pDX, IDC_BTN_RECTANGLE, m_btn_rectangle);
	DDX_Control(pDX, IDC_BTN_CIRCLE, m_btn_circle);
	DDX_Control(pDX, IDC_BTN_EDGE_1, m_btn_edge_1);
	DDX_Control(pDX, IDC_BTN_EDGE_2, m_btn_edge_2);
	DDX_Control(pDX, IDC_CMB_MAGNI, m_cmb_magni);
	DDX_Control(pDX, IDC_EDIT_TEST_ROI_MIN, m_edit_test_roi_min);
	DDX_Control(pDX, IDC_EDIT_TEST_ROI_MAX, m_edit_test_roi_max);
}


BEGIN_MESSAGE_MAP(DIALOG_MANUAL, CDialogEx)
	ON_WM_ERASEBKGND()
	ON_CBN_SELCHANGE(IDC_CMB_CAMERA, &DIALOG_MANUAL::OnCbnSelchangeCmbCamera)
	ON_BN_CLICKED(IDC_CHK_ABS_1, &DIALOG_MANUAL::OnBnClickedChkAbs1)
	ON_BN_CLICKED(IDC_CHK_REL_1, &DIALOG_MANUAL::OnBnClickedChkRel1)
	ON_BN_CLICKED(IDC_CHK_ABS_2, &DIALOG_MANUAL::OnBnClickedChkAbs2)
	ON_BN_CLICKED(IDC_CHK_REL_2, &DIALOG_MANUAL::OnBnClickedChkRel2)
	ON_BN_CLICKED(IDC_CHK_ABS_3, &DIALOG_MANUAL::OnBnClickedChkAbs3)
	ON_BN_CLICKED(IDC_CHK_REL_3, &DIALOG_MANUAL::OnBnClickedChkRel3)
	ON_BN_CLICKED(IDC_BTN_STAGE_MAIN_X_MOVE, &DIALOG_MANUAL::OnBnClickedBtnStageMainXMove)
	ON_BN_CLICKED(IDC_BTN_STAGE_MAIN_Y_MOVE, &DIALOG_MANUAL::OnBnClickedBtnStageMainYMove)
	ON_BN_CLICKED(IDC_BTN_STAGE_SUB_X_MOVE, &DIALOG_MANUAL::OnBnClickedBtnStageSubXMove)
	ON_BN_CLICKED(IDC_BTN_LINE, &DIALOG_MANUAL::OnBnClickedBtnLine)
	ON_BN_CLICKED(IDC_BTN_RECTANGLE, &DIALOG_MANUAL::OnBnClickedBtnRectangle)
	ON_BN_CLICKED(IDC_BTN_CIRCLE, &DIALOG_MANUAL::OnBnClickedBtnCircle)
	ON_BN_CLICKED(IDC_BTN_EDGE_1, &DIALOG_MANUAL::OnBnClickedBtnEdge1)
	ON_BN_CLICKED(IDC_BTN_EDGE_2, &DIALOG_MANUAL::OnBnClickedBtnEdge2)
	ON_BN_CLICKED(IDC_BTN_RESET, &DIALOG_MANUAL::OnBnClickedBtnReset)
	ON_WM_CTLCOLOR()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BTN_GRAPHIC, &DIALOG_MANUAL::OnBnClickedBtnGraphic)
	ON_BN_CLICKED(IDC_BTN_UPPER_MARK_REG, &DIALOG_MANUAL::OnBnClickedBtnUpperMarkReg)
	ON_BN_CLICKED(IDC_BTN_UPPER_MARK_SAVE, &DIALOG_MANUAL::OnBnClickedBtnUpperMarkSave)
	ON_BN_CLICKED(IDC_BTN_SIDE_MARK_REG, &DIALOG_MANUAL::OnBnClickedBtnSideMarkReg)
	ON_BN_CLICKED(IDC_BTN_SIDE_MARK_SAVE, &DIALOG_MANUAL::OnBnClickedBtnSideMarkSave)
	ON_BN_CLICKED(IDC_BTN_MORP, &DIALOG_MANUAL::OnBnClickedBtnMorp)
	ON_BN_CLICKED(IDC_BTN_BINARY, &DIALOG_MANUAL::OnBnClickedBtnBinary)
	ON_BN_CLICKED(IDC_BTN_CONTOUR, &DIALOG_MANUAL::OnBnClickedBtnContour)
	ON_BN_CLICKED(IDC_BTN_FOCUS_RESET, &DIALOG_MANUAL::OnBnClickedBtnFocusReset)
	ON_CBN_SELCHANGE(IDC_CMB_MAGNI, &DIALOG_MANUAL::OnCbnSelchangeCmbMagni)
END_MESSAGE_MAP()


// DIALOG_MANUAL 메시지 처리기


BOOL DIALOG_MANUAL::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	int cam_width = 2048 / 4;
	int cam_height = 2048 / 4;

	
	//GetDlgItem(IDC_PIC_UPPER)->MoveWindow(4, 0, cam_width, cam_height);

	dlg_manual_upper = new DIALOG_MANUAL_UPPER;
	dlg_manual_upper->Create(IDD_DIALOG_MANUAL_UPPER, this);
	dlg_manual_upper->MoveWindow(2, 0, cam_width, cam_height);
	dlg_manual_upper->ShowWindow(SW_SHOW);

	dlg_manual_side = new DIALOG_MANUAL_SIDE;
	dlg_manual_side->Create(IDD_DIALOG_MANUAL_SIDE, this);
	dlg_manual_side->MoveWindow(2, cam_height, cam_width, cam_height);
	dlg_manual_side->ShowWindow(SW_SHOW);

	GetDlgItem(IDC_STATIC_UPPER_MAGNI)->MoveWindow(530, 490, 30, 20);
	GetDlgItem(IDC_STATIC_SIDE_MAGNI)->MoveWindow(530, 1002, 30, 20);

	//GetDlgItem(IDC_PIC_SIDE)->MoveWindow(4, cam_height, cam_width, cam_height);

	GetDlgItem(IDC_CMB_CAMERA)->MoveWindow(1312, 10, 100, 20);
	GetDlgItem(IDC_PIC_FOCUS)->MoveWindow(900, 40, cam_width, cam_height);

	GetDlgItem(IDC_STATIC_MORP_OPEN)->MoveWindow(910, 560, 80, 20);
	GetDlgItem(IDC_STATIC_MORP_CLOSE)->MoveWindow(910, 590, 80, 20);
	GetDlgItem(IDC_STATIC_BINARY)->MoveWindow(1080, 560, 80, 20);
	GetDlgItem(IDC_STATIC_CONTOUR)->MoveWindow(1080, 590, 80, 20);
	GetDlgItem(IDC_STATIC_TEST_ROI_MIN)->MoveWindow(1080, 620, 80, 20);
	GetDlgItem(IDC_STATIC_TEST_ROI_MAX)->MoveWindow(1080, 650, 80, 20);


	GetDlgItem(IDC_STATIC_MANUAL_X)->MoveWindow(910, 620, 80, 20);
	GetDlgItem(IDC_STATIC_MANUAL_Y)->MoveWindow(910, 650, 80, 20);

	GetDlgItem(IDC_STATIC_MANUAL_X_POS)->MoveWindow(990, 620, 80, 20);
	GetDlgItem(IDC_STATIC_MANUAL_Y_POS)->MoveWindow(990, 650, 80, 20);


	GetDlgItem(IDC_EDIT_MORP_OPEN)->MoveWindow(990, 560, 80, 20);
	GetDlgItem(IDC_EDIT_MORP_CLOSE)->MoveWindow(990, 590, 80, 20);
	GetDlgItem(IDC_EDIT_BINARY)->MoveWindow(1160, 560, 80, 20);
	GetDlgItem(IDC_EDIT_CONTOUR)->MoveWindow(1160, 590, 80, 20);
	GetDlgItem(IDC_EDIT_TEST_ROI_MIN)->MoveWindow(1160, 620, 80, 20);
	GetDlgItem(IDC_EDIT_TEST_ROI_MAX)->MoveWindow(1160, 650, 80, 20);


	GetDlgItem(IDC_BTN_MORP)->MoveWindow(1272, 560, 40, 40);
	GetDlgItem(IDC_BTN_BINARY)->MoveWindow(1322, 560, 40, 40);
	GetDlgItem(IDC_BTN_CONTOUR)->MoveWindow(1372, 560, 40, 40);
	GetDlgItem(IDC_BTN_FOCUS_RESET)->MoveWindow(1372, 610, 40, 40);

	m_cmb_camera.SetCurSel(0);
	m_cmb_magni.SetCurSel(0);
	
	GetDlgItem(IDC_CMB_MAGNI)->MoveWindow(700, 10, 100, 20);
	GetDlgItem(IDC_GRP_UPPER)->MoveWindow(560, 50, 240, 275);
	GetDlgItem(IDC_STATIC_UPPER_X)->MoveWindow(cam_width + 60, 70, 80, 20);
	GetDlgItem(IDC_STATIC_UPPER_Y)->MoveWindow(cam_width + 60, 100, 80, 20);
	GetDlgItem(IDC_STATIC_UPPER_MAGNI)->MoveWindow(cam_width + 60, 290, 80, 20);
	GetDlgItem(IDC_STATIC_UPPER_X_POS)->MoveWindow(cam_width + 170, 70, 100, 20);
	GetDlgItem(IDC_STATIC_UPPER_Y_POS)->MoveWindow(cam_width + 170, 100, 100, 20);
	GetDlgItem(IDC_PIC_UPPER_MARK)->MoveWindow(680, 130, 100, 100);
	GetDlgItem(IDC_CMB_UPPER_MARK)->MoveWindow(680, 240, 100, 20);
	GetDlgItem(IDC_BTN_UPPER_MARK_REG)->MoveWindow(685, 270, 40, 40);
	GetDlgItem(IDC_BTN_UPPER_MARK_SAVE)->MoveWindow(735, 270, 40, 40);

	GetDlgItem(IDC_GRP_SIDE)->MoveWindow(560, 340, 240, 275);
	GetDlgItem(IDC_STATIC_SIDE_X)->MoveWindow(cam_width + 60, 360, 80, 20);
	GetDlgItem(IDC_STATIC_SIDE_Y)->MoveWindow(cam_width + 60, 390, 80, 20);
	GetDlgItem(IDC_STATIC_SIDE_MAGNI)->MoveWindow(cam_width + 60, 580, 80, 20);
	GetDlgItem(IDC_STATIC_SIDE_X_POS)->MoveWindow(cam_width + 170, 360, 100, 20);
	GetDlgItem(IDC_STATIC_SIDE_Y_POS)->MoveWindow(cam_width + 170, 390, 100, 20);
	GetDlgItem(IDC_PIC_SIDE_MARK)->MoveWindow(680, 420, 100, 100);
	GetDlgItem(IDC_CMB_SIDE_MARK)->MoveWindow(680, 530, 100, 20);
	GetDlgItem(IDC_BTN_SIDE_MARK_REG)->MoveWindow(685, 560, 40, 40);
	GetDlgItem(IDC_BTN_SIDE_MARK_SAVE)->MoveWindow(735, 560, 40, 40);

	int edit_y_start = cam_height + 100;


	GetDlgItem(IDC_STATIC_MAIN_X)->MoveWindow(560, 630, 180, 20);
	GetDlgItem(IDC_STATIC_STAGE_MAIN_X_COMMAND)->MoveWindow(560, 650, 100, 25);
	GetDlgItem(IDC_STATIC_STAGE_MAIN_X_REFERENCE)->MoveWindow(560, 675, 100, 25);
	GetDlgItem(IDC_STATIC_STAGE_MAIN_X_POSITION)->MoveWindow(560, 700, 100, 25);
	GetDlgItem(IDC_CHK_ABS_1)->MoveWindow(560, 725, 50, 25);
	GetDlgItem(IDC_CHK_REL_1)->MoveWindow(610, 725, 50, 25);
	GetDlgItem(IDC_BTN_STAGE_MAIN_X_MOVE)->MoveWindow(670, 725, 70, 25);
	GetDlgItem(IDC_EDIT_STAGE_MAIN_X_COMMAND)->MoveWindow(670, 650, 70, 25);
	GetDlgItem(IDC_EDIT_STAGE_MAIN_X_REFERENCE)->MoveWindow(670, 675, 70, 25);
	GetDlgItem(IDC_EDIT_STAGE_MAIN_X_POSITION)->MoveWindow(670, 700, 70, 25);

	GetDlgItem(IDC_STATIC_MAIN_Y)->MoveWindow(560, 760, 180, 20);
	GetDlgItem(IDC_STATIC_STAGE_MAIN_Y_COMMAND)->MoveWindow(560, 780, 100, 25);
	GetDlgItem(IDC_STATIC_STAGE_MAIN_Y_REFERENCE)->MoveWindow(560, 805, 100, 25);
	GetDlgItem(IDC_STATIC_STAGE_MAIN_Y_POSITION)->MoveWindow(560, 830, 100, 25);
	GetDlgItem(IDC_CHK_ABS_2)->MoveWindow(560, 855, 50, 25);
	GetDlgItem(IDC_CHK_REL_2)->MoveWindow(610, 855, 50, 25);
	GetDlgItem(IDC_BTN_STAGE_MAIN_Y_MOVE)->MoveWindow(670, 855, 70, 25);
	GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_COMMAND)->MoveWindow(670, 780, 70, 25);
	GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_REFERENCE)->MoveWindow(670, 805, 70, 25);
	GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_POSITION)->MoveWindow(670, 830, 70, 25);

	GetDlgItem(IDC_STATIC_SUB_X)->MoveWindow(560, 890, 180, 20);
	GetDlgItem(IDC_STATIC_STAGE_SUB_X_COMMAND)->MoveWindow(560, 910, 100, 25);
	GetDlgItem(IDC_STATIC_STAGE_SUB_X_REFERENCE)->MoveWindow(560, 935, 100, 25);
	GetDlgItem(IDC_STATIC_STAGE_SUB_X_POSITION)->MoveWindow(560, 960, 100, 25);
	GetDlgItem(IDC_CHK_ABS_3)->MoveWindow(560, 985, 50, 25);
	GetDlgItem(IDC_CHK_REL_3)->MoveWindow(610, 985, 50, 25);
	GetDlgItem(IDC_BTN_STAGE_SUB_X_MOVE)->MoveWindow(670, 985, 70, 25);
	GetDlgItem(IDC_EDIT_STAGE_SUB_X_COMMAND)->MoveWindow(670, 910, 70, 25);
	GetDlgItem(IDC_EDIT_STAGE_SUB_X_REFERENCE)->MoveWindow(670, 935, 70, 25);
	GetDlgItem(IDC_EDIT_STAGE_SUB_X_POSITION)->MoveWindow(670, 960, 70, 25);

	GetDlgItem(IDC_BTN_GRAPHIC)->MoveWindow(1100, 894, 40, 40);
	GetDlgItem(IDC_BTN_LINE)->MoveWindow(900, 944, 40, 40);
	GetDlgItem(IDC_BTN_RECTANGLE)->MoveWindow(950, 944, 40, 40);
	GetDlgItem(IDC_BTN_CIRCLE)->MoveWindow(1000, 944, 40, 40);
	GetDlgItem(IDC_BTN_EDGE_1)->MoveWindow(1050, 944, 40, 40);
	GetDlgItem(IDC_BTN_EDGE_2)->MoveWindow(1100, 944, 40, 40);

	GetDlgItem(IDC_LIST_MEASURE)->MoveWindow(1150, 680, 250, 304);
	GetDlgItem(IDC_BTN_RESET)->MoveWindow(1330, 984, 70, 30);

	m_chk_abs_1.SetCheck(1);
	m_chk_abs_2.SetCheck(1);
	m_chk_abs_3.SetCheck(1);

	m_chk_rel_1.SetCheck(0);
	m_chk_rel_2.SetCheck(0);
	m_chk_rel_3.SetCheck(0);

	overlay_display = 0;
	overlay_graphic = 0;

	measure_mode = 0;

	GetDlgItem(IDC_BTN_LINE)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_RECTANGLE)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_CIRCLE)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_EDGE_1)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_EDGE_2)->EnableWindow(FALSE);
	
	GetDlgItem(IDC_CMB_UPPER_MARK)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_UPPER_MARK_REG)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_UPPER_MARK_SAVE)->EnableWindow(FALSE);

	GetDlgItem(IDC_CMB_SIDE_MARK)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_SIDE_MARK_REG)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_SIDE_MARK_SAVE)->EnableWindow(FALSE);

	GetDlgItem(IDC_CMB_CAMERA)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_MORP_OPEN)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_MORP_CLOSE)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_BINARY)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_CONTOUR)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_TEST_ROI_MIN)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_TEST_ROI_MAX)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_MORP)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_BINARY)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_CONTOUR)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_FOCUS_RESET)->EnableWindow(FALSE);



	check_graphic_mode = 0;

	m_edit_morp_open.SetWindowTextW(_T("5"));
	m_edit_morp_close.SetWindowTextW(_T("20"));
	m_edit_binary.SetWindowTextW(_T("150"));
	m_edit_contour.SetWindowTextW(_T("20000"));
	m_edit_test_roi_min.SetWindowTextW(_T("300"));
	m_edit_test_roi_max.SetWindowTextW(_T("600"));

	m_graphic_on.LoadBitmapW(IDB_BITMAP_GRAPHIC_ON);
	m_graphic_off.LoadBitmapW(IDB_BITMAP_GRAPHIC_OFF);
	m_line_on.LoadBitmapW(IDB_BITMAP_LINE_ON);
	m_line_off.LoadBitmapW(IDB_BITMAP_LINE_OFF);
	m_rectangle_on.LoadBitmapW(IDB_BITMAP_RECTANGLE_ON);
	m_rectangle_off.LoadBitmapW(IDB_BITMAP_RECTANGLE_OFF);
	m_circle_on.LoadBitmapW(IDB_BITMAP_CIRCLE_ON);
	m_circle_off.LoadBitmapW(IDB_BITMAP_CIRCLE_OFF);
	m_edge_1_on.LoadBitmapW(IDB_BITMAP_EDGE_1_ON);
	m_edge_1_off.LoadBitmapW(IDB_BITMAP_EDGE_1_OFF);
	m_edge_2_on.LoadBitmapW(IDB_BITMAP_EDGE_2_ON);
	m_edge_2_off.LoadBitmapW(IDB_BITMAP_EDGE_2_OFF);

	m_btn_graphic.SetBitmap(m_graphic_off);
	m_btn_line.SetBitmap(m_line_off);
	m_btn_rectangle.SetBitmap(m_rectangle_off);
	m_btn_circle.SetBitmap(m_circle_off);
	m_btn_edge_1.SetBitmap(m_edge_1_off);
	m_btn_edge_2.SetBitmap(m_edge_2_off);

	pen_line.CreatePen(PS_NULL, 1.0, RGB(255, 0, 0));
	pen_rectangle.CreatePen(PS_SOLID, 1.0, RGB(255, 0, 0));
	pen_circle.CreatePen(PS_SOLID, 1.0, RGB(255, 0, 0));
	pen_mark.CreatePen(PS_SOLID, 1.0, RGB(255, 0, 0));

	null_brush.CreateStockObject(NULL_BRUSH);

	HFONT hNewFont;

	measure_count = 1;
	list_count = 0;

	hNewFont = CreateFont(15, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_MODERN, _T("맑은 고딕"));
	m_list_measure.SendMessage(WM_SETFONT, (WPARAM)hNewFont, (LPARAM)TRUE);

	m_list_measure.InsertColumn(1, TEXT("LABEL."), LVCFMT_CENTER, 80);
	m_list_measure.InsertColumn(2, TEXT("VALUE"), LVCFMT_CENTER, 170);

	hdc_manual_upper = GetDlgItem(IDC_PIC_UPPER)->GetDC()->m_hDC;
	hdc_manual_side = GetDlgItem(IDC_PIC_SIDE)->GetDC()->m_hDC;
	hdc_mark_upper = GetDlgItem(IDC_PIC_UPPER_MARK)->GetDC()->m_hDC;
	hdc_mark_side = GetDlgItem(IDC_PIC_SIDE_MARK)->GetDC()->m_hDC;
	hdc_camera_focus = GetDlgItem(IDC_PIC_FOCUS)->GetDC()->m_hDC;

	SetStretchBltMode(hdc_manual_upper, COLORONCOLOR);
	SetStretchBltMode(hdc_manual_side, COLORONCOLOR);
	SetStretchBltMode(hdc_mark_upper, COLORONCOLOR);
	SetStretchBltMode(hdc_mark_side, COLORONCOLOR);
	SetStretchBltMode(hdc_camera_focus, COLORONCOLOR);

	SetTimer(1, 1, NULL);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


BOOL DIALOG_MANUAL::PreTranslateMessage(MSG* pMsg)
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


BOOL DIALOG_MANUAL::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	/*CRect rect;

	GetClientRect(rect);

	pDC->FillSolidRect(rect, RGB(255, 255, 255));

	return TRUE;*/
	return CDialogEx::OnEraseBkgnd(pDC);
}


void DIALOG_MANUAL::OnCbnSelchangeCmbCamera()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nPos;

	nPos = m_cmb_camera.GetCurSel();

	if (nPos == 0)
	{
		focus_image = imread("Data\\4. MEASURE\\1. ORIGIN\\UPPER.bmp");
		//focus_image = imread("upper.bmp");

		focusInfo = (BITMAPINFO*)focusBuf;
		focusInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		focusInfo->bmiHeader.biWidth = focus_image.cols;
		focusInfo->bmiHeader.biHeight = -(focus_image.rows);
		focusInfo->bmiHeader.biBitCount = 24;
		focusInfo->bmiHeader.biPlanes = 1;
		focusInfo->bmiHeader.biCompression = BI_RGB;
		focusInfo->bmiHeader.biSizeImage = 0;
		focusInfo->bmiHeader.biXPelsPerMeter = 0;
		focusInfo->bmiHeader.biYPelsPerMeter = 0;
		focusInfo->bmiHeader.biClrUsed = 0;
		focusInfo->bmiHeader.biClrImportant = 0;


		StretchDIBits(hdc_camera_focus, 0, 0, 512, 512, 0, 0, focus_image.cols, focus_image.rows,
			focus_image.data, focusInfo, DIB_RGB_COLORS, SRCCOPY);
	}

	else if (nPos == 1)
	{
		focus_image = imread("Data\\4. MEASURE\\1. ORIGIN\\SIDE.bmp");
		//focus_image = imread("side.bmp");

		focusInfo = (BITMAPINFO*)focusBuf;
		focusInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		focusInfo->bmiHeader.biWidth = focus_image.cols;
		focusInfo->bmiHeader.biHeight = -(focus_image.rows);
		focusInfo->bmiHeader.biBitCount = 24;
		focusInfo->bmiHeader.biPlanes = 1;
		focusInfo->bmiHeader.biCompression = BI_RGB;
		focusInfo->bmiHeader.biSizeImage = 0;
		focusInfo->bmiHeader.biXPelsPerMeter = 0;
		focusInfo->bmiHeader.biYPelsPerMeter = 0;
		focusInfo->bmiHeader.biClrUsed = 0;
		focusInfo->bmiHeader.biClrImportant = 0;

		StretchDIBits(hdc_camera_focus, 0, 0, 512, 512, 0, 0, focus_image.cols, focus_image.rows,
			focus_image.data, focusInfo, DIB_RGB_COLORS, SRCCOPY);
	}
}


void DIALOG_MANUAL::OnBnClickedChkAbs1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_chk_abs_1.SetCheck(1);
	m_chk_rel_1.SetCheck(0);
}


void DIALOG_MANUAL::OnBnClickedChkRel1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_chk_abs_1.SetCheck(0);
	m_chk_rel_1.SetCheck(1);
}


void DIALOG_MANUAL::OnBnClickedChkAbs2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_chk_abs_2.SetCheck(1);
	m_chk_rel_2.SetCheck(0);
}


void DIALOG_MANUAL::OnBnClickedChkRel2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_chk_abs_2.SetCheck(0);
	m_chk_rel_2.SetCheck(1);
}


void DIALOG_MANUAL::OnBnClickedChkAbs3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_chk_abs_3.SetCheck(1);
	m_chk_rel_3.SetCheck(0);
}


void DIALOG_MANUAL::OnBnClickedChkRel3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_chk_abs_3.SetCheck(0);
	m_chk_rel_3.SetCheck(1);
}


void DIALOG_MANUAL::OnBnClickedBtnStageMainXMove()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CREVIEWAREADlg *pManual = (CREVIEWAREADlg*)AfxGetMainWnd();

	CString strMove;
	GetDlgItem(IDC_BTN_STAGE_MAIN_X_MOVE)->GetWindowTextW(strMove);

	if (strMove == _T("MOVE"))
	{
		acsc_SetVelocity(hStage_manual, ACSC_AXIS_4, pManual->dlg_auto->stage_main_x_manual_speed, NULL);
		acsc_GetRPosition(hStage_manual, ACSC_AXIS_4, &pManual->stage_main_x_pos, NULL);

		stage_main_x_min_limit = pManual->dlg_auto->stage_main_x_limit_min;
		stage_main_x_max_limit = pManual->dlg_auto->stage_main_x_limit_max;

		moving_stage = 1;	// 1 : main_x

		// 절대 값 이동
		if (m_chk_abs_1.GetCheck() == 1)
		{
			m_edit_stage_main_x_position.GetWindowTextW(str_command);
			val_command = _wtof(str_command);
			m_edit_stage_main_x_command.SetWindowTextW(str_command);
		}

		else
		{
			m_edit_stage_main_x_position.GetWindowTextW(str_rel);
			val_rel = _wtof(str_rel);

			val_command = pManual->stage_main_x_pos + val_rel;
			str_command.Format(_T("%.4f"), val_command);

			m_edit_stage_main_x_command.SetWindowTextW(str_command);
		}

		manual = AfxBeginThread(manual_Thread, this);
	}

	else if (strMove == _T("STOP"))
	{
		acsc_Kill(hStage_manual, ACSC_AXIS_4, NULL);	// Stage_x kill

		// Stage Thread OFF
		DWORD nExitCode = NULL;

		GetExitCodeThread(manual->m_hThread, &nExitCode);
		TerminateThread(manual->m_hThread, nExitCode);

		manual = NULL;

		GetDlgItem(IDC_BTN_STAGE_MAIN_X_MOVE)->SetWindowTextW(_T("MOVE"));
	}
}


void DIALOG_MANUAL::OnBnClickedBtnStageMainYMove()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CREVIEWAREADlg *pManual = (CREVIEWAREADlg*)AfxGetMainWnd();

	CString strMove;
	GetDlgItem(IDC_BTN_STAGE_MAIN_Y_MOVE)->GetWindowTextW(strMove);

	if (strMove == _T("MOVE"))
	{
		acsc_SetVelocity(hStage_manual, ACSC_AXIS_0, pManual->dlg_auto->stage_main_y_manual_speed, NULL);
		acsc_GetRPosition(hStage_manual, ACSC_AXIS_0, &pManual->stage_main_y_pos, NULL);

		stage_main_y_min_limit = pManual->dlg_auto->stage_main_y_limit_min;
		stage_main_y_max_limit = pManual->dlg_auto->stage_main_y_limit_max;

		moving_stage = 2;	// 2 : main_y

		// 절대 값 이동
		if (m_chk_abs_2.GetCheck() == 1)
		{
			m_edit_stage_main_y_position.GetWindowTextW(str_command);
			val_command = _wtof(str_command);
			m_edit_stage_main_y_command.SetWindowTextW(str_command);
		}

		else
		{
			m_edit_stage_main_y_position.GetWindowTextW(str_rel);
			val_rel = _wtof(str_rel);

			val_command = pManual->stage_main_y_pos + val_rel;
			str_command.Format(_T("%.4f"), val_command);

			m_edit_stage_main_y_command.SetWindowTextW(str_command);
		}

		manual = AfxBeginThread(manual_Thread, this);
	}

	else if (strMove == _T("STOP"))
	{
		acsc_Kill(hStage_manual, ACSC_AXIS_0, NULL);

		DWORD nExitCode = NULL;

		GetExitCodeThread(manual->m_hThread, &nExitCode);
		TerminateThread(manual->m_hThread, nExitCode);

		manual = NULL;

		GetDlgItem(IDC_BTN_STAGE_MAIN_Y_MOVE)->SetWindowTextW(_T("MOVE"));
	}
}


void DIALOG_MANUAL::OnBnClickedBtnStageSubXMove()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CREVIEWAREADlg *pManual = (CREVIEWAREADlg*)AfxGetMainWnd();

	CString strMove;
	GetDlgItem(IDC_BTN_STAGE_SUB_X_MOVE)->GetWindowTextW(strMove);

	if (strMove == _T("MOVE"))
	{
		acsc_SetVelocity(hStage_manual, ACSC_AXIS_10, pManual->dlg_auto->stage_sub_x_manual_speed, NULL);
		acsc_GetRPosition(hStage_manual, ACSC_AXIS_10, &pManual->stage_sub_x_pos, NULL);

		stage_sub_x_min_limit = pManual->dlg_auto->stage_sub_x_limit_min;
		stage_sub_x_max_limit = pManual->dlg_auto->stage_sub_x_limit_max;

		moving_stage = 3;	// 3 : sub_x

		// 절대 값 이동
		if (m_chk_abs_3.GetCheck() == 1)
		{
			m_edit_stage_sub_x_position.GetWindowTextW(str_command);
			val_command = _wtof(str_command);
			m_edit_stage_sub_x_command.SetWindowTextW(str_command);
		}

		else
		{
			m_edit_stage_sub_x_position.GetWindowTextW(str_rel);
			val_rel = _wtof(str_rel);

			val_command = pManual->stage_sub_x_pos + val_rel;
			str_command.Format(_T("%.4f"), val_command);

			m_edit_stage_sub_x_command.SetWindowTextW(str_command);
		}

		manual = AfxBeginThread(manual_Thread, this);
	}

	else if (strMove == _T("STOP"))
	{
		acsc_Kill(hStage_manual, ACSC_AXIS_10, NULL);

		DWORD nExitCode = NULL;

		GetExitCodeThread(manual->m_hThread, &nExitCode);
		TerminateThread(manual->m_hThread, nExitCode);

		manual = NULL;

		GetDlgItem(IDC_BTN_STAGE_SUB_X_MOVE)->SetWindowTextW(_T("MOVE"));
	}
}


UINT DIALOG_MANUAL::manual_Thread(LPVOID pParam)
{
	DIALOG_MANUAL *dlg_manual = (DIALOG_MANUAL*)pParam;

	// stage_x
	if (dlg_manual->moving_stage == 1)
	{
		if (dlg_manual->m_chk_abs_1.GetCheck() == 1)
		{
			// limit 를 벗어난 경우

			if (dlg_manual->val_command >= dlg_manual->stage_main_x_max_limit || dlg_manual->val_command <= dlg_manual->stage_main_x_min_limit)
				AfxMessageBox(_T("Stage_main_X_limit error"));

			// limit 내 위치하는 경우
			else if (dlg_manual->val_command < dlg_manual->stage_main_x_max_limit && dlg_manual->val_command > dlg_manual->stage_main_x_min_limit)
			{
				acsc_ToPoint(dlg_manual->hStage_manual, 0, ACSC_AXIS_4, dlg_manual->val_command, NULL);
				do
				{
					acsc_GetMotorState(dlg_manual->hStage_manual, ACSC_AXIS_4, &dlg_manual->stage_main_x_status, NULL);
					dlg_manual->GetDlgItem(IDC_BTN_STAGE_MAIN_X_MOVE)->SetWindowTextW(_T("STOP"));
					Sleep(100);
				} while (dlg_manual->stage_main_x_status & ACSC_AST_MOVE);
				dlg_manual->GetDlgItem(IDC_BTN_STAGE_MAIN_X_MOVE)->SetWindowTextW(_T("MOVE"));
			}
		}

		else if (dlg_manual->m_chk_rel_1.GetCheck() == 1)
		{
			// limit 를 벗어난 경우
			if (dlg_manual->val_command >= dlg_manual->stage_main_x_max_limit || dlg_manual->val_command <= dlg_manual->stage_main_x_min_limit)
				AfxMessageBox(_T("Stage_main_X_limit error"));

			// limit 내 위치하는 경우
			else if (dlg_manual->val_command < dlg_manual->stage_main_x_max_limit && dlg_manual->val_command > dlg_manual->stage_main_x_min_limit)
			{
				acsc_ToPoint(dlg_manual->hStage_manual, ACSC_AMF_RELATIVE, ACSC_AXIS_4, dlg_manual->val_rel, NULL);
				do
				{
					acsc_GetMotorState(dlg_manual->hStage_manual, ACSC_AXIS_4, &dlg_manual->stage_main_x_status, NULL);
					dlg_manual->GetDlgItem(IDC_BTN_STAGE_MAIN_X_MOVE)->SetWindowTextW(_T("STOP"));
					Sleep(100);
				} while (dlg_manual->stage_main_x_status & ACSC_AST_MOVE);
				dlg_manual->GetDlgItem(IDC_BTN_STAGE_MAIN_X_MOVE)->SetWindowTextW(_T("MOVE"));
			}
		}
	}

	// stage_y
	if (dlg_manual->moving_stage == 2)
	{
		if (dlg_manual->m_chk_abs_2.GetCheck() == 1)
		{
			// limit 를 벗어난 경우

			if (dlg_manual->val_command >= dlg_manual->stage_main_y_max_limit || dlg_manual->val_command <= dlg_manual->stage_main_y_min_limit)
				AfxMessageBox(_T("Stage_main_Y_limit error"));

			// limit 내 위치하는 경우
			else if (dlg_manual->val_command < dlg_manual->stage_main_y_max_limit && dlg_manual->val_command > dlg_manual->stage_main_y_min_limit)
			{
				acsc_ToPoint(dlg_manual->hStage_manual, 0, ACSC_AXIS_0, dlg_manual->val_command, NULL);
				do
				{
					acsc_GetMotorState(dlg_manual->hStage_manual, ACSC_AXIS_0, &dlg_manual->stage_main_y_status, NULL);
					dlg_manual->GetDlgItem(IDC_BTN_STAGE_MAIN_Y_MOVE)->SetWindowTextW(_T("STOP"));
					Sleep(100);
				} while (dlg_manual->stage_main_y_status & ACSC_AST_MOVE);
				dlg_manual->GetDlgItem(IDC_BTN_STAGE_MAIN_Y_MOVE)->SetWindowTextW(_T("MOVE"));
			}
		}

		else if (dlg_manual->m_chk_rel_2.GetCheck() == 1)
		{
			// limit 를 벗어난 경우
			if (dlg_manual->val_command >= dlg_manual->stage_main_y_max_limit || dlg_manual->val_command <= dlg_manual->stage_main_y_min_limit)
				AfxMessageBox(_T("Stage_main_Y_limit error"));

			// limit 내 위치하는 경우
			else if (dlg_manual->val_command < dlg_manual->stage_main_y_max_limit && dlg_manual->val_command > dlg_manual->stage_main_y_min_limit)
			{
				acsc_ToPoint(dlg_manual->hStage_manual, ACSC_AMF_RELATIVE, ACSC_AXIS_0, dlg_manual->val_rel, NULL);
				do
				{
					acsc_GetMotorState(dlg_manual->hStage_manual, ACSC_AXIS_0, &dlg_manual->stage_main_y_status, NULL);
					dlg_manual->GetDlgItem(IDC_BTN_STAGE_MAIN_Y_MOVE)->SetWindowTextW(_T("STOP"));
					Sleep(100);
				} while (dlg_manual->stage_main_y_status & ACSC_AST_MOVE);
				dlg_manual->GetDlgItem(IDC_BTN_STAGE_MAIN_Y_MOVE)->SetWindowTextW(_T("MOVE"));
			}
		}
	}

	// stage_x
	if (dlg_manual->moving_stage == 3)
	{
		if (dlg_manual->m_chk_abs_3.GetCheck() == 1)
		{
			// limit 를 벗어난 경우

			if (dlg_manual->val_command >= dlg_manual->stage_sub_x_max_limit || dlg_manual->val_command <= dlg_manual->stage_sub_x_min_limit)
				AfxMessageBox(_T("Stage_sub_X_limit error"));

			// limit 내 위치하는 경우
			else if (dlg_manual->val_command < dlg_manual->stage_sub_x_max_limit && dlg_manual->val_command > dlg_manual->stage_sub_x_min_limit)
			{
				acsc_ToPoint(dlg_manual->hStage_manual, 0, ACSC_AXIS_10, dlg_manual->val_command, NULL);
				do
				{
					acsc_GetMotorState(dlg_manual->hStage_manual, ACSC_AXIS_10, &dlg_manual->stage_sub_x_status, NULL);
					dlg_manual->GetDlgItem(IDC_BTN_STAGE_SUB_X_MOVE)->SetWindowTextW(_T("STOP"));
					Sleep(100);
				} while (dlg_manual->stage_sub_x_status & ACSC_AST_MOVE);
				dlg_manual->GetDlgItem(IDC_BTN_STAGE_SUB_X_MOVE)->SetWindowTextW(_T("MOVE"));
			}
		}

		else if (dlg_manual->m_chk_rel_3.GetCheck() == 1)
		{
			// limit 를 벗어난 경우
			if (dlg_manual->val_command >= dlg_manual->stage_sub_x_max_limit || dlg_manual->val_command <= dlg_manual->stage_sub_x_min_limit)
				AfxMessageBox(_T("Stage_sub_X_limit error"));

			// limit 내 위치하는 경우
			else if (dlg_manual->val_command < dlg_manual->stage_sub_x_max_limit && dlg_manual->val_command > dlg_manual->stage_sub_x_min_limit)
			{
				acsc_ToPoint(dlg_manual->hStage_manual, ACSC_AMF_RELATIVE, ACSC_AXIS_10, dlg_manual->val_rel, NULL);
				do
				{
					acsc_GetMotorState(dlg_manual->hStage_manual, ACSC_AXIS_10, &dlg_manual->stage_sub_x_status, NULL);
					dlg_manual->GetDlgItem(IDC_BTN_STAGE_SUB_X_MOVE)->SetWindowTextW(_T("STOP"));
					Sleep(100);
				} while (dlg_manual->stage_sub_x_status & ACSC_AST_MOVE);
				dlg_manual->GetDlgItem(IDC_BTN_STAGE_SUB_X_MOVE)->SetWindowTextW(_T("MOVE"));
			}
		}
	}

	return 0;
}


void DIALOG_MANUAL::OnBnClickedBtnGraphic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.	
	CREVIEWAREADlg *pManual = (CREVIEWAREADlg*)AfxGetMainWnd();

	if (check_graphic_mode == 0)
	{
		GetDlgItem(IDC_BTN_LINE)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_RECTANGLE)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_CIRCLE)->EnableWindow(TRUE);
		//
		GetDlgItem(IDC_BTN_EDGE_1)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_EDGE_2)->EnableWindow(FALSE);

		m_btn_graphic.SetBitmap(m_graphic_on);
		m_btn_line.SetBitmap(m_line_off);
		m_btn_rectangle.SetBitmap(m_rectangle_off);
		m_btn_circle.SetBitmap(m_circle_off);
		m_btn_edge_1.SetBitmap(m_edge_1_off);
		m_btn_edge_2.SetBitmap(m_edge_2_off);

		check_graphic_mode = 1;
		overlay_display = 1;
		
		measure_mode = 0;
	}

	else if (check_graphic_mode == 1)
	{
		GetDlgItem(IDC_BTN_LINE)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_RECTANGLE)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_CIRCLE)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_EDGE_1)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_EDGE_2)->EnableWindow(FALSE);

		m_btn_graphic.SetBitmap(m_graphic_off);
		m_btn_line.SetBitmap(m_line_off);
		m_btn_rectangle.SetBitmap(m_rectangle_off);
		m_btn_circle.SetBitmap(m_circle_off);
		m_btn_edge_1.SetBitmap(m_edge_1_off);
		m_btn_edge_2.SetBitmap(m_edge_2_off);

		click_count = 0;
		click_area = 0;

		check_graphic_mode = 0;
		overlay_display = 0;

		measure_mode = 0;
	}

	pManual->graphic_active();
}


void DIALOG_MANUAL::OnBnClickedBtnLine()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	measure_mode = 1;

	m_btn_line.SetBitmap(m_line_on);
	m_btn_rectangle.SetBitmap(m_rectangle_off);
	m_btn_circle.SetBitmap(m_circle_off);
	m_btn_edge_1.SetBitmap(m_edge_1_off);
	m_btn_edge_2.SetBitmap(m_edge_2_off);
}


void DIALOG_MANUAL::OnBnClickedBtnRectangle()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	measure_mode = 2;

	m_btn_line.SetBitmap(m_line_off);
	m_btn_rectangle.SetBitmap(m_rectangle_on);
	m_btn_circle.SetBitmap(m_circle_off);
	m_btn_edge_1.SetBitmap(m_edge_1_off);
	m_btn_edge_2.SetBitmap(m_edge_2_off);
}


void DIALOG_MANUAL::OnBnClickedBtnCircle()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	measure_mode = 3;

	m_btn_line.SetBitmap(m_line_off);
	m_btn_rectangle.SetBitmap(m_rectangle_off);
	m_btn_circle.SetBitmap(m_circle_on);
	m_btn_edge_1.SetBitmap(m_edge_1_off);
	m_btn_edge_2.SetBitmap(m_edge_2_off);
}


void DIALOG_MANUAL::OnBnClickedBtnEdge1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	measure_mode = 4;
	m_btn_line.SetBitmap(m_line_off);
	m_btn_rectangle.SetBitmap(m_rectangle_off);
	m_btn_circle.SetBitmap(m_circle_off);
	m_btn_edge_1.SetBitmap(m_edge_1_on);
	m_btn_edge_2.SetBitmap(m_edge_2_off);
}


void DIALOG_MANUAL::OnBnClickedBtnEdge2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	measure_mode = 5;
	m_btn_line.SetBitmap(m_line_off);
	m_btn_rectangle.SetBitmap(m_rectangle_off);
	m_btn_circle.SetBitmap(m_circle_off);
	m_btn_edge_1.SetBitmap(m_edge_1_off);
	m_btn_edge_2.SetBitmap(m_edge_2_on);
}


void DIALOG_MANUAL::OnBnClickedBtnReset()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	measure_count = 1;
	list_count = 0;

	m_list_measure.DeleteAllItems();
}


HBRUSH DIALOG_MANUAL::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}


void DIALOG_MANUAL::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialogEx::OnLButtonDown(nFlags, point);
}


void DIALOG_MANUAL::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialogEx::OnMouseMove(nFlags, point);
}


void DIALOG_MANUAL::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	/*CREVIEWAREADlg *pDlg = (CREVIEWAREADlg*)AfxGetMainWnd();

	// draw line
	if (measure_mode == 1)
	{
		if (click_count == 1 && click_area == 1)
		{
			CClientDC dc(this);

			CRect rt;
			CStatic * pStatic = (CStatic*)GetDlgItem(IDC_PIC_UPPER);
			CDC* pDC = pStatic->GetDC();
			pStatic->GetClientRect(&rt);

			CRgn rgn;
			rgn.CreateRectRgnIndirect(&rt);
			pDC->SelectClipRgn(&rgn);

			pDC->SelectObject(pen_line);
			pDC->SelectObject(&null_brush);

			pDC->MoveTo(first_point.x, first_point.y);
			pDC->LineTo(second_point.x, second_point.y);

			ReleaseDC(pDC);

			///////////////////
			double dist_x = abs((second_point.x - first_point.x) * 4 * 0.55);
			double dist_y = abs((second_point.y - first_point.y) * 4 * 0.55);

			double dist_dia = abs(sqrt((dist_x * dist_x) + (dist_y * dist_y)));

			CString str_line;	// 가로

			str_line.Format(_T("%d_LINE : %.2f㎛"), measure_count, dist_dia);

			str_measure_label.Format(_T("%d_LINE"), measure_count);
			str_measure_value.Format(_T("%.2f㎛"), dist_dia);

			m_list_measure.InsertItem(list_count, str_measure_label);
			m_list_measure.SetItemText(list_count, 1, str_measure_value);
			list_count++;

			dc.SetBkMode(TRANSPARENT);
			dc.SetTextColor(RGB(89, 254, 10));

			if (first_point.x < 400)
				dc.TextOutW(first_point.x + 5, first_point.y, str_line);

			else if (first_point.x >= 400)
				dc.TextOutW(first_point.x - 100, first_point.y, str_line);

			measure_count++;
		}

		else if (click_count == 1 && click_area == 2)
		{
			CClientDC dc(this);

			CRect rt;
			CStatic * pStatic = (CStatic*)GetDlgItem(IDC_PIC_SIDE);
			CDC* pDC = pStatic->GetDC();
			pStatic->GetClientRect(&rt);

			CRgn rgn;
			rgn.CreateRectRgnIndirect(&rt);
			pDC->SelectClipRgn(&rgn);

			pDC->SelectObject(pen_line);
			pDC->SelectObject(&null_brush);

			pDC->MoveTo(first_point.x, first_point.y - 512);
			pDC->LineTo(second_point.x, second_point.y - 512);

			ReleaseDC(pDC);

			///////////////////
			double dist_x = abs((second_point.x - first_point.x) * 4 * 0.55);
			double dist_y = abs((second_point.y - first_point.y) * 4 * 0.55);

			double dist_dia = abs(sqrt((dist_x * dist_x) + (dist_y * dist_y)));

			CString str_line;	// 가로

			str_line.Format(_T("%d_LINE : %.2f㎛"), measure_count, dist_dia);

			str_measure_label.Format(_T("%d_LINE"), measure_count);
			str_measure_value.Format(_T("%.2f㎛"), dist_dia);

			m_list_measure.InsertItem(list_count, str_measure_label);
			m_list_measure.SetItemText(list_count, 1, str_measure_value);
			list_count++;

			dc.SetBkMode(TRANSPARENT);
			dc.SetTextColor(RGB(89, 254, 10));

			if (first_point.x < 400)
			{
				dc.TextOutW(first_point.x + 5, first_point.y, str_line);
			}


			else if (first_point.x >= 400)
			{
				dc.TextOutW(first_point.x - 100, first_point.y, str_line);
			}

			measure_count++;
			////////////
		}
		click_count = 0;
		click_area = 0;

	}

	// draw circle
	else if (measure_mode == 3)
	{
		if (point.x <= 512 && point.y > 0 && point.y <= 512)
		{
			if (click_count == 1 && click_area == 1)
			{
				CClientDC dc(this);

				CRect rt;
				CStatic * pStatic = (CStatic*)GetDlgItem(IDC_PIC_UPPER);
				CDC* pDC = pStatic->GetDC();
				pStatic->GetClientRect(&rt);

				CRgn rgn;
				rgn.CreateRectRgnIndirect(&rt);
				pDC->SelectClipRgn(&rgn);

				pDC->SelectObject(pen_circle);
				pDC->SelectObject(&null_brush);

				int dx, dy;

				double radius;

				dx = (point.x - first_point.x) * (point.x - first_point.x);
				dy = (point.y - first_point.y) * (point.y - first_point.y);

				radius = sqrt((double)(dx + dy));

				CPoint start_point;
				CPoint end_point;

				start_point.x = first_point.x - radius;
				start_point.y = first_point.y - radius;
				end_point.x = first_point.x + radius;
				end_point.y = first_point.y + radius;

				pDC->MoveTo(first_point.x, first_point.y);
				pDC->LineTo(second_point.x, second_point.y);

				pDC->Ellipse(start_point.x, start_point.y, end_point.x, end_point.y);

				ReleaseDC(pDC);

				///////////////////
				double dist_dia = abs(radius * 4 * 0.55);

				CString str_circle;

				str_circle.Format(_T("%d_RADIUS : %.2f㎛"), measure_count, dist_dia);

				str_measure_label.Format(_T("%d_RADIUS"), measure_count);
				str_measure_value.Format(_T("%.2f㎛"), dist_dia);

				m_list_measure.InsertItem(list_count, str_measure_label);
				m_list_measure.SetItemText(list_count, 1, str_measure_value);
				list_count++;

				dc.SetBkMode(TRANSPARENT);
				dc.SetTextColor(RGB(89, 254, 10));
				
				if (first_point.x < 350)
					dc.TextOutW(first_point.x, first_point.y, str_circle);


				else if (first_point.x >= 350)
					dc.TextOutW(first_point.x - 125, first_point.y, str_circle);

				measure_count++;
			}
		}

		else if (point.x <= 512 && point.y > 512 && point.y <= 1024)
		{
			if (click_count == 1 && click_area == 2)
			{
				CClientDC dc(this);

				CRect rt;
				CStatic * pStatic = (CStatic*)GetDlgItem(IDC_PIC_SIDE);
				CDC* pDC = pStatic->GetDC();
				pStatic->GetClientRect(&rt);

				CRgn rgn;
				rgn.CreateRectRgnIndirect(&rt);
				pDC->SelectClipRgn(&rgn);

				pDC->SelectObject(pen_circle);
				pDC->SelectObject(&null_brush);

				int dx, dy;

				double radius;

				dx = (point.x - first_point.x) * (point.x - first_point.x);
				dy = (point.y - first_point.y) * (point.y - first_point.y);

				radius = sqrt((double)(dx + dy));

				CPoint start_point;
				CPoint end_point;

				start_point.x = first_point.x - radius;
				start_point.y = first_point.y - radius - 512;
				end_point.x = first_point.x + radius;
				end_point.y = first_point.y + radius - 512;

				pDC->MoveTo(first_point.x, first_point.y - 512);
				pDC->LineTo(second_point.x, second_point.y - 512);

				pDC->Ellipse(start_point.x, start_point.y, end_point.x, end_point.y);

				ReleaseDC(pDC);

				///////////////////
				double dist_dia = abs(radius * 4 * 0.55);

				CString str_circle;

				str_circle.Format(_T("%d_RADIUS : %.2f㎛"), measure_count, dist_dia);

				str_measure_label.Format(_T("%d_RADIUS"), measure_count);
				str_measure_value.Format(_T("%.2f㎛"), dist_dia);

				m_list_measure.InsertItem(list_count, str_measure_label);
				m_list_measure.SetItemText(list_count, 1, str_measure_value);
				list_count++;

				dc.SetBkMode(TRANSPARENT);
				dc.SetTextColor(RGB(89, 254, 10));

				if (first_point.x < 400)
					dc.TextOutW(first_point.x, first_point.y, str_circle);


				else if (first_point.x >= 400)
					dc.TextOutW(first_point.x - 100, first_point.y, str_circle);
				

				measure_count++;
			}
		}
		click_count = 0;
		click_area = 0;

	}

	// draw rectangle (measure, edge_detect, mark reg)
	// 6 : uppermark, 7 : sidemark
	else
	{
		// upper
		// 2, 4, 5, 6
		if (point.x < 516 && point.y > 0 && point.y < 512)
		{
			if (click_count == 1 && click_area == 1)
			{
				CClientDC dc(this);

				CRect rt;
				CStatic * pStatic = (CStatic*)GetDlgItem(IDC_PIC_UPPER);
				CDC* pDC = pStatic->GetDC();
				pStatic->GetClientRect(&rt);

				CRgn rgn;
				rgn.CreateRectRgnIndirect(&rt);
				pDC->SelectClipRgn(&rgn);

				pDC->SelectObject(pen_rectangle);
				pDC->SelectObject(&null_brush);

				if (measure_mode == 6)
					pDC->SetROP2(R2_NOT);

				pDC->Rectangle(first_point.x - 2, first_point.y, second_point.x - 2, second_point.y);

				ReleaseDC(pDC);

				// draw rectangle
				if (measure_mode == 2)
				{
					// 측정 값
					double dist_x = abs((second_point.x - first_point.x) * 4 * 0.55);
					double dist_y = abs((second_point.y - first_point.y) * 4 * 0.55);

					CString str_ver;	// 가로
					CString str_hor;	// 세로

					str_ver.Format(_T("%d_VER : %.2f㎛"), measure_count, dist_x);
					str_hor.Format(_T("%d_HOR : %.2f㎛"), measure_count, dist_y);

					str_measure_label.Format(_T("%d_VER"), measure_count);
					str_measure_value.Format(_T("%.2f㎛"), dist_x);

					m_list_measure.InsertItem(list_count, str_measure_label);
					m_list_measure.SetItemText(list_count, 1, str_measure_value);
					list_count++;

					str_measure_label.Format(_T("%d_HOR"), measure_count);
					str_measure_value.Format(_T("%.2f㎛"), dist_y);

					m_list_measure.InsertItem(list_count, str_measure_label);
					m_list_measure.SetItemText(list_count, 1, str_measure_value);
					list_count++;

					dc.SetBkMode(TRANSPARENT);
					dc.SetTextColor(RGB(89, 254, 10));

					if (first_point.x < 400)
					{
						if (first_point.y > 10)
						{
							dc.TextOutW(first_point.x + 5, first_point.y - 20, str_ver);
							dc.TextOutW(first_point.x + 5, first_point.y, str_hor);
						}

						else if (first_point.y <= 10)
						{
							dc.TextOutW(first_point.x + 5, first_point.y, str_ver);
							dc.TextOutW(first_point.x + 5, first_point.y + 20, str_hor);
						}
					}

					else if (first_point.x >= 400)
					{
						if (first_point.y > 10)
						{
							dc.TextOutW(first_point.x - 100, first_point.y - 20, str_ver);
							dc.TextOutW(first_point.x - 100, first_point.y, str_hor);
						}

						else if (first_point.y <= 10)
						{
							dc.TextOutW(first_point.x - 100, first_point.y, str_ver);
							dc.TextOutW(first_point.x - 100, first_point.y + 20, str_hor);
						}
					}

					measure_count++;
				}

				// upper mark 이미지를 display
				else if (measure_mode == 6)
				{
					if (second_point.x != first_point.x && second_point.y != first_point.y)
					{
						manual_upper_image = imread("Data\\4. MEASURE\\1. ORIGIN\\UPPER.bmp");

						int rectangle_1_x;
						int rectangle_2_x;
						int rectangle_1_y;
						int rectangle_2_y;

						if (second_point.x > first_point.x)
						{
							rectangle_1_x = first_point.x;
							rectangle_2_x = second_point.x;
						}

						else if (second_point.x < first_point.x)
						{
							rectangle_1_x = second_point.x;
							rectangle_2_x = first_point.x;
						}

						if (second_point.y > first_point.y)
						{
							rectangle_1_y = first_point.y;
							rectangle_2_y = second_point.y;
						}

						else if (second_point.y < first_point.y)
						{
							rectangle_1_y = second_point.y;
							rectangle_2_y = first_point.y;
						}

						int d = rectangle_2_x - rectangle_1_x;
						int n = abs((rectangle_2_x - rectangle_1_x)) % 4;

						if (n != 0)
						{
							for (int i = rectangle_2_x; i > rectangle_2_x - 4; i--)
							{
								if ((i - rectangle_1_x) % 4 == 0)
									rectangle_2_x = i;
							}
						}

						Rect mark_roi(rectangle_1_x * 2, rectangle_1_y * 2,
							(rectangle_2_x - rectangle_1_x) * 2, (rectangle_2_y - rectangle_1_y) * 2);

						manual_upper_mark = manual_upper_image(mark_roi);

						markInfo = (BITMAPINFO*)markBuf;
						markInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
						markInfo->bmiHeader.biWidth = manual_upper_mark.cols;
						markInfo->bmiHeader.biHeight = -(manual_upper_mark.rows);
						markInfo->bmiHeader.biBitCount = 24;
						markInfo->bmiHeader.biPlanes = 1;
						markInfo->bmiHeader.biCompression = BI_RGB;
						markInfo->bmiHeader.biSizeImage = 0;
						markInfo->bmiHeader.biXPelsPerMeter = 0;
						markInfo->bmiHeader.biYPelsPerMeter = 0;
						markInfo->bmiHeader.biClrUsed = 0;
						markInfo->bmiHeader.biClrImportant = 0;

						imwrite("mark_u.bmp", manual_upper_mark);
						manual_upper_mark = imread("mark_u.bmp");

						StretchDIBits(hdc_mark_upper, 0, 0, 100, 100, 0, 0, manual_upper_mark.cols, manual_upper_mark.rows, manual_upper_mark.data, markInfo, DIB_RGB_COLORS, SRCCOPY);

						GetDlgItem(IDC_BTN_UPPER_MARK_SAVE)->EnableWindow(TRUE);
					}
				}
				click_count = 0;
				click_area = 0;

			}
		}


		else if (point.x < 512 && point.y > 512 && point.y < 1024)
		{
			if (click_count == 1 && click_area == 2)
			{
				CClientDC dc(this);

				CRect rt;
				CStatic * pStatic = (CStatic*)GetDlgItem(IDC_PIC_SIDE);
				CDC* pDC = pStatic->GetDC();
				pStatic->GetClientRect(&rt);

				CRgn rgn;
				rgn.CreateRectRgnIndirect(&rt);
				pDC->SelectClipRgn(&rgn);

				pDC->SelectObject(pen_rectangle);
				pDC->SelectObject(&null_brush);

				if (measure_mode == 7)
					pDC->SetROP2(R2_NOT);

				pDC->Rectangle(first_point.x, first_point.y - 512, second_point.x, second_point.y - 512);

				ReleaseDC(pDC);

				if (measure_mode != 7)
				{
					// 측정 값
					double dist_x = abs((second_point.x - first_point.x) * 4 * 0.55);
					double dist_y = abs((second_point.y - first_point.y) * 4 * 0.55);

					CString str_ver;	// 가로
					CString str_hor;	// 세로

					str_ver.Format(_T("%d_VER : %.2f㎛"), measure_count, dist_x);
					str_hor.Format(_T("%d_HOR : %.2f㎛"), measure_count, dist_y);

					str_measure_label.Format(_T("%d_VER"), measure_count);
					str_measure_value.Format(_T("%.2f㎛"), dist_x);

					m_list_measure.InsertItem(list_count, str_measure_label);
					m_list_measure.SetItemText(list_count, 1, str_measure_value);
					list_count++;

					str_measure_label.Format(_T("%d_HOR"), measure_count);
					str_measure_value.Format(_T("%.2f㎛"), dist_y);

					m_list_measure.InsertItem(list_count, str_measure_label);
					m_list_measure.SetItemText(list_count, 1, str_measure_value);
					list_count++;

					dc.SetBkMode(TRANSPARENT);
					dc.SetTextColor(RGB(89, 254, 10));

					if (first_point.x < 400)
					{
						if (first_point.y > 522)
						{
							dc.TextOutW(first_point.x + 5, first_point.y - 20, str_ver);
							dc.TextOutW(first_point.x + 5, first_point.y, str_hor);
						}

						else if (first_point.y <= 522)
						{
							dc.TextOutW(first_point.x + 5, first_point.y, str_ver);
							dc.TextOutW(first_point.x + 5, first_point.y + 20, str_hor);
						}
					}

					else if (first_point.x >= 400)
					{
						if (first_point.y > 522)
						{
							dc.TextOutW(first_point.x - 100, first_point.y - 20, str_ver);
							dc.TextOutW(first_point.x - 100, first_point.y, str_hor);
						}

						else if (first_point.y <= 522)
						{
							dc.TextOutW(first_point.x - 100, first_point.y, str_ver);
							dc.TextOutW(first_point.x - 100, first_point.y + 20, str_hor);
						}
					}

					measure_count++;
				}

				// side mark 이미지를 display
				else if (measure_mode == 7)
				{
					if (second_point.x != first_point.x && second_point.y != first_point.y)
					{
						manual_side_image = imread("Data\\4. MEASURE\\1. ORIGIN\\SIDE.bmp");

						int rectangle_1_x;
						int rectangle_2_x;
						int rectangle_1_y;
						int rectangle_2_y;


						if (second_point.x > first_point.x)
						{
							rectangle_1_x = first_point.x;
							rectangle_2_x = second_point.x;
						}

						else if (second_point.x < first_point.x)
						{
							rectangle_1_x = second_point.x;
							rectangle_2_x = first_point.x;
						}

						if (second_point.y > first_point.y)
						{
							rectangle_1_y = first_point.y;
							rectangle_2_y = second_point.y;
						}

						else if (second_point.y < first_point.y)
						{
							rectangle_1_y = second_point.y;
							rectangle_2_y = first_point.y;
						}

						int d = rectangle_2_x - rectangle_1_x;
						int n = abs((rectangle_2_x - rectangle_1_x)) % 4;

						if (n != 0)
						{
							for (int i = rectangle_2_x; i > rectangle_2_x - 4; i--)
							{
								if ((i - rectangle_1_x) % 4 == 0)
									rectangle_2_x = i;
							}
						}

						Rect mark_roi(rectangle_1_x * 2, (rectangle_1_y - 512) * 2,
							(rectangle_2_x - rectangle_1_x) * 2, (rectangle_2_y - rectangle_1_y) * 2);

						manual_side_mark = manual_side_image(mark_roi);

						markInfo = (BITMAPINFO*)markBuf;
						markInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
						markInfo->bmiHeader.biWidth = manual_side_mark.cols;
						markInfo->bmiHeader.biHeight = -(manual_side_mark.rows);
						markInfo->bmiHeader.biBitCount = 24;
						markInfo->bmiHeader.biPlanes = 1;
						markInfo->bmiHeader.biCompression = BI_RGB;
						markInfo->bmiHeader.biSizeImage = 0;
						markInfo->bmiHeader.biXPelsPerMeter = 0;
						markInfo->bmiHeader.biYPelsPerMeter = 0;
						markInfo->bmiHeader.biClrUsed = 0;
						markInfo->bmiHeader.biClrImportant = 0;

						imwrite("mark_s.bmp", manual_side_mark);
						manual_side_mark = imread("mark_s.bmp");

						StretchDIBits(hdc_mark_side, 0, 0, 100, 100, 0, 0, manual_side_mark.cols, manual_side_mark.rows, manual_side_mark.data, markInfo, DIB_RGB_COLORS, SRCCOPY);
						GetDlgItem(IDC_BTN_SIDE_MARK_SAVE)->EnableWindow(TRUE);
					}
				}

				click_count = 0;
				click_area = 0;
			}
		}
	}
	ClipCursor(NULL);
	*/
	CDialogEx::OnLButtonUp(nFlags, point);
}


void DIALOG_MANUAL::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	if (nIDEvent == 1)
	{
		POINT mouse;

		GetCursorPos(&mouse);

		int mouse_x_pos;
		int mouse_y_pos;

		mouse_x_pos = mouse.x;
		mouse_y_pos = mouse.y;

		if (mouse_x_pos > 1 && mouse_x_pos <= 516 && mouse_y_pos > 50 && mouse_y_pos <= 562)
		{
			CString x_pos;
			CString y_pos;

			x_pos.Format(_T("%d"), (mouse_x_pos - 3) * 4);
			y_pos.Format(_T("%d"), (mouse_y_pos - 50) * 4);

			GetDlgItem(IDC_STATIC_UPPER_X_POS)->SetWindowTextW(x_pos);
			GetDlgItem(IDC_STATIC_UPPER_Y_POS)->SetWindowTextW(y_pos);
		}

		if (mouse_x_pos <= 512 && mouse_y_pos > 562 && mouse_y_pos <= 1074)
		{
			CString x_pos;
			CString y_pos;

			x_pos.Format(_T("%d"), mouse_x_pos * 4);
			y_pos.Format(_T("%d"), (mouse_y_pos - 562) * 4);

			GetDlgItem(IDC_STATIC_SIDE_X_POS)->SetWindowTextW(x_pos);
			GetDlgItem(IDC_STATIC_SIDE_Y_POS)->SetWindowTextW(y_pos);
		}

		// 900, 40, 512, 512
		if (mouse_x_pos > 897 && mouse_x_pos <= 1409 && mouse_y_pos > 90 && mouse_y_pos <= 602)
		{
			CString x_pos;
			CString y_pos;

			x_pos.Format(_T("%d"), (mouse_x_pos - 897) * 4);
			y_pos.Format(_T("%d"), (mouse_y_pos - 90) * 4);

			GetDlgItem(IDC_STATIC_MANUAL_X_POS)->SetWindowTextW(x_pos);
			GetDlgItem(IDC_STATIC_MANUAL_Y_POS)->SetWindowTextW(y_pos);
		}
	}

	CDialogEx::OnTimer(nIDEvent);
}


void DIALOG_MANUAL::OnBnClickedBtnUpperMarkReg()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	measure_mode = 6;
}


void DIALOG_MANUAL::OnBnClickedBtnUpperMarkSave()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	if (m_cmb_upper_mark.GetCurSel() == 0)
	{
		imwrite("Data\\1. Align\\1. REG\\upper_prealign.bmp", dlg_manual_upper->manual_upper_mark);
	}
	else if (m_cmb_upper_mark.GetCurSel() == 1)
	{
		imwrite("Data\\1. Align\\1. REG\\upper_tabalign.bmp", dlg_manual_upper->manual_upper_mark);
	}
	else if (m_cmb_upper_mark.GetCurSel() == 2)
	{
		imwrite("Data\\1. Align\\1. REG\\copper.bmp", dlg_manual_upper->manual_upper_mark);
	}
}

void DIALOG_MANUAL::OnBnClickedBtnSideMarkReg()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	measure_mode = 7;
}


void DIALOG_MANUAL::OnBnClickedBtnSideMarkSave()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_cmb_side_mark.GetCurSel() == 0)
	{
		imwrite("Data\\1. Align\\1. REG\\side_mark_1.bmp", dlg_manual_side->manual_side_mark);
	}
	else if (m_cmb_side_mark.GetCurSel() == 1)
	{
		imwrite("Data\\1. Align\\1. REG\\side_mark_2.bmp", dlg_manual_side->manual_side_mark);
	}
	else if (m_cmb_side_mark.GetCurSel() == 2)
	{
		imwrite("Data\\1. Align\\1. REG\\side_mark_3.bmp", dlg_manual_side->manual_side_mark);
	}
}


void DIALOG_MANUAL::OnBnClickedBtnMorp()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str_open;
	CString str_close;

	m_edit_morp_open.GetWindowTextW(str_open);
	m_edit_morp_close.GetWindowTextW(str_close);

	int val_open;
	int val_close;

	val_open = _ttoi(str_open);
	val_close = _ttoi(str_close);

	Mat element_open(val_open, val_open, CV_8U, cv::Scalar(1));
	Mat element_close(val_close, val_close, CV_8U, cv::Scalar(1));

	morphologyEx(focus_image, morp_image, cv::MORPH_CLOSE, element_open);
	morphologyEx(morp_image, morp_image, cv::MORPH_OPEN, element_close);

	StretchDIBits(hdc_camera_focus, 0, 0, 512, 512, 0, 0, morp_image.cols, morp_image.rows,
		morp_image.data, focusInfo, DIB_RGB_COLORS, SRCCOPY);

	GetDlgItem(IDC_BTN_BINARY)->EnableWindow(TRUE);
}


void DIALOG_MANUAL::OnBnClickedBtnBinary()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;

	m_edit_binary.GetWindowTextW(str);

	int val;

	val = _ttoi(str);

	threshold(morp_image, binary_image, val, 255, THRESH_BINARY);

	CString str_roi_max;
	int val_roi_max;

	m_edit_test_roi_max.GetWindowTextW(str_roi_max);
	val_roi_max = _ttoi(str_roi_max);

	for (int i = 0; i < 6144; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			binary_image.at<uchar>(val_roi_max + j, i) = 0;
		}
	}

	StretchDIBits(hdc_camera_focus, 0, 0, 512, 512, 0, 0, binary_image.cols, binary_image.rows,
		binary_image.data, focusInfo, DIB_RGB_COLORS, SRCCOPY);

	GetDlgItem(IDC_BTN_CONTOUR)->EnableWindow(TRUE);
}


void DIALOG_MANUAL::OnBnClickedBtnContour()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str_roi_min;
	CString str_roi_max;

	int val_roi_min;
	int val_roi_max;

	m_edit_test_roi_min.GetWindowTextW(str_roi_min);
	m_edit_test_roi_max.GetWindowTextW(str_roi_max);

	val_roi_min = _ttoi(str_roi_min);
	val_roi_max = _ttoi(str_roi_max);
	
	CString str_canny;

	Canny(binary_image, canny_image, 100, 300, 3);

	Mat Image_clone;
	Image_clone = focus_image.clone();

	CString str_contour;

	m_edit_contour.GetWindowTextW(str_contour);

	int val_contour;

	val_contour = _ttoi(str_contour);

	vector<vector<Point> > contours;
	vector<Vec4i>	hierarchy;

	findContours(canny_image, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point());

	vector<vector<Point>> contours_poly_u(contours.size());
	vector<Rect> boundRect_u(contours.size());

	vector<Rect> boundRect_u_detect(contours.size());

	for (int i = 0; i < contours.size(); i++)
	{
		approxPolyDP(Mat(contours[i]), contours_poly_u[i], 1, true);
		boundRect_u[i] = boundingRect(Mat(contours_poly_u[i]));
	}

	int contours_count = 0;

	for (int i = 0; i < contours.size(); i++)
	{
		int num = boundRect_u[i].area();

		if (boundRect_u[i].area() >= val_contour)
		{
			if (boundRect_u[i].y > val_roi_min && boundRect_u[i].y< val_roi_max)
			{
				drawContours(Image_clone, contours, i, Scalar(0, 255, 0), 4, 8, hierarchy, 0, Point());
			}
		}
	}

	StretchDIBits(hdc_camera_focus, 0, 0, 512, 512, 0, 0, Image_clone.cols, Image_clone.rows,
		Image_clone.data, focusInfo, DIB_RGB_COLORS, SRCCOPY);

	GetDlgItem(IDC_BTN_FOCUS_RESET)->EnableWindow(TRUE);
}


void DIALOG_MANUAL::OnBnClickedBtnFocusReset()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nPos;

	nPos = m_cmb_camera.GetCurSel();

	if (nPos == 0)
	{
		focus_image = imread("Data\\4. MEASURE\\1. ORIGIN\\UPPER.bmp");
		//focus_image = imread("upper.bmp");

		focusInfo = (BITMAPINFO*)focusBuf;
		focusInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		focusInfo->bmiHeader.biWidth = focus_image.cols;
		focusInfo->bmiHeader.biHeight = -(focus_image.rows);
		focusInfo->bmiHeader.biBitCount = 24;
		focusInfo->bmiHeader.biPlanes = 1;
		focusInfo->bmiHeader.biCompression = BI_RGB;
		focusInfo->bmiHeader.biSizeImage = 0;
		focusInfo->bmiHeader.biXPelsPerMeter = 0;
		focusInfo->bmiHeader.biYPelsPerMeter = 0;
		focusInfo->bmiHeader.biClrUsed = 0;
		focusInfo->bmiHeader.biClrImportant = 0;


		StretchDIBits(hdc_camera_focus, 0, 0, 512, 512, 0, 0, focus_image.cols, focus_image.rows,
			focus_image.data, focusInfo, DIB_RGB_COLORS, SRCCOPY);
	}

	else if (nPos == 1)
	{
		focus_image = imread("Data\\4. MEASURE\\1. ORIGIN\\SIDE.bmp");
		//focus_image = imread("side.bmp");

		focusInfo = (BITMAPINFO*)focusBuf;
		focusInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		focusInfo->bmiHeader.biWidth = focus_image.cols;
		focusInfo->bmiHeader.biHeight = -(focus_image.rows);
		focusInfo->bmiHeader.biBitCount = 24;
		focusInfo->bmiHeader.biPlanes = 1;
		focusInfo->bmiHeader.biCompression = BI_RGB;
		focusInfo->bmiHeader.biSizeImage = 0;
		focusInfo->bmiHeader.biXPelsPerMeter = 0;
		focusInfo->bmiHeader.biYPelsPerMeter = 0;
		focusInfo->bmiHeader.biClrUsed = 0;
		focusInfo->bmiHeader.biClrImportant = 0;

		StretchDIBits(hdc_camera_focus, 0, 0, 512, 512, 0, 0, focus_image.cols, focus_image.rows,
			focus_image.data, focusInfo, DIB_RGB_COLORS, SRCCOPY);
	}

	GetDlgItem(IDC_BTN_BINARY)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_CONTOUR)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_FOCUS_RESET)->EnableWindow(FALSE);

}


void DIALOG_MANUAL::OnCbnSelchangeCmbMagni()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CREVIEWAREADlg *pDlg = (CREVIEWAREADlg*)AfxGetMainWnd();

	int n = m_cmb_magni.GetCurSel();

	// x1
	if (n == 0)
	{
		MdispZoom(pDlg->dlg_auto->area_cam.m_MilDisplay_Upper, 0.25, 0.25);
		MdispZoom(pDlg->dlg_auto->area_cam.m_MilDisplay_Side, 0.25, 0.25);
		
		dlg_manual_upper->GetDlgItem(IDC_PIC_MANUAL_UPPER)->MoveWindow(0, 0, 512, 512);
		dlg_manual_side->GetDlgItem(IDC_PIC_MANUAL_SIDE)->MoveWindow(0, 0, 512, 512);

		dlg_manual_upper->width_value = 512;
		dlg_manual_upper->height_value = 512;

		dlg_manual_side->width_value = 512;
		dlg_manual_side->height_value = 512;

		dlg_manual_upper->scrollpos = 0;
		dlg_manual_upper->VScrollPos_ = 0;
		dlg_manual_upper->HScrollPos_ = 0;

		dlg_manual_side->scrollpos = 0;
		dlg_manual_side->VScrollPos_ = 0;
		dlg_manual_side->HScrollPos_ = 0;

		GetDlgItem(IDC_STATIC_UPPER_MAGNI)->SetWindowTextW(_T("1배"));
		GetDlgItem(IDC_STATIC_SIDE_MAGNI)->SetWindowTextW(_T("1배"));
	}

	// x2
	else if (n == 1)
	{
		MdispZoom(pDlg->dlg_auto->area_cam.m_MilDisplay_Upper, 0.5, 0.5);
		MdispZoom(pDlg->dlg_auto->area_cam.m_MilDisplay_Side, 0.5, 0.5);

		dlg_manual_upper->GetDlgItem(IDC_PIC_MANUAL_UPPER)->MoveWindow(0, 0, 1024, 1024);
		dlg_manual_side->GetDlgItem(IDC_PIC_MANUAL_SIDE)->MoveWindow(0, 0, 1024, 1024);
		
		dlg_manual_upper->width_value = 1024;
		dlg_manual_upper->height_value = 1024;

		dlg_manual_side->width_value = 1024;
		dlg_manual_side->height_value = 1024;

		dlg_manual_upper->scrollpos = 0;
		dlg_manual_upper->VScrollPos_ = 0;
		dlg_manual_upper->HScrollPos_ = 0;

		dlg_manual_side->scrollpos = 0;
		dlg_manual_side->VScrollPos_ = 0;
		dlg_manual_side->HScrollPos_ = 0;

		GetDlgItem(IDC_STATIC_UPPER_MAGNI)->SetWindowTextW(_T("2배"));
		GetDlgItem(IDC_STATIC_SIDE_MAGNI)->SetWindowTextW(_T("2배"));
	}

	// x4
	/*else if (n == 2)
	{
		MdispZoom(pDlg->dlg_auto->area_cam.m_MilDisplay_Upper, 1.0, 1.0);
		MdispZoom(pDlg->dlg_auto->area_cam.m_MilDisplay_Side, 1.0, 1.0);

		dlg_manual_upper->GetDlgItem(IDC_PIC_MANUAL_UPPER)->MoveWindow(0, 0, 2048, 2048);
		dlg_manual_side->GetDlgItem(IDC_PIC_MANUAL_SIDE)->MoveWindow(0, 0, 2048, 2048);

		dlg_manual_upper->width_value = 2048;
		dlg_manual_upper->height_value = 2048;

		dlg_manual_side->width_value = 2048;
		dlg_manual_side->height_value = 2048;

		GetDlgItem(IDC_STATIC_UPPER_MAGNI)->SetWindowTextW(_T("4배"));
		GetDlgItem(IDC_STATIC_SIDE_MAGNI)->SetWindowTextW(_T("4배"));
	}
	*/
	dlg_manual_upper->click_magni();
	dlg_manual_side->click_magni();
}

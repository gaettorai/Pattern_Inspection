// DIALOG_SETTING_PARAM.cpp: 구현 파일
//

#include "stdafx.h"
#include "REVIEW_AREA.h"
#include "DIALOG_SETTING_PARAM.h"
#include "afxdialogex.h"


// DIALOG_SETTING_PARAM 대화 상자

IMPLEMENT_DYNAMIC(DIALOG_SETTING_PARAM, CDialogEx)

DIALOG_SETTING_PARAM::DIALOG_SETTING_PARAM(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SETTING_PARAM, pParent)
{

}

DIALOG_SETTING_PARAM::~DIALOG_SETTING_PARAM()
{
}

void DIALOG_SETTING_PARAM::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_EDIT_PREALIGN_MATCHING, m_edit_prealign_matching);
	DDX_Control(pDX, IDC_EDIT_TABALIGN_MATCHING, m_edit_tabalign_matching);
	DDX_Control(pDX, IDC_EDIT_PREALIGN_RANGE, m_edit_prealign_range);
	DDX_Control(pDX, IDC_EDIT_WIDTH, m_edit_width);
	DDX_Control(pDX, IDC_EDIT_HEIGHT, m_edit_height);
	DDX_Control(pDX, IDC_EDIT_WIDTH_RANGE, m_edit_width_range);
	DDX_Control(pDX, IDC_EDIT_HEIGHT_RANGE, m_edit_height_range);
	DDX_Control(pDX, IDC_EDIT_MA_X_RANGE, m_edit_ma_x_range);
	DDX_Control(pDX, IDC_EDIT_MA_Y, m_edit_ma_y);
	DDX_Control(pDX, IDC_EDIT_MA_Y_RANGE, m_edit_ma_y_range);
	DDX_Control(pDX, IDC_EDIT_OFFSET, m_edit_offset);
	DDX_Control(pDX, IDC_EDIT_UPPER_ALIGN_OFFSET, m_edit_upper_align_offset);
	DDX_Control(pDX, IDC_EDIT_SIDE_ALIGN_OFFSET, m_edit_side_align_offset);
	DDX_Control(pDX, IDC_EDIT_SPACE, m_edit_space);
}


BEGIN_MESSAGE_MAP(DIALOG_SETTING_PARAM, CDialogEx)
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// DIALOG_SETTING_PARAM 메시지 처리기


HBRUSH DIALOG_SETTING_PARAM::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}


BOOL DIALOG_SETTING_PARAM::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	return CDialogEx::OnEraseBkgnd(pDC);
}


BOOL DIALOG_SETTING_PARAM::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	int static_widht = 100;
	int static_height = 30;

	int edit_height = 30;

	int y_gap = 30;

	int y_start = 20;

	GetDlgItem(IDC_STATIC_PREALIGN_MATCHING)->MoveWindow(10, y_start, 80, edit_height);
	GetDlgItem(IDC_STATIC_PREALIGN_RANGE)->MoveWindow(10, y_start + y_gap * 1, 80, edit_height);

	GetDlgItem(IDC_STATIC_UPPER_ALIGN_OFFSET)->MoveWindow(10, y_start + y_gap * 2, 80, edit_height);
	GetDlgItem(IDC_STATIC_WIDTH)->MoveWindow(10, y_start + y_gap * 3, 80, edit_height);
	GetDlgItem(IDC_STATIC_HEIGHT)->MoveWindow(10, y_start + y_gap * 4, 80, edit_height);
	GetDlgItem(IDC_STATIC_SPACE)->MoveWindow(10, y_start + y_gap * 5, 80, edit_height);
	GetDlgItem(IDC_STATIC_MA_Y)->MoveWindow(10, y_start + y_gap * 6, 80, edit_height);
	GetDlgItem(IDC_STATIC_OFFSET)->MoveWindow(10, y_start + y_gap * 7, 80, edit_height);

	GetDlgItem(IDC_STATIC_TABALIGN_MATCHING)->MoveWindow(190, y_start, 80, edit_height);
	GetDlgItem(IDC_STATIC_SIDE_ALIGN_OFFSET)->MoveWindow(190, y_start + y_gap * 2, 80, edit_height);
	GetDlgItem(IDC_STATIC_WIDTH_RANGE)->MoveWindow(190, y_start + y_gap * 3, 80, edit_height);
	GetDlgItem(IDC_STATIC_HEIGHT_RANGE)->MoveWindow(190, y_start + y_gap * 4, 80, edit_height);
	GetDlgItem(IDC_STATIC_MA_Y_RANGE)->MoveWindow(190, y_start + y_gap * 6, 80, edit_height);
	GetDlgItem(IDC_STATIC_MA_X_RANGE)->MoveWindow(190, y_start + y_gap * 7, 80, edit_height);
	

	GetDlgItem(IDC_EDIT_PREALIGN_MATCHING)->MoveWindow(90, y_start, 80, edit_height);
	GetDlgItem(IDC_EDIT_PREALIGN_RANGE)->MoveWindow(90, y_start + y_gap * 1, 80, edit_height);
	GetDlgItem(IDC_EDIT_UPPER_ALIGN_OFFSET)->MoveWindow(90, y_start + y_gap * 2, 80, edit_height);
	GetDlgItem(IDC_EDIT_WIDTH)->MoveWindow(90, y_start + y_gap * 3, 80, edit_height);
	GetDlgItem(IDC_EDIT_HEIGHT)->MoveWindow(90, y_start + y_gap * 4, 80, edit_height);
	GetDlgItem(IDC_EDIT_SPACE)->MoveWindow(90, y_start + y_gap * 5, 80, edit_height);
	GetDlgItem(IDC_EDIT_MA_Y)->MoveWindow(90, y_start + y_gap * 6, 80, edit_height);
	GetDlgItem(IDC_EDIT_OFFSET)->MoveWindow(90, y_start + y_gap * 7, 80, edit_height);

	GetDlgItem(IDC_EDIT_TABALIGN_MATCHING)->MoveWindow(270, y_start, 80, edit_height);
	GetDlgItem(IDC_EDIT_SIDE_ALIGN_OFFSET)->MoveWindow(270, y_start + y_gap * 2, 80, edit_height);
	GetDlgItem(IDC_EDIT_WIDTH_RANGE)->MoveWindow(270, y_start + y_gap * 3, 80, edit_height);
	GetDlgItem(IDC_EDIT_HEIGHT_RANGE)->MoveWindow(270, y_start + y_gap * 4, 80, edit_height);
	GetDlgItem(IDC_EDIT_MA_Y_RANGE)->MoveWindow(270, y_start + y_gap * 6, 80, edit_height);
	GetDlgItem(IDC_EDIT_MA_X_RANGE)->MoveWindow(270, y_start + y_gap * 7, 80, edit_height);
	

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


BOOL DIALOG_SETTING_PARAM::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	return CDialogEx::PreTranslateMessage(pMsg);
}

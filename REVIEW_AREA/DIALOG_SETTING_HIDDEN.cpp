// DIALOG_SETTING_HIDDEN.cpp: 구현 파일
//

#include "stdafx.h"
#include "REVIEW_AREA.h"
#include "DIALOG_SETTING_HIDDEN.h"
#include "afxdialogex.h"


// DIALOG_SETTING_HIDDEN 대화 상자

IMPLEMENT_DYNAMIC(DIALOG_SETTING_HIDDEN, CDialogEx)

DIALOG_SETTING_HIDDEN::DIALOG_SETTING_HIDDEN(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SETTING_HIDDEN, pParent)
{

}

DIALOG_SETTING_HIDDEN::~DIALOG_SETTING_HIDDEN()
{
}

void DIALOG_SETTING_HIDDEN::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_EDIT_BINARY_UPPER, m_edit_binary_upper);
	DDX_Control(pDX, IDC_EDIT_BINARY_SIDE, m_edit_binary_side);
	DDX_Control(pDX, IDC_EDIT_BINARY_EDGE, m_edit_binary_edge);
	DDX_Control(pDX, IDC_EDIT_MORPHOLOGY_OPEN, m_edit_morphology_open);
	DDX_Control(pDX, IDC_EDIT_MORPHOLOGY_CLOSE, m_edit_morphology_close);
	DDX_Control(pDX, IDC_EDIT_UPPER_CONTOUR, m_edit_upper_contour);
	DDX_Control(pDX, IDC_EDIT_SIDE_CONTOUR, m_edit_side_contour);
	DDX_Control(pDX, IDC_EDIT_GANTRY_LIMIT_MIN, m_edit_gantry_limit_min);
	DDX_Control(pDX, IDC_EDIT_GANTRY_LIMIT_MAX, m_edit_gantry_limit_max);
	DDX_Control(pDX, IDC_EDIT_AF_LIMIT, m_edit_af_limit);
}


BEGIN_MESSAGE_MAP(DIALOG_SETTING_HIDDEN, CDialogEx)
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// DIALOG_SETTING_HIDDEN 메시지 처리기


HBRUSH DIALOG_SETTING_HIDDEN::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.

	return hbr;
}


BOOL DIALOG_SETTING_HIDDEN::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	return CDialogEx::OnEraseBkgnd(pDC);
}


BOOL DIALOG_SETTING_HIDDEN::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	int static_widht = 100;
	int static_height = 30;

	int edit_height = 30;

	int y_gap = 30;

	int y_start = -10;


	GetDlgItem(IDC_STATIC_BINARY_UPPER)->MoveWindow(10, y_start + y_gap * 1, 80, edit_height);
	GetDlgItem(IDC_STATIC_BINARY_SIDE)->MoveWindow(10, y_start + y_gap * 2, 80, edit_height);
	GetDlgItem(IDC_STATIC_BINARY_EDGE)->MoveWindow(10, y_start + y_gap * 3, 80, edit_height);

	GetDlgItem(IDC_STATIC_MORPHOLOGY_OPEN)->MoveWindow(190, y_start + y_gap * 1, 80, edit_height);
	GetDlgItem(IDC_STATIC_MORPHOLOGY_CLOSE)->MoveWindow(190, y_start + y_gap * 2, 80, edit_height);
	GetDlgItem(IDC_STATIC_UPPER_CONTOUR)->MoveWindow(190, y_start + y_gap * 4, 80, edit_height);
	GetDlgItem(IDC_STATIC_SIDE_CONTOUR)->MoveWindow(190, y_start + y_gap * 5, 80, edit_height);

	GetDlgItem(IDC_EDIT_BINARY_UPPER)->MoveWindow(90, y_start + y_gap * 1, 80, edit_height);
	GetDlgItem(IDC_EDIT_BINARY_SIDE)->MoveWindow(90, y_start + y_gap * 2, 80, edit_height);
	GetDlgItem(IDC_EDIT_BINARY_EDGE)->MoveWindow(90, y_start + y_gap * 3, 80, edit_height);

	GetDlgItem(IDC_EDIT_MORPHOLOGY_OPEN)->MoveWindow(270, y_start + y_gap * 1, 80, edit_height);
	GetDlgItem(IDC_EDIT_MORPHOLOGY_CLOSE)->MoveWindow(270, y_start + y_gap * 2, 80, edit_height);
	GetDlgItem(IDC_EDIT_UPPER_CONTOUR)->MoveWindow(270, y_start + y_gap * 4, 80, edit_height);
	GetDlgItem(IDC_EDIT_SIDE_CONTOUR)->MoveWindow(270, y_start + y_gap * 5, 80, edit_height);


	GetDlgItem(IDC_STATIC_GANTRY_LIMIT_MIN)->MoveWindow(10, y_start + y_gap * 5, 80, edit_height);
	GetDlgItem(IDC_STATIC_GANTRY_LIMIT_MAX)->MoveWindow(10, y_start + y_gap * 6, 80, edit_height);
	GetDlgItem(IDC_STATIC_AF_LIMIT)->MoveWindow(10, y_start + y_gap * 7, 80, edit_height);

	GetDlgItem(IDC_EDIT_GANTRY_LIMIT_MIN)->MoveWindow(90, y_start + y_gap * 5, 80, edit_height);
	GetDlgItem(IDC_EDIT_GANTRY_LIMIT_MAX)->MoveWindow(90, y_start + y_gap * 6, 80, edit_height);
	GetDlgItem(IDC_EDIT_AF_LIMIT)->MoveWindow(90, y_start + y_gap * 7, 80, edit_height);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


BOOL DIALOG_SETTING_HIDDEN::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	return CDialogEx::PreTranslateMessage(pMsg);
}

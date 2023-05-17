// DIALOG_SETTING_INFO.cpp: 구현 파일
//

#include "stdafx.h"
#include "REVIEW_AREA.h"
#include "DIALOG_SETTING_INFO.h"
#include "afxdialogex.h"


// DIALOG_SETTING_INFO 대화 상자

IMPLEMENT_DYNAMIC(DIALOG_SETTING_INFO, CDialogEx)

DIALOG_SETTING_INFO::DIALOG_SETTING_INFO(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SETTING_INFO, pParent)
{

}

DIALOG_SETTING_INFO::~DIALOG_SETTING_INFO()
{
}

void DIALOG_SETTING_INFO::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_EDIT_TAB_COUNT, m_edit_tab_count);
	DDX_Control(pDX, IDC_EDIT_TAB_POINT, m_edit_tab_point);
	DDX_Control(pDX, IDC_EDIT_TAB_DIST, m_edit_tab_dist);
	DDX_Control(pDX, IDC_EDIT_TAB_INTERVAL, m_edit_tab_interval);
	DDX_Control(pDX, IDC_EDIT_UPPER_ROI_MIN, m_edit_upper_roi_min);
	DDX_Control(pDX, IDC_EDIT_UPPER_ROI_MAX, m_edit_upper_roi_max);
	DDX_Control(pDX, IDC_EDIT_SIDE_ROI_MIN, m_edit_side_roi_min);
	DDX_Control(pDX, IDC_EDIT_SIDE_ROI_MAX, m_edit_side_roi_max);
	DDX_Control(pDX, IDC_EDIT_EDGE_ROI_MIN, m_edit_edge_roi_min);
	DDX_Control(pDX, IDC_EDIT_EDGE_ROI_MAX, m_edit_edge_roi_max);
}


BEGIN_MESSAGE_MAP(DIALOG_SETTING_INFO, CDialogEx)
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// DIALOG_SETTING_INFO 메시지 처리기


HBRUSH DIALOG_SETTING_INFO::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}


BOOL DIALOG_SETTING_INFO::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	return CDialogEx::OnEraseBkgnd(pDC);
}


BOOL DIALOG_SETTING_INFO::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	int static_widht = 100;
	int static_height = 30;

	int edit_height = 30;

	int y_gap = 30;

	int y_start = 20;


	GetDlgItem(IDC_STATIC_ROI_MIN)->MoveWindow(10, y_start + y_gap * 1, 100, edit_height);
	GetDlgItem(IDC_STATIC_ROI_MAX)->MoveWindow(10, y_start + y_gap * 2, 100, edit_height);

	GetDlgItem(IDC_STATIC_UPPER)->MoveWindow(110, y_start, 80, 30);
	GetDlgItem(IDC_STATIC_SIDE)->MoveWindow(190, y_start, 80, 30);
	GetDlgItem(IDC_STATIC_EDGE)->MoveWindow(270, y_start, 80, 30);
	GetDlgItem(IDC_EDIT_UPPER_ROI_MIN)->MoveWindow(110, y_start + y_gap * 1, 80, edit_height);
	GetDlgItem(IDC_EDIT_UPPER_ROI_MAX)->MoveWindow(110, y_start + y_gap * 2, 80, edit_height);
	GetDlgItem(IDC_EDIT_SIDE_ROI_MIN)->MoveWindow(190, y_start + y_gap * 1, 80, edit_height);
	GetDlgItem(IDC_EDIT_SIDE_ROI_MAX)->MoveWindow(190, y_start + y_gap * 2, 80, edit_height);
	GetDlgItem(IDC_EDIT_EDGE_ROI_MIN)->MoveWindow(270, y_start + y_gap * 1, 80, edit_height);
	GetDlgItem(IDC_EDIT_EDGE_ROI_MAX)->MoveWindow(270, y_start + y_gap * 2, 80, edit_height);

	GetDlgItem(IDC_STATIC_TAB_COUNT)->MoveWindow(190, y_start + y_gap * 4, 80, edit_height);
	GetDlgItem(IDC_STATIC_TAB_POINT)->MoveWindow(190, y_start + y_gap * 5, 80, edit_height);
	GetDlgItem(IDC_STATIC_TAB_DIST)->MoveWindow(190, y_start + y_gap * 6, 80, edit_height);
	GetDlgItem(IDC_STATIC_TAB_INTERVAL)->MoveWindow(190, y_start + y_gap * 7, 80, edit_height);

	GetDlgItem(IDC_EDIT_TAB_COUNT)->MoveWindow(270, y_start + y_gap * 4, 80, edit_height);
	GetDlgItem(IDC_EDIT_TAB_POINT)->MoveWindow(270, y_start + y_gap * 5, 80, edit_height);
	GetDlgItem(IDC_EDIT_TAB_DIST)->MoveWindow(270, y_start + y_gap * 6, 80, edit_height);
	GetDlgItem(IDC_EDIT_TAB_INTERVAL)->MoveWindow(270, y_start + y_gap * 7, 80, edit_height);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


BOOL DIALOG_SETTING_INFO::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	return CDialogEx::PreTranslateMessage(pMsg);
}

// DIALOG_SETTING_INSPECT.cpp: 구현 파일
//

#include "stdafx.h"
#include "REVIEW_AREA.h"
#include "DIALOG_SETTING_INSPECT.h"
#include "afxdialogex.h"

#include "REVIEW_AREADlg.h"

// DIALOG_SETTING_INSPECT 대화 상자

IMPLEMENT_DYNAMIC(DIALOG_SETTING_INSPECT, CDialogEx)

DIALOG_SETTING_INSPECT::DIALOG_SETTING_INSPECT(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SETTING_INSPECT, pParent)
{

}

DIALOG_SETTING_INSPECT::~DIALOG_SETTING_INSPECT()
{
}

void DIALOG_SETTING_INSPECT::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHK_MISSALIGN_X, m_chk_missalign_x);
	DDX_Control(pDX, IDC_CHK_MISSALIGN_Y, m_chk_missalign_y);
	DDX_Control(pDX, IDC_CHK_OPEN, m_chk_open);
	DDX_Control(pDX, IDC_CHK_SHORT, m_chk_short);
	DDX_Control(pDX, IDC_CHK_WIDTH, m_chk_width);
	DDX_Control(pDX, IDC_CHK_HEIGHT, m_chk_height);
	DDX_Control(pDX, IDC_COLOR_MISSALIGN_X, m_color_missalign_x);
	DDX_Control(pDX, IDC_COLOR_MISSALIGN_Y, m_color_missalign_y);
	DDX_Control(pDX, IDC_COLOR_OPEN, m_color_open);
	DDX_Control(pDX, IDC_COLOR_SHORT, m_color_short);
	DDX_Control(pDX, IDC_COLOR_WIDTH, m_color_width);
	DDX_Control(pDX, IDC_COLOR_HEIGHT, m_color_height);
	DDX_Control(pDX, IDC_CHK_BOTH, m_chk_both);
	DDX_Control(pDX, IDC_COLOR_BOTH, m_color_both);
	DDX_Control(pDX, IDC_CHK_UPPER_MARK_1, m_chk_upper_mark_1);
	DDX_Control(pDX, IDC_CHK_UPPER_MARK_2, m_chk_upper_mark_2);
	DDX_Control(pDX, IDC_CHK_SIDE_MARK_1, m_chk_side_mark_1);
	DDX_Control(pDX, IDC_CHK_SIDE_MARK_2, m_chk_side_mark_2);
}


BEGIN_MESSAGE_MAP(DIALOG_SETTING_INSPECT, CDialogEx)
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_COLOR_MISSALIGN_X, &DIALOG_SETTING_INSPECT::OnBnClickedColorMissalignX)
	ON_BN_CLICKED(IDC_COLOR_MISSALIGN_Y, &DIALOG_SETTING_INSPECT::OnBnClickedColorMissalignY)
	ON_BN_CLICKED(IDC_COLOR_OPEN, &DIALOG_SETTING_INSPECT::OnBnClickedColorOpen)
	ON_BN_CLICKED(IDC_COLOR_SHORT, &DIALOG_SETTING_INSPECT::OnBnClickedColorShort)
	ON_BN_CLICKED(IDC_COLOR_WIDTH, &DIALOG_SETTING_INSPECT::OnBnClickedColorWidth)
	ON_BN_CLICKED(IDC_COLOR_HEIGHT, &DIALOG_SETTING_INSPECT::OnBnClickedColorHeight)
	ON_BN_CLICKED(IDC_COLOR_BOTH, &DIALOG_SETTING_INSPECT::OnBnClickedColorBoth)
	ON_BN_CLICKED(IDC_CHK_MISSALIGN_X, &DIALOG_SETTING_INSPECT::OnBnClickedChkMissalignX)
	ON_BN_CLICKED(IDC_CHK_MISSALIGN_Y, &DIALOG_SETTING_INSPECT::OnBnClickedChkMissalignY)
	ON_BN_CLICKED(IDC_CHK_OPEN, &DIALOG_SETTING_INSPECT::OnBnClickedChkOpen)
	ON_BN_CLICKED(IDC_CHK_SHORT, &DIALOG_SETTING_INSPECT::OnBnClickedChkShort)
	ON_BN_CLICKED(IDC_CHK_WIDTH, &DIALOG_SETTING_INSPECT::OnBnClickedChkWidth)
	ON_BN_CLICKED(IDC_CHK_HEIGHT, &DIALOG_SETTING_INSPECT::OnBnClickedChkHeight)
	ON_BN_CLICKED(IDC_CHK_BOTH, &DIALOG_SETTING_INSPECT::OnBnClickedChkBoth)
	ON_BN_CLICKED(IDC_CHK_UPPER_MARK_1, &DIALOG_SETTING_INSPECT::OnBnClickedChkUpperMark1)
	ON_BN_CLICKED(IDC_CHK_UPPER_MARK_2, &DIALOG_SETTING_INSPECT::OnBnClickedChkUpperMark2)
	ON_BN_CLICKED(IDC_CHK_SIDE_MARK_1, &DIALOG_SETTING_INSPECT::OnBnClickedChkSideMark1)
	ON_BN_CLICKED(IDC_CHK_SIDE_MARK_2, &DIALOG_SETTING_INSPECT::OnBnClickedChkSideMark2)
END_MESSAGE_MAP()


// DIALOG_SETTING_INSPECT 메시지 처리기


HBRUSH DIALOG_SETTING_INSPECT::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}


BOOL DIALOG_SETTING_INSPECT::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	return CDialogEx::OnEraseBkgnd(pDC);
}


BOOL DIALOG_SETTING_INSPECT::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	GetDlgItem(IDC_CHK_MISSALIGN_X)->MoveWindow(60, 10, 80, 30);
	GetDlgItem(IDC_CHK_MISSALIGN_Y)->MoveWindow(60, 50, 80, 30);
	GetDlgItem(IDC_CHK_OPEN)->MoveWindow(60, 90, 80, 30);
	GetDlgItem(IDC_CHK_SHORT)->MoveWindow(60, 130, 80, 30);
	GetDlgItem(IDC_CHK_WIDTH)->MoveWindow(60, 170, 80, 30);
	GetDlgItem(IDC_CHK_HEIGHT)->MoveWindow(60, 210, 80, 30);
	GetDlgItem(IDC_CHK_BOTH)->MoveWindow(60, 250, 80, 30);

	GetDlgItem(IDC_COLOR_MISSALIGN_X)->MoveWindow(140, 15, 50, 20);
	GetDlgItem(IDC_COLOR_MISSALIGN_Y)->MoveWindow(140, 55, 50, 20);
	GetDlgItem(IDC_COLOR_OPEN)->MoveWindow(140, 95, 50, 20);
	GetDlgItem(IDC_COLOR_SHORT)->MoveWindow(140, 135, 50, 20);
	GetDlgItem(IDC_COLOR_WIDTH)->MoveWindow(140, 175, 50, 20);
	GetDlgItem(IDC_COLOR_HEIGHT)->MoveWindow(140, 215, 50, 20);
	GetDlgItem(IDC_COLOR_BOTH)->MoveWindow(140, 255, 50, 20);

	GetDlgItem(IDC_CHK_UPPER_MARK_1)->MoveWindow(240, 10, 100, 30);
	GetDlgItem(IDC_CHK_UPPER_MARK_2)->MoveWindow(240, 50, 100, 30);
	GetDlgItem(IDC_CHK_SIDE_MARK_1)->MoveWindow(240, 90, 100, 30);
	GetDlgItem(IDC_CHK_SIDE_MARK_2)->MoveWindow(240, 130, 100, 30);

	check_ng_ma_x = true;
	check_ng_ma_y = true;
	check_ng_open = true;
	check_ng_short = true;
	check_ng_width = true;
	check_ng_height = true;
	check_ng_both = true;
	check_ng_upper_mark_1 = false;
	check_ng_upper_mark_2 = false;
	check_ng_side_mark_1 = false;
	check_ng_side_mark_2 = false;

	m_chk_missalign_x.SetCheck(1);
	m_chk_missalign_y.SetCheck(1);
	m_chk_open.SetCheck(1);
	m_chk_short.SetCheck(1);
	m_chk_width.SetCheck(1);
	m_chk_height.SetCheck(1);
	m_chk_both.SetCheck(1);

	ma_x_cl = RGB(237, 28, 36);
	ma_y_cl = RGB(255, 127, 39);
	open_cl = RGB(255, 242, 0);
	short_cl = RGB(34, 177, 76);
	width_cl = RGB(0, 162, 232);
	height_cl = RGB(63, 72, 204);
	both_cl = RGB(163, 73, 164);

	m_color_missalign_x.SetColor(ma_x_cl);
	m_color_missalign_y.SetColor(ma_y_cl);
	m_color_open.SetColor(open_cl);
	m_color_short.SetColor(short_cl);
	m_color_width.SetColor(width_cl);
	m_color_height.SetColor(height_cl);
	m_color_both.SetColor(both_cl);

	ma_x_r = GetRValue(ma_x_cl);
	ma_x_g = GetGValue(ma_x_cl);
	ma_x_b = GetBValue(ma_x_cl);

	ma_y_r = GetRValue(ma_y_cl);
	ma_y_g = GetGValue(ma_y_cl);
	ma_y_b = GetBValue(ma_y_cl);

	open_r = GetRValue(open_cl);
	open_g = GetGValue(open_cl);
	open_b = GetBValue(open_cl);

	short_r = GetRValue(short_cl);
	short_g = GetGValue(short_cl);
	short_b = GetBValue(short_cl);

	width_r = GetRValue(width_cl);
	width_g = GetGValue(width_cl);
	width_b = GetBValue(width_cl);

	height_r = GetRValue(height_cl);
	height_g = GetGValue(height_cl);
	height_b = GetBValue(height_cl);

	both_r = GetRValue(both_cl);
	both_g = GetGValue(both_cl);
	both_b = GetBValue(both_cl);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


BOOL DIALOG_SETTING_INSPECT::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	return CDialogEx::PreTranslateMessage(pMsg);
}


void DIALOG_SETTING_INSPECT::OnBnClickedColorMissalignX()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	ma_x_cl = m_color_missalign_x.GetColor();

	ma_x_r = GetRValue(ma_x_cl);
	ma_x_g = GetGValue(ma_x_cl);
	ma_x_b = GetBValue(ma_x_cl);
}


void DIALOG_SETTING_INSPECT::OnBnClickedColorMissalignY()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	ma_y_cl = m_color_missalign_y.GetColor();

	ma_y_r = GetRValue(ma_y_cl);
	ma_y_g = GetGValue(ma_y_cl);
	ma_y_b = GetBValue(ma_y_cl);
}


void DIALOG_SETTING_INSPECT::OnBnClickedColorOpen()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	open_cl = m_color_open.GetColor();

	open_r = GetRValue(open_cl);
	open_g = GetGValue(open_cl);
	open_b = GetBValue(open_cl);
}


void DIALOG_SETTING_INSPECT::OnBnClickedColorShort()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	short_cl = m_color_short.GetColor();

	short_r = GetRValue(short_cl);
	short_g = GetGValue(short_cl);
	short_b = GetBValue(short_cl);
}


void DIALOG_SETTING_INSPECT::OnBnClickedColorWidth()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	width_cl = m_color_width.GetColor();

	width_r = GetRValue(width_cl);
	width_g = GetGValue(width_cl);
	width_b = GetBValue(width_cl);
}


void DIALOG_SETTING_INSPECT::OnBnClickedColorHeight()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	height_cl = m_color_height.GetColor();

	height_r = GetRValue(height_cl);
	height_g = GetGValue(height_cl);
	height_b = GetBValue(height_cl);
}


void DIALOG_SETTING_INSPECT::OnBnClickedColorBoth()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	both_cl = m_color_both.GetColor();
	
	both_r = GetRValue(both_cl);
	both_g = GetGValue(both_cl);
	both_b = GetBValue(both_cl);
}


void DIALOG_SETTING_INSPECT::OnBnClickedChkMissalignX()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	if (m_chk_missalign_x.GetCheck() == 0)
		check_ng_ma_x = false;

	else if (m_chk_missalign_x.GetCheck() == 1)
		check_ng_ma_x = true;
	
}


void DIALOG_SETTING_INSPECT::OnBnClickedChkMissalignY()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	if (m_chk_missalign_y.GetCheck() == 0)
		check_ng_ma_y = false;

	else if (m_chk_missalign_y.GetCheck() == 1)
		check_ng_ma_y = true;
}


void DIALOG_SETTING_INSPECT::OnBnClickedChkOpen()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	if (m_chk_open.GetCheck() == 0)
		check_ng_open = false;

	else if (m_chk_open.GetCheck() == 1)
		check_ng_open = true;
}


void DIALOG_SETTING_INSPECT::OnBnClickedChkShort()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	if (m_chk_short.GetCheck() == 0)
		check_ng_short = false;
	
	else if (m_chk_short.GetCheck() == 1)
		check_ng_short = true;

}


void DIALOG_SETTING_INSPECT::OnBnClickedChkWidth()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	if (m_chk_width.GetCheck() == 0)
	{
		check_ng_width = false;
		check_ng_both = false;

		m_chk_both.SetCheck(0);
	}


	else if (m_chk_width.GetCheck() == 1)
	{
		check_ng_width = true;

		if (m_chk_height.GetCheck() == 1)
		{
			check_ng_both = true;
			m_chk_both.SetCheck(1);
		}
	}
	

}


void DIALOG_SETTING_INSPECT::OnBnClickedChkHeight()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	if (m_chk_height.GetCheck() == 0)
	{
		check_ng_height = false;
		check_ng_both = false;

		m_chk_both.SetCheck(0);
	}
		
	else if (m_chk_height.GetCheck() == 1)
	{
		check_ng_height = true;

		if (m_chk_width.GetCheck() == 1)
		{
			check_ng_both = true;
			m_chk_both.SetCheck(1);
		}
	}
}


void DIALOG_SETTING_INSPECT::OnBnClickedChkBoth()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	if (m_chk_both.GetCheck() == 0)
	{
		check_ng_width = false;
		check_ng_height = false;
		check_ng_both = false;

		m_chk_width.SetCheck(0);
		m_chk_height.SetCheck(0);
	}

	else if (m_chk_both.GetCheck() == 1)
	{
		check_ng_width = true;
		check_ng_height = true;
		check_ng_both = true;

		m_chk_width.SetCheck(1);
		m_chk_height.SetCheck(1);
	}
}


void DIALOG_SETTING_INSPECT::OnBnClickedChkUpperMark1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	if (m_chk_upper_mark_1.GetCheck() == 0)
		check_ng_upper_mark_1 = true;

	else if (m_chk_upper_mark_1.GetCheck() == 1)
		check_ng_upper_mark_1 = false;
}


void DIALOG_SETTING_INSPECT::OnBnClickedChkUpperMark2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	if (m_chk_upper_mark_2.GetCheck() == 0)
		check_ng_upper_mark_2 = true;

	else if (m_chk_upper_mark_2.GetCheck() == 1)
		check_ng_upper_mark_2 = false;

}


void DIALOG_SETTING_INSPECT::OnBnClickedChkSideMark1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	if (m_chk_side_mark_1.GetCheck() == 0)
		check_ng_side_mark_1 = true;

	else if (m_chk_side_mark_1.GetCheck() == 1)
		check_ng_side_mark_1 = false;

}


void DIALOG_SETTING_INSPECT::OnBnClickedChkSideMark2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	if (m_chk_side_mark_2.GetCheck() == 0)
		check_ng_side_mark_2 = true;

	else if (m_chk_side_mark_2.GetCheck() == 1)
		check_ng_side_mark_2 = false;

}

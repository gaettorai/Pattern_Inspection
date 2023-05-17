// DIALOG_SETTING_PROCESS.cpp: 구현 파일
//

#include "stdafx.h"
#include "REVIEW_AREA.h"
#include "DIALOG_SETTING_PROCESS.h"
#include "afxdialogex.h"

#include "REVIEW_AREADlg.h"

// DIALOG_SETTING_PROCESS 대화 상자

IMPLEMENT_DYNAMIC(DIALOG_SETTING_PROCESS, CDialogEx)

DIALOG_SETTING_PROCESS::DIALOG_SETTING_PROCESS(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SETTING_PROCESS, pParent)
{

}

DIALOG_SETTING_PROCESS::~DIALOG_SETTING_PROCESS()
{
}

void DIALOG_SETTING_PROCESS::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BTN_TAB_1, m_btn_tab_1);
	DDX_Control(pDX, IDC_BTN_TAB_2, m_btn_tab_2);
	DDX_Control(pDX, IDC_BTN_TAB_3, m_btn_tab_3);
	DDX_Control(pDX, IDC_BTN_TAB_4, m_btn_tab_4);
	DDX_Control(pDX, IDC_BTN_TAB_5, m_btn_tab_5);
	DDX_Control(pDX, IDC_BTN_TAB_6, m_btn_tab_6);
	DDX_Control(pDX, IDC_BTN_TAB_7, m_btn_tab_7);
	DDX_Control(pDX, IDC_BTN_TAB_8, m_btn_tab_8);
	DDX_Control(pDX, IDC_BTN_TAB_9, m_btn_tab_9);
	DDX_Control(pDX, IDC_BTN_TAB_10, m_btn_tab_10);
	DDX_Control(pDX, IDC_BTN_TAB_11, m_btn_tab_11);
	DDX_Control(pDX, IDC_BTN_TAB_12, m_btn_tab_12);
	DDX_Control(pDX, IDC_BTN_TAB_13, m_btn_tab_13);
	DDX_Control(pDX, IDC_BTN_TAB_14, m_btn_tab_14);
	DDX_Control(pDX, IDC_BTN_TAB_15, m_btn_tab_15);
	DDX_Control(pDX, IDC_BTN_TAB_16, m_btn_tab_16);
	DDX_Control(pDX, IDC_BTN_TAB_17, m_btn_tab_17);
	DDX_Control(pDX, IDC_BTN_TAB_18, m_btn_tab_18);
	DDX_Control(pDX, IDC_BTN_TAB_19, m_btn_tab_19);
	DDX_Control(pDX, IDC_BTN_TAB_20, m_btn_tab_20);
	DDX_Control(pDX, IDC_BTN_TAB_21, m_btn_tab_21);
	DDX_Control(pDX, IDC_BTN_TAB_22, m_btn_tab_22);
	DDX_Control(pDX, IDC_BTN_TAB_23, m_btn_tab_23);
	DDX_Control(pDX, IDC_BTN_TAB_24, m_btn_tab_24);
	DDX_Control(pDX, IDC_BTN_TAB_25, m_btn_tab_25);
	DDX_Control(pDX, IDC_BTN_TAB_26, m_btn_tab_26);
	DDX_Control(pDX, IDC_BTN_TAB_27, m_btn_tab_27);
	DDX_Control(pDX, IDC_BTN_TAB_28, m_btn_tab_28);
	DDX_Control(pDX, IDC_BTN_TAB_29, m_btn_tab_29);
	DDX_Control(pDX, IDC_BTN_TAB_30, m_btn_tab_30);

}


BEGIN_MESSAGE_MAP(DIALOG_SETTING_PROCESS, CDialogEx)
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_BTN_TAB_PASS, &DIALOG_SETTING_PROCESS::OnBnClickedBtnTabPass)
	ON_BN_CLICKED(IDC_BTN_TABALIGN_PASS, &DIALOG_SETTING_PROCESS::OnBnClickedBtnTabalignPass)
	ON_BN_CLICKED(IDC_BTN_PREALIGN_PASS, &DIALOG_SETTING_PROCESS::OnBnClickedBtnPrealignPass)
END_MESSAGE_MAP()


// DIALOG_SETTING_PROCESS 메시지 처리기


HBRUSH DIALOG_SETTING_PROCESS::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}


BOOL DIALOG_SETTING_PROCESS::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	return CDialogEx::OnEraseBkgnd(pDC);
}


BOOL DIALOG_SETTING_PROCESS::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	GetDlgItem(IDC_STATIC_PROCESS_PREALIGN)->MoveWindow(150, 30, 100, 30);
	GetDlgItem(IDC_STATIC_PROCESS_TABALIGN)->MoveWindow(150, 70, 100, 30);
	GetDlgItem(IDC_STATIC_PROCESS_TAB)->MoveWindow(150, 110, 100, 30);

	GetDlgItem(IDC_BTN_PREALIGN_PASS)->MoveWindow(250, 30, 100, 30);
	GetDlgItem(IDC_BTN_TABALIGN_PASS)->MoveWindow(250, 70, 100, 30);
	GetDlgItem(IDC_BTN_TAB_PASS)->MoveWindow(250, 110, 100, 30);

	GetDlgItem(IDC_BTN_TAB_1)->MoveWindow(10, 160, 30, 30);
	GetDlgItem(IDC_BTN_TAB_2)->MoveWindow(45, 160, 30, 30);
	GetDlgItem(IDC_BTN_TAB_3)->MoveWindow(80, 160, 30, 30);
	GetDlgItem(IDC_BTN_TAB_4)->MoveWindow(115, 160, 30, 30);
	GetDlgItem(IDC_BTN_TAB_5)->MoveWindow(150, 160, 30, 30);
	GetDlgItem(IDC_BTN_TAB_6)->MoveWindow(185, 160, 30, 30);
	GetDlgItem(IDC_BTN_TAB_7)->MoveWindow(220, 160, 30, 30);
	GetDlgItem(IDC_BTN_TAB_8)->MoveWindow(255, 160, 30, 30);
	GetDlgItem(IDC_BTN_TAB_9)->MoveWindow(290, 160, 30, 30);
	GetDlgItem(IDC_BTN_TAB_10)->MoveWindow(325, 160, 30, 30);

	GetDlgItem(IDC_BTN_TAB_11)->MoveWindow(10, 210, 30, 30);
	GetDlgItem(IDC_BTN_TAB_12)->MoveWindow(45, 210, 30, 30);
	GetDlgItem(IDC_BTN_TAB_13)->MoveWindow(80, 210, 30, 30);
	GetDlgItem(IDC_BTN_TAB_14)->MoveWindow(115, 210, 30, 30);
	GetDlgItem(IDC_BTN_TAB_15)->MoveWindow(150, 210, 30, 30);
	GetDlgItem(IDC_BTN_TAB_16)->MoveWindow(185, 210, 30, 30);
	GetDlgItem(IDC_BTN_TAB_17)->MoveWindow(220, 210, 30, 30);
	GetDlgItem(IDC_BTN_TAB_18)->MoveWindow(255, 210, 30, 30);
	GetDlgItem(IDC_BTN_TAB_19)->MoveWindow(290, 210, 30, 30);
	GetDlgItem(IDC_BTN_TAB_20)->MoveWindow(325, 210, 30, 30);

	GetDlgItem(IDC_BTN_TAB_21)->MoveWindow(10, 260, 30, 30);
	GetDlgItem(IDC_BTN_TAB_22)->MoveWindow(45, 260, 30, 30);
	GetDlgItem(IDC_BTN_TAB_23)->MoveWindow(80, 260, 30, 30);
	GetDlgItem(IDC_BTN_TAB_24)->MoveWindow(115, 260, 30, 30);
	GetDlgItem(IDC_BTN_TAB_25)->MoveWindow(150, 260, 30, 30);
	GetDlgItem(IDC_BTN_TAB_26)->MoveWindow(185, 260, 30, 30);
	GetDlgItem(IDC_BTN_TAB_27)->MoveWindow(220, 260, 30, 30);
	GetDlgItem(IDC_BTN_TAB_28)->MoveWindow(255, 260, 30, 30);
	GetDlgItem(IDC_BTN_TAB_29)->MoveWindow(290, 260, 30, 30);
	GetDlgItem(IDC_BTN_TAB_30)->MoveWindow(325, 260, 30, 30);


	m_bmp_tab_1.LoadBitmapW(IDB_BITMAP_TAB_1);
	m_bmp_tab_2.LoadBitmapW(IDB_BITMAP_TAB_2);
	m_bmp_tab_3.LoadBitmapW(IDB_BITMAP_TAB_3);
	m_bmp_tab_4.LoadBitmapW(IDB_BITMAP_TAB_4);
	m_bmp_tab_5.LoadBitmapW(IDB_BITMAP_TAB_5);
	m_bmp_tab_6.LoadBitmapW(IDB_BITMAP_TAB_6);
	m_bmp_tab_7.LoadBitmapW(IDB_BITMAP_TAB_7);
	m_bmp_tab_8.LoadBitmapW(IDB_BITMAP_TAB_8);
	m_bmp_tab_9.LoadBitmapW(IDB_BITMAP_TAB_9);
	m_bmp_tab_10.LoadBitmapW(IDB_BITMAP_TAB_10);
	m_bmp_tab_11.LoadBitmapW(IDB_BITMAP_TAB_11);
	m_bmp_tab_12.LoadBitmapW(IDB_BITMAP_TAB_12);
	m_bmp_tab_13.LoadBitmapW(IDB_BITMAP_TAB_13);
	m_bmp_tab_14.LoadBitmapW(IDB_BITMAP_TAB_14);
	m_bmp_tab_15.LoadBitmapW(IDB_BITMAP_TAB_15);
	m_bmp_tab_16.LoadBitmapW(IDB_BITMAP_TAB_16);
	m_bmp_tab_17.LoadBitmapW(IDB_BITMAP_TAB_17);
	m_bmp_tab_18.LoadBitmapW(IDB_BITMAP_TAB_18);
	m_bmp_tab_19.LoadBitmapW(IDB_BITMAP_TAB_19);
	m_bmp_tab_20.LoadBitmapW(IDB_BITMAP_TAB_20);
	m_bmp_tab_21.LoadBitmapW(IDB_BITMAP_TAB_21);
	m_bmp_tab_22.LoadBitmapW(IDB_BITMAP_TAB_22);
	m_bmp_tab_23.LoadBitmapW(IDB_BITMAP_TAB_23);
	m_bmp_tab_24.LoadBitmapW(IDB_BITMAP_TAB_24);
	m_bmp_tab_25.LoadBitmapW(IDB_BITMAP_TAB_25);
	m_bmp_tab_26.LoadBitmapW(IDB_BITMAP_TAB_26);
	m_bmp_tab_27.LoadBitmapW(IDB_BITMAP_TAB_27);
	m_bmp_tab_28.LoadBitmapW(IDB_BITMAP_TAB_28);
	m_bmp_tab_29.LoadBitmapW(IDB_BITMAP_TAB_29);
	m_bmp_tab_30.LoadBitmapW(IDB_BITMAP_TAB_30);

	m_bmp_tab_1_a.LoadBitmapW(IDB_BITMAP_TAB_1_A);
	m_bmp_tab_2_a.LoadBitmapW(IDB_BITMAP_TAB_2_A);
	m_bmp_tab_3_a.LoadBitmapW(IDB_BITMAP_TAB_3_A);
	m_bmp_tab_4_a.LoadBitmapW(IDB_BITMAP_TAB_4_A);
	m_bmp_tab_5_a.LoadBitmapW(IDB_BITMAP_TAB_5_A);
	m_bmp_tab_6_a.LoadBitmapW(IDB_BITMAP_TAB_6_A);
	m_bmp_tab_7_a.LoadBitmapW(IDB_BITMAP_TAB_7_A);
	m_bmp_tab_8_a.LoadBitmapW(IDB_BITMAP_TAB_8_A);
	m_bmp_tab_9_a.LoadBitmapW(IDB_BITMAP_TAB_9_A);
	m_bmp_tab_10_a.LoadBitmapW(IDB_BITMAP_TAB_10_A);
	m_bmp_tab_11_a.LoadBitmapW(IDB_BITMAP_TAB_11_A);
	m_bmp_tab_12_a.LoadBitmapW(IDB_BITMAP_TAB_12_A);
	m_bmp_tab_13_a.LoadBitmapW(IDB_BITMAP_TAB_13_A);
	m_bmp_tab_14_a.LoadBitmapW(IDB_BITMAP_TAB_14_A);
	m_bmp_tab_15_a.LoadBitmapW(IDB_BITMAP_TAB_15_A);
	m_bmp_tab_16_a.LoadBitmapW(IDB_BITMAP_TAB_16_A);
	m_bmp_tab_17_a.LoadBitmapW(IDB_BITMAP_TAB_17_A);
	m_bmp_tab_18_a.LoadBitmapW(IDB_BITMAP_TAB_18_A);
	m_bmp_tab_19_a.LoadBitmapW(IDB_BITMAP_TAB_19_A);
	m_bmp_tab_20_a.LoadBitmapW(IDB_BITMAP_TAB_20_A);
	m_bmp_tab_21_a.LoadBitmapW(IDB_BITMAP_TAB_21_A);
	m_bmp_tab_22_a.LoadBitmapW(IDB_BITMAP_TAB_22_A);
	m_bmp_tab_23_a.LoadBitmapW(IDB_BITMAP_TAB_23_A);
	m_bmp_tab_24_a.LoadBitmapW(IDB_BITMAP_TAB_24_A);
	m_bmp_tab_25_a.LoadBitmapW(IDB_BITMAP_TAB_25_A);
	m_bmp_tab_26_a.LoadBitmapW(IDB_BITMAP_TAB_26_A);
	m_bmp_tab_27_a.LoadBitmapW(IDB_BITMAP_TAB_27_A);
	m_bmp_tab_28_a.LoadBitmapW(IDB_BITMAP_TAB_28_A);
	m_bmp_tab_29_a.LoadBitmapW(IDB_BITMAP_TAB_29_A);
	m_bmp_tab_30_a.LoadBitmapW(IDB_BITMAP_TAB_30_A);

	m_btn_tab_1.EnableWindow(FALSE);
	m_btn_tab_2.EnableWindow(FALSE);
	m_btn_tab_3.EnableWindow(FALSE);
	m_btn_tab_4.EnableWindow(FALSE);
	m_btn_tab_5.EnableWindow(FALSE);
	m_btn_tab_6.EnableWindow(FALSE);
	m_btn_tab_7.EnableWindow(FALSE);
	m_btn_tab_8.EnableWindow(FALSE);
	m_btn_tab_9.EnableWindow(FALSE);
	m_btn_tab_10.EnableWindow(FALSE);
	m_btn_tab_11.EnableWindow(FALSE);
	m_btn_tab_12.EnableWindow(FALSE);
	m_btn_tab_13.EnableWindow(FALSE);
	m_btn_tab_14.EnableWindow(FALSE);
	m_btn_tab_15.EnableWindow(FALSE);
	m_btn_tab_16.EnableWindow(FALSE);
	m_btn_tab_17.EnableWindow(FALSE);
	m_btn_tab_18.EnableWindow(FALSE);
	m_btn_tab_19.EnableWindow(FALSE);
	m_btn_tab_20.EnableWindow(FALSE);
	m_btn_tab_21.EnableWindow(FALSE);
	m_btn_tab_22.EnableWindow(FALSE);
	m_btn_tab_23.EnableWindow(FALSE);
	m_btn_tab_24.EnableWindow(FALSE);
	m_btn_tab_25.EnableWindow(FALSE);
	m_btn_tab_26.EnableWindow(FALSE);
	m_btn_tab_27.EnableWindow(FALSE);
	m_btn_tab_28.EnableWindow(FALSE);
	m_btn_tab_29.EnableWindow(FALSE);
	m_btn_tab_30.EnableWindow(FALSE);

	m_btn_tab_1.SetBitmap(m_bmp_tab_1);
	m_btn_tab_2.SetBitmap(m_bmp_tab_2);
	m_btn_tab_3.SetBitmap(m_bmp_tab_3);
	m_btn_tab_4.SetBitmap(m_bmp_tab_4);
	m_btn_tab_5.SetBitmap(m_bmp_tab_5);
	m_btn_tab_6.SetBitmap(m_bmp_tab_6);
	m_btn_tab_7.SetBitmap(m_bmp_tab_7);
	m_btn_tab_8.SetBitmap(m_bmp_tab_8);
	m_btn_tab_9.SetBitmap(m_bmp_tab_9);
	m_btn_tab_10.SetBitmap(m_bmp_tab_10);
	m_btn_tab_11.SetBitmap(m_bmp_tab_11);
	m_btn_tab_12.SetBitmap(m_bmp_tab_12);
	m_btn_tab_13.SetBitmap(m_bmp_tab_13);
	m_btn_tab_14.SetBitmap(m_bmp_tab_14);
	m_btn_tab_15.SetBitmap(m_bmp_tab_15);
	m_btn_tab_16.SetBitmap(m_bmp_tab_16);
	m_btn_tab_17.SetBitmap(m_bmp_tab_17);
	m_btn_tab_18.SetBitmap(m_bmp_tab_18);
	m_btn_tab_19.SetBitmap(m_bmp_tab_19);
	m_btn_tab_20.SetBitmap(m_bmp_tab_20);
	m_btn_tab_21.SetBitmap(m_bmp_tab_21);
	m_btn_tab_22.SetBitmap(m_bmp_tab_22);
	m_btn_tab_23.SetBitmap(m_bmp_tab_23);
	m_btn_tab_24.SetBitmap(m_bmp_tab_24);
	m_btn_tab_25.SetBitmap(m_bmp_tab_25);
	m_btn_tab_26.SetBitmap(m_bmp_tab_26);
	m_btn_tab_27.SetBitmap(m_bmp_tab_27);
	m_btn_tab_28.SetBitmap(m_bmp_tab_28);
	m_btn_tab_29.SetBitmap(m_bmp_tab_29);
	m_btn_tab_30.SetBitmap(m_bmp_tab_30);

	tab_pass_active = 0;

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


BOOL DIALOG_SETTING_PROCESS::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	
	if (tab_pass_active == 1)
	{
		if (pMsg->message == WM_LBUTTONDOWN)
		{
			pButton = (CButton*)GetDlgItem(IDC_BTN_TAB_1);
			pButton->GetWindowRect(rect_tab_pass);
			if (rect_tab_pass.PtInRect(pMsg->pt))
				PassTab(1);

			pButton = (CButton*)GetDlgItem(IDC_BTN_TAB_2);
			pButton->GetWindowRect(rect_tab_pass);
			if (rect_tab_pass.PtInRect(pMsg->pt))
				PassTab(2);

			pButton = (CButton*)GetDlgItem(IDC_BTN_TAB_3);
			pButton->GetWindowRect(rect_tab_pass);
			if (rect_tab_pass.PtInRect(pMsg->pt))
				PassTab(3);

			pButton = (CButton*)GetDlgItem(IDC_BTN_TAB_4);
			pButton->GetWindowRect(rect_tab_pass);
			if (rect_tab_pass.PtInRect(pMsg->pt))
				PassTab(4);

			pButton = (CButton*)GetDlgItem(IDC_BTN_TAB_5);
			pButton->GetWindowRect(rect_tab_pass);
			if (rect_tab_pass.PtInRect(pMsg->pt))
				PassTab(5);

			pButton = (CButton*)GetDlgItem(IDC_BTN_TAB_6);
			pButton->GetWindowRect(rect_tab_pass);
			if (rect_tab_pass.PtInRect(pMsg->pt))
				PassTab(6);

			pButton = (CButton*)GetDlgItem(IDC_BTN_TAB_7);
			pButton->GetWindowRect(rect_tab_pass);
			if (rect_tab_pass.PtInRect(pMsg->pt))
				PassTab(7);

			pButton = (CButton*)GetDlgItem(IDC_BTN_TAB_8);
			pButton->GetWindowRect(rect_tab_pass);
			if (rect_tab_pass.PtInRect(pMsg->pt))
				PassTab(8);

			pButton = (CButton*)GetDlgItem(IDC_BTN_TAB_9);
			pButton->GetWindowRect(rect_tab_pass);
			if (rect_tab_pass.PtInRect(pMsg->pt))
				PassTab(9);

			pButton = (CButton*)GetDlgItem(IDC_BTN_TAB_10);
			pButton->GetWindowRect(rect_tab_pass);
			if (rect_tab_pass.PtInRect(pMsg->pt))
				PassTab(10);

			pButton = (CButton*)GetDlgItem(IDC_BTN_TAB_11);
			pButton->GetWindowRect(rect_tab_pass);
			if (rect_tab_pass.PtInRect(pMsg->pt))
				PassTab(11);

			pButton = (CButton*)GetDlgItem(IDC_BTN_TAB_12);
			pButton->GetWindowRect(rect_tab_pass);
			if (rect_tab_pass.PtInRect(pMsg->pt))
				PassTab(12);

			pButton = (CButton*)GetDlgItem(IDC_BTN_TAB_13);
			pButton->GetWindowRect(rect_tab_pass);
			if (rect_tab_pass.PtInRect(pMsg->pt))
				PassTab(13);

			pButton = (CButton*)GetDlgItem(IDC_BTN_TAB_14);
			pButton->GetWindowRect(rect_tab_pass);
			if (rect_tab_pass.PtInRect(pMsg->pt))
				PassTab(14);

			pButton = (CButton*)GetDlgItem(IDC_BTN_TAB_15);
			pButton->GetWindowRect(rect_tab_pass);
			if (rect_tab_pass.PtInRect(pMsg->pt))
				PassTab(15);

			pButton = (CButton*)GetDlgItem(IDC_BTN_TAB_16);
			pButton->GetWindowRect(rect_tab_pass);
			if (rect_tab_pass.PtInRect(pMsg->pt))
				PassTab(16);

			pButton = (CButton*)GetDlgItem(IDC_BTN_TAB_17);
			pButton->GetWindowRect(rect_tab_pass);
			if (rect_tab_pass.PtInRect(pMsg->pt))
				PassTab(17);

			pButton = (CButton*)GetDlgItem(IDC_BTN_TAB_18);
			pButton->GetWindowRect(rect_tab_pass);
			if (rect_tab_pass.PtInRect(pMsg->pt))
				PassTab(18);

			pButton = (CButton*)GetDlgItem(IDC_BTN_TAB_19);
			pButton->GetWindowRect(rect_tab_pass);
			if (rect_tab_pass.PtInRect(pMsg->pt))
				PassTab(19);

			pButton = (CButton*)GetDlgItem(IDC_BTN_TAB_20);
			pButton->GetWindowRect(rect_tab_pass);
			if (rect_tab_pass.PtInRect(pMsg->pt))
				PassTab(20);

			pButton = (CButton*)GetDlgItem(IDC_BTN_TAB_21);
			pButton->GetWindowRect(rect_tab_pass);
			if (rect_tab_pass.PtInRect(pMsg->pt))
				PassTab(21);

			pButton = (CButton*)GetDlgItem(IDC_BTN_TAB_22);
			pButton->GetWindowRect(rect_tab_pass);
			if (rect_tab_pass.PtInRect(pMsg->pt))
				PassTab(22);

			pButton = (CButton*)GetDlgItem(IDC_BTN_TAB_23);
			pButton->GetWindowRect(rect_tab_pass);
			if (rect_tab_pass.PtInRect(pMsg->pt))
				PassTab(23);

			pButton = (CButton*)GetDlgItem(IDC_BTN_TAB_24);
			pButton->GetWindowRect(rect_tab_pass);
			if (rect_tab_pass.PtInRect(pMsg->pt))
				PassTab(24);

			pButton = (CButton*)GetDlgItem(IDC_BTN_TAB_25);
			pButton->GetWindowRect(rect_tab_pass);
			if (rect_tab_pass.PtInRect(pMsg->pt))
				PassTab(25);

			pButton = (CButton*)GetDlgItem(IDC_BTN_TAB_26);
			pButton->GetWindowRect(rect_tab_pass);
			if (rect_tab_pass.PtInRect(pMsg->pt))
				PassTab(26);

			pButton = (CButton*)GetDlgItem(IDC_BTN_TAB_27);
			pButton->GetWindowRect(rect_tab_pass);
			if (rect_tab_pass.PtInRect(pMsg->pt))
				PassTab(27);

			pButton = (CButton*)GetDlgItem(IDC_BTN_TAB_28);
			pButton->GetWindowRect(rect_tab_pass);
			if (rect_tab_pass.PtInRect(pMsg->pt))
				PassTab(28);

			pButton = (CButton*)GetDlgItem(IDC_BTN_TAB_29);
			pButton->GetWindowRect(rect_tab_pass);
			if (rect_tab_pass.PtInRect(pMsg->pt))
				PassTab(29);

			pButton = (CButton*)GetDlgItem(IDC_BTN_TAB_30);
			pButton->GetWindowRect(rect_tab_pass);
			if (rect_tab_pass.PtInRect(pMsg->pt))
				PassTab(30);
		}

	}
	
	return CDialogEx::PreTranslateMessage(pMsg);
}


void DIALOG_SETTING_PROCESS::OnBnClickedBtnTabalignPass()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CREVIEWAREADlg *pDlg = (CREVIEWAREADlg*)AfxGetMainWnd();

	CString strbtn;
	GetDlgItem(IDC_BTN_TABALIGN_PASS)->GetWindowTextW(strbtn);

	if (strbtn == _T("EXCUTE_MODE"))
	{
		GetDlgItem(IDC_BTN_TABALIGN_PASS)->SetWindowTextW(_T("PASS_MODE"));
		pDlg->dlg_auto->process_pass_tabalign = false;
	}

	else if (strbtn == _T("PASS_MODE"))
	{
		GetDlgItem(IDC_BTN_TABALIGN_PASS)->SetWindowTextW(_T("EXCUTE_MODE"));
		pDlg->dlg_auto->process_pass_tabalign = true;
	}
}


void DIALOG_SETTING_PROCESS::OnBnClickedBtnPrealignPass()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CREVIEWAREADlg *pDlg = (CREVIEWAREADlg*)AfxGetMainWnd();

	CString strbtn;
	GetDlgItem(IDC_BTN_PREALIGN_PASS)->GetWindowTextW(strbtn);

	if (strbtn == _T("EXCUTE_MODE"))
	{
		GetDlgItem(IDC_BTN_PREALIGN_PASS)->SetWindowTextW(_T("PASS_MODE"));
		pDlg->dlg_auto->process_pass_prealign = false;
	}

	else if (strbtn == _T("PASS_MODE"))
	{
		GetDlgItem(IDC_BTN_PREALIGN_PASS)->SetWindowTextW(_T("EXCUTE_MODE"));
		pDlg->dlg_auto->process_pass_prealign = true;
	}
}


void DIALOG_SETTING_PROCESS::OnBnClickedBtnTabPass()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	/*CREVIEWAREADlg *pDlg = (CREVIEWAREADlg*)AfxGetMainWnd();

	CString strbtn;
	GetDlgItem(IDC_BTN_TAB_PASS)->GetWindowTextW(strbtn);

	if (strbtn == _T("EXCUTE_MODE"))
	{
		GetDlgItem(IDC_BTN_TAB_PASS)->SetWindowTextW(_T("PASS_MODE"));

		pass_tab_setting(pDlg->dlg_auto->tab_count, 1);
		tab_pass_active = 1;
	}

	else if (strbtn == _T("PASS_MODE"))
	{
		GetDlgItem(IDC_BTN_TAB_PASS)->SetWindowTextW(_T("EXCUTE_MODE"));

		pass_tab_setting(pDlg->dlg_auto->tab_count, 2);
		tab_pass_active = 0;
	}*/
}


void DIALOG_SETTING_PROCESS::pass_tab_setting(int tab, int Case)
{
	/*CREVIEWAREADlg *pDlg = (CREVIEWAREADlg*)AfxGetMainWnd();

	if (Case == 1)
	{
		if (tab > 1)
		{
			GetDlgItem(IDC_BTN_TAB_1)->EnableWindow(TRUE);
			GetDlgItem(IDC_BTN_TAB_2)->EnableWindow(TRUE);
		}

		if (tab > 2)
			GetDlgItem(IDC_BTN_TAB_3)->EnableWindow(TRUE);
		if (tab > 3)
			GetDlgItem(IDC_BTN_TAB_4)->EnableWindow(TRUE);
		if (tab > 4)
			GetDlgItem(IDC_BTN_TAB_5)->EnableWindow(TRUE);
		if (tab > 5)
			GetDlgItem(IDC_BTN_TAB_6)->EnableWindow(TRUE);
		if (tab > 6)
			GetDlgItem(IDC_BTN_TAB_7)->EnableWindow(TRUE);
		if (tab > 7)
			GetDlgItem(IDC_BTN_TAB_8)->EnableWindow(TRUE);
		if (tab > 8)
			GetDlgItem(IDC_BTN_TAB_9)->EnableWindow(TRUE);
		if (tab > 9)
			GetDlgItem(IDC_BTN_TAB_10)->EnableWindow(TRUE);
		if (tab > 10)
			GetDlgItem(IDC_BTN_TAB_11)->EnableWindow(TRUE);
		if (tab > 11)
			GetDlgItem(IDC_BTN_TAB_12)->EnableWindow(TRUE);
		if (tab > 12)
			GetDlgItem(IDC_BTN_TAB_13)->EnableWindow(TRUE);
		if (tab > 13)
			GetDlgItem(IDC_BTN_TAB_14)->EnableWindow(TRUE);
		if (tab > 14)
			GetDlgItem(IDC_BTN_TAB_15)->EnableWindow(TRUE);
		if (tab > 15)
			GetDlgItem(IDC_BTN_TAB_16)->EnableWindow(TRUE);
		if (tab > 16)
			GetDlgItem(IDC_BTN_TAB_17)->EnableWindow(TRUE);
		if (tab > 17)
			GetDlgItem(IDC_BTN_TAB_18)->EnableWindow(TRUE);
		if (tab > 18)
			GetDlgItem(IDC_BTN_TAB_19)->EnableWindow(TRUE);
		if (tab > 19)
			GetDlgItem(IDC_BTN_TAB_20)->EnableWindow(TRUE);
		if (tab > 20)
			GetDlgItem(IDC_BTN_TAB_21)->EnableWindow(TRUE);
		if (tab > 21)
			GetDlgItem(IDC_BTN_TAB_22)->EnableWindow(TRUE);
		if (tab > 22)
			GetDlgItem(IDC_BTN_TAB_23)->EnableWindow(TRUE);
		if (tab > 23)
			GetDlgItem(IDC_BTN_TAB_24)->EnableWindow(TRUE);
		if (tab > 24)
			GetDlgItem(IDC_BTN_TAB_25)->EnableWindow(TRUE);
		if (tab > 25)
			GetDlgItem(IDC_BTN_TAB_26)->EnableWindow(TRUE);
		if (tab > 26)
			GetDlgItem(IDC_BTN_TAB_27)->EnableWindow(TRUE);
		if (tab > 27)
			GetDlgItem(IDC_BTN_TAB_28)->EnableWindow(TRUE);
		if (tab > 28)
			GetDlgItem(IDC_BTN_TAB_29)->EnableWindow(TRUE);
		if (tab > 29)
			GetDlgItem(IDC_BTN_TAB_30)->EnableWindow(TRUE);
	}

	else if (Case == 2)
	{
		GetDlgItem(IDC_BTN_TAB_1)->EnableWindow(FALSE);
		pDlg->dlg_auto->process_pass_tab_1 = false;
		m_btn_tab_1.SetBitmap(m_bmp_tab_1);

		GetDlgItem(IDC_BTN_TAB_2)->EnableWindow(FALSE);
		pDlg->dlg_auto->process_pass_tab_2 = false;
		m_btn_tab_2.SetBitmap(m_bmp_tab_2);

		GetDlgItem(IDC_BTN_TAB_3)->EnableWindow(FALSE);
		pDlg->dlg_auto->process_pass_tab_3 = false;
		m_btn_tab_3.SetBitmap(m_bmp_tab_3);

		GetDlgItem(IDC_BTN_TAB_4)->EnableWindow(FALSE);
		pDlg->dlg_auto->process_pass_tab_4 = false;
		m_btn_tab_4.SetBitmap(m_bmp_tab_4);

		GetDlgItem(IDC_BTN_TAB_5)->EnableWindow(FALSE);
		pDlg->dlg_auto->process_pass_tab_5 = false;
		m_btn_tab_5.SetBitmap(m_bmp_tab_5);

		GetDlgItem(IDC_BTN_TAB_6)->EnableWindow(FALSE);
		pDlg->dlg_auto->process_pass_tab_6 = false;
		m_btn_tab_6.SetBitmap(m_bmp_tab_6);

		GetDlgItem(IDC_BTN_TAB_7)->EnableWindow(FALSE);
		pDlg->dlg_auto->process_pass_tab_7 = false;
		m_btn_tab_7.SetBitmap(m_bmp_tab_7);

		GetDlgItem(IDC_BTN_TAB_8)->EnableWindow(FALSE);
		pDlg->dlg_auto->process_pass_tab_8 = false;
		m_btn_tab_8.SetBitmap(m_bmp_tab_8);

		GetDlgItem(IDC_BTN_TAB_9)->EnableWindow(FALSE);
		pDlg->dlg_auto->process_pass_tab_9 = false;
		m_btn_tab_9.SetBitmap(m_bmp_tab_9);

		GetDlgItem(IDC_BTN_TAB_10)->EnableWindow(FALSE);
		pDlg->dlg_auto->process_pass_tab_10 = false;
		m_btn_tab_10.SetBitmap(m_bmp_tab_10);

		GetDlgItem(IDC_BTN_TAB_11)->EnableWindow(FALSE);
		pDlg->dlg_auto->process_pass_tab_11 = false;
		m_btn_tab_11.SetBitmap(m_bmp_tab_11);

		GetDlgItem(IDC_BTN_TAB_12)->EnableWindow(FALSE);
		pDlg->dlg_auto->process_pass_tab_12 = false;
		m_btn_tab_12.SetBitmap(m_bmp_tab_12);

		GetDlgItem(IDC_BTN_TAB_13)->EnableWindow(FALSE);
		pDlg->dlg_auto->process_pass_tab_13 = false;
		m_btn_tab_13.SetBitmap(m_bmp_tab_13);

		GetDlgItem(IDC_BTN_TAB_14)->EnableWindow(FALSE);
		pDlg->dlg_auto->process_pass_tab_14 = false;
		m_btn_tab_14.SetBitmap(m_bmp_tab_14);

		GetDlgItem(IDC_BTN_TAB_15)->EnableWindow(FALSE);
		pDlg->dlg_auto->process_pass_tab_15 = false;
		m_btn_tab_15.SetBitmap(m_bmp_tab_15);

		GetDlgItem(IDC_BTN_TAB_16)->EnableWindow(FALSE);
		pDlg->dlg_auto->process_pass_tab_16 = false;
		m_btn_tab_16.SetBitmap(m_bmp_tab_16);

		GetDlgItem(IDC_BTN_TAB_17)->EnableWindow(FALSE);
		pDlg->dlg_auto->process_pass_tab_17 = false;
		m_btn_tab_17.SetBitmap(m_bmp_tab_17);

		GetDlgItem(IDC_BTN_TAB_18)->EnableWindow(FALSE);
		pDlg->dlg_auto->process_pass_tab_18 = false;
		m_btn_tab_18.SetBitmap(m_bmp_tab_18);

		GetDlgItem(IDC_BTN_TAB_19)->EnableWindow(FALSE);
		pDlg->dlg_auto->process_pass_tab_19 = false;
		m_btn_tab_19.SetBitmap(m_bmp_tab_19);

		GetDlgItem(IDC_BTN_TAB_20)->EnableWindow(FALSE);
		pDlg->dlg_auto->process_pass_tab_20 = false;
		m_btn_tab_20.SetBitmap(m_bmp_tab_20);

		GetDlgItem(IDC_BTN_TAB_21)->EnableWindow(FALSE);
		pDlg->dlg_auto->process_pass_tab_21 = false;
		m_btn_tab_21.SetBitmap(m_bmp_tab_21);

		GetDlgItem(IDC_BTN_TAB_22)->EnableWindow(FALSE);
		pDlg->dlg_auto->process_pass_tab_22 = false;
		m_btn_tab_22.SetBitmap(m_bmp_tab_22);

		GetDlgItem(IDC_BTN_TAB_23)->EnableWindow(FALSE);
		pDlg->dlg_auto->process_pass_tab_23 = false;
		m_btn_tab_23.SetBitmap(m_bmp_tab_23);

		GetDlgItem(IDC_BTN_TAB_24)->EnableWindow(FALSE);
		pDlg->dlg_auto->process_pass_tab_24 = false;
		m_btn_tab_24.SetBitmap(m_bmp_tab_24);

		GetDlgItem(IDC_BTN_TAB_25)->EnableWindow(FALSE);
		pDlg->dlg_auto->process_pass_tab_25 = false;
		m_btn_tab_25.SetBitmap(m_bmp_tab_25);

		GetDlgItem(IDC_BTN_TAB_26)->EnableWindow(FALSE);
		pDlg->dlg_auto->process_pass_tab_26 = false;
		m_btn_tab_26.SetBitmap(m_bmp_tab_26);

		GetDlgItem(IDC_BTN_TAB_27)->EnableWindow(FALSE);
		pDlg->dlg_auto->process_pass_tab_27 = false;
		m_btn_tab_27.SetBitmap(m_bmp_tab_27);

		GetDlgItem(IDC_BTN_TAB_28)->EnableWindow(FALSE);
		pDlg->dlg_auto->process_pass_tab_28 = false;
		m_btn_tab_28.SetBitmap(m_bmp_tab_28);

		GetDlgItem(IDC_BTN_TAB_29)->EnableWindow(FALSE);
		pDlg->dlg_auto->process_pass_tab_29 = false;
		m_btn_tab_29.SetBitmap(m_bmp_tab_29);

		GetDlgItem(IDC_BTN_TAB_30)->EnableWindow(FALSE);
		pDlg->dlg_auto->process_pass_tab_30 = false;
		m_btn_tab_30.SetBitmap(m_bmp_tab_30);

	}*/
}


void DIALOG_SETTING_PROCESS::PassTab(int TabNum)
{
	CREVIEWAREADlg *pDlg = (CREVIEWAREADlg*)AfxGetMainWnd();

	if (TabNum == 1)
	{
		if (pDlg->dlg_auto->process_pass_tab_1 == true)
		{
			pDlg->dlg_auto->process_pass_tab_1 = false;
			m_btn_tab_1.SetBitmap(m_bmp_tab_1);
		}

		else if (pDlg->dlg_auto->process_pass_tab_1 == false)
		{
			pDlg->dlg_auto->process_pass_tab_1 = true;
			m_btn_tab_1.SetBitmap(m_bmp_tab_1_a);
		}
	}

	else if (TabNum == 2)
	{
		if (pDlg->dlg_auto->process_pass_tab_2 == true)
		{
			pDlg->dlg_auto->process_pass_tab_2 = false;
			m_btn_tab_2.SetBitmap(m_bmp_tab_2);
		}

		else if (pDlg->dlg_auto->process_pass_tab_2 == false)
		{
			pDlg->dlg_auto->process_pass_tab_2 = true;
			m_btn_tab_2.SetBitmap(m_bmp_tab_2_a);
		}
	}

	else if (TabNum == 3)
	{
		if (pDlg->dlg_auto->process_pass_tab_3 == true)
		{
			pDlg->dlg_auto->process_pass_tab_3 = false;
			m_btn_tab_3.SetBitmap(m_bmp_tab_3);
		}

		else if (pDlg->dlg_auto->process_pass_tab_3 == false)
		{
			pDlg->dlg_auto->process_pass_tab_3 = true;
			m_btn_tab_3.SetBitmap(m_bmp_tab_3_a);
		}
	}

	else if (TabNum == 4)
	{
		if (pDlg->dlg_auto->process_pass_tab_4 == true)
		{
			pDlg->dlg_auto->process_pass_tab_4 = false;
			m_btn_tab_4.SetBitmap(m_bmp_tab_4);
		}

		else if (pDlg->dlg_auto->process_pass_tab_4 == false)
		{
			pDlg->dlg_auto->process_pass_tab_4 = true;
			m_btn_tab_4.SetBitmap(m_bmp_tab_4_a);
		}
	}

	else if (TabNum == 5)
	{
		if (pDlg->dlg_auto->process_pass_tab_5 == true)
		{
			pDlg->dlg_auto->process_pass_tab_5 = false;
			m_btn_tab_5.SetBitmap(m_bmp_tab_5);
		}

		else if (pDlg->dlg_auto->process_pass_tab_5 == false)
		{
			pDlg->dlg_auto->process_pass_tab_5 = true;
			m_btn_tab_5.SetBitmap(m_bmp_tab_5_a);
		}
	}

	else if (TabNum == 6)
	{
		if (pDlg->dlg_auto->process_pass_tab_6 == true)
		{
			pDlg->dlg_auto->process_pass_tab_6 = false;
			m_btn_tab_6.SetBitmap(m_bmp_tab_6);
		}

		else if (pDlg->dlg_auto->process_pass_tab_6 == false)
		{
			pDlg->dlg_auto->process_pass_tab_6 = true;
			m_btn_tab_6.SetBitmap(m_bmp_tab_6_a);
		}
	}

	else if (TabNum == 7)
	{
		if (pDlg->dlg_auto->process_pass_tab_7 == true)
		{
			pDlg->dlg_auto->process_pass_tab_7 = false;
			m_btn_tab_7.SetBitmap(m_bmp_tab_7);
		}

		else if (pDlg->dlg_auto->process_pass_tab_7 == false)
		{
			pDlg->dlg_auto->process_pass_tab_7 = true;
			m_btn_tab_7.SetBitmap(m_bmp_tab_7_a);
		}
	}

	else if (TabNum == 8)
	{
		if (pDlg->dlg_auto->process_pass_tab_8 == true)
		{
			pDlg->dlg_auto->process_pass_tab_8 = false;
			m_btn_tab_8.SetBitmap(m_bmp_tab_8);
		}

		else if (pDlg->dlg_auto->process_pass_tab_8 == false)
		{
			pDlg->dlg_auto->process_pass_tab_8 = true;
			m_btn_tab_8.SetBitmap(m_bmp_tab_8_a);
		}
	}

	else if (TabNum == 9)
	{
		if (pDlg->dlg_auto->process_pass_tab_9 == true)
		{
			pDlg->dlg_auto->process_pass_tab_9 = false;
			m_btn_tab_9.SetBitmap(m_bmp_tab_9);
		}

		else if (pDlg->dlg_auto->process_pass_tab_9 == false)
		{
			pDlg->dlg_auto->process_pass_tab_9 = true;
			m_btn_tab_9.SetBitmap(m_bmp_tab_9_a);
		}
	}

	else if (TabNum == 10)
	{
		if (pDlg->dlg_auto->process_pass_tab_10 == true)
		{
			pDlg->dlg_auto->process_pass_tab_10 = false;
			m_btn_tab_10.SetBitmap(m_bmp_tab_10);
		}

		else if (pDlg->dlg_auto->process_pass_tab_10 == false)
		{
			pDlg->dlg_auto->process_pass_tab_10 = true;
			m_btn_tab_10.SetBitmap(m_bmp_tab_10_a);
		}
	}

	else if (TabNum == 11)
	{
		if (pDlg->dlg_auto->process_pass_tab_11 == true)
		{
			pDlg->dlg_auto->process_pass_tab_11 = false;
			m_btn_tab_11.SetBitmap(m_bmp_tab_11);
		}

		else if (pDlg->dlg_auto->process_pass_tab_11 == false)
		{
			pDlg->dlg_auto->process_pass_tab_11 = true;
			m_btn_tab_11.SetBitmap(m_bmp_tab_11_a);
		}
	}

	else if (TabNum == 12)
	{
		if (pDlg->dlg_auto->process_pass_tab_12 == true)
		{
			pDlg->dlg_auto->process_pass_tab_12 = false;
			m_btn_tab_12.SetBitmap(m_bmp_tab_12);
		}

		else if (pDlg->dlg_auto->process_pass_tab_12 == false)
		{
			pDlg->dlg_auto->process_pass_tab_12 = true;
			m_btn_tab_12.SetBitmap(m_bmp_tab_12_a);
		}
	}

	else if (TabNum == 13)
	{
		if (pDlg->dlg_auto->process_pass_tab_13 == true)
		{
			pDlg->dlg_auto->process_pass_tab_13 = false;
			m_btn_tab_13.SetBitmap(m_bmp_tab_13);
		}

		else if (pDlg->dlg_auto->process_pass_tab_13 == false)
		{
			pDlg->dlg_auto->process_pass_tab_13 = true;
			m_btn_tab_13.SetBitmap(m_bmp_tab_13_a);
		}
	}

	else if (TabNum == 14)
	{
		if (pDlg->dlg_auto->process_pass_tab_14 == true)
		{
			pDlg->dlg_auto->process_pass_tab_14 = false;
			m_btn_tab_14.SetBitmap(m_bmp_tab_14);
		}

		else if (pDlg->dlg_auto->process_pass_tab_14 == false)
		{
			pDlg->dlg_auto->process_pass_tab_14 = true;
			m_btn_tab_14.SetBitmap(m_bmp_tab_14_a);
		}
	}

	else if (TabNum == 15)
	{
		if (pDlg->dlg_auto->process_pass_tab_15 == true)
		{
			pDlg->dlg_auto->process_pass_tab_15 = false;
			m_btn_tab_15.SetBitmap(m_bmp_tab_15);
		}

		else if (pDlg->dlg_auto->process_pass_tab_15 == false)
		{
			pDlg->dlg_auto->process_pass_tab_15 = true;
			m_btn_tab_15.SetBitmap(m_bmp_tab_15_a);
		}
	}

	else if (TabNum == 16)
	{
		if (pDlg->dlg_auto->process_pass_tab_16 == true)
		{
			pDlg->dlg_auto->process_pass_tab_16 = false;
			m_btn_tab_16.SetBitmap(m_bmp_tab_16);
		}

		else if (pDlg->dlg_auto->process_pass_tab_16 == false)
		{
			pDlg->dlg_auto->process_pass_tab_16 = true;
			m_btn_tab_16.SetBitmap(m_bmp_tab_16_a);
		}
	}

	else if (TabNum == 17)
	{
		if (pDlg->dlg_auto->process_pass_tab_17 == true)
		{
			pDlg->dlg_auto->process_pass_tab_17 = false;
			m_btn_tab_17.SetBitmap(m_bmp_tab_17);
		}

		else if (pDlg->dlg_auto->process_pass_tab_17 == false)
		{
			pDlg->dlg_auto->process_pass_tab_17 = true;
			m_btn_tab_17.SetBitmap(m_bmp_tab_17_a);
		}
	}

	else if (TabNum == 18)
	{
		if (pDlg->dlg_auto->process_pass_tab_18 == true)
		{
			pDlg->dlg_auto->process_pass_tab_18 = false;
			m_btn_tab_18.SetBitmap(m_bmp_tab_18);
		}

		else if (pDlg->dlg_auto->process_pass_tab_18 == false)
		{
			pDlg->dlg_auto->process_pass_tab_18 = true;
			m_btn_tab_18.SetBitmap(m_bmp_tab_18_a);
		}
	}

	else if (TabNum == 19)
	{
		if (pDlg->dlg_auto->process_pass_tab_19 == true)
		{
			pDlg->dlg_auto->process_pass_tab_19 = false;
			m_btn_tab_19.SetBitmap(m_bmp_tab_19);
		}

		else if (pDlg->dlg_auto->process_pass_tab_19 == false)
		{
			pDlg->dlg_auto->process_pass_tab_19 = true;
			m_btn_tab_19.SetBitmap(m_bmp_tab_19_a);
		}
	}

	else if (TabNum == 20)
	{
		if (pDlg->dlg_auto->process_pass_tab_20 == true)
		{
			pDlg->dlg_auto->process_pass_tab_20 = false;
			m_btn_tab_20.SetBitmap(m_bmp_tab_20);
		}

		else if (pDlg->dlg_auto->process_pass_tab_20 == false)
		{
			pDlg->dlg_auto->process_pass_tab_20 = true;
			m_btn_tab_20.SetBitmap(m_bmp_tab_20_a);
		}
	}

	else if (TabNum == 21)
	{
		if (pDlg->dlg_auto->process_pass_tab_21 == true)
		{
			pDlg->dlg_auto->process_pass_tab_21 = false;
			m_btn_tab_21.SetBitmap(m_bmp_tab_21);
		}

		else if (pDlg->dlg_auto->process_pass_tab_21 == false)
		{
			pDlg->dlg_auto->process_pass_tab_21 = true;
			m_btn_tab_21.SetBitmap(m_bmp_tab_21_a);
		}
	}

	else if (TabNum == 22)
	{
		if (pDlg->dlg_auto->process_pass_tab_22 == true)
		{
			pDlg->dlg_auto->process_pass_tab_22 = false;
			m_btn_tab_22.SetBitmap(m_bmp_tab_22);
		}

		else if (pDlg->dlg_auto->process_pass_tab_22 == false)
		{
			pDlg->dlg_auto->process_pass_tab_22 = true;
			m_btn_tab_22.SetBitmap(m_bmp_tab_22_a);
		}
	}

	else if (TabNum == 23)
	{
		if (pDlg->dlg_auto->process_pass_tab_23 == true)
		{
			pDlg->dlg_auto->process_pass_tab_23 = false;
			m_btn_tab_23.SetBitmap(m_bmp_tab_23);
		}

		else if (pDlg->dlg_auto->process_pass_tab_23 == false)
		{
			pDlg->dlg_auto->process_pass_tab_23 = true;
			m_btn_tab_23.SetBitmap(m_bmp_tab_23_a);
		}
	}

	else if (TabNum == 24)
	{
		if (pDlg->dlg_auto->process_pass_tab_24 == true)
		{
			pDlg->dlg_auto->process_pass_tab_24 = false;
			m_btn_tab_24.SetBitmap(m_bmp_tab_24);
		}

		else if (pDlg->dlg_auto->process_pass_tab_24 == false)
		{
			pDlg->dlg_auto->process_pass_tab_4 = true;
			m_btn_tab_24.SetBitmap(m_bmp_tab_24_a);
		}
	}

	else if (TabNum == 25)
	{
		if (pDlg->dlg_auto->process_pass_tab_25 == true)
		{
			pDlg->dlg_auto->process_pass_tab_25 = false;
			m_btn_tab_25.SetBitmap(m_bmp_tab_25);
		}

		else if (pDlg->dlg_auto->process_pass_tab_25 == false)
		{
			pDlg->dlg_auto->process_pass_tab_25 = true;
			m_btn_tab_25.SetBitmap(m_bmp_tab_25_a);
		}
	}

	else if (TabNum == 26)
	{
		if (pDlg->dlg_auto->process_pass_tab_26 == true)
		{
			pDlg->dlg_auto->process_pass_tab_26 = false;
			m_btn_tab_26.SetBitmap(m_bmp_tab_26);
		}

		else if (pDlg->dlg_auto->process_pass_tab_26 == false)
		{
			pDlg->dlg_auto->process_pass_tab_26 = true;
			m_btn_tab_26.SetBitmap(m_bmp_tab_26_a);
		}
	}

	else if (TabNum == 27)
	{
		if (pDlg->dlg_auto->process_pass_tab_27 == true)
		{
			pDlg->dlg_auto->process_pass_tab_27 = false;
			m_btn_tab_27.SetBitmap(m_bmp_tab_27);
		}

		else if (pDlg->dlg_auto->process_pass_tab_27 == false)
		{
			pDlg->dlg_auto->process_pass_tab_27 = true;
			m_btn_tab_27.SetBitmap(m_bmp_tab_27_a);
		}
	}

	else if (TabNum == 28)
	{
		if (pDlg->dlg_auto->process_pass_tab_28 == true)
		{
			pDlg->dlg_auto->process_pass_tab_28 = false;
			m_btn_tab_28.SetBitmap(m_bmp_tab_28);
		}

		else if (pDlg->dlg_auto->process_pass_tab_28 == false)
		{
			pDlg->dlg_auto->process_pass_tab_28 = true;
			m_btn_tab_28.SetBitmap(m_bmp_tab_28_a);
		}
	}

	else if (TabNum == 29)
	{
		if (pDlg->dlg_auto->process_pass_tab_29 == true)
		{
			pDlg->dlg_auto->process_pass_tab_29 = false;
			m_btn_tab_29.SetBitmap(m_bmp_tab_29);
		}

		else if (pDlg->dlg_auto->process_pass_tab_29 == false)
		{
			pDlg->dlg_auto->process_pass_tab_29 = true;
			m_btn_tab_29.SetBitmap(m_bmp_tab_29_a);
		}
	}

	else if (TabNum == 30)
	{
		if (pDlg->dlg_auto->process_pass_tab_30 == true)
		{
			pDlg->dlg_auto->process_pass_tab_30 = false;
			m_btn_tab_30.SetBitmap(m_bmp_tab_30);
		}

		else if (pDlg->dlg_auto->process_pass_tab_30 == false)
		{
			pDlg->dlg_auto->process_pass_tab_30 = true;
			m_btn_tab_30.SetBitmap(m_bmp_tab_30_a);
		}
	}

}
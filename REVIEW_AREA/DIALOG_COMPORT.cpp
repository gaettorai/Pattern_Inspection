// DIALOG_COMPORT.cpp: 구현 파일
//

#include "stdafx.h"
#include "REVIEW_AREA.h"
#include "DIALOG_COMPORT.h"
#include "afxdialogex.h"


// DIALOG_COMPORT 대화 상자

IMPLEMENT_DYNAMIC(DIALOG_COMPORT, CDialogEx)

DIALOG_COMPORT::DIALOG_COMPORT(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_COMPORT, pParent)
{

}

DIALOG_COMPORT::~DIALOG_COMPORT()
{
}

void DIALOG_COMPORT::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CMB_PORT_1, m_cmb_port_1);
	DDX_Control(pDX, IDC_CMB_BAUD_1, m_cmb_baud_1);
	DDX_Control(pDX, IDC_CMB_DATABIT_1, m_cmb_databit_1);
	DDX_Control(pDX, IDC_CMB_PARITY_1, m_cmb_parity_1);
	DDX_Control(pDX, IDC_CMB_STOPBIT_1, m_cmb_stopbit_1);
	DDX_Control(pDX, IDC_CMB_PORT_2, m_cmb_port_2);
	DDX_Control(pDX, IDC_CMB_BAUD_2, m_cmb_baud_2);
	DDX_Control(pDX, IDC_CMB_DATABIT_2, m_cmb_databit_2);
	DDX_Control(pDX, IDC_CMB_PARITY_2, m_cmb_parity_2);
	DDX_Control(pDX, IDC_CMB_STOPBIT_2, m_cmb_stopbit_2);
	DDX_Control(pDX, IDC_CMB_PORT_3, m_cmb_port_3);
	DDX_Control(pDX, IDC_CMB_BAUD_3, m_cmb_baud_3);
	DDX_Control(pDX, IDC_CMB_DATABIT_3, m_cmb_databit_3);
	DDX_Control(pDX, IDC_CMB_PARITY_3, m_cmb_parity_3);
	DDX_Control(pDX, IDC_CMB_STOPBIT_3, m_cmb_stopbit_3);
	DDX_Control(pDX, IDC_CMB_PORT_4, m_cmb_port_4);
	DDX_Control(pDX, IDC_CMB_BAUD_4, m_cmb_baud_4);
	DDX_Control(pDX, IDC_CMB_DATABIT_4, m_cmb_databit_4);
	DDX_Control(pDX, IDC_CMB_PARITY_4, m_cmb_parity_4);
	DDX_Control(pDX, IDC_CMB_STOPBIT_4, m_cmb_stopbit_4);
}


BEGIN_MESSAGE_MAP(DIALOG_COMPORT, CDialogEx)
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// DIALOG_COMPORT 메시지 처리기


HBRUSH DIALOG_COMPORT::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}


BOOL DIALOG_COMPORT::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	return CDialogEx::OnEraseBkgnd(pDC);
}


BOOL DIALOG_COMPORT::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	
	SetWindowPos(&wndTop, 700, 250, 480, 500, SWP_SHOWWINDOW);
	
	GetDlgItem(IDC_GRP_UPPER_LIGHT)->MoveWindow(20, 30, 200, 180);
	GetDlgItem(IDC_STATIC_PORT_1)->MoveWindow(40, 50, 80, 20);
	GetDlgItem(IDC_STATIC_BAUD_1)->MoveWindow(40, 80, 80, 20);
	GetDlgItem(IDC_STATIC_DATABIT_1)->MoveWindow(40, 110, 80, 20);
	GetDlgItem(IDC_STATIC_PARITY_1)->MoveWindow(40, 140, 80, 20);
	GetDlgItem(IDC_STATIC_STOPBIT_1)->MoveWindow(40, 170, 80, 20);
	
	GetDlgItem(IDC_CMB_PORT_1)->MoveWindow(120, 50, 80, 20);
	GetDlgItem(IDC_CMB_BAUD_1)->MoveWindow(120, 80, 80, 20);
	GetDlgItem(IDC_CMB_DATABIT_1)->MoveWindow(120, 110, 80, 20);
	GetDlgItem(IDC_CMB_PARITY_1)->MoveWindow(120, 140, 80, 20);
	GetDlgItem(IDC_CMB_STOPBIT_1)->MoveWindow(120, 170, 80, 20);

	GetDlgItem(IDC_GRP_SIDE_LIGHT)->MoveWindow(250, 30, 200, 180);
	GetDlgItem(IDC_STATIC_PORT_2)->MoveWindow(270, 50, 80, 20);
	GetDlgItem(IDC_STATIC_BAUD_2)->MoveWindow(270, 80, 80, 20);
	GetDlgItem(IDC_STATIC_DATABIT_2)->MoveWindow(270, 110, 80, 20);
	GetDlgItem(IDC_STATIC_PARITY_2)->MoveWindow(270, 140, 80, 20);
	GetDlgItem(IDC_STATIC_STOPBIT_2)->MoveWindow(270, 170, 80, 20);

	GetDlgItem(IDC_CMB_PORT_2)->MoveWindow(350, 50, 80, 20);
	GetDlgItem(IDC_CMB_BAUD_2)->MoveWindow(350, 80, 80, 20);
	GetDlgItem(IDC_CMB_DATABIT_2)->MoveWindow(350, 110, 80, 20);
	GetDlgItem(IDC_CMB_PARITY_2)->MoveWindow(350, 140, 80, 20);
	GetDlgItem(IDC_CMB_STOPBIT_2)->MoveWindow(350, 170, 80, 20);

	GetDlgItem(IDC_GRP_UPPER_AF)->MoveWindow(20, 230, 200, 180);
	GetDlgItem(IDC_STATIC_PORT_3)->MoveWindow(40, 250, 80, 20);
	GetDlgItem(IDC_STATIC_BAUD_3)->MoveWindow(40, 280, 80, 20);
	GetDlgItem(IDC_STATIC_DATABIT_3)->MoveWindow(40, 310, 80, 20);
	GetDlgItem(IDC_STATIC_PARITY_3)->MoveWindow(40, 340, 80, 20);
	GetDlgItem(IDC_STATIC_STOPBIT_3)->MoveWindow(40, 370, 80, 20);

	GetDlgItem(IDC_CMB_PORT_3)->MoveWindow(120, 250, 80, 20);
	GetDlgItem(IDC_CMB_BAUD_3)->MoveWindow(120, 280, 80, 20);
	GetDlgItem(IDC_CMB_DATABIT_3)->MoveWindow(120, 310, 80, 20);
	GetDlgItem(IDC_CMB_PARITY_3)->MoveWindow(120, 340, 80, 20);
	GetDlgItem(IDC_CMB_STOPBIT_3)->MoveWindow(120, 370, 80, 20);

	GetDlgItem(IDC_GRP_SIDE_AF)->MoveWindow(250, 230, 200, 180);
	GetDlgItem(IDC_STATIC_PORT_4)->MoveWindow(270, 250, 80, 20);
	GetDlgItem(IDC_STATIC_BAUD_4)->MoveWindow(270, 280, 80, 20);
	GetDlgItem(IDC_STATIC_DATABIT_4)->MoveWindow(270, 310, 80, 20);
	GetDlgItem(IDC_STATIC_PARITY_4)->MoveWindow(270, 340, 80, 20);
	GetDlgItem(IDC_STATIC_STOPBIT_4)->MoveWindow(270, 370, 80, 20);

	GetDlgItem(IDC_CMB_PORT_4)->MoveWindow(350, 250, 80, 20);
	GetDlgItem(IDC_CMB_BAUD_4)->MoveWindow(350, 280, 80, 20);
	GetDlgItem(IDC_CMB_DATABIT_4)->MoveWindow(350, 310, 80, 20);
	GetDlgItem(IDC_CMB_PARITY_4)->MoveWindow(350, 340, 80, 20);
	GetDlgItem(IDC_CMB_STOPBIT_4)->MoveWindow(350, 370, 80, 20);

	m_cmb_port_1.SetCurSel(6);
	m_cmb_baud_1.SetCurSel(1);
	m_cmb_databit_1.SetCurSel(3);
	m_cmb_parity_1.SetCurSel(0);
	m_cmb_stopbit_1.SetCurSel(0);

	m_cmb_port_2.SetCurSel(7);
	m_cmb_baud_2.SetCurSel(1);
	m_cmb_databit_2.SetCurSel(3);
	m_cmb_parity_2.SetCurSel(0);
	m_cmb_stopbit_2.SetCurSel(0);

	m_cmb_port_3.SetCurSel(8);
	m_cmb_baud_3.SetCurSel(1);
	m_cmb_databit_3.SetCurSel(3);
	m_cmb_parity_3.SetCurSel(0);
	m_cmb_stopbit_3.SetCurSel(0);

	m_cmb_port_4.SetCurSel(9);
	m_cmb_baud_4.SetCurSel(1);
	m_cmb_databit_4.SetCurSel(3);
	m_cmb_parity_4.SetCurSel(0);
	m_cmb_stopbit_4.SetCurSel(0);

	GetDlgItem(IDOK)->MoveWindow(270, 420, 80, 30);
	GetDlgItem(IDCANCEL)->MoveWindow(360, 420, 80, 30);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


BOOL DIALOG_COMPORT::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	return CDialogEx::PreTranslateMessage(pMsg);
}

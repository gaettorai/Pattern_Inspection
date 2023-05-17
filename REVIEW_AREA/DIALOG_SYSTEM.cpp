// DIALOG_SYSTEM.cpp: 구현 파일
//

#include "stdafx.h"
#include "REVIEW_AREA.h"
#include "DIALOG_SYSTEM.h"
#include "afxdialogex.h"

#include "REVIEW_AREADlg.h"

// DIALOG_SYSTEM 대화 상자

IMPLEMENT_DYNAMIC(DIALOG_SYSTEM, CDialogEx)

DIALOG_SYSTEM::DIALOG_SYSTEM(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SYSTEM, pParent)
{
}

DIALOG_SYSTEM::~DIALOG_SYSTEM()
{
}

void DIALOG_SYSTEM::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_ID, m_edit_id);
	DDX_Control(pDX, IDC_EDIT_PASSWORD, m_edit_password);
	DDX_Control(pDX, IDOK, m_btn_ok);
}


BEGIN_MESSAGE_MAP(DIALOG_SYSTEM, CDialogEx)
	ON_BN_CLICKED(IDOK, &DIALOG_SYSTEM::OnBnClickedOk)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// DIALOG_SYSTEM 메시지 처리기

BOOL DIALOG_SYSTEM::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	SetWindowPos(&wndTop, 800, 450, 300, 150, SWP_SHOWWINDOW);

	GetDlgItem(IDC_STATIC_ID)->MoveWindow(50, 10, 80, 20);
	GetDlgItem(IDC_STATIC_PASSWORD)->MoveWindow(50, 40, 80, 20);

	GetDlgItem(IDC_EDIT_ID)->MoveWindow(170, 10, 80, 20);
	GetDlgItem(IDC_EDIT_PASSWORD)->MoveWindow(170, 40, 80, 20);

	m_edit_id.SetWindowTextW(_T("admin"));
	m_edit_password.SetWindowTextW(_T("wiacorp"));

	GetDlgItem(IDOK)->MoveWindow(45, 70, 100, 30);
	GetDlgItem(IDCANCEL)->MoveWindow(155, 70, 100, 30);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


BOOL DIALOG_SYSTEM::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	return CDialogEx::PreTranslateMessage(pMsg);
}


void DIALOG_SYSTEM::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CREVIEWAREADlg *pDlg = (CREVIEWAREADlg*)AfxGetMainWnd();

	CString id;
	CString pw;

	m_edit_id.GetWindowTextW(id);
	m_edit_password.GetWindowTextW(pw);
	
	pDlg->str_id = id;
	pDlg->str_pw = pw;

	CDialogEx::OnOK();
}

void DIALOG_SYSTEM::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
	CREVIEWAREADlg *pDlg = (CREVIEWAREADlg*)AfxGetMainWnd();

	if (pDlg->check_login == 1)
	{
		GetDlgItem(IDOK)->SetWindowTextW(_T("LogOut"));
		GetDlgItem(IDC_EDIT_ID)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_PASSWORD)->EnableWindow(FALSE);
	}

	else if (pDlg->check_login == 0)
	{
		GetDlgItem(IDOK)->SetWindowTextW(_T("LogIn"));
	}
}

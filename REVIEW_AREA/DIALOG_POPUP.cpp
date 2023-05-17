// DIALOG_POPUP.cpp: 구현 파일
//

#include "stdafx.h"
#include "REVIEW_AREA.h"
#include "DIALOG_POPUP.h"
#include "afxdialogex.h"


// DIALOG_POPUP 대화 상자

IMPLEMENT_DYNAMIC(DIALOG_POPUP, CDialogEx)

DIALOG_POPUP::DIALOG_POPUP(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_POPUP, pParent)
{

}

DIALOG_POPUP::~DIALOG_POPUP()
{
}

void DIALOG_POPUP::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DIALOG_POPUP, CDialogEx)
END_MESSAGE_MAP()


// DIALOG_POPUP 메시지 처리기


BOOL DIALOG_POPUP::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	SetWindowPos(&wndTop, 800, 450, 300, 150, SWP_SHOWWINDOW);

	GetDlgItem(IDC_STATIC_POPUP)->MoveWindow(65, 30, 170, 30);

	GetDlgItem(IDOK)->MoveWindow(45, 60, 100, 40);
	GetDlgItem(IDCANCEL)->MoveWindow(155, 60, 100, 40);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


BOOL DIALOG_POPUP::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	return CDialogEx::PreTranslateMessage(pMsg);
}

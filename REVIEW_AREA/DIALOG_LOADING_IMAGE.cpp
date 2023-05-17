// DIALOG_LOADING_IMAGE.cpp: 구현 파일
//

#include "stdafx.h"
#include "REVIEW_AREA.h"
#include "DIALOG_LOADING_IMAGE.h"
#include "afxdialogex.h"


// DIALOG_LOADING_IMAGE 대화 상자

IMPLEMENT_DYNAMIC(DIALOG_LOADING_IMAGE, CDialog)

DIALOG_LOADING_IMAGE::DIALOG_LOADING_IMAGE(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_LOADING, pParent)
{

}

DIALOG_LOADING_IMAGE::~DIALOG_LOADING_IMAGE()
{
}

void DIALOG_LOADING_IMAGE::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DIALOG_LOADING_IMAGE, CDialog)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// DIALOG_LOADING_IMAGE 메시지 처리기

void DIALOG_LOADING_IMAGE::Show(UINT uMilliseconds)

{

	if (Create(IDD_DIALOG_LOADING, GetDesktopWindow()))

	{

		ShowWindow(SW_SHOWNORMAL);

		SetTimer(100, uMilliseconds, NULL);

	}

}




void DIALOG_LOADING_IMAGE::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialog::OnTimer(nIDEvent);
}


BOOL DIALOG_LOADING_IMAGE::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetTimer(1, 1, NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

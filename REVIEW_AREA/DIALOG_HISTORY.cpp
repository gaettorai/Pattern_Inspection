// DIALOG_HISTORY.cpp: 구현 파일
//

#include "stdafx.h"
#include "REVIEW_AREA.h"
#include "DIALOG_HISTORY.h"
#include "afxdialogex.h"


// DIALOG_HISTORY 대화 상자

IMPLEMENT_DYNAMIC(DIALOG_HISTORY, CDialogEx)

DIALOG_HISTORY::DIALOG_HISTORY(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_HISTORY, pParent)
{

}

DIALOG_HISTORY::~DIALOG_HISTORY()
{
}

void DIALOG_HISTORY::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_FOLDER, m_list_folder);
	DDX_Control(pDX, IDC_LIST_RESULT, m_list_result);
	DDX_Control(pDX, IDC_PIC_SELECT, m_pic_select);
	DDX_Control(pDX, IDC_TREE_FOLDER, m_tree_folder);
}


BEGIN_MESSAGE_MAP(DIALOG_HISTORY, CDialogEx)
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// DIALOG_HISTORY 메시지 처리기


HBRUSH DIALOG_HISTORY::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}


BOOL DIALOG_HISTORY::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	return CDialogEx::OnEraseBkgnd(pDC);
}


BOOL DIALOG_HISTORY::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	
	GetDlgItem(IDC_TREE_FOLDER)->MoveWindow(10, 10, 300, 1000);
	GetDlgItem(IDC_LIST_FOLDER)->MoveWindow(330, 10, 1080, 480);
	GetDlgItem(IDC_PIC_SELECT)->MoveWindow(330, 500, 256, 512);
	GetDlgItem(IDC_LIST_RESULT)->MoveWindow(600, 500, 810, 512);

	HFONT hNewFont;

	hNewFont = CreateFont(15, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_MODERN, _T("IMPACT"));
	m_list_folder.SendMessage(WM_SETFONT, (WPARAM)hNewFont, (LPARAM)TRUE);
	m_list_result.SendMessage(WM_SETFONT, (WPARAM)hNewFont, (LPARAM)TRUE);


	m_list_folder.InsertColumn(0, TEXT("이름"), LVCFMT_CENTER, 400);
	m_list_folder.InsertColumn(1, TEXT("수정한 날짜"), LVCFMT_CENTER, 300);
	m_list_folder.InsertColumn(2, TEXT("유형"), LVCFMT_CENTER, 200);
	m_list_folder.InsertColumn(3, TEXT("크기"), LVCFMT_CENTER, 180);

	//m_list_result.InsertColumn(0, TEXT(""), LVCFMT_CENTER, 100);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


BOOL DIALOG_HISTORY::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	return CDialogEx::PreTranslateMessage(pMsg);
}

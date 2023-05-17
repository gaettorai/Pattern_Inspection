// DIALOG_MANUAL_ALIGN.cpp: 구현 파일
//

#include "stdafx.h"
#include "REVIEW_AREA.h"
#include "DIALOG_MANUAL_ALIGN.h"
#include "afxdialogex.h"


// DIALOG_MANUAL_ALIGN 대화 상자

IMPLEMENT_DYNAMIC(DIALOG_MANUAL_ALIGN, CDialogEx)

DIALOG_MANUAL_ALIGN::DIALOG_MANUAL_ALIGN(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_MANUAL_ALIGN, pParent)
{

}

DIALOG_MANUAL_ALIGN::~DIALOG_MANUAL_ALIGN()
{
}

void DIALOG_MANUAL_ALIGN::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC_MANUAL_ALIGN, m_pic_manual_align);
}


BEGIN_MESSAGE_MAP(DIALOG_MANUAL_ALIGN, CDialogEx)
	ON_BN_CLICKED(IDOK, &DIALOG_MANUAL_ALIGN::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &DIALOG_MANUAL_ALIGN::OnBnClickedCancel)
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// DIALOG_MANUAL_ALIGN 메시지 처리기


BOOL DIALOG_MANUAL_ALIGN::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetWindowPos(&wndTop, 0, 0, 1120, 1050, SWP_SHOWWINDOW);

	GetDlgItem(IDC_PIC_MANUAL_ALIGN)->MoveWindow(0, 0, 1024, 1024);
	GetDlgItem(IDOK)->MoveWindow(1040, 924, 40, 40);
	GetDlgItem(IDCANCEL)->MoveWindow(1040, 984, 40, 40);

	hdc_align = GetDlgItem(IDC_PIC_MANUAL_ALIGN)->GetDC()->m_hDC;

	SetStretchBltMode(hdc_align, COLORONCOLOR);

	GetDlgItem(IDOK)->EnableWindow(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


BOOL DIALOG_MANUAL_ALIGN::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_RETURN) // ENTER키 눌릴 시
			return TRUE;
		else if (pMsg->wParam == VK_ESCAPE) // ESC키 눌릴 시
			return TRUE;
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}


void DIALOG_MANUAL_ALIGN::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}


void DIALOG_MANUAL_ALIGN::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}


HBRUSH DIALOG_MANUAL_ALIGN::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}


BOOL DIALOG_MANUAL_ALIGN::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	return CDialogEx::OnEraseBkgnd(pDC);
}


void DIALOG_MANUAL_ALIGN::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	GetDlgItem(IDOK)->EnableWindow(TRUE);

	clone_image = align_image.clone();

	x1 = (point.x * 2) - (mark_cols / 2);
	x2 = (point.x * 2) + (mark_cols / 2);
	y1 = (point.y * 2) - (mark_rows / 2);
	y2 = (point.y * 2) + (mark_rows / 2);

	rectangle(clone_image, Point(x1, y1), Point(x2, y2), Scalar(0, 255, 0), 8, 8, 0);

	StretchDIBits(hdc_align, 0, 0, 1024, 1024, 0, 0, clone_image.cols, clone_image.rows,
		clone_image.data, alignInfo, DIB_RGB_COLORS, SRCCOPY);

	CDialogEx::OnLButtonDown(nFlags, point);
}


void DIALOG_MANUAL_ALIGN::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.

	align_image = imread(file_name);

	alignInfo = (BITMAPINFO*)alignBuf;
	alignInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	alignInfo->bmiHeader.biWidth = align_image.cols;
	alignInfo->bmiHeader.biHeight = -(align_image.rows);
	alignInfo->bmiHeader.biBitCount = 24;
	alignInfo->bmiHeader.biPlanes = 1;
	alignInfo->bmiHeader.biCompression = BI_RGB;
	alignInfo->bmiHeader.biSizeImage = 0;
	alignInfo->bmiHeader.biXPelsPerMeter = 0;
	alignInfo->bmiHeader.biYPelsPerMeter = 0;
	alignInfo->bmiHeader.biClrUsed = 0;
	alignInfo->bmiHeader.biClrImportant = 0;


	StretchDIBits(hdc_align, 0, 0, 1024, 1024, 0, 0, align_image.cols, align_image.rows,
		align_image.data, alignInfo, DIB_RGB_COLORS, SRCCOPY);

	mark_image = imread("Data\\1. ALIGN\\1. REG\\upper_prealign.bmp");

	markInfo = (BITMAPINFO*)markBuf;
	markInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	markInfo->bmiHeader.biWidth = mark_image.cols;
	markInfo->bmiHeader.biHeight = -(mark_image.rows);
	markInfo->bmiHeader.biBitCount = 24;
	markInfo->bmiHeader.biPlanes = 1;
	markInfo->bmiHeader.biCompression = BI_RGB;
	markInfo->bmiHeader.biSizeImage = 0;
	markInfo->bmiHeader.biXPelsPerMeter = 0;
	markInfo->bmiHeader.biYPelsPerMeter = 0;
	markInfo->bmiHeader.biClrUsed = 0;
	markInfo->bmiHeader.biClrImportant = 0;

	mark_cols = mark_image.cols;
	mark_rows = mark_image.rows;
}

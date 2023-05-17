// DIALOG_MANUAL_SIDE.cpp: 구현 파일
//

#include "stdafx.h"
#include "REVIEW_AREA.h"
#include "DIALOG_MANUAL_SIDE.h"
#include "afxdialogex.h"

#include "REVIEW_AREADlg.h"
// DIALOG_MANUAL_SIDE 대화 상자

IMPLEMENT_DYNAMIC(DIALOG_MANUAL_SIDE, CDialogEx)

const int m_nLineSize = 15;
const int m_nBasic = 95;
const int m_nRepeat = 10;

DIALOG_MANUAL_SIDE::DIALOG_MANUAL_SIDE(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_MANUAL_SIDE, pParent)
{

}

DIALOG_MANUAL_SIDE::~DIALOG_MANUAL_SIDE()
{
}

void DIALOG_MANUAL_SIDE::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC_MANUAL_SIDE, m_pic_manual_side);
}


BEGIN_MESSAGE_MAP(DIALOG_MANUAL_SIDE, CDialogEx)
	ON_WM_SIZE()
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()


// DIALOG_MANUAL_SIDE 메시지 처리기


BOOL DIALOG_MANUAL_SIDE::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	GetDlgItem(IDC_PIC_MANUAL_SIDE)->MoveWindow(0, 0, 512, 512);

	scrollpos = 0;
	VScrollPos_ = 0;
	HScrollPos_ = 0;

	measure_mode = 0;
	click_count = 0;

	pen_line.CreatePen(PS_NULL, 1.0, RGB(255, 0, 0));
	pen_rectangle.CreatePen(PS_SOLID, 1.0, RGB(255, 0, 0));
	pen_circle.CreatePen(PS_SOLID, 1.0, RGB(255, 0, 0));
	pen_mark.CreatePen(PS_SOLID, 1.0, RGB(255, 0, 0));

	null_brush.CreateStockObject(NULL_BRUSH);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


BOOL DIALOG_MANUAL_SIDE::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	return CDialogEx::PreTranslateMessage(pMsg);
}


void DIALOG_MANUAL_SIDE::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.

	ViewWidth_ = width_value;
	ViewHeight_ = height_value;

	int HScrollMax = 0;
	HPageSize_ = 0;

	if (cx < ViewWidth_)
	{
		HScrollMax = ViewWidth_ - 1;
		HPageSize_ = cx;
		HScrollPos_ = min(HScrollPos_, ViewWidth_ - HPageSize_ - 1);
	}

	SCROLLINFO si;
	si.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;
	si.nMin = 0;
	si.nMax = HScrollMax;
	si.nPos = HScrollPos_;
	si.nPage = HPageSize_;
	SetScrollInfo(SB_HORZ, &si, TRUE);

	int VScrollMax = 0;
	VPageSize_ = 0;

	if (cy < ViewHeight_)
	{
		VScrollMax = ViewHeight_ - 1;
		VPageSize_ = cy;
		VScrollPos_ = min(VScrollPos_, ViewHeight_ - VPageSize_ - 1);
	}

	si.fMask = SIF_RANGE | SIF_PAGE | SIF_POS;
	si.nMin = 0;
	si.nMax = VScrollMax;
	si.nPos = VScrollPos_;
	si.nPage = VPageSize_;
	SetScrollInfo(SB_VERT, &si, TRUE);
}


void DIALOG_MANUAL_SIDE::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_nHdelta = 0;

	switch (nSBCode)
	{
	case SB_LINELEFT:
		m_nHdelta = -m_nBasic;
		break;
	case SB_PAGELEFT:
		m_nHdelta = -HPageSize_;
		break;
	case SB_THUMBTRACK:
		m_nHdelta = static_cast<int>(nPos) - HScrollPos_;
		break;
	case SB_PAGERIGHT:
		m_nHdelta = HPageSize_;
		break;
	case SB_LINERIGHT:
		m_nHdelta = m_nBasic;
		break;
	default:
		return;
	}

	int scrollpos = HScrollPos_ + m_nHdelta;
	int maxpos = ViewWidth_ - HPageSize_;

	if (scrollpos < 0)
		m_nHdelta = -HScrollPos_;
	else
		if (scrollpos > maxpos)
			m_nHdelta = maxpos - HScrollPos_;

	if (m_nHdelta != 0)
	{
		HScrollPos_ += m_nHdelta;
		SetScrollPos(SB_HORZ, HScrollPos_, TRUE);
		ScrollWindow(-m_nHdelta, 0);
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void DIALOG_MANUAL_SIDE::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int delta;

	switch (nSBCode)
	{
	case SB_LINEUP:
		delta = -m_nBasic;
		break;
	case SB_PAGEUP:
		delta = -VPageSize_;
		break;
	case SB_THUMBTRACK:
		delta = static_cast<int>(nPos) - VScrollPos_;
		break;
	case SB_PAGEDOWN:
		delta = VPageSize_;
		break;
	case SB_LINEDOWN:
		delta = m_nBasic;
		break;
	default:
		return;
	}

	scrollpos = VScrollPos_ + delta;
	int maxpos = ViewHeight_ - VPageSize_;
	if (scrollpos < 0)
		delta = -VScrollPos_;
	else
		if (scrollpos > maxpos)
			delta = maxpos - VScrollPos_;

	if (delta != 0)
	{
		VScrollPos_ += delta;
		SetScrollPos(SB_VERT, VScrollPos_, TRUE);
		ScrollWindow(0, -delta);
	}
	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}


int DIALOG_MANUAL_SIDE::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	width_value = 512;
	height_value = 512;

	return 0;
}


void DIALOG_MANUAL_SIDE::click_magni()
{
	RECT rc;
	GetClientRect(&rc);
	SendMessage(WM_SIZE, (WPARAM)SIZE_RESTORED, MAKELPARAM(rc.right - rc.left, rc.bottom - rc.top));
}

void DIALOG_MANUAL_SIDE::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CREVIEWAREADlg *pDlg = (CREVIEWAREADlg*)AfxGetMainWnd();

	if (pDlg->dlg_manual->measure_mode != 0)
	{
		click_count = 1;
		first_point.x = point.x + HScrollPos_;
		first_point.y = point.y + VScrollPos_;

		second_point.x = point.x + HScrollPos_;
		second_point.y = point.y + VScrollPos_;

		/*CRect rect;
		m_pic_manual_upper.GetWindowRect(&rect);
		ScreenToClient(&rect);

		ClipCursor(&rect);*/
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}


void DIALOG_MANUAL_SIDE::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CREVIEWAREADlg *pDlg = (CREVIEWAREADlg*)AfxGetMainWnd();

	if (pDlg->dlg_manual->measure_mode != 0)
	{
		// LINE
		if (pDlg->dlg_manual->measure_mode == 1)
		{
			if (click_count == 1)
			{
				CRect rt;
				CStatic * pStatic = (CStatic*)GetDlgItem(IDC_PIC_MANUAL_SIDE);
				CDC* pDC = pStatic->GetDC();
				pStatic->GetClientRect(&rt);

				CRgn rgn;
				rgn.CreateRectRgnIndirect(&rt);
				pDC->SelectClipRgn(&rgn);

				pDC->SelectObject(pen_rectangle);
				pDC->SelectObject(&null_brush);

				point.x = point.x + HScrollPos_;
				point.y = point.y + VScrollPos_;

				pDC->SetROP2(R2_NOT);

				pDC->MoveTo(first_point.x, first_point.y);
				pDC->LineTo(second_point.x, second_point.y);

				pDC->MoveTo(first_point.x, first_point.y);
				pDC->LineTo(point.x, point.y);

				second_point = point;

				ReleaseDC(pDC);
			}
		}

		// RECTANGLE
		else if (pDlg->dlg_manual->measure_mode == 2 || pDlg->dlg_manual->measure_mode == 4 || pDlg->dlg_manual->measure_mode == 5 || pDlg->dlg_manual->measure_mode == 7)
		{
			if (click_count == 1)
			{
				CRect rt;
				CStatic * pStatic = (CStatic*)GetDlgItem(IDC_PIC_MANUAL_SIDE);
				CDC* pDC = pStatic->GetDC();
				pStatic->GetClientRect(&rt);

				CRgn rgn;
				rgn.CreateRectRgnIndirect(&rt);
				pDC->SelectClipRgn(&rgn);

				pDC->SelectObject(pen_rectangle);
				pDC->SelectObject(&null_brush);

				point.x = point.x + HScrollPos_;
				point.y = point.y + VScrollPos_;

				pDC->SetROP2(R2_NOT);

				pDC->Rectangle(first_point.x, first_point.y, second_point.x, second_point.y);
				pDC->Rectangle(first_point.x, first_point.y, point.x, point.y);

				second_point = point;

				ReleaseDC(pDC);
			}
		}

		// CIRCLE
		else if (pDlg->dlg_manual->measure_mode == 3)
		{
			if (click_count == 1)
			{
				CRect rt;
				CStatic * pStatic = (CStatic*)GetDlgItem(IDC_PIC_MANUAL_SIDE);
				CDC* pDC = pStatic->GetDC();
				pStatic->GetClientRect(&rt);

				CRgn rgn;
				rgn.CreateRectRgnIndirect(&rt);
				pDC->SelectClipRgn(&rgn);

				pDC->SelectObject(pen_circle);
				pDC->SelectObject(&null_brush);

				point.x = point.x + HScrollPos_;
				point.y = point.y + VScrollPos_;


				dx = (point.x - first_point.x) * (point.x - first_point.x);
				dy = (point.y - first_point.y) * (point.y - first_point.y);

				radius = sqrt((double)(dx + dy));

				CPoint start_point;
				CPoint end_point;

				start_point.x = first_point.x - radius;
				start_point.y = first_point.y - radius;
				end_point.x = first_point.x + radius;
				end_point.y = first_point.y + radius;

				pDC->SetROP2(R2_NOT);
				pDC->Ellipse(start_point.x, start_point.y, end_point.x, end_point.y);
				pDC->MoveTo(first_point.x, first_point.y);
				pDC->LineTo(second_point.x, second_point.y);

				dx = (second_point.x - first_point.x) * (second_point.x - first_point.x);
				dy = (second_point.y - first_point.y) * (second_point.y - first_point.y);

				radius = sqrt((double)(dx + dy));

				start_point.x = first_point.x - radius;
				start_point.y = first_point.y - radius;
				end_point.x = first_point.x + radius;
				end_point.y = first_point.y + radius;

				pDC->Ellipse(start_point.x, start_point.y, end_point.x, end_point.y);
				pDC->MoveTo(first_point.x, first_point.y);
				pDC->LineTo(point.x, point.y);

				second_point = point;

				ReleaseDC(pDC);
			}
		}
	}
	CDialogEx::OnMouseMove(nFlags, point);
}


void DIALOG_MANUAL_SIDE::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CREVIEWAREADlg *pDlg = (CREVIEWAREADlg*)AfxGetMainWnd();

	if (pDlg->dlg_manual->measure_mode != 0)
	{
		// LINE
		if (pDlg->dlg_manual->measure_mode == 1)
		{
			CClientDC dc(this);

			CRect rt;
			CStatic * pStatic = (CStatic*)GetDlgItem(IDC_PIC_MANUAL_SIDE);
			CDC* pDC = pStatic->GetDC();
			pStatic->GetClientRect(&rt);

			CRgn rgn;
			rgn.CreateRectRgnIndirect(&rt);
			pDC->SelectClipRgn(&rgn);


			if (pDlg->dlg_manual->m_cmb_magni.GetCurSel() == 0)
			{
				dist_x = abs((second_point.x - first_point.x) * 4 * 0.55);
				dist_y = abs((second_point.y - first_point.y) * 4 * 0.55);

				dist_dia = abs(sqrt((dist_x * dist_x) + (dist_y * dist_y)));
			}

			else if (pDlg->dlg_manual->m_cmb_magni.GetCurSel() == 1)
			{
				dist_x = abs((second_point.x - first_point.x) * 2 * 0.55);
				dist_y = abs((second_point.y - first_point.y) * 2 * 0.55);

				dist_dia = abs(sqrt((dist_x * dist_x) + (dist_y * dist_y)));
			}

			str_line.Format(_T("%d_LINE : %.2f"), pDlg->dlg_manual->measure_count, dist_dia);

			str_measure_label.Format(_T("%d_LINE"), pDlg->dlg_manual->measure_count);
			str_measure_value.Format(_T("%.2f"), dist_dia);

			pDlg->dlg_manual->m_list_measure.InsertItem(pDlg->dlg_manual->list_count, str_measure_label);
			pDlg->dlg_manual->m_list_measure.SetItemText(pDlg->dlg_manual->list_count, 1, str_measure_value);
			pDlg->dlg_manual->list_count++;

			pDlg->dlg_manual->measure_count++;

			if (pDlg->dlg_manual->m_cmb_magni.GetCurSel() == 0)
				pDlg->dlg_auto->DrawLine(first_point, second_point, 2, str_line);

			else if (pDlg->dlg_manual->m_cmb_magni.GetCurSel() == 1)
			{
				first_point.x = first_point.x / 2;
				first_point.y = first_point.y / 2;

				second_point.x = second_point.x / 2;
				second_point.y = second_point.y / 2;

				pDlg->dlg_auto->DrawLine(first_point, second_point, 2, str_line);
			}
		}

		// RECTANGLE
		else if (pDlg->dlg_manual->measure_mode == 2 || pDlg->dlg_manual->measure_mode == 4 || pDlg->dlg_manual->measure_mode == 5 || pDlg->dlg_manual->measure_mode == 7)
		{
			if (click_count == 1)
			{
				CClientDC dc(this);

				CRect rt;
				CStatic * pStatic = (CStatic*)GetDlgItem(IDC_PIC_MANUAL_SIDE);
				CDC* pDC = pStatic->GetDC();
				pStatic->GetClientRect(&rt);

				CRgn rgn;
				rgn.CreateRectRgnIndirect(&rt);
				pDC->SelectClipRgn(&rgn);

				// draw rectangle
				if (pDlg->dlg_manual->measure_mode == 2)
				{
					// 측정 값
					if (pDlg->dlg_manual->m_cmb_magni.GetCurSel() == 0)
					{
						dist_x = abs((second_point.x - first_point.x) * 4 * 0.55);
						dist_y = abs((second_point.y - first_point.y) * 4 * 0.55);
					}

					else if (pDlg->dlg_manual->m_cmb_magni.GetCurSel() == 1)
					{
						dist_x = abs((second_point.x - first_point.x) * 2 * 0.55);
						dist_y = abs((second_point.y - first_point.y) * 2 * 0.55);
					}

					str_ver.Format(_T("%d_VER : %.2f"), pDlg->dlg_manual->measure_count, dist_x);
					str_hor.Format(_T("%d_HOR : %.2f"), pDlg->dlg_manual->measure_count, dist_y);

					str_measure_label.Format(_T("%d_VER"), pDlg->dlg_manual->measure_count);
					str_measure_value.Format(_T("%.2f"), dist_x);

					pDlg->dlg_manual->m_list_measure.InsertItem(pDlg->dlg_manual->list_count, str_measure_label);
					pDlg->dlg_manual->m_list_measure.SetItemText(pDlg->dlg_manual->list_count, 1, str_measure_value);
					pDlg->dlg_manual->list_count++;

					str_measure_label.Format(_T("%d_HOR"), pDlg->dlg_manual->measure_count);
					str_measure_value.Format(_T("%.2f"), dist_y);

					pDlg->dlg_manual->m_list_measure.InsertItem(pDlg->dlg_manual->list_count, str_measure_label);
					pDlg->dlg_manual->m_list_measure.SetItemText(pDlg->dlg_manual->list_count, 1, str_measure_value);

					pDlg->dlg_manual->list_count++;
					pDlg->dlg_manual->measure_count++;

					if (pDlg->dlg_manual->m_cmb_magni.GetCurSel() == 0)
						pDlg->dlg_auto->DrawRectangle(first_point, second_point, 2, str_ver, str_hor);

					else if (pDlg->dlg_manual->m_cmb_magni.GetCurSel() == 1)
					{
						first_point.x = first_point.x / 2;
						first_point.y = first_point.y / 2;

						second_point.x = second_point.x / 2;
						second_point.y = second_point.y / 2;

						pDlg->dlg_auto->DrawRectangle(first_point, second_point, 2, str_ver, str_hor);
					}
				}

				else if (pDlg->dlg_manual->measure_mode == 7)
				{
					pDC->SelectObject(pen_rectangle);
					pDC->SelectObject(&null_brush);

					pDC->SetROP2(R2_NOT);
					pDC->Rectangle(first_point.x, first_point.y, second_point.x, second_point.y);

					manual_side_image = imread("Data\\4. MEASURE\\1. ORIGIN\\SIDE.bmp");

					int rectangle_1_x;
					int rectangle_2_x;
					int rectangle_1_y;
					int rectangle_2_y;

					if (second_point.x > first_point.x)
					{
						rectangle_1_x = first_point.x;
						rectangle_2_x = second_point.x;
					}

					else if (second_point.x < first_point.x)
					{
						rectangle_1_x = second_point.x;
						rectangle_2_x = first_point.x;
					}

					if (second_point.y > first_point.y)
					{
						rectangle_1_y = first_point.y;
						rectangle_2_y = second_point.y;
					}

					else if (second_point.y < first_point.y)
					{
						rectangle_1_y = second_point.y;
						rectangle_2_y = first_point.y;
					}

					int d = rectangle_2_x - rectangle_1_x;
					int n = abs((rectangle_2_x - rectangle_1_x)) % 4;

					if (n != 0)
					{
						for (int i = rectangle_2_x; i > rectangle_2_x - 4; i--)
						{
							if ((i - rectangle_1_x) % 4 == 0)
								rectangle_2_x = i;
						}
					}

					if (pDlg->dlg_manual->m_cmb_magni.GetCurSel() == 0)
					{
						Rect mark_roi(rectangle_1_x * 4, rectangle_1_y * 4,
							(rectangle_2_x - rectangle_1_x) * 4, (rectangle_2_y - rectangle_1_y) * 4);
						manual_side_mark = manual_side_image(mark_roi);

					}

					else if (pDlg->dlg_manual->m_cmb_magni.GetCurSel() == 1)
					{
						Rect mark_roi(rectangle_1_x * 2, rectangle_1_y * 2,
							(rectangle_2_x - rectangle_1_x) * 2, (rectangle_2_y - rectangle_1_y) * 2);
						manual_side_mark = manual_side_image(mark_roi);

					}

					markInfo = (BITMAPINFO*)markBuf;
					markInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
					markInfo->bmiHeader.biWidth = manual_side_mark.cols;
					markInfo->bmiHeader.biHeight = -(manual_side_mark.rows);
					markInfo->bmiHeader.biBitCount = 24;
					markInfo->bmiHeader.biPlanes = 1;
					markInfo->bmiHeader.biCompression = BI_RGB;
					markInfo->bmiHeader.biSizeImage = 0;
					markInfo->bmiHeader.biXPelsPerMeter = 0;
					markInfo->bmiHeader.biYPelsPerMeter = 0;
					markInfo->bmiHeader.biClrUsed = 0;
					markInfo->bmiHeader.biClrImportant = 0;

					imwrite("mark_s.bmp", manual_side_mark);
					manual_side_mark = imread("mark_s.bmp");

					StretchDIBits(pDlg->dlg_manual->hdc_mark_side, 0, 0, 100, 100, 0, 0, manual_side_mark.cols, manual_side_mark.rows, manual_side_mark.data, markInfo, DIB_RGB_COLORS, SRCCOPY);

					pDlg->dlg_manual->GetDlgItem(IDC_BTN_SIDE_MARK_SAVE)->EnableWindow(TRUE);
				}
			}
		}

		// CIRCLE
		else if (pDlg->dlg_manual->measure_mode == 3)
		{
			CClientDC dc(this);

			CRect rt;
			CStatic * pStatic = (CStatic*)GetDlgItem(IDC_PIC_MANUAL_SIDE);
			CDC* pDC = pStatic->GetDC();
			pStatic->GetClientRect(&rt);

			CRgn rgn;
			rgn.CreateRectRgnIndirect(&rt);
			pDC->SelectClipRgn(&rgn);

			pDC->SelectObject(pen_circle);
			pDC->SelectObject(&null_brush);

			dx = (point.x - first_point.x) * (point.x - first_point.x);
			dy = (point.y - first_point.y) * (point.y - first_point.y);

			radius = sqrt((double)(dx + dy));

			dist_dia = abs(radius * 4 * 0.55);


			str_circle.Format(_T("%d_RADIUS : %.2f"), pDlg->dlg_manual->measure_count, dist_dia);

			str_measure_label.Format(_T("%d_RADIUS"), pDlg->dlg_manual->measure_count);
			str_measure_value.Format(_T("%.2f"), dist_dia);

			pDlg->dlg_manual->m_list_measure.InsertItem(pDlg->dlg_manual->list_count, str_measure_label);
			pDlg->dlg_manual->m_list_measure.SetItemText(pDlg->dlg_manual->list_count, 1, str_measure_value);
			pDlg->dlg_manual->list_count++;

			pDlg->dlg_manual->measure_count++;

			if (pDlg->dlg_manual->m_cmb_magni.GetCurSel() == 0)
			{
				pDlg->dlg_auto->DrawCircle(first_point, second_point, radius, 2, str_circle);
			}

			else if (pDlg->dlg_manual->m_cmb_magni.GetCurSel() == 1)
			{
				first_point.x = first_point.x / 2;
				first_point.y = first_point.y / 2;

				second_point.x = second_point.x / 2;
				second_point.y = second_point.y / 2;

				radius = radius / 2;

				pDlg->dlg_auto->DrawCircle(first_point, second_point, radius, 2, str_circle);
			}
		}

		click_count = 0;
	}

	CDialogEx::OnLButtonUp(nFlags, point);
}


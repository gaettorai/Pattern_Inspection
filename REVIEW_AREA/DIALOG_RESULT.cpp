// DIALOG_RESULT.cpp: 구현 파일
//

#include "stdafx.h"
#include "REVIEW_AREA.h"
#include "DIALOG_RESULT.h"
#include "afxdialogex.h"

#include "REVIEW_AREADlg.h"

// DIALOG_RESULT 대화 상자

IMPLEMENT_DYNAMIC(DIALOG_RESULT, CDialogEx)

DIALOG_RESULT::DIALOG_RESULT(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_RESULT, pParent)
{

}

DIALOG_RESULT::~DIALOG_RESULT()
{
}

void DIALOG_RESULT::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_TOTAL, m_list_total);
	DDX_Control(pDX, IDC_LIST_UPPER, m_list_upper);
	DDX_Control(pDX, IDC_LIST_SIDE, m_list_side);
	DDX_Control(pDX, IDC_PIC_RESULT_UPPER, m_pic_result_upper);
	DDX_Control(pDX, IDC_PIC_RESULT_SIDE, m_pic_result_side);
	DDX_Control(pDX, IDC_PIC_OVERLAY_UPPER, m_pic_overlay_upper);
	DDX_Control(pDX, IDC_PIC_OVERLAY_SIDE, m_pic_overlay_side);
	DDX_Control(pDX, IDC_LIST_SIDE_MARK, m_list_side_mark);
}


BEGIN_MESSAGE_MAP(DIALOG_RESULT, CDialogEx)
	ON_NOTIFY(NM_CLICK, IDC_LIST_TOTAL, &DIALOG_RESULT::OnClickListTotal)
	ON_NOTIFY(NM_CLICK, IDC_LIST_UPPER, &DIALOG_RESULT::OnClickListUpper)
	ON_NOTIFY(NM_CLICK, IDC_LIST_SIDE, &DIALOG_RESULT::OnClickListSide)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// DIALOG_RESULT 메시지 처리기


BOOL DIALOG_RESULT::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CClientDC dc(this);
	
	SetWindowPos(&wndTop, 100, 0, 1250, 1080, SWP_SHOWWINDOW);

	GetDlgItem(IDC_LIST_TOTAL)->MoveWindow(10, 10, 240, 250);
	GetDlgItem(IDC_LIST_SIDE_MARK)->MoveWindow(260, 10, 240, 250);

	GetDlgItem(IDC_STATIC_UPPER)->MoveWindow(10, 280, 500, 20);
	GetDlgItem(IDC_LIST_UPPER)->MoveWindow(10, 300, 500, 350);

	GetDlgItem(IDC_STATIC_SIDE)->MoveWindow(10, 660, 500, 20);
	GetDlgItem(IDC_LIST_SIDE)->MoveWindow(10, 680, 500, 354);

	GetDlgItem(IDC_STATIC_COLOR_MA)->MoveWindow(1070, 10, 80, 20);
	GetDlgItem(IDC_STATIC_COLOR_OPEN)->MoveWindow(1070, 40, 80, 20);
	GetDlgItem(IDC_STATIC_COLOR_SHORT)->MoveWindow(1070, 70, 80, 20);
	GetDlgItem(IDC_STATIC_COLOR_WIDTH)->MoveWindow(1070, 100, 80, 20);
	GetDlgItem(IDC_STATIC_COLOR_HEIGHT)->MoveWindow(1070, 130, 80, 20);
	GetDlgItem(IDC_STATIC_COLOR_BOTH)->MoveWindow(1070, 160, 80, 20);
	GetDlgItem(IDC_STATIC_COLOR_OK)->MoveWindow(1070, 190, 80, 20);

	ma_cl = RGB(ma_r, ma_g, ma_b);
	open_cl = RGB(open_r, open_g, open_b);
	short_cl = RGB(short_r, short_g, short_b);
	width_cl = RGB(width_r, width_g, width_b);
	height_cl = RGB(height_r, height_g, height_b);
	both_cl = RGB(both_r, both_g, both_b);
	ok_cl = RGB(0, 255, 0);

	GetDlgItem(IDC_PIC_RESULT_UPPER)->MoveWindow(540, 10, 512, 512);
	GetDlgItem(IDC_PIC_RESULT_SIDE)->MoveWindow(540 + (camera_offset / 4), 522, 512, 512);

	GetDlgItem(IDC_PIC_OVERLAY_UPPER)->MoveWindow(540, 10, 512, 512);
	GetDlgItem(IDC_PIC_OVERLAY_SIDE)->MoveWindow(540 + (camera_offset / 4), 522, 512, 512);

	GetDlgItem(IDOK)->MoveWindow(1102, 984, 50, 50);
	GetDlgItem(IDCANCEL)->MoveWindow(1162, 984, 50, 50);

	hdc_upper = GetDlgItem(IDC_PIC_RESULT_UPPER)->GetDC()->m_hDC;
	hdc_side = GetDlgItem(IDC_PIC_RESULT_SIDE)->GetDC()->m_hDC;

	SetStretchBltMode(hdc_upper, COLORONCOLOR);
	SetStretchBltMode(hdc_side, COLORONCOLOR);

	m_list_total.SetExtendedStyle(LVS_EX_CHECKBOXES);

	m_list_total.InsertColumn(0, TEXT("TAB."), LVCFMT_CENTER, 60);
	m_list_total.InsertColumn(1, TEXT("POINT"), LVCFMT_CENTER, 80);
	m_list_total.InsertColumn(2, TEXT("JUDGE"), LVCFMT_CENTER, 100);

	m_list_side_mark.InsertColumn(0, TEXT("TAB"), LVCFMT_CENTER, 50);
	m_list_side_mark.InsertColumn(1, TEXT("POINT"), LVCFMT_CENTER, 50);
	m_list_side_mark.InsertColumn(2, TEXT("MARK_1<->2"), LVCFMT_CENTER, 70);
	m_list_side_mark.InsertColumn(3, TEXT("MARK_2<->PAT."), LVCFMT_CENTER, 70);

	m_list_upper.InsertColumn(0, TEXT("NUM"), LVCFMT_CENTER, 50);
	m_list_upper.InsertColumn(1, TEXT("X"), LVCFMT_CENTER, 50);
	m_list_upper.InsertColumn(2, TEXT("WIDTH"), LVCFMT_CENTER, 50);
	m_list_upper.InsertColumn(3, TEXT("Y"), LVCFMT_CENTER, 50);
	m_list_upper.InsertColumn(4, TEXT("HEIGHT"), LVCFMT_CENTER, 50);
	m_list_upper.InsertColumn(5, TEXT("M.A_X"), LVCFMT_CENTER, 50);
	m_list_upper.InsertColumn(6, TEXT("JUDGE"), LVCFMT_CENTER, 100);

	m_list_side.InsertColumn(0, TEXT("NUM"), LVCFMT_CENTER, 50);
	m_list_side.InsertColumn(1, TEXT("X"), LVCFMT_CENTER, 50);
	m_list_side.InsertColumn(2, TEXT("WIDTH"), LVCFMT_CENTER, 50);
	m_list_side.InsertColumn(3, TEXT("Y"), LVCFMT_CENTER, 50);
	m_list_side.InsertColumn(4, TEXT("HEIGHT"), LVCFMT_CENTER, 50);
	m_list_side.InsertColumn(5, TEXT("OPEN"), LVCFMT_CENTER, 50);
	m_list_side.InsertColumn(6, TEXT("SHORT"), LVCFMT_CENTER, 50);
	m_list_side.InsertColumn(7, TEXT("JUDGE"), LVCFMT_CENTER, 150);

	pen_ok.CreatePen(PS_SOLID, 1.0, RGB(0,255,0));
	pen_ma.CreatePen(PS_SOLID, 1.0, ma_cl);
	pen_open.CreatePen(PS_SOLID, 1.0, open_cl);
	pen_short.CreatePen(PS_SOLID, 1.0, short_cl);
	pen_width.CreatePen(PS_SOLID, 1.0, width_cl);
	pen_height.CreatePen(PS_SOLID, 1.0, height_cl);
	pen_both.CreatePen(PS_SOLID, 1.0, both_cl);

	null_brush.CreateStockObject(NULL_BRUSH);


	if (check_manual == true)
	{
		m_list_total.InsertItem(0, _T("MANUAL"), 0); // tab
		m_list_total.SetItemText(0, 1, _T("MANUAL")); // point
	}

	else if (check_manual == false)
	{
		CString str_result;

		count = 0;
		int list_count = 0;
		CString str_registry;

		start_tab = 0;

		for (int i = start_tab; i < result_tab; i++)
		{
			CString tab_num;
			tab_num.Format(_T("%d"), i + 1);

			if (i == 0 && process_pass_tab_1 == true)
			{
				for (int j = 0; j < result_point; j++)
					count++;

				continue;
			}

			else if (i == 1 && process_pass_tab_2 == true)
			{
				for (int j = 0; j < result_point; j++)
					count++;

				continue;
			}

			else if (i == 2 && process_pass_tab_3 == true)
			{
				for (int j = 0; j < result_point; j++)
					count++;

				continue;
			}

			else if (i == 3 && process_pass_tab_4 == true)
			{
				for (int j = 0; j < result_point; j++)
					count++;

				continue;
			}

			else if (i == 4 && process_pass_tab_5 == true)
			{
				for (int j = 0; j < result_point; j++)
					count++;

				continue;
			}

			else if (i == 5 && process_pass_tab_6 == true)
			{
				for (int j = 0; j < result_point; j++)
					count++;

				continue;
			}

			else if (i == 6 && process_pass_tab_7 == true)
			{
				for (int j = 0; j < result_point; j++)
					count++;

				continue;
			}

			else if (i == 7 && process_pass_tab_8 == true)
			{
				for (int j = 0; j < result_point; j++)
					count++;

				continue;
			}

			else if (i == 8 && process_pass_tab_9 == true)
			{
				for (int j = 0; j < result_point; j++)
					count++;

				continue;
			}

			else if (i == 9 && process_pass_tab_10 == true)
			{
				for (int j = 0; j < result_point; j++)
					count++;

				continue;
			}

			else if (i == 10 && process_pass_tab_11 == true)
			{
				for (int j = 0; j < result_point; j++)
					count++;

				continue;
			}

			else if (i == 11 && process_pass_tab_12 == true)
			{
				for (int j = 0; j < result_point; j++)
					count++;

				continue;
			}

			else if (i == 12 && process_pass_tab_13 == true)
			{
				for (int j = 0; j < result_point; j++)
					count++;

				continue;
			}

			else if (i == 13 && process_pass_tab_14 == true)
			{
				for (int j = 0; j < result_point; j++)
					count++;

				continue;
			}

			else if (i == 14 && process_pass_tab_15 == true)
			{
				for (int j = 0; j < result_point; j++)
					count++;

				continue;
			}

			else if (i == 15 && process_pass_tab_16 == true)
			{
				for (int j = 0; j < result_point; j++)
					count++;

				continue;
			}

			else if (i == 16 && process_pass_tab_17 == true)
			{
				for (int j = 0; j < result_point; j++)
					count++;

				continue;
			}

			else if (i == 17 && process_pass_tab_18 == true)
			{
				for (int j = 0; j < result_point; j++)
					count++;

				continue;
			}

			else if (i == 18 && process_pass_tab_19 == true)
			{
				for (int j = 0; j < result_point; j++)
					count++;

				continue;
			}

			else if (i == 19 && process_pass_tab_20 == true)
			{
				for (int j = 0; j < result_point; j++)
					count++;

				continue;
			}

			else if (i == 20 && process_pass_tab_21 == true)
			{
				for (int j = 0; j < result_point; j++)
					count++;

				continue;
			}

			else if (i == 21 && process_pass_tab_22 == true)
			{
				for (int j = 0; j < result_point; j++)
					count++;

				continue;
			}

			else if (i == 22 && process_pass_tab_23 == true)
			{
				for (int j = 0; j < result_point; j++)
					count++;

				continue;
			}

			else if (i == 23 && process_pass_tab_24 == true)
			{
				for (int j = 0; j < result_point; j++)
					count++;

				continue;
			}

			else if (i == 24 && process_pass_tab_25 == true)
			{
				for (int j = 0; j < result_point; j++)
					count++;

				continue;
			}

			else if (i == 25 && process_pass_tab_26 == true)
			{
				for (int j = 0; j < result_point; j++)
					count++;

				continue;
			}

			else if (i == 26 && process_pass_tab_27 == true)
			{
				for (int j = 0; j < result_point; j++)
					count++;

				continue;
			}

			else if (i == 27 && process_pass_tab_28 == true)
			{
				for (int j = 0; j < result_point; j++)
					count++;

				continue;
			}

			else if (i == 28 && process_pass_tab_29 == true)
			{
				for (int j = 0; j < result_point; j++)
					count++;

				continue;
			}

			else if (i == 29 && process_pass_tab_30 == true)
			{
				for (int j = 0; j < result_point; j++)
					count++;

				continue;
			}


			for (int j = 0; j < result_point; j++)
			{
				CString point_num;
				CString judge;
				point_num.Format(_T("%d"), j + 1);

				if (result[count] == 1)
					judge = _T("NG");

				else if (result[count] == 0)
					judge = _T("OK");

				m_list_total.InsertItem(list_count, tab_num, 0); // tab
				m_list_total.SetItemText(list_count, 1, point_num); // point
				m_list_total.SetItemText(list_count, 2, judge);

				list_count++;
			}
		}
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


BOOL DIALOG_RESULT::PreTranslateMessage(MSG* pMsg)
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


void DIALOG_RESULT::OnClickListTotal(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	if (check_manual == false)
	{
		CREVIEWAREADlg *pDlg = (CREVIEWAREADlg*)AfxGetMainWnd();

		m_list_upper.DeleteAllItems();
		m_list_side.DeleteAllItems();

		int index = pNMItemActivate->iItem;

		CString check_tab;
		CString check_point;

		check_tab = m_list_total.GetItemText(index, 0);
		check_point = m_list_total.GetItemText(index, 1);

		int num = m_list_total.GetItemCount();

		// 다른 check 해제
		for (int i = 0; i < num; i++)
		{
			if (i != index)
				m_list_total.SetCheck(i, FALSE);
		}

		if (index >= 0 && index < m_list_total.GetItemCount()) // 표시된 아이템들중에 클릭시 아래 코드 실행 
		{
			// 이미지 불러오기
			CString load_result_upper;
			CString load_result_side;

			load_result_upper = load_path + _T("\\") + check_tab + _T("\\") + check_tab + _T("_") + check_point + _T("_UPPER.bmp");
			load_result_side = load_path + _T("\\") + check_tab + _T("\\") + check_tab + _T("_") + check_point + _T("_SIDE.bmp");

			CT2CA ConvertUpper(load_result_upper);
			std::string image_text_upper(ConvertUpper);

			CT2CA ConvertSide(load_result_side);
			std::string image_text_side(ConvertSide);

			result_upper_image = imread(image_text_upper);
			result_side_image = imread(image_text_side);

			loadInfo = (BITMAPINFO*)loadBuf;
			loadInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
			loadInfo->bmiHeader.biWidth = result_upper_image.cols;
			loadInfo->bmiHeader.biHeight = -(result_upper_image.rows);
			loadInfo->bmiHeader.biBitCount = 24;
			loadInfo->bmiHeader.biPlanes = 1;
			loadInfo->bmiHeader.biCompression = BI_RGB;
			loadInfo->bmiHeader.biSizeImage = 0;
			loadInfo->bmiHeader.biXPelsPerMeter = 0;
			loadInfo->bmiHeader.biYPelsPerMeter = 0;
			loadInfo->bmiHeader.biClrUsed = 0;
			loadInfo->bmiHeader.biClrImportant = 0;

			StretchDIBits(hdc_upper, 0, 0, 512, 512, 0, 0, result_upper_image.cols, result_upper_image.rows,
				result_upper_image.data, loadInfo, DIB_RGB_COLORS, SRCCOPY);

			StretchDIBits(hdc_side, 0, 0, 512, 512, 0, 0, result_side_image.cols, result_side_image.rows,
				result_side_image.data, loadInfo, DIB_RGB_COLORS, SRCCOPY);

		}

		CXLEzAutomation XC(FALSE);

		CString load_excel = load_path + _T("\\") + check_tab + _T("\\Result.xlsx");
		XC.OpenExcelFile(load_excel);

		int click_point;
		click_point = _ttoi(check_point);

		CString str_upper_point;
		CString str_side_point;

		int val_upper_point;
		int val_side_point;

		int val_upper_start;
		int val_upper_end;
		int val_side_start;
		int val_side_end;

		// 고정
		val_upper_start = result_point + 6;	//

		for (int i = val_upper_start; i < 1000; i++)
		{
			str_side_point = XC.GetCellValue(3, i);
			if (str_side_point == "POINT")
			{
				val_upper_end = i - 3;
				val_side_start = i + 1;
				break;
			}
		}

		for (int i = val_side_start; i < 1000; i++)
		{
			str_side_point = XC.GetCellValue(3, i);
			if (str_side_point == "")
			{
				val_side_end = i - 1;
				break;
			}
		}

		CString str_num;

		CString str_upper_x;
		CString str_upper_width;
		CString str_upper_y;
		CString str_upper_height;

		CString str_ma_x_value;
		CString str_ma_x_judge;

		CString str_side_x;
		CString str_side_width;
		CString str_side_y;
		CString str_side_height;
		CString str_dimension_judge;

		CString str_open;
		CString str_short;

		CString str_ma_y_value;
		CString str_ma_y_judge;

		int val_num;
		double val_change;

		double display_value;
		double display_result;


		int count = 0;
		for (int i = val_upper_start; i <= val_upper_end; i++)
		{
			str_upper_point = XC.GetCellValue(3, i);
			val_upper_point = _wtof(str_upper_point);

			if (val_upper_point == click_point)
			{
				str_num = XC.GetCellValue(4, i);
				val_num = _wtof(str_num);
				str_num.Format(_T("%d"), val_num);

				// 5 : x
				str_upper_x = XC.GetCellValue(5, i);
				val_change = _wtof(str_upper_x);
				str_upper_x.Format(_T("%.1f"), val_change);
				// 6 : width
				str_upper_width = XC.GetCellValue(6, i);
				val_change = _wtof(str_upper_width);
				str_upper_width.Format(_T("%.1f"), val_change);

				// 7 : y
				str_upper_y = XC.GetCellValue(7, i);
				val_change = _wtof(str_upper_y);
				str_upper_y.Format(_T("%.1f"), val_change);

				// 8 : height
				str_upper_height = XC.GetCellValue(8, i);
				val_change = _wtof(str_upper_height);
				str_upper_height.Format(_T("%.1f"), val_change);

				// 9 : ma_x
				str_ma_x_value = XC.GetCellValue(9, i);
				val_change = _wtof(str_ma_x_value);
				str_ma_x_value.Format(_T("%.1f"), val_change);

				// 10 : judge
				str_ma_x_judge = XC.GetCellValue(10, i);

				m_list_upper.InsertItem(count, str_num, 0);
				m_list_upper.SetItemText(count, 1, str_upper_x);
				m_list_upper.SetItemText(count, 2, str_upper_width);
				m_list_upper.SetItemText(count, 3, str_upper_y);
				m_list_upper.SetItemText(count, 4, str_upper_height);
				m_list_upper.SetItemText(count, 5, str_ma_x_value);
				m_list_upper.SetItemText(count, 6, str_ma_x_judge);

				count++;
			}
		}

		// Side
		count = 0;
		for (int i = val_side_start; i <= val_side_end; i++)
		{
			str_side_point = XC.GetCellValue(3, i);
			val_side_point = _wtof(str_side_point);

			if (val_side_point == click_point)
			{
				CString str_side_x;
				CString str_side_width;
				CString str_side_y;
				CString str_side_height;
				CString str_ma_y_value;

				CString str_open;
				CString str_short;

				CString str_dimension_judge;


				str_num = XC.GetCellValue(4, i);
				val_num = _wtof(str_num);
				str_num.Format(_T("%d"), val_num);

				str_side_x = XC.GetCellValue(5, i);
				val_change = _wtof(str_side_x);
				str_side_x.Format(_T("%.1f"), val_change);

				str_side_width = XC.GetCellValue(6, i);
				val_change = _wtof(str_side_width);
				str_side_width.Format(_T("%.1f"), val_change);

				str_side_y = XC.GetCellValue(7, i);
				val_change = _wtof(str_side_y);
				str_side_y.Format(_T("%.1f"), val_change);

				str_side_height = XC.GetCellValue(8, i);
				val_change = _wtof(str_side_height);
				str_side_height.Format(_T("%.1f"), val_change);

				str_open = XC.GetCellValue(9, i);
				str_short = XC.GetCellValue(10, i);

				str_dimension_judge = XC.GetCellValue(11, i);

				m_list_side.InsertItem(count, str_num, 0);
				m_list_side.SetItemText(count, 1, str_side_x);
				m_list_side.SetItemText(count, 2, str_side_width);
				m_list_side.SetItemText(count, 3, str_side_y);
				m_list_side.SetItemText(count, 4, str_side_height);
				m_list_side.SetItemText(count, 5, str_open);
				m_list_side.SetItemText(count, 6, str_short);
				m_list_side.SetItemText(count, 7, str_dimension_judge);

				count++;
			}
		}

		XC.ReleaseExcel();
	}
	*pResult = 0;
}


void DIALOG_RESULT::OnClickListUpper(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	/*int index = pNMItemActivate->iItem;
	
	CString check_number;
	CString str_x_position;
	CString str_width;
	CString str_judge;

	int val_x_position;
	int val_width;
	
	check_number = m_list_upper.GetItemText(index, 0);
	str_x_position = m_list_upper.GetItemText(index, 1);
	str_width = m_list_upper.GetItemText(index, 2);
	str_judge = m_list_upper.GetItemText(index, 6);

	val_x_position = _ttoi(str_x_position);
	val_width = _ttoi(str_width);
	*/
	/*CRect rt_upper;
	CStatic * pStatic_upper = (CStatic*)GetDlgItem(IDC_PIC_OVERLAY_UPPER);
	CDC* pDC_upper = pStatic_upper->GetDC();
	pStatic_upper->GetClientRect(&rt_upper);

	pDC_upper->SetBkMode(TRANSPARENT);

	if (str_judge == "OK")
		pDC_upper->SetTextColor(RGB(0, 255, 0));

	else if (str_judge == "NG")
		pDC_upper->SetTextColor(RGB(ma_r, ma_g, ma_b));

	
	pDC_upper->TextOutW(((val_x_position + val_width) / 4) + 1, 10, check_number);*/

	//pDC_upper->DeleteDC();

	/*int ma_x_pos;
	int ma_x_pos_side;

	CString str_width;
	CString str_ng;
	CString str_value;


	double val_ma;
	double val_width;

	
	str_width = m_list_upper.GetItemText(index, 2);
	
	str_value = m_list_upper.GetItemText(index, 5);
	str_ng = m_list_upper.GetItemText(index, 6);


	val_width = _wtof(str_width);
	val_width = (val_width / 0.55) / 2;

	val_x_position = val_x_position + val_width;

	ma_x_pos = val_x_position / 4;

	val_ma = _wtof(str_value);
	//val_ma = val_ma - camera_offset;
	val_ma = val_ma * 0.55;

	ma_x_pos_side = ma_x_pos + val_ma;

	*/

	/*CRect rt_side;
	CStatic * pStatic_side = (CStatic*)GetDlgItem(IDC_PIC_OVERLAY_SIDE);
	CDC* pDC_side = pStatic_side->GetDC();
	pStatic_side->GetClientRect(&rt_side);

	CRgn rgn_side;

	if (str_ng == "OK")
	{
		pDC_upper->SelectObject(pen_ok);
		pDC_side->SelectObject(pen_ok);
	}
	

	else if (str_ng == "NG")
	{
		pDC_upper->SelectObject(pen_ma);
		pDC_side->SelectObject(pen_ma);
	}

	pDC_upper->SelectObject(&null_brush);
	pDC_side->SelectObject(&null_brush);

	rgn_upper.CreateRectRgnIndirect(&rt_upper);
	pDC_upper->SelectClipRgn(&rgn_upper);

	rgn_side.CreateRectRgnIndirect(&rt_side);
	pDC_side->SelectClipRgn(&rgn_side);

	pDC_upper->SetROP2(R2_XORPEN);
	
	pDC_upper->MoveTo(ma_x_pos, 0);
	pDC_upper->LineTo(ma_x_pos, 512);

	pDC_side->SetROP2(R2_XORPEN);
	pDC_side->MoveTo(ma_x_pos_side, 0);
	pDC_side->LineTo(ma_x_pos_side, 512);
	*/

	*pResult = 0;
}


void DIALOG_RESULT::OnClickListSide(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int index = pNMItemActivate->iItem;

	/*CString side_x;
	CString side_width;
	CString side_y;
	CString side_height;
	CString str_ng;
	CString str_open;
	CString str_short;

	int val_side_x;
	int val_side_width;
	int val_side_y;
	int val_side_height;
	int val_side_center;

	int relax_dimension;
	int relax_open;
	int relax_short;


	side_x = m_list_side.GetItemText(index, 1);
	side_width = m_list_side.GetItemText(index, 2);
	side_y = m_list_side.GetItemText(index, 3);
	side_height = m_list_side.GetItemText(index, 4);

	str_open = m_list_side.GetItemText(index, 5);
	str_short = m_list_side.GetItemText(index, 6);
	str_ng = m_list_side.GetItemText(index, 7);

	val_side_x = _ttoi(side_x);
	val_side_width = _ttoi(side_width);
	val_side_y = _ttoi(side_y);
	val_side_height = _ttoi(side_height);

	val_side_x = val_side_x / 4;
	val_side_width = (val_side_width / 0.55) / 4;
	val_side_y = val_side_y / 4;
	val_side_height = (val_side_height / 0.55) / 4;

	val_side_center = val_side_y + (val_side_height / 8);

	relax_open = 3;
	relax_short = 4;
	relax_dimension = 5;

	CRect rt_side;
	CStatic * pStatic_side = (CStatic*)GetDlgItem(IDC_PIC_OVERLAY_SIDE);
	CDC* pDC_side = pStatic_side->GetDC();
	pStatic_side->GetClientRect(&rt_side);

	CRgn rgn_side;

	if (str_ng == "OK")
		pDC_side->SelectObject(pen_ok);

	else if (str_ng == "WIDTH_NG")
		pDC_side->SelectObject(pen_width);

	else if (str_ng == "HEIGHT_NG")
		pDC_side->SelectObject(pen_height);

	else if (str_ng == "BOTH_NG")
		pDC_side->SelectObject(pen_both);

	pDC_side->SelectObject(&null_brush);

	rgn_side.CreateRectRgnIndirect(&rt_side);
	pDC_side->SelectClipRgn(&rgn_side);

	pDC_side->SetROP2(R2_XORPEN);
	pDC_side->Rectangle(val_side_x - relax_dimension, val_side_y - relax_dimension, val_side_x + val_side_width + (relax_dimension * 2), val_side_y + val_side_height + (relax_dimension * 2));


	if (str_open == "OPEN")
	{
		pDC_side->SelectObject(pen_open);
		pDC_side->SelectObject(&null_brush);

		pDC_side->SetROP2(R2_XORPEN);
		pDC_side->Rectangle(val_side_x - relax_open, val_side_y - relax_open, val_side_x + val_side_width + (relax_open * 2), val_side_y + val_side_height + (relax_open * 2));
	}

	if (str_short == "SHORT")
	{
		pDC_side->SelectObject(pen_short);
		pDC_side->SelectObject(&null_brush);

		pDC_side->SetROP2(R2_XORPEN);
		pDC_side->Rectangle(val_side_x - relax_short, val_side_y - relax_short, val_side_x + val_side_width + (relax_short * 2), val_side_y + val_side_height + (relax_short * 2));
	}
	*/
	*pResult = 0;
}


void DIALOG_RESULT::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.

	CPen pen;
	pen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));    // 빨간색 펜을 생성
	CPen* oldPen = dc.SelectObject(&pen);

	CBrush brush_ma;
	CBrush brush_open;
	CBrush brush_short;
	CBrush brush_width;
	CBrush brush_height;
	CBrush brush_both;
	CBrush brush_ok;

	brush_ma.CreateSolidBrush(ma_cl);
	brush_open.CreateSolidBrush(open_cl);
	brush_short.CreateSolidBrush(short_cl);
	brush_width.CreateSolidBrush(width_cl);
	brush_height.CreateSolidBrush(height_cl);
	brush_both.CreateSolidBrush(both_cl);
	brush_ok.CreateSolidBrush(ok_cl);

	dc.SelectObject(&brush_ma);
	dc.Rectangle(1162, 10, 1182, 30);

	dc.SelectObject(&brush_open);
	dc.Rectangle(1162, 40, 1182, 60);

	dc.SelectObject(&brush_short);
	dc.Rectangle(1162, 70, 1182, 90);

	dc.SelectObject(&brush_width);
	dc.Rectangle(1162, 100, 1182, 120);

	dc.SelectObject(&brush_height);
	dc.Rectangle(1162, 130, 1182, 150);

	dc.SelectObject(&brush_both);
	dc.Rectangle(1162, 160, 1182, 180);

	dc.SelectObject(&brush_ok);
	dc.Rectangle(1162, 190, 1182, 210);
}

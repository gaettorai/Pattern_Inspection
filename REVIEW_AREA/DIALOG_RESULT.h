
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#pragma once

using namespace cv;
using namespace std;

// DIALOG_RESULT 대화 상자

class DIALOG_RESULT : public CDialogEx
{
	DECLARE_DYNAMIC(DIALOG_RESULT)

public:
	DIALOG_RESULT(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DIALOG_RESULT();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_RESULT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	CListCtrl m_list_total;
	CListCtrl m_list_upper;
	CListCtrl m_list_side;
	CStatic m_pic_result_upper;
	CStatic m_pic_result_side;

	Mat result_upper_image;
	Mat result_side_image;
	HDC hdc_upper;
	HDC hdc_side;

	char loadBuf[2048];			// load image
	BITMAPINFO *loadInfo = 0;

	int result_tab;
	int result_point;
	int start_tab;

	bool check_manual;

	CString load_path;
	double result[300];
	afx_msg void OnClickListTotal(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClickListUpper(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClickListSide(NMHDR *pNMHDR, LRESULT *pResult);

	int count;

	CPen pen_ok;
	CPen pen_ma;
	CPen pen_open;
	CPen pen_short;
	CPen pen_width;
	CPen pen_height;
	CPen pen_both;

	CBrush null_brush;

	bool process_pass_tab_1;
	bool process_pass_tab_2;
	bool process_pass_tab_3;
	bool process_pass_tab_4;
	bool process_pass_tab_5;
	bool process_pass_tab_6;
	bool process_pass_tab_7;
	bool process_pass_tab_8;
	bool process_pass_tab_9;
	bool process_pass_tab_10;
	bool process_pass_tab_11;
	bool process_pass_tab_12;
	bool process_pass_tab_13;
	bool process_pass_tab_14;
	bool process_pass_tab_15;
	bool process_pass_tab_16;
	bool process_pass_tab_17;
	bool process_pass_tab_18;
	bool process_pass_tab_19;
	bool process_pass_tab_20;
	bool process_pass_tab_21;
	bool process_pass_tab_22;
	bool process_pass_tab_23;
	bool process_pass_tab_24;
	bool process_pass_tab_25;
	bool process_pass_tab_26;
	bool process_pass_tab_27;
	bool process_pass_tab_28;
	bool process_pass_tab_29;
	bool process_pass_tab_30;

	int camera_offset;
	CStatic m_pic_overlay_upper;
	CStatic m_pic_overlay_side;

	int ma_r;
	int ma_g;
	int ma_b;

	int open_r;
	int open_g;
	int open_b;

	int short_r;
	int short_g;
	int short_b;

	int width_r;
	int width_g;
	int width_b;

	int height_r;
	int height_g;
	int height_b;

	int both_r;
	int both_g;
	int both_b;

	int ok_r;
	int ok_g;
	int ok_b;

	COLORREF	ma_cl;
	COLORREF	open_cl;
	COLORREF	short_cl;
	COLORREF	width_cl;
	COLORREF	height_cl;
	COLORREF	both_cl;
	COLORREF	ok_cl;

	afx_msg void OnPaint();
	CListCtrl m_list_side_mark;
};

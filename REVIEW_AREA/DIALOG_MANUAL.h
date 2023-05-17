
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "DIALOG_MANUAL_UPPER.h"
#include "DIALOG_MANUAL_SIDE.h"

#pragma once

using namespace cv;
using namespace std;
// DIALOG_MANUAL 대화 상자

class DIALOG_MANUAL : public CDialogEx
{
	DECLARE_DYNAMIC(DIALOG_MANUAL)

public:
	DIALOG_MANUAL(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DIALOG_MANUAL();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MANUAL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

	DIALOG_MANUAL_UPPER	*dlg_manual_upper;
	DIALOG_MANUAL_SIDE	*dlg_manual_side;

	HANDLE hStage_manual;

	CStatic m_pic_upper;
	CStatic m_pic_side;
	CComboBox m_cmb_camera;
	afx_msg void OnCbnSelchangeCmbCamera();
	CStatic m_pic_mark_upper;
	CStatic m_pic_mark_side;
	CEdit m_edit_stage_main_x_command;
	CEdit m_edit_stage_main_x_reference;
	CEdit m_edit_stage_main_x_position;
	CEdit m_edit_stage_main_y_command;
	CEdit m_edit_stage_main_y_reference;
	CEdit m_edit_stage_main_y_position;
	CEdit m_edit_stage_sub_x_command;
	CEdit m_edit_stage_sub_x_reference;
	CEdit m_edit_stage_sub_x_position;
	CComboBox m_cmb_upper_mark;
	CButton m_chk_abs_1;
	CButton m_chk_rel_1;
	CButton m_chk_abs_2;
	CButton m_chk_rel_2;
	CButton m_chk_abs_3;
	CButton m_chk_rel_3;
	afx_msg void OnBnClickedChkAbs1();
	afx_msg void OnBnClickedChkRel1();
	afx_msg void OnBnClickedChkAbs2();
	afx_msg void OnBnClickedChkRel2();
	afx_msg void OnBnClickedChkAbs3();
	afx_msg void OnBnClickedChkRel3();
	afx_msg void OnBnClickedBtnStageMainXMove();
	afx_msg void OnBnClickedBtnStageMainYMove();
	afx_msg void OnBnClickedBtnStageSubXMove();
	afx_msg void OnBnClickedBtnLine();
	afx_msg void OnBnClickedBtnRectangle();
	afx_msg void OnBnClickedBtnCircle();
	afx_msg void OnBnClickedBtnEdge1();
	afx_msg void OnBnClickedBtnEdge2();
	afx_msg void OnBnClickedBtnReset();
	
	CBitmap m_graphic_on;
	CBitmap m_graphic_off;
	CBitmap	m_line_on;
	CBitmap m_line_off;
	CBitmap	m_rectangle_on;
	CBitmap m_rectangle_off;
	CBitmap	m_circle_on;
	CBitmap m_circle_off;
	CBitmap	m_edge_1_on;
	CBitmap m_edge_1_off;
	CBitmap	m_edge_2_on;
	CBitmap m_edge_2_off;

	CListCtrl m_list_measure;

	HDC hdc_manual_upper;
	HDC hdc_manual_side;
	HDC hdc_mark_upper;
	HDC hdc_mark_side;

	HDC hdc_camera_focus;

	char manualBuf[2048];
	BITMAPINFO *manualInfo = 0;

	char markBuf[2048];
	BITMAPINFO *markInfo = 0;

	char focusBuf[2048];
	BITMAPINFO *focusInfo = 0;

	Mat manual_upper_image;
	Mat manual_side_image;
	Mat manual_upper_mark;
	Mat manual_side_mark;
	
	Mat focus_image;
	Mat morp_image;
	Mat binary_image;
	Mat canny_image;

	int overlay_display;
	int overlay_graphic;

	int moving_stage;

	CString str_command;
	double val_command;

	CString str_rel;
	double val_rel;

	double stage_main_x_max_limit;
	double stage_main_x_min_limit;

	double stage_main_y_max_limit;
	double stage_main_y_min_limit;

	double stage_sub_x_max_limit;
	double stage_sub_x_min_limit;

	double stage_main_x_pos;
	double stage_main_y_pos;
	double stage_sub_x_pos;
	
	int stage_main_x_status;
	int stage_main_y_status;
	int stage_sub_x_status;

	static UINT manual_Thread(LPVOID pParam);	// Stage (ACS Motion Control)

	CWinThread* manual = NULL;

	CButton m_chk_crossline;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	int measure_mode;
	int measure_count;

	CPoint first_point;
	CPoint second_point;
	CPoint third_point;

	CString str_measure_label;
	CString str_measure_value;
	
	int list_count;

	CPen pen_line;
	CPen pen_rectangle;
	CPen pen_circle;
	CPen pen_mark;

	CBrush null_brush;

	int click_count;
	int click_area;
	afx_msg void OnBnClickedBtnGraphic();
	afx_msg void OnBnClickedBtnUpperMarkReg();
	afx_msg void OnBnClickedBtnUpperMarkSave();
	afx_msg void OnBnClickedBtnSideMarkReg();
	afx_msg void OnBnClickedBtnSideMarkSave();
	CComboBox m_cmb_side_mark;
	CStatic m_pic_side_mark;
	CEdit m_edit_morp_open;
	CEdit m_edit_morp_close;
	CEdit m_edit_binary;
	CEdit m_edit_contour;
	CButton m_btn_graphic;
	CButton m_btn_line;
	CButton m_btn_rectangle;
	CButton m_btn_circle;
	CButton m_btn_edge_1;
	CButton m_btn_edge_2;
	afx_msg void OnBnClickedBtnMorp();
	afx_msg void OnBnClickedBtnBinary();
	afx_msg void OnBnClickedBtnContour();
	afx_msg void OnBnClickedBtnFocusReset();

	int check_graphic_mode;
	CComboBox m_cmb_magni;
	afx_msg void OnCbnSelchangeCmbMagni();
	CEdit m_edit_test_roi_min;
	CEdit m_edit_test_roi_max;
};

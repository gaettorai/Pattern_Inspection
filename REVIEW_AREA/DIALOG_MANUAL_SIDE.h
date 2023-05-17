#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#pragma once

using namespace cv;
using namespace std;
// DIALOG_MANUAL_SIDE 대화 상자

class DIALOG_MANUAL_SIDE : public CDialogEx
{
	DECLARE_DYNAMIC(DIALOG_MANUAL_SIDE)

public:
	DIALOG_MANUAL_SIDE(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DIALOG_MANUAL_SIDE();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MANUAL_SIDE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CStatic m_pic_manual_side;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);

	int ViewWidth_;
	int ViewHeight_;
	int HScrollPos_;
	int VScrollPos_;
	int HPageSize_;
	int VPageSize_;
	int delta;
	int m_nHdelta;

	int scrollpos;

	int camWidth;
	int camHeight;
	int magni;

	int width_value;
	int height_value;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

	void click_magni();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);

	int measure_mode;
	int measure_count;

	CPoint first_point;
	CPoint second_point;
	CPoint third_point;

	int click_count;

	CPen pen_line;
	CPen pen_rectangle;
	CPen pen_circle;
	CPen pen_mark;

	CBrush null_brush;

	CString str_measure_label;
	CString str_measure_value;

	int list_count;

	// draw line
	double dist_x;
	double dist_y;
	double dist_dia;

	CString str_line;

	CString str_ver;
	CString str_hor;

	int dx, dy;
	double radius;

	CString str_circle;

	Mat manual_side_image;
	Mat manual_side_mark;

	char markBuf[2048];
	BITMAPINFO *markInfo = 0;
};

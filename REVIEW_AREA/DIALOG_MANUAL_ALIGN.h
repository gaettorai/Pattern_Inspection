#pragma once

#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

// DIALOG_MANUAL_ALIGN 대화 상자

using namespace cv;
using namespace std;

class DIALOG_MANUAL_ALIGN : public CDialogEx
{
	DECLARE_DYNAMIC(DIALOG_MANUAL_ALIGN)

public:
	DIALOG_MANUAL_ALIGN(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DIALOG_MANUAL_ALIGN();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MANUAL_ALIGN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

	Mat align_image;
	Mat clone_image;
	Mat mark_image;

	HDC hdc_align;

	char alignBuf[2048];			// load image
	BITMAPINFO *alignInfo = 0;

	char markBuf[2048];			// load mark
	BITMAPINFO *markInfo = 0;

	CStatic m_pic_align;

	int mark_rows;
	int mark_cols;

	int x1;
	int x2;
	int y1;
	int y2;

	int alignCase;
	String file_name;
	CStatic m_pic_manual_align;
	afx_msg void OnPaint();
};

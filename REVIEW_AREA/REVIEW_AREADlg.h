
// REVIEW_AREADlg.h: 헤더 파일
//
#include "DIALOG_AUTO.h"
#include "DIALOG_MANUAL.h"
#include "DIALOG_SETTING.h"
#include "DIALOG_HISTORY.h"
#include "DIALOG_ALARM.h"
#include "DIALOG_LOADING.h"
#include "DIALOG_LOADING_IMAGE.h"
#include "DIALOG_COMPORT.h"
#include "DIALOG_SYSTEM.h"

#include "CommThread.h"
#include "ACSC.h"

#include "atf_lib_exp.h"

#include <atltime.h>


#pragma once


// CREVIEWAREADlg 대화 상자
class CREVIEWAREADlg : public CDialogEx
{
// 생성입니다.
public:
	CREVIEWAREADlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_REVIEW_AREA_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedBtnUpperCam();
	afx_msg void OnBnClickedBtnSideCam();
	afx_msg void OnBnClickedBtnAllCam();
	afx_msg void OnBnClickedBtnMainStageX();
	afx_msg void OnBnClickedBtnMainStageY();
	afx_msg void OnBnClickedBtnSubStageX();
	afx_msg void OnBnClickedBtnAllStage();
	afx_msg void OnSelchangeTabWindows(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnReleasedcaptureSldUpper(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnReleasedcaptureSldSide(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnChangeEditUpperLight();
	afx_msg void OnChangeEditSideLight();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

	CToolBar m_wndToolBar;

	// comport connect
	CString byIndexComPort(int xPort);
	DWORD byIndexBaud(int xBaud);
	BYTE byIndexData(int xData);
	BYTE byIndexParity(int xParity);
	BYTE byIndexStop(int xStop);

	DIALOG_AUTO	*dlg_auto;
	DIALOG_MANUAL *dlg_manual;
	DIALOG_SETTING *dlg_setting;
	DIALOG_HISTORY *dlg_history;
	DIALOG_ALARM	*dlg_alarm;
	DIALOG_LOADING *dlg_loading;
	DIALOG_LOADING_IMAGE dlg_loading_image;


	CStatic m_pic_logo;
	CStatic m_pic_start;
	CStatic m_pic_stop;

	CEdit m_edit_upper_light;
	CEdit m_edit_side_light;
	CTabCtrl m_tab_windows;

	// status
	int stage_main_x_Status;
	int stage_main_y_Status;
	int stage_sub_x_Status;

	// position
	double stage_main_x_pos;	
	double stage_main_y_pos;
	double stage_sub_x_pos;

	// Thread
	static UINT Status_Thread(LPVOID pParam);	// Stage (ACS Motion Control)
	CWinThread* Status = NULL;

	// Comport
	CCommThread	upper_light_comport;	
	CCommThread side_light_comport;	
	CCommThread upper_af_comport;	
	CCommThread side_af_comport;	
	
	CSliderCtrl m_sld_upper;
	CSliderCtrl m_sld_side;

	// button
	CBitmap m_logo;
	CBitmap	m_green_led;
	CBitmap m_red_led;

	CBrush bg_brush;

	CTime Clock_time;
	CString str_year;
	CString str_day;
	CString str_clock;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	
	afx_msg void OnDestroy();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);

	CString strPath;

	CButton m_btn_upper_cam;
	CButton m_btn_side_cam;
	CButton m_btn_all_cam;

	CBitmap m_cam_off;
	CBitmap m_cam_on;
	
	CBitmap m_af_off;
	CBitmap m_af_on;

	CBitmap m_light_off;
	CBitmap m_light_on;

	CBitmap m_stage_off;
	CBitmap m_stage_on;

	CButton m_btn_main_stage_x;
	CButton m_btn_main_stage_y;
	CButton m_btn_sub_stage_x;
	CButton m_btn_all_stage;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnBnClickedBtnUpperLight();
	afx_msg void OnBnClickedBtnSideLight();
	afx_msg void OnBnClickedBtnUpperAf();
	afx_msg void OnBnClickedBtnSideAf();
	CButton m_btn_upper_light;
	CButton m_btn_side_light;
	CButton m_btn_upper_af;
	CButton m_btn_side_af;
	afx_msg void OnSaveCamUpper();
	afx_msg void OnSaveCamSide();
	afx_msg void OnSaveCamAll();
	afx_msg void OnFileLoad();
	afx_msg void OnFileExit();
	afx_msg void OnGraphicActive();
	afx_msg void OnGraphicLine();
	afx_msg void OnGraphicRectangle();
	afx_msg void OnGraphicCircle();
	afx_msg void OnGraphicEdge();
	afx_msg void OnGraphicEdge_2();
	afx_msg void OnComportConnect();
	afx_msg void OnSystemLogin();

	int display_check_graphic;
	int display_check_upper;
	int display_check_side;

	CStatic m_pic_login;

	CString str_id;
	CString str_pw;

	int check_login;

	int upper_ecode;
	int side_ecode;

	int selected_af;

	void graphic_active();
	CComboBox m_cmb_af_step;
	CSpinButtonCtrl m_spin_af;
	afx_msg void OnDeltaposSpinAf(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedChkUpperAf();
	CButton m_chk_upper_af;
	CButton m_chk_side_af;
	afx_msg void OnBnClickedChkSideAf();
	CEdit m_edit_aoi;
	CStatic m_pic_upper_af;
	CStatic m_pic_side_af;
	afx_msg void OnBnClickedBtnAf();
	afx_msg void OnBnClickedBtnStop();
	afx_msg void OnBnClickedBtnMoveStop();
	void align_af_pos();
	void process_af_pos();
	void inspection_upper_af(int Case);
	void inspection_side_af(int Case);

	void ProcessAFStart();
	void ProcessAFStop();
};

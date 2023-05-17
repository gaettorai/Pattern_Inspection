
#include "DIALOG_MANUAL_ALIGN.h"	// manual align
#include "DIALOG_RESULT.h"
#include "DIALOG_POPUP.h"
#include "DIALOG_ALARM.h"
#include "DIALOG_CLAMP.h"

#include "ACSC.h"

#include "mil.h"

#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "XLAutomation.h"
#include "XLEzAutomation.h"

#include <atltime.h>

#pragma once

using namespace cv;
using namespace std;
// DIALOG_AUTO 대화 상자

typedef struct MIL_AREA
{
	MIL_ID  m_MilApplication;
	MIL_ID	m_MilSystem_Upper;
	MIL_ID	m_MilSystem_Side;
	MIL_ID	m_MilDigitizer_Upper;
	MIL_ID	m_MilDigitizer_Side;
	MIL_ID	m_MilDisplay_Upper;
	MIL_ID	m_MilDisplay_Side;
	MIL_ID	m_MilImage_Upper;
	MIL_ID	m_MilImage_Side;
	MIL_ID	m_Overlay_Upper_Center;
	MIL_ID	m_Overlay_Side_Center;
	MIL_INT	m_numberOfDigitizer_Upper;
	MIL_INT	m_numberOfDigitizer_Side;
	MIL_INT  m_digitizerSizeX;
	MIL_INT  m_digitizerSizeY;
	MIL_INT  m_digitizerNoBands;
	MIL_DOUBLE ZoomFactor;
} MIL_AREA;

typedef struct INSPECT_RESULT
{
	double total_result[300];

	double upper_num[30];

	double upper_x[30][100];
	double upper_width[30][100];
	double upper_y[30][100];
	double upper_height[30][100];
	double upper_ma_x_center[30][100];

	double side_num[30];

	double side_x[30][100];
	double side_width[30][100];
	double side_y[30][100];
	double side_height[30][100];
	double side_ma_x_center[30][100];
	double side_ma_y_center[30][100];

	double ma_x[30][100];
	double ma_y[30][100];

	double result_ma_x[30][100];
	double result_ma_y[30][100];
	double result_open[30][100];
	double result_short[30][100];
	double result_width[30][100];
	double result_height[30][100];


}INSPECT_RESULT;

typedef struct MANUAL_INSPECT_RESULT
{
	double upper_num;
	double upper_x[100];
	double upper_width[100];
	double upper_y[100];
	double upper_height[100];
	double upper_ma_x_center[100];

	double side_num;
	double side_x[100];
	double side_width[100];
	double side_y[100];
	double side_height[100];
	double side_ma_x_center[100];
	double side_ma_y_center[100];

	double ma_x[100];

	double result_ma_x[100];
	double result_open[100];
	double result_short[100];
	double result_width[100];
	double result_height[100];


}MANUAL_INSPECT_RESULT;

enum eAutoSeq
{
	MoveReadyPos,
	ReadyPosComplete,
	MoveProcessPos,
	ProcessPosComplete,
	PreAlign,
	PreAlignComplete,
	MoveTabAlignPos,
	TabAlignPosComplete,
	TabAlign,
	TabAlignComplete,
	MoveInspectionPos,
	Inspection,
	InspectionComplete,
	Judge,
	JudgeComplete,
	Unloading,
	UnloadingComplete,
};

enum eAutoResult
{
	NotYet,
	FirstFinish,
	InspectionFinish,
};

class DIALOG_AUTO : public CDialogEx
{
	DECLARE_DYNAMIC(DIALOG_AUTO)

public:
	DIALOG_AUTO(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DIALOG_AUTO();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_AUTO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnBnClickedBtnStart();
	afx_msg void OnBnClickedBtnStop();
	afx_msg void OnBnClickedBtnReset();
	afx_msg void OnBnClickedBtnLogReset();

	DIALOG_ALARM*	dlg_alarm;

	HANDLE hStage_auto;

	MIL_AREA area_cam;
	INSPECT_RESULT	result_value;
	MANUAL_INSPECT_RESULT	manual_result_value;

	// image
	CStatic m_pic_upper;
	CStatic m_pic_side;

	// led button
	CStatic m_pic_process_ready;
	CStatic m_pic_process_process;
	CStatic m_pic_process_prealign;
	CStatic m_pic_process_tabalign;
	CStatic m_pic_process_inspection;
	CStatic m_pic_process_judge;
	CStatic m_pic_process_unloading;

	// Edit Display
	CEdit m_edit_stage_main_x_pos;
	CEdit m_edit_stage_main_x_ready_pos;
	CEdit m_edit_stage_main_x_process_pos;
	CEdit m_edit_stage_main_x_limit_min;
	CEdit m_edit_stage_main_x_limit_max;
	CEdit m_edit_stage_main_x_manual_speed;
	CEdit m_edit_stage_main_x_process_speed;

	CEdit m_edit_stage_main_y_pos;
	CEdit m_edit_stage_main_y_ready_pos;
	CEdit m_edit_stage_main_y_process_pos;
	CEdit m_edit_stage_main_y_limit_min;
	CEdit m_edit_stage_main_y_limit_max;
	CEdit m_edit_stage_main_y_manual_speed;
	CEdit m_edit_stage_main_y_process_speed;

	CEdit m_edit_stage_sub_x_pos;
	CEdit m_edit_stage_sub_x_ready_pos;
	CEdit m_edit_stage_sub_x_process_pos;
	CEdit m_edit_stage_sub_x_limit_min;
	CEdit m_edit_stage_sub_x_limit_max;
	CEdit m_edit_stage_sub_x_align_offset;
	CEdit m_edit_stage_sub_x_manual_speed;
	CEdit m_edit_stage_sub_x_process_speed;
	
	CEdit m_edit_tacktime_process;
	CEdit m_edit_tacktime_align;
	CEdit m_edit_tacktime_inspection;
	CEdit m_edit_tacktime_judge;
	CEdit m_edit_tacktime_unloading;
	CEdit m_edit_tacktime_total;


	// button
	CBitmap	m_green_led;
	CBitmap m_red_led;
	CBitmap m_yellow_led;

	CListCtrl m_list_result;
	CListCtrl m_list_ma_x;
	CListCtrl m_list_ma_y;
	CListCtrl m_list_os;
	CListCtrl m_list_other;

	// Thread
	static UINT Inspect_Thread(LPVOID pParam);
	CWinThread*Inspect = NULL;


	// inspection recipe vaule
	double stage_main_x_ready_pos;
	double stage_main_x_process_pos;
	double stage_main_x_limit_min;
	double stage_main_x_limit_max;
	double stage_main_x_manual_speed;
	double stage_main_x_process_speed;

	double stage_main_y_ready_pos;
	double stage_main_y_process_pos;
	double stage_main_y_limit_min;
	double stage_main_y_limit_max;
	double stage_main_y_manual_speed;
	double stage_main_y_process_speed;

	double stage_sub_x_ready_pos;
	double stage_sub_x_process_pos;
	double stage_sub_x_limit_min;
	double stage_sub_x_limit_max;
	double stage_sub_x_align_offset;
	double stage_sub_x_manual_speed;
	double stage_sub_x_process_speed;

	int tab_count;
	int tab_point;
	double tab_dist;
	double tab_interval;

	double tab_step;

	double prealign_matching;
	double tabalign_matching;
	double prealign_range;
	double offset;
	double upper_align_offset;
	double side_align_offset;
	double width;
	double height;
	double space;
	double width_range;
	double height_range;
	double ma_x_range;
	double ma_y_value;
	double ma_y_range;
	double ma_x_offset;

	double binary_upper;
	double binary_side;
	double binary_edge;

	double morphology_open;
	double morphology_close;

	double upper_contour;
	double side_contour;

	double upper_roi_min;
	double upper_roi_max;
	double side_roi_min;
	double side_roi_max;
	double edge_roi_min;
	double edge_roi_max;

	double gantry_limit_min;
	double gantry_limit_max;
	double af_limit;

	// motor move
	int stage_main_x_status;
	int stage_main_y_status;
	int stage_sub_x_status;

	// realtime value
	double stage_main_x_pos;
	double stage_main_y_pos;
	double stage_sub_x_pos;

	bool bStart;	// auto 동작 start
	bool bStop;	// auto 동작 stop
	bool bReady;	// safety pos move 
	bool bReadyComplete;	// safety pos move complete
	bool bProcess;
	bool bProcessComplete;
	bool bPreAlign;	// Ready Pos move
	bool bPreAlignComplete;	// ready pos move complete
	bool bTabAlign;	// Align 실행
	bool bTabAlignComplete;	// Align complete
	bool bInspect;	// Inspect 진행 중
	bool bInspectComplete;	// Inspect 동작 완료
	bool bJudge;	// 판정 
	bool bJudgeComplete;	// 판정 완료
	bool bUnloading;	// 배출
	bool bUnloadingComplete;	// 배출 완료

	bool process_pass_prealign;
	bool process_pass_tabalign;

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

	bool check_ng_ma_x;
	bool check_ng_ma_y;
	bool check_ng_open;
	bool check_ng_short;
	bool check_ng_width;
	bool check_ng_height;
	bool check_ng_both;
	bool check_ng_upper_mark_1;
	bool check_ng_upper_mark_2;
	bool check_ng_side_mark_1;
	bool check_ng_side_mark_2;

	bool check_manual;

	double finish_position;		// 현재 위치에서 진행하였을 때 검사 종료를 위한 sub_x 이동 값
	double first_finish_position;
	double over_pos;			// sub_x limit을 넘었을 때 더 이동해야 하는 sub_x 이동 값
	int possible_tab;			// 첫 번째 검사 진행 시 가능한 Tab의 수

	int pass_tab[30];

	Mat load_align_image;
	Mat load_align_mark;
	Mat resize_upper_image;
	Mat resize_side_image;
	Mat resize_upper_mark;
	Mat detect_align_mark;
	Mat Merge_result;
	Mat Merge_origin;

	Mat load_side_mark_1;
	Mat load_side_mark_2;

	Mat resize_side_mark_1;
	Mat resize_side_mark_2;

	Mat detect_side_mark_1;
	Mat detect_side_mark_2;

	HDC hdc_upper;
	HDC hdc_side;

	char ImageBuf[2048];
	BITMAPINFO *ImageInfo = 0;

	char loadBuf[2048];			// load Image
	BITMAPINFO *loadInfo = 0;

	char mergeBuf[2048];		// merge Image
	BITMAPINFO *mergeInfo = 0;

	double maxVal_align;
	Point maxLoc_align;

	double align_x_start;
	double align_y_start;
	double align_width;
	double align_height;

	double tabalign_x_start;
	double tabalign_y_start;
	double tabalign_width;
	double tabalign_height;

	int upper_start_position;
	int upper_end_position;
	int side_start_position;
	int side_end_position;

	CString str_log;
	
	CTime log_time;
	CString str_log_time;

	// Tacktime
	DWORD Now_Time;		// for tacktime calculation
	DWORD Start_Time;	// start button click
	DWORD Align_Time;	// move process pos <-> align finish
	DWORD Inspect_Time;	// align finish <-> inspection finish
	DWORD Judge_Time;	// inspection finish <-> judge finish
	DWORD Unloading_Time;	// judge finish <-> unloading pos 

	CTime inspection_start_time;
	CString str_inspection_start_time;

	CString file_path;
	CString saveTabPath;

	CString folder_path;
	CString origin_path;
	CString result_path;

	void ParameterInit();
	void ImageAlign(int alignCase);
	void ExcelResult(int TabNum);
	void PopupResult();
	void Image_Inspect(int TabNum, int TabPoint);
	void Image_manual_Inspect();
	void CamUpperStatus();
	void CamSideStatus();
	void CamStatus();

	int upper_camera_status;
	int side_camera_status;


	int iRet;
	int errorRet;
	int clampRet;

	double prealign_pos_left;
	double prealign_pos_right;

	double align_correction;

	int tab_start;

	double tab_start_point;
	double tab_center_point;
	double tab_end_point;

	//  ng 결과 관련 행렬
	int ng_result_list_count;
	int ng_ma_x_list_count;
	int ng_ma_y_list_count;
	int ng_os_list_count;
	int ng_other_list_count;

	// 검사 결과 color
	int ma_x_r;
	int ma_x_g;
	int ma_x_b;

	int ma_y_r;
	int ma_y_g;
	int ma_y_b;

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
	int	height_g;
	int height_b;

	int both_r;
	int both_g;
	int both_b;


	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedBtnEmo();
	CListCtrl m_list_log;

	int log_count;

	void display_log(CString time, CString level, CString point, CString message, int log_count);

	int check_alarm;
	CEdit m_edit_process;

	int check_process_stop;
	int process_stop;
	void process_clicked_stop();

	int check_alram_unloading;

	void displayAlarm(int nCase);

	void DrawLine(CPoint startPos, CPoint endPos, int Cam, CString strText);
	void DrawRectangle(CPoint startPos, CPoint endPos, int Cam, CString strText_Ver, CString strText_Hor);
	void DrawCircle(CPoint StartPos, CPoint endPos, int Radius, int Cam, CString strText);
	afx_msg void OnBnClickedBtnManualInspect(); 

	int process_af_check;

	CEdit m_edit_glass_id;
};


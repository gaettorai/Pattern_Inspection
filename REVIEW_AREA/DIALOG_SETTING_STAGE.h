#pragma once


// DIALOG_SETTING_STAGE 대화 상자

class DIALOG_SETTING_STAGE : public CDialogEx
{
	DECLARE_DYNAMIC(DIALOG_SETTING_STAGE)

public:
	DIALOG_SETTING_STAGE(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DIALOG_SETTING_STAGE();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SETTING_STAGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	CEdit m_edit_stage_main_x_ready_pos;
	CEdit m_edit_stage_main_x_process_pos;
	CEdit m_edit_stage_main_x_limit_min;
	CEdit m_edit_stage_main_x_limit_max;
	CEdit m_edit_stage_main_x_manual_speed;
	CEdit m_edit_stage_main_x_process_speed;

	CEdit m_edit_stage_main_y_ready_pos;
	CEdit m_edit_stage_main_y_process_pos;
	CEdit m_edit_stage_main_y_limit_min;
	CEdit m_edit_stage_main_y_limit_max;
	CEdit m_edit_stage_main_y_manual_speed;
	CEdit m_edit_stage_main_y_process_speed;

	CEdit m_edit_stage_sub_x_ready_pos;
	CEdit m_edit_stage_sub_x_process_pos;
	CEdit m_edit_stage_sub_x_limit_min;
	CEdit m_edit_stage_sub_x_limit_max;
	CEdit m_edit_stage_sub_x_align_offset;
	CEdit m_edit_stage_sub_x_manual_speed;
	CEdit m_edit_stage_sub_x_process_speed;
};

#pragma once


// DIALOG_SETTING_PARAM 대화 상자

class DIALOG_SETTING_PARAM : public CDialogEx
{
	DECLARE_DYNAMIC(DIALOG_SETTING_PARAM)

public:
	DIALOG_SETTING_PARAM(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DIALOG_SETTING_PARAM();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SETTING_PARAM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	CEdit m_edit_prealign_matching;
	CEdit m_edit_tabalign_matching;
	CEdit m_edit_prealign_range;
	CEdit m_edit_width;
	CEdit m_edit_height;
	CEdit m_edit_width_range;
	CEdit m_edit_height_range;
	CEdit m_edit_ma_x_range;
	CEdit m_edit_ma_y;
	CEdit m_edit_ma_y_range;
	CEdit m_edit_offset;
	CEdit m_edit_upper_align_offset;
	CEdit m_edit_side_align_offset;
	CEdit m_edit_space;
};

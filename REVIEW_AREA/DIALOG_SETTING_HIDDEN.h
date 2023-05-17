#pragma once


// DIALOG_SETTING_HIDDEN 대화 상자

class DIALOG_SETTING_HIDDEN : public CDialogEx
{
	DECLARE_DYNAMIC(DIALOG_SETTING_HIDDEN)

public:
	DIALOG_SETTING_HIDDEN(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DIALOG_SETTING_HIDDEN();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SETTING_HIDDEN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	CEdit m_edit_binary_upper;
	CEdit m_edit_binary_side;
	CEdit m_edit_binary_edge;
	CEdit m_edit_morphology_open;
	CEdit m_edit_morphology_close;
	CEdit m_edit_upper_contour;
	CEdit m_edit_side_contour;
	CEdit m_edit_gantry_limit_min;
	CEdit m_edit_gantry_limit_max;
	CEdit m_edit_af_limit;
};

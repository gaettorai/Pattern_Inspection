#pragma once


// DIALOG_SETTING_INFO 대화 상자

class DIALOG_SETTING_INFO : public CDialogEx
{
	DECLARE_DYNAMIC(DIALOG_SETTING_INFO)

public:
	DIALOG_SETTING_INFO(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DIALOG_SETTING_INFO();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SETTING_INFO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	CEdit m_edit_tab_count;
	CEdit m_edit_tab_point;
	CEdit m_edit_tab_dist;
	CEdit m_edit_tab_interval;
	CEdit m_edit_upper_roi_min;
	CEdit m_edit_upper_roi_max;
	CEdit m_edit_side_roi_min;
	CEdit m_edit_side_roi_max;
	CEdit m_edit_edge_roi_min;
	CEdit m_edit_edge_roi_max;

};

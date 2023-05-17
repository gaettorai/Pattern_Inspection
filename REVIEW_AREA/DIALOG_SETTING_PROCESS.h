#pragma once


// DIALOG_SETTING_PROCESS 대화 상자

class DIALOG_SETTING_PROCESS : public CDialogEx
{
	DECLARE_DYNAMIC(DIALOG_SETTING_PROCESS)

public:
	DIALOG_SETTING_PROCESS(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DIALOG_SETTING_PROCESS();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SETTING_PROCESS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedBtnTabalignPass();
	afx_msg void OnBnClickedBtnPrealignPass();
	afx_msg void OnBnClickedBtnTabPass();

	void pass_tab_setting(int tab, int Case);

	CButton* pButton;
	CRect rect_tab_pass;

	void PassTab(int TabNum);

	CBitmap m_bmp_tab_1;
	CBitmap m_bmp_tab_2;
	CBitmap m_bmp_tab_3;
	CBitmap m_bmp_tab_4;
	CBitmap m_bmp_tab_5;
	CBitmap m_bmp_tab_6;
	CBitmap m_bmp_tab_7;
	CBitmap m_bmp_tab_8;
	CBitmap m_bmp_tab_9;
	CBitmap m_bmp_tab_10;
	CBitmap m_bmp_tab_11;
	CBitmap m_bmp_tab_12;
	CBitmap m_bmp_tab_13;
	CBitmap m_bmp_tab_14;
	CBitmap m_bmp_tab_15;
	CBitmap m_bmp_tab_16;
	CBitmap m_bmp_tab_17;
	CBitmap m_bmp_tab_18;
	CBitmap m_bmp_tab_19;
	CBitmap m_bmp_tab_20;
	CBitmap m_bmp_tab_21;
	CBitmap m_bmp_tab_22;
	CBitmap m_bmp_tab_23;
	CBitmap m_bmp_tab_24;
	CBitmap m_bmp_tab_25;
	CBitmap m_bmp_tab_26;
	CBitmap m_bmp_tab_27;
	CBitmap m_bmp_tab_28;
	CBitmap m_bmp_tab_29;
	CBitmap m_bmp_tab_30;

	CBitmap m_bmp_tab_1_a;
	CBitmap m_bmp_tab_2_a;
	CBitmap m_bmp_tab_3_a;
	CBitmap m_bmp_tab_4_a;
	CBitmap m_bmp_tab_5_a;
	CBitmap m_bmp_tab_6_a;
	CBitmap m_bmp_tab_7_a;
	CBitmap m_bmp_tab_8_a;
	CBitmap m_bmp_tab_9_a;
	CBitmap m_bmp_tab_10_a;
	CBitmap m_bmp_tab_11_a;
	CBitmap m_bmp_tab_12_a;
	CBitmap m_bmp_tab_13_a;
	CBitmap m_bmp_tab_14_a;
	CBitmap m_bmp_tab_15_a;
	CBitmap m_bmp_tab_16_a;
	CBitmap m_bmp_tab_17_a;
	CBitmap m_bmp_tab_18_a;
	CBitmap m_bmp_tab_19_a;
	CBitmap m_bmp_tab_20_a;
	CBitmap m_bmp_tab_21_a;
	CBitmap m_bmp_tab_22_a;
	CBitmap m_bmp_tab_23_a;
	CBitmap m_bmp_tab_24_a;
	CBitmap m_bmp_tab_25_a;
	CBitmap m_bmp_tab_26_a;
	CBitmap m_bmp_tab_27_a;
	CBitmap m_bmp_tab_28_a;
	CBitmap m_bmp_tab_29_a;
	CBitmap m_bmp_tab_30_a;


	CButton m_btn_tab_1;
	CButton m_btn_tab_2;
	CButton m_btn_tab_3;
	CButton m_btn_tab_4;
	CButton m_btn_tab_5;
	CButton m_btn_tab_6;
	CButton m_btn_tab_7;
	CButton m_btn_tab_8;
	CButton m_btn_tab_9;
	CButton m_btn_tab_10;
	CButton m_btn_tab_11;
	CButton m_btn_tab_12;
	CButton m_btn_tab_13;
	CButton m_btn_tab_14;
	CButton m_btn_tab_15;
	CButton m_btn_tab_16;
	CButton m_btn_tab_17;
	CButton m_btn_tab_18;
	CButton m_btn_tab_19;
	CButton m_btn_tab_20;
	CButton m_btn_tab_21;
	CButton m_btn_tab_22;
	CButton m_btn_tab_23;
	CButton m_btn_tab_24;
	CButton m_btn_tab_25;
	CButton m_btn_tab_26;
	CButton m_btn_tab_27;
	CButton m_btn_tab_28;
	CButton m_btn_tab_29;
	CButton m_btn_tab_30;

	int tab_pass_active;
};

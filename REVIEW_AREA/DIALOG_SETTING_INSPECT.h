#pragma once


// DIALOG_SETTING_INSPECT 대화 상자

class DIALOG_SETTING_INSPECT : public CDialogEx
{
	DECLARE_DYNAMIC(DIALOG_SETTING_INSPECT)

public:
	DIALOG_SETTING_INSPECT(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DIALOG_SETTING_INSPECT();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SETTING_INSPECT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CButton m_chk_missalign_x;
	CButton m_chk_missalign_y;
	CButton m_chk_open;
	CButton m_chk_short;
	CButton m_chk_width;
	CButton m_chk_height;
	CMFCColorButton m_color_missalign_x;
	CMFCColorButton m_color_missalign_y;
	CMFCColorButton m_color_open;
	CMFCColorButton m_color_short;
	CMFCColorButton m_color_width;
	CMFCColorButton m_color_height;
	afx_msg void OnBnClickedColorMissalignX();
	afx_msg void OnBnClickedColorMissalignY();
	afx_msg void OnBnClickedColorOpen();
	afx_msg void OnBnClickedColorShort();
	afx_msg void OnBnClickedColorWidth();
	afx_msg void OnBnClickedColorHeight();

	COLORREF  ma_x_cl;
	COLORREF  ma_y_cl;
	COLORREF  open_cl;
	COLORREF  short_cl;
	COLORREF  width_cl;
	COLORREF  height_cl;
	COLORREF  both_cl;

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

	CButton m_chk_both;
	CMFCColorButton m_color_both;
	afx_msg void OnBnClickedColorBoth();
	afx_msg void OnBnClickedChkMissalignX();
	afx_msg void OnBnClickedChkMissalignY();
	afx_msg void OnBnClickedChkOpen();
	afx_msg void OnBnClickedChkShort();
	afx_msg void OnBnClickedChkWidth();
	afx_msg void OnBnClickedChkHeight();
	afx_msg void OnBnClickedChkBoth();
	afx_msg void OnBnClickedChkUpperMark1();
	afx_msg void OnBnClickedChkUpperMark2();
	afx_msg void OnBnClickedChkSideMark1();
	afx_msg void OnBnClickedChkSideMark2();

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

	CButton m_chk_upper_mark_1;
	CButton m_chk_upper_mark_2;
	CButton m_chk_side_mark_1;
	CButton m_chk_side_mark_2;
};

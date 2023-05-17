#pragma once


// DIALOG_SYSTEM 대화 상자

class DIALOG_SYSTEM : public CDialogEx
{
	DECLARE_DYNAMIC(DIALOG_SYSTEM)

public:
	DIALOG_SYSTEM(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DIALOG_SYSTEM();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SYSTEM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit_id;
	CEdit m_edit_password;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	CButton m_btn_ok;
	afx_msg void OnPaint();
};

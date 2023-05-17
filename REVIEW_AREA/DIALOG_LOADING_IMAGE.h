#pragma once


// DIALOG_LOADING_IMAGE 대화 상자



class DIALOG_LOADING_IMAGE : public CDialog
{
	DECLARE_DYNAMIC(DIALOG_LOADING_IMAGE)

public:
	DIALOG_LOADING_IMAGE(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DIALOG_LOADING_IMAGE();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_LOADING };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

public:
	void Show(UINT uMilliseconds = 5000);

	DECLARE_MESSAGE_MAP()
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual BOOL OnInitDialog();
};

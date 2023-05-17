#pragma once


// DIALOG_POPUP 대화 상자

class DIALOG_POPUP : public CDialogEx
{
	DECLARE_DYNAMIC(DIALOG_POPUP)

public:
	DIALOG_POPUP(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DIALOG_POPUP();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_POPUP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};

#pragma once


// DIALOG_HISTORY 대화 상자

class DIALOG_HISTORY : public CDialogEx
{
	DECLARE_DYNAMIC(DIALOG_HISTORY)

public:
	DIALOG_HISTORY(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DIALOG_HISTORY();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_HISTORY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CListCtrl m_list_folder;
	CListCtrl m_list_result;
	CStatic m_pic_select;
	CMFCShellTreeCtrl m_tree_folder;
};

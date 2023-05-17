#include <atltime.h>
#pragma once


// DIALOG_ALARM 대화 상자

class DIALOG_ALARM : public CDialogEx
{
	DECLARE_DYNAMIC(DIALOG_ALARM)

public:
	DIALOG_ALARM(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DIALOG_ALARM();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ALARM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CListCtrl m_list_alarm;

	void DisplayAlarm(int alarmCase);

	int alarm_count;

	CTime alarm_time;
	CString str_alarm_time;

	afx_msg void OnBnClickedBtnReset();
};

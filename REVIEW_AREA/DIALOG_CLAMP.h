﻿#pragma once


// DIALOG_CLAMP 대화 상자

class DIALOG_CLAMP : public CDialogEx
{
	DECLARE_DYNAMIC(DIALOG_CLAMP)

public:
	DIALOG_CLAMP(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DIALOG_CLAMP();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CLAMP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};

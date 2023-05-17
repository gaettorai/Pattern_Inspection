#pragma once

#include "DIALOG_SETTING_STAGE.h"
#include "DIALOG_SETTING_INFO.h"
#include "DIALOG_SETTING_PARAM.h"
#include "DIALOG_SETTING_HIDDEN.h"
#include "DIALOG_SETTING_PROCESS.h"
#include "DIALOG_SETTING_INSPECT.h"
// DIALOG_SETTING 대화 상자

class DIALOG_SETTING : public CDialogEx
{
	DECLARE_DYNAMIC(DIALOG_SETTING)

public:
	DIALOG_SETTING(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DIALOG_SETTING();

	DIALOG_SETTING_STAGE*	dlg_setting_stage;
	DIALOG_SETTING_INFO*	dlg_setting_info;
	DIALOG_SETTING_PARAM*	dlg_setting_param;
	DIALOG_SETTING_HIDDEN*	dlg_setting_hidden;
	DIALOG_SETTING_PROCESS*	dlg_setting_process;
	DIALOG_SETTING_INSPECT*	dlg_setting_inspect;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SETTING };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnBnClickedBtnRecipe();
	afx_msg void OnBnClickedBtnModify();
	afx_msg void OnBnClickedBtnApply();
	afx_msg void OnBnClickedBtnCancel();

	void Init_Parameter();
	CEdit m_edit_load_recipe;
	CTabCtrl m_tab_setting;
	afx_msg void OnSelchangeTabSetting(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedBtnSave();
	CString recipe_name;

	CButton m_btn_modify;
	CButton m_btn_apply;
	CButton m_btn_save;
	CButton m_btn_cancel;
	CButton m_btn_recipe;
};

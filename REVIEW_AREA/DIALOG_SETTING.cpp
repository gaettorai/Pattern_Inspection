// DIALOG_SETTING.cpp: 구현 파일
//

#include "stdafx.h"
#include "REVIEW_AREA.h"
#include "DIALOG_SETTING.h"
#include "afxdialogex.h"

#include "REVIEW_AREADlg.h"

// DIALOG_SETTING 대화 상자

IMPLEMENT_DYNAMIC(DIALOG_SETTING, CDialogEx)

DIALOG_SETTING::DIALOG_SETTING(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SETTING, pParent)
{

}

DIALOG_SETTING::~DIALOG_SETTING()
{
}

void DIALOG_SETTING::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_TAB_SETTING, m_tab_setting);
	DDX_Control(pDX, IDC_BTN_MODIFY, m_btn_modify);
	DDX_Control(pDX, IDC_BTN_APPLY, m_btn_apply);
	DDX_Control(pDX, IDC_BTN_SAVE, m_btn_save);
	DDX_Control(pDX, IDC_BTN_CANCEL, m_btn_cancel);
	DDX_Control(pDX, IDC_BTN_RECIPE, m_btn_recipe);
}


BEGIN_MESSAGE_MAP(DIALOG_SETTING, CDialogEx)
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_BTN_RECIPE, &DIALOG_SETTING::OnBnClickedBtnRecipe)
	ON_BN_CLICKED(IDC_BTN_MODIFY, &DIALOG_SETTING::OnBnClickedBtnModify)
	ON_BN_CLICKED(IDC_BTN_APPLY, &DIALOG_SETTING::OnBnClickedBtnApply)
	ON_BN_CLICKED(IDC_BTN_CANCEL, &DIALOG_SETTING::OnBnClickedBtnCancel)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_SETTING, &DIALOG_SETTING::OnSelchangeTabSetting)
	ON_BN_CLICKED(IDC_BTN_SAVE, &DIALOG_SETTING::OnBnClickedBtnSave)
END_MESSAGE_MAP()


// DIALOG_SETTING 메시지 처리기


BOOL DIALOG_SETTING::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	int static_width = 100;
	int static_height = 20;

	int edit_width = 70;
	int edit_height = 20;

	int y_start = 100;

	GetDlgItem(IDC_BTN_RECIPE)->MoveWindow(10, 10, 50, 30);
	GetDlgItem(IDC_STATIC_LOAD_RECIPE)->MoveWindow(70, 10, 80, 30);
	GetDlgItem(IDC_BTN_MODIFY)->MoveWindow(160, 10, 50, 30);
	GetDlgItem(IDC_BTN_APPLY)->MoveWindow(220, 10, 50, 30);
	GetDlgItem(IDC_BTN_SAVE)->MoveWindow(280, 10, 50, 30);
	GetDlgItem(IDC_BTN_CANCEL)->MoveWindow(340, 10, 50, 30);

	GetDlgItem(IDC_TAB_SETTING)->MoveWindow(10, 50, 380, 330);

	m_tab_setting.InsertItem(0, _T("STAGE"));
	m_tab_setting.InsertItem(1, _T("INFO"));
	m_tab_setting.InsertItem(2, _T("PARAM."));
	m_tab_setting.InsertItem(3, _T("PROCESS"));
	m_tab_setting.InsertItem(4, _T("INSPECT"));
	//m_tab_setting.InsertItem(5, _T("HIDDEN"));

	m_tab_setting.SetCurSel(0);

	dlg_setting_stage = new DIALOG_SETTING_STAGE;
	dlg_setting_stage->Create(IDD_DIALOG_SETTING_STAGE, this);
	dlg_setting_stage->MoveWindow(15, 55, 370, 300);
	dlg_setting_stage->ShowWindow(SW_SHOW);

	dlg_setting_info = new DIALOG_SETTING_INFO;
	dlg_setting_info->Create(IDD_DIALOG_SETTING_INFO, this);
	dlg_setting_info->MoveWindow(15, 55, 370, 300);
	dlg_setting_info->ShowWindow(SW_HIDE);

	dlg_setting_param = new DIALOG_SETTING_PARAM;
	dlg_setting_param->Create(IDD_DIALOG_SETTING_PARAM, this);
	dlg_setting_param->MoveWindow(15, 55, 370, 300);
	dlg_setting_param->ShowWindow(SW_HIDE);

	dlg_setting_hidden = new DIALOG_SETTING_HIDDEN;
	dlg_setting_hidden->Create(IDD_DIALOG_SETTING_HIDDEN, this);
	dlg_setting_hidden->MoveWindow(15, 55, 370, 300);
	dlg_setting_hidden->ShowWindow(SW_HIDE);

	dlg_setting_process = new DIALOG_SETTING_PROCESS;
	dlg_setting_process->Create(IDD_DIALOG_SETTING_PROCESS, this);
	dlg_setting_process->MoveWindow(15, 55, 370, 300);
	dlg_setting_process->ShowWindow(SW_HIDE);

	dlg_setting_inspect = new DIALOG_SETTING_INSPECT;
	dlg_setting_inspect->Create(IDD_DIALOG_SETTING_INSPECT, this);
	dlg_setting_inspect->MoveWindow(15, 55, 370, 300);
	dlg_setting_inspect->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_BTN_APPLY)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_CANCEL)->EnableWindow(FALSE);

	// STAGE
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_X_READY_POS)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_X_PROCESS_POS)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_X_LIMIT_MIN)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_X_LIMIT_MAX)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_X_MANUAL_SPEED)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_X_PROCESS_SPEED)->EnableWindow(FALSE);

	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_READY_POS)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_PROCESS_POS)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_LIMIT_MIN)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_LIMIT_MAX)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_MANUAL_SPEED)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_PROCESS_SPEED)->EnableWindow(FALSE);

	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_SUB_X_READY_POS)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_SUB_X_PROCESS_POS)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_SUB_X_LIMIT_MIN)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_SUB_X_LIMIT_MAX)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_SUB_X_ALIGN_OFFSET)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_SUB_X_MANUAL_SPEED)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_SUB_X_PROCESS_SPEED)->EnableWindow(FALSE);

	//INFO

	dlg_setting_info->GetDlgItem(IDC_EDIT_TAB_COUNT)->EnableWindow(FALSE);
	dlg_setting_info->GetDlgItem(IDC_EDIT_TAB_POINT)->EnableWindow(FALSE);
	dlg_setting_info->GetDlgItem(IDC_EDIT_TAB_DIST)->EnableWindow(FALSE);
	dlg_setting_info->GetDlgItem(IDC_EDIT_TAB_INTERVAL)->EnableWindow(FALSE);

	dlg_setting_info->GetDlgItem(IDC_EDIT_UPPER_ROI_MIN)->EnableWindow(FALSE);
	dlg_setting_info->GetDlgItem(IDC_EDIT_UPPER_ROI_MAX)->EnableWindow(FALSE);
	dlg_setting_info->GetDlgItem(IDC_EDIT_SIDE_ROI_MIN)->EnableWindow(FALSE);
	dlg_setting_info->GetDlgItem(IDC_EDIT_SIDE_ROI_MAX)->EnableWindow(FALSE);
	dlg_setting_info->GetDlgItem(IDC_EDIT_EDGE_ROI_MIN)->EnableWindow(FALSE);
	dlg_setting_info->GetDlgItem(IDC_EDIT_EDGE_ROI_MAX)->EnableWindow(FALSE);

	// param
	dlg_setting_param->GetDlgItem(IDC_EDIT_PREALIGN_MATCHING)->EnableWindow(FALSE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_TABALIGN_MATCHING)->EnableWindow(FALSE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_PREALIGN_RANGE)->EnableWindow(FALSE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_OFFSET)->EnableWindow(FALSE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_UPPER_ALIGN_OFFSET)->EnableWindow(FALSE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_SIDE_ALIGN_OFFSET)->EnableWindow(FALSE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_WIDTH)->EnableWindow(FALSE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_HEIGHT)->EnableWindow(FALSE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_SPACE)->EnableWindow(FALSE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_WIDTH_RANGE)->EnableWindow(FALSE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_HEIGHT_RANGE)->EnableWindow(FALSE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_MA_X_RANGE)->EnableWindow(FALSE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_MA_Y)->EnableWindow(FALSE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_MA_Y_RANGE)->EnableWindow(FALSE);

	// PROCESS
	dlg_setting_process->GetDlgItem(IDC_BTN_PREALIGN_PASS)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TABALIGN_PASS)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_PASS)->EnableWindow(FALSE);

	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_1)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_2)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_3)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_4)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_5)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_6)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_7)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_8)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_9)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_10)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_11)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_12)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_13)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_14)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_15)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_16)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_17)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_18)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_19)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_20)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_21)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_22)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_23)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_24)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_25)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_26)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_27)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_28)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_29)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_30)->EnableWindow(FALSE);


	// INSPECT
	dlg_setting_inspect->GetDlgItem(IDC_CHK_MISSALIGN_X)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_CHK_MISSALIGN_Y)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_CHK_OPEN)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_CHK_SHORT)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_CHK_WIDTH)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_CHK_HEIGHT)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_CHK_BOTH)->EnableWindow(FALSE);

	dlg_setting_inspect->GetDlgItem(IDC_COLOR_MISSALIGN_X)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_COLOR_MISSALIGN_Y)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_COLOR_OPEN)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_COLOR_SHORT)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_COLOR_WIDTH)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_COLOR_HEIGHT)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_COLOR_BOTH)->EnableWindow(FALSE);

	dlg_setting_inspect->GetDlgItem(IDC_CHK_UPPER_MARK_1)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_CHK_UPPER_MARK_2)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_CHK_SIDE_MARK_1)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_CHK_SIDE_MARK_2)->EnableWindow(FALSE);

	// hidden
	dlg_setting_hidden->GetDlgItem(IDC_EDIT_BINARY_UPPER)->EnableWindow(FALSE);
	dlg_setting_hidden->GetDlgItem(IDC_EDIT_BINARY_SIDE)->EnableWindow(FALSE);
	dlg_setting_hidden->GetDlgItem(IDC_EDIT_BINARY_EDGE)->EnableWindow(FALSE);

	dlg_setting_hidden->GetDlgItem(IDC_EDIT_MORPHOLOGY_OPEN)->EnableWindow(FALSE);
	dlg_setting_hidden->GetDlgItem(IDC_EDIT_MORPHOLOGY_CLOSE)->EnableWindow(FALSE);
	dlg_setting_hidden->GetDlgItem(IDC_EDIT_UPPER_CONTOUR)->EnableWindow(FALSE);
	dlg_setting_hidden->GetDlgItem(IDC_EDIT_SIDE_CONTOUR)->EnableWindow(FALSE);

	dlg_setting_hidden->GetDlgItem(IDC_EDIT_GANTRY_LIMIT_MIN)->EnableWindow(FALSE);
	dlg_setting_hidden->GetDlgItem(IDC_EDIT_GANTRY_LIMIT_MAX)->EnableWindow(FALSE);
	dlg_setting_hidden->GetDlgItem(IDC_EDIT_AF_LIMIT)->EnableWindow(FALSE);

	HFONT hNewFont;

	hNewFont = CreateFont(10, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_MODERN, _T("IMPACT"));
	//m_edit_load_recipe.SendMessage(WM_SETFONT, (WPARAM)hNewFont, (LPARAM)TRUE);


	/*HFONT hNewFont;

	hNewFont = CreateFont(10, 5, 0, 0, FW_BOLD, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_MODERN, _T("IMPACT"));
	m_btn_recipe.SendMessage(WM_SETFONT, (WPARAM)hNewFont, (LPARAM)TRUE);
	m_btn_modify.SendMessage(WM_SETFONT, (WPARAM)hNewFont, (LPARAM)TRUE);
	m_btn_apply.SendMessage(WM_SETFONT, (WPARAM)hNewFont, (LPARAM)TRUE);
	m_btn_save.SendMessage(WM_SETFONT, (WPARAM)hNewFont, (LPARAM)TRUE);
	m_btn_cancel.SendMessage(WM_SETFONT, (WPARAM)hNewFont, (LPARAM)TRUE);
	*/

	// Recipe 불러오기
	CString str_registry;

	str_registry = AfxGetApp()->GetProfileStringW(_T("RECIPE"), _T("Recipe_name"));
	GetDlgItem(IDC_STATIC_LOAD_RECIPE)->SetWindowTextW(str_registry);

	Init_Parameter();


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


BOOL DIALOG_SETTING::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_RETURN) // ENTER키 눌릴 시
			return TRUE;
		else if (pMsg->wParam == VK_ESCAPE) // ESC키 눌릴 시
			return TRUE;
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}


BOOL DIALOG_SETTING::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CRect rect;

	GetClientRect(rect);

	pDC->FillSolidRect(rect, RGB(255, 255, 255));

	return TRUE;
	//return CDialogEx::OnEraseBkgnd(pDC);
}


void DIALOG_SETTING::OnBnClickedBtnRecipe()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	static TCHAR BASED_CODE szFilter[] = _T(" 모든파일(*.*)|*.*|");

	CFileDialog dlg(TRUE, _T("*.jpg"), _T("image"), OFN_HIDEREADONLY, szFilter);

	if (IDOK == dlg.DoModal())
	{
		CString pathName = dlg.GetPathName();
		int value = pathName.GetLength();

		int i = pathName.ReverseFind('\\');//실행 파일 이름을 지우기 위해서 왼쪽에 있는 '/'를 찾는다.
		recipe_name = pathName.Mid(i + 1, value);//뒤에 있는 현재 실행 파일 이름을 지운다.

		i = recipe_name.ReverseFind('.');
		recipe_name = recipe_name.Left(i);

		AfxGetApp()->WriteProfileStringW(_T("RECIPE"), _T("Recipe_name"), recipe_name);

		GetDlgItem(IDC_STATIC_LOAD_RECIPE)->SetWindowTextW(recipe_name);

		Init_Parameter();
	}
}


void DIALOG_SETTING::OnBnClickedBtnModify()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItem(IDC_BTN_MODIFY)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_APPLY)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_CANCEL)->EnableWindow(TRUE);

	// STAGE
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_X_READY_POS)->EnableWindow(TRUE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_X_PROCESS_POS)->EnableWindow(TRUE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_X_LIMIT_MIN)->EnableWindow(TRUE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_X_LIMIT_MAX)->EnableWindow(TRUE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_X_MANUAL_SPEED)->EnableWindow(TRUE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_X_PROCESS_SPEED)->EnableWindow(TRUE);

	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_READY_POS)->EnableWindow(TRUE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_PROCESS_POS)->EnableWindow(TRUE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_LIMIT_MIN)->EnableWindow(TRUE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_LIMIT_MAX)->EnableWindow(TRUE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_MANUAL_SPEED)->EnableWindow(TRUE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_PROCESS_SPEED)->EnableWindow(TRUE);

	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_SUB_X_READY_POS)->EnableWindow(TRUE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_SUB_X_PROCESS_POS)->EnableWindow(TRUE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_SUB_X_LIMIT_MIN)->EnableWindow(TRUE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_SUB_X_LIMIT_MAX)->EnableWindow(TRUE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_SUB_X_ALIGN_OFFSET)->EnableWindow(TRUE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_SUB_X_MANUAL_SPEED)->EnableWindow(TRUE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_SUB_X_PROCESS_SPEED)->EnableWindow(TRUE);

	//INFO	
	dlg_setting_info->GetDlgItem(IDC_EDIT_TAB_COUNT)->EnableWindow(TRUE);
	dlg_setting_info->GetDlgItem(IDC_EDIT_TAB_POINT)->EnableWindow(TRUE);
	dlg_setting_info->GetDlgItem(IDC_EDIT_TAB_DIST)->EnableWindow(TRUE);
	dlg_setting_info->GetDlgItem(IDC_EDIT_TAB_INTERVAL)->EnableWindow(TRUE);

	dlg_setting_info->GetDlgItem(IDC_EDIT_UPPER_ROI_MIN)->EnableWindow(TRUE);
	dlg_setting_info->GetDlgItem(IDC_EDIT_UPPER_ROI_MAX)->EnableWindow(TRUE);
	dlg_setting_info->GetDlgItem(IDC_EDIT_SIDE_ROI_MIN)->EnableWindow(TRUE);
	dlg_setting_info->GetDlgItem(IDC_EDIT_SIDE_ROI_MAX)->EnableWindow(TRUE);
	dlg_setting_info->GetDlgItem(IDC_EDIT_EDGE_ROI_MIN)->EnableWindow(TRUE);
	dlg_setting_info->GetDlgItem(IDC_EDIT_EDGE_ROI_MAX)->EnableWindow(TRUE);


	// param
	dlg_setting_param->GetDlgItem(IDC_EDIT_PREALIGN_MATCHING)->EnableWindow(TRUE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_TABALIGN_MATCHING)->EnableWindow(TRUE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_PREALIGN_RANGE)->EnableWindow(TRUE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_OFFSET)->EnableWindow(TRUE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_UPPER_ALIGN_OFFSET)->EnableWindow(TRUE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_SIDE_ALIGN_OFFSET)->EnableWindow(TRUE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_WIDTH)->EnableWindow(TRUE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_HEIGHT)->EnableWindow(TRUE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_SPACE)->EnableWindow(TRUE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_WIDTH_RANGE)->EnableWindow(TRUE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_HEIGHT_RANGE)->EnableWindow(TRUE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_MA_X_RANGE)->EnableWindow(TRUE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_MA_Y)->EnableWindow(TRUE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_MA_Y_RANGE)->EnableWindow(TRUE);

	// PROCESS
	dlg_setting_process->GetDlgItem(IDC_BTN_PREALIGN_PASS)->EnableWindow(TRUE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TABALIGN_PASS)->EnableWindow(TRUE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_PASS)->EnableWindow(TRUE);

	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_1)->EnableWindow(TRUE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_2)->EnableWindow(TRUE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_3)->EnableWindow(TRUE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_4)->EnableWindow(TRUE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_5)->EnableWindow(TRUE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_6)->EnableWindow(TRUE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_7)->EnableWindow(TRUE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_8)->EnableWindow(TRUE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_9)->EnableWindow(TRUE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_10)->EnableWindow(TRUE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_11)->EnableWindow(TRUE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_12)->EnableWindow(TRUE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_13)->EnableWindow(TRUE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_14)->EnableWindow(TRUE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_15)->EnableWindow(TRUE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_16)->EnableWindow(TRUE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_17)->EnableWindow(TRUE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_18)->EnableWindow(TRUE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_19)->EnableWindow(TRUE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_20)->EnableWindow(TRUE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_21)->EnableWindow(TRUE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_22)->EnableWindow(TRUE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_23)->EnableWindow(TRUE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_24)->EnableWindow(TRUE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_25)->EnableWindow(TRUE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_26)->EnableWindow(TRUE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_27)->EnableWindow(TRUE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_28)->EnableWindow(TRUE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_29)->EnableWindow(TRUE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_30)->EnableWindow(TRUE);

	dlg_setting_process->tab_pass_active = 1;

	// INSPECT
	dlg_setting_inspect->GetDlgItem(IDC_CHK_MISSALIGN_X)->EnableWindow(TRUE);
	dlg_setting_inspect->GetDlgItem(IDC_CHK_MISSALIGN_Y)->EnableWindow(TRUE);
	dlg_setting_inspect->GetDlgItem(IDC_CHK_OPEN)->EnableWindow(TRUE);
	dlg_setting_inspect->GetDlgItem(IDC_CHK_SHORT)->EnableWindow(TRUE);
	dlg_setting_inspect->GetDlgItem(IDC_CHK_WIDTH)->EnableWindow(TRUE);
	dlg_setting_inspect->GetDlgItem(IDC_CHK_HEIGHT)->EnableWindow(TRUE);
	dlg_setting_inspect->GetDlgItem(IDC_CHK_BOTH)->EnableWindow(TRUE);

	dlg_setting_inspect->GetDlgItem(IDC_COLOR_MISSALIGN_X)->EnableWindow(TRUE);
	dlg_setting_inspect->GetDlgItem(IDC_COLOR_MISSALIGN_Y)->EnableWindow(TRUE);
	dlg_setting_inspect->GetDlgItem(IDC_COLOR_OPEN)->EnableWindow(TRUE);
	dlg_setting_inspect->GetDlgItem(IDC_COLOR_SHORT)->EnableWindow(TRUE);
	dlg_setting_inspect->GetDlgItem(IDC_COLOR_WIDTH)->EnableWindow(TRUE);
	dlg_setting_inspect->GetDlgItem(IDC_COLOR_HEIGHT)->EnableWindow(TRUE);
	dlg_setting_inspect->GetDlgItem(IDC_COLOR_BOTH)->EnableWindow(TRUE);

	dlg_setting_inspect->GetDlgItem(IDC_CHK_UPPER_MARK_1)->EnableWindow(TRUE);
	dlg_setting_inspect->GetDlgItem(IDC_CHK_UPPER_MARK_2)->EnableWindow(TRUE);
	dlg_setting_inspect->GetDlgItem(IDC_CHK_SIDE_MARK_1)->EnableWindow(TRUE);
	dlg_setting_inspect->GetDlgItem(IDC_CHK_SIDE_MARK_2)->EnableWindow(TRUE);

	// hidden
	dlg_setting_hidden->GetDlgItem(IDC_EDIT_BINARY_UPPER)->EnableWindow(TRUE);
	dlg_setting_hidden->GetDlgItem(IDC_EDIT_BINARY_SIDE)->EnableWindow(TRUE);
	dlg_setting_hidden->GetDlgItem(IDC_EDIT_BINARY_EDGE)->EnableWindow(TRUE);

	dlg_setting_hidden->GetDlgItem(IDC_EDIT_MORPHOLOGY_OPEN)->EnableWindow(TRUE);
	dlg_setting_hidden->GetDlgItem(IDC_EDIT_MORPHOLOGY_CLOSE)->EnableWindow(TRUE);
	dlg_setting_hidden->GetDlgItem(IDC_EDIT_UPPER_CONTOUR)->EnableWindow(TRUE);
	dlg_setting_hidden->GetDlgItem(IDC_EDIT_SIDE_CONTOUR)->EnableWindow(TRUE);

	dlg_setting_hidden->GetDlgItem(IDC_EDIT_GANTRY_LIMIT_MIN)->EnableWindow(TRUE);
	dlg_setting_hidden->GetDlgItem(IDC_EDIT_GANTRY_LIMIT_MAX)->EnableWindow(TRUE);
	dlg_setting_hidden->GetDlgItem(IDC_EDIT_AF_LIMIT)->EnableWindow(TRUE);
}


void DIALOG_SETTING::OnBnClickedBtnApply()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString str_recipe;
	CString str_edit;

	GetDlgItem(IDC_STATIC_LOAD_RECIPE)->GetWindowTextW(str_recipe);

	AfxGetApp()->WriteProfileStringW(_T("RECIPE"), _T("Recipe_name"), str_recipe);

	// Stage X
	dlg_setting_stage->m_edit_stage_main_x_ready_pos.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Stage_Main_X_Ready_pos"), str_edit);

	dlg_setting_stage->m_edit_stage_main_x_process_pos.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Stage_Main_X_Process_pos"), str_edit);

	dlg_setting_stage->m_edit_stage_main_x_limit_min.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Stage_Main_X_Limit_min"), str_edit);

	dlg_setting_stage->m_edit_stage_main_x_limit_max.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Stage_Main_X_Limit_max"), str_edit);

	dlg_setting_stage->m_edit_stage_main_x_manual_speed.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Stage_Main_X_Manual_speed"), str_edit);

	dlg_setting_stage->m_edit_stage_main_x_process_speed.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Stage_Main_X_Process_speed"), str_edit);

	// Stage Y
	dlg_setting_stage->m_edit_stage_main_y_ready_pos.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Stage_Main_Y_Ready_pos"), str_edit);

	dlg_setting_stage->m_edit_stage_main_y_process_pos.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Stage_Main_Y_Process_pos"), str_edit);

	dlg_setting_stage->m_edit_stage_main_y_limit_min.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Stage_Main_Y_Limit_min"), str_edit);

	dlg_setting_stage->m_edit_stage_main_y_limit_max.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Stage_Main_Y_Limit_max"), str_edit);

	dlg_setting_stage->m_edit_stage_main_y_manual_speed.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Stage_Main_Y_Manual_speed"), str_edit);

	dlg_setting_stage->m_edit_stage_main_y_process_speed.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Stage_Main_Y_Process_speed"), str_edit);

	// Sub_X
	dlg_setting_stage->m_edit_stage_sub_x_ready_pos.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Stage_Sub_X_Ready_pos"), str_edit);

	dlg_setting_stage->m_edit_stage_sub_x_process_pos.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Stage_Sub_X_Process_pos"), str_edit);

	dlg_setting_stage->m_edit_stage_sub_x_limit_min.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Stage_Sub_X_Limit_min"), str_edit);

	dlg_setting_stage->m_edit_stage_sub_x_limit_max.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Stage_Sub_X_Limit_max"), str_edit);

	dlg_setting_stage->m_edit_stage_sub_x_align_offset.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Stage_Sub_X_Align_offset"), str_edit);

	dlg_setting_stage->m_edit_stage_sub_x_manual_speed.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Stage_Sub_X_Manual_speed"), str_edit);

	dlg_setting_stage->m_edit_stage_sub_x_process_speed.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Stage_Sub_X_Process_speed"), str_edit);



	// Tab Info
	dlg_setting_info->m_edit_tab_count.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Tab_Count"), str_edit);

	dlg_setting_info->m_edit_tab_point.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Tab_Point"), str_edit);

	dlg_setting_info->m_edit_tab_dist.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Tab_Dist"), str_edit);

	dlg_setting_info->m_edit_tab_interval.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Tab_Interval"), str_edit);

	dlg_setting_info->m_edit_upper_roi_min.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Upper_Roi_min"), str_edit);

	dlg_setting_info->m_edit_upper_roi_max.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Upper_Roi_max"), str_edit);

	dlg_setting_info->m_edit_side_roi_min.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Side_Roi_min"), str_edit);

	dlg_setting_info->m_edit_side_roi_max.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Side_Roi_max"), str_edit);

	dlg_setting_info->m_edit_edge_roi_min.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Edge_Roi_min"), str_edit);

	dlg_setting_info->m_edit_edge_roi_max.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Edge_Roi_max"), str_edit);


	// Inspection
	dlg_setting_param->m_edit_prealign_matching.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("PreAlign_Matching"), str_edit);

	dlg_setting_param->m_edit_tabalign_matching.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("TabAlign_Matching"), str_edit);

	dlg_setting_param->m_edit_prealign_range.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("PreAlign_Range"), str_edit);

	dlg_setting_param->m_edit_offset.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Offset"), str_edit);

	dlg_setting_param->m_edit_upper_align_offset.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Upper_Align_Offset"), str_edit);

	dlg_setting_param->m_edit_side_align_offset.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Side_Align_Offset"), str_edit);

	dlg_setting_param->m_edit_width.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Width"), str_edit);

	dlg_setting_param->m_edit_height.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Height"), str_edit);

	dlg_setting_param->m_edit_space.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Space"), str_edit);

	dlg_setting_param->m_edit_width_range.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Width_Range"), str_edit);

	dlg_setting_param->m_edit_height_range.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Height_Range"), str_edit);

	dlg_setting_param->m_edit_ma_x_range.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("MissAlign_X_Range"), str_edit);

	dlg_setting_param->m_edit_ma_y.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("MissAlign_Y"), str_edit);

	dlg_setting_param->m_edit_ma_y_range.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("MissAlign_Y_Range"), str_edit);

	// ENGINEER MODE
	dlg_setting_hidden->m_edit_binary_upper.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Binary_Upper"), str_edit);

	dlg_setting_hidden->m_edit_binary_side.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Binary_Side"), str_edit);

	dlg_setting_hidden->m_edit_binary_edge.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Binary_Edge"), str_edit);

	dlg_setting_hidden->m_edit_morphology_open.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Morphology_Open"), str_edit);

	dlg_setting_hidden->m_edit_morphology_close.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Morphology_Close"), str_edit);

	dlg_setting_hidden->m_edit_upper_contour.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Upper_Contour"), str_edit);

	dlg_setting_hidden->m_edit_side_contour.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Side_Contour"), str_edit);

	dlg_setting_hidden->m_edit_gantry_limit_min.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Gantry_Limit_min"), str_edit);

	dlg_setting_hidden->m_edit_gantry_limit_max.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("Gantry_Limit_max"), str_edit);

	dlg_setting_hidden->m_edit_af_limit.GetWindowTextW(str_edit);
	AfxGetApp()->WriteProfileStringW(str_recipe, _T("AF_Limit"), str_edit);


	///
	GetDlgItem(IDC_BTN_MODIFY)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_APPLY)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_CANCEL)->EnableWindow(FALSE);

	// STAGE
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_X_READY_POS)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_X_PROCESS_POS)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_X_LIMIT_MIN)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_X_LIMIT_MAX)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_X_MANUAL_SPEED)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_X_PROCESS_SPEED)->EnableWindow(FALSE);

	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_READY_POS)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_PROCESS_POS)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_LIMIT_MIN)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_LIMIT_MAX)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_MANUAL_SPEED)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_PROCESS_SPEED)->EnableWindow(FALSE);

	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_SUB_X_READY_POS)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_SUB_X_PROCESS_POS)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_SUB_X_LIMIT_MIN)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_SUB_X_LIMIT_MAX)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_SUB_X_ALIGN_OFFSET)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_SUB_X_MANUAL_SPEED)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_SUB_X_PROCESS_SPEED)->EnableWindow(FALSE);


	//INFO

	dlg_setting_info->GetDlgItem(IDC_EDIT_TAB_COUNT)->EnableWindow(FALSE);
	dlg_setting_info->GetDlgItem(IDC_EDIT_TAB_POINT)->EnableWindow(FALSE);
	dlg_setting_info->GetDlgItem(IDC_EDIT_TAB_DIST)->EnableWindow(FALSE);
	dlg_setting_info->GetDlgItem(IDC_EDIT_TAB_INTERVAL)->EnableWindow(FALSE);

	dlg_setting_info->GetDlgItem(IDC_EDIT_UPPER_ROI_MIN)->EnableWindow(FALSE);
	dlg_setting_info->GetDlgItem(IDC_EDIT_UPPER_ROI_MAX)->EnableWindow(FALSE);
	dlg_setting_info->GetDlgItem(IDC_EDIT_SIDE_ROI_MIN)->EnableWindow(FALSE);
	dlg_setting_info->GetDlgItem(IDC_EDIT_SIDE_ROI_MAX)->EnableWindow(FALSE);
	dlg_setting_info->GetDlgItem(IDC_EDIT_EDGE_ROI_MIN)->EnableWindow(FALSE);
	dlg_setting_info->GetDlgItem(IDC_EDIT_EDGE_ROI_MAX)->EnableWindow(FALSE);

	// param
	dlg_setting_param->GetDlgItem(IDC_EDIT_PREALIGN_MATCHING)->EnableWindow(FALSE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_TABALIGN_MATCHING)->EnableWindow(FALSE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_PREALIGN_RANGE)->EnableWindow(FALSE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_OFFSET)->EnableWindow(FALSE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_UPPER_ALIGN_OFFSET)->EnableWindow(FALSE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_SIDE_ALIGN_OFFSET)->EnableWindow(FALSE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_WIDTH)->EnableWindow(FALSE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_HEIGHT)->EnableWindow(FALSE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_SPACE)->EnableWindow(FALSE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_WIDTH_RANGE)->EnableWindow(FALSE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_HEIGHT_RANGE)->EnableWindow(FALSE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_MA_X_RANGE)->EnableWindow(FALSE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_MA_Y)->EnableWindow(FALSE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_MA_Y_RANGE)->EnableWindow(FALSE);

	// PROCESS
	dlg_setting_process->GetDlgItem(IDC_BTN_PREALIGN_PASS)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TABALIGN_PASS)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_PASS)->EnableWindow(FALSE);

	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_1)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_2)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_3)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_4)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_5)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_6)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_7)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_8)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_9)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_10)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_11)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_12)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_13)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_14)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_15)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_16)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_17)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_18)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_19)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_20)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_21)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_22)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_23)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_24)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_25)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_26)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_27)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_28)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_29)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_30)->EnableWindow(FALSE);


	// INSPECT
	dlg_setting_inspect->GetDlgItem(IDC_CHK_MISSALIGN_X)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_CHK_MISSALIGN_Y)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_CHK_OPEN)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_CHK_SHORT)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_CHK_WIDTH)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_CHK_HEIGHT)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_CHK_BOTH)->EnableWindow(FALSE);

	dlg_setting_inspect->GetDlgItem(IDC_COLOR_MISSALIGN_X)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_COLOR_MISSALIGN_Y)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_COLOR_OPEN)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_COLOR_SHORT)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_COLOR_WIDTH)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_COLOR_HEIGHT)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_COLOR_BOTH)->EnableWindow(FALSE);

	dlg_setting_inspect->GetDlgItem(IDC_CHK_UPPER_MARK_1)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_CHK_UPPER_MARK_2)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_CHK_SIDE_MARK_1)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_CHK_SIDE_MARK_2)->EnableWindow(FALSE);

	// hidden

	dlg_setting_hidden->GetDlgItem(IDC_EDIT_BINARY_UPPER)->EnableWindow(FALSE);
	dlg_setting_hidden->GetDlgItem(IDC_EDIT_BINARY_SIDE)->EnableWindow(FALSE);
	dlg_setting_hidden->GetDlgItem(IDC_EDIT_BINARY_EDGE)->EnableWindow(FALSE);

	dlg_setting_hidden->GetDlgItem(IDC_EDIT_MORPHOLOGY_OPEN)->EnableWindow(FALSE);
	dlg_setting_hidden->GetDlgItem(IDC_EDIT_MORPHOLOGY_CLOSE)->EnableWindow(FALSE);
	dlg_setting_hidden->GetDlgItem(IDC_EDIT_UPPER_CONTOUR)->EnableWindow(FALSE);
	dlg_setting_hidden->GetDlgItem(IDC_EDIT_SIDE_CONTOUR)->EnableWindow(FALSE);

	dlg_setting_hidden->GetDlgItem(IDC_EDIT_GANTRY_LIMIT_MIN)->EnableWindow(FALSE);
	dlg_setting_hidden->GetDlgItem(IDC_EDIT_GANTRY_LIMIT_MAX)->EnableWindow(FALSE);
	dlg_setting_hidden->GetDlgItem(IDC_EDIT_AF_LIMIT)->EnableWindow(FALSE);

	Init_Parameter();
}


void DIALOG_SETTING::OnBnClickedBtnCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
		// Stage X
	dlg_setting_stage->m_edit_stage_main_x_ready_pos.Clear();
	dlg_setting_stage->m_edit_stage_main_x_process_pos.Clear();
	dlg_setting_stage->m_edit_stage_main_x_limit_min.Clear();
	dlg_setting_stage->m_edit_stage_main_x_limit_max.Clear();
	dlg_setting_stage->m_edit_stage_main_x_manual_speed.Clear();
	dlg_setting_stage->m_edit_stage_main_x_process_speed.Clear();

	// Stage Y
	dlg_setting_stage->m_edit_stage_main_y_ready_pos.Clear();
	dlg_setting_stage->m_edit_stage_main_y_process_pos.Clear();
	dlg_setting_stage->m_edit_stage_main_y_limit_min.Clear();
	dlg_setting_stage->m_edit_stage_main_y_limit_max.Clear();
	dlg_setting_stage->m_edit_stage_main_y_manual_speed.Clear();
	dlg_setting_stage->m_edit_stage_main_y_process_speed.Clear();

	// Sub_X
	dlg_setting_stage->m_edit_stage_sub_x_ready_pos.Clear();
	dlg_setting_stage->m_edit_stage_sub_x_process_pos.Clear();
	dlg_setting_stage->m_edit_stage_sub_x_limit_min.Clear();
	dlg_setting_stage->m_edit_stage_sub_x_limit_max.Clear();
	dlg_setting_stage->m_edit_stage_sub_x_align_offset.Clear();
	dlg_setting_stage->m_edit_stage_sub_x_manual_speed.Clear();
	dlg_setting_stage->m_edit_stage_sub_x_process_speed.Clear();

	// Tab Info
	dlg_setting_info->m_edit_tab_count.Clear();
	dlg_setting_info->m_edit_tab_point.Clear();
	dlg_setting_info->m_edit_tab_dist.Clear();
	dlg_setting_info->m_edit_tab_interval.Clear();

	dlg_setting_info->m_edit_upper_roi_min.Clear();
	dlg_setting_info->m_edit_upper_roi_max.Clear();
	dlg_setting_info->m_edit_side_roi_min.Clear();
	dlg_setting_info->m_edit_side_roi_max.Clear();
	dlg_setting_info->m_edit_edge_roi_min.Clear();
	dlg_setting_info->m_edit_edge_roi_max.Clear();

	// parameter
	dlg_setting_param->m_edit_prealign_matching.Clear();
	dlg_setting_param->m_edit_tabalign_matching.Clear();
	dlg_setting_param->m_edit_prealign_range.Clear();
	dlg_setting_param->m_edit_offset.Clear();
	dlg_setting_param->m_edit_upper_align_offset.Clear();
	dlg_setting_param->m_edit_side_align_offset.Clear();
	dlg_setting_param->m_edit_width.Clear();
	dlg_setting_param->m_edit_height.Clear();
	dlg_setting_param->m_edit_space.Clear();
	dlg_setting_param->m_edit_width_range.Clear();
	dlg_setting_param->m_edit_height_range.Clear();
	dlg_setting_param->m_edit_ma_x_range.Clear();
	dlg_setting_param->m_edit_ma_y.Clear();
	dlg_setting_param->m_edit_ma_y_range.Clear();

	// ENGINEER MODE
	dlg_setting_hidden->m_edit_binary_upper.Clear();
	dlg_setting_hidden->m_edit_binary_side.Clear();
	dlg_setting_hidden->m_edit_binary_edge.Clear();
	dlg_setting_hidden->m_edit_morphology_open.Clear();
	dlg_setting_hidden->m_edit_morphology_close.Clear();
	dlg_setting_hidden->m_edit_upper_contour.Clear();
	dlg_setting_hidden->m_edit_side_contour.Clear();
	dlg_setting_hidden->m_edit_gantry_limit_min.Clear();
	dlg_setting_hidden->m_edit_gantry_limit_max.Clear();
	dlg_setting_hidden->m_edit_af_limit.Clear();

	GetDlgItem(IDC_BTN_MODIFY)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_APPLY)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_CANCEL)->EnableWindow(FALSE);

	// STAGE
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_X_READY_POS)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_X_PROCESS_POS)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_X_LIMIT_MIN)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_X_LIMIT_MAX)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_X_MANUAL_SPEED)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_X_PROCESS_SPEED)->EnableWindow(FALSE);

	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_READY_POS)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_PROCESS_POS)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_LIMIT_MIN)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_LIMIT_MAX)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_MANUAL_SPEED)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_MAIN_Y_PROCESS_SPEED)->EnableWindow(FALSE);

	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_SUB_X_READY_POS)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_SUB_X_PROCESS_POS)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_SUB_X_LIMIT_MIN)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_SUB_X_LIMIT_MAX)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_SUB_X_ALIGN_OFFSET)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_SUB_X_MANUAL_SPEED)->EnableWindow(FALSE);
	dlg_setting_stage->GetDlgItem(IDC_EDIT_STAGE_SUB_X_PROCESS_SPEED)->EnableWindow(FALSE);


	//INFO

	dlg_setting_info->GetDlgItem(IDC_EDIT_TAB_COUNT)->EnableWindow(FALSE);
	dlg_setting_info->GetDlgItem(IDC_EDIT_TAB_POINT)->EnableWindow(FALSE);
	dlg_setting_info->GetDlgItem(IDC_EDIT_TAB_DIST)->EnableWindow(FALSE);
	dlg_setting_info->GetDlgItem(IDC_EDIT_TAB_INTERVAL)->EnableWindow(FALSE);

	dlg_setting_info->GetDlgItem(IDC_EDIT_UPPER_ROI_MIN)->EnableWindow(FALSE);
	dlg_setting_info->GetDlgItem(IDC_EDIT_UPPER_ROI_MAX)->EnableWindow(FALSE);
	dlg_setting_info->GetDlgItem(IDC_EDIT_SIDE_ROI_MIN)->EnableWindow(FALSE);
	dlg_setting_info->GetDlgItem(IDC_EDIT_SIDE_ROI_MAX)->EnableWindow(FALSE);
	dlg_setting_info->GetDlgItem(IDC_EDIT_EDGE_ROI_MIN)->EnableWindow(FALSE);
	dlg_setting_info->GetDlgItem(IDC_EDIT_EDGE_ROI_MAX)->EnableWindow(FALSE);

	// param
	dlg_setting_param->GetDlgItem(IDC_EDIT_PREALIGN_MATCHING)->EnableWindow(FALSE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_TABALIGN_MATCHING)->EnableWindow(FALSE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_PREALIGN_RANGE)->EnableWindow(FALSE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_OFFSET)->EnableWindow(FALSE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_UPPER_ALIGN_OFFSET)->EnableWindow(FALSE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_SIDE_ALIGN_OFFSET)->EnableWindow(FALSE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_WIDTH)->EnableWindow(FALSE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_HEIGHT)->EnableWindow(FALSE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_SPACE)->EnableWindow(FALSE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_WIDTH_RANGE)->EnableWindow(FALSE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_HEIGHT_RANGE)->EnableWindow(FALSE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_MA_X_RANGE)->EnableWindow(FALSE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_MA_Y)->EnableWindow(FALSE);
	dlg_setting_param->GetDlgItem(IDC_EDIT_MA_Y_RANGE)->EnableWindow(FALSE);
	
	// PROCESS
	dlg_setting_process->GetDlgItem(IDC_BTN_PREALIGN_PASS)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TABALIGN_PASS)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_PASS)->EnableWindow(FALSE);

	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_1)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_2)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_3)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_4)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_5)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_6)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_7)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_8)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_9)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_10)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_11)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_12)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_13)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_14)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_15)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_16)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_17)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_18)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_19)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_20)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_21)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_22)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_23)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_24)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_25)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_26)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_27)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_28)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_29)->EnableWindow(FALSE);
	dlg_setting_process->GetDlgItem(IDC_BTN_TAB_30)->EnableWindow(FALSE);


	// INSPECT
	dlg_setting_inspect->GetDlgItem(IDC_CHK_MISSALIGN_X)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_CHK_MISSALIGN_Y)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_CHK_OPEN)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_CHK_SHORT)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_CHK_WIDTH)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_CHK_HEIGHT)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_CHK_BOTH)->EnableWindow(FALSE);
	
	dlg_setting_inspect->GetDlgItem(IDC_COLOR_MISSALIGN_X)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_COLOR_MISSALIGN_Y)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_COLOR_OPEN)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_COLOR_SHORT)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_COLOR_WIDTH)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_COLOR_HEIGHT)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_COLOR_BOTH)->EnableWindow(FALSE);

	dlg_setting_inspect->GetDlgItem(IDC_CHK_UPPER_MARK_1)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_CHK_UPPER_MARK_2)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_CHK_SIDE_MARK_1)->EnableWindow(FALSE);
	dlg_setting_inspect->GetDlgItem(IDC_CHK_SIDE_MARK_2)->EnableWindow(FALSE);

	// hidden

	dlg_setting_hidden->GetDlgItem(IDC_EDIT_BINARY_UPPER)->EnableWindow(FALSE);
	dlg_setting_hidden->GetDlgItem(IDC_EDIT_BINARY_SIDE)->EnableWindow(FALSE);
	dlg_setting_hidden->GetDlgItem(IDC_EDIT_BINARY_EDGE)->EnableWindow(FALSE);

	dlg_setting_hidden->GetDlgItem(IDC_EDIT_MORPHOLOGY_OPEN)->EnableWindow(FALSE);
	dlg_setting_hidden->GetDlgItem(IDC_EDIT_MORPHOLOGY_CLOSE)->EnableWindow(FALSE);
	dlg_setting_hidden->GetDlgItem(IDC_EDIT_UPPER_CONTOUR)->EnableWindow(FALSE);
	dlg_setting_hidden->GetDlgItem(IDC_EDIT_SIDE_CONTOUR)->EnableWindow(FALSE);

	dlg_setting_hidden->GetDlgItem(IDC_EDIT_GANTRY_LIMIT_MIN)->EnableWindow(FALSE);
	dlg_setting_hidden->GetDlgItem(IDC_EDIT_GANTRY_LIMIT_MAX)->EnableWindow(FALSE);
	dlg_setting_hidden->GetDlgItem(IDC_EDIT_AF_LIMIT)->EnableWindow(FALSE);

	// 
	Init_Parameter();
}


void DIALOG_SETTING::Init_Parameter()
{
	// parameter load (registry)
	CREVIEWAREADlg *pDlg = (CREVIEWAREADlg*)AfxGetMainWnd();

	CString str_registry;

	GetDlgItem(IDC_STATIC_LOAD_RECIPE)->GetWindowTextW(str_registry);

	recipe_name = str_registry;

	pDlg->GetDlgItem(IDC_STATIC_RECIPE)->SetWindowTextW(recipe_name);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Stage_Main_X_Ready_pos"));
	dlg_setting_stage->m_edit_stage_main_x_ready_pos.SetWindowTextW(str_registry);
	pDlg->dlg_auto->stage_main_x_ready_pos = _wtof(str_registry);
	pDlg->dlg_auto->m_edit_stage_main_x_ready_pos.SetWindowTextW(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Stage_Main_X_Process_pos"));
	dlg_setting_stage->m_edit_stage_main_x_process_pos.SetWindowTextW(str_registry);
	pDlg->dlg_auto->stage_main_x_process_pos = _wtof(str_registry);
	pDlg->dlg_auto->m_edit_stage_main_x_process_pos.SetWindowTextW(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Stage_Main_X_Limit_min"));
	dlg_setting_stage->m_edit_stage_main_x_limit_min.SetWindowTextW(str_registry);
	pDlg->dlg_auto->stage_main_x_limit_min = _wtof(str_registry);
	pDlg->dlg_auto->m_edit_stage_main_x_limit_min.SetWindowTextW(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Stage_Main_X_Limit_max"));
	dlg_setting_stage->m_edit_stage_main_x_limit_max.SetWindowTextW(str_registry);
	pDlg->dlg_auto->stage_main_x_limit_max = _wtof(str_registry);
	pDlg->dlg_auto->m_edit_stage_main_x_limit_max.SetWindowTextW(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Stage_Main_X_Manual_speed"));
	dlg_setting_stage->m_edit_stage_main_x_manual_speed.SetWindowTextW(str_registry);
	pDlg->dlg_auto->stage_main_x_manual_speed = _wtof(str_registry);
	pDlg->dlg_auto->m_edit_stage_main_x_manual_speed.SetWindowTextW(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Stage_Main_X_Process_speed"));
	dlg_setting_stage->m_edit_stage_main_x_process_speed.SetWindowTextW(str_registry);
	pDlg->dlg_auto->stage_main_x_process_speed = _wtof(str_registry);
	pDlg->dlg_auto->m_edit_stage_main_x_process_speed.SetWindowTextW(str_registry);


	// Stage Y
	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Stage_Main_Y_Ready_pos"));
	dlg_setting_stage->m_edit_stage_main_y_ready_pos.SetWindowTextW(str_registry);
	pDlg->dlg_auto->stage_main_y_ready_pos = _wtof(str_registry);
	pDlg->dlg_auto->m_edit_stage_main_y_ready_pos.SetWindowTextW(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Stage_Main_Y_Process_pos"));
	dlg_setting_stage->m_edit_stage_main_y_process_pos.SetWindowTextW(str_registry);
	pDlg->dlg_auto->stage_main_y_process_pos = _wtof(str_registry);
	pDlg->dlg_auto->m_edit_stage_main_y_process_pos.SetWindowTextW(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Stage_Main_Y_Limit_min"));
	dlg_setting_stage->m_edit_stage_main_y_limit_min.SetWindowTextW(str_registry);
	pDlg->dlg_auto->stage_main_y_limit_min = _wtof(str_registry);
	pDlg->dlg_auto->m_edit_stage_main_y_limit_min.SetWindowTextW(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Stage_Main_Y_Limit_max"));
	dlg_setting_stage->m_edit_stage_main_y_limit_max.SetWindowTextW(str_registry);
	pDlg->dlg_auto->stage_main_y_limit_max = _wtof(str_registry);
	pDlg->dlg_auto->m_edit_stage_main_y_limit_max.SetWindowTextW(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Stage_Main_Y_Manual_speed"));
	dlg_setting_stage->m_edit_stage_main_y_manual_speed.SetWindowTextW(str_registry);
	pDlg->dlg_auto->stage_main_y_manual_speed = _wtof(str_registry);
	pDlg->dlg_auto->m_edit_stage_main_y_manual_speed.SetWindowTextW(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Stage_Main_Y_Process_speed"));
	dlg_setting_stage->m_edit_stage_main_y_process_speed.SetWindowTextW(str_registry);
	pDlg->dlg_auto->stage_main_y_process_speed = _wtof(str_registry);
	pDlg->dlg_auto->m_edit_stage_main_y_process_speed.SetWindowTextW(str_registry);

	// Sub_X
	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Stage_Sub_X_Ready_pos"));
	dlg_setting_stage->m_edit_stage_sub_x_ready_pos.SetWindowTextW(str_registry);
	pDlg->dlg_auto->stage_sub_x_ready_pos = _wtof(str_registry);
	pDlg->dlg_auto->m_edit_stage_sub_x_ready_pos.SetWindowTextW(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Stage_Sub_X_Process_pos"));
	dlg_setting_stage->m_edit_stage_sub_x_process_pos.SetWindowTextW(str_registry);
	pDlg->dlg_auto->stage_sub_x_process_pos = _wtof(str_registry);
	pDlg->dlg_auto->m_edit_stage_sub_x_process_pos.SetWindowTextW(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Stage_Sub_X_Limit_min"));
	dlg_setting_stage->m_edit_stage_sub_x_limit_min.SetWindowTextW(str_registry);
	pDlg->dlg_auto->stage_sub_x_limit_min = _wtof(str_registry);
	pDlg->dlg_auto->m_edit_stage_sub_x_limit_min.SetWindowTextW(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Stage_Sub_X_Limit_max"));
	dlg_setting_stage->m_edit_stage_sub_x_limit_max.SetWindowTextW(str_registry);
	pDlg->dlg_auto->stage_sub_x_limit_max = _wtof(str_registry);
	pDlg->dlg_auto->m_edit_stage_sub_x_limit_max.SetWindowTextW(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Stage_Sub_X_Align_offset"));
	dlg_setting_stage->m_edit_stage_sub_x_align_offset.SetWindowTextW(str_registry);
	pDlg->dlg_auto->stage_sub_x_align_offset = _wtof(str_registry);
	pDlg->dlg_auto->m_edit_stage_sub_x_align_offset.SetWindowTextW(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Stage_Sub_X_Manual_speed"));
	dlg_setting_stage->m_edit_stage_sub_x_manual_speed.SetWindowTextW(str_registry);
	pDlg->dlg_auto->stage_sub_x_manual_speed = _wtof(str_registry);
	pDlg->dlg_auto->m_edit_stage_sub_x_manual_speed.SetWindowTextW(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Stage_Sub_X_Process_speed"));
	dlg_setting_stage->m_edit_stage_sub_x_process_speed.SetWindowTextW(str_registry);
	pDlg->dlg_auto->stage_sub_x_process_speed = _wtof(str_registry);
	pDlg->dlg_auto->m_edit_stage_sub_x_process_speed.SetWindowTextW(str_registry);

	// information
	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Tab_Count"));
	dlg_setting_info->m_edit_tab_count.SetWindowTextW(str_registry);
	pDlg->dlg_auto->tab_count = _wtof(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Tab_Point"));
	dlg_setting_info->m_edit_tab_point.SetWindowTextW(str_registry);
	pDlg->dlg_auto->tab_point = _wtof(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Tab_Dist"));
	dlg_setting_info->m_edit_tab_dist.SetWindowTextW(str_registry);
	pDlg->dlg_auto->tab_dist = _wtof(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Tab_Interval"));
	dlg_setting_info->m_edit_tab_interval.SetWindowTextW(str_registry);
	pDlg->dlg_auto->tab_interval = _wtof(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Upper_Roi_min"));
	dlg_setting_info->m_edit_upper_roi_min.SetWindowTextW(str_registry);
	pDlg->dlg_auto->upper_roi_min = _wtof(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Upper_Roi_max"));
	dlg_setting_info->m_edit_upper_roi_max.SetWindowTextW(str_registry);
	pDlg->dlg_auto->upper_roi_max = _wtof(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Side_Roi_min"));
	dlg_setting_info->m_edit_side_roi_min.SetWindowTextW(str_registry);
	pDlg->dlg_auto->side_roi_min = _wtof(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Side_Roi_max"));
	dlg_setting_info->m_edit_side_roi_max.SetWindowTextW(str_registry);
	pDlg->dlg_auto->side_roi_max = _wtof(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Edge_Roi_min"));
	dlg_setting_info->m_edit_edge_roi_min.SetWindowTextW(str_registry);
	pDlg->dlg_auto->edge_roi_min = _wtof(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Edge_Roi_max"));
	dlg_setting_info->m_edit_edge_roi_max.SetWindowTextW(str_registry);
	pDlg->dlg_auto->edge_roi_max = _wtof(str_registry);


	// parameter
	// Inspection
	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("PreAlign_Matching"));
	dlg_setting_param->m_edit_prealign_matching.SetWindowTextW(str_registry);
	pDlg->dlg_auto->prealign_matching = _wtof(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("TabAlign_Matching"));
	dlg_setting_param->m_edit_tabalign_matching.SetWindowTextW(str_registry);
	pDlg->dlg_auto->tabalign_matching = _wtof(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("PreAlign_Range"));
	dlg_setting_param->m_edit_prealign_range.SetWindowTextW(str_registry);
	pDlg->dlg_auto->prealign_range = _wtof(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Offset"));
	dlg_setting_param->m_edit_offset.SetWindowTextW(str_registry);
	pDlg->dlg_auto->offset = _wtof(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Upper_Align_Offset"));
	dlg_setting_param->m_edit_upper_align_offset.SetWindowTextW(str_registry);
	pDlg->dlg_auto->upper_align_offset = _wtof(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Side_Align_Offset"));
	dlg_setting_param->m_edit_side_align_offset.SetWindowTextW(str_registry);
	pDlg->dlg_auto->side_align_offset = _wtof(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Width"));
	dlg_setting_param->m_edit_width.SetWindowTextW(str_registry);
	pDlg->dlg_auto->width = _wtof(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Height"));
	dlg_setting_param->m_edit_height.SetWindowTextW(str_registry);
	pDlg->dlg_auto->height = _wtof(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Space"));
	dlg_setting_param->m_edit_space.SetWindowTextW(str_registry);
	pDlg->dlg_auto->space = _wtof(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Width_Range"));
	dlg_setting_param->m_edit_width_range.SetWindowTextW(str_registry);
	pDlg->dlg_auto->width_range = _wtof(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Height_Range"));
	dlg_setting_param->m_edit_height_range.SetWindowTextW(str_registry);
	pDlg->dlg_auto->height_range = _wtof(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("MissAlign_X_Range"));
	dlg_setting_param->m_edit_ma_x_range.SetWindowTextW(str_registry);
	pDlg->dlg_auto->ma_x_range = _wtof(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("MissAlign_Y"));
	dlg_setting_param->m_edit_ma_y.SetWindowTextW(str_registry);
	pDlg->dlg_auto->ma_y_value = _wtof(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("MissAlign_Y_Range"));
	dlg_setting_param->m_edit_ma_y_range.SetWindowTextW(str_registry);
	pDlg->dlg_auto->ma_y_range = _wtof(str_registry);

	// hidden
	// ENGINEER MODE
	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Binary_Upper"));
	dlg_setting_hidden->m_edit_binary_upper.SetWindowTextW(str_registry);
	pDlg->dlg_auto->binary_upper = _wtof(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Binary_Side"));
	dlg_setting_hidden->m_edit_binary_side.SetWindowTextW(str_registry);
	pDlg->dlg_auto->binary_side = _wtof(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Binary_Edge"));
	dlg_setting_hidden->m_edit_binary_edge.SetWindowTextW(str_registry);
	pDlg->dlg_auto->binary_edge = _wtof(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Morphology_Open"));
	dlg_setting_hidden->m_edit_morphology_open.SetWindowTextW(str_registry);
	pDlg->dlg_auto->morphology_open = _wtof(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Morphology_Close"));
	dlg_setting_hidden->m_edit_morphology_close.SetWindowTextW(str_registry);
	pDlg->dlg_auto->morphology_close = _wtof(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Upper_Contour"));
	dlg_setting_hidden->m_edit_upper_contour.SetWindowTextW(str_registry);
	pDlg->dlg_auto->upper_contour = _wtof(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Side_Contour"));
	dlg_setting_hidden->m_edit_side_contour.SetWindowTextW(str_registry);
	pDlg->dlg_auto->side_contour = _wtof(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Gantry_Limit_min"));
	dlg_setting_hidden->m_edit_gantry_limit_min.SetWindowTextW(str_registry);
	pDlg->dlg_auto->gantry_limit_min = _wtof(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("Gantry_Limit_max"));
	dlg_setting_hidden->m_edit_gantry_limit_max.SetWindowTextW(str_registry);
	pDlg->dlg_auto->gantry_limit_max = _wtof(str_registry);

	str_registry = AfxGetApp()->GetProfileStringW(recipe_name, _T("AF_Limit"));
	dlg_setting_hidden->m_edit_af_limit.SetWindowTextW(str_registry);
	pDlg->dlg_auto->af_limit = _wtof(str_registry);

	//
	pDlg->dlg_auto->check_ng_ma_x = dlg_setting_inspect->check_ng_ma_x;
	pDlg->dlg_auto->check_ng_ma_y = dlg_setting_inspect->check_ng_ma_y;
	pDlg->dlg_auto->check_ng_open = dlg_setting_inspect->check_ng_open;
	pDlg->dlg_auto->check_ng_short = dlg_setting_inspect->check_ng_short;
	pDlg->dlg_auto->check_ng_width = dlg_setting_inspect->check_ng_width;
	pDlg->dlg_auto->check_ng_height = dlg_setting_inspect->check_ng_height;
	pDlg->dlg_auto->check_ng_both = dlg_setting_inspect->check_ng_both;
	pDlg->dlg_auto->check_ng_upper_mark_1 = dlg_setting_inspect->check_ng_upper_mark_1;
	pDlg->dlg_auto->check_ng_upper_mark_2 = dlg_setting_inspect->check_ng_upper_mark_2;
	pDlg->dlg_auto->check_ng_side_mark_1 = dlg_setting_inspect->check_ng_side_mark_1;
	pDlg->dlg_auto->check_ng_side_mark_2 = dlg_setting_inspect->check_ng_side_mark_2;

	pDlg->dlg_auto->ma_x_r = dlg_setting_inspect->ma_x_r;
	pDlg->dlg_auto->ma_x_g = dlg_setting_inspect->ma_x_g;
	pDlg->dlg_auto->ma_x_b = dlg_setting_inspect->ma_x_b;

	pDlg->dlg_auto->ma_y_r = dlg_setting_inspect->ma_y_r;
	pDlg->dlg_auto->ma_y_g = dlg_setting_inspect->ma_y_g;
	pDlg->dlg_auto->ma_y_b = dlg_setting_inspect->ma_y_b;

	pDlg->dlg_auto->open_r = dlg_setting_inspect->open_r;
	pDlg->dlg_auto->open_g = dlg_setting_inspect->open_g;
	pDlg->dlg_auto->open_b = dlg_setting_inspect->open_b;

	pDlg->dlg_auto->short_r = dlg_setting_inspect->short_r;
	pDlg->dlg_auto->short_g = dlg_setting_inspect->short_g;
	pDlg->dlg_auto->short_b = dlg_setting_inspect->short_b;

	pDlg->dlg_auto->width_r = dlg_setting_inspect->width_r;
	pDlg->dlg_auto->width_g = dlg_setting_inspect->width_g;
	pDlg->dlg_auto->width_b = dlg_setting_inspect->width_b;

	pDlg->dlg_auto->height_r = dlg_setting_inspect->height_r;
	pDlg->dlg_auto->height_g = dlg_setting_inspect->height_g;
	pDlg->dlg_auto->height_b = dlg_setting_inspect->height_b;

	pDlg->dlg_auto->both_r = dlg_setting_inspect->both_r;
	pDlg->dlg_auto->both_g = dlg_setting_inspect->both_g;
	pDlg->dlg_auto->both_b = dlg_setting_inspect->both_b;
}

void DIALOG_SETTING::OnSelchangeTabSetting(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int Tab = m_tab_setting.GetCurSel();

	if (Tab == 0)
	{
		dlg_setting_stage->ShowWindow(SW_SHOW);
		dlg_setting_info->ShowWindow(SW_HIDE);
		dlg_setting_param->ShowWindow(SW_HIDE);
		dlg_setting_process->ShowWindow(SW_HIDE);
		dlg_setting_inspect->ShowWindow(SW_HIDE);
		dlg_setting_hidden->ShowWindow(SW_HIDE);
	}

	else if (Tab == 1)
	{
		dlg_setting_stage->ShowWindow(SW_HIDE);
		dlg_setting_info->ShowWindow(SW_SHOW);
		dlg_setting_param->ShowWindow(SW_HIDE);
		dlg_setting_process->ShowWindow(SW_HIDE);
		dlg_setting_inspect->ShowWindow(SW_HIDE);
		dlg_setting_hidden->ShowWindow(SW_HIDE);
	}

	else if (Tab == 2)
	{
		dlg_setting_stage->ShowWindow(SW_HIDE);
		dlg_setting_info->ShowWindow(SW_HIDE);
		dlg_setting_param->ShowWindow(SW_SHOW);
		dlg_setting_process->ShowWindow(SW_HIDE);
		dlg_setting_inspect->ShowWindow(SW_HIDE);
		dlg_setting_hidden->ShowWindow(SW_HIDE);
	}

	else if (Tab == 3)
	{
		dlg_setting_stage->ShowWindow(SW_HIDE);
		dlg_setting_info->ShowWindow(SW_HIDE);
		dlg_setting_param->ShowWindow(SW_HIDE);
		dlg_setting_process->ShowWindow(SW_SHOW);
		dlg_setting_inspect->ShowWindow(SW_HIDE);
		dlg_setting_hidden->ShowWindow(SW_HIDE);
	}

	else if (Tab == 4)
	{
		dlg_setting_stage->ShowWindow(SW_HIDE);
		dlg_setting_info->ShowWindow(SW_HIDE);
		dlg_setting_param->ShowWindow(SW_HIDE);
		dlg_setting_process->ShowWindow(SW_HIDE);
		dlg_setting_inspect->ShowWindow(SW_SHOW);
		dlg_setting_hidden->ShowWindow(SW_HIDE);
	}

	else if (Tab == 5)
	{
		dlg_setting_stage->ShowWindow(SW_HIDE);
		dlg_setting_info->ShowWindow(SW_HIDE);
		dlg_setting_param->ShowWindow(SW_HIDE);
		dlg_setting_process->ShowWindow(SW_HIDE);
		dlg_setting_inspect->ShowWindow(SW_HIDE);
		dlg_setting_hidden->ShowWindow(SW_SHOW);
	}
	*pResult = 0;
}


void DIALOG_SETTING::OnBnClickedBtnSave()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CREVIEWAREADlg *pDlg = (CREVIEWAREADlg*)AfxGetMainWnd();

	CString m_strPath;
	CStdioFile file;

	// CFile 파일;
	CFileException ex;
	CFileDialog dlg(FALSE, _T("*.txt"), NULL, OFN_FILEMUSTEXIST | OFN_OVERWRITEPROMPT, _T("TXT Files(*.txt)|*.txt|"), NULL);

	if (dlg.DoModal() == IDOK)
	{
		m_strPath = dlg.GetPathName();
		file.Open(m_strPath, CFile::modeCreate | CFile::modeReadWrite, &ex);

		// 에디트 박스에 있습니다. 

		UpdateData(TRUE);
		file.Close();

		CString str_recipe;
		CString str_edit;

		m_strPath = dlg.GetPathName();
		int value = m_strPath.GetLength();

		int i = m_strPath.ReverseFind('\\');//실행 파일 이름을 지우기 위해서 왼쪽에 있는 '/'를 찾는다.
		str_recipe = m_strPath.Mid(i + 1, value);//뒤에 있는 현재 실행 파일 이름을 지운다.

		i = str_recipe.ReverseFind('.');
		str_recipe = str_recipe.Left(i);

		AfxGetApp()->WriteProfileStringW(_T("RECIPE"), _T("Recipe_name"), str_recipe);

		GetDlgItem(IDC_STATIC_LOAD_RECIPE)->SetWindowTextW(str_recipe);
		pDlg->GetDlgItem(IDC_STATIC_RECIPE)->SetWindowTextW(str_recipe);

		//////////////////////////////////////////////////////////////////////////////////////////////////
		// Stage Recipe
		// Stage X
		dlg_setting_stage->m_edit_stage_main_x_ready_pos.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Stage_Main_X_Ready_pos"), str_edit);

		dlg_setting_stage->m_edit_stage_main_x_process_pos.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Stage_Main_X_Process_pos"), str_edit);

		dlg_setting_stage->m_edit_stage_main_x_limit_min.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Stage_Main_X_Limit_min"), str_edit);

		dlg_setting_stage->m_edit_stage_main_x_limit_max.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Stage_Main_X_Limit_max"), str_edit);

		dlg_setting_stage->m_edit_stage_main_x_manual_speed.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Stage_Main_X_Manual_speed"), str_edit);

		dlg_setting_stage->m_edit_stage_main_x_process_speed.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Stage_Main_X_Process_speed"), str_edit);

		// Stage Y
		dlg_setting_stage->m_edit_stage_main_y_ready_pos.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Stage_Main_Y_Ready_pos"), str_edit);

		dlg_setting_stage->m_edit_stage_main_y_process_pos.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Stage_Main_Y_Process_pos"), str_edit);

		dlg_setting_stage->m_edit_stage_main_y_limit_min.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Stage_Main_Y_Limit_min"), str_edit);

		dlg_setting_stage->m_edit_stage_main_y_limit_max.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Stage_Main_Y_Limit_max"), str_edit);

		dlg_setting_stage->m_edit_stage_main_y_manual_speed.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Stage_Main_Y_Manual_speed"), str_edit);

		dlg_setting_stage->m_edit_stage_main_y_process_speed.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Stage_Main_Y_Process_speed"), str_edit);

		// Sub_X
		dlg_setting_stage->m_edit_stage_sub_x_ready_pos.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Stage_Sub_X_Ready_pos"), str_edit);

		dlg_setting_stage->m_edit_stage_sub_x_process_pos.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Stage_Sub_X_Process_pos"), str_edit);

		dlg_setting_stage->m_edit_stage_sub_x_limit_min.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Stage_Sub_X_Limit_min"), str_edit);

		dlg_setting_stage->m_edit_stage_sub_x_limit_max.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Stage_Sub_X_Limit_max"), str_edit);

		dlg_setting_stage->m_edit_stage_sub_x_align_offset.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Stage_Sub_X_Align_offset"), str_edit);

		dlg_setting_stage->m_edit_stage_sub_x_manual_speed.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Stage_Sub_X_Manual_speed"), str_edit);

		dlg_setting_stage->m_edit_stage_sub_x_process_speed.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Stage_Sub_X_Process_speed"), str_edit);

		//////////////////////////////////////////////////////////////////////////////////////////////////

		// Information Recipe
		dlg_setting_info->m_edit_tab_count.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Tab_Count"), str_edit);

		dlg_setting_info->m_edit_tab_point.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Tab_Point"), str_edit);

		dlg_setting_info->m_edit_tab_dist.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Tab_Dist"), str_edit);

		dlg_setting_info->m_edit_tab_interval.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Tab_Interval"), str_edit);

		dlg_setting_info->m_edit_upper_roi_min.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Upper_Roi_min"), str_edit);

		dlg_setting_info->m_edit_upper_roi_max.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Upper_Roi_max"), str_edit);

		dlg_setting_info->m_edit_side_roi_min.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Side_Roi_min"), str_edit);

		dlg_setting_info->m_edit_side_roi_max.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Side_Roi_max"), str_edit);

		dlg_setting_info->m_edit_edge_roi_min.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Edge_Roi_min"), str_edit);

		dlg_setting_info->m_edit_edge_roi_max.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Edge_Roi_max"), str_edit);

		//////////////////////////////////////////////////////////////////////////////////////////////////

		// Pameter Recipe
		dlg_setting_param->m_edit_prealign_matching.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("PreAlign_Matching"), str_edit);

		dlg_setting_param->m_edit_tabalign_matching.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("TabAlign_Matching"), str_edit);

		dlg_setting_param->m_edit_prealign_range.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("PreAlign_Range"), str_edit);

		dlg_setting_param->m_edit_offset.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Offset"), str_edit);

		dlg_setting_param->m_edit_upper_align_offset.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Upper_Align_Offset"), str_edit);

		dlg_setting_param->m_edit_side_align_offset.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Side_Align_Offset"), str_edit);

		dlg_setting_param->m_edit_width.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Width"), str_edit);

		dlg_setting_param->m_edit_height.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Height"), str_edit);

		dlg_setting_param->m_edit_space.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Space"), str_edit);

		dlg_setting_param->m_edit_width_range.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Width_Range"), str_edit);

		dlg_setting_param->m_edit_height_range.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Height_Range"), str_edit);

		dlg_setting_param->m_edit_ma_x_range.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("MissAlign_X_Range"), str_edit);

		dlg_setting_param->m_edit_ma_y.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("MissAlign_Y"), str_edit);

		dlg_setting_param->m_edit_ma_y_range.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("MissAlign_Y_Range"), str_edit);

		//////////////////////////////////////////////////////////////////////////////////////////////////


		// ENGINEER MODE
		dlg_setting_hidden->m_edit_binary_upper.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Binary_Upper"), str_edit);

		dlg_setting_hidden->m_edit_binary_side.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Binary_Side"), str_edit);

		dlg_setting_hidden->m_edit_binary_edge.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Binary_Edge"), str_edit);

		dlg_setting_hidden->m_edit_morphology_open.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Morphology_Open"), str_edit);

		dlg_setting_hidden->m_edit_morphology_close.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Morphology_Close"), str_edit);

		dlg_setting_hidden->m_edit_upper_contour.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Upper_Contour"), str_edit);

		dlg_setting_hidden->m_edit_side_contour.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Side_Contour"), str_edit);

		dlg_setting_hidden->m_edit_gantry_limit_min.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Gantry_Limit_min"), str_edit);

		dlg_setting_hidden->m_edit_gantry_limit_max.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("Gantry_Limit_max"), str_edit);

		dlg_setting_hidden->m_edit_af_limit.GetWindowTextW(str_edit);
		AfxGetApp()->WriteProfileStringW(str_recipe, _T("AF_Limit"), str_edit);
	}

}

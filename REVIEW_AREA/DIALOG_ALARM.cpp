// DIALOG_ALARM.cpp: 구현 파일
//

#include "stdafx.h"
#include "REVIEW_AREA.h"
#include "DIALOG_ALARM.h"
#include "afxdialogex.h"


// DIALOG_ALARM 대화 상자

IMPLEMENT_DYNAMIC(DIALOG_ALARM, CDialogEx)

DIALOG_ALARM::DIALOG_ALARM(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ALARM, pParent)
{

}

DIALOG_ALARM::~DIALOG_ALARM()
{
}

void DIALOG_ALARM::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_ALARM, m_list_alarm);
}


BEGIN_MESSAGE_MAP(DIALOG_ALARM, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_RESET, &DIALOG_ALARM::OnBnClickedBtnReset)
END_MESSAGE_MAP()


// DIALOG_ALARM 메시지 처리기


BOOL DIALOG_ALARM::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	GetDlgItem(IDC_LIST_ALARM)->MoveWindow(10, 10, 1400, 900);

	m_list_alarm.SetExtendedStyle(LVS_EX_GRIDLINES);

	m_list_alarm.InsertColumn(1, TEXT("No."), LVCFMT_CENTER, 100);
	m_list_alarm.InsertColumn(2, TEXT("TIME"), LVCFMT_CENTER, 200);
	m_list_alarm.InsertColumn(3, TEXT("ALARM CODE"), LVCFMT_CENTER, 200);
	m_list_alarm.InsertColumn(4, TEXT("ALARM MESSAGE"), LVCFMT_CENTER, 1000);

	GetDlgItem(IDC_BTN_RESET)->MoveWindow(1330, 920, 80, 30);

	alarm_count = 0;
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


BOOL DIALOG_ALARM::PreTranslateMessage(MSG* pMsg)
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


void DIALOG_ALARM::DisplayAlarm(int alarmCase)
{
	//

	alarm_time = CTime::GetCurrentTime();
	str_alarm_time.Format(_T("%04d%02d%02d_%02d%02d%02d"), alarm_time.GetYear(), alarm_time.GetMonth(), alarm_time.GetDay(), alarm_time.GetHour(),
		alarm_time.GetMinute(), alarm_time.GetSecond());

	CString str_num;

	str_num.Format(_T("%d"), alarm_count + 1);

	// EMO
	if (alarmCase == 1)
	{
		m_list_alarm.InsertItem(alarm_count, str_num);
		m_list_alarm.SetItemText(alarm_count, 1, str_alarm_time);
		m_list_alarm.SetItemText(alarm_count, 2, _T("PEE0001"));
		m_list_alarm.SetItemText(alarm_count, 3, _T("PROCESS_EMO "));

		alarm_count++;
	}

	// PREALIGN OFFSET
	else if (alarmCase == 2)
	{
		m_list_alarm.InsertItem(alarm_count, str_num);
		m_list_alarm.SetItemText(alarm_count, 1, str_alarm_time);
		m_list_alarm.SetItemText(alarm_count, 2, _T("PEP0001"));
		m_list_alarm.SetItemText(alarm_count, 3, _T("PREALIGN_OFFSET"));

		alarm_count++;
	}

	// PREALIGN LEFT MISS MATCHING
	else if (alarmCase == 3)
	{
		m_list_alarm.InsertItem(alarm_count, str_num);
		m_list_alarm.SetItemText(alarm_count, 1, str_alarm_time);
		m_list_alarm.SetItemText(alarm_count, 2, _T("PEP0002"));
		m_list_alarm.SetItemText(alarm_count, 3, _T("PREALIGN[LEFT] MISS MATCHING"));

		alarm_count++;
	}

	// PREALIGN RIGHT MISS MATCHING
	else if (alarmCase == 4)
	{
		m_list_alarm.InsertItem(alarm_count, str_num);
		m_list_alarm.SetItemText(alarm_count, 1, str_alarm_time);
		m_list_alarm.SetItemText(alarm_count, 2, _T("PEP0003"));
		m_list_alarm.SetItemText(alarm_count, 3, _T("PREALIGN[RIGHT] MISS MATCHING"));

		alarm_count++;
	}

	// TAB ALIGN MISS MATCHING
	else if (alarmCase == 5)
	{
		m_list_alarm.InsertItem(alarm_count, str_num);
		m_list_alarm.SetItemText(alarm_count, 1, str_alarm_time);
		m_list_alarm.SetItemText(alarm_count, 2, _T("PET0001"));
		m_list_alarm.SetItemText(alarm_count, 3, _T("TABALIGN MISS MATCHING"));

		alarm_count++;
	}

	// STAGE_X_MIN
	else if (alarmCase == 6)
	{
		m_list_alarm.InsertItem(alarm_count, str_num);
		m_list_alarm.SetItemText(alarm_count, 1, str_alarm_time);
		m_list_alarm.SetItemText(alarm_count, 2, _T("SMX0001"));
		m_list_alarm.SetItemText(alarm_count, 3, _T("STAGE_MAIN_X MIN LIMIT"));

		alarm_count++;
	}

	// STAGE_X_MAX
	else if (alarmCase == 7)
	{
		m_list_alarm.InsertItem(alarm_count, str_num);
		m_list_alarm.SetItemText(alarm_count, 1, str_alarm_time);
		m_list_alarm.SetItemText(alarm_count, 2, _T("SMX0002"));
		m_list_alarm.SetItemText(alarm_count, 3, _T("STAGE_MAIN_X MAX LIMIT"));

		alarm_count++;
	}

	// STAGE_Y_MIN
	else if (alarmCase == 8)
	{
		m_list_alarm.InsertItem(alarm_count, str_num);
		m_list_alarm.SetItemText(alarm_count, 1, str_alarm_time);
		m_list_alarm.SetItemText(alarm_count, 2, _T("SMY0001"));
		m_list_alarm.SetItemText(alarm_count, 3, _T("STAGE_MAIN_Y MIN LIMIT"));

		alarm_count++;
	}

	// STAGE_Y_MAX
	else if (alarmCase == 9)
	{
		m_list_alarm.InsertItem(alarm_count, str_num);
		m_list_alarm.SetItemText(alarm_count, 1, str_alarm_time);
		m_list_alarm.SetItemText(alarm_count, 2, _T("SMY0002"));
		m_list_alarm.SetItemText(alarm_count, 3, _T("STAGE_MAIN_Y MAX LIMIT"));

		alarm_count++;
	}

	// SUB_X_MIN
	else if (alarmCase == 10)
	{
		m_list_alarm.InsertItem(alarm_count, str_num);
		m_list_alarm.SetItemText(alarm_count, 1, str_alarm_time);
		m_list_alarm.SetItemText(alarm_count, 2, _T("SSX0001"));
		m_list_alarm.SetItemText(alarm_count, 3, _T("STAGE_SUB_X MIN LIMIT"));

		alarm_count++;
	}

	// SUB_X_MAX
	else if (alarmCase == 11)
	{
		m_list_alarm.InsertItem(alarm_count, str_num);
		m_list_alarm.SetItemText(alarm_count, 1, str_alarm_time);
		m_list_alarm.SetItemText(alarm_count, 2, _T("SSX0002"));
		m_list_alarm.SetItemText(alarm_count, 3, _T("STAGE_SUB_X MAX LIMIT"));

		alarm_count++;
	}

	else if (alarmCase == 12)
	{
		m_list_alarm.InsertItem(alarm_count, str_num);
		m_list_alarm.SetItemText(alarm_count, 1, str_alarm_time);
		m_list_alarm.SetItemText(alarm_count, 2, _T("SEMX001"));
		m_list_alarm.SetItemText(alarm_count, 3, _T("STAGE_MAIN_X NOT ENABLE"));

		alarm_count++;
	}

	else if (alarmCase == 13)
	{
		m_list_alarm.InsertItem(alarm_count, str_num);
		m_list_alarm.SetItemText(alarm_count, 1, str_alarm_time);
		m_list_alarm.SetItemText(alarm_count, 2, _T("SEMY001"));
		m_list_alarm.SetItemText(alarm_count, 3, _T("STAGE_MAIN_Y NOT ENABLE"));

		alarm_count++;
	}

	else if (alarmCase == 14)
	{
		m_list_alarm.InsertItem(alarm_count, str_num);
		m_list_alarm.SetItemText(alarm_count, 1, str_alarm_time);
		m_list_alarm.SetItemText(alarm_count, 2, _T("SESX001"));
		m_list_alarm.SetItemText(alarm_count, 3, _T("STAGE_SUB_X NOT ENABLE"));

		alarm_count++;
	}
}

void DIALOG_ALARM::OnBnClickedBtnReset()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	alarm_count = 0;
	m_list_alarm.DeleteAllItems();
}

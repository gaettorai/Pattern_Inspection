#pragma once


// DIALOG_COMPORT 대화 상자

class DIALOG_COMPORT : public CDialogEx
{
	DECLARE_DYNAMIC(DIALOG_COMPORT)

public:
	DIALOG_COMPORT(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DIALOG_COMPORT();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_COMPORT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	CComboBox m_cmb_port_1;
	CComboBox m_cmb_baud_1;
	CComboBox m_cmb_databit_1;
	CComboBox m_cmb_parity_1;
	CComboBox m_cmb_stopbit_1;

	CComboBox m_cmb_port_2;
	CComboBox m_cmb_baud_2;
	CComboBox m_cmb_databit_2;
	CComboBox m_cmb_parity_2;
	CComboBox m_cmb_stopbit_2;

	CComboBox m_cmb_port_3;
	CComboBox m_cmb_baud_3;
	CComboBox m_cmb_databit_3;
	CComboBox m_cmb_parity_3;
	CComboBox m_cmb_stopbit_3;
	 
	CComboBox m_cmb_port_4;
	CComboBox m_cmb_baud_4;
	CComboBox m_cmb_databit_4;
	CComboBox m_cmb_parity_4;
	CComboBox m_cmb_stopbit_4;
};

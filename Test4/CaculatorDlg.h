
// CaculatorDlg.h : ͷ�ļ�
//

#pragma once


// CCaculatorDlg �Ի���
class CCaculatorDlg : public CDialogEx
{
// ����
public:
	CCaculatorDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CACULATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On_0();
	afx_msg void On_point();
	afx_msg void On_1();
	afx_msg void On_2();
	afx_msg void On_3();
	afx_msg void On_4();
	afx_msg void On_5();
	afx_msg void On_6();
	afx_msg void On_7();
	afx_msg void On_8();
	afx_msg void On_9();
	afx_msg void On_add();
	afx_msg void On_sub();
	afx_msg void On_mux();
	afx_msg void On_delive();
	afx_msg void On_remainer();
	afx_msg void On_light();
	afx_msg void On_right();
	// ��¼����ı��ʽ
	CString m_input;
	afx_msg void On_tui();
	afx_msg void On_delete();
	bool judge(CString &s);
	void transfer(CString &s);
	afx_msg void On_equal();
	// �����ܺ�
	double sum;
	void erase(CString &s);
	afx_msg void On_sin();
	CString copy_str;
	afx_msg void On_cos();
	afx_msg void On_tan();
	afx_msg void On_sqrt();
	afx_msg void On_N();
	afx_msg void On_P();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void On032771();
	afx_msg void On032772();
	afx_msg void On032776();
	afx_msg void On032777();


	CMFCButton mfc_Button_OpenClose;
	CMFCButton d;
	CMFCButton K1;
	CMFCButton k3;
	CMFCButton k4;
};

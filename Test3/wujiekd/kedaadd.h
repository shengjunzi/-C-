#pragma once


// kedaadd 对话框

class kedaadd : public CDialogEx
{
	DECLARE_DYNAMIC(kedaadd)

public:
	kedaadd(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~kedaadd();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = add };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString name;
	CString grade;
	CString classs;
	

	CString number;


	CString m_set;        //手动增加
	BOOL FA;
	CString program;
	CString math;
	CString lishan;
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	afx_msg void OnPaint();
};

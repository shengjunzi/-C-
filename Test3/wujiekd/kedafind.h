#pragma once


// kedafind 对话框

class kedafind : public CDialogEx
{
	DECLARE_DYNAMIC(kedafind)

public:
	kedafind(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~kedafind();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = finds };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	CString filenaem="C:\\Users\\Administrator\\Desktop\\kkk.txt";
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton1();
	CString b;
	int a;
	BOOL fa;
	afx_msg void OnEnChangeEdit1();
};

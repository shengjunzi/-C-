#pragma once


// kedafinds 对话框

class kedafinds : public CDialogEx
{
	DECLARE_DYNAMIC(kedafinds)

public:
	kedafinds(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~kedafinds();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = find_s };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedCancel();
//	UINT a;
	CString b; 
	BOOL FA;
	CString filenaem = "C:\\Users\\Administrator\\source\\repos\\wujiekd\\keda.dat";
	int a;
	afx_msg void OnPaint();
};

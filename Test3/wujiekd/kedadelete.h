#pragma once


// kedadelete 对话框

class kedadelete : public CDialogEx
{
	DECLARE_DYNAMIC(kedadelete)

public:
	kedadelete(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~kedadelete();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = delete_ };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	UINT a;
	CString b;
	int a;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedCancel();
	BOOL FA;
	afx_msg void OnPaint();
};

#pragma once


// kedaimport 对话框

class kedaimport : public CDialogEx
{
	DECLARE_DYNAMIC(kedaimport)

public:
	kedaimport(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~kedaimport();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = import };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	BOOL FA;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnPaint();
};

#pragma once


// kedasave 对话框

class kedasave : public CDialogEx
{
	DECLARE_DYNAMIC(kedasave)

public:
	kedasave(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~kedasave();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = save };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedCancel();
};

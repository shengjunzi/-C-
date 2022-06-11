#pragma once


// kedachange 对话框

class kedachange : public CDialogEx
{
	DECLARE_DYNAMIC(kedachange)

public:
	kedachange(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~kedachange();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = change };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString old_name;
	CString new_name;
	CString name;
	CString new_grade;
	CString new_class;
	UINT new_math;
	UINT new_program;
	UINT new_lishan;
	UINT new_number;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnEnChangeEdit10();

	int cao;
	BOOL FA;
};

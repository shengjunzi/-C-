// kedachange.cpp: 实现文件
//

#include "stdafx.h"
#include "wujiekd.h"
#include "kedachange.h"
#include "afxdialogex.h"


// kedachange 对话框

IMPLEMENT_DYNAMIC(kedachange, CDialogEx)

kedachange::kedachange(CWnd* pParent /*=nullptr*/)
	: CDialogEx(change, pParent)
	, old_name(_T(""))
	, new_name(_T(""))
	, name(_T(""))
	, new_grade(_T(""))
	, new_class(_T(""))
	, new_math(0)
	, new_program(0)
	, new_lishan(0)
	, new_number(0)
	, cao(0)
{
	FA = FALSE;
}

kedachange::~kedachange()
{
}

void kedachange::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, old_name);
	DDX_Text(pDX, IDC_EDIT7, new_name);
	DDX_Text(pDX, IDC_EDIT10, name);
	//  DDX_Radio(pDX, IDC_RADIO2, a);
	DDX_Text(pDX, IDC_EDIT5, new_grade);
	DDX_Text(pDX, IDC_EDIT9, new_class);
	//  DDX_Text(pDX, IDC_EDIT1, new_number);
	DDX_Text(pDX, IDC_EDIT11, new_math);
	DDX_Text(pDX, IDC_EDIT3, new_program);
	DDX_Text(pDX, IDC_EDIT8, new_lishan);
	DDX_Text(pDX, IDC_EDIT1, new_number);
	//  DDX_Radio(pDX, IDC_RADIO2, a);
	DDX_Radio(pDX, IDC_RADIO2, cao);
}


BEGIN_MESSAGE_MAP(kedachange, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &kedachange::OnBnClickedButton1)
	ON_BN_CLICKED(IDCANCEL, &kedachange::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_EDIT10, &kedachange::OnEnChangeEdit10)
//	ON_WM_PAINT()
END_MESSAGE_MAP()


// kedachange 消息处理程序


void kedachange::OnBnClickedButton1()
{
	CDialogEx::OnOK();// TODO: 在此添加控件通知处理程序代码
}


void kedachange::OnBnClickedCancel()
{
	FA = TRUE;
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void kedachange::OnEnChangeEdit10()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

}



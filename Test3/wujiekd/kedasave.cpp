// kedasave.cpp: 实现文件
//

#include "stdafx.h"
#include "wujiekd.h"
#include "kedasave.h"
#include "afxdialogex.h"


// kedasave 对话框

IMPLEMENT_DYNAMIC(kedasave, CDialogEx)

kedasave::kedasave(CWnd* pParent /*=nullptr*/)
	: CDialogEx(save, pParent)
{

}

kedasave::~kedasave()
{
}

void kedasave::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(kedasave, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &kedasave::OnBnClickedButton1)
	ON_BN_CLICKED(IDCANCEL, &kedasave::OnBnClickedCancel)
END_MESSAGE_MAP()


// kedasave 消息处理程序


void kedasave::OnBnClickedButton1()
{
	CDialogEx::OnOK();
	// TODO: 在此添加控件通知处理程序代码
}


void kedasave::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}

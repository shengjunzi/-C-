// kedaadd.cpp: 实现文件
//

#include "stdafx.h"
#include "wujiekd.h"
#include "kedaadd.h"
#include "afxdialogex.h"


// kedaadd 对话框

IMPLEMENT_DYNAMIC(kedaadd, CDialogEx)

kedaadd::kedaadd(CWnd* pParent /*=nullptr*/)
	: CDialogEx(add, pParent)
	, name(_T(""))
	, grade(_T(""))
	, number(_T(""))
	, classs(_T(""))
	, program(_T(""))
	, math(_T(""))
	, lishan(_T(""))
{
	FA = FALSE;
}

kedaadd::~kedaadd()
{
}

void kedaadd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, name);
	DDX_Text(pDX, IDC_EDIT3, grade);
	DDX_Text(pDX, IDC_EDIT2, classs);
	DDX_Text(pDX, IDC_EDIT4, number);
	DDX_Text(pDX, IDC_EDIT5, program);
	DDX_Text(pDX, IDC_EDIT6, math);
	DDX_Text(pDX, IDC_EDIT7, lishan);
}


BEGIN_MESSAGE_MAP(kedaadd, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &kedaadd::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_OK, &kedaadd::OnBnClickedOk)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// kedaadd 消息处理程序





void kedaadd::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	FA = TRUE;
	CDialogEx::OnCancel();
}


BOOL kedaadd::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	name = "";
	grade = "";
	classs = "";
	number = "";
	program = "";
	math = "";
	lishan = "";
	// TODO:  在此添加额外的初始化
	GetDlgItem(IDC_EDIT1)->SetFocus();
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void kedaadd::OnBnClickedOk()
{
	CDialogEx::OnOK();
	// TODO: 在此添加控件通知处理程序代码
}


void kedaadd::OnPaint()
{

	CPaintDC   dc(this);
	CRect   rect;
	GetClientRect(&rect);
	CDC   dcMem;
	dcMem.CreateCompatibleDC(&dc);
	CBitmap   bmpBackground;
	bmpBackground.LoadBitmap(IDB_BITMAP4);          		//IDB_BITMAP是你自己的图对应的ID   
	BITMAP   bitmap;
	bmpBackground.GetBitmap(&bitmap);
	CBitmap   *pbmpOld = dcMem.SelectObject(&bmpBackground);
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
}
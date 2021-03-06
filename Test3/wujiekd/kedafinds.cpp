// kedafinds.cpp: 实现文件
//

#include "stdafx.h"
#include "wujiekd.h"
#include "kedafinds.h"
#include "afxdialogex.h"


// kedafinds 对话框

IMPLEMENT_DYNAMIC(kedafinds, CDialogEx)

kedafinds::kedafinds(CWnd* pParent /*=nullptr*/)
	: CDialogEx(find_s, pParent)
	, a(0)
	, b(_T(""))
{
	FA = FALSE;
}

kedafinds::~kedafinds()
{
}

void kedafinds::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Radio(pDX, IDC_RADIO1, a);
	DDX_Text(pDX, IDC_EDIT1, b);
	DDX_Radio(pDX, IDC_RADIO1, a);
}


BEGIN_MESSAGE_MAP(kedafinds, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &kedafinds::OnBnClickedButton1)
	ON_BN_CLICKED(IDCANCEL, &kedafinds::OnBnClickedCancel)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// kedafinds 消息处理程序


void kedafinds::OnBnClickedButton1()
{
	CDialogEx::OnOK();
	// TODO: 在此添加控件通知处理程序代码
}


void kedafinds::OnBnClickedCancel()
{
	FA = TRUE;
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void kedafinds::OnPaint()
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

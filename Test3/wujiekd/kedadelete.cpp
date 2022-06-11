// kedadelete.cpp: 实现文件
//

#include "stdafx.h"
#include "wujiekd.h"
#include "kedadelete.h"
#include "afxdialogex.h"


// kedadelete 对话框

IMPLEMENT_DYNAMIC(kedadelete, CDialogEx)

kedadelete::kedadelete(CWnd* pParent /*=nullptr*/)
	: CDialogEx(delete_, pParent)
	, b(_T(""))
	, a(0)
{
	FA = FALSE;
}

kedadelete::~kedadelete()
{
}

void kedadelete::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Radio(pDX, IDC_RADIO1, a);
	DDX_Text(pDX, IDC_EDIT1, b);
	DDX_Radio(pDX, IDC_RADIO1, a);
}


BEGIN_MESSAGE_MAP(kedadelete, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &kedadelete::OnBnClickedButton2)
	ON_BN_CLICKED(IDCANCEL, &kedadelete::OnBnClickedCancel)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// kedadelete 消息处理程序


void kedadelete::OnBnClickedButton2()
{
	CDialogEx::OnOK();// TODO: 在此添加控件通知处理程序代码
}


void kedadelete::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	FA = TRUE;
	CDialogEx::OnCancel();
}


void kedadelete::OnPaint()
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

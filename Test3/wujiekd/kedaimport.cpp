// kedaimport.cpp: 实现文件
//

#include "stdafx.h"
#include "wujiekd.h"
#include "kedaimport.h"
#include "afxdialogex.h"


// kedaimport 对话框

IMPLEMENT_DYNAMIC(kedaimport, CDialogEx)

kedaimport::kedaimport(CWnd* pParent /*=nullptr*/)
	: CDialogEx(import, pParent)
{
	FA = FALSE;
}

kedaimport::~kedaimport()
{
}

void kedaimport::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(kedaimport, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &kedaimport::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &kedaimport::OnBnClickedButton2)
	ON_BN_CLICKED(IDCANCEL, &kedaimport::OnBnClickedCancel)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// kedaimport 消息处理程序


void kedaimport::OnBnClickedButton1()
{
	FA = TRUE;
	CDialogEx::OnOK();
	// TODO: 在此添加控件通知处理程序代码
}


void kedaimport::OnBnClickedButton2()
{
	
	CDialogEx::OnOK();// TODO: 在此添加控件通知处理程序代码
}


void kedaimport::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void kedaimport::OnPaint()
{

	CPaintDC   dc(this);
	CRect   rect;
	GetClientRect(&rect);
	CDC   dcMem;
	dcMem.CreateCompatibleDC(&dc);
	CBitmap   bmpBackground;
	bmpBackground.LoadBitmap(IDB_BITMAP2);          		//IDB_BITMAP是你自己的图对应的ID   
	BITMAP   bitmap;
	bmpBackground.GetBitmap(&bitmap);
	CBitmap   *pbmpOld = dcMem.SelectObject(&bmpBackground);
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
}

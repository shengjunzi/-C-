
// wujiekdDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "wujiekd.h"
#include "wujiekdDlg.h"
#include "afxdialogex.h"
#include"management.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CwujiekdDlg 对话框



CwujiekdDlg::CwujiekdDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(DIALOG, pParent)
	, zhanghao(_T(""))
	, mima(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CwujiekdDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, zhanghao);
	DDX_Text(pDX, IDC_EDIT1, mima);
}

BEGIN_MESSAGE_MAP(CwujiekdDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CwujiekdDlg::OnBnClickedOk)

//ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CwujiekdDlg 消息处理程序

BOOL CwujiekdDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	SetWindowText("学生成绩管理系统");
	SetDlgItemText(IDC_EDIT2, "QQ/手机/邮箱");	
	SetDlgItemText(IDC_EDIT1, "输入密码");
	
	return FALSE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CwujiekdDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CwujiekdDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CwujiekdDlg::OnPaint()    //用来添加背景图片
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else                              //设置背景图

	{ 
		CPaintDC   dc(this);
		CRect   rect;
		GetClientRect(&rect);
		CDC   dcMem;
		dcMem.CreateCompatibleDC(&dc);
		CBitmap   bmpBackground;
		bmpBackground.LoadBitmap(IDB_BITMAP4);         	//IDB_BITMAP是我设置的图对应的ID   
		BITMAP   bitmap;
		bmpBackground.GetBitmap(&bitmap);
		CBitmap   *pbmpOld = dcMem.SelectObject(&bmpBackground);
		dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0,bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
	}
}




void CwujiekdDlg::OnBnClickedOk()  //按下确定键对账号密码进行判断
{
	
	UpdateData(TRUE);
	CString zhang = zhanghao;
	CString mi = mima;
	if (zhang == "张昌盛" && mi == "123")
	{

		AfxGetMainWnd()->SendMessage(WM_CLOSE);
		management dlgs;
		dlgs.DoModal();
	}
	else if (zhang == "" || mi == "")
	{
		MessageBox("账号或密码不能为空", "提醒");
		return;
	}
	else
	{
		MessageBox("账号或密码错误，还有三次机会~","提醒");    //只是吓吓人而已，哈哈，三次锁定可以加，也挺简单的
		return;
	}
	UpdateData(FALSE);
	CDialogEx::OnOK();
	
}

BOOL CwujiekdDlg::PreTranslateMessage(MSG* pMsg)         //重载它来处理键盘和鼠标消息，这段代码主要用于当点击编辑框，
{                                                        //会把默认文本清除，其实是按照QQ的思路来设置的，比较巧妙，用了特殊的设置密码
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
	CEdit* pEdit2 = (CEdit*)GetDlgItem(IDC_EDIT2);
	CString s = (CString)"";
	if (pMsg->message == WM_LBUTTONDOWN)
	{	
		UpdateData(TRUE);
		if (pMsg->hwnd == pEdit->GetSafeHwnd())
		{
			CEdit * kd = (CEdit*)GetDlgItem(IDC_EDIT1);
			kd->SetPasswordChar('*');
			pEdit->SetWindowText(_T(""));
			if (zhanghao== s)                    //不要以为这里没有用，我加了很多细节
			{
				pEdit2->SetWindowText("QQ/手机/邮箱");
			}
		}
		else if(pMsg->hwnd == pEdit2->GetSafeHwnd())
		{
			pEdit2->SetWindowText("");
			if (mima == s)
			{			
				CEdit * kd = (CEdit*)GetDlgItem(IDC_EDIT1);
				kd->SetPasswordChar(NULL);
				pEdit->SetWindowText("输入密码");
			}
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}



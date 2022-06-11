
// CaculatorDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Caculator.h"
#include "CaculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "Resource.h"
#include "Stack.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
//**************��������atof()�����ַ�ת��Ϊ������
#include <math.h>
using namespace std;

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCaculatorDlg �Ի���



CCaculatorDlg::CCaculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCaculatorDlg::IDD, pParent)
	, m_input(_T(""))
	, sum(0)
	, copy_str(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCaculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_input);
	DDX_Text(pDX, IDC_EDIT2, sum);
	DDX_Control(pDX, IDC_BUTTON1, mfc_Button_OpenClose);
	DDX_Control(pDX, IDC_BUTTON7, d);
	DDX_Control(pDX, IDC_BUTTON2, K1);
	DDX_Control(pDX, IDC_BUTTON4, k3);
	DDX_Control(pDX, IDC_BUTTON5, k4);
}

BEGIN_MESSAGE_MAP(CCaculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CCaculatorDlg::On_0)
	ON_BN_CLICKED(IDC_BUTTON8, &CCaculatorDlg::On_point)
	ON_BN_CLICKED(IDC_BUTTON2, &CCaculatorDlg::On_1)
	ON_BN_CLICKED(IDC_BUTTON7, &CCaculatorDlg::On_2)
	ON_BN_CLICKED(IDC_BUTTON4, &CCaculatorDlg::On_3)
	ON_BN_CLICKED(IDC_BUTTON5, &CCaculatorDlg::On_4)
	ON_BN_CLICKED(IDC_BUTTON10, &CCaculatorDlg::On_5)
	ON_BN_CLICKED(IDC_BUTTON6, &CCaculatorDlg::On_6)
	ON_BN_CLICKED(IDC_BUTTON11, &CCaculatorDlg::On_7)
	ON_BN_CLICKED(IDC_BUTTON13, &CCaculatorDlg::On_8)
	ON_BN_CLICKED(IDC_BUTTON12, &CCaculatorDlg::On_9)
	ON_BN_CLICKED(IDC_BUTTON15, &CCaculatorDlg::On_add)
	ON_BN_CLICKED(IDC_BUTTON14, &CCaculatorDlg::On_sub)
	ON_BN_CLICKED(IDC_BUTTON9, &CCaculatorDlg::On_mux)
	ON_BN_CLICKED(IDC_BUTTON16, &CCaculatorDlg::On_delive)
	ON_BN_CLICKED(IDC_BUTTON18, &CCaculatorDlg::On_remainer)
	ON_BN_CLICKED(IDC_BUTTON19, &CCaculatorDlg::On_light)
	ON_BN_CLICKED(IDC_BUTTON23, &CCaculatorDlg::On_right)
	ON_BN_CLICKED(IDC_BUTTON27, &CCaculatorDlg::On_tui)
	ON_BN_CLICKED(IDC_BUTTON26, &CCaculatorDlg::On_delete)
	ON_BN_CLICKED(IDC_BUTTON3, &CCaculatorDlg::On_equal)
	ON_BN_CLICKED(IDC_BUTTON17, &CCaculatorDlg::On_sin)
	ON_BN_CLICKED(IDC_BUTTON21, &CCaculatorDlg::On_cos)
	ON_BN_CLICKED(IDC_BUTTON24, &CCaculatorDlg::On_tan)
	ON_BN_CLICKED(IDC_BUTTON22, &CCaculatorDlg::On_sqrt)
	ON_BN_CLICKED(IDC_BUTTON25, &CCaculatorDlg::On_N)
	ON_BN_CLICKED(IDC_BUTTON20, &CCaculatorDlg::On_P)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_0_32771, &CCaculatorDlg::On032771)
	ON_COMMAND(ID_0_32772, &CCaculatorDlg::On032772)
	ON_COMMAND(ID_0_32776, &CCaculatorDlg::On032776)
	ON_COMMAND(ID_0_32777, &CCaculatorDlg::On032777)
END_MESSAGE_MAP()


// CCaculatorDlg ��Ϣ�������

BOOL CCaculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CCaculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCaculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CCaculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCaculatorDlg::On_0()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	
	if (!m_input.IsEmpty())
	{
		char temp = m_input[m_input.GetLength() - 1];
		if (temp == ')')
			return;
	}
	mfc_Button_OpenClose.m_bTransparent = FALSE;
	mfc_Button_OpenClose.m_bDontUseWinXPTheme = TRUE;
	mfc_Button_OpenClose.SetFaceColor(RGB(0, 0, 255));
	m_input += _T("0");
	UpdateData(false);
}


void CCaculatorDlg::On_point()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (m_input.IsEmpty())
		return;
	//***************************ǳ���жϣ�.ǰ��ֻ����������
	if (!m_input.IsEmpty())
	{
		char temp = m_input[m_input.GetLength() - 1];
		if (!(temp >= '0'&&temp <= '9'))
			return;
	}
	//***************************����жϣ�һ�����ֲ�����������С����
	int len = m_input.GetLength();
	while (len)
	{
		if (m_input[len - 1] == '+' || m_input[len - 1] == '-' || m_input[len - 1] == '*' ||
			m_input[len - 1] == '%' || m_input[len - 1] == '/'
			|| m_input[len - 1] == 'N' || m_input[len - 1] == 'P')
			break;
		if (m_input[len-1] == '.')
			return;
		len--;
	}
	m_input += _T(".");
	UpdateData(false);
}


void CCaculatorDlg::On_1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	K1.m_bTransparent = FALSE;
	K1.m_bDontUseWinXPTheme = TRUE;
	K1.SetFaceColor(RGB(255, 255, 0));
	if (!m_input.IsEmpty())
	{
		char temp = m_input[m_input.GetLength() - 1];
		if (temp == ')')
			return;
	}
	m_input += _T("1");
	UpdateData(false);
}


void CCaculatorDlg::On_2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	d.m_bTransparent = FALSE;
	d.m_bDontUseWinXPTheme = TRUE;
	d.SetFaceColor(RGB(0, 255, 0));
	if (!m_input.IsEmpty())
	{
		char temp = m_input[m_input.GetLength() - 1];
		if (temp == ')')
			return;
	}
	m_input += _T("2");
	UpdateData(false);
}


void CCaculatorDlg::On_3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	k3.m_bTransparent = FALSE;
	k3.m_bDontUseWinXPTheme = TRUE;
	k3.SetFaceColor(RGB(100, 100, 100));
	if (!m_input.IsEmpty())
	{
		char temp = m_input[m_input.GetLength() - 1];
		if (temp == ')')
			return;
	}
	m_input += _T("3");
	UpdateData(false);
}



void CCaculatorDlg::On_4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	k4.m_bTransparent = FALSE;
	k4.m_bDontUseWinXPTheme = TRUE;
	k4.SetFaceColor(RGB(10, 10, 10));
	if (!m_input.IsEmpty())
	{
		char temp = m_input[m_input.GetLength() - 1];
		if (temp == ')')
			return;
	}
	m_input += _T("4");
	UpdateData(false);
}


void CCaculatorDlg::On_5()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (!m_input.IsEmpty())
	{
		char temp = m_input[m_input.GetLength() - 1];
		if (temp == ')')
			return;
	}
	m_input += _T("5");
	UpdateData(false);
}


void CCaculatorDlg::On_6()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (!m_input.IsEmpty())
	{
		char temp = m_input[m_input.GetLength() - 1];
		if (temp == ')')
			return;
	}
	m_input += _T("6");
	UpdateData(false);
}



void CCaculatorDlg::On_7()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (!m_input.IsEmpty())
	{
		char temp = m_input[m_input.GetLength() - 1];
		if (temp == ')')
			return;
	}
	m_input += _T("7");
	UpdateData(false);
}


void CCaculatorDlg::On_8()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (!m_input.IsEmpty())
	{
		char temp = m_input[m_input.GetLength() - 1];
		if (temp == ')')
			return;
	}
	m_input += _T("8");
	UpdateData(false);
}


void CCaculatorDlg::On_9()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (!m_input.IsEmpty())
	{
		char temp = m_input[m_input.GetLength() - 1];
		if (temp == ')')
			return;
	}
	m_input += _T("9");
	UpdateData(false);
}


void CCaculatorDlg::On_add()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (m_input.IsEmpty())
		return;
	if (!m_input.IsEmpty())
	{
		char temp = m_input[m_input.GetLength() - 1];
		if (temp == '+' || temp == '-' || temp == '*' || temp == '/' 
			|| temp == '%' || temp == '.' || temp == 'N' || temp == 'P' || temp == '(')
			return;
	}
	m_input += _T("+");
	UpdateData(false);
}



void CCaculatorDlg::On_sub()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (m_input.IsEmpty())
		return;
	if (!m_input.IsEmpty())
	{
		char temp = m_input[m_input.GetLength() - 1];
		if (temp == '+' || temp == '-' || temp == '*' || temp == '/' 
			|| temp == '%' || temp == '.' || temp == 'N' || temp == 'P' || temp == '(')
			return;
	}
	m_input += _T("-");
	UpdateData(false);
}


void CCaculatorDlg::On_mux()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (m_input.IsEmpty())
		return;
	if (!m_input.IsEmpty())
	{
		char temp = m_input[m_input.GetLength() - 1];
		if (temp == '+' || temp == '-' || temp == '*' || temp == '/' 
			|| temp == '%' || temp == '.' || temp == 'N' || temp == 'P' || temp == '(')
			return;
	}
	m_input += _T("*");
	UpdateData(false);
}


void CCaculatorDlg::On_delive()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (m_input.IsEmpty())
		return;
	if (!m_input.IsEmpty())
	{
		char temp = m_input[m_input.GetLength() - 1];
		if (temp == '+' || temp == '-' || temp == '*' || temp == '/'
			|| temp == '%' || temp == '.' || temp == 'N' || temp == 'P' || temp == '(')
			return;
	}
	m_input += _T("/");
	UpdateData(false);
}



void CCaculatorDlg::On_remainer()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (m_input.IsEmpty())
		return;
	if (!m_input.IsEmpty())
	{
		char temp = m_input[m_input.GetLength() - 1];
		if (temp == '+' || temp == '-' || temp == '*' || temp == '/' || 
			temp == '%' || temp == '.' || temp == 'N' || temp == 'P' || temp == '(')
			return;
	}
	m_input += _T("%");
	UpdateData(false);
}


void CCaculatorDlg::On_light()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//*****************��������߲��������ֻ��ߵ�
	if (!m_input.IsEmpty())
	{
		char temp = m_input[m_input.GetLength() - 1];
		if (((temp >= '0'&&temp <= '9') || temp == '.'))
			return;
	}
	m_input += _T("(");
	UpdateData(false);
}


void CCaculatorDlg::On_right()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (!m_input.IsEmpty())
	{
		char temp = m_input[m_input.GetLength() - 1];
		if (!(temp >= '0'&&temp <= '9'))
			return;
	}
	if (m_input.IsEmpty())
		return;
	m_input += _T(")");
	UpdateData(false);
}


void CCaculatorDlg::On_tui()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	this->erase(m_input);
}


void CCaculatorDlg::On_delete()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_input = _T("");
	UpdateData(false);
}

//********************�жϳ����Ĵ���������ƥ��
bool CCaculatorDlg::judge(CString &s)
{
	int len = s.GetLength();
	//********************1.β�ַ�
	if (s[len - 1] == '+' || s[len - 1] == '-' || s[len - 1] == '*' || 
		s[len - 1] == '%' || s[len - 1] == '/' || s[len - 1] == '.'
		|| s[len-1] == 'N' || s[len-1] == 'P')
		return false;
	//*********************2.����ƥ��
	Stack<int> temp;
	int j;
	for (int i = 0; i <len; i++)
	{
		if (s[i] == '(')
			temp.Push(s[i]);
		else if (s[i] == ')')
		if (!temp.Pop(j))      //��ջ���ɹ�
		{
			//cout << "����������ȱʧ��" << endl;
			::MessageBox(NULL,L"������ȱʧ��",L"����",MB_OK);
			return false;
		}
	}
	if (!temp.IsEmpty())
	{
		//cout << "����������ȱʧ��" << endl;
		::MessageBox(NULL, L"������ȱʧ��", L"����", MB_OK);
		return false;
	}
	return true;
}

//**************************����׺ʽת��Ϊ��׺ʽ
void CCaculatorDlg::transfer(CString &s)
{
	ofstream fout;
	fout.open("1.txt", ios::out);
	int len = s.GetLength();
	Stack<char>myStack;
	for (int i = 0; i <len - 1; i++)        //�������һ���ַ����Ҳ��ж�
	{
		//***************1.�����֣���������
		if ((s[i] >='0'&&s[i] <= '9') || s[i] == '.')
		{
			fout <<(char)s[i];             //��֪��Ϊʲôϵͳ�Զ�����ת����ASCLL���ʮ����
			if (s[i + 1]<'0'&&s[i + 1]>'9')
			{
				fout << " ";
				continue;
			}
			continue;
		}
		//***************2.��')'����ջ����Ϊ'('
		else if (')' == s[i])
		{
			char temp;
			myStack.Pop(temp);
			while ('(' != temp)
			{
				fout << temp;
				myStack.Pop(temp);
			}
		}
		//***************3.'+','-'ֱ�ӵ�ջ,����Ϊ�ջ���'('
		else if ('+' == s[i] || '-' == s[i])
		{
			if (myStack.IsEmpty())
				myStack.Push(s[i]);
			else
			{
				char temp;
				do
				{
					myStack.Pop(temp);
					if ('(' == temp)          //�����(,��ѹջ��ȥ
						myStack.Push(temp);
					else
						fout << temp;
				} while (!myStack.IsEmpty() && '(' != temp);
				//***********���ջ��Ϊ�ջ��߲�Ϊ(,��ջ
				//***************��ջ�����˽�ջ
				myStack.Push(s[i]);
			}
		}
		//***************4.*,/,P
		else if ('*' == s[i] || '/' == s[i] || '%' == s[i]||s[i]=='P')
		{
			if (myStack.IsEmpty())
				myStack.Push(s[i]);
			else
			{
				char temp;
				do
				{
					myStack.Pop(temp);
					if ('(' == temp || '+' == temp || '-' == temp)          //�����,��ѹջ��ȥ
						myStack.Push(temp);
					else
						fout << temp;
				} while (!myStack.IsEmpty() && ('(' != temp) && ('+' != temp) && ('-' != temp));
				myStack.Push(s[i]);
			}
		}
		//**************************������ֱ��ѹջ
		else if ('(' == s[i])
			myStack.Push(s[i]);
		//***************************************************����
		//************����ֱ��ѹջ����ǰ��ֻ������������
		else if ('N' == s[i])
			myStack.Push(s[i]);

		fout << " ";         //����ո��������
	}
	//********************************���һ���ַ�
	if (s[len - 1] == ')')
	{
		char temp;
		myStack.Pop(temp);
		while ('(' != temp)
		{
			fout << temp;
			myStack.Pop(temp);
		}
	}
	else if (s[len - 1] >= '0'&&s[len - 1] <= '9')
		fout << (char)s[len- 1];
	//********************************��󵯳�ʣ����ַ�
	while (!myStack.IsEmpty())
	{
		char temp;
		myStack.Pop(temp);
		fout << temp;
	}
	fout.close();
}


void CCaculatorDlg::On_equal()
{
	if (m_input.IsEmpty())
		return;
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (!judge(m_input))
	{
		::MessageBox(NULL, L"�������ʽ����", L"����", MB_OK);
		return;
	}
	this->transfer(m_input);
	//**************************��ʼ����
	Stack<double> stack2;
	stack2.Push(0);              //���Լ��㸺��
	ifstream fin;
	fin.open("1.txt", ios::in);
	char a[500];
	char str[50];                //���ڼ�¼����
	memset(str, '\0', 50);
	int j = 0;
	fin.getline(a, 100);
	int len = strlen(a);
	sum = 0;
	double add1, add2;           //�����������
	int temp1, temp2;            //����ȡ��ֻ��������
	//*********************Ϊʲôcase���治�ܶ������
	for (int i = 0; i < len; i++)
	{
		//***************************������
		if ((a[i] >= '0'&&a[i] <= '9') || a[i] == '.')
		{
			str[j++] = a[i];       //�����ֻ���ȱ�������
			//��������һ���������Ҳ����С���㣬��ʼת������׺ʽ����󲻿��������֣����Բ���Խ��
			if (!((a[i + 1] >= '0'&&a[i + 1] <= '9') || a[i + 1] == '.'))
			{
				//*****************�ַ�ת��Ϊ��������ѹջ
				double temp = atof(str);
				stack2.Push(temp);
				j = 0;
				memset(str, '\0', 50);      //��ʼ������
			}
			continue;
		}
		//***************************�����
		switch (a[i])
		{
		case '+':
			stack2.Pop(add2);
			stack2.Pop(add1);
			sum = add1 + add2;
			stack2.Push(sum);
			break;
		case '-':
			stack2.Pop(add2);
			stack2.Pop(add1);
			sum = add1 - add2;
			stack2.Push(sum);
			break;
		case '*':
			stack2.Pop(add2);
			stack2.Pop(add1);
			sum = add1 * add2;
			stack2.Push(sum);
			break;
		case '/':
			stack2.Pop(add2);
			stack2.Pop(add1);
			if (add2 == 0)
			{
				//cout << "��������Ϊ0��" << endl;
				::MessageBox(NULL, L"��������Ϊ0��", L"����", MB_OK);
				return;
			}
			sum = add1 / add2;
			stack2.Push(sum);
			break;
		case '%':
			stack2.Pop(add2);
			stack2.Pop(add1);
			temp1 = (int)add1;
			temp2 = (int)add2;
			sum = temp1%temp2;
			stack2.Push(sum);
			break;
		case ' ':
			continue;
			//******************************************����
		case 'N':
			stack2.Pop(add1);
			sum = 0 - add1;
			stack2.Push(sum);
			break;
		case 'P':
			stack2.Pop(add2);
			stack2.Pop(add1);
			sum = pow(add1,add2);
			stack2.Push(sum);
			break;
		default:
			break;
		}
	}
	//cout << "����֮�ͣ�" << sum << endl;
	//***************�������֣�û��������������ֻ���ջ��
	/*if (stack2.IsEmpty())
		return;*/
	stack2.Pop(sum);
	UpdateData(false);
	fin.close();
	copy_str = m_input;
	m_input = _T("");
}

//**************************����һ���ַ�
void CCaculatorDlg::erase(CString &s)
{
	//*****************�Ѿ�Ϊ�վͲ���Ҫ�����
	if (s.IsEmpty())
		return;
	int len = s.GetLength();
	s = s.Left(len-1);
	//s[len - 1] = '\0';
	UpdateData(false);
}


void CCaculatorDlg::On_sin()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//******************CStringתdouble
	//double temp = _wtof(m_input);
	this->On_equal();
	sum = sin(sum);
	m_input = copy_str;             
	m_input = _T("sin(")+m_input+_T(")");
	UpdateData(false);
	copy_str = _T("");
	m_input = _T("");
	//sum = 0;
}


void CCaculatorDlg::On_cos()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	this->On_equal();
	sum = cos(sum);
	m_input = copy_str;
	m_input = _T("cos(") + m_input + _T(")");
	UpdateData(false);
	copy_str = _T("");
	m_input = _T("");
}


void CCaculatorDlg::On_tan()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	this->On_equal();
	sum = tan(sum);
	m_input = copy_str;
	m_input = _T("tan(") + m_input + _T(")");
	UpdateData(false);
	copy_str = _T("");
	m_input = _T("");
}


void CCaculatorDlg::On_sqrt()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	this->On_equal();
	sum = sqrt(sum);
	m_input = copy_str;
	m_input = _T("sqrt(") + m_input + _T(")");
	UpdateData(false);
	copy_str = _T("");
	m_input = _T("");
}


void CCaculatorDlg::On_N()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//****************����
	if (!m_input.IsEmpty())
	{
		char temp = m_input[m_input.GetLength() - 1];
		if (temp == 'N')
			this->erase(m_input);
		if (temp != '(')
			return;
	}
	m_input += _T("N");
	UpdateData(false);
}


void CCaculatorDlg::On_P()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (m_input.IsEmpty())
		return;
	if (!m_input.IsEmpty())
	{
		char temp = m_input[m_input.GetLength() - 1];
		if (!(temp>='0'&&temp<='9'))
			return;
	}
	m_input += _T("P");
	UpdateData(false);
}


//*************************************�Ҽ��˵�
void CCaculatorDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMenu menu, *pSubMenu;
	menu.LoadMenuW(IDR_MENU1);
	pSubMenu = menu.GetSubMenu(0);
	GetCursorPos(&point);                                            //�õ���괦
	pSubMenu->TrackPopupMenu(nFlags, point.x, point.y, this);        //ȷ���Ҽ�������Ĳ˵���������
	CDialogEx::OnRButtonDown(nFlags, point);
}


void CCaculatorDlg::On032771()
{
	// TODO:  �ڴ���������������
	::MessageBox(NULL,L"2022/6/8",L"TIME",MB_OK);
}


void CCaculatorDlg::On032777()
{
	// TODO:  �ڴ���������������
	::MessageBox(NULL, L"ʢ����", L"AUTHOR", MB_OK);
}

void CCaculatorDlg::On032772()
{
	// TODO:  �ڴ���������������
	::MessageBox(NULL, L"ʢ����", L"AUTHOR", MB_OK);
}
void CCaculatorDlg::On032776()
{
	// TODO:  �ڴ���������������
	::MessageBox(NULL, L"ʢ����", L"AUTHOR", MB_OK);
}



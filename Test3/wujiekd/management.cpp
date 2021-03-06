// management.cpp: 实现文件
//

#include "stdafx.h"
#include "wujiekd.h"
#include "management.h"
#include "afxdialogex.h"
#include "wujiekddlg.h"
#include<algorithm>             //引入快排
#include <afxdb.h>
#include <icrsint.h>
#include <windows.h>  
#include <sqltypes.h>  
#include <sql.h>  
#include <sqlext.h>

using namespace std;


// management 对话框

IMPLEMENT_DYNAMIC(management, CDialogEx)

management::management(CWnd* pParent /*=nullptr*/)
	: CDialogEx(menu, pParent)
	, m_stusum(0)
{
	m_index = 0;                
	m_line = 0;
	m_indexmax = 8;
	judge = FALSE;
	check = TRUE;
	filename = "";
	m_pConnection.CreateInstance(__uuidof(Connection));//创建 Connection 对象  
	//初始化Recordset指针
	pRecordset.CreateInstance(__uuidof(Recordset));

}

management::~management()
{
}

void management::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_list);
	DDX_Text(pDX, IDC_EDIT1, m_stusum);
	DDX_Control(pDX, IDC_EDIT2, m_edit);
	DDX_Control(pDX, IDC_COMBO1, m_cbx);
}


BEGIN_MESSAGE_MAP(management, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &management::OnLvnItemchangedList2)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON1, &management::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &management::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &management::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &management::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &management::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &management::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &management::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &management::OnBnClickedButton8)
	ON_WM_PAINT()
ON_NOTIFY(NM_DBLCLK, IDC_LIST2, &management::OnDblclkList2)
ON_EN_KILLFOCUS(IDC_EDIT2, &management::OnKillfocusEdit2)
ON_NOTIFY(NM_CUSTOMDRAW, IDC_LIST2, &management::OnCustomdrawList2)
ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST2, &management::OnColumnclickList2)
ON_CBN_SELCHANGE(IDC_COMBO1, &management::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// management 消息处理程序


void management::OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


BOOL management::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	ModifyStyleEx(0, WS_EX_APPWINDOW);

	CString str = "学生通讯录系统           用户：张昌盛";
	SetWindowText(str);

	CRect rect;
	CListCtrl* pmyListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST2);    //设置风格
	LONG dwStyle = GetWindowLong(pmyListCtrl->m_hWnd, GWL_STYLE);
	SetWindowLong(pmyListCtrl->m_hWnd, GWL_STYLE, dwStyle | LVS_REPORT);
	LONG styles = pmyListCtrl->GetExtendedStyle();
	pmyListCtrl->SetExtendedStyle(styles | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_NOSCROLL);
	pmyListCtrl->GetWindowRect(&rect);


	m_list.InsertColumn(0, "序号", LVCFMT_CENTER, 30);    //list control第一列会不在中间，但通过此方法可以很好的达到中间的目的

	m_list.InsertColumn(1, "序号", LVCFMT_CENTER, 50);
	m_list.InsertColumn(2, "学号", LVCFMT_CENTER, 100);
	m_list.InsertColumn(3, "姓名", LVCFMT_CENTER, 70);
	m_list.InsertColumn(4, "系所", LVCFMT_CENTER, 140);
	m_list.InsertColumn(5, "学位课", LVCFMT_CENTER, 60);
	m_list.InsertColumn(6, "选课时间", LVCFMT_CENTER, 100);
	m_list.InsertColumn(7, "手机号", LVCFMT_CENTER, 90);


	m_list.DeleteColumn(0);                  //删除第一列


	m_stusum=m_line;
	UpdateData(FALSE);
	GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);

	m_edit.ShowWindow(SW_HIDE);
	// TODO:  在此添加额外的初始化


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
//————————————————————————————————关键，多个操作功能会用到它！———————————————————————————————
BOOL management::nodata()//判断列表中是否有数据             
{
	if (m_list.GetItemText(0, 0) != "")
	{
		return TRUE;
	}
	return FALSE;

}

//——————————————————————————————————————添加————————————————————————————————————


BOOL management::empty()//判定数据是否存在没填的
{
	if (adds.name == "" || adds.grade == "" || adds.classs == "" || adds.number == "")
	{
		MessageBox("数据框有空,请填写");
		return FALSE;
	}
	return true;
}

BOOL management::checknumber()//检测学号是否相等
{
	
	for (UINT i = 0; i < m_line; i++)
	{
		
		if (adds.number == m_list.GetItemText(i, 1))
		{
			char cid[100];
			_itoa_s(i + 1, cid, 10);
			CString s = "学号与第";
			s += cid;
			s += "个同学相同，请重新输入";
			MessageBox(s);
			return FALSE;
		}
	}
	return TRUE;
}


void management::OnBnClickedButton1()//将数据加载至列表框
{
	// TODO: 在此添加控件通知处理程序代码
	while (1)
	{

		if (adds.DoModal() == IDOK && empty() && adds.FA == FALSE )
		{

			if (checknumber())
			{
				
				m_list.InsertItem(0, adds.name);                   //每次都是把新的信息加到第一行
				m_list.SetItemText(0, 1, adds.grade);
				m_list.SetItemText(0, 2, adds.classs);
				m_list.SetItemText(0, 3, adds.number);
				m_list.SetItemText(0, 4, adds.program);
				m_list.SetItemText(0, 5, adds.math);
				m_list.SetItemText(0, 6, adds.lishan);
				

				

				m_line++;

				m_stusum = m_line;                     //用于显示
				UpdateData(FALSE);
				m_index = 0;
				check = FALSE;
				adds.name = "";
				adds.grade = "";
				adds.classs = "";
				adds.number = "";
				adds.program = "";
				adds.math = "";
				adds.lishan = "";
			}
		}		
		if (adds.FA == TRUE)
		{
			adds.FA = FALSE;
			break;
		}
	}
}

//—————————————————————————————————————删除————————————————————————————————
void management::deletenull()//删除列表框的所有数据								
{
	m_list.DeleteAllItems();
	m_line = 0;
	m_stusum = m_line;
	UpdateData(FALSE);
	
}
void management::delete_q()//删除单个数据+调用上面函数删除所有数据
{
	if (deletes.a == 0 && deletes.b != "")
	{
		for (UINT i = 0; i < m_line; i++)
		{
			CString s = m_list.GetItemText(i, 1);
			if (deletes.b == s)
			{
				m_list.DeleteItem(i);
				m_line--;
				deletes.b = "";
				judge = TRUE;
				m_stusum = m_line;
				UpdateData(FALSE);
				MessageBox("删除成功");
				break;
			}

		}
		if (judge == FALSE)
			MessageBox("没有此名字的学生");
	}
	else if (deletes.a == 1 && deletes.b != "")
	{
			for (UINT i = 0; i < m_line; i++)
			{
				CString s = m_list.GetItemText(i, 0);
				if (deletes.b == s)
				{
					m_list.DeleteItem(i);
					m_line--;
					deletes.b = "";
					judge = TRUE;
					m_stusum = m_line;
					UpdateData(FALSE);
					MessageBox("删除成功");
					break;
				}

			}
			if (judge == FALSE)
				MessageBox("没有此学号的学生");
	}
	else if (deletes.a == 2)
	{
		deletenull();
	}
	else
	{
			MessageBox("请输入一项数据删除");
	}


}


void management::OnBnClickedButton2()//删除按钮响应函数
{
	if (!nodata() )
	{
		MessageBox("列表中没有数据~");
	}	
	while (nodata())
	{
		if (deletes.DoModal() == IDOK)
		{
			delete_q();
		}
		if (deletes.FA == TRUE|| !nodata())
		{
			deletes.FA = FALSE;
			break;
		}
	}
}

//——————————————————————————————————————保存————————————————————————————————

void management::OnBnClickedButton3()//保存按钮响应函数
{
	BOOL jdg = FALSE;

	kedasave saves;
	CFileDialog filesaves(FALSE);
	filesaves.m_ofn.lpstrTitle = "选择文件并保存";
	filesaves.m_ofn.lpstrFilter = "所有文件(*.*)\0*.*\0\0";
	if (filesaves.DoModal() == IDOK)
	{
		filename = filesaves.GetPathName();
		finds.filenaem = filename;

	}	
	if (saves.DoModal() == IDOK && nodata())
	{
		if (filename == "")MessageBox("请选择保存的文件名");
		else {
			CFile file;
			file.Open(filename, file.modeWrite | file.modeCreate);
			
			for (UINT i = 0; i < m_line; i++)
			{			
				for (UINT j = 0; j < 8; j++)
				{
					CString s = m_list.GetItemText(i, j);
					int strLength2 = s.GetLength() + 1;
					char chArray[20];
					memset(chArray, 0, sizeof(chArray) ); //将数组的垃圾内容清空.
					strncpy_s(chArray, s, strLength2);

					file.Write(chArray, sizeof(chArray));
				}
			}
			MessageBox("数据存储成功");
			file.Close();
		}
	}
	if (!nodata())
	{
		MessageBox("列表中没有数据,请先添加");
	}
	check = TRUE;
}
//——————————————————————————————————————查找————————————————————————————————
void management::reset(UINT i)//把查找的同学原来的行数传过来，将其插入第一行，达到查找效果
{
	
	CString AID = m_list.GetItemText(i, 0);
	CString Aname = m_list.GetItemText(i, 1);
	CString Axing = m_list.GetItemText(i, 2);
	CString Agrade = m_list.GetItemText(i, 3);
	CString Aclasss = m_list.GetItemText(i, 4);
	CString Aprogram = m_list.GetItemText(i, 5);
	CString Amath = m_list.GetItemText(i, 6);
	CString Alishan = m_list.GetItemText(i, 7);
	m_list.DeleteItem(i);
	m_list.InsertItem(0, AID);
	m_list.SetItemText(0, 1, Aname);
	m_list.SetItemText(0, 2, Axing);
	m_list.SetItemText(0, 3, Agrade);
	m_list.SetItemText(0, 4, Aclasss);
	m_list.SetItemText(0, 5, Aprogram);
	m_list.SetItemText(0, 6, Amath);
	m_list.SetItemText(0, 7, Alishan);
	m_list.SetItemData(0, COLOR_RED);   // 给该行设置背景颜色和字体颜色使得更加突出
	
}

void management::find_q()//查找某学号或某名字的学生的信息
{
		if (finds.a == 0 && finds.b != "")
	{
		
		CString connstr;//数据库连接语句
		connstr = "driver={SQL Server};server=DESKTOP-EKLE056\\SQLEXPRESS;Initial Catalog=db1";//为SQL Server服务器名称，Version为在SQL Server中建立的一个空的数据库名称
		try
		{
			//打开数据库
			m_pConnection->Open(_bstr_t(connstr), "", "", adConnectUnspecified);
			AfxMessageBox("数据库连接成功！");
		}
		catch (_com_error e)//捕捉异常
		{
			AfxMessageBox("数据库连接失败!");
			AfxMessageBox(e.ErrorMessage());
			if (m_pConnection->State)
			{
				m_pConnection->Close();
				m_pConnection = NULL;
			}//若连接失败，则释放该指针
		}
		CString strsql = TEXT("select * from 选修名单统计 where 姓名 like '%" + finds.b + "%'");
		//CString strsql = "select * from 选修名单统计 where 姓名 like '%" + finds.b + "%'";
		//strsql.Format("select * from 选修名单统计 where 姓名 like ‘%s%'", finds.b);
		pRecordset = m_pConnection->Execute(_bstr_t(strsql), NULL, adCmdText);//将查询结果导入pRecordset数据容器

		//遍历并读取sname列的记录并输出

		for (UINT i = 0; i < m_line; i++)
		{
			CString s = m_list.GetItemText(i, 2);
			if (s == (TCHAR*)(_bstr_t)pRecordset->GetFields()->GetItem("姓名")->Value)
			{
				reset(i);
				pRecordset->MoveNext();
				
				judge = TRUE;
				
				if(pRecordset->adoEOF) break;
			}
			
		}
		finds.b = "";
		if (judge == FALSE)
			MessageBox("没有此姓名的学生");
		else MessageBox("查找成功");
	}
	else if (finds.a == 1 && finds.b != "")
	{
		for (UINT i = 0; i < m_line; i++)
		{
			CString s = m_list.GetItemText(i, 1);
			if (finds.b == s)
			{
				reset(i);
				finds.b = "";
				judge = TRUE;
				MessageBox("查找成功");
				break;
			}
		}
		if (judge == FALSE)
			MessageBox("没有此学号的学生");
	}
	else
	{
		MessageBox("请输入一项数据删除");
	}


}
void management::OnBnClickedButton4()//查找按钮相应函数
{
	if (!nodata())
	{
		MessageBox("列表中没有数据~");
	}
	while (nodata())
	{
		if (finds.DoModal() == IDOK)
		{
			m_list.SetItemData(0, COLOR_DEFAULT);
			find_q();
		}
		if (finds.FA == TRUE)
		{
			finds.FA = FALSE;
			break;
		}
	}

}
void management::OnCustomdrawList2(NMHDR *pNMHDR, LRESULT *pResult)                //这个用于查找时候把提到第一行的学生信息标红
{
	LPNMTVCUSTOMDRAW pNMCD = reinterpret_cast<LPNMTVCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	NMCUSTOMDRAW nmCustomDraw = pNMCD->nmcd;
	switch (nmCustomDraw.dwDrawStage)
	{
	case CDDS_ITEMPREPAINT:
	{
		if (COLOR_RED == nmCustomDraw.lItemlParam)
		{
			pNMCD->clrTextBk = RGB(255, 0, 0);		 //背景颜色
			pNMCD->clrText = RGB(255, 255, 255);		//文字颜色
		}
		else if (COLOR_DEFAULT == nmCustomDraw.lItemlParam)
		{
			pNMCD->clrTextBk = RGB(255, 255, 255);
			pNMCD->clrText = RGB(0, 0, 0);
		}
		break;
	}
	default:
	{
		break;
	}
	}
	*pResult = 0;
	*pResult |= CDRF_NOTIFYPOSTPAINT;
	*pResult |= CDRF_NOTIFYITEMDRAW;
	return;

}

//——————————————————————————————————————导入————————————————————————————————
void management::OnBnClickedButton5()//导入按钮响应函数
{
	kedaimport dlg;
	if (dlg.DoModal() == IDOK && dlg.FA == FALSE)
	{
		importtt();
	}
	else if (dlg.FA == TRUE)
		{
			dlg.FA = FALSE;
			int line = m_list.GetItemCount();
			for (int i = 0; i < line; i++)
			{
				m_list.DeleteItem(0);
				m_line--;
			}
			m_stusum = m_line;
			UpdateData(FALSE);
			importtt();
		}
}

void management::importtt()//获得需要导入的学生信息的文件的地址
{
	MessageBox("请导入学生信息!");
	//CFileDialog filedlg(TRUE);
	//filedlg.m_ofn.lpstrTitle = "请选择文件并导入";
	//filedlg.m_ofn.lpstrFilter = "所有文件(*.*)\0*.*\0\0";
	//if (IDOK == filedlg.DoModal())
	//{
	//	finds.filenaem = filedlg.GetPathName();
	//	//UINT num = importt();
	//	if (num == 0)
	//		MessageBox("导入信息成功");	
	//}
}

UINT management::importt(CString s)//真正的导入函数主体，管理系统主菜单初始化时就调用了该函数，使得一开始就有了25个学生信息
{

	
	CString connstr;//数据库连接语句
	connstr = "driver={SQL Server};server=DESKTOP-EKLE056\\SQLEXPRESS;Initial Catalog=db1";//为SQL Server服务器名称，Version为在SQL Server中建立的一个空的数据库名称
	try
	{
		//打开数据库
		m_pConnection->Open(_bstr_t(connstr), "", "", adConnectUnspecified);
		AfxMessageBox("数据库连接成功！");
	}
	catch (_com_error e)//捕捉异常
	{
		AfxMessageBox("数据库连接失败!");
		AfxMessageBox(e.ErrorMessage());
		if (m_pConnection->State)
		{
			m_pConnection->Close();
			m_pConnection = NULL;
		}//若连接失败，则释放该指针
	}

	//查询
	CString strsql = TEXT("select * from 选修名单统计 where 系所="+s);
	//CString strsql = TEXT("select * from 选修名单统计 where 姓名 like '%" + finds.b + "%'");
	try {
		pRecordset = m_pConnection->Execute(_bstr_t(strsql), NULL, adCmdText);
	}//将查询结果导入pRecordset数据容器
	catch (_com_error e)//捕捉异常
	{
		AfxMessageBox("查询失败!");
		AfxMessageBox(e.ErrorMessage());
		if (m_pConnection->State)
		{
			m_pConnection->Close();
			m_pConnection = NULL;
		}//若连接失败，则释放该指针
	}

	//遍历并读取sname列的记录并输出
	while (!pRecordset->adoEOF)
	{
		CString temp = (TCHAR*)(_bstr_t)pRecordset->GetFields()->GetItem("系所")->Value;
		if (temp == '8') temp = "信息科学技术学院";
		if (temp == '3') temp = "机械电子工程学院";

		m_list.InsertItem(m_line, (TCHAR*)(_bstr_t)pRecordset->GetFields()->GetItem("序号")->Value);
		m_list.SetItemText(m_line, 1, (TCHAR*)(_bstr_t)pRecordset->GetFields()->GetItem("学号")->Value);
		m_list.SetItemText(m_line, 2, (TCHAR*)(_bstr_t)pRecordset->GetFields()->GetItem("姓名")->Value);
		m_list.SetItemText(m_line, 3, temp);
		m_list.SetItemText(m_line, 4, (TCHAR*)(_bstr_t)pRecordset->GetFields()->GetItem("学位课")->Value);
		m_list.SetItemText(m_line, 5, (TCHAR*)(_bstr_t)pRecordset->GetFields()->GetItem("选课时间")->Value);
		m_list.SetItemText(m_line, 6, (TCHAR*)(_bstr_t)pRecordset->GetFields()->GetItem("手机号")->Value);
		m_line++;

		pRecordset->MoveNext();
	}
	m_stusum = m_line;
	UpdateData(FALSE);
	m_pConnection->Close();

	return 0;
}
	


//——————————————————————————————————————修改————————————————————————————————



BOOL management::checknum()//检查成绩是否超出范围
{
	if (changes.new_program > 100 || changes.new_math > 100 || changes.new_lishan > 100)
	{
		MessageBox("成绩输入不合法");
		return FALSE;
	}
	return TRUE;
}


void management::settext(int line)//将新的信息显示出表格里面，没有填的就跳过，只会更新新的信息
{		
	char c[20] = "0";
	char c1[5], c2[5], c3[5];
	_itoa_s(changes.new_program, c1, 10);
	_itoa_s(changes.new_math, c2, 10);
	_itoa_s(changes.new_lishan, c3, 10);
	if (changes.new_number != 0)
	{
		_itoa_s(changes.new_number, c, 10);
		m_list.SetItemText(line, 0, c);
	}
	if(changes.new_grade!="")
	m_list.SetItemText(line, 3, changes.new_grade);
	if (changes.new_class != "")
	m_list.SetItemText(line, 4, changes.new_class);
	if (checknum())
	{
		m_list.SetItemText(line, 5, c1);
		m_list.SetItemText(line, 6, c2);
		m_list.SetItemText(line, 7, c3);
	}
}

void management::findcheck()//个人信息修改函数
{

	BOOL f = FALSE;
	if (changes.name != "")
	{
		for (UINT i = 0; i < m_line; i++)
		{
			if (changes.name == m_list.GetItemText(i, 1))
			{
				settext(i);
				f = TRUE;
			}
			if (f)
			{
				MessageBox("成功修改");
				break;
			}
		}
		if (!f)
		{
			MessageBox("查找的人名字可能不符,请检查");
		}
	}
	else {
		MessageBox("请输入修改同学的新旧姓名");
	}
}

void management::changename()//只修改名字
{
	BOOL f = FALSE;
	for (UINT i = 0; i < m_line; i++)
	{
		if (changes.old_name == m_list.GetItemText(i, 1))
		{
			m_list.SetItemText(i, 1, changes.new_name);
			f = TRUE;
		}
		if (f)
		{
			MessageBox("成功修改");
			break;
		}	
	}	
}


void management::OnBnClickedButton6()//修改按钮相应函数
{
	// TODO: 在此添加控件通知处理程序代码

	while (nodata())
	{
		changes.old_name = "";
		changes.new_name = "";
		changes.new_number = 0;
		changes.new_program = 0;
		changes.new_math = 0;
		changes.new_lishan = 0;
		changes.new_class = "";
		changes.new_grade = "";

		if (changes.DoModal() == IDOK)
		{
			UpdateData(TRUE);
			if (changes.cao == 0 && changes.old_name != "")
			{
				changename();
			}
			else if (changes.cao == 1 && changes.name != "")
			{
				findcheck();
			}
			else
			{
				MessageBox("请输入该学生的姓名");
			}			
		}
		if (changes.FA == TRUE )
		{
			deletes.FA = FALSE;
			break;
		}
		
	}
	if (!nodata())
	{
		MessageBox("信息为空,请先添加信息");
	}
}

//—————————————————————————————————————排序————————————————————————————————


BOOL  cmp(point pt1, point pt2)   //利用快排函数sort()的时候会用到,升序
{
	return pt1.y < pt2.y;
}

BOOL  ccmp(point pt1, point pt2)   //利用快排函数sort()的时候会用到，降序
{
	return pt1.y > pt2.y;
}

void management::resort(UINT x)   //排序函数
{
	point *keda = new point[m_line];                  //建立动态数组

	for (UINT i = 0; i < m_line; i++)
	{
		CString a = m_list.GetItemText(i, x);
		UINT AA = _ttoi(a);
		keda[i].x = i;
		keda[i].y = AA;
	}
	if(x==0)
		sort(keda, keda + m_line, cmp);           //快排
	else 
		sort(keda, keda + m_line, ccmp);

	for (int i = 0; i < m_line; i++)
	{
		CString a = m_list.GetItemText(keda[i].x, 0);
		m_list.InsertItem(i+m_line, a);
		for (UINT j = 1; j < 8; j++)
		{
			CString a = m_list.GetItemText(keda[i].x, j);
			m_list.SetItemText(i + m_line, j, a);
		}
	}
	for (int i = 0; i <m_line; i++)
	{
		m_list.DeleteItem(0);
	}
	delete []keda;                             //防止内存泄露
}


void management::OnBnClickedButton7()
{
	if (!nodata())
	{
		MessageBox("信息为空,请先添加信息");
	}
	else resort(0);
}

//——————————————————————————————————————退出————————————————————————————————————

void management::OnBnClickedButton8()
{
	if (MessageBox("请确认保存学生信息再退出！", "警告",MB_ICONEXCLAMATION | MB_OKCANCEL)==IDCANCEL)
	{
		CDialog::OnClose();
	}
	else 
	{
		CDialogEx::OnCancel();
	}
}



//————————————————————————————————————背景图片————————————————————————————————————


void management::OnPaint()                   //设置背景
{

	CPaintDC   dc(this);
	CRect   rect;
	GetClientRect(&rect);
	CDC   dcMem;
	dcMem.CreateCompatibleDC(&dc);
	CBitmap   bmpBackground;
	bmpBackground.LoadBitmap(IDB_BITMAP4);          		//IDB_BITMAP是我的背景图片对应的ID   
	BITMAP   bitmap;
	bmpBackground.GetBitmap(&bitmap);
	CBitmap   *pbmpOld = dcMem.SelectObject(&bmpBackground);
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
}



//———————————————————————————强大的额外删除功能————————————————————————————————————

void management::OnDblclkList2(NMHDR *pNMHDR, LRESULT *pResult)       //双击响应
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	CRect rc;             //矩形
	m_Row = pNMListView->iItem;
	m_Col = pNMListView->iSubItem;

	if (pNMListView->iSubItem != -1)   //在listcontrol和edit上操作
	{
		m_list.GetSubItemRect(m_Row, m_Col, LVIR_LABEL, rc);  //获取控件矩形区域
		m_edit.SetParent(&m_list);    //SetParent  就是把编辑框转到列表框里面
		m_edit.MoveWindow(rc);
		m_edit.SetWindowText(m_list.GetItemText(m_Row, m_Col));
		m_edit.ShowWindow(SW_SHOW);
		m_edit.SetFocus();
		m_edit.ShowCaret();   //使插入标记在屏幕的当前位置上可见
	}
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}

void management::OnKillfocusEdit2()               //失去焦点时响应
{
	CString tem;
	m_edit.GetWindowText(tem);   
	m_list.SetItemText(m_Row, m_Col, tem);  
	m_edit.ShowWindow(SW_HIDE);                
	// TODO: 在此添加控件通知处理程序代码
}


//———————————————————————————强大的额外排序功能————————————————————————————————————

void management::OnColumnclickList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);

	resort(pNMLV->iSubItem);

	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


//—————————————————————————————强大的其他功能————————————————————————————————————

void management::OnOK()              //重载函数OnOK,防止在修改信息时，不小心按了回车退出，就什么都不用加就行了
{
	
}







void management::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	int index = m_cbx.GetCurSel();

	CString str;
	m_cbx.GetLBText(index, str);
	if (str == "信息科学技术学院") str = '8';
	if (str == "机电院") str = '3';
	importt(str);
}

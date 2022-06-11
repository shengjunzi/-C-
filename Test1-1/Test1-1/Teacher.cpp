#include"Teacher.h"


Teacher::Teacher(int id, string name, string pwd)
{
	this->m_id = id;
	this->m_name = name;
	this->m_pwd = pwd;
}

void Teacher::openmenu()
{
	cout << "欢迎" << this->m_name << "老师登录！" << endl;
	cout << "\t\t--------------------------------" << endl;
    cout << "\t\t|\t1.查看所有预约记录          |" << endl;
	cout << "\t\t|\t2.审核预约记录              |" << endl;
	cout << "\t\t|\t0.退出                      |" << endl;
	cout << "\t\t|______________________________|" << endl;
}

void Teacher::fianAllOrder()
{
	ifstream ifs;
	ifs.open("orderfile.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败或预约记录为空" << endl;

	}
	string date;    // 日期
	string interval;//时间段
	string stuId;   //学生编号
	string stuName; //学生姓名
	string roomId;  //自习室编号
	string status;  //预约状态
	int i = 0;
	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		cout <<i+1<<"、"<< date << " " << interval << " " << stuId << " " << stuName << " " << roomId << " " << status << endl;
	}
	ifs.close();
}
void Teacher::ValidOrder()
{
	Order order;
	if (order.m_size == 0)
	{
		cout << "无预约记录" << endl;
		return;
	}
	cout << "所有待审核预约记录如下:" << endl;
	fianAllOrder();
	int choose ;
	int select;
	
	while (true)
	{
		cout << "请选择要审核的记录:(输入0退出审核！）" << endl;
        cin >> select;
		if (select > 0 && select <= order.m_size)
		{
			
			cout << "输入1表示通过，2表示不通过" << endl;
			cin >> choose;
			if (choose == 1)
			{
				order.m_order[select - 1]["状态"] = "通过";
			}
			else if (choose == 2)
			{
				order.m_order[select - 1]["状态"] = "不通过";
			}
			order.update();
		}
		else if (select == 0)
		{
			system("cls"); return;
		}
		
		
	}
}
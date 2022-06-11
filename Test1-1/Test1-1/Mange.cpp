#include"Mange.h"
using namespace std;

Mange::Mange(int id, string name, string pwd)
{
	this->m_id = id;
	this->m_name = name;
	this->m_pwd = pwd;
}
void Mange::openmenu()
{
	
	cout << "\t\t\t\t管理员界面\t\t\t\t" << endl;
	cout << "\t\t1.添加账户" << endl;
	cout << "\t\t2.清空预约信息" << endl;
	cout << "\t\t3.查看所有账户" << endl;
	cout << "\t\t0.退出登录" << endl;
	
}
void Mange::Addmount()
{
	while (true)
	{
		cout << "请输入要添加的账户类型:" << endl;
		cout << "\t1.学生" << endl;
		cout << "\t2.教师" << endl;
		int select = 0;
		string filename;
		string tip;
		string errortip;
		ofstream ofs;
		cin >> select;
		if (select == 1)
		{
			filename = "Student.txt";
			tip = "请输入学号：";
			errortip = "学号重复，请重新输入：";
		}
		else if (select == 2)
		{
			filename = "Teacher.txt";
			tip = "请输入教师号：";
			errortip = "教师号重复，请重新输入：";
		}
		else
		{
			cout << "输入错误，请重新输入！" << endl;
			break;
		}
		int id = 0;
		string name;
		string pwd;
		ofs.open(filename, ios::out | ios::app);
		cout << tip << endl;
		while (true)
		{
			cin >> id;
			bool ret = checkRepeat(id, select);
			if (ret) cout << errortip << endl;
			else break;
		}
		cout << "请输入姓名：" << endl;
		cin >> name;
		cout << "请输入密码：" << endl;
		cin >> pwd;

		ofs << id << " " << name << " " << pwd << endl;
		cout << "添加成功" << endl;
		cout << "请选择继续添加或者退出！" << endl;
		cout << "\t\t1.继续添加" << endl;
		cout << "\t\t2.退出" << endl;
		int choose = 0;
		cin >> choose;
		if (choose == 1) { ofs.close(); system("cls"); }
		else { ofs.close(); system("cls"); return; }

		this->initvector();
	}
}
void Mange::initvector()
{
	stu.clear();
	ter.clear();
	
	ifstream ifs;
	ifs.open("Student.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}
	Student s;
	while (ifs>>s.m_id&&ifs>>s.m_name&&ifs>>s.m_pwd)
	{
		stu.push_back(s);
	}
	ifs.close();

	ifs.open("Teacher.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_id && ifs >> t.m_name && ifs >> t.m_pwd)
	{
		ter.push_back(t);
	}
	ifs.close();
}
bool Mange::checkRepeat(int id,int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = stu.begin(); it != stu.end(); it++)
		{
			if (id == m_id) return true;
		}
	}
	else if (type == 2)
	{
		for (vector<Teacher>::iterator it = ter.begin(); it != ter.end(); it++)
		{
			if (id == m_id) return true;
		}
	}
}
void Mange::findMount()
{
	cout << "选择查看账户信息：" << endl;
	cout << "\t1.教师" << endl;
	cout << "\t2.学生" << endl;
	int select;
	cin >> select;
	int id = 0;
	string name;
	string pwd;
	string filename;
	ifstream ifs;
	if (select == 1)
	{
		filename="Teacher.txt";
		
	}
	else if (select == 2) {
		filename="Student.txt";
	}
	ifs.open(filename, ios::in);
	if (!ifs.is_open())
	{
		cout << "打开文件失败或账户未建立！" << endl;
		return;
	}
	while (ifs >> id && ifs >> name && ifs >> pwd)
	{
		cout << id << " " << name << " " << pwd << endl;
	}
	ifs.close();
	system("pause");
	system("cls");
}
void Mange::ClearOrder()
{
	remove("orderfile.txt");
	cout << "预约记录已删除" << endl;
	system("pauese");
	system("cls");
}
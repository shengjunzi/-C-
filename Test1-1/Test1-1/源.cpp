#include<fstream>

#include"Student.h"
#include"Teacher.h"
#include"Mange.h"
#include"Identify.h"
using namespace std;




void Studenmenu(Identify*& student)
{
	while (true)
	{
		student->openmenu();
		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;
		if (select == 1) { stu->ApplyOrder(); }
		else if (select == 2) { stu->ShowOrder(); }
		else if (select == 3) { stu->CanclOrder(); }
		else {
			delete stu;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;

		}
	}
}

void Teachermenu(Identify* teacher)
{
	while (true)
	{
		teacher->openmenu();
		Teacher* teachers = (Teacher*)teacher;
		int select = 0;
		cout << "请选择功能:" << endl;
		cin >> select;
		if (select == 1) { teachers->fianAllOrder(); }
		else if (select == 2) { teachers->ValidOrder(); }
		else {
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;

		}

	}
}

void Mangemenu(Identify* mange)
{
	while (true)
	{
		mange->openmenu();
		Mange* manges = (Mange*)mange;
		int select = 0;
		cout << "请选择功能：" << endl;
		cin >> select;
		if (select == 1) { manges->Addmount(); }
		else if (select == 2) { manges->ClearOrder(); }
		else if (select == 3) { manges->findMount(); }
		else {
			delete mange;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;

		}

	}
	

}

void LoginIn(const string filename,int type)
{

	Identify* person = NULL;     //父类指针指向子类对象
	ifstream ifs;
	
	ifs.open(filename, ios::in);
	if (!ifs.is_open())
	{
		cout << "账户信息为空，请管理员添加账户信息" << endl;
		ifs.close();
		system("pause");
		system("cls");
		return;
	}
	int id = 0;
	string name;
	string pwd;
	 if (type == 1)
	{
		cout << "请输入学号:" << endl;
		cin >> id;
	}
	 else if (type == 2)
	 {
		 cout << "请输入教师号：" << endl;
		 cin >> id;
	 }
	 else if (type == 3)
	 {
		 cout << "请输入管理员账号:" << endl;
		 cin >> id;
	 }
	 cout << "请输入姓名：" << endl;
	 cin >> name;
	 cout << "请输入密码：" << endl;
	 cin >> pwd;
	 if (type == 1)
	 {
		 int f_id;
		 string f_name;
		 string f_pwd;
		 while (ifs >> f_id && ifs >> f_name && ifs >> f_pwd)
		 {
			 if (f_id == id && f_pwd == pwd&&f_name==name)
			 {
				 cout << "登录成功" << endl;
				 system("pause");
				 system("cls");
				 person = new Student(id, name, pwd);
				 Studenmenu(person);
			 }
		 }
	 }
	 else if (type == 2)
	 {
		 int f_id;
		 string f_name;
		 string f_pwd;
		 while (ifs >> f_id && ifs >> f_name && ifs >> f_pwd)
		 {
			 if (f_id == id && f_pwd == pwd)
			 {
				 cout << "登录成功" << endl;
				 system("pause");
				 system("cls");
				 person = new Teacher(id, name, pwd);
				 Teachermenu(person);
			 }

		 }
	 }
	 else if (type == 3)
	 {
		 int f_id;
		 string f_name;
		 string f_pwd;
		 while (ifs >> f_id && ifs >> f_name && ifs >> f_pwd)
		 {
			 if (f_id == id && f_pwd == pwd)
			 {
				 cout << "登录成功" << endl;
				 system("pause");
				 system("cls");
				 person = new Mange(id, name, pwd);
				Mangemenu(person);
			 }

		 }
	 }
}

int main()
{
	int select = 0;
	while (true)
	{
		cout << "\t\t ———————————————- " << endl;
		cout << "\t\t|    欢迎使用考试答题系统       |\t\t" << endl;
		cout << "\t\t|                               |\t\t" << endl;
		cout << "\t\t|       1. 学生账户             |\t\t" << endl;
		cout << "\t\t|       2. 教师账户             |\t\t" << endl;
		cout << "\t\t|       3. 管理员账户           |\t\t" << endl;
		cout << "\t\t|       0. 退出系统             |\t\t" << endl;
		cout << "\t\t|_______________________________|" << endl;

		cout << "请选择账户身份：" << endl;
		cin >> select;
		switch (select)
		{
		case 1: LoginIn( "student.txt",1);
			break;
		case 2: LoginIn("Teacher.txt", 2);
			break;
		case 3: LoginIn("Mange.txt", 3);
			break;
		case 0: 
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新输入信息！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

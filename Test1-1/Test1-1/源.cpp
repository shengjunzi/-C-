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
			cout << "ע���ɹ�" << endl;
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
		cout << "��ѡ����:" << endl;
		cin >> select;
		if (select == 1) { teachers->fianAllOrder(); }
		else if (select == 2) { teachers->ValidOrder(); }
		else {
			delete teacher;
			cout << "ע���ɹ�" << endl;
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
		cout << "��ѡ���ܣ�" << endl;
		cin >> select;
		if (select == 1) { manges->Addmount(); }
		else if (select == 2) { manges->ClearOrder(); }
		else if (select == 3) { manges->findMount(); }
		else {
			delete mange;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;

		}

	}
	

}

void LoginIn(const string filename,int type)
{

	Identify* person = NULL;     //����ָ��ָ���������
	ifstream ifs;
	
	ifs.open(filename, ios::in);
	if (!ifs.is_open())
	{
		cout << "�˻���ϢΪ�գ������Ա����˻���Ϣ" << endl;
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
		cout << "������ѧ��:" << endl;
		cin >> id;
	}
	 else if (type == 2)
	 {
		 cout << "�������ʦ�ţ�" << endl;
		 cin >> id;
	 }
	 else if (type == 3)
	 {
		 cout << "���������Ա�˺�:" << endl;
		 cin >> id;
	 }
	 cout << "������������" << endl;
	 cin >> name;
	 cout << "���������룺" << endl;
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
				 cout << "��¼�ɹ�" << endl;
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
				 cout << "��¼�ɹ�" << endl;
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
				 cout << "��¼�ɹ�" << endl;
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
		cout << "\t\t ������������������������������- " << endl;
		cout << "\t\t|    ��ӭʹ�ÿ��Դ���ϵͳ       |\t\t" << endl;
		cout << "\t\t|                               |\t\t" << endl;
		cout << "\t\t|       1. ѧ���˻�             |\t\t" << endl;
		cout << "\t\t|       2. ��ʦ�˻�             |\t\t" << endl;
		cout << "\t\t|       3. ����Ա�˻�           |\t\t" << endl;
		cout << "\t\t|       0. �˳�ϵͳ             |\t\t" << endl;
		cout << "\t\t|_______________________________|" << endl;

		cout << "��ѡ���˻���ݣ�" << endl;
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
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������������Ϣ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

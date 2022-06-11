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
	
	cout << "\t\t\t\t����Ա����\t\t\t\t" << endl;
	cout << "\t\t1.����˻�" << endl;
	cout << "\t\t2.���ԤԼ��Ϣ" << endl;
	cout << "\t\t3.�鿴�����˻�" << endl;
	cout << "\t\t0.�˳���¼" << endl;
	
}
void Mange::Addmount()
{
	while (true)
	{
		cout << "������Ҫ��ӵ��˻�����:" << endl;
		cout << "\t1.ѧ��" << endl;
		cout << "\t2.��ʦ" << endl;
		int select = 0;
		string filename;
		string tip;
		string errortip;
		ofstream ofs;
		cin >> select;
		if (select == 1)
		{
			filename = "Student.txt";
			tip = "������ѧ�ţ�";
			errortip = "ѧ���ظ������������룺";
		}
		else if (select == 2)
		{
			filename = "Teacher.txt";
			tip = "�������ʦ�ţ�";
			errortip = "��ʦ���ظ������������룺";
		}
		else
		{
			cout << "����������������룡" << endl;
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
		cout << "������������" << endl;
		cin >> name;
		cout << "���������룺" << endl;
		cin >> pwd;

		ofs << id << " " << name << " " << pwd << endl;
		cout << "��ӳɹ�" << endl;
		cout << "��ѡ�������ӻ����˳���" << endl;
		cout << "\t\t1.�������" << endl;
		cout << "\t\t2.�˳�" << endl;
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
		cout << "�ļ���ȡʧ��" << endl;
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
		cout << "�ļ���ȡʧ��" << endl;
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
	cout << "ѡ��鿴�˻���Ϣ��" << endl;
	cout << "\t1.��ʦ" << endl;
	cout << "\t2.ѧ��" << endl;
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
		cout << "���ļ�ʧ�ܻ��˻�δ������" << endl;
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
	cout << "ԤԼ��¼��ɾ��" << endl;
	system("pauese");
	system("cls");
}
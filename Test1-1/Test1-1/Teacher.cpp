#include"Teacher.h"


Teacher::Teacher(int id, string name, string pwd)
{
	this->m_id = id;
	this->m_name = name;
	this->m_pwd = pwd;
}

void Teacher::openmenu()
{
	cout << "��ӭ" << this->m_name << "��ʦ��¼��" << endl;
	cout << "\t\t--------------------------------" << endl;
    cout << "\t\t|\t1.�鿴����ԤԼ��¼          |" << endl;
	cout << "\t\t|\t2.���ԤԼ��¼              |" << endl;
	cout << "\t\t|\t0.�˳�                      |" << endl;
	cout << "\t\t|______________________________|" << endl;
}

void Teacher::fianAllOrder()
{
	ifstream ifs;
	ifs.open("orderfile.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܻ�ԤԼ��¼Ϊ��" << endl;

	}
	string date;    // ����
	string interval;//ʱ���
	string stuId;   //ѧ�����
	string stuName; //ѧ������
	string roomId;  //��ϰ�ұ��
	string status;  //ԤԼ״̬
	int i = 0;
	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		cout <<i+1<<"��"<< date << " " << interval << " " << stuId << " " << stuName << " " << roomId << " " << status << endl;
	}
	ifs.close();
}
void Teacher::ValidOrder()
{
	Order order;
	if (order.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		return;
	}
	cout << "���д����ԤԼ��¼����:" << endl;
	fianAllOrder();
	int choose ;
	int select;
	
	while (true)
	{
		cout << "��ѡ��Ҫ��˵ļ�¼:(����0�˳���ˣ���" << endl;
        cin >> select;
		if (select > 0 && select <= order.m_size)
		{
			
			cout << "����1��ʾͨ����2��ʾ��ͨ��" << endl;
			cin >> choose;
			if (choose == 1)
			{
				order.m_order[select - 1]["״̬"] = "ͨ��";
			}
			else if (choose == 2)
			{
				order.m_order[select - 1]["״̬"] = "��ͨ��";
			}
			order.update();
		}
		else if (select == 0)
		{
			system("cls"); return;
		}
		
		
	}
}
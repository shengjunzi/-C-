#include"Student.h"
#include <time.h> 

Student::Student(int id, string name, string pwd)
{
	this->m_id = id;
	this->m_name = name;
	this->m_pwd = pwd;
	ifstream ifs;
	ifs.open("room.txt", ios::in);
	Room room;
	while (ifs>>room.room_id&&ifs>>room.room_size)
	{
		rooms.push_back(room);
	}
}

void Student::openmenu()
{
	cout << "���ã���ӭ" << this->m_name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
    cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.��ʼ����              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.�鿴����              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          3.��������              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.�˳���¼              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;

}

void Student::ApplyOrder()
{
	system("cls");
	cout << "\t\t\t��ʼ����" << endl;
	string filename;
	ofstream ofs;
	filename = "room.txt";
	ofs.open(filename, ios::out | ios::app);

	this->count = 0;
	
	int add_item = 0;  //�Ӽ��˳�����
	int sub_item = 0;
	int mul_item = 0;
	int div_item = 0;
	int x, y, result;  //����x,y;���result
	srand((unsigned)time(NULL));   //ʹ��ʱ�亯����������

	while (1)
	{
		         //�ж��Ƿ���ִ���
		x = rand() % 101;     //�������[0,100]�������x,y
		y = rand() % 101;
	


		if ((x + y) <= 100 && add_item < 7) {   //��֤�ӽ��������100���ҳ��ּ��������
			cout << "��" << add_item + 1 << "���ӷ���:" << x << "+" << y << "=" << endl;
			add_item++;
			cout << "�������:";
			cin >> result;                  //������
			if (result == x + y) {            //�����ȷ
				this->count++;
			}
			else {                          //������󣬴�������
				
				ofs << x << "+" << y << "=" << endl;
				//cout << "����" << endl;
				//flag = 1;
				continue;
			}
			
		}
		if ((x - y) >= 0 && sub_item < 8) {    //��֤���������0���ҳ��ּ��������
			cout << "��" << sub_item + 1 << "��������:" << x << "-" << y << "=" << endl;
			sub_item++;
			cout << "������𰸣�";
			cin >> result;                 //ͬ��
			if (result == x - y) {
				this->count++;
			}
			else {
				ofs << x << "-" << y << "=" << endl;
				continue;
			}
			
		}
		if ((x * y) <= 100 && mul_item < 7) {  //��֤�˽��������100���ҳ��ֳ��������
			cout << "��" << mul_item + 1 << "���˷���:" << x << "*" << y << "=" << endl;
			mul_item++;
			cout << "�������:";
			cin >> result;                 //ͬ��
			if (result == x * y) {
				this->count++;
			}
			else {
				ofs << x << "*" << y << "=" << endl;
				continue;
			}
			
		}
		if (y > 0 && y < 10) {               //��֤������[1,9]����������
			if ((x % y) == 0) {
				cout << "��" << div_item + 1 << "��������:" << x << "/" << y << "=" << endl;
				div_item++;
				cout << "�������:";
				cin >> result;             //ͬ��
				if (result == x / y) {
					this->count++;
				}
				else {
					ofs << x << "/" << y << "=" << endl;
					continue;
				}
				
			}
		}

		if (add_item + sub_item + mul_item + div_item == 30) {//��֤30��
			cout << "30�����,�ӷ���:"<<add_item<<" ������:"<<sub_item<<" �˷���:"<<mul_item<<" �����⣺"<<div_item<< endl;
			break;
		}
	}
	ofs.close();
	system("pause");
	system("pause");
	system("cls");

}

void Student::ShowOrder()
{
    
	cout <<this->m_name<< "ͬѧ����Ϊ:" << this->count;
	system("pause");
	system("cls");
}

void Student::CanclOrder()
{
	string filename;
	ifstream ifs;

	
	filename = "room.txt";
	ifs.open(filename, ios::in);
	string line;

	if (ifs) // �и��ļ�
	{
		while (getline(ifs, line)) // line�в�����ÿ�еĻ��з�
		{
			cout << line << endl;
		}
	}
	else // û�и��ļ�
	{
		cout << "no such file" << endl;
	}
	ifs.close();

}

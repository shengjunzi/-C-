#include"orderfile.h"

Order::Order()
{
	ifstream ifs;
	ifs.open("orderfile.txt", ios::in);
	string date;    // ����
	string interval;//ʱ���
	string stuId;   //ѧ�����
	string stuName; //ѧ������
	string roomId;  //��ϰ�ұ��
	string status;  //ԤԼ״̬

	this->m_size = 0;
	while (ifs >> date && ifs >> interval &&ifs>>stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		string key;
		string value;
		map<string, string>m;
		int pos = date.find(":");
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = stuId.find(":");
		if (pos != -1)
		{
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = stuName.find(":");
		if (pos != -1)
		{
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = roomId.find(":");
		if (pos != -1)
		{
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		m_order.insert(make_pair(this->m_size, m));
		this->m_size++;
	}
	ifs.close();
}
void Order::update()
{
	if (this->m_size == 0)
	{
		cout << "ԤԼ��¼Ϊ��" << endl;
		return;
	}
	ofstream ofs("orderfile.txt", ios::out | ios::trunc);
	for (int i = 0; i < this->m_size; i++)
	{
		ofs << "����:" << this->m_order[i]["����"]<< " ";
		ofs << "ʱ���:" <<this->m_order[i]["ʱ���"] << " ";
		ofs << "��ϰ�Һ�:" << this->m_order[i]["��ϰ�Һ�"]<< " ";
		ofs << "ѧ��:" <<this->m_order[i]["ѧ��"]<< " ";
		ofs << "����:" << this->m_order[i]["����"] << " ";
		ofs << "״̬:" << this->m_order[i]["״̬"] << endl;

	}
	ofs.close();
}
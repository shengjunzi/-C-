#include"orderfile.h"

Order::Order()
{
	ifstream ifs;
	ifs.open("orderfile.txt", ios::in);
	string date;    // 日期
	string interval;//时间段
	string stuId;   //学生编号
	string stuName; //学生姓名
	string roomId;  //自习室编号
	string status;  //预约状态

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
		cout << "预约记录为空" << endl;
		return;
	}
	ofstream ofs("orderfile.txt", ios::out | ios::trunc);
	for (int i = 0; i < this->m_size; i++)
	{
		ofs << "日期:" << this->m_order[i]["日期"]<< " ";
		ofs << "时间段:" <<this->m_order[i]["时间段"] << " ";
		ofs << "自习室号:" << this->m_order[i]["自习室号"]<< " ";
		ofs << "学号:" <<this->m_order[i]["学号"]<< " ";
		ofs << "姓名:" << this->m_order[i]["姓名"] << " ";
		ofs << "状态:" << this->m_order[i]["状态"] << endl;

	}
	ofs.close();
}
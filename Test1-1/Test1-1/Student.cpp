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
	cout << "您好！欢迎" << this->m_name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
    cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.开始答题              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.查看分数              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          3.导出错题              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.退出登录              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;

}

void Student::ApplyOrder()
{
	system("cls");
	cout << "\t\t\t开始答题" << endl;
	string filename;
	ofstream ofs;
	filename = "room.txt";
	ofs.open(filename, ios::out | ios::app);

	this->count = 0;
	
	int add_item = 0;  //加减乘除题数
	int sub_item = 0;
	int mul_item = 0;
	int div_item = 0;
	int x, y, result;  //变量x,y;结果result
	srand((unsigned)time(NULL));   //使用时间函数生成种子

	while (1)
	{
		         //判断是否出现错题
		x = rand() % 101;     //随机生成[0,100]区间的数x,y
		y = rand() % 101;
	


		if ((x + y) <= 100 && add_item < 7) {   //保证加结果不大于100，且出现加运算均匀
			cout << "第" << add_item + 1 << "道加法题:" << x << "+" << y << "=" << endl;
			add_item++;
			cout << "请输入答案:";
			cin >> result;                  //输入结果
			if (result == x + y) {            //结果正确
				this->count++;
			}
			else {                          //结果错误，错题重现
				
				ofs << x << "+" << y << "=" << endl;
				//cout << "错误！" << endl;
				//flag = 1;
				continue;
			}
			
		}
		if ((x - y) >= 0 && sub_item < 8) {    //保证减结果大于0，且出现减运算均匀
			cout << "第" << sub_item + 1 << "道减法题:" << x << "-" << y << "=" << endl;
			sub_item++;
			cout << "请输入答案：";
			cin >> result;                 //同上
			if (result == x - y) {
				this->count++;
			}
			else {
				ofs << x << "-" << y << "=" << endl;
				continue;
			}
			
		}
		if ((x * y) <= 100 && mul_item < 7) {  //保证乘结果不大于100，且出现乘运算均匀
			cout << "第" << mul_item + 1 << "道乘法题:" << x << "*" << y << "=" << endl;
			mul_item++;
			cout << "请输入答案:";
			cin >> result;                 //同上
			if (result == x * y) {
				this->count++;
			}
			else {
				ofs << x << "*" << y << "=" << endl;
				continue;
			}
			
		}
		if (y > 0 && y < 10) {               //保证除数在[1,9]，且能整除
			if ((x % y) == 0) {
				cout << "第" << div_item + 1 << "道除法题:" << x << "/" << y << "=" << endl;
				div_item++;
				cout << "请输入答案:";
				cin >> result;             //同上
				if (result == x / y) {
					this->count++;
				}
				else {
					ofs << x << "/" << y << "=" << endl;
					continue;
				}
				
			}
		}

		if (add_item + sub_item + mul_item + div_item == 30) {//保证30题
			cout << "30题完成,加法题:"<<add_item<<" 减法题:"<<sub_item<<" 乘法题:"<<mul_item<<" 除法题："<<div_item<< endl;
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
    
	cout <<this->m_name<< "同学分数为:" << this->count;
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

	if (ifs) // 有该文件
	{
		while (getline(ifs, line)) // line中不包括每行的换行符
		{
			cout << line << endl;
		}
	}
	else // 没有该文件
	{
		cout << "no such file" << endl;
	}
	ifs.close();

}

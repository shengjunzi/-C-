#pragma once
#include<map>
#include<fstream>
#include<string>
#include<iostream>
using namespace std;
class Order {
public:
	Order();
	void update();
	int m_size;
	map<int, map<string, string>>m_order;

};

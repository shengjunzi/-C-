#pragma once
#include"Identify.h"
#include<iostream>
#include<fstream>
#include"orderfile.h"
using namespace std;
class Teacher :public Identify {

public:
	Teacher():m_id(0){}
	Teacher(int id, string name, string pwd);
	virtual void openmenu();
	void fianAllOrder();
	void ValidOrder();
    int m_id;
};
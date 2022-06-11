#pragma once
#include"Identify.h"
#include<iostream>
#include<vector>
#include<fstream>
#include"Student.h"
#include"Teacher.h"
#include<stdio.h>
using namespace std;
class Mange :public Identify {
public:
	Mange():m_id(0){}
	Mange(int id, string name, string pwd);
	virtual void openmenu();
	void Addmount();
	void ClearOrder();
	void initvector();
	bool checkRepeat(int id,int type);
	void findMount();
	vector<Student> stu;
	vector<Teacher>ter;
    int m_id;
};


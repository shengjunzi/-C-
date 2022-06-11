#pragma once
#include"Identify.h"
#include<iostream>
#include<vector>
#include"Computerroom.h"
#include<fstream>
#include"orderfile.h"
using namespace std;
class Student : public Identify {
public:
	Student():m_id(0){}
	Student(int id, string name, string pwd);
	virtual void openmenu();
	void ApplyOrder();
	void ShowOrder();
	void CanclOrder();
	void findRoom();
	int m_id;
	int count;
	vector<Room>rooms;

};

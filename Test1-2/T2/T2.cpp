// T2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	double x = 0,y = 0;
	double x_min = 0;
	double min = 1;

	for(int i=1; i < 10000; i++){    //确定精度为0.0001
		x = i * 0.0001;
		y = pow(x, 4) - 6*x + 1 - sin(x);   //方程
		if(abs(y) < min){            //找到最接近零点的值
			min = abs(y);
			x_min = x;               //取出解
		}
	}
	cout << "-----------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "一元方程求根问题 x^4-6x+1-sin(x)=0" << endl;
	cout << "（1）求出其近似解；" << endl;
	cout << "（2）若有精度要求，需解精确到0.0001；" << endl;
	cout << "-----------------------------------------------------------------------" << endl;

	cout << "求解结果：" << endl;
	cout << "\tx = "<< x_min << endl;    //打印结果
	cout << "\ty = "<< pow(x_min, 8) - 7*x_min + 1 - sin(x_min) << endl;
	cout << endl;

	system("pause");
}


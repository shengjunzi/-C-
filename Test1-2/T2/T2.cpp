// T2.cpp : �������̨Ӧ�ó������ڵ㡣
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

	for(int i=1; i < 10000; i++){    //ȷ������Ϊ0.0001
		x = i * 0.0001;
		y = pow(x, 4) - 6*x + 1 - sin(x);   //����
		if(abs(y) < min){            //�ҵ���ӽ�����ֵ
			min = abs(y);
			x_min = x;               //ȡ����
		}
	}
	cout << "-----------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "һԪ����������� x^4-6x+1-sin(x)=0" << endl;
	cout << "��1���������ƽ⣻" << endl;
	cout << "��2�����о���Ҫ����⾫ȷ��0.0001��" << endl;
	cout << "-----------------------------------------------------------------------" << endl;

	cout << "�������" << endl;
	cout << "\tx = "<< x_min << endl;    //��ӡ���
	cout << "\ty = "<< pow(x_min, 8) - 7*x_min + 1 - sin(x_min) << endl;
	cout << endl;

	system("pause");
}


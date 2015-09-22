// 01.RepeatOverload.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Number
{
	int data;
public:
	// new in �++ 11
	Number() = default; // default - ������ �������������� ����������� �� ���������
					   //           �������������� ������������
	                   // delete  - ��������� ������ ��� ������ ������� ������������
					   //           ���������. ������ �� ����� ����������
	Number(const Number&) = default;
	Number(int init)
	{
		data = init;
	}
	Number operator+(const Number& right)
	{
		Number res(this->data + right.data);
		return res;
	}
	Number& operator=(const Number& right) = default;
	/*{
		data = right.data;
		return *this;
	}*/

	Number& operator+=(const Number& right)
	{
		data += right.data;
		return *this;
	}
	void show()
	{
		cout << data << endl;
	}
};



int _tmain(int argc, _TCHAR* argv[])
{
	Number n1(10);  // ��� �������� ������� n1 ��������� ����������� � �����������
	Number n2 = n1; // ��� �������� ������� n2 ��������� ����������� �����������

	Number n3;     // ��� �������� ������� n3 ��������� ����������� �� ���������
	n3 = n1 + n2;
	n2 += n3;
	n3 = n2;
	n2.show();
	return 0;
}


// 04.OverrideAndFinal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

// ����� � C++11
class Base
{
public:
	virtual void foo()
	{

	}

	virtual void boo() final // ������ �� ����������
	{
		cout << "Final method" << endl;
	}
};

// ��������� ������������ ��� ������� final
class Derived final : public Base
{
public:
	virtual void foo() override // ����� ���������� ������ �������� �������
	{

	}
	//virtual void boo() override //  ������ ���������� ������ ���������� final � ������� ������
	//{}
};

//class SubDerived : public Derived
//{
//
//};

int main()
{
    return 0;
}


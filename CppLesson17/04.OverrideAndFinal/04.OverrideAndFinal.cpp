// 04.OverrideAndFinal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

// новое в C++11
class Base
{
public:
	virtual void foo()
	{

	}

	virtual void boo() final // запрет на перегрузку
	{
		cout << "Final method" << endl;
	}
};

// запрещено наследование при наличии final
class Derived final : public Base
{
public:
	virtual void foo() override // явная перегрузка метода базового каласса
	{

	}
	//virtual void boo() override //  запрет перегрузки метода укзананием final в базовом классе
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


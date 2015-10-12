// 05.StandartSmartPtr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <memory> // auto_ptr, unique_ptr, shared_ptr, weak_ptr
#include <iostream>
using namespace std;

void ex01()
{
	auto_ptr<int> pi(new int(10));
	cout << *pi << endl;
	
	auto_ptr<int> pj;
	pj = pi;
	cout << *pj << endl;
	cout << pi.get() << " " << pj.get() << endl;
	// cout << *pi << endl; ошибка на этапе выполнения т.к. pi = 0
}

void ex02()
{
	unique_ptr<int> pi(new int(10));
	cout << *pi << endl;

	unique_ptr<int> pj;
	//pj = pi;
	pj = move(pi); // перемещение данных из pi в pj
	cout << *pj << endl;
	cout << pi.get() << " " << pj.get() << endl;
}

int main()
{
	ex01();
	ex02();
    return 0;
}


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
	cout << pi.get() << endl;  // адрес исходных данных
	int* a = pi.release();
	cout << pi.get() << " a: " << a << endl;
	pi.reset(new int(15));
	cout << pi.get() << endl;	
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

void ex03()
{
	shared_ptr<int> sh(new int(100));
	shared_ptr<int> sh2 = sh;
	cout << *sh << endl;
	cout << *sh2 << endl;
	cout << sh.use_count() << endl;
}

int main()
{
	ex01();
	ex02();
	ex03();

    return 0;
}


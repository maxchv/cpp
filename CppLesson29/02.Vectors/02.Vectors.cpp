// 02.Vectors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <array>
using namespace std;

void ex01()
{
	vector<int> v = { 1, 2, 3, 4 };

	/*v.pop_back();
	v.pop_back();
	v.pop_back();
	v.pop_back();*/
	v.shrink_to_fit();
	cout << "size: " << v.size() << endl;
	cout << "cpacity: " << v.capacity() << endl;

	int * orig = v.data();
	for (int i = 0; i < v.size(); i++)
	{
		cout << orig[i] << endl;
	}
}

void ex02()
{
	array<int, 10> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	
	for (auto &item : arr)
	{
		cout << item << endl;
	}

}

int main()
{
	ex01();
	ex02();
    return 0;
}


// 01.Deque.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <deque>
using namespace std;

void ex00()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	int *cur = arr;			  //
	const int* end = arr + 5; //
	while(cur != end)
	{
		cout << *cur << endl;
		cur++;
	}
}

void ex01()
{
	// конструкторы и инициализаторы

	deque<int> d;
	d.assign(10, 5); // задание первым 10 элементам значения 5
	for (int i = 0; i < d.size(); i++)
	{
		//cout << d[i] << endl;
	}

	deque<int> d2(10, 100);// задание первым 10 элементам значения 100
	for (int i = 0; i < d2.size(); i++)
	{
		//cout << d2[i] << endl;
	}

	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	
	deque<int> d3(arr, arr + 10);
	for (int i = 0; i < d3.size() + 1; i++)
	{
		try {
			//cout << d3[i] << endl;
			cout << d3.at(i) << endl;
		}
		catch (out_of_range &ex)
		{
			cerr << "catch exception: " << ex.what() << endl;
		}
	}

	deque<int> d4;
	d4.assign(d3.begin(), d3.begin() + 5);
	for (int i = 0; i < d4.size(); i++)
	{
		try {			
			cout << d4.at(i) << endl;
		}
		catch (out_of_range &ex)
		{
			cerr << "catch exception: " << ex.what() << endl;
		}
	}
}

int main()
{
	//ex00();
	ex01();
    return 0;
}


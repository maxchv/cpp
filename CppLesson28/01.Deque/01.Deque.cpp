// 01.Deque.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <deque>
#include <string>
#include <sstream>
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
	// ������������ � ��������������

	deque<int> d;
	d.assign(10, 5); // ������� ������ 10 ��������� �������� 5
	for (int i = 0; i < d.size(); i++)
	{
		//cout << d[i] << endl;
	}

	deque<int> d2(10, 100);// ������� ������ 10 ��������� �������� 100
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

void ex02()
{
	// ������� ��������� �������
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	deque<int> d(arr, arr+10);

	deque<int>::iterator cur = d.begin(); // �������� ������ �������
	deque<int>::const_iterator end = d.cend(); // ����������� �������� ����� �������
	// ����� ������������������ �� ������ �� �����
	while (cur != end)
	{
		cout << *cur << " ";
		cur++;				
	}
	cout << endl;

	deque<int>::reverse_iterator rcur = d.rbegin(); // �������� ������ �������
	deque<int>::const_reverse_iterator rend = d.crend(); // ����������� �������� ����� �������
	// ����� ������������������ �� ����� � ������
	while (rcur != rend)
	{
		cout << *rcur << " ";
		rcur++;
	}
	cout << endl;
}

void ex03()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	deque<int> d(arr, arr + 10);

	for (deque<int>::iterator it = d.begin(); it != d.cend(); it++)
	{
		//cout << *it << endl;
	}

	// �������� ����� auto
	auto i = 1;
	auto dd = 3.14;

	for (auto it = d.rbegin(); it != d.crend(); it++)
	{
		//cout << *it << endl;
	}

	// ���� foreach
	for (auto item : d)
	{
		cout << item << endl;
	}

	for (auto item : arr)
	{
		cout << item << " ";
	}
}

void ex04()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	deque<int> d(arr, arr + 10);

	// ������� � ����� �������
	d.push_back(11);
	cout << "back: " << d.back() << endl;
	// ������� � ������ �������
	d.push_front(0);
	cout << "front: " << d.front() << endl;
	
	// ������� � �������� ������� ��������� ��������	
	d.insert(d.begin() + 5, 100);
	//0 1 2 3 4 100 5 6 7 8 9 10 11
	for (auto item : d)
	{
		cout << item << " ";
	}
	cout << endl;

	// ������� � �������� ������� ������ ������
	d.insert(d.begin() + 7, arr, arr+5);
	// 0 1 2 3 4 100 5 1 2 3 4 5 6 7 8 9 10 11
	for (auto item : d)
	{
		cout << item << " ";
	}
	cout << endl;

	// �������� ��������� �������
	d.erase(d.begin() + 5); // ��������� �������� ���������� ��������
	// 0 1 2 3 4 5 1 2 3 4 5 6 7 8 9 10 11
	for (auto item : d)
	{
		cout << item << " ";
	}
	cout << endl;

	auto start = d.begin() + 6;
	d.erase(start, start+5); // ��������� �������� ���������� ��������
	// 0 1 2 3 4 5 6 7 8 9 10 11
	for (auto item : d)
	{
		cout << item << " ";
	}
	cout << endl;
}

void ex05()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	deque<int> d(arr, arr + 10);
	
	d.resize(d.size() + 10, 0); // ��������� ������������� 10 ���������
	for (auto item : d)
	{
		cout << item << " ";
	}
	
	cout << endl;
	cout << "size: " << d.size() << endl;
	d.erase(d.begin(), d.end());
	cout << "size: " << d.size() << endl;
	d.push_front(10);
	d.shrink_to_fit();
}

class Gift
{
	string gift;
public:
	explicit Gift(string _gift): gift(_gift){} // ����������� � ������ ������ ������������ ������
	void show()
	{
		cout << gift << endl;
	}
};

void ex06()
{
	deque<Gift> gift_bag;
	
	//Gift g = string("gift"); // ������� ����� ������������ Gift
	Gift g2(string("str"));  // ����� ����� ����������� Gift

	stringstream ss;
	for (int i = 0; i < 10; i++)
	{
		ss.str("");
		ss.clear();
		ss << "gift " << i+1 << ends;
		
		gift_bag.push_back(Gift(ss.str())); // ������� ����� ������������ Gift 
		gift_bag.emplace_back(ss.str());// ������ emplace* ���� �������� ������������ �������
	}

	for (auto g : gift_bag)
	{
		g.show();
	}
	cout << "max size: " << gift_bag.max_size() << endl;
}

int main()
{
	//ex00();
	//ex01();
	//ex02();
	//ex03();
	//ex04();
	//ex05();
	ex06();

    return 0;
}


// 01.Lamdas.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


bool desc(int a, int b)
{
	return a < b;
}

bool asc(int a, int b)
{
	return a > b;
}

/*
	������� ���������� ������� ��������
*/
void bubleSort(int *arr, int size, bool (*cmp)(int a, int b) = asc)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if (cmp(arr[j - 1], arr[j]))
			{
				int tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
		}
	}
}

template<typename Iterator>
void print_array(Iterator from, Iterator end)
{
	Iterator cur = from;
	while(cur != end)
	{
		cout << *cur++ << " ";		
	}
	cout << endl;
}

void ex00()
{
	int arr[10];
	generate(arr, arr + 10, rand);
	print_array(arr, arr + 10);
	bubleSort(arr, 10, desc);
	print_array(arr, arr + 10);

	bool(*cmp)(int, int) = asc;
	cmp = desc;
}

class Generate
{
	int _max;
public:
	Generate(int max = 100): _max(max)
	{}
	int operator()()
	{
		return rand() % _max;
	}
};

void ex01()
{
	// ����� ��������� ��������� �� ������ ���������
	bool(*cmp)(int, int) = [](int a, int b) { return a < b; };
	
	int arr[10];
	//generate(arr, arr + 10, []() { return rand() % 100; });
	generate(arr, arr + 10, Generate(10));
	
	bubleSort(arr, 10, cmp);

	// ����� �������� ������ �������� ��������������� ��� ���������� ��������� 
	for_each(arr, arr + 10, [](int a) { cout << a << " "; });
	cout << endl;
}

class Hippo
{
	string _name;
	int _weight;
public:
	Hippo(string name, int weight): 
		_name(name), _weight(weight)
	{}

	string& Name()
	{
		return _name;
	}

	int& Weight()
	{
		return _weight;
	}

	friend ostream& operator<<(ostream& stream, Hippo& gipo)
	{
		stream << gipo._name << " " << gipo._weight;
		return stream;
	}
};

void ex02()
{
	vector<Hippo> leak;
	leak.push_back(Hippo("Vasja", rand() % 100 + 50));
	leak.push_back(Hippo("Sharik", rand() % 100 + 50));
	leak.push_back(Hippo("Slunavchick", rand() % 100 + 50));
	leak.push_back(Hippo("Antidot", rand() % 100 + 50));

	sort(leak.begin(), leak.end(), [](Hippo g1, Hippo g2) { return g1.Name() < g2.Name(); });
	print_array(leak.begin(), leak.end());
	cout << endl;
	sort(leak.begin(), leak.end(), [](auto g1, auto g2) { return g1.Weight() < g2.Weight(); });
	print_array(leak.begin(), leak.end());
	cout << endl;
}

void ex03()
{
	int a = 5, b = 10, c = 20, d = 15;
	
	// ������ ���������� a
	auto f = [a]{ cout << a << endl; };
	f();

	int arr[10];
	
	generate(arr, arr + 10, [a]() { return rand() % a; });
	for_each(arr, arr + 10, [](int a) { cout << a << " ";});
	cout << endl;
	// ������ ���� ���������� ������� ���������
	auto foo = [=]{cout << a << " " << b << " " << c << " " << d << endl;};
	foo();
}

//		��������
//  1. ������������� ������ (������) ��������� ����� � ��������� 0..1000
//  2. ��������� ���������� �������� > 200 � < 600 (�������� count_if) ��������� ������

int main()
{
	//ex00();
	//ex01();
	//ex02();
	//ex03();
    return 0;
}


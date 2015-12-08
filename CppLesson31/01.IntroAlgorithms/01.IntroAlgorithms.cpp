// 01.IntroAlgorithms.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

template<typename T, typename UniFunc>
void ModifyData(T& x, UniFunc f)
{
	f(x);
}

template<typename T>
class ModifyCls
{
public:
	void operator()(T& x)
	{
		x = 5;
	}
};

void ex00()
{
	int x = 10;
	cout << "x: " << x << endl;
	ModifyData(x, ModifyCls<int>());
	cout << "x: " << x << endl;
}

template<typename T>
ostream& operator<<(ostream& stream, vector<T> v)
{
	for (auto item : v)
	{
		stream << item << " ";
	}	
	return stream;
}

class IsPositive
{
public:
	bool operator()(int x)
	{
		return x >= 0;
	}
};

void ex01(const vector<int> &v)
{
	// соответствуют ли все элеметы заданному условию	
	if (all_of(v.begin(), v.end(), IsPositive()))
	{
		cout << "All items are positive" << endl;
	}
}

// предикат - проверка на отрицательные значения
class IsNegative
{
public:
	bool operator()(int x)
	{
		return x < 0;
	}
};

void ex02(const vector<int> &v)
{
	// соответствуют ли хотя бы один элемент заданному условию
	if (any_of(v.begin(), v.end(), IsNegative()))
	{
		cout << "Some items are negative" << endl;
	}
}

void ex03(const vector<int> &v)
{
	// ни один элемент не соответствует заданному условию
	if (none_of(v.begin(), v.end(), IsNegative()))
	//if (!any_of(v.begin(), v.end(), IsNegative()))
	{
		cout << "None items are negative" << endl;
	}
}

void ex04(const vector<int> &v)
{
	// подсчет количества элементов
	int zeros = count(v.begin(), v.end(), 0);
	cout << "count(0) = " << zeros << endl;
}

void ex05(const vector<int> &v)
{
	// подсчет количества отрицательных элементов
	int negative = count_if(v.begin(), v.end(), IsNegative());
	cout << "count(i<0) = " << negative << endl;
}

void f(int x)
{
	cout << x*x << endl;
}

void ex06(const vector<int> &v)
{
	cout << "ex06" << endl;
	// применяет функцию f к половине последовательности
	for_each(v.begin(), v.begin() + v.size() / 2, f);
}

void out(int x)
{
	cout << x << " ";
}

void ex07(const vector<int> &v)
{
	cout << "ex07" << endl;
	// поиск заданного значения
	//vector<int>::const_iterator it = find(v.begin(), v.end(), -1);
	auto it = find(v.begin(), v.end(), 4);
	if (it != v.end()) // если был найден
	{
		for_each(v.begin(), it, out);
		cout << endl;
	}
}

void ex08(const vector<int> &v)
{
	cout << "ex08" << endl;
	// поиск первого отрицательного значения
	//vector<int>::const_iterator it = find(v.begin(), v.end(), -1);
	auto it = find_if(v.begin(), v.end(), IsNegative());
	if (it != v.end()) // если был найден
	{
		for_each(it, v.end(), out);
		cout << endl;
	}
}

void ex09(const vector<int> &v)
{
	cout << "ex09" << endl;
	int arr[] = { 3, 5, 7 }; // должен быть отсортирован
	// поиск первое значение из массива arr
	auto it = find_first_of(v.begin(), v.end(), arr, arr + 3);
	if (it != v.end()) // если был найден
	{		
		cout << "idx: " << it - v.begin()<< endl;
	}
}

int main()
{
	//ex00();

	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(rand() % 20);
	}
	v.push_back(-1);
	v.push_back(-10);
	cout << v << endl;

	//ex01(v);
	/*ex02(v);
	ex03(v);
	ex04(v);
	ex05(v);
	ex06(v);
	ex07(v);
	ex08(v);*/
	ex09(v);
    return 0;
}


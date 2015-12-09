// 02.ModifiedAlgorithms.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
ostream& operator<<(ostream& stream, vector<T> v)
{
	for (auto item : v)
	{
		stream << item << " ";
	}
	return stream;
}

void  ex01(vector<int> &v)
{
	v.resize(10); // резервирование места для данных
	fill(v.begin(), v.end(), 50); // заполнение всего вектора значениями 50
	cout << v << endl;
	fill_n(v.begin() + v.size()/2, 5, 100); // заполнение половины вектор значениями 100
	cout << v << endl;
}

int rand50()
{
	return rand() % 50; // 0..49
}

class A
{
	
public:
	int _a;
	A(int a): _a(a)
	{}
};

A getA()
{
	return A(rand()%50001 + 5000);
}

bool sortA(const A& a1, const A& a2)
{
	return a1._a < a2._a;
}

void ex06()
{
	vector<A> a(10);
	generate(a.begin(), a.end(), getA);
	sort(a.begin(), a.end(), sortA);
}

void ex02(vector<int> &v)
{
	cout << "ex02" << endl << endl;
	// заполнение массива случайными числами
	generate(v.begin(), v.end(), rand50);
	cout << v << endl;
	
	int arr[10];
	generate_n(arr, 10, rand50);
	for (int v : arr)
	{
		cout << "arr: " << v << endl;
	}
}

bool IsGreater10(int item)
{
	return item > 10;
}

void out(int i)
{
	cout << i << " ";
}

void ex03(const vector<int> &orig)
{
	cout << endl << "ex03" << endl;
	vector<int> cpy;
	cpy.resize(orig.size());
	// полное копирование по итераторам
	copy(orig.begin(), orig.end(), cpy.begin());
	// копирование с указанем количества элементов
	//copy_n(orig.begin(), orig.size(), cpy);
	
	cpy[0] = 10;
	cout << cpy << endl;
	// сравнение последовательностей
	if (equal(orig.begin(), orig.end(), cpy.begin(), cpy.end()))
	{
		cout << "Vectors are equal" << endl;
	}

	cpy.clear();
	cpy.resize(10);
	// частичное копирование
	vector<int>::iterator end = copy_if(orig.begin(), orig.end(), cpy.begin(), IsGreater10);
	for_each(cpy.begin(), end, out);	
	cout << endl;
}


bool LessThan20(int item)
{
	return item < 20;
}

void ex04(const vector<int> &orig)
{
	cout << endl << "ex04" << endl;
	vector<int> cpy(orig);
	cout << cpy << endl;
	// удалить элемент 8
	auto end = remove(cpy.begin(), cpy.end(), 8);
	// удалить элемент 0
	end = remove(cpy.begin(), end, 0);
	// удалить все элементы меньше 20
	end = remove_if(cpy.begin(), end, LessThan20);
	for_each(cpy.begin(), end, out);
}

void ex05(const vector<int> &orig)
{
	cout << endl << "ex05" << endl;
	vector<int> cpy(orig);
	// сортировка в порядке возрастания
	sort(cpy.begin(), cpy.end());
	cout << cpy << endl;
	// обращение элементов
	reverse(cpy.begin(), cpy.end());
	cout << cpy << endl;
	// перемешать элементы последовательности
	random_shuffle(cpy.begin(), cpy.end());
	cout << cpy << endl;
}

class GetRandom
{
	int _max;
public:
	GetRandom(int m)
	{
		_max = m;
	}
	int operator()()
	{
		return rand() % _max; // 0.._max-1
	}
};

void ex06()
{
	vector<int> v(10);
	generate(v.begin(), v.end(), GetRandom(3));
	cout << v << endl;
	// удаляет повторяющиеся подряд элементы
	auto end = unique(v.begin(), v.end());
	if (end != v.end())
	{
		v.erase(end, v.end()); // вырезает лишние элементы
	}
	for_each(v.begin(), v.end(), out);
	cout << endl;
}

int main()
{
	vector<int> v;
	ex01(v);
	ex02(v);
	ex03(v);
	ex04(v);
	ex05(v);
	ex06();
    return 0;
}


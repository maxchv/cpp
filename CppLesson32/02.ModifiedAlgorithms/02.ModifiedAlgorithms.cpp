// 02.ModifiedAlgorithms.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <numeric>
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
	A() {}
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

void _ex06()
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

void ex07(vector<int> &v)
{
	v.resize(10);
	generate(v.begin(), v.end(), GetRandom(10));
	sort(v.begin(), v.end());
	cout << "v: ";
	cout << v << endl;
	if (is_sorted(v.begin(), v.end())) // отсортирован ли массив?
	{
		cout << "Vector is sorted" << endl;
	}

	vector<int> nv(10);
	generate(nv.begin(), nv.end(), GetRandom(20));
	sort(nv.begin(), nv.end()); // перед объединением нужно отсортировать массивы
	cout << "nv: ";
	cout << nv << endl;

	vector<int> m(v.size() + nv.size());
	// объединение двух последовательностей
	merge(v.begin(), v.end(), nv.begin(), nv.end(), m.begin());
	cout << "m: ";
	cout << m << endl;
}

bool cmp(int a, int b)
{
	return abs(a) < abs(b);
}

void ex08(vector<int> &v)
{
	v.push_back(-10);
	v.push_back(-100);
	random_shuffle(v.begin(), v.end());
	cout << v << endl;
	// найти наибольший элемент по абсолютному значению
	auto it_max = max_element(v.begin(), v.end(), cmp);
	cout << "max: " << *it_max << endl;

	// найти наименьший элемент по абсолютному значению
	auto it_min = min_element(v.begin(), v.end(), cmp);
	cout << "min: " << *it_min << endl;

	//pair<vector<int>::iterator, vector<int>::iterator> it_minmax =
	auto it_minmax = minmax_element(v.begin(), v.end(), cmp);
	cout << "min: " << *it_minmax.first 
		 << " max: " << *it_minmax.second << endl;
}

int mysum(int a, int b)
{
	return abs(a) + abs(b);
}

int myprod(int a, int b)
{
	return abs(a) * abs(b);
}

void ex09(vector<int> &v)
{
	int sum = accumulate(v.begin(), v.end(), 0, mysum);
	cout << "sum: " << sum << endl;

	int prod = accumulate(v.begin(), v.end(), 1, myprod);
	cout << "prod: " << prod << endl;
}

void ex10()
{
	// Пример проверки слова на палиндром
	string word = "MAdam";
	// преобразование к нижнему регистру
	transform(word.begin(), word.end(), word.begin(), tolower);
	// вариант без алгоритмов
	bool is_palindrom = true;
	for (int i = 0; i < word.size() / 2; i++)
	{
		if (word[i] != word[word.size() - i - 1])
		{
			is_palindrom = false;
			break;
		}
	}
	// вариант 1 с алгоритмами 
	string rev(word);
	reverse(rev.begin(), rev.end());
	if (word == rev)
	{
		is_palindrom = true;
	}
	else
	{
		is_palindrom = false;
	}
	// вариант 2 с алгоритмами
	is_palindrom = equal(word.begin(), word.begin() + word.size() / 2, word.rbegin());

	if (is_palindrom)
	{
		cout << "word " << word << " is palindrome" << endl;
	}
}

int main()
{
	vector<int> v;
	/*ex01(v);
	ex02(v);
	ex03(v);
	ex04(v);
	ex05(v);
	ex06();*/
	ex07(v);
	ex08(v);
	ex09(v);

	

    return 0;
}


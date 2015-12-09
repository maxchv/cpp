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
	v.resize(10); // �������������� ����� ��� ������
	fill(v.begin(), v.end(), 50); // ���������� ����� ������� ���������� 50
	cout << v << endl;
	fill_n(v.begin() + v.size()/2, 5, 100); // ���������� �������� ������ ���������� 100
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
	// ���������� ������� ���������� �������
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
	// ������ ����������� �� ����������
	copy(orig.begin(), orig.end(), cpy.begin());
	// ����������� � �������� ���������� ���������
	//copy_n(orig.begin(), orig.size(), cpy);
	
	cpy[0] = 10;
	cout << cpy << endl;
	// ��������� �������������������
	if (equal(orig.begin(), orig.end(), cpy.begin(), cpy.end()))
	{
		cout << "Vectors are equal" << endl;
	}

	cpy.clear();
	cpy.resize(10);
	// ��������� �����������
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
	// ������� ������� 8
	auto end = remove(cpy.begin(), cpy.end(), 8);
	// ������� ������� 0
	end = remove(cpy.begin(), end, 0);
	// ������� ��� �������� ������ 20
	end = remove_if(cpy.begin(), end, LessThan20);
	for_each(cpy.begin(), end, out);
}

void ex05(const vector<int> &orig)
{
	cout << endl << "ex05" << endl;
	vector<int> cpy(orig);
	// ���������� � ������� �����������
	sort(cpy.begin(), cpy.end());
	cout << cpy << endl;
	// ��������� ���������
	reverse(cpy.begin(), cpy.end());
	cout << cpy << endl;
	// ���������� �������� ������������������
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
	// ������� ������������� ������ ��������
	auto end = unique(v.begin(), v.end());
	if (end != v.end())
	{
		v.erase(end, v.end()); // �������� ������ ��������
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
	if (is_sorted(v.begin(), v.end())) // ������������ �� ������?
	{
		cout << "Vector is sorted" << endl;
	}

	vector<int> nv(10);
	generate(nv.begin(), nv.end(), GetRandom(20));
	sort(nv.begin(), nv.end()); // ����� ������������ ����� ������������� �������
	cout << "nv: ";
	cout << nv << endl;

	vector<int> m(v.size() + nv.size());
	// ����������� ���� �������������������
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
	// ����� ���������� ������� �� ����������� ��������
	auto it_max = max_element(v.begin(), v.end(), cmp);
	cout << "max: " << *it_max << endl;

	// ����� ���������� ������� �� ����������� ��������
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
	// ������ �������� ����� �� ���������
	string word = "MAdam";
	// �������������� � ������� ��������
	transform(word.begin(), word.end(), word.begin(), tolower);
	// ������� ��� ����������
	bool is_palindrom = true;
	for (int i = 0; i < word.size() / 2; i++)
	{
		if (word[i] != word[word.size() - i - 1])
		{
			is_palindrom = false;
			break;
		}
	}
	// ������� 1 � ����������� 
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
	// ������� 2 � �����������
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


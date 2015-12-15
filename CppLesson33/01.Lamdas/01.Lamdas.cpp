// 01.Lamdas.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
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
	Функция сортировки методом пузырька
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
	// можно сохранить указатель на лямбда выражение
	bool(*cmp)(int, int) = [](int a, int b) { return a < b; };
	
	int arr[10];
	//generate(arr, arr + 10, []() { return rand() % 100; });
	generate(arr, arr + 10, Generate(10));
	
	bubleSort(arr, 10, cmp);

	// можно передать лямбда выражени непосредственно без сохнанения указателя 
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
	
	// захват переменной a
	function<void()> f = [a]{ cout << a << endl; };
	f();

	int arr[10];
	
	generate(arr, arr + 10, [a]() { return rand() % a; });
	for_each(arr, arr + 10, [](int a) { cout << a << " ";});
	cout << endl;
	// захват всех переменных данного контекста
	f = [=]{cout << a << " " << b << " " << c << " " << d << endl;};
	f();
}

void ex04()
{
	string str = "hElLo";
	// tolower
	transform(str.begin(), str.end(), str.begin(), [](auto ch) {return ch | 32;});
	cout << str << endl;
	// toupper
	transform(str.begin(), str.end(), str.begin(), [](auto ch) {return ch ^ 32;});
	cout << str << endl;
}

//		Практика
//  1. сгенерировать массив (вектор) случайных чисел в диапазоне 0..1000
//  2. посчитать количество элеметов > 200 и < 600 (алгоритм count_if) используя лямбду

class Functor
{
	mutable int _i;
public:
	Functor(int i):_i(i)
	{}
	int operator()() const
	{
		return _i++;
	}
};

void ex05()
{
	int arr[10];
	int i = 0;
	int j = 10;
	// данные захватываются по значению
	// для захвата всех данных по значению [=]
	generate(arr, arr + 10, [i]() mutable { return i++; });
	print_array(arr, arr + 10);
	cout << endl << "i: " << i << endl;

	// данные захватываются по ссылке
	// для захвата всех данных по значению [&]
	generate(arr, arr + 10, [&]() { i++; return j++; });
	cout << endl << "i: " << i << endl;
	cout << endl << "j: " << j << endl;
}

void ex06()
{
	int arr[10];
	int i = 0;	
	generate(arr, arr + 10, [i]() mutable { return i++; });

	transform(arr, arr + 10, arr, [](int i) -> double {
		if (i == 0)
		{
			return i + 2.0;
		}
		else if (i % 2 == 0)
		{
			return i / 2.0;
		}
		else
		{
			return i*i;
		}
	});
	print_array(arr, arr + 10);
}

template<typename T1, typename T2>
auto add(T1 t1, T2 t2)
{
	decltype(t1 + t2) t3;
	t3 = t1 + t2;
	return t3;
}

void ex07()
{
	// лямбда, которая генерирует лямбду
	auto genLambda = [](int val)->function<int()>
	{
		int a = 0, b = 1;
		return [a, b]() mutable {a = b; b = a + b; return a;};
	};

	int arr[10];
	generate(arr, arr + 10, genLambda(10));
	print_array(arr, arr + 10);
}

int main()
{
	//ex00();
	//ex01();
	//ex02();
	//ex03();
	//ex04();
	//ex05();
	//ex06();
	ex07();

    return 0;
}


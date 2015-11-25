// 01.Lists.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iomanip>
#include <list>
#include <deque>
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

template <typename T>
ostream &operator<<(ostream &stream, list<T> &lst)
{
	for (auto &item : lst)
	{
		stream << item << endl;
	}
	stream << endl;
	return stream;
}

void ex00()
{
	deque<int> d = {1, 2, 3, 4};
	auto itd = d.begin();
	
	list<int> l(d.begin(), d.end());

	list<int> lst = {1, 4, 5};

	lst.push_back(12);
	lst.push_front(56);

	auto it = lst.begin();	
	
	cout << lst << endl;
}

void ex01()
{
	//srand(time(NULL));
	list<int> lst;
	for (int i = 0; i < 10; i++)
	{
		lst.push_back(rand() % 100);
	}
	cout << lst << endl;
	lst.sort(); // сортировка по возростанию
	lst.reverse(); // реверс (переворот) списка
	cout << lst << endl;
}

class Train
{
	int _num;		 // номер поезда
	string _station; // конечная станция
public:
	Train(int num, string station):
		_num(num), _station(station)
	{}

	string Station()
	{
		return _station;
	}

	int Num()
	{
		return _num;
	}

	friend ostream &operator<<(ostream &stream, Train &train)
	{		
		stream << setfill('.') << train._num << right
			   << setw(20) << right << train._station;
		return stream;
	}

	// перегрузить оператор < для возможности сортировки данных этого типа
	bool operator<(Train& right)
	{
		return _num < right._num;
	}
};

// Функция сортировки поездов в порядке убывания 
// по номеру поезда
bool cmpDescNum(Train &tr1, Train &tr2)
{
	return tr1.Num() > tr2.Num();
}

// Предикат для сравенения по конечной станции - назначению (по возростанию)
class ComparerAscStation
{
public:
	bool operator()(Train &tr1, Train &tr2)
	{
		return tr1.Station() < tr2.Station();
	}
};


void ex02()
{
	list<Train> trains;
	trains.emplace_back(10, "Kiev");
	trains.emplace_back(14, "Kharkov");
	trains.emplace_back(15, "Adisabeba");
	trains.emplace_back(13, "Moskow");
	trains.emplace_back(17, "Odessa");

	cout << trains << endl;
	
	trains.sort(); // сортировка по умолчанию

	cout << trains << endl;

	trains.sort(cmpDescNum); // сортировка с применением функции сравнения

	cout << trains << endl;

	trains.sort(ComparerAscStation()); // сортировка через предикат

	cout << trains << endl;
}

void ex03()
{
	list<int> lst1 = { 5, 2, 3, 2 };
	list<int> lst2 = { 4, 9, 2, 0 };
		
	// перед merge обязательно отсортировать списки
	lst1.sort();
	lst2.sort();

	cout << "first: " << endl << lst1 << " second: " << endl << lst2 << endl;

	lst1.merge(lst2); 
	
	lst1.push_front(2);
	// список lst2 после сортировка становится пустым!!!
	cout << "first: " << endl << lst1 << " second: " << boolalpha << lst2.empty() << endl;

	
	lst1.unique();
	cout << "after unique:" << endl;
	cout << lst1 << endl;
}

class IsNegative
{
public:
	bool operator()(int &item)
	{
		return item < 0;
	}
};

void ex04()
{
	list<int> lst = { -1, 5, 0, -4, 2, 5 };

	cout << lst << endl;
	
	lst.remove(5); // удаляет все 5 из списка

	cout << lst << endl;

	// удалить все отрицательные элементы в списке
	lst.remove_if(IsNegative());

	cout << lst << endl;
}

void ex05()
{
	list<int> lst1 = { 5, 2, 3, 2 };
	list<int> lst2 = { 4, 9, 2, 0 };

	auto it = lst1.begin();
	advance(it, 2); // переместить итератор на 2 позиции вперед
	auto it2 = lst2.begin();
	advance(it2, 2);
	auto it3 = lst2.end();
	// lst1.splice(it, lst2, it2); // { 5, 2, 4, 9, 2, 0, 3, 2 };
	//lst1.splice(it, lst2, it2); // { 5, 2, 2, 3, 2 };
	lst1.splice(it, lst2, it2, it3); // { 5, 2, 2, 0, 3, 2 };

	cout << "first: " << endl << lst1 << " second: " << boolalpha << lst2.empty() << endl;
	cout << lst2 << endl;

	
}

int main()
{

	//ex00();
	//ex01();
	//ex02();
	//ex03();
	//ex04();
	ex05();

    return 0;
}


// 02.Stacks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>
#include <string.h>
#include <cmath>
#include <queue>
using namespace std;

void ex01()
{
	// LIFO
	stack<int> s;
	s.emplace(1);
	s.emplace(2);
	for (int i = 0; i < 10; i++)
	{
		s.push(i); // втолкнуть элемент
	}
	while (!s.empty()) // пока не пустой
	{
		cout << s.top() << endl; // отобразить вершину стека 
		s.pop(); // вытолкнуть вершину стека
	}
}

class Human
{
public:
	string name;
	enum _sex {MALE, FEMALE, UGLY} sex;
};

void ex02()
{
	// FIFO
	queue<Human> q;
	q.emplace(Human{"Vasja", Human::_sex::MALE});
	q.emplace(Human{ "Petja", Human::_sex::MALE });
	q.emplace(Human{ "Darina", Human::_sex::FEMALE });
	q.emplace(Human{ "Mila", Human::_sex::FEMALE });

	while (!q.empty())
	{
		Human h = q.front();
		cout << h.name << " " << h.sex << endl;
		q.pop();
	}
}

int main()
{
	//ex01();
	ex02();

    return 0;
}


// 01.OverloadOperators.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Wallet
{
	int money;
public:
	Wallet() = delete;
	Wallet(int i)
	{
		money = i;
	}
	
	void add(int m)
	{
		money += m;
	}

	int get()
	{
		return money;
	}

	Wallet operator+(Wallet &other)
	{
		Wallet tmp(0);		
		tmp.add(money + other.money);
		money = 0;
		other.money = 0;
		return tmp;
	}

	int operator-(Wallet &other)
	{
		return money - other.money;
	}

	Wallet operator+(int m)
	{
		Wallet tmp(0);
		tmp.add(money + m);
		money = 0;		
		return tmp;
	}

	// оператор преобразования типа
	operator int()
	{
		return money;
	}

	bool operator>(Wallet &other)
	{
		return money > other.money;
	}

	bool operator<(Wallet &other)
	{
		return money < other.money;
	}

	bool operator>=(Wallet &other)
	{
		return money >= other.money;
	}
	
	bool operator<=(Wallet &other)
	{
		return money <= other.money;
	}

	bool operator!=(Wallet &other)
	{
		return money != other.money;
	}

	bool operator==(Wallet &other)
	{
		return money == other.money;
	}

	void show()
	{
		cout << "I have $" << money << endl;
	}
};

Wallet operator+(int m, Wallet &right)
{
	Wallet tmp(0);
	tmp.add(m + right.get());
	return tmp;
}

class AppleBox
{
	int apples;
	mutable int it_can_be_change;
	const int count = 60;
public:
	AppleBox(int a) { apples = a; }
	int getCount() const // константный метод
	{
		//apples = 10; ошибка т.к. в константом методе нельзя изменять 
		//             поля класса!!!
		it_can_be_change = 10;
		return count;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Wallet w1(0), w2(0), w3(0);
	w1 = move(w2);
	w1.add(10);
	w2.add(5);

	if (w1 > w2)
	{
		cout << "I have more maney than she" << endl;
	}

	w3 = w1 + w2;
	w3 = w3 + 10;
	w3 = 10 + w3;
	w3.show();
	w1.show();
	w2.show();

	int m = w3;
	cout << "how much" << m << endl;
	w1.add(5);

	int res = w3 - w1;

	return 0;
}


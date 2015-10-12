// 04.ExchangeMoney.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class ExchangeMoney
{
	static double buyUSD;
	static double buyUAH;
	double USD, UAH;
public:
	ExchangeMoney(double startUSD, double startUAH)
	{
		USD = startUSD;
		UAH = startUAH;
	}

	static void ChangeCurrents(const char* pass, double usd, double uah)
	{
		if (!strcmp(pass, "1234"))
		{
			buyUSD = usd;
			buyUAH = uah;
		}
	}

	friend ostream& operator<<(ostream& stream, ExchangeMoney& em)
	{
		stream << "UAH: " << em.UAH << " USD: " << em.USD ;
		return stream;
	}

	double USDtoUAH(double usd)
	{
		double g = usd * buyUSD;
		if (UAH >= g)
		{
			UAH -= g;
			USD += usd;
			return g;
		}
		else
		{
			cerr << "Not enought money" << endl;
			return 0;
		}
	}
};

double ExchangeMoney::buyUAH = 22.8;
double ExchangeMoney::buyUSD = 21.8;

int main()
{
	ExchangeMoney b1(1000, 10000);
	ExchangeMoney b2(1500, 20000);
	ExchangeMoney b3(3000, 15000);

	cout << b1.USDtoUAH(5) << endl;
	cout << b2.USDtoUAH(5) << endl;
	ExchangeMoney::ChangeCurrents("1234", 23.6, 24.5);
	cout << b1.USDtoUAH(5) << endl;
	cout << b2.USDtoUAH(5) << endl;
	cout << b3.USDtoUAH(5) << endl;

	cout << b1 << endl;
	cout << b2 << endl;
	cout << b3 << endl;

    return 0;
}


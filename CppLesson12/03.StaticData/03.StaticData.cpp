// 03.StaticData.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class StaticCls
{
	int nostatic;
	static int data;
public:	
	void setNostatic(int n)
	{
		this->nostatic = n;
	}
	static int getData() 
	{ 		
		// нет указателя this -> нет доступа к нестатическим полям и методам
		//nostatic = 10;
		return data; 
	}
	static void setData(int d) { data = d; }
};
int StaticCls::data = 0;

int main()
{
	StaticCls obj; // объект или экземпляр класса
	
	StaticCls::setData(10);
	cout << StaticCls::getData() << endl;

	obj.setData(100);

	StaticCls obj2;
	cout << obj.getData() << " " << obj2.getData() << endl;
	

    return 0;
}


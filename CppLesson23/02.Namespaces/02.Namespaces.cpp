// 02.Namespaces.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "my_header.h"

using std::cout;
using std::endl;

namespace Paris
{
	class Tower
	{

	};
}

namespace London
{
	class Tower
	{

	};

	int a;
}

int a;

namespace it_is_too_long_name_for_namespace
{
	class A
	{
	public:
		A()
		{
			cout << "it is class A in it_is_too_long_name_for_namespace" << endl;
		}
	};
}

class A
{
public:
	A()
	{
		cout << "it is class A in global scope" << endl;
	}
};

namespace ns = it_is_too_long_name_for_namespace;

int main()
{
	Paris::Tower EiffelTower;
	London::Tower BigBan;

	a = 5;
	London::a = 10;
	
	{
		int a = 20;
		cout << "a = " << a << " ::a = " << ::a << endl;		
	}

	ns::A a;
	A b;

	B c;
	C d;
	cout << d.msg() << endl;

    return 0;
}


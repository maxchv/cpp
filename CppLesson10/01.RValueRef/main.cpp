#include <iostream>
using namespace std;

void f(int &i)
{
	cout << "This function give lvalue reference" << endl;
}

void f(int &&i)
{
	cout << "This function give rvalue reference" << endl;
}

int fnum()
{
	int i = 10;
	return i;
}

int main()
{
	int i = 0;
	
	f(i);
	f(10);
	f(fnum());
	f(move(i));

	int &l = i;
	const int &c = 10;	   // C++03

	// rvalue reference	 C++11
	int &&r = 2;
	cout << r << endl;
	r = 10;
	cout << r << endl;

	system("pause");
	return 0;
}
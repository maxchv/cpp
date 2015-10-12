// PointerThis.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#pragma warning(disable: 4996)

class Point
{
	int x, y;
	char *name;	
	bool is_copy;
public:
	//Point() // ����������� �� ���������
	//{
	//	x = y = 0;		
	//}
	//Point(int x) // ����������� � ����� ����������
	//{
	//	this->x = x;
	//	y = 0;
	//}

	Point(char *name, int x = 0, int y = 0)// ����������� � ����� �����������
	{
		cout << "It is Constructor" << endl;
		int n = strlen(name);         // ���������� ������ ������
		this->name = new char[n + 1]; // �������� ������ ��� �������� ��������� ������
		strcpy(this->name, name);     // �������� ������
		this->x = x;
		this->y = y;
		is_copy = false;
	}

	Point(const Point& orig)
	{
		cout << "Constructor copy" << endl;
		x = orig.x;
		y = orig.y;
		//name = orig.name; <- ������� ������
		int n = strlen(orig.name);         // ���������� ������ ������
		this->name = new char[n + 1]; // �������� ������ ��� �������� ��������� ������
		strcpy(this->name, orig.name);     // �������� ������
		is_copy = true;
	}

	~Point()
	{
		cout << "Destructor ";
		if (is_copy)
		{
			cout << "copy ";
		}
		cout << name << endl;
		delete[] name;
	}

	void show()
	{
		cout << name << " x: " << x << " y: " << y << endl;
	}
};

void fnct_show(Point p)
{
	p.show();
}

int main()
{
	char name[30];
	cout << "Type name of first point: ";
	cin >> name;
	Point p(name);
	cout << "Type name of second point: ";
	cin >> name;
	Point p1(name, 10);
	cout << "Type name of third point: ";
	cin >> name;
	Point p2(name, 10, 20);
	
	//Point *ptr; // ��������� �� Point
	//ptr = &p;   // & - �������� ����� ������� p
	//ptr->show();// -> ��������

	//p.show();  // x = 0, y = 0
	//p1.show(); // x = 10, y = 0
	fnct_show(p1);
	p2.show(); // x = 10, y = 20	
	Point new_point = p1; // ����������� ����������� �����������
	//new_point = p2;     // ���������� �������� ������������

	//// ������������ ��������� ������
	//int *iptr = new int(10);
	//cout << *iptr << endl; // * - �������������

	////Point *pptr = new Point(50, 50);
	////pptr->show();

	//delete iptr;
	////delete pptr;

	return 0;
}


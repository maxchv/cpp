// 01.stringio.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;
#pragma warning(disable: 4996)

// ����: ��������� ����/������

void f(const char *msg)
{
	cout << msg << endl;
}

void ex00()
{
	// ��� ������������� ������������ ������
	// � � �������������� ������� sprintf
	char buf[50];
	int x, y;
	cout << "type x and y: ";
	cin >> x >> y;
	sprintf(buf, "x: %d y: %d", x, y);
	f(buf);
}

void ex01()
{
	// � �++ ���� ������� ��������� ����� � ������� �����
	// �������� ��� � cout � cin
	stringstream stream;
	int x, y;
	cout << "type x and y: ";
	cin >> x >> y;
	stream << "x: " << x << " y: " << y << ends;

	string str = stream.str(); // ���������� ������
	f(str.c_str());
}

void ex02()
{
	// ����/�����
	stringstream ss;
	ss << "10 20 3.14 string";
	int x, y;
	double d;
	string str;
	ss >> x >> y >> d >> str;
	cout << x << " " << y << " " << d << " " << str;
}

void ex03()
{
	// �������� stringstream
	stringstream ss;

	ss << 10 << " " << 12 << " " << 20;

	int x, y, z;
	cout << "type x,y,z: ";

	cin >> x >> y >> z;

	ss.str(""); // ������ ������ ������
	ss.clear(); // �������� ������

	ss << x << " " << y << " " << z;

	cout << ss.str();
}

string make_row(int i, int n, char sym)
{
	ostringstream ss;
	string stars(1 + i * 2, sym);
	ss << setw(i + n / 2 + 1) << right << stars << endl;
	return ss.str();
}

string task01(int n)
{
	/*
		�������. ������������ ������ �� ��������� � ����� �����
		��������� ��������� �����
	*/
	ostringstream ss;
	for (int i = 0; i < n / 2 + 1; i++)
	{
		ss << make_row(i, n, '*');
	}
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		ss << make_row(i, n, '*');
	}
	return ss.str();
}

int main()
{
	//ex00();
	//ex01();
	//ex02();
	//ex03();
	for (int i = 1; i < 10; i += 2)
	{
		cout << "i = " << i << endl;
		string str = task01(i);
		cout << str << endl << endl;
	}

	return 0;
}


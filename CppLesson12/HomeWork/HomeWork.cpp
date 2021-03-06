// HomeWork.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <locale>
#include <time.h>
#include <cassert>
using namespace std;

/*
������� 1.
�����������, ��� �� ��������� ���������� ����� �� 5 ������������.
�� ��������� ��������� �������, ������� ������������ �� ������
����������������.
��� ����� ������� ��������������� ������ ���� �� ���� ���������.
������������� ������ ���� ��������������� ������� � ���������� ������� ���
������ �� �������.

��� ������������� ������ ���������������� ������� ������������ ����������� ���� ������.
��� ��������� ���� ��� ������� ����� ������������ ����������� ����.
��� ������������� �������� ����������� ������������ rand()
������� - ����, ������� �� ������ ���� ����������� �.�. ��������� � ������ ��������, � �� �� ����
*/

class GasStation
{
	string name;
	// �������� �������
	// �������� ����������� ����������������
public:
	GasStation(char *n) { name = n; } // � ������������ ������ �������� ������� 
	void show()
	{
		cout << "�������� " << name << endl;
		cout << "�������: " /* �������� ����� ������� */ << endl;
		cout << endl;
	}
	// ������������ �������� �������� count ������
	void fuel(int liters)
	{
		// ��������� ���������� - ������ �������� ������� � ���� ��������
		// � ��������� ������� �� liters ������
	}

	static bool empty() // ����������, ���� �������� ������, �.�. ������� ������ ���
	{
		return true;
	}
};

void task01()
{
	// ������� �����, ��� � ����� ������ ��� ������, ����� ������� � �������
	GasStation net[5] = { GasStation("������"), GasStation("������"), GasStation("������"),
		GasStation("��������"), GasStation("�����") };
	// ������������� ��������
	while (!GasStation::empty()) // ���� ���� �������
	{
		int n = rand() % 5; // �������� ������� ��������
		int liters = rand() % 16 + 5;
		net[n].fuel(liters);
	}

	for (int i = 0; i<5; i++)
	{
		net[i].show(); // ����� ���������� ��� ���� ��������
	}
}


int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "russian");

	task01();

    return 0;
}


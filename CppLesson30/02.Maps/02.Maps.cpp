// 02.Maps.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <map>
#include <iostream>
#include <string>
#include <locale>
using namespace std;

// �������� �������
void ex01()
{	
	map<string, int> group;
	
	// � ������� ������ �������� � ���� ����������� ������ pair
	pair<string, int> p("Petja", 0);	

	// ��������� ������� ������� ������
	group.insert(p);
	group.insert(pair<string, int>("Vasja", 10));
	group.insert(make_pair<string, int>("Lola", 11));
	group.emplace("Mila", 12);
	group["Darina"] = 12;
	group["Darina"] = 10;
	group.at("Darina") = 5; // ���������� ������

	for (pair<string, int> s : group)// ������� ���� ��������� ���������� map
	{
		cout << s.first << " " << s.second << endl;
	}
	cout << group["Dima"] << endl;
	cout << group.size() << endl;
}

// �������� ��� ���������� ������
class Comparer
{
public:
	bool operator()(string s1, string s2) const
	{
		return s1 > s2;
	}
};

void ex02()
{
	map<string, int, Comparer> group;

	group["Vasja"] = 10;
	group["Lola"] = 11;
	group["Mila"] = 12;
	group["Lina"] = 12;
	group["Masha"] = 10;

	// ����� �� �����
	map<string, int>::iterator mila = group.find("Mila");
	cout << mila->first << " " << mila->second << endl;
	
	try 
	{
		group.at("Sonja") = 5; // ���� ����� ��� - ���������� ����������
	}
	catch (...)
	{
		cerr << "Sonja is not student this group" << endl;
	}

	for (auto s : group)
	{
		cout << s.first << " " << s.second << endl;
	}
}

int main()
{
	//ex01();
	//ex02();

    return 0;
}


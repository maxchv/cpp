//--------------------------------------------------------------------
// STL List Exercise
// file: main.cpp
//
// ������� ������ ��������� �� ����� input.txt, 
// ������������� ������ � ������������ � key, 
// � ������� ������ �� �����.
//



#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

class DataType 
{
	string lastname;	// ������� ��������
	string firstname;	// ��� ��������
public:
	DataType(string firstname, string lastname);// ����������� �����������

	string getKey () const
	{ return lastname; }   // ���������� �������� ����
};

//--------- ����������� �������� << (������)



//------- ����������� �������� < (������)
bool operator < (DataType lhs, DataType rhs)
{

}

int main() 
{
	ifstream studentFile ("input.txt");  // �������� ���� �� ������� ���������
	list <DataType> students;            // ������ ���������
		
	// ������� ������ ������ �� ����� input.txt:
    
	// �������� �������� � ������ 

	// ������� ���� ��������� �� �����

	// ������������� ������ ���������

	// ������� ��������������� ������ ���������

	return 0;
}



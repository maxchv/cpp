//--------------------------------------------------------------------
// STL List Exercise
// file: main.cpp
//
// Считать список студентов из файла input.txt, 
// отсортировать список в соответствии с key, 
// и вывести список на экран.
//



#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

class DataType 
{
	string lastname;	// Фамилия студента
	string firstname;	// Имя студента
public:
	DataType(string firstname, string lastname);// Реализовать конструктор

	string getKey () const
	{ return lastname; }   // Возвращает ключевое поле
};

//--------- Перегрузить оператор << (вывода)



//------- Перегрузить оператор < (меньше)
bool operator < (DataType lhs, DataType rhs)
{

}

int main() 
{
	ifstream studentFile ("input.txt");  // Исходный файл со списком студентов
	list <DataType> students;            // Список студентов
		
	// Считать каждую строку из файла input.txt:
    
	// Добавить студента в список 

	// Вывести всех студентов на экран

	// Отсортировать список студентов

	// Вывести отсортированный список студентов

	return 0;
}



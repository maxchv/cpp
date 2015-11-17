// 01.BinaryIO.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;
#pragma warning(disable: 4996)

#define NODINAMIC

class Car
{

#ifdef DINAMIC
	char *tm;
	char *model;
	char *color;
#else
	char tm[50];
	char model[50];
	char color[10]; 
#endif

	double price;
public:
	Car() {}
	Car(const char *tm, const char *model, const char* color, double price)
	{
#ifdef DINAMIC
		this->tm = new char[strlen(tm) + 1];
		this->model = new char[strlen(model) + 1];
		this->color = new char[strlen(color) + 1];
#endif
		strcpy(this->tm, tm);
		strcpy(this->model, model);
		strcpy(this->color, color);
		this->price = price;
	}
	
	friend ostream& operator<<(ostream& stream, Car& car)
	{
		stream << car.tm << " "
			<< car.model << " "
			<< car.color << " $"
			<< car.price << endl;
		return stream;
	}
};

void ex01()
{
	// сохранение объекта в файл
	Car cars[] = {
		Car("Opel", "Astra", "Black", 23000),
		Car("BMW", "X5", "Red", 45000),
		Car("Lada", "Priora", "Eggplan", 8000)
	};
	//cout << cars[0]  << endl << cars[1] << endl;
	ofstream out("cars.bin", ios::binary); // ios::out | ios::trunc
	if (out.is_open())
	{
		out.write((char *)cars, sizeof(cars));
	}
}

void ex02()
{
	// считываение объекта из файла
	
	ifstream in("cars.bin", ios::binary);
	if (in.is_open())
	{
		in.seekg(0, ios::end);		// перемещаем указатель чтения на конец файла
		int size = in.tellg();		// определяем размер данных в файле
		int n = size / sizeof(Car); // кол-во автомобилей в файле
		
		Car* cars = new Car[n];  
		
		in.seekg(0, ios::beg);		// перемещаем указатель чтения на начало файла
		in.read((char*)cars, size);
		
		for (int i = 0; i < n; i++)
		{
			cout << cars[i] << endl;
		}
	
		delete[] cars;
	}
}

void ex03()
{
	Car cars[3];
	cout << "sizeof(cars): " << sizeof(cars) <<
		"sizeof(car): " << sizeof(Car) << endl;
}

int main()
{
	//ex01();
	ex02();
	ex03();
    return 0;
}


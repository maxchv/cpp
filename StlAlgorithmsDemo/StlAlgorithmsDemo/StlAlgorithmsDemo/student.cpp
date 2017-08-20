#include "stdafx.h"
#include "student.h"

student::student(string name, int age, gender gen) :
	name(name), age(age), gen(gen)
{}

string student::getName() {
	return name;
}

int student::getAge() {
	return age;
}

gender student::getGender() {
	return gen;
}

ostream& operator<<(ostream& stream, const student& student) {
	stream << "{" <<
		"name='" + student.name + '\'' +
		", age=" << student.age <<
		", gender=" << (student.gen == gender::MAN ? "man" : "woman") <<
		'}';
	return stream;
}

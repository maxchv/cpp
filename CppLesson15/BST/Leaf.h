#include <iostream>
using namespace std;

#pragma once
class Leaf
{
private:
	int key;
public:
	~Leaf();
	Leaf *left;
	Leaf* right;
	Leaf *parent;
	Leaf(int k);
	bool operator<(const Leaf & right);
	bool operator>(const Leaf & right);
	bool operator==(const Leaf& right);
	friend ostream& operator<<(ostream& stream, Leaf& l);
};


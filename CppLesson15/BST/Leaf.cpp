#include "stdafx.h"
#include "Leaf.h"

Leaf::~Leaf()
{
}


Leaf::Leaf(int k)
{
	left = right = parent = NULL;
	key = k;
}


bool Leaf::operator<(const Leaf & right)
{
	return key < right.key;
}


bool Leaf::operator>(const Leaf & right)
{
	return key > right.key;
}


bool Leaf::operator==(const Leaf& right)
{
	return key == right.key;
}

Leaf::operator int()
{
	return key;
}

ostream& operator<<(ostream& stream, Leaf& l)
{
	stream << l.key;
	return stream;
}
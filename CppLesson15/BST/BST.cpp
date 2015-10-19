// BST.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Leaf.h"

class BST // �������� ������ ������
{
	Leaf *root;
	int count;

	void addItem(Leaf *cur, Leaf *new_item)
	{
		if (*new_item < *cur) // ���� ��������� � ����� ����� ��� � ������
		{
			if (!cur->left) // ����� ������� ��������� �.�. ����� ������� �������
			{
				cur->left = new_item;
				new_item->parent = cur;
			}
			else // ����� ���������� ����������� ����� � ����� �����
			{
				addItem(cur->left, new_item);
			}
		}
		else
		{
			if (!cur->right) // ������ ������� ��������� �.�. ����� ������� �������
			{
				cur->right = new_item;
				new_item->parent = cur;
			}
			else // ����� ���������� ����������� ����� � ������ �����
			{
				addItem(cur->right, new_item);
			}
		}
	}
public:
	BST(): root(NULL), count(0)
	{}

	void addItem(int item)
	{
		Leaf *tmp = new Leaf(item);
		if (!root)
		{
			root = tmp;
		}
		else
		{
			addItem(root, tmp);
		}
	}

	void showTree()
	{

	}

};


int main()
{
	BST b;
	b.addItem(10);
	b.addItem(5);
	b.addItem(20);
	b.addItem(3);

    return 0;
}


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
	
	void showTree(Leaf *cur)
	{
		if (cur)
		{
			showTree(cur->right);			
			cout << *cur << " ";
			showTree(cur->left);			
		}
	}

	int getMax(Leaf *cur)
	{
		if (cur->right)
		{
			return getMax(cur->right);
		}
		return *cur;
	}

	void cleanTree(Leaf* cur)
	{
		if (cur)
		{
			cleanTree(cur->right);
			cleanTree(cur->left);
			delete cur;
		}
	}

public:
	BST(): root(NULL), count(0)
	{}

	bool getMax(int &res)
	{
		if (root)
		{
			res = getMax(root);
			return false; // ������ ��� �.�. ������ ������������ �������
		}
		return true; // ������ �.�. ������ ����
	}

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
		count++;
	}

	void showTree()
	{
		showTree(root);
		cout << endl;
	}

	~BST()
	{
		cleanTree(root);
	}
};


int main()
{
	BST b;
	b.addItem(10);
	b.addItem(5);
	b.addItem(20);
	b.addItem(3);
	b.showTree();
	int max;
	if (!b.getMax(max))
	{
		cout << max << endl;
	}
    return 0;
}


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

	// ����� ���� � ������ key
	Leaf* findItem(Leaf* cur, int key)
	{
		if (cur) // ���� ����������
		{
			if (int(*cur) == key) // ���� ������
			{
				return cur;
			}
			else if (int(*cur) < key) // ���� ������ ���� � ������ �����
			{
				return findItem(cur->right, key);
			}
			else // ����� �� � �����
			{
				return findItem(cur->left, key);
			}
		}
		else
		{
			return NULL; // ���� �� ��� ������
		}
	}

	// ����� ������������ ������� ��� ����
	Leaf* findMinLastItem(Leaf* cur)
	{
		if (cur)
		{
			if (cur->left)
			{
				return findMinLastItem(cur->left);
			}
			else if (cur->right)
			{
				return findMinLastItem(cur->right);
			}
			return cur;
		}
		else // ������ �� ������
		{
			return NULL;
		}
	}

	public:
		BST() : root(NULL), count(0)
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

		void deleteItem(int key)
		{
			Leaf *del = findItem(root, key);
			if (del)
			{
				cout << "Delete: " <<  *del << endl;
				if (!del->left && !del->right) // ������� ����������
				{
					if (del->parent->left == del) // "�����" �������
					{
						del->parent->left = NULL;						
					}
					else // ������ �������
					{
						del->parent->right = NULL;						
					}					
				}
				else if (!del->left && del->right) // ���������� ������ �������
				{
					if (del->parent->right == del) // � �������� ��������� ������� ��� ������ �������
					{
						del->parent->right = del->right;
					}
					else
					{
						del->parent->left = del->right;
					}
					del->right->parent = del->parent;					
				}
				else if (del->left && !del->right) // ���������� ����� �������
				{
					if (del->parent->right == del) // � �������� ��������� ������� ��� ������ �������
					{
						del->parent->right = del->left;
					}
					else
					{
						del->parent->left = del->left;
					}
					del->left->parent = del->parent;					
				}
				else // ��������� ��� �������
				{
					// ���������� �������
					Leaf* sub = findMinLastItem(del->right);// ���� ����������� ������� ������� �������
					cout << "Min item: " << *sub << endl;
					// �������� ���� sub �� ������ ��������
					if (sub->parent->left == sub) // ����� ������� 
					{
						sub->parent->left = NULL;
					}
					else
					{
						sub->parent->right = NULL;
					}
					// ��������� ����� � ���������� �������� �� ����������
					sub->parent = del->parent;
					sub->left = del->left;
					sub->right = del->right;

					// ��������� ����� ��� ��������
					if (del->parent->left = del) // ��� �������� ��������� ������� ��� ���� �������
					{
						del->parent->left = sub;
					}
					else
					{
						del->parent->right = sub;
					}
				}
				// ������� ������
				delete del; 
			}
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
		b.addItem(2);
		b.addItem(4);
		b.addItem(8);
		b.addItem(6);
		b.addItem(9);
		b.addItem(25);
		b.addItem(1);		
		b.showTree();
		int max;
		if (!b.getMax(max))
		{
			//cout << max << endl;
		}

		b.deleteItem(5);
		b.showTree();

		return 0;
	}


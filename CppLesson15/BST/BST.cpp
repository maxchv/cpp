// BST.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Leaf.h"

class BST // бинарное дерево поиска
{
	Leaf *root;
	int count;

	void addItem(Leaf *cur, Leaf *new_item)
	{
		if (*new_item < *cur) // куда вставлять в левую ветвь или в правую
		{
			if (!cur->left) // левый потомок отсутвует т.е. место вставки найдено
			{
				cur->left = new_item;
				new_item->parent = cur;
			}
			else // иначе производим рекурсивный поиск в левой ветви
			{
				addItem(cur->left, new_item);
			}
		}
		else
		{
			if (!cur->right) // правый потомок отсутвует т.е. место вставки найдено
			{
				cur->right = new_item;
				new_item->parent = cur;
			}
			else // иначе производим рекурсивный поиск в правой ветви
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

	// поиск узла с ключем key
	Leaf* findItem(Leaf* cur, int key)
	{
		if (cur) // узел существует
		{
			if (int(*cur) == key) // узел найден
			{
				return cur;
			}
			else if (int(*cur) < key) // узел должен быть в правой ветви
			{
				return findItem(cur->right, key);
			}
			else // иначе он в левой
			{
				return findItem(cur->left, key);
			}
		}
		else
		{
			return NULL; // узел не был найден
		}
	}

	// поиск минимального элемнта для узла
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
		else // защита от ошибок
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
				return false; // ошибок нет т.к. найден максимальный элемент
			}
			return true; // ошбика т.к. список пуст
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
				if (!del->left && !del->right) // потомки остутсвуют
				{
					if (del->parent->left == del) // "левый" потомок
					{
						del->parent->left = NULL;						
					}
					else // правый потомок
					{
						del->parent->right = NULL;						
					}					
				}
				else if (!del->left && del->right) // существует правый потомок
				{
					if (del->parent->right == del) // у родителя удаляемый элемент это правый потомок
					{
						del->parent->right = del->right;
					}
					else
					{
						del->parent->left = del->right;
					}
					del->right->parent = del->parent;					
				}
				else if (del->left && !del->right) // существует левый потомок
				{
					if (del->parent->right == del) // у родителя удаляемый элемент это правый потомок
					{
						del->parent->right = del->left;
					}
					else
					{
						del->parent->left = del->left;
					}
					del->left->parent = del->parent;					
				}
				else // сущесвуют оба потомка
				{
					// замещаемый элемент
					Leaf* sub = findMinLastItem(del->right);// ищем минимальный элемент правого потомка
					cout << "Min item: " << *sub << endl;
					// оторвать узел sub от своего родителя
					if (sub->parent->left == sub) // левый потомок 
					{
						sub->parent->left = NULL;
					}
					else
					{
						sub->parent->right = NULL;
					}
					// переносим связи с удаляемого элемента на замещаемый
					sub->parent = del->parent;
					sub->left = del->left;
					sub->right = del->right;

					// добавляем связь для родителя
					if (del->parent->left = del) // для родителя удаляемый элемент это левй потомок
					{
						del->parent->left = sub;
					}
					else
					{
						del->parent->right = sub;
					}
				}
				// очищаем память
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


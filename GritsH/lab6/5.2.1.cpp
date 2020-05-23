// 5.2.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
} Node;

Node* Push(int a, struct Node* t)
{
	if (t == NULL)
	{
		t = (struct Node*)malloc(sizeof(Node));
		t->data = a;
		t->left = t->right = NULL;
	}
	else if (a == t->data);
	else if (a < t->data)
		t->left = Push(a, t->left);
	else
		t->right = Push(a, t->right);
	return t;
}

void PushData(Node** t)
{
	int d = 0;
	for (int i = 0; i < 10; i++)
	{
		d = rand() % 25;
		*t = Push(d, *t);
	}
}

void Push(Node** tree1, const Node* tree2)
{
	if (tree2 != NULL) {
		Push(tree1, tree2->left);
		*tree1 = Push(tree2->data, *tree1);
		Push(tree1, tree2->right);
	}
}

void Print(Node* t, int lvl)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		Print(t->left, ++lvl);
		for (int i = 0; i < lvl; i++)
		{
			printf_s("|");
		}
		printf_s("%d\n", t->data);
	}
	Print(t->right, ++lvl);
}

void Merge(Node** tree, const Node* tree1, const Node* tree2)
{
	Push(tree, tree1);
	Push(tree, tree2);
}

void Delete(Node** tree, int lvl)
{
	if (lvl == 0 && *tree == NULL)
	{
		return;
	}
	if ((*tree)->right != NULL)
	{
		Delete(&(*tree)->right, lvl + 1);
	}
	if ((*tree)->left != NULL)
	{
		Delete(&(*tree)->left, lvl + 1);
	}
	if (*tree && lvl != 0)
	{
		free(*tree);
	}
	else *tree = NULL;
}



int main()
{
	Node* Tree1 = NULL;
	Node* Tree2 = NULL;
	Node* Tree = NULL;
	PushData(&Tree1);
	PushData(&Tree2);
	printf_s("First tree:\n");
	Print(Tree1, 0);
	printf_s("\nSecond tree:\n");
	Print(Tree2, 0);
	printf_s("\nMerged tree:\n");
	Merge(&Tree, Tree1, Tree2);
	Print(Tree, 0);
	Delete(&Tree1, 0);
	Delete(&Tree2, 0);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

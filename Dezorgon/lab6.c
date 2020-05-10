//  5.2 (1).
// Даны два бинарных дерева поиска. Разработать функцию, которая
//создает одно общее бинарное дерево поиска, исключая
//повторяющиеся элементы.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct TNode 
{
	int data;
	struct TNode* left;
	struct TNode* right;
}  TNode;

TNode* TAdd(struct TNode* tree, int data)
{
	int cond;
	if (tree == NULL)
	{
		tree = (struct TNode*)malloc(sizeof(TNode));
		tree->data = data;
		tree->left = tree->right = NULL;
	}
	else if (data == tree->data);
	else if (data < tree->data)
		tree->left = TAdd(tree->left, data);
	else
		tree->right = TAdd(tree->right, data);
	return tree;
}

void TDel(TNode* tree) 
{
	if (tree != NULL)
	{
		TDel(tree->left);
		TDel(tree->right);
		free(tree);
	}
}

void TPrint(TNode* p)
{
	if (p != NULL) 
	{
		TPrint(p->left);
		printf("%d\n", p->data);
		TPrint(p->right);
	}
}

void TAddData(TNode** tree, int count)
{
	int data ;
	for (int i = 0; i < count; i++)
	{
		scanf_s("%d", &data, 10);
		*tree = TAdd(*tree, data);
	} 
}

void TAddToT(TNode** tree1, const TNode* tree2)
{
	if (tree2 != NULL) {
		TAddToT(tree1, tree2->left);
		*tree1 = TAdd(*tree1, tree2->data);
		TAddToT(tree1, tree2->right);
	}
}

void TSum(TNode** tree, const TNode* tree1, const TNode* tree2)
{
	TAddToT(tree, tree1);
	TAddToT(tree, tree2);
}

int main() 
{
	TNode* tree1 = NULL;
	TNode* tree2 = NULL;

	int count;
	puts("count:");
	scanf_s("%d", &count, 10);
	printf("\n");
	puts("input:");
	TAddData(&tree1, count);
	printf("\n");

	puts("count:");
	scanf_s("%d", &count, 10);
	printf("\n");
	puts("input:");
	TAddData(&tree2, count);
	printf("\n");

	puts("tree1:");
	TPrint(tree1);
	printf("\n");
	puts("tree2:");
	TPrint(tree2);
	printf("\n");
	printf("\n");

	TNode* tree = NULL;
	TSum(&tree, tree1, tree2);
	puts("merged tree:");
	TPrint(tree);

	TDel(tree);
	TDel(tree1);
	TDel(tree2);
}

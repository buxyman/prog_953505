
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define scanf_s scanf

typedef struct Tree
{
	int data;
	struct Tree* left;
	struct Tree* right;
}  Tree;

Tree* add_tree(struct Tree* tree, int data)
{
	int cond;
	if (tree == NULL)
	{
		tree = (struct Tree*)malloc(sizeof(Tree));
		tree->data = data;
		tree->left = tree->right = NULL;
	}
	else if (data == tree->data);
	else if (data < tree->data)
		tree->left = add_tree(tree->left, data);
	else
		tree->right = add_tree(tree->right, data);
	return tree;
}

void delete_tree(Tree* tree) 
{
	if (tree != NULL)
	{
		delete_tree(tree->left);
		delete_tree(tree->right);
		free(tree);
	}
}

void print_tree(Tree* p)
{
	if (p != NULL) 
	{
		print_tree(p->left);
		printf("%d\n", p->data);
		print_tree(p->right);
	}
}

void add_tree_data(Tree** tree, int count)
{
	int data ;
	for (int i = 0; i < count; i++)
	{
		scanf_s("%d", &data, 10);
		*tree = add_tree(*tree, data);
	} 
}

void add_tree_to_tree(Tree** tree1, const Tree* tree2)
{
	if (tree2 != NULL) {
		add_tree_to_tree(tree1, tree2->left);
		*tree1 = add_tree(*tree1, tree2->data);
		add_tree_to_tree(tree1, tree2->right);
	}
}

void tree_sum(Tree** tree, const Tree* tree1, const Tree* tree2)
{
	add_tree_to_tree(tree, tree1);
	add_tree_to_tree(tree, tree2);
}

int main() 
{
	Tree* tree1 = NULL;
	Tree* tree2 = NULL;

	int count;
	printf("count: \n");
	scanf_s("%d", &count, 10);

	printf("input: \n");
	add_tree_data(&tree1, count);

	printf("count: \n");
	scanf_s("%d", &count, 10);

	printf("input: \n");
	add_tree_data(&tree2, count);

	printf("tree1: \n");
	print_tree(tree1);

	printf("tree2: \n");
	print_tree(tree2);

	Tree** tree = NULL;
	tree_sum(&tree, tree1, tree2);

	printf("merged tree:\n");
	print_tree(tree);

	delete_tree(tree);
	delete_tree(tree1);
	delete_tree(tree2);
}
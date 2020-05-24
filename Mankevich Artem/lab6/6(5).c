/* Построить бинарное дерево поиска из букв строки, вводимой
пользователем. Разработать функцию подсчета числа листьев
дерева. */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct tree
{
	char symbol;
	struct tree* left, * right;
} tree;

void Add(tree** node, char x)
{
	if (*node == NULL)
	{
		*node = (tree*)malloc(sizeof(tree));
		(*node)->symbol = x;
		(*node)->left = (*node)->right = NULL;
	}
	else
	{
		if ((*node)->symbol > x)
		{
			Add(&((*node)->left), x);
		}
		else
		{
			Add(&((*node)->right), x);
		}
	}
}

int CountLeaves(tree* root)
{
	int count;
	if (root == NULL)
	{
		count = 0;
	}
	else if ((root->left == NULL) && (root->right == NULL))
	{
		count = 1;
	}
	else
	{
		count = CountLeaves(root->left) + CountLeaves(root->right);
	}
	return count;
}

void FreeMemory(tree* root)
{
	if (root != NULL)
	{
		FreeMemory(root->left);
		FreeMemory(root->right);
		free(root);
	}
}

int main()
{
	int count = 0;
	tree* root = NULL;
	char* str;
	str = (char*)malloc(100 * sizeof(char));

	printf("Input string: ");
	fgets(str, 100, stdin);
	str[strlen(str) - 1] = '\0';
	for (int i = 0; i < 100; i++)
	{
		if (str[i] != '\0')
		{
			Add(&root, str[i]);
		}
		else
		{
			break;
		}
	}
	
	printf("Number of leaves: %d", CountLeaves(root));
	
	free(str);
	FreeMemory(root);
	return 0;
}

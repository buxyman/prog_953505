#include <stdio.h>
#include <malloc.h>

typedef struct node
{
	int number;
	struct node* left;
	struct node* right;
}Node;
typedef struct tree
{
	Node* root;
}Tree;

void insert(int number, Node** root)
{
	if (number < (*root)->number)
	{
		if ((*root)->left != NULL)
		{
			insert(number, &((*root)->left));
		}
		else
		{
			(*root)->left = (Node*)malloc(sizeof(Node));
			(*root)->left->number = number;
			(*root)->left->left = NULL;
			(*root)->left->right = NULL;
		}
	}
	else if (number > (*root)->number)
	{
		if ((*root)->right != NULL)
		{
			insert(number, &((*root)->right));
		}
		else
		{
			(*root)->right = (Node*)malloc(sizeof(Node)); 
			(*root)->right->number = number;
			(*root)->right->left = NULL;
			(*root)->right->right = NULL;
		}
	}
}

void Insert(int number, Node** root)
{
	if (*root != NULL)
	{
		insert(number, root);
	}
	else
	{
		(*root) = (Node*)malloc(sizeof(Node));
		(*root)->number = number;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
}

void ReadFile(Node** root)
{
	FILE* file;
	errno_t err;
	err = fopen_s(&file, "Numbers.txt", "r");
	char varChr;
	int varInt = 0;
	while ((varChr = fgetc(file)) != EOF)
	{
		if (varChr == '-')
		{
			varInt = -1;
			varChr = fgetc(file);
			varInt *= varChr - '0';
		}
		else if (varChr != ' ' && varChr != '\0' && varChr != '\n')
		{
			if (varInt == 0)
			{
				varInt += varChr - '0';
			}
			else if (varInt < 0)
			{
				varInt = varInt * 10 - (varChr - '0');
			}
			else
			{
				varInt = varInt * 10 + (varChr - '0');
			}
		}
		else
		{
			Insert(varInt, root);
			varInt = 0;
		}
	}
}

void printTree(Node** root)
{
	if ((*root) != NULL)
	{
		printf_s("%d ", (*root)->number);
		printTree(&((*root)->left));
		printTree(&((*root)->right));
	}
}

void PrintTree(Node** root)
{
	printf_s("Numbers in the tree: ");
	printTree(root);
	printf_s("\n");
}

int oddNumbers(Node** root)
{
	if (*root == NULL)
	{
		return 0;
	}
	if ((*root)->number % 2 != 0)
	{
		return oddNumbers(&(*root)->left) + oddNumbers(&(*root)->right) + 1;
	}
	else
	{
		return oddNumbers(&(*root)->left) + oddNumbers(&(*root)->right);
	}
}

void PrintOddNumbers(Node** root)
{
	printf_s("Amount of odd numbers in the tree: %d\n", oddNumbers(root));
}

void DeleteTree(Node* root)
{
	if (root != NULL)
	{
		DeleteTree(root->left);
		DeleteTree(root->right);
		free(root);
	}
}

int main()
{
	Tree tree = { NULL };
	ReadFile(&tree.root);
	PrintTree(&tree.root);
	PrintOddNumbers(&tree.root);
	DeleteTree(tree.root);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>

typedef struct node {
	char data;
	struct node* left;
	struct node* right;
} Node;

void AddNode(char data, Node** node);
int NodeCount(Node* node);
void DeleteTree(Node* node);

void AddNode(char data, Node** node)
{
	if (*node == NULL) {
		*node = (Node*)malloc(sizeof(Node));
		(*node)->data = data;
		(*node)->left = (*node)->right = NULL;
	}
	else {
		if (data < (*node)->data)
			AddNode(data, &(*node)->left);
		else if (data > (*node)->data)
			AddNode(data, &(*node)->right);
	}
}

int NodeCount(Node* node)
{
	if (node->left == NULL && node->right == NULL)
		return 1;
	int left, right;
	if (node->left != NULL)
		left = NodeCount(node->left);
	else
		left = 0;
	if (node->right != NULL)
		right = NodeCount(node->right);
	else
		right = 0;
	return left + right + 1;
}

void DeleteTree(Node* node) {
	if (node->left) {
		DeleteTree(node->left);
	}
	if (node->right) {
		DeleteTree(node->right);
	}
	free(node);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char str[80];
	gets_s(str, 80);
	Node* root = NULL;
	for (int i = 0; i < strlen(str); i++) {
		AddNode(str[i], &root);
	}
	printf("Number of nodes = %d", NodeCount(root));
	DeleteTree(root);
}
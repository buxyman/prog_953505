#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

struct TreeNode {
	char txt[256];
	struct TreeNode* left;
	struct TreeNode* right;
};

void create_node(struct TreeNode** root, char msg[256]) {
	if (!(*root = (struct TreeNode*)malloc(sizeof(struct TreeNode)))) {
		puts("Critical error! Unable to allocate memory!");
		_getch();
		exit(0);
	}
	strcpy((*root)->txt, msg);
	(*root)->left = (*root)->right = NULL;
}

int add_item(struct TreeNode** root, char msg[256]) {
	if (!(*root)) {
		create_node(root, msg);
		return 1;
	}

	if (!strcmp((*root)->txt, msg)) {
		return 0;
	}

	else if (strcmp((*root)->txt, msg) > 0) {
		return add_item(&((*root)->left), msg);
	}

	else {
		return add_item(&((*root)->right), msg);
	}
}

void print_inorder(struct TreeNode* root) {
	if (!root) {
		return;
	}

	print_inorder(root->left);
	puts(root->txt);
	print_inorder(root->right);
}

void print_preorder(struct TreeNode* root) {
	if (!root) {
		return;
	}

	puts(root->txt);
	print_preorder(root->left);
	print_preorder(root->right);
}

void print_postorder(struct TreeNode* root) {
	if (!root) {
		return;
	}

	print_postorder(root->left);
	print_postorder(root->right);
	puts(root->txt);
}

int delete_item(struct TreeNode** root, char msg[256]) {
	if (!(*root)) {
		return 0;
	}

	if (!strcmp((*root)->txt, msg)) {

		if (!(*root)->left && !(*root)->right) {
			free(*root);
			*root = NULL;
		}

		else if (!(*root)->left) {
			struct TreeNode* temp = (*root)->right;
			strcpy((*root)->txt, temp->txt);
			(*root)->left = temp->left;
			(*root)->right = temp->right;
			free(temp);
		}

		else if (!(*root)->right) {
			struct TreeNode* temp = (*root)->left;
			strcpy((*root)->txt, temp->txt);
			(*root)->left = temp->left;
			(*root)->right = temp->right;
			free(temp);
		}

		else {
			struct TreeNode* temp = (*root)->right;
			while (temp->left) {
				temp = temp->left;
			}
			strcpy((*root)->txt, temp->txt);
			delete_item(&(*root)->right, temp->txt);
		}

		return 1;
	}

	else if (strcmp((*root)->txt, msg) > 0) {
		return delete_item(&((*root)->left), msg);
	}

	else {
		return delete_item(&((*root)->right), msg);
	}
}

int find(struct TreeNode* root, char msg[256]) {
	if (!root) {
		return 0;
	}

	if (!strcmp(root->txt, msg)) {
		return 1;
	}

	if (strcmp(root->txt, msg) > 0) {
		return find(root->left, msg);
	}

	else {
		return find(root->right, msg);
	}
}
//////////////////////////////////////////
struct StackNode {
	char txt[256];
	struct StackNode* next;
	struct StackNode* prev;
};

void push(struct StackNode** stack_head, char msg[256]) {
	struct StackNode* new_node;
	new_node = (struct StackNode*)malloc(sizeof(struct StackNode));
	if (!new_node) {
		puts("Critical error! Unable to allocate memory!");
		_getch();
		exit(0);
	}	
	strcpy(new_node->txt, msg);
	new_node->prev = NULL;
	if (*stack_head) {
		(*stack_head)->prev = new_node;
	}
	new_node->next = *stack_head;
	*stack_head = new_node;
}

void pop(struct StackNode** stack_head) {
	struct StackNode* curr = *stack_head;
	if (curr == NULL) {
		puts("No more nodes to pop");
		return;
	}
	while (curr->next) {
		curr = curr->next;
	}	
	if (curr == *stack_head) {
		*stack_head = NULL;
	}
	else {
		curr->prev->next = NULL;
	}
	char txt[256];
	strcpy(txt, curr->txt);
	printf("You popped \"%s\"\n", txt);
	free(curr);
}
//////////////////////////////////////////
void build_stack(struct StackNode** stack, struct TreeNode* root) {
	if (!root) {
		return;
	}

	build_stack(stack, root->left);
	push(stack, root->txt);
	build_stack(stack, root->right);
}
//////////////////////////////////////////
void work_with_stack(struct StackNode** stack_head) {
	while (1) {
		puts("Stack menu. Choose a function to call:\n");
		puts("1. Pop\n2. Push\n0. Exit\n-------");
		char choice = _getch();
		if (choice == '0')
			return;

		switch (choice)
		{
		case '1':
			pop(stack_head);
			puts("Press any key to proceed...");
			_getch();
			system("cls");
			break;
		case '2': 
		{
			char buf[256] = "";
			puts("Enter a text to fill in new node (up to 256 characters):");
			gets_s(buf, 256);
			push(stack_head, buf);
			puts("Successfully pushed!");
			puts("Press any key to proceed...");
			_getch();
			system("cls");
			break;
		}
		}
	}
}
/////////////////////////////////////////
int main(void)
{
	struct TreeNode* tree_root = NULL;
	struct StackNode* stack_head = NULL;
	while (1)
	{

		puts("Welcome to menu! Choose an operation number to proceed:\n");
		puts("1. Add node to tree\n2. Print tree inorder");
		puts("3. Print tree preorder\n4. Print tree postorder");
		puts("5. Delete item in the tree\n6. Find item in the tree");
		puts("7. Rebuild tree to stack (opens sub-menu)");
		while (1)
		{
			char choice = _getch();
			if (choice >= '2' && choice <= '4')
			{
				system("cls");
				switch (choice)
				{
				case '2':
					print_inorder(tree_root);
					break;
				case '3':
					print_preorder(tree_root);
					break;
				case '4':
					print_postorder(tree_root);
					break;
				}
			}
			else if (choice == '1') {
				system("cls");
				puts("Enter a text to insert in the tree (up to 256 characters):");
				char txt[256];
				gets_s(txt, 256);
				if (add_item(&tree_root, txt)) {
					puts("Added successfully!");
				}
				else {
					puts("Such an item already exist");
				}
			}
			else if (choice >= '5' && choice <= '6')
			{
				char txt[256];
				system("cls");
				switch (choice)
				{
				case '5':
					puts("Enter the text to delete node with:");
					gets_s(txt, 256);
					if (delete_item(&tree_root, txt)) {
						puts("Successfully deleted item!");
					}
					else {
						puts("No such item found!");
					}
					break;
				case '6':
					puts("Enter the text to find node with:");
					gets_s(txt, 256);
					if (find(tree_root, &txt)) {
						puts("Such an item exists in the tree!");
					}
					else {
						puts("No such item found!");
					}
					break;
				}
			}
			if (choice >= '1' && choice <= '6')
			{
				puts("Press any key to proceed...");
				_getch();
				system("cls");
				break;
			}
			if (choice == '7')
			{
				build_stack(&stack_head, tree_root);
				system("cls");
				work_with_stack(&stack_head);
				return 0;
			}
		}
	}
}

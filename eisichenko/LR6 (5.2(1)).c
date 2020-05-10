#include <stdio.h>
#include <Windows.h>

typedef struct Node // узел дерева
{
	int data;
	struct Node* left;
	struct Node* right;
}Node;

void Add(Node**, int, int); 
void PrintInRightOrder(Node**, int);
void Clear(Node**, int);
void Merge(Node**, Node**);

int CheckInputInt(char[]);
void SetGreenColor();
void SetWhiteColor();

int main()
{
	Node* root1 = NULL;
	Node* root2 = NULL;
	Node** currentRoot = &root1; // указатель на текущий корень

	char buff[1000];

	char key = 'q';
	int data;

	// диалоговое меню
	do
	{
		system("cls");

		if (currentRoot == &root1)
		{
			// установка цвета на светло-зеленый для последующего текста
			SetGreenColor();
		}
		// вывод первого дерева (повернуто на 90 градусов против часовой)
		printf("Tree1 : \n===============================\n\n");
		PrintInRightOrder(&root1, 0);
		printf("\n===============================\n");

		// установка цвета на белый для последующего текста
		SetWhiteColor();

		if (currentRoot == &root2)
		{
			// установка цвета на светло-зеленый для последующего текста
			SetGreenColor();
		}
		// вывод второго дерева (повернуто на 90 градусов против часовой)
		printf("\nTree2 : \n===============================\n\n");
		PrintInRightOrder(&root2, 0);
		printf("\n===============================\n");

		// установка цвета на белый для последующего текста
		SetWhiteColor();

		printf("\n'a' - add\n'c' - clear\n's' - switch the tree\n'm' - merge Tree2 with Tree1\n'q' - quite\n");

		key = getchar();
		rewind(stdin);

		while (key != 'q' && key != 'a' && key != 's'
			&& key != 'c' && key != 'm')
		{
			printf("Invalid input!\n");
			key = getchar();
			rewind(stdin);
		}

		switch (key)
		{
		case 'a':
			printf("\nEnter the data to add : ");
			data = CheckInputInt(buff);
			Add(currentRoot, data, 0);
			break;
		case 'c':
			Clear(currentRoot, 0);
			break;
		case 's':
			if (currentRoot == &root1) currentRoot = &root2;
			else currentRoot = &root1;
			break;
		case 'm':
			Merge(&root1, &root2);
			Clear(&root2, 0);
			break;
		}

	} while (key != 'q');

	Clear(&root1, 0);
	Clear(&root2, 0);
	system("cls");

	return 0;
}

void Add(Node** root, int data, int mergeFlag) // добавление узла
{
	if (*root == NULL)
	{
		*root = (Node*)calloc(1, sizeof(Node));
		(*root)->data = data;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else
	{
		if (data < (*root)->data)
		{
			Add(&(*root)->left, data, mergeFlag);
		}
		else if (data > (*root)->data)
		{
			Add(&(*root)->right, data, mergeFlag);
		}
		else if (!mergeFlag)
		{
			printf("\nIt's already exists\nPress any key to continue...\n");
			getch();
		}
	}
}

void Clear(Node** root, int level) // очистка дерева
{
	if (level == 0 && *root == NULL) return;

	if ((*root)->right != NULL)
		Clear(&(*root)->right, level + 1);

	if ((*root)->left != NULL)
		Clear(&(*root)->left, level + 1);

	if (*root && level != 0) free(*root);
	else *root = NULL;
}

void Merge(Node** root1, Node** root2) // слияние втоорого дерева с первым
{
	if ((*root2)->right != NULL)
	{
		Merge(root1, &(*root2)->right);
	}

	Add(root1, (*root2)->data, 1);

	if ((*root2)->left != NULL)
	{
		Merge(root1, &(*root2)->left);
	}
}

void PrintInRightOrder(Node** root, int level) // вывод дерева (повернуто против часовой на 90 градусов)
{
	if (level == 0 && *root == NULL) return;

	if ((*root)->right != NULL)
		PrintInRightOrder(&(*root)->right, level + 1);

	for (int i = 0; i < level; i++) printf("   ");
	printf("%d\n", (*root)->data);

	if ((*root)->left != NULL)
		PrintInRightOrder(&(*root)->left, level + 1);
}

int CheckInputInt(char buff[]) { // проверка на правильность ввода значения узла 
	int find_char, i, n;

	while (1) {
		find_char = 0;
		gets_s(buff, 1000);
		for (i = 0; i < strlen(buff); i++) {
			if ((buff[i] < '0' || buff[i] > '9') && buff[i] != '-') {
				find_char = 1;
				break;
			}
		}
		if (find_char == 0) n = atoi(buff);

		if (find_char == 0 && n < _CRT_INT_MAX) {
			break;
		}
		else printf("Invalid input!\n");
	}
	return n;
}

void SetGreenColor() // светло-зеленый цвет в консоли
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

void SetWhiteColor() // белый цвет в консоли
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

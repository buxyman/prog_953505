// 5.2.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
/*5.2.1 Даны два бинарных дерева поиска. Разработать функцию, которая
создает одно общее бинарное дерево поиска, исключая
повторяющиеся элементы.
*/
//внутренний правый
#include <stdio.h>
#include <malloc.h>
#include <locale.h>
/* Структура, описывающая узел дерева */
typedef struct item {
	int data;
	struct item* left;
	struct item* right;
} Item;
//-------------------------------
Item* AddNode(item** node, int data);
void DeleteNode(Item** node, int level);
void PrintNode(Item** node, int level);
void AddData(Item** node, int count);
void Merge(Item** root1, Item** root2);
//-------------------------------
int main(void)
{
	setlocale(LC_ALL, "Rus");
	Item* node1 = NULL;
	Item* node2 = NULL;
	int count;

	printf("Введите количество элементов в 1 дереве:\n");
	scanf_s("%d", &count, 10);
	printf("\nВведите эти элементы:\n");
	AddData(&node1, count);
	
	printf("\nТеперь количество для 2 дерева:\n");
	scanf_s("%d", &count, 10);
	printf("\nВведите эти элементы:\n");
	AddData(&node2, count);
	
	printf("\nДерево 1:\n");
	PrintNode(&node1, 0);
	printf("\nДерево 2:\n");
	PrintNode(&node2, 0);

	Merge(&node1, &node2);
	printf("\n\nОбщее дерево исключая повторяющиеся элементы:\n");
	PrintNode(&node1, 0);

	DeleteNode(&node1, 0);
	DeleteNode(&node2, 0);
}
//-------------------------------
/* Добавить узел в бинарное дерево поиска */
Item* AddNode(item** node, int data)
{
	if ((*node) == NULL)
	{
		(*node) = (item*)malloc(sizeof(Item));
		(*node)->data = data;
		(*node)->left = (*node)->right = NULL;
	}
	else if (data == (*node)->data);
	else if (data < (*node)->data)
	{
		(*node)->left = AddNode(&(*node)->left, data);
	}
	else
	{
		(*node)->right = AddNode(&(*node)->right, data);
	}
	return (*node);
}
//-------------------------------
/*Освобождение памяти*/
void DeleteNode(Item** node, int level)
{
	if (level == 0 && (*node) == NULL) return;

	if ((*node)->right != NULL)
	{
		DeleteNode(&(*node)->right, level + 1);
	}
	if ((*node)->left != NULL)
	{
		DeleteNode(&(*node)->left, level + 1);
	}
	if ((*node) && level != 0)
	{
		free(*node);
	}
	else
	{
		(*node) = NULL;
	}
}
//-------------------------------
/*Печать дерева*/
void PrintNode(Item** node, int level)
{
	if (level == 0 && *node == NULL) return;
	if ((*node)->right != NULL)
	{
		PrintNode(&(*node)->right, level + 1);
	}
	for (int i = 0; i < level; i++)
	{
		printf("   ");
	}
	printf("%d\n", (*node)->data);
	if ((*node)->left != NULL)
	{
		PrintNode(&(*node)->left, level + 1);
	}
}
//-------------------------------
/*Ввод данных с клавиатуры*/
void AddData(Item** node, int count)
{
	int data;
	for (int i = 0; i < count; i++)
	{
		scanf_s("%d", &data, 10);
		(*node) = AddNode(&(*node), data);
	}
}
//-------------------------------
/*Слияние  второго дерева с первым*/
void Merge(Item** root1, Item** root2)
{
	if ((*root2)->right != NULL)
	{
		Merge(root1, &(*root2)->right);
	}
	AddNode(root1, (*root2)->data);
	if ((*root2)->left != NULL)
	{
		Merge(root1, &(*root2)->left);
	}
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

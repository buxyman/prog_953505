// 5.1(3).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
/* 5.1.3
С помощью двунаправленного списка определить, является ли
строка палиндромом (т.е. одинаково читается справа налево и слева
направо). Пробелы и знаки пунктуации – игнорировать.
*/
#include <iostream>
#include <stdio.h>
#include <string>
#include <malloc.h>
//структура, описывающая элемент двунаправленного списка
typedef struct item
{
	char Data;
	struct item* Prev;
	struct item* Next;
} Item;
//структура, описывающая строку
typedef struct enteredstring
{
	Item* Head;
	Item* Tail;
	int Length;
} EnteredString;
//------------
EnteredString initString(char* initStr);
void AddChar(EnteredString* entStr, char a);
bool isPalindrom(EnteredString* entStr);
//------------
int main()
{
	system("chcp 1251");
	system("cls");
	printf("Введите строку:\n");
	char* input = (char*)malloc(255);
	fgets(input, 255, stdin);
	EnteredString entStr = initString(input);
	bool pal = isPalindrom(&entStr);
	if (pal)
	{
		printf("Это палиндром\n");
	}
	else
	{
		printf("Это не палиндром\n");
	}
	//освобождение памяти 
	free(input);
	return 0;
}
//------------
EnteredString initString(char* initStr)
{
	EnteredString entStr = { NULL, NULL, 0 };
	int n;
	for (n = strlen(initStr) - 1; n >= 0; n--)
	{
		AddChar(&entStr, initStr[n] - '0');
	}
	return entStr;
}
//------------
void AddChar(EnteredString* entStr, char a)
{
	if (!((a >= 48 && a <= 57) || (a >= 65 && a <= 90) || (a >= 97 && a <= 122))) return;
	Item* p = (Item*)malloc(sizeof(Item));
	p->Data = a;
	p->Next = p->Prev = NULL;
	if (entStr->Head == NULL)
	{
		entStr->Head = entStr->Tail = p;
	}
	else
	{
		entStr->Tail->Next = p;
		p->Prev = entStr->Tail;
		entStr->Tail = p;
	}
	entStr->Length++;
	free(p);
}
//------------
bool isPalindrom(EnteredString* entStr)
{
	if (entStr->Head == NULL)
	{
		return true;
	}
	char* First = (char*)malloc(entStr->Length + 1);
	char* Second = (char*)malloc(entStr->Length + 1);

	Item* curr = entStr->Tail;
	for (int i = 0; i < entStr->Length; i++, curr = curr->Prev)
	{
		First[i] = curr->Data;
	}
	First[entStr->Length] = '\0';

	curr = entStr->Head;
	for (int i = 0; i < entStr->Length; i++, curr = curr->Next)
	{
		Second[i] = curr->Data;
	}
	Second[entStr->Length] = '\0';
	bool result = !strcmp(First, Second);
	free(First);
	free(Second);
	return result;
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

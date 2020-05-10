#include "stdio.h"
#include "time.h";

typedef struct Node
{
	unsigned int data;
	struct Node* pNext;
	struct Node* pPrev;
} Node;

typedef struct List
{
	Node* head;
	Node* tail;
	int size;
} List;

void PushFront(List*, unsigned int);
void PopFront(List*);
void PrintList(List*);
void Clear(List*);
void Pow(List*, int);

int CheckInputInt(char[]);

int main()
{
	int n;
	char buff[1000], key = 'q';
	List* a;

	do
	{
		system("cls");
		a = (List*)malloc(sizeof(List));
		a->head = NULL;
		a->tail = NULL;
		a->size = 0;

		PushFront(a, 1);
		
		printf("Enter N in expression 3^n (0 <= n <= 200 000) : ");
		n = CheckInputInt(buff);

		int time1 = clock();
		Pow(a, n);
		int time2 = clock();

		printf("3^%d == ", n);
		PrintList(a);

		Clear(a);

		printf("Time Elapsed: %f sec\n\n", (float)(time2 - time1)/1000.0);
		printf("'q' - exit\n'c' - continue\n");

		
		key = getchar();
		rewind(stdin);

		while (key != 'q' && key != 'c')
		{
			printf("Invalid input!\n");
			key = getchar();
			rewind(stdin);
		}

	} while (key != 'q');

	system("cls");

	return 0;
}

void PushFront(List* a, unsigned int n)
{
	if (a->size == 0)
	{
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = n;
		newNode->pNext = NULL;
		newNode->pPrev = NULL;

		a->head = newNode;
		a->tail = newNode;

	}
	else
	{
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = n;
		newNode->pNext = a->head;
		newNode->pPrev = NULL;

		a->head->pPrev = newNode;
		a->head = newNode;
	}
	a->size++;
}

void PopFront(List* a)
{

	if (a->size == 1)
	{
		free(a->tail);
		a->size--;
		return;
	}
	if (a->size == 0) return;
	Node* next = a->head->pNext;
	next->pPrev = NULL;

	free(a->head);
	a->head = next;
	a->size--;
}

void PrintList(List* a)
{
	Node* current = a->head;
	while (current != NULL && a->size > 0)
	{
		printf("%u", current->data);
		current = current->pNext;
	}
	printf("\n\n");
}

void Clear(List* a)
{
	while (a->size > 0)
	{
		PopFront(a);
	}
	free(a);
}

void Pow(List* a, int n)
{
	unsigned int dop;
	unsigned int base = 1000000000;
	Node* current;

	for (int i = 0; i < n; i++)
	{
		if (i % 50000 == 0)
		{
			system("cls");
			printf("%d\n", i);
		}
		current = a->tail;
		dop = 0;
		while (current != NULL)
		{
			current->data = current->data * 3 + dop;

			dop = current->data / base;
			current->data = current->data % base;
			if (dop != 0 && current->pPrev == NULL)
			{
				PushFront(a, 0);
			}
			current = current->pPrev;
		}		
	}
}

int CheckInputInt(char buff[]) {
	int find_char, i, n;

	while (1) {
		find_char = 0;
		gets_s(buff, 1000);
		for (i = 0; i < strlen(buff); i++) {
			if (buff[i] < '0' || buff[i] > '9') {
				find_char = 1;
				break;
			}
		}
		if (find_char == 0) n = atoi(buff);

		if (find_char == 0 && n <= 20000000 && n >= 0) {
			break;
		}
		else printf("Invalid input!\n");
	}
	return n;
}
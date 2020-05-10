#pragma once

#include "Account.h"

typedef struct Node
{
	Account data;
	struct Node* pNext;
	struct Node* pPrev;
} Node;

typedef struct List
{
	Node* head;
	Node* tail;
	int size;
} List;

// prototypes

void PushBack(List*, Account);
void PushFront(List*, Account);
void Insert(List*, int, Account);

void PopFront(List*);
void PopBack(List*);
void Delete(List*);

void PrintList(List*);
void Clear(List*);

void Sort(List*);
Account* Find(List*, int); // возвращает узел
int FindIndex(List*, int); // возвращает индекс узла

void SkipMonth(List*); // рассчет процентов для каждого аккаунта
void SkipDay(List*);
void ClearOperations(List*); // очистка всех операций за прошлый год

void WriteToFile(List*, FILE*); // помещает информацию в файл
int ReadFromFile(List*, FILE*); // считывает информацию из файла, возвращает счетчик ID после чтения

// declarations

void PrintList(List* list)
{
	Node* current = list->head;

	while (current != NULL)
	{
		Print(current->data);
		current = current->pNext;
	}
	printf("\n");
}

void PushBack(List* list, Account data)
{
	if (list->head == NULL && list->tail == NULL)
	{
		Node* newNode = (Node*)calloc(1, sizeof(Node));
		newNode->pNext = NULL;
		newNode->pPrev = NULL;
		newNode->data = data;


		list->head = newNode;
		list->tail = newNode;
	}
	else
	{
		Node* newNode = (Node*)calloc(1, sizeof(Node));
		newNode->pNext = NULL;
		newNode->pPrev = list->tail;
		newNode->data = data;

		list->tail->pNext = newNode;
		list->tail = newNode;
	}

	list->size++;
}

void PushFront(List* list, Account data)
{
	if (list->head == NULL && list->tail == NULL)
	{
		Node* newNode = (Node*)calloc(1, sizeof(Node));
		newNode->pNext = NULL;
		newNode->pPrev = NULL;
		newNode->data = data;


		list->head = newNode;
		list->tail = newNode;
	}
	else
	{
		Node* newNode = (Node*)calloc(1, sizeof(Node));
		newNode->pNext = list->head;
		newNode->pPrev = NULL;
		newNode->data = data;

		list->head->pPrev = newNode;
		list->head = newNode;
	}

	list->size++;
}

void Insert(List* list, int index, Account data)
{
	if (index == 0)
	{
		PushFront(list, data);
		return;
	}

	if (index == list->size)
	{
		PushBack(list, data);
		return;
	}

	Node* current;

	if (index < list->size / 2)
	{
		int counter = 0;
		current = list->head;

		while (counter < index)
		{
			current = current->pNext;
			counter++;
		}
	}
	else
	{
		int counter = list->size - 1;
		current = list->tail;

		while (counter > index)
		{
			current = current->pPrev;
			counter--;
		}
	}

	Node* newNode = (Node*)calloc(1, sizeof(Node));

	newNode->pPrev = current->pPrev;
	newNode->pNext = current;

	current->pPrev->pNext = newNode;
	current->pPrev = newNode;

	newNode->data = data;

	list->size++;

}

void PopFront(List* list)
{
	if (list->size == 0) return;

	if (list->size == 1)
	{
		list->head = NULL;
		list->tail = NULL;
		list->size--;
		return;
	}

	Node* toDelete = list->head;
	list->head = list->head->pNext;

	list->head->pPrev = NULL;

	free(toDelete);

	list->size--;
}

void PopBack(List* list)
{
	if (list->size == 0) return;

	if (list->size == 1)
	{
		list->head = NULL;
		list->tail = NULL;
		list->size--;
		return;
	}

	Node* toDelete = list->tail;
	list->tail = list->tail->pPrev;

	list->tail->pNext = NULL;

	free(toDelete);

	list->size--;
}

void Delete(List* list, int index)
{
	if (index == 0)
	{
		PopFront(list);
		return;
	}

	if (index == list->size - 1)
	{
		PopBack(list);
		return;
	}

	Node* current;

	if (index < list->size / 2)
	{
		int counter = 0;
		current = list->head;

		while (counter < index)
		{
			current = current->pNext;
			counter++;
		}
	}
	else
	{
		int counter = list->size - 1;
		current = list->tail;

		while (counter > index)
		{
			current = current->pPrev;
			counter--;
		}
	}

	Node* toDelete = current;

	current->pPrev->pNext = current->pNext;
	current->pNext->pPrev = current->pPrev;

	free(toDelete);

	list->size--;

}

void Clear(List* list)
{
	while (list->size > 0)
	{
		PopFront(list);
	}
}

void Sort(List* list)
{
	for (Node* current1 = list->head; current1 != NULL; current1 = current1->pNext)
	{
		for (Node* current2 = current1; current2 != NULL; current2 = current2->pNext)
		{
			if (current1->data.sum > current2->data.sum)
			{
				Account t = current1->data;
				current1->data = current2->data;
				current2->data = t;
			}
		}
	}
}

Account* Find(List* list, int ID)
{
	Node* current = list->head;

	while (current != NULL)
	{
		if (current->data.ID == ID)
		{
			return &(current->data);
		}
		current = current->pNext;
	}
	return NULL;
}

int FindIndex(List* list, int ID)
{
	int counter = 0;

	Node* current = list->head;

	while (current != NULL)
	{
		if (current->data.ID == ID)
		{
			return counter;
		}
		current = current->pNext;
		counter++;
	}
	return -1;
}

void SkipMonth(List* list)
{
	Node* current = list->head;

	while (current != NULL)
	{
		current->data.sum += (current->data.percentage / 100.0) * current->data.sum;

		current = current->pNext;
	}
}

void SkipDay(List* list)
{
	Node* current = list->head;

	while (current != NULL)
	{
		current->data.sum += (current->data.percentage / 3000.0) * current->data.sum;

		current = current->pNext;
	}
}

void ClearOperations(List* list)
{
	Node* current = list->head;

	while (current != NULL)
	{
		free(current->data.operations);
		current->data.operations = NULL;

		current = current->pNext;
	}
}

void WriteToFile(List* list, FILE* fptr)
{
	Node* current = list->head;

	while (current != NULL)
	{
		fprintf(fptr, "%d\n", current->data.ID);
		fprintf(fptr, "%s\n", current->data.name);
		fprintf(fptr, "%.2lf\n", current->data.sum);
		fprintf(fptr, "%.2lf\n", current->data.percentage);
		fprintf(fptr, "%ld\n", current->data.opened);
		fprintf(fptr, "%d\n", current->data.type);
		fprintf(fptr, "%d\n", current->data.months);
		fprintf(fptr, "%s", current->data.operations);

		if (current->data.operations == NULL) fprintf(fptr, "\n");

		fputs("==================\n", fptr);

		current = current->pNext;
	}
}

int ReadFromFile(List* list, FILE* fptr)
{
	char buff[100];
	int maxID = 0; // подсчет ID после чтения

	while (!feof(fptr))
	{
		Account acc;

		if (fscanf(fptr, "%d", &acc.ID) == EOF) break; // доп проверка на конец файла

		if (maxID < acc.ID) maxID = acc.ID;
		
		acc.name = (char*)calloc(40, sizeof(char));
		fscanf(fptr, "%s", acc.name);
		
		fscanf(fptr, "%lf", &acc.sum);
		fscanf(fptr, "%lf", &acc.percentage);
		fscanf(fptr, "%lld", &acc.opened);
		fscanf(fptr, "%d", &acc.type);
		fscanf(fptr, "%d", &acc.months);

		acc.isChosenForTransaction = 0;
		acc.operations = NULL;

		fgetc(fptr); // пропускаем '\n' в файле
		fgets(buff, 100, fptr);		

		if (strcmp(buff, "(null)\n")) // если не (null) в буффере
		{
			acc.operations = (char*)calloc(100, sizeof(char));
			strcat(acc.operations, buff);

			while (1)
			{
				fgets(buff, 100, fptr);
				
				if (!strcmp(buff, "==================\n")) break; // если конец операций

				acc.operations = (char*)realloc(acc.operations, 100 * sizeof(char));
				strcat(acc.operations, buff);
			}
		}
		else
		{
			fgets(buff, 100, fptr);
		}

		PushBack(list, acc);

		if (feof(fptr)) 
			break;
				
	}

	return maxID + 1;
}

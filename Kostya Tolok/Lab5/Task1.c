//Задание 5.1(8)

//Даны две упорядоченные очереди. Разработать функцию,
//которая объединяет их в один упорядоченный двунаправленный список.

#include <stdio.h>
struct List
{
	int data;
	struct List* next;
	struct List* prev;
};
struct Queue
{
	struct List* start;
	struct List* end;
};
struct List* InitializeElement(int data)
{
	struct List* List;
	List = (struct List*)malloc(sizeof(struct List));
	List->data = data;
	List->next = NULL;
	List->prev = NULL;
	return List;
}
struct List* AddElement(struct List* element, int data)
{
	if (!element)
	{
		element = InitializeElement(data);
		return element;
	}
	struct List* temp;
	temp = (struct List*)malloc(sizeof(struct List));
	element->next = temp;
	temp->data = data;
	temp->next = NULL;
	temp->prev = element;
	return(temp);
}
void ListPrint(struct List* element)
{
	struct List* print;
	print = element;
	while(print)
	{
		printf("%d ", print->data);
		print = print->next;
	}
}
void InitializeQueue(struct Queue* q)
{
	q->start = NULL;
	q->end = NULL;
}
void AddToQueue(struct Queue* q, int data)
{
	if (q->start == NULL && q->end == NULL)
	{
		q->end = InitializeElement(data);
		q->start = q->end;
	}
	else
	{
		q->end = AddElement(q->end, data);
	}
}
void QueuePrint(struct Queue* q)
{
	struct List* element;
	for (element = q->start; element != NULL; element = element->next)
	{
		printf("%d ", element->data);
	}
	return;
}
void DeleteFromQueue(struct Queue* q)
{
	struct List* temp;
	temp = q->start;
	q->start = q->start->next;
	free(temp);
}
struct List* DeleteHead(struct List* root)
{
	struct List* temp;
	temp = root->next;
	temp->prev = NULL;
	free(root);
	return(temp);
}
struct List* ClearList(struct List* list)
{
	while (list->next)
	{
		list = DeleteHead(list);
	}
	free(list);
	list = NULL;
	return list;
}
int main(void)
{
	srand(time(0));
	struct Queue* first_queue, * second_queue;
	struct List* list = NULL;
	first_queue = (struct Queue*)malloc(sizeof(struct Queue));
	second_queue = (struct Queue*)malloc(sizeof(struct Queue));
	InitializeQueue(first_queue);
	InitializeQueue(second_queue);
	int count1 = 0;
	int count2 = 0;
	int amount = 0;
	printf("Enter amount of queue elements: ");
	scanf_s("%d", &amount);
	for (int i = 0; i < amount; i++)
	{
		count1 += rand() % 10 + 1;
		count2 += rand() % 10 + 1;
		AddToQueue(first_queue, count1);
		AddToQueue(second_queue, count2);
	}
	printf("First queue:\n");
	QueuePrint(first_queue);
	printf("\nSecond queue:\n");
	QueuePrint(second_queue);
	while (first_queue->start && second_queue->start)
	{
		if (first_queue->start->data <= second_queue->start->data)
		{
			list = AddElement(list, first_queue->start->data);
			if (first_queue->start != first_queue->end)
			{
				DeleteFromQueue(first_queue);
			}
			else
			{
				while (second_queue->start)
				{
					list = AddElement(list, second_queue->start->data);
					DeleteFromQueue(second_queue);
				}
			}
		}
		else
		{
			list = AddElement(list, second_queue->start->data);
			if (second_queue->start != second_queue->end)
			{
				DeleteFromQueue(second_queue);
			}
			else
			{
				while (first_queue->start)
				{
					list = AddElement(list, first_queue->start->data);
					DeleteFromQueue(first_queue);
				}
			}
		}
	}
	while (list->prev)
	{
		list = list->prev;
	}
	printf("\nList:\n");
	ListPrint(list);
	list = ClearList(list);
}

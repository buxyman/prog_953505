#include "List.h"
#pragma warning(disable : 4996)
void AddElement(List* list, Worker data)
{
	if (!list->head && !list->tail)
	{
		ListNode* element = (ListNode*)malloc(sizeof(ListNode));
		element->next = NULL;
		element->prev = NULL;
		element->data = data;
		list->head = element;
		list->tail = element;
	}
	else
	{
		ListNode* element = (ListNode*)malloc(sizeof(ListNode));
		element->next = NULL;
		element->prev = list->tail;
		element->data = data;
		list->tail->next = element;
		list->tail = element;
	}
	list->size++;
}
void DeleteElement(List* list, int index)
{
	if (list->size == 0)
	{
		return;
	}
	if (index == 1)
	{
		PopFront(list);
	}
	else
	{
		ListNode* previous = list->head;
		for (int i = 1; i < index - 1; i++)
		{
			previous = previous->next;
		}
		ListNode* toDelete = previous->next;
		previous->next = toDelete->next;
		toDelete->next = previous;
		free(toDelete);
		list->size--;
	}
}
ListNode* DeleteNode(List* list, ListNode* node)
{
	ListNode* prev = node->prev, * next = node->next;
	if (prev && next)
	{
		prev->next = next;
		next->prev = prev;
		free(node);
		list->size--;
		return prev;
	}
	else if (!prev)
	{
		PopFront(list);
		return next;
	}
	else if (!next)
	{
		PopBack(list);
		return prev;
	}
}
void PopFront(List* list)
{
	if (list->size == 1)
	{
		free(list->head);
		list->size--;
		list->head = NULL;
		list->tail = NULL;
		return;
	}
	ListNode* temp = list->head;
	list->head = list->head->next;
	list->head->prev = NULL;
	free(temp);
	list->size--;
}
void PopBack(List* list)
{
	if (list->size == 1)
	{
		free(list->tail);
		list->size--;
		list->head = NULL;
		list->tail = NULL;
		return;
	}
	ListNode* temp = list->tail;
	list->tail = list->tail->prev;
	list->tail->next = NULL;
	free(temp);
	list->size--;
}
void ListPrint(List* list)
{
	ListNode* print = list->head;
	int i = 1;
	while (print)
	{
		SetLightBlueColor();
		printf("\n%d-й рабочий: \n", i++);
		Print(print->data);
		print = print->next;
	}
}
void Clear(List* list)
{
	while (list->size > 0)
	{
		PopFront(list);
	}
}

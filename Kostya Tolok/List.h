#pragma once
#include "Worker.h"
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	Worker data;
}ListNode;
typedef struct List
{
	ListNode* head;
	ListNode* tail;
	int size;
}List;
void AddElement(List* list, Worker data);
void DeleteElement(List* list, int num);
void PopFront(List* list);
void PopBack(List* list);
void ListPrint(List* list);
ListNode* DeleteNode(List* list, ListNode* node);
void Clear(List* list);
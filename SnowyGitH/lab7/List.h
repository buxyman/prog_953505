#pragma once
#include "Employee.h"
#include <malloc.h>

#define NULL ((Node*)0)

typedef struct node
{
	node* pNext;
	node* pPrev;
	Employee employee;
}Node;

typedef struct list
{
	Node* head;
	Node* tail;
	int size;
}List;

List Create()
{
	List list = { NULL, NULL, 0 };
	return list;
}

void Copy(List* list, Node* node)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->employee.firstName = _strdup(node->employee.firstName);
	newNode->employee.lastName = _strdup(node->employee.lastName);
	newNode->employee.dateOfBirth.day = node->employee.dateOfBirth.day;
	newNode->employee.dateOfBirth.month = node->employee.dateOfBirth.month;
	newNode->employee.dateOfBirth.year = node->employee.dateOfBirth.year;
	newNode->employee.passport.passportNumber = node->employee.passport.passportNumber;
	newNode->employee.passport.issueDay = node->employee.passport.issueDay;
	newNode->employee.passport.issueMonth = node->employee.passport.issueMonth;
	newNode->employee.passport.issueYear = node->employee.passport.issueYear;
	newNode->employee.passport.expiryDay = node->employee.passport.expiryDay;
	newNode->employee.passport.expiryMonth = node->employee.passport.expiryMonth;
	newNode->employee.passport.expiryYear = node->employee.passport.expiryYear;
	newNode->employee.passport.nationality = _strdup(node->employee.passport.nationality);
	newNode->employee.socialSecurityCard.cardNumber = node->employee.socialSecurityCard.cardNumber;
	newNode->employee.education.degree = _strdup(node->employee.education.degree);
	newNode->employee.position = _strdup(node->employee.position);
	newNode->employee.salary = node->employee.salary;
	newNode->employee.enrollmentDate.day = node->employee.enrollmentDate.day;
	newNode->employee.enrollmentDate.month = node->employee.enrollmentDate.month;
	newNode->employee.enrollmentDate.year = node->employee.enrollmentDate.year;
	newNode->employee.notes.encouragement = _strdup(node->employee.notes.encouragement);
	newNode->employee.notes.penalties = _strdup(node->employee.notes.penalties);
	newNode->employee.status = _strdup(node->employee.status);
	newNode->pNext = newNode->pPrev = NULL;
	if (list->head == NULL)
	{
		list->head = list->tail = newNode;
	}
	else
	{
		list->tail->pNext = newNode;
		newNode->pPrev = list->tail;
		list->tail = newNode;
	}
	list->size++;
}

void AddNode(List* list)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->pNext = newNode->pPrev = NULL;
	if (list->head == NULL)
	{
		list->head = list->tail = newNode;
	}
	else
	{
		list->tail->pNext = newNode;
		newNode->pPrev = list->tail;
		list->tail = newNode;
	}
	list->size++;
}

void ClearEmployee(Node* node)
{
	free(node->employee.firstName);
	free(node->employee.lastName);
	free(node->employee.passport.nationality);
	free(node->employee.education.degree);
	free(node->employee.position);
	free(node->employee.notes.encouragement);
	free(node->employee.notes.penalties);
}

void PopTail(List* list)
{
	Node* toDelete = list->tail;
	if (list->tail->pPrev != NULL)
	{
		list->tail = list->tail->pPrev;
		list->tail->pNext = NULL;
	}
	ClearEmployee(toDelete);
	free(toDelete);
	list->size--;
}

void DeleteNode(Node* node, List* list)
{
	Node* prev = node->pPrev;
	Node* next = node->pNext;
	prev != NULL ? prev->pNext = node->pNext: list->head = next;
	next != NULL ? next->pPrev = node->pPrev: list->tail = prev;
	ClearEmployee(node);
	free(node);
	list->size--;
}

void Clear(List* list)
{
	Node* toDelete;
	while (list->size != 0)
	{
		toDelete = list->tail;
		list->tail = list->tail->pPrev;
		ClearEmployee(toDelete);
		free(toDelete);
		list->size--;
		if (list->size != 0)
		{
			list->tail->pNext = NULL;
		}
		else if (list->size == 0)
		{
			list->head = list->tail = NULL;
		}
	}
}

Node* GetNodeAt(List* list, const int index)
{
	Node* varNode = list->head;
	for (int i = 0; i < list->size; i++)
	{
		if (i  == index - 1)
		{
			return varNode;
		}
		else
		{
			varNode = varNode->pNext;
		}
	}
}

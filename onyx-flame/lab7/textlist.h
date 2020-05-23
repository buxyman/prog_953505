#ifndef TEXTLIST_H_INCLUDED
#define TEXTLIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>


typedef struct listnode
{
    struct listnode* next;
    char* data;
} ListNode;

typedef struct list
{
    ListNode* head;
    ListNode* tail;
    int size;
} List;

List* CreateList()
{
    List* lst = malloc(sizeof(List));
    lst->head = lst->tail = NULL;
    lst->size = 0;
    return lst;
}

void ListPop(List* lst)
{
    if(lst->size == 0) return;
    ListNode* temp = lst->head;
    lst->size--;
    lst->head = temp->next;
    free(temp);
    if(lst->size == 0)
    {
        lst->head = lst->tail = NULL;
    }
}

void DeleteList(List* lst)
{
    while(lst->head != NULL)
    {
        ListPop(lst);
    }
}

char* ListPeek(List* lst)
{
    return lst->head->data;
}

void ListPushBack(List* lst, char* data)
{
    ListNode* temp = malloc(sizeof(ListNode));
    temp->data = data;
    if(lst->tail != NULL)
    {
        lst->tail->next = temp;
    }
    else
    {
        lst->head = temp;
    }
    lst->tail = temp;
    lst->tail->next = NULL;
    lst->size++;
}

ListNode* ListGetNode(List* lst, int index)
{
    ListNode* temp;
    int i = 0;
    temp = lst->head;
    while (temp != NULL && i < index)
    {
        temp = temp->next;
        i++;
    }
    return temp;
}

void ListPrint(List* lst)
{
    ListNode* temp = lst->head;
    while(temp != NULL)
    {
        puts(temp->data);
        temp = temp->next;
    }
}

void ListPrintWithNum(List* lst)
{
    ListNode* temp = lst->head;
    int i = 1;
    while(temp != NULL)
    {
        printf("%d) ", i); puts(temp->data);
        i++;
        temp = temp->next;
    }
}

#endif // TEXTLIST_H_INCLUDED

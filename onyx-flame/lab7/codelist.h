#ifndef CODELIST_H_INCLUDED
#define CODELIST_H_INCLUDED

#include "sourcecode.h"

typedef struct codelistnode
{
    struct codelistnode* next;
    SourceCode* data;
} CodeListNode;

typedef struct codelist
{
    CodeListNode* head;
    CodeListNode* tail;
    int size;
} CodeList;

CodeList* CreateCodeList()
{
    CodeList* lst = malloc(sizeof(CodeList));
    lst->head = lst->tail = NULL;
    lst->size = 0;
    return lst;
}

void CodeListPop(CodeList* lst)
{
    if(lst->size == 0) return;
    CodeListNode* temp = lst->head;
    lst->size--;
    lst->head = temp->next;
    DeleteSourceCode(temp->data);
    free(temp);
    if(lst->size == 0)
    {
        lst->head = lst->tail = NULL;
    }
}

void DeleteCodeList(CodeList* lst)
{
    while(lst->head != NULL)
    {
        CodeListPop(lst);
    }
}

void CodeListPushBack(CodeList* lst, SourceCode* data)
{
    CodeListNode* temp = malloc(sizeof(CodeListNode));
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

void CodeListPrint(CodeList* lst)
{
    CodeListNode* temp = lst->head;
    while(temp != NULL)
    {
        fputs(temp->data->language, stdout); puts(":");
        ListPrint(temp->data->code);
        temp = temp->next;
    }
}

#endif // CODELIST_H_INCLUDED

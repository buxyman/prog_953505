#ifndef ITEMSLIST_H_INCLUDED
#define ITEMSLIST_H_INCLUDED

#include "collection.h"
#include "textlist.h"

typedef struct dlistnode
{
    struct dlistnode* next;
    struct dlistnode* prev;
    Item* data;
} DListNode;

typedef struct dlist
{
    DListNode* head;
    DListNode* tail;
    int size;
} DList;


DList* CreateDList()
{
    DList* temp = (DList*)malloc(sizeof(DList));
    temp->head = temp->tail = NULL;
    temp->size = 0;
    return temp;
}

void DListPushBack(DList* lst, Item* x)
{
    DListNode* temp = (DListNode*)malloc(sizeof(DListNode));
    temp->data = x;
    temp->next = NULL;
    temp->prev = lst->tail;
    if (lst->tail != NULL)
    {
        lst->tail->next = temp;
    }
    lst->tail = temp;
    if (lst->head == NULL)
    {
        lst->head = temp;
    }
    lst->size++;
}

void DListPop(DList* lst)
{
    DListNode* del = lst->head;
    lst->head = lst->head->next;
    if (lst->head != NULL)
    {
        lst->head->prev = NULL;
    }
    if (del == lst->tail)
    {
        lst->head = lst->tail = NULL;
    }
    DeleteArticle(del->data->article);
    DeleteCommentList(del->data->comments);
    DeleteCodeList(del->data->sourceCodes);
    free(del);
    lst->size--;
}

void DeleteDList(DList* lst)
{
    while(lst->head != NULL)
    {
        DListPop(lst);
    }
}

DListNode* DListGetNode(DList* lst, int index)
{
    DListNode* temp;
    int i;
    if (index < lst->size/2)
    {
        i = 0;
        temp = lst->head;
        while (temp != NULL && i < index)
        {
            temp = temp->next;
            i++;
        }
    }
    else if(index < lst->size)
    {
        i = lst->size - 1;
        temp = lst->tail;
        while (temp != NULL && i > index)
        {
            temp = temp->prev;
            i--;
        }
    }
    return temp;
}

void DListPrintItem(DListNode* temp)
{
    printf("\t"); puts(temp->data->article->title);
    printf("Theme:\t\t"); puts(temp->data->article->theme);
    printf("Dated:\t\t"); puts(temp->data->article->date);
    printf("Languages: \t"); puts(temp->data->article->languages);
    puts("");
    ListPrint(temp->data->article->text);
    puts("\nSource:\n");
    CodeListPrint(temp->data->sourceCodes);
    printf("\nComments(%d):\n\n", temp->data->comments->size);
    CommentListPrint(temp->data->comments);
}

#endif // ITEMSLIST_H_INCLUDED

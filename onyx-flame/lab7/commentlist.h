#ifndef COMMENTLIST_H_INCLUDED
#define COMMENTLIST_H_INCLUDED

#include "comment.h"

typedef struct commentlistnode
{
    struct commentlistnode* next;
    Comment* data;
} CommentListNode;

typedef struct commentlist
{
    CommentListNode* head;
    CommentListNode* tail;
    int size;
} CommentList;

CommentList* CreateCommentList()
{
    CommentList* lst = malloc(sizeof(CommentList));
    lst->head = lst->tail = NULL;
    lst->size = 0;
    return lst;
}

void CommentListPop(CommentList* lst)
{
    if(lst->size == 0) return;
    CommentListNode* temp = lst->head;
    lst->size--;
    lst->head = temp->next;
    DeleteComment(temp->data);
    free(temp);
    if(lst->size == 0)
    {
        lst->head = lst->tail = NULL;
    }
}

void DeleteCommentList(CommentList* lst)
{
    while(lst->head != NULL)
    {
        CommentListPop(lst);
    }
}

void CommentListPushBack(CommentList* lst, Comment* data)
{
    CommentListNode* temp = malloc(sizeof(CommentListNode));
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

CommentListNode* CommentListGetNode(CommentList* lst, int index)
{
    CommentListNode* temp;
    int i = 0;
    temp = lst->head;
    while (temp != NULL && i < index)
    {
        temp = temp->next;
        i++;
    }
    return temp;
}

void CommentListPrint(CommentList* lst)
{
    CommentListNode* temp = lst->head;
    int i=0;
    while(temp != NULL)
    {
        printf("#%d ", i++); fputs(temp->data->user, stdout); puts(" wrote:\n");
        ListPrint(temp->data->text);
        puts("\n");
        temp = temp->next;
    }
}

#endif // COMMENTLIST_H_INCLUDED

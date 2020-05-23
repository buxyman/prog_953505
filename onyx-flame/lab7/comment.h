#ifndef COMMENT_H_INCLUDED
#define COMMENT_H_INCLUDED

#include "textlist.h"

typedef struct comm
{
    char* title;
    char* user;
    List* text;
} Comment;

Comment* CreateComment()
{
    Comment* temp = (Comment*)malloc(sizeof(Comment));
    temp->text = CreateList();
    return temp;
}

void DeleteComment(Comment* temp)
{
    DeleteList(temp->text);
    free(temp->user);
    free(temp->title);
    free(temp);
}

#endif // COMMENT_H_INCLUDED

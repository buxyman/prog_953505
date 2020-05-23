#ifndef COLLECTION_H_INCLUDED
#define COLLECTION_H_INCLUDED

#include "article.h"
#include "codelist.h"
#include "commentlist.h"

typedef struct item
{
    Article* article;
    CodeList* sourceCodes;
    CommentList* comments;
} Item;

Item* CreateItem()
{
    Item* temp = (Item*)malloc(sizeof(Item));
    temp->article = (Article*)malloc(sizeof(Article));
    temp->sourceCodes = CreateCodeList();
    temp->comments = CreateCommentList();
    return temp;
}

#endif // COLLECTION_H_INCLUDED

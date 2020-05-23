#ifndef FILEOPERATIONS_H_INCLUDED
#define FILEOPERATIONS_H_INCLUDED
#include "textlist.h"
#include "article.h"
#include "collection.h"
#include "itemslist.h"
#include "codelist.h"
#include "sourcecode.h"
#include "comment.h"
#include "commentlist.h"

void ReadArticles(DList* collectionOfItems)
{
    int strSize = 50;
    char* str = (char*)malloc(strSize*sizeof(char));
    FILE* fp = fopen("articles.txt", "r");
    int i = 0;
    Item* forFill;
    List* tempie = CreateList();
    while (!feof(fp))
    {
        fscanf(fp,"%c",&str[i]);
        if(str[i] == '\n' || feof(fp))
        {
            str[i] = '\0';
            if((strlen(str) == 3 && str[0] == '#' && str[1] == '#' && str[2] == '#') || feof(fp))
            {
                if(feof(fp))
                {
                    ListPushBack(tempie, str);
                }
                forFill = CreateItem();
                forFill->article->title = strdup(ListPeek(tempie));
                ListPop(tempie);
                forFill->article->theme = strdup(ListPeek(tempie));
                ListPop(tempie);
                forFill->article->date = strdup(ListPeek(tempie));
                ListPop(tempie);
                forFill->article->languages = strdup(ListPeek(tempie));
                ListPop(tempie);
                forFill->article->text = tempie;
                DListPushBack(collectionOfItems, forFill);
                tempie = CreateList();
                str = (char*)malloc(strSize*sizeof(char));
                i = 0;
                continue;
            }
            str = (char*)realloc(str, (i+1)*sizeof(char));
            ListPushBack(tempie, str);
            str = (char*)malloc(strSize*sizeof(char));
            i = 0;
            continue;
        }
        i++;
        if(i>=strSize)
        {
            strSize*=2;
            str = (char*)realloc(str, strSize*sizeof(char));
        }
    }
    fclose(fp);
    free(str);
}

void ReadSourceCodes(DList* collectionOfItems)
{
    int strSize = 50;
    char* str = (char*)malloc(strSize*sizeof(char));
    FILE* fp = fopen("source.txt", "r");
    int i = 0;
    SourceCode* forFill;
    List* tempie = CreateList();
    while (!feof(fp))
    {
        fscanf(fp,"%c",&str[i]);
        if(str[i] == '\n' || feof(fp))
        {
            str[i] = '\0';
            if((strlen(str) == 3 && str[0] == '#' && str[1] == '#' && str[2] == '#') || feof(fp))
            {
                if(feof(fp))
                {
                    ListPushBack(tempie, str);
                }
                DListNode* pos = collectionOfItems->head;
                while(pos != NULL)
                {
                    if(strcmp(pos->data->article->title,ListPeek(tempie)) == 0) break;
                    pos = pos->next;
                }
                if(pos != NULL)
                {
                    forFill = CreateSourceCode();
                    forFill->title = strdup(ListPeek(tempie));
                    ListPop(tempie);
                    forFill->language = strdup(ListPeek(tempie));
                    ListPop(tempie);
                    forFill->code = tempie;
                    CodeListPushBack(pos->data->sourceCodes, forFill);
                }
                tempie = CreateList();
                str = (char*)malloc(strSize*sizeof(char));
                i = 0;
                continue;
            }
            str = (char*)realloc(str, (i+1)*sizeof(char));
            ListPushBack(tempie, str);
            str = (char*)malloc(strSize*sizeof(char));
            i = 0;
            continue;
        }
        i++;
        if(i>=strSize)
        {
            strSize*=2;
            str = (char*)realloc(str, strSize*sizeof(char));
        }
    }
    fclose(fp);
    free(str);
}

void ReadComments(DList* collectionOfItems)
{
    int strSize = 50;
    char* str = (char*)malloc(strSize*sizeof(char));
    FILE* fp = fopen("comments.txt", "r");
    int i = 0;
    Comment* forFill;
    List* tempie = CreateList();
    while (!feof(fp))
    {
        fscanf(fp,"%c",&str[i]);
        if(str[i] == '\n' || feof(fp))
        {
            str[i] = '\0';
            if((strlen(str) == 3 && str[0] == '#' && str[1] == '#' && str[2] == '#') || feof(fp))
            {
                if(feof(fp))
                {
                    ListPushBack(tempie, str);
                }
                DListNode* pos = collectionOfItems->head;
                while(pos != NULL)
                {
                    if(strcmp(pos->data->article->title,ListPeek(tempie)) == 0) break;
                    pos = pos->next;
                }
                if(pos != NULL)
                {
                    forFill = CreateComment();
                    forFill->title = strdup(ListPeek(tempie));
                    ListPop(tempie);
                    forFill->user = strdup(ListPeek(tempie));
                    ListPop(tempie);
                    forFill->text = tempie;
                    CommentListPushBack(pos->data->comments, forFill);
                }
                tempie = CreateList();
                str = (char*)malloc(strSize*sizeof(char));
                i = 0;
                continue;
            }
            str = (char*)realloc(str, (i+1)*sizeof(char));
            ListPushBack(tempie, str);
            str = (char*)malloc(strSize*sizeof(char));
            i = 0;
            continue;
        }
        i++;
        if(i>=strSize)
        {
            strSize*=2;
            str = (char*)realloc(str, strSize*sizeof(char));
        }
    }
    fclose(fp);
    free(str);
}


#endif // FILEOPERATIONS_H_INCLUDED 

#ifndef SOURCECODE_H_INCLUDED
#define SOURCECODE_H_INCLUDED

#include "codelist.h"

typedef struct sc
{
    char* title;
    char* language;
    List* code;
} SourceCode;

SourceCode* CreateSourceCode()
{
    SourceCode* temp = (SourceCode*)malloc(sizeof(SourceCode));
    temp->code = CreateList();
    return temp;
}

void DeleteSourceCode(SourceCode* temp)
{
    DeleteList(temp->code);
    free(temp->title);
    free(temp->language);
    free(temp);
}

#endif // SOURCECODE_H_INCLUDED

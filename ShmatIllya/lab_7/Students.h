#pragma once
#include "Blocks.h"
#include "Delete.h"
#include "Search.h"
#include "Output.h"
#include "Personal.h"
enum e{FCP, FCSAS, FI, IIT, FRIE};
struct Student { char name[100]; char sername[100]; char middle_name[100]; enum e faculty; char course[100]; long int group; int violations; struct Student* next; };
struct Queue1
{
    struct Student* first1;
    struct Student* last1;
};
struct Queue1 Q1;
void Blocks_Students_Add();
void Students_main();
void Students_Creation();
void Students_Add();
void Students_Print();


#pragma once
#include "Students.h"
struct Rooms { int num; int status; struct Student* st;};
struct Blocks { int block_numer; struct Rooms floors_array[5][20]; struct Blocks* next; };
struct Queue
{
    struct Blocks* first;
    struct Blocks* last;
};
struct Queue Q2;
void Blocks_main();
void Creation();
void Add();
void Del_All_2(struct Blocks* h);


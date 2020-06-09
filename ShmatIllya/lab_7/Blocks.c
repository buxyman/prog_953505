#include "Blocks.h"
#include <malloc.h>
int value = 1;
void Creation()
{
    Q2.first = malloc(1 * sizeof(struct Blocks));
    Q2.first->next = NULL;
    Q2.last = Q2.first;
    Q2.last->block_numer = value;
    value++;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            Q2.last->floors_array[i][j].st = malloc(sizeof(struct Student));
            Q2.last->floors_array[i][j].num =(i+1)*100+j;
            Q2.last->floors_array[i][j].status = 0;
        }
    }
}
void Add()
{
    Q2.last->next = malloc(1 * sizeof(struct Blocks));
    Q2.last = Q2.last->next;
    Q2.last->block_numer = value;
    value++;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 20; j++)
        {  
            Q2.last->floors_array[i][j].st = malloc(sizeof(struct Student));
            Q2.last->floors_array[i][j].num = (i + 1) * 100 + j;
            Q2.last->floors_array[i][j].status = 0;
        }
    }
    Q2.last->next = NULL;
}
void Del_All_2(struct Blocks* h)
{
    if (h != NULL)
    {
        Del_All_2(h->next);
        free(h);
    }
}
void Blocks_main()
{
    Creation();
    for (int i = 0; i < 4; i++)
    {
        Add();
    }
}

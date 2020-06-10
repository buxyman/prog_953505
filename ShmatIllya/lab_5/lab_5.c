#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <locale.h>
//=================== Вариант 23==================
struct Node
{
int data;
struct Node *next;
};
 struct Queue
{
int size;
struct Node *first;
struct Node *last;
};
void Creation(struct Queue *Q)
{
Q->first=malloc(1*sizeof(struct Node));
Q->first->next=NULL;
Q->last=Q->first;
Q->size=0;
}
void Add(struct Queue *Q)
{
int value;
value=rand()%10;
Q->last->next=malloc(1*sizeof(struct Node));
Q->last=Q->last->next;
Q->last->data=value;
Q->last->next=NULL;
Q->size++;
}
void Sort (struct Queue *Q)
{
struct Node *h;
for (int i=0;i<10;i++)
{
for (h=Q->first; h->next!=NULL; h=h->next)
{
 if (h->data>h->next->data)
 {
     int temp=h->data;
     h->data=h->next->data;
     h->next->data=temp;
 }
}
}
}
void Task (struct Queue *Q1, struct Queue *Q2, struct Queue *Q3)
{
  struct Node *h1;
  struct Node *h2;
  for (h1=Q1->first; h1->next!=NULL; h1=h1->next)
  {
      for (h2=Q2->first; h2->next!=NULL; h2=h2->next)
      {
          if (h1->data==h2->data)
          {
              h1->data=-10;
              h2->data=-10;
              break;
          }
      }
  }
  for (h1=Q1->first; h1!=NULL; h1=h1->next)
  {
      if (h1->data!=-10)
      {
Q3->last->next=malloc(1*sizeof(struct Node));
Q3->last=Q3->last->next;
Q3->last->data=h1->data;
Q3->last->next=NULL;
Q3->size++;
      }
  }
  Q3->last->data=-10;
  for (h2=Q2->first; h2!=NULL; h2=h2->next)
  {
      if (h2->data!=-10)
      {
Q3->last->next=malloc(1*sizeof(struct Node));
Q3->last=Q3->last->next;
Q3->last->data=h2->data;
Q3->last->next=NULL;
Q3->size++;
      }
  }
  Q3->first=Q3->first->next;
  struct Node *h3;
for (int i=0;i<10;i++)
{
for (h3=Q3->first; h3->next!=NULL; h3=h3->next)
{
 if (h3->data>h3->next->data)
 {
     int temp=h3->data;
     h3->data=h3->next->data;
     h3->next->data=temp;
 }
}
}
Q3->first=Q3->first->next;

}
void Print (struct Queue *Q)
{
    struct Node *h;
    for (h=Q->first; h->next!=NULL; h=h->next)
    {
        printf("%d ", h->data);
    }
    printf("\n");
}
int main()
{
setlocale(LC_ALL,"Rus");
struct Queue Q1;
struct Queue Q2;
struct Queue Q3;
Creation(&Q1);
Creation(&Q2);
Creation(&Q3);
srand(time(NULL));
for (int i=0;i<=10;i++)
{
    Add(&Q1);
    Add(&Q2);
}
Sort(&Q1);
Sort(&Q2);
Print(&Q1);
Print(&Q2);
printf("\n");
Task(&Q1,&Q2,&Q3);
printf("\n");
Print(&Q3);
return 0;
}


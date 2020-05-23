#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>
#include "fileoperations.h"

bool IsNumber(char* txt)
{
    int i;
    if(strlen(txt) == 0) return false;
    for(i=0; i<strlen(txt); i++)
    {
        if(!isdigit(txt[i])) return false;
    }
    return true;
}

int main()
{
    system("chcp 1251");
    system("cls");
    DList* collectionOfItems = CreateDList();
    ReadArticles(collectionOfItems);
    ReadSourceCodes(collectionOfItems);
    ReadComments(collectionOfItems);
    char choice; 
    char* t;
    while(true)
    {
        printf("1. Выбор статьи и редактирование комментариев.\n");
        printf("2. Выбор статьи по тематике. \n");
        printf("3. Выход");
        choice = getche();
        system("cls");
        if(choice == '1' || choice == 97)
        {
            puts("Введите нужное число для выбора статьи:");
            DListNode* temp = collectionOfItems->head;
            int i = 1;
            while(temp != NULL)
            {
                printf("%d) ", i); puts(temp->data->article->title);
                i++;
                temp = temp->next;
            }
            int num = -1;
            printf("Введите номер желаемой статьи: "); 
            while(num<1 || num>(collectionOfItems->size))
            {
                t = (char*)malloc(10);
                fgets(t,5,stdin);
                t[strlen(t)-1] = '\0';
                if(IsNumber(t))
                {
                    num = atoi(t);
                    if(num>=1 && num<= collectionOfItems->size)
                    {
                        free(t);
                        break;
                    }
                }
                printf("\nОшибка при вводе. Повторите снова: ");
            }
            free(t);
            system("cls");
            DListPrintItem(DListGetNode(collectionOfItems, num-1));
            puts("1. Добавить комментарий");
            puts("2. Изменить комментарий");
            char r = getch();
            if(r == '1' || r == 97)
            {
                Comment* t = CreateComment();
                printf("Добавление нового комментария...\n");
                t->title = strdup(DListGetNode(collectionOfItems, num-1)->data->article->title);
                char* string = (char*)malloc(100);
                printf("Введите имя пользователя: ");
                fgets(string,100,stdin);
                string[strlen(string)-1] = '\0';
                t->user = strdup(string);
                printf("Введите сообщение: ");
                fgets(string,100,stdin);
                ListPushBack(t->text, string);
                CommentListPushBack(DListGetNode(collectionOfItems,num-1)->data->comments, t);
            }
            else if(r == '2' || r == 98)
            {
                int k=-1, curr=0;
                printf("Введите ID комментария: ");
                scanf("%d",&k);
                CommentListNode* edit = DListGetNode(collectionOfItems, num-1)->data->comments->head;
                while(edit != NULL && curr != k)
                {
                    edit = edit->next;
                }

                puts("1. Изменить ник комментатора");
                puts("2. Изменить комментарий");
                char w = getch();
                char trash;
                if(w == '1' || w == 97)
                {
                    scanf("%c", &trash);
                    char* string = (char*)malloc(100);
                    printf("Enter user: ");
                    fgets(string,100,stdin);
                    string[strlen(string)-1] = '\0';
                    puts(string);
                    edit->data->user = strdup(string);
                }
                else if(w == '2' || w == 98)
                {
                    char* string = (char*)malloc(100);
                    char litter = scanf("%c", &litter);
                    printf("Enter message: ");
                    fgets(string,100,stdin);
                    string[strlen(string)-1] = '\0';
                    while(edit->data->text->head != NULL)
                    {
                        ListPop(edit->data->text);
                    }
                    ListPushBack(edit->data->text, string);
                }
                else
                {
                    continue;
                }
            }
            getch();
        }
        else if(choice == '2' || choice == 98)
        {
            List* tempie = CreateList();
            DListNode* temp = collectionOfItems->head;
            while(temp != NULL)
            {
                if(tempie->size == 0) ListPushBack(tempie,strdup(temp->data->article->theme));
                int counter = 0;
                ListNode* start = tempie->head;
                while(start != NULL)
                {
                    if(strcmp(temp->data->article->theme, start->data) == 0) counter++;
                    start = start->next;
                }
                if(counter == 0) ListPushBack(tempie,strdup(temp->data->article->theme));
                temp = temp->next;
            }
            puts("Список тем по статьям:");
            ListPrintWithNum(tempie);
            printf("\nВыберите одну из них: ");
            int themeIndex = 0;
            while(themeIndex<1 || themeIndex>(tempie->size))
            {
                t = (char*)malloc(10);
                fgets(t,5,stdin);
                t[strlen(t)-1] = '\0';
                if(IsNumber(t))
                {
                    themeIndex = atoi(t);
                    if(themeIndex>=1 && themeIndex<= (tempie->size))
                    {
                        free(t);
                        break;
                    }
                }
                printf("\nОшибка при вводе. Повторите снова: ");
            }
            free(t);
            temp = collectionOfItems->head;
            List* themeTop = CreateList();
            while(temp != NULL)
            {
                if(strcmp(temp->data->article->theme, ListGetNode(tempie,themeIndex-1)->data) == 0)
                {
                    ListPushBack(themeTop, temp->data->article->title);
                }
                temp = temp->next;
            }
            puts("\nСписок статей по заданной теме:");
            ListPrintWithNum(themeTop);
            printf("\nВыберите статью: ");
            int ko = 0;
            while(ko<1 || ko>(themeTop->size))
            {
                t = (char*)malloc(10);
                fgets(t,5,stdin);
                t[strlen(t)-1] = '\0';
                if(IsNumber(t))
                {
                    ko = atoi(t);
                    if(ko>=1 && ko<= (themeTop->size))
                    {
                        free(t);
                        break;
                    }
                }
                printf("\nОшибка при вводе. Повторите снова: ");
            }
            temp = collectionOfItems->head;
            while(temp != NULL)
            {
                if(strcmp(temp->data->article->title,ListGetNode(themeTop,ko-1)->data) == 0) break;
                temp = temp->next;
            }
            system("cls");
            DListPrintItem(temp);
            getch();
        }
        else if(choice == '3' || choice == 99)
        {
            FILE* fp = fopen("comma.txt", "w");
            DListNode* temp = collectionOfItems->head;
            while(temp != NULL)
            {
                CommentListNode* k = temp->data->comments->head;
                while(k != NULL)
                {
                    fputs(k->data->title,fp); fputs("\n",fp);
                    fputs(k->data->user,fp);  fputs("\n",fp);
                    ListNode* w = k->data->text->head;
                    while(w != NULL)
                    {
                        fputs(w->data,fp); fputs("\n", fp);
                        w = w->next;
                    }
                    fputs("###\n",fp);
                    k = k->next;
                }
                temp= temp->next;
            }
            DeleteDList(collectionOfItems);
            break;
        }
        system("cls");
    }
    return 0;
}

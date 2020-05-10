//IDE: CodeBlocks
//Task 5.2(30)
/*
Напишите программу, которая вводит строку текста, разделяет
предложение на отдельные слова, вставляет слова в бинарное
дерево поиска, а затем распечатывает их, обходя дерево слева и
справа.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

typedef struct item //структура узла дерева поиска
{
    char* data; //содержимое узла - строка
    struct item* left;  //указатель на левую ветвь узла
    struct item* right; //указатель на правую ветвь узла
} Item;

void AddNode(char* x, Item** root)  //добавление строки в дерево поиска
{
    if (*root == NULL)  //если узел пуст
    {
        *root = (Item*)malloc(sizeof(Item));    //выделяем память под узел
        (*root)->data = x;  //устанавливаем значение узла
        (*root)->left = (*root)->right = NULL;  //зануляем указатели на ветви
    }
    //иначе, дерево непустое
    else if (strcmp(x,(*root)->data) < 0)   //если x меньше значения узла
    {
        AddNode(x, &((*root)->left));   //рекурсивно вызываем эту же фукнцию, но пробуем добавить x в узел в левой ветви root
    }
    else if (strcmp(x,(*root)->data) > 0)   //если x больше значения узла
    {
        AddNode(x, &((*root)->right));  //рекурсивно вызываем эту же фукнцию, но пробуем добавить x в узел в правой ветви root
    }
    else    //иначе пишем сообщение, что такое слово уже добавлено в дерево поиска
    {
        printf("Word \"%s\" is already included in search tree, so it wasn't added once again\n", x);
    }
}

void LeftOrder(Item** node) //функция обхода дерева слево направо
{
    if((*node) != NULL) //если узел непустой
    {
        LeftOrder(&((*node)->left));    //рекурсивно спускаемся в самую левую ветвь узла
        printf("%s ", (*node)->data);   //печатаем содержимое
        LeftOrder(&((*node)->right));   //рекурсивно спускаемся в самую правую ветвь узла
    }
}

void RightOrder(Item** node)    //функция обхода дерева справо налево
{
    if((*node) != NULL) //если узел непустой
    {
        LeftOrder(&((*node)->right));  //рекурсивно спускаемся в самую правую ветвь узла
        printf("%s ", (*node)->data);  //печатаем содержимое
        LeftOrder(&((*node)->left));   //рекурсивно спускаемся в самую левую ветвь узла
    }
}

void FillTree(Item** root, char* str)
{
    int count = 0;  //счетчик длины слова
    int isEmpty = 1;    //флаг пустоты дерева
    int temp;   //временный INT
    for(int i=0; i<strlen(str); i++)
    {
        if(str[i] == ' ') continue; //скипаем пробелы
        int t = i;  //запоминаем положение первого символа
        while(str[t] != ' ' && t != strlen(str))    //вычисляем длину слова
        {
            t++;
            count++;
        }
        char* word = (char*)malloc(count+1);    //выделяем память под слово
        for(int j=0; j<count; j++, i++) //копируем символы в word
        {
            word[j] = str[i];
        }
        word[count] = '\0'; //нуль-терминатор в конце строки
        AddNode(word,root); //добавляем word в дерево поиска
        count = 0;  //зануляем счётчик слов
    }
}

void DeleteTree(Item* root) //функция очистки дерева
{
    if(root != NULL) //спускаемся вниз по дереву и рекурсивно удаляем элементы
    {
        DeleteTree(root->left);
        DeleteTree(root->right);
        free(root);
    }
}

int main()
{
    system("chcp 1251");
    system("cls");
    Item* root = NULL;  //начальный указатель на дерево
    printf("Введите строку:\n");
    char* t = (char*)malloc(500);   //выделение памяти под строку
    gets(t);    //считывание строки
    FillTree(&root,t);  //заполнение дерева строкой t
    free(t);    //освобождение памяти
    if(root != NULL)    //если дерево непустое, делаем обходы
    {
        printf("\n\nОбход слева направо:\n");
        LeftOrder(&root);
        printf("\n\nОбход справо налево:\n");
        RightOrder(&root);
        printf("\n");
    }
    else    //иначе пишем ошибку
    {
        printf("Дерево пустое!\n");
    }
    DeleteTree(root);   //очистка дерева
    return 0;
}

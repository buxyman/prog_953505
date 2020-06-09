//IDE: VisualStudio
//Task 6(5.2(16))
/*
Построить бинарное дерево поиска из букв строки, вводимой пользователем. 
Разработать функцию, подсчитывающую, сколько уровней содержит дерево.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct Node
{
    char type;
    Node* left, * right;
};

struct Tree
{
    Node* base;
};

Tree* CreateTree()
{
    Tree* temp = (Tree*)malloc(sizeof(Tree));
    if (!temp)exit(0);
    temp->base = NULL;
    return temp;
}

Node* Func_search(Node* n, char c)
{
    if (c < n->type)
    {
        if (!n->left)
        {
            n->left = (Node*)malloc(sizeof(Node));
            if (!n->left) exit(0);
            return n->left;
        }
        else return Func_search(n->left, c);
    }
    else
    {
        if (!n->right)
        {
            n->right = (Node*)malloc(sizeof(Node));
            if (!n->right)
                exit(0);
            return n->right;
        }
        else return Func_search(n->right, c);
    }
}

void Add(Tree* t, char a)
{
    if (!t->base)
    {
        t->base = (Node*)malloc(sizeof(Node));
        if (!t->base)
            exit(0);
        t->base->type = a;
        t->base->left = NULL;
        t->base->right = NULL;
        return;
    }
    else
    {
        Node* n = Func_search(t->base, a);
        n->type = a;
        n->left = NULL;
        n->right = NULL;
        return;
    }
}

void print_tree(Node* a, int level = 0)
{
    if (a)
    {
        print_tree(a->left, level + 1);
        for (int i = 0; i < level; i++)
            printf("  ");
        printf("%c\n", a->type);
        print_tree(a->right, level + 1);
    }
}

void remove_tree(Node* a)
{
    if (!a)
        return;
    remove_tree(a->left);
    remove_tree(a->right);
    free(a);
    return;
}

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int Depth(Node* a, int count = 0)
{
    if (!a)
        return count;
    else
        return max(Depth(a->left, count + 1), Depth(a->right, count + 1));
}

int main()
{
    setlocale(LC_ALL, "rus");
    Tree* T = CreateTree();
    char* str = (char*)malloc(100 * sizeof(char));
    if (!str)
        exit(1);
    printf("\nВведите строку символов: ");
    fgets(str, 100, stdin);
    str[strlen(str) - 1] = '\0';
    for (int i = 0; str[i]; i++)
        Add(T, str[i]);
    free(str);
    printf("\nСоставленное дерево:\n");
    print_tree(T->base);
    printf("\nКоличество уровней дерева: %d\n", Depth(T->base));
    remove_tree(T->base);
    free(T);
    return 0;
}

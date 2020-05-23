//IDE: CodeBlocks
//Task 5.2(18)
/*
Дана очередь, элементы которой содержат целые числа.
Сформировать на основе очереди бинарное дерево поиска.
Разработать функцию «обрезки» дерева, которая оставляет на
каждом узле только один лист.
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node //структура для описания узла дерева
{
    int data;
    struct node* right;
    struct node* left;
};

struct node* newNode(int x) //созд. корня дерева
{
    struct node* p;
    p = malloc(sizeof(struct node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;

    return p;
}

struct node* insert(struct node* cur, int x) //вставка нового узла дерева
{
    if (cur == NULL) return newNode(x);
    else if (x > cur->data)
        cur->right = insert(cur->right, x);
    else cur->left = insert(cur->left, x);
    return cur;
}

void inOrder(struct node* cur) //печать дерева
{
    if (cur != NULL)
    {
        inOrder(cur->left);
        printf(" %d ", cur->data);
        inOrder(cur->right);
    }
}

void deleteTree(struct node* cur) //удаление дерева //очистка памяти
{
    if(cur != NULL) //спуск и рек. удаление
    {
        deleteTree(cur->left);
        deleteTree(cur->right);
        free(cur);
    }
}

struct node* treePruning(struct node* cur, struct node* temp) //обрезка самого дерева
{
    if (cur == NULL)
        return NULL;

    else if ((cur->left == NULL) && (cur->right == NULL)) //если текущий cur -  лист, то рек...
    {
        treePruning(temp, NULL);
    }
    else if (cur->left != NULL && cur->right != NULL) // если потомки !NULL
    {
        if ((cur->left)->left != NULL && (cur->left)->right != NULL) //если подпотомки левого потомка !NULL
        {                                                            // записывает указатель на правого потомка в temp
            temp = cur->right;                                       // и далее идет от левого потомка
            treePruning(cur->left, temp);
        }
        //если левый - лист, а у правого есть хоть один потомок, идем к правому
        else if ((cur->left)->left == NULL && (cur->left)->right == NULL && ((cur->right)->left != NULL || (cur->right)->right != NULL))
        {
            treePruning(cur->right, temp);
        }
        //если правый - лист, а у левого есть хоть один потомок, идем к левого
        else if ((cur->right)->left == NULL && (cur->right)->right == NULL && ((cur->left)->left != NULL || (cur->left)->right != NULL))
        {
            treePruning(cur->left, temp);
        }
        //если правый и левый - листы, удаляем правый потомок (можно и левый, не принципиально)
        else if ((cur->right)->left == NULL && (cur->right)->right == NULL && (cur->left)->left == NULL && (cur->left)->right == NULL)
        {
            free(cur->right);
            cur->right = NULL;
        }
        treePruning(temp, NULL);
    }
    //если левый потомок есть, а правого нету - идем к левому
    else if (cur->left != NULL && cur->right == NULL)
    {
        treePruning(cur->left, temp);
    }
    //если правый потомок есть, а левого нету - идем к правому
    else if (cur->left == NULL && cur->right != NULL)
        treePruning(cur->right, temp);

    return cur;
}

int main()
{
    struct node* cur;
    struct node* temp;
    cur = newNode(500);
    insert(cur, 480); insert(cur, 490);
    insert(cur, 475); insert(cur, 478);
    insert(cur, 470); insert(cur, 495);
    insert(cur, 498); insert(cur, 492);
    insert(cur, 510); insert(cur, 520);
    insert(cur, 505); insert(cur, 501);
    insert(cur, 507); insert(cur, 527);

    inOrder(cur);
    printf("\n");
    
    treePruning(cur, temp);

    inOrder(cur);
    printf("\n");

    deleteTree(cur);

    return 0;
}

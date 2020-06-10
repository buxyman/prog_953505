#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct item {
    int data;
    struct item* left;
    struct item* right;
} Item;

void AddNode(int data, Item** node);
int get(Item* node, int n, int c);
void lvl(Item* root);



int main(void)
{
    char buffer[512];
    int i;
    Item* root = NULL;
    FILE* fp = fopen("input.txt", "r");

    if (!fp) exit(1);

    while (fgets(buffer, 512, fp) != NULL)
        AddNode(atoi(buffer), &root);
    lvl(root);
    fclose(fp);
    /*lvl(root);*/
    system("PAUSE");
    return 0;
}

void AddNode(int data, Item** node)
{
    if (*node == NULL) {
        *node = (Item*)calloc(1, sizeof(Item));
        (*node)->data = data;
        (*node)->left = (*node)->right = NULL;
    }
    else {
        if (data < (*node)->data)
            AddNode(data, &(*node)->left);
        else if (data > (*node)->data)
            AddNode(data, &(*node)->right);
        else
            puts("There is such element in the tree");
    }
}
int get(Item* node, int n, int c)
{
    if (n == c)  return 1;
    return ((node->left) ? get(node->left, n, c + 1) : 0) + ((node->right) ? get(node->right, n, c + 1) : 0);
}

void lvl(Item* root) {
    int t = 0, l = 0;
    while ((l = get(root, t++, 0)) != 0) {
        printf("lvl(%d) = %d\n", t, l);
    }
}

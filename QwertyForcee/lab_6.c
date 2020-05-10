// zadanie 5.2(17) Bystrov Maxim 953505
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct  tree{
	int data;
	struct tree *right;
	struct tree *left;
} Tree;
void AddNode(int data, Tree **node);
void LeftOrder(Tree *node);
void JustShow(Tree *node);
void Delete(Tree *p);
/*Äîáàâëÿåò ýëåìåíò*/
void AddNode(int data, Tree **node)
{
	if (*node == NULL) {
		*node = (Tree *)calloc(1, sizeof(Tree));	
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
/*Для создания дерева НЕпоиска*/
void AddWrongNode(char s,int data, Tree **node)
{
	if (*node == NULL) {
		*node = (Tree *)calloc(1, sizeof(Tree));
		(*node)->data = data;
		(*node)->left = (*node)->right = NULL;
	}
	else {
		if (s=='l')
			AddWrongNode('l',data, &(*node)->left);
		else if (s=='r')
			AddWrongNode('r',data, &(*node)->right);			
	}
}
/*Произвольное дерево--->Дерево поиска	*/
void Sort(Tree *node, Tree **result) {
	if (node == NULL)return;
		//Sort2((node)->left, &(*result));
		AddNode(node->data, &(*result));
		Sort((node)->left, &(*result));
		Sort((node)->right, &(*result));
		//Sort2((node)->left, &(*result));
		//AddNode(node->data, &(*result));
}
/* Обход дерева слева (вывод по возрастанию)*/
void LeftOrder(Tree *node)
{
	if (node->left)
		LeftOrder(node->left);
	printf("%d ", node->data);
	if (node->right)
		LeftOrder(node->right);
}
/*Pre-order обходит грубо говоря слева и вглубь*/
void JustShow(Tree *node) {
	if (!node)return;
	printf("%d, ", node->data);
	JustShow(node->left);
	JustShow(node->right);
}
void Delete(Tree *p)
{
  if (p != NULL)
  {
   Delete(p->left);
   Delete(p->right);
	 free(p);
  }
}
int main(){
	Tree *first=NULL;	
	AddNode(4, &first);
	AddNode(49, &first);
	AddNode(3, &first);
	AddWrongNode('r',12, &first);
	AddWrongNode('r', 46, &first);
	AddWrongNode('l', 55, &first);
	AddWrongNode('l', 123, &first);
	AddWrongNode('r', 8, &first);
	JustShow(first);
	Tree *second = NULL;
	Sort(first, &second);
	printf("\n\n");
	LeftOrder(second);	
	printf("\n\n");
	JustShow(second);
	Delete(first);
	Delete(second);
	return 0;
}

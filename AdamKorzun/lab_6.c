#include <stdio.h>
typedef struct node {
	char data[100];
	struct node* left;
	struct node* right;
} Node;
void AddNode(Node **node, char data[100]) {
	if (*node == NULL) {
		*node = (Node*)malloc(sizeof(Node));
		strcpy((*node)->data,data);
		(*node)->left = (*node)->right = NULL;

	}
	else {
		if (strcmp(data, (*node)->data) < 0) {
			AddNode(&((*node)->left), data);
		}
		else if (strcmp(data, (*node)->data) > 0) {
			AddNode(&((*node)->right), data);
		}
		else {
			printf("This word is alrady present in the tree\n");
		}
	}
	
}
char* findPalindrome(char data[100]) {
	int wordLen = strlen(data);
	for (int i = 0; i < wordLen / 2; i++) {
		if (data[i] != data[wordLen - i  - 1]) {
			return '0';
		}
	}
	return data;
	
}
void LeftOrderNumber(Node* node,int *number)
{
	
	if (node->left) {
		LeftOrderNumber(node->left,number);
	}
	if (node->right) {
		LeftOrderNumber(node->right, number);
	}
	if (findPalindrome(node->data) != '0') {
		*number = *number+1;
	}
	

}
void LeftOrderFill(Node* node, int* number, char** pArray)
{

	if (node->left) {
		LeftOrderFill(node->left, number,pArray);
	}
	if (node->right) {
		LeftOrderFill(node->right, number,pArray);
	}
	if (findPalindrome(node->data) != '0') {
		strcpy(pArray[*number], node->data);
		*number = *number + 1;
	}


}
void SortArray(char** palindromeArray, int number) {
	char* temp = (char*)malloc(sizeof(char) * 100);
	for (int i = 0; i < number - 1; i++) {
		for (int j = i + 1; j < number; j++) {
			if (strcmp(palindromeArray[j], palindromeArray[i]) < 0)
			{
				strcpy(temp, palindromeArray[j]);
				strcpy(palindromeArray[j], palindromeArray[i]);
				strcpy(palindromeArray[i], temp);
			}
		}

	}
	for (int i = 0; i < number; i++) {
		printf("%s\n", palindromeArray[i]);
	}
}
void DeleteTree(Node* node) {
	if (node->left) {
		DeleteTree(node->left);
	}
	if (node->right) {
		DeleteTree(node->right);
	}
	free(node);
}
int main() {
	Node* root = NULL;
	char word[100];
	printf("Word: ");
	gets(word);
	if (!(strcmp(word, "end"))) {
		return;
	}
	while (strcmp(word, "end")){

		AddNode(&root, word);
		printf("Word: ");
		gets(word);
	}
	int number = 0;
	LeftOrderNumber(root,&number);
	char** palindromeArray = (char**)malloc(sizeof(char*) * number);
	for (int i = 0; i < number; i++) {
		palindromeArray[i] = (char*)malloc(sizeof(char) * 100);
	}
	number = 0;
	LeftOrderFill(root, &number, palindromeArray);
	SortArray(palindromeArray, number);

	for (int i = 0; i < number;i++) {
		free(palindromeArray[i]);
	}
	free(palindromeArray);
	DeleteTree(root);
	
	return -1;
}

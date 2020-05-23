// 5lab #13 start - gcc -o 5l 5lab.c && ./5l

#include <stdio.h> 
#include <stdlib.h> 

// лист
struct Node { 
	int data; 
	struct Node* next; 
}; 

// функция реверсирования листа
void reverse(struct Node** head_ref) 
{ 
	struct Node* prev = NULL; 
	struct Node* current = *head_ref; 
	struct Node* next = NULL; 
	while (current != NULL) { 
		// записываем следующий объект
		next = current->next; 

		// перемещаем указатель 
		current->next = prev; 

		// перенос указателей на 1 назад 
		prev = current; 
		current = next; 
	} 
	*head_ref = prev; 
} 

void push(struct Node** head_ref, int new_data) 
{ 
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
	new_node->data = new_data; 
	new_node->next = (*head_ref); 
	(*head_ref) = new_node; 
} 

void print_list(struct Node* head) 
{ 
	struct Node* temp = head; 
	while (temp != NULL) { 
		printf("%d ", temp->data); 
		temp = temp->next; 
	} 
} 


void freeList(struct Node* head)
{
   struct Node* tmp;

   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
    }

}

int main() 
{ 
	struct Node* head = NULL; 

	push(&head, 20); 
	push(&head, 4); 
	push(&head, 15); 
	push(&head, 85); 
    push(&head, 43);

	printf("Given linked list\n"); 
	print_list(head); 
	reverse(&head); 
	printf("\nReversed Linked list \n"); 
	print_list(head);

	free_list(head);
} 

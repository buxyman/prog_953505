//5.1 (27). 
// Задан двунаправленный список, указывающий порядок обработки
//одной из
//n очередей. Элементы списка содержат номер
//обрабатываемой очереди i (i <= n); признак выполняемого
//действия: ‘А’ – элемент из списка добавляется в i-ю очередь, ‘D’ –
//из i-й очереди удаляется элемент; данные (символ). Разработать
//функцию обработки очередей в соответствии с «программой»
//двунаправленного списка.


	//input example:
	//Ag5
	//B5
	//Am4


#include <stdio.h>
#include <stdlib.h>


typedef struct Node    
{
	char value;        
	struct Node* next; 
}   Node;

typedef struct Queue   
{
	Node* head;        
	Node* tail;        
}   Queue;


Queue* Push(Queue* queue, char value)
{
	Node* node = malloc(sizeof(Node));
	node->value = value;
	node->next = NULL;

	if (queue->head && queue->tail)
	{
		queue->tail->next = node;
		queue->tail = node;
	}
	else
	{
		queue->head = queue->tail = node;
	}

	return queue;
}

char Pop(Queue* queue)
{
	char value = 0;
	Node* node;

	if (queue->head)
	{
		node = queue->head;
		value = node->value;
		queue->head = queue->head->next;
		free(node);
	}

	return value;
}

void Clear(Queue* queue)
{
	while (queue->head)
	{
		Pop(queue);
	}

	queue->head = queue->tail = NULL;
}

void Print(const Queue* queue)
{
	const Node* node = queue->head;

	for (; node; node = node->next)
	{
		printf("%c ", node->value);
	}
	printf("\n");
}


typedef struct NodeList
{
	struct NodeList* prev;
	struct NodeList* next;
	int n;
	char operation;
	char data;
}   NodeList;

typedef struct List
{
	NodeList* head;
	NodeList* tail;
	int count;
}   List;

void ListInit(struct List* List)
{
	List->head = List->tail = NULL;
	List->count = 0;
}

void AddHead(struct List* List, char data, char operation, int n)
{
	NodeList* node = malloc(sizeof(NodeList));

	node->prev = 0;
	node->data = data;
	node->n = n;
	node->operation = operation;
	node->next = List->head;

	if (List->head != 0)
		List->head->prev = node;

	if (List->count == 0)
		List->head = List->tail = node;
	else
		List->head = node;

	List->count++;
}

void AddTail(struct List* List, char data, char operation, int n)
{
	NodeList* node = malloc(sizeof(NodeList));

	node->next = 0;
	node->data = data;
	node->n = n;
	node->operation = operation;
	node->prev = List->tail;

	if (List->tail != 0)
		List->tail->next = node;

	if (List->count == 0)
		List->head = List->tail = node;
	else
		List->tail = node;

	List->count++;
}

void Insert(struct List* List, int pos, char data, char operation, int n)
{
	if (pos < 1 || pos > List->count + 1)
	{
		return;
	}

	if (pos == List->count + 1)
	{
		AddTail(List, data, operation, n);
		return;
	}
	else if (pos == 1)
	{
		AddHead(List, data, operation, n);
		return;
	}

	int i = 1;
	NodeList* Ins = malloc(sizeof(NodeList));

	while (i < pos)
	{
		Ins = Ins->next;
		i++;
	}

	NodeList* PrevIns = Ins->prev;

	NodeList* node = malloc(sizeof(NodeList));

	node->data = data;
	node->n = n;
	node->operation = operation;

	if (PrevIns != 0 && List->count != 1)
		PrevIns->next = node;

	node->next = Ins;
	node->prev = PrevIns;
	Ins->prev = node;

	List->count++;
}

void Del(struct List* List, int pos)
{
	if (pos < 1 || pos > List->count)
	{
		return;
	}

	int i = 1;

	NodeList* Del = List->head;

	while (i < pos)
	{
		Del = Del->next;
		i++;
	}

	NodeList* PrevDel = Del->prev;
	NodeList* AfterDel = Del->next;

	if (PrevDel != 0 && List->count != 1)
		PrevDel->next = AfterDel;

	if (AfterDel != 0 && List->count != 1)
		AfterDel->prev = PrevDel;

	if (pos == 1)
		List->head = AfterDel;

	if (pos == List->count)
		List->tail = PrevDel;

	free(Del);

	List->count--;
}
void DelAll(struct List* List)
{
	while (List->count != 0)
		Del(List, 1);
}

Queue Qarr[10];
int first_bool = 1;
void Foo(int count, int repite_count)
{
	char data, operation;
	int n;
	List list1;
	ListInit(&list1);
	AddHead(&list1, ' ', ' ', 0);
	for (int i = 0; i < count; i++)
	{
		scanf_s("%c", &operation);
		if (operation == 'A')
			scanf_s("%c", &data);
		scanf_s("%d", &n);
		gets();
		AddTail(&list1, data, operation, n);
	}
	for (int i = 0; i < repite_count; i++)
	{
		NodeList* temp = list1.head;
		for (int i = 0; i < count; i++)
		{
			temp = temp->next;
			switch (temp->operation)
			{
			case 'A':
			{
				Push(&Qarr[temp->n], temp->data);
				printf_s("\nAdd operation executed <%c added to %d queue>", temp->data, temp->n);
				break;
			}
			case 'D':
			{
				char ch = Pop(&Qarr[temp->n]);
				if (ch == 0)
				{
					printf_s("\nQueue #%d has no elements", temp->n);
				}
				else
				{
					printf_s("\nDeleting operation executed <%c deleted from %d queue>", ch, temp->n);
				}
				break;
			}
			}
		}
	}
	DelAll(&list1);
}

int main(int argc, char* argv[])
{
	//input example:
	//Ag5
	//B5
	//Am4
	Foo(5,4);
	printf_s("\n");
	for (int i = 0; i < 10; i++)
	{
		Print(&Qarr[i]);
	}
}

// 5.1.30.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h>
#include <iostream>

struct Stack
{
	int Data;
	Stack* next;
};

void push(Stack** top, int data)
{

	Stack* t = (Stack*)malloc(sizeof(Stack));
	t->Data = data;
	if (top == NULL)
	{
		*top = t;
	}
	else
	{
		t->next = *top;
		*top = t;
	}
}

void pop(Stack** top, int data)
{
	Stack* t = *top;
	Stack* prev = NULL;
	while (t != NULL)
	{
		if (t->Data == data)
		{
			if (t == *top)
			{
				*top = t->next;
				free(t);
				t->Data = NULL;
				t->next = NULL;
			}
			else
			{
				prev->next = t->next;
				free(t);
				t->Data = NULL;
				t->next = NULL;
			}
		}
		prev = t;
		t = t->next;
	}
}

void printStack(Stack* top)
{
	Stack* t = top;
	while (t)
	{
		printf_s("%i ", t->Data);
		t = t->next;
	}
}

int isEmpty(Stack** top)
{
	return *top == NULL;
}

int topValue(Stack** top)
{
	if (!isEmpty(top))
	{
		return (*top)->Data;
	}
	else
	{
		return 0;
	}
}

void copyStack(Stack** top1, Stack** top2, int amount)
{
	for (int i = 0; i < amount; i++)
	{
		push(top2, topValue(top1));
		pop(top1, topValue(top1));
	}
	printf_s("\nSecond stack: \n");
	printStack(*top2);
}

void clear(Stack* top)
{	
	if (top)
	{
		clear(top->next);
		free(top);
	}
}

int main()
{
	Stack* stack1 = NULL;
	Stack* stack2 = NULL;
	int amountEl;
	int amountCpy;
	printf_s("How many elements u'd like \nto have in your stack: ");
	scanf_s("%i", &amountEl);
	for (int i = 0; i < amountEl; i++)
	{
		push(&stack1, i);
	}
	printf_s("First stack: \n");
	printStack(stack1);
	printf_s("\nHow many elements u'd like to copy: ");
	scanf_s("%i", &amountCpy);
	if (amountCpy > amountEl)
	{
		amountCpy = 0;
		printf_s("U cant copy this amount, try again: ");
		scanf_s("%i", &amountCpy);
	}
	copyStack(&stack1, &stack2, amountCpy);
	clear(stack1);
	clear(stack2);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

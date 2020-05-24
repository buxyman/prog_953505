/* Создать тип данных Многоразрядное число. Разработать следующие
функции:
· Equal() – сравнение двух многоразрядных чисел (возвращает 0,
если числа равны, 1 – если первое число больше, -1 – если второе
число больше);
· LongModShort() – возвращает остаток от деления
многоразрядного числа на короткое число типа int;
· LongDivShort() – возвращает результат целочисленного деления
многоразрядного числа на короткое число типа int;
· LongMulShort() – возвращает результат умножения
многоразрядного числа на короткое число типа int.
Для хранения многоразрядного числа использовать динамический
двунаправленный список. */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <Windows.h>
struct MultiDigit
{
	int digit;
	struct MultiDigit* prev;
	struct MultiDigit* next;
};
typedef struct MultiDigit MNumber;
void NewMNumber(MNumber** numL, MNumber** numR)
{
	*numL = (MNumber*)malloc(sizeof(MNumber));
	*numR = (MNumber*)malloc(sizeof(MNumber));
	(*numL)->prev = NULL;
	(*numL)->next = *numR;
	(*numR)->prev = *numL;
	(*numR)->next = NULL;
	return;
}
void AddDigit(MNumber* numR, int digit)
{
	MNumber* node = NULL;
	node = (MNumber*)malloc(sizeof(MNumber));
	node->digit = digit;
	node->prev = numR->prev;
	node->next = numR;
	node->prev->next = node;
	numR->prev = node;
	return;
}
void Output(MNumber** numL, MNumber** numR)
{
	MNumber* node = (*numL)->next;
	while (node != *numR)
	{
		printf("%d", node->digit);
		node = node->next;
	}
	return;
}
int DigitsCount(MNumber** numL, MNumber** numR)
{
	MNumber* node = (*numL)->next;
	int digitscount = 0;
	while (node != *numR)
	{
		node = node->next;
		digitscount++;
	}
	return digitscount;
}
int Equal(MNumber** num1L, MNumber** num1R, MNumber** num2L, MNumber** num2R)
{
	MNumber* pointer1 = (*num1L)->next;
	MNumber* pointer2 = (*num2L)->next;
	int size1 = DigitsCount(num1L, num1R), size2 = DigitsCount(num2L, num2R);
	if (size1 > size2)
	{
		return 1;
	}
	else if (size1 < size2)
	{
		return -1;
	}
	else if (size1 == size2)
	{
		while (pointer1 != *num1R)
		{
			if (pointer1->digit > pointer2->digit)
			{
				return 1;
			}
			if (pointer1->digit < pointer2->digit)
			{
				return -1;
			}
			pointer1 = pointer1->next;
			pointer2 = pointer2->next;
		}
	}
	return 0;
}
// остаток от деления на short int
int LongModShort(MNumber** num1L, MNumber** num1R, int shortint) 
{
	int remainder = 0;
	MNumber* node = (*num1L)->next;
	while (node != *num1R)
	{
		remainder = remainder * 10 + node->digit;
		node = node->next;
		remainder %= shortint;
	}
	return remainder;
}
MNumber* DeleteDigit(MNumber** numL)
{
	MNumber* node = (*numL)->next;
	MNumber* tmp = node;
	node->prev->next = node->next;
	node->next->prev = node->prev;
	free(tmp);
	node = (*numL)->next;
	return node->prev;
}
// целая часть от деления на short int
MNumber* LongDivShort(MNumber** num1L, MNumber** num1R, int shortint)
{
	MNumber* divL = NULL, * divR = NULL;
	if (divL == NULL)
	{
		NewMNumber(&divL, &divR);
	}
	int del = 0;
	MNumber* spt = (*num1L)->next;
	while (spt != *num1R)
	{
		del = del * 10 + spt->digit;
		spt = spt->next;
		AddDigit(divR, del / shortint);
		del %= shortint;
	}
	while (divL->next->digit == 0)
	{
		divL = DeleteDigit(&divL);
	}
	Output(&divL, &divR);
	return divL;
}
// функция умножения на short int
MNumber* LongMulShort(MNumber** num1L, MNumber** num1R, int shortint)
{
	int intdigits = 0, temp = shortint, count = 0;
	while (temp)
	{
		temp /= 10;
		intdigits++;
	}
	intdigits += DigitsCount(num1L, num1R);
	MNumber* numL = NULL, * numR = NULL;
	if (numL == NULL)
	{
		NewMNumber(&numL, &numR);
	}
	for (int i = 0; i < intdigits; i++)
	{
		AddDigit(numR, 0);
	}
	int digit = 0, pos = 0;
	MNumber* spt = (*num1R)->prev;
	MNumber* spt1 = numR->prev;
	int mod = shortint % 10;
	shortint = shortint / 10;
	while (mod != 0)
	{
		while (spt != *num1L)
		{
			spt1->digit += (spt->digit * mod + pos);
			pos = 0;
			if (spt1->digit >= 10) 
			{
				pos = spt1->digit / 10;
				spt1->digit = spt1->digit % 10;
			}
			spt = spt->prev;
			spt1 = spt1->prev;
		}
		count++;
		if (pos)
		{
			spt1->digit += pos;
			pos = 0;
		}
		mod = shortint % 10;
		shortint = shortint / 10;
		spt = (*num1R)->prev;
		spt1 = numR->prev;
		for (int i = 0; i < count; i++)
		{
			spt1 = spt1->prev;
		}
	}
	while (numL->next->digit == 0)//лишние разряды
	{
		numL = DeleteDigit(&numL);
	}
	Output(&numL, &numR);
	return numL;
}
void FreeMemory(MNumber** numL, MNumber** numR) 
{
	MNumber* spt = (*numL)->next;
	while (spt != *numR)
	{
		MNumber* tmp = spt;
		spt->prev->next = spt->next;
		spt->next->prev = spt->prev;
		free(tmp);
		spt = (*numL)->next;
	}
	free(*numL); *numL = NULL;
	free(*numR); *numR = NULL;
	return;
}
int main(void)
{
	char *Number1, *Number2;
	Number1 = (char*)malloc(100 * sizeof(char));
	Number2 = (char*)malloc(100 * sizeof(char));
	int shortnum = 0, equal, flag = 0;
	
	printf("Input first multidigit number\n");
	fgets(Number1, 100, stdin);
	Number1[strlen(Number1) - 1] = '\0';
	
	printf("Input second multidigit number\n");
	fgets(Number2, 100, stdin);
	Number2[strlen(Number2) - 1] = '\0';
	
	struct MultiDigit* num1L = NULL, * num1R = NULL, * num2L = NULL, * num2R = NULL;
	
	if (num1L == NULL)
	{
		NewMNumber(&num1L, &num1R);
	}
	if (num2L == NULL)
	{
		NewMNumber(&num2L, &num2R);
	}
	for (int i = 0; i < strlen(Number1); i++)
	{
		char c = Number1[i];
		AddDigit(num1R, atoi(&c));
	}
	for (int i = 0; i < strlen(Number2); i++)
	{
		char c = Number2[i];
		AddDigit(num2R, atoi(&c));
	}
	int size1 = DigitsCount(&num1L, &num1R), size2 = DigitsCount(&num2L, &num2R), size3 = 0, temp = 0;
	printf("Input short int: \n");
	while (size3 > size1 || size3 > size2 || shortnum < 1)
	{
		scanf_s("%i", &shortnum);
		while (temp)
		{
			temp /= 10;
			size3++;
		}
		if (size3 > size1 || size3 > size2 || shortnum < 1)
		{
			printf("Try again\n");
		}
	}
	while (1)
	{
		if (flag != 0)
		{
			Sleep(1000);
		}
		flag = 1;
		system("cls");
		int i = 0;
		printf("Choose:\n");
		printf("1. Compare to multidigit numbers:\n");
		printf("2. Remainder of a division:\n");
		printf("3. Whole part of a division:\n");
		printf("4. Multiply:\n");
		printf("0. Exit:\n");
		scanf_s("%i", &i);
		switch (i)
		{
		case 1:
			equal = Equal(&num1L, &num1R, &num2L, &num2R);
			if (equal == 1)
			{
				printf("First number > second number\n");
			}
			if (equal == 0)
			{
				printf("First number = second number\n");
			}
			if (equal == -1)
			{
				printf("First number < second number\n");
			}
			break;
		case 2:
			printf("Remainder of a division of first number:\t%d\n", LongModShort(&num1L, &num1R, shortnum));
			printf("Remainder of a division of second number:\t%d\n", LongModShort(&num2L, &num2R, shortnum));
			break;
		case 3:
			printf("Whole part of a division of first number:\t"); LongDivShort(&num1L, &num1R, shortnum); printf("\n");
			printf("Whole part of a division of second number:\t"); LongDivShort(&num2L, &num2R, shortnum); printf("\n");
			break;
		case 4:
			printf("First number multiplication:\t");  LongMulShort(&num1L, &num1R, shortnum); printf("\n");
			printf("Second number multiplication:\t");  LongMulShort(&num2L, &num2R, shortnum); printf("\n");
			break;
		case 0:
			FreeMemory(&num1L, &num1R);
			FreeMemory(&num2L, &num2R);
			free(num1L);
			free(num1R);
			free(num2L);
			free(num2R);
			free(Number1);
			free(Number2);
			return 0;
		default:
			printf("Try again\n");
		}
	}
}

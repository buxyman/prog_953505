// -------------5.1(Вариант 2) Быстров Максим 953505-------------
#include  <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>
typedef struct item {
	int digit;
	struct item* next;
	struct item* prev;
} Item;
typedef struct mnumber {
	Item* head;
	Item* tail;
	int n;
} MNumber;
MNumber CreateMNumber(char* initStr);
void AddDigit(MNumber* number, int digit);
void PrintMNumber(MNumber number);
MNumber Divide(MNumber number, int x);
void Delete(Item *p);
int IsDivisible(MNumber number, int x);
MNumber SumMNumber(MNumber n1, MNumber n2);
MNumber CreateMNumber(char initStr[])
{
	MNumber number = { NULL, NULL, 0 };
	int n;
	for (n = strlen(initStr) - 1; n >= 0; n--)
		AddDigit(&number, initStr[n] - '0');
	return number;
}
void AddDigit(MNumber* number, int digit)
{
	Item* p = (Item*)malloc(sizeof(Item));
	p->digit = digit;
	p->next = p->prev = NULL;
	if (number->head == NULL)
		number->head = number->tail = p;
	else {
		number->tail->next = p;
		p->prev = number->tail;
		number->tail = p;
	}
	number->n++;
}
/* Вывод числа на экран */
void PrintMNumber(MNumber number)
{
	Item* p = number.tail;
	printf("\nNumber: ");
	while (p) {
		printf("%d", p->digit);
		p = p->prev;
	}
}
/*Деление*/
MNumber Divide(MNumber number, int x) {
	Item* p = (Item*)malloc(sizeof(Item));
	p = number.tail;
	int xtemp = x;
	int xlength = 0;
	while (xtemp > 0) {
		xtemp /= 10;
		xlength++;
	}
	int temp = (int)pow(10, xlength - 1);
	int chislo = 0;
	for (int i = 0; i < xlength; i++) {
		chislo += p->digit * temp;
		temp /= 10;
		p = p->prev;
	}
	xtemp = x;
	char answer[40];
	int nomerok = 0;
	if (chislo < x) {
		chislo = chislo * 10 + p->digit;
		p = p->prev;
	}
	int count = 1;
	while (chislo >= xtemp + x) {
		xtemp += x;
		count++;
	}
	answer[nomerok] = count + 48;
	nomerok++;
	chislo = chislo - xtemp;
	while (p != number.head->prev) {
		xtemp = x;
		if (p->digit != 0) {
			if (chislo < x) {
				chislo = chislo * 10 + p->digit;
				p = p->prev;
			}
			int count = 1;
			while (chislo >= xtemp + x) {
				xtemp += x;
				count++;
			}
			answer[nomerok] = count + 48;
			nomerok++;
			chislo = chislo - xtemp;
		}
		else if (p->digit == 0) {
			answer[nomerok] = '0';
			nomerok++;
			p = p->prev;
		}
	}
	answer[nomerok] = '\0';
	return CreateMNumber(answer);
}
/*Проверка на деление*/
int IsDivisible(MNumber number, int x) {
	if (number.head == NULL)return 0;
	Item* p = (Item*)malloc(sizeof(Item));
	p = number.tail;
	int ostatok = 0;
	int xtemp = x;
	int xlength = 0;
	while (xtemp > 0) {
		xtemp /= 10;
		xlength++;
	}
	int temp = (int)pow(10, xlength - 1);
	int chislo = 0;
	for (int i = 0; i < xlength; i++) {
		chislo += p->digit * temp;
		temp /= 10;
		p = p->prev;
		if (p == NULL)break;
	}
	xtemp = x;
	if (p != NULL && chislo < x) {
		chislo = chislo * 10 + p->digit;
		p = p->prev;
	}
	while (chislo >= xtemp + x) {
		xtemp += x;
	}
	ostatok = chislo - xtemp;
	chislo = chislo - xtemp;

	while (p != number.head->prev) {
		xtemp = x;
		if (p->digit != 0) {
			if (chislo < x) {
				chislo = chislo * 10 + p->digit;
				p = p->prev;
			}
			while (chislo >= xtemp + x) {
				xtemp += x;
			}
			ostatok = chislo - xtemp;
			chislo = chislo - xtemp;
		}
		else if (p->digit == 0) {
			if (chislo != 0) {
				chislo = chislo * 10 + p->digit;
				p = p->prev;
				while (chislo >= xtemp + x) {
					xtemp += x;
				}
				ostatok = chislo - xtemp;
				chislo = chislo - xtemp;
			}
			else {
				p = p->prev;
			}
		}
	}
	return ostatok ? 0 : 1;

}
/*Факторизация*/
void Decomposition(MNumber number) {
	for (int i = 2; i < 2000000000; i++)
	{
		while (IsDivisible(number, i))
		{
			printf("%d,", i);
			number = Divide(number, i);
		}
		if (number.head->digit == 1 && number.n == 1) break;
	}
}
/*Сумма двух чисел*/
MNumber SumMNumber(MNumber n1, MNumber n2)
{
	MNumber sum = CreateMNumber("");
	Item* p1 = n1.head, * p2 = n2.head;
	int digit, pos = 0, s1, s2;
	while (p1 || p2) {
		if (p1) { s1 = p1->digit; p1 = p1->next; }
		else s1 = 0;
		if (p2) { s2 = p2->digit; p2 = p2->next; }
		else s2 = 0;
		digit = (s1 + s2 + pos) % 10;
		pos = (s1 + s2 + pos) / 10;
		AddDigit(&sum, digit);
	}
	if (pos) AddDigit(&sum, pos);
	return sum;
}
void Delete(Item *p)
{
  if (p != NULL)
  {
    Delete(p->next);
    free(p);
  }
}
int main() {
	MNumber first = CreateMNumber("22222222222");
	PrintMNumber(first);
	MNumber second = Divide(first, 2);
	PrintMNumber(second);
	printf("\n\n");
	Decomposition(first);
	printf("\n\n");
	Decomposition(second);
	Delete(first->head);
	Delete(second->head);
	return 0;
}

//5.1 (26). 
//Определить наименьшее общее кратное двух многоразрядных
//чисел. Для хранения многоразрядного числа использовать
//динамический двунаправленный список.

#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define len1 200
#define bool int
#define true 1
#define false 0

typedef struct item
{
	struct item* pNext;
	struct item* pPrev;
	int digit;
}Item;
typedef struct mNumber
{
	Item* head;
	Item* tail;
	int n;
}MNumber;
MNumber CreateMNumber(char* str)
{
	MNumber number = { NULL, NULL, 0 };
	for (int i = strlen(str) - 1; i >= 0; i--)
	{
		if (str[i] != '-')
		{
			AddDigit(&number, str[i] - '0');
		}
	}
	return number;
}
int AddDigit(MNumber* number, int digit)
{
	Item* newItem = (Item*)malloc(sizeof(Item));
	newItem->digit = digit;
	newItem->pNext = newItem->pPrev = NULL;
	if (number->head == NULL)
	{
		number->head = number->tail = newItem;
	}
	else
	{
		number->tail->pNext = newItem;
		newItem->pPrev = number->tail;
		number->tail = newItem;
	}
	number->n++;
}
void PopTail(MNumber* number)
{
	Item* toDelete = number->tail;
	number->tail = number->tail->pPrev;
	number->tail->pNext = NULL;
	free(toDelete);
	number->n--;
}
void Clear(MNumber* number)
{
	Item* temp;
	while (number->n != 0)
	{
		temp = number->tail;
		number->tail = number->tail->pPrev;
		number->n--;
		if (number->n != 0)
		{
			number->tail->pNext = NULL;
		}
		else if (number->n == 0)
		{
			number->head = number->tail = NULL;
			number->n = 0;
		}
		free(temp);
	}
}
void Print(MNumber number)
{
	Item* p = number.tail;
	while (p)
	{
		printf_s("%d", p->digit);
		p = p->pPrev;
	}
	printf_s("\n");
}
MNumber SumMNumber(MNumber a, MNumber b)
{
	MNumber sum = CreateMNumber("");
	Item* pA = a.head;
	Item* pB = b.head;
	int digit, pos = 0, s1, s2;
	while (pA || pB)
	{
		if (pA)
		{
			s1 = pA->digit;
			pA = pA->pNext;
		}
		else
		{
			s1 = 0;
		}
		if (pB)
		{
			s2 = pB->digit;
			pB = pB->pNext;
		}
		else
		{
			s2 = 0;
		}
		digit = (s1 + s2 + pos) % 10;
		pos = (s1 + s2 + pos) / 10;
		AddDigit(&sum, digit);
	}
	if (pos)
	{
		AddDigit(&sum, pos);
	}
	Clear(&a);
	return sum;
}
MNumber Multiplication(MNumber a, MNumber b)
{
	MNumber mult = CreateMNumber("");
	MNumber multNumbers = CreateMNumber("");
	Item* pA = a.head;
	Item* pB = b.head;
	int i = 0, digit, pos;
	while (pB)
	{
		pos = 0;
		for (int j = 0; j < i; j++)
		{
			AddDigit(&multNumbers, 0);
		}
		while (pA)
		{
			digit = ((pB->digit * pA->digit) + pos) % 10;
			pos = ((pB->digit * pA->digit) + pos) / 10;
			AddDigit(&multNumbers, digit);
			pA = pA->pNext;
		}
		if (pos)
		{
			AddDigit(&multNumbers, pos);
		}
		pA = a.head;
		pB = pB->pNext;
		i++;
		mult = SumMNumber(mult, multNumbers);
		Clear(&multNumbers);
	}
	return mult;
}
bool Check(char* aArr, char* bArr)
{
	if (strlen(aArr) > strlen(bArr))
	{
		return true;
	}
	else if (strlen(aArr) < strlen(bArr))
	{
		return false;
	}
	else
	{
		for (int i = 0; i < strlen(aArr); i++)
		{
			if (aArr[i] > bArr[i])
			{
				return true;
			}
			else if(aArr[i] < bArr[i])
			{
				return false;
			}
		}
	}
}
bool CheckNum(MNumber b, MNumber r)
{
	Item* pB = b.tail;
	Item* pR = r.tail;
	while (pB && pR)
	{
		if (r.n > b.n)
		{
			return true;
		}
		else if (r.n < b.n)
		{
			return false;
		}
		else 
		{
			if (pR->digit > pB->digit)
			{
				return true;
			}
			else if (pR->digit < pB->digit)
			{
				return false;
			}
		}
		pR = pR->pPrev;
		pB = pB->pPrev;
	}
}
MNumber Subtraction(MNumber a, MNumber b)
{
	MNumber sub = CreateMNumber("");
	Item* pA = a.head;
	Item* pB = b.head;
	int digit, s1, s2, pos = 0;
	while (pA || pB)
	{
		if (pA)
		{
			s1 = pA->digit + pos;
			pos = 0;
			pA = pA->pNext;
		}
		else
		{
			s1 = 0;
		}
		if (pB)
		{
			s2 = pB->digit;
			pB = pB->pNext;
		}
		else
		{
			s2 = 0;
		}
		if (s1 < s2)
		{
			pos--;
			s1 += 10;
		}
		digit = s1 - s2;
		AddDigit(&sub, digit);
	}
	while (sub.n != 1 && sub.tail->digit == 0)
	{
		PopTail(&sub);
	}
	Clear(&a);
	return sub;
}
MNumber Opt(MNumber a, MNumber b)
{
	MNumber a1 = CreateMNumber("");
	MNumber b1 = CreateMNumber("");
	Item* pA1 = a.head;
	Item* pB1;
	bool aIsBigger = false;
	while (pA1)
	{
		AddDigit(&a1, pA1->digit);
		pA1 = pA1->pNext;
	}
	while ((a1.n - b.n) >= 1)
	{
		pA1 = a1.tail;
		pB1 = b.tail;
		while (pB1)
		{
			if (pB1->digit < pA1->digit)
			{
				aIsBigger = true;
				break;
			}
			else if (pB1->digit > pA1->digit)
			{
				aIsBigger = false;
				break;
			}
			else
			{
				aIsBigger = true;
			}
			pA1 = pA1->pPrev;
			pB1 = pB1->pPrev;
		}
		if (aIsBigger)
		{
			Clear(&b1);
			pB1 = b.head;
			int size = a1.n - b.n;
			for (int i = 0; i < size; i++)
			{
				AddDigit(&b1, 0);
			}
			while (pB1)
			{
				AddDigit(&b1, pB1->digit);
				pB1 = pB1->pNext;
			}
		}
		else if(!aIsBigger)
		{
			Clear(&b1);
			pB1 = b.head;
			int size = a1.n - b.n - 1;
			for (int i = 0; i < size; i++)
			{
				AddDigit(&b1, 0);
			}
			while (pB1)
			{
				AddDigit(&b1, pB1->digit);
				pB1 = pB1->pNext;
			}
		}
		a1 = Subtraction(a1,b1);
	}
	return a1;
}
MNumber Gcd(MNumber a, MNumber b)
{
	MNumber r = CreateMNumber("");
	MNumber q = CreateMNumber("");
	Item* pR = NULL;
	Item* pB = NULL;
	bool rIsBigger;
	r = Opt(a,b); 
	while (true)
	{
		rIsBigger = false;
		r = Subtraction(r, b);
		rIsBigger = CheckNum(b, r);
		while (rIsBigger)
		{
			r = Subtraction(r, b);
			rIsBigger = CheckNum(b, r);
		}
		if (r.tail->digit == 0)
		{
			break;
		}
		if(!rIsBigger)
		{
			a = b;
			b = r;
			r = a;
		}
	}
	return b;
}
MNumber Lcm(MNumber a, MNumber b)
{
	MNumber lcm = CreateMNumber("");
	MNumber var = CreateMNumber("1");
	MNumber ab = Multiplication(a, b); //0001
	MNumber gcd = Gcd(a, b); //2
	printf_s("GCD: ");
	Print(gcd);
	printf_s("LCM: ");
	MNumber gcdCopy = CreateMNumber("");
	Item* pGcd;
	Item* pAb;
	bool abIsBigger;
	while ((ab.n - gcd.n) >= 1)
	{
		pGcd = gcd.tail;
		pAb = ab.tail;
		while (pGcd)
		{
			if (pGcd->digit < pAb->digit)
			{
				abIsBigger = true;
				break;
			}
			else if (pGcd->digit > pAb->digit)
			{
				abIsBigger = false;
				break;
			}
			else
			{
				abIsBigger = true;
			}
			pGcd = pGcd->pPrev;
			pAb = pAb->pPrev;
		}
		if (abIsBigger)
		{
			Clear(&gcdCopy);
			pGcd = gcd.head;
			int size = ab.n - gcd.n;
			for (int i = 0; i < size; i++)
			{
				AddDigit(&gcdCopy, 0);
			}
			AddDigit(&gcdCopy, 1);
			lcm = SumMNumber(lcm, gcdCopy);
			PopTail(&gcdCopy);
			while (pGcd)
			{
				AddDigit(&gcdCopy, pGcd->digit);
				pGcd = pGcd->pNext;
			}
		}
		else if (!abIsBigger)
		{
			Clear(&gcdCopy);
			pGcd = gcd.head;
			int size = ab.n - gcd.n - 1;
			for (int i = 0; i < size; i++)
			{
				AddDigit(&gcdCopy, 0);
			}
			AddDigit(&gcdCopy, 1);
			lcm = SumMNumber(lcm, gcdCopy);
			PopTail(&gcdCopy);
			while (pGcd)
			{
				AddDigit(&gcdCopy, pGcd->digit);
				pGcd = pGcd->pNext;
			}
		}
		ab = Subtraction(ab, gcdCopy);
		Print(lcm);
	}
	while (ab.tail->digit != 0)
	{
		ab = Subtraction(ab, gcd);
		lcm = SumMNumber(lcm,var);
	}
	return lcm;
}

int main()
{
	char aArr[len1];
	char bArr[len1];
	MNumber a = CreateMNumber("");
	MNumber b = CreateMNumber("");
	printf_s("First number: ");
	gets(aArr);
	printf_s("Second number: ");
	gets(bArr);
	bool aIsBigger = Check(aArr, bArr);
	if (aIsBigger)
	{
		a = CreateMNumber(aArr);
		b = CreateMNumber(bArr);
	}
	else
	{
		a = CreateMNumber(bArr);
		b = CreateMNumber(aArr);
	}
	Print(Lcm(a, b));
	return 0;
}

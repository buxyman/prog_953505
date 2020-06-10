#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct item
{
	int digit;
	struct item* next;
	struct item* prev;
}Item;

typedef struct number
{
	int size;
	Item* head;
	Item* tail;
}Number;

void Trim(Number* num);
Number* CreateNumber(char* str);
void AddDigit(Number* num, int digit);
void AddDigitL(Number* num, int digit);
void DeleteNumber(Number* num);
void PrintNumber(Number num);
Number* Copy(Number num);
bool IsBigger(Number greater, Number lower);
bool Equals(Number a, Number b);
Number* Divide(Number num, Number divider);
Number* Multiply(Number a, Number b);
Number* Subtract(Number a, Number b);
Number* Sum(Number a, Number b);
Number* GetNod(Number a, Number b);
Number* GetNok(Number a, Number b);

Number* CreateNumber(char* str)
{	
	Number* num = (Number*)malloc(sizeof(Number));
	num->size = 0;
	num->head = num->tail = NULL;
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] > '9' || str[i] < '0') return num;
		i++;
	}
	for (int i = strlen(str) - 1; i >= 0; i--) {
		AddDigit(num, str[i] - '0');
	}
	return num;
}

void DeleteNumber(Number* num) {
	Item* current = num->head;
	while (current != NULL)
	{
		current = num->head->next;
		free(num->head);
		num->head = current;
	}
	free(num);
}

void AddDigit(Number* num, int digit) {
	Item* item = (Item*)malloc(sizeof(Item));
	item->digit = digit;
	item->next = item->prev = NULL;
	if (num->head == NULL) {
		num->head = num->tail = item;
	}
	else {
		num->tail->next = item;
		item->prev = num->tail;
		num->tail = item;
	}
	num->size++;
}

void AddDigitL(Number* num, int digit) {
	Item* item = (Item*)malloc(sizeof(Item));
	item->digit = digit;
	item->next = item->prev = NULL;
	if (num->head == NULL) {
		num->head = num->tail = item;
	}
	else {
		num->head->prev = item;
		item->next = num->head;
		num->head = item;
	}
	num->size++;
}

void PrintNumber(Number num)
{
	Item* cur = num.tail;
	while (cur) {
		printf("%d", cur->digit);
		cur = cur->prev;
	}
	printf("\n");
}

void Trim(Number* num)
{
	Item* cur = num->tail;
	if (!cur) return;
	while (!cur->digit) {
		if (num->size == 1) return;
		cur = cur->prev;
		num->tail = num->tail->prev;
		num->tail->next = NULL;
		num->size--;
		if (!cur) {
			free(num->head);
			num->head = NULL;
			break;
		}
		free(cur->next);
	}
}

bool IsBigger(Number greater, Number lower) {
	if (greater.size == lower.size) {
		if (!greater.size) return false;
		Item* it1 = greater.tail, * it2 = lower.tail;
		while (it1->digit == it2->digit) {
			if (!it1->prev) return false;
			it1 = it1->prev;
			it2 = it2->prev;
		}
		return it1->digit > it2->digit;
	}
	else return greater.size > lower.size;
}

bool Equals(Number a, Number b) {
	return !(IsBigger(a, b) || IsBigger(b, a));
}

Number* Multiply(Number a, Number b)
{
	Number* result = CreateNumber("");
	if (IsBigger(b, a)) {
		Number temp = b;
		b = a;
		a = temp;
	}
	Item* itemB = b.head, * itemA;
	for (int i = 0; i < b.size; i++) {
		Number* sum = CreateNumber("");
		int mult = 0;
		int rem = 0;
		itemA = a.head;
		for (int k = 0; k < i; k++) AddDigitL(sum, 0);
		for (int j = 0; j < a.size; j++) {
			mult = itemA->digit * itemB->digit + rem;
			rem = 0;
			if (mult > 9) {
				rem = (mult - mult % 10) / 10;
				mult %= 10;
			}
			AddDigit(sum, mult);
			itemA = itemA->next;
			if (rem && !itemA) AddDigit(sum, rem);
		}
		itemB = itemB->next;
		Number* temp = result;
		Trim(sum);
		result = Sum(*result, *sum);
		DeleteNumber(temp);
		DeleteNumber(sum);
	}
	return result;
}

Number* Sum(Number a, Number b) {
	Number* result = CreateNumber("");
	Item* cur1 = a.head, * cur2 = b.head;
	int digit, rem = 0, s1, s2;
	while (cur1 || cur2) {
		if (cur1) { s1 = cur1->digit; cur1 = cur1->next; }
		else s1 = 0;
		if (cur2) { s2 = cur2->digit; cur2 = cur2->next; }
		else s2 = 0;
		digit = (s1 + s2 + rem) % 10;
		rem = (s1 + s2 + rem) / 10;
		AddDigit(result, digit);
	}
	if (rem) AddDigit(result, rem);
	return result;
}

Number* Subtract(Number a, Number b)
{
	if (IsBigger(b, a)) return NULL;
	Number* result = CreateNumber("");
	Item* cur1 = a.head, * cur2 = b.head;
	int rem = 0, d1, d2;
	while (cur1) {
		d1 = cur1->digit;
		cur1 = cur1->next;
		if (cur2) {
			d2 = cur2->digit;
			cur2 = cur2->next;
		}
		else d2 = 0;
		int res = d1 - d2 + rem;
		rem = 0;
		if (res < 0) {
			res += 10;
			rem = -1;
		}
		AddDigit(result, res);
	}
	Trim(result);
	return result;
}

Number* Divide(Number a, Number b)
{
	Number* result = CreateNumber("");
	if (IsBigger(b, a)) {
		AddDigit(result, 0);
		return result;
	}
	Number* va = Copy(a);
	Number* vb = Copy(b);
	Trim(va);
	Trim(vb);
	if (!vb->tail || !va->tail) {
		Number* null = CreateNumber("");
		DeleteNumber(va);
		DeleteNumber(vb);
		return null;
	}
	if (vb->tail->digit == 0 || va->tail->digit == 0) {
		Number* zero = CreateNumber("0");
		DeleteNumber(va);
		DeleteNumber(vb);
		return zero;
	}
	Item* cur = a.tail;
	Number* part = CreateNumber("");
	while (true) {
		while (IsBigger(b, *part) && cur)
		{
			AddDigitL(part, cur->digit);
			Trim(part);
			cur = cur->prev;
		}
		int digit = 0;
		while (!IsBigger(b, *part)) {
			Number* temp = part;
			part = Subtract(*part, b);
			DeleteNumber(temp);
			digit++;
		}
		AddDigitL(result, digit);
		if (!cur)
		{
			DeleteNumber(va);
			DeleteNumber(vb);
			DeleteNumber(part);
			Trim(result);
			return result;
		}
	}
}

Number* Mod(Number a, Number b)
{
	if (IsBigger(b, a)) {
		Number* copy = CreateNumber("");
		Item* cur = a.head;
		while (cur) {
			AddDigit(copy, cur->digit);
			cur = cur->next;
		}
		return copy;
	}
	Number* va = Copy(a);
	Number* vb = Copy(b);
	Trim(va);
	Trim(vb);
	if (!vb->tail || !va->tail) {
		Number* null = CreateNumber("");
		DeleteNumber(va);
		DeleteNumber(vb);
		return null;
	}
	if (vb->tail->digit == 0 || va->tail->digit == 0) {
		Number* zero = CreateNumber("0");
		DeleteNumber(va);
		DeleteNumber(vb);
		return zero;
	}

	Number* part = CreateNumber("");
	Item* cur = a.tail;
	while (true) {
		while (IsBigger(b, *part) && cur)
		{
			AddDigitL(part, cur->digit);
			Trim(part);
			cur = cur->prev;
		}
		int digit = 0;
		while (!IsBigger(b, *part)) {
			Number* temp = part;
			part = Subtract(*part, b);
			DeleteNumber(temp);
		}
		if (!cur)
		{
			DeleteNumber(va);
			DeleteNumber(vb);
			return part;
		}
	}
}

Number* Copy(Number num)
{
	Number* copy = CreateNumber("");
	Item* cur = num.head;
	while (cur) {
		AddDigit(copy, cur->digit);
		cur = cur->next;
	}
	return copy;
}

Number* GetNod(Number a, Number b)
{
	Number* valA = Copy(a);
	Number* valB = Copy(b);
	Number* zero = CreateNumber("0");
	if (!valB->tail || !valA->tail) {
		Number* null = CreateNumber("");
		DeleteNumber(valA);
		DeleteNumber(valB);
		return null;
	}
	if (valB->tail->digit == 0 || valA->tail->digit == 0) {
		DeleteNumber(valA);
		DeleteNumber(valB);
		return zero;
	}
	while (!Equals(*valA, *zero) && !Equals(*valB, *zero)) {
		if (IsBigger(*valA, *valB)) {
			Number* temp = valA;
			valA = Mod(*valA, *valB);
			DeleteNumber(temp);
		}
		else {
			Number* temp = valB;
			valB = Mod(*valB, *valA);
			DeleteNumber(temp);
		}
	}
	Number* result = Sum(*valA, *valB);
	DeleteNumber(valA);
	DeleteNumber(valB);
	DeleteNumber(zero);
	return result;
}

Number* GetNok(Number a, Number b) {
	Number* nod = GetNod(a, b);
	Number* mult = Multiply(a, b);
	if (!nod->tail || !mult->tail) {
		Number* null = CreateNumber("");
		DeleteNumber(nod);
		DeleteNumber(mult);
		return null;
	}
	if (nod->tail->digit == 0 || mult->tail->digit == 0) {
		Number* null = CreateNumber("");
		DeleteNumber(nod);
		DeleteNumber(mult);
		return null;
	}
	Number* result = Divide(*mult, *nod);
	DeleteNumber(nod);
	DeleteNumber(mult);
	return result;
}

int main()
{
	Number* num1 = CreateNumber("742345245425325243");
	Number* num2 = CreateNumber("36123231232153425");
	PrintNumber(*num1);
	PrintNumber(*num2);
	printf("\n");
	Number* result = GetNok(*num1, *num2);
	PrintNumber(*result);
	DeleteNumber(result);
	DeleteNumber(num1);
	DeleteNumber(num2);
}
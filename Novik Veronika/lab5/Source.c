/*29. Определить, являются ли два многоразрядных числа взаимно
простыми. Для хранения многоразрядного числа использовать
динамический двунаправленный список.*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct single_digit
{
	struct single_digit* next_digit;
	struct single_digit* prev_digit;
	short digit;
};

struct Digits
{
	int numof_digits;
	struct single_digit* msd;
	struct single_digit* lsd;
};

void add_digit(struct Digits* num, char dig)
{
	struct single_digit* dd = (struct single_digit*)malloc(sizeof(struct single_digit));
	if (dd == NULL)
	{
		puts("No more memory, terminating...");
		_getch();
		exit(-1);
	}
	dd->next_digit = NULL;
	dd->digit = (unsigned short)dig - 48;
	if (num->numof_digits == 0)
	{
		dd->prev_digit = NULL;
		num->msd = dd;
	}
	else
	{
		dd->prev_digit = num->lsd;
		num->lsd->next_digit = dd;
	}
	num->lsd = dd;
	num->numof_digits++;
}

void delete_digit(struct Digits* num)
{
	struct single_digit* temp = num->lsd;
	if (num->numof_digits != 1)
	{
		num->lsd = num->lsd->prev_digit;
		num->lsd->next_digit = NULL;
	}
	free(temp);
	num->numof_digits--;
}

void initialize(const char name[4], struct Digits* num)
{
	printf("Enter your %s number: ", name);
	char dig = '\0';
	while (dig != '\r')
	{
		dig = _getch();
		if (dig == '0' && num->numof_digits == 0)
			dig = '\0';
		else if (dig >= '0' && dig <= '9')
		{
			putchar(dig);
			add_digit(num, dig);
		}
		else if (dig == '\b')
		{
			if (num->numof_digits == 0)
				continue;
			else
				delete_digit(num);
			fputs("\b \b", stdout);
		}
		else if (dig == '\r' && num->numof_digits == 0)
			dig = '\0';
	}
	puts("");
}

int compare(struct Digits* num1, struct Digits* num2)
{
	if (num1->numof_digits > num2->numof_digits)
		return 0;
	if (num2->numof_digits > num1->numof_digits)
		return 1;
	struct single_digit* cur1 = num1->msd;
	struct single_digit* cur2 = num2->msd;
	for (int i = 0; i < num1->numof_digits; i++)
	{
		if (cur1->digit > cur2->digit)
			return 0;
		if (cur2->digit > cur1->digit)
			return 1;
		cur1 = cur1->next_digit;
		cur2 = cur2->next_digit;
	}
	return -1;
}

struct single_digit* get_num(struct Digits* num, int index)
{
	struct single_digit* temp;
	if (num->numof_digits / index < 2)
	{
		temp = num->lsd;
		for (int i = num->numof_digits; i > index; i--)
		{
			temp = temp->prev_digit;
		}
	}
	else
	{
		temp = num->msd;
		for (int i = 1; i < index; i++)
		{
			temp = temp->next_digit;
		}
	}
	return temp;
}

void clear_zero_msd(struct Digits* major)
{
	struct single_digit* temp = major->msd;
	major->msd = major->msd->next_digit;
	major->msd->digit += temp->digit * 10;
	major->msd->prev_digit = NULL;
	major->numof_digits--;
	free(temp);
}

//ALWAYS first argument is major number, second is minor
void coprimes_check(struct Digits* major, struct Digits* minor)
{
	do
	{
		if (major->msd->digit < minor->msd->digit)
		{
			clear_zero_msd(major);
		}

		for (int i = minor->numof_digits; i > 0; i--)
		{
			struct single_digit* m1 = get_num(major, i);
			struct single_digit* m2 = get_num(minor, i);
			if (m1->digit - m2->digit < 0)
			{
				for (int k = i - 1; k > 0; k--)
				{
					struct single_digit* tmp = get_num(major, k);
					if (tmp->digit > 0)
					{
						tmp->digit--;
						break;
					}
					else
						tmp->digit = 9;
				}
				m1->digit += 10;
			}
			m1->digit -= m2->digit;
		}
	} while (compare(major, minor) == 0);

	while (major->msd->digit == 0 && major->numof_digits > 1)
	{
		clear_zero_msd(major);
	}
}

int main(void)
{
	while (1)
	{
		struct Digits num1 = { 0, NULL, NULL };
		struct Digits num2 = { 0, NULL, NULL };
		initialize("1-st", &num1);
		initialize("2-nd", &num2);
		puts("");
		int call_num = compare(&num1, &num2);
		if (call_num == -1)
		{
			puts("Numbers are qual => surely not coprimes");
		}
		else
		{
			while (!(num1.lsd == num1.msd && (num1.lsd->digit == 1 || num1.lsd->digit == 0)) &&
				!(num2.lsd == num2.msd && (num2.lsd->digit == 1 || num2.lsd->digit == 0)))
			{
				if (call_num % 2)
					coprimes_check(&num2, &num1);
				else
					coprimes_check(&num1, &num2);
				call_num++;
			}
			if ((num1.numof_digits == 1 && num1.lsd->digit == 1) ||
				(num2.numof_digits == 1 && num2.lsd->digit == 1))
			{
				fputs("These numbers are coprimes", stdout);
			}
			else
			{
				fputs("These numbers are not coprimes", stdout);
			}
			free(num1.lsd);
			free(num2.lsd);
		}
		puts("\n\n");
	}
	_getch();
	return 0;
}
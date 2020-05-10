//Даны натуральное n и вещественное f. Вычислить значение выражения

#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
int main(void)
{
	int n = 1;
	int k = 0;
	double f, multiplied = 1, sum = 0;
	
	printf("Enter natural number for n: ");
	scanf_s("%d", &n);
	
	printf("Enter real number for f: ");
	scanf_s("%lf", &f);
	
	sum = (f+n)*n/2;
	
	for (int i = 1; i <= n; i++)
	{
		
		multiplied *= 1/sum;
	}
	printf("Answer: %lf", multiplied);
}

/*Численно убедиться в справедливости равенства, для чего для
заданного значения х вычислить его левую часть и разложение,
стоящее в правой части. При каком n исследуемое выражение
отличается от sin x менее, чем на заданную погрешность ε?
Испытать разложение на сходимость при разных значениях х.*/

#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <time.h>
double factorial(double x)
{
	if (x <= 0)
	{
		return 1;
	}
	return x * factorial(x - 1);
}
int iterative(double x, double e)
{
	int n = 1;
	double rightStatement = 0;
	double denominator;
	do
	{
		denominator = 2 * n - 1;
		rightStatement += (pow(-1, n - 1) * pow(x, 2 * n - 1)) / factorial(denominator);
		n++;
	} while (fabs(sin(x) - rightStatement) >= e);
	return n;
}
int recursive(double x, double e, int n, double right)
{
	double denominator = 2*n - 1;
	right += (pow(-1, (n - 1)) * pow(x, 2 * n - 1)) / factorial(denominator);
	if (fabs(sin(x) - right) < e)
	{
		return n;
	}
	return recursive(x, e, n+=1, right);
}
int main(void)
{
	setlocale(LC_ALL, "Rus");
	double x, e, rightStatement = 0;
	int n = 1;
	clock_t start, end;
	
	printf("Введите x: ");
	scanf_s("%lf", &x);
	
	printf("Введите погрешность: ");
	scanf_s("%lf", &e);
	
	start = clock();
	int NIterative = iterative(x, e);
	end = clock();
	double time = (double)(end - start) / CLK_TCK;
	printf("Итеративно:\n");
	printf("\tЧисло членов N = %d\n", NIterative);
	printf("\tВремя работы: %lf секунд\n", (double)(end - start) / CLK_TCK);

	start = clock();
	int NRecursive = recursive(x,e,n,rightStatement);
	end = clock();
	printf("Рекурсивно:\n");
	printf("\t Число членов N = %d\n", NRecursive);
	printf("\tВремя работы: %lf секунд", (double)(end - start) / CLOCKS_PER_SEC);
}

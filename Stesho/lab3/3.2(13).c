//Task 3.2(13)
/*
Дан целочисленный массив a(n,m). Упорядочить по неубыванию
элементы на главной диагонали и диагоналях, параллельных ей.
Перестановка элементов допускается только в пределах
соответствующей диагонали.
*/

#include <conio.h>
#include <stdio.h>
#include <malloc.h>
#include <locale.h>

void OutputArray(int* a, int n, int m);
void Sort(int* a, int n, int m);
int main()
{
	setlocale(LC_ALL, "Rus");
	int* a;
	int n, m;
	printf("Количество строк:");
	scanf_s("%d", &n);
	printf("Количество столбцов:");
	scanf_s("%d", &m);
	a = (int*)malloc(n * m * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("a[%d][%d] = ", i, j);
			scanf_s("%d", (a + i*m + j));
		}
	}
	OutputArray(a, n, m);
	printf("\n");
	Sort(a, n, m);
	OutputArray(a, n, m);
}
void OutputArray(int* a, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%4d", *(a + i * m + j));
		}
		printf("\n");
	}
}
void Sort(int* a, int n, int m)
{
	for (int k = 0; k < m; k++)
	{
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < m - 1; j++)
			{
				if (a[i * m + j] > a[(i + 1) * m + (j + 1)])
				{
					int temp = a[i * m + j];
					a[i * m + j] = a[(i + 1) * m + (j + 1)];
					a[(i + 1) * m + (j + 1)] = temp;
				}
			}
		}
	}
}

//3.2 (28). 
//Элементы массива a(n,m) ниже главной диагонали равны нулю.
//Выше и на главной диагонали нулевых элементов нет. Строки и
//столбцы случайным образом перемешаны. Перестановкой строк и
//столбцов восстановить исходный массив.


#include <stdio.h>
#include <malloc.h>
#include <time.h>

void FillArr(int** NameOfArray, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			NameOfArray[i][j] = rand() % 100 + 1;
		}
	}
}
void PrintArr(int** NameOfArray, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d\t", NameOfArray[i][j]);
		}
		printf("\n\n");
	}
}
void MixArr(int** NameOfArray, int n, int amountOfMixing)
{
	int column1, column2, line1, line2;
	for (int i = 0; i < amountOfMixing; i++)
	{
		column1 = rand() % n;
		column2 = rand() % n;
		ChangeColumns(NameOfArray, n, column1, column2);
		line1 = rand() % n;
		line2 = rand() % n;
		ChangeLines(NameOfArray, n, line1, line2);
	}
}
void RestoreArr(int** NameOfArray, int n)
{
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			int counter = 0;
			for (int j = 0; j < n; j++)
			{
				if (NameOfArray[i][j] == 0)
				{
					counter++;
				}
			}
			if (k == counter && i != counter)
			{
				ChangeLines(NameOfArray, n, i, counter);
				break;
			}
		}
	}
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			int counter = 0;
			for (int j = 0; j < n; j++)
			{
				if (NameOfArray[j][i] == 0)
				{
					counter++;
				}
			}
			if (k == counter && i != n - counter - 1)
			{
				ChangeColumns(NameOfArray, n, i, n - counter - 1);
				break;
			}
		}
	}
}
int ChangeColumns(int** NameOfArray, int n, int column1, int column2)
{
	for (int j = 0; j < n; j++)
	{
		int a = NameOfArray[j][column1];
		NameOfArray[j][column1] = NameOfArray[j][column2];
		NameOfArray[j][column2] = a;
	}
}
int ChangeLines(int** NameOfArray, int n, int line1, int line2)
{
	for (int j = 0; j < n; j++)
	{
		int a = NameOfArray[line1][j];
		NameOfArray[line1][j] = NameOfArray[line2][j];
		NameOfArray[line2][j] = a;
	}
}

int main()
{
	srand(time(NULL));
	int amountOfMixing = rand() % 50 + 10;
	int n = 0, m = 0;
	printf("n = ");
	scanf_s("%d", &n);
	system("cls");
	int** numArr = (int**)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		numArr[i] = (int*)calloc(n, sizeof(int));
	}
	FillArr(numArr, n);
	PrintArr(numArr, n);
	MixArr(numArr, n, amountOfMixing);
	printf("\n\n");
	PrintArr(numArr, n);
	RestoreArr(numArr, n);
	printf("\n\n");
	PrintArr(numArr, n);
	for (int i = 0; i < n; i++)
	{
		free(numArr[i]);
	}
	free(numArr);
	return 0;
}

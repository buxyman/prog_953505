/*Пирог. Имеется прямоугольный пирог, разрезанный на m×n частей
(клеток), причем, левая нижняя клетка пирога отравлена. Игроки по
очереди выбирают какую-нибудь клетку пирога и «съедают» ее
вместе со всеми клетками, расположенными правее и выше
выбранной. Проигрывает тот, кто съедает отравленную клетку.*/

#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>
#include <locale.h>
int main(void)
{
	setlocale(LC_ALL, "Rus");
	int n = 0, m = 0, column = 0, string = 0;
	printf("N - количество строк, M - количество столбцов. 0 - не съеденный кусок пирога, 1 - съеденный, 2 - отравленный.\n\n");
	printf("Введите n: ");
	scanf_s("%d", &n);
	printf("Введите m: ");
	scanf_s("%d", &m);

	int** Array = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		Array[i] = (int*)malloc(m * sizeof(int));
	}
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < m; k++)
		{
			Array[i][k] = 0;
		}
	}
	Array[n - 1][0] = 2;
	while (true)
	{
		system("cls");
		printf("N - количество строк, M - количество столбцов. 0 - не съеденный кусок пирога, 1 - съеденный, 2 - отравленный.\n\n");
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				printf("%d", Array[i][j]);
				printf("  ");
			}
			printf("\n");
		}
		printf("Выберите столбец: ");
		scanf_s("%d", &column);
		printf("Выберите строку: ");
		scanf_s("%d", &string);
		if (Array[string][column] == 2)
		{
			printf("Вы проиграли");
			break;
		}
		if (Array[string][column] != 1)
		{
			Array[string][column] = 1;
			if (string > 0)
			{
				if (Array[string - 1][column] != 1)
				{
					Array[string - 1][column] = 1;
				}
			}
			if (column != (m - 1))
			{
				if (Array[string][column + 1] != 1)
				{
					Array[string][column + 1] = 1;
				}
			}
		}
		else
		{
			printf("Кусок уже съеден, выберите другой\n");
			Sleep(1000);
		}
	}
	for (int i = 0; i < n; i++)
	{
		free(Array[i]);
	}
	free(Array);
}

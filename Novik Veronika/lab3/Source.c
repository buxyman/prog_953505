/*19. Пирог. Имеется прямоугольный пирог, разрезанный на m×n частей
(клеток), причем, левая нижняя клетка пирога отравлена. Игроки по
очереди выбирают какую-нибудь клетку пирога и «съедают» ее
вместе со всеми клетками, расположенными правее и выше
выбранной. Проигрывает тот, кто съедает отравленную клетку.*/

#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int check(void)
{
	int summa, f; char a;
	f = 0;
	while (f == 0)
	{
		summa = 0;
		a = '0';
		while ((a >= '0') && (a <= '9')) {
			scanf_s("%c", &a);
			if (a == '\n') {
				break;
			}
			summa = summa * 10 + (a - '0');

		}
		if (a != '\n') {
			printf("your value is unacceptable !");
			while (a != '\n') {
				scanf_s("%c", &a);
			}
		}
		else {
			f = 1;
		}
	}
	return summa;
}

int main(void)
{
	int row, colomn, x, y; int** arr;
	int count = 0;
	printf_s("enter the amount of rows of the main array ");
	row = check();
	printf_s("enter the amount of colomns of the main array ");
	colomn = check();
	arr = (int**)malloc(row * sizeof(int));
	for (int i = 0; i < row; i++)
	{
		arr[i] = (int*)malloc(colomn * sizeof(int));

	}
	for (int i = 0; i < row; i++)
		for (int j = 0; j < colomn; j++)
			arr[i][j] = 1;
	arr[row - 1][0] = -1;
	int person = 1;
	while (1) {
		printf("person %d should to choose a piece", person);
		for (int i = 0;i < row;i++)
		{
			for (int j = 0;j < colomn;j++) 
				printf("%3d", arr[i][j]);
			printf("\n");
		}
		printf("choose a piece and enter the number of the row");
		x = check();
		x--;
		printf("choose a piece and enter the number of the colomn");
		y = check();
		y--;
		if ((x >= row) || (y >= colomn) || (x < 0) || (y < 0)) {
			printf("false");
		}
		else {
			if (arr[x][y] == 0) {
				printf("almost");
			}
			if (arr[x][y] == 1) {
				for (int i = 0; i < row; i++)
					for (int j = 0; j < colomn; j++)
						arr[i][j] = 0;
				if (person == 2) {
					person = 1;
				}
				else {
					person = 2;
				}
			}
			if (arr[x][y] == -1) {
				break;
			}
		}
	}
	printf("person %d lost:(", person);
	free(arr);
	return 0;
	
}

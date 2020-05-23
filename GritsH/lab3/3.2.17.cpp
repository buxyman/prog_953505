// 3.2.17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>

int main(void)
{
	int row, colomn, sqrRow, sqrColomn, posj, posi, i = 0, j = 0, counter = 0;
	printf_s("Enter the amount of lines of the main array: ");
	scanf_s("%d", &row);
	printf_s("Enter the amount of colomns of the main array: ");
	scanf_s("%d", &colomn);
	int** array = (int**)malloc(row * sizeof(int*));
	for (int i = 0; i < row; i++)
	{
		array[i] = (int*)malloc(colomn * sizeof(int));
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < colomn; j++)
		{
			array[i][j] = rand() % 2;
		}
	}
	printf_s("\nMain array:\n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < colomn; j++)
		{
			printf_s("%d\t", array[i][j]);
		}
		printf_s("\n");
	}
	printf_s("Enter the amount of rows in the 'black square': ");
	scanf_s("%d", &sqrRow);
	printf_s("Enter the amount of colomns in the 'black square': ");
	scanf_s("%d", &sqrColomn);
	int** square = (int**)malloc(sqrRow * sizeof(int*));
	for (int i = 0; i < sqrRow; i++)
	{
		square[i] = (int*)malloc(sqrColomn * sizeof(int));
	}
	for (int i = 0; i < sqrRow; i++)
	{
		for (int j = 0; j < sqrColomn; j++)
		{
			square[i][j] = 0;
		}
	}
	for (; i < row; i++)
	{
		for (; j < colomn; j++)
		{
			counter = 0;
			if (array[i][j] == 0)
			{

				for (posi = i; posi < sqrRow + i; posi++)
				{
					for (posj = j; posj < sqrColomn + j; posj++)
					{
						if (posi >= row && posj >= colomn)
						{
							continue;
						}
						else
						{
							if (array[posi][posj] == 0)
							{
								counter++;
							}
							if (counter == sqrColomn * sqrRow)
							{

								for (int i = 0; i < sqrRow; i++)
								{
									for (int j = 0; j < sqrColomn; j++)
									{
										printf_s("%d ", square[i][j]);
									}
									printf_s("\n");
								}

								for (int i = 0; i < sqrRow; i++)
								{
									free(square[i]);
								}
								free(square);

								for (int i = 0; i < row; i++)
								{
									free(array[i]);
								}
								free(array);
								return 0;

							}
							//printf_s("ssss");
							
						}

					}

				}
			}
		}
	}
	printf_s("hhh");
	for (int i = 0; i < sqrRow; i++)
	{
		free(square[i]);
	}
	free(square);

	for (int i = 0; i < row; i++)
	{
		free(array[i]);
	}
	free(array);
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

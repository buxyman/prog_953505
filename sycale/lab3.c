#include <stdio.h>
#include <stdlib.h>

#define scanf_s scanf
#define printf_s printf 


int main(void)
{
    int row, column, sqrRow, sqrColumn, posj, posi, i = 0, j = 0, counter = 0;
    printf_s("Enter the amount of lines of the main array: ");
    scanf_s("%d", &row);
    printf_s("Enter the amount of colomns of the main array: ");
    scanf_s("%d", &column);
    int** array = (int **)malloc(row * sizeof(int*));
    for(int i = 0; i < row; i++) 
        array[i] = (int *)malloc(column * sizeof(int));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            array[i][j] = rand() % 2;
        }
    }
    printf_s("\nMain array:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf_s("%d\t", array[i][j]);
        }
        printf_s("\n");
    }
    printf_s("Enter the amount of rows in the 'black square': ");
    scanf_s("%d", &sqrRow);
    printf_s("Enter the amount of colomns in the 'black square': ");
    scanf_s("%d", &sqrColumn);
    int** square = (int **)malloc(sqrRow * sizeof(int*));
    for (int i = 0; i < sqrRow; i++)
    {
        square[i] = (int *)malloc(sqrColumn * sizeof(int));
    }
    for (int i = 0; i < sqrRow; i++)
    {
        for (int j = 0; j < sqrColumn; j++)
        {
            square[i][j] = 0;
        }
    }
    for (; i < row; i++)
    {
        for (; j < column; j++)
        {
            counter = 0;
            if (array[i][j] == 0)
            {

                for (posi = i; posi < sqrRow + i; posi++)
                {
                    for (posj = j; posj < sqrColumn + j; posj++)
                    {
                        if (posi >= row && posj >= column)
                        {
                            continue;
                        }
                        else
                        {
                            if (array[posi][posj] == 0)
                            {
                                counter++;
                            }
                            if (counter == sqrColumn * sqrRow)
                            {
                                for (int i = 0; i < sqrRow; i++)
                                {
                                    for (int j = 0; j < sqrColumn; j++)
                                    {
                                        printf_s("%d ", square[i][j]);
                                    }
                                    printf_s("\n");
                                }
                                exit(1);
                            }

                        }

                    }
                }
            }
        }
    }
    for(int i = 0; i < row; i += 1)
    {
        free(array[i]);
    }
    free(array);
    for(int i = 0; i < sqrRow; i += 1)
    {
        free(square[i]);
    }
    free(square);
}
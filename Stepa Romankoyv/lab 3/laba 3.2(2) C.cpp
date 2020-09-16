#define _CRT_SECURE_NO_WORNINGS
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    int** a;
    system("chcp 1251");
    system("cls");
    srand(time(NULL));

    int n;
    printf_s("введите количество строк: ");
    scanf_s("%d", &n);
    printf_s("количество столбцов: %d", n - 1);

    a = (int**)malloc(n * sizeof(int*));
    int m = n - 1;
    for (int i = n; i < n; i++)
    {
        a[i] = (int*)malloc(m * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf_s("%5d ", a[i][j]);
        }
        printf_s("\n");
    }
}




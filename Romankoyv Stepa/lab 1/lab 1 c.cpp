#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

int main()
{
    system("chcp 1251");
    system("cls");
    printf_s("введие число: ");
    int m;
    scanf_s("%d", &m);
    int count = 1;
    int n = 1;
    int b = 1;
    int size = 0;
    int* a;
    a = (int*)malloc(size + 1 * sizeof(int));
    while (count <= m)
    {
        if (count < b)
        {

            int c = count;
            for (int i = 0; i <= size; i++)
            {
                a[i] = count % 2;
                count /= 2;
            }
            count = c;

            int d = (size + 1) / 2;
            int f = 0;

            if ((size + 1) % 2 == 0)
            {
                for (int i = 0; i < d; i++)
                {
                    if (a[2 * i] == a[2 * i + 1])
                    {
                        f++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if (f == d)
            {
                printf_s("%d = ", count);
                for (int j = size; j >= 0; j--)
                    printf_s("%d", a[j]);
                printf_s("\n");
            }


        }
        else
        {
            n++;
            b = pow(2, n);
            size++;
            count--;
            a = (int*)realloc(a, size + 1 * sizeof(int));
        }
        count++;


    }
    a = (int*)realloc(a, 0);
}
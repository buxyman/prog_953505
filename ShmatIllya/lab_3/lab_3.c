#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//================ Вариант 4 ======================
int main()
{
setlocale(LC_ALL, "rus");
printf("Внимание! Данная программа полностью зависит от случайностей в создании массива, поэтому большую часть её итераций вам\nпридётся лицезреть ответ в виде нуля, однако спешу заверить в том, что программа работает.\nВсё, что необходимо, - это терпение.\n\n");
srand(time(NULL));
int **array=(int**)malloc(5*sizeof(int*));
int n=0, count=0;
for (int i=0;i<5;i++)
{
    array[i]=(int*)malloc(5*sizeof(int));
}
int* array2=(int*)malloc(5*sizeof(int));
int* array3=(int*)malloc(5*sizeof(int));
for (int i=0;i<5;i++)
{
    for(int j=0;j<5;j++)
    {
        array[i][j]=rand()%5+1;
    }
}
printf("Исходная матрица:\n");
for (int i=0;i<5;i++)
{
    for(int j=0;j<5;j++)
    {
        printf("%d ", array[i][j]);
    }
    printf("\n");
}
printf("\n");
for (int j=0;j<5;j++)
{
    for (int i=0;i<5;i++)
    {
        array2[i]=array[i][j];
    }
    for (int j2=j+1;j2<5;j2++)
    {
        for (int j3=0;j3<5;j3++)
        {
            array3[j3]=array[j3][j2];
        }
        for (int i2=0;i2<5;i2++)
        {
            for (int i3=0;i3<5;i3++)
            {
                if (array2[i2]==array3[i3])
                {
                    n++;
                    array3[i3]=0;
                    break;
                }
            }
        }
        if (n==5)
        {
            printf("Найдены похожие столбцы:\n");
           count++;
           for (int y=0;y<5;y++)
           {
               printf("%d ", array[y][j]);
           }
           printf("\n");
           for (int y=0;y<5;y++)
           {
               printf("%d ", array[y][j2]);
           }
           printf("\n\n");
        }
        n=0;
    }
}
printf("Количество пар похожих столбцов:");
printf("\n%d\n", count);
for (int i=0;i<5;i++)
{
    free(array[i]);
}
free(array);
free(array2);
free(array3);
    return 0;
}

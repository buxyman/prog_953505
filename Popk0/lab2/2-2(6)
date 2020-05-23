//IDE: CodeBlocks
//Task 2.2(6) - общее для всех
/*
    Численно убедиться в справедливости равенства, для чего для
    заданного значения х вычислить его левую часть и разложение,
    стоящее в правой части. При каком n исследуемое выражение
    отличается от sin x менее, чем на заданную погрешность E?
    Испытать разложение на сходимость при разных значениях х.
*/

#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>


typedef int bool;
#define false 0
#define true 1

long double fact (int N)
{
    if(N<2) return 1;
    return N * fact(N-1);
}

double absolute(double x)
{
    if(x > 0) return x;
        else return -x;
}

int func(double x,long double epsilon, int n,long double sinX,long double sum)
{
    if (fabs((sinX - sum) / sinX) < (epsilon))
    {
        return n - 1;
    }
    sum += (((n+1)%2)?(-1):(1))*pow(x,2*n-1)/fact(2*n-1);
    return func(x, epsilon, n+1, sinX, sum);
}

int main()
{
    setlocale(0,"");
    double x, sinX = 0, temp, accuracy, y_row_acc;
    int n, n_acc;
    bool IsFound = true;
    printf("Введите x: ");
    scanf("%lf", &x);
    printf("\nВведите точность: ");
    scanf("%lf", &accuracy);
    sinX = sin(x);

    double y_row_temp = 0;
    int i = 1;

    double rez = 0;
    time_t now  = time(0);
    while(IsFound == true)
    {
        if((i-1) % 2 == 0) temp = 1;
        else temp = -1;

        for(int j=1; j <= 2*i-1; j++)
        {
            temp/=j;
            temp*=x;
        }
        y_row_temp+=temp;

        if(absolute((y_row_temp-sinX) / sinX) <= accuracy && IsFound == true)
        {
            y_row_acc = y_row_temp;
            n_acc = i;
            IsFound = false;
            rez = difftime(time(0), now);
            printf("\n\nВаша точность достигается при n = %d, где значение: %.16f\n", n_acc, y_row_acc);
        }
        i++;
    }

    double rez2 = 0;
    now = time(0);
    printf("\n\n\aЕсли рекурсивно, то ваша точность достигается при  n = %d\n", func(x,accuracy,1,sinX,0));
    printf("\nСамо значение функции(sin(x)):  %.16f\n\n", sinX);

    rez2 = difftime(time(0), now);
    if (rez > rez2)
    {
        printf("\nИтерационный способ быстрее");
    }
    else{
        printf("\nРекурсивный метод быстрее");
    }
    printf ( ", в данном случае\n");

    getch();
    return 0;
}

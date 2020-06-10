#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
//======================== Вариант 21 ====================
char* itob(int num, char* result, int base)
{
    if (num==0)
     {
          return '\0';
     }

        char res;
    int i, length = strlen(result);
    if(num%base > 9)
    {
        res = (char)(num%base-10)+'A';
    }
        else
        {
            res = (char)(num%base)+'0';
        }

        for(i=length;i>-1;i--)
        {
            result[i+1]=result[i];
        }

    result[0]=res;

        itob(num/base, result, base);
        return result;
}


int main()
{
    setlocale(LC_ALL, "rus");
    int b;
    long n;
    printf("Введите число:\nn = ");
    ln: scanf("%d", &n);
    if (n<=0)
    {
        printf("Ошибка ввода. Минимальное число для ввода-1\n");
        goto ln;
    }
    printf("Введите систему счисления:\nb = ");
    lm: scanf("%d", &b);
    if (b<2)
    {
        printf("Ошибка ввода. Минимальное число для ввода-2\n");
        goto lm;
    }
    char result[80]="";
    itob(n,result,b);
    printf("%s", result);


    return 0;
}


/*Многострочный текст, введенный с клавиатуры, выровнять по
ширине, вставляя дополнительные пробелы между словами
(равномерно по всей строке).*/
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define N 60
void Align(char*);
int main()
{
    char* str;
    str = (char*)malloc(500 * sizeof(char));
    printf("Input text: ");
    fgets(str, 360, stdin);
    Align(str);
    free(str);
    return 0;
}
void Align(char* str)
{
    char* first, * last, * end;
    char delim[] = ",.; :!?";
    int i = 0, flag = 0, count = 0, finish = 0;
    end = &str[strlen(str)];
    last = first = str;
    while (!finish) 
    {
        last += N;
        if (last >= end)
        {
            last = end - 1;
            finish = 1;
        }
        flag = 0;
        while (!flag && !finish)
        {
            for (i = 0; delim[i]; i++)
                if (*last == delim[i])
                {
                    flag = 1;
                    break;
                }
            if (!flag)
            {
                last--;
            }
        }
        char* last1 = last, * first1 = first;
        int number_of_words = 0, spaces_in_row = 0, rest_of_spaces = 0, flag2 = 0;
        int number_of_spaces = N - (last - first);
        count = 0;
        if (number_of_spaces > 2) 
        {
            while (first1 <= last1) 
            {
                for (i = 0; delim[i]; i++)
                {
                    if (*first1 == delim[i]) 
                    {
                        number_of_words++;
                        break;
                    }
                }
                first1++;
            }
            if (number_of_spaces > number_of_words) 
            {
                spaces_in_row = number_of_spaces / number_of_words;
                rest_of_spaces = number_of_spaces % number_of_words;
                for (int j = spaces_in_row; j; j--)
                {
                    putchar(' ');
                }
            }
            else {
                rest_of_spaces = number_of_spaces;
                if (rest_of_spaces-- > 0)
                {
                    putchar(' ');
                }
            }
            while (first <= last) 
            {
                flag2 = 0;
                while (!flag2)
                {
                    for (i = 0; delim[i]; i++)
                    {
                        if (*first == delim[i])
                        {
                            flag2 = 1;
                        }
                    }
                    putchar(*first++);
                }
                if (spaces_in_row && first < last)
                {
                    for (int j = spaces_in_row; j; j--)
                    {
                        putchar(' ');
                    }
                }
                if (rest_of_spaces-- > 0)
                {
                    putchar(' ');
                }
            }
        }
        else
        {
            while (last - first + count++ < N)
            {
                putchar(' ');
            }
            while (first <= last)
            {
                putchar(*first++);
            }
        }
        putchar('\n');
    }
}

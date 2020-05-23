#include <stdio.h>
#include <string.h>



int main()
{
    char stroka[80];
    char reverse[80];
    int i, j, len=0;
    printf("Input string:\n");
    gets (stroka);
    len=strlen(stroka)-1;
    j=0;
    for (i=len; i>=0; i--)
    {
        reverse[j++]=stroka[i];
    }
    reverse[j]=0;
    printf("\nReverse string: %s \n", reverse);
}
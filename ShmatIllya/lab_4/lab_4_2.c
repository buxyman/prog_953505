#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
//================== Âàğèàíò 21 ================
char* check(char temp[100])
{
char array1[29]="ÀÁÂÃÄÅ¨ÆÇÈÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙİŞß";
char array2[29]="àáâãäå¸æçèêëìíîïğñòóôõö÷øùışÿ";
int e=0;
for (int i=0;temp[i]!='\0';i++)
{
    if (temp[i]==' ')
    {
        for (int y=i+1;temp[y]==' ';y++)
        {
            temp[y]='i';
        }
    }
}
char* temp2=malloc(100*sizeof(char));
for (int i=0,y=0; temp[i]!='\0'; i++)
{
    if (temp[i]!='i')
    {
        temp2[y]=temp[i];
        y++;
    }
}
for (int i=0; temp2[i]!='\0'; i++)
{
    if (i==0)
    {
        for (int i1=0; array1[i1]!='\0'; i1++)
        {
           if (temp[i]==array1[i1])
           {
               e++;
               break;
           }
        }
        if (e==0)
        {
            for (int i2=0; array2[i2]!='\0'; i2++)
            {
                if (temp2[i]==array2[i2])
                {
                    temp2[i]=array1[i2];
                    break;
                }
            }
        }
        e=0;
    }
    if (temp2[i]=='.'||temp2[i]=='!'||temp2[i]=='?')
    {
        for (int i1=0; array1[i1]!='\0'; i1++)
        {
           if (temp2[i+2]==array1[i1])
           {
               e++;
               break;
           }
        }
        if (e==0)
        {
            for (int i2=0; array2[i2]!='\0'; i2++)
            {
                if (temp2[i+2]==array2[i2])
                {
                    temp2[i+2]=array1[i2];
                    break;
                }
            }
        }
        e=0;
    }
}
return temp2;
}
int main()
{
    setlocale(LC_ALL, "rus");
    FILE *fp;
    int i=0;
    char temp[100];

    fp=fopen("text.txt", "r");
    if (!fp)
    {
        printf("Nothing found");
    }
    while (fgets(temp, 80, fp) != NULL)
    {
        i++;
    }
    free(fp);
    printf("Ñ÷èòàííûé òåêñò:\n%s\n", temp);
    char* tempresult=check(temp);
    printf("Ğóçóëüòàò:\n%s", tempresult);
    return 0;
}

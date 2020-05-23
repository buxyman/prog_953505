#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool check_if_opened(FILE* fp)
{
    if(fp == NULL)
    {
        return 0;
    }
    else
        return 1;
}

bool checker(char * s, int counter)
{
    if (counter < 0) return false;

    for(;*s;++s)
        switch(*s)
        {
            case '(': return checker(s+1,counter+1);
            case ')': return checker(s+1,counter-1);
        }
    return (counter == 0);
}


bool checker_second(char * s, int counter)
{
    if (counter < 0) return false;

    for(;*s;++s)
        switch(*s)
        {
            case '{': return checker_second(s+1,counter+1);
            case '}': return checker_second(s+1,counter-1);
        }
    return (counter == 0);
}

bool checker_third(char * s, int counter)
{
    if (counter < 0) return false;

    for(;*s;++s)
        switch(*s)
        {
            case '[': return checker_third(s+1,counter+1);
            case ']': return checker_third(s+1,counter-1);
        }
    return (counter == 0);
}

bool tests(char* str)
{
    return checker(str, 0) && checker_second(str, 0) && checker_third(str, 0);
}

int main()
{
    FILE* fp;
    char str[80];
    const char* filename = "./text.txt";
    fp = fopen(filename, "r");
    if(check_if_opened(fp))
    {
        while(fgets(str, 80, fp) != NULL)
        {
            printf("%s", str);
        }
        if(tests(str))
        {
            printf("true");
        }
        else 
            printf("false");

        printf("\n");
        fclose(fp);
    }
    else
    {
        printf("Can't open %s", filename);
    }

    return 0;

}
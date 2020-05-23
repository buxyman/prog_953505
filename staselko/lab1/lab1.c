//Найти сумму первых трех цифр дробной части вещественного
//числа.
#include <stdio.h>

int main()
{
    int startNumber;
    printf("Enter the value:");
    scanf("%d", &startNumber);
//    counting remainder
    printf("Number with remainder:\n %d", startNumber%10 + startNumber%100 + startNumber%1000);
    return 0;
}


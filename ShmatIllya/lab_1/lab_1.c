#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>
//====================== Вариант 16 ==========================
int main()
{
setlocale(LC_ALL, "rus");
int no;
printf("Введите десятичное число");
printf("\nВнимание! Начиная с 4000, ввиду отстутствия возможности использовать горизонтальнную черту поверх символа, будет использоваться символ - перед записью соответствующего символа(Например -V, M-V и т.д.)");
scanf("%d",&no);
if (no==1000000) {printf("\nВаше число в римской системе счисления: -M"); return 0;}
int ones1=0;
char* ones2;
int tens1=0;
char* tens2;
int decades1=0;
char* decades2;
int thousands1=0;
char* thousands2;
int tenthousands1=0;
char* tenthousands2;
int decadethousands1=0;
char* decadethousands2;
for (ones1=0; no%10!=0; no--,ones1++)
{
if (no==0) {break;}
}
switch (ones1)
{   case 0: {ones2=""; break;}
    case 1: {ones2="I"; break;}
    case 2: {ones2="II"; break;}
    case 3: {ones2="III"; break;}
    case 4: {ones2="IV"; break;}
    case 5: {ones2="V"; break;}
    case 6: {ones2="VI"; break;}
    case 7: {ones2="VII"; break;}
    case 8: {ones2="VIII"; break;}
    case 9: {ones2="IX"; break;}
    default: {}
}
for (tens1=0; no%100!=0; no-=10,tens1++)
{
 if (no==0) {break;}
}
switch (tens1)
{   case 0: {tens2=""; break;}
    case 1: {tens2="X"; break;}
    case 2: {tens2="XX"; break;}
    case 3: {tens2="XXX"; break;}
    case 4: {tens2="XL"; break;}
    case 5: {tens2="L"; break;}
    case 6: {tens2="LX"; break;}
    case 7: {tens2="LXX"; break;}
    case 8: {tens2="LXXX"; break;}
    case 9: {tens2="LC"; break;}
    default: {}
}
for (decades1=0; no%1000!=0; no-=100,decades1++)
{
 if (no==0) {break;}
}
switch (decades1)
{   case 0: {decades2=""; break;}
    case 1: {decades2="C"; break;}
    case 2: {decades2="CC"; break;}
    case 3: {decades2="CCC"; break;}
    case 4: {decades2="CD"; break;}
    case 5: {decades2="D"; break;}
    case 6: {decades2="DC"; break;}
    case 7: {decades2="DCC"; break;}
    case 8: {decades2="DCCC"; break;}
    case 9: {decades2="CM"; break;}
    default: {}
}
for (thousands1=0; no%10000!=0; no-=1000,thousands1++)
{
 if (no==0) {break;}
}
switch (thousands1)
{   case 0: {thousands2=""; break;}
    case 1: {thousands2="M"; break;}
    case 2: {thousands2="MM"; break;}
    case 3: {thousands2="MMM"; break;}
    case 4: {thousands2="M-V"; break;}
    case 5: {thousands2="-V"; break;}
    case 6: {thousands2="-VM"; break;}
    case 7: {thousands2="-VMM"; break;}
    case 8: {thousands2="-VMMM"; break;}
    case 9: {thousands2="M-X"; break;}
    default: {}
}
for (tenthousands1=0; no%100000!=0; no-=10000,tenthousands1++)
{
 if (no==0) {break;}
}
switch (tenthousands1)
{   case 0: {tenthousands2=""; break;}
    case 1: {tenthousands2="-X"; break;}
    case 2: {tenthousands2="-X-X"; break;}
    case 3: {tenthousands2="-X-X-X"; break;}
    case 4: {tenthousands2="-X-L"; break;}
    case 5: {tenthousands2="-L"; break;}
    case 6: {tenthousands2="-L-X"; break;}
    case 7: {tenthousands2="-L-X-X"; break;}
    case 8: {tenthousands2="-L-X-X-X"; break;}
    case 9: {tenthousands2="-X-C"; break;}
    default: {}
}
for (decadethousands1=0; no%1000000!=0; no-=100000,decadethousands1++)
{
 if (no==0) {break;}
}
switch (decadethousands1)
{   case 0: {decadethousands2=""; break;}
    case 1: {decadethousands2="-C"; break;}
    case 2: {decadethousands2="-C-C"; break;}
    case 3: {decadethousands2="-C-C-C"; break;}
    case 4: {decadethousands2="-C-D"; break;}
    case 5: {decadethousands2="-D"; break;}
    case 6: {decadethousands2="-D-C"; break;}
    case 7: {decadethousands2="-D-C-C"; break;}
    case 8: {decadethousands2="-D-C-C-C"; break;}
    case 9: {decadethousands2="-C-M"; break;}
    default: {}
}
printf("\nВаше число в римской системе счисления: %s%s%s%s%s%s", (decadethousands2), (tenthousands2), (thousands2), (decades2), (tens2), (ones2));
return 0;
}

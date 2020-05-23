#include<stdio.h>
int main(){
int a,b, tmp,x,i;
char format[8];
scanf("%d %d ", &a,&b);
printf("%d x %d\n", a,b);
printf("%15d\n%15d\n%15s\n", a,b,"");
i=15;
x=b%10;
tmp=b/10;
while(tmp || x) {
sprintf(format, "%%%dd\n", i--);
printf(format, x*a);
x = tmp%10;
tmp = tmp / 10;
}
printf("%15s\n%15d\n", "_", a*b);
return 0;
}

/*Волга-матушка. Гидрологами произведена серия замеров по прямой
от берега до берега реки перпендикулярно фарватеру. Получены
данные: si – расстояние от левого берега, м; hi – глубина реки, м; vi –
скорость течения, м/с, i = 1, 2,..., n. Каков расход воды в сечении, т.е.
сколько кубометров воды протекает через сечение реки в секунду?*/
// main.c
// laba 3.2.22
//
// Created by Ilyass-Emir on 4/27/20.
// Copyright © 2020 malumba. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {

float *a, *b, *c;
float square,res,speed;
int i;
printf("Enter i ");
scanf("%d",&i);
a= (float*)malloc(i*sizeof(float));
b= (float*)malloc(i*sizeof(float));
c= (float*)malloc(i*sizeof(float));

printf("input distance");

for (int j=0; j<i; j++)
{
scanf("%f",&a[j]);
}

printf("input depth");

for (int j=0; j<i; j++)

{
scanf("%f",&b[j]);
}

printf("input speed");

for (int j=0; j<i; j++)
{
scanf("%f",&c[j]);
}

square =a[0]*b[0]/2;
for (int k=1;k<i; k++) {
square += a[k]*b[k]/2;
}
for (int k=0; k<i; k++) {
speed+=b[k];
}
speed /=i;
res=square -speed;
printf("\nwater consumption is: %f\n",res);

return 0;
}

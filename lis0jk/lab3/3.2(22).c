//Task 3.2.22
/*Гидрологами произведена серия замеров по прямой
от берега до берега реки перпендикулярно фарватеру. Получены
данные: si – расстояние от левого берега, м; hi – глубина реки, м; vi –
скорость течения, м/с, i = 1, 2,..., n. Каков расход воды в сечении, т.е.
сколько кубометров воды протекает через сечение реки в секунду?*/

#include <stdio.h>
#include <conio.h>
#include <malloc.h>

float Count(float* h, float* s, float l, int count)
{
	float as = 0, ah = 0, j = 0, square, sp;
	for (int i = 0; i < count; i++)
	{
		ah = (ah + h[i]) / (j + 1.0);
		j++;
	}
	j = 0;
	for (int i = 0; i < count; i++)
	{
		as = (as + s[i]) / (j + 1.0);
		j++;
	}
	square = ah * l;
	sp = square * as;
	delete[] h;
	delete[] s;
	return sp;
}

int main()
{
	float* v, * h, l;
	int n;
	printf("Count of steps: ");
	scanf_s("%d", &n);
	printf("Length of farvaters: ");
	scanf_s("%f", &l);
	v = (float*)malloc(sizeof(float) * n);
	h = (float*)malloc(sizeof(float) * n);
	for (int i = 0; i < n; i++)
	{
		printf("Speed[%d]: ", i + 1);
		scanf_s("%f", &v[i]);
		printf("Height[%d]: ", i + 1);
		scanf_s("%f", &h[i]);
	}
	printf("Spending: %f", Count(h, v, l, n));
}

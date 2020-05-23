#include <iostream>
#include <math.h>
#include <cmath>
#include <windows.h>
//add iteration steps
void IterFunc(float eps, float angle, float rSide, float lSide, float difference, float element)
{
	int i = 1;
	for (i = 1; difference > eps; i++)
	{
		rSide += element;
		element *= (-1) * angle * angle / (2 * i) / (2 * i + 1);
		difference = abs(rSide - lSide);
	}
	printf_s("sin(%f)=%f\n", angle, rSide);
	printf_s("Итерационных шагов= %d", i);
}

void RecFunc(float eps, float angle, float rSide, float lSide, float difference, float element, int i)
{

	rSide += element;
	element *= (-1) * angle * angle / (2 * i) / (2 * i + 1);
	difference = abs(rSide - lSide);
	if (difference > eps)
	{
		i = i + 1;
		RecFunc(eps, angle, rSide, lSide, difference, element, i);
	}

	else
	{
		printf_s("Итерационных шагов= %d \n", i);
		printf_s("sin(%f)=%f\n", angle, rSide);
	}
}


void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	float x = 0, LeftSide = 0, epsilon = 0, NewElement = 0, RightSide = 0, difference = 1;
	int i = 1;

	printf_s("Введите угол (в радианах): ");
	scanf_s("%f", &x);
	printf_s("Введите погрешность: ");
	scanf_s("%f", &epsilon);

	LeftSide = sin(x);                                                                                                                                                                                                                                                                                                                                                                        
	NewElement = x;

	printf_s("\nИспользование итерационной функции:\n");
	IterFunc(epsilon, x, RightSide, LeftSide, difference, NewElement);
	printf_s("\n\nИспользование рекурсивной функции:\n");
	RecFunc(epsilon, x, RightSide, LeftSide, difference, NewElement, i);
}


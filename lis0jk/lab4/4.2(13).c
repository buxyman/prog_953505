//Task 4.2.13
/*Текст в файле содержит числа, которые записаны в восьмеричной
системе счисления. Преобразовать эти числа в десятичную систему
счисления и записать отредактированный текст обратно в файл.*/

#include <iostream>
#include <math.h>
#include <cmath>

void iterFunc(float eps, float angle, float rSide, float lSide, float difference, float element)
{
	int i;
	for (i = 1; difference > eps; i++)
	{
		rSide += element;
		element *= (-1) * angle * angle / (2 * i) / (2 * i + 1);
		difference = abs(rSide - lSide);
	}
	printf_s("sin(%f) = %f\n", angle, rSide);
	printf_s("Iteration steps = %d", i);
}

void recFunc(float eps, float angle, float rSide, float lSide, float difference, float element, int i)
{
	rSide += element;
	element *= (-1) * angle * angle / (2 * i) / (2 * i + 1);
	difference = abs(rSide - lSide);
	if (difference > eps)
	{
		i++;
		recFunc(eps, angle, rSide, lSide, difference, element, i);
	}

	else
	{
		printf_s("Iteration steps = %d \n", i);
		printf_s("sin(%f) = %f\n", angle, rSide);
	}
}

void main()
{
	float x = 0, leftSide = 0, epsilon = 0, newElement = 0, rightSide = 0, diff = 1;
	int i = 1;
	printf_s("Angle (radians): ");
	scanf_s("%f", &x);
	printf_s("Epsilon: ");
	scanf_s("%f", &epsilon);
	leftSide = sin(x);                                                                                                                                                                                                                                                                                                                                                                        	leftSide = sin(x);
	newElement = x;
	printf_s("\nUsing iteration function:\n");
	iterFunc(epsilon, x, rightSide, leftSide, diff, newElement);
	printf_s("\n\nUsing recursion:\n");
	recFunc(epsilon, x, rightSide, leftSide, diff, newElement, i);
}

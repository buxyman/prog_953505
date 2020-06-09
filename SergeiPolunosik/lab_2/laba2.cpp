#include <iostream>
#include<stdio.h>
#include <conio.h>

int GetPerimetr(int n)
{
	return n * 6;
}

int GetSquare(int n)
	{

	return n * n * sqrt(3) / 4 * 6;
	}

int GetHeight(int n)
{
	return sqrt(2.0 / 3) * n;
}

int GetCapacity(int n)
{
	return (sqrt(3) * sqrt(2.0 / 3)) / 12 * n * n * n;
}

int GetR(int n)
{
	return n / (sqrt(6) * 2);
}

void GetDataAboutVersion()
{
	printf("Version 'laba 2' by Polunosik Segrei");
}

float Factorial(int n)
{
	if (n < 0)
	{
		return 0;
	}

	if (n == 0)
	{
		return 1;
	}
	else
	{
		return n * Factorial(n - 1);
	}
}

void Exe_2_2_6(float x)
{
	float result = 0, factorial, y;
	for (int n = 1; n <= 10;n++)
	{
		factorial = Factorial(2 * n - 1);
		y = pow(x, 2 * n - 1);
		result += (pow(-1, n - 1)*1.0) * (y * 1.0) / (factorial * 1.0);
		printf("Result (n) %i = ", n);
		printf("%f", result);
		printf("\n");
	}
		printf("\n");
		printf("RESULT = %f", result);
}

int main()
{
	int lenght;
	bool programRunning = true;
	char choice;
	while (programRunning) {
		system("cls");
		printf("1)Enter length of rib \n2)Show P \n3)Show S of land \n4)Show capacity \n5)Show height \n6)Show r \n7)Version information \n8)To end program \n9)Exe 2.2.6 \nYour answer:");
		scanf_s("%c", &choice);
		switch (choice)
		{
		case '1':
			system("cls");
			printf("Enter lenght: ");
			scanf_s("%d", &lenght);
			break;

		case '2':
			system("cls");
			printf("P = %i", GetPerimetr(lenght));
			printf("\n");
			system("pause");
			break;

		case'3':
			system("cls");
			printf("Square = %i", GetSquare(lenght));
			printf("\n");
			system("pause");
			break;

		case'4':
			system("cls");
			printf("Capacity = %i", GetCapacity(lenght));
			printf("\n");
			system("pause");
			break;

		case '5':
			system("cls");
			printf("Height = %i", GetHeight(lenght));
			printf("\n");
			system("pause");		
			break;

		case '6':
			system("cls");
			printf("r = %i", GetR(lenght));
			printf("\n");
			system("pause");
			break;

		case '7':
			system("cls");
			GetDataAboutVersion();
			printf("\n");
			system("pause");
			break;

		case '8':
			programRunning = false;
			system("cls");
			printf("Executed successful!");
			break;

		case '9':
			system("cls");
			float x;
			printf("Enter x = ");
			scanf_s("%f", &x);
			Exe_2_2_6(x);
			system("pause");
			break;
		default:
			continue;
		}
	}
}

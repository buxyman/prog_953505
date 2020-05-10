/*Рациональные числа. Разработать программу, меню которой
позволяет выполнить следующие функции:
1. Ввод (числитель и знаменатель) двух рациональных чисел.
2. Вывод двух рациональных чисел (в форме:
m/n ).
3. Сложение чисел.
4. Вычитание чисел.
5. Умножение чисел.
6. Деление чисел.
7. Получение гармонического значения двух чисел.
8. Информация о версии и авторе программы.
9. Выход из программы.
Справка: Гармоническое значение двух чисел получается путем
получения обратных значений двух чисел, усреднения их и
получения обратного значения результата.*/

#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <Windows.h>
int main(void)
{
	setlocale(LC_ALL, "Rus");
	double n = 0, m = 1;
	char menuSelect;
	double harmonicValue = 0;
	while (true) 
	{
		printf("1.Ввод (числитель и знаменатель) двух рациональных чисел\n");
		printf("2.Вывод двух рациональных чисел (в форме n/m)\n");
		printf("3.Сложение чисел\n");
		printf("4.Вычитание чисел\n");
		printf("5.Умножение чисел\n");
		printf("6.Деление чисел\n");
		printf("7.Получение гармонического значения двух чисел\n");
		printf("8.Информация о версии и авторе программы\n");
		printf("9.Выход из программы\n");
		menuSelect = getch();
		switch (menuSelect)
		{
			case '1':
				printf("Введите числитель n: \n");
				scanf_s("%lf", &n);
				printf("Введите знаменатель m: \n");
				scanf_s("%lf", &m);
				break;
			case '2':
				printf("%lf/%lf\n", n,m);
				system("pause");
				break;
			case '3':
				printf("%lf\n", n + m);
				system("pause");
				break;
			case '4':
				printf("%lf\n", n - m);
				system("pause");
				break;
			case '5':
				printf("%lf\n", n * m);
				system("pause");
				break;
			case '6':
				printf("%lf\n", n / m);
				system("pause");
				break;
			case '7':
				harmonicValue = 2.00 / (1.00 / n + 1.00 / m);
				printf("%lf\n", harmonicValue);
				system("pause");
				break;
			case '8':
				printf("Версия 1.0.0.\n");
				printf("Манкевич Артём, группа 953505\n");
				system("pause");
				break;
			case '9':
				exit(0);
				break;
		}
		system("cls");
	}
	

}

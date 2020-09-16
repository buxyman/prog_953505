#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//часть 1
/*float mand()
{
	float a;
	printf_s("стоимость $1.14\nВведите вес в кг ");
	scanf_s("%f", &a);
	float b = a * 1.14;
	printf_s("%f кг\nцена $%f ", a, b);
	return(b);
}
float pers()
{
	float a;
	printf_s("стоимость $1.00\nВведите вес в кг ");
	scanf_s("%f", &a);
	float b = a * 1.00;
	printf_s("%f кг\nцена $%f ", a, b);
	return(b);
}
float vino()
{
	float a;
	printf_s("стоимость $1.28\nВведите вес в кг ");
	scanf_s("%f", &a);
	float b = a * 1.28;
	printf_s("%f кг\nцена $%f ", a, b);
	return(b);
}
void korzina(int b, int c, int d, float man, float per, float vin)
{
	if (b != 0)
	{
		float kgm = man / 1.14;
		printf_s("Мандарины: кг %f цена %f ", kgm, man);
	}
	if (c != 0)
	{
		float kgp = per / 1.00;
		printf_s("Персики: цена %f ", per);
	}
	if (d != 0)
	{
		float kgv = vin / 1.28;
		printf_s("Виноград: цена %f ", vin);
	}
	if (b == 0 && c == 0 && d == 0)
	{
		printf_s("тут пока пусто\n");
	}
}
void obratka()
{
	printf_s("eFruit\n№лицензии: 492190 \nПродавец: Романьков Степан Юрьевич\nНомер телевона магазина: +089(29)590-24-82\n");
}
void ras(float man, float per, float vin, int b, int c, int d)
{
	printf_s("наименование кг стоимость цена цена со скидкой\n");
	float kgv = vin / 1.28;
	float kgm = man / 1.14;
	float kgp = per / 1.00;
	if (b > 0)
	{
		printf_s("Мандарины %f $1.14 $%f ",kgm ,man );
		if (man >= 100)
		{
			man = man * 0.9;
		}
		printf_s("$%f\n", man);
	}
	if (c > 0)
	{
		printf_s("Персики %f $1.00 $%f ", kgp, per);
		if (per >= 100)
		{
			per = per * 0.9;
		}
		printf_s("$%f\n", per);
	}
	if (d > 0)
	{
		printf_s("Виноград %f $1.28 $%f ", kgv, vin);
		if (vin >= 100)
		{
			vin = vin * 0.9;
		}
		printf_s("$%f\n", vin);
	}
	printf_s("за доставку: ");
	float fullpay = vin + man + per;
	float fullkg = kgv + kgp + kgm;
	if (fullkg > 0 && fullkg < 5)
	{
		printf_s("$1\n");
		fullpay++;
	}
	else
	{
		if (fullkg >= 5 && fullkg < 20)
		{
			printf_s("$3\n");
			fullpay+=3;
		}
		else
		{

			fullkg -= 20;
			fullkg *= 2;
			fullpay = fullpay + 5 + fullkg;
			printf_s("$5+$%f\n", fullkg);
		}
	}
	printf_s("общая сумма: $%f\n ", fullpay);
}
int main()
{
	system("chcp 1251");
	system("cls");
	int a = 0;
	float man = 0;
	float per = 0;
	float vin = 0;
	int b = 0, c = 0, d = 0;
	do
	{
		printf_s("1 - Заказ мандаринов (кг).\n2 - Заказ персиков (кг).\n3 - Заказ винограда (кг).\n4 - Корзина.\n5 - Расчет стоимости заказа\n6 - Обратная связь\n7 - Выход из программы.\n");
		scanf_s("%d", &a);
		switch (a)
		{
		case 1: {
			b++;
			man = mand();
		}
			  break;
		case 2: {
			c++;
			per = pers();
		}
			  break;
		case 3: {
			d++;
			vin = vino();
		}
			  break;
		case 4: {
			korzina(b, c, d, man, per, vin);
		}
			  break;
		case 5: ras(man, per, vin, b, c, d);
			  break;
		case 6: obratka();
			break;
		case 7:break;
		default: printf_s("ошибка кода\n"); break;
		}
	} while (a != 7);
}*/

//часть 2

/*int fact(int n)
{
	if (n == 0)
		return 1;
	else
		return (fact(n - 1) * n);
}
int main()
{
	system("chcp 1251");
	system("cls");
	int n, m;
	float a, b = 0, x, eps, c = 0;
	printf_s("x = ");
	scanf_s("%f", &x);
	a = sin(x);
	printf_s("погрешноть(epsilon) = ");
	scanf_s("%f", &eps);
	int i = 1;
	do
	{
		m = 2 * i - 1;
		b = b + pow(-1, i - 1) * (pow(x, 2 * i - 1) / fact(m));
		c = b - a;
		i++;
	} while (c > eps);
	printf_s("sin(x) = %f\nвыражение = %f\n", a, b);
	printf_s("%d", i-1);*/
}
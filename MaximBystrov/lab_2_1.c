// -------------2.1(Вариант 10) Быстров Максим 953505-------------
#include <stdio.h>
#include <locale.h>
#include <Windows.h>
#include <conio.h>
void menu(int  *cost, int  *year, int *square, int *km);
void about(void);
void enter_cost(int *cost);
void enter_year(int *year);
void enter_square(int *square);
void enter_km(int *km);
void counting(int  *cost, int  *year, int *square, int *km);
int main() {
setlocale(LC_ALL, "Rus");
int cost=0,year=0,square=0,km=0;
menu(&cost, &year,&square, &km);
}
void menu(int *cost, int *year, int *square, int *km) {
	system("cls");	
	printf("\n1.Ввод стоимости автомобиля в стране Евросоюза.\n2.Ввод года выпуска автомобиля.\n3.Ввод объема двигателя.\n4.Ввод расстояния прогона (км).\n5.Расчет стоимости услуги\n6.Информация о версии и авторе программы\n7.Выход из программы.");
	char temp = _getch();
	switch (temp) {
	case '1':  
		enter_cost(*&cost);
		menu(*&cost, *&year, *&square, *&km);
		break;
	case '2':  
		enter_year(*&year); 
		menu(*&cost, *&year, *&square, *&km);
		break;
	case '3':  enter_square(*&square);
		menu(*&cost, *&year, *&square, *&km); 
		break;
	case '4':  enter_km(*&km);
		menu(*&cost, *&year, *&square, *&km); 
		break;
	case '5':  counting(*&cost, *&year, *&square, *&km);
		menu(*&cost, *&year, *&square, *&km); 
		break;
	case '6':about();
		menu(*&cost, *&year, *&square, *&km); 
		break;
	case '7': break;
	}
}
void enter_cost(int *cost) {
	system("cls");
	printf("Введите Стоимость:");
	scanf_s("%d", cost);
}
void enter_year(int *year) {
	system("cls");
	printf("Введите год выпуска автомобиля:");
	scanf_s("%d", year);
}
void enter_square(int *square) {
	system("cls");
	printf("Введите объем двигателя:");
	scanf_s("%d", square);
}
void enter_km(int *km) {
	system("cls");
	printf("Введите расстояние прогона:");
	scanf_s("%d", km);
}
void counting(int  *cost, int  *year, int *square, int *km) {
	system("cls");
	double COST, COSTrast, COSTATALL;
	if (*cost == 0 || *year == 0 || *square == 0 || *km == 0) {
		printf("Вы не задали все компаненты!");
	}
	else {
		*year = 2020 - *year;
		COST = 0.5*(*km+0.0);
		if (*year < 3 && *square>2500) COSTrast = 0.6*(*square);
		else if ((*year >= 3 && *year <= 10) && *square < 2500)COSTrast = 0.35*(*square);
		else if ((*year >= 3 && *year <= 10) && *square >= 2500)COSTrast = 0.6*(*square);
		else if (*year > 10 && *year < 14) COSTrast = 0.6*(*square);
		else if (*year >= 14)COSTrast = 2 * (*square);
		COSTATALL = COST + COSTrast;
		printf("Стоимость перегона:%.2f EURO\n",*&COST);
		printf("Стоимость растамаживания:%.2f EURO\n", *&COSTrast);
		printf("Общая Стоимость:%.2f EURO\n", *&COSTATALL);
	}
	_getch();
}
void about(void) {	
	system("cls");
	printf("Автор программы - Максим Быстров, студент 1 курса ИиТП. Версия программы 1.0");
	_getch();
	
}

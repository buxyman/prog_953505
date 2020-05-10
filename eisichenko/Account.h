#pragma once
#include "time.h"
#include "stdio.h"
#include "windows.h"

typedef struct Account
{
	int ID;
	char* name;
	double sum;
	double percentage;
	time_t opened;
	int type; // 1 - счет до востребования (пользователь может снять деньги, когда захочет)
		      // 2 - депозитный (пользователь может снять деньги только через определенный интервал времени) 
	int months; // интервал для депозитного счета

	char* operations; // операции с данным аккаунтом

	int isChosenForTransaction;

} Account;

void SetGreenColor() // светло-зеленый цвет в консоли
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

void SetYellowColor() // желтый цвет в консоли
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED);
}

void SetCyanColor() // бирюзовый цвет в консоли
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
}

void SetPurpleColor() // фиолетовый цвет в консоли
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
}

void SetWhiteColor() // белый цвет в консоли
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void SetRedColor() // красный цвет в консоли
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_INTENSITY);
}

char* TimeToStr(time_t time) // конвертирует time_t в char* 
{
	struct tm* date; // структура с компонентами календарного времени

	date = localtime(&time); // переводит time_t в структуру

	char s[40];
	for (int i = 0; i < 40; i++) s[i] = '\0';

	strftime(s, 40, "%d %B %G", date); // перевод в строку (пример 13 April 2020)

	char* tmp = (char*)malloc(sizeof(s));

	strcpy(tmp, s); // перевод в char*

	return tmp;
}

int AddMonth(time_t* time) // добавление одного месяца
{
	struct tm* u = localtime(time);
	u->tm_mon++;

	if (u->tm_mon == 12)
	{
		*time = mktime(u);
		return 1;
	}

	*time = mktime(u);

	return 0;
}

int AddDay(time_t* time) // добавление одного дня
{
	struct tm* u = localtime(time);
	u->tm_mday++;

	if (u->tm_mday == 32 && u->tm_mon == 11)
	{
		*time = mktime(u);
		return 1;
	}

	*time = mktime(u);

	return 0;
}

void Print(Account acc)
{

	char* openedStr; // строка, где будет храниться текстовый вариант даты

	openedStr = TimeToStr(acc.opened);

	if (acc.type == 1)
	{
		if (acc.isChosenForTransaction == 1) SetGreenColor();
		else SetCyanColor();

		printf("ID : %-4d Тип счета : %-20s  Имя : %-10s  Сумма : %-10.2lf  Проценты : %-5.2lf  Дата открытия : %-15s", acc.ID, "До востребования", acc.name, acc.sum, acc.percentage, openedStr);
	}		
	else
	{
		if (acc.isChosenForTransaction == 1) SetGreenColor();
		else SetYellowColor();

		printf("ID : %-4d Тип счета : %-20s  Имя : %-10s  Сумма : %-10.2lf  Проценты : %-5.2lf  Дата открытия : %-15s  Интервал : %d мес.", acc.ID, "Депозитный", acc.name, acc.sum, acc.percentage, openedStr, acc.months);
	}
	printf("\n\n");

	SetWhiteColor();
}

void Put(Account* acc, double sum) //положить деньги на счет
{
	acc->sum += sum;
}

int Withdraw(Account* acc, double sum, time_t currentTime) // снять деньги со счета
{
	if (acc->type == 2 && CheckMonths(acc, currentTime) != 1)
		return 0;

	if (sum > acc->sum)
	{
		return 0;
	}

	acc->sum -= sum;

	return 1;
}

int CheckMonths(Account* acc, time_t currentTime)
{
	struct tm* date;

	struct tm date1, date2;

	
	date = localtime(&(acc->opened));
	date1 = *date;
	
	date = localtime(&currentTime);
	date2 = *date;
	
	int months = date2.tm_mon - date1.tm_mon;

	if (months < 0) months *= -1;

	if (months % acc->months == 0) return 1;

	return 0;

}



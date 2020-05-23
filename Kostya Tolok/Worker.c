#pragma warning(disable : 4996)
#include "Worker.h"
#include <stdio.h>
#include <time.h>
#include <Windows.h>
char* TimeToChar(time_t time)
{
	struct tm* now = localtime(&time);
	char buff[100] = "";
	strftime(buff, 100, "%d.%m.%Y", now);
	char* temp = (char*)malloc(sizeof(buff));
	strcpy_s(temp, sizeof(buff), buff);
	return temp;
}
void Print(Worker worker)
{
	SetLightBlueColor();
	printf("Имя: %s\n", worker.name);
	printf("Фамилия: %s\n", worker.surname);
	printf("Отчество: %s\n", worker.patronymic);
	char* timestr = TimeToChar(worker.date_of_birth);
	printf("Дата рождения: %s\n", timestr);
	printf("Номер паспорта: %d\n", worker.passport_ID);
	printf("Номер карточки социального страхования: %d\n", worker.insurance_ID);
	printf("Образование: %s\n", worker.education);
	printf("Должность: %s\n", worker.position);
	printf("Зарплата: %d\n", worker.salary);
	timestr = TimeToChar(worker.work_start_date);
	printf("Дата начала работы: %s\n", timestr);
	printf("Примечания: %s\n", worker.annotation);
	char buff1[100] = "";
	char buff2[100] = "";
	struct tm* start_date = localtime(&worker.work_start_date);
	strftime(buff2, 100, "%d.%m.%G", start_date);
	time_t t = time(0);
	struct tm* date = localtime(&t);
	strftime(buff1, 100, "%d.%m.%G", date);
	printf("Рабочий работает с %s по %s\n", buff2, buff1);
	if (worker.on_vacation)
	{
		printf("Сейчас рабочий в отпуске\n");
	}
	else
	{
		printf("Сейчас рабочий не в отпуске\n");
		printf("До отпуска %d месяцев, %d дней\n", worker.months_until_vacation, worker.days_until_vacation);
	}
	SetWhiteColor();
}
void SetGreenColor()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

}
void SetRedColor()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_INTENSITY);
}
void SetWhiteColor()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
void SetLightBlueColor()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
}
void SetYellowColor()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED);
}

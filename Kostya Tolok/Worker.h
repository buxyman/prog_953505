#pragma once
#include <time.h>
#include <stdbool.h>
typedef struct Worker
{
	char* name;
	char* surname;
	char* patronymic;
	time_t date_of_birth;
	int passport_ID;
	int insurance_ID;
	char* education;
	char* position;
	int salary;
	time_t work_start_date;
	char* annotation;
	bool on_vacation;
	int months_until_vacation;
	int days_until_vacation;
}Worker;
char* TimeToChar(time_t time);
void Print(Worker worker);
void SetGreenColor();
void SetRedColor();
void SetWhiteColor();
void SetLightBlueColor();
void SetYellowColor();

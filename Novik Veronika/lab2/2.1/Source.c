/*15.Project Manager. Софтверная компания Insoft заказывает вам
программу, позволяющую управлять программными проектами
внутри компании. Программа должны выполнять следующие
действия:
1 Ввод даты начала и даты окончания проекта.
2 Ввод количества разработчиков.
3 Вывод длительности проекта (кол-во календарных и рабочих
дней).
4 Расчет трудоемкости проекта (вывод кол-ва человеко-дней и
человеко-часов).
5 Расчет финансовых параметров (общая стоимость проекта;
сумма зарплаты программистам; накладные расходы; прибыль
компании).
6 Принятие решение о целесообразности принятия проекта
(указывается получаемая компанией прибыль).
7 Информация о версии и авторе программы.
8 Выход из программы.*/

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>

void scantime(int*, int*, int*, int*, int*, int*);
void scanmembers(int*);
void timeprojects(int, int, int, int, int*, int*, int, int);
void trudoemkost(int, int, int*);
void financial_parameters(int*, int*, int, int, int);
void fullprofit(int, int);
void author(void);

//прототипы

int main()
{
	int day_start = 0, month_start = 0, year_start = 0;
	int day_end = 0, month_end = 0, year_end = 0;
	int calendar_days = 0, work_days = 0;
	int number_of_developers = 0;
	int hours = 0;
	int total_cost = 0, sum_of_salarys, cost, profit = 0;
	int num, x = 0;
	while (1)
	{
		printf("choose the number of the function to execute:"
			"\n 1. enter the the project start date and end date"
			"\n 2. enter the number of employees"
			"\n 3. output the project duration (calendar and business days)"
			"\n 4. calculating the project's labor intensity"
			"\n 5. calculation of financial parameters"
			"\n 6. making a decision on whether to adopt the project"
			"\n 7. information about the author"
			"\n 8. exit the program");
		scanf_s("%d", &num);
		switch (num)
		{ 
		case 1: {
			scantime(&day_start, &month_start, &year_start, &day_end, &month_end, &year_end);
				break;
		}
		case 2: {
			scanmembers(&number_of_developers);
				break;
		}
		case 3: {
			timeprojects(year_start, year_end, month_start, month_end, &calendar_days, &work_days, day_start, day_end);
			printf("enter 1 to go to menu\n");
			scanf_s("%d", &x);
			if (x == 1)
			{
				break;
			}
		}
		case 4: {
			trudoemkost(number_of_developers, work_days, &hours);
			printf("enter 1 to go to menu\n");
			scanf_s("%d", &x);
			if (x == 1)
			{
				break;
			}
		}
		case 5: {
			financial_parameters(&total_cost, &profit, number_of_developers, calendar_days, hours);
			printf("enter 1 to go to menu\n");
			scanf_s("%d", &x);
			if (x == 1)
			{
				break;
			}
		}
		case 6: {
			fullprofit(profit, total_cost);
			printf("enter 1 to go to menu\n");
			scanf_s("%d", &x);
			if (x == 1)
			{
				break;
			}
		}
		case 7: {
			author();
			printf("enter 1 to go to menu\n");
			scanf_s("%d", &x);
			if (x == 1)
			{
				break;
			}
		}

		if (num == 8)
			break;
		}

	}
	void scantime(int* d_s, int* m_s, int* y_s, int* d_e, int* m_e, int* y_e)
	{
		printf("enter the day f the beginning ");
		scanf_s("%d.", d_s);
		scanf_s("%d.", m_s);
		scanf_s("%d", y_s);

		printf("enter the day of the end ");
		scanf_s("%d.", d_e);
		scanf_s("%d.", m_e);
		scanf_s("%d", y_e);
	}
	void scanmembers(int* develop)
	{
		printf("enter the number of employees ");
		scanf_s("%d", develop);
	}


	void timeprojects(int year_start, int year_end, int month_start, int month_end, int* calendar_days, int* work_days, int day_start, int day_end)
	{
		int day = 0, month = 0, year = 0;
		int Calendardays = 0, workdays = 0;


		if (year_start == year_end)
		{

			day = abs(day_start - day_end);
			month = abs(month_start - month_end);
			Calendardays = day + month * 30;
			workdays = (Calendardays / 7) * 5 + Calendardays % 7;
		}

		if (abs(year_start - year_end) == 1)
		{
			day = abs(day_start - day_end);
			month = (-1) * month_start + month_end + 12;
			Calendardays = day + month * 30;
			workdays = (Calendardays / 7) * 5 + Calendardays % 7;
		}

		if (abs(year_start - year_end) > 1)
		{
			day = abs(day_start - day_end);
			month = -month_start + month_end + 12;
			year = abs(year_start - year_end);
			Calendardays = day + month * 30 + (year - 1) * 12 * 30;
			workdays = (Calendardays / 7) * 5 + Calendardays % 7;
		}
		*calendar_days = Calendardays;
		*work_days = workdays;
		printf("\ncalendar days %d\n business дни: %d\n", *calendar_days, *work_days);

	}


	void trudoemkost(int number_of_developers, int work_days, int* hours)
	{
		int  man_hours, man_days, all_time;
		all_time = work_days * 8;
		man_hours = number_of_developers * all_time;
		man_days = number_of_developers * work_days;
		*hours = all_time;
		printf("\namount person-days: %d\namount of person-hours: %d\n", man_days, man_hours);
	}


	void financial_parameters(int* total_cost, int* profit, int number_of_developers, int calendar_days, int hours)
	{

		int sum_of_salarys, cost, profit_, totalcost;
		sum_of_salarys = number_of_developers * 400 * calendar_days / 30;
		cost = sum_of_salarys * 2, 5;
		profit_ = hours * number_of_developers * 9;
		totalcost = sum_of_salarys + cost;
		*profit = profit_;
		*total_cost = totalcost;
		printf("total summa: %d\nsalaries of programmers %d\noverhead: %d\nprofit: %d\n", *total_cost, sum_of_salarys, cost, *profit);
	}

	void fullprofit(int profit, int total_cost)
	{
		int net_profit;
		net_profit = profit - total_cost;
		if (net_profit > 1000)
		{
			printf("net profit: %d\nexpedient project\n", net_profit);
		}
		else
		{
			printf("net profit: %d\nunexpedient project\n", net_profit);

		}
	}
	void author()
	{
		printf("this program was made by Veronika Novik");
	}

}

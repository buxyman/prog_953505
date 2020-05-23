//Лабораторная работа 7 Вариант 26(6.2)
//Отдел кадров. Содержит полный список сотрудников организации: ФИО, дата рождения, паспортные данные,
//карточка соц. страхования, образование, должность, оклад, дата поступления на работу, примечание ( поощрения и взыскания).
//Программа осуществляет поиск сотрудника по любому полю. Функции увольнения и принятия на работу. Показывает срок работы 
//сотрудника и подыскивает время отпуска  (после полугода работы полагается 2 недели отпуска). Сообщения о приближающихся 
//днях рождения сотрудников. Списки работников, которые находятся на работе и в отпуске. Сокращение штатов: выбор для увольнения
//лиц пенсионного и предпенсионного возраста, подготовка приказа. 
#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>
#include "Worker.h"
#include "List.h"
#include <time.h>
void Add(List* list);
void Delete(List* list);
void CheckIfInt(char str[100]);
void CheckIfFloat(char str[100]);
int MonthCheck(int month);
time_t InputBirthDate();
time_t InputStartDate(time_t day_of_birth);
void Find(List* list);
void FindName(List* list);
void FindSurname(List* list);
void FindPatronymic(List* list);
void FindDateOfBirth(List* list);
void FindPassportID(List* list);
void FindInsuranceID(List* list);
void FindEducation(List* list);
void FindPosition(List* list);
void FindSalary(List* list);
void FindStartDate(List* list);
void FindAnnotation(List* list);
bool CheckIfOnVacation(time_t work_start_date, int* months_until_vacation, int* days_until_vacation);
void PrintOnVacation(List* list);
void PrintOnWork(List* list);
void IncomingDaysOfBirth(List* list);
void RetireWorkers(List* list);
void WriteToFile(List* list);
void ReadFromFile(List* list);
void RefreshStatus(List* list);
int main(void)
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	List* list = (List*)malloc(sizeof(List));
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	char choice;
	while (true)
	{
		SetGreenColor();
		printf("1.Ввести рабочего\n");
		SetRedColor();
		printf("2.Уволить рабочего\n");
		SetLightBlueColor();
		printf("3.Вывести данные о рабочих\n");
		printf("4.Поиск рабочего\n");
		printf("5.Список рабочих находящихся в отпуске\n");
		printf("6.Список рабочих находящихся на работе\n");
		printf("7.Приближающиеся дни рождения сотрудников\n");
		printf("8.Обновить рабочие статусы сотрудников\n");
		SetRedColor();
		printf("9.Уволить работников пенсионного возраста\n");
		SetYellowColor();
		printf("w - Запись в файл\n");
		printf("r - Чтение из файла\n");
		SetRedColor();
		printf("e - Выход из программы\n");
		SetWhiteColor();
		choice = getch();
		switch (choice)
		{
		case '1':
			Add(list);
			break;
		case'2':
			Delete(list);
			break;
		case '3':
			system("cls");
			ListPrint(list);
			system("pause");
			break;
		case '4':
			Find(list);
			break;
		case '5':
			PrintOnVacation(list);
			system("pause");
			break;
		case '6':
			PrintOnWork(list);
			system("pause");
			break;
		case '7':
			IncomingDaysOfBirth(list);
			system("pause");
			break;
		case '8':
			RefreshStatus(list);
			break;
		case '9':
			RetireWorkers(list);
			system("pause");
			break;
		case 'w':
		case 'ц':
			WriteToFile(list);
			break;
		case 'r':
		case 'к':
			ReadFromFile(list);
			break;
		case 'e':
		case 'у':
			exit(0);
			break;
		default:
			break;
		}
		system("cls");
	}
	Clear(list);
}
void Add(List* list)
{
	Worker worker;
	char buff[100];
	system("cls");
	printf("Введите имя: \n");
	gets(buff);
	worker.name = (char*)malloc(strlen(buff));
	strcpy(worker.name, buff);
	system("cls");
	printf("Введите фамилию: \n");
	gets(buff);
	worker.surname = (char*)malloc(strlen(buff));
	strcpy(worker.surname, buff);
	system("cls");
	printf("Введите отчество: \n");
	gets(buff);
	worker.patronymic = (char*)malloc(strlen(buff));
	strcpy(worker.patronymic, buff);
	worker.date_of_birth = InputBirthDate();
	system("cls");
	printf("Введите номер паспорта: \n");
	gets(buff);
	CheckIfInt(buff);
	worker.passport_ID = atoi(buff);
	system("cls");
	printf("Введите номер карточки социального страхования: \n");
	gets(buff);
	CheckIfInt(buff);
	worker.insurance_ID = atoi(buff);
	system("cls");
	printf("Введите образование: \n");
	gets(buff);
	worker.education = (char*)malloc(strlen(buff));
	strcpy(worker.education, buff);
	system("cls");
	printf("Введите должность: \n");
	gets(buff);
	worker.position = (char*)malloc(strlen(buff));
	strcpy(worker.position, buff);
	system("cls");
	printf("Введите зарплату: \n");
	gets(buff);
	CheckIfInt(buff);
	worker.salary = atoi(buff);
	worker.work_start_date = InputStartDate(worker.date_of_birth);
	system("cls");
	printf("Введите примечания: \n");
	gets(buff);
	worker.annotation = (char*)malloc(strlen(buff));
	strcpy(worker.annotation, buff);
	worker.months_until_vacation = 0;
	worker.days_until_vacation = 0;
	worker.on_vacation = CheckIfOnVacation(worker.work_start_date, &worker.months_until_vacation, &worker.days_until_vacation);
	AddElement(list, worker);
	system("cls");
	SetGreenColor();
	printf("\nРабочий добавлен\n");
	Sleep(700);
	SetWhiteColor();
}
void RefreshStatus(List* list)
{
	system("cls");
	ListNode* current = list->head;
	while (current)
	{
		current->data.on_vacation= CheckIfOnVacation(current->data.work_start_date, &current->data.months_until_vacation, &current->data.days_until_vacation);
		current = current->next;
	}
	SetGreenColor();
	printf("\nСтатусы рабочих обновлены\n");
	Sleep(700);
	SetWhiteColor();
}
bool CheckIfOnVacation(time_t work_start_date, int* months_until_vacation, int* days_until_vacation)
{
	struct tm* date = localtime(&work_start_date);
	int start_day, now_day, start_month, now_month, start_year, now_year;
	char buff[100];
	start_day = date->tm_mday;
	start_month = date->tm_mon + 1;
	start_year = date->tm_year + 1900;
	time_t tme = time(0);
	struct tm* now = localtime(&tme);
	now_day = now->tm_mday;
	now_month = now->tm_mon + 1;
	now_year = now->tm_year+ 1900;
	int count_months = 0;
	if (start_year != now_year || start_month != now_month)
	{
		if ((MonthCheck(start_month) - start_day) + now_day >= MonthCheck(start_month))
		{
			count_months++;
			start_month++;
			if (start_month > 12)
			{
				start_month = 1;
				count_months++;
				start_year++;
			}
			now_day = ((MonthCheck(start_month) - start_day) + now_day) - MonthCheck(start_month);
		}
		else
		{
			now_day += (MonthCheck(start_month) - start_day);
		}
	}
	while (start_year != now_year || start_month != now_month)
	{
		start_month++;
		if (start_month > 12)
		{
			start_month = 1;
			start_year++;
		}
		count_months++;
		if (count_months == 6)
		{
			if (start_year == now_year && start_month == now_month)
			{
				if (now_day >= 0 && now_day <= 14)
				{
					*months_until_vacation = 0;
					*days_until_vacation = 0;
					return true;
				}
				count_months = 0;
				break;
			}
			count_months = 0;
		}
	}
	*days_until_vacation = MonthCheck(now_month) - now_day;
	*months_until_vacation = (5 - count_months);
	return false;
}
void PrintOnVacation(List* list)
{
	system("cls");
	ListNode* current = list->head;
	while (current)
	{
		if (current->data.on_vacation)
		{
			Print(current->data);
		}
		current = current->next;
	}
}
void PrintOnWork(List* list)
{
	system("cls");
	ListNode* current = list->head;
	while (current)
	{
		if (!current->data.on_vacation)
		{
			Print(current->data);
		}
		current = current->next;
	}
}
void IncomingDaysOfBirth(List* list)
{
	system("cls");
	ListNode* current = list->head;
	while (current)
	{
		char buff[100];
		int now_day, now_month, now_year, birth_day, birth_month, birth_year;
		time_t tme = time(0);
		struct tm* now = localtime(&tme);
		strftime(buff, 100, "%d", now);
		now_day = atoi(buff);
		strftime(buff, 100, "%m", now);
		now_month = atoi(buff);
		strftime(buff, 100, "%G", now);
		now_year = atoi(buff);
		struct tm* date = localtime(&current->data.date_of_birth);
		strftime(buff, 100, "%d", date);
		birth_day = atoi(buff);
		strftime(buff, 100, "%m", date);
		birth_month = atoi(buff);
		strftime(buff, 100, "%G", date);
		birth_year = atoi(buff);
		if ((now_month - birth_month == 1 || now_month - birth_month == 0) && now_day - birth_day >= 0 && now_day - birth_day < 14)
		{
			Print(current->data);
		}
		current = current->next;
	}
}
void RetireWorkers(List* list)
{
	ListNode* current = list->head;
	time_t now = time(0);
	int count = 1;
	SetRedColor();
	while (current)
	{
		long int years = (now - current->data.date_of_birth) / 31536000;
		if (years >= 40)
		{
			current = DeleteNode(list, current);
			printf("\nРабочий под номером %d был уволен, возраст: %d\n", count, years);
			Sleep(1000);
		}
		if (current)
		{
			current = current->next;
		}
		count++;
	}
	SetWhiteColor();
}
time_t InputStartDate(time_t day_of_birth)
{
	struct tm* date;
	time_t t = time(0);
	date = localtime(&t);
	char buff[100] = "";
	int day, newday, month, newmonth, year, newyear, birthday, birthmonth, birthyear;
	strftime(buff, 100, "%d", date);
	day = atoi(buff);
	strftime(buff, 100, "%m", date);
	month = atoi(buff);
	strftime(buff, 100, "%G", date);
	year = atoi(buff);
	date = localtime(&day_of_birth);
	strftime(buff, 100, "%d", date);
	birthday = atoi(buff);
	strftime(buff, 100, "%m", date);
	birthmonth = atoi(buff);
	strftime(buff, 100, "%G", date);
	birthyear = atoi(buff);
	while (true)
	{
		system("cls");
		printf("Введите дату начала работы: \n");
		printf("Текущая дата: %d.%d.%d\n", day, month, year);
		printf("Дата рождения: %d.%d.%d\n", birthday, birthmonth, birthyear);
		printf("Введите желаемый год: \n");
		gets(buff);
		CheckIfInt(buff);
		newyear = atoi(buff);
		if (newyear <= 1970 || newyear > year || newyear - birthyear < 18 || year - newyear > 82)
		{
			printf("Неверный год");
			Sleep(700);
		}
		else
		{
			break;
		}
	}
	while (true)
	{
		system("cls");
		printf("Введите дату начала работы: \n");
		printf("Текущая дата: %d.%d.%d\n", day, month, year);
		printf("Дата рождения: %d.%d.%d\n", birthday, birthmonth, birthyear);
		printf("Введите желаемый месяц: \n");
		gets(buff);
		CheckIfInt(buff);
		newmonth = atoi(buff);
		if (newmonth <= 0 || newmonth > 12 || (newyear == birthyear && newmonth > month) || (year == newyear && newmonth > month))
		{
			printf("Неверный месяц");
			Sleep(700);
		}
		else
		{
			break;
		}
	}
	while (true)
	{
		system("cls");
		printf("Введите дату начала работы: \n");
		printf("Текущая дата: %d.%d.%d\n", day, month, year);
		printf("Дата рождения: %d.%d.%d\n", birthday, birthmonth, birthyear);
		printf("Введите желаемый день: \n");
		gets(buff);
		CheckIfInt(buff);
		newday = atoi(buff);
		if (newday <= 0 || newday > MonthCheck(newmonth) || (newyear == year && newmonth == month && newday > day))
		{
			printf("Неверный день");
			Sleep(700);
		}
		else
		{
			break;
		}
	}
	date->tm_mday = newday;
	date->tm_mon = newmonth - 1;
	date->tm_year = newyear - 1900;
	date->tm_hour = 0;
	date->tm_min = 0;
	date->tm_sec = 0;
	date->tm_wday = 0;
	date->tm_yday = 0;
	return mktime(date);
}
time_t InputBirthDate()
{
	system("cls");
	struct tm* date;
	time_t t = time(0);
	date = localtime(&t);
	char buff[100] = "";
	int day, newday, month, newmonth, year, newyear;
	strftime(buff, 100, "%d", date);
	day = atoi(buff);
	strftime(buff, 100, "%m", date);
	month = atoi(buff);
	strftime(buff, 100, "%G", date);
	year = atoi(buff);
	while (true)
	{
		system("cls");
		printf("Введите дату рождения: \n");
		printf("Текущая дата: %d.%d.%d\n", day, month, year);
		printf("Введите желаемый год: \n");
		gets(buff);
		CheckIfInt(buff);
		newyear = atoi(buff);
		if (newyear <= 1970 || newyear > year || year - newyear > 50 || year - newyear < 18)
		{
			printf("Неверный год");
			Sleep(700);
		}
		else
		{
			break;
		}
	}
	while (true)
	{
		system("cls");
		printf("Введите дату рождения: \n");
		printf("Текущая дата: %d.%d.%d\n", day, month, year);
		printf("Введите желаемый месяц: \n");
		gets(buff);
		CheckIfInt(buff);
		newmonth = atoi(buff);
		if (newmonth <= 0 || newmonth > 12 || (year - newyear == 18 && newmonth > month))
		{
			printf("Неверный месяц");
			Sleep(700);
		}
		else
		{
			break;
		}
	}
	while (true)
	{
		system("cls");
		printf("Введите дату рождения: \n");
		printf("Текущая дата: %d.%d.%d\n", day, month, year);
		printf("Введите желаемый день: \n");
		gets(buff);
		CheckIfInt(buff);
		newday = atoi(buff);
		if (newday <= 0 || newday > 31 || newday > MonthCheck(newmonth) || (newmonth == month && newday > day))
		{
			printf("Неверный день");
			Sleep(700);
		}
		else
		{
			break;
		}
	}
	date->tm_mday = newday;
	date->tm_mon = newmonth - 1;
	date->tm_year = newyear - 1900;
	date->tm_hour = 0;
	date->tm_min = 0;
	date->tm_sec = 0;
	return mktime(date);
}
void Delete(List* list)
{
	char index[100];
	char esc;
	int ind;
	while (true)
	{
		system("cls");
		printf("\nESC - выход \\ Любая клавиша - продолжить\n");
		if (esc = getch() == 27)
		{
			return;
		}
		system("cls");
		printf("\nВведите номер рабочего для удаления: \n");
		gets(index);
		CheckIfInt(index);
		ind = atoi(index);
		if (ind <= list->size)
		{
			DeleteElement(list, ind);
			SetRedColor();
			printf("Рабочий под номером %d был удален", ind);
			SetWhiteColor();
			Sleep(700);
			continue;
		}
		printf("Неверный номер\n");
		Sleep(700);
		continue;
	}
}
void Find(List* list)
{
	system("cls");
	char choice;
	while (true)
	{
		printf("Выберите по чему провести поиск:\n1.Имя\n2.Фамилия\n3.Отчество\n4.Дата рождения\n5.Номер паспорта");
		printf("\n6.Номер карточки социального страхования\n7.Образование\n8.Должность\n9.Дата приема на работу\n0.Зарплата\na.Примечание\nESC - выход\n");
		choice = getch();
		system("cls");
		switch (choice)
		{
		case '1':
			FindName(list);
			system("pause");
			break;
		case '2':
			FindSurname(list);
			system("pause");
			break;
		case '3':
			FindPatronymic(list);
			system("pause");
			break;
		case '4':
			FindDateOfBirth(list);
			system("pause");
			break;
		case '5':
			FindPassportID(list);
			system("pause");
			break;
		case '6':
			FindInsuranceID(list);
			system("pause");
			break;
		case '7':
			FindEducation(list);
			system("pause");
			break;
		case '8':
			FindPosition(list);
			system("pause");
			break;
		case '9':
			FindStartDate(list);
			system("pause");
			break;
		case '0':
			FindSalary(list);
			system("pause");
			break;
		case 'a':
		case 'ф':
			FindAnnotation(list);
			system("pause");
			break;
		case 27:
			break;
		default:
			system("cls");
			continue;
		}
		break;
	}
}
void FindName(List* list)
{
	char buff[100];
	printf("Введите имя: \n");
	gets(buff);
	ListNode* current = list->head;
	while (current)
	{
		if (strcmp(current->data.name, buff) == 0)
		{
			Print(current->data);
		}
		current = current->next;
	}
}
void FindSurname(List* list)
{
	char buff[100];
	printf("Введите фамилию: \n");
	gets(buff);
	ListNode* current = list->head;
	while (current)
	{
		if (strcmp(current->data.surname, buff) == 0)
		{
			Print(current->data);
		}
		current = current->next;
	}
}
void FindPatronymic(List* list)
{
	char buff[100];
	printf("Введите отчество: \n");
	gets(buff);
	ListNode* current = list->head;
	while (current)
	{
		if (strcmp(current->data.patronymic, buff) == 0)
		{
			Print(current->data);
		}
		current = current->next;
	}
}
void FindDateOfBirth(List* list)
{
	time_t buff;
	printf("Введите дату рождения: \n");
	buff = InputBirthDate();
	ListNode* current = list->head;
	while (current)
	{
		if (current->data.date_of_birth == buff)
		{
			Print(current->data);
		}
		current = current->next;
	}
}
void FindPassportID(List* list)
{
	char buff[100];
	printf("Введите номер паспорта: \n");
	gets(buff);
	CheckIfInt(buff);
	ListNode* current = list->head;
	while (current)
	{
		if (current->data.passport_ID == atoi(buff))
		{
			Print(current->data);
		}
		current = current->next;
	}
}
void FindInsuranceID(List* list)
{
	char buff[100];
	printf("Введите номер карточки социального страхования: \n");
	gets(buff);
	CheckIfInt(buff);
	ListNode* current = list->head;
	while (current)
	{
		if (current->data.insurance_ID == atoi(buff))
		{
			Print(current->data);
		}
		current = current->next;
	}
}
void FindEducation(List* list)
{
	char buff[100];
	printf("Введите образование: \n");
	gets(buff);
	ListNode* current = list->head;
	while (current)
	{
		if (strcmp(current->data.education, buff) == 0)
		{
			Print(current->data);
		}
		current = current->next;
	}
}
void FindPosition(List* list)
{
	char buff[100];
	printf("Введите должность: \n");
	gets(buff);
	ListNode* current = list->head;
	while (current)
	{
		if (strcmp(current->data.position, buff) == 0)
		{
			Print(current->data);
		}
		current = current->next;
	}
}
void FindSalary(List* list)
{
	char buff[100];
	printf("Введите зарплату: \n");
	gets(buff);
	CheckIfInt(buff);
	ListNode* current = list->head;
	while (current)
	{
		if (current->data.salary == atoi(buff))
		{
			Print(current->data);
		}
		current = current->next;
	}
}
void FindStartDate(List* list)
{
	time_t start;
	char buff[100];
	printf("Введите дату начала работы: \n");
	struct tm* date;
	time_t t = time(0);
	date = localtime(&t);
	int day, newday, month, newmonth, year, newyear;
	strftime(buff, 100, "%d", date);
	day = atoi(buff);
	strftime(buff, 100, "%m", date);
	month = atoi(buff);
	strftime(buff, 100, "%G", date);
	year = atoi(buff);
	while (true)
	{
		system("cls");
		printf("Введите дату начала работы: \n");
		printf("Текущая дата: %d.%d.%d\n", day, month, year);
		printf("Введите желаемый год: \n");
		gets(buff);
		CheckIfInt(buff);
		newyear = atoi(buff);
		if (newyear <= 1970 || newyear > year)
		{
			printf("Неверный год");
			Sleep(700);
		}
		else
		{
			break;
		}
	}
	while (true)
	{
		system("cls");
		printf("Введите дату начала работы: \n");
		printf("Текущая дата: %d.%d.%d\n", day, month, year);
		printf("Введите желаемый месяц: \n");
		gets(buff);
		CheckIfInt(buff);
		newmonth = atoi(buff);
		if (newmonth <= 0 || newmonth > 12 || (year == newyear && newmonth > month))
		{
			printf("Неверный месяц");
			Sleep(700);
		}
		else
		{
			break;
		}
	}
	while (true)
	{
		system("cls");
		printf("Введите дату начала работы: \n");
		printf("Текущая дата: %d.%d.%d\n", day, month, year);
		printf("Введите желаемый день: \n");
		gets(buff);
		CheckIfInt(buff);
		newday = atoi(buff);
		if (newday <= 0 || newday > MonthCheck(newmonth) || (newyear == year && newmonth == month && newday > day))
		{
			printf("Неверный день");
			Sleep(700);
		}
		else
		{
			break;
		}
	}
	date->tm_mday = newday;
	date->tm_mon = newmonth - 1;
	date->tm_year = newyear - 1900;
	date->tm_hour = 0;
	date->tm_min = 0;
	date->tm_sec = 0;
	start = mktime(date);
	ListNode* current = list->head;
	while (current)
	{
		if (current->data.work_start_date == start)
		{
			Print(current->data);
		}
		current = current->next;
	}
}
void FindAnnotation(List* list)
{
	char buff[100];
	printf("Введите примечание: \n");
	gets(buff);
	ListNode* current = list->head;
	while (current)
	{
		if (current->data.annotation == buff)
		{
			Print(current->data);
		}
		current = current->next;
	}
}
void WriteToFile(List* list)
{
	FILE* file = fopen("workers.txt", "w");
	ListNode* current = list->head;
	while (current)
	{
		fprintf(file, "%s\n", current->data.name);
		fprintf(file, "%s\n", current->data.surname);
		fprintf(file, "%s\n", current->data.patronymic);
		fprintf(file, "%ld\n", current->data.date_of_birth);
		fprintf(file, "%d\n", current->data.passport_ID);
		fprintf(file, "%d\n", current->data.insurance_ID);
		fprintf(file, "%s\n", current->data.education);
		fprintf(file, "%s\n", current->data.position);
		fprintf(file, "%d\n", current->data.salary);
		fprintf(file, "%ld\n", current->data.work_start_date);
		fprintf(file, "%s\n", current->data.annotation);
		fprintf(file, "\n");
		current = current->next;
	}
	fclose(file);
	SetGreenColor();
	printf("\nДанные успешно записаны в файл");
	SetWhiteColor();
	Sleep(1400);
}
void ReadFromFile(List* list)
{
	Clear(list);
	FILE* file = fopen("workers.txt", "r");
	fseek(file, 0, SEEK_SET);
	while (!feof(file))
	{
		Worker worker;
		worker.name = (char*)calloc(100, sizeof(char));
		fscanf(file, "%s", worker.name);
		worker.surname = (char*)malloc(100);
		fscanf(file, "%s", worker.surname);
		worker.patronymic = (char*)malloc(100);
		fscanf(file, "%s", worker.patronymic);
		fscanf(file, "%lld", &worker.date_of_birth);
		fscanf(file, "%d", &worker.passport_ID);
		fscanf(file, "%d", &worker.insurance_ID);
		worker.education = (char*)malloc(100);
		fscanf(file, "%s", worker.education);
		worker.position = (char*)malloc(100);
		fscanf(file, "%s", worker.position);
		fscanf(file, "%d", &worker.salary);
		fscanf(file, "%lld", &worker.work_start_date);
		worker.annotation = (char*)malloc(100);
		fscanf(file, "%s", worker.annotation);
		worker.on_vacation = CheckIfOnVacation(worker.work_start_date, &worker.months_until_vacation, &worker.days_until_vacation);
		fgetc(file);
		if (feof(file))
		{
			break;
		}
		AddElement(list, worker);
	}
	fclose(file);
	SetGreenColor();
	printf("\nДанные успешно считаны из файла");
	SetWhiteColor();
	Sleep(1400);
}
void CheckIfInt(char str[100])
{
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (int i = 0; i < strlen(str); i++)
		{
			if (!isdigit(str[i]))
			{
				flag = true;
				break;
			}
		}
		if (!flag && atoi(str) < _CRT_INT_MAX)
		{
			break;
		}
		else
		{
			system("cls");
			printf("Неверно. Повторите ввод: ");
			gets(str);
			flag = true;
		}
	}
}
void CheckIfFloat(char str[100])
{
	bool flag = true;
	while (flag)
	{
		flag = false;
		int pointcount = 0;
		for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] == ',')
			{
				pointcount++;
				continue;
			}
			if (!isdigit(str[i]))
			{
				flag = true;
				break;
			}
		}
		if (pointcount <= 1 && !flag && atof(str) < _CRT_INT_MAX)
		{
			break;
		}
		else
		{
			system("cls");
			printf("Неверно. Повторите ввод: ");
			gets(str);
			flag = true;
		}
	}
}
int MonthCheck(int month)
{
	return 28 + (month + abs(month / 8)) % 2 + 2 % month + 2 * abs(1 / month);
}

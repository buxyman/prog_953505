#pragma once
#include "List.h"
#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <math.h>

#define bool int
#define true 1
#define false 0 

List employeeList;
List buffList;
List searchResultList;

int StrToInt(char arr[])
{
	int var = 0;
	for (int j = 0; arr[j] != '\n' && arr[j] != '\0'; j++)
	{
		var = var * 10 + (arr[j] - '0');
	}
	return var;
}

int StrToIntDate(char arr[], int start, int end)
{
	int var = 0;
	for (int j = start; j < end; j++)
	{
		var =  var * 10 + (arr[j] - '0');
	}
	return var;
}

char* CreateString(char arr[], const int size)
{
	char* newString = (char*)malloc(sizeof(char) * size);
	int i = 0;
	while (arr[i] != '\n')
	{
		newString[i] = arr[i];
		i++;
	}
	newString[i] = '\0';
	return newString;
}

void SetDefaultValues(Node* node)
{
	int day = 11;
	int month = 11;
	int year = 1111;
	int elseVal = 1;
	const char* str = "-";
	node->employee.firstName = _strdup(str);
	node->employee.lastName = _strdup(str);
	node->employee.dateOfBirth.day = day;
	node->employee.dateOfBirth.month = month;
	node->employee.dateOfBirth.year = year;
	node->employee.passport.passportNumber = elseVal;
	node->employee.passport.issueDay = day;
	node->employee.passport.issueMonth = month;
	node->employee.passport.issueYear = year;
	node->employee.passport.expiryDay = day;
	node->employee.passport.expiryMonth = month;
	node->employee.passport.expiryYear = year;
    node->employee.passport.nationality = _strdup(str);
    node->employee.socialSecurityCard.cardNumber = elseVal;
	node->employee.education.degree = _strdup(str);
	node->employee.position = _strdup(str);
	node->employee.salary = elseVal;
	node->employee.enrollmentDate.day = day;
	node->employee.enrollmentDate.month = month;
	node->employee.enrollmentDate.year = year;
	node->employee.notes.encouragement = _strdup(str);
	node->employee.notes.penalties = _strdup(str);
	node->employee.status = _strdup(str);
}

void ReadFile()
{
	Node* node;
	const int size = 30;
	char buffer[size];
	FILE* file;
	errno_t err;
	err = fopen_s(&file, "EmployeeData.txt", "r");
	while (fgets(buffer, size, file))
	{
		AddNode(&employeeList);
		node = employeeList.tail;
		fgets(buffer, size, file);
		node->employee.firstName = CreateString(&buffer[0], size);
		fgets(buffer, size, file);
		node->employee.lastName = CreateString(&buffer[0], size);
		fgets(buffer, size, file);
		node->employee.dateOfBirth.day = StrToIntDate(&buffer[0], 0, 2);
		node->employee.dateOfBirth.month = StrToIntDate(&buffer[0], 3, 5);
		node->employee.dateOfBirth.year = StrToIntDate(&buffer[0], 6, 10);
		fgets(buffer, size, file);
		node->employee.passport.passportNumber = StrToInt(&buffer[0]);
		fgets(buffer, size, file);
		node->employee.passport.issueDay = StrToIntDate(&buffer[0], 0, 2);
		node->employee.passport.issueMonth = StrToIntDate(&buffer[0], 3, 5);
		node->employee.passport.issueYear = StrToIntDate(&buffer[0], 6, 10);
		fgets(buffer, size, file);
		node->employee.passport.expiryDay = StrToIntDate(&buffer[0], 0, 2);
		node->employee.passport.expiryMonth = StrToIntDate(&buffer[0], 3, 5);
		node->employee.passport.expiryYear = StrToIntDate(&buffer[0], 6, 10);
		fgets(buffer, size, file);
		node->employee.passport.nationality = CreateString(&buffer[0], size);
		fgets(buffer, size, file);
		node->employee.socialSecurityCard.cardNumber = StrToInt(&buffer[0]);
		fgets(buffer, size, file);
		node->employee.education.degree = CreateString(&buffer[0], size);
		fgets(buffer, size, file);
		node->employee.position = CreateString(&buffer[0], size);
		fgets(buffer, size, file);
		node->employee.salary = StrToInt(&buffer[0]);
		fgets(buffer, size, file);
		node->employee.enrollmentDate.day = StrToIntDate(&buffer[0], 0, 2);
		node->employee.enrollmentDate.month = StrToIntDate(&buffer[0], 3, 5);
		node->employee.enrollmentDate.year = StrToIntDate(&buffer[0], 6, 10);
		fgets(buffer, size, file);
		node->employee.notes.encouragement = CreateString(&buffer[0], size);
		fgets(buffer, size, file);
		node->employee.notes.penalties = CreateString(&buffer[0], size);
		fgets(buffer, size, file);
		node->employee.status = CreateString(&buffer[0], size);
 	}
	fclose(file);
}

void WriteFile()
{
	FILE* file;
	errno_t err;
	err = fopen_s(&file, "EmployeeData.txt", "w");
	Node* node = employeeList.head;
	const int twoDigitNum = 10;
	while (node != NULL)
	{
		fprintf_s(file, "\n");
		fprintf_s(file, "%s\n", node->employee.firstName);
		fprintf_s(file, "%s\n", node->employee.lastName);

		node->employee.dateOfBirth.day < twoDigitNum ? fprintf_s(file, "%d%d.", 0, node->employee.dateOfBirth.day) : fprintf_s(file, "%d.", node->employee.dateOfBirth.day);
		node->employee.dateOfBirth.month < twoDigitNum ? fprintf_s(file, "%d%d.", 0, node->employee.dateOfBirth.month) : fprintf_s(file, "%d.", node->employee.dateOfBirth.month);
		fprintf_s(file, "%d\n", node->employee.dateOfBirth.year);

		fprintf_s(file, "%d\n", node->employee.passport.passportNumber);
		node->employee.passport.issueDay < twoDigitNum ? fprintf_s(file, "%d%d.", 0, node->employee.passport.issueDay) : fprintf_s(file, "%d.", node->employee.passport.issueDay);
		node->employee.passport.issueMonth < twoDigitNum ? fprintf_s(file, "%d%d.", 0, node->employee.passport.issueMonth) : fprintf_s(file, "%d.", node->employee.passport.issueMonth);
		fprintf_s(file, "%d\n", node->employee.passport.issueYear);

		node->employee.passport.expiryDay < twoDigitNum ? fprintf_s(file, "%d%d.", 0, node->employee.passport.expiryDay) : fprintf_s(file, "%d.", node->employee.passport.expiryDay);
		node->employee.passport.expiryMonth < twoDigitNum ? fprintf_s(file, "%d%d.", 0, node->employee.passport.expiryMonth) : fprintf_s(file, "%d.", node->employee.passport.expiryMonth);
		fprintf_s(file, "%d\n", node->employee.passport.expiryYear);

		fprintf_s(file, "%s\n", node->employee.passport.nationality);
		fprintf_s(file, "%d\n", node->employee.socialSecurityCard.cardNumber);
		fprintf_s(file, "%s\n", node->employee.education.degree);
		fprintf_s(file, "%s\n", node->employee.position);
		fprintf_s(file, "%d\n", node->employee.salary);
		
		node->employee.enrollmentDate.day < twoDigitNum ? fprintf_s(file, "%d%d.", 0, node->employee.enrollmentDate.day) : fprintf_s(file, "%d.", node->employee.enrollmentDate.day);
		node->employee.enrollmentDate.month < twoDigitNum ? fprintf_s(file, "%d%d.", 0, node->employee.enrollmentDate.month) : fprintf_s(file, "%d.", node->employee.enrollmentDate.month);
		fprintf_s(file, "%d\n", node->employee.enrollmentDate.year);

		fprintf_s(file, "%s\n", node->employee.notes.encouragement);
		fprintf_s(file, "%s\n", node->employee.notes.penalties);
		fprintf_s(file, "%s\n", node->employee.status);

		node = node->pNext;
	}
	fclose(file);
}

bool DataInput(Node* node, int field)
{
	const int size = 30;
	const char* inputCheck = "";
	char* buffer = (char*)malloc(sizeof(char) * size);
	int key = 0;
	gets_s(buffer, size);
	if (buffer[0] != inputCheck[0])
	{
		switch (field)
		{
		case 1: free(node->employee.firstName); node->employee.firstName = buffer; break;
		case 2: free(node->employee.lastName); node->employee.lastName = buffer; break;
		case 3:
			node->employee.dateOfBirth.day = StrToIntDate(&buffer[0], 0, 2);
			node->employee.dateOfBirth.month = StrToIntDate(&buffer[0], 3, 5);
			node->employee.dateOfBirth.year = StrToIntDate(&buffer[0], 6, 10); break;
		case 4: node->employee.passport.passportNumber = StrToInt(&buffer[0]); break;
		case 5:
			node->employee.passport.issueDay = StrToIntDate(&buffer[0], 0, 2);
			node->employee.passport.issueMonth = StrToIntDate(&buffer[0], 3, 5);
			node->employee.passport.issueYear = StrToIntDate(&buffer[0], 6, 10); break;
		case 6:
			node->employee.passport.expiryDay = StrToIntDate(&buffer[0], 0, 2);
			node->employee.passport.expiryMonth = StrToIntDate(&buffer[0], 3, 5);
			node->employee.passport.expiryYear = StrToIntDate(&buffer[0], 6, 10); break;
		case 7: free(node->employee.passport.nationality); node->employee.passport.nationality = buffer; break;
		case 8: node->employee.socialSecurityCard.cardNumber = StrToInt(&buffer[0]); break;
		case 9: free(node->employee.education.degree); node->employee.education.degree = buffer; break;
		case 10: free(node->employee.position); node->employee.position = buffer; break;
		case 11: node->employee.salary = StrToInt(&buffer[0]);; break;
		case 12:
			node->employee.enrollmentDate.day = StrToIntDate(&buffer[0], 0, 2);
			node->employee.enrollmentDate.month = StrToIntDate(&buffer[0], 3, 5);
			node->employee.enrollmentDate.year = StrToIntDate(&buffer[0], 6, 10); break;
		case 13: free(node->employee.notes.encouragement); node->employee.notes.encouragement = buffer; break;
		case 14: free(node->employee.notes.penalties); node->employee.notes.penalties = buffer; break;
		case 15: free(node->employee.status); node->employee.status = buffer; break;
		default:
			break;
		}
		return true;
	}
	return false;
}

bool SearchEmployee(Node* nodeSearch, Node* nodeField, int field)
{
	bool isFound = false;
	while (nodeSearch != NULL)
	{
		switch (field)
		{
		case 1: 
			if (!strcmp(nodeSearch->employee.firstName, nodeField->employee.firstName))
			{
				Copy(&searchResultList, nodeSearch);
				isFound = true;
			} break;
		case 2:
			if (!strcmp(nodeSearch->employee.lastName, nodeField->employee.lastName))
			{
				Copy(&searchResultList, nodeSearch);
				isFound = true;
			} break;
		case 3:
			if (nodeSearch->employee.dateOfBirth.day == nodeField->employee.dateOfBirth.day 
				&& nodeSearch->employee.dateOfBirth.month == nodeField->employee.dateOfBirth.month
				&& nodeSearch->employee.dateOfBirth.year == nodeField->employee.dateOfBirth.year)
			{
				Copy(&searchResultList, nodeSearch);
				isFound = true;
			} break;
		case 4:
			if (nodeSearch->employee.passport.passportNumber == nodeField->employee.passport.passportNumber)
			{
				Copy(&searchResultList, nodeSearch);
				isFound = true;
			} break;
		case 5:
			if (nodeSearch->employee.passport.issueDay == nodeField->employee.passport.issueDay
				&& nodeSearch->employee.passport.issueMonth == nodeField->employee.passport.issueMonth
				&& nodeSearch->employee.passport.issueYear == nodeField->employee.passport.issueYear)
			{
				Copy(&searchResultList, nodeSearch);
				isFound = true;
			} break;
		case 6:
			if (nodeSearch->employee.passport.expiryDay == nodeField->employee.passport.expiryDay
				&& nodeSearch->employee.passport.expiryMonth == nodeField->employee.passport.expiryMonth
				&& nodeSearch->employee.passport.expiryYear == nodeField->employee.passport.expiryYear)
			{
				Copy(&searchResultList, nodeSearch);
				isFound = true;
			} break;
		case 7:
			if (!strcmp(nodeSearch->employee.passport.nationality, nodeField->employee.passport.nationality))
			{
				Copy(&searchResultList, nodeSearch);
				isFound = true;
			} break;
		case 8:
			if (nodeSearch->employee.socialSecurityCard.cardNumber == nodeField->employee.socialSecurityCard.cardNumber)
			{
				Copy(&searchResultList, nodeSearch);
				isFound = true;
			} break;
		case 9:
			if (!strcmp(nodeSearch->employee.education.degree, nodeField->employee.education.degree))
			{
				Copy(&searchResultList, nodeSearch);
				isFound = true;
			} break;
		case 10:
			if (!strcmp(nodeSearch->employee.position, nodeField->employee.position))
			{
				Copy(&searchResultList, nodeSearch);
				isFound = true;
			} break;
		case 11:
			if (nodeSearch->employee.salary == nodeField->employee.salary)
			{
				Copy(&searchResultList, nodeSearch);
				isFound = true;
			} break;
		case 12:
			if (nodeSearch->employee.enrollmentDate.day == nodeField->employee.enrollmentDate.day
				&& nodeSearch->employee.enrollmentDate.month == nodeField->employee.enrollmentDate.month
				&& nodeSearch->employee.enrollmentDate.year == nodeField->employee.enrollmentDate.year)
			{
				Copy(&searchResultList, nodeSearch);
				isFound = true;
			} break;
		case 13:
			if (!strcmp(nodeSearch->employee.notes.encouragement, nodeField->employee.notes.encouragement))
			{
				Copy(&searchResultList, nodeSearch);
				isFound = true;
			} break;
		case 14:
			if (!strcmp(nodeSearch->employee.notes.penalties, nodeField->employee.notes.penalties))
			{
				Copy(&searchResultList, nodeSearch);
				isFound = true;
			} break;
		case 15:
			if (!strcmp(nodeSearch->employee.status, nodeField->employee.status))
			{
				Copy(&searchResultList, nodeSearch);
				isFound = true;
			} break;
		default:
			break;
		}
		nodeSearch = nodeSearch->pNext;
	}
	return isFound;
}

int countLeapYears(int day, int month, int year)
{
	int years = year;
	if (month <= 2)
	{
		years--;
	}
	return years / 4 - years / 100 + years / 400;
}

int GetDifferenceDates(int day, int month, int year)
{
	time_t t = time(0);
	struct tm tm; 
	errno_t err = localtime_s(&tm, &t);
	int currYear = tm.tm_year + 1900;
	int currMonth = tm.tm_mon + 1;
	int currDay = tm.tm_mday;
    const int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	long int n1 = year * 365 + day;
	for (int i = 0; i < month - 1; i++)
	{
		n1 += monthDays[i];
	}
	n1 += countLeapYears(day, month, year);
	
	long int n2 = currYear * 365 + currDay;
	for (int i = 0; i < currMonth - 1; i++)
		n2 += monthDays[i];
	n2 += countLeapYears(currDay, currMonth, currYear);
	return abs(n2 - n1);
}

void AddDays(int day1, int month1, int year1, int addDays, int* day2, int* month2, int* year2)
{
	struct tm  t = { 0 };
	t.tm_mday = day1;
	t.tm_mon = month1 - 1;
	t.tm_year = year1 - 1900;
	t.tm_mday += addDays;
	mktime(&t);
	*day2 = t.tm_mday;
	*month2 = t.tm_mon + 1;
	*year2 = t.tm_year + 1900;
}

int GetAge(int bDay, int bMonth, int bYear)
{
	time_t t = time(0);
	struct tm tm;
	errno_t err = localtime_s(&tm, &t);
	int currYear = tm.tm_year + 1900;
	int currMonth = tm.tm_mon + 1;
	int currDay = tm.tm_mday;

	if (currDay >= bDay && currMonth >= bMonth)
	{
		return currYear - bYear;
	}
	else
	{
		return currYear - bYear - 1;
	}
}

int GetDaysToBday(int bDay, int bMonth)
{
	time_t t = time(0);
	struct tm tm;
	errno_t err = localtime_s(&tm, &t);
	int year = tm.tm_year + 1900;
	int month = tm.tm_mon + 1;
	int day = tm.tm_mday;

	if (day > bDay && month >= bMonth)
	{
		return GetDifferenceDates(bDay, bMonth, year + 1);
	}
	else
	{
		return GetDifferenceDates(bDay, bMonth, year);
	}
}

void FireByAge(List* list, int minAge, int maxAge)
{
	Node* node;
	Node* nodeNext = list->head;
	int personAge = 0;
	while (nodeNext != NULL)
	{
		node = nodeNext;
		nodeNext = node->pNext;
		personAge = GetAge(node->employee.dateOfBirth.day, node->employee.dateOfBirth.month, node->employee.dateOfBirth.year);
		if (minAge <= personAge && personAge < maxAge)
		{
			DeleteNode(node, list);
		}
	}
}

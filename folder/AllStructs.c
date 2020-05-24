#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "AllStructs.h"
#include "work_with_files.h"
#define CurrentMonth May

char* GetMonth(Month month) {
	switch (month)
	{
	case May:return "May";
	case June:return "June";
	case July:return "July";
	case August:return "August";
	case September:return "September";
	case October:return "October";
	case November:return "November";
	case December:return "December";
	default:
		return "";
	}
}
void ClearList(Item* item) {
	if (item == NULL)return;
	ClearList(item->next);
	free(item);
}
Flight CreateFlight(char* flight_number,char destination[],char* type,int hour,int minute,int flight_time,int free_places) {
	Flight* temp = (Flight*)malloc(sizeof(Flight));
	temp->flight_time = flight_time;
	temp->free_places=free_places;
	return *temp;
}
void AddFlight(List* list, Flight* flight) 
{
	Item* p = (Item*)malloc(sizeof(Item));
		p->item = (Flight*)malloc(sizeof(Flight));
		memcpy(p->item, flight, sizeof(Flight));
	p->next = p->prev = NULL;
	if (list->head == NULL)list->head = list->tail = p;
	else {
		list->tail->next = p;
		p->prev = list->tail;
		list->tail = p;
	}
	list->n++;
}
void PrintFlight(Flight flight)
{
	printf("\n%d Flight number:%s\tType:%s\tDestination:%s\tDate: %s,%d\tDeparture Time:%d:%d\t Flight Time:%d  Free Places:%d",
		flight.numinlist, flight.flight_number,flight.type,flight.destination,GetMonth(flight.month),flight.day,
		flight.hour,flight.minute,flight.flight_time,flight.free_places);
}
void PrintFlightByIndex(List* list,int index) {
	if (index < 0)return;
	Item* p = list->head;
	int listindex = 0;
	while (p) {
		if (listindex == index) {
			PrintFlight(*(p->item));
			return;
		}
		listindex++;
		p = p->next;
	}
}
void DeleteMenu(List* list)
{
	int index;
	system("cls");
	PrintAllFlights(list);
	printf("---------------\nWhich one you want to delete?");
	scanf("%d", &index);
	if (index > 0)
	{
		DeleteFromFile(index);
		DeleteFromList(list, index);
		
	}
}
void DeleteFromList(List* list, int index)
{
	Item* p = list->head;
	while (p) {
		if (p->item->numinlist == index) {
			if (p->next != NULL) {
				p->prev->next = p->next;
				p->next->prev = p->prev;
			}
			else {
				p->prev->next = NULL;
			}
			free(p->item);
			free(p);
			return;
		}
		p = p->next;
	}
}
void PrintAllFlights(List* list) 
{
	system("cls");
	Item* p = list->head;
	while (p) 
	{
		PrintFlight(*p->item);
		p = p->next;
	}	
	getchar();
}
void AddFlightInList(List* list) {
	system("cls");
	Flight* flight = (Flight*)malloc(sizeof(Flight));
	flight->numinlist = FItemsGetCount();
	flight->isdeleted = 0;
	printf("Enter destination:");
	scanf("%s", flight->destination);
	printf("Enter flight number:");
	scanf("%s", flight->flight_number);
	printf("Enter type of plane:");
	scanf("%s", flight->type);
	printf("Enter the hour of arrival:");
	scanf("%d", &flight->hour);
	printf("Enter the minute of arrival:");
	scanf("%d", &flight->minute);
	printf("Enter count of free places:");
	scanf("%d", &flight->free_places);
	printf("Enter flight time:");
	scanf("%d", &flight->flight_time);
	printf("Enter month of flight(as digit):");
	scanf("%d", &flight->month);
	flight->month += 5;
	printf("Enter day of flight(as digit):");
	scanf("%d", &flight->day);
	AddFlight(list, flight);
	LoadToFile(flight);
}
void Search(List* list)
{
	char key;
	do
	{
		key = getchar();
			system("cls");
		printf("\t\t\t\t\tBelavia\n\n");
		printf(
			"1.Find appropriate race\n"
			"2.Back\n");
		switch (key)
		{
		case '1': AppropriateRace(list); break;
		default:
			break;
		}
	} while (key != '2');

}
void AppropriateRace(List* list)
{
	int count = 0;
	char destination[15];
	int index = 0,listindex=0;
	Month tempMonth=December;
	int tempDay = 31;
	system("cls");
	printf("Please, enter destination:");
	scanf_s("%s", destination,sizeof(destination));
	Item* p = list->head;
	while (p)
	{
		if (strcmp(p->item->destination,destination)==0) {
			 if (p->item->month == tempMonth) {
				if (p->item->day<tempDay) {
					tempDay = p->item->day;
					tempMonth = p->item->month;
					index = listindex;
					count++;
				}
			}else if (p->item->month<tempMonth && p->item->month>CurrentMonth) {
				tempDay = p->item->day;
				tempMonth = p->item->month;
				index = listindex;
				count++;
			}
		}
		listindex++;
		p = p->next;
	}
	if (!count) {
		printf("\nNo results were found for this request.\n");
	}else PrintFlightByIndex(list, index);
	getchar();
}

#pragma once
#ifndef STRUCTS_H
#define STRUCTS_H
#include <time.h>
typedef enum {
	January, February, March, April, May, June, July, August, September, October, November, December
} Month;
char* GetMonth(Month month);
typedef struct flight {
	int isdeleted;
	int numinlist;
	char flight_number[7];
	char destination[15];
	char type[10];
	int hour, minute;
	int flight_time;
	int free_places;
	Month month;
	int day;
} Flight;
typedef struct item {
	Flight* item;
	struct item* next;
	struct item* prev;
} Item;
typedef struct list {
	Item* head;
	Item* tail;
	int n;
} List;
extern void AddFlight(List* list, Flight* flight);
extern void PrintFlight(Flight flight);
extern void ClearList(Item * item);
extern Flight CreateFlight(char* flight_number, char destination[], char* type, int hour, int minute, int flight_time, int free_places);
extern void PrintAllFlights(List* list);
extern void Search(List* list);
extern void AppropriateRace(List* list);
extern void PrintFlightByIndex(List* list, int index);
void DeleteFromList(List* list, int index);
void DeleteMenu(List* list);
extern void AddFlightInList(List* list);
#endif // !STRUCTS_H

#include <stdio.h>
#include <errno.h>
#include "AllStructs.h"
#include "interface.h"
#include "work_with_files.h"
List SomeList= { NULL,NULL,0 };
int main() 
{
	LoadFromFileToList(&SomeList);
	Ad();
	errno_t	err;
	FILE* fPtr;
	Menu();
	ClearList(SomeList.head);
	return 0;

}
void FlightsMenu() {
	char key;
	do {
		key = getchar();
		system("cls");
		printf(
			"1.View all flights\n"
			"2.Search\n"
			"3.Add a flight\n"
			"4.Delete a flight\n"
			"5.Print ticket\n"
			"6.Back\n"
		);
		switch (key)
		{
		case '1':PrintAllFlights(&SomeList); break;
		case '2':Search(&SomeList); break;
		case '3':AddFlightInList(&SomeList); break;
		case '4':DeleteMenu(&SomeList); break;
		case '6':break;
		default:
			break;
		}
	} while (key != '6');
}

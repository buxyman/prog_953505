#include "interface.h"
void Menu()
{
	char key;
	do
	{
		key = getchar();
		system("cls");
		printf("\t\t\t\t\tBelavia\n\n");
		printf("1.Flights\n"
				"2.About\n"
				"3.Exit\n"
		);
		//key = getchar();
		switch (key)
		{
		case '1': FlightsMenu(); break;
		case '2':About(); break;
		default:
			break;
		}
	} while(key != '3');
}
void About()
{
	system("cls");
	printf("Program author - Maxim Bystrov");
	getchar();
}
void Ad()
{
	system(CONSOLE_COLOR);
	printf("-----------------Belavia-----------------\n");
	printf("-----------support@belavia.by------------\n");
	printf("------BELAVIA - Belarusian Airlines------\n");
	printf("-14A, Nemiga str., Minsk,Belarus, 220004-\n");
}


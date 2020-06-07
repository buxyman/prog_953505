#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>

void WriteToFile(struct contact** contact, FILE* fptr);
int DateCompare(const struct date first, const struct date second);
void GetTodayDate(struct date* date);
unsigned long long InputCheck(const unsigned long long min, const unsigned long long max);
void PrintDate(const struct date date);
struct event* GetEventNode(struct event* event, int index);
void ChangeEvent(struct event** event);
void SortEvent(struct event* event);
void PrintEvents(struct event** event);
void AddEvent(struct event** event);
void DeleteEvent(struct event** event);
void DisplayEventMenu(struct event** event);
struct contact* GetContactNode(struct contact* contact, int index);
void ChangeContact(struct contact** contact);
void PrintContacts(struct contact** contact);
void AddContact(struct contact** contact);
void DeleteContact(struct contact** contact);
void DisplayContactMenu(struct contact** contact);
void FreeMemoryEvents(struct event* event);
void FreeMemoryContacts(struct contact* contact);
void DisplayNotifications(struct contact* contact);

struct date
{
	int day;
	int mon;
	int year;
};

struct event
{
	char title[30];
	unsigned long long duration_min;
	char place[30];
	struct date dt;
	char note[100];
	struct event* next;
};

struct contact
{
	char surname[20];
	char name[20];
	char work_place[30];
	unsigned long long phone_number;
	struct date birthday;
	struct event(*ev);
	struct contact* next;
};

int main(void)
{
	struct contact* cont = NULL;
	FILE* file;
	while (1)
	{
		struct date dt;
		system("cls");
		GetTodayDate(&dt);
		PrintDate(dt);
		printf("1.Contacts\n");
		printf("2.Notifications\n");
		printf("3.Exit\n");

		char c;
		c = _getch();
		switch (c)
		{
		case '1':
			DisplayContactMenu(&cont);
			break;
		case '2':
			DisplayNotifications(cont);
			break;
		case '3':
			file = fopen("C:\\Users\\Lenovo\\Desktop\\Contacts.txt", "w");
			while (cont)
			{
				WriteToFile(&cont, file);
				cont = (cont)->next;
			}
			fclose(file);
			FreeMemoryContacts(cont);
			return 0;
		default:
			continue;
		}
	}
}

int DateCompare(const struct date first, const struct date second)
{
	if (first.year == second.year)
	{
		if (first.mon == second.mon)
		{
			return first.day - second.day;
		}
		else
		{
			return first.mon - second.mon;
		}
	}
	else
	{
		return first.year - second.year;
	}
}

void GetTodayDate(struct date* date)
{
	time_t timer = time(NULL);
	struct tm* current_date = localtime(&timer);
	date->year = current_date->tm_year + 1900;
	date->mon = current_date->tm_mon + 1;
	date->day = current_date->tm_mday;
}

unsigned long long InputCheck(const unsigned long long min, const unsigned long long max)
{
	int temp = 0;
	unsigned long long res;
	do
	{
		temp = scanf_s("%llu", &res);

		if (temp != 1)
		{
			temp = 0;
			printf("Input error\n");
			while (getchar() != '\n');
		}
		else
		{
			if (res >= min && res <= max)
			{
				break;
			}
			else
			{
				printf("Input error\n");
				temp = 0;
				continue;
			}
		}
	} while (temp != 1);
	return res;
}

void PrintDate(const struct date date)
{
	printf("Date: %d.%d.%d\n", date.day, date.mon, date.year);
}

struct event* GetEventNode(struct event* event, int index)
{
	if (!event)
	{
		return NULL;
	}
	struct event* temp = event;

	int i;
	for (i = 0; i < index; i++)
	{
		temp = temp->next;
	}
	return temp;
}

void ChangeEvent(struct event** event)
{
	char temp[20];
	while (1)
	{
		struct date dt;
		system("cls");
		printf("Title: %s\n", (*event)->title);
		printf("Select what changes to apply:\n");
		printf("1.Duration\n");
		printf("2.Place\n");
		printf("3.Date\n");
		printf("4.Note\n");
		printf("5.Title\n");
		printf("6.Go back\n");

		char c;
		c = _getch();

		switch (c)
		{
		case '1':
			system("cls");
			printf("Duration(min): ");
			scanf_s("%llu", &((*event)->duration_min));
			break;
		case '2':
			system("cls");
			printf("Place: ");
			fgets(temp, 30, stdin);
			fgets((*event)->place, 30, stdin);
			break;
		case '3':
			system("cls");

			printf("Day: ");
			(*event)->dt.day = InputCheck(1, 31);

			printf("Month: ");
			(*event)->dt.mon = InputCheck(1, 12);

			printf("Year: ");
			(*event)->dt.year = InputCheck(2020, 3020);
			break;
		case '4':
			system("cls");
			printf("Note: ");
			fgets(temp, 30, stdin);
			fgets((*event)->note, 100, stdin);
			break;
		case '5':
			system("cls");
			printf("New title: ");
			fgets((*event)->title, 30, stdin);
			break;
		case '6':
			GetTodayDate(&dt);
			if (DateCompare(dt, (*event)->dt) > 0)
			{
				printf("Date assignment is onle possible for the future or present\n");
				printf("Press any key to continue with current time\n");
				_getch();
				GetTodayDate(&((*event))->dt);
			}
			return;
		}
	}
}

void SortEvent(struct event* event)
{
	struct event* first = event;
	struct event* second = event->next;

	while (first->next)
	{
		while (second)
		{
			if (DateCompare(first->dt, second->dt) > 0)
			{
				struct event* temp = first;
				first = second;
				second = temp;
			}
			second = second->next;
		}
		first = first->next;
		second = first->next;
	}
}

void PrintEvents(struct event** event)
{
	if (!(*event))
	{
		printf("List is empty\nPress any key to continue");
		_getch();
		return;
	}
	SortEvent(*event);

	while (1)
	{
		system("cls");
		printf("Select event:\n");
		int leng = 1;
		struct event* temp = (*event);

		while (temp)
		{
			printf("%d.%s", leng++, temp->title);
			temp = temp->next;
		}
		printf("%d.Go back\n", leng);
		int id = InputCheck(1, leng);

		if (id == leng)
		{
			return;
		}
		if (id > 0 && id < leng)
		{
			system("cls");
			id--;
			struct event* p = GetEventNode((*event), id);
			printf("Title: %s", p->title);
			if (p->duration_min != 0)
			{
				printf("Duration(min): %llu\n", p->duration_min);
			}
			else
			{
				printf("Duration(min): \n");
			}
			printf("Place: %s\n", p->place);
			PrintDate(p->dt);
			printf("Note: %s", p->note);
			printf("\nApply changes? (y- yes, n - no)\n");

			while (1)
			{
				char c;
				c = _getch();
				switch (c)
				{
				case 'y':
					ChangeEvent(&p);
					break;
				case 'n':
					break;
				default:
					printf("Input error\n");
					continue;
				}
				break;
			}
		}
		else
		{
			printf("Input error");
		}
	}
}

void AddEvent(struct event** event)
{
	struct event* temp = NULL;

	if (!(temp = (struct event*)malloc(sizeof(struct event))))
	{
		printf("Not enough memory. Goodbye");
		_getch();
		exit(1);
	}
	printf("Title: ");
	fgets(temp->title, 30, stdin);
	GetTodayDate(&temp->dt);
	temp->place[0] = '\0';
	temp->note[0] = '\0';
	temp->next = NULL;
	temp->duration_min = 0;
	ChangeEvent(&temp);

	if (!(*event))
	{
		(*event) = temp;
	}
	else
	{
		temp->next = (*event);
		(*event) = temp;
	}
}

void DeleteEvent(struct event** event)
{
	if (!(*event))
	{
		printf("Is empty\nPress any key to continue");
		_getch();
		return;
	}
	while (1)
	{
		system("cls");
		printf("Select event:\n");
		int leng = 1;
		struct event* temp = (*event);

		while (temp)
		{
			printf("%d.%s", leng++, temp->title);
			temp = temp->next;
		}
		printf("%d.Go back\n", leng);
		int id = InputCheck(1, leng);

		if (id == leng)
		{
			return;
		}
		if (id > 0 && id < leng)
		{
			printf("Are you sure?(y - yes, n - no)\n");

			while (1)
			{
				struct event* p = NULL;

				char c;
				c = _getch();
				switch (c)
				{
				case 'y':
					if (id == 1)
					{
						p = *event;
						*event = (*event)->next;
						free(p);
					}
					else
					{
						p = GetEventNode(*event, id - 2);
						struct event* pn = p->next;
						p->next = p->next->next;
						free(pn);
					}
					break;
				case 'n':
					break;;
				default:
					printf("Input error");
					continue;
				}
				break;
			}
		}
	}
}

void DisplayEventMenu(struct event** event)
{
	while (1)
	{
		system("cls");
		printf("1.Show events\n");
		printf("2.Add event\n");
		printf("3.Delete event\n");
		printf("4.Go back\n");

		char c;
		c = _getch();
		switch (c)
		{
		case '1':
			PrintEvents(event);
			break;
		case '2':
			AddEvent(event);
			break;
		case '3':
			DeleteEvent(event);
			break;
		case '4':
			return;
		default:
			break;
		}
	}
}

struct contact* GetContactNode(struct contact* contact, int index)
{
	if (!contact)
	{
		return NULL;
	}
	struct contact* temp = contact;

	int i;
	for (i = 0; i < index; i++)
	{
		temp = temp->next;
	}
	return temp;
}

void ChangeContact(struct contact** contact)
{
	while (1)
	{
		system("cls");
		printf("%s%s\n", (*contact)->surname, (*contact)->name);
		printf("Select what to change\n");
		printf("1.Surname and first name\n");
		printf("2.Phone number\n");
		printf("3.Work place\n");
		printf("4.Birthday\n");
		printf("5.Events\n");
		printf("6.Go back\n");

		char temp[30];
		char c;
		c = _getch();
		switch (c)
		{
		case '1':
			system("cls");
			printf("Surname: ");
			fgets(temp, 30, stdin);
			fgets((*contact)->surname, 20, stdin);
			printf("\nFirst name: ");
			fgets((*contact)->name, 20, stdin);
			break;
		case '2':
			system("cls");
			printf("Phone number: ");
			scanf_s("%llu", &((*contact)->phone_number));
			break;
		case '3':
			system("cls");
			printf("Work place: ");
			fgets(temp, 30, stdin);
			fgets((*contact)->work_place, 30, stdin);
			break;
		case '4':
			system("cls");
			printf("Day: ");
			(*contact)->birthday.day = InputCheck(1, 31);

			printf("Month: ");
			(*contact)->birthday.mon = InputCheck(1, 12);

			printf("Year: ");
			(*contact)->birthday.year = InputCheck(1, 2020);
			break;
		case '5':
			DisplayEventMenu(&(*contact)->ev);
			break;
		case '6':
			return;
		default:
			break;
		}
	}
}

void PrintContacts(struct contact** contact)
{
	if (!(*contact))
	{
		printf("List is empty");
		Sleep(500);
		return;
	}

	while (1)
	{
		system("cls");
		printf("Select contact:\n");
		int leng = 1;
		struct contact* temp = (*contact);

		while (temp)
		{
			printf("%d.%s  %s", leng++, temp->surname, temp->name);
			temp = temp->next;
		}

		printf("%d.Go back\n", leng);
		int id = InputCheck(1, leng);

		if (id == leng)
		{
			return;
		}
		else if (id > 0 && id < leng)
		{
			system("cls");
			id--;
			struct contact* p = GetContactNode((*contact), id);
			printf("Surname: %s", p->surname);
			printf("First name: %s", p->name);
			printf("Work place: %s\n", p->work_place);
			PrintDate(p->birthday);
			printf("Phone number: %llu\n", p->phone_number);
			printf("Events:\n");

			struct event* tempev = (*contact)->ev;

			while (tempev)
			{
				printf("%s", tempev->title);
				if (tempev->next == NULL)
				{
					break;
				}
				else tempev = tempev->next;
			}
			printf("\n\nApply changes? (y- yes, n - no)\n");

			while (1)
			{
				char c;
				c = _getch();
				switch (c)
				{
				case 'y':
					ChangeContact(&p);
					break;
				case 'n':
					break;
				default:
					printf("Input error\n");
					continue;
				}
				break;
			}
		}
		else
		{
			printf("Input error");
		}
	}
}

void AddContact(struct contact** contact)
{
	struct contact* temp = NULL;
	char tempget[20];
	if (!(temp = (struct contact*)malloc(sizeof(struct contact))))
	{
		printf("Not enough memory. Goodbye");
		_getch();
		exit(1);
	}
	printf("Surname: ");
	fgets(temp->surname, 30, stdin);
	printf("First name: ");
	fgets(temp->name, 30, stdin);
	GetTodayDate(&temp->birthday);
	temp->work_place[0] = '\0';
	temp->phone_number = 0;
	temp->ev = NULL;
	temp->next = NULL;
	ChangeContact(&temp);

	if (!(*contact))
	{
		(*contact) = temp;
	}
	else
	{
		temp->next = (*contact);
		(*contact) = temp;
	}
}

void DeleteContact(struct contact** contact)
{
	if (!(*contact))
	{
		printf("List is empty\nPress any key to continue");
		_getch();
		return;
	}
	while (1)
	{
		system("cls");
		printf("Select contact:\n");
		int leng = 1;
		struct contact* temp = *contact;

		while (temp)
		{
			printf("%d.%s  %s", leng++, temp->surname, temp->name);
			temp = temp->next;
		}
		printf("%d.Go back\n", leng);
		int id = InputCheck(1, leng);

		if (id == leng)
		{
			return;
		}
		else
		{
			printf("Are you sure?(y - yes, n - no)\n");

			while (1)
			{
				struct contact* p = NULL;

				char c;
				c = _getch();
				switch (c)
				{
				case 'y':
					if (id == 1)
					{
						p = *contact;
						*contact = (*contact)->next;
						free(p);
					}
					else
					{
						p = GetContactNode(*contact, id - 2);
						struct contact* pn = p->next;
						p->next = p->next->next;
						free(pn);
					}
					break;
				case 'n':
					break;;
				default:
					printf("Input error");
					continue;
				}
				break;
			}
		}
	}
}

void DisplayContactMenu(struct contact** contact)
{
	while (1)
	{
		system("cls");
		printf("1.Show contacts\n");
		printf("2.Add contact\n");
		printf("3.Delete contact\n");
		printf("4.Go back\n");

		fflush(stdin);
		char c;
		c = _getch();
		switch (c)
		{
		case '1':
			PrintContacts(contact);
			break;
		case '2':
			AddContact(contact);
			break;
		case '3':
			DeleteContact(contact);
			break;
		case '4':
			return;
		default:
			continue;
		}
	}
}

void FreeMemoryEvents(struct event* event)
{
	while (event)
	{
		struct event* temp = event;
		event = event->next;
		free(temp);
	}
}

void FreeMemoryContacts(struct contact* contact)
{
	while (contact)
	{
		FreeMemoryEvents(contact->ev);
		struct contact* temp = contact;
		contact = contact->next;
		free(temp);
	}
}

void DisplayNotifications(struct contact* contact)
{
	struct date dt;
	GetTodayDate(&dt);
	struct contact* temp = contact;
	printf("Coming soon:\n");

	while (temp)
	{
		struct event* p = temp->ev;

		while (p)
		{
			if (p->dt.year == dt.year &&
				p->dt.mon == dt.mon &&
				p->dt.day - dt.day < 5 &&
				p->dt.day - dt.day >= 0)
			{
				printf("%s", p->title);
				PrintDate(p->dt);
			}
			p = p->next;
		}
		temp = temp->next;
	}
	printf("Birthday:\n");
	temp = contact;

	while (temp)
	{
		if (temp->birthday.mon == dt.mon &&
			temp->birthday.day - dt.day < 5 &&
			temp->birthday.day - dt.day >= 0)
		{
			printf("%s%s", temp->surname, temp->name);
			PrintDate(temp->birthday);
		}
		temp = temp->next;
	}
	printf("\nPress any key to continue\n");
	_getch();
	return;
}

void WriteToFile(struct contact** contact, FILE* fptr)
{
	struct contact* tempwrite = (*contact);

	while (tempwrite != NULL)
	{
		fprintf(fptr, "%s\n", tempwrite->name);
		fprintf(fptr, "%s\n", tempwrite->surname);
		if (tempwrite->work_place)
		{
			fprintf(fptr, "%s\n", tempwrite->work_place);
		}
		if (tempwrite->phone_number)
		{
			fprintf(fptr, "%llu\n", tempwrite->phone_number);
		}
		if (tempwrite->birthday.day && tempwrite->birthday.mon && tempwrite->birthday.year)
		{
			fprintf(fptr, "%d.%d.%d\n", tempwrite->birthday.day, tempwrite->birthday.mon, tempwrite->birthday.year);
		}
		if (tempwrite->ev)
		{
			if (tempwrite->ev->title)
			{
				fprintf(fptr, "%s\n", tempwrite->ev->title);
			}
			if (tempwrite->ev->duration_min)
			{
				fprintf(fptr, "%llu\n", tempwrite->ev->duration_min);
			}
			if (tempwrite->ev->place)
			{
				fprintf(fptr, "%s\n", tempwrite->ev->place);
			}
			if (tempwrite->ev->dt.day && tempwrite->ev->dt.mon && tempwrite->ev->dt.year)
			{
				fprintf(fptr, "%d.%d.%d\n", tempwrite->ev->dt.day, tempwrite->ev->dt.mon, tempwrite->ev->dt.year);
			}
			if (tempwrite->ev->note)
			{
				fprintf(fptr, "%s", tempwrite->ev->note);
			}
		}
		if (tempwrite == NULL)
			fprintf(fptr, "\n");
		fputs("==================\n", fptr);

		tempwrite = tempwrite->next;
	}
}

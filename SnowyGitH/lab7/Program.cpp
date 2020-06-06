#include "Menu.h"
#include "Container.h"
#include "List.h"

#define bool int
#define true 1
#define false 0 

int main()
{
	AddNode(&buffList);
	SetDefaultValues(buffList.tail);
	ReadFile();
	int functionNumber = 0;
	int exit = 10;
	while (functionNumber != exit)
	{
		system("cls");
		functionNumber = Menu();
		switch (functionNumber)
		{
		case 1: EmployeeListMenu("Employee list:\n\n", "Employee information:\n\n", true, &ShowEmployeeMenu, &employeeList); break;
		case 2: SearchEmployeeMenu(); break;
		case 3: EmployeeListMenu("Choose who to fire:\n\n", "You sure?\n\n", true, &FireEmployeeMenu, &employeeList); break;
		case 4: HireEmployeeMenu("Enter information about the new employee:\n\n", &employeeList); break;
		case 5: ShowVacation(); break;
		case 6: ShowBirthday(); break;
		case 7: ShowStatusMenu("Employees who are currently at work:\n\n", "Employees who are currently at work:\n\n Nobody is at work!", "At work"); break;
		case 8: ShowStatusMenu("Employees who are currently on vacation:\n\n", "Employees who are currently on vacation:\n\n Nobody on vacation!", "On vacation"); break;
		case 9: ShowStaffReductionMenu(); break;
		case 10: system("cls"); WriteFile();  Clear(&employeeList); Clear(&buffList); Clear(&searchResultList); break;
		default: break;
		}
	}
	printf_s(" ");
	return 0;
}

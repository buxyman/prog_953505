#include <Windows.h>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <vector>

struct Info
{
	string registrationNumber;
	string FIO;
	string gender;
	string birthday;
	string height;
	string weight;
	string city;
	string hobby;
	string badHabits;
	string personalInfo;
};

Info AddDialog()
{
	system("cls");

	string registrationNumber;
	string FIO;
	string gender;
	string birthday;
	string height;
	string weight;
	string city;
	string hobby;
	string badHabits;
	string personalInfo;

	printf_s("%s", string(120, '=').c_str());
	printf_s("\t%s\n", "Registration number      | ");
	printf_s("\t%s\n", "FIO:                     | ");
	printf_s("\t%s\n", "Gender:                  | ");
	printf_s("\t%s\n", "Birthday:                | ");
	printf_s("\t%s\n", "Height:                  | ");
	printf_s("\t%s\n", "Weight:                  | ");
	printf_s("\t%s\n", "City:                    | ");
	printf_s("\t%s\n", "Hobby:                   | ");
	printf_s("\t%s\n", "Bad habits:              | ");
	printf_s("\t%s\n", "Personal info:           | ");
	printf_s("%s", string(120, '=').c_str());

	char tmp[101];

	scanf_s("%100s", tmp, 101);
	registrationNumber = tmp;

	scanf_s("%100s", tmp, 101);
	FIO = tmp;

	scanf_s("%100s", tmp, 101);
	gender = tmp;

	scanf_s("%100s", tmp, 101);
	birthday = tmp;

	scanf_s("%100s", tmp, 101);
	height = tmp;

	scanf_s("%100s", tmp, 101);
	weight = tmp;

	scanf_s("%100s", tmp, 101);
	city = tmp;

	scanf_s("%100s", tmp, 101);
	hobby = tmp;

	scanf_s("%100s", tmp, 101);
	badHabits = tmp;

	scanf_s("%100s", tmp, 101);
	personalInfo = tmp;

	return { registrationNumber, FIO, gender, birthday, height, weight, city, hobby, badHabits, personalInfo };
}

void PrintEntry(Info entry)
{
	printf_s("\tRegistration number:      %s\n", entry.registrationNumber.c_str());
	printf_s("\tFIO:                      %s\n", entry.FIO.c_str());
	printf_s("\tGender:                   %s\n", entry.gender.c_str());
	printf_s("\tBirthday:                 %s\n", entry.birthday.c_str());
	printf_s("\tHeight:                   %s\n", entry.height.c_str());
	printf_s("\tWeight:                   %s\n", entry.weight.c_str());
	printf_s("\tCity:                     %s\n", entry.city.c_str());
	printf_s("\tHobby:                    %s\n", entry.hobby.c_str());
	printf_s("\tBad habits:               %s\n", entry.badHabits.c_str());
	printf_s("\tPersonal info:            %s\n", entry.personalInfo.c_str());
}

void PrintList(vector<Info> info)
{
	system("cls");
	if (info.size() > 0)
	{
		for (unsigned int i = 0; i < info.size(); i++)
		{
			printf_s("%s", string(120, '=').c_str());
			printf_s("Entry #%d\n", i + 1);
			PrintEntry(info[i]);
		}
		printf_s("%s", string(120, '=').c_str());
	}
	else
	{
		printf_s(" There's no data to print!\n Press any key to exit to main menu...\n");
	}
	_getch();
}

void MenuDialog()
{
	system("cls");
	printf_s("%s\n", string(41, '-').c_str());
	printf_s("| What would you like to do?            |\n");
	printf_s("%s\n", string(41, '-').c_str());
	printf_s("| P |  Print all info.                  |\n");
	printf_s("| A |  Add new entry.                   |\n");
	printf_s("| F |  Find entry.                      |\n");
	printf_s("| S |  Sort data.                       |\n");
	printf_s("| C |  Get info about the candidate.    |\n");
	printf_s("| Q |  Quit program.                    |\n");
	printf_s("%s\n", string(41, '-').c_str());
}

void SortData(vector<Info>& data)
{
	for (unsigned int i = 0; i < data.size(); i++)
		for (unsigned int j = 0; j < data.size() - i - 1; j++)
			if (data[j].FIO.compare(data[j + 1].FIO) > 0) swap(data[j], data[j + 1]);
}

void EditDialog(Info& entry)
{
	system("cls");

	string registrationNumber;
	string FIO;
	string gender;
	string birthday;
	string height;
	string weight;
	string city;
	string hobby;
	string badHabits;
	string personalInfo;

	printf_s("%s", string(120, '=').c_str());
	printf_s("\t%s\n", "Registration number      | ");
	printf_s("\t%s\n", "FIO:                     | ");
	printf_s("\t%s\n", "Gender:                  | ");
	printf_s("\t%s\n", "Birthday:                | ");
	printf_s("\t%s\n", "Height:                  | ");
	printf_s("\t%s\n", "Weight:                  | ");
	printf_s("\t%s\n", "City:                    | ");
	printf_s("\t%s\n", "Hobby:                   | ");
	printf_s("\t%s\n", "Bad habits:              | ");
	printf_s("\t%s\n", "Personal info:           | ");
	printf_s("%s", string(120, '=').c_str());

	char tmp[101];

	scanf_s("%100s", tmp, 101);
	registrationNumber = tmp;

	scanf_s("%100s", tmp, 101);
	FIO = tmp;

	scanf_s("%100s", tmp, 101);
	gender = tmp;

	scanf_s("%100s", tmp, 101);
	birthday = tmp;

	scanf_s("%100s", tmp, 101);
	height = tmp;

	scanf_s("%100s", tmp, 101);
	weight = tmp;

	scanf_s("%100s", tmp, 101);
	city = tmp;

	scanf_s("%100s", tmp, 101);
	hobby = tmp;

	scanf_s("%100s", tmp, 101);
	badHabits = tmp;

	scanf_s("%100s", tmp, 101);
	personalInfo = tmp;

	entry.registrationNumber = registrationNumber;
	entry.FIO = FIO;
	entry.gender = gender;
	entry.birthday = birthday;
	entry.height = height;
	entry.weight = weight;
	entry.city = city;
	entry.hobby = hobby;
	entry.badHabits = badHabits;
	entry.personalInfo = personalInfo;
}

void FindEntry(vector<Info>& data)
{
	system("cls");

	char tmp[101];
	string number;
	printf_s("Enter birthday day: ");
	scanf_s("%100s", tmp, 101);
	number = tmp;

	system("cls");

	vector<int> indexes = vector<int>();
	for (unsigned int i = 0; i < data.size(); i++)
	{
		if (data[i].birthday >= number)
		{
			indexes.push_back(i);
		}
	}

	if (!indexes.empty())
	{
		int x;

		for (unsigned int i = 0; i < indexes.size(); i++)
		{
			printf_s("%s", string(120, '=').c_str());
			printf_s("Entry #%d\n", indexes[i] + 1);
			PrintEntry(data[indexes[i]]);
		}
		printf_s("%s", string(120, '=').c_str());

		if (indexes.size() > 1)
		{
			do
			{
				printf_s("Which one?: ");
				scanf_s("%d", &x);
				x--;
			} while (find(indexes.begin(), indexes.end(), x) == indexes.end());
			//system("cls");
		}
		else
		{
			x = indexes[0];
		}

		printf_s("\n What would you like to do? \n");
		printf_s("\t E -  Edit entry.\n");
		printf_s("\t D -  Delete entry.\n");
		printf_s("\t Q -  Quit to main menu.\n");

		bool quit = false;
		while (!quit)
		{
			switch (_getch())
			{
			case 'E':
			case 'e':
				EditDialog(data[x]);
				quit = true;
				break;
			case 'D':
			case 'd':
				data.erase(data.begin() + x);
				quit = true;
				break;
			case 'Q':
			case 'q':
				quit = true;
				break;
			}
			//system("cls");
		}
	}
	else
	{
		printf_s("There's no entries woth matching properties!\nPress any key to return to main menu...\n");
		_getch();
	}
	free(indexes);
}

void GenderInfoDialog(vector<Info>& data)
{
	system("cls");

	char tmp[101];
	string gender;
	printf_s("Enter Author: ");
	scanf_s("%100s", tmp, 101);
	gender = tmp;

	system("cls");

	vector<int> indexes = vector<int>();
	auto found = vector<Info>();
	for (unsigned int i = 0; i < data.size(); i++)
	{
		if (data[i].gender == gender)
		{
			indexes.push_back(i);
			found.push_back(data[i]);
		}
	}

	if (!indexes.empty())
	{
		for (unsigned int i = 0; i < found.size(); i++)
			for (unsigned int j = 0; j < found.size() - i - 1; j++)
				if (found[j].birthday.compare(found[j + 1].birthday) > 0)
				{
					swap(found[j], found[j + 1]);
					swap(indexes[j], indexes[j + 1]);
				}

		for (unsigned int i = 0; i < indexes.size(); i++)
		{
			printf_s("%s", string(120, '=').c_str());
			printf_s("Entry #%d\n", indexes[i] + 1);
			PrintEntry(data[indexes[i]]);
		}
		printf_s("%s", string(120, '=').c_str());

		_getch();
	}
	else
	{
		printf_s("There's no entries woth matching properties!\nPress any key to return to main menu...\n");
		_getch();
	}
	free(indexes);
	free(found);
}

int main()
{
	ifstream input("input.txt");
	ofstream output("output.txt");

	auto info = vector<Info>();

	while (!input.eof())
	{
		string registrationNumber;
		string FIO;
		string gender;
		string birthday;
		string height;
		string weight;
		string city;
		string hobby;
		string badHabits;
		string personalInfo;

		getline(input, registrationNumber);
		getline(input, FIO);
		getline(input, gender);
		getline(input, birthday);
		getline(input, height);
		getline(input, weight);
		getline(input, city);
		getline(input, hobby);
		getline(input, badHabits);
		getline(input, personalInfo);

		Info entry = { registrationNumber, FIO, gender, birthday, height, weight, city, hobby, badHabits, personalInfo };
		info.push_back(entry);
	}

	bool quit = false;
	while (!quit)
	{
		MenuDialog();
		switch (_getch())
		{
		case 'P':
		case 'p':
			PrintList(info);
			break;
		case 'A':
		case 'a':
			info.push_back(AddDialog());
			break;
		case 'S':
		case 's':
			SortData(info);
			break;
		case 'C':
		case 'c':
			GenderInfoDialog(info);
			break;
		case 'F':
		case 'f':
			FindEntry(info);
			break;
		case 'Q':
		case 'q':
			quit = true;
			break;
		}
		system("pause");
	}

	for (unsigned int i = 0; i < info.size(); i++)
	{
		output << info[i].registrationNumber << endl;
		output << info[i].FIO << endl;
		output << info[i].gender << endl;
		output << info[i].birthday << endl;
		output << info[i].height << endl;
		output << info[i].weight << endl;
		output << info[i].city << endl;
		output << info[i].hobby << endl;
		output << info[i].badHabits << endl;
		output << info[i].personalInfo << endl;
		if (i < info.size() - 1) output << endl;
	}


	input.close();
	output.close();
	free(info);
	return 0;
}

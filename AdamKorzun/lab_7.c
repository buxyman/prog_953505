#include <stdio.h>
// var - 16
typedef struct student {
	struct student* next;
	struct student* prev;
	char* name;
	int** grades;
	int numberOfSessions;
	int year;
	int group;
	int* numberOfGrades;
	float* averageGrades;
}Student;

void AddStudent(Student* stu, char name[], int** grades, int numberOfSessions, int numberOfGrades[], int year, int group){
	
	Student* newStudent = (Student*)malloc(sizeof(Student));
	newStudent->next = NULL;
	newStudent->prev = stu;
	
	stu->next = newStudent;
	
	
	
	newStudent->grades = (int**)malloc(sizeof(int*) * numberOfSessions);
	newStudent->averageGrades = (float*)malloc(sizeof(float) * numberOfSessions);
	for (int i = 0; i < numberOfSessions; i++) {
		(newStudent->grades)[i] = (int*)malloc(sizeof(int) * numberOfGrades[i]);
		float averageGrade = 0;
		for (int j = 0; j < numberOfGrades[i]; j++) {
			averageGrade += grades[i][j];
		}
		averageGrade /= numberOfGrades[i];
		(newStudent->averageGrades)[i] = averageGrade;
	}
	for (int i = 0; i < numberOfSessions; i++) {
		for (int j = 0; j < numberOfGrades[i]; j++) {
			(newStudent->grades)[i][j] = grades[i][j];
		}
	}
	newStudent->name = (char*)malloc(strlen(name) * sizeof(char));
	
	strcpy(newStudent->name,name);
	newStudent->numberOfSessions = numberOfSessions;
	newStudent->group  = group;
	newStudent->year = year;
	newStudent->numberOfGrades = numberOfGrades;
}
void PrintInfo(Student* stu, int session, int pos) {
	if (session > stu->numberOfSessions) {
		return;
	}
	printf("%s%d	%.2f	%d	", stu->name, stu->group, (stu->averageGrades)[session - 1], pos);
	if (session - 2 >= 0) {
		if ((stu->averageGrades)[session - 1] > (stu->averageGrades)[session - 2]) {
			printf("+");
		}
		else if ((stu->averageGrades)[session - 1] < (stu->averageGrades)[session - 2]) {
			printf("-");
		}
	}
	printf("\n");
	
	/*
	for (int i = 0; i < stu->numberOfSessions; i++) {
		for (int j = 0; j < (stu->numberOfGrades)[i]; j++) {
			printf("%d ", (stu->grades)[i][j]);
		}
		printf("\n");
	}
	*/
	//printf("%d\n", stu->group);
	//printf("%.2f\n", (stu->averageGrades)[session - 1]);
}
void BubbleSort(Student* start,int session){
	int tr = 1;
	if (session > start->numberOfSessions) {
		return;
	}
	Student* temp = start;
	Student* next = start->next;
	while (tr) {
		tr = 0;
		while (next) {
			if (next->numberOfSessions < session || start->numberOfGrades < session) {
				start = start->next;
				next = start->next;
				continue;
			}
			if (start->numberOfSessions > next->numberOfSessions) {
				tr = 1;
				temp = start;
				if (start->prev) {
					(start->prev)->next = start->next;
				}
				if (next->next) {
					(next->next)->prev = next->prev;
				}
				next->prev = start->prev;
				start->next = next->next;
				next->next = start;
				start->prev = next;
				start = start->prev;


			}
			start = start->next;
			next = start->next;

		}
		while (start->prev) {
			start = start->prev;
		}
		next = start->next;

	}
	while (start->prev) {
		start = start->prev;
	}
	next = start->next;
	tr = 1;
	while (tr) {
		tr = 0;
		while (next) {
			if (next->numberOfSessions < session || start->numberOfGrades < session) {
				start = start->next;
				next = start->next;
				continue;
			}
			if ((start->averageGrades)[session - 1] < (next->averageGrades)[session - 1]) {
				tr = 1;
				temp = start;
				if (start->prev) {
					(start->prev)->next = start->next;
				}
				if (next->next) {
					(next->next)->prev = next->prev;
				}
				next->prev = start->prev;
				start->next = next->next;
				next->next = start;
				start->prev = next;
				start = start->prev;


			}
			start = start->next;
			next = start->next;
			
		}
		while (start->prev) {
			start = start->prev;
		}
		next = start->next;
		
	}
}
void GetInfoFromFile(char** stuNames, int numberOfStudents, Student* stu) {
	for (int i = 0; i < numberOfStudents; i++) {
		FILE* stuFile = fopen(strcat(stuNames[i], ".txt"), "r");
		char* name = (char*)malloc(sizeof(char) * 100);
		int group;
		int year;
		int numberOfSessions;
		fgets(name, 99, stuFile);
		fscanf(stuFile, "%d", &group);
		fscanf(stuFile, "%d", &year);
		fscanf(stuFile, "%d", &numberOfSessions);
		char** gradesChar = (char**)malloc(sizeof(char*) * numberOfSessions);
		for (int j = 0; j < numberOfSessions; j++) {
			gradesChar[j] = (char*)malloc(sizeof(char) * 100);
		}
		fgets(gradesChar[0], 99, stuFile);
		for (int j = 0; j< numberOfSessions; j++) {
			if (feof(stuFile)) {
				break;
			}
			fgets(gradesChar[j], 99, stuFile);
		
		}
		int* numberOfGrades = (int*)malloc(sizeof(int) * numberOfSessions);
		for (int j = 0; j < numberOfSessions; j++) {
			numberOfGrades[j] = (strlen(gradesChar[j])) / 2;
		}


		int** grades = (int**)malloc(sizeof(int*) * numberOfSessions);
		for (int j = 0; j < numberOfSessions; j++) {
			grades[j] = (int*)malloc(sizeof(int) * numberOfGrades[j]);
		}
		for (int j = 0; j < numberOfSessions; j++) {
			for (int f = 0, k = 0; f < strlen(gradesChar[j]); f += 2, k++) {
				char* tempStr = (char*)malloc(sizeof(char) * 100);
				for (int z = f,m = 0; gradesChar[j][z] != ' ' && gradesChar[j][z] != '\n' && gradesChar[j][z] != NULL; z++,m++) {
					tempStr[m] = gradesChar[j][z];
					f = z;
					
				}
				
				grades[j][k] = atoi(tempStr);
				
				free(tempStr);
				
;			}
			
		}
		
		AddStudent(stu, name, grades, numberOfSessions, numberOfGrades, year, group);
		
		stu = stu->next;




		for (int j = 0; j < numberOfSessions; j++) {
			free(gradesChar[j]);
			
		}
		free(gradesChar);

		fclose(stuFile);
	}
	
}
void PrintMenu() {
	printf("1 - Get info by group\n");
	printf("2 - Get info by session\n");
	printf("3 - Exit\n");
	printf("Option: ");
}
int main() {
	FILE* flNames;
	char nameBuffer[100];
	
	flNames = fopen("names.txt", "r");

	if (flNames == NULL) {
		printf("Can't open names.txt");
		return;
	}
	int numberOfFiles = 0;
	while (fscanf(flNames, "%s", &nameBuffer) != EOF) {
		numberOfFiles++;
	}
	rewind(flNames);
	char** fileNames = (char**)malloc(sizeof(char*) * numberOfFiles);
	for (int i = 0; i < numberOfFiles; i++) {
		fileNames[i] = (char*)malloc(sizeof(char) * 100);
		fscanf(flNames, "%s", fileNames[i]);
		
	}
	
	Student* stu = (Student*)malloc(sizeof(Student));
	stu->next = NULL;
	stu->prev = NULL;
	GetInfoFromFile(fileNames, numberOfFiles, stu);
	if (!stu->next) {
		return;
	}
	stu = stu->next;
	free(stu->prev);
	stu->prev = NULL;
	
	
	/*
	while (stu->next) {
		PrintInfo(stu,1);
		stu = stu->next;
	}
	if (!stu->next) {
		PrintInfo(stu,1);
	}
	*/
	



	while (1) {
		char option;
		PrintMenu();
		scanf("%c", &option);
		if (option == '1') {
			system("cls");
			int group;
			int session;
			int pos = 0;
			printf("Group: ");
			scanf("%d", &group);
			printf("Session: ");
			scanf("%d", &session);
			BubbleSort(stu, session);

			while (stu->prev) {
				stu = stu->prev;
			}
			while (stu->next) {
				if (stu->group== group) {
					pos++;
					PrintInfo(stu, session,pos);
				}
				stu = stu->next;
			}
			if (stu->group == group) {
				pos++;
				PrintInfo(stu, session, pos);
			}
			while (stu->prev) {
				stu = stu->prev;
			}
		}
		else if (option == '2') {
			system("cls");
			int year;
			int session;
			printf("Year: ");
			scanf("%d", &year);
			printf("Session: ");
			scanf("%d", &session);
			BubbleSort(stu, session);

			while (stu->prev) {
				stu = stu->prev;
			}
			int pos = 0;
			while (stu->next) {
				if (stu->year == year) {
					pos++;
					PrintInfo(stu, session,pos);
				}
				stu = stu->next;
			}
			if (stu->year == year) {
				pos++;
				PrintInfo(stu, session,pos);
			}
			while (stu->prev) {
				stu = stu->prev;
			}
			
		}
		else if (option == '3') {
			break;
		}
		_getch();
		system("cls");
	}



	while (stu->next) {
		
		stu = stu->next;
	}
	while (stu->prev) {
		stu = stu->prev;
		free(stu->next);
	}
	free(stu);
	for (int i = 0; i < numberOfFiles; i++) {
		free(fileNames[i]);
	}
	free(fileNames);
	
	return -1;
}

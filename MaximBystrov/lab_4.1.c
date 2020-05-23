// -------------4.1(Вариант 28) Быстров Максим 953505-------------
#include <stdio.h>
#include <string.h>
#include <locale.h>
#define COUNT 3
void Swap(char text[]);
int MinLength(char text[]);
int MinLength(char text[]);
int main() {
	setlocale(LC_ALL, "Rus");
	printf("Введите 3 строки:\n");
	int MAX = 0, MIN = 1000;
	char txt[3][120];
	for (int i = 0; i < COUNT; i++) {
		fgets(txt[i], sizeof(txt[i]) + 1, stdin);
		if (MAX < MaxLength(txt[i]))MAX = MaxLength(txt[i]);
		if (MIN > MinLength(txt[i]))MIN = MinLength(txt[i]);
	}
	for (int i = 0; i < COUNT; i++) {
		Swap(txt[i]);
	}
	printf("\n\nMax length in text:%d\nMin length in text:%d", MAX, MIN);
	return 0;
}
/*Меняет местами самое длинное и самое короткое слово в text[]*/
void Swap(char text[]) {
	char temp[120], temp2[120];
	int min = 0, max = 0, tempmin = 100, tempmax = 0, index = 0, index2 = 0;
	int maxind, minind;
	strcpy_s(temp, sizeof(temp), text);
	strcpy_s(temp2, sizeof(temp2), text);
	char answer[120] = "";
	char* strmin = NULL;
	char* strmax = NULL;
	char* delim = NULL;
	char* delim2 = NULL;
	char *ptr = strtok_s(temp, " ", &delim);
	char *ptr2 = strtok_s(temp2, " ", &delim2);
	while (ptr != NULL)
	{
		if (tempmin > strlen(ptr)) {
			tempmin = strlen(ptr);
			minind = index;
			strmin = ptr;
		}
		if (tempmax < strlen(ptr)) {
			tempmax = strlen(ptr);
			maxind = index;
			strmax = ptr;
		}
		index++;
		ptr = strtok_s(NULL, " ", &delim);
	}
	while (ptr2 != NULL) {
		if (index2 == minind) {
			strcat_s(answer, 120, strmax);
		}
		else if (index2 == maxind) {	
			strcat_s(answer, 120, strmin);
		}
		else {
			strcat_s(answer, 120, ptr2);
		}
		index2++;
		strcat_s(answer, 120, " ");
		ptr2 = strtok_s(NULL, " ", &delim2);
	}
	printf("Swaped:%s", answer);	
}
/*Возвращает длину самого длинного слова в text[]*/
int MaxLength(char text[]) {
	char temp[120];
	strcpy_s(temp, sizeof(temp), text);
	char* delim = NULL;
	char *ptr = strtok_s(temp, " ", &delim);
	int tempmax = 0;
	while (ptr != NULL)
	{
		if (tempmax < strlen(ptr)) {
			tempmax = strlen(ptr);
		}
		ptr = strtok_s(NULL, " ", &delim);
	}
	return tempmax;	
}
/*Возвращает длину самого короткого слова в text[]*/
int MinLength(char text[]) {
	char temp[120];
	strcpy_s(temp, sizeof(temp), text);
	char* delim = NULL;
	char *ptr = strtok_s(temp, " ", &delim);
	int tempmin = 9999;
	while (ptr != NULL)
	{
		if (tempmin > strlen(ptr)) {
			tempmin = strlen(ptr);
		}
		ptr = strtok_s(NULL, " ", &delim);
	}
	return tempmin;
}

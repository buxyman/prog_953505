  
// -------------4.2(Вариант 28) Быстров Максим 953505-------------
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <errno.h>
#include <string.h>
void Replacement();
void Replace(char oldword[], char newword[], char answer[]);
int NumOfPairs();
void ReplaceInLine(char *str, const char *oldword, const char *newword);
int main() {
	Replacement();
	return 0;	
}
/*Находим количество пар во втором файле*/
int NumOfPairs() {
	FILE* fPtr;
	errno_t err;
	char temp[120];
	int NUM = 0;
	if ((err = fopen_s(&fPtr, "second.txt", "r")) != 0)
	{
		printf("FAILED");
	}
	else
	{
		while ((fgets(temp, 120, fPtr)) != NULL)
		{
			NUM++;
		}
		fclose(fPtr);
	}
	return NUM;
}
/*Проходим по каждой паре во втором файле и вызываем фукцию замены*/
void Replacement() {
	FILE* fPtr;
	errno_t err;
	char oldword[15], newword[15],answer[120];
	if ((err = fopen_s(&fPtr, "second.txt", "r")) != 0)
	{
		printf("FAILED");
	}
	else {
		for (int i = 0; i < NumOfPairs(); i++)
		{
			fscanf_s(fPtr, "%s", oldword, sizeof(oldword));
			fscanf_s(fPtr, "%s", newword, sizeof(newword));
			Replace(oldword, newword, answer);
		}
		fclose(fPtr);
	}
}
/*Проходим по каждой строке первого файла и переписываем сам файл*/
void Replace(char oldword[],char newword[],char answer[]) {
	FILE* fPtr;
	FILE* fTemp;
	errno_t err,err2;
    char currentline[120];
	err2 = fopen_s(&fTemp, "replace.tmp", "w");
	if ((err = fopen_s(&fPtr, "first.txt", "r+")) != 0 && (err2)!=0 &&fTemp!=NULL )
	{
		printf("FAILED");
	}
	else {		
		while ((fgets(currentline, 120, fPtr)) != NULL)
		{
			ReplaceInLine(currentline, oldword, newword);
			fputs(currentline, fTemp);
		}
		fclose(fPtr);
		fclose(fTemp);
		remove("first.txt");
		rename("replace.tmp", "first.txt");
	}
}
void ReplaceInLine(char *str, const char *oldword, const char *newword)
{
	char *pos, temp[120];
	int index = 0;
	int owlen;
	owlen = strlen(oldword);
	while ((pos = strstr(str, oldword)) != NULL)
	{
		strcpy(temp, str);
		index = pos - str;
		str[index] = '\0';
		strcat(str, newword);
		strcat(str, temp + index + owlen);
	}
}

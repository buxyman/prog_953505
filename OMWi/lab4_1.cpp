#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

int StrLen(char* str) {
	int size = 0;
	while (str[size] != '\0') size++;
	return size;
}

void PrintStr(char* str) {
	for (int i = 0; i < StrLen(str); i++) {
		printf("%c", str[i]);
	}
}

bool IsLower(char ch) {
	if (ch < 'a' || ch > 'z') return false;
	return true;
}

char ToUpper(char ch) {
	if (IsLower(ch)) {
		ch += 'A' - 'a';
	}
	return ch;
}

char* Correct(char* str1)
{
	char* str2 = (char*)malloc(sizeof(char) * 300);
	int index2 = 0;
	for (int index1 = 0; index1 < StrLen(str1); index1++, index2++) {
		str2[index2] = str1[index1];
		if ((str1[index1] == ',' || str1[index1] == ':' || str1[index1] == ';' 
			|| str1[index1] == '.' || str1[index1] == '!' || str1[index1] == '?')
			&& str1[index1 + 1] != ' ')
		{
			if (index1 + 1 == StrLen(str1)) continue;
			str2[++index2] = ' ';			
		}
		if ((str1[index1] == '.' || str1[index1] == '!' || str1[index1] == '?') && IsLower(str1[index1 + 2])) {
			str2[++index2] = ToUpper(str1[++index1]);
		}
	}
	str2[index2] = '\0';
	return str2;
}

int main() {
	char* str = (char*)malloc(sizeof(char)*200);
	gets_s(str, 200);
	printf("Start string:");
	PrintStr(str);
	PrintStr("\n");
	char* temp = str;
	str = Correct(str);
	free(temp);
	printf("Formatted string:");
	PrintStr(str);
	free(str);
}
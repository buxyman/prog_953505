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

int Find(char* str, char ch) {
	for (int index = 0; index < StrLen(str); index++) {
		if (str[index] == ch) return index;
	}
	return -1;
}

int FindLast(char* str, char ch) {
	for (int index = StrLen(str) - 1; index >= 0; index--) {
		if (str[index] == ch) return index;
	}
	return -1;
}

bool CheckEquivalence(char* str) {
	int count = 0;
	for (int index = 0; index < StrLen(str); index++) {
		if (str[index] == '(') count++;
		if (str[index] == ')') count--;
	}
	if (!count && (Find(str, ')') > FindLast(str, '('))) return true;
	return false;
}

char* ReturnBrackets(char* str, int noChangeIndex1, int noChangeIndex2) {
	str[noChangeIndex1] = '(';
	str[noChangeIndex2] = ')';
	return str;
}

char* Correct(char* str) {
	if (!CheckEquivalence(str)) return str;
	int noChangeIndex1 = FindLast(str, '(');
	int noChangeIndex2 = Find(str, ')');
	str[noChangeIndex1] = 's';
	str[noChangeIndex2] = 's';
	if (FindLast(str, '(') == -1) return ReturnBrackets(str, noChangeIndex1, noChangeIndex2);
	str[FindLast(str, '(')] = '[';
	str[Find(str, ')')] = ']';
	while (FindLast(str, '(') != -1) {
		str[FindLast(str, '(')] = '{';
		str[Find(str, ')')] = '}';
	}
	return ReturnBrackets(str, noChangeIndex1, noChangeIndex2);
}

char* GetTextF(char* name) {
	FILE* fp;
	fopen_s(&fp, name, "r");
	if (!fp) return NULL;
	int size = 0;
	while (fgetc(fp) != EOF) {
		size++;
	}
	char* text = (char*)malloc(sizeof(char) * (size + 1));
	fseek(fp, 0, 0);
	fgets(text, size + 1, fp);
	return text;
}

int main() {
	char* str;
	char name[] = "data.txt";
	str = GetTextF(name);
	PrintStr(str);
	PrintStr("\n");
	str = Correct(str);
	PrintStr(str);
	free(str);
}
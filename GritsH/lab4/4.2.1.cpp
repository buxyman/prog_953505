// 4.2.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>


int main()
{
	FILE* file;
	char arr[256];
	int counter = 0, * sizes, wordSize = 0;
	int length = 0, wordsAmount = 0;
	fopen_s(&file, "text.txt", "r");
	if (file == 0)
	{
		printf_s("press f to pay respect\n");
	}
	else printf_s("okey it's here\n\n");
	while ((fgets(arr, 256, file)) != NULL)
	{
		printf_s("%s", arr);
	}
	printf_s("\n");
	length = strlen(arr);
	arr[length] = '\0';
	for (int i = 0; i < length; i++)
	{
		if (arr[i] == ' ')
		{
			counter++;
		}
	}
	wordsAmount = counter + 1;
	sizes = (int*)malloc(wordsAmount * sizeof(int));
	int j = 0;
	for (int i = 0; i <= length; i++)
	{
		if (arr[i] == ' ' || arr[i] == NULL)
		{
			sizes[j] = wordSize;
			wordSize = 0;
			j++;
		}
		else
		{
			wordSize++;
		}
	}
	char** buff = (char**)malloc(wordsAmount * sizeof(char*));
	for (int i = 0; i < wordsAmount; i++)
	{
		buff[i] = (char*)malloc(sizes[i] * sizeof(char));
	}
	int index1 = 0, index2 = 0;
	for (int i = 0; i <= length; i++)
	{
		if (arr[i] == ' ' || arr[i] == NULL)
		{
			buff[index1][index2] = '\0';
			index1++;
			index2 = 0;
		}
		else
		{
			buff[index1][index2] = arr[i];
			index2++;
		}
	}
	printf_s("\n");
	for (int i = 0; i < wordsAmount; i++)
	{
		printf_s("%s - ", buff[i]);
		for (int j = sizes[i] - 1; j >= 0; j--)
		{
			printf_s("%c", buff[i][j]);
		}
		printf_s("\n----------------------\n");
	}

https://www.youtube.com/watch?v=gKpk4-tAzs4&feature=youtu.be 
	// sry 
	fclose(file);
	for (int i = 0; i < wordsAmount; i++)
	{
		free(buff);
	}
	free(buff);
	free(sizes);
	free(arr);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

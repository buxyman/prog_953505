// 4.1.1.0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <string.h>
#include <malloc.h>

int amountOfWords(char* input)
{
	int i = 0;
	int amount = 0;
	while (input[i] != '\0')
	{
		if (input[i] == ' ')
		{
			amount++;
		}
		i++;
	}
	return amount + 1;
}

int* wordsSizes(char* input)
{
	int wordSize = 0;
	int* arrayOfSizes = (int*)malloc(amountOfWords(input) * sizeof(int));
	int i = 0, j = 0;
	while (input[j] != '\n')
	{
		if (input[j] == ' ')
		{
			arrayOfSizes[i] = wordSize;
			wordSize = 0;
			i++;
		}
		if (input[j] != ' ')
		{
			wordSize++;
			if (input[j + 1] == '\n')
			{
				arrayOfSizes[i] = wordSize;
			}
		}
		j++;
	}
	return arrayOfSizes;
}


int main()
{
	char input[256];
	int index1 = 0, index2 = 0;
	char splittedInput[50][50];
	printf_s("Enter the text: ");
	fgets(input, sizeof input, stdin);
	int wordsAmount = amountOfWords(input);
	int o = 0;
	int textLength = 0;
	while (input[o] != '\n')
	{
		textLength++;
		o++;
	}
	for (int i = 0; i <= textLength; i++)
	{
		if (input[i] == ' ' || input[i] == '\n')
		{
			splittedInput[index1][index2] = '\0';
			index1++;
			index2 = 0;
		}
		else
		{
			splittedInput[index1][index2] = input[i];
			index2++;
		}
	}
	char** arr = (char**)malloc(wordsAmount * sizeof(char*)); 
	for (int i = 0; i < wordsAmount; i++)
	{
		arr[i] = (char*)malloc(wordsSizes(input)[i] * sizeof(char));
	}
	for (int i = 0; i < wordsAmount; i++)
	{
		arr[i] = splittedInput[i];
	}
	int* arrayOfSizes = (int*)malloc(wordsAmount * sizeof(int));
	for (int i = 0; i < wordsAmount; i++)
	{
		arrayOfSizes[i] = wordsSizes(input)[i];
	}
	for (int i = 0; i < wordsAmount; i++)
	{
		for (int j = 0; j < wordsAmount; j++)
		{
			if (arrayOfSizes[j] > arrayOfSizes[i])
			{
				int x = arrayOfSizes[i];
				arrayOfSizes[i] = arrayOfSizes[j];
				arrayOfSizes[j] = x;
				char* tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
				
			}
		}
	}
	for (int i = 0; i < amountOfWords(input); i++)
	{
		printf_s("%s ", arr[i]);
	}

	free(input);
	for (int i = 0; i < wordsAmount; i++)
	{
		free(splittedInput);
	}
	free(splittedInput);
	free(arrayOfSizes);
	for (int i = 0; i < wordsAmount; i++)
	{
		free(arr);
	}
	for (int i = 0; i < wordsAmount; i++)
	{
		free(arr);
	}
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

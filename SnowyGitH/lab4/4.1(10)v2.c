//4.1 (10).v2 
//Морзянка. Вводимый с клавиатуры текст перевести в
//последовательность точек и тире с помощью азбуки Морзе.

#include <stdio.h>
#define size1  42
#define size2 10
#define size3 256

//To check the program use:
//THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG . , : ? ' /

void ReadFile(char arr[])
{
	FILE* file;
	errno_t err;
	err = fopen_s(&file, "MorseCode.txt", "r");
	char varChar;
	int i = 0, j = 0;
	while ((varChar = fgetc(file)) != EOF)
	{
		if (varChar != ' ' && varChar != '\n')
		{
			arr[i * size2 + j] = varChar;
			j++;
		}
		else if (varChar == '\n')
		{
			arr[i * size2 + j] = ' ';
			arr[i * size2 + j + 1] = '\0';
			i++;
			j = 0;
		}
	}
	fclose(file);
}
void PrintTranslated(char arr1[], char arr2[])
{
	printf_s("\nMorse code:\n");
	int i = 0;
	while (arr2[i] != '\0')
	{
		if (arr2[i] == ' ')
		{
			printf_s("/ ");
		}
		else
		{
			for (int j = 0; j < size1; j++)
			{
				if (arr2[i] == arr1[j * size2])
				{
					for (int q = 1; arr1[j * size2 + q] != '\0'; q++)
					{
						printf_s("%c", arr1[j * size2 + q]);
					}
					break;
				}
			}
		}
		i++;
	}
}

int main()
{
	char arr1[size1][size2];
	char arr2[size3];
	ReadFile(&arr1[0][0]);
	printf_s("Enter sentence(Eng and Caps only!):\n");
	gets_s(arr2, size3);
	PrintTranslated(&arr1[0][0], &arr2[0]);
	return 0;
}

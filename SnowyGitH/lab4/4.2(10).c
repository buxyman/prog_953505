//4.2 (10). 
//В одном файле дан исходный текст программы на языке С, в другом
//– словарь ключевых слов этого языка. Преобразовать текст, записав
//ключевые слова прописными буквами, а остальные – строчными.

#include <stdio.h>
#define len1 256
#define len2 256
#define len3 256
#define bool int
#define true 1
#define false 0

int main()
{
	char code[len1];
	char keywords[len2];
	char buff[len3];
	FILE* stream1;
	FILE* stream2;
	errno_t err;
	err = fopen_s(&stream1, "code.txt", "r");
	err = fopen_s(&stream2, "keywords.txt", "r");
	fgets(keywords, len2, stream2); 
	int i;
	bool isFound;
	bool isEmpty;
	while (fgets(code, len1, stream1))
	{
		i = 0;
		while (code[i] != '\0') //reads words to the end of the line
		{
			isFound = false;
			isEmpty = true;
			for (int j = 0; ; j++, i++) //reads a word
			{
				if (code[i] == ' ' || code[i] == '{' || code[i] == '}' || code[i] == '(' || code[i] == ')' || code[i] == '.'
					|| code[i] == '+' || code[i] == '-' || code[i] == '*' || code[i] == '/' || code[i] == '='
					|| code[i] == '#' || code[i] == '<' || code[i] == '>' || code[i] == '\0' || code[i] == '\t') //not all symbols are added!!
				{
					break;
				}
				buff[j] = code[i];
				buff[j + 1] = '\0';
				isEmpty = false;
			}
			for (int j = 0, k = 0; keywords[k] != '\0' && !isEmpty;) //looks if its a keyword
			{
				if (buff[j] == keywords[k])
				{
					j++;
					k++;
					isFound = true;
					if (buff[j] == '\0') //stops if this is a keyword
					{
						break;
					}
				}
				else //if not returns to the beginning of buff and looks for new keyword in array
				{
					isFound = false;
					j = 0;
					while (keywords[k] != ' ' && keywords[k] != '\0')
					{
						k++;
					}
					if (keywords[k] == '\0')
					{
						break;
					}
					k++;
				}
			}
			if (isFound)
			{
				for (int j = 0; buff[j] != '\0'; j++)
				{
					printf_s("%c", toupper(buff[j]));
				}
				if (code[i] != '\0')
				{
					printf_s("%c", code[i]);
					i++;
				}
			}
			else
			{
				if (!isEmpty)
				{
					printf_s("%s", buff);
				}
				if (code[i] != '\0')
				{
					printf_s("%c", code[i]);
					i++;
				}
			}
		}
	}
	fclose(stream1);
	fclose(stream2);
	return 0;
}

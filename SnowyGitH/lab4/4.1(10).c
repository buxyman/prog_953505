//4.1 (10). 
//Морзянка. Вводимый с клавиатуры текст перевести в
//последовательность точек и тире с помощью азбуки Морзе.

#include <stdio.h>
#define len 256

int main()
{
	char arr[len], ch;
	int i = 0;
	printf_s("Enter sentence(eng only!):\n");
	while ((ch = getchar()) != '\n')
	{
		if (ch == 'A' || ch == 'a')
		{
			arr[i] = '.';
			arr[i + 1] = '-';
			arr[i + 2] = ' ';
			arr[i + 3] = '\0';
			i += 3;
		}
		else if (ch == 'B' || ch == 'b')
		{
			arr[i] = '-';
			arr[i + 1] = '.';
			arr[i + 2] = '.';
			arr[i + 3] = '.';
			arr[i + 4] = ' ';
			arr[i + 5] = '\0';
			i += 5;
		}
		else if (ch == 'W' || ch == 'w')
		{
			arr[i] = '.';
			arr[i + 1] = '-';
			arr[i + 2] = '-';
			arr[i + 3] = ' ';
			arr[i + 4] = '\0';
			i += 4;
		}
		else if (ch == 'G' || ch == 'g')
		{
			arr[i] = '-';
			arr[i + 1] = '-';
			arr[i + 2] = '.';
			arr[i + 3] = ' ';
			arr[i + 4] = '\0';
			i += 4;
		}
		else if (ch == 'D' || ch == 'd')
		{
			arr[i] = '-';
			arr[i + 1] = '.';
			arr[i + 2] = '.';
			arr[i + 3] = ' ';
			arr[i + 4] = '\0';
			i += 4;
		}
		else if (ch == 'E' || ch == 'e')
		{
			arr[i] = '.';
			arr[i + 1] = ' ';
			arr[i + 2] = '\0';
			i += 2;
		}
		else if (ch == 'V' || ch == 'v')
		{
			arr[i] = '.';
			arr[i + 1] = '.';
			arr[i + 2] = '.';
			arr[i + 3] = '-';
			arr[i + 4] = ' ';
			arr[i + 5] = '\0';
			i += 5;
		}
		else if (ch == 'Z' || ch == 'z')
		{
			arr[i] = '-';
			arr[i + 1] = '-';
			arr[i + 2] = '.';
			arr[i + 3] = '.';
			arr[i + 4] = ' ';
			arr[i + 5] = '\0';
			i += 5;
		}
		else if (ch == 'I' || ch == 'i')
		{
			arr[i] = '.';
			arr[i + 1] = '.';
			arr[i + 2] = ' ';
			arr[i + 3] = '\0';
			i += 3;
		}
		else if (ch == 'J' || ch == 'j')
		{
			arr[i] = '.';
			arr[i + 1] = '-';
			arr[i + 2] = '-';
			arr[i + 3] = '-';
			arr[i + 4] = ' ';
			arr[i + 5] = '\0';
			i += 5;
		}
		else if (ch == 'K' || ch == 'k')
		{
			arr[i] = '-';
			arr[i + 1] = '.';
			arr[i + 2] = '-';
			arr[i + 3] = ' ';
			arr[i + 4] = '\0';
			i += 4;
		}
		else if (ch == 'L' || ch == 'l')
		{
			arr[i] = '.';
			arr[i + 1] = '-';
			arr[i + 2] = '.';
			arr[i + 3] = '.';
			arr[i + 4] = ' ';
			arr[i + 5] = '\0';
			i += 5;
		}
		else if (ch == 'M' || ch == 'm')
		{
			arr[i] = '-';
			arr[i + 1] = '-';
			arr[i + 2] = ' ';
			arr[i + 3] = '\0';
			i += 3;
		}
		else if (ch == 'N' || ch == 'n')
		{
		arr[i] = '-';
		arr[i + 1] = '.';
		arr[i + 2] = ' ';
		arr[i + 3] = '\0';
		i += 3;
		}
		else if (ch == 'O' || ch == 'o')
		{
		arr[i] = '-';
		arr[i + 1] = '-';
		arr[i + 2] = '-';
		arr[i + 3] = ' ';
		arr[i + 4] = '\0';
		i += 4;
		}
		else if (ch == 'P' || ch == 'p')
		{
		arr[i] = '.';
		arr[i + 1] = '-';
		arr[i + 2] = '-';
		arr[i + 3] = '.';
		arr[i + 4] = ' ';
		arr[i + 5] = '\0';
		i += 5;
		}
		else if (ch == 'R' || ch == 'r')
		{
		arr[i] = '.';
		arr[i + 1] = '-';
		arr[i + 2] = '.';
		arr[i + 3] = ' ';
		arr[i + 4] = '\0';
		i += 4;
		}
		else if (ch == 'S' || ch == 's')
		{
		arr[i] = '.';
		arr[i + 1] = '.';
		arr[i + 2] = '.';
		arr[i + 3] = ' ';
		arr[i + 4] = '\0';
		i += 4;
		}
		else if (ch == 'T' || ch == 't')
		{
		arr[i] = '-';
		arr[i + 1] = ' ';
		arr[i + 2] = '\0';
		i += 2;
		}
		else if (ch == 'U' || ch == 'u')
		{
		arr[i] = '.';
		arr[i + 1] = '.';
		arr[i + 2] = '-';
		arr[i + 3] = ' ';
		arr[i + 4] = '\0';
		i += 4;
		}
		else if (ch == 'F' || ch == 'f')
		{
		arr[i] = '.';
		arr[i + 1] = '.';
		arr[i + 2] = '-';
		arr[i + 3] = '.';
		arr[i + 4] = ' ';
		arr[i + 5] = '\0';
		i += 5;
		}
		else if (ch == 'H' || ch == 'h')
		{
		arr[i] = '.';
		arr[i + 1] = '.';
		arr[i + 2] = '.';
		arr[i + 3] = '.';
		arr[i + 4] = ' ';
		arr[i + 5] = '\0';
		i += 5;
		}
		else if (ch == 'C' || ch == 'c')
		{
		arr[i] = '-';
		arr[i + 1] = '.';
		arr[i + 2] = '-';
		arr[i + 3] = '.';
		arr[i + 4] = ' ';
		arr[i + 5] = '\0';
		i += 5;
		}
		else if (ch == 'Q' || ch == 'q')
		{
		arr[i] = '-';
		arr[i + 1] = '-';
		arr[i + 2] = '.';
		arr[i + 3] = '-';
		arr[i + 4] = ' ';
		arr[i + 5] = '\0';
		i += 5;
		}
		else if (ch == 'Y' || ch == 'y')
		{
		arr[i] = '-';
		arr[i + 1] = '.';
		arr[i + 2] = '-';
		arr[i + 3] = '-';
		arr[i + 4] = ' ';
		arr[i + 5] = '\0';
		i += 5;
		}
		else if (ch == 'X' || ch == 'x')
		{
		arr[i] = '-';
		arr[i + 1] = '.';
		arr[i + 2] = '.';
		arr[i + 3] = '-';
		arr[i + 4] = ' ';
		arr[i + 5] = '\0';
		i += 5;
		}
		else if (ch == '1')
		{
		arr[i] = '.';
		arr[i + 1] = '-';
		arr[i + 2] = '-';
		arr[i + 3] = '-';
		arr[i + 4] = '-';
		arr[i + 5] = ' ';
		arr[i + 6] = '\0';
		i += 6;
		}
		else if (ch == '2')
		{
		arr[i] = '.';
		arr[i + 1] = '.';
		arr[i + 2] = '-';
		arr[i + 3] = '-';
		arr[i + 4] = '-';
		arr[i + 5] = ' ';
		arr[i + 6] = '\0';
		i += 6;
		}
		else if (ch == '3')
		{
		arr[i] = '.';
		arr[i + 1] = '.';
		arr[i + 2] = '.';
		arr[i + 3] = '-';
		arr[i + 4] = '-';
		arr[i + 5] = ' ';
		arr[i + 6] = '\0';
		i += 6;
		}
		else if (ch == '4')
		{
		arr[i] = '.';
		arr[i + 1] = '.';
		arr[i + 2] = '.';
		arr[i + 3] = '.';
		arr[i + 4] = '-';
		arr[i + 5] = ' ';
		arr[i + 6] = '\0';
		i += 6;
		}
		else if (ch == '5')
		{
		arr[i] = '.';
		arr[i + 1] = '.';
		arr[i + 2] = '.';
		arr[i + 3] = '.';
		arr[i + 4] = '.';
		arr[i + 5] = ' ';
		arr[i + 6] = '\0';
		i += 6;
		}
		else if (ch == '6')
		{
		arr[i] = '-';
		arr[i + 1] = '.';
		arr[i + 2] = '.';
		arr[i + 3] = '.';
		arr[i + 4] = '.';
		arr[i + 5] = ' ';
		arr[i + 6] = '\0';
		i += 6;
		}
		else if (ch == '7')
		{
		arr[i] = '-';
		arr[i + 1] = '-';
		arr[i + 2] = '.';
		arr[i + 3] = '.';
		arr[i + 4] = '.';
		arr[i + 5] = ' ';
		arr[i + 6] = '\0';
		i += 6;
		}
		else if (ch == '8')
		{
		arr[i] = '-';
		arr[i + 1] = '-';
		arr[i + 2] = '-';
		arr[i + 3] = '.';
		arr[i + 4] = '.';
		arr[i + 5] = ' ';
		arr[i + 6] = '\0';
		i += 6;
		}
		else if (ch == '9')
		{
		arr[i] = '-';
		arr[i + 1] = '-';
		arr[i + 2] = '-';
		arr[i + 3] = '-';
		arr[i + 4] = '.';
		arr[i + 5] = ' ';
		arr[i + 6] = '\0';
		i += 6;
		}
		else if (ch == '0')
		{
		arr[i] = '-';
		arr[i + 1] = '-';
		arr[i + 2] = '-';
		arr[i + 3] = '-';
		arr[i + 4] = '-';
		arr[i + 5] = ' ';
		arr[i + 6] = '\0';
		i += 6;
		}
		else if (ch == '.')
		{
		arr[i] = '.';
		arr[i + 1] = '-';
		arr[i + 2] = '.';
		arr[i + 3] = '-';
		arr[i + 4] = '.';
		arr[i + 5] = '-';
		arr[i + 6] = ' ';
		arr[i + 7] = '\0';
		i += 7;
		}
		else if (ch == ',')
		{
		arr[i] = '-';
		arr[i + 1] = '-';
		arr[i + 2] = '.';
		arr[i + 3] = '.';
		arr[i + 4] = '-';
		arr[i + 5] = '-';
		arr[i + 6] = ' ';
		arr[i + 7] = '\0';
		i += 7;
		}
		else if (ch == ':')
		{
		arr[i] = '-';
		arr[i + 1] = '-';
		arr[i + 2] = '-';
		arr[i + 3] = '.';
		arr[i + 4] = '.';
		arr[i + 5] = '.';
		arr[i + 6] = ' ';
		arr[i + 7] = '\0';
		i += 7;
		}
		else if (ch == '?')
		{
		arr[i] = '.';
		arr[i + 1] = '.';
		arr[i + 2] = '-';
		arr[i + 3] = '-';
		arr[i + 4] = '.';
		arr[i + 5] = '.';
		arr[i + 6] = ' ';
		arr[i + 7] = '\0';
		i += 7;
		}
		else if (ch == '-')
		{
		arr[i] = '-';
		arr[i + 1] = '.';
		arr[i + 2] = '.';
		arr[i + 3] = '.';
		arr[i + 4] = '.';
		arr[i + 5] = '-';
		arr[i + 6] = ' ';
		arr[i + 7] = '\0';
		i += 7;
		}
		else if (ch == '/')
		{
		arr[i] = '-';
		arr[i + 1] = '.';
		arr[i + 2] = '.';
		arr[i + 3] = '-';
		arr[i + 4] = '.';
		arr[i + 5] = ' ';
		arr[i + 6] = '\0';
		i += 6;
		}
		else if (ch == ';')
		{
		arr[i] = '-';
		arr[i + 1] = '.';
		arr[i + 2] = '-';
		arr[i + 3] = '-';
		arr[i + 4] = '.';
		arr[i + 5] = '-';
		arr[i + 6] = ' ';
		arr[i + 7] = '\0';
		i += 7;
		}
		else if (ch == ' ')
		{
		arr[i] = '/';
		arr[i + 1] = ' ';
		arr[i + 2] = '\0';
		i += 2;
		}
	}
	printf_s("%s", arr);
	return 0;
}

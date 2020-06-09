#include <stdio.h>
#include "Blocks.h"
#include "Students.h"
#include <locale.h>
//============================= Вариант 2 ============================
void main()
{
	setlocale(LC_ALL, "rus");
	printf("Добро пожаловать!\nВнимание!!! Данная программа не поддерживает ввод на русском. Настоятельная просьба вводить текс, используя латиницу\n");
	Students_main();
	printf("Hello World");
}
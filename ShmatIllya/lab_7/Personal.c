#include "Personal.h"
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
void Personal_main()
{
    printf("----------------------------------------\n");
    printf("Внимание! Поскольку данный фрагмент программы писался автором в состоянии глубокой дипрессии и\nнедосыпания, вам придётся вручную вписывать все данные о персонале кроме их должностей.\nВажная ремарка: данный поступок со стороны автора вовсе не отражает его отношение к работе. Если бы автору\nплатили за его работу, то подобного никогда бы не случилось.\nБлагодарю за понимание автора.\n");
    srand(time(NULL));
    int choise;
    int radix=10;
    int a;
    printf("Однако вы можете выбрать другой вариант, а именно заполнить всё случайными числами. Выбор за вами.\n1.Путь боли\n2.Лёгкий путь\n");
 lm:   switch (getch())
    {
    case '1':
    {
        choise = 0;
        break;
    }
    case '2':
    {
        choise = 1;
        break;
    }
    default:
    {
        printf("Неверный ввод\n");
        goto lm;
    }
    }
    int counter = 0;
    for (int j = 0; j < 5; j++)
    {
        
        for (int i = 0; i < 10; i++)
        {
            switch (counter)
            {
            case 0:
            {
                strcpy_s(Array[j][i].profesion,100,"Заведующая");
                break;
            }
            case 1:
            {
                strcpy_s(Array[j][i].profesion,100, "Паспортистка");
                break;
            }
            case 2:
            {
                strcpy_s(Array[j][i].profesion,100, "Психолог");
                break;
            }
            case 3:
            {
                strcpy_s(Array[j][i].profesion,100, "Воспитатель");
                break;
            }
            case 4:
            {
                strcpy_s(Array[j][i].profesion,100, "Комендант");
                break;
            }
            case 5:
            {
                strcpy_s(Array[j][i].profesion,100, "Староста 1-ого этажа");
                break;
            }
            case 6:
            {
                strcpy_s(Array[j][i].profesion,100, "Староста 2-ого этажа");
                break;
            }
            case 7:
            {
                strcpy_s(Array[j][i].profesion,100, "Староста 3-его этажа");
                break;
            }
            case 8:
            {
                strcpy_s(Array[j][i].profesion,100, "Староста 4-ого этажа");
                break;
            }
            case 9:
            {
                strcpy_s(Array[j][i].profesion,100, "Староста 5-ого этажа");
                break;
            }
            }
            if (choise == 0)
            {
                printf("Введите имя служащего\n");
                scanf_s("%s", &Array[j][i].name, 100);
                printf("Введите фамилию служащего\n");
                scanf_s("%s", &Array[j][i].sername, 100);
                printf("Введите отчество служащего\n");
                scanf_s("%s", &Array[j][i].middle_name, 100);
                printf("Введите телефон служащего\n");
                scanf_s("%s", &Array[j][i].telephone, 100);
            }
            else
            {
                a = rand() % 100;
                _itoa_s(a, Array[j][i].name,100, radix);
                a = rand() % 100;
                _itoa_s(a, Array[j][i].sername,100, radix);
                a = rand() % 100;
                _itoa_s(a, Array[j][i].middle_name,100, radix);
                a = rand() % 100;
                _itoa_s(a, Array[j][i].telephone,100, radix);
            }
            counter++;

        }
        counter = 0;
    }
}
void Personal_Print(int status)
{
    if (status == 0)
    {
        Personal_main();
    }
    for (int j = 0; j < 5; j++)
    {
        printf("------------------------------\n");
        printf("Блок №%d:\n", j+1);
        for (int i = 0; i < 10; i++)
        {
            printf("%s: Фамилия: %s, Имя: %s, Отчество: %s, Телефон: %s\n", Array[j][i].profesion, Array[j][i].sername, Array[j][i].name, Array[j][i].middle_name, Array[j][i].telephone);
        }
    }
}

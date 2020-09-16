#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char surname[5][20] = { {"Ivanov"}, {"Petrov"}, {"Smirnov"}, {"Ctepanov"}, {"Alekseev"} };
    char holidays[4][30] = { {"happy Birthday"}, {"mary Christmas"}, {"happy New Year"}, {"Thanksgiving day"} };
    char congr[8][40] = { {"happiness"}, {"health"}, {"love"}, {"goodluck"}, {"longevities"}, {"execution of desires"}, {"best friends"}, {"a lot of money"} };
    srand((unsigned int)(time(NULL)));
    int sur, hol;
    sur = rand() % 5;
    hol = rand() % 4;
    printf_s("%s%s%s%s", surname[sur], ", I greet you with ", holidays[hol], ", I wish you ");
    int con;
    int temp[2][1];
    for (int i = 0; i < 3; i++)
    {
        con = rand() % 8;
        if (i == 0) {
            temp[i][0] = con;
        }
        else if (i == 1) {
            while (con == temp[0][0]) {
                con = rand() % 8;
            }
            temp[i][0] = con;
        }
        else
            if (i == 2) {
                while (con == temp[0][0] || con == temp[1][0]) {
                    con = rand() % 8;
                }
            }
        printf_s("%s", congr[con]);
        if (i == 2) {
            printf_s(".");
        }
        else printf_s(", ");
    }
    printf_s("\n");

}
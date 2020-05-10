#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get() {
    static char number[81] = "";
    char c = 'a';
    int kol = 0;
    while (1) {
        c = getchar();
        if (c == '\n') break;
        if (kol == 80) {
            puts("The input is too big, try again");
            while (c != '\n') c = getchar();
            return get(); 
        }
        number[kol++] = c;
    }
    if (kol == 0) {
        puts("String is empty, try again");
        return get();
    }
    number[kol] = '\0';
    return number;
}

char *get_string() {
    while (1) {
        char *number = get();
        if (number != NULL) {
            return number;
            break;    
        }
    }    
}

int valid(char *num) {
    int commas = 0; char *c;
    for (c = num; *c != '\0'; c++) {
        if (*c == ',') *c = '.';
        if (*c == '-' && c != num) {
            puts("symbol '-' in the middle of the string");
            return 0;
        }
        if (*c != '.' && (*c < '0' || *c > '9') && *c != '-') {
            puts("String contains restricted symbol(s)");
            return 0;
        }
        if (*c == '.') {
            commas++;
            if (commas == 2) {
                puts("String contains more than one decimal points");
                return 0;
            }
        }
    }
    return 1;
}

double get_double() {
    while(1) {
        char *num = get_string();
        if (valid(num)) {
            if ((int)strlen(num) > 14) {
                puts("the number is too big");
                continue;
            }
            return atof(num);
        }
    }
    return 0;
}

double get_udouble() {
    while(1) {
        char *num = get_string();
        if (num[0] == '-') {
            puts("the number must be positive");
            continue;
        }
        if (valid(num)) {
            if ((int)strlen(num) > 14) {
                puts("the number is too big");
                continue;
            }
            return atof(num);
        }
    }
    return 0;
}
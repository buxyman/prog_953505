#define CRT_SECURE_NO_WARNINGS_

#include <stdio.h>
#include <stdlib.h>

int searchLetter(char sym) {
    if (sym >= 65 && sym <= 90) {
        return 1;
    }
    else return 0;
}

int searchOperand(char sym) {
    if (sym == 42 || sym == 43 || sym == 45 || sym == 47) {
        return 1;
    }
    else return 0;
}

float strToNum(char* s) {
    float intp = 0;
    float flop = 0;

    int i = 0;
    int sign = 0;
    if (s[i] == '-')
    {
        sign = 1;
        i++;
    }
    while (s[i] >= 0x30 && s[i] <= 0x39)
    {
        intp += (s[i] & 0x0F);
        intp *= 10;
        i++;
    }
    intp /= 10;
    int j = 0;
    float temp;
    if (s[i] == '.' || s[i] == ',') {
        i++;
        while (s[i] >= 0x30 && s[i] <= 0x39)
        {
            j++;
            temp = s[i] & 0x0F;
            for (int f = 0; f < j; f++) {
                temp *= 0.1;
            }
            flop += temp;
            i++;
        }
    }

    intp += flop;

    if (sign == 1)
        intp = -intp;

    return intp;
}


int main() {
    errno_t err1, err2;
    FILE* Expr;
    err1 = fopen_s(&Expr, "expr.txt", "r");
    FILE* Value;
    err2 = fopen_s(&Value, "value.txt", "r");

    if (err1 == NULL) {
        printf("Не удалось открыть файл с выражениями\n");
        return 0;
    }

    if (err2 == NULL) {
        printf("Не удалось открыть файл со значениями\n");
        return 0;
    }

    char sym = '\0', lSym = '\0';
    char let[30];
    char* elet;
    float val = 0, result = 0;


    elet = fgets(let, sizeof(let), Expr);
    printf("%s", elet);
    fseek(Expr, 0, SEEK_SET);

    while (!feof(Expr)) {
        lSym = sym;
        sym = fgetc(Expr);

        if (searchLetter(sym)) {
            while (!feof(Value)) {
                elet = fgets(let, sizeof(let), Value);
                if (let[0] == sym && let[1] == '=') {
                    val = strToNum(&let[2]);
                    if (result == 0) {
                        result = val;
                    }
                }
            }
            fseek(Value, 0, SEEK_SET);
        }
        else if (searchOperand(sym)) {
            continue;
        }
        else if (sym == '=') {
            printf("%.2f%s", result, "\n");
        }
        else if (sym == '\xff') {
            continue;
        }
        else printf("неопознанный символ\n");

        if (searchOperand(lSym)) {
            if (lSym == '+') {
                result += val;
            }
            else if (lSym == '-') {
                result -= val;
            }
            else if (lSym == '*') {
                result *= val;
            }
            else if (lSym == '/') {
                if (val == 0) {
                    printf("нельязя делить на 0");
                    exit(0);
                }
                else result /= val;
            }
        }
    }

    fclose(Value);
    fclose(Expr);
    return 0;
}

// var 2

#include <stdio.h>
#include <Windows.h>
#include <math.h>
#define M_PI 3.14159265358979323846
void InArray(float val, int arr[], int pos) {
    if (val != 0) {
        arr[pos] = (int)val;
    }
    else {
        printf("Error");
        exit(1);
    }
}
void PrintMenu() {
    printf("1 - Enter numbers\n");
    printf("2 - Print numbers\n");
    printf("3 - Add number\n");
    printf("4 - Subtract numbers\n");
    printf("5 - Multiply numbers\n");
    printf("6 - Divide numbers\n");
    printf("7 - Harmonic mean\n");
    printf("8 - Info\n");
    printf("9 - Exit\n");
}
void EnterNumbers(int valArr[]) {
 
    float numerator = 0;
    float denominator = 0;
    printf("First number\nNumerator: ");
    scanf_s("%f", &numerator);
    printf("Denominator: ");
    scanf_s("%f", &denominator);
    InArray(numerator, valArr, 0);
    InArray(denominator, valArr, 1);
    numerator = 0;
    denominator = 0;
    printf("Second number\nNumerator: ");
    scanf_s("%f", &numerator);
    printf("Denominator: ");
    scanf_s("%f", &denominator);
    InArray(numerator, valArr, 2);
    InArray(denominator, valArr, 3);
}
void PrintNumber(int valArr[]) {
    if (valArr[1] == 0) {
        printf("Error");
        return;
    }
    printf("First number: \n");
    printf("%d\n", valArr[0]);
    printf("---------\n");
    printf("%d\n", valArr[1]);
    printf("Second number: \n");
    printf("%d\n", valArr[2]);
    printf("---------\n");
    printf("%d\n", valArr[3]);
}
void AddNumbers(int valArr[]) {
    if (valArr[1] == 0) {
        printf("Error");
        return;
    }
    float res = ((float)valArr[0] / (float)valArr[1]) + (float)((float)valArr[2] / (float)valArr[3]);
    printf("Numbers added: %f", res);
}
void SubtractNumbers(int valArr[]) {
    if (valArr[1] == 0) {
        printf("Error");
        return;
    }
    float res = ((float)valArr[0] / (float)valArr[1]) - (float)((float)valArr[2] / (float)valArr[3]);
    printf("Numbers subtracted: %f", res);
}
void MultiplyNumbers(int valArr[]) {
    if (valArr[1] == 0) {
        printf("Error");
        return;
    }
    int res;
    res = valArr[0] * valArr[2];
    printf("%d\n", res);
    res = valArr[1] * valArr[3];
    printf("-------\n");
    printf("%d\n", res);
}
void DivideNumbers(int valArr[]) {
    if (valArr[1] == 0) {
        printf("Error");
        return;
    }
    int res;
    res = valArr[0] * valArr[3];
    printf("%d\n", res);
    res = valArr[1] * valArr[2];
    printf("-------\n");
    printf("%d\n", res);
}
void HarmonicMean(int valArr[]) {
    if (valArr[1] == 0) {
        printf("Error");
        return;
    }

    float res = 2 * (float)valArr[0] / (float)valArr[1] * (float)valArr[2] / (float)valArr[3] / ((float)valArr[0] / (float)valArr[1]
        + (float)valArr[2] / (float)valArr[3]);
    printf("%f\n", res);
}
void assignment1() {
    const int arLen = 4;
    int* valArr = malloc(arLen * sizeof(int));
    valArr[1] = 0;
    int option;
    while (1) {
        PrintMenu();
        printf("Option: ");
        scanf_s("%d", &option);
        switch(option) {
        case 1:
            EnterNumbers(valArr);
            break;
        case 2:
            PrintNumber(valArr);
            break;
        case 3:
            AddNumbers(valArr);
            break;
        case 4:
            SubtractNumbers(valArr);
            break;  
        case 5:
            MultiplyNumbers(valArr);
            break;
        case 6:
            DivideNumbers(valArr);
            break;
        case 7:
            HarmonicMean(valArr);
            break;
        case 8:
            printf("Some info\n");
            break;
        case 9:
            return;
        default:
            break;

        }
        _getch();
        system("cls");
    }
}
int fact(int i) {
    if (i == 1) {
        return 1;
    }
    
    return i * fact(i - 1);
}
int RecAssigment2(double x, double sum, double epsilon,double sinX, int n,double toPower) {
    if (fabs(sinX - sum) < epsilon) {
        return n;
    }
    toPower = 1;
    for (double j = 1; j <= 2 * n - 1; j++) {
        toPower = toPower / j * x;
    }
    toPower *= pow(-1, n - 1);
    sum += toPower;
    printf("%Lf\n",sum);
    
    return RecAssigment2(x, sum, epsilon, sinX, n+=1,toPower);
}
void assignment2() {
    double  epsil;
    double  x;
    printf("x=");
    scanf_s("%Lf", &x);
    printf("epsilon=");
    scanf_s("%Lf", &epsil);
    long double funcX = 0;
    double fct;
    for (;x >= 2 * M_PI;) {
        x -= 2 * M_PI;
    }
    long double sinX = sin(x);
    long double toPower = 1;
    
    int recInt = RecAssigment2(x, 0, epsil, sinX, 1,1) - 1;
    
    
    for (int j = 0; j < 10000; j++) {
        for (int i = 1; fabs(sinX - funcX) > epsil; i++) {
            
            toPower = 1;
            for (double j = 1; j <= 2 * i - 1; j++) {
                toPower = toPower / j * x;
                
            }
            toPower *= pow(-1, i - 1);
            
            funcX += toPower;
            printf("Function: %.15Lf\n", funcX);

        }
        funcX - 0;
    }

    
}
int main()
{
    //assignment1();
    assignment2();
    return 0;
}

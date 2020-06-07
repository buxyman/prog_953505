//Task 4.1.13
/*Ввести с клавиатуры натуральное число n <= 1000 и символ,
указывающий падеж. Вывести на экран введенное число русскими
словами в заданном падеже.*/


#include <stdio.h>
#include <locale.h>
static char* sot[] = { "ст","дв","тр","четыре",
            "пят","шест", "сем","восем","девят" };
static char* desiat[] = { " двадцат"," тридцат"," сорок"," пят"," шест",
               " сем"," восем"," девя" };
static char* edm[] = { ""," од"," дв"," тр"," четыр"," пят"," шест",
            " сем"," восем",
            " девят"," десят"," одиннадцат"," двенадцат"," тринадцат",
            " четырнадцат"," пятнадцат"," шестнадцат"," семнадцат"," восемнадцат"," девятнадцат" };
static char* edw[] = { " одна"," две" };
long atol(char* b);

void ImenitelVinitelPadez(int L, int n, char* s) // Именительный & Винительный падежи
{
    int R, ns, nd;
    char* p;
    int M;
    M = L / 1000;
    R = L % 1000;
    if (M != 0) IP(M, n + 1, s); 
    if (R == 0) return;
    ns = R / 100;
    if (ns) sprintf_s(s + strlen(s), " %s", sot[ns - 1]);
    if (ns == 1) strcat(s, "o");
    if (ns == 2) strcat(s, "ести");
    if (ns == 3) strcat(s, "иста");
    if (ns == 4) strcat(s, "ста");
    if (ns >= 5) strcat(s, "ьсот");
    R = R % 100;  
    nd = R / 10;    
    if (nd >= 2) 
    {
        strcat(s, desiat[nd - 2]);
        if (nd == 2 || nd == 3) strcat(s, "ь");
        if (nd >= 5 && nd <= 8) strcat(s, "ьдесят");
        if (nd == 9) strcat(s, "носто");
        R = R % 10;
    }
    if (n == 1 && R > 0 && R < 3) p = edw[R - 1];
    else p = edm[R];
    strcat(s, p);
    if (R == 1) strcat(s, "ин");
    if (R == 2) strcat(s, "a");
    if (R == 3) strcat(s, "и");
    if (R == 4) strcat(s, "e");
    if (R > 4) strcat(s, "ь");    
}

void RoditelPadez(unsigned long L, int n, char* s) //Родительный падеж
{
    int R, ns, nd;
    char* p;
    unsigned long M;
    M = L / 1000;
    R = L % 1000;
    if (M != 0) RP(M, n + 1, s);
    if (R == 0) return;
    ns = R / 100;
    if (ns) sprintf_s(s + strlen(s), " %s", sot[ns - 1]);
    if (ns == 1) strcat(s, "а");
    if (ns == 2) strcat(s, "ухсот");
    if (ns == 3) strcat(s, "ехсот");
    if (ns == 4) strcat(s, "хсот");
    if (ns >= 5) strcat(s, "исот");
    R = R % 100;  
    nd = R / 10;      
    if (nd >= 2)
    {
        strcat(s, desiat[nd - 2]);
        if (nd == 2 || nd == 3) strcat(s, "и");
        if (nd == 4) strcat(s, "a");
        if (nd >= 5 && nd <= 8) strcat(s, "идесяти");
        if (nd == 9) strcat(s, "тидесяти");
        R = R % 10;
    }
    if (n == 1 && R > 0 && R < 3) p = edw[R - 1];
    else p = edm[R];
    strcat(s, p);
    if (R == 1) strcat(s, "ного");
    if (R == 2) strcat(s, "ух");
    if (R == 3  || R == 4) strcat(s, "ех"); 
    if (R > 4) strcat(s, "и");    
}

void DatelPadez(unsigned long L, int n, char* s) // Дательный падеж
{
    int R, ns, nd;
    char* p;
    unsigned long M;
    M = L / 1000;
    R = L % 1000;
    if (M != 0) DP(M, n + 1, s);
    if (R == 0) return;
    ns = R / 100;
    if (ns) sprintf_s(s + strlen(s), " %s", sot[ns - 1]);
    if (ns == 1) strcat(s, "ам");
    if (ns == 2) strcat(s, "ухстам");
    if (ns == 3) strcat(s, "ехстам");
    if (ns == 4) strcat(s, "хстам");
    if (ns >= 5) strcat(s, "исот");
    R = R % 100;
    nd = R / 10;
    if (nd >= 2)
    {
        strcat(s, desiat[nd - 2]);
        if (nd == 2 || nd == 3) strcat(s, "и");
        if (nd == 4) strcat(s, "a");
        if (nd >= 5 && nd <= 8) strcat(s, "идесяти");
        if (nd == 9) strcat(s, "тидесяти");
        R = R % 10;
    }
    if (n == 1 && R > 0 && R < 3) p = edw[R - 1];
    else p = edm[R];
    strcat(s, p);
    if (R == 1) strcat(s, "ному");
    if (R == 2) strcat(s, "ум");
    if (R == 3 || R == 4) strcat(s, "ем");
    if (R > 4) strcat(s, "и");    
}

void TvoritelPadez(unsigned long L, int n, char* s) // Творительный падеж
{
    int R, ns, nd;
    char* p;
    unsigned long M;
    M = L / 1000;
    R = L % 1000;
    if (M != 0) TP(M, n + 1, s);
    if (R == 0) return;
    ns = R / 100;
    if (ns) sprintf_s(s + strlen(s), " %s", sot[ns - 1]);
    if (ns == 1) strcat(s, "о");
    if (ns == 2) strcat(s, "ухстами");
    if (ns == 3) strcat(s, "ехстами");
    if (ns == 4) strcat(s, "хстами");
    if (ns >= 5) strcat(s, "истами");
    R = R % 100;
    nd = R / 10;
    if (nd >= 2)
    {
        strcat(s, desiat[nd - 2]);
        if (nd == 2 || nd == 3) strcat(s, "ью");
        if (nd == 4) strcat(s, "a");
        if (nd >= 5 && nd <= 8) strcat(s, "идесятью");
        if (nd == 9) strcat(s, "тидесятью");
        R = R % 10;
    }
    if (n == 1 && R > 0 && R < 3) p = edw[R - 1];
    else p = edm[R];
    strcat(s, p);
    if (R == 1) strcat(s, "ним");
    if (R == 2) strcat(s, "умя");
    if (R == 3) strcat(s, "емя");
    if (R == 4) strcat(s, "ьмя");
    if (R > 4) strcat(s, "ью");
}

void PredlozPadez(unsigned long L, int n, char* s) // Предложный падеж
{
    int R, ns, nd;
    char* p;
    unsigned long M;
    M = L / 1000;
    R = L % 1000;
    if (M != 0) PP(M, n + 1, s);
    if (R == 0) return;
    ns = R / 100;
    if (ns) sprintf_s(s + strlen(s), " %s", sot[ns - 1]);
    if (ns == 1) strcat(s, "ах");
    if (ns == 2) strcat(s, "ухстах");
    if (ns == 3) strcat(s, "ехстах");
    if (ns == 4) strcat(s, "хстах");
    if (ns >= 5) strcat(s, "истах");
    R = R % 100;
    nd = R / 10;
    if (nd >= 2)
    {
        strcat(s, desiat[nd - 2]);
        if (nd == 2 || nd == 3) strcat(s, "и");
        if (nd == 4) strcat(s, "a");
        if (nd >= 5 && nd <= 8) strcat(s, "идесяти");
        if (nd == 9) strcat(s, "тидесяти");
        R = R % 10;
    }
    if (n == 1 && R > 0 && R < 3) p = edw[R - 1];
    else p = edm[R];
    strcat(s, p);
    if (R == 1) strcat(s, "ном");
    if (R == 2) strcat(s, "ух");
    if (R == 3 || R == 4) strcat(s, "ех");
    if (R > 4) strcat(s, "и");
}

int Pad(int o) //выбор падежа
{
    o = 0;
    printf_s("Выберите падеж:\n 1.Именительный\n 2.Родительный\n 3.Дательный\n 4.Винительный\n 5.Творительный\n 6.Предложный\n \nпадеж: ");
    scanf_s("%d", &o);
    if (o > 6)
    {
        printf_s("\nОшибка. Выберите другой падеж\n\n");
        return Pad(o);
    }
    return o;
}

void main()
{
    setlocale(LC_ALL, "Rus");
    char b[200], s[1000]; 
    int L;    
    int choice = 0;
    printf("Число: ");
    gets(b);
    if (strlen(b) == 0) return;
    s[0] = '\0';
    L = atol(b);    
    switch (Pad(choice))
    {
    case 1:
        ImenitelVinitelPadez(L, 0, s);
        printf("%s\n", s);
        break;
    case 2:
        RoditelPadez(L, 0, s);
        printf("%s\n", s);
        break;
    case 3:
        DatelPadez(L, 0, s);
        printf("%s\n", s);
        break;
    case 4:
        ImenitelVinitelPadez(L, 0, s);
        printf("%s\n", s);
        break;
    case 5:
        TvoritelPadez(L, 0, s);
        printf("%s\n", s);
        break;
    case 6:
        PredlozPadez(L, 0, s);
        printf("%s\n", s);
        break;
    }
}

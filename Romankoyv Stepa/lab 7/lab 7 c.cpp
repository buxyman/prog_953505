#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "BuyerDataBase.h"
#include "CarDataBase.h"

int currenYear = 2020;

CarBase* Car = NULL;
BuyerBase* Buyer = NULL;

float makeFullPrice(CarBase* itm)
{
    float fPrice = 250, tam = 0;

    if (currenYear - itm->year < 0)
    {
        printf("Невернно введены данные(год производства автомобиля или текущий год)\n");
        return 0;
    }
    else if (currenYear - itm->year <= 3)
    {
        tam = 0.6 * itm->engineVolume;
    }
    else if (currenYear - itm->year <= 10)
    {
        if (itm->engineVolume < 2500)
            tam = 0.35 * itm->engineVolume;
        else
            tam = 0.6 * itm->engineVolume;
    }
    else if (currenYear - itm->year < 14)
    {
        tam = 0.6 * itm->engineVolume;
    }
    else
    {
        tam = 2 * itm->engineVolume;
    }

    fPrice += tam;

    return fPrice;
}
CarBase* showSelOption(CarBase* head, BuyerBase* first, char* name)
{
    int i = 0;
    BuyerBase* temp = first;
    CarBase* tmp = head;
    CarBase* selOp = NULL;
    char dBrand[15] = { "\0" };
    int mPrice = 0;
    while (temp)
    {
        if (!strcmp(temp->name, name))
        {
            for (i = 0; temp->desiredBrand[i] != '\0'; i++) {
                dBrand[i] = temp->desiredBrand[i];
            }
            mPrice = temp->maxPrice;
            break;
        }
        temp = temp->next;
    }

    while (tmp)
    {
        if (!strcmp(tmp->brand, dBrand))
        {
            if (1.15 * (tmp->price + makeFullPrice(tmp)) <= mPrice)
            {
                selOp = addByStep(tmp->brand, tmp->year, tmp->engineVolume, tmp->state, tmp->price, selOp);
                tmp = tmp->next;
            }
        }
        tmp = tmp->next;
    }
    return selOp;
}


int main() {
    system("chcp1251");
    system("cls");

    int res, f, state, year, enV, price, num, i = 0, a, b, cou = 0;
    double income = 0;
    char brand[15] = { "\0" }, name[60] = { "\0" }, email[30] = { "\0" };
    char* ptr, * ptrmail, * ptrdB;
    CarBase* tmp = NULL, * s = NULL, * temp = NULL;
    Contacts con;
    CarBase* selOp;
    FILE* fCar;
    FILE* fBuyer;
    CarBase* addit;
    fCar = fopen("CarDataBase.txt", "r");
    fBuyer = fopen("BuyerDataBase.txt", "r");
    if (fCar == NULL) {
        printf("wrong 1\n");
        return 1;
    }

    if (fBuyer == NULL) {
        printf("Wrong 2\n");
        return 1;
    }
    while (true) {
        printf("\t\t\tMENU:\n1)Download car base\n2)Download buyers base\n3)Serch in car base\n4)Serch car\n5)Finding of variants\n6)Creating a request for a supplier\n7)Calculating the company's profit\n8)Exit\n");
        res = scanf("%d", &f);
        if (!res)
        {
            printf("You must enter an integer. Try again. \n");
            return 0;
        }
        switch (f) {
        case 1:
            while (!feof(fCar)) {
                ptr = fgets(brand, sizeof(brand), fCar);
                if (ptr[0] == '\n')
                    continue;
                ptr[strcspn(ptr, "\n")] = '\0';
                fscanf(fCar, "%d", &year);
                fscanf(fCar, "%d", &enV);
                fscanf(fCar, "%d", &state);
                if (state == 1)
                    state = 1;
                else
                    state = 0;
                fscanf(fCar, "%d", &price);
                addit = (CarBase*)calloc(1, sizeof(CarBase));
                if (!addit) {
                    printf("Ошибка выделения памяти.\n");
                }
                for (i = 0; ptr[i] != '\0'; i++)
                    addit->brand[i] = ptr[i];
                addit->year = year;
                addit->engineVolume = enV;
                addit->state = state;
                addit->price = price;
                Car = add(addit, Car);
                ptr = NULL;
            }
            tmp = Car;
            show(Car);
            break;
        case 2:
            while (!feof(fBuyer)) {
                ptr = fgets(name, sizeof(name), fBuyer);
                ptr[strcspn(ptr, "\n")] = '\0';
                fscanf(fBuyer, "%d", &num);
                ptrmail = fgets(email, sizeof(email), fBuyer);
                if (ptrmail[0] == '\n') {
                    ptrmail[strcspn(ptrmail, "\n")] = '\0';
                    ptrmail = fgets(email, sizeof(email), fBuyer);
                }
                ptrmail[strcspn(ptrmail, "\n")] = '\0';
                ptrdB = fgets(brand, sizeof(brand), fBuyer);
                ptrdB[strcspn(ptrdB, "\n")] = '\0';
                fscanf(fBuyer, "%d", &year);
                fscanf(fBuyer, "%d", &state);
                if (state == 1)
                    state = 1;
                else
                    state = 0;
                fscanf(fBuyer, "%d", &price);
                con.number = num;
                for (i = 0; ptrmail[i] != '\0'; i++)
                    con.email[i] = ptrmail[i];
                Buyer = addBuyer(ptr, con, ptrdB, year, state, price, Buyer);
                ptr = fgets(name, sizeof(name), fBuyer);
                ptr = NULL;
            }
            showBuyer(Buyer);
            break;
        case 3:

            if (!Car)
            {
                printf_s("Carbase is empty.\n");
                break;
            }
            printf("serch:\n1)Brand\n2)release year\n3)Engine capacity\n4)The condition of the car\n5)Price\n");
            b = scanf("%d", &a);
            if (!b)
            {
                printf("You must enter an integer. Try again. \n");
                return 0;
            }
            s = NULL;
            s = search(Car, a);
            printf("\n");
            show(s);
            break;
        case 4:
            if (!Car)
            {
                printf("Carbase is empty.\n");
                break;
            }
            printf("Sort by:\n1)Price\n2)Release year\n");
            res = scanf("%d", &f);
            if (!res)
            {
                printf("You must enter an integer. Try again. \n");
                return 0;
            }
            cou = count(Car);
            if (f <= 1)
            {
                temp = NULL;
                Car = sortPrice(Car, temp, cou);
                show(temp);
            }
            else if (f >= 2)
            {
                temp = NULL;
                temp = sortYear(Car, temp, cou);
                show(temp);
            }
            break;
        case 5:
            if (!Car)
            {
                printf("Carbase us empty.\n");
                break;
            }
            if (!Buyer)
            {
                printf("Buyersbase is empty.\n");
                break;
            }
            printf("Enter the buyr: ");
            fflush(stdin);
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';
            selOp = showSelOption(Car, Buyer, name);
            printf("\n");
            if (!selOp) {
                printf("Wrong.\n");
                break;
            }
            show(selOp);
            break;
        case 6:
            if (!Car) {
                printf("Carbase is empty.\n");
                break;
            }
            tmp = Car;
            printf("The compani Atlant-M want to buy car: ");
            while (tmp)
            {
                if (!tmp->next) {
                    printf("%s%s", tmp->brand, ". ");
                    break;
                }
                printf("%s%s", tmp->brand, ", ");
                tmp = tmp->next;
            }
            break;
        case 7:
            if (!Car) {
                printf("Carbase is empty.\n");
                break;
            }
            tmp = Car;
            income = 0;
            while (tmp)
            {
                income += tmp->price + makeFullPrice(tmp);
                tmp = tmp->next;
            }
            income *= 0.15;
            printf("%s%.2f%s", "Company gain: \n", income, " ye\n");
            break;
        default:
            printf("closing.\n");
            delAll(Car);
            delAllBuyer(Buyer);
            return 0;
            break;
        }
    }

    return 0;
}
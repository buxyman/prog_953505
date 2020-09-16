#define _CRT_SECURE_NO_WARNINGS

#include "CarDataBase.h"

CarBase* addByStep(char* b, int y, int enV, int st, int p, CarBase* head)
{
    int i = 0;
    CarBase* newItem = (CarBase*)calloc(1, sizeof(CarBase));
    if (!newItem)
    {
        printf("Wrong\n");
        return NULL;
    }
    for (i = 0; b[i] != '\0'; i++)
        newItem->brand[i] = b[i];
    newItem->year = y;
    newItem->engineVolume = enV;
    if (st == 1)
        newItem->state = 1;
    else newItem->state = 0;
    newItem->price = p;
    if (!head)
    {
        head = newItem;
    }
    else
    {
        CarBase* current = head;
        for (i = 1; current->next != NULL; i++)
            current = current->next;
        if (current->next)
        {
            current->next->prev = newItem;
        }
        newItem->next = current->next;
        current->next = newItem;
        newItem->prev = current;
        current = newItem;
    }
    return head;
}

CarBase* add(CarBase* newItem, CarBase* head)
{
    int i = 0;
    if (!head)
    {
        head = newItem;
    }
    else
    {
        CarBase* current = head;
        for (i = 1; current->next != NULL; i++)
            current = current->next;
        if (current->next)
        {
            current->next->prev = newItem;
        }
        newItem->next = current->next;
        current->next = newItem;
        newItem->prev = current;
        current = newItem;
    }
    return head;
}

CarBase* search(CarBase* head, int num)
{
    CarBase* temp = head;
    CarBase* tmp = NULL;
    char tmpStr[15];
    int tmpNum = 0;
    bool st;
    switch (num) {
    case 1:
        printf("Enter the brand: ");
        scanf("%s", tmpStr);
        while (temp) {
            if (!strcmp(temp->brand, tmpStr)) {
                tmp = addByStep(temp->brand, temp->year, temp->engineVolume, temp->state, temp->price, tmp);
                temp = temp->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        return tmp;
        break;
    case 2:
        printf("Enter the year: ");
        scanf("%d", &tmpNum);
        while (temp) {
            if (tmpNum == temp->year) {
                tmp = addByStep(temp->brand, temp->year, temp->engineVolume, temp->state, temp->price, tmp);
                temp = temp->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        return tmp;
        break;
    case 3:
        printf("Enter the engine capacity: ");
        scanf("%d", &tmpNum);
        while (temp) {
            if (tmpNum == temp->engineVolume) {
                tmp = addByStep(temp->brand, temp->year, temp->engineVolume, temp->state, temp->price, tmp);
                temp = temp->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        return tmp;
        break;
    case 4:
        printf("Enter the condition of the car:\n1)new\t2)\old\n ");
        scanf("%d", &tmpNum);
        if (tmpNum == 1) {
            st = 1;
        }
        else st = 0;
        while (temp) {
            if (st == temp->state) {
                tmp = addByStep(temp->brand, temp->year, temp->engineVolume, temp->state, temp->price, tmp);
                temp = temp->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        return tmp;
        break;
    case 5:
        printf("Enter the price: ");
        scanf("%d", &tmpNum);
        while (temp) {
            if (tmpNum == temp->price) {
                tmp = addByStep(temp->brand, temp->year, temp->engineVolume, temp->state, temp->price, tmp);
                temp = temp->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        return tmp;
        break;

    default:
        printf("try again.\n");
        return NULL;
        break;
    }
}

CarBase* sortPrice(CarBase* head, CarBase* buff, int right)
{
    int i = 0, j = 0, t = 0;
    CarBase* tmp = (CarBase*)calloc(1, sizeof(CarBase));
    buff = head;
    if (!tmp)
    {
        printf("wrong\n");
        return NULL;
    }
    for (i = 0; i < right - 1; i++)
    {
        for (j = 0; j < right - i - 1; buff = buff->next, j++)
        {
            if (buff->price > buff->next->price)
            {
                for (t = 0; buff->brand[t] != '\0'; t++)
                    tmp->brand[t] = buff->brand[t];
                memset(buff->brand, 0, 15);
                tmp->year = buff->year;
                tmp->engineVolume = buff->engineVolume;
                tmp->state = buff->state;
                tmp->price = buff->price;
                for (t = 0; buff->next->brand[t] != '\0'; t++)
                    buff->brand[t] = buff->next->brand[t];
                memset(buff->next->brand, 0, 15);
                buff->year = buff->next->year;
                buff->engineVolume = buff->next->engineVolume;
                buff->state = buff->next->state;
                buff->price = buff->next->price;
                for (t = 0; tmp->brand[t] != '\0'; t++)
                    buff->next->brand[t] = tmp->brand[t];
                memset(tmp->brand, 0, 15);
                buff->next->year = tmp->year;
                buff->next->engineVolume = tmp->engineVolume;
                buff->next->state = tmp->state;
                buff->next->price = tmp->price;
            }
        }
        buff = head;
    }
    return buff;
}

CarBase* sortYear(CarBase* head, CarBase* buff, int right)
{
    int i = 0, j = 0, t = 0;
    CarBase* tmp = (CarBase*)calloc(1, sizeof(CarBase));
    buff = head;
    if (!tmp)
    {
        printf("wrong\n");
        return NULL;
    }
    for (i = 0; i < right - 1; i++)
    {
        for (j = 0; j < right - i - 1; buff = buff->next, j++)
        {
            if (buff->year > buff->next->year)
            {
                for (t = 0; buff->brand[t] != '\0'; t++)
                    tmp->brand[t] = buff->brand[t];
                memset(buff->brand, 0, 15);
                tmp->year = buff->year;
                tmp->engineVolume = buff->engineVolume;
                tmp->state = buff->state;
                tmp->price = buff->price;
                for (t = 0; buff->next->brand[t] != '\0'; t++)
                    buff->brand[t] = buff->next->brand[t];
                memset(buff->next->brand, 0, 15);
                buff->year = buff->next->year;
                buff->engineVolume = buff->next->engineVolume;
                buff->state = buff->next->state;
                buff->price = buff->next->price;
                for (t = 0; tmp->brand[t] != '\0'; t++)
                    buff->next->brand[t] = tmp->brand[t];
                memset(tmp->brand, 0, 15);
                buff->next->year = tmp->year;
                buff->next->engineVolume = tmp->engineVolume;
                buff->next->state = tmp->state;
                buff->next->price = tmp->price;
            }
        }
        buff = head;
    }
    return buff;
}

void show(CarBase* head)
{
    if (head)
    {
        printf("%s%s%s", "Brand: ", head->brand, "\n");
        printf("%s%d%s", "Year: ", head->year, "\n");
        printf("%s%d%s", "Engine volume : ", head->engineVolume, "\n");
        if (head->state == 1)
        {
            printf("The condition of the car: new\n");
        }
        else printf("The condition of the car: old\n");
        printf("%s%d%s", "price: ", head->price, "\n");
        printf("\n");
        show(head->next);
    }
    else printf("\n");
}

int count(CarBase* head)
{
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

void delAll(CarBase* head)
{
    if (head) {
        delAll(head->next);
        free(head);
    }
}
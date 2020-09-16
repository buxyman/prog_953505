#define _CRT_SECURE_NO_WARNINGS

#include "BuyerDataBase.h"

BuyerBase* addBuyer(char* n, Contacts c, char* dB, int y, int st, int mP, BuyerBase* head)
{
    system("chcp1251");
    system("cls");
    int i = 0;
    BuyerBase* newItem = (BuyerBase*)calloc(1, sizeof(BuyerBase));
    if (!newItem)
    {
        printf("������ ��������� ������\n");
        return NULL;
    }
    for (i = 0; n[i] != '\0'; i++)
        newItem->name[i] = n[i];
    newItem->contact = c;
    for (i = 0; dB[i] != '\0'; i++)
        newItem->desiredBrand[i] = dB[i];
    newItem->year = y;
    if (st == 1)
        newItem->state = 1;
    else newItem->state = 0;
    newItem->maxPrice = mP;
    if (!head)
    {
        head = newItem;
    }
    else
    {
        BuyerBase* current = head;
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

void showBuyer(BuyerBase* head)
{
    if (head)
    {
        printf("%s%s%s", "���: ", head->name, "\n");
        printf("%s%d%s%s%s", "�������: ", head->contact.number, "\n�����: ", head->contact.email, "\n");
        printf("%s%s%s", "�������� �����: ", head->desiredBrand, "\n");
        printf("%s%d%s", "���: ", head->year, "\n");
        if (head->state == 1)
        {
            printf("C�������� ����������: �����\n");
        }
        else printf("C�������� ����������: �/�\n");
        printf("%s%d%s", "���������� �����������: ", head->maxPrice, "\n");
        printf("\n");
        showBuyer(head->next);
    }
    else printf("\n");
}

void delAllBuyer(BuyerBase* head)
{
    if (head) {
        delAllBuyer(head->next);
        free(head);
    }
}

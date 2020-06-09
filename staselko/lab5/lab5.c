#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListItem {
    struct ListItem *next;
    struct ListItem *prev;
    char ch;
};

void addChar(struct ListItem **list, char ch) {
    struct ListItem *head = (struct ListItem*)calloc(1, sizeof(struct ListItem));
    head->ch = ch;
    if(*list) {
        (*list)->prev = head;
    }
    head->prev = NULL;
    head->next = *list;
    *list = head;
}

void createList(struct ListItem **list, char *string) {
    unsigned long i, j;
    i = 0;
    j = strlen(string) - 1;
     while (i < j) {
        while (!((string[i] >= 'a' && string[i] <= 'z') ||
                 (string[i] >= 'A' && string[i] <= 'Z')) && i < j) {
            i++;
        }
        while (!((string[j] >= 'a' && string[j] <= 'z') ||
                 (string[j] >= 'A' && string[j] <= 'Z')) && i < j) {
            j--;
        }
        addChar(list, string[i]);
        addChar(list, string[j]);
        i++;
        j--;
    }
}

int isPalindrome(struct ListItem *list) {
    if (!list) return 0;
    while (list) {
        if (list->ch != list->next->ch) return 0;
        list = list->next->next;
    }
    return 1;
}

void deleteList(struct ListItem *list) {
    while(list) {
        struct ListItem *temp = list;
        list = list->next;
        free(temp);
    }
}

int main(void) {
    char *string;
    struct ListItem *list = NULL;
    printf("Program checks whether the string is a palindrome\n"
           "Enter a string:\n");
    scanf("%[^\n]s", string);
    createList(&list, string);
    if (isPalindrome(list)) {
        printf("The string is a palindrome!\n");
    } else {
        printf("The string is not a palindrome!\n");
    }
    deleteList(list);
    return 0;
}


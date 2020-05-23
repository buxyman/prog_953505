/*Пользователь вводит с клавиатуры слово. Найти в файле-словаре
все слова, в которых использованы только буквы введенного слова.*/
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define vocabulary_size 100
int main()
{
    int counter = 0;
    char *word;
    word = (char*)malloc(100 * sizeof(char));
    
    int* alphabet;
    alphabet = (int*)malloc(512 * sizeof(int));
    
    char* filepath = "C:\\Users\\Lenovo\\Desktop\\vocabulary.txt";
    FILE* vocabulary;
    fopen_s(&vocabulary, filepath, "r");
    
    printf("Enter your word: ");
    fgets(word, 100, stdin);
    
    for (int i = 0; i < 125; i++)
    {
        alphabet[i] = 0;
    }
    for (int i = 0; i < strlen(word); i++)
    {
        alphabet[word[i]] = 1;
    }
    for (int i = 0; i < 1000; i++)
    {
        int found = 1;
        char temp[vocabulary_size];
        fgets(temp, vocabulary_size, vocabulary);
        for (int j = 0; j < strlen(temp) - 1; j++)
        {
            if (alphabet[temp[j]] == 0)
            {
                found = 0;
                break;
            }
        }
        if (found) 
        {
            counter++;
            printf("%s", temp);
        }
    }
    printf("\nNumber of found words: %d", counter);
    free(word);
    free(alphabet);
    return 0;
}

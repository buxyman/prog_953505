/*26. В слове угаданы некоторые буквы. Пользователь
вводит «шаблон» слова, заменяя неизвестные буквы знаком
подчеркивания. Компьютер из файла-словаря выбирает все слова,
удовлетворяющие этому шаблону.*/

#include <stdio.h>

int main()
{
    printf("Input example of your word:\n");
    char pattern[10];
    scanf_s("%s", pattern);
    char words[10][10] = {
        "mommy", "lake", "sea", "rainbow", "cake", "veronika", "value", "joke", "family" };
    printf("Similar:\n");
    int i, k;
    int equal;
    for (i = 0; i < 10; i++)
    {
        equal = 1;
        for (k = 0; pattern[k] && words[i][k] && equal; k++)
        {
            if (pattern[k] == '_')
            {
                continue;
            }
            if (pattern[k] != words[i][k])
            {
                equal = 0;
            }
        }
        if (pattern[k] || words[i][k])
        {
            equal = 0;
        }
        if (equal > 0)
        {
            printf("%s\n", words[i]);
        }
    }

    return 0;
}
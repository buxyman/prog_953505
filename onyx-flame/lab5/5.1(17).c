//IDE: CodeBlocks
//Task 5.1(17)
/*
Даны два упорядоченных стека, в которых могут быть одинаковые
элементы. Разработать функцию создания одного общего
упорядоченного стека, исключив повторяющиеся элементы.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

void change(char** a, char** b)
{
    char* temp = *a;
    *a =  *b;
    *b = temp;
}

typedef struct node     //структура узла стека
{
    int data;   //содержимое узла - число
    struct node* pNext;     //указатель на следующий элемент
} Node;

typedef struct stack    //структура стека
{
    Node* head;     //указатель на вершину стека
    int count;      //количество элементов в стеке
} Stack;

Stack* CreateStack()    //инициализация стека
{
    Stack* temp = (Stack*)malloc(sizeof(Stack));    //выделение памяти
    temp->head = NULL;      //устанавливаем нулевой указатель на вершины
    temp->count = 0;    //зануляем счетчик элементов
}

void Push(Stack* st, int x)     //добавление элемента в стек
{
    Node* temp = (Node*)malloc(sizeof(Node));   //выделение памяти для нового элемента
    temp->data = x;     //заполнение узла информацией-числом
    temp->pNext = st->head; //указатель pNext указывает на текущую вершину стека
    st->head = temp;    //temp объявляем новой вершиной стека
    st->count++;    //инкрементируем счетчик
}

void Pop(Stack* st)     //удаление элемента из стека
{
    Node* temp = st->head;      //устанавливаем указатель на текущую вершину
    st->head = st->head->pNext;    //элемент, стоящий после текущей вершины, объявляем новой вершиной
    free(temp);     //освобождаем память старой вершины
    st->count--;    //декрементируем счетчик
}

int Peek(Stack* st) //считывание элемента с вершины стека
{
    return st->head->data;
}

void Print(Stack* st) //печать стека
{
    Node* temp = st->head; //объявление "временного" указателя на вершину
    while(temp != NULL)     //пока указатель указывает на какую-либо выделенную память
    {
        printf("%d ", temp->data);      //печатаем содержимое узла
        temp = temp->pNext;     //сдвигаем указатель вперед
    }
    printf("\n");
}

int StrCmp(char* str1, char* str2) //функция для сравнения двух чисел в виде двух строк
{                                  //возвращает 1, если первое больше второго; -1, если второе больше первого; 0, если числа равны
    int iStart = 0;     //начальное значение при условии, что число положительное
    if(str1[0] == '-' && str2[0] != '-')    //если первое со знаком "-", а второе без, возврат -1
    {
        return -1;
    }
    else if(str1[0] != '-' && str2[0] == '-')   //если второе со знаком "-", а первое без, возврат 1
    {
        return 1;
    }
    else if(str1[0] == '-' && str2[0] == '-')   //если оба числа отрицательные, устанавливаем индекс для начала сравнения чисел
    {
        iStart = 1;
    }
    if(strlen(str1) > strlen(str2)) //сравнение чисел по длине, если длина первой строке больше второй
    {
        if(iStart == 0) return 1;   //если индекс i равен 0(число положительное), возврат 1
        if(iStart == 1) return -1;  //если индекс i равен 1(число отрицательное), возврат -1
    }
    if(strlen(str1) < strlen(str2)) //сравнение чисел по длине, если длина второй строке больше первой
    {
        if(iStart == 0) return -1;  //если индекс i равен 0(число положительное), возврат -1
        if(iStart == 1) return 1;   //если индекс i равен 1(число отрицательное), возврат 1
    }
    int counter = 0;    //счетчик соответствия
    for(int i = iStart; i<strlen(str1); i++) //посимвольное сравнение строк
    {
        if(str1[i] == str2[i])  //если char-ы равны
        {
            counter++;  //инкрементируем счетчик
            continue;
        }
        else if(str1[i] > str2[i]) //если первый символ первой строки больше символа из второй строки
        {
            if(iStart == 0) return 1;   //если числа положительные, возврат 1
            if(iStart == 1) return -1;  //если числа отрицательные, возврат -1
            continue;
        }
        else if(str1[i] < str2[i])  //если первый символ первой строки меньше символа из второй строки
        {
            if(iStart == 0) return -1;  //если числа положительные, возврат -1
            if(iStart == 1) return 1;   //если числа отрицательные, возврат 1
        }
    }
    if(counter == strlen(str1) - iStart) return 0;  //если абсолютно все цифры строк одинаковы, возвращаем 0
}

char* CheckString(char* temp)   //проверка строки; функция удаляет лишние нули перед числом(-000012 -> -12)
{                               //и возвращает указатель на исправленное число, а если строка не является числом, возвращает нулевой указатель
    int iStart, counter = 0;
    if(temp[0] == '-')  //если число отрицательное
    {
        iStart = 1; //цикл проверки начинаем с 1
    }
    else if(isdigit(temp[0])) //если первый символ - цифра
    {
        iStart = 0; //иначе цикл начнем с 0
    }
    else    //иначе
    {
        return NULL;    //возврат нулевого указателя
    }
    for(int i=iStart; i<strlen(temp); i++)  //проверка числа
    {
        if(!isdigit(temp[i])) return NULL; //если символ - не цифра, возврат NULL
        if(i == iStart && temp[1] == '0') //считаем лишние нули перед основной частью числа
        {
            while(temp[i] == '0')
            {
                counter++;
                i++;
            }
        }
    }
    if(counter != 0)    //если есть лишние нули перед числом
    {
        char* x = (char*)malloc(strlen(temp)-counter+1);    //выделяем память под новое число
        int r = 0;
        for(int i=0; r<strlen(temp)-counter; i++)   //игнорим нули и копируем остальное число
        {
            if(i == iStart) {while(temp[i] == '0' && i!=strlen(temp)-1) i++;}
            x[r++] = temp[i];
        }
        x[strlen(temp)-counter] = '\0'; //нуль-терминатор
        change(&x,&temp);   //обмениваемся указателями на память, в temp лежит теперь новое число
        free(x);    //удаляем старое
    }
    if(StrCmp(temp, "-2147483648") == -1 || StrCmp(temp, "2147483647") == 1) return NULL; //проверка на выход за пределы INT
    return temp; //возврат строки
}

int FillStack(Stack* stack, char* str) //заполнение стека со строки
{
    int count = 0;  //переменная для длины строки-числа
    int isEmpty = 1;    //флаг пустоты стека
    int temp;   //временный INT
    for(int i=0; i<strlen(str); i++)
    {
        if(str[i] == ' ') continue; //скипаем пробелы
        int t = i;
        while(str[t] != ' ' && t != strlen(str))    //пока не нашли пробел, увеличиваем счетчик, находим длину предполагаемого числа
        {
            t++;
            count++;
        }
        char* num = (char*)malloc(count+1);     //выделяем память для предполагаемого числа
        for(int j=0; j<count; j++, i++) //заполняем предполагаемое число
        {
            num[j] = str[i];
        }
        num[count] = '\0';  //нуль-терминатор
        num = CheckString(num); //выполняем проверку числа
        if(num == NULL) //если num не является числом, пишем сообщение, возврат 0
        {
            printf("There is an element which isn`t a number or number is too large for int. ");
            return 0;
        }
        count = 0;  //зануляем счётчик
        temp = atoi(num); //превращаем num в число
        if(isEmpty == 0) //если стек непустой, мы должны сравнить числа, чтобы стек был упорядоченным
        {               //что требуется по условию задачи
            if(Peek(stack) > temp)  //если не удовлетворяет условиям, пишем сообщение, возврат 0
            {
                printf("Numbers in file must be sorted from smaller to larger. ");
                return 0;
            }
        }
        else    //если стек сейчас пустой, то после добавления в нем будут данные
        {
            isEmpty = 0;    //поэтому флаг зануляем
        }
        Push(stack, temp);  //добавляем число в стек
        free(num);  //освобождаем память для строки
    }
    return 1;   //возврат единицы
}

Stack* GetMergedStack(Stack* stack1, Stack* stack2) //объединение двух стеков в один
{
    Stack* temp = CreateStack();    //результирующий стек
    int isEmpty = 1;    //флаг пустоты результирующего стека
    while(stack1->head != NULL && stack2->head != NULL) //пока один из стеков не опустеет
    {
        //сравниваем числа в вершинах, добавляем большее число
        //если в результ. стеке уже есть это число, не добавляем его
        if(Peek(stack1) > Peek(stack2))
        {
            if(isEmpty == 1)
            {
                Push(temp, Peek(stack1));
                Pop(stack1);
                isEmpty = 0;
            }
            else
            {
                if(Peek(stack1) == Peek(temp))
                {
                    Pop(stack1);
                }
                else
                {
                    Push(temp,Peek(stack1));
                    Pop(stack1);
                }
            }
        }
        else if(Peek(stack1) == Peek(stack2))
        {
            if(isEmpty == 1)
            {
                Push(temp, Peek(stack1));
                Pop(stack1);
                Pop(stack2);
                isEmpty = 0;
            }
            else
            {
                if(Peek(stack1) == Peek(temp))
                {
                    Pop(stack1);
                    Pop(stack2);
                }
                else
                {
                    Push(temp,Peek(stack1));
                    Pop(stack1);
                    Pop(stack2);
                }
            }
        }
        else if(Peek(stack1) < Peek(stack2))
        {
            if(isEmpty == 1)
            {
                Push(temp, Peek(stack2));
                Pop(stack2);
                isEmpty = 0;
            }
            else
            {
                if(Peek(stack2) == Peek(temp))
                {
                    Pop(stack2);
                }
                else
                {
                    Push(temp,Peek(stack2));
                    Pop(stack2);
                }
            }
        }
    }
    if(stack2->head != NULL)    //если после цикла второй стек остался непустым, выкидываем оттуда все числа в результ. стек
    {
        while(stack2->head != NULL)
        {
            if(Peek(stack2) == Peek(temp))
            {
                Pop(stack2);
            }
            else
            {
                Push(temp,Peek(stack2));
                Pop(stack2);
            }
        }
    }
    if(stack1->head != NULL)    //если после цикла первый стек остался непустым, выкидываем оттуда все числа в результ. стек
    {
        while(stack1->head != NULL)
        {
            if(Peek(stack1) == Peek(temp))
            {
                Pop(stack1);
            }
            else
            {
                Push(temp,Peek(stack1));
                Pop(stack1);
            }
        }
    }
    Stack* result = CreateStack();  //для того, чтобы элементы в стеке были в том же порядке, что и в первом, и во втором,
    while(temp->head != NULL)   //инвертируем результ.стек
    {
        Push(result, Peek(temp));
        Pop(temp);
    }
    return result;
}

void FreeStack(Stack* t)    //очистка стека
{
    while(t->count != 0)    //пока количество элементов не тсанет равным 0, делаем Pop
    {
        Pop(st);
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    Stack* st1 = CreateStack(); //инициализация
    Stack* st2 = CreateStack(); //стеков
    int strSize = 50, i = 0, k = 0;
    char* str = (char*)malloc(strSize*sizeof(char)); //выделение памяти для строки для считывания с файла
    FILE* fp = fopen("text.txt", "r");  //открываем файл
    if(!fp) //не получилось  - пишем сообщение, завершаем функцию
    {
        puts("Error! Can't open the file!");
        return 0;
    }
    while (!feof(fp) && k != 2) //пока не считается две строки
    {
        fscanf(fp,"%c",&str[i]); //посимвольно считываем в строку с файла
        if(str[i] == '\n' || feof(fp)) //если встретился символ перехода на новую строку или конец файла
        {
            str[i] = '\0'; //ставим нуль-терминатор в конце
            if(k == 0)  //если так, заполняем первый стек
            {
                if(FillStack(st1,str) == 0) //если функция возвращает 0, ошибка, очистка стека, завершение функции
                {
                    printf("Error in the first stack!");
                    FreeStack(st1);
                    return 0;
                }
            }
            else if(k == 1) //заполнение второго стека
            {
                if(FillStack(st2,str) == 0) //если функция возвращает 0, ошибка, очистка стека, завершение функции
                {
                    printf("Error in the second stack!");
                    FreeStack(st2);
                    return 0;
                }
            }
            i = 0;  //зануляем счётчик для элементов
            k++;    //добавляем единичку к k
            continue;
        }
        i++; //инкрементируем i для сдвига индекса
        if(i>=strSize)  //если индекс строки стал равен размеру выделенной памяти
        {
            strSize*=2;
            str = (char*)realloc(str, strSize*sizeof(char)); //реаллоцируем память
        }
    }
    free(str);  //освобождаем память для строки
    fclose(fp); //закрываем файл
    //печать стеков
    printf("First stack:\n");
    Print(st1);
    printf("Second stack:\n");
    Print(st2);
    //создаем новый стек и выводим на печать
    Stack* res = GetMergedStack(st1,st2);
    printf("Merged stack:\n");
    Print(res);
    FreeStack(res); //удаление стека
    return 0;
}

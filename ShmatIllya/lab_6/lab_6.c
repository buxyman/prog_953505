#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <malloc.h>
//================ Вариант 23 =============
struct Tree {
int info;
char* word;
struct Tree *Left, *Right;
} *Root; // Root – указатель на корень
void Make(int, char* array);
void Print (struct Tree*, int);
void Del(int);
void Del_All(struct Tree*);
struct Tree* List(int, char*);
char array_imp[100][100];
char task_array[]={"АаЕеЁеИиОоУуыЭэЮюЯя"};
int u=0;
void array_creation(char* temp)
{
    int i1=0, i2=0;

for (int i=0;temp[i]!='\0'; i++)
{
    if (i==0)
    {
        for (int y=i; temp[y]!=' '&&temp[y]!='.'&&temp[y]!=','&&temp[y]!='!'&&temp[y]!='?';y++)
        {
            array_imp[i2][i1]=temp[y];
            i1++;
            i=y;
        }
        i2++;
        i1=0;
        u++;
    }
   else if (temp[i]==' ')
    {
        for (int y=i+1; temp[y]!=' '&&temp[y]!='.'&&temp[y]!=','&&temp[y]!='!'&&temp[y]!='?';y++)
        {
            array_imp[i2][i1]=temp[y];
            i1++;
            i=y;
        }
        i2++;
        i1=0;
        u++;
    }
}
printf("Считанная информация:\n");
for (int i=0;i<u;i++)
{
    printf("%s\n", array_imp[i]);
}
printf("---------------------------------\n");
}
int main() {
int key;
setlocale(LC_ALL, "rus");
    FILE *fp;
    char temp[1000];

    fp=fopen("text.txt", "r");
    if (!fp)
    {
        printf("Nothing found");
    }
    while (fgets(temp, 1000, fp) != NULL)
    {
    }
    array_creation(temp);
    free(fp);
while(1) {
puts(" Создать дерево - 1\n Вывести дерево на экран - 2 \n Удалить элемент дерева - 3 \n Инд. задание - 4 \n Выход - 0");
switch (getch()) {
case '1':
    Make(0,array_imp[0]);
    for (int i=1; i<u; i++)
    {
      Make(1,array_imp[i]);
    }
break;
case '2': if( Root == NULL ) puts ("\t Конец дерева !");
else Print(Root, 0);
break;
case '3': puts("\n Укажите ключ удаляемого элемента "); scanf("%d", &key);
Del(key);
break;
case '4':
printf("--------------------------------------\n");
Task(Root);
printf("--------------------------------------\n");
break;
case '0': Del_All(Root);
puts("\n Дерево удалено!");
return 0;
}
}
}
//============ Создание дерева ==========================
void Make(int kod, char* array) {
struct Tree *Prev, *t, *t1;
int b,found;
if ( kod == 0 ) {
puts( "\n Укажите ключ корня :");
scanf("%d", &b);
Root = List(b, array);
}
else
{
//============= Вставка остальных элементов ===============
puts( "\n Укажите ключ элемента :"); scanf("%d", &b);
t = Root;
found = 0;
while ( t && !found ) {
Prev = t;
if( b == t->info) found = 1;
else
if ( b < t -> info ) t = t -> Left;
else t = t -> Right;
}
if (!found) {
t1 = List(b, array);
if ( b < Prev -> info ) Prev -> Left = t1;
else Prev -> Right = t1;
}
}
}
//============= Удаление элемента по ключу (не корень) ===============
void Del(int key) {
struct Tree *Del,*Prev_Del,*R,*Prev_R;
Del = Root; Prev_Del = NULL;
while (Del != NULL && Del -> info != key) {
Prev_Del = Del;
if (Del->info >key) Del=Del->Left;
else Del=Del->Right;
}
if (Del==NULL){
puts ( "\n Ключа нет!");
return;
}
if (Del -> Right == NULL) R = Del->Left;
else
if (Del -> Left == NULL) R = Del->Right;
else {
Prev_R = Del;
R = Del->Left;
while (R->Right != NULL) {
Prev_R=R;
R=R->Right;
}
if( Prev_R == Del) R->Right=Del->Right;
else {
R->Right=Del->Right;
Prev_R->Right=R->Left;
R->Left=Prev_R;
}
}
if (Prev_Del==NULL) { Root = Prev_Del = R; }
else
if (Del->info < Prev_Del->info) Prev_Del->Left=R;
else Prev_Del->Right=R;
printf("\n Удалён элемент %d\n",Del->info);
free (Del);
}
//============= Формирование (создание) элемента - листа =============
struct Tree* List(int i, char* array) {
struct Tree *t = malloc(sizeof(struct Tree));
t -> info = i;
t->word=array;
t -> Left = t -> Right = NULL;
return t;
}
//=========== Функция вывода на экран ========================
void Print ( struct Tree *p, int level ) {
if ( p ) {
Print ( p -> Right , level+1);
for ( int i=0; i<level; i++) printf(" ");
printf("%d %s \n", p->info, p->word);
Print( p -> Left , level+1);
}
}
//=========== Вывод элементов, количество гласных в которых больше трёх ==============
void Task ( struct Tree *p) {
if ( p ) {
        int count=0;
for (int i=0; p->word[i]!='\0'; i++)
{
    for (int j=0; task_array[j]!='\0'; j++)
    {
        if (p->word[i]==task_array[j])
            {
               count++;
               break;
            }
    }
}
if (count>=3)
{
   printf("%d %s \n", p->info, p->word);
}
Task ( p -> Right);
Task( p -> Left);
}
}
//===================== Освобождение памяти ==================
void Del_All(struct Tree *t) {
if ( t != NULL) {
Del_All ( t -> Left);
Del_All ( t -> Right);
free (t);
}
}

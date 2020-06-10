/*Разнобуквица. С клавиатуры вводится многострочный текст.
Распечатать самое длинное слово, в котором все буквы разные.*/
// main.c
// 4.1.5
//
// Created by Ilyass-Emir on 5/23/20.
// Copyright © 2020 malumba. All rights reserved.
//
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>


bool Unique(const char *begin, const char *end)
{
bool seen[UCHAR_MAX + 1] = { 0 };

for (const char *c = begin; c != end; c++)

{
size_t i = (unsigned char) *c;
if (seen[i])
return false;

seen[i] = true;
}

return true;
}

int main(void)
{
const char *text ;
puts("Input text:");
gets(text);

const char *max_word = NULL;
size_t max_length = 0;

const char *end = text;

do
{
const char *begin = end;
while (*begin != '\0' && !isalpha(*begin))
++begin;

if (*begin == '\0')
break;

end = begin;
while (isalpha(*end))
++end;

size_t length = end - begin;
if (length > max_length && Unique(begin, end))
{
max_word = begin;
max_length = length;
}

} while (true);

if (max_word != NULL)
printf("Max word: %.*s\n", (int) max_length, max_word);
}

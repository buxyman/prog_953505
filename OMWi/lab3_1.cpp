#include <stdio.h>
#include <malloc.h>
#include <locale.h>

int* InitArray(int size) {
	int* array = (int*)malloc(sizeof(int) * size);
	printf("Введите значения элементов массива\n");
	for (int i = 0; i < size; i++) {
		scanf_s("%d", &array[i]);
	}
	return array;
}

void SortArray(int* array, int size) {
	for (int i = 1; i < size; i++) {
		for (int j = i; j > 0 && array[j - 1] > array[j];j--) {
			int temp = array[j - 1];
			array[j - 1] = array[j];
			array[j] = temp;
		}
	}
}

void PrintArray(int* array, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int size;
	printf("Введите размер массива ");
	scanf_s("%d", &size);
	int* array = InitArray(size);
	float q;
	printf("Введите q ");
	scanf_s("%f", &q);
	SortArray(array, size);
	PrintArray(array, size);
	free(array);
}
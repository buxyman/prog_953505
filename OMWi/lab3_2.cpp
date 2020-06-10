#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <stdbool.h>

bool*** CreateArray3(int x, int y, int z) {
	bool*** array = (bool***)malloc(sizeof(bool**) * z);
	for (int i = 0; i < z; i++) {
		array[i] = (bool**)malloc(sizeof(bool*) * y);
		for (int j = 0; j < y;j++) {
			array[i][j] = (bool*)malloc(sizeof(bool) * x);
		}
	}
	return array;
}

bool** CreateArray2(int rows, int columns) {
	bool** array = (bool**)malloc(sizeof(bool*) * rows);
	for (int i = 0; i < rows; i++) {
		array[i] = (bool*)malloc(sizeof(bool) * columns);
	}
	return array;
}

void DeleteArray3(bool*** array, int y, int z) {
	for (int i = 0; i < z; i++) {
		for (int j = 0; j < y;j++) {
			free(array[i][j]);
		}
		free(array[i]);
	}
	free(array);
}

void DeleteArray2(bool** array, int rows) {
	for (int i = 0; i < rows; i++) {
		free(array[i]);
	}
	free(array);
}

void PrintArray2(bool** array, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns;j++) {
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
}

bool** GetXYProjection(bool*** array, int x, int y, int z) {
	bool** projection = CreateArray2(x, y);
	for (int xIndex = 0;xIndex < x; xIndex++) {
		for (int yIndex = 0; yIndex < y; yIndex++) {
			bool value = 0;
			for (int zIndex = 0; zIndex < z; zIndex++) {
				if (array[zIndex][yIndex][xIndex]) {
					value = 1;
					break;
				}
			}
			projection[xIndex][yIndex] = value;
		}
	}
	return projection;
}

bool** GetZXProjection(bool*** array, int x, int y, int z) {
	bool** projection = CreateArray2(x, z);
	for (int xIndex = 0;xIndex < x; xIndex++) {
		for (int zIndex = 0; zIndex < z; zIndex++) {
			bool value = 0;
			for (int yIndex = 0; yIndex < y; yIndex++) {
				if (array[zIndex][yIndex][xIndex]) {
					value = 1;
					break;
				}
			}
			projection[z - zIndex - 1][x - xIndex - 1] = value;
		}
	}
	return projection;
}

bool** GetZYProjection(bool*** array, int x, int y, int z) {
	bool** projection = CreateArray2(x, z);
	for (int zIndex = 0;zIndex < z; zIndex++) {
		for (int yIndex = 0; yIndex < y; yIndex++) {
			bool value = 0;
			for (int xIndex = 0; xIndex < x; xIndex++) {
				if (array[zIndex][yIndex][xIndex]) {
					value = 1;
					break;
				}
			}
			projection[z - zIndex - 1][yIndex] = value;
		}
	}
	return projection;
}

void EnterData(bool*** array, int x, int y, int z) {
	for (int i = 0; i < z;i++) {
		for (int j = 0;j < y; j++) {
			for (int k = 0; k < z;k++) {
				printf("array[%d][%d][%d] ", i, j, k);
				scanf_s("%d", &array[i][j][k]);
			}
		}
	}
}

int main() {
	int x = 3, y = 3, z = 3;
	//max 40 иначе в консоль не влезет
	bool*** array = CreateArray3(x, y, z);
	EnterData(array, x, y, z);
	printf("\n\n");
	bool** xy = GetXYProjection(array, x, y, z);
	bool** xz = GetZXProjection(array, x, y, z);
	bool** zy = GetZYProjection(array, x, y, z);
	PrintArray2(xy, x, y);
	printf("\n\n");
	PrintArray2(xz, x, z);
	printf("\n\n");
	PrintArray2(zy, y, z);
	DeleteArray3(array, y, z);
	DeleteArray2(xy, x);
	DeleteArray2(xz, x);
	DeleteArray2(zy, y);
}
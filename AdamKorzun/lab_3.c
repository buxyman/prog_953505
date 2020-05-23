// var 1

#include <stdio.h>
void PrintMatrix(float **matrix,int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			printf("%.15f ", matrix[i][j]);
		}
		printf("\n");
	}
}
void SwapRows(float** matrix, int rows, int columns,int toSwap) {
	float* tempRow = (float*)malloc(columns * sizeof(float));
	for (int i = 0; i < columns; i++) {
		tempRow[i] = matrix[toSwap][i];
	}
	for (int i = 0; i < columns; i++) {
		matrix[toSwap][i] = matrix[0][i];
		matrix[0][i] = tempRow[i];
	}
	free(tempRow);
}
void DivideRow(float** matrix, int rows, int columns, int toDivide,int elNumber) {
	if (matrix[toDivide][elNumber] == 0) {
		return;
	}
	double divNum = matrix[toDivide][elNumber];
	for (int i = elNumber; i < columns; i++) {
		if (matrix[toDivide][i] < 0.00001) {
			matrix[toDivide][i] = 0;
		}
		matrix[toDivide][i] /= divNum;
	}
}
void RowToZero(float** matrix, int rows, int columns, int elNumber) {
	if (matrix[elNumber][elNumber] == 0) {
		return;
	}
	double divNum = matrix[elNumber][elNumber];
	for (int j = elNumber+ 1; j < rows; j++) {
		
		double divider = matrix[j][elNumber] / divNum;
		for (int i = elNumber; i < columns; i++) {
			matrix[j][i] -= matrix[elNumber][i] * divider;
		}
	}

}
void assignment1() {
	
	int rows, columns;
	printf("Rows: ");
	scanf_s("%d", &rows);
	printf("Coulums: ");
	scanf_s("%d", &columns);
	
	
	
	float **matrix = (float **)malloc(rows * sizeof(float *));
	for (int i = 0; i < rows; i++) {
		matrix[i] = (float *)malloc(columns * sizeof(float));
	}
	
	
	for (int i = 0; i < rows; i++) {
		printf("Row %d\n", i);
		for (int j = 0; j < columns; j++) {
			printf("Element: [%d][%d]: ", i, j);
			scanf_s("%f", &matrix[i][j]);
		}
	}
	
	if (rows > columns) {
		float** matrixTemp = (float**)malloc(rows * sizeof(float*));
		for (int i = 0; i < rows; i++) {
			matrixTemp[i] = (float*)malloc(columns * sizeof(float));
		}
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				matrixTemp[i][j] = matrix[i][j];
			}
		}
		free(matrix);
		int temp = rows;
		rows = columns;
		columns = temp;
		
		matrix = (float**)malloc(rows * sizeof(float*));
		for (int i = 0; i < rows; i++) {
			matrix[i] = (float*)malloc(columns * sizeof(float));
		}
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				matrix[i][j] = matrixTemp[j][i];
				//printf("%f ", matrix[i][j]);
			}
			//printf("\n");
		}
		free(matrixTemp);
		printf("Matrix was transposed.\n");
		
	}
	
	
	
	
	
	
	printf("\n");

	int minEl = fabs(matrix[0][0]);
	if (matrix[0][0] == 0) {
		for (int i = 0; i < rows; i++) {
			if (matrix[i][0] != 0) {
				minEl = matrix[i][0];
				break;
			}
		}
	}
	int minIndex = 0;
	for (int i = 0; i < rows; i++) {
		if (fabs(matrix[i][0]) < minEl && matrix[i][0] != 0) {
			minEl = matrix[i][0];
			minIndex = i;
		}
	}
	SwapRows(matrix, rows, columns, minIndex);
	PrintMatrix(matrix,rows,columns);
	printf("\n");
	for (int i = 0; i < rows; i++) {
		
		DivideRow(matrix, rows, columns, i, i);
		RowToZero(matrix, rows, columns, i);
		PrintMatrix(matrix, rows, columns);
		printf("\n");
	}
	int linIndependtentR = rows;
	int linIndependtentC = columns;
	//independent rows
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (matrix[i][j] != 0) {
				break;
			}
			if (j == columns - 1) {
				linIndependtentR-=1;
			}
		}
	}
	// independent columns
	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < rows; j++) {
			if (matrix[j][i] != 0) {
				break;
			}
			if (j == rows - 1) {
				linIndependtentC-=1;
			}
		}
	}
	
	if (linIndependtentC > linIndependtentR) {
		printf("Matrix rank: %d", linIndependtentR);
		return;
	}
	else {
		printf("Matrix rank: %d", linIndependtentC);
	}
	
	for (int i = 0; i < rows; i++) {
		free(matrix[i]);
	}
	free(matrix);

}
int main() {
	assignment1();
	return 0;
}

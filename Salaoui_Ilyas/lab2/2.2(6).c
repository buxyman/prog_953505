
#include <stdio.h>
#include <math.h>


int main() {

	int i, n, k1, k2, fact = 1;
	float right = 0, left = 0, x, eps;
	printf("Enter calculation error: \t");
	if (!scanf_s("%f", &eps)) {
		printf("Error\n");
	}
	else {
		printf("\n");
	}
	printf("Enter number of members in a row: \t");
	if (!scanf_s("%d", &n)) {
		printf("Error\n");
	}
	else {
		printf("\n");
	}
	if (n >= 0) {
		printf("Enter amount of numbers for convergence checks:\t");
		if (!scanf_s("%d", &k1)) {
			printf("error\n");
		}
		else {
			printf("\n");
		}
		k2 = 0;
		float res = 0;
		while (k2 < k1) {
			printf("x= "); // x-заданное значение для подстановки в выражения
			if (!scanf_s("%f", &x)) {
				printf("error\n");
			}
			else {
				printf("\n");
			}
			for (i = 1, fact = 1, right = 0; i < 2 * n; i++) {

				fact *= (2 * i) - 1;
				right += powl(-1, i - 1) * powl(x, (2 * i) - 1) / fact;
				res = (sin(x) - right);
				if (res > eps) {
					printf("\nn = %d", i);
				}

			}


			left = sin(x);
			printf("\nValue of the right function: %f\n", right);
			printf("Value of the left function: %f\n", left);
			k2++;

		}
	}
	else {
		printf("Error\n");
	}
	return 0;
} 

//-------------2.2(Вариант 6)Быстров Максим 953505-------------
#include <math.h>
#include <stdio.h>	
int factorization(int n);
int calculation(double radians, int n);
int recursion(double radians, double result, double e, int y);
int x;
int factorization(int n) {
	return n <= 1 ? 1 : factorization(n - 1)*n;
}
int calculation(double radians, int n)
{
	long double e, a, b, c, result = 0;
	for (int y = 1; y < n; y++)
	{
		e = y - 1;
		a = pow(-1, y-1);
		b = pow(radians, (2 * y) - 1);
		c = factorization((2 * y) - 1);
		result += (a * b) / (long double)c;
		if (result - sin(radians) < e)
		{
			printf("S(x) - %Lf\n", result);
			return y;
		}
	}
	return 0;
}
int recursion(double radians, double result, double e, int y) {
	
	e = y - 1;
	double a = pow(-1, y - 1);
	double b = pow(radians, (2 * y) - 1);
	double c = factorization((2 * y) - 1);
	result += (a * b) / (long double)c;
	if (result - sin(radians) < e)
	{
		printf("S(x) - %Lf\n", result);
		return y;
	}
	return recursion(radians, result, e, y += 1);
}
int main()
{
	printf("Enter x:");
	scanf_s("%d", &x);
	printf("%d", calculation(x, 1000));
	return 0;
}

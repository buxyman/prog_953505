#include <stdio.h>
#include <math.h>
#include <Windows.h>

double pi = 3.14159265358;

double getTaylorChange(int n, double x)
{
	double taylorChange = 1;
	for (int i = 1;i < 2 * n; i++)
	{
		taylorChange = taylorChange / i * x;
	}
	taylorChange *= pow(-1, n - 1);
	return taylorChange;
}

void checkIteration(double x, double e)
{

	double taylor = 0;
	double fault;
	int n;
	for (n = 1; ; n++)
	{
		taylor += getTaylorChange(n, x);
		fault = sin(x) - taylor;
		if (fabs(fault) < e) break;
	}
	//printf("Iterations\t");
	//printf("n = %d\t", n);
}

void checkRecursion(double x, double e, double taylor, int n)
{
	taylor += getTaylorChange(n, x);
	double fault = taylor - sin(x);
	if (fabs(fault) < e)
	{
		//printf("Recursion\t");
		//printf("n = %hi\t", n);
		return;
	}
	checkRecursion(x, e, taylor, n + 1);
}

int main()
{
	double x;
	printf("Enter x(in degrees) ");
	scanf_s("%lf", &x);
	x *= pi / 180;
	while (x > 2 * pi)
	{
		x -= 2 * pi;
	}
	while (x < 0)
	{
		x += 2 * pi;
	}
	double e;
	printf("Enter e ");
	scanf_s("%lf", &e);
	if (e < 1e-14)
	{
		printf("Error");
		return 1;
	}
	int start = GetTickCount64();
	for (int i = 0; i < 100000;i++)
	{
		checkIteration(x, e);
	}
	int end = GetTickCount64();
	int  time = (end - start) ;
	printf("Iteration elapsed time %d\n", time);
	start = GetTickCount64();
	for (int i = 0; i < 100000;i++)
	{
		checkRecursion(x, e, 0, 1);
	}	
	end = GetTickCount64();
	time = (end - start) ;
	printf("Recursion elapsed time %d\n", time);
}
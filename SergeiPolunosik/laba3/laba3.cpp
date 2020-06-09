#include <stdio.h>
#include <conio.h>
#include <malloc.h>

float GetSpending(float *height, float *speed, float length, int count)
{
	float averageSpeed = 0, averageHeight = 0, j = 0, square, spending;

	for (int i = 0;i < count;i++)
	{
		averageHeight = (averageHeight + height[i]) / (j + 1.0);
		j++;
	}

	j = 0;

	for (int i = 0; i < count;i++)
	{
		averageSpeed = (averageSpeed + speed[i]) / (j + 1.0);
		j++;
	}
	
	square = averageHeight * length;
	spending = square * averageSpeed;
	return spending;
}

int main()
{
	float * Vi, * Hi, L, Li;
	int n;
	printf("Enter count of steps: ");
	scanf_s("%d", &n);
	printf("Enter length of FARVATER in metrs: ");
	scanf_s("%f", &L);
	Vi = (float*)malloc(sizeof(float) * n);
	Hi = (float*)malloc(sizeof(float) * n);

	for (int i = 0;i < n;i++)
	{
		printf("Speed[%d] in metrs/s= ", i + 1);
		scanf_s("%f", &Vi[i]);
		printf("Height[%d] in metrs = ", i + 1);
		scanf_s("%f", &Hi[i]);
	}

	printf("Spending = %f", GetSpending(Hi, Vi, L, n));
}


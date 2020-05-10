#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define scanf_s scanf

int Input()
{
	int value = 0;
	scanf_s("%d", &value);
	return value;
}
void Coordinations(int* x1, int* y1, int* x2, int* y2, int* x3, int* y3)
{
	// Coordinates inputting by dots
	printf("Enter the coordinates of the triangle.\n\n");
	printf("First dot\n");
	scanf_s("%d", &(*x1));
	scanf_s("%d", &(*y1));
	printf("Second dot\n");
	scanf_s("%d", &(*x2));
	scanf_s("%d", &(*y2));
	printf("Third dot\n");
	scanf_s("%d", &(*x3));
	scanf_s("%d", &(*y3));
}
void Sides(int* x1, int* y1, int* x2, int* y2, int* x3, int* y3, double* a, double* b, double* c)
{
	// Sides of triangle
	(*a) = fabs(sqrt(pow(((*x1) - (*x2)), 2) + pow(((*y1) - (*y2)), 2)));
	(*b) = fabs(sqrt(pow(((*x2) - (*x3)), 2) + pow(((*y2) - (*y3)), 2)));
	(*c) = fabs(sqrt(pow(((*x3) - (*x1)), 2) + pow(((*y3) - (*y1)), 2)));
	if ((*a) < (*b) + (*c) && (*b) < (*a) + (*c) && (*c) < (*a) + (*b))
	{
		printf("The triangle exists\n");
	}
	else
	{
		printf("The triangle does not exist\n");
	}
}
void Type(double* a, double* b, double* c) // Allows you to figure out what type is your triangle
{
	if ((*a) == (*b) == (*c))
	{
		printf("The triangle is correct\n");
	}
	else if ((*a) == (*b) || (*b) == (*c) || (*a) == (*c))
	{
		printf("The triangle is isosceles\n");
	}
	else if ((((*a) * (*a)) == (((*b) * (*b)) + ((*c) * (*c)))) || (((*b) * (*b)) == (((*a) * (*a)) + ((*c) * (*c)))) || (((*c) * (*c)) == (((*b) * (*b)) + ((*a) * (*a)))))
	{
		printf("The triangle is rectangular\n");
	}
	else
	{
		printf("The triangle is arbitrary");
	}

}
void Perimeter(double* a, double* b, double* c, double* Per) 
{
	(*Per) = (*a) + (*b) + (*c);
	printf("The perimeter is %f\n", (*Per));
}
void Square(double* a, double* b, double* c, double* p, double* h, double* Sq)
{
	(*p) = 0.5 * ((*a) + (*b) + (*c));
	(*h) = (2 * (sqrt((*p) * ((*p) - (*a)) * ((*p) - (*b)) * ((*p) - (*c))))) / (*a);
	(*Sq) = 0.5 * (*a) * (*h);
	printf("The area is %f\n", (*Sq));
}

void Okr(double* a, double* b, double* c, double* p, double* r, double* R)
{
	(*p) = 0.5 * ((*a) + (*b) + (*c));
	(*r) = sqrt((((*p) - (*a)) * ((*p) - (*b)) * ((*p) - (*c))) / (*p));
	printf("The radius of the inscribed circle is %f\n", (*r));

	(*R) = ((*a) * (*b) * (*c)) / (4 * sqrt((*p) * ((*p) - (*a)) * ((*p) - (*b)) * ((*p) - (*c))));
	printf("The radius of the circumscribed circle is %f\n", (*R));
}
int main(void)
{
	int choose = 0, LookAnswer = 0;
	static int x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;
	static double a = 0, b = 0, c = 0, Per = 0, h = 0, Sq = 0, p = 0, r = 0, R = 0;
	while (LookAnswer < 2)
	{
		LookAnswer = 0;
		printf("\nShow menu - 1, exit - 2\n");
		LookAnswer = Input();
		if (LookAnswer == 1)
		{
			printf("Choose:\n");
			printf("1.Coordinates.\n");
			printf("2.Type.\n");
			printf("3.Perimeter.\n");
			printf("4.The area.\n");
			printf("5.The radii.\n");
			printf("6.Exit.\n\n");
			scanf_s("%d", &choose);
			switch (choose)
			{
			case 1:

				Coordinations(&x1, &y1, &x2, &y2, &x3, &y3);
				Sides(&x1, &y1, &x2, &y2, &x3, &y3, &a, &b, &c);
				while (x1 == x2 && x2 == x3 && x1 == x3)
				{
					printf("Icorrect coordinates\nAgain\n");
					Coordinations(&x1, &y1, &x2, &y2, &x3, &y3);
					Sides(&x1, &y1, &x2, &y2, &x3, &y3, &a, &b, &c);
				}
				while (y1 == y2 && y2 == y3 && y1 == y3)
				{
					printf("Icorrect coordinates\nAgain\n");
					Coordinations(&x1, &y1, &x2, &y2, &x3, &y3);
					Sides(&x1, &y1, &x2, &y2, &x3, &y3, &a, &b, &c);
				}
				break;
			case 2:
				printf("Define the type of triangle.\n\n");
				while (a == 0 || b == 0 || c == 0)
				{
					printf("Incorrect side\n");
					Coordinations(&x1, &y1, &x2, &y2, &x3, &y3);
					Sides(&x1, &y1, &x2, &y2, &x3, &y3, &a, &b, &c);
				}
				Type(&a, &b, &c);
				break;
			case 3:
				printf("Output of the triangle perimeter.\n\n");
				while (a == 0 || b == 0 || c == 0)
				{
					printf("Incorrect side\n");
					Coordinations(&x1, &y1, &x2, &y2, &x3, &y3);
					Sides(&x1, &y1, &x2, &y2, &x3, &y3, &a, &b, &c);
				}
				Perimeter(&a, &b, &c, &Per);
				break;
			case 4:
				printf("Output the area of the triangle.\n\n");
				while (a == 0 || b == 0 || c == 0)
				{
					printf("Incorrect side\n");
					Coordinations(&x1, &y1, &x2, &y2, &x3, &y3);
					Sides(&x1, &y1, &x2, &y2, &x3, &y3, &a, &b, &c);
				}
				Square(&a, &b, &c, &p, &h, &Sq);
				break;
			case 5:
				printf("The radius of the circles inscribed and described around the triangle.\n\n");

				while (a == 0 || b == 0 || c == 0)
				{
					printf("Incorrect side\n");
					Coordinations(&x1, &y1, &x2, &y2, &x3, &y3);
					Sides(&x1, &y1, &x2, &y2, &x3, &y3, &a, &b, &c);
				}
				Okr(&a, &b, &c, &p, &r, &R);
				break;
			case 6:
				printf("\n You've just quited this program");
				LookAnswer = 2;
			}
		}
		else
		{
			printf("Quitting...\n");
		}
	}
}
 
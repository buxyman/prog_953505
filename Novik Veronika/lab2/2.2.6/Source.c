/*2.2.6.Численно убедиться в справедливости равенства, для чего для
заданного значения х вычислить его левую часть и разложение,
стоящее в правой части. При каком n исследуемое выражение
отличается от sin x менее, чем на заданную погрешность ??
Испытать разложение на сходимость при разных значениях х. */

#include <stdio.h>
#include <math.h>

double Fact(int a, double res) {
	if (a > 1) return Fact(a - 1, res * a);
	return res;
}

int Rec(double x, double e, int n, double sum) {
	if (fabs(sin(x) - sum) < e) {
		printf("Recursion: (Form) sin x = expression\n\n %lf = %lf\n\n", sin(x), sum);
		return n;
	}

	n++;
	sum += pow(-1, n - 1) * pow(x, 2 * n - 1) / Fact(2 * n - 1, 1.);
	return Rec(x, e, n, sum);
}

int Iter(double x, double e, int n, double sum) {
	for (; !(fabs(sin(x) - sum) < e); n++) {
		sum += pow(-1, n - 1) * pow(x, 2 * n - 1) / Fact(2 * n - 1, 1.);
	}

	printf("\n\nIteration: (Form) sin x = expression\n\n %lf = %lf\n\n", sin(x), sum);
	return n;
}

int main() {
	double x, e;
	printf("Enter x:\nx = ");
	scanf_s("%lf.20", &x);
	printf("Enter e:\ne = ");
	scanf_s("%lf", &e);
	printf("n = %d", Rec(x, e, 1., x));
	printf("n = %d", Iter(x, e, 2., x) - 1);
	return 0;
}
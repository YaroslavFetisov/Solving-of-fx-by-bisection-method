#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

double dichotomy(double (*)(double), double, double, double);
double sinx(double);
double ln1(double);
double exp2x(double);

const double eps = 1.e-10;
const double pi = 3.14159265359;

void main(void) {
	//sin(x) = x, [-1, 1]
	cout << "sin(x) = x,\tx = " << dichotomy(sinx, -1, 1, eps) << endl;
	//sin(x) = 0, [π - 1, π]
	cout << "sin(x) = 0,\tx = " << dichotomy(sin, pi-1, pi, eps) << endl;
	//ln(x) = 1, [2, 3]
	cout << "ln(x) = 1,\tx = " << dichotomy(ln1, 2, 3, eps) << endl;
	//exp(x) = 2 - x, [0, 2]
	cout << "exp(x) = 2 - x,\tx = " << dichotomy(exp2x, 0, 2, eps) << endl;
}

double dichotomy(double (*f)(double), double a, double b, double eps) {
	assert(f(a) * f(b) < 0);
	double x;
	do {
		x = (a + b) / 2;
		if (f(x) * f(a) < 0) {
			b = x;
		}
		else {
			a = x;
		}
	} while (fabs(f(x)) > eps);
	return x;
}

double sinx(double x) {
	return sin(x) - x;
}

double ln1(double x) {
	return log(x) - 1;
}

double exp2x(double x) {
	return exp(x) + x - 2;
}
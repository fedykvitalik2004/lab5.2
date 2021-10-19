#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;double s(const double x, const double eps, int &n, double S);double A(const double x, const int n, double a);int main()
{
	double xp, xk, x, dx, eps, a, R, S=0;
	int n=0;

	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << "eps = "; cin >> eps;

	cout << fixed;
	cout << "---------------------------------------------" << endl;
	cout << "|" << setw(10) << "x" << " |"
		<< setw(10) << "arcth(x)" << " |"
		<< setw(10) << "S" << " |"
		<< setw(5) << "n" << " |"
		<< endl;
	cout << "---------------------------------------------" << endl;
	
	x = xp;
	while (x <= xk)
	{
		S=s(x, eps, n, S);
		cout << "|" << setw(10) << setprecision(2) << x << " |"
			<< setw(10) << setprecision(5) << atanh(1.0 / x) << " |"
			<< setw(10) << setprecision(5) << S << " |"
			<< setw(5) << n << " |"
			<< endl;
		x += dx;
	}
	cout << "---------------------------------------------" << endl;
	return 0;
}

double s(const double x, const double eps, int &n, double S)
{
	n = 0;
	double a = 1.0 / x;
	S = a;
	do {
		n++;
		a = A(x, n, a);
		S += a;
	} while (abs(a) >= eps);
	return S;
}

double A(const double x, const int n, double a)
{
	double R = (2 * n - 1) / ((2 * n + 1) * x * x);
	a *= R;
	return a;
}
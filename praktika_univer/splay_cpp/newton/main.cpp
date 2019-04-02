#include <iostream>
using namespace std;


struct Data {
    double x, y;
};

double q_calculate(double q, int n) {
	double temp = q;
	for (int i = 1; i < n; i++)
        temp *= (q - i);
	return temp;
}

double fact(int n) {
	double f = 1.;
	for (int i = 2; i <= n; i++)
        f *= i;
	return f;
}

int main() {
	//Количество исходных точек:
	const int n = 4;

	Data f[n] = {
	 { 0, 0 },
	 { 1, 1 },
	 { 2, 4 },
	 { 3, 9 }
	};

	double y[n][n];
	for (int i = 0; i < n; i++)
        y[i][0] = f[i].y;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++)
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
	}
	double x1 = 0,
		x2 = 5,
		dx = 0.125;
	cout << "X" << '\t';
	cout << "Y" << endl;
	for (double x = x1; x <= x2; x += dx) {
		double sum = y[0][0];
		double q = (x - f[0].x) / (f[1].x - f[0].x);
		for (int i = 1; i < n; i++) {
			sum += (q_calculate(q, i) * y[0][i]) / fact(i);
		}
		 cout << x << '\t';
		 cout << sum << endl;
	}

	return 0;
}

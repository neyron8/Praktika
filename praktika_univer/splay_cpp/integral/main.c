#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double getrand()
{
    return (double)rand() / RAND_MAX;
}

double func(double x, double y)
{
    return exp(pow(x+y,2));
}
const double PI = 3.14159265358979323846;
const double n = 10000000;

int main(int argc, char **argv)
{
    double in = 0;
    double s = 0;
    for (int i = 0; i < n; i++) {
        double x = getrand() * (1 - x);
        double y = getrand();
    if (y < (1 - x)) {
        in++;
        s += func(x, y);
    }
    }
    double v = in / n;
    double res = v * s / in;
    printf("Result: %.12f, n %f\n", res, n);
    return 0;
}

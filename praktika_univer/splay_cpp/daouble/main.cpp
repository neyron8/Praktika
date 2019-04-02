#include <iostream>
#include <cmath>
#define EPS 1E-2

using namespace std;

double calculate_f(double x, double y)
{
   return y + exp(x) * cos(x);
}

double a = 5;
double b = 15;
double y0 = 1;
double n = 10000;

double eiler()
{
    double a=0; double b=1; double h=0.1;
    double n=(b-a)/h;
    double X[(int)n]; double Y[(int)n];
    X[0]=a; Y[0]=2;
    for(int i=1; i<=n; i++){
        X[i]=a+i*h;
        Y[i]=Y[i-1]+h*F(X[i-1],Y[i-1]);
    }
    for(int i=0; i<=n; i++){
        cout << "X["<<i<<"]="<<X[i] <<" ";
    }
    cout << endl;
    for(int i=0; i<=n; i++){
        cout << "Y["<<i<<"]="<<Y[i] << " ";
    }
    return 0;
}

int main()
{
    double t,t2;

 do{
    double h = (b - a) / n;
    double x[n + 1];
    double y[n + 1];
    double y_2[2*(n + 1)];
    x[0] = a;
    y[0] = y0;
    for (int j = 1; j < n; j++)
    {
        cout.precision(7);
        cout.setf(ios::fixed);
        x[j] = x[j - 1] + h;
        y[j] = y[j - 1] + h * calculate_f(x[j - 1], y[j - 1]);
        t = y[j];
             cout <<"-------------------" << endl;
             cout << "x_h= " << x[j-1] + h << endl;
             cout << "y_h= " << t << endl;

        for (int i = 0; i < 2; i++)
        {
            x[i + 1] = x[i] + h/2;
            y_2[i + 1] = y_2[i ] + (h/2) * calculate_f(x[i], y_2[i]);
            t2 = y_2[i];
        }
             cout << "y_h2= " << t2 << endl;
             cout <<"eps= " << abs(t2-t) << endl;
             cout <<"-------------------" << endl;
             if(abs(t2-t) > EPS)
             {
             h = h/2;
             }
             cout << "h= " << h << endl;
     }
   } while(fabs(s1 - s) > EPS);

    cin.ignore();
    cin.get();
}

#include<bits/stdc++.h>
using namespace std;
#define PI 3.1416
double  f(double x , double y)
{
    return x - y ;
}
int main()
{
    double x0 , y0 ;
    cin >> x0 >> y0 ;
    double h;
    cin >> h;
    int iter = 1 ;
    for(double i=0 ; i<10 ; i+=h)
    {
        double k1 = h * f(x0 , y0) ;
        double k2 = h * f(x0 + h/2 , y0 + k1/2) ;
        double k3 = h * f(x0 + h/2 , y0 + k2/2) ;
        double k4 = h * f(x0 + h , y0 + k3) ;

        double y = y0 + (1.0/6) * (k1 + 2*k2 + 2*k3 + k4) ;

        cout << "y" << iter << " = " << y << endl;

        x0 = x0 + h ;
        y0 = y ;
        iter++;
    }
    return 0;
}

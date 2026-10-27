#include<bits/stdc++.h>
using namespace std;
int a, b, c, d,e ;
double f(double x)
{
    return  a*pow(x,4) + b*pow(x, 3) + c*pow(x,2) + d*x + e ;
}
double bisection(double l, double r, int &iter)
{
    double mid ;
    double prev = 0;
    iter = 0;
    while(true)
    {

        iter++;
        mid = (l*f(r) - r*f(l)) / (f(r) - f(l)) ;
        if(f(mid) == 0) return mid;
        if(iter > 1 && fabs((mid - prev) / prev) < 1e-4)
        {
            return mid ;
        }
        if(f(mid) * f(l) < 0) r = mid;
        else if(f(mid) * f(r) < 0) l = mid ;

        prev = mid ;
    }

}
int main()
{

    cin >> a >> b >> c  >> d >> e ;
    double xmax = sqrt(pow(b / a, 2) - 2 * (c/a)) ;
    double start = -xmax ;
    double ed = xmax ;
    for(double l = -xmax ; l<ed ; l+=0.5)
    {
        double r =min( l + 0.5 , ed) ;
        int iter ;
        if(f(l) * f(r) < 0)
        {
            double root = bisection(l, r, iter) ;
            cout << root <<endl;
            cout << "Interval: [" << l << ", " << r << "]\n";
            cout << "Root = " << root << endl;
            cout << "Iterations = " << iter << "\n\n";
        }
    }

    return 0;
}


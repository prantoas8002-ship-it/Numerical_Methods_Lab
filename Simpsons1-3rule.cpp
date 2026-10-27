#include<bits/stdc++.h>
using namespace std;
double f(double x)
{
    return 1/(1+x*x) ;
}
int main()
{
    double l, u, h ;
    cin >> l >> u >> h ;
    int n = (u-l) / h ;
    double y[n+1] ;

    if(n % 2 != 0)
    {
        cout << "not even number of interval" ;
        return 0;
    }


    for(int i=0 ; i <=n ; i++)
    {
        double x = l + i*h ;
        y[i] = f(x) ;
    }
    double sum = y[0] + y[n] ;

    for(int i=1 ; i<n ; i++)
    {
        if(i % 2 != 0)
            sum += 4*y[i] ;
        else
            sum += 2*y[i] ;
    }
    double ans = (h/3.0) * sum ;
    cout << ans << endl;
    return 0;
}

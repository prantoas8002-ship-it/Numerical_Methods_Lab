#include<bits/stdc++.h>
using namespace std;
double f(double x)
{
    return sqrt(x) ;
}
int main()
{
    double l , u ;
    int n ;
    cin >> l >> u >> n;
    double h = (u-l) / n ;
    double y[n + 1] ;

    if(n % 3 != 0)
    {
        cout << "interval is not multiple of 3" << endl;
        return 0;
    }

    for(int i=0 ; i<=n ; i++)
    {
        double x = l + i * h ;
        y[i] = f(x) ;
    }
    double sum = y[0] + y[n] ;

      for(int i=1 ; i<n ; i++)
    {
       if(i % 3 == 0)
            sum += 2*y[i] ;
            else sum += 3*y[i] ;
    }
    double ans = (3.0/8) * h * sum ;

    cout << ans << endl;
    return 0;
}

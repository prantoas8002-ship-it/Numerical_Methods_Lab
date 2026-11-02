#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    double x[n] , d[n][n] ;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            d[i][j] = 0;
        }
    }
    for(int i=0 ; i<n ; i++)
        cin >> x[i] ;
    for(int i=0 ; i<n ; i++)
        cin >> d[i][0] ;

    // difference table

    for(int j=1 ; j<n ; j++)
    {
        for(int i=0 ; i<n-j ; i++)
        {
            d[i][j] = d[i+1][j-1] - d[i][j-1] ;
        }
    }

    double h = x[1] - x[0] ;
    double value ;
    cin >> value;
    double u = (value - x[0]) / h;
    double term = 1 ;
    double ans = d[0][0];
    for(int i=1 ; i<n ; i++)
    {
        term *= (u - (i-1)) / i ;
        ans += term * d[0][i] ;
    }
    cout  << "-----solution------" << endl;
    cout << ans << endl;
    // printing difference table
       cout << "----difference table----" << endl;
    for(int i=0; i< n ; i++)
    {
        for(int j=0 ; j<n-i ; j++)
        {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
    // equation
    cout << "----- equation ------" << endl;
    cout << "y(x) = " << d[0][0] ;
    for(int i=1 ; i<n ; i++)
    {
        double coef = d[0][i] ;
        for(int j=1 ; j<=i ; j++)
        {
            coef = coef / j ;
        }
        coef = coef / pow(h , i) ;
        if(coef == 0) continue ;
        cout << " + (" << coef << ")" ;
        for(int j=0 ; j<i ; j++)
        {
            cout << "(x-" << x[j] << ")" ;
        }
    }
    return 0;
}
/*
4
3 5 7 9
180 150 120 90
*/

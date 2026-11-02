#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n ;
    cin >> n ;
    double x[n], d[n][n] ;
    for(int i=0 ; i< n ; i++)
        for(int j=0 ; j<n ; j++)
            d[i][j] = 0;
    for(int i=0 ; i<n ; i++)
        cin >> x[i] ;
    for(int i=0 ; i<n ; i++)
        cin >> d[i][0] ;

    //difference table
    for(int j=1 ; j<n ; j++)
    {
        for(int i=0 ; i<n-j ; i++)
        {
            d[i][j] = d[i+1][j-1] - d[i][j-1] ;
        }
    }
    //print differencec table
    cout << "--------difference table----------" << endl;
    for(int i=0 ; i< n ; i++)
    {
        for(int j=0 ; j<n-i ; j++)
            cout << d[i][j] << " ";
        cout << endl;
    }

    double value;
    cin >> value ;
    double h = x[1] - x[0] ;
    double u = (value - x[n-1]) / h ;
    double term = 1;
    double ans = d[n-1][0];
    for(int i=1 ; i<n ; i++)
    {
        term *= (u+(i-1)) / i ;
        ans += term * d[n-i-1][i] ;
    }

    cout << "--------solution----------" << endl;
    cout << ans << endl;

    cout << "--------equation----------" << endl;

    cout << "f(x) = " << d[n-1][0] ;
    for(int i=1 ; i<n ; i++)
    {
        double coef = d[n-i-1][i] ;

        for(int j=1; j<=i ; j++)
            coef /= j;

        coef /= pow(h, i) ;

        if(coef == 0) continue ;

        cout << "+(" << coef << ")" ;

        for(int j=0 ; j<i ; j++)
            cout << "(x-" << x[n-j-1] << ")" ;
    }
    return 0;
}
/*
5
24 28 32 36 40
28.06 30.19 32.75 34.94 40
*/


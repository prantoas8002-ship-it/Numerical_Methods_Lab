#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n ;
    double x[n] , d[n][n] ;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j< n; j++)
            d[i][j] = 0;
        cout <<endl;
    }
    for(int i=0 ; i< n ; i++)
        cin >> x[i] ;
    for(int i=0 ; i< n; i++)
        cin >> d[i][0] ;

        //difference table
    for(int j=1 ; j<n ; j++)
    {
        for(int i=0 ; i<n-j ; i++)
        {
            d[i][j] = (d[i+1][j-1] - d[i][j-1]) / (x[i+j] - x[i]) ;
        }
    }

    cout << "-------difference table--------" << endl;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n-i ; j++)
        {
            cout << d[i][j] << " " ;
        }
        cout << endl;
    }

    double value;
    cin >> value;
    double term = 1;
    double ans = d[0][0];
    for(int i=1 ; i<n ; i++)
    {
        term *= value - x[i-1] ;
        ans += term*d[0][i] ;
    }
    cout << "------solution--------" << endl;
    cout << ans << endl;

    cout << "--------equation--------" << endl;
    cout << "f(x) = " << d[0][0] ;
    for(int i=1 ; i<n ; i++)
    {
        if(d[0][i] == 0) continue;
        cout << "+(" << d[0][i] << ")" ;
        for(int j=0 ; j<i ; j++)
            cout << "(x-" << x[j] << ")" ;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    double a[n][2*n], b[n], x[n] ;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
            cin >> a[i][j] ;

        for(int j=n ; j< 2*n ; j++)
        {
            if(j-n == i)
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
    }


    for(int i=0 ; i<n ; i++)
        cin >> b[i] ;

    // jordan
    for(int i=0 ; i<n; i++)
    {
        double pivot = a[i][i];
        for(int j=0 ; j<2*n ; j++)
        {
            a[i][j] = a[i][j] / pivot ;
        }
        for(int k=0 ; k<n ; k++)
        {
            if(k != i)
            {
                double f = a[k][i] ;
                for(int j=0 ; j<2*n ; j++)
                {
                    a[k][j] -= f*a[i][j] ;
                }
            }
        }
    }

    for(int i=0 ; i<n ; i++)
    {
        x[i] = 0 ;
        for(int j=0 ; j< n ; j++)
        {
            x[i] += a[i][j+n] * b[j] ;
        }
    }

    for(int i=0 ; i<n ; i++)
    {
        cout << x[i] << endl;
    }

    return 0;
}

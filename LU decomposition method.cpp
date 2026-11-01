#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    double a[n][n], b[n], L[n][n], U[n][n];
    double x[n], y[n] ;

    //input

    for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<n ; j++)
        {
            cin >> a[i][j] ;
            L[i][j] = 0;
            U[i][j] = 0 ;
        }

    for(int i=0 ; i<n ; i++)
        cin >> b[i] ;


    // LU decomposition
    for(int i =0 ; i<n ; i++)
    {
        for(int j = i ; j<n ; j++)
        {
            double sum = 0;
            for(int k=0 ; k<i ; k++)
            {
                sum += L[i][k] * U[k][j];
            }
            U[i][j] = a[i][j] - sum ;
        }
        L[i][i] = 1 ;

        for(int j = i+1 ; j<n ; j++)
        {
            double sum = 0 ;
            for(int k=0 ; k<i ; k++)
            {
                sum += L[j][k]*U[k][i] ;
            }
            L[j][i] = (a[j][i] - sum)/U[i][i] ;
        }

    }

    //forward substitution
    for(int i=0 ; i< n ; i++)
    {
        y[i] = b[i] ;
        for(int j=0 ; j<i ; j++)
        {
            y[i] -= L[i][j] * y[j]
        }
        y[i] /= L[i][i] ;
    }


    //backward substitution
    for(int i=n-1 ; i>=0 ; i--)
    {
        x[i] = y[i] ;
        for(int j=i+1 ; j<n ; j++)
        {
            x[i] -= U[i][j] * x[j] ;
        }
        x[i] /= U[i][i] ;
    }



    cout << "L :" << endl;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            cout << L[i][j] << " " ;
        }
        cout << endl;
    }

    cout << " U : " << endl;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            cout << U[i][j] << " " ;
        }
        cout << endl;
    }
    cout << "soln:" << endl;
    for(int i=0 ; i<n ; i++)
    {
        cout << x[i] << endl;
    }

    return 0;
}

/*
3
1 2 3
4 5 6
7 8 9
1 2 3
*/

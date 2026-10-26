#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    double a[n][n+1];
    for(int i=0 ; i<n ; i++)
    {
         for(int j=0 ; j<=n ; j++)
        cin >> a[i][j];

    }

    //forward elemination
    for(int i=0 ; i<n ; i++)
    {
        for(int j=i+1 ; j<n ; j++)
        {
            double factor = a[j][i] / a[i][i] ;

            for(int k=i ; k<=n ; k++)
            {
                a[j][k] = a[j][k] - (factor * a[i][k]) ;
            }
        }
    }

    double x[n];

    for(int i=n-1 ; i>=0 ; i--)
    {
        x[i] = a[i][n] ;
        for(int j=i+1 ; j<n ; j++)
        {
            x[i] = x[i] - (x[j] * a[i][j]) ;
        }
        x[i] = x[i] / a[i][i] ;
    }
/*
     for(int i=0 ; i<n ; i++)
     {
         for(int j=0 ; j<=n ; j++)
        cout <<  a[i][j] << " ";
        cout << endl;
     }
     */


     bool nosoln = false;
     bool infsoln = false;

     for(int i=0 ; i<n ; i++)
     {
         bool zero = true ;
         for(int j=0 ; j<n ; j++)
         {
             if(a[i][j] > 1e-6)
             {
                 zero = false;
                 break;
             }
         }
         if(zero)
         {
             if(a[i][n] > 1e-6)
             {
                 nosoln = true;
             }
             else infsoln = true;
         }
     }

     if(nosoln)
     {
         cout << " NO solution" << endl;
     }
     else if(infsoln)
     {
         cout << "infinity solution" << endl;
     }
     else cout << " unique solution" << endl;

     cout << endl;
     cout << fixed << setprecision(4) ;

     for(int i=0 ; i<n ; i++)
        cout << x[i] << endl;



    return 0;
}

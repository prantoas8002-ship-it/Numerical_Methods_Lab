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
        {
            cin >> a[i][j];
        }
    }
    //main logic
    for(int i=0 ; i<n ; i++)
    {
        double pivot = a[i][i];
        for(int j=0 ; j<=n ; j++)
        {
            a[i][j] /= pivot ;
        }
        for(int k=0 ; k<n ; k++)
        {
            double factor = a[k][i];
            if(k!=i)
            {
                for(int j=0 ; j<=n ; j++)
                    a[k][j] = a[k][j] - ( factor * a[i][j]) ;
            }

        }
    }

    cout << fixed << setprecision(4);
    for(int i=0; i<n ; i++)
    {
        cout << a[i][n] << endl;
    }
    return 0;
}

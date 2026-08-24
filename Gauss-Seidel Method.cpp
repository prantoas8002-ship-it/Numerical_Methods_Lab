#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n ;
    cin.ignore();

    vector<vector<double>> matrix(n, vector<double>(n,0));
    vector<double> value(n,0);

    string vars = "xyz";
    string input;

    for(int i=0 ; i<n ; i++)
    {
        getline(cin, input);
        int eqPos = input.find('=');
        string left = input.substr(0, eqPos);
        string right = input.substr(eqPos+1);

        value[i] = stod(right);

        int sign = 1 ;    // sign ashte pare + or -
        string number = "";
        // ar variable ashte pare ar ashte pare coefficient(numbers)

        for(int j=0 ; j<left.size() ; j++)
        {
            if(left[j] == '+')
            {
                sign = 1;
            }
            else if(left[j] == '-')
            {
                sign = -1;
            }
            else if(isdigit(left[j]))
            {
                number += left[j];
            }
            else if(isalpha(left[j]))
            {
                double coefficient;
                if(number.empty())
                {
                    coefficient = 1;
                }
                else
                {
                    coefficient = stod(number);
                }

                coefficient = coefficient * sign ;
                int col = vars.find(left[j]);

                matrix[i][col] = coefficient ;

                number.clear();
                sign = 1;
            }
        }
    }

    // logic of Gauss-Seidel Method  ...

    vector<double> x(n,0);
    double err = 1e-6;

    for(int iterate = 0 ; iterate<100 ; iterate++)
    {
        vector<double> oldX = x;

        for(int i=0 ; i<n ; i++)
        {
            double sum = 0;
            for(int j=0; j<n ; j++)
            {
                if(i != j)
                {
                    sum += ( matrix[i][j] * x[j] );
                }
            }
            x[i] = ( value[i] - sum) / matrix[i][i];
        }

        bool done = true ;

        for(int i=0 ; i<n ; i++)
        {
            if(fabs( oldX[i] - x[i] ) > err)
            {
                done = false;
            }
        }

        if(done) break;
    }



    //printing matrix and value

    cout << "coefficient matrix : " << endl;

    for(auto x : matrix)
    {
        for(auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    cout << "value matrix : ";

    for(auto x : value)
    {
        cout << x << " ";
    }

    //solution

    cout << "solution" << endl;
    for(auto a : x)
    {
        cout << a << " ";
    }

    return 0;
}


/*
3
10x+y+z=12
2x+10y+z=13
2x+2y+10z=14
*/


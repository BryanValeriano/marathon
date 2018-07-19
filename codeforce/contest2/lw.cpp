#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int M[n];
    int novo[n];
    int somat;
    int max = -100000;
    int min = 100000;


    for(int i = 0; i < n; i++)
    {
        cin >> M[i];
        novo[i] = M[i];
        somat += M[i];
        if(M[i] > max) max = M[i];
        if(M[i] < min) min = M[i];
    }

    if(n > 2)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(novo[i] + 1 <= max && novo[j] - 1 >= min && j != i)
                {
                    novo[i] += 1;
                    novo[j] -= 1;
                }
                else if(novo[i] - 1 >= min && novo[j] + 1 <= max && j != i)
                {
                    novo[i] -= 1;
                    novo[j] += 1;
                }
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << novo[i] << " ";
    }

}    

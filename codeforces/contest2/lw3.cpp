#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int M[n];
    int novo[n][2];
    int somat;
    int max = -100000;
    int min = 100000;
    set<int> M1;
    set<int> novo1;

    for(int i = 0; i < n; i++)
    {
        cin >> M[i];
        novo[i][0] = M[i];
        M1.insert(M[i]);
        novo1.insert(M[1]);
        somat += M[i];
        if(M[i] > max) max = M[i];
        if(M[i] < min) min = M[i];
    }

    for(int i = 0; i < n; i++)
    {
        novo[i][1] = 0;
    }

    int p = 0;
    if(n > 2)
    {
        while(p < n)
        {
            for(int j = p; j < n; j++)
            {
                if(novo[p][1] != 9999 && novo[j][1] != 9999 && novo[p][0] + 1 <= max && novo[j][0] - 1 >= min && j != p)
                {
                    
                    novo[p][0] += 1;
                    novo[p][1] = 9999;
                    novo[j][0] -= 1;
                    novo[j][1] = 9999;
                    
                    p++;
                    break;
                }
                else if(novo[p][1] != 9999 && novo[j][1] != 9999 && novo[p][0] - 1 >= min && novo[j][0] + 1 <= max && j != p)
                {
                    novo[p][0] -= 1;
                    novo[p][1] = 9999;
                    novo[j][0] += 1;
                    novo[j][1] = 9999;
                    p++;
                    break;
                }
                else if(j + 1 == n)
                {
                    p++;
                    break;
                }
            }
            
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << novo[i][0] << " ";
    }
    cout << endl;
    return 0;
}

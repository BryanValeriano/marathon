#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int M[n];
    int novo[n][2];
    map<int, int> novoset;
    int somat;
    int max = -100000;
    int min = 100000;
    

    for(int i = 0; i < n; i++)
    {
        cin >> M[i];
        novo[i][0] = M[i];
        if(! novoset.size()) novoset.insert(make_pair(M[i], 0));
        for (map<int,int>::iterator it=novoset.begin(); it!=novoset.end(); ++it)
        {
            if(it->first == M[i]) it->second += 1;
            else novoset.insert(make_pair(M[i], 0));
        }
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
    for (map<int,int>::iterator it=novoset.begin(); it!=novoset.end(); ++it)
    {
        cout << "(" << it->first << ", " << it->second << ") ";
    }
    cout << endl;
    return 0;
}

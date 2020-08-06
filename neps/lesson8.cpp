#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t[3];
    int i = 0;
    int sinal = 0;
    int best = 0; 

    do
    {
        cin >> t[i];
        i++;
    }
    while(i < 3);

    while(sinal < 3)
    {
        for(int j = 1; j < 3; j++)
        {
            if(t[j] < t[j-1] and t[j] <t[best])
            {
                best = j;
            }
            else if(t[j-1] < t[best])
            {
                best = j - 1;
            }
        }
        cout << best + 1 << endl;
        sinal ++;
        t[best] = 9999;     
        best = 0;
    }
}


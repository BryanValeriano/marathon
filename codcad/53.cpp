#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
 
int main()
{
    int n, k;
    cin >> n;
    int row[n];
    for(int i = 0; i < n; i++)
        cin >> row[i];
    cin >> k;
    for(int i = 0; i < n; i++)
    {
        int meio = n/2;
        int ini = 0;
        int fim = n-1;
        while(ini <= fim)
        {
            meio = (fim + ini)/2;
            if(row[i] + row[meio] == k)
            {
                cout << row[i] << " " << row[meio] << endl;
                return 0;
            }
            else if(row[i] + row[meio] < k) ini = meio + 1;
            else fim = meio - 1;
        }
    }
    
    
    return 0;
}


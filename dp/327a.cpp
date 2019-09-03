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
    int n;
    cin >> n;
    int tam[n];
    int cont[n];
    memset(cont, 0, sizeof cont);
    cin >> tam[0];
    cont[0] += tam[0]; 
    for(int i = 1; i < n; i++)
    {
        cin >> tam[i];
        cont[i] += tam[i] + cont[i-1];
    }
    int maxx = 0;
    int saldo = 0;
    int inicio = 0;
    int fim = 0;
    for(int i = 1; i < n; i++)
    {
        saldo = 0;
        for(int j = i; j < n; j++)
        {
            if(cont[j] == cont[j - 1]) saldo++;
            else saldo--;
            if(saldo > maxx)
            {
                maxx = saldo;
                inicio = i;
                fim = j;
            }
        }
    }
    if(inicio == 1 && tam[1] == tam[0]) inicio = 0; 

    for(int i = inicio; i <= fim; i++)
    {
        tam[i] = 1 - tam[i];
    }
    cout << accumulate(tam, tam + n, 0) << endl;
    //cout << "inicio: " << inicio << " fim: " << fim << " saldo: " << maxx << endl;

    return 0;
}


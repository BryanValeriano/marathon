#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;


int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    ll s[n];
    ll c[n];

    for(int i = 0; i < n; i++)
        cin >> s[i];
    
    for(int i = 0; i < n; i++)
        cin >> c[i];


    ll valores = INT_MAX;
    ll valtemp = 0;
    ll preco;
    int sinal = 0;
    int fim = 0;
    int pos;

    for(int i = 1; i < n; i++)
    {
        pos = i;
        for(int k = 0; k < pos; k++)
            if(s[pos] > s[k] && c[pos] + c[k] < valores)
            {
               valores = c[k];
               valores += c[pos];
               preco = INT_MAX;
               sinal = 0;
                for(int j = pos; j < n; j++)
                    if(s[j] > s[pos])
                    {
                         preco = min(preco, c[j]);
                         sinal = 1;
                    }
                if(sinal == 1){ valtemp = valores + preco; fim=1;}

            }       
     }
    if(fim == 1)cout << valtemp << endl;    
    else cout << -1 << endl;






    return 0;
}


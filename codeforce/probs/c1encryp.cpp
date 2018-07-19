#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;

ll calc(ll inicio, ll table[], ll n, ll maxx, ll p)
{
    ll soma = 0;
    for(ll i = 0; i < n - 1; i++)
    {
        soma = table[i] % p + (table[n - 1] - table[i]) % p;
        if(soma > maxx) maxx = soma;
    }
    return maxx;
}
int main(){
    ios_base::sync_with_stdio(false);

    ll n, p;
    ll sum = 0;
    ll value = 0;

    cin >> n >> p;
    ll table[n];
    
    for(ll i = 0; i < n; i++)
    {
        cin >> value;
        sum += value;
        table[i] = sum;
    } 

    cout << calc(1, table, n, 0, p) << endl;
   
    return 0;
}


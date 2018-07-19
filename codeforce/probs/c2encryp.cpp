#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
ll n, k, p;
ll table[200005];
ll dp[200005];

ll calc(int n)
{
    if(n == k) return 0;
    if(dp[n] != 0) return dp[n];

    for(ll i = 0; i < n - 1; i++)
    {
         
    }
    dp[n] = q;
    return q;
}

int main(){
    ios_base::sync_with_stdio(false);

    ll sum = 0;
    ll value = 0;

    cin >> n >> k >> p;
    ll table[n];
    
    for(ll i = 0; i < n; i++)
    {
        cin >> value;
        sum += value;
        table[i] = sum;
    } 

    cout << calc(n) << endl;
   
    return 0;
}


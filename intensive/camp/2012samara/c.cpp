#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
int n, m;
ll dp[205][205];

ll steve(int atual, int tam) {
    if(atual > m) return 0;
    if(tam == n) return 1;
    ll &e = dp[atual][tam];
    if(e != -1) return e;
    ll R = 0;
    ll L = 0;
    L = steve(atual + 1, tam) % mod; 
    R = steve(atual + 1, tam+1) % mod;
    return e = (L+R)%mod;
}

int main()
{
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    cin >> n >> m;
    ll resp = 0;
    memset(dp, -1, sizeof dp);
    resp += steve(0,0) % mod;
    cout << resp%mod << endl; 
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;

const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

ll n,m;

ll ele(ll base, ll e) {
    ll ans = 1;

    while(e) {
        if(e&1) ans = (ans * base) % MOD;
        base = (base * base) % MOD;
        e >>= 1;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    ll k = 2;

    cin >> n >> m;

    ll ans = ele(4,n*m);


    ll wtf = (n+m-k);
    ll wtf2 = ((n*m)-1 - wtf);

    ll d = ele(2, wtf);
    ll q = ele(4, wtf2);
    ll b = (d*q) % MOD;

    b = ele(b, MOD-2);
    
    ans = (ans * b) % MOD;

    cout << ans << endl;

    return 0;
}


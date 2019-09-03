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

const int T = 1e6 + 10;
const int MOD = 1e9 + 7;
ll a,b,n;
ll f[T];

bool sum(ll x) {
    bool flag = true;
    while(x) {
        flag &= ((x % 10) == a or (x % 10) == b);
        x /= 10;
    }
    return flag;
}

ll exp(ll base, ll e) {
    ll ans = 1;
    base %= MOD;
    while(e) {
        if(e & 1) ans = (ans * base) % MOD;
        base = (base * base) % MOD;
        e >>= 1;
    }
    return ans;
}

ll fat(ll x) {
    if(f[x] != -1) return f[x];
    return f[x] = (x * fat(x-1)) % MOD;
}

ll bin(ll x, ll y) {
    ll baixo = (fat(x) * fat(y)) % MOD;
    return ( fat(n) * exp(baixo,MOD-2) ) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    memset(f, -1, sizeof f);
    f[0] = 1;
    f[1] = 1;
    f[2] = 2;
    cin >> a >> b >> n;

    ll xa;
    ll xb;
    ll ans = 0;

    for(int i = 0; i <= n; i ++) {
        xa = a*i;
        xb = b*(n-i);
        if(sum(xa+xb)) {
            ans = (ans + bin(i,n-i)) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}


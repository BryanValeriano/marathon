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

const int T = 2e6 + 10;
const int MOD = 1300031;
ll f[T];
ll n,c;
ll x,y,d;

void gcd(ll a, ll b) {
    if(b == 0) { x = 1; y = 0; d = a; return; }
    gcd(b, a%b);
    ll x1 = y;
    ll y1 = x - (a/b) * y;
    x = x1;
    y = y1;
}

ll fat(ll x) {
    if(x == 1) return 1;
    if(f[x] != -1) return f[x];
    return f[x] = (x * fat(x-1)) % MOD;
}

ll solve() {
    ll t = fat(n+c-1);
    ll u = fat(n-1);
    gcd(u,MOD);
    u = x;
    while(u < 0) { u += (MOD/d); }
    ll z = fat(c);
    gcd(z,MOD);
    z = x;
    while(z < 0) { z += (MOD/d); }
    cout << (((t * u) %MOD) * z) % MOD << endl;
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    memset(f, -1, sizeof f);
    while(tc--) {
        cin >> n >> c;
        solve();
    }
    return 0;
}


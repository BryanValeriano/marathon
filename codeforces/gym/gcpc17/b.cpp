#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int mod = 1e9 + 7;

ll xp(ll b, ll e) {
    if (e == 0) return 1;
    ll c = xp(b, e >> 1);
    c = c * c % mod;
    if (e & 1) c = c * b % mod;
    return c;
}

ll inv(ll x) {
    return xp(x, mod - 2);
}

vector<ll> divs(ll x) {
    vector<ll> ds;
    for (ll i = 2;i * i <= x;i++) {
        if (x % i == 0) {
            ds.push_back(i);
            ds.push_back(x / i);
        }
    }
    sort(ds.begin(), ds.end());
    ds.pop_back();
    return ds;
}

int main() {
    ios_base::sync_with_stdio(false);
    
    ll n, m, c;
    cin >> n >> m >> c;
    c = xp(c, n);
    ll ans = 0;
    map<ll, ll> memo;
    for (auto& d : divs(m)) {
        ll tot = xp(c, m);
        for (auto& d2 : divs(m)) {
            tot -= memo[d2];
            tot %= mod;
        }
        tot *= inv(d);
        tot = (tot % mod + mod) % mod;
        memo[d] = tot;
    }
    cout << ans << endl;
    return 0;
}
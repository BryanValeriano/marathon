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
const ll MOD = 998244353;
const int T = 1e7;

vii v;
map<int,int> bag;
ll win[T], lose[T];
ll f[T];

ll ele(ll base, ll e) {
    ll ans = 1;
    while(e) {
        if(e&1) ans = (ans*base)%MOD;
        base = (base*base)%MOD;
        e >>= 1;
    }
    return ans;
}

ll inv(ll x) {
    return ele(x,MOD-2);
}

ll choose(ll n, ll k) {
    if(n < k) return 0;
    return (f[n]*inv((f[n-k]*f[k])%MOD))%MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,k; cin >> n >> k;

    if(k==1) {
        cout << n << endl;
        return 0;
    }

    f[0] = 1;
    for(ll i = 1; i < T; i++) f[i] = (i*(f[i-1]))%MOD;

    for(int i = 0; i < n; i++) {
        int l,r; cin >> l >> r;
        v.eb(l,r+1);
        bag[l]++; bag[r+1]++;
    }

    int aux = 1;
    for(ii x : bag) bag[x.fi] = ++aux;
    for(int i = 0; i < n; i++) {
        win[bag[v[i].fi]]++;
        lose[bag[v[i].se]]--;
    }

    ll ans = 0;
    ll ativo = 0;

    for(int i = 1; i < T; i++) {
        int novo = win[i];
        ativo += win[i]+lose[i];
        if(novo > 0 and ativo >= k) {
            for(int j = 1; j <= novo; j++) {
                ans = (ans + choose(ativo-j,k-1))%MOD;
            }
        }
    }

    cout << ans << endl;
    return 0;
}


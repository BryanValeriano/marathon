#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
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
const ll MOD = 1e9 + 7;
const int T = 2e5;

ll f[T];
bitset<T> crivo;
vector<ll> primes;
vector<int> degrees;
ll n,m;

void pre() {
    for(int i = 2; i < T; i++) {
        if(!crivo[i]) {
            primes.pb(i);
            for(int j = i+i; j < T; j += i) crivo[j] = 1;
        }
    }
}

void decop(ll x) {
    for(int i = 0; i < primes.size() and primes[i]*primes[i] <= x; i++) {
        int dg = 0;
        while(x % primes[i] == 0) x /= primes[i], dg++;
        if(dg) degrees.pb(dg);
    }
    if(x > 1) degrees.pb(1);
}

ll ele(ll base, ll e) {
    ll ans = 1;
    while(e) {
        if(e&1) ans = (ans * base) % MOD;
        base = (base * base) % MOD;
        e >>= 1;
    }
    return ans;
}

ll fat(ll x) {
    if(~f[x]) return f[x];
    return f[x] = (x * fat(x-1)) % MOD;
}

ll choose(ll a, ll b) {
    ll x = a+b-1;
    ll y = fat(b);
    ll z = fat(a-1);
    return fat(x)*ele((y*z)%MOD,MOD-2)%MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    pre();
    memset(f, -1, sizeof f);
    f[0] = f[1] = 1;
    cin >> n >> m;
    decop(m);
    ll ans = 1;
    for(ll x : degrees) ans = (ans * choose(n,x)) % MOD;
    cout << ans << endl;
    return 0;
}


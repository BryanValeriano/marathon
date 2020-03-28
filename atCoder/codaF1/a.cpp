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
const int T = 1e4 + 3;
const int N = 1e3 + 2;
const int OK = 1e6 + 10;

bitset<N> crivo;
int maxDiv[OK];
vector<int> primes;
ll v[T];

void init() {
    for(int i = 2; i < N; i++) {
        if(!crivo[i]) {
            primes.pb(i);
            for(int j = i+i; j < N; j += i) crivo[j] = 1;
        }
    }
}

ll expo(ll base, ll e) {
    ll ans = 1;
    while(e) {
        if(e&1) ans = (ans * base) % MOD;
        base = (base * base) % MOD;
        e >>= 1;
    }
    return ans;
}

void decop(int x) {
    for(int i = 0; i < primes.size() and primes[i]*primes[i] <= x; i++) {
        int d = 0;
        while(x % primes[i] == 0) d++, x /= primes[i];
        maxDiv[primes[i]] = max(maxDiv[primes[i]], d);
    }
    if(x > 1) maxDiv[x] = max(maxDiv[x],1);
}

int main() {
    ios_base::sync_with_stdio(false);
    init();
    int n; cin >> n;
    ll tira = 0;

    for(int i = 0; i < n; i++) {
        cin >> v[i];
        decop(v[i]);
    }

    ll acum = 1;
    for(ll i = 0; i < OK; i++) {
        ll ok = 1;
        while(maxDiv[i]) ok = (ok * i) % MOD, maxDiv[i]--;
        if(ok > 1) acum = (acum * ok)%MOD;
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ll ok = (acum*expo(v[i],MOD-2))%MOD;
        ans = (ans + ok) % MOD;
    }
    cout << ans << endl;
    return 0;
}


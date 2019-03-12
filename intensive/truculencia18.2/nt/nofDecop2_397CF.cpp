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

const int T = 1e5 + 10;
const ll MOD = 1000000007;
ll n;

vector<int> primes;
bitset<T> crivo;
ll f[T];
map<int,int> vezes;

void gen() {
    for(int i = 2; i < T; i++) {
        if(!crivo[i]) {
            primes.pb(i);
            for(int j = i+i; j < T; j += i) crivo[j] = true;
        }
    }
}

void decop(int x) {
    int iter = 0;
    if(x == 1) return;
    while(iter < primes.size() and primes[iter] * primes[iter] <= x) {
        while(x % primes[iter] == 0) vezes[primes[iter]]++, x /= primes[iter];
        iter++;
    }
    if(x != 1) vezes[x]++;;
}

ll fat(ll x) {
    if(f[x] != -1) return f[x] % MOD;
    return f[x] = (x * fat(x-1)) % MOD;
}

ll exp(ll base, ll e) {
    ll ans = 1;
    while(e) {
        if(e&1) ans = (ans * base) % MOD;
        base = (base * base) % MOD;
        e >>= 1;
    }
    return ans % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    gen();
    memset(f, -1, sizeof f);
    f[0] = f[1] = 1;

    cin >> n;
    ll x;
    ll ans = 1;
    for(int i = 0; i < n; i++) { 
        cin >> x; 
        decop(x);
    } 

    for(auto x : vezes) {
        int pr = x.se;
        if(pr) {
            ll cima = fat(n + pr - 1);
            ll baixo = (fat(n-1) * fat(pr)) % MOD;
            ll tmp = (cima * exp(baixo, MOD-2)) % MOD;
            ans = (ans * tmp) % MOD;
        }
    }

    cout << ans << endl;    

    return 0;
}


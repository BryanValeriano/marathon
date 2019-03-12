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
const int MOD = 1000000007;
int n;

vector<int> primes;
bitset<T> crivo;
ll vezes[T];
ll f[T];

ll fixo;
ll rep;

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
    while(primes[iter] * primes[iter] <= x) {
        while(x % primes[iter] == 0) vezes[primes[iter]]++, x /= primes[iter];
        iter++;
    }

    if(x != 0) vezes[x]++;
}

ll fat(ll x) {
    if(x == 1) return 1;
    if(f[x] != -1) return f[x];
    return f[x] = (x * fat(x-1)) % MOD;
}

ll exp(ll base, ll e) {
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
    vector<int> reps;
    gen();
    memset(f, -1, sizeof f);
    f[0] = 1;

    cin >> n;
    ll x;
    for(int i = 0; i < n; i++) { cin >> x; decop(x); }

    for(int i = 2; i < T; i++) 
        if(vezes[i]) {
            fixo++, rep += vezes[i]-1;
            if(vezes[i]-1) reps.pb(vezes[i]-1);
        }

    if(fixo == 0) { cout << 1 << endl; return 0; } 
   
    ll ans = 1;
    ll tmp = 1;
    ll um = 0;

    um = n;
    if(fixo > 1 and fixo <= n)  tmp = ( fat(n) * exp(fat(n-fixo),MOD-2) ) % MOD;

    if(fixo > 1 and fixo < n) {
        ll casa1 = n-fixo;
        ans = ( fat(rep+casa1) * exp(fat(casa1), MOD-2) ) % MOD;
        for(auto r : reps) ans = (ans * exp(fat(r),MOD-2)) % MOD;
    }

    ans = (ans != 1 or tmp != 1)? (((ans*tmp) % MOD) + um) % MOD : um % MOD;

    cout << ans << endl;
    return 0;
}


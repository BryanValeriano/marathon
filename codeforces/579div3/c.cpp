#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;

const int T = 1e6 + 5;
bitset<T> crivo;
vector<ll> primes;
vii divs;

void init() {
    for(int i = 2; i < T; i++) {
        if(!crivo[i]) {
            primes.pb(i);
            for(int j = i+i; j < T; j += i) crivo[j] = 1;
        }
    }
}

void decop(ll x) {
    for(int i = 0; i < primes.size() and primes[i]*primes[i] <= x; i++) {
        ii at = mk(primes[i],0);
        while(x % primes[i] == 0) {
            x /= primes[i];
            at.se++;
        }
        if(at.se) divs.pb(at);
    }

    if(x > 1) divs.eb(x,1);
}

ll solve() {
    ll ans = 1;
    for(int i = 0; i < divs.size(); i++) ans *= (divs[i].se+1);
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    init();
    int n; cin >> n;
    ll gcd = -1;

    while(n--) {
        ll x; cin >> x;
        if(gcd == -1) gcd = x;
        gcd = __gcd(gcd,x);
    }

    decop(gcd);
    cout << solve() << endl;
    
    return 0;
}


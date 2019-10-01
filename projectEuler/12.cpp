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

const int T = 1e7 + 3;
bitset<T> crivo;
vector<ll> primes;

void init() {
    for(int i = 2; i < T; i++) {
        if(!crivo[i]) {
            primes.pb(i);
            for(int j = i+i; j < T; j += i) crivo[j] = 1;
        }
    }
}

ll numDiv(ll x) {
    ll ans = 1;
    for(int i = 0; i < primes.size() and primes[i]*primes[i] <= x; i++) {
        ll power = 0;
        while(x % primes[i] == 0) { x /= primes[i]; power++; }
        ans *= (power+1);
    }
    if(x != 1) ans *= 2;
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    init();
    for(ll i = 1; i <= 1000000; i++) {
        ll x = numDiv(i*(i+1)/2);
        if(x > 500) { cout << (i*(i+1)/2) << " " << x << '\n'; break; }
    }
    return 0;
}


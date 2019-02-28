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

const int T = 1e5;
bitset<T> crivo;
vector<int> primes;

void gen() {
    for(int i = 2; i < T; i++) {
        if(crivo[i] == false) {
            primes.pb(i);
            for(int j = i+i; j < T; j += i) crivo[j] = true;
        }
    }
}

ll phi(ll x) {
    int i = 0;
    ll ans = x;
    while(i < primes.size() and primes[i] * primes[i] <= x) {
        if(x % primes[i] == 0) ans -= ans/primes[i];
        while(x % primes[i] == 0) x /= primes[i];
        i++;
    }
    if(x != 1) ans -= ans/x;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    ll n;
    gen();
    while(~scanf("%lld", &n)) {
        printf("%lld\n", phi(n)/2);
    }
    return 0;
}


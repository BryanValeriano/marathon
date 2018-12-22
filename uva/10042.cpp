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
const int T = 1e6 + 1e5;
vector<ll> primes;
vector<ll> digs;
bitset<T> check;

bool isPrime(ll x) {
    if(x < T and check[x] == false) return true;
    if(x < T and check[x] == true) return false;
    for(int i = 0; i < primes.size(); i++) 
        if(x % primes[i] == 0) return false;
    return true;
}

void crivo() {
    for(ll i = 2; i < T; i++) {
        if(!check[i]) {
            primes.pb(i);
            for(ll j = i+i; j < T; j += i)
                check.set(j,true);
        }
    }
}

void factors(ll x) {
    digs.clear();
    ll i = 0;
    ll PF = primes[i]; while(PF * PF <= x) {
        while(x % PF == 0) {
            digs.pb(PF);
            x /= PF;
        }
        PF = primes[++i];
    }
    if(x != 1) digs.pb(x);
}

ll sumDig(ll x) {
    ll ans = 0;
    while(x != 0) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    crivo();
    int tc; cin >> tc;
    while(tc--) {
        ll x; cin >> x;
        for(ll i = x+1; i <= 1e9 + 90000; i++) {
            if(isPrime(i)) continue;
            factors(i);
            ll a = sumDig(i);
            ll b = 0;
            for(auto y : digs) 
                b += sumDig(y);
            if(a == b) { cout << i << endl; break; }
        }
    }
    return 0;
}


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
typedef vector< pair<ll,ll> > vll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int T = 1e6 + 100;
ll n,b;
vector<ll> primes;
vll primesB;
bitset<T>check;

void crivo() {
    for(ll i = 2; i < T; i++) {
        if(check[i] == false) {
            primes.pb(i);
            for(ll j = i+i; j < T; j += i) check[j] = true;
        }
    }
}

void factor() {
    ll i = 0;
    while(i < primes.size() and primes[i] * primes[i] <= b) {
        while(b % primes[i] == 0) { 
            b /= primes[i];
            if(primesB.size() != 0 and primesB.rbegin()->fi == primes[i]) primesB[primesB.size()-1].se++;
            else primesB.eb(primes[i], 1);
        }
        i++;
    }
    if(b != 1) primesB.eb(b,1);
}

ll lpower(ll n, ll p) {
    ll x = 0;
    while(n) {
        n /= p;
        x += n;
    }
    return x;
}


int main() {
    ios::sync_with_stdio(false);
    crivo();
    cin >> n >> b;
    factor();
    ll ans = INF;
    for(auto x : primesB) 
        ans = min(ans, lpower(n,x.fi)/x.se);
    cout << (ans == INF? 0 : ans) << endl;
    return 0;
}


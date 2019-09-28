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

const int T = 1e7 + 5;
bitset<T> crivo;
vector<ll> primes;

void pre() {
    for(int i = 2; i < T; i++) {
        if(!crivo[i]) {
            primes.pb(i);
            for(int j = i+i; j < T; j+= i) crivo[j] = 1;
        }
    }
}

void fat(ll x) {
    for(int i = 0; i < primes.size() and primes[i] * primes[i] <= x; i++) {
        if(x % primes[i] == 0) {
            cout << primes[i] << endl;
            while(x % primes[i] == 0) x /= primes[i];
        }
    }
    if(x) cout << x << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    pre();
    ll x; cin >> x;
    fat(x);
    return 0;
}


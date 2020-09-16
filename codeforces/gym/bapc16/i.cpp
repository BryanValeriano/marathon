#include <bits/stdc++.h>
using namespace std;

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
const int T = 1e5;
bitset<T> crivo;
vector<ll> primes;

void pre() {
    for(int i = 2; i < T; i++) {
        if(!crivo[i]) {
            primes.pb(i);
            for(int j = i+i; j < T; j += i) crivo[j] = 1;
        }
    }
}

int decop(ll x) {
    ll ans = 0;
    for(int i = 0; i < primes.size() and primes[i]*primes[i] <= x; i++) {
        if(x%primes[i]) continue;
        ans++;
        while(!(x%primes[i])) x /= primes[i];
    }
    return ans+(x>1);
}

int main() {
    ios_base::sync_with_stdio(false);
    pre();
    ll q; cin >> q;
    cout << (decop(q) == 1? "yes\n" : "no\n");
    return 0;
}


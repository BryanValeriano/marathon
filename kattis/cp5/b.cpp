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
const int T = 1e4+2;
bitset<T> crivo;
vector<ll> primes;
ll phi[T];

void init() {
    for(int i = 2; i < T; i++) {
        if(!crivo[i]) {
            primes.pb(i);
            for(int j = i+i; j < T; j += i) crivo[j] = 1;
        }
    }
}

ll eulerPhi(ll x) {
    ll ans = x;
    for(int i = 0; primes[i]*primes[i] <= x; i++) {
        if(x % primes[i] == 0) ans -= ans/primes[i];
        while(x % primes[i] == 0) x /= primes[i];
    }
    if(x != 1) ans -= ans/x;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    init();
    int tc; cin >> tc;
    phi[0] = 1;
    for(int i = 1; i < T; i++) {
        phi[i] = eulerPhi(i);
        phi[i] += phi[i-1];
    }
    while(tc--) {
        int k, n;
        cin >> k >> n;;
        cout << k << " " << phi[n] << endl;
    }
    return 0;
}


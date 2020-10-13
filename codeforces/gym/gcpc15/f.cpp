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
const int T = 1e7+2;
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

ll decop(ll x) {
    ll ans = 1;

    for(int i = 0; i < primes.size() and primes[i]*primes[i] <= x; i++) {
        ll tmp = 0;
        while(x % primes[i] == 0) tmp++, x /= primes[i];
        ans *= (tmp+1);
    }

    cout << x << endl;
    ll s = sqrt(x);

    if(s*s == x or (s+1)*(s+1) == x or (s-1)*(s-1) == x) ans *= 3ll;
    else ans *= 2ll;

    return ans;
}



int main() {
    ios_base::sync_with_stdio(false);
    init();
    ll n;
    cin >> n;
    cout << decop(n) << endl;
    return 0;
}


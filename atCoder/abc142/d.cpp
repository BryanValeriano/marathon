#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
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
const int T = 1e6 + 100;
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

int decop(ll x) {
    if(x == 1) return 1;
    int ans = 1;

    for(int i = 0; i < primes.size() and primes[i]*primes[i] <= x; i++) {
        if(x % primes[i] == 0) {
            ans++;
            while(x % primes[i] == 0) x /= primes[i];
        }
    }

    if(x > 1) ans++;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    init();
    ll a,b; cin >> a >> b;
    cout << decop(__gcd(a,b)) << endl;
    return 0;
}


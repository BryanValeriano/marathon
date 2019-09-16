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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 1e5;
bitset<T> crivo;
vector<ll> primes;
vector<ii> p;
vector<ll> bag;
ll a,b;
int n;

void init() {
    for(int i = 2; i < T; i++) {
        if(!crivo[i]) {
            primes.pb(i);
            for(int j = i+i; j < T; j += i) crivo[j] = 1;
        }
    }
}

void decomp(ll x) {
    for(int i = 0; i < primes.size() and primes[i] * primes[i] <= x; i++) {
        ll vez = 0;
        while(x % primes[i] == 0) { x /= primes[i], vez++; }
        if(vez) p.eb(primes[i],vez);
    }
    if(x > 1) p.eb(x,1);
}

void solve(int at, ll val) {
    if(at == n) { bag.pb(val); return; }
    solve(at+1, val);
    ll acum = 1;
    for(int i = 1; i <= p[at].se; i++) {
        acum *= p[at].fi;
        solve(at+1, val*acum);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    init();
    cin >> a >> b;
    ll gcd = __gcd(a,b);
    decomp(gcd);
    n = p.size();
    solve(0,1);
    sort(bag.begin(), bag.end());

    int n; cin >> n;

    while(n--) {
        ll x,y; cin >> x >> y;
        int pos = lower_bound(bag.begin(), bag.end(), y) - bag.begin();

        if(pos == bag.size()) pos--;
        while(pos > 0 and bag[pos] > y) pos--;

        if(bag[pos] > y or bag[pos] < x) { cout << -1 << endl; continue; }
        cout << bag[pos] << endl;
    }

    return 0;
}


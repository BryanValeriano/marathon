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

const int T = 1e6;
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

ll sumDiv(ll x) {
    ll ans = 1;

    for(int i = 0; i < primes.size() and primes[i]*primes[i] <= x; i++) {
        ll power = primes[i];
        while(x % primes[i] == 0) power *= primes[i], x /= primes[i];
        ans *= (power - 1) / (primes[i] - 1);
    }
    if(x != 1) ans *= (x*x - 1) / (x - 1);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    init();
    ll x;
    cin >> x;

    ll po[32];
    po[0] = 1;

    for(ll i = 1; i < 32; i++) po[i] = po[i-1]*2ll;

    while(x) {
        ll a = po[x-1];
        ll b = po[x]-1;
        ll c = a*b;

        ll gcd = __gcd(a,b);

        a /= gcd;
        b /= gcd;
        a = sumDiv(a), b = sumDiv(b) * sumDiv(gcd);

        if(a*b/2 == c) cout << "Perfect: " << c << "!" << endl;
        else {
            cout << "Given number is ";
            cout << (!crivo[x]? "prime. But, " : "NOT prime! ");
            cout << "NO perfect number is available." << endl;
        }
        cin >> x;
    }
    return 0;
}


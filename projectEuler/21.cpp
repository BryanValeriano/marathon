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
const int T = 10000 + 3;
bitset<T> crivo;
vector<int> primes;
ll v[T];

void init() {
    for(int i = 2; i < T; i++) {
        if(!crivo[i]) {
            primes.pb(i);
            for(int j = i+i; j < T; j += i) crivo[j] = 1;
        }
    }
}

ll sumDiv(ll x) {
    ll z = x;
    ll ans = 1;
    for(int i = 0; i < primes.size() and primes[i]*primes[i] <= x; i++) {
        ll power = 0;
        while(x % primes[i] == 0) { x /= primes[i], power++; }
        ans *= ((ll)pow((double)primes[i], power + 1.0) - 1) / (primes[i] - 1);
    }
    if(x != 1) ans *= ((ll)pow((double)x,2.0) - 1) / (x -1);
    return ans - z;
}


int main() {
    ios_base::sync_with_stdio(false);
    init();
    ll ans = 0;
    for(int i = 1; i <= 10000; i++) v[i] = sumDiv(i);

    for(int i = 1; i <= 10000; i++)
        if(v[i] <= 10000 and v[v[i]] == i and v[i] != i)
            ans += i;

    cout << ans << endl;
    return 0;
}


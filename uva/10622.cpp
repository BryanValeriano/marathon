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

const int T = 1e5;
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

vii decop(ll x) {
    x = abs(x);
    vii ans;

    for(int i = 0; i < primes.size() and primes[i]*primes[i] <= x; i++) {
        ii tmp = mk(primes[i],0);
        while(x % primes[i] == 0) tmp.se++, x /= primes[i];
        if(tmp.se) ans.pb(tmp);
    }

    if(x > 1) ans.eb(x,1);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    init();
    ll x; cin >> x;

    while(x) {
        vii v = decop(x);

        int ans = 1;

        for(int i = 1; i <= 32; i++) {
            bool f = 1;
            for(int j = 0; j < v.size(); j++) f &= ((v[j].se % i) == 0);
            ans = (f and x > 0? i : ans);
            ans = (f and x < 0 and i&1 ? i : ans);
        }

        cout << (x == 1? 1 : ans) << endl;
        cin >> x;
    }


    return 0;
}


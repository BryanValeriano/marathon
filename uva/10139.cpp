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
const int T = 1e5 + 2;
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

vii decop(int x) {
    vii v;
    for(int i = 0; i < primes.size() and primes[i]*primes[i] <= x; i++) {
        ii ok = mk(primes[i],0);
        while(x % primes[i] == 0) ok.se++, x /= primes[i];
        if(ok.se) v.eb(ok);
    }
    if(x > 1) v.eb(x,1);
    return v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    init();

    int n,m;
    while(cin >> n) {
        cin >> m;
        vii pr = decop(m);
        bool ans = 1;

        for(ii x : pr) {
            int gol = x.se;
            ll ok = x.fi;
            ll nice = 0;
            while(ok <= n) nice += n/ok, ok *= (ll)x.fi;
            if(nice < gol) { ans = 0; break; }
        }

        cout << m;
        cout << (ans? " divides " : " does not divide ");
        cout << n << "!" << endl;
    }

    return 0;
}


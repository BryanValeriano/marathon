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
const int T = 5e6;

bitset<T> crivo;
vector<int> primes;
vector<int> g[T];

void init() {
    crivo[0] = crivo[1] = 1;

    for(int i = 2; i < T; i++) {
        if(!crivo[i]) {
            primes.pb(i);
            for(int j = i+i; j < T; j += i) crivo[j] = 1;
        }
    }
}

ll junt(int x, int y) {
    ll ans = 0;
    ll casa = 1;

    while(y) {
        ans += (y%10)*casa;
        casa *= 10;
        y /= 10;
    }
    while(x) {
        ans += (x%10)*casa;
        casa *= 10;
        x /= 10;
    }

    return ans;
}

void build(int x) {
    int gol = x;
    int y = x%10;

    x /= 10;
    int casa = 10;

    while(x) {
        if(!crivo[x] and !crivo[y] and junt(x,y) == gol and !crivo[junt(y,x)])
            g[x].pb(y), g[y].pb(x);

        y += (x%10)*casa;
        casa *= 10;
        x /= 10;
    }

}

int ans = INF;

void print(int a, int b, int c, int d, int e) {
    //cout << a << endl;
    //cout << b << endl;
    //cout << c << endl;
    //cout << d << endl;
    //cout << e << endl;
    //cout << a+b+c+d+e << endl;
    if(a+b+c+d+e < ans) cout << a+b+c+d+e << endl;
    ans = min(ans,a+b+c+d+e);
    //cout << endl;
}

bool isPrime(ll x) {
    for(int i = 0; i < primes.size() and (ll)primes[i]*(ll)primes[i] <= x; i++) {
        if(x % primes[i] == 0) return 0;
    }
    return 1;
}

bool ok(int a, int b) {
    return isPrime(junt(a,b)) and isPrime(junt(b,a));
}

int main() {
    ios_base::sync_with_stdio(false);
    init();

    for(int i = 0; i < primes.size(); i++) build(primes[i]);

    for(int i = 0; i < primes.size(); i++) {
        int j = primes[i];
        sort(g[j].begin(), g[j].end());
        g[j].resize(unique(g[j].begin(), g[j].end()) - g[j].begin());
    }

    for(int i : primes)
        for(auto j : g[i])
            if(j > i)
                for(auto k : g[j])
                    if(ok(i,k))
                        for(auto p : g[k])
                            if(ok(j,p) and ok(i,p))
                                for(auto q : g[p])
                                    if(ok(k,q) and ok(j,q) and ok(i,q)) {
                                        print(i,j,k,p,q);
                                    }


    cout << ans << endl;

    return 0;
}


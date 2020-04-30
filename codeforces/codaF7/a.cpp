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
const int T = 1e5 + 4;

bitset<T> crivo;
vector<int> v;
vector<int> primes;
vector<int> hasPrime[T];
vector<int> g[T];
int in[T];
int best[T];

void init() {
    for(int i = 2; i < T; i++) {
        if(!crivo[i]) {
            primes.pb(i);
            for(int j = i+i; j < T; j += i) crivo[j] = 1;
        }
    }
}

void decop(int x) {
    int ori = x;
    for(int i = 0; i < primes.size() and primes[i]*primes[i] <= x; i++) {
        if(x%primes[i]) continue;
        hasPrime[primes[i]].pb(ori);
        while(x%primes[i]==0) x /= primes[i];
    }
    if(x > 1) hasPrime[x].pb(ori);
}

int main() {
    ios_base::sync_with_stdio(false);
    init();
    int n; cin >> n;

    while(n--) {
        int x; cin >> x;
        decop(x);
        v.pb(x);
    }

    queue<int> fila;

    for(int i = 0; i < T; i++) {
        for(int j = 1; j < hasPrime[i].size(); j++) {
            in[hasPrime[i][j-1]]++;
            g[hasPrime[i][j]].pb(hasPrime[i][j-1]);
        }
    }

    for(auto x : v) {
        if(!in[x]) {
            fila.push(x);
            best[x] = 1;
        }
    }

    int ans = 0;
    while(!fila.empty()) {
        int u = fila.front();
        fila.pop();
        ans = max(ans,best[u]);
        for(int nxt : g[u]) {
            in[nxt]--;
            best[nxt] = max(best[nxt],best[u]+1);
            if(!in[nxt]) fila.push(nxt);
        }
    }

    cout << ans << endl;

    return 0;
}


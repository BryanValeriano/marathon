#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
//const ll p[2] = {1020379,1005217};
const ll p[2] = {31,47};
const ll m[2] = {1073807359,1442968193};
const int T = 1e6+2;

ll po[2][T];
ll g[2][T];
ll sz[T];
map<ii,ll> id[T];

void build(int n) {
    for(int j = 0; j < 2; j++) {
        po[j][0] = 1;
        for(int i = 1; i <= n; i++)
            po[j][i] = (po[j][i-1]*p[j]) % m[j];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    build(n);
    vii corn;

    while(q--) {
        int u,v; cin >> u >> v;
        corn.eb(u,v);
        sz[u]++, sz[v]++;
        g[0][u] = (g[0][u] + (po[0][v])) % m[0];
        g[1][u] = (g[1][u] + (po[1][v])) % m[1];
        g[0][v] = (g[0][v] + (po[0][u])) % m[0];
        g[1][v] = (g[1][v] + (po[1][u])) % m[1];
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ii ok = mk(g[0][i],g[1][i]);
        ans += id[sz[i]][ok];
        id[sz[i]][ok]++;
    }
    for(auto &[u,v] : corn) {
        ii okU = mk((g[0][u]-po[0][v]+m[0])%m[0],(g[1][u]-po[1][v]+m[1])%m[1]);
        ii okV = mk((g[0][v]-po[0][u]+m[0])%m[0],(g[1][v]-po[1][u]+m[1])%m[1]);
        if(okV == okU) ans++;
    }
    cout << ans << endl;
    return 0;
}


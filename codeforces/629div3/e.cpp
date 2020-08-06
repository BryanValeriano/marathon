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
const int T = 2e5 + 3;
const int LOG = log2(T)+2;
int n,q;
vector<int> g[T];
int h[T];
int anc[LOG][T];

int lca(int u, int v) {
    if(h[u] < h[v]) swap(u,v);
    for(int i = LOG-1; i >= 0; i--)
        if(h[u]-(1<<i) >= h[v]) u = anc[i][u];
    if(u==v) return u;
    for(int i = LOG-1; i >= 0; i--)
        if(anc[i][u] != anc[i][v]) u = anc[i][u], v = anc[i][v];
    return anc[0][u];
}

void solve() {
    while(q--) {
        int k; cin >> k;
        vii v;
        while(k--) {
            int x; cin >> x;
            v.eb(h[x],x);
        }
        sort(v.begin(),v.end());
        bool ans = 1;
        for(int i = v.size()-1; i >= 1 and ans; i--) {
            int low = lca(v[i].se,v[i-1].se);
            ans &= (low==v[i-1].se or low == anc[0][v[i-1].se]);
        }
        cout << (ans?"YES":"NO") << endl;
    }
}

void dfs(int u) {
    for(int v : g[u]) {
        if(h[v]) continue;
        h[v] = h[u]+1;
        anc[0][v] = u;
        dfs(v);
    }
}

void buildLCA() {
    h[1] = 1;
    anc[0][1] = 1;
    dfs(1);
    for(int i = 1; i < LOG; i++)
        for(int j = 1; j <= n; j++)
            anc[i][j] = anc[i-1][anc[i-1][j]];
}

void read() {
    cin >> n >> q;
    for(int i = 0; i < n-1; i++) {
        int x,y; cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    read();
    buildLCA();
    solve();
    return 0;
}


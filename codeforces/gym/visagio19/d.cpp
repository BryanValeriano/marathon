#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 2e3 + 5;

int n,m,t,sz;;
vii edg;
vector<int> g[T];
int pai[T], peso[T], d[T], low[T], st[T], ans[T], in[T];
set<int> bag[T];
set<ii> tmp;

void init() {
    for(int i = 0; i < T; i++) {
        peso[i] = 0;
        pai[i] = i;
    }
}

int find(int x) {
    return (x == pai[x]? x : pai[x] = find(pai[x]));
}

void join(int x, int y) {
    x = find(x);
    y = find(y);

    if(x == y) return;

    if(peso[x] < peso[y]) swap(x,y);

    pai[y] = x;
    peso[x] += peso[y];
}

void dfs(int u) {
    st[sz++] = u;
    d[u] = low[u] = ++t;

    for(int a : g[u]) {
        int v = edg[a].se;
        if(!d[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else low[u] = min(low[u], d[v]);
    }

    if(low[u] >= d[u]) {
        int a;
        do {
            a = st[--sz];
            join(a,u);
            d[a] = INF;
        } while(a != u);
    }
}

void dfs2(int u) {
    d[u] = 1;

    for(int a : g[u]) {
        int v = find(edg[a].se);
        if(!d[v]) dfs2(v);
        for(auto x : bag[v]) bag[u].insert(x);
    }

    for(auto x : bag[u]) ans[u] ^= x;
}

int main() {
    ios::sync_with_stdio(false);
    init();
    int a,b;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a].pb(edg.size());
        edg.eb(a,b);
    }

    for(int i = 1; i <= n; i++)
        if(d[i] == 0) dfs(i);

    for(int i = 0; i <= n; i++) g[i].clear();

    for(int i = 0; i < m; i++) {
        a = find(edg[i].fi), b = find(edg[i].se);
        if(a != b and !tmp.count(mk(a,b))) {
            g[a].pb(i), tmp.emplace(a,b);
            in[b]++;
        }
    }

    for(int i = 1; i <= n; i++) bag[find(i)].insert(i);

    memset(d, 0, sizeof d);

    for(int i = 1; i <= n; i++)
        if(in[find(i)] == 0 and d[i] == 0)
            dfs2(find(i));

    for(int i = 1; i <= n; i++) cout << ans[find(i)] << endl;

    return 0;
}


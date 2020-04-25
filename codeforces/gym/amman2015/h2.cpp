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
const int T = 3e5 + 10;
vector<int> g[T];
vector<ii> arestas;
set<ii> pontes;
int vis[T];
int pai[T];
int peso[T];
int low[T];
int tin[T];
int t, n, m, vez, ori;

void pre() {
    for(int i = 1; i < T; i++) {
        pai[i] = i;
        g[i].clear();
        peso[i] = 0;
    }
    arestas.clear();
    pontes.clear();
    t = 0;
}

void dfs(int u, int p) {
    tin[u] = low[u] = ++t;
    vis[u] = vez;
    for(int v : g[u]) {
        if(vis[v] != vez /* and v != p*/) {
            dfs(v,u);
            if(low[v] > tin[u]) {
                if(u < v) pontes.emplace(u,v);
                else pontes.emplace(v,u);
            }
            low[u] = min(low[v], low[u]);
        } else if(v != p) low[u] = min(low[u], tin[v]);
    }
}

int find(int x) {
    return (pai[x] == x? x : pai[x] = find(pai[x]));
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;

    if(peso[x] < peso[y]) swap(x,y);
    pai[y] = x;

    if(peso[x] == peso[y]) peso[x]++;
}

void rebuild() {
    for(int i = 0; i < T; i++) g[i].clear();

    for(ii x : arestas)
        if((x.fi < x.se and !pontes.count(mk(x.fi,x.se))) or
            x.se < x.fi and !pontes.count(mk(x.se,x.fi)))
            join(find(x.fi), find(x.se));

    for(ii x : pontes) {
        g[find(x.fi)].pb(find(x.se));
        g[find(x.se)].pb(find(x.fi));
        ori = find(x.fi);
    }
}

void read() {
    cin >> n >> m;
    int u,v;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        if(u < v) arestas.eb(u,v);
        else arestas.eb(v,u);
        g[u].pb(v);
        g[v].pb(u);
        ori = u;
    }
}

ii best(const ii a, const ii b) {
    if(a.se != b.se) {
        if(a.se > b.se) return a;
        else return b;
    }
    return a;
}

ii dfs2(int u, int niv) {
    vis[u] = vez;
    ii ans = mk(u,niv);
    for(int v : g[u])
        if(vis[v] != vez)
            ans = best(ans, dfs2(v, niv+1));
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        pre();
        read();
        vez++; dfs(ori,ori);
        rebuild();
        vez++; ii a = dfs2(ori, 0);
        vez++; ii b = dfs2(a.fi,0);
        cout << pontes.size() - b.se << endl;
    }
    return 0;
}


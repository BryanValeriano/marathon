#include <bits/stdc++.h>
using namespace std;

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

struct graph {
    int size;
    vector<list<int>> adj;
    graph(int n) : size(n), adj(n)  {}
    void addEdge(int a, int b) {
        adj[a].push_back(b);
    }
};

const int N = 1e5 + 10;
int r, sz;
int st[N], d[N], low[N], comp[N];
int vis[N], vis2[N];

void tarjan(graph& g, int u) {
    st[sz++] = u;
    d[u] = low[u] = ++r;

    for(int v : g.adj[u]) {
        if(!low[v]) {
            tarjan(g, v);
            low[u] = min(low[u], low[v]);
        } else low[u] = min(low[u],d[v]);
    }

    if(low[u] >= d[u]) {
        int a;
        do {
            a = st[--sz];
            comp[a] = u;
            d[a] = INF;
        } while(a != u);
    }
}

void dfs(graph&g, int u) {
    vis[u] = 1;
    for(int v : g.adj[u]) if(!vis[v]) dfs(g,v);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, t;
    cin >> n >> m >> t;

    int a, b;
    graph g(n);
    graph f(n);
    graph h(n);

    for (int i = 0;i < m;i++) {
        cin >> a >> b;
        f.addEdge(a,b);
        h.addEdge(b,a);
        if(a != t) g.addEdge(b, a);
    }

    tarjan(g,t);
    dfs(h,t);
    vis[t] = 0;
    vector<int> ans;

    for(int u = 0; u < n; u++)
        for(int v : f.adj[u])
            if(comp[u] != comp[v] and vis[v])
                vis2[comp[u]]++;

    for(int u : h.adj[t]) vis2[comp[u]]++;
    for(int u : h.adj[t]) {
        bool ok = 1;
        if(vis2[comp[u]] > 1) continue;
        for(int v : f.adj[u])
            if(comp[u] != comp[v])
                ok &= !vis[v];
        if(ok) ans.pb(u);
    }

    sort(ans.begin(),ans.end());
    cout << ans.size() << endl;
    for (int x : ans) cout << x << endl;
    return 0;
}

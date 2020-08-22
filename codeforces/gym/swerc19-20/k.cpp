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
    vector<set<int>> adj2;
    vector<int> in;
    graph(int n) : size(n), adj(n), adj2(n), in(n, 0) {}
    void addEdge(int a, int b) {
        if(adj2[a].count(b)) return;
        adj[a].push_back(b);
        in[b]++;
        adj2[a].insert(b);
    }
};

const int N = 1e5 + 10;
int r, sz;
int st[N], d[N], low[N], pai[N], peso[N];
int vis[N];

int find(int x) {
    return (x == pai[x]? x : pai[x] = find(pai[x]));
}

void join(graph& g, int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (peso[a] > peso[b]) swap(a, b);
    pai[a] = b;
    peso[b] += peso[a];
    for(int wtf : g.adj2[a]) g.adj2[b].insert(wtf);
    return;
}

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
            join(g,u,a);
            d[a] = INF;
        } while(a != u);
    }
}

void bfs(graph& g, int t) {
    vis[t] = 1;
    queue<int> lista;
    lista.push(t);

    while(!lista.empty()) {
        int u = lista.front();
        lista.pop();
        for(int v : g.adj2[u]) {
            vis[v] += (vis[u] - (u==t));
            g.in[v]--;
            if(!g.in[v]) lista.push(v);
        }
    }
}

void init(int n) {
    for(int i = 0; i < n; i++) {
        pai[i] = i;
        peso[i] = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    int n, m, t;
    cin >> n >> m >> t;
    init(n);

    int a, b;
    graph g(n);

    for (int i = 0;i < m;i++) {
        cin >> a >> b;
        if(a != t) g.addEdge(b, a);
    }

    tarjan(g, t);
    graph h(n);

    for(int i = 0; i < n; i++) {
        if(!vis[find(i)]) {
            int u = find(i);
            vis[u] = 1;
            for(int v : g.adj2[u])
                if(find(v) != u) h.addEdge(u, find(v));
        }
    }

    memset(vis,0,sizeof vis);
    for(int v : g.adj[t]) vis[find(v)]++;
    bfs(h, t);
    vector<int> ans;
    for(int v : g.adj[t]) if(vis[find(v)] == 1) ans.pb(v);

    cout << ans.size() << endl;
    for (int x : ans) cout << x << endl;
    return 0;
}

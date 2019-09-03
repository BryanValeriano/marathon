#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef pair<int,int> ii;

const int T = 1e5 + 10;
set<ii> edges;
vector<int> g[T];
vector<int> g2[T];
int tin[T];
int low[T];
bool vis[T];
int dist[T];
int pai[T];
int n, m, z, t, vez, ponte;


void dfs2(int u, int niv) {
    vis[u] = true;
    dist[u] = niv;
    for(int v : g2[u]) 
        if(vis[v] == false) 
            dfs2(v, niv+1);
}

void dfs1(int u, int comp) {
    vis[u] = true;
    pai[u] = comp;
    for(int v : g[u]) 
        if(vis[v] == false and !edges.count(mk(u,v))) 
            dfs1(v, comp);
}

void dfs(int u, int p) {
    tin[u] = low[u] = ++t;
    vis[u] = true;
    for(int v : g[u]) {
        if(vis[v] == false and v != p) {
            dfs(v,u);
            if(low[v] > tin[u]) { 
                edges.insert(mk(u,v));
                edges.insert(mk(v,u));
                ponte++;
            }
            low[u] = min(low[u], low[v]);
        } else if(v != p) low[u] = min(low[u], tin[v]);
    }
}

void read() {
    int u,v;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        z = u;
    }
}

void reset() {
    for(int i = 1; i < T; i ++) {
        g[i].clear();
        g2[i].clear();
        vis[i] = false;
        dist[i] = 0;
    }
    edges.clear();
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        t = ponte = 0;
        reset();
        read();
        dfs(z,z);

        memset(vis,0,sizeof vis);
        int cont = 0;

        for(int i = 1; i <= n; i++)
            if(!vis[i])
                dfs1(i,++cont);
        
        for(auto x : edges)
            g[pai[x.fi]].pb(pai[x.se]);

        dfs2(1,0);
        int d = 0;
        int ori;
        for(int i = 0; i <= n; i++) if(dist[i] > d) { d = dist[i]; ori = i; }
        memset(vis,0,sizeof vis);
        memset(dist,0,sizeof dist);
        dfs2(ori,0);
        d = 0;
        for(int i = 0; i <= n; i++) d = max(d, dist[i]); 

        cout << ponte - d << endl;
    }
    return 0;
}


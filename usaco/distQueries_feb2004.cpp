//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>

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
const int T = 4e4 + 10;
const int LOG = 20;
int n;
int pai[T];
int nivel[T];
ll dist[T];
int ancestral[T][LOG];
vii g[T];

int lca(int u, int v) {
    if(nivel[u] < nivel[v]) swap(u,v);
    
    for(int i = LOG-1; i >= 0; i--)
        if(nivel[u] - (i<<1) >= nivel[v])
            u = ancestral[u][i];

    if(u == v) return u;

    for(int i = LOG-1; i >= 0; i--)
        if(ancestral[u][i] != -1 and ancestral[u][i] != ancestral[v][i]) {
            u = ancestral[u][i];
            v = ancestral[v][i];
        }

    return ancestral[u][0];
}

void dfs(int u) {
    for(int i = 0; i < g[u].size(); i++) {
        ii v = g[u][i];
        if(nivel[v.fi] == -1) {
            nivel[v.fi] = nivel[u] + 1;
            pai[v.fi] = u;
            dist[v.fi] = dist[u] + v.se;
            dfs(v.fi);
        }
    }
}

void build() {
    memset(pai, -1, sizeof pai);
    memset(nivel, -1, sizeof nivel);
    memset(ancestral, -1, sizeof ancestral);
    pai[1] = 1;
    nivel[1] = 0;
    dfs(1);
    for(int i = 1; i <= n; i++) ancestral[i][0] = pai[i];
    for(int j = 1; j < LOG; j++)
        for(int i = 1; i <= n; i++)
            ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];
} 

void read() {
    int u, v, d, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        char tmp;
        cin >> u >> v >> d >> tmp;
        g[u].pb(mk(v,d));
        g[v].pb(mk(u,d));
    }
}

void solve() {
    int k, u, v;
    cin >> k;
    while(k--) {
        cin >> u >> v;
        cout << dist[u] + dist[v] - 2*dist[lca(u,v)] << endl;
    }
}


int main() {
    ios::sync_with_stdio(false);
    read();
    build();
    solve();
    return 0;
}


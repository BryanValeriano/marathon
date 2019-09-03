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
const int T = 5e4;
const int LOG = 20;
vector<ii> g[T];
int pai[T];
int nivel[T];
int peso[T];
int ancestral[T][LOG];
int n;

int lca(int u, int v) {
    if(nivel[u] < nivel[v]) swap(u,v);

    for(int i = LOG-1; i >= 0; i--) 
        if(nivel[u] - (1<<i) >= nivel[v]) u = ancestral[u][i];
    
    if(u == v) return u;

    for(int i = LOG-1; i >= 0; i--) 
        if(ancestral[u][i] != -1 and ancestral[u][i] != ancestral[v][i]) {
            u = ancestral[u][i];
            v = ancestral[v][i];
        }

    return pai[u];
}

void query() {
    int q; cin >> q;
    int u, v;
    while(q--) {
        cin >> u >> v;
        cout << peso[u] + peso[v] - (2*peso[lca(u,v)]) << endl;
    }
}

void dfs(int atual) {
    for(int i = 0; i < g[atual].size(); i++) {
        int viz = g[atual][i].fi;
        if(nivel[viz] == -1) {
            pai[viz] = atual;
            nivel[viz] = nivel[atual] + 1;
            peso[viz] += peso[atual] + g[atual][i].se;
            dfs(viz);
        }
    }
}

void build() {
    pai[0] = 0;
    nivel[0] = 0;
    dfs(0);

    for(int i = 0; i < n; i++) ancestral[i][0] = pai[i];

    for(int j = 1; j < LOG; j++)
        for(int i = 0; i < n; i++)
            ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];
}

void read() {
    int u,v,w;
    for(int i = 0; i < n-1; i++) {
        cin >> u >> v >> w;
        g[u].pb(mk(v,w));
        g[v].pb(mk(u,w));
    }
}

int main() {
    ios::sync_with_stdio(false);
    memset(ancestral, -1, sizeof ancestral);
    memset(pai, -1, sizeof pai);
    memset(nivel, -1, sizeof nivel);
    cin >> n;
    read();
    build();
    query();
    return 0;
}


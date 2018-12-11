#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ll> pll;
typedef vector< pair<int,int> > vii;
const ll INF = 0x3f3f3f3f3f3f3f;
const int T = 1e5 + 10;
const int LOG = 20;
int prim = 0;
int n, m;
int pai[T];
int ancestral[T][LOG];
int nivel[T];
ll peso[T];
ll d[45][T];
vii g[T];
set<ii>fora;


int lca(int u, int v) {
    if(nivel[u] < nivel[v]) swap(u,v);

    for(int i = LOG-1; i >= 0; i--) 
        if(nivel[u] - (1<<i) >= nivel[v]) 
            u = ancestral[u][i];

    if(u == v) return u;

    for(int i = LOG - 1; i >= 0; i--) 
        if(ancestral[u][i] != -1 and ancestral[u][i] != ancestral[v][i]) {
            u = ancestral[u][i];
            v = ancestral[v][i];
        }

    return pai[u];
}

void dij(int ini, ll d[T]) {
    priority_queue<pll, vector<pll>, greater<pll> >pq;
    for(int i = 0; i <= n; i++) d[i] = INF;
    d[ini] = 0;
    pq.emplace(ini,0);
    while(!pq.empty()) {
        pll atual = pq.top(); 
        pq.pop();
        int u = atual.fi;
        for(int i = 0; i < g[u].size(); i++) {
            int filho = g[u][i].fi;
            int dist = g[u][i].se;
            if(d[filho] > d[u] + dist) {
                d[filho] = d[u] + dist;
                pq.emplace(filho,d[filho]);
            }
        }
    }
}
    

void dfs(int u) {
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i].fi;
        int w = g[u][i].se;
        if(nivel[v] == -1) {
            nivel[v] = nivel[u] + 1;
            peso[v] = peso[u] + w;
            pai[v] = u;
            if(u < v) fora.erase(mk(u,v));
            else fora.erase(mk(v,u));
            dfs(v);
        }
    }
}

void build() {
    memset(pai, -1, sizeof pai);
    memset(nivel, -1, sizeof nivel);
    memset(ancestral, -1, sizeof ancestral);
    nivel[prim] = 0;
    pai[prim] = prim;
    dfs(prim);
    
    for(int i = 1; i <= n; i++) ancestral[i][0] = pai[i];
    
    for(int j = 1; j < LOG; j++)
        for(int i = 1; i <= n; i++) 
            ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];
}


int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int u,v,w;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        if(prim == 0) prim = u;
        g[u].eb(v,w);
        g[v].eb(u,w);
        if(u < v) fora.insert(mk(u,v));
        else fora.insert(mk(v,u));
    }
    build(); 
    int cont = 0;
    for(auto e : fora)  
        dij(e.fi, d[cont++]);
    
    int q; cin >> q;
    while(q--) {
        cin >> u >> v;
        ll ans = peso[u] + peso[v] - 2*peso[lca(u,v)];
        for(int i = 0; i < fora.size(); i++) 
            ans = min(ans, d[i][u] + d[i][v]);
        cout << ans << endl;
    }

    return 0;
}


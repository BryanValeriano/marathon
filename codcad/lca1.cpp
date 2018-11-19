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
const int T = 5e4 + 3;
const int LOG = 20;
vector<int> g[T];
int pai[T];
int nivel[T];
int ancestral[T][LOG];

void dfs(int u) {
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(nivel[v] == -1) {
            pai[v] = u;
            nivel[v] = nivel[u] + 1;
            dfs(v);
        }
    }
}

int LCA(int u, int v) {
    if(nivel[u] < nivel[v]) swap(u,v);

    for(int i = LOG-1; i >= 0; i--) 
        if(nivel[u] - (1<<i) >= nivel[v])
            u = ancestral[u][i];

    if(u == v) return u;

    for(int i = LOG-1; i >= 0; i--)
        if(ancestral[u][i] != -1 and ancestral[u][i] != ancestral[v][i]) {
            u = ancestral[u][i];
            v = ancestral[v][i];
        }
    
    return pai[u];
}


int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> par[n];
    int aux;
    for(int i = 1; i <= n; i++) {
        cin >> aux;
        par[aux].pb(i);
    }
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    memset(pai, -1, sizeof pai);
    memset(nivel, -1, sizeof nivel);
    memset(ancestral, -1, sizeof ancestral);
    nivel[1] = 0;
    pai[1] = 1;
    dfs(1);
    for(int i = 1; i <= n; i++) ancestral[i][0] = pai[i];
    for(int j = 1; j < LOG; j++)
        for(int i = 1; i <= n; i++)
            ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];
    
    ll ans = 0;
    for(int i = 1; i <= n/2; i++) 
        ans += nivel[par[i][0]] + nivel[par[i][1]] - 2*nivel[LCA(par[i][0],par[i][1])];

    cout << ans << endl;
    return 0;
}


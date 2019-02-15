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
const int T = 1e3 + 10;
const int LOG = 12;
vector<int> g[T];
int pai[T];
int nivel[T];
int ancestral[T][LOG+3];
int n;

int lca(int u, int v) {
    if(nivel[u] < nivel[v]) swap(u,v);

    for(int i = LOG; i >= 0; i--)
        if(nivel[u] - (1<<i) >= nivel[v]) 
            u = ancestral[u][i];

    if(u == v) return u;
    
    for(int i = LOG; i >= 0; i--) 
        if(ancestral[u][i] != -1 and ancestral[u][i] != ancestral[v][i]) {
            u = ancestral[u][i];
            v = ancestral[v][i];
        }

    return ancestral[u][0];
}

void dfs(int atual) {
    for(int i = 0; i < g[atual].size(); i++) {
        int v = g[atual][i];
        if(pai[v] == -1) {
            pai[v] = atual;
            nivel[v] = nivel[atual] + 1;
            dfs(v);
        }
    }
}

void read() {
    cin >> n;
    int lim, u, v;
    for(int i = 1; i <= n; i++) {
        g[i].clear();
        cin >> lim;
        for(int j = 0; j < lim; j++) {
            cin >> v;
            g[i].pb(v);
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

    for(int i = 1; i <= n; i++)  
        ancestral[i][0] = pai[i];

    for(int j = 1; j <= LOG; j++) 
        for(int i = 1; i <= n; i++) 
            ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];
}

void query(int c) {
    cout << "Case " << c << ":" << endl;
    int q; cin >> q;
    int u, v;
    while(q--) {
        cin >> u >> v;
        cout << lca(u,v) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    int aux = 0;
    while(tc--) {
        read();        
        build();
        query(++aux);        
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,ll> > vii;
const int INF = 0x3f3f3f3f;
const int LOG = 20;
const int T = 1e5 + 3;
int n;
int ancestral[T][LOG];
int pai[T];
int nivel[T];
ll peso[T];
vii g[T];

int lca(int u, int v) {
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

    return ancestral[u][0];
}

void dfs(int u) {
    for(int i = 0; i < g[u].size(); i++) {
        ii v = g[u][i];
        if(nivel[v.fi] == -1) {
            pai[v.fi] = u;
            nivel[v.fi] = nivel[u] + 1;
            peso[v.fi] = peso[u] + v.se;
            dfs(v.fi);
        }
    }
}
            

void build() {
    nivel[0] = 0;
    pai[0] = 0;
    peso[0] = 0;
    dfs(0);
    for(int i = 0; i <= n-1; i++)
        ancestral[i][0] = pai[i];
    for(int j = 1; j < LOG; j++) 
        for(int i = 0; i <= n-1; i++)
            ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];
}

void pre() {
    for(int i = 0; i <= n; i++) {
        g[i].clear();
        pai[i] = nivel[i] = -1;
        peso[i] = 0;
    }
    for(int j = LOG - 1; j >= 0; j--)
        for(int i = 0; i <= n; i++)
            ancestral[i][j] = -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    while(n) {
        pre();
        for(int i = 1; i <= n-1; i++) {
            int u, p;
            cin >> u >> p;
            g[u].eb(i,p);
            g[i].eb(u,p);
        }
        build();
        int q; cin >> q;
        while(q--) {
            int u, v;
            cin >> u >> v;
            cout << peso[u] + peso[v] - 2*peso[lca(u,v)];
            if(q) cout << " ";
        }
        cout << endl;
        cin >> n;
    }
    return 0;
}


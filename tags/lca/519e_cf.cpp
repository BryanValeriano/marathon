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
const int T = 1e5 + 20; 
const int LOG = 20;
int n;
int pai[T];
int nivel[T];
int ancestral[T][LOG];
int peso[T];
vector<int> g[T];

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

int kth(int u, int niv) {
    niv = nivel[u] - niv;
    for(int i = LOG - 1; i >= 0; i--)
        if(nivel[u] - (1<<i) >= niv)
            u = ancestral[u][i];
    return u;
}

void query() {
    int m; cin >> m;
    int a, b;
    //for(int i = 1; i <= n; i++)
    //    cout << peso[i] << " ";
    //cout << endl;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        int anc = lca(a,b);
        if(anc != a and anc != b) {
            if(anc == 1) cout << peso[anc] - (peso[a] + peso[b]) << endl;
            else cout << peso[1] - peso[anc] + 1 << endl;
        } else {
            int baixo;
            nivel[a] > nivel[b]? baixo = a : baixo = b;
            int dist = nivel[baixo] - nivel[anc];
            int corte = dist-1;
            if(dist > 1 and dist%2 == 0) cout << peso[kth(baixo, dist/2)] - peso[kth(baixo, corte/2)] << endl;
            else cout << 0 << endl;
        }
    }
}

void dfs(int u) {
    peso[u] = 1;
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(nivel[v] == -1) {
            nivel[v] = nivel[u] + 1;
            pai[v] = u;
            dfs(v);
            peso[u] += peso[v];
        }
    }
}

void build() {
    memset(nivel, -1, sizeof nivel);
    memset(ancestral, -1, sizeof ancestral);
    nivel[1] = 1;
    pai[1] = 1;
    dfs(1);
    for(int i = 1; i <= n; i++) ancestral[i][0] = pai[i];
    for(int j = 1; j < LOG; j++)
        for(int i = 1; i <= n; i++)
            ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];
}

void read() {
    cin >> n;
    int u,v;
    for(int i = 0; i < n-1; i++) {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    read();
    build();
    query();
    return 0;
}


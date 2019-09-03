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
int n, m;
int pai[T];
int nivel[T];
int ancestral[T][LOG];
int ans[T];
bool vis[T];
vector< pair<int,int> >querys[T];
unordered_set<int> glob[T];
vector<int> g[T];

inline void dfs2(int u) {
    vis[u] = true;
    for(auto it : glob[nivel[u]])
        ans[it]++;
    for(auto it : querys[u]) 
        glob[it.fi].insert(it.se);
    for(auto v : g[u]) 
        if(!vis[v]) dfs2(v);
    for(auto it : querys[u]) 
        glob[it.fi].erase(it.se);
}

void solve() {
    for(int i = 1; i <= n; i++)
        if(!vis[i]) dfs2(i);
    for(int i = 0; i < m; i++) 
        cout << ans[i] - 1 << " ";
    cout << endl;
}

int kth(int u, int niv) {
    niv = nivel[u] - niv;
    for(int i = LOG -1; i >= 0; i--)
        if(nivel[u] - (1<<i) >= niv) 
            u = ancestral[u][i];
    return u;
}

void query() {
    cin >> m;
    int u, niv;
    for(int i = 0; i < m; i++) {
        cin >> u >> niv;
        int anc = kth(u,niv);
        if(anc > 0) querys[anc].eb(nivel[u],i);
        else ans[i] = 1;
    }
}

inline void dfs1(int u) {
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(nivel[v] == -1) {
            nivel[v] = nivel[u] + 1;
            dfs1(v);
        }
    }
}

void build() {
    memset(nivel, -1, sizeof nivel);
    memset(ancestral, -1, sizeof ancestral);
    for(int i = 1; i <= n; i++) 
        if(nivel[i] == -1) { nivel[i] = 0; dfs1(i); }
    for(int i = 1; i <= n; i++) ancestral[i][0] = pai[i];
    for(int j = 1; j < LOG; j++)
        for(int i = 1; i <= n; i++) 
            ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];
}

void read() {
    cin >> n;
    memset(pai, -1, sizeof pai);
    for(int i = 1; i <= n; i++) {
        cin >> pai[i];
        g[pai[i]].pb(i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    read();
    build();
    query();
    solve();
    return 0;
}

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
const int T = 1e5 + 100;
const int LOG = 20;
int n, m;
int pai[T];
int nivel[T];
int ancestral[T][LOG];
int ans[T];
bool vis[T];
set< pair<int,int> >querys[T];
set<int> glob[T];
vector<int> g[T];

void dfs2(int u) {
    vis[u] = true;
    int niv = nivel[u];
    auto it = glob[niv].begin();
    while(it != glob[niv].end()) {
        ans[*it]++;
        it++;
    }
    if(querys[u].size())
        for(set< pair<int,int> >::iterator it = querys[u].begin(); it != querys[u].end(); it++) 
            glob[it->fi].insert(it->se);
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(!vis[v]) dfs2(v);
    }
    if(querys[u].size())
        for(set< pair<int,int> >::iterator it = querys[u].begin(); it != querys[u].end(); it++) 
            glob[it->fi].erase(it->se);

}

void solve() {
    for(int i = 1; i <= n; i++)
        if(!vis[i]) dfs2(i);
    for(int i = 0; i < m; i++) 
        printf("%d ", ans[i]-1);
    printf("\n");
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
        if(anc > 0) querys[anc].insert(mk(nivel[u],i));
        else ans[i] = 1;
    }
}

void dfs1(int u) {
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
        scanf("%d", &pai[i]);
        g[pai[i]].pb(i);
    }
}

int main() {
    read();
    build();
    query();
    solve();
    return 0;
}

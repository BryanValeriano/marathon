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
const int LOG = 20;
const int T = 5e4+3;
vector<int> g[T];
int pai[T];
int nivel[T];
ll prefix[T];
int ancestral[T][LOG];
bool vis[T];
int n, k;
ll maxi;

int lca(int u, int v) {
    if(nivel[u] < nivel[v]) swap(u,v);

    for(int i = LOG - 1; i >= 0; i--)
        if(nivel[u] - (1<<i) >= nivel[v])
            u = ancestral[u][i];

    if(u == v) return u;

    for(int i = LOG - 1; i >= 0; i--)
        if(ancestral[u][i] != -1 and ancestral[u][i] != ancestral[v][i]) {
            u = ancestral[u][i];
            v = ancestral[v][i];
        }

    return ancestral[u][0];
}

void dfs(int u, bool flag) {
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(nivel[v] == -1 && !flag) {
            nivel[v] = nivel[u] + 1;
            pai[v] = u;
            dfs(v, flag);
        }
        if(flag && !vis[v]) {
            vis[v] = true;
            dfs(v, flag);
            prefix[u] += prefix[v];
            maxi = max(maxi, prefix[u]);
        }
    }
}

void pre() {
    memset(nivel, -1, sizeof nivel);
    memset(pai, -1, sizeof pai);
    memset(ancestral, -1, sizeof ancestral);
    nivel[1] = 0;
    pai[1] = 1;
    dfs(1,false);
    for(int i = 1; i <= n; i++) 
        ancestral[i][0] = pai[i];
    
    for(int j = 1; j < LOG; j++)
        for(int i = 1; i <= n; i++)
            ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];
}

void read() {
    int u, v;
    for(int i = 0; i < n-1; i++) { 
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    int u, v;
    cin >> n >> k;
    read();    
    pre();
    while(k--) {
        cin >> u >> v;
        prefix[u]++;
        prefix[v]++;
        int ancestor = lca(u,v);
        prefix[ancestor]--;
        prefix[pai[ancestor]]--;
    }
    dfs(1, true);
    cout << maxi << endl;
    return 0;
}


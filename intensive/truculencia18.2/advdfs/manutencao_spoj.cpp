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
const int T = 410;
vector<int> g[T];
set<int> ans;
int tin[T];
int low[T];
int vis[T];
int vez, t, n, m;

void dfs(int u, int p) {
    tin[u] = low[u] = ++t;
    vis[u] = vez;
    int nf = 0;
    bool any = false;
    for(auto v : g[u]) {
        if(vis[v] != vez and v != p) {
            nf++;
            dfs(v, u);
            if(low[v] >= tin[u]) any = true;
            low[u] = min(low[u], low[v]);
        } else low[u] = min(low[u], tin[v]);
    }
    if(u == 1 and nf >= 2) ans.insert(u);
    else if(u != 1 and any) ans.insert(u);
}

void read() {
    int u, v;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
}

void reset() {
    for(int i = 1; i <= n; i++) g[i].clear();
    ans.clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int cont = 0;
    while(n or m) {
        reset();
        read();
        vez++;
        dfs(1,1);
        cout << "Teste " << ++cont << endl;
        if(ans.size()) for(auto x : ans) cout << x << " ";
        else cout << "nenhum";
        cout << endl << endl;;
        cin >> n >> m;
    }
    return 0;
}


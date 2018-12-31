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
const int T = 3e3;
int n, v;
int vis[T];
int pai[T];
unordered_set<int> g[T];
vii flights;
int node;
int alt;

void dfs(int atual, int nivel) {
    if(nivel > alt) { alt = nivel; node = atual; }
    for(auto vizinho : g[atual]) {
        if(vis[vizinho] != v) {
            if(pai[vizinho] == -1) pai[vizinho] = atual;
            vis[vizinho] = v;
            dfs(vizinho, nivel+1);
        }
    }
}

void finDist() {
    memset(pai, -1, sizeof pai);
    v++;
    dfs(1, 0);
    int u = node;
    alt = 0;
    v++;
    dfs(u, 0);
    int v = node;
}

void read() {
    cin >> n;
    int u,v;
    for(int i = 1; i <= n; i++) g[i].clear();
    for(int i = 0; i < n-1; i++) {
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
        flights.eb(u,v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        read();
    }
    return 0;
}


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

const int T = 2e5 + 10;
vector<int> g[T];
vii edges;
int nivel[T];
bool vis[T];
bool flag = true;

void dfs(int u, int pai) {
    vis[u] = true;
    for(auto v : g[u]) {
        if(!vis[v]) {
            nivel[v] = nivel[u]+1;
            dfs(v,u);
        }
        if(!((nivel[v] - nivel[u])&1)) flag = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n, m, u, v;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        edges.pb({u,v});
    }

    nivel[1] = 1;
    dfs(1,1);
    if(!flag) { cout << "NO" << endl; return 0; }

    cout << "YES" << endl;
    for(auto x : edges) {
        if(nivel[x.fi]&1) cout << '1';
        else cout << '0';
    }
    cout << endl;

    return 0;
}


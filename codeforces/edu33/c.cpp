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

const int T = 1e5 + 10;

vector<int> g[T];
int cost[T];
bool vis[T];

int dfs(int u) {
    vis[u] = true;
    int x = cost[u];
    for(auto v : g[u]) 
        if(!vis[v]) x = min(x,dfs(v));
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    int n, m,u,v; cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> cost[i];

    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    ll ans = 0;

    for(int i = 1; i <= n; i++) 
        if(!vis[i]) ans += dfs(i);
    cout << ans << endl;
    return 0;
}


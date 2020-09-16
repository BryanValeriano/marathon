#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e5+5;
vector<int> g[T], h[T];
bool vis[T];

void tarjan(int u) {
    st[sz++] = u;
    d[u] = low[u] = ++r;

    for(int v : g[) {
        if(!low[v]) {
            tarjan(g, v);
            low[u] = min(low[u], low[v]);
        } else low[u] = min(low[u],d[v]);
    }

    if(low[u] >= d[u]) {
        int a;
        do {
            a = st[--sz];
            join(g,u,a);
            d[a] = INF;
        } while(a != u);
    }
}

void dfs(int u) {
    vis[u] = 1;
    for(int v : h[u])
        if(!vis[v]) dfs(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,m,t;
    cin >> n >> m >> t;
    while(m--) {
        int x,y; cin >> x >> y;
        g[x].pb(y);
        h[y].pb(x);
    }

    dfs(t);
    vis[t] = 0;
    vector<int> ans;

    for(int u : h[t]) {
        bool ok = 1;
        for(int v : g[u]) ok &= !vis[v];
        if(ok) ans.pb(u);
    }

    sort(ans.begin(),ans.end());
    cout << ans.size() << endl;
    for(int u : ans) cout << u << endl;

    return 0;
}


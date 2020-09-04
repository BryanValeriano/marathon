#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,bool> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e4+5;
int low[T], d[T], vis[T], pai[T];
vector<ii> g[T];
int t,cont;

void reset(int n) {
    for(int i = 1; i <= n; i++) {
        g[i].clear();
        low[i] = d[i] = 0;
        pai[i] = i;
    }
    t = 0;
}

void dfs1(int u, int p) {
    d[u] = low[u] = ++t;
    int ind;

    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i].fi;
        if(v == p) { ind = i; continue; }
        if(!low[v]) {
            dfs1(v,u);
            if(low[v] > d[u]) g[u][i].se = 1;
            low[u] = min(low[u],low[v]);
        } else low[u] = min(low[u],d[v]);
    }

    if(low[u] > d[p]) g[u][ind].se = 1;
}

void dfs2(int u, int p, int lider) {
    vis[u] = cont;
    for(ii e : g[u]) {
        if((!e.se) or e.fi == p or vis[e.fi] == cont) continue;
        pai[e.fi] = lider;
        if(vis[e.fi] != cont)
            dfs2(e.fi,u,lider);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,m,q;
    cin >> n >> m >> q;
    while(n or m or q) {
        reset(n);
        while(m--) {
            int u,v; cin >> u >> v;
            g[u].eb(v,0);
            g[v].eb(u,0);
        }

        for(int i = 1; i <= n; i++)
            if(!low[i])
                dfs1(i,i);

        ++cont;
        for(int i = 1; i <= n; i++)
            if(vis[i] != cont)
                dfs2(i,i,i);

        while(q--) {
            int u,v; cin >> u >> v;
            cout << (pai[u] == pai[v]? 'Y' : 'N') << endl;
        }

        cin >> n >> m >> q;
        cout << "-\n";
    }
    return 0;
}


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
int vis[T], pai[T], st[T], in[T], low[T], d[T];
int cont, t, sz;
vector<int> g[T];

void tarjan(int u) {
    st[sz++] = u;
    low[u] = d[u] = ++t;
    vis[u] = cont;

    for(int v : g[u]) {
        if(vis[v] != cont) {
            tarjan(v);
            low[u] = min(low[u],low[v]);
        } else low[u] = min(low[u],d[v]);
    }

    if(low[u] >= d[u]) {
        int a;
        do {
            a = st[--sz];;
            pai[a] = u;
            d[a] = INF;
        } while(a != u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;

    while(tc--) {
        cont++;
        t = 0;
        int n,m;
        cin >> n >> m;

        for(int i = 1; i <= n; i++)
            g[i].clear(), in[i] = 0;

        while(m--) {
            int u,v; cin >> u >> v;
            g[u].pb(v);
        }

        for(int i = 1; i <= n; i++)
            if(vis[i] != cont)
                tarjan(i);

        for(int i = 1; i <= n; i++)
            for(int j = 0; j < g[i].size(); j++)
                if(pai[i] != pai[g[i][j]])
                    in[pai[g[i][j]]]++;

        cont++;
        int ans = 0;
        for(int i = 1; i <= n; i++)
            if(vis[pai[i]] != cont) {
                vis[pai[i]] = cont;
                if(!in[pai[i]]) ans++;
            }

        cout << ans << endl;
    }

    return 0;
}


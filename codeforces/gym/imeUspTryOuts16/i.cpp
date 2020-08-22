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
const int T = 5e5+10;

bool vis[T];
bool low[T];
vector<int> g[T];
vector<int> postOrd;
vector<int> pai(T,0), sz(T,0);
vii edges;
int t = 1;

void print(int u, int v) {
    int wtf[4] = { edges[u].fi, edges[u].se,edges[v].fi, edges[v].se };
    sort(wtf, wtf+4);
    int same = 0;
    for(int i = 1; i < 4; i++) if(wtf[i] == wtf[i-1]) same = wtf[i];
    int diff1 = edges[u].fi == same ? edges[u].se : edges[u].fi;
    int diff2 = edges[v].fi == same ? edges[v].se : edges[v].fi;
    cout << diff1 << " " << same << " " << diff2 << endl;
    sz[same] -= 2;
    sz[diff1]--;
    sz[diff2]--;
}

void dfs(int u) {
    low[u] = ++t;
    for(int e : g[u]) {
        int v = (edges[e].fi == u? edges[e].se : edges[e].fi);
        if(!low[v] and v != pai[u]) {
            pai[v] = u;
            dfs(v);
        }
    }
    postOrd.pb(u);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u,v; cin >> u >> v;
        g[u].pb(edges.size());
        g[v].pb(edges.size());
        sz[u]++;
        sz[v]++;
        edges.eb(u,v);
    }

    dfs(1);
    cout << m/2 << endl;

    for(int i : postOrd) {
        bool aval = 0;
        bool odd = (sz[i]&1);
        int u,v;
        while(g[i].size()) {
            int at = g[i].back();
            g[i].pop_back();
            if(odd and (edges[at].fi == pai[i] or edges[at].se == pai[i])) continue;
            if(!vis[at]) {
                if(!aval) u = at, aval = 1;
                else {
                    v = at;
                    aval = 0;
                    vis[u] = vis[v] = 1;
                    print(u,v);
                }
            }
        }
    }

    return 0;
}


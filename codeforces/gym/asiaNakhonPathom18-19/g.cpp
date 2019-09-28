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

set<ii> bag;
const int T = 202;
vector<int> g[T];
int pai[T];
int peso[T];
int st[T];
int d[T];
int low[T];
int ok[T];
bool vis[T];
int t,sz;

void init(int n) {
    for(int i = 0; i < n; i++) {
        peso[i] = 0;
        pai[i] = i;
        vis[i] = 0;
        ok[i] = 0;
        g[i].clear();
    }
    t = 0;
    sz = 0;
}

int find(int x) {
    return(pai[x] == x? x : pai[x] = find(pai[x]));
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(peso[y] > peso[x]) swap(x,y);
    pai[y] = x;
    peso[x] += peso[y];
}

void dfs(int u) {
    vis[u] = 1;
    st[sz++] = u;
    d[u] = low[u] = t++;

    for(int v : g[u]) {
        if(!vis[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else low[u] = min(low[u],d[v]);
    }

    if(low[u] >= d[u]) {
        int a;
        do {
            a = st[--sz];
            join(a,u);
            d[a] = INF;
        } while(a != u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        init(n);
        int m; cin >> m;
        for(int i = 0; i < m; i++) { 
            int a,b; cin >> a >> b;
            g[a].pb(b);
        }
        for(int i = 0; i < n; i++) if(!vis[i]) dfs(i);
        int ans = 0;
        for(int i = 0; i < n; i++) if(!ok[find(i)]) ans++, ok[find(i)] = 1;
        cout << ans << endl; 
    }
    return 0;
}


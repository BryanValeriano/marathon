#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef tuple<int,int,int> ti;
typedef vector<ti> vti;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 1e5 + 5;
const int LOG = log2(T) + 1;
int n,m;
map<ii,int> edg;
set<ii> pego;
vti bag;
int pai[T];
int peso[T];
bool vis[T];

int anc[T][LOG + 2];
int path[T][LOG + 2];
int h[T];
vector<int> g[T];

void init() {
    for(int i = 0; i < T; i++) {
        pai[i] = i;
        peso[i] = 1;
    }
}

int find(int x) {
    return (x == pai[x]? x : pai[x] = find(pai[x]));
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(peso[x] < peso[y]) swap(x,y);
    pai[y] = x; 
    peso[x] += peso[y];
}

void dfs(int u) {
    vis[u] = 1;
    for(int v : g[u]) {
        if(!vis[v]) {
            anc[v][0] = u;
            path[v][0] = edg[mk(min(u,v),max(u,v))];
            h[v] = h[u]+1; 
            dfs(v);
        }
    }
}

void build() {
    for(int i = 1; i <= n; i++)
        if(!vis[i]) h[i] = 1, dfs(i);

    for(int j = 1; j <= LOG; j++) 
        for(int i = 1; i <= n; i++) {
            anc[i][j] = anc[anc[i][j-1]][j-1];
            path[i][j] = max({path[i][j], path[i][j-1], path[anc[i][j-1]][j-1]});
        }
}

int maxPath(int u, int v) {
    if(h[u] < h[v]) swap(v,u);

    int ans = 0;

    for(int i = LOG; i >= 0; i--)
        if(h[u] - (1 << i) >= h[v]) {
            ans = max(ans,path[u][i]);
            u = anc[u][i];
        }

    if(u == v) return ans;

    for(int i = LOG-1; i >= 0; i--) 
        if(anc[u][i] != anc[v][i]) {
            ans = max(ans,path[u][i]);
            ans = max(ans,path[v][i]);
            u = anc[u][i];
            v = anc[v][i];
        }
    
    return max({ans, path[v][0], path[u][0]});
}
 
int main() {
    ios_base::sync_with_stdio(false);
    init();
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a,b,c; cin >> a >> b >> c;
        edg[mk(min(a,b),max(a,b))] = c;
        bag.eb(c,a,b);
    }

    sort(bag.begin(), bag.end()); 
    int ans = 0;

    for(auto bg : bag) {
        int c,a,b;
        tie(c,a,b) = bg;
        if(find(a) != find(b)) {
            join(a,b);
            g[a].pb(b);
            g[b].pb(a);
            pego.emplace(min(a,b),max(a,b));
            ans += c;
        }
    }
    
    build();
    int q; cin >> q;

    while(q--) {
        int a,b; cin >> a >> b;
        if(pego.count(mk(min(a,b),max(a,b)))) cout << ans << endl;
        else {
            ll x = ans + edg[mk(min(a,b),max(a,b))];    
            x -= maxPath(a,b);
            cout << x << endl;
        }
    }

    return 0;
}


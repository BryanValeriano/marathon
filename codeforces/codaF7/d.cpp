#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
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
const int T = 202;
vector<int> g[T];
int vis[T], vez, n;

int dfs(int u, int pai, int gol) {
    if(u == gol) {vis[u] = vez; return 1; }
    for(int v : g[u]) {
        if(v == pai) continue;
        if(int x = dfs(v,u,gol)) { vis[u] = vez; return x+1; }
    }
    return 0;
}

ii dfs2(int u, int pai, int niv, bool ok) {
    if(ok) vis[u] = vez;
    ii d = mk(niv,u);
    for(int v : g[u]) {
        if(v == pai or vis[v] == vez) continue;
        d = max(d,dfs2(v,u,niv+1,ok));
    }
    return d;
}

int getPath(int x, int y) { vez++; return dfs(x,0,y); }

int getRest() {
    int best = 0;
    for(int i = 1; i <= n; i++) {
        if(vis[i] == vez) continue;
        ii x = dfs2(i,i,0,0);
        ii y = dfs2(x.se,x.se,0,1);
        best = max(best,y.fi);
    }
    return best;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i = 0; i < n-1; i++) {
        int a,b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            int x = getPath(i,j);
            int y = getRest();
            x--;
            ans = max(ans,x*y);
        }
    }

    cout << ans << endl;

    return 0;
}


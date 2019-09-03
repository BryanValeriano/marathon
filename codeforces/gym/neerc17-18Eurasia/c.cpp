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

const int T = 1e5 + 3;

int n,m;
int st[T], d[T], low[T], vis[T];
vector<int> g[T];
vii edg;
unordered_set<int> ans;
int vez,t,sz;

void init(int n) {
    for(int i = 0; i <= n; i++) g[i].clear();
    edg.clear();
    t = 0;
    ans.clear();
}
    
void dfs(int u) {
    vis[u] = vez;
    st[sz++] = u;
    d[u] = low[u] = t++;
    int volta = 0;
    int lowv = INF;

    for(int a : g[u]) {
        int v = edg[a].se;
        if(vis[v] != vez) {
            dfs(v);
            low[u] = min(low[u], low[v]);
            ans.insert(a);
        } else {
            low[u] = min(low[u],d[v]);
            if(d[v] != INF and low[v] < lowv) volta = a, lowv = low[v];
        }
    }

    if(volta) ans.insert(volta);

    if(low[u] >= d[u]) {
        int a;
        do {
            a = st[--sz];
            d[a] = INF;
        } while(a != u);
    }
}

int main() {
    ios::sync_with_stdio(false);

    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> m;
        init(n);
        int a,b;

        for(int i = 0; i < m; i++) {
            cin >> a >> b;
            g[a].pb(edg.size());
            edg.eb(a,b);
        }

        vez++;
        for(int i = 1; i <= n; i++) 
            if(vis[i] != vez) dfs(i);

        int ok = m - 2*n;
        int i = 0;

        while(ans.size() < 2*n) ans.insert(i++);

        for(int i = 0; i < edg.size(); i++) 
            if(!ans.count(i)) cout << edg[i].fi << " " << edg[i].se << endl;
        
    }

    return 0;
}


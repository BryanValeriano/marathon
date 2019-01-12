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

const int T = 5e3 + 10;
int vez;
vector<int> g[T];
vii nodes;
int vis[T];
bool chegou[T];

void dfs(int u) {
    chegou[u] = true;
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(! chegou[v] )
            dfs(v);
    }
}

int dfs2(int u) {
    vis[u] = vez; 
    int cont = 1;
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(vis[v] != vez && !chegou[v]) 
            cont += dfs2(v);
    }
    return cont;
}

bool cmp(const ii &a, const ii &b) {
    if(a.fi != b.fi) return a.fi > b.fi;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    int n, m, s, u, v;
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u].pb(v);
    }

    dfs(s);

    for(int i = 1; i <= n; i++) {
        if(! chegou[i]) {
            vez++;
            int cont = dfs2(i);
            nodes.eb(cont,i);
        }
    }
    
    sort(nodes.begin(), nodes.end(), cmp);

    int ans = 0;
    for(auto x : nodes) {
        if(! chegou[x.se] ) {
            ans++;
            dfs(x.se);
        }
    }

    cout << ans << endl;

    return 0;
}


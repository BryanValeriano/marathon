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
const int N = 1e3 + 4;
int visit = 0;
ii melhor;
bool erase[N];
int vis[N];
vii g[N];

void dfs(int atual) {
    if(vis[atual] == visit) return;
    vis[atual] = visit;
    
    ll custo = 0;
    for(int i = 1; i < g[atual].size(); i++) {
        int vizinho = g[atual][i].fi;
        if(!erase[vizinho]) custo += g[atual][i].se;
        dfs(vizinho);
    }
    if(erase[atual]) custo = INF;
    if(custo == melhor.se && melhor.se != INF) 
        if(g[atual][0].se > g[melhor.fi][0].se)
            melhor = mk(atual,custo);
    if(custo < melhor.se) melhor = mk(atual,custo);
}

int main() {
    ios::sync_with_stdio(false);
    int n; int m;
    set<int> rest;
    cin >> n >> m;
    int aux;
    for(int i = 1; i <= n; i++) {
        rest.insert(i);
        cin >> aux;
        g[i].eb(i, aux);
    }
    int u, v;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u].eb(v, g[v][0].se);
        g[v].eb(u, g[u][0].se);
    }
    ll ans = 0;
    while(rest.size() > 0) {
        visit++;
        melhor = mk(INF,INF);
        set<int> ::iterator it = rest.begin();
        dfs(*it);
        rest.erase(melhor.fi);
        ans += melhor.se;
        erase[melhor.fi] = true;
        cout << melhor.fi << " " << melhor.se << endl;
    }
    cout << ans << endl;
    return 0;
}


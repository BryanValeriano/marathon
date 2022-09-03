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
const int T = 2e5 + 5;
ll val[T];
ll peso[T];
ll qtd[T];
vector<int> g[T];
ll ans = 0;

void dfs(int u, int pai) {
    for(int v : g[u]) {
        if(v == pai) continue;
        dfs(v,u);
        qtd[u] += qtd[v];
        peso[u] += peso[v] + qtd[v] - val[v];
    }
    qtd[u] += val[u];
    peso[u] += val[u];
    //cout << u << " | " << qtd[u] << " " << peso[u] << endl;
}

void reroot(int u, int pai) {
    ans = max(ans, peso[u] - val[u]);
    //cout << u << " " << peso[u] << " " << val[u] << endl;
    for(int v : g[u]) {
        if(v == pai) continue;
        qtd[u] -= qtd[v];
        peso[u] -= (peso[v] + qtd[v] - val[v]);
        qtd[v] += qtd[u];
        peso[v] += (peso[u] + qtd[u] - val[u]);
        reroot(v,u);
        peso[v] -= (peso[u] + qtd[u] - val[u]);
        qtd[v] -= qtd[u];
        peso[u] += (peso[v] + qtd[v] - val[v]);
        qtd[u] += qtd[v];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> val[i];
    for(int i = 0; i < n-1; i++) {
        int u,v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1,1);
    reroot(1,1);

    cout << ans << endl;
    return 0;
}


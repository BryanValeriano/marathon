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

const ll MOD = 1e9+7;
const int T = 2e5 + 4;

vector<int> g[T];
vector<ll> pre[T];
vector<ll> suf[T];
ll ans[T];
ll sz[T];
ll fat[T];

void dfs(int u, int pai) {
    sz[u] = 1;

    suf[u].reserve(g[u].size());
    pre[u].reserve(g[u].size());

    for(int p = 0; p < g[u].size(); p++) {
        int v = g[u][p];
        if(v == pai) continue;
        dfs(v,u);
        pre[u][p] = sz[u];
        sz[u] = (sz[u]*(sz[v]+1))%MOD;
    }

    sz[u] = 1;
    for(int s = g[u].size()-1; s >= 0; s--) {
        int v = g[u][s];
        if(v == pai) continue;
        suf[u][s] = sz[u];
        sz[u] = (sz[u]*(sz[v]+1))%MOD;
    }
}

void reroot(int u, int pai) {
    ans[u] = sz[u];
    for(int ok = 0; ok < g[u].size(); ok++) {
        int v = g[u][ok];
        if(v == pai) continue;
        ll last = sz[v];
        sz[u] = ((pre[u][ok]*suf[u][ok])%MOD)*fat[pai]%MOD;
        fat[u] = (sz[u]+1)%MOD;
        sz[v] = (sz[v]*(sz[u]+1))%MOD;
        reroot(v,u);
        sz[v] = last;
        sz[u] = ans[u];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;

    for(int i = 2; i <= n; i++) {
        int x; cin >> x;
        g[x].pb(i);
        g[i].pb(x);
    }

    dfs(1,1);
    fat[0] = 1;
    reroot(1,0);

    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}

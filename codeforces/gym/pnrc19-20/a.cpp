#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,ll> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e5+5;
vii g[T];
ll t[T], ans[T], sd[T], sz[T], st[T];
ll n, tt;

void dfs(int u, int p, ll cost) {
    sz[u] = 1;
    st[u] = t[u];
    sd[u] = cost;
    for(ii e : g[u]) {
        int v; ll w;
        tie(v,w) = e;
        if(v == p) continue;
        dfs(v,u,cost+w);
        sd[u] += sd[v];
        sz[u] += sz[v];
        st[u] += st[v];
    }
    ans[1] += cost*(t[1]+t[u]);
}

//sz[i] qtd de filhos de i
//sd[i] somatoria di->v
//st soma dos ti
//w peso aresta pai -> filho

void reroot(int u, int p, ll w) {
    if(u != p) {
        sz[p] = n - sz[u];
        st[p] = tt - st[u];
        ll qtd = (sz[p] - sz[u])*w;
        ll aux = (st[p] - st[u])*w;

        ans[u] = ans[p] - (t[p]*sd[p]) + aux;
        sd[u] = sd[p] + qtd;
        ans[u] += sd[u]*t[u];

        sz[u] = n;
        st[u] = tt;
    }
    for(ii e : g[u]) {
        int v; ll w;
        tie(v,w) = e;
        if(v==p) continue;
        auto last = make_tuple(sz[u], sz[v], st[u], st[v], sd[v]);
        reroot(v,u,w);
        tie(sz[u], sz[v], st[u], st[v], sd[v]) = last;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> t[i];
        tt += t[i];
    }
    for(int i = 0; i < n-1; i++) {
        int a,b,w; cin >> a >> b >> w;
        g[a].eb(b,w);
        g[b].eb(a,w);
    }
    dfs(1,1,0);
    reroot(1,1,0);
    for(int i = 1; i <= n; i++)
        cout << ans[i] << endl;
    return 0;
}


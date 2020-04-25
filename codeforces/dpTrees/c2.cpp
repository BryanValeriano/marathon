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
const int T = 2e5 + 5;
const ll MOD = 1e9+7;
vector<int> g[T];
ll val[T];
ll sz[T];
ll cont[2];
ll ans;

void solve(int u, int pai, int nv) {
    sz[u] = 1;
    for(int v : g[u]) {
        if(v == pai) continue;
        solve(v,u,nv+1);
        sz[u] += sz[v];
    }
    cont[nv&1] = cont[nv&1]+sz[u]*val[u];
}

void reroot(int u, int pai, int nv) {
    ans = ans+cont[nv&1]-cont[!(nv&1)];
    cout << u << " " << cont[nv&1] << " " << cont[!(nv&1)] << " = " << cont[nv&1]-cont[!(nv&1)] << endl;

    for(int v : g[u]) {
        if(v == pai) continue;
        ll off = sz[u] - sz[v];
        ll off2 = sz[v];
        sz[u] -= sz[v], sz[v] += off;
        cont[nv&1] = cont[nv&1]-off2*val[u];
        cont[!(nv&1)] = cont[!(nv&1)]+off*val[v];
        reroot(v,u,nv+1);
        cont[!(nv&1)] = cont[!(nv&1)]-off*val[v];
        cont[nv&1] = cont[nv&1]+off2*val[u];
        sz[v] -= off, sz[u] += sz[v];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> val[i];
    for(int i = 0; i < n-1; i++) {
        int a,b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    solve(1,1,0);
    cout << cont[0] << " " << cont[1] << endl;
    reroot(1,1,0);

    cout << ans << endl;

    return 0;
}


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
const int T = 2e5 + 4;
vector<int> g[T];
ll sz[T];
ll at = 0;
ll ans = 0;

void solve(int u, int pai) {
    sz[u] = 1;
    for(int v : g[u]) {
        if(v == pai) continue;
        solve(v,u);
        sz[u] += sz[v];
    }
    at += sz[u];
}

void reroot(int u, int pai) {
    ans = max(ans,at);
    for(int v : g[u]) {
        if(v == pai) continue;
        at -= (sz[u]+sz[v]);
        sz[u] -= sz[v];
        sz[v] += sz[u];
        at += (sz[u]+sz[v]);
        reroot(v,u);
        at -= (sz[u]+sz[v]);
        sz[v] -= sz[u];
        sz[u] += sz[v];
        at += (sz[u]+sz[v]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n-1; i++) {
        int a,b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    solve(1,1);
    reroot(1,1);

    cout << ans << endl;

    return 0;
}


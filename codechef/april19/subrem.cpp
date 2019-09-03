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

const int T = 1e5 + 10;
ll n,x;
vector<int> g[T];
ll val[T];
int tin[T];
int tout[T];
int out[T];
int vis[T];
int vis2[T];
ll dp[T];
ll tree[T];
int t;
int v;

ll dfs(int u) {
    tin[u] = ++t;
    vis[u] = v;

    ll acum = val[u];
    
    for(auto z : g[u]) 
        if(vis[z] != v) acum += dfs(z);
    
    tree[tin[u]] = acum;
    tout[u] = t;
    out[tin[u]] = t;
    return acum;
}

ll solve(int at) {
    if(at > n) return 0;
    if(vis2[at] == v) return dp[at];

    ll ans = solve(out[at]+1) + tree[at] + x;
    ans = min(ans, solve(at+1));

    vis2[at] = v;
    return dp[at] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    int a,b;

    while(tc--) {
        v++;
        t = 0;
        cin >> n >> x;
        for(int i = 1; i <= n; i++) g[i].clear();
        ll ans = 0;

        for(int i = 1; i <= n; i++) {
            cin >> val[i];
            ans += val[i];
        }

        for(int i = 0; i < n-1; i++) {
            cin >> a >> b;
            g[a].pb(b);
            g[b].pb(a);
        }
        dfs(1);
        cout << ans - solve(1) << endl;
    }

    return 0;
}



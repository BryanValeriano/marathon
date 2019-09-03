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
vector<int> g[T];
bool vis[T];
set<ii> probs;
int ans = 0;

int dfs(int u) {
    vis[u] = true;
    int peso = 1;

    for(auto v : g[u])
        if(!vis[v]) peso += dfs(v);

    if(!(peso&1)) {
        if(u != 1) ans++;
        return 0;
    }

    return peso;
}

int main() {
    ios::sync_with_stdio(false);
    int n, u, v; cin >> n;
    if(n&1) { cout << -1 << endl; return 0; }

    for(int i = 0; i < n-1; i++) {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    if(dfs(1)) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}


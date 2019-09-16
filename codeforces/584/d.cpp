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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 1e5 + 3;

int n,k;
bool vis[T];
vector<int> g[T];

int dfs(int u) {
    vis[u] = 1;
    int ans = 1;
    for(int v : g[u]) if(!vis[v]) ans += dfs(v);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;

    for(int i = 0; i < k; i++) {
        int a,b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    int ans = k;

    for(int i = 1; i <= n; i++)
        if(!vis[i]) ans -= dfs(i)-1;

    cout << ans << endl;

    return 0;
}


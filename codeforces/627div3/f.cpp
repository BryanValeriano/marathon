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
const int T = 2e5 + 3;
int cor[T];
int dp[T];
int ans[T];
vector<int> g[T];

int solve(int u, int pai) {
    dp[u] = cor[u];
    for(auto v : g[u]) {
        if(v == pai) continue;
        dp[u] += max(0,solve(v,u));
    }
    return dp[u];
}

void reroot(int u, int pai) {
    ans[u] = dp[u];
    for(auto v : g[u]) {
        if(v == pai) continue;
        dp[u] -= max(0,dp[v]);
        dp[v] += max(0,dp[u]);
        reroot(v,u);
        dp[v] -= max(0,dp[u]);
        dp[u] += max(0,dp[v]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp,-1,sizeof dp);
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> cor[i];
        if(!cor[i]) cor[i] = -1;
    }

    for(int i = 0; i < n-1; i++) {
        int a,b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    solve(1,1);
    reroot(1,1);

    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}


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
const int T = 1e3 + 3;
int n, m, k;
vector<int> g[T];
bool vis[T];
bool vi[T];
int grups[T];
int grupsW[T];
int grupsB[T];
int w[T];
int b[T];
int fi[T];
ll dp[T][T];

void dfs(int atual, int grup) {
    if(!vis[atual]) {
        grupsW[grup] += w[atual];
        grupsB[grup] += b[atual];
        grups[atual] = grup;
        vis[atual] = true;
        for(int i = 0; i < g[atual].size(); i++)
            dfs(g[atual][i], grup);
        }
}

ll solve(int i,int peso) {
    if(i > n) return 0;
    if(vi[grups[i]]) return solve(i+1,peso);
    ll &r = dp[i][peso];
    if(r != -1) return r;
    ll ans = -INF;
    if(vi[grups[i]] == 0) {
        vi[grups[i]] = 1;
        if(peso + grupsW[grups[i]] <= k && fi[grups[i]] == i)
            ans = max(ans, solve(i+1, peso + grupsW[grups[i]]) + grupsB[grups[i]]); 
        if(peso + w[i] <= k) ans = max(ans, solve(i+1, peso + w[i]) + b[i]); 
        vi[grups[i]] = 0;
    }
    ans = max(ans, solve(i+1, peso));

    return r = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        cin >> w[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    int u, v;
    for(int i = 0; i < m; i++) { 
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int cont = -1;
    for(int i = 1; i <= n; i++) 
        if(!vis[i]) { 
            dfs(i, ++cont);
            fi[cont] = i;
        }
    memset(dp, -1, sizeof dp);
    cout << solve(1,0) << endl;

    return 0;
}


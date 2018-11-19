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

struct pessoa {
    int b,w,g = 0;

    bool const operator < (pessoa &b) const {
        if(g != b.g) return g < b.g;
        return false;
    }
};

vector<int> g[T];
bool vis[T];
int grupsW[T];
int grupsB[T];
int w[T];
int b[T];
int ini[T];
int fim[T];
pessoa p[T];
ll dp[T][T];

void dfs(int atual, int grup) {
    if(!vis[atual]) {
        grupsW[grup] += p[atual].w;
        grupsB[grup] += p[atual].b;
        p[atual].g = grup;
        vis[atual] = true;
        for(int i = 0; i < g[atual].size(); i++)
            dfs(g[atual][i], grup);
        }
}

ll solve(int i,int peso) {
    if(i > n) return 0;
    ll &r = dp[i][peso];
    if(r != -1) return r;
    ll ans = -INF;

    if(i == ini[p[i].g] && grupsW[p[i].g] + peso <= k) 
        ans = max(ans, solve(fim[p[i].g]+1, peso + grupsW[p[i].g]) + grupsB[p[i].g]);

    if(peso + p[i].w <= k)
        ans = max(ans, solve(fim[p[i].g]+1, peso + p[i].w) + p[i].b);

    ans = max(ans, solve(i+1, peso));

    return r = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        cin >> p[i].w;
    for(int i = 1; i <= n; i++) 
        cin >> p[i].b;
    int u, v;
    for(int i = 0; i < m; i++) { 
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int cont = -1;
    for(int i = 1; i <= n; i++) { 
        if(!vis[i]) {
            dfs(i, ++cont);
        }
    }
    sort(p+1, p+n+1);
    p[0].g = -1;
    for(int i = 1; i <= n; i++) {
        if(p[i].g != p[i-1].g) { 
            ini[p[i].g] = i;
            fim[p[i-1].g] = i-1;
        }
        else if(i == n) {
            fim[p[n].g] = n;
            if(ini[p[n].g] == 0) ini[p[n].g] = n;
        }
    }
    if(fim[p[n].g] == 0) fim[p[n].g] = n;
    memset(dp, -1, sizeof dp);
    cout << solve(1,0) << endl;

    return 0;
}


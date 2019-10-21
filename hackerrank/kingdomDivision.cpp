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
const ll MOD = 1e9 + 7;

const int T = 1e5 + 5;
int pai[T];
ll dp[T][2][2];
vector<int> g[T];
int n;

void dfs(int u, int p) {
    for(int v : g[u])
        if(v != p) pai[v] = u, dfs(v,u);
}

ll knapSack(int a, int c, bool d, bool e);

ll makeTree(int at, bool cor, bool eq) {
    return knapSack(at,0,cor,eq);
}
 
ll knapSack(int at, int c, bool cor, bool eq) {
    if(c >= g[at].size()) return eq;
    int x = g[at][c];
    if(x == pai[at]) return knapSack(at,c+1,cor,eq);
    if(~dp[x][cor][eq]) return dp[x][cor][eq];
    ll ans = 0;
    ans = (makeTree(x,cor,1) * knapSack(at,c+1,cor,1)) % MOD;
    ans = (ans + ((makeTree(x,!cor,0) * knapSack(at,c+1,cor,eq)) %MOD)%MOD);
    return dp[x][cor][eq] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp,-1,sizeof dp);
    cin >> n;
    for(int i = 0; i < n-1; i++) {
        int a,b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1,1);
    cout << (makeTree(1,0,0) + makeTree(1,1,0))%MOD << endl;
    return 0;
}


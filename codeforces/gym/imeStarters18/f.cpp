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

const int T = 1e5 + 5;

int n, m;
int dp[T][2];
vector<int> g[T];

int solve(int at, int pai, int pega) {
    if(g[at].size() == 1) return pega;
    if(dp[at][pega] != -1) return dp[at][pega];

    int ans = pega;
    int l = 0, r = 0;
    for(auto v : g[at]) { 
        if(v == pai) continue;
        r = solve(v,at,!pega);
        if(pega == 0) l = solve(v,at,pega);
        ans += max(l,r);
    }

    return dp[at][pega] = ans;
}


int main() {
    ios::sync_with_stdio(false);
    memset(dp,-1,sizeof dp);
    cin >> n >> m;
    int a,b;

    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    cout << max(solve(1,0,0), solve(1,0,1)) << endl;

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const int N = 1e5+2;
int size[N];
vector<ii> g[N];
vector<int> dp[N];

int solve(int at, int last) {
    int ans = 1;
    if(last >= size[at]) return ans;
    if(~dp[at][last]) return dp[at][last];
    for(int i = last; i < g[at].size(); i++)
        ans = max(ans,solve(g[at][i].fi,g[at][i].se+1)+1);
    return (~last?dp[at][last] = ans:ans);
}

int test() {
    for(int at = n; at >= 1; at--) {
        for(int u = 0; u < g[at].size(); u++) {
            int x = g[at][u].fi;
            int c = g[at][u].se;
            for(int v = c+1; v < g[x].size(); v++) {
                int y = g[x][v].fi;
                dp[at][u] = (y>x?dp[x][c]+1:2);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a,b; cin >> a >> b;
        g[a].eb(b,0);
        dp[a].pb(-1);
        g[b].eb(a,0);
        dp[b].pb(-1);
        size[a]++;
        size[b]++;
    }

    for(int i = 1; i <= n; i++) sort(g[i].begin(),g[i].end());
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < g[i].size(); j++) {
            int x = g[i][j].fi;
            g[i][j].se = lower_bound(g[x].begin(),g[x].end(),mk(i,0))-g[x].begin();
        }

    for(int i = 1; i <= n; i++) cout << solve(i,0) << (i+1<=n?" ":"");
    cout << endl;

    return 0;
}


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
const int N = 300;

int n,m,gol;
ll dp[10][N];
vector<int> g[10];

ll solve(int u, int mask) {
    if(mask == gol) return 1;
    ll &r = dp[u][mask];
    if(~r) return r;
    r = 0;

    for(int v : g[u]) {
        if(mask & (1 << v)) continue;
        r += solve(v, mask | (1 << v));
    }

    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp,-1,sizeof dp);
    cin >> n >> m;
    gol = pow(2,n)-1;

    while(m--) {
        int a,b; cin >> a >> b;
        a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    cout << solve(0,1) << endl;

    return 0;
}


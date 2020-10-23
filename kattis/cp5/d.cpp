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
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e5+5;
ll h[T];
int in[T], dp[T], corn[T];
map<ll,int> pos;
vector<int> g[T];

void pre() {
    ll v[2] = {1,2};
    pos[1] = 1;
    pos[2] = 2;
    for(int i = 3; i < 90; i++) {
        ll at = v[1] + v[0];
        pos[at] = i;
        swap(v[0],v[1]);
        v[1] = at;
    }
}

int solve(int at) {
    if(dp[at] != -1) return dp[at];
    dp[at] = 1;
    for(int v : g[at]) {
        dp[at] = max(dp[at], solve(v)+1);
    }
    return dp[at];
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp,-1,sizeof dp);
    pre();
    int n,m; cin >> n >> m;

    for(int i = 1; i <= n; i++) cin >> h[i];

    while(m--) {
        int a,b;
        cin >> a >> b;
        if(h[a] > h[b]) swap(a,b);
        if(h[a] == 1 and h[b] == 1) corn[a] = corn[b] = 1;
        if(!pos.count(h[a]) or !pos.count(h[b])) continue;
        if(pos[h[a]]+1 == pos[h[b]]) {
            g[a].pb(b);
            in[b]++;
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++)
        if(!in[i] and pos.count(h[i]))
            ans = max(ans,solve(i)+ corn[i]);

    cout << ans << endl;
    return 0;
}


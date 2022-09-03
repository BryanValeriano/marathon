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
const ll MOD = 1000000007;
const int T = 2e5;
vector<int> g[T];
int pai[T];
bool vis[T];

void dfs(int u) {
    vis[u] = 1;
    for(int v : g[u]) {
        if(vis[v]) continue;
        pai[v] = u;
        dfs(v);
    }
}

ll ele(ll b, ll e) {
    ll ans = 1;
    while(e) {
        if(e&1) ans = (ans*b) % MOD;
        b = (b*b)%MOD;
        e >>= 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,q; cin >> n >> q;

    for(int i = 1; i < n; i++) {
        int a,b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    pai[0] = INF;
    dfs(0);

    while(q--) {
        ll a,b,k; cin >> a >> b >> k;
        ll ans = (k*ele(k-1,n-2))%MOD;
        ans = (ans*(k-2+(pai[b] == a || pai[a] == b)))%MOD;
        cout << ans << endl;
    }

    return 0;
}


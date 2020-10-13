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
const int T = 2e5+5;
ll nv[T], weight[T];
vector<int> g[T];

void dfs(int u, int p) {
    for(int v : g[u]) {
        if(v==p) continue;
        nv[v] = nv[u]+1;
        dfs(v,u);
        weight[u] += weight[v]+1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,k; cin >> n >> k;
    for(int i = 0; i < n-1; i++) {
        int a,b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1,1);
    vector<ll> v;
    for(int i = 1; i <= n; i++) v.pb(nv[i]-weight[i]);
    ll ans = 0;
    sort(v.begin(), v.end(), greater<ll>());
    for(int i = 0; i < k; i++) ans += v[i];
    cout << ans << endl;
    return 0;
}


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
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e3 + 4;
ll dist[T];
bool vis[T];
vii g[T];
int n,m;

void bellman() {
    for(int i = 0; i < n; i++)
        for(int u = 1; u <= n ; u++)
            for(ii v : g[u]) {
                if(!vis[v.fi]) dist[v.fi] = dist[u]+v.se;
                vis[v.fi] = 1;
                dist[v.fi] = max(dist[v.fi],dist[u]+v.se);
            }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 2; i <= n; i++) dist[i] = -1e18;

    for(int i = 0; i < m; i++) {
        int a,b,c; cin >> a >> b >> c;
        g[a].eb(b,c);
    }

    bellman();
    ll ans = dist[n];
    bellman();

    if(ans == dist[n]) cout << ans << endl;
    else cout << "inf" << endl;

    return 0;
}


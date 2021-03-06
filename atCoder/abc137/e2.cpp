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
const ll INF = 1e12;
const double PI = acos(-1.0);
const int T = 2500 + 4;
ll dist[T];
bool vis[T];
vii g[T];
int n,m;
ll p;

void bellman() {
    for(int i = 0; i < n; i++)
        for(int u = 1; u <= n ; u++)
            for(ii v : g[u])
                dist[v.fi] = max(dist[v.fi],dist[u]+v.se);
}

void cycle() {
    for(int i = 0; i < n; i++)
        for(int u = 1; u <= n ; u++)
            for(ii v : g[u])
                if(dist[v.fi] > dist[u] + v.se) dist[v.fi] = INF;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> p;
    for(int i = 2; i <= n; i++) dist[i] = -1e18;

    for(int i = 0; i < m; i++) {
        int a,b,c; cin >> a >> b >> c;
        g[a].eb(b,c-p);
    }

    bellman();
    ll ans = dist[n];
    cycle();
    bellman();

    if(ans == dist[n]) cout << max(0ll,ans) << endl;
    else cout << -1 << endl;

    return 0;
}


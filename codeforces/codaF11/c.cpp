#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e3+2;
int n,m,x,y;
vii g[T];
vector<int> h[T];
bool vis[T][T];

ll d[T][T];
ll t[T], c[T];
ll cost[T];

void dij(int at, ll dist[]) {
    for(int i = 1; i <= n; i++) dist[i] = INF;
    dist[at] = 0;
    priority_queue<ii,vii,greater<ii>> pq;
    pq.emplace(dist[at],at);

    while(!pq.empty()) {
        ll di; int u;
        tie(di,u) = pq.top();
        pq.pop();

        if(vis[at][u]) continue;
        vis[at][u] = 1;

        for(ii e : g[u]) {
            ll dd; int v;
            tie(v,dd) = e;
            if(dist[v] > dist[u]+dd) {
                dist[v] = dist[u]+dd;
                pq.emplace(dist[v],v);
            }
        }
    }
}

ll solve() {
    for(int i = 1; i <= n; i++) cost[i] = INF, vis[x][i] = 0;
    cost[x] = 0;
    priority_queue<ii,vii,greater<ii>> pq;
    pq.emplace(cost[x],x);

    while(!pq.empty()) {
        ll di; int u;
        tie(di,u) = pq.top();
        pq.pop();

        if(u == y) return di;
        if(vis[x][u]) continue;
        vis[x][u] = 1;

        for(int v : h[u]) {
            if(cost[v] > cost[u]+c[u]) {
                cost[v] = cost[u]+c[u];
                pq.emplace(cost[v],v);
            }
        }
    }

    return INF;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    cin >> x >> y;

    while(m--) {
        int a,b,c;
        cin >> a >> b >> c;
        g[a].eb(b,c);
        g[b].eb(a,c);
    }

    for(int i = 1; i <= n; i++)
        cin >> t[i] >> c[i];

    for(int i = 1; i <= n; i++)
        dij(i,d[i]);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i==j) continue;
            if(d[i][j] <= t[i]) h[i].pb(j);
        }
    }

    ll ans = solve();
    cout << (ans >= INF? -1 : ans) << endl;

    return 0;
}


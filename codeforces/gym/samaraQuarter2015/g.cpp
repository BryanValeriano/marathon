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
const ll INF = 0x3f3f3f3f3f3f3f;
const double PI = acos(-1.0);

const int T = 1e5 + 3;

vector<ii> g[T];
int pai[T];
ll dist[T];
bool vis[T];
int n,m;
int ori, dest;
ll ans;
priority_queue<ii, vector<ii> > pq;

void dijkstra() {
    ans = INF;

    while(!pq.empty()) {
        ll u,d;
        tie(d,u) = pq.top();
        pq.pop();
        d = -d;

        if(vis[u]) continue;
        vis[u] = 1;

        for(ii e : g[u]) {
            ll w,v;
            tie(v,w) = e;

            if(pai[v] and pai[v] != pai[u]) {
                if(d + dist[v] + w < ans) {
                    ans = d + dist[v] + w;
                    ori = pai[u], dest = pai[v];
                }
            }

            if(d + w < dist[v]) {
                pai[v] = pai[u];
                dist[v] = d + w;
                pq.emplace(-dist[v], v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    fill(dist, dist+T, INF);
    cin >> n >> m;
    int x,y,z;

    for(int i = 1; i <= n; i++) {
        cin >> x;
        if(x) dist[i] = 0, pai[i] = i, pq.emplace(0,i);
    }

    for(int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        g[x].eb(y,z);
        g[y].eb(x,z);
    }

    dijkstra();

    if(ans == INF) {
        cout << "No luck at all" << endl;
    } else cout << ans << endl << ori << " " << dest << endl;
    return 0;
}


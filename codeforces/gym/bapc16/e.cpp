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
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);

struct graph {
    int size;
    vector<list<pair<int, ll>>> adj;
    graph(int n) : size(n), adj(n) {}
    void addEdge(int a, int b, ll c) {
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
};

ll dijkstra(graph& g, ll maxe) {
    vector<ll> dist(g.size, INFLL);
    vector<bool> visit(g.size, false);
    priority_queue<pair<ll, int>> q;
    dist[0] = 0;
    q.emplace(0, 0);
    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();
        if (visit[u]) continue;
        if (u == g.size - 1) return dist[u];
        visit[u] = true;
        for (auto& [v, w] : g.adj[u]) {
            if (visit[v] or w > maxe) continue;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                q.emplace(-dist[v], v);
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);

    int n, m, x;
    cin >> n >> m >> x;
    graph g(n);
    int a, b;
    ll c;
    for (int i = 0;i < m;i++) {
        cin >> a >> b >> c;
        g.addEdge(a - 1, b - 1, c);
    }
    ll bc = dijkstra(g, INFLL);
    ll l = 1, r = INFLL;
    ll maxcost = bc + (x * bc) / 100;
    while (l < r) {
        ll mid = (l + r) >> 1;
        ll x = dijkstra(g, mid);
        if (x == -1 or x > maxcost) l = mid + 1;
        else r = mid;
    }
    cout << l << endl;
    return 0;
}


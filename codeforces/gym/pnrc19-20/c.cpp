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

struct graph {
    int size;
    vector<list<int>> adj;
    graph(int n) : size(n), adj(n) {}
    void addEdge(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
};

int bfs(graph& g) {
    vector<int> dist(g.size, INF);
    vector<bool> vis(g.size, false);
    queue<int> q;
    dist[0] = 0;
    vis[0] = true;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g.adj[u]) {
            if (vis[v]) continue;
            vis[v] = true;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
    return dist[g.size - 1];
}

int main() {
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    graph g(n);
    for (int i = 0;i < m;i++) {
        int a, b;
        cin >> a >> b;
        g.addEdge(a - 1, b - 1);
    }
    cout << bfs(g) - 1 << endl;
    return 0;
}


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
  vector<map<int, int>> adj;
  graph(int n) : size(n), adj(n) {}
  void addEdge(int a, int b, int w) {
    adj[a][b] = adj[b][a] = w;
  }
};

typedef tuple<int, int, int> tup;

vector<int> par;
void dijkstra(graph& g) {
  par.assign(g.size, -1);
  vector<int> dist(g.size, INF);
  vector<bool> visit(g.size, false);
  priority_queue<tup> q;
  dist[1] = 0;
  q.emplace(0, 1, -1);
  while (!q.empty()) {
    auto [d, u, p] = q.top();
    q.pop();
    if (visit[u]) continue;
    visit[u] = true;
    par[u] = p;
    for (auto& [v, w] : g.adj[u]) {
      if (visit[v]) continue;
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        q.emplace(-dist[v], v, u);
      }
    }
  }
}

int main() {
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    graph g(n);
    int a, b, c;
    for (int i = 0;i < m;i++) {
      cin >> a >> b >> c;
      g.addEdge(a, b, c);
    }
    dijkstra(g);
    for (int i = 0;i < n;i++) {
      if (par[i] != -1) {
        g.adj[par[i]].erase(i);
      }
    }
    dijkstra(g);
    if (par[0] == -1) cout << "impossible" << endl;
    else {
      vector<int> ans;
      int sz = 0;
      int x = 0;
      while (x != -1) {
        ans.push_back(x);
        sz++;
        x = par[x];
      }
      cout << sz;
      for (int i = 0;i < sz;i++) cout << " " << ans[i];
      cout << endl;
    }
    return 0;
}

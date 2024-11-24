#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef tuple<int, int, int> ti;
typedef vector<ti> vti;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 2e5 + 5;
vector<int> graph[T];
vector<int> weights;
vii edges;
vii repeatedEdges;
// kruskal
int pai[T];
int peso[T];

void clear(int n) {
  edges.clear();
  repeatedEdges.clear();
  weights.clear();
  for (int i = 0; i <= n; i++)
    graph[i].clear();
}

void readGraph(int edgeQtd) {
  while (edgeQtd--) {
    int u, v;
    cin >> u >> v;
    edges.eb(u, v);
    graph[u].pb(edges.size());
    graph[v].pb(edges.size());
  }
}

void readWeights(int m) {
  while (m--) {
    int x;
    cin >> x;
    weights.pb(x);
  }
  sort(weights.begin(), weights.end());
}

void fillPath(int origin, int dest, vector<int> &edgeUsedToGoInto,
              vector<bool> &vis, vector<bool> &checkVis) {
  int at = dest;
  while (at != origin) {
    int e = edgeUsedToGoInto[at];
    ii uv = edges[e];
    vis[e] = 1;
    if (checkVis[e]) {
      repeatedEdges.eb(edges[e]);
    }
    int v = (uv.first == at ? uv.second : uv.first);
    at = v;
  }
}

int bfs(int origin, int dest, int n, vector<bool> &vis,
        vector<bool> &checkVis) {
  queue<int> bag;
  vector<int> dist(n + 2, 0);
  vector<int> edgeUsedToGoInto(vis.size(), 0);
  bag.push(origin);
  dist[origin] = 0;

  while (!bag.empty()) {
    int at = bag.front();
    if (at == dest)
      return dist[at];
    bag.pop();

    for (int e : graph[at]) {
      ii uv = edges[e];
      int v = (uv.first == at ? uv.second : uv.first);

      if (!dist[v]) {
        edgeUsedToGoInto[v] = e;
        bag.push(v);
        dist[v] = dist[at] + 1;
        if (v == dest) {
          fillPath(origin, dest, edgeUsedToGoInto, vis, checkVis);
          return dist[v];
        }
      }
    }
  }
  return 0;
}

int find(int x) { return (pai[x] == x ? x : pai[x] = find(pai[x])); }

void join(int u, int v) {
  u = find(u);
  v = find(v);
  if (peso[v] > peso[u])
    swap(u, v);
  pai[v] = u;
  peso[u] += peso[v];
}

void initUnionFind(int n) {
  for (int i = 0; i <= n; i++) {
    pai[i] = i;
    peso[i] = 1;
  }
}

void kruskal(int n) {
  initUnionFind(n);
  for (int i = 0; i < edges.size(); i++) {
    auto [u, v] = edges[i];
    if (find(u) != find(v)) {
      join(u, v);
      graph[u].pb(i);
      graph[v].pb(i);
      cout << u << " X " << v << endl;
    }
  }
}

ll solve(int doubleWeight, int singleWeight) {
  ll ans = 0;
  for (int i = 0; i < doubleWeight; i++) {
    ans += (ll)(weights[i] * 2);
  }
  for (int i = doubleWeight; i < doubleWeight + singleWeight; i++) {
    ans += (ll)weights[i];
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    readWeights(m);
    readGraph(m);
    // kruskal(n);
    vector<bool> visA(m + 5, 0);
    vector<bool> visC(m + 5, 0);
    int pathAtoB = bfs(a, b, n, visA, visC);
    int pathCtoB = bfs(c, b, n, visC, visA);
    int repeatedNodes = repeatedEdges.size();
    cout << pathAtoB << " | " << pathCtoB << " | " << repeatedNodes << endl;
    cout << solve(repeatedNodes, pathCtoB + pathAtoB - repeatedNodes * 2)
         << endl;
    clear(n);
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x) cout << #x << " = " << x << endl
#define ok cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

// union find - start
void resetUnionFind(vector<int> &father) {
  int n = father.size();
  for (int i = 0; i < n; i++) {
    father[i] = i;
  }
}

int find(int x, vector<int> &father) {
  return (x == father[x] ? x : father[x] = find(father[x], father));
}

void join(int x, int y, vector<int> &father, vector<int> &weight) {
  x = find(x, father);
  y = find(y, father);
  if (x == y)
    return;
  if (weight[y] > weight[x])
    swap(x, y);
  father[y] = x;
  weight[x] += y;
}
// union find - end

vector<vector<int>> buildGraph(map<string, vector<int>> &genre,
                               map<string, vector<int>> &writer, int n) {
  vector<vector<int>> graph(n, vector<int>());
  for (auto [_, neighbours] : genre) {
    for (int i = 0; i < neighbours.size(); i++) {
      for (int j = i + 1; j < neighbours.size(); j++) {
        graph[neighbours[i]].pb(neighbours[j]);
        graph[neighbours[j]].pb(neighbours[i]);
      }
    }
  }
  for (auto [_, neighbours] : writer) {
    for (int i = 0; i < neighbours.size(); i++) {
      for (int j = i + 1; j < neighbours.size(); j++) {
        graph[neighbours[i]].pb(neighbours[j]);
        graph[neighbours[j]].pb(neighbours[i]);
      }
    }
  }
  return graph;
}

int solve(int currentNode, vector<vector<int>> &graph, vector<int> &father,
          vector<int> &weight) {
  int currentGroup = find(currentNode, father);
  for (int neighbour : graph[currentGroup]) {
  }
}

void dfs(int currentNode, int parent, bool isRoot, vector<vector<int>> &graph,
         vector<int> &nodeLowestReach, vector<int> &nodeLvl,
         vector<int> &father, vector<int> &weight, int currentLvl) {
  nodeLvl[currentNode] = nodeLowestReach[currentNode] = currentLvl;
  for (int child : graph[currentNode]) {
    if (!nodeLvl[child] && child != parent) {
      currentLvl++;
      dfs(child, currentNode, false, graph, nodeLowestReach, nodeLvl, father,
          weight, currentLvl);
      if (nodeLowestReach[child] <= nodeLvl[currentNode]) {
        join(currentNode, child, father, weight);
      }
      nodeLowestReach[currentNode] =
          min(nodeLowestReach[currentNode], nodeLowestReach[child]);
    } else if (child != parent)
      nodeLowestReach[currentNode] =
          min(nodeLowestReach[currentNode], nodeLvl[child]);
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    map<string, vector<int>> genre;
    map<string, vector<int>> writer;
    // tarjan bidirectional
    vector<int> nodeLvl(n, 0);
    vector<int> nodeLowestReachLvl(n, 0);
    // union find
    vector<int> father(n, 0);
    vector<int> weight(n, 1);
    resetUnionFind(father);
    for (int i = 0; i < n; i++) {
      string g, w;
      cin >> g >> w;
      genre[g].pb(i);
      writer[w].pb(i);
    }
    vector<vector<int>> graph = buildGraph(genre, writer, n);
    int ans = INF;
    for (int node = 0; node < graph.size(); node++) {
      dfs(node, node, true, graph, nodeLowestReachLvl, nodeLvl, father, weight,
          1);
    }

    cout << ans << endl;
  }

  return 0;
}
